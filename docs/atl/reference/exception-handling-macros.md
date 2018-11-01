---
title: Macros de tratamento de exceção
ms.date: 11/04/2016
f1_keywords:
- atldef/ATL::_ATLCATCH
- atldef/ATL::_ATLCATCHALL
- atldef/ATL::_ATLTRY
helpviewer_keywords:
- exception handling, macros
- C++ exception handling, macros
ms.assetid: a8385d34-3fb0-4006-a42a-de045cacf0f4
ms.openlocfilehash: cf4b7ffb8c6b197dc1c4eea4b6c569e173bb188d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50544398"
---
# <a name="exception-handling-macros"></a>Macros de tratamento de exceção

Essas macros fornecem suporte para manipulação de exceção.

|||
|-|-|
|[_ATLCATCH](#_atlcatch)|Instruções para manipular erros que ocorrem no associado `_ATLTRY`.|
|[_ATLCATCHALL](#_atlcatchall)|Instruções para manipular erros que ocorrem no associado `_ATLTRY`.|
|[_ATLTRY](#_atltry)|Marca uma seção de código protegido, em que um erro, possivelmente, pode ocorrer.|

## <a name="requirements"></a>Requisitos:

**Cabeçalho:** atldef.h

##  <a name="_atlcatch"></a>  _ATLCATCH

Instruções para manipular erros que ocorrem no associado `_ATLTRY`.

```
_ATLCATCH(e)
```

### <a name="parameters"></a>Parâmetros

*e*<br/>
Exceção a ser obtida.

### <a name="remarks"></a>Comentários

Usado em conjunto com `_ATLTRY`. Resolve para C++ [catch (e CAtlException)](../../cpp/try-throw-and-catch-statements-cpp.md) para lidar com um determinado tipo de exceções do C++.

##  <a name="_atlcatchall"></a>  _ATLCATCHALL

Instruções para manipular erros que ocorrem no associado `_ATLTRY`.

```
_ATLCATCHALL
```

### <a name="remarks"></a>Comentários

Usado em conjunto com `_ATLTRY`. Resolve para C++ [Catch ](../../cpp/try-throw-and-catch-statements-cpp.md) para lidar com todos os tipos de exceções do C++.

##  <a name="_atltry"></a>  _ATLTRY

Marca uma seção de código protegido, em que um erro, possivelmente, pode ocorrer.

```
_ATLTRY
```

### <a name="remarks"></a>Comentários

Usado em conjunto com [_ATLCATCH](#_atlcatch) ou [_ATLCATCHALL](#_atlcatchall). Resolve para o símbolo de C++ [tente](../../cpp/try-throw-and-catch-statements-cpp.md).

## <a name="see-also"></a>Consulte também

[Macros](../../atl/reference/atl-macros.md)
