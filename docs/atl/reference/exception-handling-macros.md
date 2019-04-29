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
ms.openlocfilehash: 8afb2019e38f7548467e85d9a2c1c12c538cf744
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62276233"
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
