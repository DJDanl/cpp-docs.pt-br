---
title: Ferramentas de vinculador LNK4247 aviso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4247
dev_langs:
- C++
helpviewer_keywords:
- LNK4247
ms.assetid: 085d7fdf-9eaf-4641-8473-6eaadd073c7b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2d84a5964cb8df5d2973b6031da55d48dade584e
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46078004"
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