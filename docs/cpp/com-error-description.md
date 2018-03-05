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
- Description method [C++]
ms.assetid: 88191e24-4ee8-44a6-8c4c-3758e22e0548
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f3ed306a8eba4e76c2eefc738b617117188e85c8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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