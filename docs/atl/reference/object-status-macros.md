---
title: Macros de Status do objeto | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- atlcom/ATL::DECLARE_OLEMISC_STATUS
dev_langs:
- C++
ms.assetid: 727dbef2-a342-4157-9d64-a421805d9747
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: eddfc28c659d0c1eb54794d8fc76a9f3a4f9e73b
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32360868"
---
# <a name="object-status-macros"></a>Macros de Status do objeto
Esta macro define os sinalizadores que pertencem aos controles ActiveX.  
  
|||  
|-|-|  
|[DECLARE_OLEMISC_STATUS](#declare_olemisc_status)|Usado em controles ActiveX ATL para definir o **OLEMISC** sinalizadores.|  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  

##  <a name="declare_olemisc_status"></a>  DECLARE_OLEMISC_STATUS  
 Usado em controles ActiveX ATL para definir os sinalizadores OLEMISC.  
  
```
DECLARE_OLEMISC_STATUS( miscstatus )
```  
  
### <a name="parameters"></a>Parâmetros  
 *miscstatus*  
 Sinalizadores OLEMISC todos os aplicáveis.  
  
### <a name="remarks"></a>Comentários  
 Essa macro é usada para definir os sinalizadores OLEMISC para um controle ActiveX. Consulte [IOleObject::GetMiscStatus](http://msdn.microsoft.com/library/windows/desktop/ms678521) para obter mais detalhes.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing#124](../../atl/codesnippet/cpp/object-status-macros_1.h)]  
  
## <a name="see-also"></a>Consulte também  
 [Macros](../../atl/reference/atl-macros.md)
