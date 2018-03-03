---
title: Destruindo janelas com moldura | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- PostNcDestroy
dev_langs:
- C++
helpviewer_keywords:
- Default method [MFC]
- DestroyWindow method [MFC]
- frame windows [MFC], destroying
- OnNcDestroy method, and frame windows
- document frame windows [MFC], destroying
- destroying frame windows
- MFC, frame windows
- windows [MFC], destroying
- OnClose method [MFC]
- PostNcDestroy method [MFC]
ms.assetid: 5affca77-1999-4507-a2b2-9aa226611b4b
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f1cbd96f5044626c7c3c07e8fca115c2b1dca8cb
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="destroying-frame-windows"></a>Destruindo janelas com moldura
A estrutura MFC gerencia destruição de janela, bem como a criação para as janelas associadas com modos de exibição e documentos do framework. Se você criar janelas adicionais, você é responsável por destruí-las.  
  
 Na estrutura, quando o usuário fecha a janela do quadro, padrão da janela [OnClose](../mfc/reference/cwnd-class.md#onclose) chamadas de manipulador [DestroyWindow](../mfc/reference/cwnd-class.md#destroywindow). É a última função membro chamada quando a janela do Windows é destruída [OnNcDestroy](../mfc/reference/cwnd-class.md#onncdestroy), que faz alguma limpeza, chama o [padrão](../mfc/reference/cwnd-class.md#default) membro de função para executar a limpeza do Windows e finalmente chama a função membro virtual [PostNcDestroy](../mfc/reference/cwnd-class.md#postncdestroy). O [CFrameWnd](../mfc/reference/cframewnd-class.md) implementação de `PostNcDestroy` exclui o objeto de janela C++. Você nunca deve usar o C++ **excluir** operador em uma janela do quadro. Use `DestroyWindow` em seu lugar.  
  
 Quando a janela principal é fechada, o aplicativo for fechado. Se há forem modificados documentos não salvos, o framework exibe uma caixa de mensagem para perguntar se os documentos devem ser salvos e garante que os documentos apropriados são salvos, se necessário.  
  
## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Criando janelas com moldura de documento](../mfc/creating-document-frame-windows.md)  
  
## <a name="see-also"></a>Consulte também  
 [Usando janelas com moldura](../mfc/using-frame-windows.md)

