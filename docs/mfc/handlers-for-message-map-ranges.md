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
ms.openlocfilehash: 0ff9178679792929bbd6eb92bb6148cfa008dcad
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84621687"
---
# <a name="handlers-for-message-map-ranges"></a>Manipuladores para intervalos de mapa da mensagem

Este artigo explica como mapear um intervalo de mensagens para uma única função de manipulador de mensagens (em vez de mapear uma mensagem para apenas uma função).

Há ocasiões em que você precisa processar mais de uma mensagem ou uma notificação de controle exatamente da mesma maneira. Nesses momentos, talvez você queira mapear todas as mensagens para uma única função de manipulador. Os intervalos de mapa de mensagens permitem que você faça isso para um intervalo contíguo de mensagens:

- Você pode mapear intervalos de IDs de comando para:

  - Uma função de manipulador de comandos.

  - Uma função de manipulador de atualização de comando.

- Você pode mapear mensagens de notificação de controle para um intervalo de IDs de controle para uma função de manipulador de mensagens.

Os tópicos abordados neste artigo incluem:

- [Gravando a entrada do mapa de mensagens](#_core_writing_the_message.2d.map_entry)

- [Declarando a função do manipulador](#_core_declaring_the_handler_function)

- [Exemplo de um intervalo de IDs de comando](#_core_example_for_a_range_of_command_ids)

- [Exemplo de um intervalo de IDs de controle](#_core_example_for_a_range_of_control_ids)

## <a name="writing-the-message-map-entry"></a><a name="_core_writing_the_message.2d.map_entry"></a>Gravando a entrada do mapa de mensagens

No. Arquivo CPP, adicione sua entrada de mapa de mensagem, conforme mostrado no exemplo a seguir:

[!code-cpp[NVC_MFCMessageHandling#6](codesnippet/cpp/handlers-for-message-map-ranges_1.cpp)]

A entrada do mapa de mensagens consiste nos seguintes itens:

- A macro do intervalo do mapa de mensagens:

  - [ON_COMMAND_RANGE](reference/message-map-macros-mfc.md#on_command_range)

  - [ON_UPDATE_COMMAND_UI_RANGE](reference/message-map-macros-mfc.md#on_update_command_ui_range)

  - [ON_CONTROL_RANGE](reference/message-map-macros-mfc.md#on_control_range)

- Parâmetros para a macro:

  As duas primeiras macros usam três parâmetros:

  - A ID de comando que inicia o intervalo

  - A ID de comando que termina o intervalo

  - O nome da função do manipulador de mensagens

  O intervalo de IDs de comando deve ser contíguo.

  A terceira macro, `ON_CONTROL_RANGE` , usa um primeiro parâmetro adicional: uma mensagem de notificação de controle, como **EN_CHANGE**.

## <a name="declaring-the-handler-function"></a><a name="_core_declaring_the_handler_function"></a>Declarando a função do manipulador

Adicione sua declaração de função de manipulador no. Arquivo H. O código a seguir mostra como isso pode parecer, como mostrado abaixo:

[!code-cpp[NVC_MFCMessageHandling#7](codesnippet/cpp/handlers-for-message-map-ranges_2.h)]

Funções de manipulador para comandos únicos normalmente não usam parâmetros. Com exceção das funções do manipulador de atualização, as funções de manipulador para intervalos de mapa de mensagem exigem um parâmetro extra, *NID*, do tipo **uint**. Esse parâmetro é o primeiro parâmetro. O parâmetro extra acomoda a ID de comando extra necessária para especificar qual comando o usuário realmente escolheu.

Para obter mais informações sobre os requisitos de parâmetro para atualizar funções de manipulador, consulte [exemplo para um intervalo de IDs de comando](#_core_example_for_a_range_of_command_ids).

## <a name="example-for-a-range-of-command-ids"></a><a name="_core_example_for_a_range_of_command_ids"></a>Exemplo de um intervalo de IDs de comando

Quando você pode usar intervalos, um exemplo é manipular comandos como o comando de zoom no exemplo do MFC [HIERSVR](../overview/visual-cpp-samples.md). Esse comando amplia a exibição, dimensionando-a entre 25% e 300% de seu tamanho normal. A classe de exibição do HIERSVR usa um intervalo para lidar com os comandos de zoom com uma entrada de mapa de mensagem semelhante a esta:

[!code-cpp[NVC_MFCMessageHandling#8](codesnippet/cpp/handlers-for-message-map-ranges_3.cpp)]

Ao gravar a entrada do mapa de mensagens, você especifica:

- Duas IDs de comando, começando e terminando um intervalo contíguo.

   Aqui, eles são **ID_VIEW_ZOOM25** e **ID_VIEW_ZOOM300**.

- O nome da função do manipulador para os comandos.

   Aqui está `OnZoom` .

A declaração da função seria semelhante a esta:

[!code-cpp[NVC_MFCMessageHandling#9](codesnippet/cpp/handlers-for-message-map-ranges_4.h)]

O caso das funções do manipulador de atualização é semelhante e provavelmente será mais útil. É muito comum escrever `ON_UPDATE_COMMAND_UI` manipuladores para vários comandos e encontrar você mesmo escrever, ou copiar, o mesmo código repetidamente. A solução é mapear um intervalo de IDs de comando para uma função de manipulador de atualização usando a `ON_UPDATE_COMMAND_UI_RANGE` macro. As IDs de comando devem formar um intervalo contíguo. Para obter um exemplo, consulte o `OnUpdateZoom` manipulador e sua `ON_UPDATE_COMMAND_UI_RANGE` entrada de mapa de mensagem na classe de exibição do exemplo HIERSVR.

As funções do manipulador de atualização para comandos únicos normalmente usam um único parâmetro, *pCmdUI*, do tipo `CCmdUI*` . Diferentemente das funções de manipulador, as funções de manipulador de atualização para intervalos de mapa de mensagem não exigem um parâmetro extra, *NID*, do tipo **uint**. A ID de comando, que é necessária para especificar qual comando o usuário realmente escolheu, é encontrado no `CCmdUI` objeto.

## <a name="example-for-a-range-of-control-ids"></a><a name="_core_example_for_a_range_of_control_ids"></a>Exemplo de um intervalo de IDs de controle

Outro caso interessante é o mapeamento de mensagens de notificação de controle para um intervalo de IDs de controle para um único manipulador. Suponha que o usuário possa clicar em qualquer um dos 10 botões. Para mapear todos os 10 botões para um manipulador, sua entrada de mapa de mensagens ficaria assim:

[!code-cpp[NVC_MFCMessageHandling#10](codesnippet/cpp/handlers-for-message-map-ranges_5.cpp)]

Ao escrever a `ON_CONTROL_RANGE` macro em seu mapa de mensagens, você especifica:

- Uma mensagem de notificação de controle específica.

   Aqui está **BN_CLICKED**.

- Os valores de ID de controle associados ao intervalo contíguo de controles.

   Aqui estão **IDC_BUTTON1** e **IDC_BUTTON10**.

- O nome da função do manipulador de mensagens.

   Aqui está `OnButtonClicked` .

Ao gravar a função do manipulador, especifique o parâmetro **uint** extra, conforme mostrado a seguir:

[!code-cpp[NVC_MFCMessageHandling#11](codesnippet/cpp/handlers-for-message-map-ranges_6.cpp)]

O `OnButtonClicked` manipulador de uma única mensagem de **BN_CLICKED** não usa parâmetros. O mesmo manipulador para um intervalo de botões recebe um **uint**. O parâmetro extra permite identificar o controle específico responsável pela geração da mensagem de **BN_CLICKED** .

O código mostrado no exemplo é típico: convertendo o valor passado para um `int` dentro do intervalo de mensagens e afirmando que esse é o caso. Em seguida, você pode executar alguma ação diferente, dependendo de qual botão foi clicado.

## <a name="see-also"></a>Consulte também

[Declarando funções de manipulador de mensagens](declaring-message-handler-functions.md)
