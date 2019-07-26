---
title: '&lt;clocale&gt;'
ms.date: 11/04/2016
f1_keywords:
- <clocale>
helpviewer_keywords:
- clocale header
ms.assetid: 5bde3e01-cf67-4f1f-a383-447ec814d00e
ms.openlocfilehash: 60d15795328de567a8ba626f5344b2fb08e57aa7
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68459345"
---
# <a name="ltclocalegt"></a>&lt;clocale&gt;

Inclui o cabeçalho \<locale.h> da biblioteca C Padrão e adiciona os nomes associados ao namespace `std`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<> clocale

**Namespace:** std

## <a name="remarks"></a>Comentários

A inclusão desse cabeçalho garante que os nomes declarados usando vinculação externa no cabeçalho da biblioteca C Padrão sejam declarados no namespace `std`.

## <a name="constants"></a>Constantes

```cpp
#define NULL see below
#define LC_ALL see below
#define LC_COLLATE see below
#define LC_CTYPE see below
#define LC_MONETARY see below
#define LC_NUMERIC see below
#define LC_TIME see below
```

## <a name="structures"></a>Estruturas

```cpp
struct lconv;
```

## <a name="functions"></a>Funções

```cpp
char* setlocale(int category, const char* locale);
lconv* localeconv();
```

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[Visão geral da biblioteca padrão C++](../standard-library/cpp-standard-library-overview.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
