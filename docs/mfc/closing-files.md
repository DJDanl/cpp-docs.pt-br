---
title: Fechando arquivos
ms.date: 11/04/2016
helpviewer_keywords:
- MFC, file operations
- files [MFC], closing
ms.assetid: 8415a3a8-3c75-45b0-ac2a-d5385f49bdb3
ms.openlocfilehash: 51e51c88260a51ec44f11ecb5c2a88e645194f4e
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84617226"
---
# <a name="closing-files"></a>Fechando arquivos

Como de costume nas operações de e/s, depois de terminar com um arquivo, você deve fechá-lo.

#### <a name="to-close-a-file"></a>Para fechar um arquivo

1. Use a função de membro **Close** . Essa função fecha o arquivo do sistema de arquivos e libera os buffers, se necessário.

Se você alocou o objeto [testcfile](reference/cfile-class.md) no quadro (como no exemplo mostrado em [arquivos de abertura](opening-files.md)), o objeto será fechado automaticamente e, em seguida, destruído quando sair do escopo. Observe que a exclusão do `CFile` objeto não exclui o arquivo físico no sistema de arquivos.

## <a name="see-also"></a>Consulte também

[Arquivos](files-in-mfc.md)
