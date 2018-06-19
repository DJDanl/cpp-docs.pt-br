---
title: Adicionando um evento (ATL Tutorial, parte 5) | Microsoft Docs
ms.custom: get-started-article
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 2de12022-3148-4ce3-8606-8a9d4274f0e9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a118cf29546ac8dae2e882d5658b07e3b5e085f6
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32361259"
---
# <a name="adding-an-event-atl-tutorial-part-5"></a>Adicionando um evento (Tutorial ATL, parte 5)
Nesta etapa, você adicionará um `ClickIn` e um `ClickOut` eventos para o controle ATL. Você será acionado a `ClickIn` evento se o usuário clica dentro do polígono e acionar `ClickOut` se o usuário clica fora. As tarefas para adicionar um evento são da seguinte maneira:  
  
-   Adicionando o `ClickIn` e `ClickOut` métodos  
  
-   Gerando a biblioteca de tipos  
  
-   Implementar as Interfaces de ponto de Conexão  
  
## <a name="adding-the-clickin-and-clickout-methods"></a>Adicionar métodos ClickOut e ClickIn  
 Ao criar o controle ATL na etapa 2, você selecionou o **pontos de Conexão** caixa de seleção. Isso criou o `_IPolyCtlEvents` interface no arquivo Polygon.idl. Observe que o nome da interface começa com um sublinhado. Isso é uma convenção para indicar que a interface é uma interface interna. Assim, programas que permitem que você procure objetos COM podem escolher não exibir a interface para o usuário. Observe também que a seleção **pontos de Conexão** adicionado a seguinte linha no arquivo Polygon.idl para indicar que `_IPolyCtlEvents` é a interface de origem padrão:  
  
 `[default, source] dispinterface _IPolyCtlEvents;`  
  
 O atributo de origem indica que o controle é a origem das notificações, para que ele chamará essa interface no contêiner.  
  
 Agora, adicione o `ClickIn` e `ClickOut` métodos para o `_IPolyCtlEvents` interface.  
  
#### <a name="to-add-the-clickin-and-clickout-methods"></a>Para adicionar os métodos ClickIn e ClickOut  
  
1.  No modo de exibição de classe, expanda para exibir _IPolyCtlEvents de polígono e PolygonLib.  
  
2.  Clique com botão direito _IPolyCtlEvents. No menu de atalho, clique em **adicionar**e, em seguida, clique em **Adicionar método**.  
  
3.  Selecione um **tipo de retorno** de `void`.  
  
4.  Digite `ClickIn` no **nome do método** caixa.  
  
5.  Em **atributos de parâmetro**, selecione o **na** caixa.  
  
6.  Selecione um **tipo de parâmetro** de `LONG`.  
  
7.  Tipo `x` como o **nome do parâmetro**e clique em **adicionar**.  
  
8.  Repita as etapas 5 a 7, neste momento para um **nome do parâmetro** de `y`.  
  
9. Clique em **Avançar**.  
  
10. Tipo `method ClickIn` como o **helpstring**.  
  
11. Clique em **Finalizar**.  
  
