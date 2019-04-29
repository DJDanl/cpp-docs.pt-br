---
title: Manipulando comandos no documento
ms.date: 11/04/2016
helpviewer_keywords:
- message maps [MFC], in document class
- command handling [MFC]
- documents [MFC], message maps
- message handling [MFC], WM_COMMAND messages
- command handling [MFC], commands in documents
- documents [MFC], handling messages in
ms.assetid: c7375584-27af-4275-b2fd-afea476785d0
ms.openlocfilehash: f3cce539d52bd04e97a6b5f84cbd833b05afb5bb
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62240568"
---
# <a name="handling-commands-in-the-document"></a>Manipulando comandos no documento

Sua classe de documento também pode tratar certos comandos gerados pelos itens de menu, botões de barra de ferramentas ou teclas de aceleração. Por padrão, `CDocument` manipula o salvamento e salvar como os comandos no menu Arquivo, usando a serialização. Outros comandos que afetam os dados também podem ser manipulados por funções de membro de seu documento. Por exemplo, no programa rabisco, a classe `CScribDoc` fornece um manipulador para o comando Editar Limpar tudo, o que exclui todos os dados atualmente armazenados no documento. Documentos podem ter mapas de mensagem, mas ao contrário de modos de exibição, os documentos não podem manipular mensagens padrão do Windows — só **WM_COMMAND** mensagens ou "commands".

## <a name="see-also"></a>Consulte também

[Usando documentos](../mfc/using-documents.md)
