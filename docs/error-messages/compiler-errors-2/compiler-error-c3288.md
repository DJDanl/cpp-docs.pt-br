---
title: Erro do compilador C3288 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3288
dev_langs:
- C++
helpviewer_keywords:
- C3288
ms.assetid: ed08a540-9751-46e1-9cbe-c51d6a49ffab
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 36412510efcedd765ad44b4aab61e6a7d64155fb
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46079928"
---
# <a name="compiler-error-c3288"></a>Erro do compilador C3288

'type': cancelamento inválido de um tipo de identificador

O compilador detectou uma ilegal desreferência de um tipo de identificador. Você pode cancelar a referência de um tipo de identificador e atribuí-lo a uma referência. Para obter mais informações, consulte [operador de referência de acompanhamento](../../windows/tracking-reference-operator-cpp-component-extensions.md).

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