---
title: Bool auto_handle::operator
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- auto_handle.operator bool
- msclr.auto_handle.operator bool
- operator bool
- msclr::auto_handle::operator bool
- auto_handle::operator bool
helpviewer_keywords:
- auto_handle::operator bool
ms.assetid: 2e535e99-cf87-4008-b588-02c587d77453
ms.openlocfilehash: 95a4b324194b2e1adf8cc9596f8e2440379e5a47
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50565939"
---
# <a name="autohandleoperator-bool"></a>Bool auto_handle::operator

Operador para usar `auto_handle` em uma expressão condicional.

## <a name="syntax"></a>Sintaxe

```
operator bool();
```

## <a name="return-value"></a>Valor de retorno

**True** se o objeto encapsulado for válido; **falsos** caso contrário.

## <a name="remarks"></a>Comentários

Este operador converte realmente para `_detail_class::_safe_bool` que é mais segura do que **bool** porque ele não pode ser convertido em um tipo integral.

## <a name="example"></a>Exemplo

```
// msl_auto_handle_operator_bool.cpp
// compile with: /clr
#include <msclr\auto_handle.h>

using namespace System;
using namespace msclr;

int main() {
   auto_handle<String> s1;
   auto_handle<String> s2 = "hi";
   if ( s1 ) Console::WriteLine( "s1 is valid" );
   if ( !s1 ) Console::WriteLine( "s1 is invalid" );
   if ( s2 ) Console::WriteLine( "s2 is valid" );
   if ( !s2 ) Console::WriteLine( "s2 is invalid" );
   s2.reset();
   if ( s2 ) Console::WriteLine( "s2 is now valid" );
   if ( !s2 ) Console::WriteLine( "s2 is now invalid" );
}
```

```Output
s1 is invalid
s2 is valid
s2 is now invalid
```

## <a name="requirements"></a>Requisitos

**Arquivo de cabeçalho** \<msclr\auto_handle.h >

**Namespace** msclr

## <a name="see-also"></a>Consulte também

[Membros auto_handle](../dotnet/auto-handle-members.md)<br/>
[auto_handle::operator!](../dotnet/auto-handle-operator-logical-not.md)