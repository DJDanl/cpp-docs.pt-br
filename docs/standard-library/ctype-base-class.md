---
title: "Classe ctype_base | Microsoft Docs"
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
  - "locale/std::ctype_base"
  - "std.ctype_base"
  - "ctype_base"
  - "std::ctype_base"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe ctype_base"
ms.assetid: ccffe891-d7ab-4d22-baf8-8eb6d438a96d
caps.latest.revision: 19
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe ctype_base
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Serve como a classe de uma classe base para facetas do modelo [C](../standard-library/ctype-class.md)classe.  Uma classe base da classe de C que é usada para definir os tipos de enumeração usados para classificar ou testar caracteres individualmente ou dentro dos intervalos inteiros.  
  
## Sintaxe  
  
```  
struct ctype_base : public locale::facet  
{  
    enum  
    {  
        alnum, alpha, cntrl, digit, graph,  
        lower, print, punct, space, upper,  
        xdigit  
    };  
    typedef short mask;  
    ctype_base(  
        size_t _Refs = 0  
    );  
    ~ctype_base();  
};  
```  
  
## Comentários  
 Define uma máscara da enumeração.  Cada constante de enumeração caracteriza uma maneira diferente de classificar caracteres, conforme definido por funções com nomes semelhantes declarados no cabeçalho \<ctype.h.\>  As constantes são:  
  
-   **space** \(função [isspace](../Topic/isspace.md)\)  
  
-   **print** \(função [isprint](../Topic/isprint.md)\)  
  
-   **cntrl** \(função [iscntrl](../Topic/iscntrl.md)\)  
  
-   **upper** \(função [isupper](../Topic/isupper.md)\)  
  
-   **lower** \(função [islower](../Topic/islower.md)\)  
  
-   **digit** \(função [isdigit](../Topic/isdigit.md)\)  
  
-   **punct** \(função [ispunct](../Topic/ispunct.md)\)  
  
-   **xdigit** \(função [isxdigit](../Topic/isxdigit.md)\)  
  
-   **alpha** \(função [isalpha](../Topic/isalpha.md)\)  
  
-   **alnum** \(função [isalnum](../Topic/isalnum.md)\)  
  
-   **graph** \(função [isgraph](../Topic/isgraph.md)\)  
  
 Você pode caracterizar uma combinação de classificações por anel\-O essas constantes.  Em particular, é sempre true que \=\= de **alnum** \(**alpha** ``&#124; **digit**\) e \=\= de **graph** \(**alnum**``&#124; **punct**\).  
  
## Requisitos  
 Localidade \<de**Header:** \>  
  
 **Namespace:** std  
  
## Consulte também  
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)