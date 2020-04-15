---
title: Arquivos no MFC
ms.date: 11/04/2016
helpviewer_keywords:
- serialization [MFC], MFC files
- I/O [MFC], MFC classes
- files [MFC], MFC
- files [MFC], serialization
- binary access, binary file operations in MFC
- file I/O classes [MFC]
- I/O [MFC]
- persistence [MFC]
- MFC, file operations
- files [MFC], manipulating
- binary access [MFC]
ms.assetid: ae25e2c5-2859-4679-ab97-438824e93ce1
ms.openlocfilehash: 3a99c4143bbd27ba765b0289b80be8870a940f63
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365311"
---
# <a name="files-in-mfc"></a>Arquivos no MFC

No Microsoft Foundation Class Library (MFC), a classe [CFile](../mfc/reference/cfile-class.md) lida com operações normais de I/O de arquivo. Esta família de artigos explica como abrir e fechar arquivos, bem como ler e gravar dados para esses arquivos. Também discute operações de status de arquivo. Para obter uma descrição de como usar os recursos de serialização baseados em objetos do MFC como uma maneira alternativa de ler e escrever dados em arquivos, consulte o artigo [Serialização](../mfc/serialization-in-mfc.md).

> [!NOTE]
> Quando você usa `CDocument` objetos MFC, a estrutura faz grande parte do trabalho de serialização para você. Em particular, a estrutura `CFile` cria e usa o objeto. Você só tem que escrever código `Serialize` em sua `CDocument`substituição da função membro da classe .

A `CFile` classe fornece uma interface para operações de arquivos binários de uso geral. As `CStdioFile` `CMemFile` classes derivadas `CFile` e `CSharedFile` a classe `CMemFile` derivada da oferta de serviços de arquivos mais especializados.

Para obter mais informações sobre alternativas ao tratamento de arquivos MFC, consulte [O tratamento de arquivos](../c-runtime-library/file-handling.md) na referência da biblioteca em tempo de *execução*.

Para obter informações `CFile` sobre classes derivadas, consulte o gráfico de hierarquia do [MFC](../mfc/hierarchy-chart.md).

## <a name="what-do-you-want-to-do"></a>O que você quer fazer?

*Use CFile*

- [Abra um arquivo com CFile](../mfc/opening-files.md)

- [Ler e gravar um arquivo com cFile](../mfc/reading-and-writing-files.md)

- [Feche um arquivo com CFile](../mfc/closing-files.md)

- [Acesso ao status do arquivo com CFile](../mfc/accessing-file-status.md)

*Use serialização de MFC (persistência do objeto)*

- [Criar uma classe serializável](../mfc/serialization-making-a-serializable-class.md)

- [Serialize um objeto através de um objeto CArchive](../mfc/serialization-serializing-an-object.md)

- [Criar um objeto CArchive](../mfc/two-ways-to-create-a-carchive-object.md)

- [Use operadores \< de <e >> do CArchive](../mfc/using-the-carchive-output-and-input-operators.md)

- [Armazene e carregue Objetos cobjects e derivados do CObject através de um arquivo](../mfc/storing-and-loading-cobjects-via-an-archive.md)

## <a name="see-also"></a>Confira também

[Conceitos](../mfc/mfc-concepts.md)<br/>
[Tópicos MFC gerais](../mfc/general-mfc-topics.md)<br/>
[Classe CArchive](../mfc/reference/carchive-class.md)<br/>
[Classe CObject](../mfc/reference/cobject-class.md)
