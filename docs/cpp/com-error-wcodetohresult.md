---
title: _com_error::WCodeToHRESULT | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _com_error::WCodeToHRESULT
dev_langs:
- C++
helpviewer_keywords:
- WCodeToHRESULT method [C++]
ms.assetid: 0ec43a4b-ca91-42d5-b270-3fde9c8412ea
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 31b9df8305d0eea772979904f63847f6d6c2325a
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32413369"
---
# <a name="comerrorwcodetohresult"></a>_com_error::WCodeToHRESULT
**Seção específica da Microsoft**  
  
 Mapeia um `wCode` de 16 bits para um `HRESULT` de 32 bits.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      static HRESULT WCodeToHRESULT(  
   WORD wCode   
) throw( );  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `wCode`  
 O `wCode` de 16 bits a ser mapeado para o `HRESULT` de 32 bits.  
  
## <a name="return-value"></a>Valor de retorno  
 O `HRESULT` de 32 bits mapeado para o `wCode` de 16 bits.  
  
## <a name="remarks"></a>Comentários  
 Consulte o [WCode](../cpp/com-error-wcode.md) função de membro.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [_com_error::WCode](../cpp/com-error-wcode.md)   
 [_com_error::HRESULTToWCode](../cpp/com-error-hresulttowcode.md)   
 [Classe _com_error](../cpp/com-error-class.md)