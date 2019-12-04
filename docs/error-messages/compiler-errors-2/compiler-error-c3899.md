---
title: Erro do compilador C3899
ms.date: 11/04/2016
f1_keywords:
- C3899
helpviewer_keywords:
- C3899
ms.assetid: 14e07e4a-f7a7-4309-baaa-649d69e12e23
ms.openlocfilehash: 022bc1a37f7d9cfdb2c206592dd303a9c3c95080
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74749107"
---
# <a name="compiler-error-c3899"></a>Erro do compilador C3899

' var ': o uso de l-Value de membro de dados InitOnly não é permitido diretamente dentro de uma região Parallel na classe ' class '

Um membro de dados [InitOnly (C++/CLI)](../../dotnet/initonly-cpp-cli.md) não pode ser inicializado dentro dessa parte de um construtor que está em uma região [paralela](../../parallel/openmp/reference/parallel.md) .  Isso ocorre porque o compilador faz uma realocação interna desse código, de modo que ele não faz mais parte do construtor.

Para resolver, inicialize o membro de dados InitOnly no construtor, mas fora da região paralela.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3899.

```cpp
// C3899.cpp
// compile with: /clr /openmp
#include <omp.h>

public ref struct R {
   initonly int x;
   R() {
      x = omp_get_thread_num() + 1000;   // OK
      #pragma omp parallel num_threads(5)
      {
         // cannot assign to 'x' here
         x = omp_get_thread_num() + 1000;   // C3899
         System::Console::WriteLine("thread {0}", omp_get_thread_num());
      }
      x = omp_get_thread_num() + 1000;   // OK
   }
};

int main() {
   R^ r = gcnew R;
   System::Console::WriteLine(r->x);
}
```
