---
title: _com_error::HelpContext | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _com_error::HelpContext
dev_langs:
- C++
helpviewer_keywords:
- HelpContext method [C++]
ms.assetid: 160d6443-9b68-4cf5-a540-50da951a5b2b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7123fcf5859ce3fc373b29b4cb3e7b32109b464e
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32410818"
---
# <a name="comerrorhelpcontext"></a>_com_error::HelpContext
**Seção específica da Microsoft**  
  
 Chamadas **IErrorInfo::GetHelpContext** função.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
DWORD HelpContext( ) const throw( );  
  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna o resultado da **IErrorInfo::GetHelpContext** para o **IErrorInfo** objeto registrados dentro de `_com_error` objeto. Se nenhum **IErrorInfo** objeto será registrado, ele retorna um zero.  
  
## <a name="remarks"></a>Comentários  
 Qualquer falha ao chamar o **IErrorInfo::GetHelpContext** método será ignorado.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _com_error](../cpp/com-error-class.md)