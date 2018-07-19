---
title: Classe make_signed | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- type_traits/std::make_signed
dev_langs:
- C++
helpviewer_keywords:
- make_signed class
- make_signed
ms.assetid: 686247c0-247c-496b-9b1b-ba9dcd633621
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7fe6eb3ffa83316071de2ba26cf80e6e6cbd5245
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38957341"
---
# <a name="makesigned-class"></a>Classe make_signed

Cria o tipo ou o menor tipo com sinal maior ou igual em tamanho ao tipo.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
struct make_signed;

template <class T>
using make_signed_t = typename make_signed<T>::type;
```

### <a name="parameters"></a>Parâmetros

*T* para modificar o tipo.

## <a name="remarks"></a>Comentários

Uma instância do modificador de tipo mantém um tipo modificado que é *T* se `is_signed<T>` se aplica. Caso contrário, será o menor tipo sem sinal `UT` para `sizeof (T) <= sizeof (UT)`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
