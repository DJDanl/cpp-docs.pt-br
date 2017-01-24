---
title: "Classe time_get | Microsoft Docs"
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
  - "std.time_get"
  - "xloctime/std::time_get"
  - "time_get"
  - "std::time_get"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe time_get"
ms.assetid: 869d5f5b-dbab-4628-8333-bdea7e272023
caps.latest.revision: 21
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe time_get
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe de modelo descreve um objeto que pode servir como uma faceta de localidade para controlar conversões de sequências do tipo `CharType` em valores de tempo.  
  
## Sintaxe  
  
```  
template <  
   class CharType,  
   class InputIterator = istreambuf_iterator<CharType>  
> class time_get : public time_base;  
```  
  
#### Parâmetros  
 `CharType`  
 O tipo usado em um programa para codificar caracteres.  
  
 `InputIterator`  
 O iterador do qual os valores de tempo são lidos.  
  
## Comentários  
 Como qualquer faceta de localidade, a ID de objeto estático tem um valor armazenado inicial de zero.  A primeira tentativa de acessar seu valor armazenado armazena um valor positivo exclusivo em **id.**  
  
### Construtores  
  
|||  
|-|-|  
|[time\_get](../Topic/time_get::time_get.md)|O construtor para objetos do tipo `time_get`.|  
  
### Typedefs  
  
|||  
|-|-|  
|[char\_type](../Topic/time_get::char_type.md)|Um tipo que é usado para descrever um caractere usado por uma localidade.|  
|[iter\_type](../Topic/time_get::iter_type.md)|Um tipo que descreve um iterador de entrada.|  
  
### Funções membro  
  
|||  
|-|-|  
|[date\_order](../Topic/time_get::date_order.md)|Retorna a ordem de data usada por uma faceta.|  
|[do\_date\_order](../Topic/time_get::do_date_order.md)|Uma função membro virtual protegida que é chamada para retornar a ordem de data usada por uma faceta.|  
|[do\_get](../Topic/time_get::do_get.md)|Lê e converte dados de caractere em um valor de tempo.|  
|[do\_get\_date](../Topic/time_get::do_get_date.md)|Uma função membro virtual protegida que é chamada para analisar uma cadeia de caracteres como a data gerada pelo especificador `x` para `strftime`.|  
|[do\_get\_monthname](../Topic/time_get::do_get_monthname.md)|Uma função membro virtual protegida que é chamada para analisar uma cadeia de caracteres como o nome do mês.|  
|[do\_get\_time](../Topic/time_get::do_get_time.md)|Uma função membro virtual protegida que é chamada para analisar uma cadeia de caracteres como a data gerada pelo especificador `X` para `strftime`.|  
|[do\_get\_weekday](../Topic/time_get::do_get_weekday.md)|Uma função membro virtual protegida que é chamada para analisar uma cadeia de caracteres como o nome do dia da semana.|  
|[do\_get\_year](../Topic/time_get::do_get_year.md)|Uma função membro virtual protegida que é chamada para analisar uma cadeia de caracteres como o nome do ano.|  
|[get](../Topic/time_get::get.md)|Lê de uma origem de dados de caracteres e converte esses dados em uma hora que é armazenada em um struct de tempo.|  
|[get\_date](../Topic/time_get::get_date.md)|Analise uma cadeia de caracteres como a data gerada pelo especificador `x` para `strftime`.|  
|[get\_monthname](../Topic/time_get::get_monthname.md)|Analisa uma cadeia de caracteres como o nome do mês.|  
|[get\_time](../Topic/time_get::get_time.md)|Analise uma cadeia de caracteres como a data gerada pelo especificador `X` para `strftime`.|  
|[get\_weekday](../Topic/time_get::get_weekday.md)|Analisa uma cadeia de caracteres como o nome do dia da semana.|  
|[get\_year](../Topic/time_get::get_year.md)|Analisa uma cadeia de caracteres como o nome do ano.|  
  
## Requisitos  
 **Cabeçalho:** \<locale\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<locale\>](../standard-library/locale.md)   
 [Classe time\_base](../Topic/time_base%20Class.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)