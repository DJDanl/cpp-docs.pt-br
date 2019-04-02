---
title: Classe de evento (WRL)
ms.date: 09/24/2018
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::Event
- corewrappers/Microsoft::WRL::Wrappers::Event::Event
- corewrappers/Microsoft::WRL::Wrappers::Event::operator=
helpviewer_keywords:
- Microsoft::WRL::Wrappers::Event class
- Microsoft::WRL::Wrappers::Event::Event, constructor
- Microsoft::WRL::Wrappers::Event::operator= operator
ms.assetid: 55dfc9fc-62d4-4bb2-9d85-5b6dd88569e8
ms.openlocfilehash: 2d36b4fa3d1824f43e0cfafe55c439a6bdeccb6f
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58783924"
---
# <a name="event-class-wrl"></a>Classe de evento (WRL)

Representa um evento.

## <a name="syntax"></a>Sintaxe

```cpp
class Event : public HandleT<HandleTraits::EventTraits>;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

Nome                   | Descrição
---------------------- | ------------------------------------------------
[Event::Event](#event) | Inicializa uma nova instância da classe `Event`.

### <a name="public-operators"></a>Operadores públicos

Nome                                 | Descrição
------------------------------------ | ------------------------------------------------------------------------
[Event::operator=](#operator-assign) | Atribui especificado `Event` referência atual `Event` instância.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`HandleT`

`Event`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers

## <a name="event"></a>Event::Event

Inicializa uma nova instância da classe `Event`.

```cpp
explicit Event(
   HANDLE h = HandleT::Traits::GetInvalidValue()
);
WRL_NOTHROW Event(
   _Inout_ Event&& h
);
```

### <a name="parameters"></a>Parâmetros

*h*<br/>
Manipular um evento. Por padrão, *h* é inicializado como `nullptr`.

## <a name="operator-assign"></a>Event::operator=

Atribui especificado `Event` referência atual `Event` instância.

```cpp
WRL_NOTHROW Event& operator=(
   _Inout_ Event&& h
);
```

### <a name="parameters"></a>Parâmetros

*h*<br/>
Uma referência rvalue para um `Event` instância.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a atual `Event` instância.
