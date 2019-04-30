---
title: Erro do compilador C3153
ms.date: 11/04/2016
f1_keywords:
- C3153
helpviewer_keywords:
- C3153
ms.assetid: d775d97e-2480-484f-81f1-88406b10f947
ms.openlocfilehash: 62b9e7499c52153183f14eae47c488da6a59b458
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62374866"
---
# <a name="compiler-error-c3153"></a>Erro do compilador C3153

'interface': você não pode criar uma instância de uma interface

Uma interface não pode ser instanciada. Para usar os membros de uma interface, derive uma classe de interface, implementar os membros de interface e, em seguida, usar os membros.

O exemplo a seguir gera C3153:

```
// C3153.cpp
// compile with: /clr
interface class A {
};

int main() {
   A^ a = gcnew A;   // C3153
}
```
