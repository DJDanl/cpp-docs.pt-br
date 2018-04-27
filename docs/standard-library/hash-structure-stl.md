---
title: Estrutura hash (Biblioteca Padrão C++)| Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- thread/std::hash
dev_langs:
- C++
ms.assetid: 4a8bf5bc-4334-4070-936b-98585f8a073b
caps.latest.revision: 13
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 2e9898ce4415420966c4f3377865bda6346cdf67
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="hash-structure-c-standard-library"></a>Estrutura hash (Biblioteca Padrão C++)

Define uma função membro que retorna um valor determinado de forma exclusiva por `Val`. A função membro define uma função de [hash](../standard-library/hash-class.md) adequada para mapear valores do tipo `thread::id` para uma distribuição de valores de índice.

## <a name="syntax"></a>Sintaxe

```cpp
template <>
struct hash<thread::id> :
    public unary_function<thread::id, size_t>
{
    size_t operator()(thread::id Val) const;


};
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<thread >

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
[\<thread>](../standard-library/thread.md)<br/>
[Struct unary_function](../standard-library/unary-function-struct.md)<br/>
