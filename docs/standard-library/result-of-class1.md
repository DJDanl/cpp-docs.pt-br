---
title: "Classe result_of | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "cpp"
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "result_of"
  - "std.result_of"
  - "std::result_of"
  - "type_traits/std::result_of"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "result_of"
ms.assetid: 5374a096-4b4a-4712-aa97-6852c5cdd6be
caps.latest.revision: 13
caps.handback.revision: 3
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe result_of
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Determina o tipo de retorno do tipo callable que usa os tipos de argumento especificado.  
  
## Sintaxe  
  
```  
template <class Fn, class... ArgTypes>  
    struct result_of<Fn(ArgTypes...)>;  
```  
  
#### Parâmetros  
 `Fn`  
 O tipo que pode ser chamado para consulta.  
  
 `ArgTypes`  
 Os tipos de lista de argumentos para o tipo que pode ser chamado para consulta.  
  
## Comentários  
 Use este modelo para determinar em tempo de compilação o tipo de resultado de `Fn`\(`ArgTypes`\), onde `Fn` é um tipo que pode ser chamado invocado com uma lista de argumentos de tipos em `ArgTypes`. O `type` o tipo de resultado os nomes dos membros da classe modelo `decltype(INVOKE(declval<Fn>(), declval<ArgTypes>()...))` se a expressão não avaliada `INVOKE(declval<Fn>(), declval<ArgTypes>()...)` está bem formado. Caso contrário, a classe de modelo não tiver nenhum membro `type`. O tipo `Fn` e todos os tipos de pacote de parâmetros `ArgTypes` devem ser tipos completos, `void`, ou matrizes de associação desconhecida.  
  
## Requisitos  
 **Cabeçalho:** \< type\_traits \>  
  
 **Namespace:** std  
  
## Consulte também  
 [\< type\_traits \>](../standard-library/type-traits.md)