---
title: _com_error::ErrorInfo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _com_error::ErrorInfo
dev_langs:
- C++
helpviewer_keywords:
- ErrorInfo method [C++]
ms.assetid: 071b446c-4395-4fb8-bd3d-300a8b25f5cd
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 52935c81849ded072cb20d6c835b3a71b66c2871
ms.sourcegitcommit: 1fd1eb11f65f2999dfd93a2d924390ed0a0901ed
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/10/2018
ms.locfileid: "37941308"
---
# <a name="comerrorerrorinfo"></a>_com_error::ErrorInfo
**Seção específica da Microsoft**  
  
 Recupera o objeto `IErrorInfo` passado para o construtor.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
IErrorInfo * ErrorInfo( ) const throw( );  
  
```  
  
## <a name="return-value"></a>Valor de retorno  
 O item `IErrorInfo` bruto passado para o construtor.  
  
## <a name="remarks"></a>Comentários  
 Recupera encapsulado `IErrorInfo` de item em uma `_com_error` do objeto ou nulo se nenhum `IErrorInfo` item é registrado. O chamador deve chamar `Release` no objeto retornado quando terminar de usá-lo.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _com_error](../cpp/com-error-class.md)