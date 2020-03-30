#ifndef CALCULATE_HPP
#define CALCULATE_HPP
#include "math.h"
#include <QObject>

class Calculate : public QObject
{
        Q_OBJECT
public:
        explicit Calculate(QObject* parent = nullptr);
        // Roll, pitch and yaw are referred to in one word as the attitude.
        struct attitude
        {
                double roll, pitch, yaw;
        };

        struct vector
        {
                double x, y, z;
        };


        struct matrix
        {
                double a1, a2, a3;
                double b1, b2, b3;
                double c1, c2, c3;
        };

        vector matrixProduct(matrix jm, vector jv);

        matrix rotationMatrix(double pitch, double roll, double yaw);

        double dotProduct(double x1, double y1, double z1, double x2, double y2, double z2);
        double norm(double x, double y, double z);

        double vectorAngle(double x1, double y1, double z1, double x2, double y2, double z2);
        double vectorProduct(vector jv1, vector jv2);
        vector vecTimeMat(vector v, matrix m);
        double norm(vector v);
        double dotProd(vector v, vector u);
        double vecAngle(vector v, vector u);
        vector matTimesVec(matrix m, vector v);
signals:

public slots:
};

#endif // CALCULATE_HPP
