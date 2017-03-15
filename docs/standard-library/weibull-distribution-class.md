---
title: Classe weibull_distribution | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- weibull_distribution
- std::weibull_distribution
- random/std::weibull_distribution
- std::weibull_distribution::reset
- random/std::weibull_distribution::reset
- std::weibull_distribution::a
- random/std::weibull_distribution::a
- std::weibull_distribution::b
- random/std::weibull_distribution::b
- std::weibull_distribution::param
- random/std::weibull_distribution::param
- std::weibull_distribution::min
- random/std::weibull_distribution::min
- std::weibull_distribution::max
- random/std::weibull_distribution::max
- std::weibull_distribution::operator()
- random/std::weibull_distribution::operator()
- std::weibull_distribution::param_type
- random/std::weibull_distribution::param_type
- std::weibull_distribution::param_type::a
- random/std::weibull_distribution::param_type::a
- std::weibull_distribution::param_type::b
- random/std::weibull_distribution::param_type::b
- std::weibull_distribution::param_type::operator==
- random/std::weibull_distribution::param_type::operator==
- std::weibull_distribution::param_type::operator!=
- random/std::weibull_distribution::param_type::operator!=
dev_langs:
- C++
helpviewer_keywords:
- weibull_distribution class
ms.assetid: f20b49d3-1b9a-41af-8db4-baf800eaa02b
caps.latest.revision: 15
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 491992306060125ab91d64560113f7f8a3b740b1
ms.openlocfilehash: 265754b7593a9654eab6f377d34d95268f1b9454
ms.lasthandoff: 02/25/2017

---
# <a name="weibulldistribution-class"></a>Classe weibull_distribution
Gera uma distribuição Weibull.  
  
## <a name="syntax"></a>Sintaxe  
```  
class weibull_distribution  
   {  
   public: 
    // types  
   typedef RealType result_type;  
   struct param_type; 

    // constructor and reset functions  
   explicit weibull_distribution(result_type a = 1.0, result_type b = 1.0);
   explicit weibull_distribution(const param_type& parm);
   void reset();

   // generating functions  
   template <class URNG>  
      result_type operator()(URNG& gen);
   template <class URNG>  
      result_type operator()(URNG& gen, const param_type& parm);
   
   // property functions  
   result_type a() const;
   result_type b() const;
   param_type param() const;
   void param(const param_type& parm);
   result_type min() const;
   result_type max() const;
   };  
```   
#### <a name="parameters"></a>Parâmetros  
*RealType*  
O tipo de resultado de ponto flutuante assume `double` como padrão. Para ver os tipos possíveis, consulte [\<random>](../standard-library/random.md).  
  
## <a name="remarks"></a>Comentários  
A classe de modelo descreve uma distribuição que produz valores de um tipo de ponto flutuante especificado pelo usuário ou um tipo `double` caso nenhum seja fornecido, distribuído de acordo com a Distribuição Weibull. A tabela a seguir contém links para artigos sobre cada um dos membros.  
  
