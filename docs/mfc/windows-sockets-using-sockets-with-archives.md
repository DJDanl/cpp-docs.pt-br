---
title: 'Windows Sockets: Usando soquetes com arquivos mortos'
ms.date: 11/04/2016
helpviewer_keywords:
- Windows Sockets [MFC], archives
- sockets [MFC], with archives
- archives [MFC], and Windows Sockets
- CSocket class [MFC], programming model
ms.assetid: 17e71a99-a09e-4e1a-9fda-13d62805c824
ms.openlocfilehash: 71a7ed1f1b67bed157805328679a18ceabf201d3
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62358273"
---
# <a name="windows-sockets-using-sockets-with-archives"></a>Windows Sockets: Usando soquetes com arquivos mortos

Este artigo descreve o [modelo de programação CSocket](#_core_the_csocket_programming_model). Classe [CSocket](../mfc/reference/csocket-class.md) fornece suporte a soquete de nível mais alto de abstração de classe [CAsyncSocket](../mfc/reference/casyncsocket-class.md). `CSocket` usa uma versão do protocolo de serialização do MFC para passar dados para e de um objeto de soquete por meio de um MFC [CArchive](../mfc/reference/carchive-class.md) objeto. `CSocket` fornece o bloqueio (enquanto gerencia o processamento em segundo plano de mensagens do Windows) e fornece acesso à `CArchive`, que gerencia muitos aspectos da comunicação que teria de fazer por conta própria usando o brutos API ou classe `CAsyncSocket`.

> [!TIP]
>  Você pode usar a classe `CSocket` sozinho, como uma versão mais conveniente `CAsyncSocket`, mas o modelo de programação mais simples é usar `CSocket` com um `CArchive` objeto.

Para obter mais informações sobre como funciona a implementação de soquetes com arquivos mortos, consulte [Windows Sockets: Como funcionam soquetes com arquivos mortos](../mfc/windows-sockets-how-sockets-with-archives-work.md). Por exemplo de código, consulte [Windows Sockets: Sequência de operações](../mfc/windows-sockets-sequence-of-operations.md) e [Windows Sockets: Exemplo de soquetes que usam arquivos mortos](../mfc/windows-sockets-example-of-sockets-using-archives.md). Para obter informações sobre algumas das funcionalidades que você pode obter, derivando suas próprias classes das classes de soquetes, consulte [Windows Sockets: Derivando de Classes de soquete](../mfc/windows-sockets-deriving-from-socket-classes.md).

> [!NOTE]
>  Se você estiver escrevendo um programa de cliente do MFC para se comunicar com servidores estabelecida (não MFC), não envie objetos C++ por meio do arquivo morto. A menos que o servidor for um aplicativo do MFC que compreende os tipos de objetos que você deseja enviar, não será capaz de receber e desserializar os seus objetos. Para obter material relacionado sobre o assunto de se comunicar com aplicativos não MFC, consulte também o artigo [Windows Sockets: A ordem de bytes](../mfc/windows-sockets-byte-ordering.md).

##  <a name="_core_the_csocket_programming_model"></a> O modelo de programação CSocket

Usando um `CSocket` objeto envolve criar e associar juntos vários objetos de classe do MFC. O procedimento geral abaixo, cada etapa é obtida por soquete de servidor e o soquete de cliente, exceto para a etapa 3, em que cada tipo de soquete requer uma ação diferente.

> [!TIP]
>  Em tempo de execução, o aplicativo de servidor geralmente começa pela primeira vez ser preparado e "escuta" quando o aplicativo cliente busca uma conexão. Se o servidor não está pronto quando o cliente tenta se conectar, você normalmente exige o aplicativo de usuário para se conectar novamente mais tarde.

#### <a name="to-set-up-communication-between-a-server-socket-and-a-client-socket"></a>Para configurar a comunicação entre um soquete de servidor e um soquete de cliente

1. Construir uma [CSocket](../mfc/reference/csocket-class.md) objeto.

1. Usar o objeto para criar subjacente **soquete** manipular.

   Para um `CSocket` objeto de cliente, você normalmente deve usar os parâmetros padrão para [criar](../mfc/reference/casyncsocket-class.md#create), a menos que você precisa de um soquete de datagrama. Para um `CSocket` objeto de servidor, você deve especificar uma porta no `Create` chamar.

    > [!NOTE]
    >  `CArchive` não funciona com soquetes de datagrama. Se você quiser usar `CSocket` para um soquete de datagrama, você deve usar a classe como você usaria `CAsyncSocket`, ou seja, sem um arquivo morto. Porque datagramas não são confiáveis (não a garantia de que chegam e podem ser repetidas ou fora de sequência), eles não são compatíveis com a serialização por meio de um arquivo morto. Você espera que uma operação de serialização para concluir com confiança e na sequência. Se você tentar usar `CSocket` com um `CArchive` de objeto para um datagrama uma asserção MFC falha.

1. Se o soquete é um cliente, chame [CAsyncSocket::Connect](../mfc/reference/casyncsocket-class.md#connect) para conectar-se o objeto de soquete para um soquete de servidor.

     - ou -

   Se o soquete é um servidor, chame [CAsyncSocket::Listen](../mfc/reference/casyncsocket-class.md#listen) para começar a escutar tentativas de conexão de um cliente. Ao receber uma solicitação de conexão, aceitá-lo chamando [CAsyncSocket::Accept](../mfc/reference/casyncsocket-class.md#accept).

    > [!NOTE]
    >  O `Accept` função de membro usa uma referência a um novo e vazio `CSocket` objeto como seu parâmetro. Você deve construir esse objeto antes de chamar `Accept`. Se esse objeto de soquete sai do escopo, a conexão será fechada. Não chame `Create` para esse novo objeto de soquete.

1. Criar uma [CSocketFile](../mfc/reference/csocketfile-class.md) do objeto, associando o `CSocket` objeto com ele.

1. Criar uma [CArchive](../mfc/reference/carchive-class.md) objeto para carregamento (recebimento) ou armazenamento de dados (envio). O arquivo está associado com o `CSocketFile` objeto.

   Tenha em mente que `CArchive` não funciona com soquetes de datagrama.

1. Use o `CArchive` objeto para passar dados entre os soquetes de cliente e servidor.

   Tenha em mente que um determinado `CArchive` objeto move dados em apenas uma direção: para carregamento (recebimento) ou armazenar (envio). Em alguns casos, você usará dois `CArchive` objetos: uma para envio de dados, o outro para o recebimento de confirmações.

   Depois de aceitar uma conexão e como configurar o arquivo morto, você pode executar tarefas como a validação de senhas.

1. Destrua objetos de soquete, o arquivo de soquete e arquivamento.

    > [!NOTE]
    >  Classe `CArchive` fornece a `IsBufferEmpty` função de membro especificamente para uso com a classe `CSocket`. Por exemplo, se o buffer contém várias mensagens de dados, você precisará executar um loop até que todos eles são lidos e o buffer será limpo. Caso contrário, sua próxima notificação de que há dados a serem recebidos pode ser atrasada por tempo indeterminado. Use `IsBufferEmpty` para garantir que você recuperar todos os dados.

O artigo [Windows Sockets: Sequência de operações](../mfc/windows-sockets-sequence-of-operations.md) ilustra ambos os lados desse processo com o código de exemplo.

Para obter mais informações, consulte:

- [Windows Sockets: soquetes de fluxo](../mfc/windows-sockets-stream-sockets.md)

- [Windows Sockets: soquetes de datagrama](../mfc/windows-sockets-datagram-sockets.md)

## <a name="see-also"></a>Consulte também

[Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)<br/>
[CSocket::Create](../mfc/reference/csocket-class.md#create)
