---
title: 'Windows Sockets: Como funcionam soquetes com arquivos mortos'
ms.date: 11/19/2018
helpviewer_keywords:
- Windows Sockets [MFC], synchronous
- sockets [MFC], synchronous operation
- sockets [MFC], with archives
- synchronous state socket
- Windows Sockets [MFC], with archives
- two-state socket object
ms.assetid: d8ae4039-391d-44f0-a19b-558817affcbb
ms.openlocfilehash: 3af94bc881276238f1a8d2dbeeee4dca1f173a4b
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57300677"
---
# <a name="windows-sockets-how-sockets-with-archives-work"></a>Windows Sockets: Como funcionam soquetes com arquivos mortos

Este artigo explica como um [CSocket](../mfc/reference/csocket-class.md) objeto, um [CSocketFile](../mfc/reference/csocketfile-class.md) objeto e uma [CArchive](../mfc/reference/carchive-class.md) objeto são combinadas para simplificar o envio e recebimento de dados por meio de um Windows Soquete.

O artigo [Windows Sockets: Exemplo de soquetes usando arquivamentos](../mfc/windows-sockets-example-of-sockets-using-archives.md) apresenta o `PacketSerialize` função. O objeto de arquivo morto na `PacketSerialize` exemplo funciona bem como um objeto de arquivo morto passado para um MFC [Serialize](../mfc/reference/cobject-class.md#serialize) função. A diferença de essencial é que, para soquetes, o arquivo morto é anexado não a um padrão [CFile](../mfc/reference/cfile-class.md) objeto (normalmente associado a um arquivo de disco), mas para um `CSocketFile` objeto. Em vez de se conectar a um arquivo de disco, o `CSocketFile` objeto se conecta a um `CSocket` objeto.

Um `CArchive` objeto gerencia um buffer. Quando o buffer de um arquivo de armazenamento (envio) estiver cheio, um associado `CFile` objeto grava o conteúdo do buffer. Liberando o buffer de um arquivo anexado a um soquete é equivalente a enviar uma mensagem. Quando o buffer de um arquivo de carregamento (recebimento) estiver cheio, o `CFile` objeto interromperá a leitura até que o buffer esteja disponível novamente.

Classe `CSocketFile` deriva `CFile`, mas não oferece suporte [CFile](../mfc/reference/cfile-class.md) funções de membro, como as funções de posicionamento (`Seek`, `GetLength`, `SetLength`e assim por diante), o bloqueio de funções ( `LockRange`, `UnlockRange`), ou o `GetPosition` função. Todos os [CSocketFile](../mfc/reference/csocketfile-class.md) objeto deve fazer é de gravação ou leitura de sequências de bytes para ou de associado `CSocket` objeto. Porque um arquivo não está envolvido, operações, como `Seek` e `GetPosition` não fazem sentido. `CSocketFile` é derivado de `CFile`, portanto, ele normalmente herdaria todas essas funções de membro. Para evitar isso, sem o suporte `CFile` funções de membro são substituídas no `CSocketFile` para lançar um [CNotSupportedException](../mfc/reference/cnotsupportedexception-class.md).

O `CSocketFile` objeto chama o membro de funções de seu `CSocket` objeto para enviar ou receber dados.

A figura a seguir mostra as relações entre esses objetos em ambos os lados da comunicação.

![CArchive, CSocketFile e CSocket](../mfc/media/vc38ia1.gif "CArchive, CSocketFile e CSocket") <br/>
CArchive, CSocketFile e CSocket

A finalidade dessa complexidade aparente é proteger você da necessidade de gerenciar os detalhes do soquete por conta própria. Você cria o soquete, o arquivo e o arquivo morto e, em seguida, começar a enviar ou receber dados por inseri-lo para o arquivo morto ou extraindo-o do arquivo morto. [CArchive](../mfc/reference/carchive-class.md), [CSocketFile](../mfc/reference/csocketfile-class.md), e [CSocket](../mfc/reference/csocket-class.md) gerenciar os detalhes nos bastidores.

Um `CSocket` é, na verdade, um objeto de dois estados: assíncrona, às vezes, (o estado normal) e, às vezes, síncrono. Em seu estado assíncrono, um soquete pode receber notificações assíncronas do framework. No entanto, durante uma operação, como recebimento ou envio de dados o soquete se torna síncrono. Isso significa que o soquete receberão nenhuma outra notificações assíncronas até que a operação síncrona seja concluída. Porque ele alterna os modos, você pode, por exemplo, fazer algo semelhante ao seguinte:

[!code-cpp[NVC_MFCSimpleSocket#2](../mfc/codesnippet/cpp/windows-sockets-how-sockets-with-archives-work_1.cpp)]

Se `CSocket` não foram implementados como um objeto de dois estados, é possível receber notificações adicionais para o mesmo tipo de evento, embora você esteja processando uma notificação anterior. Por exemplo, você pode obter um `OnReceive` notificação ao processar um `OnReceive`. No fragmento de código acima, extraindo `str` do arquivo morto pode levar a recursão. Alternando estados, `CSocket` impede a recursão, impedindo que notificações adicionais. A regra geral não é que nenhuma notificação dentro de notificações.

> [!NOTE]
> Um `CSocketFile` também pode ser usado como um arquivo (limitado) sem um `CArchive` objeto. Por padrão, o `CSocketFile` do construtor *bArchiveCompatible* parâmetro é **TRUE**. Isso especifica que o objeto de arquivo é para uso com um arquivo morto. Para usar o objeto de arquivo sem um arquivo morto, passe **falsos** na *bArchiveCompatible* parâmetro.

No modo de "compatível com o arquivo morto", um `CSocketFile` objeto fornece um melhor desempenho e reduz o risco de um "deadlock". Um deadlock ocorre quando os soquetes de envio e recebimento estão aguardando uns aos outros ou aguardando um recurso comum. Essa situação pode ocorrer se o `CArchive` objeto trabalhou com o `CSocketFile` da forma que faz com um `CFile` objeto. Com `CFile`, o arquivo morto pode presumir que se ela recebe menos bytes que ele é solicitado, o final do arquivo foi atingido. Com `CSocketFile`, no entanto, dados for baseado em mensagem; o buffer pode conter várias mensagens, então receber menos do que o número de bytes solicitado não implica o final do arquivo. O aplicativo não bloqueia neste caso, como pode ocorrer com `CFile`, e pode continuar lendo mensagens do buffer até que o buffer está vazio. O [IsBufferEmpty](../mfc/reference/carchive-class.md#isbufferempty) funcionar em `CArchive` é útil para monitorar o estado do buffer do arquivo morto nesse caso.

Para obter mais informações, consulte [Windows Sockets: Usando soquetes com arquivos mortos](../mfc/windows-sockets-using-sockets-with-archives.md)

## <a name="see-also"></a>Consulte também

[Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)<br/>
[CObject::Serialize](../mfc/reference/cobject-class.md#serialize)
