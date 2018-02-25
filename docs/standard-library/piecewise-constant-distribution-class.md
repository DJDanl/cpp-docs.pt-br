---
title: Classe piecewise_constant_distribution | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- random/std::piecewise_constant_distribution
- random/std::piecewise_constant_distribution::reset
- random/std::piecewise_constant_distribution::intervals
- random/std::piecewise_constant_distribution::densities
- random/std::piecewise_constant_distribution::param
- random/std::piecewise_constant_distribution::min
- random/std::piecewise_constant_distribution::max
- random/std::piecewise_constant_distribution::operator()
- random/std::piecewise_constant_distribution::param_type
- random/std::piecewise_constant_distribution::param_type::intervals
- random/std::piecewise_constant_distribution::param_type::densities
- random/std::piecewise_constant_distribution::param_type::operator==
- random/std::piecewise_constant_distribution::param_type::operator!=
dev_langs:
- C++
helpviewer_keywords:
- std::piecewise_constant_distribution [C++]
- std::piecewise_constant_distribution [C++], reset
- std::piecewise_constant_distribution [C++], intervals
- std::piecewise_constant_distribution [C++], densities
- std::piecewise_constant_distribution [C++], param
- std::piecewise_constant_distribution [C++], min
- std::piecewise_constant_distribution [C++], max
- std::piecewise_constant_distribution [C++], param_type
- std::piecewise_constant_distribution [C++], param_type
ms.assetid: 2c9a21fa-623e-4d63-b827-3f1556b6dedb
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 923398932307845bffb95e8ef3fd7ef83e38530f
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="piecewiseconstantdistribution-class"></a>Classe piecewise_constant_distribution
Gera uma distribuição em trechos que tem intervalos com largura variável e probabilidade uniforme em cada intervalo.  
  
## <a name="syntax"></a>Sintaxe  
```  
template<class RealType = double>  
class piecewise_constant_distribution  
   {  
public:  
   // types  
   typedef RealType result_type;  
   struct param_type;  
   
   // constructor and reset functions  
   piecewise_constant_distribution();
   template <class InputIteratorI, class InputIteratorW>  
   piecewise_constant_distribution(
       InputIteratorI firstI, InputIteratorI lastI, InputIteratorW firstW);
   template <class UnaryOperation>  
   piecewise_constant_distribution(
      initializer_list<result_type> intervals, UnaryOperation weightfunc);
   template <class UnaryOperation>  
   piecewise_constant_distribution(
      size_t count, result_type xmin, result_type xmax, UnaryOperation weightfunc);
   explicit piecewise_constant_distribution(const param_type& parm);
   void reset();

   // generating functions  
   template <class URNG>  
   result_type operator()(URNG& gen);
   template <class URNG>  
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

### <a name="parameters"></a>Parâmetros  
*RealType*  
O tipo de resultado de ponto flutuante assume `double` como padrão. Para encontrar os tipos possíveis, consulte [\<random>](../standard-library/random.md).  
  
## <a name="remarks"></a>Comentários  
Essa distribuição de amostragem tem intervalos de largura variável e probabilidade uniforme em cada intervalo. Para obter mais informações sobre outras distribuições de amostragem, consulte [piecewise_linear_distribution Class](../standard-library/piecewise-linear-distribution-class.md) e [discrete_distribution](../standard-library/discrete-distribution-class.md).  
  
A tabela a seguir contém links para artigos sobre cada um dos membros:  
  
||||  
|-|-|-|  
|[piecewise_constant_distribution](#piecewise_constant_distribution)|`piecewise_constant_distribution::intervals`|`piecewise_constant_distribution::param`|  
|`piecewise_constant_distribution::operator()`|`piecewise_constant_distribution::densities`|[param_type](#param_type)|  
  
A função da propriedade `intervals()` retorna um `vector<result_type>` com o conjunto de intervalos armazenados da distribuição.  
  
A função da propriedade `densities()` retorna um `vector<result_type>` com as densidades armazenadas para cada conjunto de intervalos. Essas densidades são calculadas de acordo com os pesos indicados nos parâmetros do construtor.  
  
O membro da propriedade `param()` define ou retorna o pacote de parâmetros de distribuição armazenado `param_type`.  

As funções membro `min()` e `max()` retornam o menor resultado possível e o maior resultado possível, respectivamente.  
  
A função membro `reset()` descarta qualquer valor armazenado em cache, de forma que o resultado da próxima chamada para `operator()` não dependerá dos valores obtidos do mecanismo antes da chamada.  
  
As funções membro `operator()` retornam o próximo valor gerado com base no mecanismo URNG, do pacote de parâmetros atual ou do pacote de parâmetros especificado.
  
Para obter mais informações sobre as classes de distribuição e seus membros, consulte [\<random>](../standard-library/random.md).  
  
## <a name="example"></a>Exemplo  
  
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
    vector<double> weights{ 1, 5, 10 };  
  
    piecewise_constant_distribution<double> distr(intervals.begin(), intervals.end(), weights.begin());  
  
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
        cout << setw(5) << elem.first << '-' << elem.first+1 << ' ' << string(elem.second, ':') << endl;  
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
  
```Output  
Use CTRL-Z to bypass data entry and run using default values.
Enter an integer value for the sample count: 100
min() == 0
max() == 15
intervals (index: interval):
          0:   0.0000000000          
          1:   1.0000000000          
          2:   6.0000000000          
          3:  15.0000000000
densities (index: density):
          0:   0.0625000000          
          1:   0.0625000000          
          2:   0.0694444444
