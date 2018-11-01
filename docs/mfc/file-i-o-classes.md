---
title: Classes de e / S de arquivo
ms.date: 11/04/2016
f1_keywords:
- vc.classes.file
helpviewer_keywords:
- disk file classes [MFC]
- stdio classes [MFC]
- OLE streams [MFC]
- I/O [MFC], MFC classes
- translated stream classes [MFC]
- file I/O classes [MFC]
- I/O [MFC], classes
- sockets classes [MFC]
- stream classes [MFC]
- memory file classes [MFC]
ms.assetid: 92821c3f-d9e1-47f6-98c9-3b632d86e811
ms.openlocfilehash: a6a47372e77ca8b6adee44125705dc3f4d6b267b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50443102"
---
# <a name="file-io-classes"></a>Classes de E/S do arquivo

Essas classes fornecem uma interface para os arquivos em disco tradicionais, os arquivos na memória, fluxos ativos e soquetes do Windows. Todas as classes derivadas de `CFile` pode ser usado com um `CArchive` objeto para executar a serialização.

Use as classes a seguir, particularmente `CArchive` e `CFile`, se você escrever seu próprio processamento de entrada/saída. Normalmente você não precisará derivam dessas classes. Se você usar a estrutura de aplicativo, as implementações padrão do **aberto** e **salve** os comandos no **arquivo** menu manipulará/s de arquivo (usando a classe `CArchive`), desde que você substitua o seu documento `Serialize` função para fornecer detalhes sobre como um documento serializa seu conteúdo. Para obter mais informações sobre as classes de arquivo e a serialização, consulte o artigo [arquivos no MFC](../mfc/files-in-mfc.md) e o artigo [serialização](../mfc/serialization-in-mfc.md).

[CFile](../mfc/reference/cfile-class.md)<br/>
Fornece uma interface de arquivo para arquivos de disco binário.

[CStdioFile](../mfc/reference/cstdiofile-class.md)<br/>
Fornece um `CFile` interface aos arquivos de disco de fluxo em buffer, geralmente no modo de texto.

[CMemFile](../mfc/reference/cmemfile-class.md)<br/>
Fornece um `CFile` interface para os arquivos na memória.

[CSharedFile](../mfc/reference/csharedfile-class.md)<br/>
Fornece um `CFile` interface para os arquivos compartilhados na memória.

[COleStreamFile](../mfc/reference/colestreamfile-class.md)<br/>
Usa o COM `IStream` interface para fornecer `CFile` acesso compor os arquivos.

[CSocketFile](../mfc/reference/csocketfile-class.md)<br/>
Fornece um `CFile` interface para um soquete do Windows.

## <a name="related-classes"></a>Classes relacionadas

[CArchive](../mfc/reference/carchive-class.md)<br/>
Coopera com um `CFile` objeto para implementar o armazenamento persistente de objetos por meio de serialização (consulte [CObject::Serialize](../mfc/reference/cobject-class.md#serialize)).

[CArchiveException](../mfc/reference/carchiveexception-class.md)<br/>
Uma exceção de arquivo morto.

[CFileException](../mfc/reference/cfileexception-class.md)<br/>
Uma exceção orientado a arquivos.

[CFileDialog](../mfc/reference/cfiledialog-class.md)<br/>
Fornece uma caixa de diálogo padrão para abrir ou salvar um arquivo.

[CRecentFileList](../mfc/reference/crecentfilelist-class.md)<br/>
Mantém a lista de arquivos (MRU) usado com o mais recentemente.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../mfc/class-library-overview.md)

