---
title: Classe IConnectionPointContainerImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- IConnectionPointContainerImpl
- ATLCOM/ATL::IConnectionPointContainerImpl
- ATLCOM/ATL::IConnectionPointContainerImpl::EnumConnectionPoints
- ATLCOM/ATL::IConnectionPointContainerImpl::FindConnectionPoint
dev_langs:
- C++
helpviewer_keywords:
- connectable objects
- connection points [C++], container
- IConnectionPointContainerImpl class
ms.assetid: 10db5a8d-8be9-4d9d-8a82-8ab9ffe3e9d6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d70989be8e8535336c831cb59fb9422c6e2c63e0
ms.sourcegitcommit: 7d68f8303e021e27dc8f4d36e764ed836e93d24f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/06/2018
ms.locfileid: "37886226"
---
# <a name="iconnectionpointcontainerimpl-class"></a>Classe IConnectionPointContainerImpl
Essa classe implementa um contêiner de ponto de conexão para gerenciar uma coleção de [IConnectionPointImpl](../../atl/reference/iconnectionpointimpl-class.md) objetos.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class T>  
class ATL_NO_VTABLE IConnectionPointContainerImpl 
   : public IConnectionPointContainer
```  
  
#### <a name="parameters"></a>Parâmetros  
 *T*  
 Sua classe, derivada de `IConnectionPointContainerImpl`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IConnectionPointContainerImpl::EnumConnectionPoints](#enumconnectionpoints)|Cria um enumerador para iterar por meio de pontos de conexão com suporte no objeto conectável.|  
|[IConnectionPointContainerImpl::FindConnectionPoint](#findconnectionpoint)|Recupera um ponteiro de interface para o ponto de conexão que oferece suporte a IID especificada.|  
  
## <a name="remarks"></a>Comentários  
 `IConnectionPointContainerImpl` implementa um contêiner de ponto de conexão para gerenciar uma coleção de [IConnectionPointImpl](../../atl/reference/iconnectionpointimpl-class.md) objetos. `IConnectionPointContainerImpl` fornece dois métodos que um cliente pode chamar para recuperar mais informações sobre um objeto conectável:  
  
- `EnumConnectionPoints` permite que o cliente para determinar qual saída interfaces o oferece suporte ao objeto.  
  
- `FindConnectionPoint` permite que o cliente para determinar se o objeto dá suporte a uma interface de saída específica.  
  
 Para obter informações sobre como usar pontos de conexão no ATL, consulte o artigo [pontos de Conexão](../../atl/atl-connection-points.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IConnectionPointContainer`  
  
 `IConnectionPointContainerImpl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom  
  
##  <a name="enumconnectionpoints"></a>  IConnectionPointContainerImpl::EnumConnectionPoints  
 Cria um enumerador para iterar por meio de pontos de conexão com suporte no objeto conectável.  
  
```
STDMETHOD(EnumConnectionPoints)(IEnumConnectionPoints** ppEnum);
```  
  
### <a name="remarks"></a>Comentários  
 Ver [IConnectionPointContainer::EnumConnectionPoints](http://msdn.microsoft.com/library/windows/desktop/ms682460) no Windows SDK.  
  
##  <a name="findconnectionpoint"></a>  IConnectionPointContainerImpl::FindConnectionPoint  
 Recupera um ponteiro de interface para o ponto de conexão que oferece suporte a IID especificada.  
  
```
STDMETHOD(FindConnectionPoint)(REFIID riid, IConnectionPoint** ppCP);
```  
  
### <a name="remarks"></a>Comentários  
 Ver [IConnectionPointContainer::FindConnectionPoint](http://msdn.microsoft.com/library/windows/desktop/ms692476) no Windows SDK.  
  
## <a name="see-also"></a>Consulte também  
 [IConnectionPointContainer](http://msdn.microsoft.com/library/windows/desktop/ms683857)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
