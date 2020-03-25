---
title: Erro do compilador C3286
ms.date: 11/04/2016
f1_keywords:
- C3286
helpviewer_keywords:
- C3286
ms.assetid: 554328c8-cf44-4f7d-a8d2-def74d28ecdd
ms.openlocfilehash: 4c87e98f11a560d0d92be8ea7bc624edd4e09ad2
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80201390"
---
# <a name="compiler-error-c3286"></a>Erro do compilador C3286

> '*especificador*': uma variável de iteração não pode ter nenhum especificador de classe de armazenamento

Uma classe de armazenamento não pode ser especificada em uma variável de iteração. Para obter mais informações, consulte [classes deC++armazenamento ()](../../cpp/storage-classes-cpp.md) e [para cada uma, em](../../dotnet/for-each-in.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3286 e também mostra o uso correto.

```cpp
// C3286.cpp
// compile with: /clr
int main() {
   array<int> ^p = { 1, 2, 3 };
   for each (static int i in p) {}   // C3286
   for each (int j in p) {}   // OK
}
```
