---
title: Ilustração de roteamento de comando | Microsoft Docs
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
- command routing [MFC], OnCmdMsg handler
ms.assetid: 4b7b4741-565f-4878-b076-fd85c670f87f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a12a5cd19177761dfbf484c64f528d8def194ca5
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="command-routing-illustration"></a>Ilustração de roteamento do comando
Para ilustrar, considere uma mensagem de comando de um item de menu Limpar tudo no menu Editar do aplicativo um MDI. Suponha que a função de manipulador desse comando é uma função de membro de classe de documento do aplicativo. Aqui está como o comando atinge seu manipulador depois que o usuário escolhe o item de menu:  
  
1.  A janela do quadro principal recebe a mensagem de comando pela primeira vez.  
  
2.  A janela do quadro MDI principal fornece a janela de filho MDI ativa atualmente a oportunidade de lidar com o comando.  
  
3.  O roteamento padrão de uma janela do quadro filho MDI oportunidade sua exibição no comando antes de verificar seu próprio mapa de mensagem.  
  
4.  A exibição primeiro verifica seu próprio mapa de mensagem e, em seguida não localizar nenhum manipulador encaminha o comando para o documento associado.  
  
5.  O documento verifica seu mapa de mensagem e localiza um manipulador. Essa função de membro de documento é chamada e o roteamento para.  
  
 Se o documento não tem um manipulador, ele seria lado rotear o comando para seu modelo de documento. Em seguida, o comando retornará para o modo de exibição e, em seguida, a janela do quadro. Por fim, a janela do quadro verifica seu mapa de mensagem. Se essa verificação falha, bem, o comando será encaminhado para a janela do quadro MDI principal e, em seguida, para o objeto de aplicativo — o destino final de comandos sem tratamento.  
  
## <a name="see-also"></a>Consulte também  
 [Como o Framework chama um manipulador](../mfc/how-the-framework-calls-a-handler.md)

