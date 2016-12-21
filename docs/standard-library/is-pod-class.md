---
title: "Classe is_pod | Microsoft Docs"
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
  - "std.tr1.is_pod"
  - "is_pod"
  - "std::tr1::is_pod"
  - "std.is_pod"
  - "std::is_pod"
  - "type_traits/std::is_pod"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe is_pod [TR1]"
  - "is_pod"
ms.assetid: d73ebdee-746b-4082-9fa4-2db71432eb0e
caps.latest.revision: 20
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe is_pod
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Testa se o tipo é POD.  
  
## Sintaxe  
  
```  
template<class Ty>  
    struct is_pod;  
```  
  
#### Parâmetros  
 `Ty`  
 O tipo a ser consultado.  
  
## Comentários  
 `is_pod<Ty>::value` é `true` se o tipo `Ty` é dados antigos simples \(POD\).  Caso contrário, será `false`.  
  
 Ponteiro para tipos de membro, tipos de enumeração, tipos de ponteiro e tipos aritméticos são POD.  
  
 Uma versão VC qualificado de um tipo POD em si é um tipo POD.  
  
 Uma matriz de POD é POD.  
  
 Uma estrutura ou união, todos os membros de dados não estáticos são POD, é POD se ele tem:  
  
-   Nenhum construtor declarado pelo usuário.  
  
-   Não há membros de dados de não estático particular ou protegido.  
  
-   Nenhuma classe base.  
  
-   Não há funções virtuais.  
  
-   Nenhum membro de dados não estático do tipo de referência.  
  
-   Nenhum operador de atribuição de cópia definido pelo usuário.  
  
-   Nenhum destruidor definido pelo usuário.  
  
 Portanto, você pode recursivamente compilação POD estruturas e matrizes que contêm matrizes e structs POD.  
  
## Exemplo  
  
```  
// std_tr1__type_traits__is_pod.cpp   
// compile with: /EHsc   
#include <type_traits>   
#include <iostream>   
  
struct trivial   
    {   
    int val;   
    };   
  
struct throws   
    {   
    throws() throw(int)   
        {   
        }   
  
    throws(const throws&) throw(int)   
        {   
        }   
  
    throws& operator=(const throws&) throw(int)   
        {   
        }   
  
    int val;   
    };   
  
int main()   
    {   
    std::cout << "is_pod<trivial> == " << std::boolalpha   
        << std::is_pod<trivial>::value << std::endl;   
    std::cout << "is_pod<int> == " << std::boolalpha   
        << std::is_pod<int>::value << std::endl;   
    std::cout << "is_pod<throws> == " << std::boolalpha   
        << std::is_pod<throws>::value << std::endl;   
  
    return (0);   
    }  
  
```  
  
  **is\_pod \< trivial \> \= \= true**  
**is\_pod \< int \> \= \= true**  
**is\_pod \< lança \> \= \= false**   
## Requisitos  
 **Cabeçalho:** \<type\_traits\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\< type\_traits \>](../standard-library/type-traits.md)