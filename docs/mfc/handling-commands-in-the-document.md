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
ms.openlocfilehash: d2f0a7271452ace9b9e06ff995af61881db4403c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50548948"
---
# <a name="handling-commands-in-the-document"></a>Manipulando comandos no documento

Sua classe de documento também pode tratar certos comandos gerados pelos itens de menu, botões de barra de ferramentas ou teclas de aceleração. Por padrão, `CDocument` manipula o salvamento e salvar como os comandos no menu Arquivo, usando a serialização. Outros comandos que afetam os dados também podem ser manipulados por funções de membro de seu documento. Por exemplo, no programa rabisco, a classe `CScribDoc` fornece um manipulador para o comando Editar Limpar tudo, o que exclui todos os dados atualmente armazenados no documento. Documentos podem ter mapas de mensagem, mas ao contrário de modos de exibição, os documentos não podem manipular mensagens padrão do Windows — só **WM_COMMAND** mensagens ou "commands".

## <a name="see-also"></a>Consulte também

[Usando documentos](../mfc/using-documents.md)

