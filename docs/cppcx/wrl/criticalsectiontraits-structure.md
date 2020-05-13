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
ms.openlocfilehash: 05c93bf6a2765bd11489075067c627ab3c3ab691
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372576"
---
# <a name="criticalsectiontraits-structure"></a>Estrutura CriticalSectionTraits

É especialespecializado um `CriticalSection` objeto para suportar uma seção crítica inválida ou uma função para liberar uma seção crítica.

## <a name="syntax"></a>Sintaxe

```
struct CriticalSectionTraits;
```

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

Nome   | Descrição
------ | -----------------------------------------------------------------------------------------------------------------
`Type` | A `typedef` que define um ponteiro para uma seção crítica. `Type` é definido como `typedef CRITICAL_SECTION* Type;`.

### <a name="public-methods"></a>Métodos públicos

Nome                                                       | Descrição
---------------------------------------------------------- | -----------------
[CriticalSectionTraits::GetInvalidValue](#getinvalidvalue) | Especializa `CriticalSection` um modelo para que o modelo seja sempre inválido.
[critica-setraits::desbloquear](#unlock)                   | É um `CriticalSection` modelo especializado para que ele suporte a liberação da propriedade do objeto de seção crítica especificado.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CriticalSectionTraits`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers.h

**Espaço de nome:** Microsoft::WRL::Wrappers::HandleTraits

## <a name="criticalsectiontraitsgetinvalidvalue"></a><a name="getinvalidvalue"></a>CriticalSectionTraits::GetInvalidValue

Especializa `CriticalSection` um modelo para que o modelo seja sempre inválido.

```cpp
inline static Type GetInvalidValue();
```

### <a name="return-value"></a>Valor retornado

Sempre retorna um ponteiro para uma seção crítica inválida.

### <a name="remarks"></a>Comentários

O `Type` modificador é `typedef CRITICAL_SECTION* Type;`definido como .

## <a name="criticalsectiontraitsunlock"></a><a name="unlock"></a>critica-setraits::desbloquear

É um `CriticalSection` modelo especializado para que ele suporte a liberação da propriedade do objeto de seção crítica especificado.

```cpp
inline static void Unlock(
   _In_ Type cs
);
```

### <a name="parameters"></a>Parâmetros

*Cs*<br/>
Um ponteiro para um objeto de seção crítica.

### <a name="remarks"></a>Comentários

O `Type` modificador é `typedef CRITICAL_SECTION* Type;`definido como .

Para obter mais informações, consulte **a função LeaveCriticalSection** na seção Funções de **sincronização** da documentação da API do Windows.
