---
title: Macros de tratamento de exceções | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- atldef/ATL::_ATLCATCH
- atldef/ATL::_ATLCATCHALL
- atldef/ATL::_ATLTRY
dev_langs:
- C++
helpviewer_keywords:
- exception handling, macros
- C++ exception handling, macros
ms.assetid: a8385d34-3fb0-4006-a42a-de045cacf0f4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2473a2a66792f1bfff18086030a8898a67339e10
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46024275"
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
