---
title: Classe ctype_base | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- locale/std::ctype_base
dev_langs:
- C++
helpviewer_keywords:
- ctype_base class
ms.assetid: ccffe891-d7ab-4d22-baf8-8eb6d438a96d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3def685a8cd108666b3e1b8be9314fc7585a9837
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="ctypebase-class"></a>Classe ctype_base

A classe serve como uma classe base para facetas da classe de modelo [ctype](../standard-library/ctype-class.md). Uma classe base da classe ctype que é usada para definir tipos de enumeração usados para classificar ou testar caracteres individualmente ou dentro de intervalos inteiros.

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

É possível caracterizar uma combinação de classificações pelo uso de OR nessas constantes. Em particular, é sempre true que **alnum** = = ( **alpha** &#124; **dígitos** \) e **gráfico** \= \= \( **alnum** &#124; **pontuação**).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<locale>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
