---
title: Classe Mutex
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::Mutex
- corewrappers/Microsoft::WRL::Wrappers::Mutex::Lock
- corewrappers/Microsoft::WRL::Wrappers::Mutex::Mutex
- corewrappers/Microsoft::WRL::Wrappers::Mutex::operator=
helpviewer_keywords:
- Microsoft::WRL::Wrappers::Mutex class
- Microsoft::WRL::Wrappers::Mutex::Lock method
- Microsoft::WRL::Wrappers::Mutex::Mutex, constructor
- Microsoft::WRL::Wrappers::Mutex::operator= operator
ms.assetid: 682a0963-721c-46a2-8871-000e9997505b
ms.openlocfilehash: 36466bd00c5b100f20ee87173e68fdef4131ec23
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371232"
---
# <a name="mutex-class"></a>Classe Mutex

Representa um objeto de sincronização que controla exclusivamente um recurso compartilhado.

## <a name="syntax"></a>Sintaxe

```cpp
class Mutex : public HandleT<HandleTraits::MutexTraits>;
```

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

Nome       | Descrição
---------- | ------------------------------------------------------
`SyncLock` | Um sinônimo para uma classe que suporta bloqueios síncronos.

### <a name="public-constructor"></a>Construtor Público

Nome                   | Descrição
---------------------- | ------------------------------------------------
[Mutex::Mutex](#mutex) | Inicia uma nova instância da classe `Mutex`.

### <a name="public-members"></a>Membros públicos

Nome                 | Descrição
-------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------
[Mutex::Bloqueio](#lock) | Aguarde até que o `Mutex` objeto atual, ou o objeto associado à alça especificada, libere o mutex ou o intervalo de tempo de saída especificado tenha transcorrido.

### <a name="public-operator"></a>Operador Público

Nome                                 | Descrição
------------------------------------ | ---------------------------------------------------------------------------
[Mutex::operador=](#operator-assign) | Atribui (move) o `Mutex` objeto especificado `Mutex` ao objeto atual.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`Mutex`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers.h

**Espaço de nome:** Microsoft::WRL::Wrappers

## <a name="mutexlock"></a><a name="lock"></a>Mutex::Bloqueio

Aguarde até que o `Mutex` objeto atual, ou o objeto associado à alça especificada, libere o mutex ou o intervalo de tempo de saída especificado tenha transcorrido.

```cpp
SyncLock Lock(
   DWORD milliseconds = INFINITE
);

static SyncLock Lock(
   HANDLE h,
   DWORD milliseconds = INFINITE
);
```

### <a name="parameters"></a>Parâmetros

*milliseconds*<br/>
O intervalo de tempo, em milissegundos. O valor padrão é INFINITE, que aguarda indefinidamente.

*H*<br/>
A alça `Mutex` de um objeto.

### <a name="return-value"></a>Valor retornado

## <a name="mutexmutex"></a><a name="mutex"></a>Mutex::Mutex

Inicia uma nova instância da classe `Mutex`.

```cpp
explicit Mutex(
   HANDLE h
);

Mutex(
   _Inout_ Mutex&& h
);
```

### <a name="parameters"></a>Parâmetros

*H*<br/>
Uma alça, ou uma referência de valor `Mutex` a uma alça, a um objeto.

### <a name="remarks"></a>Comentários

O primeiro construtor inicializa `Mutex` um objeto a partir da alça especificada. O segundo construtor inicializa `Mutex` um objeto da alça especificada e, em seguida, move a propriedade do mutex para o objeto atual. `Mutex`

## <a name="mutexoperator"></a><a name="operator-assign"></a>Mutex::operador=

Atribui (move) o `Mutex` objeto especificado `Mutex` ao objeto atual.

```cpp
Mutex& operator=(
   _Inout_ Mutex&& h
);
```

### <a name="parameters"></a>Parâmetros

*H*<br/>
Uma referência de valor `Mutex` a um objeto.

### <a name="return-value"></a>Valor retornado

Uma referência ao `Mutex` objeto atual.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte a seção **Mover Semantics** do Declarador de [Referência de Valor de Rvalue: &&](../../cpp/rvalue-reference-declarator-amp-amp.md).
