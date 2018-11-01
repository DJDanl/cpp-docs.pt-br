---
title: Namespace stdext
ms.date: 09/06/2017
f1_keywords:
- stdext
helpviewer_keywords:
- _DEFINE_DEPRECATED_HASH_CLASSES symbol
- stdext namespace
ms.assetid: 3e94fc89-0584-424f-bc09-081b73379545
ms.openlocfilehash: aeba486393e6b45481108f967f3de8eb73a0adea
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50468478"
---
# <a name="stdext-namespace"></a>Namespace stdext

Os membros de [ \<hash_map >](../standard-library/hash-map.md) e [ \<hash_set >](../standard-library/hash-set.md) arquivos de cabeçalho não são parte do padrão ISO C++. Portanto, esses tipos e membros foram movidos do `std` namespace para o namespace `stdext`, para permanecerem em conformidade com o padrão C++.

Ao compilar com [/Ze](../build/reference/za-ze-disable-language-extensions.md), que é o padrão, o compilador avisa sobre o uso de `std` para os membros a \<hash_map > e \<hash_set > arquivos de cabeçalho. Para desabilitar o aviso, use o pragma [warning](../preprocessor/warning.md).

Para que o compilador gere um erro para o uso de `std` para membros do \<hash_map > e \<hash_set > arquivos de cabeçalho com **/Ze**, adicione a seguinte diretiva antes de você `#include` quaisquer arquivos de cabeçalho da biblioteca padrão C++.

```cpp
#define _DEFINE_DEPRECATED_HASH_CLASSES 0
```

Ao compilar com **/Za**, o compilador gera um erro.

## <a name="see-also"></a>Consulte também

[Visão geral da biblioteca padrão C++](../standard-library/cpp-standard-library-overview.md)

