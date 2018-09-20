---
title: Manipulando comandos no documento | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- message maps [MFC], in document class
- command handling [MFC]
- documents [MFC], message maps
- message handling [MFC], WM_COMMAND messages
- command handling [MFC], commands in documents
- documents [MFC], handling messages in
ms.assetid: c7375584-27af-4275-b2fd-afea476785d0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8845ea7c44fd5a34774db0508302f5959987cdc9
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46441259"
---
# <a name="handling-commands-in-the-document"></a>Manipulando comandos no documento

Sua classe de documento também pode tratar certos comandos gerados pelos itens de menu, botões de barra de ferramentas ou teclas de aceleração. Por padrão, `CDocument` manipula o salvamento e salvar como os comandos no menu Arquivo, usando a serialização. Outros comandos que afetam os dados também podem ser manipulados por funções de membro de seu documento. Por exemplo, no programa rabisco, a classe `CScribDoc` fornece um manipulador para o comando Editar Limpar tudo, o que exclui todos os dados atualmente armazenados no documento. Documentos podem ter mapas de mensagem, mas ao contrário de modos de exibição, os documentos não podem manipular mensagens padrão do Windows — só **WM_COMMAND** mensagens ou "commands".

## <a name="see-also"></a>Consulte também

[Usando documentos](../mfc/using-documents.md)

