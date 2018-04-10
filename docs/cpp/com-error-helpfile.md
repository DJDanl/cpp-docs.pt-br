---
title: _com_error::HelpFile | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-language
ms.tgt_pltfrm: ''
ms.topic: language-reference
f1_keywords:
- _com_error::HelpFile
dev_langs:
- C++
helpviewer_keywords:
- HelpFile method [C++]
ms.assetid: d2d3a0a1-6b62-4d52-a818-3cfae545a4af
caps.latest.revision: 6
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: cac4eda3b84243c09043d8f57a04d3cc5fb8a662
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="comerrorhelpfile"></a>_com_error::HelpFile
**Seção específica da Microsoft**  
  
 Chamadas **IErrorInfo::GetHelpFile** função.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
_bstr_t HelpFile() const;  
  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna o resultado da **IErrorInfo::GetHelpFile** para o **IErrorInfo** objeto registrados dentro de `_com_error` objeto. O BSTR resultante é encapsulado em um objeto `_bstr_t`. Se nenhum **IErrorInfo** é registrado, ele retorna vazio `_bstr_t`.  
  
## <a name="remarks"></a>Comentários  
 Qualquer falha ao chamar o **IErrorInfo::GetHelpFile** método será ignorado.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _com_error](../cpp/com-error-class.md)