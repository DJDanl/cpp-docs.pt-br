---
title: Manipuladores para intervalos de mapas de mensagem | Microsoft Docs
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
ms.openlocfilehash: 896977da8ca57cc17a9fa3b7864e1744ee07f35d
ms.sourcegitcommit: 060f381fe0807107ec26c18b46d3fcb859d8d2e7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/25/2018
ms.locfileid: "36930817"
---
# <a name="handlers-for-message-map-ranges"></a>Manipuladores para intervalos de mapa da mensagem
Este artigo explica como mapear um intervalo de mensagens para uma função de manipulador de mensagem única (em vez de mapeamento de uma mensagem para apenas uma função).  
  
 Há ocasiões em que você precisa para processar mais de uma notificação de mensagem ou controle exatamente da mesma maneira. Esse tempo, você pode desejar mapear todas as mensagens para uma função de manipulador único. Intervalos de mapas de mensagem permite que você faça isso para um intervalo contíguo de mensagens:  
  
-   Você pode mapear os intervalos de IDs de comando para:  
  
    -   Uma função de manipulador de comando.  
  
    -   Uma função de manipulador de atualização de comando.  
  
-   Você pode mapear as mensagens de notificação de controle para um intervalo de IDs de controle para uma função de manipulador de mensagens.  
  
 Os tópicos abordados neste artigo incluem:  
  
