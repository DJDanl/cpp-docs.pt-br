---
title: Modificando o controle DHTML da ATL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- HTML controls, modifying
- DHTML controls
- DHTML controls, modifying
ms.assetid: c053f35f-8629-4600-9595-721f5956777a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ed2e1f8f24b3d33dd7d45bb597b252ead1453647
ms.sourcegitcommit: 997e6b7d336cddb388bb6e9e56527725fcaa0624
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/08/2018
ms.locfileid: "48861142"
---
# <a name="modifying-the-atl-dhtml-control"></a>Modificando o controle DHTML da ATL

O Assistente de controle do ATL fornece o código inicial para que você pode compilar e executar o controle e, portanto, você pode ver como os métodos são gravados nos arquivos de projeto e como DHTML chama código de C++ do controle usando os métodos de expedição. Você pode adicionar qualquer método de expedição à interface. Em seguida, você pode chamar os métodos no recurso de HTML.

## <a name="to-modify-the-atl-dhtml-control"></a>Para modificar o controle DHTML da ATL

1. Na **modo de exibição de classe**, expanda o projeto de controle.

   Observe que a interface que termina em "Interface do usuário" tem um método, `OnClick`. A interface que não terminam em "Interface do usuário" não tem nenhum método.

1. Adicione um método chamado `MethodInvoked` para a interface que não terminam em "Interface do usuário."

   Esse método será adicionado à interface que é usado no contêiner de controle para interação com o contêiner, não para a interface usada pelo DHTML para interagir com o controle. Apenas o contêiner pode invocar esse método.

1. Localize o método fragmentado-out no arquivo. cpp e adicione código para exibir uma caixa de mensagem, por exemplo:

   [!code-cpp[NVC_ATL_COM#5](../atl/codesnippet/cpp/modifying-the-atl-dhtml-control_1.cpp)]

1. Adicione outro método chamado `HelloHTML`, somente dessa vez, adicioná-lo para a interface que termina em "Interface do usuário." Descubra o por fazer o stub `HelloHTML` método na. cpp arquivo e adicione o código para exibir uma caixa de mensagem, por exemplo:

   [!code-cpp[NVC_ATL_COM#6](../atl/codesnippet/cpp/modifying-the-atl-dhtml-control_2.cpp)]

1. Adicione um método de terceiro, `GoToURL`, para a interface que não terminam em "Interface do usuário." Implemente este método chamando [IWebBrowser2::Navigate](https://msdn.microsoft.com/library/aa752133.aspx), da seguinte maneira:

   [!code-cpp[NVC_ATL_COM#7](../atl/codesnippet/cpp/modifying-the-atl-dhtml-control_3.cpp)]

   Você pode usar o `IWebBrowser2` métodos porque o ATL fornece um ponteiro para essa interface para você em seu arquivo. h.

Em seguida, modifique o recurso HTML para invocar os métodos que você criou. Você irá adicionar três botões para chamar esses métodos.

## <a name="to-modify-the-html-resource"></a>Para modificar o recurso HTML

1. Na **Gerenciador de soluções**, duas vezes no arquivo. htm para exibir o recurso HTML.

   Examine o HTML, especialmente as chamadas para os métodos de expedição externos do Windows. O HTML chama o projeto `OnClick` método e os parâmetros indicam o corpo do controle (`theBody`) e a cor a ser atribuída ("`red`"). O texto que segue a chamada de método é o rótulo que aparece no botão.

1. Adicione outro `OnClick` método, alterar a cor. Por exemplo:

    ```html
    <br>
    <br>
    <BUTTON onclick='window.external.OnClick(theBody, "white");'>Refresh</BUTTON>
    ```

   Esse método criará um botão rotulado **Refresh**, que o usuário pode clicar para retornar o controle ao plano de fundo original, em branco.

1. Adicione a chamada para o `HelloHTML` método que você criou. Por exemplo:

    ```html
    <br>
    <br>
    <BUTTON onclick='window.external.HelloHTML();'>HelloHTML</BUTTON>
    ```

   Esse método criará um botão rotulado **HelloHTML**, que o usuário pode clicar para exibir o `HelloHTML` caixa de mensagem.

Agora você pode compilar e [teste o controle DHTML modificado](../atl/testing-the-modified-atl-dhtml-control.md).

## <a name="see-also"></a>Consulte também

[Suporte para controle DHTML](../atl/atl-support-for-dhtml-controls.md)
