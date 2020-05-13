---
title: Manipuladores para intervalos de mapa da mensagem
ms.date: 11/04/2016
helpviewer_keywords:
- message handlers [MFC]
- handlers [MFC], message-map ranges
- message maps [MFC], message handler functions
- message maps [MFC], ranges
- control-notification messages [MFC]
- command IDs [MFC], message mapping
- message-map ranges [MFC]
- handlers [MFC]
- message handling [MFC], message handler functions
- mappings [MFC], message ranges
- command handling [MFC], command update handlers
- controls [MFC], notifications
- handler functions [MFC], message-map ranges
- handler functions [MFC]
- command update handlers [MFC]
- command routing [MFC], command update handlers
- message ranges [MFC]
- handler functions [MFC], declaring
- message ranges [MFC], mapping
ms.assetid: a271478b-5e1c-46f5-9f29-e5be44b27d08
ms.openlocfilehash: fc33df6957beab6e4e8de3093dfc00cf2651780e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370516"
---
# <a name="handlers-for-message-map-ranges"></a>Manipuladores para intervalos de mapa da mensagem

Este artigo explica como mapear uma série de mensagens para uma única função de manipulador de mensagens (em vez de mapear uma mensagem para apenas uma função).

Há momentos em que você precisa processar mais de uma mensagem ou notificação de controle exatamente da mesma maneira. Nesses momentos, você pode querer mapear todas as mensagens para uma única função de manipulador. Os intervalos de mapa de mensagens permitem que você faça isso para uma gama contígua de mensagens:

- Você pode mapear faixas de IDs de comando para:

  - Uma função de manipulador de comando.

  - Uma função de manipulador de atualização de comando.

- Você pode mapear mensagens de notificação de controle para uma série de IDs de controle para uma função de manipulador de mensagens.

Os tópicos abordados neste artigo incluem:

