---
title: "Macros de ponto de Conexão | Documentos do Microsoft"
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
- connection points [C++], macros
ms.assetid: cc3a6dd3-5538-45df-b027-1f34963c31e5
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
ms.sourcegitcommit: 8cdedc5cfac9d49df812ae6fcfcc548201b1edb5
ms.openlocfilehash: c16b6f2f889745270a51a32a1449add86dec6ecb
ms.lasthandoff: 02/25/2017

---
# <a name="connection-point-macros"></a>Macros de ponto de Conexão
Essas macros definem entradas e mapas de ponto de conexão.  
  
|||  
|-|-|  
|[BEGIN_CONNECTION_POINT_MAP](#begin_connection_point_map)|Marca o início das entradas de mapa de ponto de conexão.|  
|[CONNECTION_POINT_ENTRY](#connection_point_entry)|Insere os pontos de conexão no mapa.|  
|[CONNECTION_POINT_ENTRY_P](#connection_point_entry)| (2017 do visual Studio) Semelhante ao CONNECTION_POINT_ENTRY mas leva um ponteiro a iid.|
|[END_CONNECTION_POINT_MAP](#end_connection_point_map)|Marca o final das entradas de mapa de ponto de conexão.|  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h 
   
##  <a name="a-namebeginconnectionpointmapa--beginconnectionpointmap"></a><a name="begin_connection_point_map"></a>BEGIN_CONNECTION_POINT_MAP  
 Marca o início das entradas de mapa de ponto de conexão.  
  
```
BEGIN_CONNECTION_POINT_MAP(x)
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 [in] O nome da classe que contém os pontos de conexão.  
  
### <a name="remarks"></a>Comentários  
 Iniciar o mapa de ponto de conexão com o `BEGIN_CONNECTION_POINT_MAP` macro, adicione entradas para cada um dos seus pontos de conexão com o [CONNECTION_POINT_ENTRY](#connection_point_entry) macro e conclua o mapa com o [END_CONNECTION_POINT_MAP](#end_connection_point_map) macro.  
  
 Para obter mais informações sobre pontos de conexão de ATL, consulte o artigo [pontos de Conexão](../../atl/atl-connection-points.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing&#101;](../../atl/codesnippet/cpp/connection-point-macros_1.h)]  
  
##  <a name="a-nameconnectionpointentrya--connectionpointentry-and-connectionpointentryp"></a><a name="connection_point_entry"></a>CONNECTION_POINT_ENTRY e CONNECTION_POINT_ENTRY_P  
 Insere um ponto de conexão para a interface especificada para o mapa de ponto de conexão para que ele possa ser acessado.  
  
```
CONNECTION_POINT_ENTRY(iid)
CONNECTION_POINT_ENTRY_P(piid) // (Visual Studio 2017)
```  
  
### <a name="parameters"></a>Parâmetros  
 `iid`  
 [in] O GUID da interface que está sendo adicionado ao mapa de ponto de conexão. 
 
 `piid`  
 [in] Ponteiro para o GUID da interface que está sendo adde.   
  
### <a name="remarks"></a>Comentários  
 Entradas de ponto de Conexão no mapa são usadas pelo [IConnectionPointContainerImpl](../../atl/reference/iconnectionpointcontainerimpl-class.md). A classe que contém o mapa de ponto de conexão deve herdar de `IConnectionPointContainerImpl`.  
  
 Iniciar o mapa de ponto de conexão com o [BEGIN_CONNECTION_POINT_MAP](#begin_connection_point_map) macro, adicione entradas para cada um dos seus pontos de conexão com o `CONNECTION_POINT_ENTRY` macro e conclua o mapa com o [END_CONNECTION_POINT_MAP](#end_connection_point_map) macro.  
  
 Para obter mais informações sobre pontos de conexão de ATL, consulte o artigo [pontos de Conexão](../../atl/atl-connection-points.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing&#120;](../../atl/codesnippet/cpp/connection-point-macros_2.h)]  
  
##  <a name="a-nameendconnectionpointmapa--endconnectionpointmap"></a><a name="end_connection_point_map"></a>END_CONNECTION_POINT_MAP  
 Marca o final das entradas de mapa de ponto de conexão.  
  
```
END_CONNECTION_POINT_MAP()
```  
  
### <a name="remarks"></a>Comentários  
 Iniciar o mapa de ponto de conexão com o [BEGIN_CONNECTION_POINT_MAP](#begin_connection_point_map) macro, adicione entradas para cada um dos seus pontos de conexão com o [CONNECTION_POINT_ENTRY](#connection_point_entry) macro e conclua o mapa com o `END_CONNECTION_POINT_MAP` macro.  
  
 Para obter mais informações sobre pontos de conexão de ATL, consulte o artigo [pontos de Conexão](../../atl/atl-connection-points.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing&#128;](../../atl/codesnippet/cpp/connection-point-macros_3.h)]  
  
## <a name="see-also"></a>Consulte também  
 [Macros](../../atl/reference/atl-macros.md)   
 [Funções globais de ponto de Conexão](../../atl/reference/connection-point-global-functions.md)

