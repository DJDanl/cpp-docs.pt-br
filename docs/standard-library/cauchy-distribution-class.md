---
title: cauchy_distribution Class | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- random/std::cauchy_distribution
- random/std::cauchy_distribution::reset
- random/std::cauchy_distribution::a
- random/std::cauchy_distribution::b
- random/std::cauchy_distribution::param
- random/std::cauchy_distribution::min
- random/std::cauchy_distribution::max
- random/std::cauchy_distribution::operator()
- random/std::cauchy_distribution::param_type
- random/std::cauchy_distribution::param_type::a
- random/std::cauchy_distribution::param_type::b
- random/std::cauchy_distribution::param_type::operator==
- random/std::cauchy_distribution::param_type::operator!=
- random/std::cauchy_distribution::param_type
dev_langs:
- C++
helpviewer_keywords:
- std::cauchy_distribution [C++]
- std::cauchy_distribution [C++], reset
- std::cauchy_distribution [C++], a
- std::cauchy_distribution [C++], b
- std::cauchy_distribution [C++], param
- std::cauchy_distribution [C++], min
- std::cauchy_distribution [C++], max
- std::cauchy_distribution [C++], param_type
- std::cauchy_distribution [C++], param_type
ms.assetid: 21522351-f2f1-46d9-97f0-d358c932356c
caps.latest.revision: 25
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 65f4e356ad0d46333b0d443d0fd6ac0b9f2b6f58
ms.openlocfilehash: c989548d8edeffb537a0095fab9daf8207a830ff
ms.contentlocale: pt-br
ms.lasthandoff: 10/03/2017

---
# <a name="cauchydistribution-class"></a>Classe cauchy_distribution
Gera uma distribuição Cauchy.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<class RealType = double>  
class cauchy_distribution {  
public:  
   // types 
   typedef RealType result_type;  
   struct param_type;  
   
