---
title: Erro do compilador C3295
ms.date: 11/04/2016
f1_keywords:
- C3295
helpviewer_keywords:
- C3295
ms.assetid: 83f0aa4d-0e0a-4905-9f66-fcf9991fc07a
ms.openlocfilehash: 63739989d737527e3f136bb3aac2269eda6231c1
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62222551"
---
# <a name="compiler-error-c3295"></a>Erro do compilador C3295

'#pragma pragma' só pode ser usada em global ou escopo de namespace

Alguns pragmas não pode ser usado em uma função.  Ver [diretivas Pragma e a palavra-chave pragma](../../preprocessor/pragma-directives-and-the-pragma-keyword.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3295.

```
// C3295.cpp
int main() {
   #pragma managed   // C3295
}
```