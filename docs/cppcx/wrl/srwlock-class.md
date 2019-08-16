---
title: Classe SRWLock
ms.date: 09/25/2018
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::SRWLock
- corewrappers/Microsoft::WRL::Wrappers::SRWLock::LockExclusive
- corewrappers/Microsoft::WRL::Wrappers::SRWLock::LockShared
- corewrappers/Microsoft::WRL::Wrappers::SRWLock::SRWLock
- corewrappers/Microsoft::WRL::Wrappers::SRWLock::SRWLock_
- corewrappers/Microsoft::WRL::Wrappers::SRWLock::~SRWLock
- corewrappers/Microsoft::WRL::Wrappers::SRWLock::TryLockExclusive
- corewrappers/Microsoft::WRL::Wrappers::SRWLock::TryLockShared
helpviewer_keywords:
- Microsoft::WRL::Wrappers::SRWLock class
- Microsoft::WRL::Wrappers::SRWLock::LockExclusive method
- Microsoft::WRL::Wrappers::SRWLock::LockShared method
- Microsoft::WRL::Wrappers::SRWLock::SRWLock, constructor
- Microsoft::WRL::Wrappers::SRWLock::SRWLock_ data member
- Microsoft::WRL::Wrappers::SRWLock::~SRWLock, destructor
- Microsoft::WRL::Wrappers::SRWLock::TryLockExclusive method
- Microsoft::WRL::Wrappers::SRWLock::TryLockShared method
ms.assetid: 4fa250e3-5f29-4b06-ac24-61b6c04ade93
ms.openlocfilehash: 079f1abe652d8c1610a084f5e1158cc5798d61c4
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69498291"
---
# <a name="srwlock-class"></a>Classe SRWLock

Representa um bloqueio de leitor/gravador reduzido.

## <a name="syntax"></a>Sintaxe

```cpp
class SRWLock;
```

## <a name="remarks"></a>Comentários

Um bloqueio de leitor/gravador reduzido é usado para sincronizar o acesso entre threads para um objeto ou recurso. Para obter mais informações, consulte [funções de sincronização](/windows/win32/Sync/synchronization-functions).

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

Nome                | Descrição
------------------- | -------------------------------------------------------------------
`SyncLockExclusive` | Sinônimo de um `SRWLock` objeto que é adquirido em modo exclusivo.
`SyncLockShared`    | Sinônimo de um `SRWLock` objeto que é adquirido no modo compartilhado.

### <a name="public-constructors"></a>Construtores públicos

Nome                                     | Descrição
---------------------------------------- | --------------------------------------------------
[SRWLock::SRWLock](#srwlock-constructor) | Inicializa uma nova instância da classe `SRWLock`.
[SRWLock:: ~ SRWLock](#tilde-srwlock)      | Desinicializa uma instância da `SRWLock` classe.

### <a name="public-methods"></a>Métodos públicos

Nome                                           | Descrição
---------------------------------------------- | -------------------------------------------------------------------------------------------------------
[SRWLock::LockExclusive](#lockexclusive)       | Adquire um `SRWLock` objeto em modo exclusivo.
[SRWLock::LockShared](#lockshared)             | Adquire um `SRWLock` objeto no modo compartilhado.
[SRWLock::TryLockExclusive](#trylockexclusive) | Tenta adquirir um `SRWLock` objeto em modo exclusivo para o objeto atual ou especificado `SRWLock` .
[SRWLock::TryLockShared](#trylockshared)       | Tenta adquirir um `SRWLock` objeto no modo compartilhado para o objeto atual ou especificado `SRWLock` .

### <a name="protected-data-member"></a>Membro de dados protegidos

Nome                                      | Descrição
----------------------------------------- | -----------------------------------------------------------------------
[SRWLock::SRWLock_](#srwlock-data-member) | Contém a variável de bloqueio subjacente para o `SRWLock` objeto atual.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`SRWLock`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers

## <a name="tilde-srwlock"></a>SRWLock:: ~ SRWLock

Desinicializa uma instância da `SRWLock` classe.

```cpp
~SRWLock();
```

## <a name="lockexclusive"></a>SRWLock::LockExclusive

Adquire um `SRWLock` objeto em modo exclusivo.

```cpp
SyncLockExclusive LockExclusive();

static SyncLockExclusive LockExclusive(
   _In_ SRWLOCK* lock
);
```

### <a name="parameters"></a>Parâmetros

*lock*<br/>
Ponteiro para um `SRWLock` objeto.

### <a name="return-value"></a>Valor de retorno

Um `SRWLock` objeto em modo exclusivo.

## <a name="lockshared"></a>SRWLock::LockShared

Adquire um `SRWLock` objeto no modo compartilhado.

```cpp
SyncLockShared LockShared();

static SyncLockShared LockShared(
   _In_ SRWLOCK* lock
);
```

### <a name="parameters"></a>Parâmetros

*lock*<br/>
Ponteiro para um `SRWLock` objeto.

### <a name="return-value"></a>Valor de retorno

Um `SRWLock` objeto no modo compartilhado.

## <a name="srwlock-constructor"></a>SRWLock::SRWLock

Inicializa uma nova instância da classe `SRWLock`.

```cpp
SRWLock();
```

## <a name="srwlock-data-member"></a>SRWLock::SRWLock_

Contém a variável de bloqueio subjacente para o `SRWLock` objeto atual.

```cpp
SRWLOCK SRWLock_;
```

## <a name="trylockexclusive"></a>SRWLock::TryLockExclusive

Tenta adquirir um `SRWLock` objeto em modo exclusivo para o objeto atual ou especificado `SRWLock` . Se a chamada for bem-sucedida, o thread de chamada assumirá a propriedade do bloqueio.

```cpp
SyncLockExclusive TryLockExclusive();

static SyncLockExclusive TryLockExclusive(
   _In_ SRWLOCK* lock
);
```

### <a name="parameters"></a>Parâmetros

*lock*<br/>
Ponteiro para um `SRWLock` objeto.

### <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, `SRWLock` um objeto em modo exclusivo e o thread de chamada assumirão a propriedade do bloqueio. Caso contrário, `SRWLock` um objeto cujo estado é inválido.

## <a name="trylockshared"></a>SRWLock::TryLockShared

Tenta adquirir um `SRWLock` objeto no modo compartilhado para o objeto atual ou especificado `SRWLock` .

```cpp
WRL_NOTHROW SyncLockShared TryLockShared();
WRL_NOTHROW static SyncLockShared TryLockShared(
   _In_ SRWLOCK* lock
);
```

### <a name="parameters"></a>Parâmetros

*lock*<br/>
Ponteiro para um `SRWLock` objeto.

### <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, `SRWLock` um objeto no modo compartilhado e o thread de chamada assumirão a propriedade do bloqueio. Caso contrário, `SRWLock` um objeto cujo estado é inválido.
