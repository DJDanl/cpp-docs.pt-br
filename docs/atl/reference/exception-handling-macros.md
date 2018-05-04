---
title: Macros de tratamento de exceção | Microsoft Docs
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
ms.openlocfilehash: 05ee381aa792c252fc9b80107d25e15e7d1ecfca
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="exception-handling-macros"></a>Macros de tratamento de exceção
Essas macros fornecem suporte para manipulação de exceção.  
  
|||  
|-|-|  
|[_ATLCATCH](#_atlcatch)|Instruções para manipular erros que ocorrem no associado `_ATLTRY`.|  
|[_ATLCATCHALL](#_atlcatchall)|Instruções para manipular erros que ocorrem no associado `_ATLTRY`.|  
|[_ATLTRY](#_atltry)|Marca uma seção de código protegido onde possivelmente poderia ocorrer um erro.|  
  
## <a name="requirements"></a>Requisitos:
**Cabeçalho:** atldef.h

##  <a name="_atlcatch"></a>  _ATLCATCH  
 Instruções para manipular erros que ocorrem no associado `_ATLTRY`.  
  
```
_ATLCATCH(e)
```  
  
### <a name="parameters"></a>Parâmetros  
 *e*  
 A exceção a ser capturado.  
  
### <a name="remarks"></a>Comentários  
 Usado em conjunto com `_ATLTRY`. Resolve para C++ [catch (e CAtlException)](../../cpp/try-throw-and-catch-statements-cpp.md) para lidar com um determinado tipo de exceções do C++.  
  
##  <a name="_atlcatchall"></a>  _ATLCATCHALL  
 Instruções para manipular erros que ocorrem no associado `_ATLTRY`.  
  
```
_ATLCATCHALL
```  
  
### <a name="remarks"></a>Comentários  
 Usado em conjunto com `_ATLTRY`. Resolve para C++ [catch(...) ](../../cpp/try-throw-and-catch-statements-cpp.md) para lidar com todos os tipos de exceções do C++.  
  
##  <a name="_atltry"></a>  _ATLTRY  
 Marca uma seção de código protegido onde possivelmente poderia ocorrer um erro.  
  
```
_ATLTRY
```  
  
### <a name="remarks"></a>Comentários  
 Usado em conjunto com [_ATLCATCH](#_atlcatch) ou [_ATLCATCHALL](#_atlcatchall). Resolve para o símbolo de C++ [tente](../../cpp/try-throw-and-catch-statements-cpp.md).  
  
## <a name="see-also"></a>Consulte também  
 [Macros](../../atl/reference/atl-macros.md)
