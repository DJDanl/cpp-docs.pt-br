---
title: "Funções globais WinModule | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- atlbase/ATL::AtlWinModuleAddCreateWndData
- atlbase/ATL::AtlWinModuleExtractCreateWndData
dev_langs: C++
ms.assetid: 8ce45a5b-26a7-491f-9096-c09ceca5f2c2
caps.latest.revision: "19"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 290566c27fa5698c4a00a323a8c2431681b69d88
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="winmodule-global-functions"></a>Funções globais WinModule
Essas funções fornecem suporte para `_AtlCreateWndData` estrutura operações.  
  
> [!IMPORTANT]
>  As funções listadas na tabela a seguir não podem ser usadas em aplicativos que são executados o tempo de execução do Windows.  
  
|||  
|-|-|  
|[AtlWinModuleAddCreateWndData](#atlwinmoduleaddcreatewnddata)|Essa função é usada para inicializar e adicionar uma estrutura `_AtlCreateWndData`.|  
|[AtlWinModuleExtractCreateWndData](#atlwinmoduleextractcreatewnddata)|Chame essa função para extrair uma estrutura `_AtlCreateWndData` existente.|  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase  
  `            
##  <a name="atlwinmoduleaddcreatewnddata"></a>AtlWinModuleAddCreateWndData  
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
 Inicializa um `_AtlCreateWndData` estrutura, que é usada para armazenar o **isso** ponteiro usado para se referir às instâncias de classe e o adiciona à lista referenciada por um módulo `_ATL_WIN_MODULE70` estrutura. Chamado pelo [CAtlWinModule::AddCreateWndData](catlwinmodule-class.md#addcreatewnddata).  
  
##  <a name="atlwinmoduleextractcreatewnddata"></a>AtlWinModuleExtractCreateWndData  
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
 Essa função extrairá um existente `_AtlCreateWndData` estrutura da lista referenciada por um módulo `_ATL_WIN_MODULE70` estrutura.  
  
## <a name="see-also"></a>Consulte também  
 [Funções](../../atl/reference/atl-functions.md)
