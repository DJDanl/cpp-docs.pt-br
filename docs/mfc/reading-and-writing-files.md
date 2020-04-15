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
ms.openlocfilehash: 6c4b2b21bbfa19fb73997f8475cfa9a4047dc0ca
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371793"
---
# <a name="reading-and-writing-files"></a>Lendo e gravando arquivos

Se você tiver usado as funções de manipulação de arquivos da biblioteca em tempo de execução C, as operações de leitura e escrita do MFC serão familiares. Este artigo descreve ler diretamente e `CFile` escrever diretamente para um objeto. Você também pode fazer I/O de arquivo tampão com a classe [CArchive.](../mfc/reference/carchive-class.md)

#### <a name="to-read-from-and-write-to-the-file"></a>Para ler e escrever para o arquivo

1. Use `Read` as `Write` funções e membro para ler e gravar dados no arquivo.

     -ou-

1. A `Seek` função membro também está disponível para mover-se para um deslocamento específico dentro do arquivo.

`Read`leva um ponteiro para um buffer e o número de bytes para ler e retorna o número real de bytes que foram lidos. Se o número de bytes necessário não puder ser lido porque o EOF (End of-file) é atingido, o número real de bytes lidos é devolvido. Se ocorrer algum erro de leitura, uma exceção será lançada. `Write`é semelhante `Read`a , mas o número de bytes escritos não é devolvido. Se ocorrer um erro de gravação, incluindo não escrever todos os bytes especificados, uma exceção será lançada. Se você tiver `CFile` um objeto válido, você pode lê-lo ou gravá-lo como mostrado no exemplo a seguir:

[!code-cpp[NVC_MFCFiles#2](../atl-mfc-shared/reference/codesnippet/cpp/reading-and-writing-files_1.cpp)]

> [!NOTE]
> Você deve normalmente realizar operações de entrada/saída dentro de um bloco de manipulação de**exceção** **de captura de tentativa.**/ Para obter mais informações, consulte [O Manuseio de Exceções (MFC)](../mfc/exception-handling-in-mfc.md).

## <a name="see-also"></a>Confira também

[Arquivos](../mfc/files-in-mfc.md)
