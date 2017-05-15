---
title: "Funções &lt;system_error&gt; | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- system_error/std::generic_category
- system_error/std::make_error_code
- system_error/std::make_error_condition
- system_error/std::system_category
ms.assetid: 57d6f15f-f0b7-4e2f-80fe-31d3c320ee33
caps.latest.revision: 11
manager: ghogen
ms.translationtype: Machine Translation
ms.sourcegitcommit: 4ecf60434799708acab4726a95380a2d3b9dbb3a
ms.openlocfilehash: bcc9ee1b015699ab0c44bb362bcf82bc0597eb22
ms.contentlocale: pt-br
ms.lasthandoff: 04/19/2017

---
# <a name="ltsystemerrorgt-functions"></a>Funções &lt;system_error&gt;
||||  
|-|-|-|  
|[generic_category](#generic_category)|[make_error_code](#make_error_code)|[make_error_condition](#make_error_condition)|  
|[system_category](#system_category)|  
  
##  <a name="generic_category"></a>  generic_category  
 Representa a categoria de erros genéricos.  
  
```
extern const error_category& generic_category();
```  
  
### <a name="remarks"></a>Comentários  
 O `generic_category` objeto é uma implementação de [error_category](../standard-library/error-category-class.md).  
  
##  <a name="make_error_code"></a>  make_error_code  
 Cria um objeto de código de erro.  
  
```
error_code make_error_code(generic_errno _Errno);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`_Errno`|O valor de enumeração a ser armazenado no objeto de código de erro.|  
  
### <a name="return-value"></a>Valor de retorno  
 O objeto de código de erro.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="make_error_condition"></a>  make_error_condition  
 Cria um objeto de condição de erro.  
  
```
error_condition make_error_condition(generic_errno _Errno);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`_Errno`|O valor de enumeração a ser armazenado no objeto de condição de erro.|  
  
### <a name="return-value"></a>Valor de retorno  
 O objeto de condição de erro.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="system_category"></a>  system_category  
 Representa a categoria de erros causados por estouros de nível inferior do sistema.  
  
```
extern const error_category& system_category();
```  
  
### <a name="remarks"></a>Comentários  
 O `system_category` objeto é uma implementação de [error_category](../standard-library/error-category-class.md).  
  
## <a name="see-also"></a>Consulte também  
 [<system_error>](../standard-library/system-error.md)




