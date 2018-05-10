---
title: '&lt;typeindex&gt; | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- <typeindex>
dev_langs:
- C++
ms.assetid: a9551137-f74b-4f02-af64-ff00214cea1f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 189fb7cd3757a3f71a50badc682b7b4db611b4e0
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="lttypeindexgt"></a>&lt;typeindex&gt;

Inclua o cabeçalho padrão \<typeindex> para definir uma classe e a função que dê suporte a indexação dos objetos da classe [type_info](../cpp/type-info-class.md).

## <a name="syntax"></a>Sintaxe

```cpp
#include <typeindex>
```

## <a name="remarks"></a>Comentários

A [estrutura hash](../standard-library/hash-structure.md) define um `hash function` adequado para mapeamentos de valor do tipo [type_index](../standard-library/type-index-class.md) para uma distribuição de valores de índice.

A classe `type_index` encapsula um ponteiro para um objeto `type_info` a fim de auxiliar na indexação.

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)<br/>
