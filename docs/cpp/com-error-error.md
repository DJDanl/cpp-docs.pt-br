---
title: _com_error::Error | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _com_error::Error
- Error
dev_langs:
- C++
helpviewer_keywords:
- Error method [C++]
ms.assetid: b53a15fd-198e-4276-afcd-13439c4807f7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 6a7ddaefcf3bd46bf40b03c03d2d1fb00cf8fbbb
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39408421"
---
# <a name="comerrorerror"></a>_com_error::Error
**Seção específica da Microsoft**  
  
 Recupera o HRESULT transmitido ao construtor.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
HRESULT Error( ) const throw( );  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Item HRESULT bruto passado para o construtor.  
  
## <a name="remarks"></a>Comentários  
 Recupera o item HRESULT encapsulado em um `_com_error` objeto.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _com_error](../cpp/com-error-class.md)