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
ms.openlocfilehash: eca4d0357977bc7ef21063718c738ae5bd8e7431
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372744"
---
# <a name="serialization-in-mfc"></a>Serialização em MFC

Este artigo explica o mecanismo de serialização fornecido no Microsoft Foundation Class Library (MFC) para permitir que os objetos persistam entre as corridas do seu programa.

Serialização é o processo de escrever ou ler um objeto para ou a partir de um meio de armazenamento persistente, como um arquivo de disco. A serialização é ideal para situações em que se deseja manter o estado dos dados estruturados (como classes ou estruturas C++) durante ou após a execução de um programa. O uso dos objetos de serialização fornecidos pelo MFC permite que isso ocorra de forma padrão e consistente, aliviando o usuário da necessidade de realizar operações de arquivos manualmente.

O MFC fornece suporte embutido para serialização na classe `CObject`. Assim, todas as `CObject` classes derivadas `CObject`podem aproveitar o protocolo de serialização.

A ideia básica da serialização é que um objeto deve ser capaz de escrever seu estado atual, geralmente indicado pelo valor de suas variáveis de membro, para o armazenamento persistente. Mais tarde, o objeto pode ser recriado lendo ou desserializando o estado do objeto a partir do armazenamento. A serialização lida com todos os detalhes dos ponteiros de objeto e referências circulares a objetos que são usados quando você serializa um objeto. Um ponto-chave é que o objeto em si é responsável pela leitura e escrita de seu próprio estado. Assim, para que uma classe seja serializável, deve implementar as operações básicas de serialização. Como mostrado no grupo serialização de artigos, é fácil adicionar essa funcionalidade a uma classe.

O MFC usa `CArchive` um objeto da classe como intermediário entre o objeto a ser serializado e o meio de armazenamento. Este objeto está sempre `CFile` associado a um objeto, do qual obtém as informações necessárias para serialização, incluindo o nome do arquivo e se a operação solicitada é uma leitura ou gravação. O objeto que realiza uma operação `CArchive` de serialização pode usar o objeto sem considerar a natureza do meio de armazenamento.

Um `CArchive` objeto usa operadores de inserção**<** e extração**>>** sobrecarregados para realizar operações de escrita e leitura. Para obter mais informações, consulte [Armazenar e carregar CObjects através de um Arquivo](../mfc/storing-and-loading-cobjects-via-an-archive.md) no artigo Serialização: Serializando um Objeto.

> [!NOTE]
> Não confunda `CArchive` a classe com as classes iostream de uso geral, que são apenas para texto formatado. A `CArchive` classe é para objetos serializados em formato binário.

Se você quiser, você pode contornar a serialização do MFC para criar seu próprio mecanismo para armazenamento de dados persistente. Você precisará substituir as funções de membro da classe que iniciam a serialização no comando do usuário. Veja a discussão na [Nota Técnica 22](../mfc/tn022-standard-commands-implementation.md) dos comandos padrão ID_FILE_OPEN, ID_FILE_SAVE e ID_FILE_SAVE_AS.

Os seguintes artigos abrangem as duas principais tarefas necessárias para a serialização:

- [Serialização: criando uma classe serializável](../mfc/serialization-making-a-serializable-class.md)

- [Serialização: serializando um objeto](../mfc/serialization-serializing-an-object.md)

O artigo [Serialização: Serialização vs. Entrada/Saída do banco de dados](../mfc/serialization-serialization-vs-database-input-output.md) descreve quando a serialização é uma técnica apropriada de entrada/saída em aplicativos de banco de dados.

## <a name="see-also"></a>Confira também

[Conceitos](../mfc/mfc-concepts.md)<br/>
[Tópicos MFC gerais](../mfc/general-mfc-topics.md)<br/>
[Classe CArchive](../mfc/reference/carchive-class.md)<br/>
[Classe CObject](../mfc/reference/cobject-class.md)<br/>
[Classe CDocument](../mfc/reference/cdocument-class.md)<br/>
[Classe CFile](../mfc/reference/cfile-class.md)
