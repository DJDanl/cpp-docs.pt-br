---
title: Estrutura CriticalSectionTraits
ms.date: 09/26/2018
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits::CriticalSectionTraits
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits::CriticalSectionTraits::GetInvalidValue
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits::CriticalSectionTraits::Unlock
helpviewer_keywords:
- Microsoft::WRL::Wrappers::HandleTraits::CriticalSectionTraits structure
- Microsoft::WRL::Wrappers::HandleTraits::CriticalSectionTraits::GetInvalidValue method
- Microsoft::WRL::Wrappers::HandleTraits::CriticalSectionTraits::Unlock method
ms.assetid: c515a1b5-4eb0-40bc-9035-c4d9352c9de7
ms.openlocfilehash: 3573cad21734a97629cbc12b76d73b99024cbc2f
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87220503"
---
# <a name="criticalsectiontraits-structure"></a>Estrutura CriticalSectionTraits

Especializa um `CriticalSection` objeto para dar suporte a uma seção crítica inválida ou a uma função para liberar uma seção crítica.

## <a name="syntax"></a>Sintaxe

```
struct CriticalSectionTraits;
```

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

Nome   | Descrição
------ | -----------------------------------------------------------------------------------------------------------------
`Type` | Um **`typedef`** que define um ponteiro para uma seção crítica. `Type` é definido como `typedef CRITICAL_SECTION* Type;`.

### <a name="public-methods"></a>Métodos públicos

Nome                                                       | Descrição
---------------------------------------------------------- | -----------------
[CriticalSectionTraits:: getinvalidvalue](#getinvalidvalue) | Especializa um `CriticalSection` modelo para que o modelo seja sempre inválido.
[CriticalSectionTraits:: desbloquear](#unlock)                   | Especializa um `CriticalSection` modelo para que ele dê suporte à liberação de Propriedade do objeto de seção crítica especificado.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CriticalSectionTraits`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft:: WRL:: wrappers:: HandleTraits

## <a name="criticalsectiontraitsgetinvalidvalue"></a><a name="getinvalidvalue"></a>CriticalSectionTraits:: getinvalidvalue

Especializa um `CriticalSection` modelo para que o modelo seja sempre inválido.

```cpp
inline static Type GetInvalidValue();
```

### <a name="return-value"></a>Valor retornado

Sempre retorna um ponteiro para uma seção crítica inválida.

### <a name="remarks"></a>Comentários

O `Type` modificador é definido como `typedef CRITICAL_SECTION* Type;` .

## <a name="criticalsectiontraitsunlock"></a><a name="unlock"></a>CriticalSectionTraits:: desbloquear

Especializa um `CriticalSection` modelo para que ele dê suporte à liberação de Propriedade do objeto de seção crítica especificado.

```cpp
inline static void Unlock(
   _In_ Type cs
);
```

### <a name="parameters"></a>parâmetros

*CS*<br/>
Um ponteiro para um objeto de seção crítica.

### <a name="remarks"></a>Comentários

O `Type` modificador é definido como `typedef CRITICAL_SECTION* Type;` .

Para obter mais informações, consulte a **função LeaveCriticalSection** na seção **funções de sincronização** da documentação da API do Windows.
