---
title: '&lt;cassert&gt;'
ms.date: 11/04/2016
f1_keywords:
- <cassert>
helpviewer_keywords:
- cassert header
ms.assetid: 6ead15a3-ac45-4075-be8e-350bca995c26
ms.openlocfilehash: 14dda03e835ec411013b2d827bd1ccaa77f8982e
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68245012"
---
# <a name="ltcassertgt"></a>&lt;cassert&gt;

Inclui o cabeçalho da biblioteca C padrão \<Assert > e adiciona os nomes associados ao `std` namespace. Inclusão desse cabeçalho garante que os nomes declarados usando vinculação externa no cabeçalho da biblioteca C padrão sejam declarados no `std` namespace.

> [!NOTE]
> \<Assert > não define o `static_assert` macro.

## <a name="syntax"></a>Sintaxe

```cpp
#include <cassert>
```

## <a name="macros"></a>Macros

```cpp
#define assert(E)
```

### <a name="remarks"></a>Comentários

`assert(E)` só é constante, se NDEBUG for definido em que `assert` está definido ou redefinido, pela última vez ou *eletrônico* convertido em bool é avaliada como **true**.

## <a name="see-also"></a>Consulte também

[assert Macro, _assert, _wassert](../c-runtime-library/reference/assert-macro-assert-wassert.md)<br/>
[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
[Visão geral da biblioteca padrão C++](../standard-library/cpp-standard-library-overview.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
