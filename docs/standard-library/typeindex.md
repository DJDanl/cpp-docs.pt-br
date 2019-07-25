---
title: '&lt;typeindex&gt;'
ms.date: 11/04/2016
f1_keywords:
- <typeindex>
ms.assetid: a9551137-f74b-4f02-af64-ff00214cea1f
ms.openlocfilehash: 237356a0862ec3fc591264b482b23e62ef2c51cb
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68455056"
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

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)
