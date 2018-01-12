---
title: Fechando arquivos | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- MFC, file operations
- files [MFC], closing
ms.assetid: 8415a3a8-3c75-45b0-ac2a-d5385f49bdb3
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 27b1c59c952b022c7382db7d6b2dcb660cca2e9a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="closing-files"></a>Fechando arquivos
Como de costume em operações de e/s, quando você termina com um arquivo, você deve fechá-lo.  
  
#### <a name="to-close-a-file"></a>Para fechar um arquivo  
  
1.  Use o **fechar** função de membro. Essa função fecha o arquivo de sistema de arquivos e libera buffers, se necessário.  
  
 Se você tiver atribuído a [CFile](../mfc/reference/cfile-class.md) objeto no quadro (como no exemplo mostrado na [abrir arquivos](../mfc/opening-files.md)), o objeto será automaticamente ser fechado e, em seguida, destruídos quando ele sai do escopo. Observe que a exclusão de `CFile` objeto não exclui o arquivo físico no sistema de arquivos.  
  
## <a name="see-also"></a>Consulte também  
 [Arquivos](../mfc/files-in-mfc.md)

