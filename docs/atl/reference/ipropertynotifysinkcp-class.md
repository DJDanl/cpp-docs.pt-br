---
title: Classe IPropertyNotifySinkCP | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- IPropertyNotifySinkCP
dev_langs:
- C++
helpviewer_keywords:
- connection points [C++], managing
- sinks, notifying of changes
- IPropertyNotifySinkCP class
ms.assetid: 1b41445e-bc88-4fa6-bb62-d68aacec2bd5
caps.latest.revision: 21
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
ms.sourcegitcommit: 5a0c6a1062330f952bb8fa52bc934f6754465513
ms.openlocfilehash: 7e741e557688829ff555a0b0cfe3581e77625c49
ms.lasthandoff: 02/25/2017

---
# <a name="ipropertynotifysinkcp-class"></a>Classe IPropertyNotifySinkCP
Essa classe expõe [IPropertyNotifySink](http://msdn.microsoft.com/library/windows/desktop/ms692638) interface como uma interface de saída em um objeto conectável.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class T, class CDV = CComDynamicUnkArray>  
class IPropertyNotifySinkCP 
   : public IConnectionPointImpl<T, &IID_IPropertyNotifySink, CDV>
```    
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Sua classe derivada de `IPropertyNotifySinkCP`.  
  
 `CDV`  
 Uma classe que gerencia as conexões entre um ponto de conexão e seus coletores. O valor padrão é [CComDynamicUnkArray](../../atl/reference/ccomdynamicunkarray-class.md), que permite conexões ilimitadas. Você também pode usar [CComUnkArray](../../atl/reference/ccomunkarray-class.md), que especifica um número fixo de conexões.  
  
## <a name="remarks"></a>Comentários  
 `IPropertyNotifySinkCP`herda todos os métodos por meio de sua classe base, [IConnectionPointImpl](../../atl/reference/iconnectionpointimpl-class.md).  
  
 O [IPropertyNotifySink](http://msdn.microsoft.com/library/windows/desktop/ms692638) interface permite que um objeto de coletor para receber notificações sobre alterações de propriedade. Classe `IPropertyNotifySinkCP` expõe essa interface como uma interface de saída em um objeto conectável. O cliente deve implementar o `IPropertyNotifySink` métodos no coletor.  
  
 Derive a classe de `IPropertyNotifySinkCP` quando você deseja criar um ponto de conexão que representa o `IPropertyNotifySink` interface.  
  
 Para obter mais informações sobre como usar pontos de conexão de ATL, consulte o artigo [pontos de Conexão](../../atl/atl-connection-points.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlctl.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe IConnectionPointImpl](../../atl/reference/iconnectionpointimpl-class.md)   
 [Classe IConnectionPointContainerImpl](../../atl/reference/iconnectionpointcontainerimpl-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

