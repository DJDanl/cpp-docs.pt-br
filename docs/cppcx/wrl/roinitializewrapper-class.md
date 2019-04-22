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
ms.openlocfilehash: b43d5bb2f553d298584ab2ae497c22637d3beb0d
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58783721"
---
# <a name="roinitializewrapper-class"></a>Classe RoInitializeWrapper

Inicializa o tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```cpp
class RoInitializeWrapper;
```

## <a name="remarks"></a>Comentários

`RoInitializeWrapper` é uma conveniência que inicializa o tempo de execução do Windows e retorna um HRESULT que indica se a operação foi bem-sucedida. Porque chama o destruidor da classe `::Windows::Foundation::Uninitialize`, instâncias de `RoInitializeWrapper` deve ser declarado no escopo global ou de nível superior.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

Nome                                                                    | Descrição
----------------------------------------------------------------------- | -----------------------------------------------------------------
[RoInitializeWrapper::RoInitializeWrapper](#roinitializewrapper)        | Inicializa uma nova instância da classe `RoInitializeWrapper`.
[RoInitializeWrapper::~RoInitializeWrapper](#tilde-roinitializewrapper) | Destrói a instância atual do `RoInitializeWrapper` classe.

### <a name="public-operators"></a>Operadores públicos

Nome                                       | Descrição
------------------------------------------ | ------------------------------------------------------------------------
[RoInitializeWrapper::HRESULT()](#hresult) | Recupera o HRESULT produzido pelo `RoInitializeWrapper` construtor.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`RoInitializeWrapper`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers

## <a name="hresult"></a>RoInitializeWrapper::HRESULT()

Recupera o valor HRESULT produzido pela última `RoInitializeWrapper` construtor.

```cpp
operator HRESULT()
```

## <a name="roinitializewrapper"></a>RoInitializeWrapper::RoInitializeWrapper

Inicializa uma nova instância da classe `RoInitializeWrapper`.

```cpp
RoInitializeWrapper(RO_INIT_TYPE flags)
```

### <a name="parameters"></a>Parâmetros

*flags*<br/>
Uma das enumerações RO_INIT_TYPE, que especifica o suporte fornecido pelo tempo de execução do Windows.

### <a name="remarks"></a>Comentários

O `RoInitializeWrapper` classe invoca `Windows::Foundation::Initialize(flags)`.

## <a name="tilde-roinitializewrapper"></a>RoInitializeWrapper::~RoInitializeWrapper

Encerra o tempo de execução do Windows.

```cpp
~RoInitializeWrapper()
```

### <a name="remarks"></a>Comentários

O `RoInitializeWrapper` classe invoca `Windows::Foundation::Uninitialize()`.
