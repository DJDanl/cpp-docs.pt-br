---
title: Arrastando e soltando arquivos em uma janela do quadro | Microsoft Docs
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
- drag and drop [MFC], files
- drag and drop [MFC], File Manager
- Windows Explorer [MFC]
- File Manager drag and drop support [MFC]
- files [MFC], drag and drop
- frame windows [MFC], dragging and dropping files in
- drag and drop [MFC], Windows Explorer
ms.assetid: 85560fe9-121b-4105-bd7b-216b966e19fa
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 938640ed85e51d2b94b292bfe78a8d912b095188
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="dragging-and-dropping-files-in-a-frame-window"></a>Arrastando e soltando arquivos em uma janela com moldura
A janela do quadro gerencia uma relação com o Explorador de arquivos ou no Gerenciador de arquivos.  
  
 Por adicionar alguns Inicializando chamadas em sua substituição do `CWinApp` função de membro `InitInstance`, conforme descrito em [CWinApp: A classe do aplicativo](../mfc/cwinapp-the-application-class.md), que a janela do quadro indiretamente abrir arquivos arrastados do arquivo Explorer ou Gerenciador de arquivos e descartados na janela do quadro. Consulte [arquivo Gerenciador de arrastar e soltar](../mfc/special-cwinapp-services.md).  
  
## <a name="see-also"></a>Consulte também  
 [Usando janelas com moldura](../mfc/using-frame-windows.md)

