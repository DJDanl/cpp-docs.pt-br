---
title: Macros de ponto de Conexão | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- atlcom/ATL::BEGIN_CONNECTION_POINT_MAP
- atlcom/ATL::END_CONNECTION_POINT_MAP
dev_langs:
- C++
helpviewer_keywords:
- connection points [C++], macros
ms.assetid: cc3a6dd3-5538-45df-b027-1f34963c31e5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 88789bef4bbcce3df99d90d736974377c9bca5fd
ms.sourcegitcommit: 7d68f8303e021e27dc8f4d36e764ed836e93d24f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/06/2018
ms.locfileid: "37882930"
---
# <a name="connection-point-macros"></a>Macros de ponto de Conexão
Essas macros definem entradas e mapas de ponto de conexão.  
  
|||  
|-|-|  
|[BEGIN_CONNECTION_POINT_MAP](#begin_connection_point_map)|Marca o início das entradas de mapa de ponto de conexão.|  
|[CONNECTION_POINT_ENTRY](#connection_point_entry)|Insere os pontos de conexão no mapa.|  
|[CONNECTION_POINT_ENTRY_P](#connection_point_entry)| (Visual Studio 2017) Semelhante ao CONNECTION_POINT_ENTRY, mas usa um ponteiro para o iid.|
|[END_CONNECTION_POINT_MAP](#end_connection_point_map)|Marca o fim das entradas de mapa de ponto de conexão.|  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom 
   
##  <a name="begin_connection_point_map"></a>  BEGIN_CONNECTION_POINT_MAP  
 Marca o início das entradas de mapa de ponto de conexão.  
  
```
BEGIN_CONNECTION_POINT_MAP(x)
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 [in] O nome da classe que contém os pontos de conexão.  
  
### <a name="remarks"></a>Comentários  
 Inicie seu mapa de ponto de conexão com a macro BEGIN_CONNECTION_POINT_MAP, adicione entradas para cada um dos seus pontos de conexão com o [CONNECTION_POINT_ENTRY](#connection_point_entry) macro e concluir o mapa com o [END_CONNECTION_ POINT_MAP](#end_connection_point_map) macro.  
  
 Para obter mais informações sobre pontos de conexão na ATL, consulte o artigo [pontos de Conexão](../../atl/atl-connection-points.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing#101](../../atl/codesnippet/cpp/connection-point-macros_1.h)]  
  
##  <a name="connection_point_entry"></a>  CONNECTION_POINT_ENTRY e CONNECTION_POINT_ENTRY_P  
 Insere um ponto de conexão para a interface especificada para o mapa de ponto de conexão para que ele possa ser acessado.  
  
```
CONNECTION_POINT_ENTRY(iid)
CONNECTION_POINT_ENTRY_P(piid) // (Visual Studio 2017)
```  
  
### <a name="parameters"></a>Parâmetros  
 *IID*  
 [in] O GUID da interface que está sendo adicionado ao mapa de ponto de conexão. 
 
 *piid*  
 [in] Ponteiro para o GUID da interface que está sendo adde.   
  
### <a name="remarks"></a>Comentários  
 Entradas de ponto de Conexão no mapa são usadas pelo [IConnectionPointContainerImpl](../../atl/reference/iconnectionpointcontainerimpl-class.md). A classe que contém o mapa de ponto de conexão deve herdar de `IConnectionPointContainerImpl`.  
  
 Inicie seu mapa de ponto de conexão com o [BEGIN_CONNECTION_POINT_MAP](#begin_connection_point_map) macro, adicione entradas para cada um dos seus pontos de conexão com a macro CONNECTION_POINT_ENTRY e concluir o mapa com o [END_CONNECTION_ POINT_MAP](#end_connection_point_map) macro.  
  
 Para obter mais informações sobre pontos de conexão na ATL, consulte o artigo [pontos de Conexão](../../atl/atl-connection-points.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing#120](../../atl/codesnippet/cpp/connection-point-macros_2.h)]  
  
##  <a name="end_connection_point_map"></a>  END_CONNECTION_POINT_MAP  
 Marca o fim das entradas de mapa de ponto de conexão.  
  
```
END_CONNECTION_POINT_MAP()
```  
  
### <a name="remarks"></a>Comentários  
 Inicie seu mapa de ponto de conexão com o [BEGIN_CONNECTION_POINT_MAP](#begin_connection_point_map) macro, adicione entradas para cada um dos seus pontos de conexão com o [CONNECTION_POINT_ENTRY](#connection_point_entry) macro e concluir o mapa com o END_ Macro CONNECTION_POINT_MAP.  
  
 Para obter mais informações sobre pontos de conexão na ATL, consulte o artigo [pontos de Conexão](../../atl/atl-connection-points.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing#128](../../atl/codesnippet/cpp/connection-point-macros_3.h)]  
  
## <a name="see-also"></a>Consulte também  
 [Macros](../../atl/reference/atl-macros.md)   
 [Funções globais de ponto de conexão](../../atl/reference/connection-point-global-functions.md)
