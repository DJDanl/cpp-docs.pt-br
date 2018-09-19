---
title: Erro do compilador C3290 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3290
dev_langs:
- C++
helpviewer_keywords:
- C3290
ms.assetid: 0baf684b-1143-4953-ac99-a2fa267d8017
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3b97818dd6ef7b38bb815e2c0a6345cc056fc45c
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46058913"
---
# <a name="compiler-error-c3290"></a>Erro do compilador C3290

'type': uma propriedade trivial não pode ter o tipo de referência

Uma propriedade foi declarada incorretamente. Quando você declarar uma propriedade trivial, o compilador cria uma variável que atualizará a propriedade e não é possível ter uma referência de acompanhamento de variável em uma classe.

Ver [propriedade](../../windows/property-cpp-component-extensions.md) e [operador de referência de acompanhamento](../../windows/tracking-reference-operator-cpp-component-extensions.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3290.

```
// C3290.cpp
// compile with: /clr /c
ref struct R {};

ref struct X {
   R^ mr;

   property R % y;   // C3290
   property R ^ x;   // OK

   // OK
   property R% prop {
      R% get() {
         return *mr;
      }

      void set(R%) {}
   }
};

int main() {
   X x;
   R% xp = x.prop;
}
```