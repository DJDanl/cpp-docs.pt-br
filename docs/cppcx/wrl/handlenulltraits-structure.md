---
title: Estrutura HANDLENullTraits
ms.date: 09/27/2018
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits::HANDLENullTraits
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits::HANDLENullTraits::Close
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits::HANDLENullTraits::GetInvalidValue
helpviewer_keywords:
- Microsoft::WRL::Wrappers::HandleTraits::HANDLENullTraits structure
- Microsoft::WRL::Wrappers::HandleTraits::HANDLENullTraits::Close method
- Microsoft::WRL::Wrappers::HandleTraits::HANDLENullTraits::GetInvalidValue method
ms.assetid: 88a29a14-c516-40cb-a0ca-ee897a668623
ms.openlocfilehash: a7ce730b8d723a839c5b509c825cff84111ca613
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87226913"
---
# <a name="handlenulltraits-structure"></a>Estrutura HANDLENullTraits

Define características comuns de um identificador não inicializado.

## <a name="syntax"></a>Sintaxe

```cpp
struct HANDLENullTraits;
```

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

Nome   | Descrição
------ | ---------------------
`Type` | Um sinônimo para identificador.

### <a name="public-methods"></a>Métodos públicos

Nome                                                  | Descrição
----------------------------------------------------- | -----------------------------
[HANDLENullTraits:: fechar](#close)                     | Fecha o identificador especificado.
[HANDLENullTraits:: getinvalidvalue](#getinvalidvalue) | Representa um identificador inválido.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`HANDLENullTraits`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft:: WRL:: wrappers:: HandleTraits

## <a name="handlenulltraitsclose"></a><a name="close"></a>HANDLENullTraits:: fechar

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

## <a name="handlenulltraitsgetinvalidvalue"></a><a name="getinvalidvalue"></a>HANDLENullTraits:: getinvalidvalue

Representa um identificador inválido.

```cpp
inline static Type GetInvalidValue();
```

### <a name="return-value"></a>Valor retornado

Sempre retorna **`nullptr`** .
