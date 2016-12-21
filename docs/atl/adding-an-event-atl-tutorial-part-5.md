---
title: "Adicionando um evento (Tutorial ATL, parte 5) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "get-started-article"
dev_langs: 
  - "C++"
ms.assetid: 2de12022-3148-4ce3-8606-8a9d4274f0e9
caps.latest.revision: 13
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Adicionando um evento (Tutorial ATL, parte 5)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Em esta etapa, você adicionará `ClickIn` e um evento de `ClickOut` ao controle de ATL.  Você acionará o evento de `ClickIn` se o usuário clica em polygon e de fogo `ClickOut` se o usuário clicar fora.  As tarefas adicionar um evento são:  
  
-   Adicionando os métodos de `ClickIn` e de `ClickOut`  
  
-   Gerando a biblioteca de tipos  
  
-   Implementando as interfaces de ponto de conexão  
  
## Adicionando os métodos de ClickIn e de ClickOut  
 Quando você criou o controle de ATL na etapa 2, você marcar a caixa de seleção de **pontos de conexão** .  Isso cria a interface de `_IPolyCtlEvents` no arquivo de Polygon.idl.  Observe que inicia o nome da interface com um sublinhado.  Esta é uma convenção para indicar que a interface é uma interface interna.  Assim, os programas que permitem que você procure COM objetos podem optar por não exibir a interface para o usuário.  Também observe que seleciona **pontos de conexão** adicionou a seguinte linha no arquivo de Polygon.idl para indicar que `_IPolyCtlEvents` é a interface padrão de origem:  
  
 `[default, source] dispinterface _IPolyCtlEvents;`  
  
 O atributo de origem indica que o controle é a origem das notificações, o que chamará essa interface no recipiente.  
  
 Agora adicione `ClickIn` e métodos de `ClickOut` a `_IPolyCtlEvents` interface.  
  
#### Para adicionar os métodos de ClickIn e de ClickOut  
  
1.  Em o modo da classe, expanda o polígonos e o PolygonLib para exibir \_IPolyCtlEvents.  
  
2.  Clique com o botão direito do mouse \_IPolyCtlEvents.  Em o menu de atalho, clique **Adicionar**, clique em **Adicionar método**.  
  
3.  Selecione **Tipo de retorno** de `void`.  
  
4.  Entre em `ClickIn` na caixa de **Nome do método** .  
  
5.  Em **Atributos de parâmetro**, selecione a caixa de **em** .  
  
6.  Selecione **Tipo de parâmetro** de `LONG`.  
  
7.  Digite `x` como **Nome do parâmetro**, e clique **Adicionar**.  
  
8.  Repita as etapas 5 a 7, de essa vez para **Nome do parâmetro** de `s`.  
  
9. Clique em **Próximo**.  
  
10. Tipo `método ClickIn` como **helpstring**.  
  
11. Clique em **Concluir**.  
  