12. Repita as etapas acima para definir um `ClickOut` método com o mesmo `LONG` parâmetros `x` e `y`, o mesmo **atributos de parâmetro** e o mesmo `void` tipo de retorno.  
  
 Verifique o arquivo Polygon.idl para ver se o código foi adicionado para o `_IPolyCtlEvents` dispinterface.  
  
 O `_IPolyCtlEvents` dispinterface no arquivo Polygon.idl agora deve se parecer com:  
  
 [!code-cpp[NVC_ATL_Windowing#56](../atl/codesnippet/cpp/adding-an-event-atl-tutorial-part-5_1.idl)]  
  
 O `ClickIn` e `ClickOut` têm métodos x e y do ponto clicado como parâmetros.  
  
## <a name="generating-the-type-library"></a>Gerando a biblioteca de tipos  
 Gere a biblioteca de tipos neste momento, porque o Assistente de Conexão do ponto de usá-lo para obter as informações necessárias para construir uma interface de ponto de conexão e uma interface de contêiner de ponto de conexão para o seu controle.  
  
#### <a name="to-generate-the-type-library"></a>Para gerar a biblioteca de tipos  
  
1.  Recompile o projeto.  
  
     -ou-  
  
2.  Clique no arquivo Polygon.idl no Gerenciador de soluções e clique em **compilar** no menu de atalho.  
  
 Isso criará o arquivo Polygon.tlb, que é a biblioteca de tipos. O arquivo de Polygon.tlb não está visível no Gerenciador de soluções, porque ele é um arquivo binário e não pode ser exibido ou editado diretamente.  
  
## <a name="implementing-the-connection-point-interfaces"></a>Implementar as Interfaces de ponto de Conexão  
 Implemente uma interface de ponto de conexão e uma interface de contêiner de ponto de conexão para o seu controle. Em COM, os eventos são implementados por meio do mecanismo de pontos de conexão. Para receber eventos de um objeto COM, um contêiner estabelece uma conexão de consultoria ao ponto de conexão que implementa o objeto COM. Como um objeto COM pode ter vários pontos de conexão, o objeto COM também implementa uma interface de contêiner de ponto de conexão. Por meio dessa interface, o contêiner pode determinar quais pontos de conexão são suportados.  
  
 A interface que implementa um ponto de conexão é chamada `IConnectionPoint`, e a interface que implementa um contêiner de ponto de conexão é chamada `IConnectionPointContainer`.  
  
 Para ajudar a implementar `IConnectionPoint`, você usará o Assistente para implementar pontos de Conexão. Este assistente gera o `IConnectionPoint` interface ler a biblioteca de tipos e implementando uma função para cada evento que pode ser acionado.  
  
#### <a name="to-use-the-implement-connection-point-wizard"></a>Para usar o Assistente de implementação de ponto de Conexão  
  
1.  No modo de exibição de classe, clique na classe de implementação do controle `CPolyCtl`.  
  
2.  No menu de atalho, clique em **adicionar**e, em seguida, clique em **Adicionar ponto de Conexão**.  
  
3.  Selecione `_IPolyCtlEvents` do **Interfaces de origem** lista e clique duas vezes nele para adicioná-lo para o **implementar pontos de conexão** coluna. Clique em **Finalizar**. Uma classe de proxy para o ponto de conexão será gerada, nesse caso, `CProxy_IPolyCtlEvents`.  
  
 Se você examinar o arquivo _IPolyCtlEvents_CP.h gerado no Gerenciador de soluções, você verá que ela tem uma classe chamada `CProxy_IPolyCtlEvents` que deriva de `IConnectionPointImpl`. _IPolyCtlEvents_CP.h também define dois métodos `Fire_ClickIn` e `Fire_ClickOut`, que usam os dois parâmetros de coordenada. Quando você deseja disparar um evento de controle para chamar esses métodos.  
  
 O assistente também adicionado `CProxy_PolyEvents` e `IConnectionPointContainerImpl` à lista de herança vários do controle. O assistente também exposto `IConnectionPointContainer` para você, adicionando entradas apropriadas para o mapa COM.  
  
 Você tiver terminado de implementar o código para oferecer suporte a eventos. Agora, adicione código para disparar os eventos no momento apropriado. Lembre-se de que você vai disparar um `ClickIn` ou `ClickOut` evento quando o usuário clica no botão esquerdo do mouse no controle. Para saber quando o usuário clica no botão, adicione um manipulador para o `WM_LBUTTONDOWN` mensagem.  
  
#### <a name="to-add-a-handler-for-the-wmlbuttondown-message"></a>Para adicionar um manipulador para a mensagem WM_LBUTTONDOWN  
  
1.  No modo de exibição de classe, a classe CPolyCtl de mouse e clique em **propriedades** no menu de atalho.  
  
2.  No **propriedades** janela, clique no **mensagens** e, em seguida, clique em `WM_LBUTTONDOWN` na lista à esquerda.  
  
3.  Na lista suspensa que aparece, clique em  **\<Adicionar > OnLButtonDown**. O `OnLButtonDown` declaração do manipulador será adicionada ao PolyCtl.h e a implementação do manipulador será adicionada ao PolyCtl.cpp.  
  
 Em seguida, modifique o manipulador.  
  
#### <a name="to-modify-the-onlbuttondown-method"></a>Para modificar o método OnLButtonDown  
  
1.  Alterar o código que compõe o `OnLButtonDown` método PolyCtl.cpp (excluindo qualquer código colocado pelo Assistente) para que fique assim:  
  
     [!code-cpp[NVC_ATL_Windowing#57](../atl/codesnippet/cpp/adding-an-event-atl-tutorial-part-5_2.cpp)]  
  
 Isso faz com código uso dos pontos de calculado no `OnDraw` função para criar uma região que detecta clica com o mouse do usuário com a chamada para `PtInRegion`.  
  
 O `uMsg` parâmetro é a ID de mensagem do Windows que está sendo tratada. Isso permite que você tenha uma função que manipula um intervalo de mensagens. O `wParam` e `lParam` parâmetros são os valores padrão para a mensagem que está sendo tratado. O parâmetro bHandled permite que você especifique se a função tratou a mensagem ou não. Por padrão, o valor é definido como `TRUE` para indicar que a função tratou a mensagem, mas você pode defini-lo `FALSE`. Isso fará com que o ATL continuar procurando por outra função de manipulador de mensagens enviar a mensagem.  
  
## <a name="building-and-testing-the-control"></a>Compilar e testar o controle  
 Experimente agora seus eventos. Criar o controle e iniciar o contêiner de teste do controle ActiveX novamente. Neste momento, exiba a janela de log de eventos. Para eventos de rota para a janela de saída, clique em **log** do **opções** menu e selecione **Log janela de saída**. Inserir o controle e tente clicar na janela. Observe que `ClickIn` é acionado se você clicar em polígono preenchido, e `ClickOut` é acionado quando você clicar fora dele.  
  
 Em seguida, você adicionará uma página de propriedades.  
  
 [Para a etapa 4](../atl/changing-the-drawing-code-atl-tutorial-part-4.md) &#124; [na etapa 6](../atl/adding-a-property-page-atl-tutorial-part-6.md)  
  
## <a name="see-also"></a>Consulte também  
 [Tutorial](../atl/active-template-library-atl-tutorial.md)

