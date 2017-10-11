---
title: _com_error::HelpContext | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- _com_error::HelpContext
dev_langs:
- C++
helpviewer_keywords:
- HelpContext method [C++]
ms.assetid: 160d6443-9b68-4cf5-a540-50da951a5b2b
caps.latest.revision: 6
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: d3eb0678e7d3b7cb4c1824cf17bc25499bf0c0ce
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

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
