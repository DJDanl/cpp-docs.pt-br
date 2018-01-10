---
title: "Funções globais COM mapa | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- atlbase/ATL::AtlInternalQueryInterface
- atlbase/ATL::InlineIsEqualIUnknown
dev_langs: C++
helpviewer_keywords: COM interfaces, COM map global functions
ms.assetid: b9612d30-eb23-46ef-8093-d56f237d3cf1
caps.latest.revision: "19"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: f7a0a02e46906ae8d3b6c62b8cc1b9147d396966
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="com-map-global-functions"></a>Funções globais COM mapa
Essas funções fornecem suporte para o mapa COM **IUnknown** implementações.  
  
|||  
|-|-|  
|[AtlInternalQueryInterface](#atlinternalqueryinterface)|Delega para o **IUnknown** de um objeto agregado.|  
|[InlineIsEqualIUnknown](#inlineisequaliunknown)|Gera código eficiente para comparação de interfaces contra **IUnknown**.|  

  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase  

##  <a name="atlinternalqueryinterface"></a>AtlInternalQueryInterface  
 Recupera um ponteiro para a interface solicitada.  
  
```
HRESULT AtlInternalQueryInterface(
    void* pThis,
    const _ATL_INTMAP_ENTRY* pEntries,
    REFIID iid,
    void** ppvObject);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pThis`  
 [in] Um ponteiro para o objeto que contém o mapa COM interfaces expostas a `QueryInterface`.  
  
 `pEntries`  
 [in] Uma matriz de **_ATL_INTMAP_ENTRY** estruturas que acessam um mapa das interfaces disponíveis.  
  
 `iid`  
 [in] O GUID da interface que está sendo solicitado.  
  
 `ppvObject`  
 [out] Um ponteiro para o ponteiro de interface especificado em `iid`, ou **nulo** se a interface não foi encontrada.  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos valores HRESULT padrão.  
  
### <a name="remarks"></a>Comentários  
 `AtlInternalQueryInterface` somente lida com interfaces na tabela de mapa COM. Se o objeto é agregado, `AtlInternalQueryInterface` não delegar a externo desconhecido. Você pode inserir interfaces na tabela de mapa COM a macro [COM_INTERFACE_ENTRY](com-interface-entry-macros.md#com_interface_entry) ou uma de suas variantes.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing#94](../../atl/codesnippet/cpp/com-map-global-functions_1.cpp)]  
  
##  <a name="inlineisequaliunknown"></a>InlineIsEqualIUnknown  
 Chamar essa função, no caso especial de testes para **IUnknown**.  
  
```
BOOL InlineIsEqualUnknown(REFGUID rguid1);
```  
  
### <a name="parameters"></a>Parâmetros  
 *rguid1*  
 [in] O GUID a ser comparado com **IID_IUnknown**.  
  
## <a name="see-also"></a>Consulte também  
 [Funções](../../atl/reference/atl-functions.md)   
 [Macros de mapa COM](../../atl/reference/com-map-macros.md)