Distribution for 100 samples:
    0-1 :::::::    
    1-2 ::::::    
    2-3 :::::    
    3-4 ::::::    
    4-5 :::::::    
    5-6 ::::::    
    6-7 :::    
    7-8 ::::::::::    
    8-9 ::::::    
    9-10 ::::::::::::   
    10-11 :::::   
    11-12 ::::::   
    12-13 :::::::::   
    13-14 ::::   
    14-15 ::::::::  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<random>  
  
 **Namespace:** std  
  
##  <a name="piecewise_constant_distribution"></a>  piecewise_constant_distribution::piecewise_constant_distribution  
Constrói a distribuição.  
  
```  
// default constructor  
piecewise_constant_distribution();
 
// constructs using a range of intervals, [firstI, lastI), with  
// matching weights starting at firstW  
template <class InputIteratorI, class InputIteratorW>  
piecewise_constant_distribution(InputIteratorI firstI, InputIteratorI lastI, InputIteratorW firstW);
 
// constructs using an initializer list for range of intervals,  
// with weights generated by function weightfunc  
template <class UnaryOperation>  
piecewise_constant_distribution(initializer_list<RealType>  
intervals, UnaryOperation weightfunc);
 
// constructs using an initializer list for range of count intervals,  
// distributed uniformly over [xmin,xmax] with weights generated by function weightfunc  
template <class UnaryOperation>  
piecewise_constant_distribution(size_t count, RealType xmin, RealType xmax, UnaryOperation weightfunc);
 
// constructs from an existing param_type structure  
explicit piecewise_constant_distribution(const param_type& parm);
```  
  
### <a name="parameters"></a>Parâmetros  
 `firstI`  
 Um iterador de entrada do primeiro elemento no intervalo de distribuição.  
  
 `lastI`  
 Um iterador de entrada do último elemento no intervalo de distribuição.  
  
 `firstW`  
 Um iterador de entrada do primeiro elemento no intervalo de pesos.  
  
 `intervals`  
 Uma [initializer_list](../cpp/initializers.md) com os intervalos da distribuição.  
  
 `count`  
 O número de elementos no intervalo de distribuição.  
  
 `xmin`  
 O valor mais baixo no intervalo de distribuição.  
  
 `xmax`  
 O valor mais alto no intervalo de distribuição. Deve ser maior que `xmin`.  
  
 `weightfunc`  
 O objeto que representa a função de probabilidade para a distribuição. Deve ser possível converter o valor retornado e o parâmetro em `double`.  
  
 `parm`  
 A estrutura do parâmetro usada para construir a distribuição.  
  
### <a name="remarks"></a>Comentários  
O construtor padrão define os parâmetros armazenados de modo que haja um intervalo, 0 a 1, com uma densidade de probabilidade de 1.  
  
O construtor do intervalo do iterador  
```  
template <class InputIteratorI, class InputIteratorW>  
piecewise_constant_distribution(InputIteratorI firstI, InputIteratorI lastI,  
    InputIteratorW firstW);
```  
  
constrói um objeto de distribuição com intervalos de iteradores sobre a sequência [`firstI`, `lastI`) e uma sequência de peso correspondente começando em `firstW`.  
  
O construtor da lista do inicializador  
```  
template <class UnaryOperation>  
piecewise_constant_distribution(initializer_list<result_type>  
intervals,   
    UnaryOperation weightfunc);
```  
  
constrói um objeto de distribuição com intervalos da lista do inicializador `intervals` e pesos gerados da função `weightfunc`.  
  
O construtor definido como  
```  
template <class UnaryOperation>  
piecewise_constant_distribution(size_t count, result_type xmin, result_type xmax,  
    UnaryOperation weightfunc);
```  
  
constrói um objeto de distribuição com intervalos `count` distribuídos uniformemente por [`xmin,xmax`], atribuindo a cada intervalo pesos de acordo com a função `weightfunc` e `weightfunc` deve aceitar um parâmetro e ter um valor retornado, sendo que ambos podem ser convertidos em `double`. **Pré-condição:** `xmin < xmax`  
  
O construtor definido como  
```  
explicit piecewise_constant_distribution(const param_type& parm);
```  
  
constrói um objeto de distribuição usando `parm` como estrutura de parâmetro armazenada.  
  
##  <a name="param_type"></a>  piecewise_constant_distribution::param_type  
Armazena todos os parâmetros da distribuição.  
  
```    
struct param_type {  
   typedef piecewise_constant_distribution<result_type> distribution_type;  
   param_type();
   template <class IterI, class IterW>  
   param_type(IterI firstI, IterI lastI, IterW firstW);
   template <class UnaryOperation>  
   param_type(size_t count, result_type xmin, result_type xmax, UnaryOperation weightfunc);
   std::vector<result_type> densities() const;
   std::vector<result_type> intervals() const;
     
   bool operator==(const param_type& right) const;
   bool operator!=(const param_type& right) const;
   };  
```  
  
### <a name="parameters"></a>Parâmetros  
Consulte os parâmetros do construtor para o [piecewise_constant_distribution](#piecewise_constant_distribution).  
  
### <a name="remarks"></a>Comentários  
 **Pré-condição:** `xmin < xmax`  
  
Essa estrutura pode ser enviada ao construtor de classe de distribuição na instanciação, para a função de membro `param()` para definir os parâmetros armazenados de uma distribuição existente e para `operator()` a ser usado no lugar dos parâmetros armazenados.  
  
## <a name="see-also"></a>Consulte também  
[\<random>](../standard-library/random.md)   
[piecewise_linear_distribution](../standard-library/piecewise-linear-distribution-class.md)


