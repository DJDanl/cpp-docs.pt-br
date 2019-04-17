---
title: Erro do compilador C3288
ms.date: 11/04/2016
f1_keywords:
- C3288
helpviewer_keywords:
- C3288
ms.assetid: ed08a540-9751-46e1-9cbe-c51d6a49ffab
ms.openlocfilehash: d076dabe0df91cefb90be5ec9e90f371331a51f1
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58771001"
---
# <a name="compiler-error-c3288"></a>Erro do compilador C3288

'type': cancelamento inválido de um tipo de identificador

O compilador detectou uma ilegal desreferência de um tipo de identificador. Você pode cancelar a referência de um tipo de identificador e atribuí-lo a uma referência. Para obter mais informações, consulte [operador de referência de acompanhamento](../../extensions/tracking-reference-operator-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3288.

```
// C3288.cpp
// compile with: /clr
ref class R {};
int main() {
   *(System::Object^) nullptr;   // C3288

// OK
   (System::Object^) nullptr;   // OK
   R^ r;
   R% pr = *r;
}
```