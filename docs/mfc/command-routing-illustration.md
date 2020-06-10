---
title: Ilustração de roteamento do comando
ms.date: 11/04/2016
helpviewer_keywords:
- MFC, command routing
- command handling [MFC], routing commands
- command routing [MFC], OnCmdMsg handler
ms.assetid: 4b7b4741-565f-4878-b076-fd85c670f87f
ms.openlocfilehash: d362cfe54a9b5a562237c7bb9632edae6e58228b
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84622917"
---
# <a name="command-routing-illustration"></a>Ilustração de roteamento do comando

Para ilustrar, considere uma mensagem de comando de um item de menu limpar tudo no menu Editar de um aplicativo MDI. Suponha que a função de manipulador para esse comando seja uma função membro da classe de documento do aplicativo. Veja como esse comando atinge seu manipulador depois que o usuário escolhe o item de menu:

1. A janela do quadro principal recebe a mensagem de comando primeiro.

1. A janela principal do quadro MDI fornece à janela filho MDI ativa no momento uma oportunidade de manipular o comando.

1. O roteamento padrão de uma janela de quadro filho MDI fornece à sua exibição uma chance no comando antes de verificar seu próprio mapa de mensagens.

1. A exibição verifica seu próprio mapa de mensagens primeiro e, não localizando nenhum manipulador, em seguida roteia o comando para seu documento associado.

1. O documento verifica seu mapa de mensagens e localiza um manipulador. Essa função de membro de documento é chamada e o roteamento para.

Se o documento não tivesse um manipulador, ele avançaria o comando para o seu modelo de documento. Em seguida, o comando retornaria para a exibição e, em seguida, a janela do quadro. Por fim, a janela do quadro verificaria seu mapa de mensagens. Se essa verificação tiver falhado também, o comando seria roteado de volta para a janela de quadro MDI principal e, em seguida, para o objeto Application — o destino final dos comandos sem tratamento.

## <a name="see-also"></a>Consulte também

[Como o Framework chama um manipulador](how-the-framework-calls-a-handler.md)
