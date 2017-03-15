---
title: Macros de mensagens do Windows | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
ms.assetid: 63abd22c-372d-4148-bb04-c605950ae64f
caps.latest.revision: 16
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 604a4bf49490ad2599c857eb3afd527d67e1e25b
ms.openlocfilehash: be814c0a2ade7df8f7a4d6863627e79efe0a48bc
ms.lasthandoff: 02/25/2017

---
# <a name="windows-messages-macros"></a>Macros de mensagens do Windows
Essa macro encaminha as mensagens de janela.  
  
|||  
|-|-|  
|[WM_FORWARDMSG](#wm_forwardmsg)|Use para encaminhar uma mensagem recebida por uma janela para outra janela para processamento.|  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase. h 
   
##  <a name="a-namewmforwardmsga--wmforwardmsg"></a><a name="wm_forwardmsg"></a>WM_FORWARDMSG  
 Essa macro encaminha uma mensagem recebida por uma janela para outra janela para processamento.  
  
```
WM_FORWARDMSG
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a mensagem foi processada, zero se não.  
  
### <a name="remarks"></a>Comentários  
 Use `WM_FORWARDMSG` para encaminhar uma mensagem recebida por uma janela para outra janela para processamento. O LPARAM e o WPARAM parâmetros são usados da seguinte maneira:  
  
|Parâmetro|Uso|  
|---------------|-----------|  
|WPARAM|Dados definidos pelo usuário|  
|LPARAM|Um ponteiro para um `MSG` estrutura que contém informações sobre uma mensagem|  
  
### <a name="example"></a>Exemplo  
 No exemplo a seguir, `m_hWndOther` representa a outra janela que recebe essa mensagem.  
  
 [!code-cpp[NVC_ATL_Windowing&#137;](../../atl/codesnippet/cpp/windows-messages-macros_1.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Macros](../../atl/reference/atl-macros.md)

