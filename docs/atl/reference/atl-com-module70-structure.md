---
title: Estrutura de _ATL_COM_MODULE70 | Documentos do Microsoft
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 4e393abb2a904a0f5e101efe3d78d0645664397b
ms.openlocfilehash: 503c2a29cf0e70020b012911c51b056f00562374
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="atlcommodule70-structure"></a>Estrutura _ATL_COM_MODULE70
Utilizada pelo código relacionado COM ATL.  
  
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
 A instância do identificador para a biblioteca de tipos para este módulo.  
  
 **m_ppAutoObjMapFirst**  
 Endereço do elemento da matriz que indica o início das entradas de mapa de objeto para esse módulo.  
  
 **m_ppAutoObjMapLast**  
 Endereço do elemento da matriz que indica o fim das entradas de mapa de objeto para esse módulo.  
  
 `m_csObjMap`  
 Seção crítica para serializar o acesso para as entradas de mapa do objeto. Usado internamente pelo ATL.  
  
## <a name="remarks"></a>Comentários  
 [_ATL_COM_MODULE](atl-typedefs.md#_atl_com_module) é definido como um typedef de `_ATL_COM_MODULE70`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase. h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas](../../atl/reference/atl-structures.md)






