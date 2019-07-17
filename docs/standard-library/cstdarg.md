---
title: '&lt;cstdarg&gt;'
ms.date: 11/04/2016
f1_keywords:
- <cstdarg>
helpviewer_keywords:
- cstdarg header
ms.assetid: 639b4ef7-8408-4640-9343-41631f0ab663
ms.openlocfilehash: f8d2d3b886cfa46905e8f17f1e13b51881b80191
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68244479"
---
# <a name="ltcstdarggt"></a>&lt;cstdarg&gt;

Inclui o cabeçalho da biblioteca C padrão \<stdarg. h > e adiciona os nomes associados ao `std` namespace. Inclusão desse cabeçalho garante que os nomes declarados usando vinculação externa no cabeçalho da biblioteca C padrão sejam declarados no `std` namespace.

## <a name="syntax"></a>Sintaxe

```cpp
#include <cstdarg>
```

## <a name="namespace-and-macros"></a>Namespace e Macros

```cpp
namespace std {
    using va_list = see below;
}

#define va_arg(V, P)
#define va_copy(VDST, VSRC)
#define va_end(V)
#define va_start(V, P)
```

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
[Visão geral da biblioteca padrão C++](../standard-library/cpp-standard-library-overview.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
