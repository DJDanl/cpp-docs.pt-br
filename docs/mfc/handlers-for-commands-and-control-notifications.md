---
title: Manipuladores para comandos e notificações de controle
ms.date: 11/04/2016
helpviewer_keywords:
- commands [MFC], handlers for
- functions [MFC], handler
- handlers [MFC]
- controls [MFC], notifications
- handlers [MFC], control notification [MFC]
- notifications [MFC], handlers for control
- handlers [MFC], command
ms.assetid: 20f57f4a-f577-4c09-80a2-43faf32a1c2e
ms.openlocfilehash: cc89cbfde0a1eba5dc736b40c178d4a4fde37a4d
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84625767"
---
# <a name="handlers-for-commands-and-control-notifications"></a>Manipuladores para comandos e notificações de controle

Não há manipuladores padrão para comandos ou mensagens de notificação de controle. Portanto, você está associado somente por convenção ao nomear seus manipuladores para essas categorias de mensagens. Quando você mapeia o comando ou a notificação de controle para um manipulador, o [Assistente de classe](reference/mfc-class-wizard.md) propõe um nome com base na ID de comando ou no código de notificação de controle. Você pode aceitar o nome proposto, alterá-lo ou substituí-lo.

A Convenção sugere que você nomeie manipuladores em ambas as categorias para o objeto de interface do usuário que elas representam. Portanto, um manipulador para o comando Recortar no menu Editar pode ser nomeado

[!code-cpp[NVC_MFCMessageHandling#4](codesnippet/cpp/handlers-for-commands-and-control-notifications_1.h)]

Como o comando Cut é tão comumente implementado em aplicativos, a estrutura predefine a ID de comando para o comando Recortar como **ID_EDIT_CUT**. Para obter uma lista de todas as IDs de comando predefinidas, consulte o arquivo AFXRES. T. Para obter mais informações, consulte [comandos padrão](standard-commands.md).

Além disso, a Convenção sugere um manipulador para a mensagem de notificação **BN_CLICKED** de um botão rotulado "meu botão" pode ser nomeado

[!code-cpp[NVC_MFCMessageHandling#5](codesnippet/cpp/handlers-for-commands-and-control-notifications_2.h)]

Você pode atribuir a esse comando uma ID de **IDC_MY_BUTTON** porque ele é equivalente a um objeto de interface de usuário específico do aplicativo.

As duas categorias de mensagens não usam argumentos e não retornam nenhum valor.

## <a name="see-also"></a>Consulte também

[Declarando funções de manipulador de mensagens](declaring-message-handler-functions.md)
