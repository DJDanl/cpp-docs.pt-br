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
ms.openlocfilehash: dde8c9afff6be083580042a958f59e057bc44350
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62396074"
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

**Cliente com suporte mínimo:** Windows 8

**Servidor com suporte mínimo:** Windows Server 2012

**Namespace:** Plataforma

**Metadados:** platform.winmd

## <a name="see-also"></a>Consulte também

[Classe Platform::COMException](../cppcx/platform-comexception-class.md)
