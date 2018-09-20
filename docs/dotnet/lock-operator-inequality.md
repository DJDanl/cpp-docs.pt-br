---
title: 'Lock:: Operator! = | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- lock.operator!=
- msclr.lock.operator!=
- msclr::lock::operator!=
- lock::operator!=
dev_langs:
- C++
helpviewer_keywords:
- lock::operator!=
ms.assetid: ed1d674e-9ee9-4257-8a7e-2e3567d50222
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: d96ddbd35b37f084e277951812f7868452ed09d5
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46438191"
---
# <a name="lockoperator"></a>lock::operator!=

Operador de desigualdade.

## <a name="syntax"></a>Sintaxe

```
template<class T> bool operator!=(
   T t
);
```

#### <a name="parameters"></a>Parâmetros

*t*<br/>
O objeto a ser comparado quanto à desigualdade.

## <a name="return-value"></a>Valor de retorno

Retorna `true` se `t` é diferente do objeto do bloqueio, `false` caso contrário.

## <a name="example"></a>Exemplo

```
// msl_lock_op_ineq.cpp
// compile with: /clr
#include <msclr/lock.h>

using namespace System;
using namespace System::Threading;
using namespace msclr;

int main () {
   Object^ o1 = gcnew Object;
   Object^ o2 = gcnew Object;
   lock l1(o1);
   if (l1 != o2) {
      Console::WriteLine("Inequal!");
   }
}
```

```Output
Inequal!
```

## <a name="requirements"></a>Requisitos

**Arquivo de cabeçalho** \<msclr\lock.h >

**Namespace** msclr

## <a name="see-also"></a>Consulte também

[Membros lock](../dotnet/lock-members.md)<br/>
[lock::operator==](../dotnet/lock-operator-equality.md)