#include "bgfg.h"
#include <opencv2/opencv.hpp>
#include <stdexcept>


namespace rsdt { namespace videoproc {

class BgFgVisualizerBase : public IAlgorithmVisualizer
{
public:
    BgFgVisualizerBase(Json::Value const& params)
    {
    }
    
    cv::Mat process_frame(cv::Mat const& frame)
    {
        // masking code from sample bgfg_gmg.cpp

        cv::Mat fgmask;
        cv::Mat segm;
        (*subtractor)(frame, fgmask);

        frame.copyTo(segm);
        cv::add(frame, cv::Scalar(100, 100, 0), segm, fgmask);
        return segm;
    }

protected:
    cv::Ptr<cv::BackgroundSubtractor> subtractor;
};


class BgFgVisualizerMOG : public BgFgVisualizerBase
{
public:
    BgFgVisualizerMOG(Json::Value const& params)
    : BgFgVisualizerBase(params)
    {
        subtractor = cv::Algorithm::create<cv::BackgroundSubtractorMOG>("BackgroundSubtractor.MOG");
        if (subtractor.empty())
            throw std::runtime_error("Failed to create algorithm BackgroundSubtractor.MOG");
        subtractor->set("backgroundRatio", params.get("backgroundRatio", 0.5).asDouble());
        // TODO: add other params and adjust them to make the method work
    }
};


PAlgorithmVisualizer createBgFgVisualizer(Json::Value const& params)
{
    // TODO: implement at least 2 methods, e.g. 2 of MOG, MOG2, and GMG.
    // Also an option is to create your own simple method.
    return PAlgorithmVisualizer(new BgFgVisualizerMOG(params));
}

}}
