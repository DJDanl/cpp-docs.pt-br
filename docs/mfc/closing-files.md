---
title: Fechando arquivos
ms.date: 11/04/2016
helpviewer_keywords:
- MFC, file operations
- files [MFC], closing
ms.assetid: 8415a3a8-3c75-45b0-ac2a-d5385f49bdb3
ms.openlocfilehash: 69a0960c1edabab00cb71702acda526ee9ebd798
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62326918"
---
# <a name="closing-files"></a>Fechando arquivos

Como de costume em operações de e/s, depois de concluir com um arquivo, você deve fechá-lo.

#### <a name="to-close-a-file"></a>Para fechar um arquivo

1. Use o **fechar** função de membro. Essa função fecha o arquivo de sistema de arquivos e libera buffers, se necessário.

Se você tiver atribuído a [CFile](../mfc/reference/cfile-class.md) objeto no quadro (como no exemplo mostrado na [abrindo arquivos](../mfc/opening-files.md)), o objeto automaticamente será ser fechado e, em seguida, destruídos quando ele sai do escopo. Observe que excluí o `CFile` objeto não exclui o arquivo físico no sistema de arquivos.

## <a name="see-also"></a>Consulte também

[Arquivos](../mfc/files-in-mfc.md)