12. Repita as etapas anteriores para definir um método de `ClickOut` com os mesmos parâmetros `x` e `y`, mesmo **Atributos de parâmetro** de `LONG` e o mesmo tipo de retorno de `void` .  
  
 Verifique o arquivo de Polygon.idl para ver que o código foi adicionado ao dispinterface de `_IPolyCtlEvents` .  
  
 O dispinterface de `_IPolyCtlEvents` no arquivo de Polygon.idl agora deve ser assim:  
  
 [!code-cpp[NVC_ATL_Windowing#56](../atl/codesnippet/CPP/adding-an-event-atl-tutorial-part-5_1.idl)]  
  
 Os métodos de `ClickIn` e de `ClickOut` têm as coordenadas x e y do ponto clicado como parâmetros.  
  
## Gerando a biblioteca de tipos  
 Gera a biblioteca de tipos em este ponto, porque o assistente de ponto de conexão a usará para obter as informações necessárias para construir uma interface de ponto de conexão e uma interface do recipiente de ponto de conexão para o controle.  
  
#### Para gerar a biblioteca de tipos  
  
1.  Crie seu projeto.  
  
     \-  ou  \-  
  
2.  Clique com o botão direito do mouse no arquivo de Polygon.idl no solution Explorer e clique **Compilar** no menu de atalho.  
  
 Isso criará o arquivo de Polygon.tlb, que é a biblioteca de tipos.  O arquivo de Polygon.tlb não estiver visível no solution Explorer, porque é um arquivo binário e não pode ser exibido ou editados diretamente.  
  
## Implementando as interfaces de ponto de conexão  
 Implementar uma interface de ponto de conexão e uma interface do recipiente de ponto de conexão para o controle.  Em a, os eventos são implementados pelo mecanismo de pontos de conexão.  Para receber eventos de um objeto COM, um contêiner estabelece uma conexão consultiva ao ponto de conexão que o objeto COM implementa.  Como um objeto COM pode ter vários pontos de conexão, o objeto COM também implementa uma interface do recipiente de ponto de conexão.  Através de esta interface, o contêiner pode determinar que pontos de conexão são suportados.  
  
 A interface que implementa um ponto de conexão é chamada `IConnectionPoint`, e a interface que implementa um contêiner de ponto de conexão é chamada `IConnectionPointContainer`.  
  
 Para ajudar a implementação `IConnectionPoint`, você usará o assistente de ponto de conexão de implementam.  Este assistente gera a interface de `IConnectionPoint` ler sua biblioteca de tipos e implementando uma função para cada evento que pode ser acionado.  
  
#### Para usar o assistente de ponto de conexão de implementam  
  
1.  Em o modo da classe, clique com o botão direito do mouse na classe `CPolyCtl`de implementação do controle.  
  
2.  Em o menu de atalho, clique **Adicionar**, clique em **Adicionar ponto de conexão**.  
  
3.  `_IPolyCtlEvents` selecione da lista de **Interfaces de origem** e clique duas vezes em para adicioná\-lo à coluna de **Pontos de conexão de implementam** .  Clique em **Concluir**.  Uma classe de proxy para o ponto de conexão será gerada, em esse caso, `CProxy_IPolyCtlEvents`.  
  
 Se você examinar o arquivo gerado de \_IPolyCtlEvents\_CP.h no solution Explorer, você verá que tem uma classe chamada `CProxy_IPolyCtlEvents` que deriva de `IConnectionPointImpl`.  \_IPolyCtlEvents\_CP.h também define os dois métodos `Fire_ClickIn` e `Fire_ClickOut`, que levam os dois parâmetros de coordenadas.  Você chamar esses métodos quando você deseja tenha um evento do controle.  
  
 O assistente `CProxy_PolyEvents` e `IConnectionPointContainerImpl` também adicionado à lista de várias heranças do seu controle.  O assistente `IConnectionPointContainer` também expõe para você adicionando entradas apropriadas ao mapa COM.  
  
 Você terminou que implementa o código para suportar eventos.  Agora, adicione um código para acionar eventos no momento apropriado.  Lembre\-se, você está indo tenha um evento de `ClickIn` ou de `ClickOut` quando o usuário clica no botão esquerdo do mouse no controle.  Para encontrar quando o usuário clica no botão, adicione um manipulador para a mensagem de `WM_LBUTTONDOWN` .  
  
#### Para adicionar um manipulador para a mensagem de WM\_LBUTTONDOWN  
  
1.  Em o modo da classe, clique com o botão direito do mouse na classe de CPolyCtl e clique **Propriedades** no menu de atalho.  
  
2.  Em a janela de **Propriedades** , clique no ícone de **Mensagens** e clique em `WM_LBUTTONDOWN` da lista para a esquerda.  
  
3.  Em a lista suspensa que aparece, clique em **\<Add\> \*\*\*  OnLButtonDown**.  A declaração do manipulador de `OnLButtonDown` será adicionada a PolyCtl.h, e a implementação do manipulador será adicionada a PolyCtl.cpp.  
  
 Em seguida, altere o manipulador.  
  
#### Para alterar o método de OnLButtonDown  
  
1.  Modificar o código que constitui o método de `OnLButtonDown` em PolyCtl.cpp \(que exclui qualquer código colocado pelo assistente\) para parecido com o seguinte:  
  
     [!code-cpp[NVC_ATL_Windowing#57](../atl/codesnippet/CPP/adding-an-event-atl-tutorial-part-5_2.cpp)]  
  
 Esse código usa os pontos calculados na função de `OnDraw` para criar uma região que ele detecte os cliques do mouse de usuário com a chamada a `PtInRegion`.  
  
 O parâmetro de `uMsg` é a identificação de mensagens do windows que está sendo tratado.  Isso permite que você tenha uma função que trata um intervalo de mensagens.  `wParam` e parâmetros de `lParam` são os valores padrão para a mensagem que está sendo tratado.  o parâmetro bHandled permite que você especifique se a função tratou a mensagem ou não.  Por padrão, o valor é definido como `TRUE` para indicar que a função tratou a mensagem, mas você pode definir a `FALSE`.  Isso fará com que ATL continue a procurar outra função do manipulador de mensagem para enviar a mensagem para.  
  
## Compilação e teste o controle  
 Tente agora seus eventos.  Compilar o controle e ligue o contêiner de teste do controle ActiveX novamente.  De esta vez, exibe a janela de log de eventos.  Para rotear eventos para a janela de saída, clique **Log** do menu de **Opções** e selecione **Log para a janela de saída**.  Insira o controle e tente que clicam na janela.  Observe que `ClickIn` é acionado se você clicar em polygon preenchido, e `ClickOut` é acionado quando você clicar fora de ela.  
  
 Em seguida, você adicionará uma página de propriedades.  
  
 [De volta para a etapa 4](../atl/changing-the-drawing-code-atl-tutorial-part-4.md) &#124; [a etapa 6](../Topic/Adding%20a%20Property%20Page%20\(ATL%20Tutorial,%20Part%206\).md)  
  
## Consulte também  
 [Tutorial](../Topic/Active%20Template%20Library%20\(ATL\)%20Tutorial.md)