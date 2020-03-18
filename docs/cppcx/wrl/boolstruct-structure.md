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
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79418331"
---
# <a name="boolstruct-structure"></a>Estrutura BoolStruct

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
struct BoolStruct;
```

## <a name="remarks"></a>Comentários

A estrutura de `BoolStruct` define se um `ComPtr` está gerenciando o tempo de vida do objeto de uma interface. `BoolStruct` é usado internamente pelo operador [booltype ()](comptr-class.md#operator-microsoft-wrl-details-booltype) .

## <a name="members"></a>Membros

### <a name="public-data-members"></a>Membros de Dados Públicos

Nome                          | DESCRIÇÃO
----------------------------- | ------------------------------------------------------------------------------------------------------------------
[BoolStruct:: member](#member) | Especifica que um [ComPtr](comptr-class.md) é ou não, gerenciando o tempo de vida do objeto de uma interface.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`BoolStruct`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Internal. h

**Namespace:** Microsoft:: WRL::D etalhes

## <a name="member"></a>BoolStruct:: member

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
int Member;
```

### <a name="remarks"></a>Comentários

Especifica que um [ComPtr](comptr-class.md) é ou não, gerenciando o tempo de vida do objeto de uma interface.
