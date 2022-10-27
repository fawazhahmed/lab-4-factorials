// CS 400 lab 4: calculate factorials

#include <iostream>
#include <vector> 
#include <list>

void printList(const std::list<int>& l) {               //calls this function using this linked list
    for (auto it = l.rbegin(); it != l.rend(); it++) {  //loop from beginning to end but reversed
        std::cout << *it;                               //display those numbers
    }
}

void printVector(const std::vector<int>& l) {               //calls this function using vectors
    for (auto it = l.rbegin(); it != l.rend(); it++) {      //loop from beginning to end but reversed
        std::cout << *it;                                   //display those numbers
    }
}

// TA will explain this example: 
// 24 * 5 = 120
void factorial_5() {
    std::list<int> fact;                        //initialize
    fact.push_back(4);                          //push these 2 values into the list
    fact.push_back(2);

    // print the list fact: 24 should be the output
    printList(fact);                            
    std::cout << " * 5 = ";

    // now multiple 5 with each digit from fact 
    int carry{ 0 };                             //initialize this carry
    for (auto it = fact.begin(); it != fact.end(); it++) {      //loop from beginning to end
        int product = 5 * (*it) + carry;        //do this calculation
        *it = product % 10;         // same as hw 3
        carry = product / 10;       // same as hw 3 
    }

    // handle extra carry
    while (carry != 0) {
        fact.push_back(carry % 10);     // add one digit per node 
        carry = carry / 10;             // update carry; 
    }
    printList(fact);    // should be 120 from the output;
}

void factorial_10()
{
    unsigned int long long result = 1;      //initialize this value set to 1

    for (auto i = 2; i <= 10; i++)          //loop for values 2-10
    {
         result *= i;                       //multiply all of them 
    }
    std::cout << result;                    //display it 
}
void factorial_100()
{
    std::vector<int> v;     //initialize these and pushback 1 to vector
    v.push_back(1);
    int carry{ 0 };

    for (auto i = 2; i <= 100; i++)     //loop until 100
    {
        for (auto j = 0; j<v.size(); j++)       //loop for interior vector
        {
            int p = v.at(j) * i + carry;       //do these calculation similar to factorial of 5
            v.at(j) = p % 10;
            carry = p / 10;
        }   
        while (carry) {                         //if there is a carry
            int carry_c = carry % 10;           //update for new carry
            v.push_back(carry_c);               //push back that value to end of vector
            carry = carry / 10;                 //set new value of carry and update it          
        }
    }
    printVector(v);                             //call the print function of a vector
}

void factorial_1000()
{
    std::vector<int> v;                     //initialize all these similar to the 100!
    v.push_back(1);                         
    int carry{ 0 };
        
    for (auto i = 2; i <= 1000; i++)        //loop until it reaches 1000 
    {
        for (auto j = 0; j < v.size(); j++)     //interior loop of the vector
        {
            int p = v.at(j) * i + carry;        //do these calculations for multiplying the numbers
            v.at(j) = p % 10;
            carry = p / 10;
        }
        while (carry) {
            int carry_c = carry % 10;   //while there is a carry, update it and set it to new value and pushback that value into vector
            v.push_back(carry_c);
            carry = carry / 10;
        }
    }
    printVector(v);             //call the vector print function
}



int main() {
    // TODO: call the function to calculcate factorials of following numbers: 
    // 10! = 3628800
    // 100! = 93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000
    // 1000! = 402387260077093773543702433923003985719374864210714632543799910429938512398629020592044208486969404800479988610197196058631666872994808558901323829669944590997424504087073759918823627727188732519779505950995276120874975462497043601418278094646496291056393887437886487337119181045825783647849977012476632889835955735432513185323958463075557409114262417474349347553428646576611667797396668820291207379143853719588249808126867838374559731746136085379534524221586593201928090878297308431392844403281231558611036976801357304216168747609675871348312025478589320767169132448426236131412508780208000261683151027341827977704784635868170164365024153691398281264810213092761244896359928705114964975419909342221566832572080821333186116811553615836546984046708975602900950537616475847728421889679646244945160765353408198901385442487984959953319101723355556602139450399736280750137837615307127761926849034352625200015888535147331611702103968175921510907788019393178114194545257223865541461062892187960223838971476088506276862967146674697562911234082439208160153780889893964518263243671616762179168909779911903754031274622289988005195444414282012187361745992642956581746628302955570299024324153181617210465832036786906117260158783520751516284225540265170483304226143974286933061690897968482590125458327168226458066526769958652682272807075781391858178889652208164348344825993266043367660176999612831860788386150279465955131156552036093988180612138558600301435694527224206344631797460594682573103790084024432438465657245014402821885252470935190620929023136493273497565513958720559654228749774011413346962715422845862377387538230483865688976461927383814900140767310446640259899490222221765904339901886018566526485061799702356193897017860040811889729918311021171229845901641921068884387121855646124960798722908519296819372388642614839657382291123125024186649353143970137428531926649875337218940694281434118520158014123344828015051399694290153483077644569099073152433278288269864602789864321139083506217095002597389863554277196742822248757586765752344220207573630569498825087968928162753848863396909959826280956121450994871701244516461260379029309120889086942028510640182154399457156805941872748998094254742173582401063677404595741785160829230135358081840096996372524230560855903700624271243416909004153690105933983835777939410970027753472000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

    //call the functions above and display the output
    std::cout << "Factorial of 5: " << std::endl;
    factorial_5();
    std::cout << std::endl;
    std::cout << "Factorial of 10: " << std::endl;
    factorial_10();
    std::cout << std::endl;
    std::cout << "Factorial of 100: " << std::endl;
    factorial_100();
    std::cout << std::endl;
    std::cout << "Factorial of 1000: " << std::endl;
    factorial_1000();

    return 0;
}