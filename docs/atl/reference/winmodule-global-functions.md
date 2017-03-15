---
title: "Funções globais WinModule | Documentos do Microsoft"
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
ms.assetid: 8ce45a5b-26a7-491f-9096-c09ceca5f2c2
caps.latest.revision: 19
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
ms.openlocfilehash: c477f4500bd4fe78f21f04c58b02d1b493f72c01
ms.lasthandoff: 02/25/2017

---
# <a name="winmodule-global-functions"></a>Funções globais WinModule
Essas funções fornecem suporte para `_AtlCreateWndData` operações de estrutura.  
  
> [!IMPORTANT]
>  As funções listadas na tabela a seguir não podem ser usadas em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
|||  
|-|-|  
|[AtlWinModuleAddCreateWndData](#atlwinmoduleaddcreatewnddata)|Essa função é usada para inicializar e adicionar uma estrutura `_AtlCreateWndData`.|  
|[AtlWinModuleExtractCreateWndData](#atlwinmoduleextractcreatewnddata)|Chame essa função para extrair uma estrutura `_AtlCreateWndData` existente.|  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase. h  
  `            
##  <a name="a-nameatlwinmoduleaddcreatewnddataa--atlwinmoduleaddcreatewnddata"></a><a name="atlwinmoduleaddcreatewnddata"></a>AtlWinModuleAddCreateWndData  
 Essa função é usada para inicializar e adicionar uma estrutura `_AtlCreateWndData`.  
   
```
ATLINLINE ATLAPI_(void) AtlWinModuleAddCreateWndData(
    _ATL_WIN_MODULE* pWinModule,
    _AtlCreateWndData* pData,
    void* pObject);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pWinModule`  
 Ponteiro para um módulo [_ATL_WIN_MODULE70](../../atl/reference/atl-win-module70-structure.md) estrutura.  
  
 `pData`  
 Ponteiro para o [_AtlCreateWndData](../../atl/reference/atlcreatewnddata-structure.md) estrutura a ser inicializado e adicionados ao módulo atual.  
  
 `pObject`  
 Ponteiro para um objeto **isso** ponteiro.  
  
### <a name="remarks"></a>Comentários  
 Inicializa uma `_AtlCreateWndData` estrutura, que é usada para armazenar o **isso** ponteiro usado para se referir às instâncias de classe e o adiciona à lista referenciada por um módulo `_ATL_WIN_MODULE70` estrutura. Chamado por [CAtlWinModule::AddCreateWndData](catlwinmodule-class.md#addcreatewnddata).  
  
##  <a name="a-nameatlwinmoduleextractcreatewnddataa--atlwinmoduleextractcreatewnddata"></a><a name="atlwinmoduleextractcreatewnddata"></a>AtlWinModuleExtractCreateWndData  
 Chame essa função para extrair uma estrutura `_AtlCreateWndData` existente.  
 
```
ATLINLINE ATLAPI_(void*) AtlWinModuleExtractCreateWndData(_ATL_WIN_MODULE* pWinModule);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pWinModule`  
 Ponteiro para um módulo [_ATL_WIN_MODULE70](../../atl/reference/atl-win-module70-structure.md) estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para o [_AtlCreateWndData](../../atl/reference/atlcreatewnddata-structure.md) estrutura.  
  
### <a name="remarks"></a>Comentários  
 Essa função extrairá existente `_AtlCreateWndData` estrutura da lista referenciada por um módulo `_ATL_WIN_MODULE70` estrutura.  
  
## <a name="see-also"></a>Consulte também  
 [Funções](../../atl/reference/atl-functions.md)

