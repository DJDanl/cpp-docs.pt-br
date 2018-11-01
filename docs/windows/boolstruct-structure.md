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
ms.openlocfilehash: d79ea93bf95040efe79e3e3c57ceb3397fd257de
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50643398"
---
# <a name="boolstruct-structure"></a>Estrutura BoolStruct

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
struct BoolStruct;
```

## <a name="remarks"></a>Comentários

O `BoolStruct` estrutura define se um `ComPtr` está gerenciando o tempo de vida do objeto de uma interface. `BoolStruct` é usado internamente pelo [BoolType()](../windows/comptr-operator-microsoft-wrl-details-booltype-operator.md) operador.

## <a name="members"></a>Membros

### <a name="public-data-members"></a>Membros de Dados Públicos

Nome                          | Descrição
----------------------------- | ------------------------------------------------------------------------------------------------------------------
[Boolstruct::](#member) | Especifica que um [ComPtr](../windows/comptr-class.md) é ou não, é gerenciar o tempo de vida do objeto de uma interface.

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

Especifica que um [ComPtr](../windows/comptr-class.md) é ou não, é gerenciar o tempo de vida do objeto de uma interface.
