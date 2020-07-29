---
title: '&lt;cassert&gt;'
ms.date: 11/04/2016
f1_keywords:
- <cassert>
helpviewer_keywords:
- cassert header
ms.assetid: 6ead15a3-ac45-4075-be8e-350bca995c26
ms.openlocfilehash: b28f4554610d37b881494748f75499f46cd9e8d9
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87230227"
---
# <a name="ltcassertgt"></a>&lt;cassert&gt;

Inclui o cabeçalho da biblioteca padrão C \<assert.h> e adiciona os nomes associados ao `std` namespace. A inclusão desse cabeçalho garante que os nomes declarados usando vínculo externo no cabeçalho da biblioteca padrão C sejam declarados no `std` namespace.

> [!NOTE]
> \<assert.h>não define a **`static_assert`** macro.

## <a name="syntax"></a>Sintaxe

```cpp
#include <cassert>
```

## <a name="macros"></a>Macros

```cpp
#define assert(E)
```

### <a name="remarks"></a>Comentários

`assert(E)`é apenas constante, se NDEBUG é definido onde `assert` é definido pela última vez ou redefinido, ou *E* convertido em bool é avaliado como **`true`** .

## <a name="see-also"></a>Confira também

[Macro Assert, _assert _wassert](../c-runtime-library/reference/assert-macro-assert-wassert.md)\
[Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[Visão geral da biblioteca padrão do C++](../standard-library/cpp-standard-library-overview.md)\
[Segurança de thread na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
