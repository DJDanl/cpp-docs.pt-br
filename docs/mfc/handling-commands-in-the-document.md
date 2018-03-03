---
title: Manipulando comandos no documento | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a8d27698d573e1dee539f93ab88015285648fa77
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="handling-commands-in-the-document"></a>Manipulando comandos no documento
A classe de documento também pode lidar com determinados comandos gerados pelos itens de menu, botões da barra de ferramentas ou teclas de aceleração. Por padrão, **CDocument** manipula o salvamento e salvar como comandos no menu Arquivo, usando a serialização. Outros comandos que afetam os dados também podem ser tratados por funções de membro do documento. Por exemplo, no programa rabisco, classe `CScribDoc` fornece um manipulador para o comando Editar Limpar tudo, que exclui todos os dados atualmente armazenados no documento. Documentos podem ter mapas de mensagem, mas ao contrário de modos de exibição, os documentos não podem tratar mensagens padrão do Windows — somente **WM_COMMAND** mensagens ou "comandos".  
  
## <a name="see-also"></a>Consulte também  
 [Usando documentos](../mfc/using-documents.md)

