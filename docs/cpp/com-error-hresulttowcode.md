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
ms.openlocfilehash: f0ddac28c4f39cdf11abbdf38c3af5d00c22413a
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39401900"
---
# <a name="comerrorhresulttowcode"></a>_com_error::HRESULTToWCode
**Seção específica da Microsoft**  
  
 Mapeia o HRESULT de 32 bits para 16 bits `wCode`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
static WORD HRESULTToWCode(  
   HRESULT hr   
) throw( );  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *hr*  
 O HRESULT de 32 bits a ser mapeada para 16 bits `wCode`.  
  
## <a name="return-value"></a>Valor de retorno  
 16-bit `wCode` mapeada a partir o HRESULT de 32 bits.  
  
## <a name="remarks"></a>Comentários  
 Ver [_com_error::WCode](../cpp/com-error-wcode.md) para obter mais informações.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [_com_error::WCode](../cpp/com-error-wcode.md)   
 [_com_error::WCodeToHRESULT](../cpp/com-error-wcodetohresult.md)   
 [Classe _com_error](../cpp/com-error-class.md)