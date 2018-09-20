---
title: 'Área de transferência: Quando usar cada mecanismo da área de transferência | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- applications [OLE], Clipboard
- OLE Clipboard, guidelines
- Clipboard [MFC], mechanisms
- OLE Clipboard, formats
- formats [MFC], Clipboard for OLE
- Clipboard [MFC], formats
ms.assetid: fd071996-ef8c-488b-81bd-89057095a201
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 18b8a772dd58cf9623d4076665e7859d191bb27e
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46379808"
---
# <a name="clipboard-when-to-use-each-clipboard-mechanism"></a>Área de Transferência: quando usar cada mecanismo da Área de Transferência

Siga estas diretrizes usando a área de transferência:

- Use o mecanismo de área de transferência OLE agora para habilitar novos recursos no futuro. Embora a API padrão da área de transferência será mantida, o mecanismo OLE é o futuro da transferência de dados.

- Use o mecanismo de área de transferência OLE se você estiver escrevendo um aplicativo OLE ou se você deseja que os recursos do OLE, como arrastar e soltar.

- Use o mecanismo de área de transferência OLE se você estiver fornecendo formatos OLE.

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer

- [Usar o mecanismo da área de transferência OLE](../mfc/clipboard-using-the-ole-clipboard-mechanism.md)

- [Usar o mecanismo da área de transferência do Windows](../mfc/clipboard-using-the-windows-clipboard.md)

## <a name="see-also"></a>Consulte também

[Área de transferência](../mfc/clipboard.md)

