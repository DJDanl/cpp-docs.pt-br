---
title: Documente e exibir Classes criadas pelo Assistente de aplicativo MFC | Microsoft Docs
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
ms.openlocfilehash: 6b83886784970492da0c5e2a335dbe08119ecaae
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="document-and-view-classes-created-by-the-mfc-application-wizard"></a>Classes de documento e exibição criadas pelo Assistente de Aplicativo MFC
O Assistente de aplicativo MFC fornece um ponto de partida em seu desenvolvimento de programa ao criar documento esqueleto e classes de exibição para você. Você pode, em seguida, [mapear mensagens e comandos para essas classes](../mfc/reference/mapping-messages-to-functions.md) e use o editor de código fonte do Visual C++ para gravar suas funções de membro.  
  
 A classe de documento criada pelo Assistente de aplicativo MFC é derivada da classe [CDocument](../mfc/reference/cdocument-class.md). O modo de exibição classe é derivada de [CView](../mfc/reference/cview-class.md). Os nomes que o Assistente de aplicativo fornece essas classes e os arquivos que contêm baseiam-se no nome do projeto que você fornece na caixa de diálogo Assistente de aplicativo. No Assistente de aplicativo, você pode usar a página de Classes geradas para alterar os nomes padrão.  
  
 Alguns aplicativos talvez seja necessário mais de uma classe de documento, exibição de classe ou classe de janela do quadro. Para obter mais informações, consulte [vários tipos de documento, exibições e janelas com moldura](../mfc/multiple-document-types-views-and-frame-windows.md).  
  
## <a name="see-also"></a>Consulte também  
 [Arquitetura de documento/exibição](../mfc/document-view-architecture.md)

