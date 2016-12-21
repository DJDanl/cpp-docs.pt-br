---
title: "Classe geometric_distribution | Microsoft Docs"
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
  - "std.tr1.geometric_distribution"
  - "random/std::tr1::geometric_distribution"
  - "tr1::geometric_distribution"
  - "tr1.geometric_distribution"
  - "geometric_distribution"
  - "std::tr1::geometric_distribution"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe geometric_distribution"
  - "Classe geometric_distribution [TR1]"
ms.assetid: 38f933af-3b49-492e-9d26-b6b272a60013
caps.latest.revision: 24
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe geometric_distribution
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Gera uma distribuição geométrica.  
  
## Sintaxe  
  
```  
template<class IntType = int> class geometric_distribution { public:     // types     typedef IntType result_type;     struct param_type;     // constructors and reset functions     explicit geometric_distribution(double p = 0.5);     explicit geometric_distribution(const param_type& parm);     void reset();     // generating functions     template<class URNG>     result_type operator()(URNG& gen);     template<class URNG>     result_type operator()(URNG& gen, const param_type& parm);     // property functions     double p() const;     param_type param() const;     void param(const param_type& parm);     result_type min() const;     result_type max() const; };  
```  
  
#### Parâmetros  
 `IntType`  
 O tipo de resultado do inteiro assume `int` como padrão.  Para obter os tipos possíveis, consulte [\<random\>](../standard-library/random.md).  
  
## Comentários  
 A classe do modelo descreve uma distribuição que produz valores de um tipo de integral especificado pelo usuário com uma distribuição geométrica.  A tabela a seguir contém links para artigos sobre cada um dos membros.  
  
||||  
|-|-|-|  
|[geometric\_distribution::geometric\_distribution](../Topic/geometric_distribution::geometric_distribution.md)|`geometric_distribution::p`|`geometric_distribution::param`|  
|`geometric_distribution::operator()`||[geometric\_distribution::param\_type](../Topic/geometric_distribution::param_type.md)|  
  
 A função de propriedade `p()` retorna o valor do parâmetro de distribuição armazenado `p`.  
  
 Para obter mais informações sobre classes de distribuição e seus membros, consulte [\<random\>](../standard-library/random.md).  
  
 Para obter informações detalhadas sobre distribuição qui\-quadrado, consulte o artigo da Wolfram MathWorld [Distribuição geométrica](http://go.microsoft.com/fwlink/?LinkId=400529).  
  
## Exemplo  
  
```cpp  
// compile with: /EHsc /W4  
#include <random>   
#include <iostream>  
#include <iomanip>  
#include <string>  
#include <map>  
  
void test(const double p, const int s) {  
  
    // uncomment to use a non-deterministic generator  
    //    std::random_device gen;  
    std::mt19937 gen(1701);  
  
    std::geometric_distribution<> distr(p);  
  
    std::cout << std::endl;  
    std::cout << "min() == " << distr.min() << std::endl;  
    std::cout << "max() == " << distr.max() << std::endl;  
    std::cout << "p() == " << std::fixed << std::setw(11) << std::setprecision(10) << distr.p() << std::endl;  
  
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
    double p_dist = 0.5;  
  
    int samples = 100;  
  
    std::cout << "Use CTRL-Z to bypass data entry and run using default values." << std::endl;  
    std::cout << "Enter a floating point value for the \'p\' distribution parameter: ";  
    std::cin >> p_dist;  
    std::cout << "Enter an integer value for the sample count: ";  
    std::cin >> samples;  
  
    test(p_dist, samples);  
}  
  
```  
  
## Saída  
 Primeiro teste:  
  
  **Use CTRL\-Z para efetuar o bypass da entrada de dados e executar usando valores padrão.  Insira um valor de ponto flutuante para o parâmetro de distribuição 'p': 5**  
**Insira um valor inteiro para a contagem de amostra: 100**  
**min\(\) \=\= 0**  
**max\(\) \=\= 2147483647**  
**p\(\) \=\= 0.5000000000**  
**Distribuição para 100 amostras:**  
 **0 ::::::::::::::::::::::::::::::::::::::::::::::::::::**  
 **1 ::::::::::::::::::::::::**  
 **2 ::::::::::::::**  
 **3 :::::**  
 **4 ::**  
 **5 ::**  
 **6 :**  Segundo teste:  
  
  **Use CTRL\-Z para efetuar o bypass da entrada de dados e executar usando valores padrão.  Insira um valor de ponto flutuante para o parâmetro de distribuição 'p': 1**  
**Insira um valor inteiro para a contagem de amostra: 100**  
**min\(\) \=\= 0**  
**max\(\) \=\= 2147483647**  
**p\(\) \=\= 0.1000000000**  
**Distribuição para 100 amostras:**  
 **0 :::::::::**  
 **1 :::::::::::**  
 **2 :::::::**  
 **3 ::::::::**  
 **4 ::::::::**  
 **5 ::::::**  
 **6 :::::**  
 **7 ::::::**  
 **8 :::::**  
 **9 ::::**  
 **10 ::::**  
 **11 ::**  
 **12 :**  
 **13 :**  
 **14 :::**  
 **15 ::::**  
 **16 :::**  
 **17 :**  
 **18 :**  
 **19 :**  
 **20 ::**  
 **21 :**  
 **22 :**  
 **23 :**  
 **28 ::**  
 **33 :**  
 **35 :**  
 **40 :**    
## Requisitos  
 **Cabeçalho:** \<random\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<random\>](../standard-library/random.md)