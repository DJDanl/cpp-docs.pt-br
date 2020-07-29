---
title: Atributos de classe de armazenamento estendido C
ms.date: 11/04/2016
helpviewer_keywords:
- __declspec keyword [C]
- extended attributes
- extended storage-class attributes
- storage class specifiers, C storage classes
ms.assetid: 2580735c-f5bf-46ab-9468-0696893d82be
ms.openlocfilehash: 5e1fe80f3bc1f581c6ea05c54409b1e76eacfce7
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87190215"
---
# <a name="c-extended-storage-class-attributes"></a>Atributos de classe de armazenamento estendido C

**Específico da Microsoft**

Informações mais atualizadas sobre este tópico podem ser encontradas em [__declspec (Referência C++)](../cpp/declspec.md).

A sintaxe de atributo estendido simplifica e padroniza as extensões específicas da Microsoft para a linguagem C. Os atributos de classe de armazenamento que usam a sintaxe de atributo estendido incluem thread, naked, dllimport e dllexport.

A sintaxe de atributo estendido para a especificação de informações de classe de armazenamento usa a palavra-chave __declspec, que especifica que uma instância de um determinado tipo deve ser armazenada com um atributo de classe de armazenamento específico da Microsoft (thread, naked, dllimport ou dllexport). Exemplos de outros modificadores de classe de armazenamento incluem as palavras-chave static e extern. No entanto, essas palavras-chave fazem parte do padrão ANSI C e, assim, não são abrangidas pela sintaxe de atributo estendido.

## <a name="syntax"></a>Sintaxe

*storage-class-specifier*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**__declspec (** *Extended-decl-Modifier-Seq* **)**  / \* Específico da Microsoft\*/

*Extended-decl-Modifier-Seq*: &nbsp; &nbsp; &nbsp; &nbsp; / \* específico da Microsoft\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*extended-decl-modifier*<sub>opt</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*extended-decl-modifier-seq* *extended-decl-modifier*

*Extended-decl-Modifier*: &nbsp; &nbsp; &nbsp; &nbsp; / \* específico da Microsoft\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`thread`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`naked`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`dllimport`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`dllexport`**

O espaço em branco separa os modificadores de declaração. Observe que *extended-decl-modifier-seq* pode ser vazio; nesse caso, __declspec não tem efeito.

Os atributos de classe de armazenamento thread, naked, dllimport e dllexport são uma propriedade somente da declaração dos dados ou da função aos quais são aplicados; eles não redefinem os atributos de tipo da função em si. O atributo thread afeta somente dados. O atributo naked afeta somente funções. Os atributos dllimport e dllexport afetam funções e dados.

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Declarações e tipos](../c-language/declarations-and-types.md)
