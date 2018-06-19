---
title: Arrastando e soltando arquivos em uma janela do quadro | Microsoft Docs
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
ms.openlocfilehash: aa326dba7772ddcdccb304900df4460ce9754665
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33345564"
---
# <a name="dragging-and-dropping-files-in-a-frame-window"></a>Arrastando e soltando arquivos em uma janela com moldura
A janela do quadro gerencia uma relação com o Explorador de arquivos ou no Gerenciador de arquivos.  
  
 Por adicionar alguns Inicializando chamadas em sua substituição do `CWinApp` função de membro `InitInstance`, conforme descrito em [CWinApp: A classe do aplicativo](../mfc/cwinapp-the-application-class.md), que a janela do quadro indiretamente abrir arquivos arrastados do arquivo Explorer ou Gerenciador de arquivos e descartados na janela do quadro. Consulte [arquivo Gerenciador de arrastar e soltar](../mfc/special-cwinapp-services.md).  
  
## <a name="see-also"></a>Consulte também  
 [Usando janelas com moldura](../mfc/using-frame-windows.md)

