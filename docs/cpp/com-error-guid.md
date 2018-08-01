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
ms.openlocfilehash: c592607732eb5558ce74edb7b71adbc023b2ae52
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39402277"
---
# <a name="comerrorguid"></a>_com_error::GUID
**Seção específica da Microsoft**  
  
 Chama a função `IErrorInfo::GetGUID`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
GUID GUID( ) const throw( );  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna o resultado da `IErrorInfo::GetGUID` para o `IErrorInfo` registrado no `_com_error` objeto. Se nenhum `IErrorInfo` é registrado, ele retorna `GUID_NULL`.  
  
## <a name="remarks"></a>Comentários  
 Qualquer falha ao chamar o `IErrorInfo::GetGUID` método é ignorado.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _com_error](../cpp/com-error-class.md)