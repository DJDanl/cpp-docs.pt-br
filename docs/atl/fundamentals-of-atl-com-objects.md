---
title: Fundamentos dos Objetos ATL COM
ms.date: 11/19/2018
helpviewer_keywords:
- COM, and ATL
- ATL, COM
- ATL COM objects
- COM objects, ATL
ms.assetid: 0f9c9d98-cc28-45da-89ac-dc94cee422fe
ms.openlocfilehash: 651413534ed44143e2a0fdaf00bdabd6e5d57010
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81319551"
---
# <a name="fundamentals-of-atl-com-objects"></a>Fundamentos dos Objetos ATL COM

A ilustração a seguir mostra a relação entre as classes e interfaces que são usadas para definir um objeto ATL COM.

![Estrutura ATL](../atl/media/vc307y1.gif "Estrutura ATL")

> [!NOTE]
> Este diagrama `CComObject` mostra que `CYourClass` é `CComAggObject` `CComPolyObject` derivado `CYourClass` do considerando que e incluem como uma variável membro.

Existem três maneiras de definir um objeto ATL COM. A opção padrão é `CComObject` usar a classe `CYourClass`derivada de . A segunda opção é criar um objeto `CComAggObject` agregado usando a classe. A terceira opção é `CComPolyObject` usar a classe. `CComPolyObject`atua como um híbrido: pode `CComObject` funcionar como `CComAggObject` uma classe ou como uma classe, dependendo de como ele é criado pela primeira vez. Para obter mais informações `CComPolyObject` sobre como usar a classe, consulte [CComPolyObject Class](../atl/reference/ccompolyobject-class.md).

Quando você usa o ATL COM padrão, você usa dois objetos: um objeto externo e um objeto interno. Os clientes externos acessam a funcionalidade do objeto interno através das funções do invólucro definidas no objeto externo. O objeto externo `CComObject`é do tipo .

Quando você usa um objeto agregado, o objeto externo não fornece invólucros para a funcionalidade do objeto interno. Em vez disso, o objeto externo fornece um ponteiro que é acessado diretamente por clientes externos. Neste cenário, o objeto externo `CComAggObject`é do tipo . O objeto interno é uma variável membro do objeto `CYourClass`externo, e é do tipo .

Como o cliente não precisa passar pelo objeto externo para interagir com o objeto interno, objetos agregados geralmente são mais eficientes. Além disso, o objeto externo não precisa conhecer a funcionalidade do objeto agregado, uma vez que a interface do objeto agregado está diretamente disponível para o cliente. No entanto, nem todos os objetos podem ser agregados. Para que um objeto seja agregado, ele precisa ser projetado com a agregação em mente.

AtL implementa [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) em duas fases:

- [CComObject,](../atl/reference/ccomobject-class.md) [CComAggObject](../atl/reference/ccomaggobject-class.md)ou [CComPolyObject](../atl/reference/ccompolyobject-class.md) `IUnknown` implementam os métodos.

- [CComObjectRoot](../atl/reference/ccomobjectroot-class.md) ou [CComObjectRootEx](../atl/reference/ccomobjectrootex-class.md) gerencia a contagem `IUnknown`de referênciae ponteiros externos de .

Outros aspectos do objeto ATL COM são tratados por outras classes:

- [O CComCoClass](../atl/reference/ccomcoclass-class.md) define o modelo de agregação e fábrica de classe padrão do objeto.

- [O IDispatchImpl](../atl/reference/idispatchimpl-class.md) fornece uma `IDispatch Interface` implementação padrão da parte de qualquer interface dupla no objeto.

- [O ISupportErrorInfoImpl](../atl/reference/isupporterrorinfoimpl-class.md) `ISupportErrorInfo` implementa a interface que garante que as informações de erro possam ser propagadas corretamente pela cadeia de chamadas.

## <a name="in-this-section"></a>Nesta seção

[Como implementar CComObjectRootEx](../atl/implementing-ccomobjectrootex.md)<br/>
Mostrar exemplo de entradas `CComObjectRootEx`de mapa COM para implementação .

[Implementar CComObject, CComAggObject e CComPolyObject](../atl/implementing-ccomobject-ccomaggobject-and-ccompolyobject.md)<br/>
Discute como as **macros\*_AGGREGATABLE DECLARE_** afetam o uso de `CComObject`, `CComAggObject`e `CComPolyObject`.

[Suporte a IDispatch e IErrorInfo](../atl/supporting-idispatch-and-ierrorinfo.md)<br/>
Lista as classes de implementação `IDispatch` atl a serem usados para suportar as interfaces e `IErrorInfo` interfaces.

[Suporte a IDispEventImpl](../atl/supporting-idispeventimpl.md)<br/>
Discute os passos para implementar um ponto de conexão para sua classe.

[Alterando o modelo de agregação e fábrica de classe padrão](../atl/changing-the-default-class-factory-and-aggregation-model.md)<br/>
Mostre quais macros usar para alterar o modelo de agregação e fábrica de classes padrão.

[Criando um objeto agregado](../atl/creating-an-aggregated-object.md)<br/>
Lista as etapas para criar um objeto agregado.

## <a name="related-sections"></a>Seções relacionadas

[Como criar um projeto da ATL](../atl/reference/creating-an-atl-project.md)<br/>
Fornece informações sobre a criação de um objeto ATL COM.

[ATL](../atl/active-template-library-atl-concepts.md)<br/>
Fornece links para tópicos conceituais sobre como programar usando o Active Template Library.

## <a name="see-also"></a>Confira também

[Conceitos](../atl/active-template-library-atl-concepts.md)
