---
title: 'Windows Sockets: Como funcionam soquetes com arquivos mortos | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- Windows Sockets [MFC], synchronous
- sockets [MFC], synchronous operation
- sockets [MFC], with archives
- synchronous state socket
- Windows Sockets [MFC], with archives
- two-state socket object
ms.assetid: d8ae4039-391d-44f0-a19b-558817affcbb
caps.latest.revision: "12"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 1b6ff5f07e3662e61a7ba6260bb90459f3aebd7d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="windows-sockets-how-sockets-with-archives-work"></a>Windows Sockets: como funcionam soquetes com arquivos mortos
Este artigo explica como um [CSocket](../mfc/reference/csocket-class.md) objeto, um [CSocketFile](../mfc/reference/csocketfile-class.md) objeto e um [CArchive](../mfc/reference/carchive-class.md) objeto são combinadas para simplificar o envio e recebimento de dados por meio de um Windows Soquete.  
  
 O artigo [Windows Sockets: exemplo de soquetes usando arquivos](../mfc/windows-sockets-example-of-sockets-using-archives.md) apresenta o **PacketSerialize** função. O objeto de arquivo morto no **PacketSerialize** exemplo funciona praticamente como um objeto de arquivo morto passado para um MFC [Serialize](../mfc/reference/cobject-class.md#serialize) função. A diferença fundamental é que, para soquetes, o arquivamento é anexado não com um padrão [CFile](../mfc/reference/cfile-class.md) objeto (geralmente associado a um arquivo de disco) mas para um `CSocketFile` objeto. Em vez de se conectar a um arquivo de disco, o `CSocketFile` objeto se conecta a um `CSocket` objeto.  
  
 Um `CArchive` objeto gerencia um buffer. Quando o buffer de um arquivo de armazenamento (envio) estiver cheio, um tipo de objeto `CFile` objeto grava o conteúdo do buffer. Liberando o buffer de um arquivo anexado a um soquete é equivalente ao enviar uma mensagem. Quando o buffer de um arquivo de carregamento (recebimento) está cheio, o `CFile` objeto para de leitura até que o buffer está disponível novamente.  
  
 Classe `CSocketFile` deriva `CFile`, mas não dá suporte a [CFile](../mfc/reference/cfile-class.md) funções de membro, como as funções de posicionamento (`Seek`, `GetLength`, `SetLength`e assim por diante), o bloqueio de funções ( `LockRange`, `UnlockRange`), ou o `GetPosition` função. Todos os [CSocketFile](../mfc/reference/csocketfile-class.md) objeto deve fazer é gravar ou ler sequências de bytes de ou para o associado `CSocket` objeto. Porque um arquivo não estiver envolvido, operações, como `Seek` e `GetPosition` não fazem sentido. `CSocketFile`é derivado de `CFile`, portanto, ele normalmente herdaria todas essas funções de membro. Para evitar isso, o suporte `CFile` funções de membro são substituídas em `CSocketFile` para lançar uma [CNotSupportedException](../mfc/reference/cnotsupportedexception-class.md).  
  
 O `CSocketFile` objeto chama membro funções de seu `CSocket` objeto para enviar ou receber dados.  
  
 A figura a seguir mostra as relações entre esses objetos em ambos os lados da comunicação.  
  
 ![CArchive, CSocketFile e CSocket](../mfc/media/vc38ia1.gif "vc38ia1")  
CArchive, CSocketFile e CSocket  
  
 A finalidade dessa complexidade aparente é protegem as empresas contra a necessidade de gerenciar os detalhes do soquete por conta própria. Você cria o soquete, o arquivo e o arquivo e, em seguida, comece enviados ou recebimento de dados, inseri-lo para o arquivo morto ou extraindo-o do arquivo morto. [CArchive](../mfc/reference/carchive-class.md), [CSocketFile](../mfc/reference/csocketfile-class.md), e [CSocket](../mfc/reference/csocket-class.md) gerenciar os detalhes nos bastidores.  
  
 Um `CSocket` é na verdade um objeto de dois estados: às vezes assíncrona (estado normal), às vezes, síncrono e. Em seu estado assíncrono, um soquete pode receber notificações assíncronas do framework. No entanto, durante uma operação como receber ou enviar dados soquete fica síncrono. Isso significa que o soquete receberão nenhuma outra notificações assíncronas até que a operação síncrona foi concluída. Porque ele alterna os modos, você pode, por exemplo, fazer algo semelhante ao seguinte:  
  
 [!code-cpp[NVC_MFCSimpleSocket#2](../mfc/codesnippet/cpp/windows-sockets-how-sockets-with-archives-work_1.cpp)]  
  
 Se `CSocket` não foram implementadas como um objeto de dois estados, ele poderá receber notificações adicionais para o mesmo tipo de evento enquanto estava processando uma notificação anterior. Por exemplo, você pode obter um `OnReceive` notificação ao processar um `OnReceive`. No fragmento de código acima, extraindo `str` do arquivo morto pode levar a recursão. Alternando estados, `CSocket` impede a recursão, impedindo que as notificações adicionais. A regra geral não é nenhuma notificação em notificações.  
  
> [!NOTE]
>  Um `CSocketFile` também pode ser usado como um arquivo (limitado) sem um `CArchive` objeto. Por padrão, o `CSocketFile` do construtor `bArchiveCompatible` parâmetro é **TRUE**. Isso especifica que o objeto de arquivo é para uso com um arquivo morto. Para usar o objeto de arquivo sem um arquivo morto, passar **FALSE** no `bArchiveCompatible` parâmetro.  
  
 No modo de "compatível com o arquivo", um `CSocketFile` objeto fornece um melhor desempenho e reduz o risco de um "bloqueio". Um deadlock ocorre quando os soquetes de envio e recebimento estão aguardando em si ou aguardando um recurso comum. Esta situação pode ocorrer se o `CArchive` objeto trabalhou com o `CSocketFile` da forma que faz com um `CFile` objeto. Com `CFile`, o arquivo morto pode assumir que se ele recebe menos bytes solicitados por ele, o final do arquivo foi atingido. Com `CSocketFile`, no entanto, dados for baseado em mensagem; o buffer pode conter várias mensagens, para receber menos do que o número de bytes solicitado não implica a fim de arquivo. O aplicativo não bloquear nesse caso, como pode ocorrer com `CFile`, e ele poderá continuar a ler mensagens do buffer até que o buffer está vazio. O [IsBufferEmpty](../mfc/reference/carchive-class.md#isbufferempty) funcionar em `CArchive` é útil para monitorar o estado do buffer do arquivo nesse caso.  
  
 Para obter mais informações, consulte [Windows Sockets: usando soquetes com arquivos mortos](../mfc/windows-sockets-using-sockets-with-archives.md)  
  
## <a name="see-also"></a>Consulte também  
 [Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)   
 [CObject::Serialize](../mfc/reference/cobject-class.md#serialize)

