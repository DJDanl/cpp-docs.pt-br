---
title: "Classe wstring_convert | Microsoft Docs"
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
  - "cvt.wstring_convert"
  - "wstring_convert"
  - "stdext::cvt::wstring_convert"
  - "cvt::wstring_convert"
  - "wstring/stdext::cvt::wstring_convert"
  - "stdext.cvt.wstring_convert"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe wstring_convert"
ms.assetid: e34f5b65-d572-4bdc-ac69-20778712e376
caps.latest.revision: 25
caps.handback.revision: 15
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe wstring_convert
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe de modelo `wstring_convert` executa conversões entre uma cadeia de caracteres larga e uma cadeia de caracteres de byte.  
  
## Sintaxe  
  
```  
template<  
    class Codecvt,  
    class Elem = wchar_t  
>  
class wstring_convert  
```  
  
#### Parâmetros  
 Codecvt  
 O [localidade](../standard-library/locale-class.md) faceta que representa o objeto de conversão.  
  
 Elem  
 O tipo de elemento de caractere largo.  
  
## Comentários  
 A classe de modelo descreve um objeto que controla conversões entre objetos de cadeia de caracteres larga da classe `std::basic_string<Elem>` e objetos de cadeia de caracteres de byte da classe `std::basic_string<char>` \(também conhecido como `std::string`\). A classe de modelo define os tipos de `wide_string` e `byte_string` como sinônimos para esses dois tipos. Conversão entre uma sequência de `Elem` valores \(armazenado em uma `wide_string` objeto\) e sequências de multibyte \(armazenado em uma `byte_string` objeto\) é executada por um objeto da classe `Codecvt<Elem, char, std::mbstate_t>`, que atende aos requisitos da faceta de conversão de código padrão `std::codecvt<Elem, char, std::mbstate_t>`.  
  
 Armazena um objeto dessa classe de modelo:  
  
-   Uma cadeia de caracteres de byte para exibir erros  
  
-   Uma cadeia de caracteres larga para exibir erros  
  
-   Um ponteiro para o objeto de conversão alocado \(que é liberado quando o objeto wbuffer\_convert é destruído\)  
  
-   Um objeto de estado de conversão de tipo [state\_type](../Topic/wstring_convert::state_type.md)  
  
-   Uma contagem de conversão  
  
### Construtores  
  
|||  
|-|-|  
|[wstring\_convert](../Topic/wstring_convert::wstring_convert.md)|Constrói um objeto do tipo `wstring_convert`.|  
  
### Typedefs  
  
|||  
|-|-|  
|[byte\_string](../Topic/wstring_convert::byte_string.md)|Um tipo que representa uma cadeia de caracteres de byte.|  
|[wide\_string](../Topic/wstring_convert::wide_string.md)|Um tipo que representa uma cadeia de caracteres larga.|  
|[state\_type](../Topic/wstring_convert::state_type.md)|Um tipo que representa o estado de conversão.|  
|[int\_type](../Topic/wstring_convert::int_type.md)|Um tipo que representa um número inteiro.|  
  
### Funções membro  
  
|||  
|-|-|  
|[from\_bytes](../Topic/wstring_convert::from_bytes.md)|Converte uma cadeia de caracteres de bytes em uma cadeia de caracteres larga.|  
|[to\_bytes](../Topic/wstring_convert::to_bytes.md)|Converte uma cadeia de caracteres longa em uma cadeia de caracteres de byte.|  
|[convertido](../Topic/wstring_convert::converted.md)|Retorna o número de conversões com êxito.|  
|[estado](../Topic/wstring_convert::state.md)|Retorna um objeto que representa o estado da conversão.|  
  
## Requisitos  
 **Cabeçalho:** \< local \>  
  
 **Namespace:** std