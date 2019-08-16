---
title: Conceitos básicos de objetos COM ATL
ms.date: 11/19/2018
helpviewer_keywords:
- COM, and ATL
- ATL, COM
- ATL COM objects
- COM objects, ATL
ms.assetid: 0f9c9d98-cc28-45da-89ac-dc94cee422fe
ms.openlocfilehash: ec83539b2d7101c534bbc1df33577df422e76152
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69492361"
---
# <a name="fundamentals-of-atl-com-objects"></a>Conceitos básicos de objetos COM ATL

A ilustração a seguir descreve a relação entre as classes e interfaces que são usadas para definir um objeto COM ATL.

![Estrutura de ATL](../atl/media/vc307y1.gif "Estrutura de ATL")

> [!NOTE]
>  Este diagrama mostra que `CComObject` é derivado de `CYourClass` enquanto `CComAggObject` e `CComPolyObject` inclui `CYourClass` como uma variável de membro.

Há três maneiras de definir um objeto COM ATL. A opção padrão é usar a `CComObject` classe derivada de. `CYourClass` A segunda opção é criar um objeto agregado usando a `CComAggObject` classe. A terceira opção é usar a `CComPolyObject` classe. `CComPolyObject`atua como um híbrido: ele pode funcionar como uma `CComObject` classe ou como uma `CComAggObject` classe, dependendo de como ele é criado pela primeira vez. Para obter mais informações sobre como usar a `CComPolyObject` classe, consulte [classe CComPolyObject](../atl/reference/ccompolyobject-class.md).

Ao usar COM ATL padrão, você usa dois objetos: um objeto externo e um objeto interno. Os clientes externos acessam a funcionalidade do objeto interno por meio das funções de wrapper definidas no objeto externo. O objeto externo é do tipo `CComObject`.

Quando você usa um objeto agregado, o objeto externo não fornece wrappers para a funcionalidade do objeto interno. Em vez disso, o objeto externo fornece um ponteiro que é acessado diretamente por clientes externos. Nesse cenário, o objeto externo é do tipo `CComAggObject`. O objeto interno é uma variável de membro do objeto externo e é do tipo `CYourClass`.

Como o cliente não precisa passar pelo objeto externo para interagir com o objeto interno, os objetos agregados são geralmente mais eficientes. Além disso, o objeto externo não precisa saber a funcionalidade do objeto agregado, uma vez que a interface do objeto agregado está diretamente disponível para o cliente. No entanto, nem todos os objetos podem ser agregados. Para que um objeto seja agregado, ele precisa ser projetado com a agregação em mente.

A ATL implementa [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) em duas fases:

- [CComObject](../atl/reference/ccomobject-class.md), [CComAggObject](../atl/reference/ccomaggobject-class.md)ou [CComPolyObject](../atl/reference/ccompolyobject-class.md) implementa os `IUnknown` métodos.

- [CComObjectRoot](../atl/reference/ccomobjectroot-class.md) ou [CComObjectRootEx](../atl/reference/ccomobjectrootex-class.md) gerencia a contagem de referência e os ponteiros externos do `IUnknown`.

Outros aspectos do seu objeto COM ATL são tratados por outras classes:

- [CComCoClass](../atl/reference/ccomcoclass-class.md) define a fábrica de classes padrão do objeto e o modelo de agregação.

- O [IDispatchImpl](../atl/reference/idispatchimpl-class.md) fornece uma implementação padrão da `IDispatch Interface` parte de qualquer interface dupla no objeto.

- O [ISupportErrorInfoImpl](../atl/reference/isupporterrorinfoimpl-class.md) implementa `ISupportErrorInfo` a interface que garante que as informações de erro possam ser propagadas corretamente na cadeia de chamadas.

## <a name="in-this-section"></a>Nesta seção

[Implementando CComObjectRootEx](../atl/implementing-ccomobjectrootex.md)<br/>
Mostrar exemplos de entradas de mapa COM `CComObjectRootEx`para implementação.

[Implementando CComObject, CComAggObject e CComPolyObject](../atl/implementing-ccomobject-ccomaggobject-and-ccompolyobject.md)<br/>
Discute como as macros **DECLARE_\*_AGGREGATABLE** afetam o uso de `CComObject`, `CComAggObject`e `CComPolyObject`.

[Suporte a IDispatch e IErrorInfo](../atl/supporting-idispatch-and-ierrorinfo.md)<br/>
Lista as classes de implementação de ATL a serem usadas `IDispatch` para `IErrorInfo` dar suporte às interfaces e.

[Suporte a IDispEventImpl](../atl/supporting-idispeventimpl.md)<br/>
Discute as etapas para implementar um ponto de conexão para sua classe.

[Alterando a fábrica de classes padrão e o modelo de agregação](../atl/changing-the-default-class-factory-and-aggregation-model.md)<br/>
Mostre as macros a serem usadas para alterar a fábrica de classes padrão e o modelo de agregação.

[Criando um objeto agregado](../atl/creating-an-aggregated-object.md)<br/>
Lista as etapas para criar um objeto agregado.

## <a name="related-sections"></a>Seções relacionadas

[Criando um projeto ATL](../atl/reference/creating-an-atl-project.md)<br/>
Fornece informações sobre como criar um objeto COM ATL.

[ATL](../atl/active-template-library-atl-concepts.md)<br/>
Fornece links para tópicos conceituais sobre como programar usando o Active Template Library.

## <a name="see-also"></a>Consulte também

[Conceitos](../atl/active-template-library-atl-concepts.md)
