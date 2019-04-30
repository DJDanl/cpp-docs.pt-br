---
title: Compilador aviso (nível 4) C4289
ms.date: 11/04/2016
f1_keywords:
- C4289
helpviewer_keywords:
- C4289
ms.assetid: 0dbd2863-4cde-4e16-894b-104a2d5fa724
ms.openlocfilehash: 3a997af466ddfdaaf4631afeb53d917ce0338c3b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62400897"
---
# <a name="compiler-warning-level-4-c4289"></a>Compilador aviso (nível 4) C4289

extensão não padrão usada: 'var': variável de controle de loop declarada no loop for é usada fora do escopo do loop for

Ao compilar com [/Ze](../../build/reference/za-ze-disable-language-extensions.md) e **/Zc:forScope-**, uma variável declarada em um [para](../../cpp/for-statement-cpp.md) loop foi usado após o **para**-escopo de loop.

Ver [/ZC: forScope](../../build/reference/zc-forscope-force-conformance-in-for-loop-scope.md) para obter informações sobre como especificar o comportamento padrão no **para** faz um loop com **/Ze**.

Esse aviso é desativado por padrão. Ver [compilador avisos que são desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.

O exemplo a seguir gera C4289:

```
// C4289.cpp
// compile with: /W4 /Zc:forScope-
#pragma warning(default:4289)
int main() {
   for (int i = 0 ; ; )   // C4289
      break;
   i++;
}
```