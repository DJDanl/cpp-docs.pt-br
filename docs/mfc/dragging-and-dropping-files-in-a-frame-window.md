---
title: Arrastando e soltando arquivos em uma janela com moldura
ms.date: 11/04/2016
helpviewer_keywords:
- drag and drop [MFC], files
- drag and drop [MFC], File Manager
- Windows Explorer [MFC]
- File Manager drag and drop support [MFC]
- files [MFC], drag and drop
- frame windows [MFC], dragging and dropping files in
- drag and drop [MFC], Windows Explorer
ms.assetid: 85560fe9-121b-4105-bd7b-216b966e19fa
ms.openlocfilehash: 0129b939e0fe2afd5dd29623bb44418bfd16c20d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62240654"
---
# <a name="dragging-and-dropping-files-in-a-frame-window"></a>Arrastando e soltando arquivos em uma janela com moldura

A janela do quadro gerencia uma relação com o Explorador de arquivos ou o Gerenciador de arquivos.

Por adicionar alguns Inicializando chama em seu substituto do `CWinApp` função de membro `InitInstance`, conforme descrito em [CWinApp: A classe do aplicativo](../mfc/cwinapp-the-application-class.md), você pode ter sua janela de quadro indiretamente abrir arquivos arrastado do Explorador de arquivos ou do Gerenciador de arquivo e solto na janela do quadro. Ver [arquivo gerenciador arrastar e soltar](../mfc/special-cwinapp-services.md).

## <a name="see-also"></a>Consulte também

[Usando janelas com moldura](../mfc/using-frame-windows.md)
