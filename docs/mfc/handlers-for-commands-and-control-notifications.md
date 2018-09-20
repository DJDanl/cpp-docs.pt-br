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
ms.openlocfilehash: bda42393cd55b60ab787665b51957bb2f94c5df3
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46430045"
---
# <a name="handlers-for-commands-and-control-notifications"></a>Manipuladores para comandos e notificações de controle

Não há nenhum manipulador padrão para comandos ou mensagens de notificação do controle. Portanto, você está limitado apenas pela convenção de nomenclatura seus manipuladores para essas categorias de mensagens. Quando você mapeia a notificação de comando ou o controle a um manipulador, as janelas de propriedades propõe um nome com base no código de identificação ou notificação de controle de comando. Você pode aceitar o nome proposto, alterá-lo ou substituí-lo.

Convenção sugere que você nomeie manipuladores em ambas as categorias para o objeto de interface do usuário que eles representam. Portanto, pode ser chamado de um manipulador para o comando Recortar no menu Editar

[!code-cpp[NVC_MFCMessageHandling#4](../mfc/codesnippet/cpp/handlers-for-commands-and-control-notifications_1.h)]

Como o comando Recortar muito comum é implementado em aplicativos, o framework predefine a ID de comando para o comando Recortar conforme **ID_EDIT_CUT**. Para obter uma lista de todas as IDs de comando predefinido, consulte o arquivo AFXRES. H. Para obter mais informações, consulte [comandos padrão](../mfc/standard-commands.md).

Além disso, a convenção sugere um manipulador para o **BN_CLICKED** pode ser chamada de mensagem de notificação de um botão rotulado "My Button."

[!code-cpp[NVC_MFCMessageHandling#5](../mfc/codesnippet/cpp/handlers-for-commands-and-control-notifications_2.h)]

Você pode atribuir esse comando ID **IDC_MY_BUTTON** porque ele é equivalente a um objeto de interface do usuário específicos do aplicativo.

Ambas as categorias de mensagens não usam argumentos e não retornam nenhum valor.

## <a name="see-also"></a>Consulte também

[Declarando funções de manipulador de mensagens](../mfc/declaring-message-handler-functions.md)
