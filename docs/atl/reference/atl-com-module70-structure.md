---
title: Estrutura de _ATL_COM_MODULE70 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 15
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: c55726a1728185f699afbac4ba68a6dc0f70c2bf
ms.openlocfilehash: a269820c5a0965553989bc57d7c239aa95e527ef
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="atlcommodule70-structure"></a>Estrutura _ATL_COM_MODULE70
Usado pelo relacionados COM o código em ATL.  
  
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
 A instância de identificador para a biblioteca de tipos para este módulo.  
  
 **m_ppAutoObjMapFirst**  
 Endereço do elemento da matriz que indica o início das entradas do mapa de objeto para este módulo.  
  
 **m_ppAutoObjMapLast**  
 Endereço do elemento da matriz que indica o fim das entradas de mapa de objeto para este módulo.  
  
 `m_csObjMap`  
 Seção crítica para serializar o acesso para as entradas de mapa do objeto. Usado internamente pelo ATL.  
  
## <a name="remarks"></a>Comentários  
 [_ATL_COM_MODULE](atl-typedefs.md#_atl_com_module) é definido como um typedef de `_ATL_COM_MODULE70`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas](../../atl/reference/atl-structures.md)






