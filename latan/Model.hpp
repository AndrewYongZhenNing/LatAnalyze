/*
 * Model.hpp, part of LatAnalyze 3
 *
 * Copyright (C) 2013 - 2014 Antonin Portelli
 *
 * LatAnalyze 3 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * LatAnalyze 3 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with LatAnalyze 3.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef Latan_Model_hpp_
#define Latan_Model_hpp_

#include <latan/Global.hpp>
#include <latan/Mat.hpp>
#include <memory>
#include <vector>

BEGIN_NAMESPACE

/******************************************************************************
 *                           Double model class                               *
 ******************************************************************************/
class DoubleModel
{
private:
    typedef std::function<double(const double *, const double *)> vecFunc;
    struct ModelSize {Index nArg, nPar;};
public:
    // constructor
    DoubleModel(const Index nArg = 0, const Index nPar = 0,
                const vecFunc &f = nullFunction_);
    // destructor
    virtual ~DoubleModel(void) = default;
    // access
    virtual Index getNArg(void) const;
    virtual Index getNPar(void) const;
    void  setFunction(const Index nArg = 0, const Index nPar = 0,
                      const vecFunc &f = nullFunction_);
    // function call
    double operator()(const DVec &data, const DVec &par) const;
    double operator()(const std::vector<double> &data,
                      const std::vector<double> &par) const;
protected:
    // function call
    virtual double operator()(const double *data, const double *par) const;
private:
    // error checking
    void checkSize(const Index nArg, const Index nPar) const;
private:
    std::shared_ptr<ModelSize> size_;
    vecFunc                    f_;
    static const vecFunc       nullFunction_;
};

END_NAMESPACE

#endif // Latan_Model_hpp_
