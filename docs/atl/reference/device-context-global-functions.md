---
title: "Funções globais de contexto de dispositivo | Documentos do Microsoft"
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
ms.assetid: 08ec28f6-daff-4882-9544-e8a4639d05c4
caps.latest.revision: 17
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
ms.openlocfilehash: 8c71781519b965717acbcefab6fe6a183686caef
ms.lasthandoff: 02/25/2017

---
# <a name="device-context-global-functions"></a>Funções globais de contexto de dispositivo
Esta função cria um contexto de dispositivo para um determinado dispositivo.  
  
|||  
|-|-|  
|[AtlCreateTargetDC](#atlcreatetargetdc)|Cria um contexto de dispositivo.|  
  
##  <a name="a-nameatlcreatetargetdca--atlcreatetargetdc"></a><a name="atlcreatetargetdc"></a>AtlCreateTargetDC  
 Cria um contexto de dispositivo para o dispositivo especificado no [DVTARGETDEVICE](http://msdn.microsoft.com/library/windows/desktop/ms686613) estrutura.  
  
```
HDC AtlCreateTargetDC(HDC hdc, DVTARGETDEVICE* ptd);
```  
  
### <a name="parameters"></a>Parâmetros  
 *hDC*  
 [in] O identificador existente de um contexto de dispositivo ou **nulo**.  
  
 `ptd`  
 [in] Um ponteiro para o **DVTARGETDEVICE** estrutura que contém informações sobre o dispositivo de destino.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o identificador de um contexto de dispositivo para o dispositivo especificado no **DVTARGETDEVICE**. Se nenhum dispositivo for especificado, retorna o identificador para o dispositivo de exibição padrão.  
  
### <a name="remarks"></a>Comentários  
 Se a estrutura é **nulo** e *hdc* é **nulo**, cria um contexto de dispositivo para o dispositivo de exibição padrão.  
  
 Se *hdc* não é **nulo** e `ptd` é **nulo**, a função retorna existente *hdc*.  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h  
   
## <a name="see-also"></a>Consulte também  
 [Funções](../../atl/reference/atl-functions.md)

