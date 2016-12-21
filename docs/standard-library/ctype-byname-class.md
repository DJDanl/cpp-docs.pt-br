---
title: "Classe ctype_byname | Microsoft Docs"
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
  - "xlocale/std::ctype_byname"
  - "std::ctype_byname"
  - "ctype_byname"
  - "std.ctype_byname"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe ctype_byname"
ms.assetid: a5cec021-a1f8-425f-8757-08e6f064b604
caps.latest.revision: 22
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe ctype_byname
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe derivada do modelo descreve um objeto que pode servir como uma faceta do tipo C de uma localidade específica, habilitando a classificação de caracteres e conversão de caracteres entre casos e nativo e conjuntos de caracteres especificados localidade.  
  
## Sintaxe  
  
```  
template<class _Elem>  
class ctype_byname : public ctype<_Elem>  
{  
public:  
    explicit ctype_byname(  
        const char *_Locname,  
        size_t _Refs = 0  
    );  
    explicit ctype_byname(  
        const string& _Locname,  
        size_t _Refs = 0  
    );  
protected:  
    virtual __CLR_OR_THIS_CALL ~ctype_byname();  
};  
```  
  
## Comentários  
 O comportamento é determinado pela localidade nomeada `_Locname`.  Cada construtor inicializa o objeto base com [C](../standard-library/ctype-class.md)\<CharType\>\(`_Refs`\) ou o equivalente da classe base `ctype<char>`.  
  
## Requisitos  
 localidade \<de**Cabeçalho:** \>  
  
 **Namespace:** std  
  
## Consulte também  
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)