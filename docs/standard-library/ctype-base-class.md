---
title: Classe ctype_base
ms.date: 11/04/2016
f1_keywords:
- locale/std::ctype_base
helpviewer_keywords:
- ctype_base class
ms.assetid: ccffe891-d7ab-4d22-baf8-8eb6d438a96d
ms.openlocfilehash: 4fac75d90c4e40a22e8ceae974c3f49c3d50a1d3
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72688186"
---
# <a name="ctype_base-class"></a>Classe ctype_base

A classe serve como uma classe base para facetas do modelo de classe [CType](../standard-library/ctype-class.md). Uma classe base da classe ctype que é usada para definir tipos de enumeração usados para classificar ou testar caracteres individualmente ou dentro de intervalos inteiros.

## <a name="syntax"></a>Sintaxe

```cpp
struct ctype_base : public locale::facet
{
    enum
    {
        alnum,
        alpha,
        cntrl,
        digit,
        graph,
        lower,
        print,
        punct,
        space,
        upper,
        xdigit
    };
    typedef short mask;

    ctype_base( size_t _Refs = 0 );
    ~ctype_base();
};
```

## <a name="remarks"></a>Comentários

Define uma máscara de enumeração. Cada constante de enumeração caracteriza uma maneira diferente de classificar caracteres, conforme definido pelas funções com nomes semelhantes declaradas no cabeçalho \<ctype.h>. As constantes são:

- **space** (função [isspace](../standard-library/locale-functions.md#isspace))

- **print** (função [isprint](../standard-library/locale-functions.md#isprint))

- **cntrl** (função [iscntrl](../standard-library/locale-functions.md#iscntrl))

- **upper** (função [isupper](../standard-library/locale-functions.md#isupper))

- **lower** (função [islower](../standard-library/locale-functions.md#islower))

- **digit** (função [isdigit](../standard-library/locale-functions.md#isdigit))

- **punct** (função [ispunct](../standard-library/locale-functions.md#ispunct))

- **xdigit** (função [isxdigit](../standard-library/locale-functions.md#isxdigit))

- **alpha** (função [isalpha](../standard-library/locale-functions.md#isalpha))

- **alnum** (função [isalnum](../standard-library/locale-functions.md#isalnum))

- **graph** (função [isgraph](../standard-library/locale-functions.md#isgraph))

É possível caracterizar uma combinação de classificações pelo uso de OR nessas constantes. Em particular, é sempre verdade que **alnum** = = ( **Alpha** &#124; **digit** \) e **Graph** \= \= \( **alnum** &#124; **punct**).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<locale>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
