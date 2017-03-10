---
title: Classe normal_distribution | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- normal_distribution
- std::normal_distribution
- random/std::normal_distribution
- std::normal_distribution::reset
- random/std::normal_distribution::reset
- std::normal_distribution::mean
- random/std::normal_distribution::mean
- std::normal_distribution::stddev
- random/std::normal_distribution::stddev
- std::normal_distribution::param
- random/std::normal_distribution::param
- std::normal_distribution::min
- random/std::normal_distribution::min
- std::normal_distribution::max
- random/std::normal_distribution::max
- std::normal_distribution::operator()
- random/std::normal_distribution::operator()
- std::normal_distribution::param_type
- random/std::normal_distribution::param_type
- std::normal_distribution::param_type::mean
- random/std::normal_distribution::param_type::mean
- std::normal_distribution::param_type::stddev
- random/std::normal_distribution::param_type::stddev
- std::normal_distribution::param_type::operator==
- random/std::normal_distribution::param_type::operator==
- std::normal_distribution::param_type::operator!=
- random/std::normal_distribution::param_type::operator!=
dev_langs:
- C++
helpviewer_keywords:
- normal_distribution class
ms.assetid: bf92cdbd-bc72-4d4a-b588-173d748f0d7d
caps.latest.revision: 19
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
ms.sourcegitcommit: 28baed4badda4f2c1d7e5b20235fe8d40c2a7195
ms.openlocfilehash: d587cc1def88f67ccc521d9353318acca363ad57
ms.lasthandoff: 02/25/2017

---
# <a name="normaldistribution-class"></a>Classe normal_distribution
Gera uma distribuição Normal.  
  
## <a name="syntax"></a>Sintaxe  
```  
template<class RealType = double>
class normal_distribution  
   {  
public:  
   // types  
   typedef RealType result_type;  
   struct param_type;  

   // constructors and reset functions  
   explicit normal_distribution(result_type mean = 0.0, result_type stddev = 1.0);
   explicit normal_distribution(const param_type& parm);
   void reset();

   // generating functions  
   template <class URNG>  
   result_type operator()(URNG& gen);
   template <class URNG>  
   result_type operator()(URNG& gen, const param_type& parm);

   // property functions  
   result_type mean() const;
   result_type stddev() const;
   param_type param() const;
   void param(const param_type& parm);
   result_type min() const;
   result_type max() const;
   };  
```  
  
### <a name="parameters"></a>Parâmetros  
*RealType*  
O tipo de resultado de ponto flutuante assume `double` como padrão. Para ver os tipos possíveis, consulte [\<random>](../standard-library/random.md).  
  
## <a name="remarks"></a>Comentários  
A classe de modelo descreve uma distribuição que produz valores de um tipo integral especificado pelo usuário ou um tipo `double` caso nenhum seja fornecido, distribuído de acordo com a distribuição Normal. A tabela a seguir contém links para artigos sobre cada um dos membros.  
  