||||  
|-|-|-|  
|[weibull_distribution::weibull_distribution](#weibull_distribution__weibull_distribution)|`weibull_distribution::a`|`weibull_distribution::param`|  
|`weibull_distribution::operator()`|`weibull_distribution::b`|[weibull_distribution::param_type](#weibull_distribution__param_type)|  
  
As funções de propriedade `a()` e `b()` retornam os respectivos valores para os parâmetros de distribuição armazenados *a* e *b*.  
  
O membro da propriedade `param()` define ou retorna o pacote de parâmetros de distribuição armazenado `param_type`.  

As funções membro `min()` e `max()` retornam o menor resultado possível e o maior resultado possível, respectivamente.  
  
A função membro `reset()` descarta qualquer valor armazenado em cache, de forma que o resultado da próxima chamada para `operator()` não dependerá dos valores obtidos do mecanismo antes da chamada.  
  
As funções membro `operator()` retornam o próximo valor gerado com base no mecanismo URNG, do pacote de parâmetros atual ou do pacote de parâmetros especificado.
  
Para obter mais informações sobre as classes de distribuição e seus membros, consulte [\<random>](../standard-library/random.md).  
  
Para obter informações detalhadas sobre a distribuição Weibull, consulte o artigo [Distribuição Weibull](http://go.microsoft.com/fwlink/LinkId=401115) da Wolfram MathWorld.  
  
## <a name="example"></a>Exemplo  
  
```cpp  
// compile with: /EHsc /W4  
#include <random>   
#include <iostream>  
#include <iomanip>  
#include <string>  
#include <map>  
  
void test(const double a, const double b, const int s) {  
  
    // uncomment to use a non-deterministic generator  
    //    std::random_device gen;  
    std::mt19937 gen(1701);  
  
    std::weibull_distribution<> distr(a, b);  
  
    std::cout << std::endl;  
    std::cout << "min() == " << distr.min() << std::endl;  
    std::cout << "max() == " << distr.max() << std::endl;  
    std::cout << "a() == " << std::fixed << std::setw(11) << std::setprecision(10) << distr.a() << std::endl;  
    std::cout << "b() == " << std::fixed << std::setw(11) << std::setprecision(10) << distr.b() << std::endl;  
  
    // generate the distribution as a histogram  
    std::map<double, int> histogram;  
    for (int i = 0; i < s; ++i) {  
        ++histogram[distr(gen)];  
    }  
  
    // print results  
    std::cout << "Distribution for " << s << " samples:" << std::endl;  
    int counter = 0;  
    for (const auto& elem : histogram) {  
        std::cout << std::fixed << std::setw(11) << ++counter << ": "  
            << std::setw(14) << std::setprecision(10) << elem.first << std::endl;  
    }  
    std::cout << std::endl;  
}  
  
int main()  
{  
    double a_dist = 0.0;  
    double b_dist = 1;  
  
    int samples = 10;  
  
    std::cout << "Use CTRL-Z to bypass data entry and run using default values." << std::endl;  
    std::cout << "Enter a floating point value for the 'a' distribution parameter (must be greater than zero): ";  
    std::cin >> a_dist;  
    std::cout << "Enter a floating point value for the 'b' distribution parameter (must be greater than zero): ";  
    std::cin >> b_dist;  
    std::cout << "Enter an integer value for the sample count: ";  
    std::cin >> samples;  
  
    test(a_dist, b_dist, samples);  
}  
  
```  
  
## <a name="output"></a>Saída  
 Primeira execução:  
  
```Output  
Use CTRL-Z to bypass data entry and run using default values.  
Enter a floating point value for the 'a' distribution parameter (must be greater than zero): 1  
Enter a floating point value for the 'b' distribution parameter (must be greater than zero): 1  
Enter an integer value for the sample count: 10  
 
min() == 0  
max() == 1.79769e+308  
a() == 1.0000000000  
b() == 1.0000000000  
Distribution for 10 samples:  
    1: 0.0936880533  
    2: 0.1225944894  
    3: 0.6443593183  
    4: 0.6551171649  
    5: 0.7313457551  
    6: 0.7313557977  
    7: 0.7590097389  
    8: 1.4466885214  
    9: 1.6434088411  
    10: 2.1201210996  
```  
  
 Segunda execução:  
  
```Output  
Use CTRL-Z to bypass data entry and run using default values.  
Enter a floating point value for the 'a' distribution parameter (must be greater than zero): .5  
Enter a floating point value for the 'b' distribution parameter (must be greater than zero): 5.5  
Enter an integer value for the sample count: 10  
 
min() == 0  
max() == 1.79769e+308  
a() == 0.5000000000  
b() == 5.5000000000  
Distribution for 10 samples:  
    1: 0.0482759823  
    2: 0.0826617486  
    3: 2.2835941207  
    4: 2.3604817485  
    5: 2.9417663742  
    6: 2.9418471657  
    7: 3.1685268104  
    8: 11.5109922290  
    9: 14.8543594043  
    10: 24.7220241239  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<random>  
  
 **Namespace:** std  
  
##  <a name="a-nameweibulldistributionweibulldistributiona--weibulldistributionweibulldistribution"></a><a name="weibull_distribution__weibull_distribution"></a> weibull_distribution::weibull_distribution  
  
```  
explicit weibull_distribution(result_type a = 1.0, result_type b = 1.0);
explicit weibull_distribution(const param_type& parm);
```  
  
### <a name="parameters"></a>Parâmetros  
*a*  
O parâmetro de distribuição `a`.  
  
*b*  
O parâmetro de distribuição `b`.  
  
*parm*  
A estrutura `param_type` usada para construir a distribuição.  
  
### <a name="remarks"></a>Comentários  
 **Precondição:** `0.0 < a` e `0.0 < b`  
  
 O primeiro construtor constrói um objeto cujo valor `a` armazenado contém o valor *a* e cujo valor armazenado `b` contém o valor *b*.  
  
 O segundo construtor cria um objeto cujos parâmetros armazenados são inicializados de *parm*. Você pode chamar a função de membro `param()` para obter e definir os parâmetros atuais de uma distribuição existente.  
  
##  <a name="a-nameweibulldistributionparamtypea--weibulldistributionparamtype"></a><a name="weibull_distribution__param_type"></a> weibull_distribution::param_type  
 Armazena os parâmetros da distribuição.  
```  
struct param_type {  
   typedef weibull_distribution<result_type> distribution_type;  
   param_type(result_type a = 1.0, result_type b = 1.0);
   result_type a() const;
   result_type b() const;

   bool operator==(const param_type& right) const;
   bool operator!=(const param_type& right) const;
   };  
```
### <a name="parameters"></a>Parâmetros  
*a*  
O parâmetro de distribuição `a`.  
  
*b*  
O parâmetro de distribuição `b`.  
  
*right*  
O objeto `param_type` a ser comparado a este.  
  
### <a name="remarks"></a>Comentários  
**Precondição:** `0.0 < a` e `0.0 < b`  
  
Essa estrutura pode ser enviada ao construtor de classe de distribuição na instanciação, para a função de membro `param()` para definir os parâmetros armazenados de uma distribuição existente e para `operator()` a ser usado no lugar dos parâmetros armazenados.  
  
## <a name="see-also"></a>Consulte também  
 [\<random>](../standard-library/random.md)




