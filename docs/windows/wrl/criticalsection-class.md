---
title: Classe CriticalSection
ms.date: 09/24/2018
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::CriticalSection
- corewrappers/Microsoft::WRL::Wrappers::CriticalSection::cs_
- corewrappers/Microsoft::WRL::Wrappers::CriticalSection::IsValid
- corewrappers/Microsoft::WRL::Wrappers::CriticalSection::Lock
- corewrappers/Microsoft::WRL::Wrappers::CriticalSection::~CriticalSection
- corewrappers/Microsoft::WRL::Wrappers::CriticalSection::CriticalSection
- corewrappers/Microsoft::WRL::Wrappers::CriticalSection::TryLock
helpviewer_keywords:
- Microsoft::WRL::Wrappers::CriticalSection class
- Microsoft::WRL::Wrappers::CriticalSection::cs_ data member
- Microsoft::WRL::Wrappers::CriticalSection::IsValid method
- Microsoft::WRL::Wrappers::CriticalSection::Lock method
- Microsoft::WRL::Wrappers::CriticalSection::~CriticalSection, destructor
- Microsoft::WRL::Wrappers::CriticalSection::CriticalSection, constructor
- Microsoft::WRL::Wrappers::CriticalSection::TryLock method
ms.assetid: f2e0a024-71a3-4f6b-99ea-d93a4a608ac4
ms.openlocfilehash: dd34206741ba8fee8b283e22b6e8eefb3b3efb0e
ms.sourcegitcommit: 360b55e89e5954f494e52b1cf989fbaceda06f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/16/2019
ms.locfileid: "54335479"
---
# <a name="criticalsection-class"></a>Classe CriticalSection

Representa um objeto de seção crítica.

## <a name="syntax"></a>Sintaxe

```cpp
class CriticalSection;
```

## <a name="members"></a>Membros

### <a name="constructor"></a>Construtor

Nome                                                        | Descrição
----------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------
[CriticalSection::CriticalSection](#criticalsection)        | Inicializa um objeto de sincronização que é semelhante a um objeto de mutex, mas pode ser usado por apenas os threads de um único processo.
[CriticalSection::~CriticalSection](#tilde-criticalsection) | Realiza o desligamento e destrói atual `CriticalSection` objeto.

### <a name="public-methods"></a>Métodos públicos

Nome                                 | Descrição
------------------------------------ | ---------------------------------------------------------------------------------------------------------------------------------------------
[CriticalSection::IsValid](#isvalid) | Indica se a seção crítica atual é válida.
[CriticalSection::Lock](#lock)       | Aguarda até que propriedade do objeto especificado de seção crítica. A função retorna quando o thread de chamada é concedido a propriedade.
[CriticalSection::TryLock](#trylock) | Tenta inserir uma seção crítica sem bloqueio. Se a chamada for bem-sucedida, o thread de chamada se apropria de seção crítica.

### <a name="protected-data-members"></a>Membros de dados protegidos

Nome                        | Descrição
--------------------------- | ----------------------------------------
[CriticalSection::cs_](#cs) | Declara um membro de dados da seção crítica.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CriticalSection`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers

## <a name="tilde-criticalsection"></a>CriticalSection::~CriticalSection

Realiza o desligamento e destrói atual `CriticalSection` objeto.

```cpp
WRL_NOTHROW ~CriticalSection();
```

## <a name="criticalsection"></a>CriticalSection::CriticalSection

Inicializa um objeto de sincronização que é semelhante a um objeto de mutex, mas pode ser usado por apenas os threads de um único processo.

```cpp
explicit CriticalSection(
   ULONG spincount = 0
);
```

### <a name="parameters"></a>Parâmetros

*spincount*<br/>
A contagem de rotação para o objeto de seção crítica. O valor padrão é 0.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre as seções críticas e spincounts, consulte o `InitializeCriticalSectionAndSpinCount` funcionar a `Synchronization` seção da documentação de API do Windows.

## <a name="cs"></a>CriticalSection::cs_

Declara um membro de dados da seção crítica.

```cpp
CRITICAL_SECTION cs_;
```

### <a name="remarks"></a>Comentários

Este membro de dados está protegido.

## <a name="isvalid"></a>CriticalSection::IsValid

Indica se a seção crítica atual é válida.

```cpp
bool IsValid() const;
```

### <a name="return-value"></a>Valor de retorno

Por padrão, sempre retorna **verdadeira**.

## <a name="lock"></a>CriticalSection::Lock

Aguarda até que propriedade do objeto especificado de seção crítica. A função retorna quando o thread de chamada é concedido a propriedade.

```cpp
SyncLock Lock();

   static SyncLock Lock(
   _In_ CRITICAL_SECTION* cs
);
```

### <a name="parameters"></a>Parâmetros

*cs*<br/>
Um objeto de seção crítica especificado pelo usuário.

### <a name="return-value"></a>Valor de retorno

Um objeto de bloqueio que pode ser usado para desbloquear a seção crítica atual.

### <a name="remarks"></a>Comentários

A primeira `Lock` function afeta o objeto atual de seção crítica. O segundo `Lock` function afeta uma seção crítica especificado pelo usuário.

## <a name="trylock"></a>CriticalSection::TryLock

Tenta inserir uma seção crítica sem bloqueio. Se a chamada for bem-sucedida, o thread de chamada se apropria de seção crítica.

```cpp
SyncLock TryLock();

static SyncLock TryLock(
   _In_ CRITICAL_SECTION* cs
);
```

### <a name="parameters"></a>Parâmetros

*cs*<br/>
Um objeto de seção crítica especificado pelo usuário.

### <a name="return-value"></a>Valor de retorno

Um valor diferente de zero se a seção crítica for inserida com êxito ou o thread atual já possui a seção crítica. Zero se outro thread já possui a seção crítica.

### <a name="remarks"></a>Comentários

A primeira `TryLock` function afeta o objeto atual de seção crítica. O segundo `TryLock` function afeta uma seção crítica especificado pelo usuário.
