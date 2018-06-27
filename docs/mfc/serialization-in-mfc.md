---
title: Serialização em MFC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- collection classes [MFC], serialization
- bypassing serialization [MFC]
- MFC, serialization
- serialization [MFC], MFC
- serialization [MFC], bypassing
ms.assetid: fb596a18-4522-47e0-96e0-192732d24c12
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b46dc8500543ce94b7d8d6a3415b22d019619d83
ms.sourcegitcommit: c6b095c5f3de7533fd535d679bfee0503e5a1d91
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/26/2018
ms.locfileid: "36952587"
---
# <a name="serialization-in-mfc"></a>Serialização em MFC
Este artigo explica como o mecanismo de serialização fornecido no Microsoft Foundation Class Library (MFC) para permitir que objetos persiste entre execuções do seu programa.  
  
 A serialização é o processo de gravação ou leitura de um objeto para ou de uma mídia de armazenamento persistente, como um arquivo de disco. A serialização é ideal para situações em que for necessário manter o estado dos dados estruturados (como classes C++ ou estruturas) durante ou após a execução de um programa. Os objetos de serialização fornecidos pelo MFC permite que isso ocorra de maneira consistente e padrão, liberando o usuário da necessidade de executar operações de arquivo manualmente.  
  
 MFC fornece suporte interno para serialização na classe `CObject`. Assim, todas as classes derivadas de `CObject` pode tirar proveito do `CObject`do protocolo de serialização.  
  
 A ideia básica de serialização é que um objeto deve ser capaz de gravar o estado atual, geralmente é indicado pelo valor de suas variáveis de membro, para o armazenamento persistente. Posteriormente, o objeto pode ser recriado por leitura ou desserialização, o estado do objeto do armazenamento. Serialização manipula todos os detalhes dos ponteiros do objeto e referências circulares para objetos que são usados ao serializar um objeto. Um ponto importante é que o próprio objeto é responsável por ler e gravar seu próprio estado. Portanto, para uma classe ser serializável, ele deve implementar as operações básicas de serialização. Conforme mostrado no grupo de serialização de artigos, é fácil adicionar essa funcionalidade a uma classe.  
  
 MFC usa um objeto de `CArchive` classe como um intermediário entre o objeto a ser serializado e a mídia de armazenamento. Esse objeto é sempre associado a um `CFile` objeto, que obtém as informações necessárias para a serialização, incluindo o nome do arquivo e se a operação solicitada é uma leitura ou gravação. O objeto que executa uma operação de serialização pode usar o `CArchive` objeto sem considerar a natureza da mídia de armazenamento.  
  
 Um `CArchive` objeto usa inserção sobrecarregada (**<\<**) e extração (**>>**) operadores para executar a gravação e leitura de operações. Para obter mais informações, consulte [armazenando e carregando CObjects por meio de um arquivo morto](../mfc/storing-and-loading-cobjects-via-an-archive.md) no artigo de serialização: serializando um objeto.  
  
> [!NOTE]
>  Não confunda o `CArchive` classe com classes de uso geral iostream, que são para formatados somente texto. O `CArchive` classe é para objetos serializados em formato binário.  
  
 Se desejar, você pode ignorar a serialização do MFC para criar seu próprio mecanismo de armazenamento de dados persistentes. Você precisará substituir as funções de membro de classe que iniciam serialização no comando do usuário. Consulte a discussão na [22 de observação técnica](../mfc/tn022-standard-commands-implementation.md) dos comandos padrão ID_FILE_OPEN, ID_FILE_SAVE e ID_FILE_SAVE_AS.  
  
 Os artigos a seguir abordam as duas tarefas principais necessárias para serialização:  
  
-   [Serialização: criando uma classe serializável](../mfc/serialization-making-a-serializable-class.md)  
  
-   [Serialização: serializando um objeto](../mfc/serialization-serializing-an-object.md)  
  
 O artigo [serialização: vs de serialização. Banco de dados de entrada/saída](../mfc/serialization-serialization-vs-database-input-output.md) descreve quando a serialização é uma técnica de entrada/saída apropriada em aplicativos de banco de dados.  
  
## <a name="see-also"></a>Consulte também  
 [Conceitos](../mfc/mfc-concepts.md)   
 [Tópicos MFC gerais](../mfc/general-mfc-topics.md)   
 [Classe CArchive](../mfc/reference/carchive-class.md)   
 [Classe CObject](../mfc/reference/cobject-class.md)   
 [Classe CDocument](../mfc/reference/cdocument-class.md)   
 [Classe CFile](../mfc/reference/cfile-class.md)
