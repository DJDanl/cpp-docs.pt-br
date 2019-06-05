---
title: Área de Transferência
ms.date: 11/04/2016
helpviewer_keywords:
- cutting and copying data
- copying data
- Clipboard
- Clipboard, programming
- transferring data
ms.assetid: a71b2824-1f14-4914-8816-54578d73ad4e
ms.openlocfilehash: 5814b2fdfc7fbcaca00037cc64dd71aa27d65cc3
ms.sourcegitcommit: ecf274bcfe3a977c48745aaa243e5e731f1fdc5f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2019
ms.locfileid: "66504618"
---
# <a name="clipboard"></a>Área de Transferência

Essa família de artigos explica como implementar o suporte para a área de transferência do Windows em aplicativos MFC. A área de transferência do Windows é usada de duas maneiras:

- Implementação de comandos do menu Editar padrão, como Recortar, copiar e colar.

- Implementando uniforme de dados para transferir com arrastar e soltar (OLE).

A área de transferência é o método padrão do Windows de transferir dados entre uma origem e um destino. Ela também pode ser muito útil em operações de OLE. Com o advento do OLE, há dois mecanismos de área de transferência no Windows. A API de área de transferência do Windows padrão ainda estará disponível, mas ele tem sido complementado com o mecanismo de transferência de dados OLE. Transferência de uniforme de dados OLE (UDT) dá suporte a recortar, copiar e colar com a área de transferência e arrastar e soltar.

A área de transferência é um serviço de sistema compartilhado por toda sessão do Windows, portanto, ele não tem um identificador ou uma classe própria. Você gerencia a área de transferência por meio de funções de membro da classe [CWnd](../mfc/reference/cwnd-class.md).

## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Quando usar cada mecanismo da área de transferência](../mfc/clipboard-when-to-use-each-clipboard-mechanism.md)

- [Usando a API tradicional de área de transferência do Windows](../mfc/clipboard-using-the-windows-clipboard.md)

- [Usando o mecanismo de área de transferência OLE](../mfc/clipboard-using-the-ole-clipboard-mechanism.md)

- [Copiando e colando dados](../mfc/clipboard-copying-and-pasting-data.md)

- [Adicionando outros formatos](../mfc/clipboard-adding-other-formats.md)

- [A área de transferência do Windows](/windows/desktop/dataxchg/clipboard)

- [Implementação de arrastar e soltar (OLE)](../mfc/drag-and-drop-ole.md)

## <a name="see-also"></a>Consulte também

[Elementos da Interface do usuário](../mfc/user-interface-elements-mfc.md)
