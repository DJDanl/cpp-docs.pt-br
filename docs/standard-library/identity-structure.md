---
title: Estrutura identity | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- utility/std::identity
dev_langs:
- C++
helpviewer_keywords:
- identity class
- identity structure
ms.assetid: 990756fd-7969-4b39-ad7e-0878e8dac8fd
caps.latest.revision: 15
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 991333f279053d19ec27fda86ea0bf769371fd90
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="identity-structure"></a>Estrutura identity

Um struct que fornece uma definição de tipo como o parâmetro do modelo.

## <a name="syntax"></a>Sintaxe

```cpp
struct identity {
   typedef Type type;
   Type operator()(const Type& left) const;
   };
```
### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|`left`|O valor a ser identificado.|

## <a name="remarks"></a>Comentários

A classe contém a definição de tipo público `type`, que é a mesma do parâmetro de modelo Type. Ela é usada em conjunto com a função de modelo [forward](../standard-library/utility-functions.md#forward) para garantir que o parâmetro da função tem o tipo desejado.

Para compatibilidade com o código anterior, a classe define também a função identity `operator()` que retorna o argumento `left`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<utility>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[\<utility>](../standard-library/utility.md)<br/>
