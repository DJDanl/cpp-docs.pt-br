---
title: 'Windows Sockets: usando soquetes com arquivos mortos'
ms.date: 11/04/2016
helpviewer_keywords:
- Windows Sockets [MFC], archives
- sockets [MFC], with archives
- archives [MFC], and Windows Sockets
- CSocket class [MFC], programming model
ms.assetid: 17e71a99-a09e-4e1a-9fda-13d62805c824
ms.openlocfilehash: 55b4f9a5412c1447fe2b3bde10cb934b91abf008
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81359961"
---
# <a name="windows-sockets-using-sockets-with-archives"></a>Windows Sockets: usando soquetes com arquivos mortos

Este artigo descreve o [modelo de programação CSocket](#_core_the_csocket_programming_model). Classe [CSocket](../mfc/reference/csocket-class.md) fornece suporte ao soquete em um nível mais alto de abstração do que a classe [CAsyncSocket](../mfc/reference/casyncsocket-class.md). `CSocket`usa uma versão do protocolo de serialização do MFC para passar dados de e para um objeto de soquete através de um objeto MFC [CArchive.](../mfc/reference/carchive-class.md) `CSocket`fornece bloqueio (enquanto gerencia o processamento em segundo `CArchive`plano de mensagens do Windows) e lhe dá acesso, o que `CAsyncSocket`gerencia muitos aspectos da comunicação que você teria que fazer usando a API ou a classe brutas.

> [!TIP]
> Você pode `CSocket` usar a classe por si só, como uma versão mais conveniente de , mas o modelo de `CAsyncSocket`programação mais simples é usar `CSocket` com um `CArchive` objeto.

Para obter mais informações sobre como funciona a implementação de soquetes com arquivos, consulte [Soquetes do Windows: Como soquetes com arquivos funcionam](../mfc/windows-sockets-how-sockets-with-archives-work.md). Por exemplo, código, consulte [Soquetes do Windows: Seqüência de Operações](../mfc/windows-sockets-sequence-of-operations.md) e [Soquetes do Windows: Exemplo de Soquetes Usando Arquivos](../mfc/windows-sockets-example-of-sockets-using-archives.md). Para obter informações sobre algumas das funcionalidades que você pode obter, derivando suas próprias classes das classes de soquetes, consulte [Soquetes do Windows: Derivados de Classes de Soquete](../mfc/windows-sockets-deriving-from-socket-classes.md).

> [!NOTE]
> Se você estiver escrevendo um programa cliente MFC para se comunicar com servidores estabelecidos (não-MFC), não envie objetos C++ através do arquivo. A menos que o servidor seja um aplicativo MFC que entenda os tipos de objetos que você deseja enviar, ele não será capaz de receber e desserializar seus objetos. Para obter material relacionado sobre o assunto de comunicação com aplicativos não-MFC, consulte também o artigo [Soquetes do Windows: Byte Ordering](../mfc/windows-sockets-byte-ordering.md).

## <a name="the-csocket-programming-model"></a><a name="_core_the_csocket_programming_model"></a>O modelo de programação csocket

O `CSocket` uso de um objeto envolve criar e associar vários objetos de classe MFC. No procedimento geral abaixo, cada passo é dado tanto pelo soquete do servidor quanto pelo soquete do cliente, exceto pela etapa 3, na qual cada tipo de soquete requer uma ação diferente.

> [!TIP]
> Em tempo de execução, o aplicativo do servidor geralmente começa primeiro a estar pronto e "ouvir" quando o aplicativo cliente busca uma conexão. Se o servidor não estiver pronto quando o cliente tentar se conectar, você normalmente exige que o aplicativo do usuário tente se conectar novamente mais tarde.

#### <a name="to-set-up-communication-between-a-server-socket-and-a-client-socket"></a>Para configurar a comunicação entre um soquete de servidor e um soquete do cliente

1. Construa um objeto [CSocket.](../mfc/reference/csocket-class.md)

1. Use o objeto para criar a alça **SOCKET** subjacente.

   Para `CSocket` um objeto cliente, você normalmente deve usar os parâmetros padrão para [criar,](../mfc/reference/casyncsocket-class.md#create)a menos que você precise de um soquete de datagram. Para `CSocket` um objeto de servidor, você `Create` deve especificar uma porta na chamada.

    > [!NOTE]
    >  `CArchive`não funciona com soquetes de datagram. Se você quiser `CSocket` usar para um soquete de datagram, você deve usar a classe como você `CAsyncSocket`usaria, ou seja, sem um arquivo. Como os datagramas não são confiáveis (não são garantidos para chegar e podem ser repetidos ou fora de seqüência), eles não são compatíveis com serialização através de um arquivo. Você espera que uma operação de serialização seja concluída de forma confiável e em seqüência. Se você tentar `CSocket` usar `CArchive` com um objeto para um datagrama, uma afirmação do MFC falhará.

1. Se o soquete for um cliente, ligue [cAsyncSocket::Conecte-se](../mfc/reference/casyncsocket-class.md#connect) para conectar o objeto do soquete a um soquete do servidor.

     -ou-

   Se o soquete for um servidor, ligue para [CAsyncSocket::Ouça](../mfc/reference/casyncsocket-class.md#listen) para começar a ouvir as tentativas de conexão de um cliente. Ao receber uma solicitação de conexão, aceite-a ligando para [CAsyncSocket:::Aceitar](../mfc/reference/casyncsocket-class.md#accept).

    > [!NOTE]
    >  A `Accept` função membro tem como parâmetro `CSocket` uma referência a um objeto novo e vazio. Você deve construir este `Accept`objeto antes de chamar. Se este objeto de soquete sair do escopo, a conexão será fechada. Não chame `Create` por este novo objeto de soquete.

1. Crie um objeto [CSocketFile,](../mfc/reference/csocketfile-class.md) associando o objeto a `CSocket` ele.

1. Crie um objeto [CArchive](../mfc/reference/carchive-class.md) para carregar (receber) ou armazenar (envio) dados. O arquivo está `CSocketFile` associado ao objeto.

   Tenha em `CArchive` mente que não funciona com soquetes de datagrama.

1. Use `CArchive` o objeto para passar dados entre os soquetes do cliente e do servidor.

   Tenha em mente `CArchive` que um determinado objeto move dados em uma única direção: seja para carregar (receber) ou armazenar (envio). Em alguns casos, `CArchive` você usará dois objetos: um para envio de dados, outro para receber reconhecimentos.

   Depois de aceitar uma conexão e configurar o arquivo, você pode executar tarefas como validar senhas.

1. Destrua o arquivo, o arquivo do soquete e os objetos do soquete.

    > [!NOTE]
    >  A `CArchive` classe `IsBufferEmpty` fornece a função do `CSocket`membro especificamente para uso com classe . Se o buffer contiver várias mensagens de dados, por exemplo, você precisará fazer loop até que todas elas sejam lidas e o buffer seja limpo. Caso contrário, sua próxima notificação de que há dados a serem recebidos pode ser indefinidamente adiada. Use `IsBufferEmpty` para garantir que você recupere todos os dados.

O artigo [Soquetes do Windows: Sequência de Operações](../mfc/windows-sockets-sequence-of-operations.md) ilustra ambos os lados deste processo com código de exemplo.

Para obter mais informações, consulte:

- [Windows Sockets: soquetes de fluxo](../mfc/windows-sockets-stream-sockets.md)

- [Windows Sockets: soquetes de datagrama](../mfc/windows-sockets-datagram-sockets.md)

## <a name="see-also"></a>Confira também

[Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)<br/>
[CSocket::Criar](../mfc/reference/csocket-class.md#create)
