---
title: Classe Platform::Delegate
ms.date: 12/30/2016
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::Delegate
helpviewer_keywords:
- Platform::Delegate Class
ms.assetid: 82b21271-768f-4193-9ca2-be68ddfd546e
ms.openlocfilehash: 4116de3240c3ef334db51095997f946731372708
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58769232"
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

Use a palavra-chave [delegate](../extensions/delegate-cpp-component-extensions.md) para criar delegados; não use Platform::Delegate explicitamente. Para obter mais informações, consulte [Delegados](../cppcx/delegates-c-cx.md). Para ver um exemplo de como criar e consumir um delegado, veja [Creating Windows Runtime Components in C++](/windows/uwp/winrt-components/creating-windows-runtime-components-in-cpp).

### <a name="requirements"></a>Requisitos

**Cliente com suporte mínimo:** Windows 8

**Servidor com suporte mínimo:** Windows Server 2012

**Namespace:** Plataforma

**Metadados:** platform.winmd

## <a name="see-also"></a>Consulte também

[Namespace de plataforma](../cppcx/platform-namespace-c-cx.md)
