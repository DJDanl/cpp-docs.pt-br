---
title: Erro do compilador C3012 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3012
dev_langs:
- C++
helpviewer_keywords:
- C3012
ms.assetid: cc7040b1-b3fb-4da6-a474-877914d30332
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 99bdac5ffb75978479ae7ef420a48b3d1b2f8e64
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46063665"
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