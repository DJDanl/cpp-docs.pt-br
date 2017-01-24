---
title: "Classe piecewise_linear_distribution | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "std::tr1::piecewise_linear_distribution"
  - "tr1.piecewise_linear_distribution"
  - "piecewise_linear_distribution"
  - "std.tr1.piecewise_linear_distribution"
  - "random/std::tr1::piecewise_linear_distribution"
  - "tr1::piecewise_linear_distribution"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe piecewise_linear_distribution"
ms.assetid: cd141152-7163-4754-8f98-c6d6500005e0
caps.latest.revision: 21
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe piecewise_linear_distribution
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Gera um em partes distribuição linear que tem intervalos de largura variável com probabilidade linearmente variável em cada intervalo.  
  
## Sintaxe  
  
```  
template<class RealType = double>  
class piecewise_linear_distribution  
{  
public:  
    // types  
    typedef RealType result_type;  
    struct param_type;  
    // constructor and reset functions  
    piecewise_linear_distribution();  
    template<class InputIteratorI, class InputIteratorW>  
    piecewise_linear_distribution(InputIteratorI firstI, InputIteratorI lastI, InputIteratorW firstW);  
    template<class UnaryOperation>  
    piecewise_linear_distribution(initializer_list<RealType> intervals, UnaryOperation weightfunc);  
    template<class UnaryOperation>  
    piecewise_linear_distribution(size_t count, RealType xmin, RealType xmax, UnaryOperation weightfunc);  
    explicit piecewise_linear_distribution(const param_type& parm);  
    void reset();  
    // generating functions  
    template<class URNG>  
    result_type operator()(URNG& gen);  
    template<class URNG>  
    result_type operator()(URNG& gen, const param_type& parm);  
    // property functions  
    vector<result_type> intervals() const;  
    vector<result_type> densities() const;  
    param_type param() const;  
    void param(const param_type& parm);  
    result_type min() const;  
    result_type max() const;  
};  
```  
  
#### Parâmetros  
 `RealType`  
 O tipo de resultado, padrões de ponto flutuante `double`. Para os tipos possíveis, consulte [\<random\>](../standard-library/random.md).  
  
## Comentários  
 Essa distribuição de amostragem tem intervalos de largura variável com probabilidade linearmente variável em cada intervalo. Para obter informações sobre outras distribuições de amostragem, consulte [piecewise\_constant\_distribution](../Topic/piecewise_constant_distribution%20Class.md) e [discrete\_distribution](../standard-library/discrete-distribution-class.md).  
  
 A seguinte tabela contém links para artigos sobre membros individuais:  
  
||||  
|-|-|-|  
|[piecewise\_linear\_distribution::piecewise\_linear\_distribution](../Topic/piecewise_linear_distribution::piecewise_linear_distribution.md)|`piecewise_linear_distribution::intervals`|`piecewise_linear_distribution::param`|  
|`piecewise_linear_distribution::operator()`|`piecewise_linear_distribution::densities`|[piecewise\_linear\_distribution::param\_type](../Topic/piecewise_linear_distribution::param_type.md)|  
  
 A função de propriedade `intervals()` retorna um `vector<RealType>` com o conjunto de intervalos armazenados da distribuição.  
  
 A função de propriedade `densities()` retorna um `vector<RealType>` com as densidades armazenadas para cada conjunto de intervalos que são calculadas de acordo com os pesos indicados nos parâmetros do construtor.  
  
 Para obter mais informações sobre distribuição de classes e seus membros, consulte [\<random\>](../standard-library/random.md).  
  
## Exemplo  
  
```cpp  
// compile with: /EHsc /W4  
#include <random>   
#include <iostream>  
#include <iomanip>  
#include <string>  
#include <map>  
  
using namespace std;  
  
void test(const int s) {  
  
    // uncomment to use a non-deterministic generator  
    // random_device rd;  
    // mt19937 gen(rd());  
    mt19937 gen(1701);  
  
    // Three intervals, non-uniform: 0 to 1, 1 to 6, and 6 to 15  
    vector<double> intervals{ 0, 1, 6, 15 };  
    // weights determine the densities used by the distribution  
    vector<double> weights{ 1, 5, 5, 10 };  
  
    piecewise_linear_distribution<double> distr(intervals.begin(), intervals.end(), weights.begin());  
  
    cout << endl;  
    cout << "min() == " << distr.min() << endl;  
    cout << "max() == " << distr.max() << endl;  
    cout << "intervals (index: interval):" << endl;  
    vector<double> i = distr.intervals();  
    int counter = 0;  
    for (const auto& n : i) {  
        cout << fixed << setw(11) << counter << ": " << setw(14) << setprecision(10) << n << endl;  
        ++counter;  
    }  
    cout << endl;  
    cout << "densities (index: density):" << endl;  
    vector<double> d = distr.densities();  
    counter = 0;  
    for (const auto& n : d) {  
        cout << fixed << setw(11) << counter << ": " << setw(14) << setprecision(10) << n << endl;  
        ++counter;  
    }  
    cout << endl;  
  
    // generate the distribution as a histogram  
    map<int, int> histogram;  
    for (int i = 0; i < s; ++i) {  
        ++histogram[distr(gen)];  
    }  
  
    // print results  
    cout << "Distribution for " << s << " samples:" << endl;  
    for (const auto& elem : histogram) {  
        cout << setw(5) << elem.first << '-' << elem.first + 1 << ' ' << string(elem.second, ':') << endl;  
    }  
    cout << endl;  
}  
  
int main()  
{  
    int samples = 100;  
  
    cout << "Use CTRL-Z to bypass data entry and run using default values." << endl;  
    cout << "Enter an integer value for the sample count: ";  
    cin >> samples;  
  
    test(samples);  
}  
  
```  
  
## Saída  
  
```Output  
Use CTRL-Z para ignorar a entrada de dados e executar usando valores padrão. Insira um valor inteiro para a contagem de amostras: 100min() = = 0max() = = 15intervals (índice: intervalo): 0: 0.0000000000 1: 1.0000000000 2: 6.0000000000 15.0000000000densities: 3 (índice: densidade): 0: 0.0645161290 1: 0.3225806452 2: 0.3225806452 3: 0.6451612903Distribution para 100 amostras: 0-1: 1 ou 2: 2 a 3: 3-4: 4-5: 5-6: 6 e 7: 7-8: 8 e 9: 9 e 10: 10-11: 11-12: 12-13: 13 e 14: 14 e 15:  
```  
  
## Requisitos  
 **Cabeçalho:** \< random \>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<random\>](../standard-library/random.md)