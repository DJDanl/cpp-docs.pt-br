---
title: Estrutura CriticalSectionTraits | Microsoft Docs
ms.custom: ''
ms.date: 09/26/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits::CriticalSectionTraits
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits::CriticalSectionTraits::GetInvalidValue
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits::CriticalSectionTraits::Unlock
dev_langs:
- C++
helpviewer_keywords:
- Microsoft::WRL::Wrappers::HandleTraits::CriticalSectionTraits structure
- Microsoft::WRL::Wrappers::HandleTraits::CriticalSectionTraits::GetInvalidValue method
- Microsoft::WRL::Wrappers::HandleTraits::CriticalSectionTraits::Unlock method
ms.assetid: c515a1b5-4eb0-40bc-9035-c4d9352c9de7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 420ab1019dfa2e95e00e366c64509178ad20e685
ms.sourcegitcommit: 1d9bd38cacbc783fccd3884b7b92062161c91c84
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/03/2018
ms.locfileid: "48234315"
---
# <a name="criticalsectiontraits-structure"></a>Estrutura CriticalSectionTraits

É especialista um `CriticalSection` objeto para dar suporte a uma seção crítica inválida ou uma função para liberar uma seção crítica.

## <a name="syntax"></a>Sintaxe

```
struct CriticalSectionTraits;
```

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

Nome   | Descrição
------ | -----------------------------------------------------------------------------------------------------------------
`Type` | Um `typedef` que define um ponteiro para uma seção crítica. `Type` é definido como `typedef CRITICAL_SECTION* Type;`.

### <a name="public-methods"></a>Métodos públicos

Nome                                                       | Descrição
---------------------------------------------------------- | -----------------
[Criticalsectiontraits:: Getinvalidvalue](#getinvalidvalue) | É especialista um `CriticalSection` modelo para que o modelo sempre é inválido.
[Criticalsectiontraits:: Unlock](#unlock)                   | É especialista um `CriticalSection` modelo para que ele dá suporte a liberar propriedade do objeto especificado de seção crítica.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CriticalSectionTraits`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers::HandleTraits

## <a name="getinvalidvalue"></a>Criticalsectiontraits:: Getinvalidvalue

É especialista um `CriticalSection` modelo para que o modelo sempre é inválido.

```cpp
inline static Type GetInvalidValue();
```

### <a name="return-value"></a>Valor de retorno

Sempre retorna um ponteiro para uma seção crítica inválida.

### <a name="remarks"></a>Comentários

O `Type` modificador é definido como `typedef CRITICAL_SECTION* Type;`.

## <a name="unlock"></a>Criticalsectiontraits:: Unlock

É especialista um `CriticalSection` modelo para que ele dá suporte a liberar propriedade do objeto especificado de seção crítica.

```cpp
inline static void Unlock(
   _In_ Type cs
);
```

### <a name="parameters"></a>Parâmetros

*cs*<br/>
Um ponteiro para um objeto de seção crítica.

### <a name="remarks"></a>Comentários

O `Type` modificador é definido como `typedef CRITICAL_SECTION* Type;`.

Para obter mais informações, consulte **função LeaveCriticalSection** na **funções de sincronização** seção da documentação da API do Windows.
