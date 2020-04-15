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
ms.openlocfilehash: 4f2a5acf6edb824cff2121c1b6444181b5cfcf98
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371847"
---
# <a name="boolstruct-structure"></a>Estrutura BoolStruct

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
struct BoolStruct;
```

## <a name="remarks"></a>Comentários

A `BoolStruct` estrutura define `ComPtr` se a está gerenciando a vida útil do objeto de uma interface. `BoolStruct`é usado internamente pelo operador [BoolType().](comptr-class.md#operator-microsoft-wrl-details-booltype)

## <a name="members"></a>Membros

### <a name="public-data-members"></a>Membros de Dados Públicos

Nome                          | Descrição
----------------------------- | ------------------------------------------------------------------------------------------------------------------
[BoolStruct::Membro](#member) | Especifica que um [ComPtr](comptr-class.md) está ou não gerenciando a vida útil do objeto de uma interface.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`BoolStruct`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** internal.h

**Espaço de nome:** Microsoft::WRL::Details

## <a name="boolstructmember"></a><a name="member"></a>BoolStruct::Membro

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
int Member;
```

### <a name="remarks"></a>Comentários

Especifica que um [ComPtr](comptr-class.md) está ou não gerenciando a vida útil do objeto de uma interface.
