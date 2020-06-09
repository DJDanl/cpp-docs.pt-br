---
title: Roteamento de comando
ms.date: 09/06/2019
helpviewer_keywords:
- MFC, command routing
- command handling [MFC], routing commands
- handlers [MFC]
- handlers, command [MFC]
- command routing
ms.assetid: 9393a956-bdd4-47c5-9013-dbd680433f93
ms.openlocfilehash: e47ffd38b342301da32abae9690738ef83c0426b
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84620688"
---
# <a name="command-routing"></a>Roteamento de comando

Sua responsabilidade em trabalhar com comandos é limitada a fazer conexões de mapa de mensagens entre comandos e suas funções de manipulador, uma tarefa para a qual você usa o [Assistente de classe do MFC](reference/mfc-class-wizard.md). Você também deve escrever o código para os manipuladores de comando.

As mensagens do Windows geralmente são enviadas para a janela principal do quadro, mas as mensagens de comando são roteadas para outros objetos. A estrutura roteia comandos por meio de uma sequência padrão de objetos de destino de comando, um dos quais deve ter um manipulador para o comando. Cada objeto de destino de comando verifica seu mapa de mensagens para ver se ele pode manipular a mensagem de entrada.

Classes de destino de comando diferentes verificam seus próprios mapas de mensagem em momentos diferentes. Normalmente, uma classe roteia o comando para alguns outros objetos para dar a eles a primeira chance no comando. Se nenhum desses objetos tratar o comando, a classe original verificará seu próprio mapa de mensagens. Em seguida, se ele não puder fornecer um manipulador em si, ele poderá rotear o comando para ainda mais destinos de comando. A [rota de comando padrão](#_core_standard_command_route) da tabela abaixo mostra como cada uma das classes estrutura essa sequência. A ordem geral na qual um destino de comando roteia um comando é:

1. Para seu objeto de destino de comando filho ativo no momento.

1. Para si mesmo.

1. Para outros destinos de comando.

Quão caro é esse mecanismo de roteamento em comparação com o que seu manipulador faz em resposta a um comando, o custo do roteamento é baixo. Tenha em mente que a estrutura gera comandos somente quando o usuário interage com um objeto de interface do usuário.

### <a name="standard-command-route"></a><a name="_core_standard_command_route"></a>Rota de comando padrão

|Quando um objeto desse tipo recebe um comando. . .|Ele oferece a si mesmo e outros objetos de destino de comando a oportunidade de lidar com o comando nesta ordem:|
|----------------------------------------------------------|-----------------------------------------------------------------------------------------------------|
|Janela de quadro MDI ( `CMDIFrameWnd` )|1. ativo`CMDIChildWnd`<br />2. esta janela do quadro<br />3. aplicativo ( `CWinApp` objeto)|
|Janela do quadro do documento ( `CFrameWnd` , `CMDIChildWnd` )|1. modo de exibição ativo<br />2. esta janela do quadro<br />3. aplicativo ( `CWinApp` objeto)|
|Visualizar|1. esta exibição<br />2. documento anexado à exibição|
|Document|1. este documento<br />2. modelo de documento anexado ao documento|
|Caixa de diálogo|1. esta caixa de diálogo<br />2. janela que possui a caixa de diálogo<br />3. aplicativo ( `CWinApp` objeto)|

Quando as entradas numeradas na segunda coluna da tabela anterior mencionam outros objetos, como um documento, consulte o item correspondente na primeira coluna. Por exemplo, quando você lê na segunda coluna que a exibição encaminha um comando para seu documento, veja a entrada "Document" na primeira coluna para seguir o roteamento.

## <a name="see-also"></a>Consulte também

[Como o Framework chama um manipulador](how-the-framework-calls-a-handler.md)
