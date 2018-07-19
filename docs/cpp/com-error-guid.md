---
title: _com_error::GUID | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _com_error::GUID
dev_langs:
- C++
helpviewer_keywords:
- GUID method [C++]
ms.assetid: e84c2c23-d02e-48f8-b776-9bd6937296d2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e324a84a16874a7e33f8687943b1302fbdd73a7a
ms.sourcegitcommit: 1fd1eb11f65f2999dfd93a2d924390ed0a0901ed
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/10/2018
ms.locfileid: "37939020"
---
# <a name="comerrorguid"></a>_com_error::GUID
**Seção específica da Microsoft**  
  
 Chama a função `IErrorInfo::GetGUID`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
GUID GUID( ) const throw( );  
  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna o resultado da `IErrorInfo::GetGUID` para o `IErrorInfo` registrado no `_com_error` objeto. Se nenhum `IErrorInfo` é registrado, ele retorna GUID_NULL.  
  
## <a name="remarks"></a>Comentários  
 Qualquer falha ao chamar o `IErrorInfo::GetGUID` método é ignorado.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _com_error](../cpp/com-error-class.md)