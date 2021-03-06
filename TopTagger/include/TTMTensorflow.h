#ifndef TTMTENSORFLOW_H
#define TTMTENSORFLOW_H

#include "TopTagger/TopTagger/include/TTModule.h"

#include <string>
#include <vector>

#ifdef DOTENSORFLOW
#include "tensorflow/c/c_api.h"
#endif

//class TF_Session;
//class TF_Buffer;
//class TF_Output;
//class TF_Operation;

class TTMTensorflow : public TTModule
{
private:
#ifdef DOTENSORFLOW
    double discriminator_;
    std::string modelFile_, inputOp_, outputOp_;
    double csvThreshold_;
    double bEtaCut_;
    int maxNbInTop_;

    //Tensoflow session pointer
    TF_Session *session_;

    //Input variable names 
    std::vector<std::string> vars_;

    std::vector<TF_Output>     inputs_;
    std::vector<TF_Output>     outputs_;
    std::vector<TF_Operation*> targets_;

    TF_Buffer* read_file(const std::string& file);
#endif

public:
    ~TTMTensorflow();

    void getParameters(const cfg::CfgDocument*, const std::string&);
    void run(TopTaggerResults&);
};
REGISTER_TTMODULE(TTMTensorflow);

#endif
