---
title: "Classe uniform_int_distribution | Microsoft Docs"
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
  - "tr1.uniform_int_distribution"
  - "random/std::tr1::uniform_int_distribution"
  - "uniform_int_distribution"
  - "tr1::uniform_int_distribution"
  - "std.tr1.uniform_int_distribution"
  - "std::tr1::uniform_int_distribution"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe uniform_int_distribution"
ms.assetid: a1867dcd-3bd9-4787-afe3-4b62692c1d04
caps.latest.revision: 20
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe uniform_int_distribution
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Gera uma distribuição de inteiro uniforme \(todo valor é igualmente provável\) em um intervalo de saídas inclusive\-inclusive.  
  
## Sintaxe  
  
```  
template<class IntType = int> class uniform_int_distribution { public:     // types     typedef IntType result_type;     struct param_type;     // constructors and reset functions     explicit uniform_int_distribution(IntType a = 0, IntType b = numeric_limits<IntType>::max());     explicit uniform_int_distribution(const param_type& parm);     void reset();     // generating functions     template<class URNG>     result_type operator()(URNG& gen);     template<class URNG>     result_type operator()(URNG& gen, const param_type& parm);     // property functions     result_type a() const;     result_type b() const;     param_type param() const;     void param(const param_type& parm);     result_type min() const;     result_type max() const; };  
```  
  
#### Parâmetros  
 `IntType`  
 O tipo de resultado do inteiro assume `int` como padrão.  Para obter os tipos possíveis, consulte [\<random\>](../standard-library/random.md).  
  
## Comentários  
 A classe de modelo descreve uma distribuição inclusive\-inclusive que produz valores de um tipo integral especificado por usuário com uma distribuição, de forma que todo valor seja igualmente provável.  A tabela a seguir contém links para artigos sobre cada um dos membros.  
  
||||  
|-|-|-|  
|[uniform\_int\_distribution::uniform\_int\_distribution](../Topic/uniform_int_distribution::uniform_int_distribution.md)|`uniform_int_distribution::a`|`uniform_int_distribution::param`|  
|`uniform_int_distribution::operator()`|`uniform_int_distribution::b`|[uniform\_int\_distribution::param\_type](../Topic/uniform_int_distribution::param_type.md)|  
  
 O membro da propriedade `a()` retorna o limite mínimo armazenado no momento da distribuição e `b()` retorna o limite máximo armazenado no momento.  Para essa classe de distribuição, esses valores mínimo e máximo são os mesmos retornados pelas funções de propriedade comuns `min()` e `max()`, descritas no tópico [\<random\>](../standard-library/random.md).  
  
 Para obter mais informações sobre classes de distribuição e seus membros, consulte [\<random\>](../standard-library/random.md).  
  
## Exemplo  
  
```cpp  
// compile with: /EHsc /W4  
#include <random>   
#include <iostream>  
#include <iomanip>  
#include <string>  
#include <map>  
  
void test(const int a, const int b, const int s) {  
  
    // uncomment to use a non-deterministic seed  
    //    std::random_device rd;  
    //    std::mt19937 gen(rd());  
    std::mt19937 gen(1729);  
  
    std::uniform_int_distribution<> distr(a, b);  
  
    std::cout << "lower bound == " << distr.a() << std::endl;  
    std::cout << "upper bound == " << distr.b() << std::endl;  
  
    // generate the distribution as a histogram  
    std::map<int, int> histogram;  
    for (int i = 0; i < s; ++i) {  
        ++histogram[distr(gen)];  
    }  
  
    // print results  
    std::cout << "Distribution for " << s << " samples:" << std::endl;  
    for (const auto& elem : histogram) {  
        std::cout << std::setw(5) << elem.first << ' ' << std::string(elem.second, ':') << std::endl;  
    }  
    std::cout << std::endl;  
}  
  
int main()  
{  
    int a_dist = 1;  
    int b_dist = 10;  
  
    int samples = 100;  
  
    std::cout << "Use CTRL-Z to bypass data entry and run using default values." << std::endl;  
    std::cout << "Enter an integer value for the lower bound of the distribution: ";  
    std::cin >> a_dist;  
    std::cout << "Enter an integer value for the upper bound of the distribution: ";  
    std::cin >> b_dist;  
    std::cout << "Enter an integer value for the sample count: ";  
    std::cin >> samples;  
  
    test(a_dist, b_dist, samples);  
}  
  
```  
  
## Saída  
  **Use CTRL\-Z para efetuar o bypass da entrada de dados e executar usando valores padrão.  Insira um valor inteiro para o limite mínimo da distribuição: 0**  
**Insira um valor inteiro para o limite máximo da distribuição: 12**  
**Insira um valor inteiro para a contagem de amostra: 200**  
**lower bound \=\= 0**  
**upper bound \=\= 12**  
**Distribuição para 200 amostras:**  
 **0 :::::::::::::::**  
 **1 :::::::::::::::::::::**  
 **2 ::::::::::::::::::**  
 **3 :::::::::::::::**  
 **4 :::::::**  
 **5 :::::::::::::::::::::**  
 **6 :::::::::::::**  
 **7 ::::::::::**  
 **8 :::::::::::::::**  
 **9 :::::::::::::**  
 **10 ::::::::::::::::::::::**  
 **11 :::::::::::::**  
 **12 :::::::::::::::::**    
## Requisitos  
 **Cabeçalho:** \<random\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<random\>](../standard-library/random.md)