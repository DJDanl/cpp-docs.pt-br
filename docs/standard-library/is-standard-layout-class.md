---
title: Classe is_standard_layout | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- type_traits/std::is_standard_layout
dev_langs:
- C++
helpviewer_keywords:
- is_standard_layout class
- is_standard_layout
ms.assetid: 15ccf111-f537-45ef-b552-59152a7ba312
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d899d9c56ecc8b27b18498de225bbba6f0d110d2
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33852078"
---
# <a name="isstandardlayout-class"></a>Classe is_standard_layout

Testa se o tipo é um layout padrão.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
struct is_standard_layout;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|`Ty`|O tipo a ser consultado|

## <a name="remarks"></a>Comentários

Uma instância deste predicado de tipo será verdadeira se o tipo `Ty` for uma classe que tem um layout padrão dos objetos membro na memória; caso contrário, será falsa.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
