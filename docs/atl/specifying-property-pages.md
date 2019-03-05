---
title: Especificando páginas de propriedades (ATL)
ms.date: 11/04/2016
f1_keywords:
- ISpecifyPropertyPages
helpviewer_keywords:
- ISpecifyPropertyPages method
- property pages, specifying
ms.assetid: ee8678cf-c708-49ab-b0ad-fc2db31f1ac3
ms.openlocfilehash: d738759dfba50f26b788ee1b0761baf8bc4b00ab
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57287118"
---
# <a name="specifying-property-pages"></a>Especificando páginas de propriedades

Quando você cria um controle ActiveX, muitas vezes você desejará associá-la com páginas de propriedades que podem ser usadas para definir as propriedades de seu controle. Controlar o uso de contêineres a `ISpecifyPropertyPages` interface para descobrir quais páginas de propriedade podem ser usadas para definir as propriedades do controle. Você precisará implementar essa interface em seu controle.

Para implementar `ISpecifyPropertyPages` usando ATL, execute as seguintes etapas:

1. Derive sua classe de [ISpecifyPropertyPagesImpl](../atl/reference/ispecifypropertypagesimpl-class.md).

1. Adicione uma entrada para `ISpecifyPropertyPages` ao mapa de COM da sua classe.

1. Adicionar um [PROP_PAGE](reference/property-map-macros.md#prop_page) entrada no mapa de propriedade para cada página associada ao seu controle.

> [!NOTE]
> Ao gerar um controle padrão usando o [Assistente de controle ATL](../atl/reference/atl-control-wizard.md), você só precisará adicionar as entradas PROP_PAGE ao mapa de propriedade. O assistente gera o código necessário para as outras etapas.

Contêineres com bom comportamento exibirá as páginas de propriedade especificada na mesma ordem que as entradas PROP_PAGE no mapa de propriedade. Em geral, você deve colocar as entradas de página de propriedade padrão após as entradas para suas páginas personalizadas no mapa de propriedade, para que os usuários veem as páginas específicas para seu controle pela primeira vez.

## <a name="example"></a>Exemplo

A classe a seguir para um calendário de controle usa o `ISpecifyPropertyPages` interface para informar os contêineres que suas propriedades podem ser definidas usando uma página personalizado de data e a página de cotações de cor.

[!code-cpp[NVC_ATL_Windowing#72](../atl/codesnippet/cpp/specifying-property-pages_1.h)]

## <a name="see-also"></a>Consulte também

[Páginas de propriedade](../atl/atl-com-property-pages.md)<br/>
[Exemplo de ATLPages](../visual-cpp-samples.md)