- [Escrevendo a entrada do mapa de mensagem](#_core_writing_the_message.2d.map_entry)

- [Declarando a função do manipulador](#_core_declaring_the_handler_function)

- [Exemplo para uma gama de IDs de comando](#_core_example_for_a_range_of_command_ids)

- [Exemplo para uma gama de IDs de controle](#_core_example_for_a_range_of_control_ids)

## <a name="writing-the-message-map-entry"></a><a name="_core_writing_the_message.2d.map_entry"></a>Escrevendo a entrada do mapa de mensagens

No . Arquivo CPP, adicione sua entrada de mapa de mensagem, como mostrado no exemplo a seguir:

[!code-cpp[NVC_MFCMessageHandling#6](../mfc/codesnippet/cpp/handlers-for-message-map-ranges_1.cpp)]

A entrada do mapa de mensagem consiste nos seguintes itens:

- A macro de intervalo de mapa de texto:

  - [ON_COMMAND_RANGE](reference/message-map-macros-mfc.md#on_command_range)

  - [ON_UPDATE_COMMAND_UI_RANGE](reference/message-map-macros-mfc.md#on_update_command_ui_range)

  - [ON_CONTROL_RANGE](reference/message-map-macros-mfc.md#on_control_range)

- Parâmetros para a macro:

  As duas primeiras macros levam três parâmetros:

  - O ID de comando que inicia o intervalo

  - O ID de comando que termina o intervalo

  - O nome da função manipuladora de mensagens

  A gama de iDs de comando deve ser contígua.

  A terceira `ON_CONTROL_RANGE`macro, , toma um primeiro parâmetro adicional: uma mensagem de notificação de controle, como **EN_CHANGE**.

## <a name="declaring-the-handler-function"></a><a name="_core_declaring_the_handler_function"></a>Declarando a função do manipulador

Adicione a declaração da função do manipulador no . Arquivo H. O código a seguir mostra como isso pode parecer, como mostrado abaixo:

[!code-cpp[NVC_MFCMessageHandling#7](../mfc/codesnippet/cpp/handlers-for-message-map-ranges_2.h)]

As funções do manipulador para comandos únicos normalmente não tomam parâmetros. Com exceção das funções do manipulador de atualização, as funções do manipulador para os intervalos de mapa de mensagem requerem um parâmetro extra, *nID,* do tipo **UINT**. Este parâmetro é o primeiro parâmetro. O parâmetro extra acomoda o ID de comando extra necessário para especificar qual comando o usuário realmente escolheu.

Para obter mais informações sobre os requisitos de parâmetros para atualizar funções do manipulador, consulte [Exemplo para uma gama de IDs de comando](#_core_example_for_a_range_of_command_ids).

## <a name="example-for-a-range-of-command-ids"></a><a name="_core_example_for_a_range_of_command_ids"></a>Exemplo para uma gama de IDs de comando

Quando você pode usar intervalos Um exemplo está em comandos de manuseio como o comando Zoom na amostra de MFC [HIERSVR](../overview/visual-cpp-samples.md). Este comando amplia a visualização, dimensionando-a entre 25% e 300% do seu tamanho normal. A classe de exibição do HIERSVR usa um intervalo para lidar com os comandos Zoom com uma entrada de mapa de mensagem semelhante a isso:

[!code-cpp[NVC_MFCMessageHandling#8](../mfc/codesnippet/cpp/handlers-for-message-map-ranges_3.cpp)]

Quando você escreve a entrada do mapa de mensagem, você especifica:

- Dois IDs de comando, começando e terminando um alcance contíguo.

   Aqui estão eles **ID_VIEW_ZOOM25** e **ID_VIEW_ZOOM300.**

- O nome da função de manipulador para os comandos.

   Aqui está. `OnZoom`

A declaração de função se assemelharia a isso:

[!code-cpp[NVC_MFCMessageHandling#9](../mfc/codesnippet/cpp/handlers-for-message-map-ranges_4.h)]

O caso das funções do manipulador de atualização é semelhante, e provavelmente será mais amplamente útil. É bastante comum `ON_UPDATE_COMMAND_UI` escrever manipuladores para uma série de comandos e encontrar-se escrevendo, ou copiando, o mesmo código várias vezes. A solução é mapear uma série de IDs de `ON_UPDATE_COMMAND_UI_RANGE` comando para uma função de manipulador de atualização usando a macro. Os IDs de comando devem formar um alcance contíguo. Por exemplo, consulte `OnUpdateZoom` o `ON_UPDATE_COMMAND_UI_RANGE` manipulador e sua entrada de mapa de mensagem na classe de exibição da amostra HIERSVR.

As funções do manipulador de atualização para comandos únicos normalmente `CCmdUI*`tomam um único parâmetro, *pCmdUI,* do tipo . Ao contrário das funções do manipulador, as funções de atualização do manipulador para os intervalos de mapa de mensagem não requerem um parâmetro extra, *nID,* do tipo **UINT**. O ID de comando, que é necessário para especificar `CCmdUI` qual comando o usuário realmente escolheu, é encontrado no objeto.

## <a name="example-for-a-range-of-control-ids"></a><a name="_core_example_for_a_range_of_control_ids"></a>Exemplo para uma gama de IDs de controle

Outro caso interessante é o mapeamento de mensagens de notificação de controle para uma gama de IDs de controle para um único manipulador. Suponha que o usuário pode clicar em qualquer um dos 10 botões. Para mapear todos os 10 botões para um manipulador, a entrada do mapa de mensagem seria assim:

[!code-cpp[NVC_MFCMessageHandling#10](../mfc/codesnippet/cpp/handlers-for-message-map-ranges_5.cpp)]

Quando você `ON_CONTROL_RANGE` escreve a macro no mapa de mensagens, você especifica:

- Uma mensagem de notificação de controle particular.

   Aqui está **BN_CLICKED.**

- Os valores de ID de controle associados à gama contígua de controles.

   Aqui estão **IDC_BUTTON1** e **IDC_BUTTON10.**

- O nome da função de manipulador de mensagens.

   Aqui está. `OnButtonClicked`

Ao escrever a função manipuladora, especifique o parâmetro **UINT** extra, conforme mostrado no seguinte:

[!code-cpp[NVC_MFCMessageHandling#11](../mfc/codesnippet/cpp/handlers-for-message-map-ranges_6.cpp)]

O `OnButtonClicked` manipulador de uma única mensagem **de BN_CLICKED** não tem parâmetros. O mesmo manipulador para uma gama de botões requer um **UINT**. O parâmetro extra permite identificar o controle particular responsável pela geração da mensagem **BN_CLICKED.**

O código mostrado no exemplo é típico: converter `int` o valor passado para um dentro do intervalo de mensagens e afirmar que este é o caso. Então você pode tomar alguma ação diferente dependendo de qual botão foi clicado.

## <a name="see-also"></a>Confira também

[Declarando funções de manipulador de mensagens](../mfc/declaring-message-handler-functions.md)
