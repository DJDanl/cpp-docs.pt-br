---
title: Aviso LNK4247 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4247
helpviewer_keywords:
- LNK4247
ms.assetid: 085d7fdf-9eaf-4641-8473-6eaadd073c7b
ms.openlocfilehash: 344c219fa1f3daa1e5f9c31431e608f5e7036400
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74991161"
---
# <a name="linker-tools-warning-lnk4247"></a>Aviso LNK4247 (Ferramentas de Vinculador)

o ponto de entrada ' decorated_function_name ' já tem um atributo de thread; ' attribute ' ignorado

Um ponto de entrada, especificado com [/Entry (símbolo de ponto de entrada)](../../build/reference/entry-entry-point-symbol.md), tinha um atributo threading, mas [/CLRTHREADATTRIBUTE (Set CLR thread Attribute)](../../build/reference/clrthreadattribute-set-clr-thread-attribute.md) também foi especificado, com um modelo de threading diferente.

O vinculador ignorou o valor especificado com/CLRTHREADATTRIBUTE.

Para resolver este aviso:

- Remova o/CLRTHREADATTRIBUTE da sua compilação.

- Remova o atributo do seu arquivo de código-fonte.

- Remova o atributo da origem e do/CLRTHREADATTRIBUTE de sua compilação e aceite o modelo de Threading CLR padrão.

- Altere o valor passado para/CLRTHREADATTRIBUTE, de modo que ele concorde com o atributo na origem.

- Altere o atributo na origem, de modo que ele concorde com o valor passado para/CLRTHREADATTRIBUTE.

O exemplo a seguir gera LNK4247

```cpp
// LNK4247.cpp
// compile with: /clr /c
// post-build command: link /CLRTHREADATTRIBUTE:STA LNK4247.obj /entry:functionTitle /SUBSYSTEM:Console
[System::MTAThreadAttribute]
void functionTitle (){}
```
