---
title: "Classe time_put_byname | Microsoft Docs"
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
  - "time_put_byname"
  - "xloctime/std::time_put_byname"
  - "std.time_put_byname"
  - "std::time_put_byname"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe time_put_byname"
ms.assetid: e08c2348-64d2-4ace-98b1-1496e14c7b1a
caps.latest.revision: 25
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe time_put_byname
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe derivada do modelo descreve um objeto que pode servir como uma faceta de localidade do tipo `time_put`\< CharType, OutputIterator \>.  
  
## Sintaxe  
  
```  
template<class CharType,  
 class OutIt = ostreambuf_iterator<CharType, char_traits<CharType> > >  
 class time_put_byname : public time_put<CharType, OutputIterator>  
{  
public:  
    explicit time_put_byname(  
        const char *_Locname,  
        size_t _Refs = 0  
    );  
    explicit time_put_byname(  
        const string& _Locname,  
        size_t _Refs = 0  
    );  
protected:  
    virtual ~time_put_byname();  
};  
```  
  
#### Parâmetros  
 `_Locname`  
 Um nome de localidade.  
  
 `_Refs`  
 Uma contagem de referência inicial.  
  
## Comentários  
 Seu comportamento é determinado pelo [chamado](../Topic/locale::name.md) localidade `_Locname`. Cada construtor inicializa o objeto base com [time\_put](../Topic/time_put::time_put.md)\< CharType, OutputIterator \> \(`_Refs`\).  
  
## Requisitos  
 **Cabeçalho:** \< local \>  
  
 **Namespace:** std  
  
## Consulte também  
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)