---
title: Classe IPropertyNotifySinkCP | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- IPropertyNotifySinkCP
- atlctl/ATL::IPropertyNotifySinkCP
dev_langs:
- C++
helpviewer_keywords:
- connection points [C++], managing
- sinks, notifying of changes
- IPropertyNotifySinkCP class
ms.assetid: 1b41445e-bc88-4fa6-bb62-d68aacec2bd5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 66fd7b267a70b962bb5c28bb5835bd96d44a92f0
ms.sourcegitcommit: 7d68f8303e021e27dc8f4d36e764ed836e93d24f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/06/2018
ms.locfileid: "37879183"
---
# <a name="ipropertynotifysinkcp-class"></a>Classe IPropertyNotifySinkCP
Essa classe expõe [IPropertyNotifySink](http://msdn.microsoft.com/library/windows/desktop/ms692638) interface como uma interface de saída em um objeto conectável.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class T, class CDV = CComDynamicUnkArray>  
class IPropertyNotifySinkCP 
   : public IConnectionPointImpl<T, &IID_IPropertyNotifySink, CDV>
```    
  
#### <a name="parameters"></a>Parâmetros  
 *T*  
 Sua classe, derivada de `IPropertyNotifySinkCP`.  
  
 *CDV*  
 Uma classe que gerencia as conexões entre um ponto de conexão e seus coletores. O valor padrão é [CComDynamicUnkArray](../../atl/reference/ccomdynamicunkarray-class.md), que permite conexões ilimitadas. Você também pode usar [CComUnkArray](../../atl/reference/ccomunkarray-class.md), que especifica um número fixo de conexões.  
  
## <a name="remarks"></a>Comentários  
 `IPropertyNotifySinkCP` herda todos os métodos por meio de sua classe base, [IConnectionPointImpl](../../atl/reference/iconnectionpointimpl-class.md).  
  
 O [IPropertyNotifySink](http://msdn.microsoft.com/library/windows/desktop/ms692638) interface permite que um objeto de coletor para receber notificações sobre alterações de propriedade. Classe `IPropertyNotifySinkCP` expõe essa interface como uma interface de saída em um objeto conectável. O cliente deve implementar o `IPropertyNotifySink` métodos no coletor.  
  
 Derive sua classe de `IPropertyNotifySinkCP` quando você deseja criar um ponto de conexão que representa o `IPropertyNotifySink` interface.  
  
 Para obter mais informações sobre como usar pontos de conexão no ATL, consulte o artigo [pontos de Conexão](../../atl/atl-connection-points.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlctl.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe IConnectionPointImpl](../../atl/reference/iconnectionpointimpl-class.md)   
 [Classe IConnectionPointContainerImpl](../../atl/reference/iconnectionpointcontainerimpl-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
