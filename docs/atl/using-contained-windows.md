---
title: Usando janelas contidas
ms.date: 11/04/2016
helpviewer_keywords:
- ATL, windows
- windows [C++], ATL
- contained windows in ATL
ms.assetid: 7b3d79e5-b569-413f-9b98-df4f14efbe2b
ms.openlocfilehash: 5da765eae28d411c98e79af5b9173f48ea66ef8c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81329304"
---
# <a name="using-contained-windows"></a>Usando janelas contidas

Os implementos ATL continham janelas com [CContainedWindowT](../atl/reference/ccontainedwindowt-class.md). Uma janela contida representa uma janela que delega suas mensagens a um objeto de contêiner em vez de manuseá-las em sua própria classe.

> [!NOTE]
> Você não precisa obter uma `CContainedWindowT` classe de, a fim de usar janelas contidas.

Com janelas contidas, você pode superclassificar uma classe Windows existente ou subclasse uma janela existente. Para criar uma janela que superclasses uma classe Windows existente, primeiro especifique o nome de classe existente no construtor para o `CContainedWindowT` objeto. Então `CContainedWindowT::Create`ligue. Para subclasse uma janela existente, você não precisa especificar um nome de classe do Windows (passar NULL para o construtor). Basta chamar `CContainedWindowT::SubclassWindow` o método com a alça para a janela sendo subclassificada.

Você normalmente usa janelas contidas como membros de dados de uma classe de contêiner. O recipiente não precisa ser uma janela; no entanto, ele deve derivar do [CMessageMap](../atl/reference/cmessagemap-class.md).

Uma janela contida pode usar mapas de mensagens alternativos para lidar com suas mensagens. Se você tiver mais de uma janela contida, você deve declarar vários mapas de mensagens alternativos, cada um correspondendo a uma janela contida separada.

## <a name="example"></a>Exemplo

A seguir está um exemplo de uma classe de contêiner com duas janelas contidas:

[!code-cpp[NVC_ATL_Windowing#67](../atl/codesnippet/cpp/using-contained-windows_1.h)]

Para obter mais informações sobre janelas contidas, consulte a amostra [SUBEDIT.](https://github.com/Microsoft/VCSamples/tree/master/VC2008Samples/ATL/Controls/SubEdit)

## <a name="see-also"></a>Confira também

[Aulas de janela](../atl/atl-window-classes.md)
