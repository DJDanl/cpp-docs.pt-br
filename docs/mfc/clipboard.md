---
title: Área de transferência | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- cutting and copying data
- copying data
- Clipboard
- Clipboard, programming
- transferring data
ms.assetid: a71b2824-1f14-4914-8816-54578d73ad4e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f2ad21bcbff31335f6ec79a4527ef7d99e07e547
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="clipboard"></a>Área de Transferência
Essa família de artigos explica como implementar o suporte para a área de transferência do Windows em aplicativos MFC. A área de transferência do Windows é usada de duas maneiras:  
  
-   Implementação de comandos do menu Editar padrão, como Recortar, copiar e colar.  
  
-   Implementando uniforme de dados transferidos com arrastar e soltar (OLE).  
  
 A área de transferência é o método padrão do Windows de transferência de dados entre uma origem e um destino. Ele também pode ser muito útil para operações de OLE. Com o surgimento de OLE, há dois mecanismos de área de transferência no Windows. A API de área de transferência do Windows padrão ainda está disponível, mas tem sido complementada com o mecanismo de transferência de dados OLE. Transferência de dados uniforme OLE (UDT) dá suporte a recortar, copiar e colar com a área de transferência e arrastar e soltar.  
  
 A área de transferência é um serviço de sistema compartilhado por toda a sessão Windows, portanto ele não tem uma classe de seu próprio ou um identificador. Gerenciar a área de transferência por meio de funções de membro da classe [CWnd](../mfc/reference/cwnd-class.md).  
  
## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Quando usar cada mecanismo da área de transferência](../mfc/clipboard-when-to-use-each-clipboard-mechanism.md)  
  
-   [Usando a API tradicional de área de transferência do Windows](../mfc/clipboard-using-the-windows-clipboard.md)  
  
-   [Usando o mecanismo da área de transferência OLE](../mfc/clipboard-using-the-ole-clipboard-mechanism.md)  
  
-   [Copiando e colando dados](../mfc/clipboard-copying-and-pasting-data.md)  
  
-   [Adicionando outros formatos](../mfc/clipboard-adding-other-formats.md)  
  
-   [A área de transferência do Windows](https://msdn.microsoft.com/library/ms648709)  
  
-   [Implementação de arrastar e soltar (OLE)](../mfc/drag-and-drop-ole.md)  
  
## <a name="see-also"></a>Consulte também  
 [Elementos da Interface do usuário](../mfc/user-interface-elements-mfc.md)
