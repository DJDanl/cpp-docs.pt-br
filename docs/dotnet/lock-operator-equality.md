---
title: lock::operator==
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- lock::operator==
- msclr.lock.operator==
- msclr::lock::operator==
- lock.operator==
helpviewer_keywords:
- lock::operator==
ms.assetid: 3dcf1e5a-53fc-495d-9df5-d7849a41c36c
ms.openlocfilehash: 2e7e78f5d03074058dadd969f150855f305cf85e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50647857"
---
# <a name="lockoperator"></a>lock::operator==

Operador de igualdade.

## <a name="syntax"></a>Sintaxe

```
template<class T> bool operator==(
   T t
);
```

#### <a name="parameters"></a>Parâmetros

*t*<br/>
A igualdade de um objeto a ser comparado.

## <a name="return-value"></a>Valor de retorno

Retorna **verdadeira** se `t` é o mesmo objeto do bloqueio **falso** caso contrário.

## <a name="example"></a>Exemplo

```cpp
// msl_lock_op_eq.cpp
// compile with: /clr
#include <msclr/lock.h>

using namespace System;
using namespace System::Threading;
using namespace msclr;

int main () {
   Object^ o1 = gcnew Object;
   lock l1(o1);
   if (l1 == o1) {
      Console::WriteLine("Equal!");
   }
}
```

```Output
Equal!
```

## <a name="requirements"></a>Requisitos

**Arquivo de cabeçalho** \<msclr\lock.h >

**Namespace** msclr

## <a name="see-also"></a>Consulte também

[Membros lock](../dotnet/lock-members.md)<br/>
[lock::operator!=](../dotnet/lock-operator-inequality.md)