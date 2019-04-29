---
title: Aviso LNK4247 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4247
helpviewer_keywords:
- LNK4247
ms.assetid: 085d7fdf-9eaf-4641-8473-6eaadd073c7b
ms.openlocfilehash: cd4108f8bd06ec7a0b2d2eb9fab13917174b797b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62346954"
---
# <a name="linker-tools-warning-lnk4247"></a>Aviso LNK4247 (Ferramentas de Vinculador)

ponto de entrada 'decorated_function_name' já tem um atributo de thread; 'attribute' ignorado

Um ponto de entrada especificado com [/ENTRY (símbolo de ponto de entrada)](../../build/reference/entry-entry-point-symbol.md), tinha um atributo de thread, mas [/CLRTHREADATTRIBUTE (definir atributo de Thread CLR)](../../build/reference/clrthreadattribute-set-clr-thread-attribute.md) também foi especificado, com um modelo de threading diferente.

O vinculador ignorado o valor especificado com /CLRTHREADATTRIBUTE.

Para resolver este aviso:

- Remova /CLRTHREADATTRIBUTE da sua compilação.

- Remova o atributo do seu arquivo de código fonte.

- Remova ambos os o atributo de origem e /CLRTHREADATTRIBUTE do seu build e aceitar o modelo de threading do CLR padrão.

- Altere o valor passado para /CLRTHREADATTRIBUTE, de modo que ela está de acordo com o atributo no código-fonte.

- Altere o atributo na fonte, de modo que ela está de acordo com o valor passado para /CLRTHREADATTRIBUTE.

O exemplo a seguir gera LNK4247

```
// LNK4247.cpp
// compile with: /clr /c
// post-build command: link /CLRTHREADATTRIBUTE:STA LNK4247.obj /entry:functionTitle /SUBSYSTEM:Console
[System::MTAThreadAttribute]
void functionTitle (){}
```