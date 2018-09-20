---
title: Macro ON_UPDATE_COMMAND_UI | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- ON_UPDATE_COMMAND_UI
dev_langs:
- C++
helpviewer_keywords:
- ON_UPDATE_COMMAND_UI macro [MFC]
- update handlers [MFC]
- command-handler macros
- updating user-interface objects [MFC]
ms.assetid: 3e72b50f-4119-4c82-81cf-6e09b132de05
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 17111e24a63d527996eadd82c804e5147ad78552
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46433459"
---
# <a name="onupdatecommandui-macro"></a>Macro ON_UPDATE_COMMAND_UI

Use o **propriedades** janela para se conectar a um objeto de interface do usuário a um manipulador de atualização de comando em um objeto de destino do comando. Ele automaticamente será conectar-se a ID do objeto de interface do usuário para a macro ON_UPDATE_COMMAND_UI e criar um manipulador no objeto que irá manipular a atualização. Ver [mapeando mensagens para funções](../mfc/reference/mapping-messages-to-functions.md) para obter mais informações.

Por exemplo, para atualizar um comando Limpar tudo no menu Editar do seu programa, use o **propriedades** janela para adicionar uma entrada de mapa de mensagens na classe escolhida, uma declaração de função para um manipulador de atualização de comando chamada `OnUpdateEditClearAll` na classe declaração e um modelo de função vazios no arquivo de implementação da classe. O protótipo de função tem esta aparência:

[!code-cpp[NVC_MFCDocView#2](../mfc/codesnippet/cpp/on-update-command-ui-macro_1.h)]

Todos os manipuladores, mostra a função, como o **afx_msg** palavra-chave. Como todos os manipuladores de atualização, ele usa um argumento, um ponteiro para um `CCmdUI` objeto.

## <a name="see-also"></a>Consulte também

[Como atualizar objetos da interface do usuário](../mfc/how-to-update-user-interface-objects.md)

