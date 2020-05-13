---
title: Classe RoInitializeWrapper
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::RoInitializeWrapper
- corewrappers/Microsoft::WRL::Wrappers::RoInitializeWrapper::HRESULT
- corewrappers/Microsoft::WRL::Wrappers::RoInitializeWrapper::RoInitializeWrapper
- corewrappers/Microsoft::WRL::Wrappers::RoInitializeWrapper::~RoInitializeWrapper
helpviewer_keywords:
- Microsoft::WRL::Wrappers::RoInitializeWrapper class
- Microsoft::WRL::Wrappers::RoInitializeWrapper::operator HRESULT operator
- Microsoft::WRL::Wrappers::RoInitializeWrapper::RoInitializeWrapper, constructor
- Microsoft::WRL::Wrappers::RoInitializeWrapper::~RoInitializeWrapper, destructor
ms.assetid: 4055fbe0-63a7-4c06-b5a0-414fda5640e5
ms.openlocfilehash: eba9162f17b98d13a9caf956b4f110b89dd81c37
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371245"
---
# <a name="roinitializewrapper-class"></a>Classe RoInitializeWrapper

Inicializa o Tempo de Execução do Windows.

## <a name="syntax"></a>Sintaxe

```cpp
class RoInitializeWrapper;
```

## <a name="remarks"></a>Comentários

`RoInitializeWrapper`é uma conveniência que inicializa o Tempo de Execução do Windows e retorna um HRESULT que indica se a operação foi bem sucedida. Como as chamadas `::Windows::Foundation::Uninitialize`de destruidor de `RoInitializeWrapper` classe devem ser declaradas em escopo global ou de alto nível.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

Nome                                                                    | Descrição
----------------------------------------------------------------------- | -----------------------------------------------------------------
[RoInitializeWrapper::RoInitializeWrapper](#roinitializewrapper)        | Inicia uma nova instância da classe `RoInitializeWrapper`.
[RoInitializeWrapper::~RoInitializeWrapper](#tilde-roinitializewrapper) | Destrói a instância atual `RoInitializeWrapper` da classe.

### <a name="public-operators"></a>Operadores públicos

Nome                                       | Descrição
------------------------------------------ | ------------------------------------------------------------------------
[RoInitializeWrapper::HRESULT()](#hresult) | Recupera o HRESULT produzido `RoInitializeWrapper` pelo construtor.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`RoInitializeWrapper`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers.h

**Espaço de nome:** Microsoft::WRL::Wrappers

## <a name="roinitializewrapperhresult"></a><a name="hresult"></a>RoInitializeWrapper::HRESULT()

Recupera o valor HRESULT produzido `RoInitializeWrapper` pelo último construtor.

```cpp
operator HRESULT()
```

## <a name="roinitializewrapperroinitializewrapper"></a><a name="roinitializewrapper"></a>RoInitializeWrapper::RoInitializeWrapper

Inicia uma nova instância da classe `RoInitializeWrapper`.

```cpp
RoInitializeWrapper(RO_INIT_TYPE flags)
```

### <a name="parameters"></a>Parâmetros

*Sinalizadores*<br/>
Uma das enumerações RO_INIT_TYPE, que especifica o suporte fornecido pelo Windows Runtime.

### <a name="remarks"></a>Comentários

A `RoInitializeWrapper` classe `Windows::Foundation::Initialize(flags)`invoca.

## <a name="roinitializewrapperroinitializewrapper"></a><a name="tilde-roinitializewrapper"></a>RoInitializeWrapper::~RoInitializeWrapper

Desinicializa o Tempo de Execução do Windows.

```cpp
~RoInitializeWrapper()
```

### <a name="remarks"></a>Comentários

A `RoInitializeWrapper` classe `Windows::Foundation::Uninitialize()`invoca.
