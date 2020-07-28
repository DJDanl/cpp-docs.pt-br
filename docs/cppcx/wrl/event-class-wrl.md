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
ms.openlocfilehash: 27a90bb801d1b6869b2391227464bb215dd42538
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87220477"
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
[Evento:: evento](#event) | Inicializa uma nova instância da classe `Event`.

### <a name="public-operators"></a>Operadores públicos

Nome                                 | Descrição
------------------------------------ | ------------------------------------------------------------------------
[Evento:: Operator =](#operator-assign) | Atribui a `Event` referência especificada à `Event` instância atual.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`HandleT`

`Event`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft:: WRL:: wrappers

## <a name="eventevent"></a><a name="event"></a>Evento:: evento

Inicializa uma nova instância da classe `Event`.

```cpp
explicit Event(
   HANDLE h = HandleT::Traits::GetInvalidValue()
);
WRL_NOTHROW Event(
   _Inout_ Event&& h
);
```

### <a name="parameters"></a>parâmetros

*h*<br/>
Identificador para um evento. Por padrão, *h* é inicializada para **`nullptr`** .

## <a name="eventoperator"></a><a name="operator-assign"></a>Evento:: Operator =

Atribui a `Event` referência especificada à `Event` instância atual.

```cpp
WRL_NOTHROW Event& operator=(
   _Inout_ Event&& h
);
```

### <a name="parameters"></a>parâmetros

*h*<br/>
Uma referência de rvalue a uma `Event` instância.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a `Event` instância atual.
