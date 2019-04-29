---
title: Erro do compilador C2745
ms.date: 11/04/2016
f1_keywords:
- C2745
helpviewer_keywords:
- C2745
ms.assetid: a1c45f13-7667-4678-aa16-265304a449a1
ms.openlocfilehash: 53a218fd80c6b8261aa0dda6bcaa1c347db73458
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62360301"
---
# <a name="compiler-error-c2745"></a>Erro do compilador C2745

'token': este token não pode ser convertido em um identificador

Identificadores devem ser compostos por caracteres legais.

O exemplo a seguir gera C2745:

```
// C2745.cpp
// compile with: /clr
int main() {
   int __identifier([));   // C2745
}
```