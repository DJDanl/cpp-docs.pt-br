---
title: Classe CAtlAutoThreadModule | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CAtlAutoThreadModule
- atlbase/ATL::CAtlAutoThreadModule
dev_langs: C++
helpviewer_keywords: CAtlAutoThreadModule class
ms.assetid: 3be834aa-55ef-403e-94ae-41979691b15f
caps.latest.revision: "19"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: ceff548fe53ff317eaca432a5e0c223cdc0a4e6d
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="catlautothreadmodule-class"></a>Classe CAtlAutoThreadModule
Essa classe implementa um servidor de pool de thread, o modelo de apartment COM.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CAtlAutoThreadModule : public CAtlAutoThreadModuleT<CAtlAutoThreadModule>
```  
  
## <a name="remarks"></a>Comentários  
 `CAtlAutoThreadModule`deriva [CAtlAutoThreadModuleT](../../atl/reference/catlautothreadmodulet-class.md) e implementa um servidor de pool de thread, o modelo de apartment COM. `CAtlAutoThreadModule`usa [CComApartment](../../atl/reference/ccomapartment-class.md) para gerenciar um compartimento para cada thread no módulo.  
  
 Você deve usar o [DECLARE_CLASSFACTORY_AUTO_THREAD](aggregation-and-class-factory-macros.md#declare_classfactory_auto_thread) macro na definição de classe do objeto para especificar [CComClassFactoryAutoThread](../../atl/reference/ccomclassfactoryautothread-class.md) como a fábrica de classes. Em seguida, você deve adicionar uma única instância de uma classe derivada de `CAtlAutoThreadModuleT` como `CAtlAutoThreadModule`. Por exemplo:  
  
 `CAtlAutoThreadModule _AtlAutoModule; // name is immaterial.`  
  
> [!NOTE]
>  Esta classe substitui o obsoleto [CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md) classe.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IAtlAutoThreadModule`  
  
 [CAtlAutoThreadModuleT](../../atl/reference/catlautothreadmodulet-class.md)  
  
 `CAtlAutoThreadModule`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase  
  
## <a name="see-also"></a>Consulte também  
 [Classe CAtlAutoThreadModuleT](../../atl/reference/catlautothreadmodulet-class.md)   
 [Classe IAtlAutoThreadModule](../../atl/reference/iatlautothreadmodule-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)   
 [Classes de módulo](../../atl/atl-module-classes.md)
