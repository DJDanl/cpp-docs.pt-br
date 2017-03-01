---
title: Macros de Status do objeto | Documentos do Microsoft
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
ms.assetid: 727dbef2-a342-4157-9d64-a421805d9747
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
ms.openlocfilehash: 433a816b19690f22f482f26f6ab70c73ed102673
ms.lasthandoff: 02/25/2017

---
# <a name="object-status-macros"></a>Macros de Status do objeto
Essa macro define os sinalizadores que pertencem aos controles ActiveX.  
  
|||  
|-|-|  
|[DECLARE_OLEMISC_STATUS](#declare_olemisc_status)|Usado em controles ActiveX ATL para definir o **OLEMISC** sinalizadores.|  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  

##  <a name="a-namedeclareolemiscstatusa--declareolemiscstatus"></a><a name="declare_olemisc_status"></a>DECLARE_OLEMISC_STATUS  
 Usado em controles ActiveX ATL para definir os sinalizadores OLEMISC.  
  
```
DECLARE_OLEMISC_STATUS( miscstatus )
```  
  
### <a name="parameters"></a>Parâmetros  
 *miscstatus*  
 Sinalizadores OLEMISC todos aplicáveis.  
  
### <a name="remarks"></a>Comentários  
 Essa macro é usada para definir os sinalizadores OLEMISC para um controle ActiveX. Consulte [IOleObject::GetMiscStatus](http://msdn.microsoft.com/library/windows/desktop/ms678521) para obter mais detalhes.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing&#124;](../../atl/codesnippet/cpp/object-status-macros_1.h)]  
  
## <a name="see-also"></a>Consulte também  
 [Macros](../../atl/reference/atl-macros.md)

