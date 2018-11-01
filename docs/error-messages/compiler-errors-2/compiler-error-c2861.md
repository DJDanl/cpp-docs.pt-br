---
title: Erro do compilador C2861
ms.date: 11/04/2016
f1_keywords:
- C2861
helpviewer_keywords:
- C2861
ms.assetid: 012bb44d-6c9b-4def-b54e-b19f1f8ddd1b
ms.openlocfilehash: e7cced7a9abd974d0cbcea69059459d6c15f9850
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50514693"
---
# <a name="compiler-error-c2861"></a>Erro do compilador C2861

'nome da função': uma função de membro de interface não pode ser definida.

O compilador encontrou a palavra-chave interface ou deduzido um struct como uma interface, mas encontrado, em seguida, um membro de definição de função.  Uma interface não pode conter uma definição para uma função de membro.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2861:

```
// C2861.cpp
// compile with: /c
#include <objbase.h>   // required for IUnknown definition
[ object, uuid("00000000-0000-0000-0000-000000000001") ]
__interface IMyInterface : IUnknown {
   HRESULT mf(int a);
};

HRESULT IMyInterface::mf(int a) {}   // C2861

```