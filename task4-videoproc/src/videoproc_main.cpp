#include <cstdio>
#include <fstream>
#include <algorithm>
#include <stdexcept>
#include <opencv2/opencv.hpp>
#include <json-cpp/json.h>

#include "visualizer.h"
#include "bgfg.h"
#include "optflow.h"

namespace rsdt { namespace videoproc {

static Json::Value create_default_task()
{
    using Json::Value;
    Value result(Json::objectValue);

    result["videosource"] = 0;
    result["show_bgfg"] = true;
    result["show_optflow"] = true;

    result["preprocess_params"]["scale"] = 0.5;

    return result;
}

static Json::Value parse_task_file(std::string const& filename)
{
    std::ifstream ifs(filename.c_str());
    if (!ifs.is_open())
        throw std::runtime_error("Unable to open file: " + filename);
    Json::Reader reader;
    Json::Value task;
    bool const parse_success = reader.parse(ifs, task, false);
    if (parse_success)
        return task;
    else
        throw std::runtime_error("Unable to parse JSON: " + reader.getFormatedErrorMessages());
}

static cv::Mat preprocess_frame(cv::Mat const& src, Json::Value const& params)
{
    double const scale_factor = params.get("scale", 1.0).asDouble();
    cv::Mat result;
    cv::resize(src, result, cv::Size(), scale_factor, scale_factor, cv::INTER_AREA);
    return result;
}

static void run(Json::Value const& task)
{
    using Json::Value;
    Value videosource = task["videosource"];
    cv::VideoCapture cap;
    if (videosource.isIntegral())
        cap.open(videosource.asInt());
    else
        cap.open(videosource.asString());
    if (!cap.isOpened())
        throw std::runtime_error("Unable to open VideoCapture");

    PAlgorithmVisualizer bgfg_vis;
    if (task["show_bgfg"].asBool())
        bgfg_vis = createBgFgVisualizer(task["bgfg_params"]);

    PAlgorithmVisualizer optflow_vis;
    if (task["show_optflow"].asBool())
        optflow_vis = createOptFlowVisualizer(task["optflow_params"]);

    while (true)
    {
        cv::Mat frame;
        if (!cap.read(frame))
            break;

        cv::imshow("frame", frame);

        frame = preprocess_frame(frame, task["preprocess_params"]);
        if (bgfg_vis)
            cv::imshow("bgfg", bgfg_vis->process_frame(frame));
        if (optflow_vis)
            cv::imshow("optflow", optflow_vis->process_frame(frame));

        if ((cv::waitKey(20) & 0xFF) == 27)
            break;
    }
}


static int main(int argc, char const** argv)
{
    try
    {
        Json::Value task;
        if (argc == 1)
            task = create_default_task();
        else if (argc == 2)
            task = parse_task_file(argv[1]);
        else
            throw std::runtime_error("Wrong arguments; usage: ./videoproc [task.json]");
        
        run(task);
        return 0;
    }
    catch (std::exception const& e)
    {
        fprintf(stderr, "Exception: %s\n", e.what());
        return 1;
    }
}

}}


int main(int argc, char const** argv)
{
    return rsdt::videoproc::main(argc, argv);
}
