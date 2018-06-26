---
title: Manipuladores para comandos e notificações de controle | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- commands [MFC], handlers for
- functions [MFC], handler
- handlers [MFC]
- controls [MFC], notifications
- handlers [MFC], control notification [MFC]
- notifications [MFC], handlers for control
- handlers [MFC], command
ms.assetid: 20f57f4a-f577-4c09-80a2-43faf32a1c2e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 60c66beb3c0c8874bd3d678bfc4331dc766c443a
ms.sourcegitcommit: 060f381fe0807107ec26c18b46d3fcb859d8d2e7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/25/2018
ms.locfileid: "36929125"
---
# <a name="handlers-for-commands-and-control-notifications"></a>Manipuladores para comandos e notificações de controle
Não há nenhum manipulador padrão para comandos ou mensagens de notificação de controle. Portanto, você está associados somente por convenção em seus manipuladores de nomenclatura para essas categorias de mensagens. Ao mapear a notificação de comando ou o controle para um manipulador, as janelas de propriedades sugere um nome com base no código de identificação ou notificação de controle de comando. Você pode aceitar o nome proposto, alterá-la ou substituí-lo.  
  
 Convenção sugere que você nomear manipuladores em ambas as categorias para o objeto de interface do usuário que eles representam. Portanto, um manipulador para o comando Recortar no menu Editar pode ser chamado  
  
 [!code-cpp[NVC_MFCMessageHandling#4](../mfc/codesnippet/cpp/handlers-for-commands-and-control-notifications_1.h)]  
  
 Como o comando Cortar muito comum é implementado em aplicativos, o framework predefine a ID de comando para o comando Recortar como **ID_EDIT_CUT**. Para obter uma lista de comando predefinido todas as IDs, consulte o arquivo AFXRES. H. Para obter mais informações, consulte [comandos padrão](../mfc/standard-commands.md).  
  
 Além disso, a convenção sugere um manipulador para o **BN_CLICKED** mensagem de notificação de um botão rotulado como "My Button" pode ser chamada.  
  
 [!code-cpp[NVC_MFCMessageHandling#5](../mfc/codesnippet/cpp/handlers-for-commands-and-control-notifications_2.h)]  
  
 Você pode atribuir uma ID desse comando **IDC_MY_BUTTON** porque ele é equivalente a um objeto de interface do usuário específica do aplicativo.  
  
 Ambas as categorias de mensagens não usam argumentos e não retornam nenhum valor.  
  
## <a name="see-also"></a>Consulte também  
 [Declarando funções de manipulador de mensagens](../mfc/declaring-message-handler-functions.md)
