---
title: "Classe time_put | Microsoft Docs"
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
  - "std::time_put"
  - "time_put"
  - "xloctime/std::time_put"
  - "std.time_put"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe time_put"
ms.assetid: df79493e-3331-48d2-97c3-ac3a745f0791
caps.latest.revision: 22
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe time_put
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe de modelo descreve um objeto que pode servir como uma faceta de localidade para controlar conversões de valores de tempo em sequências do tipo `CharType`.  
  
## Sintaxe  
  
```  
template <  
   class CharType,  
   class OutputIterator = ostreambuf_iterator<CharType>  
> class time_put : public locale::facet;  
```  
  
#### Parâmetros  
 `CharType`  
 O tipo usado em um programa para codificar caracteres.  
  
 `OutputIterator`  
 O tipo de iterador no qual as funções put de tempo gravam sua saída.  
  
## Comentários  
 Como qualquer faceta de localidade, a ID de objeto estático tem um valor armazenado inicial de zero.  A primeira tentativa de acessar seu valor armazenado armazena um valor positivo exclusivo em **id.**  
  
### Construtores  
  
|||  
|-|-|  
|[time\_put](../Topic/time_put::time_put.md)|O construtor para objetos do tipo `time_put`.|  
  
### Typedefs  
  
|||  
|-|-|  
|[char\_type](../Topic/time_put::char_type.md)|Um tipo que é usado para descrever um caractere usado por uma localidade.|  
|[iter\_type](../Topic/time_put::iter_type.md)|Um tipo que descreve um iterador de saída.|  
  
### Funções membro  
  
|||  
|-|-|  
|[do\_put](../Topic/time_put::do_put.md)|Uma função virtual que gera informações de hora e data como uma sequência de `CharType`s.|  
|[put](../Topic/time_put::put.md)|Gera informações de hora e data como uma sequência de `CharType`s.|  
  
## Requisitos  
 **Cabeçalho:** \<locale\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<locale\>](../standard-library/locale.md)   
 [Classe time\_base](../Topic/time_base%20Class.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)