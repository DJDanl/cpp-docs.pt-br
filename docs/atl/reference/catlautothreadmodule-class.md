---
title: Classe CAtlAutoThreadModule
ms.date: 11/04/2016
f1_keywords:
- CAtlAutoThreadModule
- atlbase/ATL::CAtlAutoThreadModule
helpviewer_keywords:
- CAtlAutoThreadModule class
ms.assetid: 3be834aa-55ef-403e-94ae-41979691b15f
ms.openlocfilehash: acd277160bc277e919a2802541310aa55446e00c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50619703"
---
# <a name="catlautothreadmodule-class"></a>Classe CAtlAutoThreadModule

Essa classe implementa um servidor COM em pool de thread, o modelo de apartment.

> [!IMPORTANT]
> Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class CAtlAutoThreadModule : public CAtlAutoThreadModuleT<CAtlAutoThreadModule>
```

## <a name="remarks"></a>Comentários

`CAtlAutoThreadModule` deriva [CAtlAutoThreadModuleT](../../atl/reference/catlautothreadmodulet-class.md) e implementa um servidor COM em pool de thread, o modelo de apartment. `CAtlAutoThreadModule` usa [CComApartment](../../atl/reference/ccomapartment-class.md) para gerenciar um apartment para cada thread no módulo.

Você deve usar o [DECLARE_CLASSFACTORY_AUTO_THREAD](aggregation-and-class-factory-macros.md#declare_classfactory_auto_thread) macro na definição de classe do objeto para especificar [CComClassFactoryAutoThread](../../atl/reference/ccomclassfactoryautothread-class.md) como a fábrica de classes. Em seguida, você deve adicionar uma única instância de uma classe derivada de `CAtlAutoThreadModuleT` como `CAtlAutoThreadModule`. Por exemplo:

`CAtlAutoThreadModule _AtlAutoModule; // name is immaterial.`

> [!NOTE]
> Essa classe substitui o obsoletos [CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md) classe.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IAtlAutoThreadModule`

[CAtlAutoThreadModuleT](../../atl/reference/catlautothreadmodulet-class.md)

`CAtlAutoThreadModule`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

## <a name="see-also"></a>Consulte também

[Classe CAtlAutoThreadModuleT](../../atl/reference/catlautothreadmodulet-class.md)<br/>
[Classe de IAtlAutoThreadModule](../../atl/reference/iatlautothreadmodule-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classes de módulo](../../atl/atl-module-classes.md)
