---
title: _com_error::Description | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _com_error::Description
dev_langs:
- C++
helpviewer_keywords:
- Description method [C++]
ms.assetid: 88191e24-4ee8-44a6-8c4c-3758e22e0548
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 4be038bff05ce7a37b09ec3b3c61572635747864
ms.sourcegitcommit: 1fd1eb11f65f2999dfd93a2d924390ed0a0901ed
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/10/2018
ms.locfileid: "37939891"
---
# <a name="comerrordescription"></a>_com_error::Description
**Seção específica da Microsoft**  
  
 Chama a função `IErrorInfo::GetDescription`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
_bstr_t Description( ) const;  
  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna o resultado da `IErrorInfo::GetDescription` para o `IErrorInfo` registrado no `_com_error` objeto. O `BSTR` resultante é encapsulado em um objeto `_bstr_t`. Se nenhum `IErrorInfo` é registrado, ele retornará um `_bstr_t`.  
  
## <a name="remarks"></a>Comentários  
 Chamadas a `IErrorInfo::GetDescription` função e recupera `IErrorInfo` registrado no `_com_error` objeto. Qualquer falha ao chamar o `IErrorInfo::GetDescription` método é ignorado.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _com_error](../cpp/com-error-class.md)