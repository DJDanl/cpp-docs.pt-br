---
title: Erro do compilador C3899
ms.date: 11/04/2016
f1_keywords:
- C3899
helpviewer_keywords:
- C3899
ms.assetid: 14e07e4a-f7a7-4309-baaa-649d69e12e23
ms.openlocfilehash: 26860ba0e8fd92f491ee389147605ba82cecf25c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50598387"
---
# <a name="compiler-error-c3899"></a>Erro do compilador C3899

'var': uso l-value de membro de dados initonly não é permitido diretamente dentro de uma região parallel na classe 'class'

Uma [initonly (C + + c++ CLI)](../../dotnet/initonly-cpp-cli.md) membro de dados não pode ser inicializado dentro dessa parte de um construtor que está em um [paralela](../../parallel/openmp/reference/parallel.md) região.  Isso é porque o compilador faz uma realocação interna desse código, de modo que ela efetivamente não é parte do construtor.

Para resolver, inicialize o membro de dados initonly no construtor, mas fora da região paralela.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3899.

```
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