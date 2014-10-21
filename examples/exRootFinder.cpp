#include <iostream>
#include <LatAnalyze/Function.hpp>
#include <LatAnalyze/GslHybridRootFinder.hpp>

using namespace std;
using namespace Latan;

int main(void)
{
    constexpr double a = 1., b = 10.;
    DoubleFunction f1(2, [a](const double *x){return a*(1.-x[0]);});
    DoubleFunction f2(2, [b](const double *x){return b*(x[1]-x[0]*x[0]);});
    vector<DoubleFunction *> system = {&f1, &f2};
    GslHybridRootFinder solve(2);
    DVec init(2), x;
    
    solve.setVerbosity(Solver::Verbosity::Debug);
    init(0) = -10.; init(1) = -5.;
    solve.setInit(init);
    x = solve(system);
    cout << "solution: " << x.transpose() << endl;
    
    return 0;
}