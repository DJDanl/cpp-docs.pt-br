---
title: Macro ON_UPDATE_COMMAND_UI | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: ON_UPDATE_COMMAND_UI
dev_langs: C++
helpviewer_keywords:
- ON_UPDATE_COMMAND_UI macro [MFC]
- update handlers [MFC]
- command-handler macros
- updating user-interface objects [MFC]
ms.assetid: 3e72b50f-4119-4c82-81cf-6e09b132de05
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 3de873cf70bafa77d7c8f4b05c70ce211b2c2258
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="onupdatecommandui-macro"></a>Macro ON_UPDATE_COMMAND_UI
Use o **propriedades** janela para se conectar a um objeto de interface do usuário para um manipulador de atualização de comando em um objeto de destino do comando. Ele se conectará automaticamente a ID do objeto de interface do usuário para o `ON_UPDATE_COMMAND_UI` macro e criar um manipulador no objeto que tratará a atualização. Consulte [mapeando mensagens para funções](../mfc/reference/mapping-messages-to-functions.md) para obter mais informações.  
  
 Por exemplo, para atualizar um comando Limpar tudo no menu Editar do programa, use o **propriedades** janela para adicionar uma entrada de mapa de mensagens na classe escolhida, uma declaração de função para um manipulador de atualização de comando chamado `OnUpdateEditClearAll` na classe declaração e um modelo de função vazio no arquivo de implementação da classe. O protótipo de função tem esta aparência:  
  
 [!code-cpp[NVC_MFCDocView#2](../mfc/codesnippet/cpp/on-update-command-ui-macro_1.h)]  
  
 Como mostra a função de todos os manipuladores de **afx_msg** palavra-chave. Como todos os manipuladores de atualização, ele usa um argumento, um ponteiro para um `CCmdUI` objeto.  
  
## <a name="see-also"></a>Consulte também  
 [Como atualizar objetos da interface do usuário](../mfc/how-to-update-user-interface-objects.md)

