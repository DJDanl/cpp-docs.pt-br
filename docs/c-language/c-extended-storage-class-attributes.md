---
title: "Atributos de classe de armazenamento estendido C | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Palavra-chave __declspec [C]"
  - "atributos estendidos"
  - "atributos de classe de armazenamento estendido"
  - "especificadores de classe de armazenamento, classes de armazenamento C"
ms.assetid: 2580735c-f5bf-46ab-9468-0696893d82be
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Atributos de classe de armazenamento estendido C
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Informações mais atualizadas sobre este tópico podem ser encontradas em [\_\_declspec \(Referência C\+\+\)](../cpp/declspec.md).  
  
 A sintaxe de atributo estendido simplifica e padroniza as extensões específicas da Microsoft para a linguagem C.  Os atributos de classe de armazenamento que usam a sintaxe de atributo estendido incluem thread, naked, dllimport e dllexport.  
  
 A sintaxe de atributo estendido para a especificação de informações de classe de armazenamento usa a palavra\-chave \_\_declspec, que especifica que uma instância de um determinado tipo deve ser armazenada com um atributo de classe de armazenamento específico da Microsoft \(thread, naked, dllimport ou dllexport\).  Exemplos de outros modificadores de classe de armazenamento incluem as palavras\-chave static e extern.  No entanto, essas palavras\-chave fazem parte do padrão ANSI C e, assim, não são abrangidas pela sintaxe de atributo estendido.  
  
## Sintaxe  
 *storage\-class\-specifier*:  
 `__declspec` \( *extended\-decl\-modifier\-seq* \) \/\* Específico da Microsoft \*\/  
  
 *extended\-decl\-modifier\-seq*:  
 *extended\-decl\-modifier*  opt  
  
 *extended\-decl\-modifier\-seq extended\-decl\-modifier*  
  
 *extended\-decl\-modifier*:  
 **thread**  
  
 **naked**  
  
 **dllimport**  
  
 `dllexport`  
  
 O espaço em branco separa os modificadores de declaração.  Observe que *extended\-decl\-modifier\-seq* pode ser vazio; nesse caso, \_\_declspec não tem efeito.  
  
 Os atributos de classe de armazenamento thread, naked, dllimport e dllexport são uma propriedade somente da declaração dos dados ou da função aos quais são aplicados; eles não redefinem os atributos de tipo da função em si.  O atributo thread afeta somente dados.  O atributo naked afeta somente funções.  Os atributos dllimport e dllexport afetam funções e dados.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Declarações e tipos](../c-language/declarations-and-types.md)