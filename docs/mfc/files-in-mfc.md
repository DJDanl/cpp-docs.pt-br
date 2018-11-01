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
ms.openlocfilehash: 815239b0d4de1938a810153cb98f39b2642b6e2d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50459326"
---
# <a name="files-in-mfc"></a>Arquivos no MFC

No Microsoft Foundation Class Library (MFC), de classe [CFile](../mfc/reference/cfile-class.md) manipula as operações de e/s de arquivo normal. Essa família de artigos explica como abrir e fechar arquivos, bem como ler e gravar dados para esses arquivos. Ele também discute o status de operações de arquivo. Para obter uma descrição de como usar os recursos de baseada em objeto de serialização do MFC como uma maneira alternativa de ler e gravar dados em arquivos, consulte o artigo [serialização](../mfc/serialization-in-mfc.md).

> [!NOTE]
>  Quando você usa o MFC `CDocument` objetos, a estrutura faz grande parte do trabalho de serialização para você. Em particular, o framework cria e usa o `CFile` objeto. Você só precisa escrever código em seu substituto do `Serialize` função de membro da classe `CDocument`.

O `CFile` classe fornece uma interface para operações de arquivo binário para fins gerais. O `CStdioFile` e `CMemFile` as classes derivadas `CFile` e o `CSharedFile` classe derivada de `CMemFile` fornecer serviços de arquivo mais especializados.

Para obter mais informações sobre alternativas para manipulação de arquivos do MFC, consulte [tratamento de arquivos](../c-runtime-library/file-handling.md) na *referência de biblioteca de tempo de execução*.

Para obter informações sobre derivado `CFile` classes, consulte a [gráfico da hierarquia MFC](../mfc/hierarchy-chart.md).

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer

*Usar CFile*

- [Abrir um arquivo com CFile](../mfc/opening-files.md)

- [Ler e gravar um arquivo com CFile](../mfc/reading-and-writing-files.md)

- [Fechar um arquivo com CFile](../mfc/closing-files.md)

- [Status de acesso ao arquivo com CFile](../mfc/accessing-file-status.md)

*Usar a serialização de MFC (persistência de objeto)*

- [Criar uma classe serializável](../mfc/serialization-making-a-serializable-class.md)

- [Serializar um objeto por meio de um objeto CArchive](../mfc/serialization-serializing-an-object.md)

- [Criar um objeto CArchive](../mfc/two-ways-to-create-a-carchive-object.md)

- [Use CArchive <\< e >> operadores](../mfc/using-the-carchive-output-and-input-operators.md)

- [Store e carregar CObjects e derivada de CObject objetos por meio de um arquivo morto](../mfc/storing-and-loading-cobjects-via-an-archive.md)

## <a name="see-also"></a>Consulte também

[Conceitos](../mfc/mfc-concepts.md)<br/>
[Tópicos gerais do MFC](../mfc/general-mfc-topics.md)<br/>
[Classe CArchive](../mfc/reference/carchive-class.md)<br/>
[Classe CObject](../mfc/reference/cobject-class.md)
