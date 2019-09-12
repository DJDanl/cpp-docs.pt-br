---
title: Macro ON_UPDATE_COMMAND_UI
ms.date: 09/06/2019
f1_keywords:
- ON_UPDATE_COMMAND_UI
helpviewer_keywords:
- ON_UPDATE_COMMAND_UI macro [MFC]
- update handlers [MFC]
- command-handler macros
- updating user-interface objects [MFC]
ms.assetid: 3e72b50f-4119-4c82-81cf-6e09b132de05
ms.openlocfilehash: 467e130f3e6518cc4ec554f6574fb9fcbabaf1f3
ms.sourcegitcommit: 3caf5261b3ea80d9cf14038c116ba981d655cd13
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/11/2019
ms.locfileid: "70907947"
---
# <a name="on_update_command_ui-macro"></a>Macro ON_UPDATE_COMMAND_UI

Para conectar um objeto de interface de usuário a um manipulador de atualização de comando em um objeto de destino de comando, abra **modo de exibição de classe**, clique com o botão direito do mouse na classe à qual o manipulador será adicionado e escolha **Assistente de classe**. Localize a ID do objeto da interface do usuário na lista à esquerda, escolha **UPDATE_COMMAND_UI** no painel direito e clique em **Adicionar manipulador**. Isso cria uma função de manipulador na classe e adiciona a entrada apropriada no mapa de mensagens. Consulte [mapeando mensagens para o Functions](../mfc/reference/mapping-messages-to-functions.md) para obter mais informações. Você pode especificar mensagens adicionais para lidar com o painel **mensagens** . 

Por exemplo, para atualizar um comando limpar tudo no menu Editar do seu programa, use o **Assistente de classe** para adicionar uma entrada de mapa de mensagem na classe selecionada, uma declaração de função para um manipulador de atualização `OnUpdateEditClearAll` de comando chamado na declaração de classe e um vazio modelo de função no arquivo de implementação da classe. O protótipo de função tem esta aparência:

[!code-cpp[NVC_MFCDocView#2](../mfc/codesnippet/cpp/on-update-command-ui-macro_1.h)]

Como todos os manipuladores, a declaração da função mostra a palavra-chave **afx_msg** . Como todos os manipuladores de atualização, ele usa um argumento, um ponteiro `CCmdUI` para um objeto.

## <a name="see-also"></a>Consulte também

[Como: atualizar objetos de interface do usuário](../mfc/how-to-update-user-interface-objects.md)
