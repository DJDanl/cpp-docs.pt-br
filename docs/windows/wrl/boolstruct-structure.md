---
title: Estrutura BoolStruct
ms.date: 09/21/2018
ms.topic: reference
f1_keywords:
- internal/Microsoft::WRL::Details::BoolStruct
- internal/Microsoft::WRL::Details::BoolStruct::Member
helpviewer_keywords:
- Microsoft::WRL::Details::BoolStruct structure
- Microsoft::WRL::Details::BoolStruct::Member data member
ms.assetid: 666eae78-e81d-4fb7-a9e4-1ba617d6d4cd
ms.openlocfilehash: cdec425e317585abbd9730447e2c4fbb19b8250a
ms.sourcegitcommit: 360b55e89e5954f494e52b1cf989fbaceda06f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/16/2019
ms.locfileid: "54335492"
---
# <a name="boolstruct-structure"></a>Estrutura BoolStruct

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
struct BoolStruct;
```

## <a name="remarks"></a>Comentários

O `BoolStruct` estrutura define se um `ComPtr` está gerenciando o tempo de vida do objeto de uma interface. `BoolStruct` é usado internamente pelo [BoolType()](comptr-class.md#operator-microsoft-wrl-details-booltype) operador.

## <a name="members"></a>Membros

### <a name="public-data-members"></a>Membros de Dados Públicos

Nome                          | Descrição
----------------------------- | ------------------------------------------------------------------------------------------------------------------
[Boolstruct::](#member) | Especifica que um [ComPtr](comptr-class.md) é ou não, é gerenciar o tempo de vida do objeto de uma interface.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`BoolStruct`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** internal.h

**Namespace:** Microsoft::WRL::Details

## <a name="member"></a>Boolstruct::

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
int Member;
```

### <a name="remarks"></a>Comentários

Especifica que um [ComPtr](comptr-class.md) é ou não, é gerenciar o tempo de vida do objeto de uma interface.
