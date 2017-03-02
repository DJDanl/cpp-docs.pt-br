---
title: "Macros de tratamento de exceção | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- exception handling, macros
- C++ exception handling, macros
ms.assetid: a8385d34-3fb0-4006-a42a-de045cacf0f4
caps.latest.revision: 16
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 9d99551d8dbe116c9f4fafeb9602e471839003a7
ms.lasthandoff: 02/25/2017

---
# <a name="exception-handling-macros"></a>Macros de tratamento de exceção
Essas macros fornecem suporte para tratamento de exceções.  
  
|||  
|-|-|  
|[_ATLCATCH](#_atlcatch)|Instruções para manipular erros que ocorrem em associado `_ATLTRY`.|  
|[_ATLCATCHALL](#_atlcatchall)|Instruções para manipular erros que ocorrem em associado `_ATLTRY`.|  
|[_ATLTRY](#_atltry)|Marca uma seção de código protegido onde possivelmente poderia ocorrer um erro.|  
  
##  <a name="a-nameatlcatcha--atlcatch"></a><a name="_atlcatch"></a>_ATLCATCH  
 Instruções para manipular erros que ocorrem em associado `_ATLTRY`.  
  
```
_ATLCATCH(e)
```  
  
### <a name="parameters"></a>Parâmetros  
 *e*  
 A exceção para capturar.  
  
### <a name="remarks"></a>Comentários  
 Usado em conjunto com `_ATLTRY`. Resolve para C++ [catch (e CAtlException)](../../cpp/try-throw-and-catch-statements-cpp.md) para lidar com um determinado tipo de exceções C++.  
  
##  <a name="a-nameatlcatchalla--atlcatchall"></a><a name="_atlcatchall"></a>_ATLCATCHALL  
 Instruções para manipular erros que ocorrem em associado `_ATLTRY`.  
  
```
_ATLCATCHALL
```  
  
### <a name="remarks"></a>Comentários  
 Usado em conjunto com `_ATLTRY`. Resolve para C++ [Catch ](../../cpp/try-throw-and-catch-statements-cpp.md) para lidar com todos os tipos de exceções C++.  
  
##  <a name="a-nameatltrya--atltry"></a><a name="_atltry"></a>_ATLTRY  
 Marca uma seção de código protegido onde possivelmente poderia ocorrer um erro.  
  
```
_ATLTRY
```  
  
### <a name="remarks"></a>Comentários  
 Usado em conjunto com [_ATLCATCH](#_atlcatch) ou [_ATLCATCHALL](#_atlcatchall). Resolve para o símbolo de C++ [tente](../../cpp/try-throw-and-catch-statements-cpp.md).  
  
## <a name="see-also"></a>Consulte também  
 [Macros](../../atl/reference/atl-macros.md)

