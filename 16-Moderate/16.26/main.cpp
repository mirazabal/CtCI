#include <cstdlib>
#include <iostream>
#include <string>

double easyop(std::string::const_iterator oper, double right, double left )
{
//    assert(*oper == '+' || *oper == '-' )
    if(*oper == '+' )
        return right + left;
    else if(*oper == '-')
        return right - left;
    else
        throw;
}


std::string::const_iterator complexop(std::string::const_iterator it, double leftVal, double& result)
{
    auto it_loop = it;
    while( *(it_loop + 1) != '+' && *(it_loop + 1) != '-' &&  *(it_loop + 1) !=  '/' && *(it_loop + 1) != '*'){
        it_loop++;
    }
    int tempVal = std::atoi( std::string(it, it_loop +1).c_str() );

    if( *(it-1) == '*' )
       result = leftVal * tempVal;

    if( *(it-1) == '/' )
       result = leftVal / tempVal;

    auto retIt = it_loop;
    if(*(it_loop + 1 ) == '*' ||  *(it_loop + 1 ) == '/' )
            retIt = complexop( it_loop + 2, result, result);

    return retIt;
}


double compute(std::string const& str){

    auto it_begin = std::begin(str);
    auto it_op = std::end(str);
    double retVal {0};
    

    for(auto it = std::begin(str); it != std::end(str); ++it){

        if( *(it + 1) == '+' || *(it+1) == '-' )
        {
            int tempVal = std::atoi( std::string(it_begin, it+1).c_str() );
            if (it_op != std::end(str)) 
                retVal = easyop(it_op, retVal, tempVal);
            else
                retVal = tempVal;

            it += 1;
            it_begin = it + 2;
            it_op = it + 1;

        } else if ( *(it + 1) == '*'  ||  *(it + 1) == '/'){
            double complexVal = 0;
            int tempVal = std::atoi( std::string(it_begin, it+1).c_str() );
            it = complexop(it + 2, tempVal, complexVal);
            if(it_op != std::end(str) )
                retVal = easyop(it_op, retVal, complexVal);
            else
                retVal = complexVal;
            it_begin = it+2;
            it_op = it + 1;

        }else if ( it+1 == std::end(str) ){
            int tempVal = std::atoi( std::string(it_begin, std::end(str)).c_str() );
            retVal = easyop(it_op,retVal, tempVal);
        }
    }
    return retVal;
}

int main()
{
    std::cout << compute("2*3+5/6*3+15" ) << '\n';
}
