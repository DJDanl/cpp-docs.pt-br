---
title: _com_error::HRESULTToWCode | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: _com_error::HRESULTToWCode
dev_langs: C++
helpviewer_keywords: HRESULTToWCode method [C++]
ms.assetid: ff3789f5-1047-41a0-b7e3-86dd8f638dba
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 14c4cdf85e67bdb0acd8dbadd178e3fbd2dbaf54
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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