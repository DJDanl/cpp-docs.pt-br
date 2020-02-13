---
title: Área de transferência
ms.date: 11/04/2016
helpviewer_keywords:
- cutting and copying data
- copying data
- Clipboard
- Clipboard, programming
- transferring data
ms.assetid: a71b2824-1f14-4914-8816-54578d73ad4e
ms.openlocfilehash: 1db089110904ab88eb9c0c111d9da4e4e6869c82
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77127901"
---
# <a name="clipboard"></a>Área de transferência

Esta família de artigos explica como implementar o suporte para a área de transferência do Windows em aplicativos MFC. A área de transferência do Windows é usada de duas maneiras:

- Implementando comandos de menu de edição padrão, como recortar, copiar e colar.

- Implementação de transferência de dados uniforme com arrastar e soltar OLE.

A área de transferência é o método padrão do Windows de transferência de dados entre uma origem e um destino. Ele também pode ser muito útil em operações OLE. Com o advento do OLE, há dois mecanismos de área de transferência no Windows. A API de área de transferência padrão do Windows ainda está disponível, mas foi complementada com o mecanismo de transferência de dados OLE. A UDT (transferência de dados uniforme) OLE dá suporte a recortar, copiar e colar com a área de transferência e arrastar e soltar.

A área de transferência é um serviço de sistema compartilhado por toda a sessão do Windows e, portanto, não tem um identificador ou uma classe própria. Você gerencia a área de transferência por meio de funções de membro da classe [CWnd](../mfc/reference/cwnd-class.md).

## <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Quando usar cada mecanismo de área de transferência](../mfc/clipboard-when-to-use-each-clipboard-mechanism.md)

- [Usando a API de área de transferência tradicional do Windows](../mfc/clipboard-using-the-windows-clipboard.md)

- [Usando o mecanismo de área de transferência OLE](../mfc/clipboard-using-the-ole-clipboard-mechanism.md)

- [Copiando e colando dados](../mfc/clipboard-copying-and-pasting-data.md)

- [Adicionando outros formatos](../mfc/clipboard-adding-other-formats.md)

- [A área de transferência do Windows](/windows/win32/dataxchg/clipboard)

- [Arrastar e soltar OLE](../mfc/drag-and-drop-ole.md)

## <a name="see-also"></a>Consulte também

[Elementos da interface do usuário](../mfc/user-interface-elements-mfc.md)
