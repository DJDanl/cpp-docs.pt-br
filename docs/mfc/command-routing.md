---
title: Roteamento de comando | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- MFC, command routing
- command handling [MFC], routing commands
- handlers [MFC]
- handlers, command [MFC]
- command routing
ms.assetid: 9393a956-bdd4-47c5-9013-dbd680433f93
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 543b9e34c881285c295fb7ab7ee2107e36c99a9c
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46418314"
---
# <a name="command-routing"></a>Roteamento de comando

Sua responsabilidade ao trabalhar com os comandos é limitada a fazer conexões de mapa de mensagens entre os comandos e suas funções do manipulador, uma tarefa para o qual você pode usar a janela Propriedades. Você também deve escrever a maioria dos manipuladores de comandos.

Mensagens do Windows geralmente são enviadas para janela principal do quadro, mas as mensagens de comando, em seguida, são roteadas para outros objetos. A estrutura roteia comandos por meio de uma sequência padrão dos objetos de destino do comando, um dos quais deve ter um manipulador para o comando. Cada objeto de destino do comando verifica seu mapa de mensagem para ver se ele pode lidar com a mensagem de entrada.

Classes diferentes de destino do comando verificar que suas próprias mensagens mapeia em momentos diferentes. Normalmente, uma classe roteia o comando para determinados outros objetos para fornecer-lhes a chance de primeiro no comando. Se nenhum desses objetos manipula o comando, a classe original verifica seu próprio mapa de mensagem. Em seguida, se ele não é possível fornecer um manipulador em si, ele pode rotear o comando para ainda mais destinos de comando. A tabela [rota de comando padrão](#_core_standard_command_route) abaixo mostra como cada uma das classes de estruturas dessa sequência. A ordem geral na qual um destino do comando roteia um comando é:

1. Para seu objeto de destino do comando filho ativo no momento.

1. A mesmo.

1. Para outros destinos de comando.

Como esse mecanismo de roteamento comparado ao que faz a seu manipulador em resposta a um comando é cara, o custo do roteamento é baixa. Tenha em mente que a estrutura gera comandos somente quando o usuário interage com um objeto de interface do usuário.

### <a name="_core_standard_command_route"></a> Padrão de rota de comando

|Quando um objeto desse tipo recebe um comando. . .|Ele oferece a mesmo e outros objetos de destino do comando a oportunidade de manipular o comando nesta ordem:|
|----------------------------------------------------------|-----------------------------------------------------------------------------------------------------|
|Janela de quadro MDI (`CMDIFrameWnd`)|1.  Active Directory `CMDIChildWnd`<br />2.  Essa janela de quadro<br />3.  Aplicativo (`CWinApp` objeto)|
|Janela de quadro do documento (`CFrameWnd`, `CMDIChildWnd`)|1.  Modo de exibição ativo<br />2.  Essa janela de quadro<br />3.  Aplicativo (`CWinApp` objeto)|
|Exibir|1.  Este modo de exibição<br />2.  Documento anexado para o modo de exibição|
|Documento|1.  Este documento<br />2.  Modelo de documento anexado ao documento|
|Caixa de diálogo|1.  Essa caixa de diálogo<br />2.  Janela à qual pertence a caixa de diálogo<br />3.  Aplicativo (`CWinApp` objeto)|

Em que entradas numeradas na segunda coluna da tabela anterior mencionam outros objetos, como um documento, consulte o item correspondente na primeira coluna. Por exemplo, quando você lê na segunda coluna que a exibição encaminha a um comando para seu documento, consulte a entrada de "Documento" na primeira coluna a seguir o roteamento adicional.

## <a name="see-also"></a>Consulte também

[Como o Framework chama um manipulador](../mfc/how-the-framework-calls-a-handler.md)

