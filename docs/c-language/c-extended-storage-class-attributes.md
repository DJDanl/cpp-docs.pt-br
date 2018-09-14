---
title: Atributos de classe de armazenamento estendido C | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- __declspec keyword [C]
- extended attributes
- extended storage-class attributes
- storage class specifiers, C storage classes
ms.assetid: 2580735c-f5bf-46ab-9468-0696893d82be
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1a55f4ac98a712d8166c3d0ca5e22e13cb8c9145
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43758811"
---
# <a name="c-extended-storage-class-attributes"></a>Atributos de classe de armazenamento estendido C
**Seção específica da Microsoft**  
  
Informações mais atualizadas sobre este tópico podem ser encontradas em [__declspec (Referência C++)](../cpp/declspec.md).  
  
A sintaxe de atributo estendido simplifica e padroniza as extensões específicas da Microsoft para a linguagem C. Os atributos de classe de armazenamento que usam a sintaxe de atributo estendido incluem thread, naked, dllimport e dllexport.  
  
A sintaxe de atributo estendido para a especificação de informações de classe de armazenamento usa a palavra-chave __declspec, que especifica que uma instância de um determinado tipo deve ser armazenada com um atributo de classe de armazenamento específico da Microsoft (thread, naked, dllimport ou dllexport). Exemplos de outros modificadores de classe de armazenamento incluem as palavras-chave static e extern. No entanto, essas palavras-chave fazem parte do padrão ANSI C e, assim, não são abrangidas pela sintaxe de atributo estendido.  
  
## <a name="syntax"></a>Sintaxe

*storage-class-specifier*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**__declspec (** *extended-decl-modifier-seq* **)** /\* Específico da Microsoft \*/

*extended-decl-modifier-seq*:&nbsp;&nbsp;&nbsp;&nbsp;/\* Específico da Microsoft \*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*extended-decl-modifier*<sub>opt</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*extended-decl-modifier-seq* *extended-decl-modifier*

*extended-decl-modifier*:&nbsp;&nbsp;&nbsp;&nbsp;/\* Específico da Microsoft \*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**thread**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**naked**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**dllimport**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**dllexport**

O espaço em branco separa os modificadores de declaração. Observe que *extended-decl-modifier-seq* pode ser vazio; nesse caso, __declspec não tem efeito.
  
Os atributos de classe de armazenamento thread, naked, dllimport e dllexport são uma propriedade somente da declaração dos dados ou da função aos quais são aplicados; eles não redefinem os atributos de tipo da função em si. O atributo thread afeta somente dados. O atributo naked afeta somente funções. Os atributos dllimport e dllexport afetam funções e dados.  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
[Declarações e tipos](../c-language/declarations-and-types.md)