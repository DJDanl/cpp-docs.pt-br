---
title: Modificando o controle DHTML ATL | Microsoft Docs
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
ms.openlocfilehash: 3810236aca4661a6cdcd8399294cdb73e97948fd
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32356489"
---
# <a name="modifying-the-atl-dhtml-control"></a>Modificando o controle DHTML ATL
O Assistente de controle ATL fornece código inicial para compilar e executar o controle e, portanto, você pode ver como os métodos são gravados nos arquivos de projeto e como DHTML chama o código C++ do controle usando os métodos de expedição. Você pode adicionar qualquer método de distribuição para a interface. Em seguida, você pode chamar os métodos no recurso HTML.  
  
#### <a name="to-modify-the-atl-dhtml-control"></a>Para modificar o controle DHTML ATL  
  
1.  No modo de exibição de classe, expanda o projeto de controle.  
  
     Observe que a interface que termina em "UI" tem um método, `OnClick`. A interface que não terminam em "UI" não tem nenhum método.  
  
2.  Adicionar um método chamado `MethodInvoked` para a interface que não terminam em "Interface de usuário".  
  
     Esse método será adicionado à interface que é usado no contêiner de controle para interação de contêiner, não para a interface usada pelo DHTML para interagir com o controle. Apenas o contêiner pode chamar esse método.  
  
3.  Localize o método fragmentado-out no arquivo. cpp e adicione código para exibir uma caixa de mensagem, por exemplo:  
  
 [!code-cpp[NVC_ATL_COM#5](../atl/codesnippet/cpp/modifying-the-atl-dhtml-control_1.cpp)]  
  
4.  Adicionar outro método chamado `HelloHTML`, somente desta vez, adicione-o para a interface que termina em "Interface de usuário". Descobrir o fragmentado- `HelloHTML` método em de. cpp e adicione código para exibir uma caixa de mensagem, por exemplo:  
  
 [!code-cpp[NVC_ATL_COM#6](../atl/codesnippet/cpp/modifying-the-atl-dhtml-control_2.cpp)]  
  
5.  Adicione um método de terceiro, `GoToURL`, para a interface que não terminam em "Interface de usuário". Implementar esse método chamando [IWebBrowser2::Navigate](https://msdn.microsoft.com/library/aa752133.aspx), da seguinte maneira:  
  
 [!code-cpp[NVC_ATL_COM#7](../atl/codesnippet/cpp/modifying-the-atl-dhtml-control_3.cpp)]  
  
     Você pode usar o **IWebBrowser2** métodos como ATL fornece um ponteiro para essa interface para você em seu arquivo. h.  
  
 Em seguida, modifique o recurso HTML para invocar os métodos que você criou. Adicione três botões para chamar esses métodos.  
  
#### <a name="to-modify-the-html-resource"></a>Para modificar o recurso HTML  
  
1.  No Solution Explorer, clique duas vezes o arquivo. htm para exibir o recurso HTML.  
  
     Examine o HTML, especialmente as chamadas para os métodos de expedição externos do Windows. O HTML chama o projeto `OnClick` método e os parâmetros de indicam o corpo do controle (`theBody`) e a cor para atribuir ("`red`"). O texto que segue a chamada de método é o rótulo que aparece no botão.  
  
2.  Adicione outro `OnClick` método, alterar a cor. Por exemplo:  
  
 ```  
 <br>  
 <br>  
 <BUTTON onclick='window.external.OnClick(theBody, "white");'>Refresh</BUTTON>  
 ```  
  
     Esse método criará um botão rotulado **atualização**, que o usuário pode clicar para retornar o controle ao plano de fundo branco, original.  
  
3.  Adicione a chamada para o `HelloHTML` método que você criou. Por exemplo:  
  
 ```  
 <br>  
 <br>  
 <BUTTON onclick='window.external.HelloHTML();'>HelloHTML</BUTTON>  
 ```  
  
     Esse método criará um botão rotulado **HelloHTML**, que o usuário pode clicar para exibir o `HelloHTML` caixa de mensagem.  
  
 Agora você pode criar e [testar o controle DHTML modificado](../atl/testing-the-modified-atl-dhtml-control.md).  
  
## <a name="see-also"></a>Consulte também  
 [Suporte para controle DHTML](../atl/atl-support-for-dhtml-controls.md)

