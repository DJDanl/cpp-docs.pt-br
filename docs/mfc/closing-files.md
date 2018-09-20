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
ms.openlocfilehash: 9c392ef728e1d796a02cfa32edc2c3e8c74d083b
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46426231"
---
# <a name="closing-files"></a>Fechando arquivos

Como de costume em operações de e/s, depois de concluir com um arquivo, você deve fechá-lo.

#### <a name="to-close-a-file"></a>Para fechar um arquivo

1. Use o **fechar** função de membro. Essa função fecha o arquivo de sistema de arquivos e libera buffers, se necessário.

Se você tiver atribuído a [CFile](../mfc/reference/cfile-class.md) objeto no quadro (como no exemplo mostrado na [abrindo arquivos](../mfc/opening-files.md)), o objeto automaticamente será ser fechado e, em seguida, destruídos quando ele sai do escopo. Observe que excluí o `CFile` objeto não exclui o arquivo físico no sistema de arquivos.

## <a name="see-also"></a>Consulte também

[Arquivos](../mfc/files-in-mfc.md)

