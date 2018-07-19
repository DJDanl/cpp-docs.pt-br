---
title: Classe make_unsigned | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- type_traits/std::make_unsigned
dev_langs:
- C++
helpviewer_keywords:
- make_unsigned class
- make_unsigned
ms.assetid: 7a6a3c4f-1a4c-47e8-9ee2-ac1f7b669353
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f379500f9455ed9ad9a581966e0f8ed7bfed13f7
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38953908"
---
# <a name="makeunsigned-class"></a>Classe make_unsigned

Cria o tipo ou o menor tipo sem sinal maior ou igual em tamanho ao tipo.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
struct make_unsigned;

template <class T>
using make_unsigned_t = typename make_unsigned<T>::type;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*T*|O tipo a ser modificado.|

## <a name="remarks"></a>Comentários

Uma instância do modificador de tipo mantém um tipo modificado que é *T* se `is_unsigned<T>` se aplica. Caso contrário, será o menor tipo com sinal `ST` para `sizeof (T) <= sizeof (ST)`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
