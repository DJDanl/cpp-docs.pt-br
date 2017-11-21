---
title: Classe extreme_value_distribution | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- random/std::extreme_value_distribution
- random/std::extreme_value_distribution::reset
- random/std::extreme_value_distribution::a
- random/std::extreme_value_distribution::b
- random/std::extreme_value_distribution::param
- random/std::extreme_value_distribution::min
- random/std::extreme_value_distribution::max
- random/std::extreme_value_distribution::operator()
- random/std::extreme_value_distribution::param_type
- random/std::extreme_value_distribution::param_type::a
- random/std::extreme_value_distribution::param_type::b
- random/std::extreme_value_distribution::param_type::operator==
- random/std::extreme_value_distribution::param_type::operator!=
dev_langs: C++
helpviewer_keywords:
- std::extreme_value_distribution [C++]
- std::extreme_value_distribution [C++], reset
- std::extreme_value_distribution [C++], a
- std::extreme_value_distribution [C++], b
- std::extreme_value_distribution [C++], param
- std::extreme_value_distribution [C++], min
- std::extreme_value_distribution [C++], max
- std::extreme_value_distribution [C++], param_type
- std::extreme_value_distribution [C++], param_type
ms.assetid: a0cd8370-0a54-4e26-9388-8b9678fb57da
caps.latest.revision: "16"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: d53e49ae0a28201ac32cd1eb722c9889258f23b9
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="extremevaluedistribution-class"></a>Classe extreme_value_distribution
Gera uma distribuição Extreme Value.  
  
## <a name="syntax"></a>Sintaxe  
```  
template<class RealType = double>
class extreme_value_distribution  
   {  
public:  
   // types  
   typedef RealType result_type;  
   struct param_type;  
   
   // constructor and reset functions  
   explicit extreme_value_distribution(result_type a = 0.0, result_type b = 1.0);
   explicit extreme_value_distribution(const param_type& parm);
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
### <a name="parameters"></a>Parâmetros  
*RealType*  
O tipo de resultado de ponto flutuante assume `double` como padrão. Para ver os tipos possíveis, consulte [\<random>](../standard-library/random.md).  
  
*URNG* O mecanismo gerador de números aleatórios. Para ver os tipos possíveis, consulte [\<random>](../standard-library/random.md).
  
## <a name="remarks"></a>Comentários  
 A classe de modelo descreve uma distribuição que produz valores de um tipo de ponto flutuante especificado pelo usuário ou um tipo `double` caso nenhum seja fornecido, distribuído de acordo com a distribuição Extreme Value. A tabela a seguir contém links para artigos sobre cada um dos membros.  
  
||||  
|-|-|-|  
|[extreme_value_distribution](#extreme_value_distribution)|`extreme_value_distribution::a`|`extreme_value_distribution::param`|  
|`extreme_value_distribution::operator()`|`extreme_value_distribution::b`|[param_type](#param_type)|  
  
 As funções de propriedade `a()` e `b()` retornam os respectivos valores para os parâmetros de distribuição armazenados `a` e `b`.  
  
 Para obter mais informações sobre as classes de distribuição e seus membros, consulte [\<random>](../standard-library/random.md).  
  
 Para obter informações detalhadas sobre a distribuição Extreme Value, consulte o artigo de Wolfram MathWorld [Distribuição Extreme Value](http://go.microsoft.com/fwlink/LinkId=401110).  
  
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
  
    std::extreme_value_distribution<> distr(a, b);  
  
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
    std::cout << "Enter a floating point value for the \'a\' distribution parameter: ";  
    std::cin >> a_dist;  
    std::cout << "Enter a floating point value for the \'b\' distribution parameter (must be greater than zero): ";  
    std::cin >> b_dist;  
    std::cout << "Enter an integer value for the sample count: ";  
    std::cin >> samples;  
  
    test(a_dist, b_dist, samples);  
}  
```  
  
```Output  
Use CTRL-Z to bypass data entry and run using default values.  
Enter a floating point value for the 'a' distribution parameter: 0  
Enter a floating point value for the 'b' distribution parameter (must be greater than zero): 1  
Enter an integer value for the sample count: 10  
 
min() == -1.79769e+308  
max() == 1.79769e+308  
a() == 0.0000000000  
b() == 1.0000000000  
Distribution for 10 samples:  
    1: -0.8813940331  
    2: -0.7698972281  
    3: 0.2951258007  
    4: 0.3110450734  
    5: 0.4210546820  
    6: 0.4210688771  
    7: 0.4598857960  
    8: 1.3155194200  
    9: 1.5379170046  
    10: 2.0568757061  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<random>  
  
 **Namespace:** std  
  
##  <a name="extreme_value_distribution"></a>  extreme_value_distribution::extreme_value_distribution  
 Constrói a distribuição.  
  
```  
explicit extreme_value_distribution(result_type a_value = 0.0, result_type b_value = 1.0);
explicit extreme_value_distribution(const param_type& parm);  
```  
  
### <a name="parameters"></a>Parâmetros  
*a_value*  
 O parâmetro de distribuição `a`.  
  
*b_value*  
 O parâmetro de distribuição `b`.  
  
*parm*  
 A estrutura `param_type` usada para construir a distribuição.  
  
### <a name="remarks"></a>Comentários  
 **Pré-condição:** `0.0 < b`  
  
 O primeiro construtor constrói um objeto cujo valor `a` armazenado contém o valor *a_value* e cujo valor armazenado `b` contém o valor *b_value*.  
  
 O segundo construtor cria um objeto cujos parâmetros armazenados são inicializados de *parm*. Você pode chamar a função de membro `param()` para obter e definir os parâmetros atuais de uma distribuição existente.  
  
##  <a name="param_type"></a>  extreme_value_distribution::param_type  
Armazena os parâmetros da distribuição.  
  
```cpp  
struct param_type {  
   typedef extreme_value_distribution<result_type> distribution_type;  
   param_type(result_type a_value = 0.0, result_type b_value = 1.0);
   result_type a() const;
   result_type b() const;
    
   bool operator==(const param_type& right) const;
   bool operator!=(const param_type& right) const;
   };  
```  
  
### <a name="parameters"></a>Parâmetros  
*a_value*  
 O parâmetro de distribuição `a`.  
  
*b_value*  
 O parâmetro de distribuição `b`.  
  
*right*  
 O objeto `param_type` a ser comparado a este.  
  
### <a name="remarks"></a>Comentários  
 **Pré-condição:** `0.0 < b`  
  
 Essa estrutura pode ser enviada ao construtor de classe de distribuição na instanciação, para a função de membro `param()` para definir os parâmetros armazenados de uma distribuição existente e para `operator()` a ser usado no lugar dos parâmetros armazenados.  
  
## <a name="see-also"></a>Consulte também  
 [\<random>](../standard-library/random.md)



