---
title: Estrutura HANDLETraits
ms.date: 09/27/2018
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits::HANDLETraits
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits::HANDLETraits::Close
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits::HANDLETraits::GetInvalidValue
helpviewer_keywords:
- Microsoft::WRL::Wrappers::HandleTraits::HANDLETraits structure
- Microsoft::WRL::Wrappers::HandleTraits::HANDLETraits::Close method
- Microsoft::WRL::Wrappers::HandleTraits::HANDLETraits::GetInvalidValue method
ms.assetid: 22963e88-d857-4624-9182-7c986daff722
ms.openlocfilehash: c04e53789fd737b12ca10ef2c279a05fb43f5925
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87212989"
---
# <a name="handletraits-structure"></a>Estrutura HANDLETraits

Define características comuns de um identificador.

## <a name="syntax"></a>Sintaxe

```cpp
struct HANDLETraits;
```

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

Nome   | Descrição
------ | ---------------------
`Type` | Um sinônimo para identificador.

### <a name="public-methods"></a>Métodos públicos

Nome                                              | Descrição
------------------------------------------------- | -----------------------------
[HANDLETraits:: fechar](#close)                     | Fecha o identificador especificado.
[HANDLETraits:: getinvalidvalue](#getinvalidvalue) | Representa um identificador inválido.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`HANDLETraits`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft:: WRL:: wrappers:: HandleTraits

## <a name="handletraitsclose"></a><a name="close"></a>HANDLETraits:: fechar

Fecha o identificador especificado.

```cpp
inline static bool Close(
   _In_ Type h
);
```

### <a name="parameters"></a>parâmetros

*h*<br/>
O identificador a ser fechado.

### <a name="return-value"></a>Valor retornado

**`true`** Se o identificador *h* foi fechado com êxito; caso contrário, **`false`** .

## <a name="handletraitsgetinvalidvalue"></a><a name="getinvalidvalue"></a>HANDLETraits:: getinvalidvalue

Representa um identificador inválido.

```cpp
inline static HANDLE GetInvalidValue();
```

### <a name="return-value"></a>Valor retornado

Sempre retorna INVALID_HANDLE_VALUE. (INVALID_HANDLE_VALUE é definido pelo Windows.)
