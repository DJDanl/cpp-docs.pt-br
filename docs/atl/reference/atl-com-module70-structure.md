---
title: Estrutura _ATL_COM_MODULE70 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- ATL::_ATL_COM_MODULE70
- ATL._ATL_COM_MODULE70
- _ATL_COM_MODULE70
dev_langs:
- C++
helpviewer_keywords:
- _ATL_COM_MODULE70 structure
- ATL_COM_MODULE70 structure
ms.assetid: 5b0b2fd0-bdeb-4c7e-8870-78fa69ace6e6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3a3140a0013d284b9145029575418054af22c65e
ms.sourcegitcommit: 7d68f8303e021e27dc8f4d36e764ed836e93d24f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/06/2018
ms.locfileid: "37883707"
---
# <a name="atlcommodule70-structure"></a>Estrutura _ATL_COM_MODULE70
Usado pelo código COM relacionados na ATL.  
  
## <a name="syntax"></a>Sintaxe  
  
```
struct _ATL_COM_MODULE70 {
    UINT cbSize;
    HINSTANCE m_hInstTypeLib;
    _ATL_OBJMAP_ENTRY** m_ppAutoObjMapFirst;
    _ATL_OBJMAP_ENTRY** m_ppAutoObjMapLast;
    CRITICAL_SECTION m_csObjMap;
};
```  
  
## <a name="members"></a>Membros  
 `cbSize`  
 O tamanho da estrutura, usado para controle de versão.  
  
 `m_hInstTypeLib`  
 A instância do identificador para a biblioteca de tipos para esse módulo.  
  
 `m_ppAutoObjMapFirst`  
 Endereço do elemento da matriz que indica o início das entradas de mapa de objeto para esse módulo.  
  
 `m_ppAutoObjMapLast`  
 Endereço do elemento da matriz que indicam o final das entradas de mapa de objeto para esse módulo.  
  
 `m_csObjMap`  
 Seção crítica para serializar o acesso às entradas de mapa de objeto. Usado internamente pelo ATL.  
  
## <a name="remarks"></a>Comentários  
 [_ATL_COM_MODULE](atl-typedefs.md#_atl_com_module) é definido como um typedef de _ATL_COM_MODULE70.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase. h  
  
## <a name="see-also"></a>Consulte também  
 [Classes e structs](../../atl/reference/atl-classes.md)





