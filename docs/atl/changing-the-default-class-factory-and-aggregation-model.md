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
ms.openlocfilehash: 1c97d8f63a441fab2b76c6e0509e4b3f384308ea
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87220880"
---
# <a name="changing-the-default-class-factory-and-aggregation-model"></a>Alterando a fábrica de classes padrão e o modelo de agregação

A ATL usa [CComCoClass](../atl/reference/ccomcoclass-class.md) para definir a fábrica de classes padrão e o modelo de agregação para seu objeto. `CComCoClass`Especifica as duas macros a seguir:

- [DECLARE_CLASSFACTORY](reference/aggregation-and-class-factory-macros.md#declare_classfactory) Declara a fábrica de classes a ser [CComClassFactory](../atl/reference/ccomclassfactory-class.md).

- [DECLARE_AGGREGATABLE](reference/aggregation-and-class-factory-macros.md#declare_aggregatable) Declara que o objeto pode ser agregado.

Você pode substituir qualquer um desses padrões especificando outra macro na definição de sua classe. Por exemplo, para usar [CComClassFactory2](../atl/reference/ccomclassfactory2-class.md) em vez de `CComClassFactory` , especifique a macro [DECLARE_CLASSFACTORY2](reference/aggregation-and-class-factory-macros.md#declare_classfactory2) :

[!code-cpp[NVC_ATL_COM#2](../atl/codesnippet/cpp/changing-the-default-class-factory-and-aggregation-model_1.h)]

Duas outras macros que definem uma fábrica de classes são [DECLARE_CLASSFACTORY_AUTO_THREAD](reference/aggregation-and-class-factory-macros.md#declare_classfactory_auto_thread) e [DECLARE_CLASSFACTORY_SINGLETON](reference/aggregation-and-class-factory-macros.md#declare_classfactory_singleton).

A ATL também usa o **`typedef`** mecanismo para implementar o comportamento padrão. Por exemplo, a macro DECLARE_AGGREGATABLE usa **`typedef`** para definir um tipo chamado `_CreatorClass` , que é então referenciado em toda a ATL. Observe que em uma classe derivada, um **`typedef`** usando o mesmo nome que os resultados da classe base **`typedef`** na ATL usando sua definição e substituindo o comportamento padrão.

## <a name="see-also"></a>Confira também

[Conceitos básicos de objetos COM ATL](../atl/fundamentals-of-atl-com-objects.md)<br/>
[Macros de agregação e classe de fábrica](../atl/reference/aggregation-and-class-factory-macros.md)
