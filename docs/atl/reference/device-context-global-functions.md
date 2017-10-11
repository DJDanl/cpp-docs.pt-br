---
title: "Funções globais do contexto de dispositivo | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- atlwin/ATL::AtlCreateTargetDC
dev_langs:
- C++
ms.assetid: 08ec28f6-daff-4882-9544-e8a4639d05c4
caps.latest.revision: 17
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: c55726a1728185f699afbac4ba68a6dc0f70c2bf
ms.openlocfilehash: d2560043bc97c384846696b76d8e38b459ae4a34
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="device-context-global-functions"></a>Funções globais do contexto de dispositivo
Esta função cria um contexto de dispositivo para um determinado dispositivo.  
  
|||  
|-|-|  
|[AtlCreateTargetDC](#atlcreatetargetdc)|Cria um contexto de dispositivo.|  
  
##  <a name="atlcreatetargetdc"></a>AtlCreateTargetDC  
 Cria um contexto de dispositivo para o dispositivo especificado no [DVTARGETDEVICE](http://msdn.microsoft.com/library/windows/desktop/ms686613) estrutura.  
  
```
HDC AtlCreateTargetDC(HDC hdc, DVTARGETDEVICE* ptd);
```  
  
### <a name="parameters"></a>Parâmetros  
 *hDC*  
 [in] O identificador existente de um contexto de dispositivo, ou **nulo**.  
  
 `ptd`  
 [in] Um ponteiro para o **DVTARGETDEVICE** estrutura que contém informações sobre o dispositivo de destino.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o identificador de um contexto de dispositivo para o dispositivo especificado no **DVTARGETDEVICE**. Se nenhum dispositivo for especificado, retorna o identificador para o dispositivo de vídeo padrão.  
  
### <a name="remarks"></a>Comentários  
 Se a estrutura é **nulo** e *hdc* é **nulo**, cria um contexto de dispositivo para o dispositivo de vídeo padrão.  
  
 Se *hdc* não é **nulo** e `ptd` é **nulo**, a função retorna existente *hdc*.  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h  
   
## <a name="see-also"></a>Consulte também  
 [Funções](../../atl/reference/atl-functions.md)

