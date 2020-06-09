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
ms.openlocfilehash: 8b8859e188e42f4419ca7ee7f683cc31de0c75b3
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84625874"
---
# <a name="files-in-mfc"></a>Arquivos no MFC

Na biblioteca MFC (MFC), a classe [testcfile](reference/cfile-class.md) lida com as operações normais de e/s de arquivo. Esta família de artigos explica como abrir e fechar arquivos, bem como ler e gravar dados nesses arquivos. Ele também aborda as operações de status do arquivo. Para obter uma descrição de como usar os recursos de serialização baseados em objeto do MFC como uma maneira alternativa de ler e gravar dados em arquivos, consulte o artigo [serialização](serialization-in-mfc.md).

> [!NOTE]
> Quando você usa `CDocument` objetos MFC, a estrutura faz grande parte do trabalho de serialização para você. Em particular, a estrutura cria e usa o `CFile` objeto. Você só precisa escrever código em sua substituição da `Serialize` função membro da classe `CDocument` .

A `CFile` classe fornece uma interface para operações de arquivo binário de uso geral. As `CStdioFile` `CMemFile` classes e derivadas de `CFile` e a `CSharedFile` classe derivada de `CMemFile` fornecem serviços de arquivo mais especializados.

Para obter mais informações sobre alternativas à manipulação de arquivos do MFC, consulte [manipulação de arquivos](../c-runtime-library/file-handling.md) na referência da biblioteca de *tempo de execução*.

Para obter informações sobre `CFile` classes derivadas, consulte o [gráfico de hierarquia do MFC](hierarchy-chart.md).

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer

*Usar RecFile*

- [Abrir um arquivo com arquivos de RecFile](opening-files.md)

- [Ler e gravar um arquivo com arquivos de RecFile](reading-and-writing-files.md)

- [Fechar um arquivo com a testcfile](closing-files.md)

- [Acessar o status do arquivo com RecFile](accessing-file-status.md)

*Usar serialização MFC (persistência de objeto)*

- [Criar uma classe serializável](serialization-making-a-serializable-class.md)

- [Serializar um objeto por meio de um objeto CArchive](serialization-serializing-an-object.md)

- [Criar um objeto CArchive](two-ways-to-create-a-carchive-object.md)

- [Usar operadores de \< and >> <CArchive](using-the-carchive-output-and-input-operators.md)

- [Armazenar e carregar objetos derivados de CObjects e CObject por meio de um arquivo](storing-and-loading-cobjects-via-an-archive.md)

## <a name="see-also"></a>Consulte também

[Conceitos](mfc-concepts.md)<br/>
[Tópicos MFC gerais](general-mfc-topics.md)<br/>
[Classe CArchive](reference/carchive-class.md)<br/>
[Classe CObject](reference/cobject-class.md)
