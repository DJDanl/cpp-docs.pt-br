---
title: Macros de mensagens do Windows | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- atlbase/ATL::WM_FORWARDMSG
dev_langs:
- C++
ms.assetid: 63abd22c-372d-4148-bb04-c605950ae64f
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 6dde3255997b03eb827ef9e318de73b3badee23c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="windows-messages-macros"></a>Macros de mensagens do Windows
Esta macro encaminha mensagens de janela.  
  
|||  
|-|-|  
|[WM_FORWARDMSG](#wm_forwardmsg)|Use esta opção para encaminhar uma mensagem recebida por uma janela para outra janela para o processamento.|  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase 
   
##  <a name="wm_forwardmsg"></a>WM_FORWARDMSG  
 Esta macro encaminha uma mensagem recebida por uma janela para outra janela para processamento.  
  
```
WM_FORWARDMSG
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a mensagem foi processada, zero se não.  
  
### <a name="remarks"></a>Comentários  
 Use `WM_FORWARDMSG` para encaminhar uma mensagem recebida por uma janela para outra janela para processamento. Os parâmetros LPARAM e WPARAM são usados da seguinte maneira:  
  
|Parâmetro|Uso|  
|---------------|-----------|  
|WPARAM|Dados definidos pelo usuário|  
|LPARAM|Um ponteiro para um `MSG` estrutura que contém informações sobre a mensagem|  
  
### <a name="example"></a>Exemplo  
 No exemplo a seguir, `m_hWndOther` representa a outra janela que recebe essa mensagem.  
  
 [!code-cpp[NVC_ATL_Windowing#137](../../atl/codesnippet/cpp/windows-messages-macros_1.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Macros](../../atl/reference/atl-macros.md)
