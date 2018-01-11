---
title: "Ilustração de roteamento de comando | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- MFC, command routing
- command handling [MFC], routing commands
- command routing [MFC], OnCmdMsg handler
ms.assetid: 4b7b4741-565f-4878-b076-fd85c670f87f
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 24ac591005d5df6b18102d296352b8b2528ba839
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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

