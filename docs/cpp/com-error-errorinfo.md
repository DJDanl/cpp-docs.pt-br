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
ms.openlocfilehash: 8fbc735dfae1b30209eccfd14f1170826fb07680
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="comerrorerrorinfo"></a>_com_error::ErrorInfo
**Seção específica da Microsoft**  
  
 Recupera o **IErrorInfo** objeto transmitido ao construtor.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
IErrorInfo * ErrorInfo( ) const throw( );  
  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Bruto **IErrorInfo** item passado para o construtor.  
  
## <a name="remarks"></a>Comentários  
 Recupera o encapsulada **IErrorInfo** item em uma `_com_error` objeto, ou **nulo** se nenhum **IErrorInfo** item é registrado. O chamador deve chamar **versão** no objeto retornado quando terminar de usá-lo.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _com_error](../cpp/com-error-class.md)