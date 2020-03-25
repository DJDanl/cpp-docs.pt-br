---
title: Estrutura InterfaceListHelper
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::InterfaceListHelper
helpviewer_keywords:
- InterfaceListHelper structure
ms.assetid: 4297e419-c96b-45df-8a00-7568062125ba
ms.openlocfilehash: 1a7b4c19bbcdd4161e9078274f18f96a48f9e7d7
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213844"
---
# <a name="interfacelisthelper-structure"></a>Estrutura InterfaceListHelper

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template <
    typename T0,
    typename T1 = Nil,
    typename T2 = Nil,
    typename T3 = Nil,
    typename T4 = Nil,
    typename T5 = Nil,
    typename T6 = Nil,
    typename T7 = Nil,
    typename T8 = Nil,
    typename T9 = Nil
>
struct InterfaceListHelper;

template <typename T0>
struct InterfaceListHelper<T0, Nil, Nil, Nil, Nil, Nil, Nil, Nil, Nil>;
```

### <a name="parameters"></a>parâmetros

*T0*<br/>
Parâmetro de modelo 0, que é necessário.

*T1*<br/>
Parâmetro de modelo 1, que por padrão não é especificado.

*T2*<br/>
Parâmetro de modelo 2, que por padrão não é especificado. O terceiro parâmetro de modelo.

*T3*<br/>
Parâmetro de modelo 3, que por padrão não é especificado.

*T4*<br/>
Parâmetro de modelo 4, que por padrão não é especificado.

*T5*<br/>
Parâmetro de modelo 5, que por padrão não é especificado.

*T6*<br/>
Parâmetro de modelo 6, que por padrão não é especificado.

*T7*<br/>
Parâmetro de modelo 7, que por padrão não é especificado.

*T8*<br/>
Parâmetro de modelo 8, que por padrão não é especificado.

*T9*<br/>
Parâmetro de modelo 9, que por padrão não é especificado.

## <a name="remarks"></a>Comentários

Cria um tipo de `InterfaceList` recursivamente aplicando os argumentos de parâmetro de modelo especificados.

O modelo **InterfaceListHelper** usa o parâmetro de modelo *T0* para definir o primeiro membro de dados em uma estrutura de `InterfaceList` e, em seguida, aplica recursivamente o modelo **InterfaceListHelper** a quaisquer parâmetros de modelo restantes. **InterfaceListHelper** para quando não há nenhum parâmetro de modelo restante.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs Públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|`TypeT`|Um sinônimo para o tipo de interface de interface.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`InterfaceListHelper`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft:: WRL::D etalhes

## <a name="see-also"></a>Confira também

[Namespace Microsoft::WRL::Details](microsoft-wrl-details-namespace.md)
