---
title: Usando o Windows independente
ms.date: 11/04/2016
helpviewer_keywords:
- ATL, windows
- windows [C++], ATL
- contained windows in ATL
ms.assetid: 7b3d79e5-b569-413f-9b98-df4f14efbe2b
ms.openlocfilehash: 800ae7cab5fd99bfa140b481f87b1615ff5b2a13
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50485365"
---
# <a name="using-contained-windows"></a>Usando o Windows independente

ATL implementa janelas independentes com [CContainedWindowT](../atl/reference/ccontainedwindowt-class.md). Uma janela contida representa uma janela que delega suas mensagens para um objeto de contêiner em vez de tratá-los em sua própria classe.

> [!NOTE]
>  Não é necessário derivar uma classe de `CContainedWindowT` para usar o windows independentes.

Com o windows independentes, você pode a superclasse uma classe existente do Windows ou uma subclasse de uma janela existente. Para criar uma janela que superclassificar um Windows existente da classe, primeiro especifique o nome de classe existente no construtor para o `CContainedWindowT` objeto. Em seguida, chame `CContainedWindowT::Create`. A subclasse uma janela existente, você não precisa especificar um nome de classe do Windows (passar nulo para o construtor). Basta chamar o `CContainedWindowT::SubclassWindow` método com o identificador para a janela que está sendo uma subclasse.

Você normalmente usa o windows independentes como membros de dados de uma classe de contêiner. O contêiner não precisa ser uma janela; No entanto, ele deve derivar de [CMessageMap](../atl/reference/cmessagemap-class.md).

Uma janela contida pode usar mapas de mensagem alternativo para lidar com suas mensagens. Se você tiver mais de uma janela contida, você deve declarar que vários alternam mapas de mensagem, cada um correspondendo a uma janela separada de independente.

## <a name="example"></a>Exemplo

A seguir está um exemplo de uma classe de contêiner com duas janelas independentes:

[!code-cpp[NVC_ATL_Windowing#67](../atl/codesnippet/cpp/using-contained-windows_1.h)]

Para obter mais informações sobre o windows independentes, consulte o [SUBEDIT](https://github.com/Microsoft/VCSamples/tree/master/VC2008Samples/ATL/Controls/SubEdit) exemplo.

## <a name="see-also"></a>Consulte também

[Classes de janela](../atl/atl-window-classes.md)

