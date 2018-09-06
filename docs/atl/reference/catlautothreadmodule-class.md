---
title: Classe CAtlAutoThreadModule | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CAtlAutoThreadModule
- atlbase/ATL::CAtlAutoThreadModule
dev_langs:
- C++
helpviewer_keywords:
- CAtlAutoThreadModule class
ms.assetid: 3be834aa-55ef-403e-94ae-41979691b15f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f7b782d7d53e5d97f08ebae62fc62d7a49c9f96d
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43763650"
---
# <a name="catlautothreadmodule-class"></a>Classe CAtlAutoThreadModule

Essa classe implementa um servidor COM em pool de thread, o modelo de apartment.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class CAtlAutoThreadModule : public CAtlAutoThreadModuleT<CAtlAutoThreadModule>
```

## <a name="remarks"></a>Comentários

`CAtlAutoThreadModule` deriva [CAtlAutoThreadModuleT](../../atl/reference/catlautothreadmodulet-class.md) e implementa um servidor COM em pool de thread, o modelo de apartment. `CAtlAutoThreadModule` usa [CComApartment](../../atl/reference/ccomapartment-class.md) para gerenciar um apartment para cada thread no módulo.

Você deve usar o [DECLARE_CLASSFACTORY_AUTO_THREAD](aggregation-and-class-factory-macros.md#declare_classfactory_auto_thread) macro na definição de classe do objeto para especificar [CComClassFactoryAutoThread](../../atl/reference/ccomclassfactoryautothread-class.md) como a fábrica de classes. Em seguida, você deve adicionar uma única instância de uma classe derivada de `CAtlAutoThreadModuleT` como `CAtlAutoThreadModule`. Por exemplo:

`CAtlAutoThreadModule _AtlAutoModule; // name is immaterial.`

> [!NOTE]
>  Essa classe substitui o obsoletos [CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md) classe.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IAtlAutoThreadModule`

[CAtlAutoThreadModuleT](../../atl/reference/catlautothreadmodulet-class.md)

`CAtlAutoThreadModule`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

## <a name="see-also"></a>Consulte também

[Classe CAtlAutoThreadModuleT](../../atl/reference/catlautothreadmodulet-class.md)   
[Classe de IAtlAutoThreadModule](../../atl/reference/iatlautothreadmodule-class.md)   
[Visão geral da classe](../../atl/atl-class-overview.md)   
[Classes de módulo](../../atl/atl-module-classes.md)
