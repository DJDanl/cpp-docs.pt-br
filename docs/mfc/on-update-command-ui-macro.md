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
ms.openlocfilehash: ba5a48fabb9142c080e688e189e0983ad5ba2eda
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84624058"
---
# <a name="on_update_command_ui-macro"></a>Macro ON_UPDATE_COMMAND_UI

Para conectar um objeto de interface de usuário a um manipulador de atualização de comando em um objeto de destino de comando, abra **modo de exibição de classe**, clique com o botão direito do mouse na classe à qual o manipulador será adicionado e escolha **Assistente de classe**. Localize a ID do objeto da interface do usuário na lista à esquerda, escolha **UPDATE_COMMAND_UI** no painel direito e clique em **Adicionar manipulador**. Isso cria uma função de manipulador na classe e adiciona a entrada apropriada no mapa de mensagens. Consulte [mapeando mensagens para o Functions](reference/mapping-messages-to-functions.md) para obter mais informações. Você pode especificar mensagens adicionais para lidar com o painel **mensagens** .

Por exemplo, para atualizar um comando limpar tudo no menu Editar do seu programa, use o **Assistente de classe** para adicionar uma entrada de mapa de mensagem na classe selecionada, uma declaração de função para um manipulador de atualização de comando chamado `OnUpdateEditClearAll` na declaração de classe e um modelo de função vazio no arquivo de implementação da classe. O protótipo de função tem esta aparência:

[!code-cpp[NVC_MFCDocView#2](codesnippet/cpp/on-update-command-ui-macro_1.h)]

Como todos os manipuladores, a declaração da função mostra a palavra-chave **afx_msg** . Como todos os manipuladores de atualização, ele usa um argumento, um ponteiro para um `CCmdUI` objeto.

## <a name="see-also"></a>Consulte também

[Como atualizar objetos da interface do usuário](how-to-update-user-interface-objects.md)