||||  
|-|-|-|  
|[normal_distribution::normal_distribution](#normal_distribution__normal_distribution)|`normal_distribution::mean`|`normal_distribution::param`|  
|`normal_distribution::operator()`|`normal_distribution::stddev`|[normal_distribution::param_type](#normal_distribution__param_type)|  
  
As funções de propriedade `mean()` e `stddev()` retornam os valores para os parâmetros de distribuição armazenados `mean` e `stddev`, respectivamente.  
  
O membro da propriedade `param()` define ou retorna o pacote de parâmetros de distribuição armazenado `param_type`.  

As funções membro `min()` e `max()` retornam o menor resultado possível e o maior resultado possível, respectivamente.  
  
A função membro `reset()` descarta qualquer valor armazenado em cache, de forma que o resultado da próxima chamada para `operator()` não dependerá dos valores obtidos do mecanismo antes da chamada.  
  
As funções membro `operator()` retornam o próximo valor gerado com base no mecanismo URNG, do pacote de parâmetros atual ou do pacote de parâmetros especificado.
  
Para obter mais informações sobre as classes de distribuição e seus membros, consulte [\<random>](../standard-library/random.md).  
  
Para obter informações detalhadas sobre a distribuição Normal, consulte o artigo [Distribuição Normal](http://go.microsoft.com/fwlink/LinkId=400924), da Wolfram MathWorld.  
  
## <a name="example"></a>Exemplo  
  
```cpp  
// compile with: /EHsc /W4  
#include <random>   
#include <iostream>  
#include <iomanip>  
#include <string>  
#include <map>  
  
using namespace std;  
  
void test(const double m, const double s, const int samples) {  
  
    // uncomment to use a non-deterministic seed  
    //    random_device gen;  
    //    mt19937 gen(rd());  
    mt19937 gen(1701);  
  
    normal_distribution<> distr(m, s);  
  
    cout << endl;  
    cout << "min() == " << distr.min() << endl;  
    cout << "max() == " << distr.max() << endl;  
    cout << "m() == " << fixed << setw(11) << setprecision(10) << distr.mean() << endl;  
    cout << "s() == " << fixed << setw(11) << setprecision(10) << distr.stddev() << endl;  
  
    // generate the distribution as a histogram  
    map<double, int> histogram;  
    for (int i = 0; i < samples; ++i) {  
        ++histogram[distr(gen)];  
    }  
  
    // print results  
    cout << "Distribution for " << samples << " samples:" << endl;  
    int counter = 0;  
    for (const auto& elem : histogram) {  
        cout << fixed << setw(11) << ++counter << ": "  
            << setw(14) << setprecision(10) << elem.first << endl;  
    }  
    cout << endl;  
}  
  
int main()  
{  
    double m_dist = 1;  
    double s_dist = 1;  
    int samples = 10;  
  
    cout << "Use CTRL-Z to bypass data entry and run using default values." << endl;  
    cout << "Enter a floating point value for the 'mean' distribution parameter: ";  
    cin >> m_dist;  
    cout << "Enter a floating point value for the 'stddev' distribution parameter (must be greater than zero): ";  
    cin >> s_dist;  
    cout << "Enter an integer value for the sample count: ";  
    cin >> samples;  
  
    test(m_dist, s_dist, samples);  
}  
  
```  
  
```Output  
Use CTRL-Z to bypass data entry and run using default values.  
Enter a floating point value for the 'mean' distribution parameter: 0  
Enter a floating point value for the 'stddev' distribution parameter (must be greater than zero): 1  
Enter an integer value for the sample count: 10  
 
min() == -1.79769e+308  
max() == 1.79769e+308  
m() == 0.0000000000  
s() == 1.0000000000  
Distribution for 10 samples:  
    1: -0.8845823965  
    2: -0.1995761116  
    3: -0.1162665130  
    4: -0.0685154932  
    5: 0.0403741461  
    6: 0.1591327792  
    7: 1.0414389924  
    8: 1.5876269426  
    9: 1.6362637713  
    10: 2.7821317338  
```  
  
## <a name="requirements"></a>Requisitos  
**Cabeçalho:** \<random>  
  
**Namespace:** std  
  
##  <a name="normal_distribution__normal_distribution"></a>  normal_distribution::normal_distribution  
Constrói a distribuição.  
  
```  
explicit normal_distribution(result_type mean = 0.0, result_type stddev = 1.0);
explicit normal_distribution(const param_type& parm);
```  
  
### <a name="parameters"></a>Parâmetros  
*mean*  
O parâmetro de distribuição `mean`.  
  
*stddev*  
O parâmetro de distribuição `stddev`.  
  
*parm*  
A estrutura do parâmetro usada para construir a distribuição.  
  
### <a name="remarks"></a>Comentários  
**Pré-condição:** `0.0 ≤ stddev`  
  
O primeiro construtor cria um objeto cujo valor `mean` armazenado contém o valor *mean* e cujo valor armazenado `stddev` contém o valor *stddev*.  
  
O segundo construtor cria um objeto cujos parâmetros armazenados são inicializados de *parm*. Você pode chamar a função de membro `param()` para obter e definir os parâmetros atuais de uma distribuição existente.  
  
##  <a name="normal_distribution__param_type"></a>  normal_distribution::param_type  
Armazena os parâmetros da distribuição.  
  
```cpp  
struct param_type {  
   typedef normal_distribution<result_type> distribution_type;  
   param_type(result_type mean = 0.0, result_type stddev = 1.0);
   result_type mean() const;
   result_type stddev() const;
  
   bool operator==(const param_type& right) const;
   bool operator!=(const param_type& right) const;
   };  
```  
### <a name="parameters"></a>Parâmetros  
*mean*  
O parâmetro de distribuição `mean`.  
  
*stddev*  
O parâmetro de distribuição `stddev`.  
  
*right*  
A estrutura `param_type` usada para comparar.  
  
### <a name="remarks"></a>Comentários  
**Pré-condição:** `0.0 ≤ stddev`  
  
Essa estrutura pode ser enviada ao construtor de classe de distribuição na instanciação, para a função de membro `param()` para definir os parâmetros armazenados de uma distribuição existente e para `operator()` a ser usado no lugar dos parâmetros armazenados.  
  
## <a name="see-also"></a>Consulte também  
 [\<random>](../standard-library/random.md)




