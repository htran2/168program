#ifndef ROUTE_H
#define ROUTE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Route {
    bool isSum168;
    vector<double> routes;
    double sumRoutes;
    public:
        Route(){
            sumRoutes = 0;
            isSum168 = false;
        }
        void pushRoute(double routeTime){
            routes.push_back(routeTime);
            sumRoutes += routeTime;
        }

        double popRoute(){
            if(routes.size() <= 0){
                return -1;
            }
            double lastRoute = routes[routes.size()-1];
            routes.pop_back();
            sumRoutes -= lastRoute;
            return lastRoute;
        }

        double at(int i){
            if(i < 0 || i > routes.size()){
                return -1;
            }
            return routes[i];
        }

        int getRouteSize(){
            return routes.size();
        }
        
        bool getBoolResult(){
            return isSum168;
        }

        void setBoolResult(bool result){
            isSum168 = result;
        }

        double getSumRoutes(){
            return sumRoutes;
        }

        void printData(){
            
            cout <<"Sum = " << sumRoutes << endl;
            int size = routes.size();
            double route;
            for(int i = 0; i < size; i ++ ){
                route = routes[i];
                int numPrint = 1;
                for(int j = i+1; j < size; j++){
                    if(routes[j] == route){
                        numPrint++;
                    }
                }
                cout << "\t" << route << " \t(" << numPrint << ")" << endl;
                i += numPrint - 1;
            }
            cout << "########################################" << endl;
        }


};

#endif