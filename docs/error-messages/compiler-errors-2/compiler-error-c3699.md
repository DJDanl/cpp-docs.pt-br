---
title: Erro do compilador C3699
ms.date: 11/04/2016
f1_keywords:
- C3699
helpviewer_keywords:
- C3699
ms.assetid: 47c29afc-ab8b-4238-adfe-788dd6e00b3b
ms.openlocfilehash: 93058d34ca9a17ab175a55a7bc7b953d369e65c5
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59779447"
---
# <a name="compiler-error-c3699"></a>Erro do compilador C3699

'operator': não é possível usar esta indireção no tipo 'type'

Foi feita uma tentativa para usar o caminho indireto que não é permitido em `type`.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3699.

```
// C3699.cpp
// compile with: /clr /c
using namespace System;
int main() {
   String * s;   // C3699
   // try the following line instead
   // String ^ s2;
}
```

## <a name="example"></a>Exemplo

Uma propriedade trivial não pode ter um tipo de referência. Ver [propriedade](../../extensions/property-cpp-component-extensions.md) para obter mais informações. O exemplo a seguir gera C3699.

```
// C3699_b.cpp
// compile with: /clr /c
ref struct C {
   property System::String % x;   // C3699
   property System::String ^ y;   // OK
};
```

## <a name="example"></a>Exemplo

O equivalente a uma sintaxe de "ponteiro para um ponteiro" é um identificador para uma referência de rastreamento. O exemplo a seguir gera C3699.

```
// C3699_c.cpp
// compile with: /clr /c
using namespace System;
void Test(String ^^ i);   // C3699
void Test2(String ^% i);
```