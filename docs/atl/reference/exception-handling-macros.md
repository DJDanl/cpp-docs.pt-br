---
title: "Macros de tratamento de exceção | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 424a65c44d7bb22d1fef6e21e1892967ecd3e9b8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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

##  <a name="_atlcatch"></a>_ATLCATCH  
 Instruções para manipular erros que ocorrem no associado `_ATLTRY`.  
  
```
_ATLCATCH(e)
```  
  
### <a name="parameters"></a>Parâmetros  
 *e*  
 A exceção a ser capturado.  
  
### <a name="remarks"></a>Comentários  
 Usado em conjunto com `_ATLTRY`. Resolve para C++ [catch (e CAtlException)](../../cpp/try-throw-and-catch-statements-cpp.md) para lidar com um determinado tipo de exceções do C++.  
  
##  <a name="_atlcatchall"></a>_ATLCATCHALL  
 Instruções para manipular erros que ocorrem no associado `_ATLTRY`.  
  
```
_ATLCATCHALL
```  
  
### <a name="remarks"></a>Comentários  
 Usado em conjunto com `_ATLTRY`. Resolve para C++ [catch(...) ](../../cpp/try-throw-and-catch-statements-cpp.md) para lidar com todos os tipos de exceções do C++.  
  
##  <a name="_atltry"></a>_ATLTRY  
 Marca uma seção de código protegido onde possivelmente poderia ocorrer um erro.  
  
```
_ATLTRY
```  
  
### <a name="remarks"></a>Comentários  
 Usado em conjunto com [_ATLCATCH](#_atlcatch) ou [_ATLCATCHALL](#_atlcatchall). Resolve para o símbolo de C++ [tente](../../cpp/try-throw-and-catch-statements-cpp.md).  
  
## <a name="see-also"></a>Consulte também  
 [Macros](../../atl/reference/atl-macros.md)
