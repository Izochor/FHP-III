#ifndef FHPMAIN_H
#define FHPMAIN_H

#include <iostream>

#include <QVector>

#include <gsl/gsl_rng.h>

#include "init.hpp"
#include "utils.hpp"
#include "fhp.hpp"
#include "measurements.hpp"

int fhpmain(QVector<double> &x,QVector<double> &y,QVector<double> &conv);

#endif // FHPMAIN_H
