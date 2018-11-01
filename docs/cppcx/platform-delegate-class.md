---
title: Classe Platform::Delegate
ms.date: 12/30/2016
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::Delegate
helpviewer_keywords:
- Platform::Delegate Class
ms.assetid: 82b21271-768f-4193-9ca2-be68ddfd546e
ms.openlocfilehash: 1b4a4955bbff53e6e0c5606f2900e22cc69146cc
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50446222"
---
# <a name="platformdelegate-class"></a>Classe Platform::Delegate

Representa um objeto de função.

## <a name="syntax"></a>Sintaxe

```cpp
public delegate void delegate_name();
```

### <a name="members"></a>Membros

A classe Delegate possui os métodos Equals(), GetHashCode() e ToString() derivados do [Platform::Object Class](../cppcx/platform-object-class.md).

### <a name="remarks"></a>Comentários

Use a palavra-chave [delegate](../windows/delegate-cpp-component-extensions.md) para criar delegados; não use Platform::Delegate explicitamente. Para obter mais informações, consulte [Delegados](../cppcx/delegates-c-cx.md). Para ver um exemplo de como criar e consumir um delegado, veja [Creating Windows Runtime Components in C++](/windows/uwp/winrt-components/creating-windows-runtime-components-in-cpp).

### <a name="requirements"></a>Requisitos

**Mínimo de cliente com suporte:** Windows 8

**Mínimo de servidor com suporte:** Windows Server 2012

**Namespace:** Platform

**Metadados:** platform.winmd

## <a name="see-also"></a>Consulte também

[Namespace Platform](../cppcx/platform-namespace-c-cx.md)