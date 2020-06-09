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
ms.openlocfilehash: ed2ef635437408cacfd600d6cdba4b3731d575b4
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84625736"
---
# <a name="handling-commands-in-the-document"></a>Manipulando comandos no documento

Sua classe de documento também pode lidar com determinados comandos gerados por itens de menu, botões da barra de ferramentas ou teclas de aceleração. Por padrão, `CDocument` o manipula os comandos salvar e salvar como no menu arquivo, usando a serialização. Outros comandos que afetam os dados também podem ser tratados por funções de membro do seu documento. Por exemplo, no programa rabisco, a classe `CScribDoc` fornece um manipulador para o comando Editar limpar tudo, que exclui todos os dados atualmente armazenados no documento. Os documentos podem ter mapas de mensagens, mas, ao contrário dos modos de exibição, os documentos não podem manipular mensagens padrão do Windows – apenas **WM_COMMAND** mensagens ou "comandos".

## <a name="see-also"></a>Consulte também

[Usando documentos](using-documents.md)