   // constructor and reset functions  
   explicit cauchy_distribution(result_type a = 0.0, result_type b = 1.0);
   explicit cauchy_distribution(const param_type& parm);
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
  
*URNG* O mecanismo gerador de números aleatórios uniformes. Para ver os tipos possíveis, consulte [\<random>](../standard-library/random.md).  

## <a name="remarks"></a>Comentários  
A classe de modelo descreve uma distribuição que produz valores de um tipo de ponto flutuante especificado pelo usuário ou de um tipo `double`, caso nenhum seja fornecido, distribuído de acordo com a Distribuição Cauchy. A tabela a seguir contém links para artigos sobre cada um dos membros.  
  
||||  
|-|-|-|  
|[cauchy_distribution](#cauchy_distribution)|`cauchy_distribution::a`|`cauchy_distribution::param`|  
|`cauchy_distribution::operator()`|`cauchy_distribution::b`|[param_type](#param_type)|  
  
As funções de propriedade `a()` e `b()` retornam os respectivos valores para os parâmetros de distribuição armazenados `a` e `b`.  
  
O membro da propriedade `param()` define ou retorna o pacote de parâmetros de distribuição armazenado `param_type`.  

As funções membro `min()` e `max()` retornam o menor resultado possível e o maior resultado possível, respectivamente.  
  
A função membro `reset()` descarta qualquer valor armazenado em cache, de forma que o resultado da próxima chamada para `operator()` não dependerá dos valores obtidos do mecanismo antes da chamada.  
  
As funções membro `operator()` retornam o próximo valor gerado com base no mecanismo URNG, do pacote de parâmetros atual ou do pacote de parâmetros especificado.
  
Para obter mais informações sobre as classes de distribuição e seus membros, consulte [\<random>](../standard-library/random.md).  
  
Para obter informações detalhadas sobre a distribuição cauchy, consulte o artigo [Cauchy Distribution](http://go.microsoft.com/fwlink/LinkId=400523) (Distribuição cauchy), da Wolfram MathWorld.  
  
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
  
    std::cauchy_distribution<> distr(a, b);  
  
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
    std::cout << "Enter a floating point value for the 'a' distribution parameter: ";  
    std::cin >> a_dist;  
    std::cout << "Enter a floating point value for the 'b' distribution parameter (must be greater than zero): ";  
    std::cin >> b_dist;  
    std::cout << "Enter an integer value for the sample count: ";  
    std::cin >> samples;  
  
    test(a_dist, b_dist, samples);  
}  
```  
  
Primeira execução:  
  
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
    1: -3.4650392984  
    2: -2.6369564174  
    3: -0.0786978867  
    4: -0.0609632093  
    5: 0.0589387400  
    6: 0.0589539764  
    7: 0.1004592006  
    8: 1.0965724260  
    9: 1.4389408122  
    10: 2.5253154706  
```  
  
Segunda execução:  
  
```Output  
Use CTRL-Z to bypass data entry and run using default values.  
Enter a floating point value for the 'a' distribution parameter: 0  
Enter a floating point value for the 'b' distribution parameter (must be greater than zero): 10  
Enter an integer value for the sample count: 10  
 
min() == -1.79769e+308  
max() == 1.79769e+308  
a() == 0.0000000000  
b() == 10.0000000000  
Distribution for 10 samples:  
    1: -34.6503929840  
    2: -26.3695641736  
    3: -0.7869788674  
    4: -0.6096320926  
    5: 0.5893873999  
    6: 0.5895397637  
    7: 1.0045920062  
    8: 10.9657242597  
    9: 14.3894081218  
    10: 25.2531547063  
```  
  
Terceira execução:  
  
```Output  
Use CTRL-Z to bypass data entry and run using default values.  
Enter a floating point value for the 'a' distribution parameter: 10  
Enter a floating point value for the 'b' distribution parameter (must be greater than zero): 10  
Enter an integer value for the sample count: 10  
 
min() == -1.79769e+308  
max() == 1.79769e+308  
a() == 10.0000000000  
b() == 10.0000000000  
Distribution for 10 samples:  
    1: -24.6503929840  
    2: -16.3695641736  
    3: 9.2130211326  
    4: 9.3903679074  
    5: 10.5893873999  
    6: 10.5895397637  
    7: 11.0045920062  
    8: 20.9657242597  
    9: 24.3894081218  
    10: 35.2531547063  
```  
  
## <a name="requirements"></a>Requisitos  
**Cabeçalho:** \<random>  
  
**Namespace:** std  
  
##  <a name="cauchy_distribution"></a>  cauchy_distribution::cauchy_distribution  
Constrói a distribuição.  
  
```  
explicit cauchy_distribution(result_type a = 0.0, result_type b = 1.0);
explicit cauchy_distribution(const param_type& parm);
```  
  
### <a name="parameters"></a>Parâmetros  
*a*  
O parâmetro de distribuição `a`.  
  
*b*  
O parâmetro de distribuição `b`.  
  
*parm*  
A estrutura `param_type` usada para construir a distribuição.  
  
### <a name="remarks"></a>Comentários  
**Pré-condição:** `0.0 < b`  
  
O primeiro construtor constrói um objeto cujo valor `a` armazenado contém o valor *a* e cujo valor `b` armazenado contém o valor *b*.  
  
O segundo construtor cria um objeto cujos parâmetros armazenados são inicializados de *parm*. Você pode chamar a função de membro `param()` para obter e definir os parâmetros atuais de uma distribuição existente.  
  
##  <a name="param_type"></a>  cauchy_distribution::param_type  
Armazena todos os parâmetros da distribuição.  
  
```cpp    
struct param_type {  
   typedef cauchy_distribution<result_type> distribution_type;  
   param_type(result_type a = 0.0, result_type b = 1.0);
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
**Pré-condição:** `0.0 < b`  
  
Essa estrutura pode ser enviada ao construtor de classe de distribuição na instanciação, para a função de membro `param()` para definir os parâmetros armazenados de uma distribuição existente e para `operator()` a ser usado no lugar dos parâmetros armazenados.  
  
## <a name="see-also"></a>Consulte também  
[\<random>](../standard-library/random.md)




