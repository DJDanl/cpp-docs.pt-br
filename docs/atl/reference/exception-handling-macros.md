---
title: Macros de tratamento de exceções
ms.date: 11/04/2016
f1_keywords:
- atldef/ATL::_ATLCATCH
- atldef/ATL::_ATLCATCHALL
- atldef/ATL::_ATLTRY
helpviewer_keywords:
- exception handling, macros
- C++ exception handling, macros
ms.assetid: a8385d34-3fb0-4006-a42a-de045cacf0f4
ms.openlocfilehash: 7fcd8221ba5f121749cf366a93cc8a6d8d00ed7c
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88833433"
---
# <a name="exception-handling-macros"></a>Macros de tratamento de exceções

Essas macros oferecem suporte para tratamento de exceção.

|Nome|Descrição|
|-|-|
|[_ATLCATCH](#_atlcatch)|Instruções para tratar erros que ocorrem no associado `_ATLTRY` .|
|[_ATLCATCHALL](#_atlcatchall)|Instruções para tratar erros que ocorrem no associado `_ATLTRY` .|
|[_ATLTRY](#_atltry)|Marca uma seção de código protegido em que um erro pode ocorrer.|

## <a name="requirements"></a>Requisitos:

**Cabeçalho:** atldef. h

## <a name="_atlcatch"></a><a name="_atlcatch"></a> _ATLCATCH

Instruções para tratar erros que ocorrem no associado `_ATLTRY` .

```
_ATLCATCH(e)
```

### <a name="parameters"></a>parâmetros

*Oriental*<br/>
A exceção a ser detectada.

### <a name="remarks"></a>Comentários

Usado em conjunto com `_ATLTRY` . Resolve para C++ [Catch (CAtlException e)](../../cpp/try-throw-and-catch-statements-cpp.md) para manipular um determinado tipo de exceções de c++.

## <a name="_atlcatchall"></a><a name="_atlcatchall"></a> _ATLCATCHALL

Instruções para tratar erros que ocorrem no associado `_ATLTRY` .

```
_ATLCATCHALL
```

### <a name="remarks"></a>Comentários

Usado em conjunto com `_ATLTRY` . Resolve para C++ [Catch (...)](../../cpp/try-throw-and-catch-statements-cpp.md) para lidar com todos os tipos de exceções de c++.

## <a name="_atltry"></a><a name="_atltry"></a> _ATLTRY

Marca uma seção de código protegido em que um erro pode ocorrer.

```
_ATLTRY
```

### <a name="remarks"></a>Comentários

Usado em conjunto com [_ATLCATCH](#_atlcatch) ou [_ATLCATCHALL](#_atlcatchall). Resolve para o símbolo C++ [try](../../cpp/try-throw-and-catch-statements-cpp.md).

## <a name="see-also"></a>Confira também

[Macros](../../atl/reference/atl-macros.md)
