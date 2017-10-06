---
title: _com_error::GUID | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- _com_error::GUID
dev_langs:
- C++
helpviewer_keywords:
- GUID method [C++]
ms.assetid: e84c2c23-d02e-48f8-b776-9bd6937296d2
caps.latest.revision: 6
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
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 6a1d0349344362853215a2c47db166bc4b885187
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="comerrorguid"></a>_com_error::GUID
**Seção específica da Microsoft**  
  
 Chamadas **IErrorInfo::GetGUID** função.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
GUID GUID( ) const throw( );  
  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna o resultado da **IErrorInfo::GetGUID** para o **IErrorInfo** objeto registrados dentro de `_com_error` objeto. Se nenhum **IErrorInfo** objeto é registrado, ele retorna `GUID_NULL`.  
  
## <a name="remarks"></a>Comentários  
 Qualquer falha ao chamar o **IErrorInfo::GetGUID** método será ignorado.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _com_error](../cpp/com-error-class.md)
