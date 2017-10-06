---
title: _com_error::Description | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- _com_error::Description
dev_langs:
- C++
helpviewer_keywords:
- Description method
ms.assetid: 88191e24-4ee8-44a6-8c4c-3758e22e0548
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
ms.openlocfilehash: 0d91f6fded1fa1c4ea4d44cadd0d9285913b5f42
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="comerrordescription"></a>_com_error::Description
**Seção específica da Microsoft**  
  
 Chamadas **IErrorInfo:: GetDescription** função.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
_bstr_t Description( ) const;  
  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna o resultado da **IErrorInfo:: GetDescription** para o **IErrorInfo** objeto registrados dentro de `_com_error` objeto. O `BSTR` resultante é encapsulado em um objeto `_bstr_t`. Se nenhum **IErrorInfo** é registrado, ele retorna vazio `_bstr_t`.  
  
## <a name="remarks"></a>Comentários  
 Chamadas de **IErrorInfo:: GetDescription** função e recupera **IErrorInfo** registrados no `_com_error` objeto. Qualquer falha ao chamar o **IErrorInfo:: GetDescription** método será ignorado.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _com_error](../cpp/com-error-class.md)
