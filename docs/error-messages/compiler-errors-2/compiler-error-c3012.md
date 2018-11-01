---
title: Erro do compilador C3012
ms.date: 11/04/2016
f1_keywords:
- C3012
helpviewer_keywords:
- C3012
ms.assetid: cc7040b1-b3fb-4da6-a474-877914d30332
ms.openlocfilehash: 9fe0ac7d3637cad3a5571c4631345dac1a0021bb
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50503072"
---
# <a name="compiler-error-c3012"></a>Erro do compilador C3012

> '*intrínseco*': função intrínseca não permitida diretamente dentro de uma região parallel

Um [intrínseco de compilador](../../intrinsics/compiler-intrinsics.md) função não é permitida em um `omp parallel` região. Para corrigir esse problema, mova intrínsecos fora da região, ou substituí-los com equivalentes intrínsecos.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3012 e mostra uma maneira de corrigir isso:

```cpp
// C3012.cpp
// compile with: /openmp
#ifdef __cplusplus
extern "C" {
#endif
void* _ReturnAddress();
#ifdef __cplusplus
}
#endif

int main()
{
   #pragma omp parallel
   {
      _ReturnAddress();   // C3012
   }
   _ReturnAddress();      // OK
}
```