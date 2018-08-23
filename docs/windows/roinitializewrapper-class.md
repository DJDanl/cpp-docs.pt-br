---
title: Classe RoInitializeWrapper | Microsoft Docs
ms.custom: ''
ms.date: 05/20/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::RoInitializeWrapper
dev_langs:
- C++
ms.assetid: 4055fbe0-63a7-4c06-b5a0-414fda5640e5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 6f5c47ac34d8b159e75acf672ba57ca8c1ebac1e
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42592823"
---
# <a name="roinitializewrapper-class"></a>Classe RoInitializeWrapper

Inicializa o tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```cpp
class RoInitializeWrapper
```

## <a name="remarks"></a>Comentários

**RoInitializeWrapper** é uma conveniência que inicializa o tempo de execução do Windows e retorna um HRESULT que indica se a operação foi bem-sucedida. Porque chama o destruidor da classe `::Windows::Foundation::Uninitialize`, instâncias do **RoInitializeWrapper** deve ser declarado no escopo global ou de nível superior.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[Construtor RoInitializeWrapper::RoInitializeWrapper](../windows/roinitializewrapper-roinitializewrapper-constructor.md)|Inicializa uma nova instância dos **RoInitializeWrapper** classe.|
|[Destruidor RoInitializeWrapper::~RoInitializeWrapper](../windows/roinitializewrapper-tilde-roinitializewrapper-destructor.md)|Destrói a instância atual do **RoInitializeWrapper** classe.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador RoInitializeWrapper::HRESULT()](../windows/roinitializewrapper-hresult-parens-operator.md)|Recupera o HRESULT produzido pelo **RoInitializeWrapper** construtor.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`RoInitializeWrapper`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL::Wrappers](../windows/microsoft-wrl-wrappers-namespace.md)