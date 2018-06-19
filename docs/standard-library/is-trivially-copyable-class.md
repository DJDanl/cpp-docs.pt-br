---
title: Classe is_trivially_copyable | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp
- devlang-cpp
ms.topic: reference
f1_keywords:
- type_traits/std::is_trivially_copyable
dev_langs:
- C++
helpviewer_keywords:
- is_trivially_copyable
ms.assetid: 89a53bf8-036c-4108-91e1-fe34adbde8b3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 177ba6e688f6d7ed2b4c76eb0ede95cc288b1d5d
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33857526"
---
# <a name="istriviallycopyable-class"></a>Classe is_trivially_copyable

Testa se o tipo pode ser copiado de forma trivial.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
struct is_trivially_copyable;
```

### <a name="parameters"></a>Parâmetros

`T` O tipo de consulta.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo `T` puder ser copiado de forma trivial; caso contrário, será falsa. Tipos que podem ser copiados de forma trivial não têm operações de cópia não triviais, operações de movimentação ou destruidores. De modo geral, uma operação de cópia será considerada trivial se puder ser implementada como uma cópia bit a bit. Tipos internos e matrizes de tipos que podem ser copiados de forma trivial.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
