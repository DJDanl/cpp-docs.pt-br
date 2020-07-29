---
title: Lendo e gravando arquivos
ms.date: 11/04/2016
helpviewer_keywords:
- CFile class [MFC], objects
- examples [MFC], reading files
- files [MFC], writing to
- examples [MFC], writing to files
- files [MFC], reading
- MFC, file operations
- CFile class [MFC], reading and writing CFile objects
- reading files
- writing to files [MFC]
ms.assetid: cac0c826-ba56-495f-99b3-ce6336f65763
ms.openlocfilehash: f68fd5c48bce214329437cc13fc39da0c3ca7d2b
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87228577"
---
# <a name="reading-and-writing-files"></a>Lendo e gravando arquivos

Se você usou as funções de manipulação de arquivo de biblioteca de tempo de execução do C, as operações de leitura e gravação do MFC aparecerão familiares. Este artigo descreve a leitura diretamente e a gravação diretamente em um `CFile` objeto. Você também pode fazer e/s de arquivo em buffer com a classe [CArchive](../mfc/reference/carchive-class.md) .

#### <a name="to-read-from-and-write-to-the-file"></a>Para ler e gravar no arquivo

1. Use as `Read` `Write` funções de membro e para ler e gravar dados no arquivo.

     -ou-

1. A `Seek` função de membro também está disponível para a movimentação para um deslocamento específico dentro do arquivo.

`Read`usa um ponteiro para um buffer e o número de bytes a serem lidos e retorna o número real de bytes lidos. Se o número necessário de bytes não puder ser lido porque o fim do arquivo (EOF) foi atingido, o número real de bytes lidos será retornado. Se ocorrer algum erro de leitura, uma exceção será lançada. `Write`é semelhante a `Read` , mas o número de bytes gravados não é retornado. Se ocorrer um erro de gravação, incluindo não gravar todos os bytes especificados, uma exceção será lançada. Se você tiver um `CFile` objeto válido, poderá lê-lo ou gravar nele, conforme mostrado no exemplo a seguir:

[!code-cpp[NVC_MFCFiles#2](../atl-mfc-shared/reference/codesnippet/cpp/reading-and-writing-files_1.cpp)]

> [!NOTE]
> Normalmente, você deve executar operações de entrada/saída em um **`try`** / **`catch`** bloco de manipulação de exceção. Para obter mais informações, consulte [tratamento de exceção (MFC)](../mfc/exception-handling-in-mfc.md).

## <a name="see-also"></a>Confira também

[Arquivos](../mfc/files-in-mfc.md)
