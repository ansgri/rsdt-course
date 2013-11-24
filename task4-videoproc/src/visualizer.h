#pragma once
#include <compat/tr1_memory.h>
#include <json-cpp/value.h>
#include <opencv2/core/core.hpp>


namespace rsdt { namespace videoproc {

class IAlgorithmVisualizer
{
public:
    virtual ~IAlgorithmVisualizer() { }
    virtual cv::Mat process_frame(cv::Mat const& frame) = 0;

protected:
    IAlgorithmVisualizer() { }

private:
    IAlgorithmVisualizer(IAlgorithmVisualizer const&);
    IAlgorithmVisualizer & operator = (IAlgorithmVisualizer const&);
};

typedef std::tr1::shared_ptr<IAlgorithmVisualizer> PAlgorithmVisualizer;

class IdentityVisualizer : public IAlgorithmVisualizer
{
public:
  IdentityVisualizer() { }

  cv::Mat process_frame(cv::Mat const& frame) 
  {
    return frame;
  }
};

}}
