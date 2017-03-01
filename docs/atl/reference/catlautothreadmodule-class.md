---
title: Classe CAtlAutoThreadModule | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL.CAtlAutoThreadModule
- CAtlAutoThreadModule
- ATL::CAtlAutoThreadModule
dev_langs:
- C++
helpviewer_keywords:
- CAtlAutoThreadModule class
ms.assetid: 3be834aa-55ef-403e-94ae-41979691b15f
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
ms.sourcegitcommit: 5a0c6a1062330f952bb8fa52bc934f6754465513
ms.openlocfilehash: 09f4a7061ce1e4a09d0d27bd90dfcc16a37f4d5b
ms.lasthandoff: 02/25/2017

---
# <a name="catlautothreadmodule-class"></a>Classe CAtlAutoThreadModule
Essa classe implementa um servidor COM pool de thread, o modelo de apartment.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CAtlAutoThreadModule : public CAtlAutoThreadModuleT<CAtlAutoThreadModule>
```  
  
## <a name="remarks"></a>Comentários  
 `CAtlAutoThreadModule`deriva de [CAtlAutoThreadModuleT](../../atl/reference/catlautothreadmodulet-class.md) e implementa um servidor COM pool de thread, o modelo de apartment. `CAtlAutoThreadModule`usa [CComApartment](../../atl/reference/ccomapartment-class.md) para gerenciar um apartamento para cada thread no módulo.  
  
 Você deve usar o [DECLARE_CLASSFACTORY_AUTO_THREAD](http://msdn.microsoft.com/library/19d7105e-03e8-4412-9f5e-5384c8a5e18f) macro na definição de classe do objeto para especificar [CComClassFactoryAutoThread](../../atl/reference/ccomclassfactoryautothread-class.md) como a fábrica de classes. Você deve adicionar uma única instância de uma classe derivada de `CAtlAutoThreadModuleT` como `CAtlAutoThreadModule`. Por exemplo:  
  
 `CAtlAutoThreadModule _AtlAutoModule; // name is immaterial.`  
  
> [!NOTE]
>  Esta classe substitui o obsoleto [CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md) classe.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IAtlAutoThreadModule`  
  
 [CAtlAutoThreadModuleT](../../atl/reference/catlautothreadmodulet-class.md)  
  
 `CAtlAutoThreadModule`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase. h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CAtlAutoThreadModuleT](../../atl/reference/catlautothreadmodulet-class.md)   
 [Classe IAtlAutoThreadModule](../../atl/reference/iatlautothreadmodule-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)   
 [Classes de módulo](../../atl/atl-module-classes.md)
