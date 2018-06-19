---
title: _com_error::HRESULTToWCode | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _com_error::HRESULTToWCode
dev_langs:
- C++
helpviewer_keywords:
- HRESULTToWCode method [C++]
ms.assetid: ff3789f5-1047-41a0-b7e3-86dd8f638dba
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7e3955fcda665e08e5415652a1e8f1f232d0fe13
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32412258"
---
# <a name="comerrorhresulttowcode"></a>_com_error::HRESULTToWCode
**Seção específica da Microsoft**  
  
 Mapas de 32 bits `HRESULT` para 16 bits `wCode`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      static WORD HRESULTToWCode(  
   HRESULT hr   
) throw( );  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `hr`  
 32 bits `HRESULT` a ser mapeada para 16-bit `wCode`.  
  
## <a name="return-value"></a>Valor de retorno  
 16-bit `wCode` mapeada a partir de 32 bits `HRESULT`.  
  
## <a name="remarks"></a>Comentários  
 Consulte [_com_error::WCode](../cpp/com-error-wcode.md) para obter mais informações.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [_com_error::WCode](../cpp/com-error-wcode.md)   
 [_com_error::WCodeToHRESULT](../cpp/com-error-wcodetohresult.md)   
 [Classe _com_error](../cpp/com-error-class.md)