---
title: "Manipuladores para intervalos de mapa da mensagem | Microsoft Docs"
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
  - "tratamento de comandos, manipuladores de atualização de comando"
  - "IDs de comando, mapeamento de mensagens"
  - "roteamento de comando, manipuladores de atualização de comando"
  - "manipuladores de atualização de comando"
  - "mensagens de notificação de controle"
  - "controles [MFC], notificações"
  - "funções de manipulador"
  - "funções de manipulador, declarando"
  - "funções de manipulador, intervalos de mapas de mensagens"
  - "manipuladores"
  - "manipuladores, intervalos de mapas de mensagens"
  - "mapeamentos, intervalos de mensagens"
  - "manipuladores de mensagens"
  - "lidando com erros, funções de manipulador de mensagens"
  - "mapas de mensagem, funções de manipulador de mensagens"
  - "mapas de mensagem, intervalos"
  - "intervalos de mensagens"
  - "intervalos de mensagens, mapeamento"
  - "intervalos de mapas de mensagens"
ms.assetid: a271478b-5e1c-46f5-9f29-e5be44b27d08
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Manipuladores para intervalos de mapa da mensagem
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo explica como mapear um intervalo de mensagens a uma única função de manipulador de mensagens \(em vez da mensagem de mapeamento um a apenas uma função\).  
  
 Há momentos em que você deseja processar exatamente da mesma maneira mais de uma notificação da mensagem ou o controle.  Em tais vezes, pode ser necessário mapear todas as mensagens para uma única função do manipulador.  Os intervalos retornadas mapa permitem que você faça isso para um intervalo contíguo de mensagens:  
  
-   Você pode mapear intervalos de IDs de comando:  
  
    -   Uma função de manipulador de comando.  
  
    -   Uma função de manipulador de atualização do comando.  
  
-   Você poderá mapear controle\- mensagens de notificação para um intervalo de IDs de controle para uma função de manipulador de mensagens.  
  
 Os tópicos abordados neste artigo incluem:  
  
