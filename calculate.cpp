#include "calculate.hpp"

/**
 * @brief Calculate::Calculate
 * @param parent
 * @author Louis P Meadows
 * @date November 11th 2019
 * @copyright Sciton
 */
Calculate::Calculate(QObject* parent) : QObject(parent)
{

}

/**
 * @brief Calculate::matProduct
 * @param jm
 * @param jv
 * @return
 * @author Louis P Meadows
 * @date November 11th 2019
 * @copyright Sciton
 */
Calculate::vector Calculate::matrixProduct(matrix jm, vector jv)
{
        //    W.x = M.a1*V.x + M.a2*V.y+M.a3*V.z;
        //    W.y = M.b1*V.x + M.b2*V.y+M.b3*V.z;
        //    W.z = M.ca1*V.x + M.c2*V.y+M.c3*V.z;
        vector result;
        result.x = jm.a1 * jv.x + jm.a2 * jv.y + jm.a3 * jv.z;
        result.y = jm.b1 * jv.x + jm.b2 * jv.y + jm.b3 * jv.z;
        result.z = jm.c1 * jv.x + jm.c2 * jv.y + jm.c3 * jv.z;
        return result;
}

/**
 * @brief Calculate::rotationMatrix
 * @param pitch
 * @param roll
 * @param yaw
 * @return
 * @author Louis P Meadows
 * @date November 11th 2019
 * @copyright
 */
Calculate::matrix
Calculate::rotationMatrix(double pitch, double roll, double yaw)
{
        Calculate::matrix m;

        m = {cos(pitch)* cos(yaw),
                 cos(yaw)* sin(pitch)* sin(roll) - cos(roll)* sin(yaw),
                 cos(roll)* cos(yaw)* sin(pitch) + sin(roll)* sin(yaw),
                 cos(pitch)* sin(yaw),
                 cos(roll)* cos(yaw) + sin(pitch)* sin(roll)* sin(yaw),
                 static_cast<double>(-1.0)* cos(yaw)* sin(roll) +
                 cos(roll)* sin(pitch)* sin(yaw),
                 static_cast<double>(-1.0)* sin(pitch),
                 cos(pitch)* sin(roll),
                 cos(pitch)* cos(roll)
                };

        return m;
}

/**
 * @brief Calculate::dotProduct
 * @param x1
 * @param y1
 * @param z1
 * @param x2
 * @param y2
 * @param z2
 * @return
 * @author Louis P Meadows
 */
double Calculate::dotProduct(double x1, double y1, double z1, double x2,
                                                         double y2, double z2)
{
        double a = (x1 * x2) + (y1 * y2) + (z1 * z2);
        return a;
}

/**
 * @brief Calculate::norm
 * @param x
 * @param y
 * @param z
 * @return
 * @author Louis P Meadows
 */
double Calculate::norm(double x, double y, double z)
{
        double n;
        n = std::sqrt(x * x + y * y + z * z);
        return n;
}

/**
 * @brief Calculate::vectorAngle
 * @param x1
 * @param y1
 * @param z1
 * @param x2
 * @param y2
 * @param z2
 * @return
 * @author Louis P Meadows
 */
double Calculate::vectorAngle(double x1, double y1, double z1, double x2,
                                                          double y2, double z2)
{
        double angle;
        vector v1 = {x1, y1, z1};
        vector v2 = {x2, y2, z2};

        angle = acos(vectorProduct(v1, v2) / (norm(x1, y1, z1) * norm(x2, y2, z2)));
        return angle;
}

/**
 * @brief Calculate::vectorProduct
 * @param jv1
 * @param jv2
 * @return
 * @author Louis P Meadows
 */
double Calculate::vectorProduct(vector jv1, vector jv2)
{
        double result;
        result = jv1.x * jv2.x + jv1.y * jv2.y + jv1.z * jv2.z;
        return result;
}

/**
 * @brief Calculate::vecTimeMat
 * @param v
 * @param m
 * @return
 * @author Louis P Meadows
 */
Calculate::vector Calculate::vecTimeMat(vector v, matrix m)
{
        vector w;

        w.x = v.x * m.a1 + v.y * m.b1 + v.z * m.c1;
        w.y = v.x * m.a2 + v.y * m.b2 + v.z * m.c2;
        w.z = v.x * m.a3 + v.y * m.b3 + v.z * m.c3;
        return (w);
}

/**
 * @brief Calculate::norm
 * @param v
 * @return
 * @author Louis P Meadows
 */
double Calculate::norm(vector v)
{
        return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

/**
 * @brief Calculate::dotProd
 * @param v
 * @param u
 * @return
 * @author Louis P Meadows
 */
double Calculate::dotProd(vector v, vector u)
{
        return (v.x * u.x + v.y * u.y + v.z * u.z);
}

/**
 * @brief Calculate::vecAngle
 * @param v
 * @param u
 * @return
 * @author Louis P Meadows
 */
double Calculate::vecAngle(vector v, vector u)
{
        return (acos(dotProd(v, u) / (norm(v) * norm(u))) * 180. / M_PI);
}

/**
 * @brief Calculate::matTimesVec
 * @param m
 * @param v
 * @return
 * @author Louis P Meadows
 */
Calculate::vector Calculate::matTimesVec(matrix m, vector v)
{
        vector w;

        w.x = m.a1 * v.x + m.a2 * v.y + m.a3 * v.z;
        w.y = m.b1 * v.x + m.b2 * v.y + m.b3 * v.z;
        w.z = m.c1 * v.x + m.c2 * v.y + m.c3 * v.z;
        return (w);
}
