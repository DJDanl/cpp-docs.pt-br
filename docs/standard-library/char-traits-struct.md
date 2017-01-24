---
title: "Struct char_traits | Microsoft Docs"
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
  - "std::char_traits"
  - "std.char_traits"
  - "iosfwd/std::char_traits"
  - "char_traits"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe char_traits"
  - "Struct char_traits"
ms.assetid: 568e59f0-4521-4207-9223-9dcf6a16d620
caps.latest.revision: 20
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Struct char_traits
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Struct char\_traits descreve os atributos associados a um caractere.  
  
## Sintaxe  
  
```  
template <  
   class CharType  
> struct char_traits;  
```  
  
#### Parâmetros  
 `CharType`  
 O tipo de dados do elemento.  
  
## Comentários  
 A estrutura do modelo descreve várias características de caractere do tipo**CharType**.  A classe de modelo[basic\_string](../standard-library/basic-string-class.md)bem como várias classes de modelo iostream, incluindo[basic\_ios](../Topic/basic_ios%20Class.md)usar essas informações para manipular elementos do tipo**CharType**.  Esse é um tipo de elemento não deve exigir explícita construção ou destruição.  Ele deve fornecer um construtor padrão, um construtor de cópia e um operador de atribuição, com a semântica esperado.  Uma cópia bit a bit deve ter o mesmo efeito de uma atribuição.  Nenhuma das funções de membro da estrutura char\_traits pode lançar exceções.  
  
### DefsTipo  
  
|||  
|-|-|  
|[char\_type](../Topic/char_traits::char_type.md)|Um tipo de caractere.|  
|[int\_type](../Topic/char_traits::int_type.md)|Um tipo de inteiro que pode representar um caractere do tipo`char_type`ou um caractere de final de arquivo \(EOF\).|  
|[off\_type](../Topic/char_traits::off_type.md)|Um tipo de inteiro que pode representar as compensações entre posições em um fluxo.|  
|[pos\_type](../Topic/char_traits::pos_type.md)|Um tipo de inteiro que pode representar posições em um fluxo.|  
|[state\_type](../Topic/char_traits::state_type.md)|Um tipo que representa o estado de conversão de caracteres multibyte em um fluxo.|  
  
### Funções membro  
  
|||  
|-|-|  
|[assign](../Topic/char_traits::assign.md)|Atribui um valor de caractere para outro.|  
|[compare](../Topic/char_traits::compare.md)|Compara um número específico de caracteres em duas cadeias de caracteres.|  
|[copy](../Topic/char_traits::copy.md)|Copia um número especificado de caracteres de uma cadeia de caracteres para outro.  Preterido.  Use[char\_traits::\_Copy\_s](../Topic/char_traits::_Copy_s.md)em vez disso.|  
|[\_Copy\_s](../Topic/char_traits::_Copy_s.md)|Copia um número especificado de caracteres de uma cadeia de caracteres para outro.|  
|[eof](../Topic/char_traits::eof.md)|Retorna o caractere de final de arquivo \(EOF\).|  
|[EQ](../Topic/char_traits::eq.md)|Testa se dois`char_type`caracteres são iguais.|  
|[eq\_int\_type](../Topic/char_traits::eq_int_type.md)|Testa se dois caracteres representados como`int_type`s são iguais.|  
|[find](../Topic/char_traits::find.md)|Localiza a primeira ocorrência de um caractere especificado em um intervalo de caracteres.|  
|[comprimento](../Topic/char_traits::length.md)|Retorna o comprimento de uma cadeia de caracteres.|  
|[lt](../Topic/char_traits::lt.md)|Testa se um caractere é menor que outro.|  
|[mover](../Topic/char_traits::move.md)|Copia um número especificado de caracteres em uma sequência para outro, sobrepostas possíveis, a sequência.  Preterido.  Use[char\_traits::\_Move\_s](../Topic/char_traits::_Move_s.md)em vez disso.|  
|[Move\_s](../Topic/char_traits::_Move_s.md)|Copia um número especificado de caracteres em uma sequência para outro, sobrepostas possíveis, a sequência.|  
|[not\_eof](../Topic/char_traits::not_eof.md)|Testa se um caractere é o caractere de final de arquivo \(EOF\).|  
|[to\_char\_type](../Topic/char_traits::to_char_type.md)|Converte um`int_type`caractere correspondente`char_type`de caracteres e retorna o resultado.|  
|[to\_int\_type](../Topic/char_traits::to_int_type.md)|Converte um`char_type`caractere correspondente`int_type`de caracteres e retorna o resultado.|  
  
## Requisitos  
 **Cabeçalho:** \<string\>  
  
 **Namespace:** std  
  
## Consulte também  
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)