-   [Escrevendo a entrada retornadas mapa](#_core_writing_the_message.2d.map_entry)  
  
-   [Declarando a função de manipulador](#_core_declaring_the_handler_function)  
  
-   [Exemplo de um intervalo de IDs de comando](#_core_example_for_a_range_of_command_ids)  
  
-   [Exemplo de um intervalo de IDs de controle](#_core_example_for_a_range_of_control_ids)  
  
##  <a name="_core_writing_the_message.2d.map_entry"></a> Escrevendo a entrada retornadas mapa  
 No arquivo de .CPP, adicione sua entrada retornadas mapa, conforme mostrado no seguinte exemplo:  
  
 [!CODE [NVC_MFCMessageHandling#6](../CodeSnippet/VS_Snippets_Cpp/NVC_MFCMessageHandling#6)]  
  
 A entrada retornadas mapa consiste nos seguintes itens:  
  
-   A macro do intervalo retornadas mapa:  
  
    -   [ON\_COMMAND\_RANGE](../Topic/ON_COMMAND_RANGE.md)  
  
    -   [ON\_UPDATE\_COMMAND\_UI\_RANGE](../Topic/ON_UPDATE_COMMAND_UI_RANGE.md)  
  
    -   [ON\_CONTROL\_RANGE](../Topic/ON_CONTROL_RANGE.md)  
  
-   Parâmetros a macro:  
  
     Os dois primeiros macros usam três parâmetros:  
  
    -   A ID de comando que inicia o intervalo  
  
    -   A ID de comando que encerra o intervalo  
  
    -   O nome da função de manipulador de mensagens  
  
     O intervalo de IDs de comando deve ser contíguas.  
  
     O terceiro macro, `ON_CONTROL_RANGE`, faça um primeiro parâmetro adicional: uma mensagem de controle\- notificação, como **EN\_CHANGE**.  
  
##  <a name="_core_declaring_the_handler_function"></a> Declarando a função de manipulador  
 Adicionar sua declaração de função de manipulador no. Arquivo de H.  O código a seguir mostra como isso pode ter, conforme mostrado abaixo:  
  
 [!CODE [NVC_MFCMessageHandling#7](../CodeSnippet/VS_Snippets_Cpp/NVC_MFCMessageHandling#7)]  
  
 As funções do manipulador para um único comandos geralmente não têm nenhum parâmetro.  Com exceção das funções do manipulador de atualização, as funções do manipulador para intervalos retornadas mapa exigem um parâmetro adicional, `nID`, do tipo **UINT**.  Esse parâmetro será o primeiro parâmetro.  O parâmetro adicional para acomodar a ID de comando adicionais necessário especificar um comando que o usuário escolhidos de fato.  
  
 Para obter mais informações sobre os requisitos de parâmetro para atualizar funções de manipulador [Exemplo de um intervalo de IDs de comando](#_core_example_for_a_range_of_command_ids), consulte.  
  
##  <a name="_core_example_for_a_range_of_command_ids"></a> Exemplo de um intervalo de IDs de comando  
 Quando você pode usar intervalos?  Um exemplo é em comandos de manipulação como o comando de zoom no exemplo [HIERSVR](../top/visual-cpp-samples.md)MFC.  Este comando aplicar zoom a exibição, dimensionando um entre 25% e 300% de seu tamanho regular.  A classe da exibição de HIERSVR usar um intervalo para controlar os comandos de zoom com uma entrada retornadas mapa que é semelhante a esta:  
  
 [!CODE [NVC_MFCMessageHandling#8](../CodeSnippet/VS_Snippets_Cpp/NVC_MFCMessageHandling#8)]  
  
 Quando você grava a entrada retornadas mapa, você especifica:  
  
-   Duas IDs, o inicia finais e do comando um intervalo contíguo.  
  
     Aqui são `ID_VIEW_ZOOM25` e `ID_VIEW_ZOOM300`.  
  
-   O nome da função de manipulador para os comandos.  
  
     Aqui está `OnZoom`.  
  
 A declaração de função seria semelhante a esta:  
  
 [!CODE [NVC_MFCMessageHandling#9](../CodeSnippet/VS_Snippets_Cpp/NVC_MFCMessageHandling#9)]  
  
 Exemplos de funções do manipulador de atualização são semelhantes, e mais probabilidade de ser muito úteis.  É o bastante comum gravar manipuladores de `ON_UPDATE_COMMAND_UI` para um número de comandos e localizar\-se gravação, ou copiando, o mesmo codifica repetidamente.  A solução é mapear um intervalo de IDs de comando a uma função de manipulador de atualização usando a macro de `ON_UPDATE_COMMAND_UI_RANGE` .  As IDs de comando devem formar um intervalo contíguo.  Para obter um exemplo, consulte o manipulador de **OnUpdateZoom** e sua entrada retornadas mapa de `ON_UPDATE_COMMAND_UI_RANGE` na exibição de exemplo de HIERSVR classificar.  
  
 As funções de manipulador de atualização para um único comandos assumem normalmente um único parâmetro, `pCmdUI`, do tipo **CCmdUI\***.  Diferentemente de funções do manipulador, as funções de manipulador de atualização para intervalos retornadas mapa não exigem um parâmetro adicional, `nID`, do tipo **UINT**.  A ID de comando, que é necessário para especificar que o comando usuário escolhidos na verdade, é localizado no objeto de `CCmdUI` .  
  
##  <a name="_core_example_for_a_range_of_control_ids"></a> Exemplo de um intervalo de IDs de controle  
 Outros casos são interessantes mapeando controle\- mensagens de notificação para um intervalo de IDs de controle em um único manipulador.  Suponha que o usuário pode clicar em qualquer um de 10 botões.  Para mapear todos os 10 botões para um manipulador, sua entrada retornadas mapa teria a seguinte aparência:  
  
 [!CODE [NVC_MFCMessageHandling#10](../CodeSnippet/VS_Snippets_Cpp/NVC_MFCMessageHandling#10)]  
  
 Quando você grava a macro de `ON_CONTROL_RANGE` em seu mapa da mensagem, você especifica:  
  
-   Uma mensagem específica de controle\- notificação.  
  
     Aqui está **BN\_CLICKED**.  
  
-   Os valores de ID de controle associados ao intervalo contíguo dos controles.  
  
     Aqui estão `IDC_BUTTON1` e `IDC_BUTTON10`.  
  
-   O nome da função de manipulador de mensagens.  
  
     Aqui está `OnButtonClicked`.  
  
 Quando você grava a função de manipulador, especifique o parâmetro adicional de **UINT** , conforme mostrado a seguir:  
  
 [!CODE [NVC_MFCMessageHandling#11](../CodeSnippet/VS_Snippets_Cpp/NVC_MFCMessageHandling#11)]  
  
 O manipulador de `OnButtonClicked` para uma única mensagem de **BN\_CLICKED** não usa nenhum parâmetro.  O mesmo manipulador para um intervalo dos botões usa um **UINT**.  O parâmetro adicional permite que identifica o controle específico responsável para gerar a mensagem de **BN\_CLICKED** .  
  
 O código mostrado no exemplo é típico: convertendo o valor passado para `int` dentro do intervalo da mensagem e afirmar que esse é o caso.  Então você pode executar alguma ação diferente dependendo do usuário clicou no botão.  
  
## Consulte também  
 [Declarando funções de manipulador de mensagens](../mfc/declaring-message-handler-functions.md)