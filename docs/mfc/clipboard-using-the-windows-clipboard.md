---
title: 'Área de transferência: Usando a área de transferência do Windows'
ms.date: 11/04/2016
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
ms.openlocfilehash: 49111e4efd2a12264d61030fe038d80b974514c1
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57264788"
---
# <a name="clipboard-using-the-windows-clipboard"></a>Área de transferência: Usando a área de transferência do Windows

Este tópico descreve como usar a API de área de transferência do Windows padrão dentro de seu aplicativo do MFC.

A maioria dos aplicativos para Windows dão suporte a recortar ou copiar dados para a área de transferência do Windows e colando dados da área de transferência. Variam os formatos de dados da área de transferência entre aplicativos. O framework oferece suporte a apenas um número limitado de formatos de área de transferência para um número limitado de classes. Normalmente, você implementará os comandos relacionados à área de transferência — Recortar, copiar e colar, no menu Editar para o modo de exibição. A biblioteca de classes define as IDs de comando para estes comandos: **ID_EDIT_CUT**, **ID_EDIT_COPY**, e **ID_EDIT_PASTE**. Seus prompts de linha de mensagem também são definidos.

[Mensagens e comandos no Framework](../mfc/messages-and-commands-in-the-framework.md) explica como lidar com comandos de menu em seu aplicativo, mapeando o comando de menu para uma função de manipulador. Desde que seu aplicativo não define funções de manipulador para os comandos de área de transferência no menu Editar, eles permanecerão desabilitados. Para escrever funções de manipulador para os comandos Recortar e copiar, implemente a seleção em seu aplicativo. Para gravar uma função de manipulador para o comando Colar, consulte a área de transferência para ver se ele contém dados em um formato que seu aplicativo pode aceitar. Por exemplo, para habilitar o comando de cópia, você pode escrever um manipulador de algo semelhante ao seguinte:

[!code-cpp[NVC_MFCListView#2](../atl/reference/codesnippet/cpp/clipboard-using-the-windows-clipboard_1.cpp)]

Os comandos Recortar, copiar e colar só são úteis em determinados contextos. Os comandos Recortar e a cópia devem ser habilitados apenas quando algo está selecionado e o comando Colar somente quando algo está na área de transferência. Você pode fornecer esse comportamento definindo funções de manipulador de atualização que habilitam ou desabilitam esses comandos, dependendo do contexto. Para obter mais informações, consulte [como objetos de atualização de Interface do usuário](../mfc/how-to-update-user-interface-objects.md).

A biblioteca Microsoft Foundation Class fornece suporte de área de transferência para edição de texto com o `CEdit` e `CEditView` classes. As classes OLE também simplificam a implementação da área de transferência operações que envolvem itens OLE. Para obter mais informações sobre as classes OLE, consulte [na área de transferência: Usando o mecanismo de área de transferência OLE](../mfc/clipboard-using-the-ole-clipboard-mechanism.md).

Implementar outros editar comandos de menu, como desfazer (**ID_EDIT_UNDO**) e Refazer (**ID_EDIT_REDO**), também é deixada para você. Se seu aplicativo não dá suporte a esses comandos, você pode excluí-los facilmente de seu arquivo de recurso usando os editores de recursos do Visual C++.

## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Copiando e colando dados](../mfc/clipboard-copying-and-pasting-data.md)

- [Usando o mecanismo de área de transferência OLE](../mfc/clipboard-using-the-ole-clipboard-mechanism.md)

## <a name="see-also"></a>Consulte também

[Área de transferência](../mfc/clipboard.md)
