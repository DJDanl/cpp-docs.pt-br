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
ms.openlocfilehash: c20ff02b2d72f1dfa6afab5a0d547b46aa55b18c
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33343541"
---
# <a name="handling-commands-in-the-document"></a>Manipulando comandos no documento
A classe de documento também pode lidar com determinados comandos gerados pelos itens de menu, botões da barra de ferramentas ou teclas de aceleração. Por padrão, **CDocument** manipula o salvamento e salvar como comandos no menu Arquivo, usando a serialização. Outros comandos que afetam os dados também podem ser tratados por funções de membro do documento. Por exemplo, no programa rabisco, classe `CScribDoc` fornece um manipulador para o comando Editar Limpar tudo, que exclui todos os dados atualmente armazenados no documento. Documentos podem ter mapas de mensagem, mas ao contrário de modos de exibição, os documentos não podem tratar mensagens padrão do Windows — somente **WM_COMMAND** mensagens ou "comandos".  
  
## <a name="see-also"></a>Consulte também  
 [Usando documentos](../mfc/using-documents.md)

