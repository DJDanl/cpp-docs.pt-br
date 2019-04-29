---
title: Serialização em MFC
ms.date: 11/04/2016
helpviewer_keywords:
- collection classes [MFC], serialization
- bypassing serialization [MFC]
- MFC, serialization
- serialization [MFC], MFC
- serialization [MFC], bypassing
ms.assetid: fb596a18-4522-47e0-96e0-192732d24c12
ms.openlocfilehash: 5c7dec140635b6d83bdae936d1bb0cef144f825b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62308206"
---
# <a name="serialization-in-mfc"></a>Serialização em MFC

Este artigo explica o mecanismo de serialização fornecido no Microsoft Foundation Class Library (MFC) para permitir que os objetos persistam entre execuções do seu programa.

A serialização é o processo de gravação ou leitura de um objeto para ou de uma mídia de armazenamento persistente, como um arquivo de disco. A serialização é ideal para situações em que é desejado para manter o estado de dados estruturados (como classes C++ ou estruturas) durante ou após a execução de um programa. Usando os objetos de serialização fornecidos pelo MFC permite que isso ocorra de maneira consistente e padrão, poupando o usuário da necessidade de executar operações de arquivo manualmente.

MFC fornece suporte interno para a serialização na classe `CObject`. Portanto, todas as classes derivadas de `CObject` podem aproveitar `CObject`do protocolo de serialização.

A ideia básica de serialização é que um objeto deve ser capaz de gravar seu estado atual, geralmente é indicado pelo valor de suas variáveis de membro, para o armazenamento persistente. Posteriormente, o objeto pode ser recriado por meio de leitura ou desserialização, o estado do objeto do armazenamento. Serialização lida com todos os detalhes de ponteiros para objetos e referências circulares a objetos que são usados quando você serializa um objeto. Um ponto importante é que o próprio objeto é responsável por ler e gravar seu próprio estado. Assim, para uma classe seja serializável, ela deve implementar as operações de serialização básica. Conforme mostrado no grupo de serialização de artigos, é fácil adicionar essa funcionalidade a uma classe.

O MFC usa um objeto do `CArchive` classe como um intermediário entre o objeto a ser serializado e a mídia de armazenamento. Esse objeto está sempre associado um `CFile` objeto, que obtém as informações necessárias para a serialização, incluindo o nome do arquivo e se a operação solicitada é uma leitura ou gravação. O objeto que executa uma operação de serialização pode usar o `CArchive` objeto sem levar em consideração a natureza da mídia de armazenamento.

Um `CArchive` usa o objeto inserção sobrecarregado (**<\<**) e a extração (**>>**) operadores para executar a gravação e leitura de operações. Para obter mais informações, consulte [armazenando e carregando CObjects por meio de um arquivo morto](../mfc/storing-and-loading-cobjects-via-an-archive.md) no artigo de serialização: Serializando um objeto.

> [!NOTE]
>  Não confunda o `CArchive` formatado de classe com classes de uso geral iostream, que são para somente texto. O `CArchive` classe é para objetos serializados do formato binário.

Se você quiser, você pode ignorar a serialização do MFC para criar seu próprio mecanismo de armazenamento de dados persistente. Você precisará substituir as funções de membro de classe que iniciam a serialização em mãos do usuário. Consulte a discussão na [22 de observação técnica](../mfc/tn022-standard-commands-implementation.md) dos comandos padrão ID_FILE_OPEN, ID_FILE_SAVE e ID_FILE_SAVE_AS.

Os artigos a seguir abordam as duas tarefas principais necessárias para a serialização:

- [Serialização: criar uma classe serializável](../mfc/serialization-making-a-serializable-class.md)

- [Serialização: serializar um objeto](../mfc/serialization-serializing-an-object.md)

O artigo [serialização: Serialização vs. Entrada/saída de banco de dados](../mfc/serialization-serialization-vs-database-input-output.md) descreve quando a serialização é uma técnica de entrada/saída apropriada em aplicativos de banco de dados.

## <a name="see-also"></a>Consulte também

[Conceitos](../mfc/mfc-concepts.md)<br/>
[Tópicos gerais do MFC](../mfc/general-mfc-topics.md)<br/>
[Classe CArchive](../mfc/reference/carchive-class.md)<br/>
[Classe CObject](../mfc/reference/cobject-class.md)<br/>
[Classe CDocument](../mfc/reference/cdocument-class.md)<br/>
[Classe CFile](../mfc/reference/cfile-class.md)