-   [Gravar a entrada de mapa de mensagem](#_core_writing_the_message.2d.map_entry)  
  
-   [Declarar a função de manipulador](#_core_declaring_the_handler_function)  
  
-   [Exemplo de um intervalo de IDs de comando](#_core_example_for_a_range_of_command_ids)  
  
-   [Exemplo de um intervalo de IDs de controle](#_core_example_for_a_range_of_control_ids)  
  
##  <a name="_core_writing_the_message.2d.map_entry"></a> Gravar a entrada de mapa de mensagem  
 No. CPP de arquivo, adicione a entrada de mapa de mensagem, conforme mostrado no exemplo a seguir:  
  
 [!code-cpp[NVC_MFCMessageHandling#6](../mfc/codesnippet/cpp/handlers-for-message-map-ranges_1.cpp)]  
  
 A entrada de mapa de mensagem consiste dos seguintes itens:  
  
-   A macro de intervalo de mapa de mensagem:  
  
    -   [ON_COMMAND_RANGE](reference/message-map-macros-mfc.md#on_command_range)  
  
    -   [ON_UPDATE_COMMAND_UI_RANGE](reference/message-map-macros-mfc.md#on_update_command_ui_range)  
  
    -   [ON_CONTROL_RANGE](reference/message-map-macros-mfc.md#on_control_range)  
  
-   Parâmetros da macro:  
  
     As primeiras duas macros aceita três parâmetros:  
  
    -   A ID de comando que inicia o intervalo  
  
    -   A ID de comando que termina o intervalo  
  
    -   O nome da função de manipulador de mensagens  
  
     O intervalo de IDs de comando deve ser contíguo.  
  
     A macro de terceira, `ON_CONTROL_RANGE`, aceita um parâmetro primeiro adicional: uma notificação de controle de mensagens, como **EN_CHANGE**.  
  
##  <a name="_core_declaring_the_handler_function"></a> Declarar a função de manipulador  
 Adicione a declaração de função de manipulador em de. Arquivo de H. O código a seguir mostra como isso pode parecer, conforme mostrado abaixo:  
  
 [!code-cpp[NVC_MFCMessageHandling#7](../mfc/codesnippet/cpp/handlers-for-message-map-ranges_2.h)]  
  
 Funções do manipulador de comandos único normalmente não usam parâmetros. Com exceção das funções de manipulador de atualização, as funções de manipulador para intervalos de mapas de mensagem requerem um parâmetro extra, *nID*, do tipo **UINT**. Esse parâmetro é o primeiro parâmetro. O parâmetro extra acomoda a ID de comando adicionais necessária para especificar que o usuário escolheu realmente de comando.  
  
 Para obter mais informações sobre requisitos de parâmetros para funções de manipulador de atualização, consulte [para um intervalo de IDs de comando de exemplo](#_core_example_for_a_range_of_command_ids).  
  
##  <a name="_core_example_for_a_range_of_command_ids"></a> Exemplo para as IDs de um intervalo de comando  
 Quando você pode usar intervalos é um exemplo de tratamento de comandos, como o comando Zoom no exemplo do MFC [HIERSVR](../visual-cpp-samples.md). Este comando amplia o modo de exibição, dimensioná-lo entre 25% e 300% de seu tamanho normal. Classe de exibição do HIERSVR usa um intervalo para lidar com os comandos de Zoom com uma entrada de mapa de mensagem semelhante a isso:  
  
 [!code-cpp[NVC_MFCMessageHandling#8](../mfc/codesnippet/cpp/handlers-for-message-map-ranges_3.cpp)]  
  
 Quando você gravar a entrada de mapa de mensagem, especifique:  
  
-   Dois IDs, abertura e fechamento de um intervalo contíguo de comando.  
  
     Aqui estão elas **ID_VIEW_ZOOM25** e **ID_VIEW_ZOOM300**.  
  
-   O nome da função de manipulador para os comandos.  
  
     Aqui é `OnZoom`.  
  
 A declaração da função é semelhante a isto:  
  
 [!code-cpp[NVC_MFCMessageHandling#9](../mfc/codesnippet/cpp/handlers-for-message-map-ranges_4.h)]  
  
 No caso de funções de manipulador de atualização é semelhante e provavelmente serão mais úteis. É muito comum gravar `ON_UPDATE_COMMAND_UI` manipuladores para um número de comandos e perceber que está gravando ou cópia, o mesmo código repetidamente. A solução é mapear um intervalo de IDs para um uso da função de manipulador de atualização de comando do `ON_UPDATE_COMMAND_UI_RANGE` macro. As IDs de comando devem formar um intervalo contíguo. Para obter um exemplo, consulte o `OnUpdateZoom` manipulador e sua `ON_UPDATE_COMMAND_UI_RANGE` entrada de mapa de mensagens na classe de exibição do exemplo HIERSVR.  
  
 Atualizar funções de manipulador de comandos único normalmente têm um único parâmetro, *pCmdUI*, do tipo `CCmdUI*`. Diferente das funções de manipulador, funções de manipulador de atualização para intervalos de mapas de mensagem não exigem um parâmetro extra, *nID*, do tipo **UINT**. A ID de comando, que é necessário para especificar quais comandos que o usuário realmente escolhido, foi encontrada no `CCmdUI` objeto.  
  
##  <a name="_core_example_for_a_range_of_control_ids"></a> Exemplo de um controle de intervalo de IDs  
 Outro caso interessante está mapeando mensagens de notificação de controle para um intervalo de IDs de controle para um único manipulador. Suponha que o usuário pode clicar em qualquer um dos botões de 10. Para mapear todos os botões de 10 para um manipulador, sua entrada de mapa de mensagem teria esta aparência:  
  
 [!code-cpp[NVC_MFCMessageHandling#10](../mfc/codesnippet/cpp/handlers-for-message-map-ranges_5.cpp)]  
  
 Quando você escreve o `ON_CONTROL_RANGE` macro em seu mapa de mensagem, especifique:  
  
-   Uma mensagem de notificação de controle específico.  
  
     Aqui é **BN_CLICKED**.  
  
-   Os valores de ID do controle associados ao intervalo contíguo de controles.  
  
     Aqui são **IDC_BUTTON1** e **IDC_BUTTON10**.  
  
-   O nome da função de manipulador de mensagens.  
  
     Aqui é `OnButtonClicked`.  
  
 Quando você escreve a função do manipulador, especifique o extra **UINT** parâmetro, conforme mostrado no exemplo a seguir:  
  
 [!code-cpp[NVC_MFCMessageHandling#11](../mfc/codesnippet/cpp/handlers-for-message-map-ranges_6.cpp)]  
  
 O `OnButtonClicked` manipulador para um único **BN_CLICKED** mensagem não usa nenhum parâmetro. O mesmo manipulador para um intervalo de botões usa uma **UINT**. Permite que o parâmetro extra para identificar o controle específico responsável por gerar o **BN_CLICKED** mensagem.  
  
 O código mostrado no exemplo é típico: Convertendo o valor passado para um `int` dentro do intervalo de mensagem e afirmando que esse é o caso. Em seguida, você poderia usar alguma ação diferente, dependendo de qual botão foi clicado.  
  
## <a name="see-also"></a>Consulte também  
 [Declarando funções de manipulador de mensagens](../mfc/declaring-message-handler-functions.md)
