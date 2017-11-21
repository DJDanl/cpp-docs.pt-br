---
title: Classe IConnectionPointContainerImpl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- IConnectionPointContainerImpl
- ATLCOM/ATL::IConnectionPointContainerImpl
- ATLCOM/ATL::IConnectionPointContainerImpl::EnumConnectionPoints
- ATLCOM/ATL::IConnectionPointContainerImpl::FindConnectionPoint
dev_langs: C++
helpviewer_keywords:
- connectable objects
- connection points [C++], container
- IConnectionPointContainerImpl class
ms.assetid: 10db5a8d-8be9-4d9d-8a82-8ab9ffe3e9d6
caps.latest.revision: "19"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 8c76ded677c7aa49c9c9135d098b00f21f6d8098
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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
 `T`  
 A classe derivada de `IConnectionPointContainerImpl`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IConnectionPointContainerImpl::EnumConnectionPoints](#enumconnectionpoints)|Cria um enumerador para iterar por meio de pontos de conexão com suporte no objeto conectável.|  
|[IConnectionPointContainerImpl::FindConnectionPoint](#findconnectionpoint)|Recupera um ponteiro de interface para o ponto de conexão que oferece suporte a IID especificada.|  
  
## <a name="remarks"></a>Comentários  
 `IConnectionPointContainerImpl`implementa um contêiner de ponto de conexão para gerenciar uma coleção de [IConnectionPointImpl](../../atl/reference/iconnectionpointimpl-class.md) objetos. `IConnectionPointContainerImpl`fornece dois métodos que um cliente pode chamar para recuperar mais informações sobre um objeto conectável:  
  
- `EnumConnectionPoints`permite que o cliente determinar qual saída interfaces com suporte no objeto.  
  
- `FindConnectionPoint`permite que o cliente determinar se o objeto oferece suporte a uma interface de saída específica.  
  
 Para obter informações sobre como usar pontos de conexão de ATL, consulte o artigo [pontos de Conexão](../../atl/atl-connection-points.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IConnectionPointContainer`  
  
 `IConnectionPointContainerImpl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
  
##  <a name="enumconnectionpoints"></a>IConnectionPointContainerImpl::EnumConnectionPoints  
 Cria um enumerador para iterar por meio de pontos de conexão com suporte no objeto conectável.  
  
```
STDMETHOD(EnumConnectionPoints)(IEnumConnectionPoints** ppEnum);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IConnectionPointContainer::EnumConnectionPoints](http://msdn.microsoft.com/library/windows/desktop/ms682460) no SDK do Windows.  
  
##  <a name="findconnectionpoint"></a>IConnectionPointContainerImpl::FindConnectionPoint  
 Recupera um ponteiro de interface para o ponto de conexão que oferece suporte a IID especificada.  
  
```
STDMETHOD(FindConnectionPoint)(REFIID riid, IConnectionPoint** ppCP);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IConnectionPointContainer::FindConnectionPoint](http://msdn.microsoft.com/library/windows/desktop/ms692476) no SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [IConnectionPointContainer](http://msdn.microsoft.com/library/windows/desktop/ms683857)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
