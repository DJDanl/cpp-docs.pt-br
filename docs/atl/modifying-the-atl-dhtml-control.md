---
title: "Modificando o controle DHTML ATL | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Controles HTML, modificando"
  - "controles DHTML"
  - "Controles DHTML, modificando"
ms.assetid: c053f35f-8629-4600-9595-721f5956777a
caps.latest.revision: 11
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Modificando o controle DHTML ATL
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O Assistente de controle ATL fornece código inicial para compilar e executar o controle e, portanto, você pode ver como os métodos são gravados nos arquivos de projeto e como DHTML chama código de C\+\+ do controle usando os métodos de expedição. Você pode adicionar qualquer método de envio para a interface. Em seguida, você pode chamar os métodos no recurso de HTML.  
  
#### Para modificar o controle DHTML ATL  
  
1.  No modo de exibição de classe, expanda o projeto de controle.  
  
     Observe que a interface que termina em "Interface do usuário" tem um método, `OnClick`. A interface que não terminam em "Interface do usuário" não tem quaisquer métodos.  
  
2.  Adicionar um método chamado `MethodInvoked` para a interface que não terminam em "Interface do usuário."  
  
     Esse método será adicionado à interface que é usado no contêiner de controle para interação de contêiner, não para a interface usada pelo DHTML para interagir com o controle. Somente o contêiner pode chamar esse método.  
  
3.  Localize o método de stub\-out no arquivo. cpp e adicione código para exibir uma caixa de mensagem, por exemplo:  
  
     [!code-cpp[NVC_ATL_COM#5](../atl/codesnippet/CPP/modifying-the-atl-dhtml-control_1.cpp)]  
  
4.  Adicionar outro método chamado `HelloHTML`, somente desta vez, adicione\-o para a interface que termina em "Interface do usuário." Descobrir o stub\- `HelloHTML` método na. cpp e adicione código para exibir uma caixa de mensagem, por exemplo:  
  
     [!code-cpp[NVC_ATL_COM#6](../atl/codesnippet/CPP/modifying-the-atl-dhtml-control_2.cpp)]  
  
5.  Adicione um terceiro método, `GoToURL`, para a interface que não terminam em "Interface do usuário." Implementar esse método chamando [IWebBrowser2::Navigate](https://msdn.microsoft.com/en-us/library/aa752133.aspx), da seguinte maneira:  
  
     [!code-cpp[NVC_ATL_COM#7](../atl/codesnippet/CPP/modifying-the-atl-dhtml-control_3.cpp)]  
  
     Você pode usar o **IWebBrowser2** métodos como ATL fornece um ponteiro para essa interface para você em seu arquivo. h.  
  
 Em seguida, modifique o recurso HTML para invocar os métodos que você criou. Você irá adicionar três botões para chamar esses métodos.  
  
#### Para modificar o recurso HTML  
  
1.  No Solution Explorer, clique duas vezes no arquivo. htm para exibir o recurso HTML.  
  
     Examine o HTML, especialmente as chamadas para os métodos de expedição externos do Windows. O HTML chama o projeto `OnClick` método e os parâmetros indicam o corpo do controle \(`theBody`\) e a cor para atribuir \("`red`"\). O texto após a chamada do método é o rótulo que aparece no botão.  
  
2.  Adicione outro `OnClick` método, alterar a cor. Por exemplo:  
  
    ```  
    <br>  
    <br>  
    <BUTTON onclick='window.external.OnClick(theBody, "white");'>Refresh</BUTTON>  
    ```  
  
     Esse método criará um botão rotulado **atualizar**, que o usuário pode clicar para retornar o controle ao plano de fundo branco, original.  
  
3.  Adicione a chamada para o `HelloHTML` método que você criou. Por exemplo:  
  
    ```  
    <br>  
    <br>  
    <BUTTON onclick='window.external.HelloHTML();'>HelloHTML</BUTTON>  
    ```  
  
     Esse método criará um botão rotulado **HelloHTML**, que o usuário pode clicar para exibir o `HelloHTML` caixa de mensagem.  
  
 Agora você pode compilar e [teste o controle DHTML modificado](../atl/testing-the-modified-atl-dhtml-control.md).  
  
## Consulte também  
 [Suporte para controle DHTML](../atl/atl-support-for-dhtml-controls.md)