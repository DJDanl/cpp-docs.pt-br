---
title: Classe Platform::WrongThreadException
ms.date: 12/30/2016
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::WrongThreadException
- VCCORLIB/Platform::WrongThreadException::WrongThreadException
helpviewer_keywords:
- Platform::WrongThreadException
ms.assetid: c193f97e-0392-4535-a4c4-0711e4e4a836
ms.openlocfilehash: b59191eb739a94f305b656425ee2f3725815c7b8
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50639992"
---
# <a name="platformwrongthreadexception-class"></a>Classe Platform::WrongThreadException

Gerada quando um thread chama via um ponteiro de interface, que destina-se a um objeto proxy que não pertence ao apartment do thread.

## <a name="syntax"></a>Sintaxe

```cpp
public ref class WrongThreadException : COMException,    IException,    IPrintable,    IEquatable
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [COMException](../cppcx/platform-comexception-class.md).

### <a name="requirements"></a>Requisitos

**Mínimo de cliente com suporte:** Windows 8

**Mínimo de servidor com suporte:** Windows Server 2012

**Namespace:** Platform

**Metadados:** platform.winmd

## <a name="see-also"></a>Consulte também

[Classe Platform::COMException](../cppcx/platform-comexception-class.md)