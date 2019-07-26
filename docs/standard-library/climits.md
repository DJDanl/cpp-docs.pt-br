---
title: '&lt;climits&gt;'
ms.date: 11/04/2016
f1_keywords:
- <climits>
helpviewer_keywords:
- climits header
ms.assetid: 7ca8a539-aa45-4ac3-86e8-74513be3f07e
ms.openlocfilehash: 6cff0975fb61e30bc96390f345cd67d7b1fbec41
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68459331"
---
# <a name="ltclimitsgt"></a>&lt;climits&gt;

Inclui o cabeçalho \<de biblioteca padrão C Limits. h > e adiciona os nomes associados `std` ao namespace. A inclusão desse cabeçalho garante que os nomes declarados usando vínculo externo no cabeçalho da biblioteca padrão C sejam `std` declarados no namespace.

## <a name="syntax"></a>Sintaxe

```cpp
#include <climits>
```

## <a name="macros"></a>Macros

```cpp
#define CHAR_BIT
#define SCHAR_MIN
#define SCHAR_MAX
#define UCHAR_MAX
#define CHAR_MIN
#define CHAR_MAX
#define MB_LEN_MAX
#define SHRT_MIN
#define SHRT_MAX
#define USHRT_MAX
#define INT_MIN
#define INT_MAX
#define UINT_MAX
#define LONG_MIN
#define LONG_MAX
#define ULONG_MAX
#define LLONG_MIN
#define LLONG_MAX
#define ULLONG_MAX
```

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[Visão geral da biblioteca padrão C++](../standard-library/cpp-standard-library-overview.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
