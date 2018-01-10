---
title: Atributos de classe de armazenamento estendido C | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- __declspec keyword [C]
- extended attributes
- extended storage-class attributes
- storage class specifiers, C storage classes
ms.assetid: 2580735c-f5bf-46ab-9468-0696893d82be
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 972a8dc27283839ce1eade0e1e9b81dc92998b15
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="c-extended-storage-class-attributes"></a>Atributos de classe de armazenamento estendido C
**Seção específica da Microsoft**  
  
 Informações mais atualizadas sobre este tópico podem ser encontradas em [__declspec (Referência C++)](../cpp/declspec.md).  
  
 A sintaxe de atributo estendido simplifica e padroniza as extensões específicas da Microsoft para a linguagem C. Os atributos de classe de armazenamento que usam a sintaxe de atributo estendido incluem thread, naked, dllimport e dllexport.  
  
 A sintaxe de atributo estendido para a especificação de informações de classe de armazenamento usa a palavra-chave __declspec, que especifica que uma instância de um determinado tipo deve ser armazenada com um atributo de classe de armazenamento específico da Microsoft (thread, naked, dllimport ou dllexport). Exemplos de outros modificadores de classe de armazenamento incluem as palavras-chave static e extern. No entanto, essas palavras-chave fazem parte do padrão ANSI C e, assim, não são abrangidas pela sintaxe de atributo estendido.  
  
## <a name="syntax"></a>Sintaxe  
 *storage-class-specifier*:  
 `__declspec` ( *extended-decl-modifier-seq* ) /* Específico da Microsoft \*/  
  
 *extended-decl-modifier-seq*:  
 *extended-decl-modifier* opt  
  
 *extended-decl-modifier-seq extended-decl-modifier*  
  
 *extended-decl-modifier*:  
 **thread**  
  
 **naked**  
  
 **dllimport**  
  
 `dllexport`  
  
 O espaço em branco separa os modificadores de declaração. Observe que *extended-decl-modifier-seq* pode ser vazio; nesse caso, __declspec não tem efeito.  
  
 Os atributos de classe de armazenamento thread, naked, dllimport e dllexport são uma propriedade somente da declaração dos dados ou da função aos quais são aplicados; eles não redefinem os atributos de tipo da função em si. O atributo thread afeta somente dados. O atributo naked afeta somente funções. Os atributos dllimport e dllexport afetam funções e dados.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Declarações e tipos](../c-language/declarations-and-types.md)