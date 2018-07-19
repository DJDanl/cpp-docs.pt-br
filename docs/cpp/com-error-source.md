---
title: _com_error::Source | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _com_error::Source
dev_langs:
- C++
helpviewer_keywords:
- Source method [C++]
ms.assetid: 55353741-fabc-4b0c-9787-b5a69bb189f2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f904fa11195c27f8e08856ef391d0ba8adbedece
ms.sourcegitcommit: 1fd1eb11f65f2999dfd93a2d924390ed0a0901ed
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/10/2018
ms.locfileid: "37939670"
---
# <a name="comerrorsource"></a>_com_error::Source
**Seção específica da Microsoft**  
  
 Chama a função `IErrorInfo::GetSource`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
_bstr_t Source() const;  
  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna o resultado da `IErrorInfo::GetSource` para o `IErrorInfo` registrado no `_com_error` objeto. O BSTR resultante é encapsulado em um objeto `_bstr_t`. Se nenhum `IErrorInfo` é registrado, ele retornará um `_bstr_t`.  
  
## <a name="remarks"></a>Comentários  
 Qualquer falha ao chamar o `IErrorInfo::GetSource` método é ignorado.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _com_error](../cpp/com-error-class.md)