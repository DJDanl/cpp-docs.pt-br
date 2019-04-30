---
title: Namespace stdext
ms.date: 09/06/2017
f1_keywords:
- stdext
helpviewer_keywords:
- _DEFINE_DEPRECATED_HASH_CLASSES symbol
- stdext namespace
ms.assetid: 3e94fc89-0584-424f-bc09-081b73379545
ms.openlocfilehash: d40f3f7a99db72784cc9a32a9c37064228597d34
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62412417"
---
# <a name="stdext-namespace"></a>Namespace stdext

Os membros de [ \<hash_map >](../standard-library/hash-map.md) e [ \<hash_set >](../standard-library/hash-set.md) arquivos de cabeçalho não são parte da ISO C++ padrão. Portanto, esses tipos e membros foram movidos do `std` namespace para o namespace `stdext`, para permanecerem em conformidade com o padrão C++.

Ao compilar com [/Ze](../build/reference/za-ze-disable-language-extensions.md), que é o padrão, o compilador avisa sobre o uso de `std` para os membros a \<hash_map > e \<hash_set > arquivos de cabeçalho. Para desabilitar o aviso, use o pragma [warning](../preprocessor/warning.md).

Para que o compilador gere um erro para o uso de `std` para membros do \<hash_map > e \<hash_set > arquivos de cabeçalho com **/Ze**, adicione a seguinte diretiva antes de você `#include` qualquer C++ arquivos de cabeçalho da biblioteca padrão.

```cpp
#define _DEFINE_DEPRECATED_HASH_CLASSES 0
```

Ao compilar com **/Za**, o compilador gera um erro.

## <a name="see-also"></a>Consulte também

[Visão geral da biblioteca padrão C++](../standard-library/cpp-standard-library-overview.md)
