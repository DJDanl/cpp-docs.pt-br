---
title: Conceitos básicos de objetos COM da ATL
ms.date: 11/19/2018
helpviewer_keywords:
- COM, and ATL
- ATL, COM
- ATL COM objects
- COM objects, ATL
ms.assetid: 0f9c9d98-cc28-45da-89ac-dc94cee422fe
ms.openlocfilehash: cba26ede01b69e4a077f1e842982adc8c2127331
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57270040"
---
# <a name="fundamentals-of-atl-com-objects"></a>Conceitos básicos de objetos COM da ATL

A ilustração a seguir descreve a relação entre as classes e interfaces que são usadas para definir um objeto COM ATL.

![Estrutura ATL](../atl/media/vc307y1.gif "estrutura ATL")

> [!NOTE]
>  Este diagrama mostra que `CComObject` deriva `CYourClass` , enquanto `CComAggObject` e `CComPolyObject` incluem `CYourClass` como uma variável de membro.

Há três maneiras de definir um objeto COM ATL. A opção padrão é usar o `CComObject` classe que é derivada de `CYourClass`. A segunda opção é criar um objeto agregado usando o `CComAggObject` classe. A terceira opção é usar o `CComPolyObject` classe. `CComPolyObject` atua como um híbrido: ele pode funcionar como uma `CComObject` classe ou como um `CComAggObject` classe, dependendo de como ele é criado pela primeira vez. Para obter mais informações sobre como usar o `CComPolyObject` classe, consulte [classe CComPolyObject](../atl/reference/ccompolyobject-class.md).

Quando você usa o padrão COM da ATL, é usar dois objetos: um objeto externo e um objeto interno. Clientes externos acessam a funcionalidade do objeto interno por meio de funções de invólucro são definidas no objeto externo. O objeto externo é do tipo `CComObject`.

Quando você usa um objeto agregado, o objeto externo não fornece wrappers para a funcionalidade do objeto interno. Em vez disso, o objeto externo fornece um ponteiro que é acessado diretamente por clientes externos. Nesse cenário, o objeto externo é do tipo `CComAggObject`. O objeto interno é uma variável de membro do objeto externo e é do tipo `CYourClass`.

Porque o cliente não precisa passar o objeto externo para interagir com o objeto interno, os objetos agregados são geralmente mais eficientes. Além disso, o objeto externo não precisa conhecer a funcionalidade do objeto agregado, considerando que a interface do objeto agregado está diretamente disponível para o cliente. No entanto, nem todos os objetos podem ser agregados. Para um objeto a ser agregada, ele precisa ser projetado com a agregação em mente.

Implementa ATL [IUnknown](/windows/desktop/api/unknwn/nn-unknwn-iunknown) em duas fases:

- [CComObject](../atl/reference/ccomobject-class.md), [CComAggObject](../atl/reference/ccomaggobject-class.md), ou [CComPolyObject](../atl/reference/ccompolyobject-class.md) implementa o `IUnknown` métodos.

- [CComObjectRoot](../atl/reference/ccomobjectroot-class.md) ou [CComObjectRootEx](../atl/reference/ccomobjectrootex-class.md) gerencia a contagem de referência e ponteiros externos de `IUnknown`.

Outros aspectos do seu objeto COM ATL são tratados por outras classes:

- [CComCoClass](../atl/reference/ccomcoclass-class.md) define o modelo de fábrica e agregação de classe de padrão do objeto.

- [IDispatchImpl](../atl/reference/idispatchimpl-class.md) fornece uma implementação padrão da `IDispatch Interface` parte de quaisquer interfaces duplas no objeto.

- [ISupportErrorInfoImpl](../atl/reference/isupporterrorinfoimpl-class.md) implementa o `ISupportErrorInfo` interface que garante que as informações de erro pode ser propagado corretamente a cadeia de chamada.

## <a name="in-this-section"></a>Nesta seção

[Implementando CComObjectRootEx](../atl/implementing-ccomobjectrootex.md)<br/>
Mostrar as entradas de mapa de COM para a implementação de exemplo `CComObjectRootEx`.

[Implementando CComObject, CComAggObject e CComPolyObject](../atl/implementing-ccomobject-ccomaggobject-and-ccompolyobject.md)<br/>
Discute como o **DECLARE_\*_AGGREGATABLE** macros afetam o uso do `CComObject`, `CComAggObject`, e `CComPolyObject`.

[Suporte a IDispatch e IErrorInfo](../atl/supporting-idispatch-and-ierrorinfo.md)<br/>
Lista as classes de implementação do ATL para usar para dar suporte à `IDispatch` e `IErrorInfo` interfaces.

[Suporte a IDispEventImpl](../atl/supporting-idispeventimpl.md)<br/>
Discute as etapas para implementar um ponto de conexão para a sua classe.

[Alterando a fábrica de classes padrão e o modelo de agregação](../atl/changing-the-default-class-factory-and-aggregation-model.md)<br/>
Mostre quais macros para usar para alterar o modelo de fábrica e agregação de classe padrão.

[Criando um objeto agregado](../atl/creating-an-aggregated-object.md)<br/>
Lista as etapas para a criação de um objeto agregado.

## <a name="related-sections"></a>Seções relacionadas

[Criando um projeto ATL](../atl/reference/creating-an-atl-project.md)<br/>
Fornece informações sobre como criar um objeto COM ATL.

[ATL](../atl/active-template-library-atl-concepts.md)<br/>
Fornece links para tópicos conceituais sobre como programar usando o Active Template Library.

## <a name="see-also"></a>Consulte também

[Conceitos](../atl/active-template-library-atl-concepts.md)
