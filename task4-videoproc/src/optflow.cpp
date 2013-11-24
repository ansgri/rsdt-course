#include "bgfg.h"
#include <opencv2/opencv.hpp>


namespace rsdt { namespace videoproc {

static void draw_opt_flow_map(cv::Mat const& flow, cv::Mat & cflowmap, int step, double, cv::Scalar const& color)
{
    // use code from sample fback.cpp
}


class OptFlowVisualizerFarneback : public IdentityVisualizer
{
public:
    OptFlowVisualizerFarneback(Json::Value const& params)
    {
        // TODO: read algorithm params
    }

    cv::Mat process_frame(cv::Mat const& frame)
    {
        cv::Mat gray;
        cv::cvtColor(frame, gray, CV_BGR2GRAY);
        if (prevgray.empty())
        {
            prevgray = gray;
            return gray;
        }

        // TODO: use code from sample fback.cpp

        draw_opt_flow_map(flow, cflow, 16, 1.5, CV_RGB(0, 255, 0));

        prevgray = gray;
        return cflow;
    }

private:
    cv::Mat prevgray;

};


PAlgorithmVisualizer createOptFlowVisualizer(Json::Value const& params)
{
    // TODO: use three optical flows:
    //  - farneback (sample fback.cpp)
    //  - LK (sample lkdemo.cpp)
    //  - TV-L1 (sample tvl1_optical_flow.cpp)
    // Choose based on 'type' param
    return PAlgorithmVisualizer(new OptFlowVisualizerFarneback(params));
}

}}
