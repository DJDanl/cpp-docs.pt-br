---
title: Estrutura IsBaseOfStrict | Microsoft Docs
ms.custom: ''
ms.date: 10/03/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- internal/Microsoft::WRL::Details::IsBaseOfStrict
- internal/Microsoft::WRL::Details::IsBaseOfStrict::value
dev_langs:
- C++
helpviewer_keywords:
- Microsoft::WRL::Details::IsBaseOfStrict structure
- Microsoft::WRL::Details::IsBaseOfStrict::value constant
ms.assetid: 6fed7366-c8d4-4991-b4fb-43ed93f8e1bf
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 90ceaf20a5d601fc2904b7ce8610b4a3906e30ac
ms.sourcegitcommit: 8480f16893f09911f08a58caf684405404f7ac8e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/12/2018
ms.locfileid: "49161197"
---
# <a name="isbaseofstrict-structure"></a>Estrutura IsBaseOfStrict

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename Base, typename Derived>
struct IsBaseOfStrict;

template <typename Base>
struct IsBaseOfStrict<Base, Base>;
```

### <a name="parameters"></a>Parâmetros

*Base de dados de*<br/>
O tipo base.

*Derivado*<br/>
O tipo derivado.

## <a name="remarks"></a>Comentários

Testa se um tipo é a base de outro.

O primeiro modelo testa se um tipo é derivado de um tipo base, que pode produzir **verdadeira** ou **falso**. O segundo modelo testa se um tipo é derivado de si mesma, que sempre produz **falsos**.

## <a name="members"></a>Membros

### <a name="public-constants"></a>Constantes públicas

Nome                            | Descrição
------------------------------- | --------------------------------------------------
[Isbaseofstrict:: Value](#value) | Indica se um tipo é a base de outro.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IsBaseOfStrict`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** internal.h

**Namespace:** Microsoft::WRL::Details

## <a name="value"></a>Isbaseofstrict:: Value

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
static const bool value = __is_base_of(Base, Derived);
```

### <a name="remarks"></a>Comentários

Indica se um tipo é a base de outro.

`value` está **verdadeira** se tipo `Base` é uma classe base do tipo `Derived`, caso contrário, será **false**.
