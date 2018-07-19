---
title: Classe is_trivially_destructible | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp
- devlang-cpp
ms.topic: reference
f1_keywords:
- type_traits/std::is_trivially_destructible
dev_langs:
- C++
helpviewer_keywords:
- is_trivially_destructible
ms.assetid: 3f7a787d-2448-40c5-ac51-a228318e02ce
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a0e2fb16ad96ba102295981b9f9d56fda810ddff
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38961052"
---
# <a name="istriviallydestructible-class"></a>Classe is_trivially_destructible

Testa se o tipo é comumente destrutível.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
struct is_trivially_destructible;
```

### <a name="parameters"></a>Parâmetros

*T* o tipo de consulta.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo *T* é um tipo destrutível e o destruidor é conhecido para o compilador para usar operações não triviais. Caso contrário, será falsa.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
