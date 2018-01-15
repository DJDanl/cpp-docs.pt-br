---
title: 'Windows Sockets: Usando soquetes com arquivos mortos | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- Windows Sockets [MFC], archives
- sockets [MFC], with archives
- archives [MFC], and Windows Sockets
- CSocket class [MFC], programming model
ms.assetid: 17e71a99-a09e-4e1a-9fda-13d62805c824
caps.latest.revision: "12"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: c9956e48f88988dfec7e04cda5bba95e514ec109
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="windows-sockets-using-sockets-with-archives"></a>Windows Sockets: usando soquetes com arquivos mortos
Este artigo descreve o [modelo de programação CSocket](#_core_the_csocket_programming_model). Classe [CSocket](../mfc/reference/csocket-class.md) fornece suporte de soquete em um nível mais alto de abstração de classe [CAsyncSocket](../mfc/reference/casyncsocket-class.md). `CSocket`usa uma versão do protocolo de serialização do MFC para transmitir e receber dados de um objeto de soquete por meio de um MFC [CArchive](../mfc/reference/carchive-class.md) objeto. `CSocket`fornece o bloqueio (ao gerenciar o processamento em segundo plano das mensagens do Windows) e fornece acesso a `CArchive`, que gerencia vários aspectos da comunicação que você precisa fazer por conta própria usando o bruto API ou classe `CAsyncSocket`.  
  
> [!TIP]
>  Você pode usar a classe `CSocket` por si só, como uma versão mais conveniente de `CAsyncSocket`, mas o modelo de programação mais simples é usar `CSocket` com um `CArchive` objeto.  
  
 Para obter mais informações sobre como funciona a implementação de soquetes com arquivos, consulte [Windows Sockets: como soquetes com arquivos de trabalho](../mfc/windows-sockets-how-sockets-with-archives-work.md). Por exemplo de código, consulte [Windows Sockets: sequência de operações](../mfc/windows-sockets-sequence-of-operations.md) e [Windows Sockets: exemplo de soquetes usando arquivos](../mfc/windows-sockets-example-of-sockets-using-archives.md). Para obter informações sobre algumas das funcionalidades que você pode obter derivando suas próprias classes as classes de soquetes, consulte [Windows Sockets: derivando de Classes de soquete](../mfc/windows-sockets-deriving-from-socket-classes.md).  
  
> [!NOTE]
>  Se você estiver escrevendo um programa de cliente do MFC para se comunicar com servidores estabelecida não-MFC (), não envie objetos C++ por meio do arquivo morto. A menos que o servidor for um aplicativo MFC que compreende os tipos de objetos que você deseja enviar, não será capaz de receber e desserializar objetos. Para obter material relacionada sobre o assunto de se comunicar com aplicativos não MFC, também, consulte o artigo [Windows Sockets: ordenação de bytes](../mfc/windows-sockets-byte-ordering.md).  
  
##  <a name="_core_the_csocket_programming_model"></a>O modelo de programação CSocket  
 Usando um `CSocket` objeto envolve criar e associar juntos vários objetos de classe do MFC. O procedimento geral a seguir, cada etapa é realizada pelo soquete de servidor e cliente soquete, exceto para a etapa 3, em que cada tipo de soquete requer uma ação diferente.  
  
> [!TIP]
>  Em tempo de execução, o aplicativo de servidor normalmente inicia pela primeira vez pronto e "escuta" quando o aplicativo cliente procura uma conexão. Se o servidor não está pronto quando o cliente tenta se conectar, você normalmente requer o aplicativo de usuário para se conectar novamente mais tarde.  
  
#### <a name="to-set-up-communication-between-a-server-socket-and-a-client-socket"></a>Para configurar a comunicação entre um soquete de servidor e um soquete do cliente  
  
1.  Construir um [CSocket](../mfc/reference/csocket-class.md) objeto.  
  
2.  Usar o objeto para criar subjacente **soquete** tratar.  
  
     Para uma `CSocket` objeto de cliente, você normalmente deve usar os parâmetros padrão para [criar](../mfc/reference/casyncsocket-class.md#create), a menos que você precisa de um soquete de datagrama. Para uma `CSocket` o objeto de servidor, você deve especificar uma porta no **criar** chamar.  
  
    > [!NOTE]
    >  `CArchive`não funciona com soquetes de datagrama. Se você quiser usar `CSocket` para um soquete de datagrama, você deve usar a classe que você usaria `CAsyncSocket`, ou seja, sem um arquivo morto. Porque datagramas são confiáveis (não garantidas de chegar e podem ser repetidas ou fora de sequência), eles não são compatíveis com a serialização por meio de um arquivo morto. Você espera que uma operação de serialização para concluir confiável e em sequência. Se você tentar usar `CSocket` com um `CArchive` de objeto para um datagrama, uma declaração de MFC falha.  
  
3.  Se o soquete é um cliente, chamar [CAsyncSocket::Connect](../mfc/reference/casyncsocket-class.md#connect) para conectar-se o objeto de soquete para um soquete do servidor.  
  
     -ou-  
  
     Se o soquete é um servidor, chame [CAsyncSocket::Listen](../mfc/reference/casyncsocket-class.md#listen) para iniciar a escuta de tentativas de conexão de um cliente. Ao receber uma solicitação de conexão, aceite-chamando [CAsyncSocket::Accept](../mfc/reference/casyncsocket-class.md#accept).  
  
    > [!NOTE]
    >  O **aceitar** função de membro usa uma referência a um novo e vazio `CSocket` objeto como seu parâmetro. Você deve construir esse objeto antes de chamar **aceitar**. Se esse objeto de soquete sai do escopo, a conexão será fechada. Não chame **criar** para esse novo objeto de soquete.  
  
4.  Criar um [CSocketFile](../mfc/reference/csocketfile-class.md) do objeto, associando o `CSocket` objeto com ele.  
  
5.  Criar um [CArchive](../mfc/reference/carchive-class.md) objeto para carregamento (recebimento) ou no armazenamento de dados (envio). O arquivo está associado a `CSocketFile` objeto.  
  
     Tenha em mente que `CArchive` não funciona com soquetes de datagrama.  
  
6.  Use o `CArchive` objeto para passar dados entre soquetes de cliente e servidor.  
  
     Lembre-se de que um determinado `CArchive` objeto move dados em apenas uma direção: para carregamento (recebimento) ou o armazenamento (envio). Em alguns casos, você usará dois `CArchive` objetos: uma para envio de dados, o outro para receber confirmações.  
  
     Depois de aceitar uma conexão e o arquivo de configuração, você pode executar tarefas como: validando senhas.  
  
7.  Destrua o arquivamento, o arquivo de soquete e objetos de soquete.  
  
    > [!NOTE]
    >  Classe `CArchive` fornece o `IsBufferEmpty` a função de membro especificamente para uso com a classe `CSocket`. Por exemplo, se o buffer contém várias mensagens de dados, você precisa executar um loop até que todos eles são lidos e o buffer será limpo. Caso contrário, sua próxima notificação de que há dados a ser recebido pode ser atrasada indefinidamente. Use `IsBufferEmpty` para garantir que você recuperar todos os dados.  
  
 O artigo [Windows Sockets: sequência de operações](../mfc/windows-sockets-sequence-of-operations.md) ilustra ambos os lados desse processo com o código de exemplo.  
  
 Para obter mais informações, consulte:  
  
-   [Windows Sockets: soquetes de fluxo](../mfc/windows-sockets-stream-sockets.md)  
  
-   [Windows Sockets: soquetes de datagrama](../mfc/windows-sockets-datagram-sockets.md)  
  
## <a name="see-also"></a>Consulte também  
 [Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)   
 [CSocket::Create](../mfc/reference/csocket-class.md#create)

