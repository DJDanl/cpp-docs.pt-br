---
title: Alterando a fábrica de classes padrão e o modelo de agregação | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 203aeae7dd2edb179ec3f9c1f56f989ffc09b35c
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46093006"
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

