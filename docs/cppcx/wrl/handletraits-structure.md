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
ms.openlocfilehash: 604098cd3289722767117910d6e44e272dcb8b77
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371441"
---
# <a name="handletraits-structure"></a>Estrutura HANDLETraits

Define características comuns de uma alça.

## <a name="syntax"></a>Sintaxe

```cpp
struct HANDLETraits;
```

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

Nome   | Descrição
------ | ---------------------
`Type` | Um sinônimo de HANDLE.

### <a name="public-methods"></a>Métodos públicos

Nome                                              | Descrição
------------------------------------------------- | -----------------------------
[HANDLETraits::Close](#close)                     | Fecha a alça especificada.
[HANDLETraits::GetInvalidValue](#getinvalidvalue) | Representa uma alça inválida.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`HANDLETraits`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers.h

**Espaço de nome:** Microsoft::WRL::Wrappers::HandleTraits

## <a name="handletraitsclose"></a><a name="close"></a>HANDLETraits::Close

Fecha a alça especificada.

```cpp
inline static bool Close(
   _In_ Type h
);
```

### <a name="parameters"></a>Parâmetros

*H*<br/>
A alça para fechar.

### <a name="return-value"></a>Valor retornado

**verdade** se a alça *h* fechado com sucesso; caso contrário, **falso**.

## <a name="handletraitsgetinvalidvalue"></a><a name="getinvalidvalue"></a>HANDLETraits::GetInvalidValue

Representa uma alça inválida.

```cpp
inline static HANDLE GetInvalidValue();
```

### <a name="return-value"></a>Valor retornado

Sempre retorna INVALID_HANDLE_VALUE. (INVALID_HANDLE_VALUE é definida pelo Windows.)
