---
title: Arrastando e soltando arquivos em uma janela de quadro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- drag and drop [MFC], files
- drag and drop [MFC], File Manager
- Windows Explorer [MFC]
- File Manager drag and drop support [MFC]
- files [MFC], drag and drop
- frame windows [MFC], dragging and dropping files in
- drag and drop [MFC], Windows Explorer
ms.assetid: 85560fe9-121b-4105-bd7b-216b966e19fa
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 6fc68923de531240a2d59336c79e54f6562b369c
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46380523"
---
# <a name="dragging-and-dropping-files-in-a-frame-window"></a>Arrastando e soltando arquivos em uma janela com moldura

A janela do quadro gerencia uma relação com o Explorador de arquivos ou o Gerenciador de arquivos.

Por adicionar alguns Inicializando chama em seu substituto do `CWinApp` função de membro `InitInstance`, conforme descrito em [CWinApp: A classe de aplicativo](../mfc/cwinapp-the-application-class.md), você pode ter sua janela de quadro indiretamente abra arquivos arrastados de arquivo Explorer ou Gerenciador de arquivo e descartados na janela do quadro. Ver [arquivo gerenciador arrastar e soltar](../mfc/special-cwinapp-services.md).

## <a name="see-also"></a>Consulte também

[Usando janelas com moldura](../mfc/using-frame-windows.md)

