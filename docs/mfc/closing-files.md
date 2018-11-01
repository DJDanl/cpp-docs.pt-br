---
title: Fechando arquivos
ms.date: 11/04/2016
helpviewer_keywords:
- MFC, file operations
- files [MFC], closing
ms.assetid: 8415a3a8-3c75-45b0-ac2a-d5385f49bdb3
ms.openlocfilehash: 04e5084615b1f1cf85d9f41e2c4dcc84910b9d05
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50636250"
---
# <a name="closing-files"></a>Fechando arquivos

Como de costume em operações de e/s, depois de concluir com um arquivo, você deve fechá-lo.

#### <a name="to-close-a-file"></a>Para fechar um arquivo

1. Use o **fechar** função de membro. Essa função fecha o arquivo de sistema de arquivos e libera buffers, se necessário.

Se você tiver atribuído a [CFile](../mfc/reference/cfile-class.md) objeto no quadro (como no exemplo mostrado na [abrindo arquivos](../mfc/opening-files.md)), o objeto automaticamente será ser fechado e, em seguida, destruídos quando ele sai do escopo. Observe que excluí o `CFile` objeto não exclui o arquivo físico no sistema de arquivos.

## <a name="see-also"></a>Consulte também

[Arquivos](../mfc/files-in-mfc.md)

