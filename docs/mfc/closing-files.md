---
title: Fechando arquivos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- MFC, file operations
- files [MFC], closing
ms.assetid: 8415a3a8-3c75-45b0-ac2a-d5385f49bdb3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 97bd910ae4cb514cda07dd319f37a05a32712909
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="closing-files"></a>Fechando arquivos
Como de costume em operações de e/s, quando você termina com um arquivo, você deve fechá-lo.  
  
#### <a name="to-close-a-file"></a>Para fechar um arquivo  
  
1.  Use o **fechar** função de membro. Essa função fecha o arquivo de sistema de arquivos e libera buffers, se necessário.  
  
 Se você tiver atribuído a [CFile](../mfc/reference/cfile-class.md) objeto no quadro (como no exemplo mostrado na [abrir arquivos](../mfc/opening-files.md)), o objeto será automaticamente ser fechado e, em seguida, destruídos quando ele sai do escopo. Observe que a exclusão de `CFile` objeto não exclui o arquivo físico no sistema de arquivos.  
  
## <a name="see-also"></a>Consulte também  
 [Arquivos](../mfc/files-in-mfc.md)

