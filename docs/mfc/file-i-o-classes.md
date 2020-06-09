---
title: Classes de I-O de arquivo
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
ms.openlocfilehash: 2fcf4dfc1388df0df2bc25928ec8541486c6bb2d
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84615666"
---
# <a name="file-io-classes"></a>Classes de E/S do arquivo

Essas classes fornecem uma interface para arquivos de disco tradicionais, arquivos na memória, fluxos ativos e Windows Sockets. Todas as classes derivadas de `CFile` podem ser usadas com um `CArchive` objeto para executar a serialização.

Use as classes a seguir, especialmente `CArchive` e `CFile` , se você escrever seu próprio processamento de entrada/saída. Normalmente, você não precisa derivar dessas classes. Se você usar a estrutura do aplicativo, as implementações padrão dos comandos **abrir** e **salvar** no menu **arquivo** tratarão a e/s de arquivo (usando a classe `CArchive` ), desde que você substitua a `Serialize` função do documento para fornecer detalhes sobre como um documento serializa seu conteúdo. Para obter mais informações sobre as classes de arquivo e a serialização, consulte os arquivos de artigo [no MFC](files-in-mfc.md) e o artigo [serialização](serialization-in-mfc.md).

[OLE](reference/cfile-class.md)<br/>
Fornece uma interface de arquivo para arquivos de disco binários.

[CStdioFile](reference/cstdiofile-class.md)<br/>
Fornece uma `CFile` interface para arquivos de disco de fluxo em buffer, geralmente em modo de texto.

[CMemFile](reference/cmemfile-class.md)<br/>
Fornece uma `CFile` interface para arquivos na memória.

[CSharedFile](reference/csharedfile-class.md)<br/>
Fornece uma `CFile` interface para compartilhar arquivos na memória.

[COleStreamFile](reference/colestreamfile-class.md)<br/>
Usa a `IStream` interface com para fornecer `CFile` acesso a arquivos compostos.

[CSocketFile](reference/csocketfile-class.md)<br/>
Fornece uma `CFile` interface para um soquete do Windows.

## <a name="related-classes"></a>Classes relacionadas

[CArchive](reference/carchive-class.md)<br/>
Coopera com um `CFile` objeto para implementar o armazenamento persistente de objetos por meio de serialização (consulte [CObject:: Serialize](reference/cobject-class.md#serialize)).

[CArchiveException](reference/carchiveexception-class.md)<br/>
Uma exceção de arquivamento.

[CFileException](reference/cfileexception-class.md)<br/>
Uma exceção orientada por arquivo.

[CFileDialog](reference/cfiledialog-class.md)<br/>
Fornece uma caixa de diálogo padrão para abrir ou salvar um arquivo.

[CRecentFileList](reference/crecentfilelist-class.md)<br/>
Mantém a lista de arquivos MRU (usados mais recentemente).

## <a name="see-also"></a>Consulte também

[Visão geral da classe](class-library-overview.md)
