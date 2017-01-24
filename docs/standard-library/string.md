---
title: "&lt;string&gt; | Microsoft Docs"
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
  - "std::<string>"
  - "string/std::<string>"
  - "std.<string>"
  - "<string>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho string"
ms.assetid: a2fb9d00-d7ae-4170-bfea-2dc337aa37cf
caps.latest.revision: 23
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# &lt;string&gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define a classe de modelo do contêiner `basic_string` e diversos modelos de suporte.  
  
 Para obter mais informações sobre `basic_string`, consulte [Classe basic\_string](../standard-library/basic-string-class.md)  
  
## Sintaxe  
  
```  
#include <string>  
```  
  
## Comentários  
 A linguagem C\+\+ e a biblioteca C\+\+ padrão dão suporte a dois tipos de cadeias de caracteres:  
  
-   Matrizes de caracteres com terminação nula geralmente conhecidas como cadeias de caracteres C.  
  
-   Objetos de classe de modelo, do tipo `basic_string`, que lidam com todos os argumentos de modelo do tipo `char`.  
  
### Typedefs  
  
|||  
|-|-|  
|[cadeia de caracteres](../Topic/string%20\(C++%20STL%20%3Cstring%3E\).md)|Um tipo que descreve uma especialização da classe modelo `basic_string` com elementos do tipo `char` como uma `string`.|  
|[wstring](../Topic/wstring.md)|Um tipo que descreve uma especialização da classe modelo `basic_string` com elementos do tipo `wchar_t` como uma `wstring`.|  
|[u16string](../Topic/u16string.md)|Um tipo que descreve uma especialização da classe modelo `basic_string` com base em elementos do tipo `char16_t`.|  
|[u32string](../Topic/u32string.md)|Um tipo que descreve uma especialização da classe modelo `basic_string` com base em elementos do tipo `char32_t`.|  
  
### Operadores  
  
|||  
|-|-|  
|[operator\+](../Topic/operator+%20\(%3Cstring%3E\).md)|Concatena dois objetos de cadeia de caracteres.|  
|[operator\!\=](../Topic/operator!=%20\(%3Cstring%3E\).md)|Testa se o objeto da cadeia de caracteres à esquerda do operador é diferente do objeto da cadeia de caracteres à direita.|  
|[operator\=\=](../Topic/operator==%20\(%3Cstring%3E\).md)|Testa se o objeto da cadeia de caracteres à esquerda do operador é igual ao objeto da cadeia de caracteres à direita.|  
|[Operador \<](../Topic/operator%3C%20\(%3Cstring%3E\).md)|Testa se o objeto da cadeia de caracteres à esquerda do operador é menor que o objeto da cadeia de caracteres à direita.|  
|[Operador \<\=](../Topic/operator%3C=%20\(in%20%3Cstring%3E\).md)|Testa se o objeto da cadeia de caracteres à esquerda do operador é menor que ou igual ao objeto da cadeia de caracteres à direita.|  
|[Operador \<\<](../Topic/operator%3C%3C%20\(%3Cstring%3E\).md)|Uma função de modelo que insere uma cadeia de caracteres no fluxo de saída.|  
|[Operador \>](../Topic/operator%3E%20\(%3Cstring%3E\).md)|Testa se o objeto da cadeia de caracteres à esquerda do operador é maior que o objeto da cadeia de caracteres à direita.|  
|[Operador \>\=](../Topic/operator%3E=%20\(%3Cstring%3E\).md)|Testa se o objeto da cadeia de caracteres à esquerda do operador é maior que ou igual ao objeto da cadeia de caracteres à direita.|  
|[Operador \>\>](../Topic/operator%3E%3E%20\(%3Cstring%3E\).md)|Uma função de modelo que extrai uma cadeia de caracteres do fluxo de entrada.|  
  
### Funções de Modelo Especializadas  
  
|||  
|-|-|  
|[swap](../Topic/swap%20\(C++%20STL%20%3Cstring%3E\).md)|Troca as matrizes de caracteres de duas cadeias de caracteres.|  
|[stod](../Topic/stod.md)|Converte uma sequência de caracteres em um `double.`|  
|[stof](../Topic/stof.md)|Converte uma sequência de caracteres em um `float`.|  
|[stoi](../Topic/stoi.md)|Converte uma sequência de caracteres em um número inteiro.|  
|[stold](../Topic/stold.md)|Converte uma sequência de caracteres em um `long double`.|  
|[stoll](../Topic/stoll.md)|Converte uma sequência de caracteres em um `long long`.|  
|[stoul](../Topic/stoul.md)|Converte uma sequência de caracteres em um `unsigned long`.|  
|[stoull](../Topic/stoull.md)|Converte uma sequência de caracteres em um `unsigned long long`.|  
|[to\_string](../Topic/to_string.md)|Converte um valor em uma `string`.|  
|[to\_wstring](../Topic/to_wstring.md)|Converte um valor em uma `string` larga.|  
  
### Funções  
  
|||  
|-|-|  
|[getline](../Topic/getline%20Template%20Function.md)|Extrai cadeias de caracteres do fluxo de entrada linha por linha.|  
  
### Classes  
  
|||  
|-|-|  
|[Classe basic\_string](../standard-library/basic-string-class.md)|Uma classe de modelo que descreve os objetos que pode armazenar uma sequência de objetos arbitrários do tipo caractere.|  
|[Struct char\_traits](../standard-library/char-traits-struct.md)|Uma classe de modelo que descreve os atributos associados a um caractere do tipo CharType|  
  
### Especializações  
  
|||  
|-|-|  
|[Struct char\_traits\<char\>](../standard-library/char-traits-char-struct.md)|Uma estrutura é uma especialização da estrutura de modelo `char_traits`\<CharType\> para um elemento do tipo `char`.|  
|[Struct char\_traits\<wchar\_t\>](../standard-library/char-traits-wchar-t-struct.md)|Uma estrutura é uma especialização da estrutura de modelo `char_traits`\<CharType\> para um elemento do tipo `wchar_t`.|  
|[Struct char\_traits\<char16\_t\>](../standard-library/char-traits-char16-t-struct.md)|Uma estrutura é uma especialização da estrutura de modelo `char_traits`\<CharType\> para um elemento do tipo `char16_t`.|  
|[Struct char\_traits\<char32\_t\>](../standard-library/char-traits-char32-t-struct.md)|Uma estrutura é uma especialização da estrutura de modelo `char_traits`\<CharType\> para um elemento do tipo `char32_t`.|  
  
## Requisitos  
  
-   **Cabeçalho:** \<string\>  
  
-   **Namespace:** std  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)