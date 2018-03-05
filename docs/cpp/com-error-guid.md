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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 1165f53027c5b8a116f97cd2660c7ca12c9e7302
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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