---
title: Classe RoInitializeWrapper | Microsoft Docs
ms.custom: ''
ms.date: 10/03/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::RoInitializeWrapper
- corewrappers/Microsoft::WRL::Wrappers::RoInitializeWrapper::HRESULT
- corewrappers/Microsoft::WRL::Wrappers::RoInitializeWrapper::RoInitializeWrapper
- corewrappers/Microsoft::WRL::Wrappers::RoInitializeWrapper::~RoInitializeWrapper
dev_langs:
- C++
helpviewer_keywords:
- Microsoft::WRL::Wrappers::RoInitializeWrapper class
- Microsoft::WRL::Wrappers::RoInitializeWrapper::operator HRESULT operator
- Microsoft::WRL::Wrappers::RoInitializeWrapper::RoInitializeWrapper, constructor
- Microsoft::WRL::Wrappers::RoInitializeWrapper::~RoInitializeWrapper, destructor
ms.assetid: 4055fbe0-63a7-4c06-b5a0-414fda5640e5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 8a0eeb4b7da53b5722733ba0b0116cf03dab4a29
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50053429"
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

### <a name="public-constructors"></a>Construtores Públicos

Nome                                                                    | Descrição
----------------------------------------------------------------------- | -----------------------------------------------------------------
[Roinitializewrapper:: Roinitializewrapper](#roinitializewrapper)        | Inicializa uma nova instância da classe `RoInitializeWrapper`.
[RoInitializeWrapper:: ~ RoInitializeWrapper](#tilde-roinitializewrapper) | Destrói a instância atual do `RoInitializeWrapper` classe.

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

## <a name="roinitializewrapper"></a>Roinitializewrapper:: Roinitializewrapper

Inicializa uma nova instância da classe `RoInitializeWrapper`.

```cpp
RoInitializeWrapper(RO_INIT_TYPE flags)
```

### <a name="parameters"></a>Parâmetros

*flags*<br/>
Uma das enumerações RO_INIT_TYPE, que especifica o suporte fornecido pelo tempo de execução do Windows.

### <a name="remarks"></a>Comentários

O `RoInitializeWrapper` classe invoca `Windows::Foundation::Initialize(flags)`.

## <a name="tilde-roinitializewrapper"></a>RoInitializeWrapper:: ~ RoInitializeWrapper

Encerra o tempo de execução do Windows.

```cpp
~RoInitializeWrapper()
```

### <a name="remarks"></a>Comentários

O `RoInitializeWrapper` classe invoca `Windows::Foundation::Uninitialize()`.
