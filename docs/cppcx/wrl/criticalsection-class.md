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
ms.openlocfilehash: 5deb89e795d1886ca316886ae1ea260ce1f36fd1
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372595"
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
[''''''''''''''''''''](#criticalsection)        | Inicializa um objeto de sincronização que é semelhante a um objeto mutex, mas pode ser usado apenas pelos segmentos de um único processo.
['''''''''''''''''''''''](#tilde-criticalsection) | Desinicializa e destrói `CriticalSection` o objeto atual.

### <a name="public-methods"></a>Métodos públicos

Nome                                 | Descrição
------------------------------------ | ---------------------------------------------------------------------------------------------------------------------------------------------
[''''''''''''''''''''](#isvalid) | Indica se a seção crítica atual é válida.
[Seção crítica::bloqueio](#lock)       | Aguarda a propriedade do objeto de seção crítica especificado. A função retorna quando o segmento de chamada é concedido.
[Seção crítica::Trylock](#trylock) | Tentativas de entrar em uma seção crítica sem bloquear. Se a chamada for bem sucedida, o segmento de chamada toma posse da seção crítica.

### <a name="protected-data-members"></a>Membros de Dados Protegidos

Nome                        | Descrição
--------------------------- | ----------------------------------------
[Seção crítica::cs_](#cs) | Declara um membro de dados de seção crítica.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CriticalSection`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers.h

**Espaço de nome:** Microsoft::WRL::Wrappers

## <a name="criticalsectioncriticalsection"></a><a name="tilde-criticalsection"></a>'''''''''''''''''''''''

Desinicializa e destrói `CriticalSection` o objeto atual.

```cpp
WRL_NOTHROW ~CriticalSection();
```

## <a name="criticalsectioncriticalsection"></a><a name="criticalsection"></a>''''''''''''''''''''

Inicializa um objeto de sincronização que é semelhante a um objeto mutex, mas pode ser usado apenas pelos segmentos de um único processo.

```cpp
explicit CriticalSection(
   ULONG spincount = 0
);
```

### <a name="parameters"></a>Parâmetros

*contagem de spincount*<br/>
A contagem de giros para o objeto da seção crítica. O valor padrão é 0.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre seções `InitializeCriticalSectionAndSpinCount` críticas `Synchronization` e contagem de spincounts, consulte a função na seção de documenação da API do Windows.

## <a name="criticalsectioncs_"></a><a name="cs"></a>Seção crítica::cs_

Declara um membro de dados de seção crítica.

```cpp
CRITICAL_SECTION cs_;
```

### <a name="remarks"></a>Comentários

Este membro de dados está protegido.

## <a name="criticalsectionisvalid"></a><a name="isvalid"></a>''''''''''''''''''''

Indica se a seção crítica atual é válida.

```cpp
bool IsValid() const;
```

### <a name="return-value"></a>Valor retornado

Por padrão, sempre retorna **verdadeiro.**

## <a name="criticalsectionlock"></a><a name="lock"></a>Seção crítica::bloqueio

Aguarda a propriedade do objeto de seção crítica especificado. A função retorna quando o segmento de chamada é concedido.

```cpp
SyncLock Lock();

   static SyncLock Lock(
   _In_ CRITICAL_SECTION* cs
);
```

### <a name="parameters"></a>Parâmetros

*Cs*<br/>
Um objeto de seção crítica especificado pelo usuário.

### <a name="return-value"></a>Valor retornado

Um objeto de bloqueio que pode ser usado para desbloquear a seção crítica atual.

### <a name="remarks"></a>Comentários

A `Lock` primeira função afeta o objeto da seção crítica atual. A `Lock` segunda função afeta uma seção crítica especificada pelo usuário.

## <a name="criticalsectiontrylock"></a><a name="trylock"></a>Seção crítica::Trylock

Tentativas de entrar em uma seção crítica sem bloquear. Se a chamada for bem sucedida, o segmento de chamada toma posse da seção crítica.

```cpp
SyncLock TryLock();

static SyncLock TryLock(
   _In_ CRITICAL_SECTION* cs
);
```

### <a name="parameters"></a>Parâmetros

*Cs*<br/>
Um objeto de seção crítica especificado pelo usuário.

### <a name="return-value"></a>Valor retornado

Um valor não zero se a seção crítica for inserida com sucesso ou o segmento atual já possuir a seção crítica. Zero se outro segmento já possuir a seção crítica.

### <a name="remarks"></a>Comentários

A `TryLock` primeira função afeta o objeto da seção crítica atual. A `TryLock` segunda função afeta uma seção crítica especificada pelo usuário.
