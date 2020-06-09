---
title: 'Área de Transferência: usando a Área de Transferência do Windows'
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
ms.openlocfilehash: 1b11bfe18443858de0dd7032f72fecadb1d6ebdd
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84626045"
---
# <a name="clipboard-using-the-windows-clipboard"></a>Área de Transferência: usando a Área de Transferência do Windows

Este tópico descreve como usar a API de área de transferência padrão do Windows em seu aplicativo MFC.

A maioria dos aplicativos do Windows dá suporte ao recortar ou copiar dados na área de transferência do Windows e colar os dados da área de transferência. Os formatos de dados da área de transferência variam entre os aplicativos. A estrutura dá suporte a apenas um número limitado de formatos de área de transferência para um número limitado de classes. Normalmente, você implementará os comandos relacionados à área de transferência — recortar, copiar e colar — no menu Editar para sua exibição. A biblioteca de classes define as IDs de comando para esses comandos: **ID_EDIT_CUT**, **ID_EDIT_COPY**e **ID_EDIT_PASTE**. Seus prompts de linha de mensagem também são definidos.

[Mensagens e comandos na estrutura](messages-and-commands-in-the-framework.md) explica como manipular comandos de menu em seu aplicativo mapeando o comando de menu para uma função de manipulador. Desde que seu aplicativo não defina funções de manipulador para os comandos da área de transferência no menu Editar, eles permanecerão desabilitados. Para gravar funções de manipulador para os comandos Recortar e copiar, implemente a seleção em seu aplicativo. Para gravar uma função de manipulador para o comando colar, consulte a área de transferência para ver se ela contém dados em um formato que seu aplicativo pode aceitar. Por exemplo, para habilitar o comando de cópia, você pode escrever um manipulador semelhante ao seguinte:

[!code-cpp[NVC_MFCListView#2](../atl/reference/codesnippet/cpp/clipboard-using-the-windows-clipboard_1.cpp)]

Os comandos Recortar, copiar e colar só são significativos em determinados contextos. Os comandos Recortar e copiar devem ser habilitados somente quando algo estiver selecionado e o comando colar somente quando algo estiver na área de transferência. Você pode fornecer esse comportamento definindo funções do manipulador de atualização que habilitam ou desabilitam esses comandos dependendo do contexto. Para obter mais informações, consulte [como atualizar objetos da interface do usuário](how-to-update-user-interface-objects.md).

O biblioteca MFC fornece suporte à área de transferência para edição de texto com as `CEdit` `CEditView` classes e. As classes OLE também simplificam a implementação de operações de área de transferência que envolvem itens OLE. Para obter mais informações sobre as classes OLE, consulte [área de transferência: usando o mecanismo de área de transferência OLE](clipboard-using-the-ole-clipboard-mechanism.md).

A implementação de outros comandos do menu Editar, como desfazer (**ID_EDIT_UNDO**) e refazer (**ID_EDIT_REDO**), também é deixada para você. Se seu aplicativo não oferecer suporte a esses comandos, você poderá excluí-los facilmente do arquivo de recursos usando os editores de recursos Visual C++.

## <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Copiando e colando dados](clipboard-copying-and-pasting-data.md)

- [Usando o mecanismo de área de transferência OLE](clipboard-using-the-ole-clipboard-mechanism.md)

## <a name="see-also"></a>Consulte também

[Área de transferência](clipboard.md)
