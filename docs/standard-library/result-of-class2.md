---
title: "Classe result_of | Microsoft Docs"
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
  - "functional/std::tr1::result_of"
  - "std::tr1::result_of"
  - "result_of"
  - "std.tr1.result_of"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe result_of [TR1]"
ms.assetid: 14ec0040-07f1-45a5-80b5-d0c9f9b00c8f
caps.latest.revision: 20
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe result_of
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O tipo de retorno de um objeto acessível ajustado.  
  
## Sintaxe  
  
```  
template<class Ty>  
    struct result_of {  
    typedef T0 type;  
    };  
```  
  
#### Parâmetros  
 `Ty`  
 Uma descrição de uma chamada de função \(consulte a seção comentários\).  
  
## Comentários  
 A classe do modelo define o membro `type` como um sinônimo para o tipo de retorno de uma chamada de função descrita por seu argumento `Ty`do modelo.  O argumento do modelo deve ser do formato `Fty(T1, T2, ..., TN)`, onde `Fty` é um tipo acessível.  O modelo determina o tipo de retorno de acordo com o primeiro das seguintes regras que o aplica:  
  
-   se `Fty` é um ponteiro para funcionar tipo `R(*)(U1, U2, ..., UN)` o tipo de retorno é `R`;  
  
-   se `Fty` é uma referência ao tipo de função `R(&)(U1, U2, ..., UN)` o tipo de retorno é `R`;  
  
-   se `Fty` é um ponteiro para o tipo `R(U1::*)(U2, ..., UN)` da função de membro o tipo de retorno é `R`;  
  
-   se `Fty` é um ponteiro para o tipo `R U1::*` do membro de dados o tipo de retorno é `R`;  
  
-   se `Fty` é uma classe com um `result_type` typedef de membro o tipo de retorno é `Fty::result_type`;  
  
-   se `N` é 0 \(ou seja, `Ty` é do formato `Fty()`\) que o tipo de retorno é `void`;  
  
-   se `Fty` é uma classe com um modelo de membro nomeada `result` o tipo de retorno é `Fty::result<T1, T2, ..., TN>::type`;  
  
-   em todos os outros casos é um erro.  
  
## Exemplo  
  
```  
// std_tr1__functional__result_of.cpp   
// compile with: /EHsc   
#include <functional>   
#include <iostream>   
  
double square(double x)   
    {   
    return (x * x);   
    }   
  
template<class Fun,   
    class Arg>   
    void test_result(const Fun& fun, Arg arg)   
    {   
    typename std::result_of<Fun(Arg)>::type val = fun(arg);   
    std::cout << "val == " << val << std::endl;   
    }   
  
int main()   
    {   
    test_result(&square, 3.0);   
  
    return (0);   
    }  
  
```  
  
  **\=\= 9 val**   
## Requisitos  
 **Cabeçalho:** \<funcional\>  
  
 **Namespace:** std