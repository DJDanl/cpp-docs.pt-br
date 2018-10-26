---
title: Manipuladores para intervalos de mapa de mensagem | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 738d441cf88b41740cb0cff933916489cac683f2
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50073091"
---
# <a name="handlers-for-message-map-ranges"></a>Manipuladores para intervalos de mapa da mensagem

Este artigo explica como mapear um intervalo de mensagens para uma função de manipulador de mensagens única (em vez de mapeamento de uma mensagem para apenas uma função).

Há ocasiões em que você precisa processar mais de uma notificação de mensagem ou controle exatamente da mesma maneira. Em tais momentos, você pode desejar mapear todas as mensagens para uma função de manipulador único. Intervalos de mapa de mensagem permite que você faça isso para um intervalo contíguo de mensagens:

- Você pode mapear os intervalos de IDs de comando para:

   - Uma função de manipulador de comando.

   - Uma função de manipulador de atualização de comando.

- Você pode mapear as mensagens de notificação de controle para um intervalo de IDs de controle para uma função de manipulador de mensagens.

Os tópicos abordados neste artigo incluem:

- [Gravar a entrada de mapa de mensagem](#_core_writing_the_message.2d.map_entry)

- [Declarar a função do manipulador](#_core_declaring_the_handler_function)

- [Exemplo de um intervalo de IDs de comando](#_core_example_for_a_range_of_command_ids)

- [Exemplo de um intervalo de IDs de controle](#_core_example_for_a_range_of_control_ids)

##  <a name="_core_writing_the_message.2d.map_entry"></a> Gravar a entrada de mapa de mensagem

Na. CPP arquivo, adicione sua entrada de mapa de mensagem, conforme mostrado no exemplo a seguir:

[!code-cpp[NVC_MFCMessageHandling#6](../mfc/codesnippet/cpp/handlers-for-message-map-ranges_1.cpp)]

A entrada de mapa de mensagens consiste dos seguintes itens:

- A macro de intervalo de mapa de mensagem:

   - [ON_COMMAND_RANGE](reference/message-map-macros-mfc.md#on_command_range)

   - [ON_UPDATE_COMMAND_UI_RANGE](reference/message-map-macros-mfc.md#on_update_command_ui_range)

   - [ON_CONTROL_RANGE](reference/message-map-macros-mfc.md#on_control_range)

- Parâmetros para a macro:

   As duas primeiras macros usam três parâmetros:

   - A ID de comando que inicia o intervalo

   - A ID de comando que encerra o intervalo

   - O nome da função de manipulador de mensagens

   O intervalo de IDs de comando deve ser contíguo.

   Terceira macro `ON_CONTROL_RANGE`, usa um parâmetro adicional de primeira: uma notificação de controle de mensagens, como **eventos EN_CHANGE**.

##  <a name="_core_declaring_the_handler_function"></a> Declarar a função do manipulador

Adicione a declaração de função de manipulador na. Arquivo de H. O código a seguir mostra como isso possa parecer, conforme mostrado abaixo:

[!code-cpp[NVC_MFCMessageHandling#7](../mfc/codesnippet/cpp/handlers-for-message-map-ranges_2.h)]

Funções de manipulador de comandos únicos normalmente não usam parâmetros. Com exceção de funções de manipulador de atualização, as funções de manipulador para os intervalos de mapa de mensagens exigem um parâmetro extra, *nID*, do tipo **UINT**. Esse parâmetro é o primeiro parâmetro. O parâmetro extra acomoda a ID de comando adicionais necessária para especificar que o usuário escolher, na verdade, de comando.

Para obter mais informações sobre os requisitos de parâmetro para funções de manipulador de atualização, consulte [para um intervalo de IDs de comando de exemplo](#_core_example_for_a_range_of_command_ids).

##  <a name="_core_example_for_a_range_of_command_ids"></a> Exemplo de um intervalo de IDs de comando

Quando você pode usar intervalos de um exemplo é na manipulação de comandos, como o comando de Zoom no exemplo de MFC [HIERSVR](../visual-cpp-samples.md). Esse comando amplia a exibição, dimensioná-lo entre 25% e 300% de seu tamanho normal. Classe de exibição do HIERSVR usa um intervalo para lidar com os comandos de Zoom com uma entrada de mapa de mensagem que se assemelha a isto:

[!code-cpp[NVC_MFCMessageHandling#8](../mfc/codesnippet/cpp/handlers-for-message-map-ranges_3.cpp)]

Quando você escreve a entrada de mapa de mensagem, especifique:

- Dois IDs, começando e terminando em um intervalo contíguo de comando.

   Aqui estão elas **ID_VIEW_ZOOM25** e **ID_VIEW_ZOOM300**.

- O nome da função de manipulador para os comandos.

   Aqui ele tem `OnZoom`.

A declaração de função seria semelhante a isso:

[!code-cpp[NVC_MFCMessageHandling#9](../mfc/codesnippet/cpp/handlers-for-message-map-ranges_4.h)]

No caso de funções de manipulador de atualização é semelhante e provavelmente serão úteis mais amplamente. É muito comum gravar `ON_UPDATE_COMMAND_UI` manipuladores para um número de comandos e acaba escrevendo ou copiando, o mesmo código repetidamente. A solução é mapear um intervalo de comando de atualização de IDs para um manipulador de funções usando o `ON_UPDATE_COMMAND_UI_RANGE` macro. As IDs de comando devem formar um intervalo contíguo. Por exemplo, consulte o `OnUpdateZoom` manipulador e seu `ON_UPDATE_COMMAND_UI_RANGE` entrada de mapa de mensagens na classe de exibição do exemplo HIERSVR.

Atualizar funções de manipulador de comandos únicos normalmente utilizam um único parâmetro, *pCmdUI*, do tipo `CCmdUI*`. Diferentemente das funções de manipulador, funções de manipulador de atualização para os intervalos de mapa de mensagens não exigem um parâmetro extra, *nID*, do tipo **UINT**. A ID de comando, que é necessária para especificar qual comando o usuário escolheu na verdade, é encontrada na `CCmdUI` objeto.

##  <a name="_core_example_for_a_range_of_control_ids"></a> Exemplo de um controle de intervalo de IDs

Outro caso interessante está mapeando as mensagens de notificação de controle para um intervalo de IDs de controle para um único manipulador. Suponha que o usuário pode clicar em qualquer um dos botões de 10. Para mapear todos os botões de 10 para um manipulador, sua entrada de mapa de mensagem teria esta aparência:

[!code-cpp[NVC_MFCMessageHandling#10](../mfc/codesnippet/cpp/handlers-for-message-map-ranges_5.cpp)]

Quando você escreve o `ON_CONTROL_RANGE` macro em seu mapa de mensagem, especifique:

- Uma mensagem de notificação de controle específico.

   Aqui ele tem **BN_CLICKED**.

- Os valores de ID de controle associados ao intervalo contíguo de controles.

   Aqui, existem **IDC_BUTTON1** e **IDC_BUTTON10**.

- O nome da função de manipulador de mensagens.

   Aqui ele tem `OnButtonClicked`.

Quando você escreve a função do manipulador, especifique o extra **UINT** parâmetro, conforme mostrado a seguir:

[!code-cpp[NVC_MFCMessageHandling#11](../mfc/codesnippet/cpp/handlers-for-message-map-ranges_6.cpp)]

O `OnButtonClicked` manipulador para uma única **BN_CLICKED** mensagem não usa nenhum parâmetro. O mesmo manipulador para um intervalo de botões usa um **UINT**. Permite que o parâmetro extra para identificar o controle específico responsável por gerar o **BN_CLICKED** mensagem.

O código mostrado no exemplo é típico: Convertendo o valor passado para um `int` dentro do intervalo de mensagem e declarando que este é o caso. Em seguida, você pode levar a alguma ação diferente, dependendo de qual botão foi clicado.

## <a name="see-also"></a>Consulte também

[Declarando funções de manipulador de mensagens](../mfc/declaring-message-handler-functions.md)
