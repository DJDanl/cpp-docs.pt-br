---
title: "Funções globais COM mapa | Microsoft Docs"
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
helpviewer_keywords:
- COM interfaces, COM map global functions
ms.assetid: b9612d30-eb23-46ef-8093-d56f237d3cf1
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
ms.sourcegitcommit: d2d39abf526a58b8442107b5ee816f316ae841f5
ms.openlocfilehash: d6f23de1a5fd13d61d376acded35f9217d0a898d
ms.lasthandoff: 03/31/2017

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
 [!code-cpp[NVC_ATL_Windowing #94](../../atl/codesnippet/cpp/com-map-global-functions_1.cpp)]  
  
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

