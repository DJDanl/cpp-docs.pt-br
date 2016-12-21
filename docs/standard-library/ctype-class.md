---
title: "Classe ctype | Microsoft Docs"
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
  - "ctype"
  - "std::ctype"
  - "std.ctype"
  - "CType"
  - "xlocale/std::ctype"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe ctype"
ms.assetid: 3627154c-49d9-47b5-b28f-5bbedee38e3b
caps.latest.revision: 19
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe ctype
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma classe que fornece uma faceta usada para classificar caracteres, fazer conversões de letras maiúsculas e minúsculas, bem como fazer a conversão entre o conjunto de caracteres nativos e o conjunto usado pela localidade.  
  
## Sintaxe  
  
```  
template <class CharType>  
   class ctype : public ctype_base;  
```  
  
#### Parâmetros  
 `CharType`  
 O tipo usado em um programa para codificar caracteres.  
  
## Comentários  
 Como qualquer faceta de localidade, a ID de objeto estático tem um valor armazenado inicial de zero.  A primeira tentativa de acessar seu valor armazenado armazena um valor positivo exclusivo em **id.** Os critérios de classificação são fornecidos em um tipo de bitmask aninhado em ctype\_base da classe base.  
  
 A Biblioteca Padrão do C\+\+ define duas especializações explícitas dessa classe de modelo:  
  
-   [ctype](#vclrf_locale_ctype_class)\<`char`\>, uma especialização explícita cujas diferenças são descritas separadamente.  
  
-   **ctype**\<`wchar_t`\>, que trata os elementos como caracteres largos.  
  
 Outras especializações da classe de modelo **ctype**\<**CharType**\>:  
  
-   Converter um valor ***ch*** do tipo **CharType** em um valor do tipo `char` com a expressão \(`char`\)**ch**.  
  
-   Converter um valor ***byte*** do tipo `char` em um valor do tipo **CharType** com a expressão **CharType** \(**byte**\).  
  
 Todas as outras operações são executadas nos valores `char` da mesma forma que para a especialização explícita **ctype**\<`char`\>.  
  
### Construtores  
  
|||  
|-|-|  
|[ctype](../Topic/ctype::ctype.md)|Construtor para objetos da classe `ctype` que atuam como facetas de localidade para caracteres.|  
  
### Typedefs  
  
|||  
|-|-|  
|[char\_type](../Topic/ctype::char_type.md)|Um tipo que descreve um caractere usado por uma localidade.|  
  
### Funções membro  
  
|||  
|-|-|  
|[do\_is](../Topic/ctype::do_is.md)|Uma função virtual chamada para testar se um único caractere tem um atributo específico ou para classificar os atributos de cada caractere em um intervalo e armazená\-los em uma matriz.|  
|[do\_narrow](../Topic/ctype::do_narrow.md)|Uma função virtual chamada para converter um caractere do tipo `CharType` usado por uma localidade em caractere correspondente do tipo `char` no conjunto de caracteres nativos.|  
|[do\_scan\_is](../Topic/ctype::do_scan_is.md)|Uma função virtual chamada para localizar o primeiro caractere em um intervalo que corresponda a uma máscara especificada.|  
|[do\_scan\_not](../Topic/ctype::do_scan_not.md)|Uma função virtual chamada para localizar o primeiro caractere em um intervalo que não corresponda a uma máscara especificada.|  
|[do\_tolower](../Topic/ctype::do_tolower.md)|Uma função virtual chamada para converter um caractere ou um intervalo em letras minúsculas.|  
|[do\_toupper](../Topic/ctype::do_toupper.md)|Uma função virtual chamada para converter um caractere ou um intervalo em letras maiúsculas.|  
|[do\_widen](../Topic/ctype::do_widen.md)|Uma função virtual chamada para converter um caractere do tipo `char` no conjunto de caracteres nativos em caractere correspondente do tipo `CharType` usado por uma localidade.|  
|[is](../Topic/ctype::is.md)|Testa se um único caractere tem um atributo específico ou classifica os atributos de cada caractere em um intervalo e os armazena em uma matriz.|  
|[narrow](../Topic/ctype::narrow.md)|Converte um caractere do tipo `CharType` usado por uma localidade em caractere correspondente do tipo char no conjunto de caracteres nativos.|  
|[scan\_is](../Topic/ctype::scan_is.md)|Localiza o primeiro caractere em um intervalo que corresponda a uma máscara especificada.|  
|[scan\_not](../Topic/ctype::scan_not.md)|Localiza o primeiro caractere em um intervalo que não corresponda a uma máscara especificada.|  
|[tolower](../Topic/ctype::tolower.md)|Converte um caractere ou um intervalo de caracteres em letras minúsculas.|  
|[toupper](../Topic/ctype::toupper.md)|Converte um caractere ou um intervalo de caracteres em letras maiúsculas.|  
|[widen](../Topic/ctype::widen.md)|Converte um caractere do tipo `char` no conjunto de caracteres nativos em caractere correspondente do tipo `CharType` usado por uma localidade.|  
  
## Requisitos  
 **Cabeçalho:** \<locale\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<locale\>](../standard-library/locale.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)