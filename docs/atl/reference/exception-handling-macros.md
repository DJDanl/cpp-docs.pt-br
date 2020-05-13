---
title: Macros de manipulação de exceções
ms.date: 11/04/2016
f1_keywords:
- atldef/ATL::_ATLCATCH
- atldef/ATL::_ATLCATCHALL
- atldef/ATL::_ATLTRY
helpviewer_keywords:
- exception handling, macros
- C++ exception handling, macros
ms.assetid: a8385d34-3fb0-4006-a42a-de045cacf0f4
ms.openlocfilehash: 2beffbbed0efee799005190bd7fd071a2087e4d9
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81330082"
---
# <a name="exception-handling-macros"></a>Macros de manipulação de exceções

Essas macros fornecem suporte para o manuseio de exceções.

|||
|-|-|
|[_ATLCATCH](#_atlcatch)|Declaração(s) para lidar com `_ATLTRY`erros ocorridos no associado .|
|[_ATLCATCHALL](#_atlcatchall)|Declaração(s) para lidar com `_ATLTRY`erros ocorridos no associado .|
|[_ATLTRY](#_atltry)|Marca uma seção de código guardada onde um erro poderia ocorrer.|

## <a name="requirements"></a>Requisitos:

**Cabeçalho:** atldef.h

## <a name="_atlcatch"></a><a name="_atlcatch"></a>_ATLCATCH

Declaração(s) para lidar com `_ATLTRY`erros ocorridos no associado .

```
_ATLCATCH(e)
```

### <a name="parameters"></a>Parâmetros

*e*<br/>
A exceção para pegar.

### <a name="remarks"></a>Comentários

Usado em `_ATLTRY`conjunto com . Resolve a captura C++ [(CAtlException e)](../../cpp/try-throw-and-catch-statements-cpp.md) para lidar com um determinado tipo de exceções C++.

## <a name="_atlcatchall"></a><a name="_atlcatchall"></a>_ATLCATCHALL

Declaração(s) para lidar com `_ATLTRY`erros ocorridos no associado .

```
_ATLCATCHALL
```

### <a name="remarks"></a>Comentários

Usado em `_ATLTRY`conjunto com . Resolve a captura [C++(...)](../../cpp/try-throw-and-catch-statements-cpp.md) para lidar com todos os tipos de exceções C++.

## <a name="_atltry"></a><a name="_atltry"></a>_ATLTRY

Marca uma seção de código guardada onde um erro poderia ocorrer.

```
_ATLTRY
```

### <a name="remarks"></a>Comentários

Usado em conjunto com [_ATLCATCH](#_atlcatch) ou [_ATLCATCHALL](#_atlcatchall). Resolve a tentativa do símbolo [C++.](../../cpp/try-throw-and-catch-statements-cpp.md)

## <a name="see-also"></a>Confira também

[Macros](../../atl/reference/atl-macros.md)
