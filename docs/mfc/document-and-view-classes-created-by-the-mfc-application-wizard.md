---
title: Documentar e exibir Classes criadas pelo Assistente de aplicativo MFC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- document classes [MFC]
- document classes [MFC], created by application wizards
- application wizards [MFC], document/view classes created
- view classes [MFC], created by application wizards
ms.assetid: 70c34a60-2701-4981-acea-c08a5787d8e6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: eb1a1fc6c35bfb9589e827d798cb112640fa9b2f
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46417612"
---
# <a name="document-and-view-classes-created-by-the-mfc-application-wizard"></a>Classes de documento e exibição criadas pelo Assistente de Aplicativo MFC

O Assistente de aplicativo do MFC fornece um ponto de partida em seu desenvolvimento do programa, criando o documento estrutural e classes de exibição para você. Em seguida, você pode [mapear comandos e mensagens para essas classes](../mfc/reference/mapping-messages-to-functions.md) e usar o editor de código de origem do Visual C++ para gravar suas funções de membro.

A classe de documento criada pelo Assistente de aplicativo do MFC é derivada da classe [CDocument](../mfc/reference/cdocument-class.md). O modo de exibição classe é derivada de [CView](../mfc/reference/cview-class.md). Os nomes que o Assistente de aplicativo dá a essas classes e os arquivos que contêm eles baseiam-se no nome do projeto que você fornecer na caixa de diálogo Assistente de aplicativo. No Assistente de aplicativo, você pode usar a página de Classes geradas para alterar os nomes padrão.

Alguns aplicativos talvez precisem de mais de uma classe de documento, exibição de classe ou classe de janela do quadro. Para obter mais informações, consulte [vários tipos de documentos, exibições e quadro Windows](../mfc/multiple-document-types-views-and-frame-windows.md).

## <a name="see-also"></a>Consulte também

[Arquitetura de documento/exibição](../mfc/document-view-architecture.md)

