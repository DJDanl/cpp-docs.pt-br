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
ms.openlocfilehash: b95e512f89ee1ff32ca9f1bea51bce643d185a2e
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87220516"
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
[CriticalSection:: CriticalSection](#criticalsection)        | Inicializa um objeto de sincronização semelhante a um objeto mutex, mas pode ser usado somente por threads de um único processo.
[CriticalSection:: ~ CriticalSection](#tilde-criticalsection) | Desinicializa e destrói o objeto atual `CriticalSection` .

### <a name="public-methods"></a>Métodos públicos

Nome                                 | Descrição
------------------------------------ | ---------------------------------------------------------------------------------------------------------------------------------------------
[CriticalSection:: IsValid](#isvalid) | Indica se a seção crítica atual é válida.
[CriticalSection:: Lock](#lock)       | Aguarda a propriedade do objeto de seção crítica especificado. A função retorna quando o thread de chamada recebe a propriedade.
[CriticalSection:: TryLock](#trylock) | Tenta inserir uma seção crítica sem bloqueio. Se a chamada for bem-sucedida, o thread de chamada assumirá a propriedade da seção crítica.

### <a name="protected-data-members"></a>Membros de Dados Protegidos

Nome                        | Descrição
--------------------------- | ----------------------------------------
[CriticalSection:: cs_](#cs) | Declara um membro de dados de seção crítica.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CriticalSection`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft:: WRL:: wrappers

## <a name="criticalsectioncriticalsection"></a><a name="tilde-criticalsection"></a>CriticalSection:: ~ CriticalSection

Desinicializa e destrói o objeto atual `CriticalSection` .

```cpp
WRL_NOTHROW ~CriticalSection();
```

## <a name="criticalsectioncriticalsection"></a><a name="criticalsection"></a>CriticalSection:: CriticalSection

Inicializa um objeto de sincronização semelhante a um objeto mutex, mas pode ser usado somente por threads de um único processo.

```cpp
explicit CriticalSection(
   ULONG spincount = 0
);
```

### <a name="parameters"></a>parâmetros

*spincount*<br/>
A contagem de rotação para o objeto da seção crítica. O valor padrão é 0.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre seções críticas e spincounts, consulte a `InitializeCriticalSectionAndSpinCount` função na `Synchronization` seção da API do Windows documentação.

## <a name="criticalsectioncs_"></a><a name="cs"></a>CriticalSection:: cs_

Declara um membro de dados de seção crítica.

```cpp
CRITICAL_SECTION cs_;
```

### <a name="remarks"></a>Comentários

Este membro de dados está protegido.

## <a name="criticalsectionisvalid"></a><a name="isvalid"></a>CriticalSection:: IsValid

Indica se a seção crítica atual é válida.

```cpp
bool IsValid() const;
```

### <a name="return-value"></a>Valor retornado

Por padrão, sempre retorna **`true`** .

## <a name="criticalsectionlock"></a><a name="lock"></a>CriticalSection:: Lock

Aguarda a propriedade do objeto de seção crítica especificado. A função retorna quando o thread de chamada recebe a propriedade.

```cpp
SyncLock Lock();

   static SyncLock Lock(
   _In_ CRITICAL_SECTION* cs
);
```

### <a name="parameters"></a>parâmetros

*CS*<br/>
Um objeto de seção crítica especificado pelo usuário.

### <a name="return-value"></a>Valor retornado

Um objeto de bloqueio que pode ser usado para desbloquear a seção crítica atual.

### <a name="remarks"></a>Comentários

A primeira `Lock` função afeta o objeto de seção crítica atual. A segunda `Lock` função afeta uma seção crítica especificada pelo usuário.

## <a name="criticalsectiontrylock"></a><a name="trylock"></a>CriticalSection:: TryLock

Tenta inserir uma seção crítica sem bloqueio. Se a chamada for bem-sucedida, o thread de chamada assumirá a propriedade da seção crítica.

```cpp
SyncLock TryLock();

static SyncLock TryLock(
   _In_ CRITICAL_SECTION* cs
);
```

### <a name="parameters"></a>parâmetros

*CS*<br/>
Um objeto de seção crítica especificado pelo usuário.

### <a name="return-value"></a>Valor retornado

Um valor diferente de zero se a seção crítica for inserida com êxito ou se o thread atual já possuir a seção crítica. Zero se outro thread já possuir a seção crítica.

### <a name="remarks"></a>Comentários

A primeira `TryLock` função afeta o objeto de seção crítica atual. A segunda `TryLock` função afeta uma seção crítica especificada pelo usuário.
