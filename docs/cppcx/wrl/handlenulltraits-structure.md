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
ms.openlocfilehash: 41e06cc50f36a077a34d992c416a543e5bf9b593
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371473"
---
# <a name="handlenulltraits-structure"></a>Estrutura HANDLENullTraits

Define características comuns de uma alça não inicializada.

## <a name="syntax"></a>Sintaxe

```cpp
struct HANDLENullTraits;
```

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

Nome   | Descrição
------ | ---------------------
`Type` | Um sinônimo de HANDLE.

### <a name="public-methods"></a>Métodos públicos

Nome                                                  | Descrição
----------------------------------------------------- | -----------------------------
[HANDLENullTraits::Close](#close)                     | Fecha a alça especificada.
[HANDLENullTraits::GetInvalidValue](#getinvalidvalue) | Representa uma alça inválida.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`HANDLENullTraits`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers.h

**Espaço de nome:** Microsoft::WRL::Wrappers::HandleTraits

## <a name="handlenulltraitsclose"></a><a name="close"></a>HANDLENullTraits::Close

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

## <a name="handlenulltraitsgetinvalidvalue"></a><a name="getinvalidvalue"></a>HANDLENullTraits::GetInvalidValue

Representa uma alça inválida.

```cpp
inline static Type GetInvalidValue();
```

### <a name="return-value"></a>Valor retornado

Retorna sempre `nullptr`.
