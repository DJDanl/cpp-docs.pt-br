---
title: "Classe wbuffer_convert | Microsoft Docs"
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
  - "stdext::cvt::wbuffer_convert"
  - "wbuffer_convert"
  - "stdext.cvt.wbuffer_convert"
  - "cvt.wbuffer_convert"
  - "cvt::wbuffer_convert"
  - "wbuffer/stdext::cvt::wbuffer_convert"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe wbuffer_convert"
ms.assetid: 4a56f9bf-4138-4612-b516-525fea401358
caps.latest.revision: 20
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe wbuffer_convert
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Descreve um buffer de fluxo que controla a transmissão de elementos em um buffer de fluxo de bytes.  
  
## Sintaxe  
  
```  
template<class Codecvt,  
    class Elem = wchar_t,  
    class Traits = std::char_traits<Elem>  
>  
    class wbuffer_convert  
        : public std::basic_streambuf<Elem, Traits>  
```  
  
#### Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|---------------|  
|`Codecvt`|O [localidade](../standard-library/locale-class.md) faceta que representa o objeto de conversão.|  
|`Elem`|O tipo de elemento de caractere largo.|  
|`Traits`|As características associadas *Elem*.|  
  
## Comentários  
 Essa classe de modelo descreve um buffer de fluxo que controla a transmissão de elementos do tipo `_Elem`, cujas características de caractere são descritas pela classe `Traits`, de e para um buffer de fluxo de bytes do tipo `std::streambuf`.  
  
 Conversão entre uma sequência de `Elem` valores e seqüências multibyte é executada por um objeto da classe `Codecvt<Elem, char, std::mbstate_t>`, que atende aos requisitos da faceta padrão de conversão de código `std::codecvt<Elem, char, std::mbstate_t>`.  
  
 Armazena um objeto dessa classe de modelo:  
  
-   Um ponteiro para o buffer de fluxo de bytes subjacente  
  
-   Um ponteiro para o objeto de conversão alocado \(que é liberada quando o [wbuffer\_convert](../standard-library/wbuffer-convert-class.md) objeto é destruído\)  
  
-   Um objeto de estado de conversão de tipo [state\_type](../Topic/wbuffer_convert::state_type.md).  
  
### Construtores  
  
|||  
|-|-|  
|[wbuffer\_convert](../Topic/wbuffer_convert::wbuffer_convert.md)|Constrói um objeto do tipo `wbuffer_convert`.|  
  
### DefsTipo  
  
|||  
|-|-|  
|[state\_type](../Topic/wbuffer_convert::state_type.md)|Um tipo que representa o estado de conversão.|  
  
### Funções membro  
  
|||  
|-|-|  
|[rdbuf](../Topic/wbuffer_convert::rdbuf.md)|Retorna o buffer de fluxo de bytes.|  
|[estado](../Topic/wbuffer_convert::state.md)|Retorna um objeto que representa o estado da conversão.|  
  
## Requisitos  
 **Cabeçalho:** \<locale\>  
  
 **Namespace:** std