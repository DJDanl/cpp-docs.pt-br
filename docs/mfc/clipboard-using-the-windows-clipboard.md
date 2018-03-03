---
title: "Área de transferência: Usando a área de transferência do Windows | Microsoft Docs"
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
- Clipboard commands
- Cut/Copy and Paste command handler functions [MFC]
- handler functions, Cut/Copy and Paste commands
- Clipboard [MFC], commands
- commands [MFC], implementing Edit
- Clipboard commands [MFC], implementing
- Windows Clipboard [MFC]
- Clipboard [MFC], Windows Clipboard API
ms.assetid: 24415b42-9301-4a70-b69a-44c97918319f
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 6063a27495d46e4b54f3133b92689e4b0faaa631
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="clipboard-using-the-windows-clipboard"></a>Área de Transferência: usando a Área de Transferência do Windows
Este tópico descreve como usar a API de área de transferência do Windows padrão dentro de seu aplicativo do MFC.  
  
 A maioria dos aplicativos do Windows oferecem suporte a cópia de dados para a área de transferência do Windows ou recortando e colando dados da área de transferência. Variam os formatos de dados de área de transferência entre aplicativos. A estrutura oferece suporte a apenas um número limitado de formatos de área de transferência para um número limitado de classes. Normalmente, você implementará os comandos relacionados à área de transferência — Recortar, copiar e colar, no menu Editar para o modo de exibição. A biblioteca de classe define as IDs de comando para esses comandos: **ID_EDIT_CUT**, **ID_EDIT_COPY**, e **ID_EDIT_PASTE**. Suas solicitações de linha da mensagem também são definidas.  
  
 [Mensagens e comandos no Framework](../mfc/messages-and-commands-in-the-framework.md) explica como lidar com os comandos de menu em seu aplicativo, mapeando o comando de menu para uma função de manipulador. Desde que o aplicativo não definir funções de manipulador para os comandos da área de transferência no menu Editar, eles permanecerão desabilitados. Para gravar funções de manipulador para os comandos Recortar e copiar, implemente a seleção em seu aplicativo. Para escrever uma função de manipulador para o comando Colar, consulte a área de transferência para ver se ele contém dados em um formato de seu aplicativo pode aceitar. Por exemplo, para habilitar o comando de cópia, você pode escrever um manipulador de algo semelhante ao seguinte:  
  
 [!code-cpp[NVC_MFCListView#2](../atl/reference/codesnippet/cpp/clipboard-using-the-windows-clipboard_1.cpp)]  
  
 Os comandos Recortar, copiar e colar somente são significativos em determinados contextos. Os comandos Recortar e cópia devem ser habilitados somente quando algo está selecionado e o comando Colar apenas quando algo na área de transferência. Você pode fornecer esse comportamento definindo funções de manipulador de atualização que habilitam ou desabilitam a esses comandos, dependendo do contexto. Para obter mais informações, consulte [como objetos de atualização de Interface do usuário](../mfc/how-to-update-user-interface-objects.md).  
  
 A biblioteca Microsoft Foundation Class oferecem suporte a área de transferência para edição de texto com o `CEdit` e `CEditView` classes. As classes OLE também simplificam as operações de área de transferência de implementação que envolvem itens OLE. Para obter mais informações sobre as classes OLE, consulte [área de transferência: usando o mecanismo de área de transferência OLE](../mfc/clipboard-using-the-ole-clipboard-mechanism.md).  
  
 Implementando outros editar comandos de menu, como desfazer (**ID_EDIT_UNDO**) e Refazer (**ID_EDIT_REDO**), também é da esquerda para você. Se seu aplicativo não oferece suporte a esses comandos, você pode excluí-los facilmente do seu arquivo de recursos usando os editores de recursos do Visual C++.  
  
## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Copiando e colando dados](../mfc/clipboard-copying-and-pasting-data.md)  
  
-   [Usando o mecanismo da área de transferência OLE](../mfc/clipboard-using-the-ole-clipboard-mechanism.md)  
  
## <a name="see-also"></a>Consulte também  
 [Área de transferência](../mfc/clipboard.md)

