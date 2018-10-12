---
title: 'bool auto_gcroot:: Operator | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- auto_gcroot.operator bool
- auto_gcroot::operator bool
- msclr.auto_gcroot.operator bool
- msclr::auto_gcroot::operator bool
- operator bool
dev_langs:
- C++
helpviewer_keywords:
- bool operator
ms.assetid: 87d38498-4221-4de8-8d02-c2dd2e6274ec
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: c2fe517809db7cecacc7a0190e0dae94ef55c35d
ms.sourcegitcommit: 8480f16893f09911f08a58caf684405404f7ac8e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/12/2018
ms.locfileid: "49161184"
---
# <a name="autogcrootoperator-bool"></a>Bool auto_gcroot::operator

Operador para usar `auto_gcroot` em uma expressão condicional.

## <a name="syntax"></a>Sintaxe

```
operator bool() const;
```

## <a name="return-value"></a>Valor de retorno

**True** se o objeto encapsulado for válido; **falsos** caso contrário.

## <a name="remarks"></a>Comentários

Este operador converte realmente para `_detail_class::_safe_bool` que é mais segura do que **bool** porque ele não pode ser convertido em um tipo integral.

## <a name="example"></a>Exemplo

```cpp
// msl_auto_gcroot_operator_bool.cpp
// compile with: /clr
#include <msclr\auto_gcroot.h>

using namespace System;
using namespace msclr;

int main() {
   auto_gcroot<String^> s;
   if ( s ) Console::WriteLine( "s is valid" );
   if ( !s ) Console::WriteLine( "s is invalid" );
   s = "something";
   if ( s ) Console::WriteLine( "now s is valid" );
   if ( !s ) Console::WriteLine( "now s is invalid" );
   s.reset();
   if ( s ) Console::WriteLine( "now s is valid" );
   if ( !s ) Console::WriteLine( "now s is invalid" );
}
```

```Output
s is invalid
now s is valid
now s is invalid
```

## <a name="requirements"></a>Requisitos

**Arquivo de cabeçalho** \<msclr\auto_gcroot.h >

**Namespace** msclr

## <a name="see-also"></a>Consulte também

[Membros auto_gcroot](../dotnet/auto-gcroot-members.md)<br/>
[auto_gcroot::operator!](../dotnet/auto-gcroot-operator-logical-not.md)