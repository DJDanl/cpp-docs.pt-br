---
title: Alterando a fábrica de classes padrão e o modelo de agregação
ms.date: 11/04/2016
helpviewer_keywords:
- CComClassFactory class, making the default
- aggregation [C++], using ATL
- aggregation [C++], aggregation models
- defaults [C++], aggregation model in ATL
- default class factory
- class factories, changing default
- CComCoClass class, default class factory and aggregation model
- default class factory, ATL
- defaults [C++], class factory
ms.assetid: 6e040e95-0f38-4839-8a8b-c9800dd47e8c
ms.openlocfilehash: 94f9ecd85e09cb3916b518d71b904961042142e8
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57277372"
---
# <a name="changing-the-default-class-factory-and-aggregation-model"></a>Alterando a fábrica de classes padrão e o modelo de agregação

Usa o ATL [CComCoClass](../atl/reference/ccomcoclass-class.md) para definir o modelo padrão de fábrica e agregação de classe para seu objeto. `CComCoClass` Especifica as duas macros a seguir:

- [DECLARE_CLASSFACTORY](reference/aggregation-and-class-factory-macros.md#declare_classfactory) declara a fábrica de classes para ser [CComClassFactory](../atl/reference/ccomclassfactory-class.md).

- [DECLARE_AGGREGATABLE](reference/aggregation-and-class-factory-macros.md#declare_aggregatable) declara que o objeto pode ser agregado.

Você pode substituir qualquer um desses padrões especificando outra macro em sua definição de classe. Por exemplo, para usar [CComClassFactory2](../atl/reference/ccomclassfactory2-class.md) em vez de `CComClassFactory`, especifique o [DECLARE_CLASSFACTORY2](reference/aggregation-and-class-factory-macros.md#declare_classfactory2) macro:

[!code-cpp[NVC_ATL_COM#2](../atl/codesnippet/cpp/changing-the-default-class-factory-and-aggregation-model_1.h)]

Duas outras macros que definem uma fábrica de classes são [DECLARE_CLASSFACTORY_AUTO_THREAD](reference/aggregation-and-class-factory-macros.md#declare_classfactory_auto_thread) e [DECLARE_CLASSFACTORY_SINGLETON](reference/aggregation-and-class-factory-macros.md#declare_classfactory_singleton).

ATL também usa o **typedef** mecanismo para implementar o comportamento padrão. Por exemplo, usa a macro DECLARE_AGGREGATABLE **typedef** para definir um tipo chamado `_CreatorClass`, que é referenciado em todo o ATL. Observe que, em uma classe derivada, uma **typedef** usando o mesmo nome como a classe base **typedef** resulta em ATL usando sua definição e substituindo o comportamento padrão.

## <a name="see-also"></a>Consulte também

[Princípios básicos de objetos COM da ATL](../atl/fundamentals-of-atl-com-objects.md)<br/>
[Macros de fábrica de classes e agregação](../atl/reference/aggregation-and-class-factory-macros.md)
