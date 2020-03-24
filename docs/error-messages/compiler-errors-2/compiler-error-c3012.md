---
title: Erro do compilador C3012
ms.date: 11/04/2016
f1_keywords:
- C3012
helpviewer_keywords:
- C3012
ms.assetid: cc7040b1-b3fb-4da6-a474-877914d30332
ms.openlocfilehash: 69f0544815804e9827631be81bf9735a95bd1a22
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80176696"
---
# <a name="compiler-error-c3012"></a>Erro do compilador C3012

> '*intrínseco*': função intrínseca não permitida diretamente em uma região paralela

Uma função [intrínseca do compilador](../../intrinsics/compiler-intrinsics.md) não é permitida em uma região `omp parallel`. Para corrigir esse problema, mova intrínsecos para fora da região ou substitua-os por equivalentes não intrínsecos.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3012 e mostra uma maneira de corrigi-lo:

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
