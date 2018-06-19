---
title: Estrutura treat_as_floating_point | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- chrono/std::chrono::treat_as_floating_point
dev_langs:
- C++
ms.assetid: d0a2161c-bbb2-4924-8961-7568d5ad5434
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 96687959ce4fdd7b5431611a64b878cf05f855ab
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33853294"
---
# <a name="treatasfloatingpoint-structure"></a>Estrutura treat_as_floating_point

Especifica se `Rep` pode ser tratado como um tipo de ponto flutuante.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Rep>
struct treat_as_floating_point : is_floating_point<Rep>;
```

## <a name="remarks"></a>Comentários

`Rep` pode ser tratado como um tipo de ponto flutuante somente quando a especialização `treat_as_floating_point<Rep>` é derivada de [true_type](../standard-library/type-traits-typedefs.md#true_type). A classe de modelo pode ser especializada para um tipo definido pelo usuário.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<chrono >

**Namespace:** std::chrono

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
[\<chrono>](../standard-library/chrono.md)<br/>
