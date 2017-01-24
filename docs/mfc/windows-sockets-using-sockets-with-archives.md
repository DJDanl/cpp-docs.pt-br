---
title: "Windows Sockets: usando soquetes com arquivos mortos | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "arquivamentos [C++], e Windows Sockets"
  - "Classe CSocket, modelo de programação"
  - "soquetes [C++], com arquivamentos"
  - "Windows Sockets [C++], arquivamentos"
ms.assetid: 17e71a99-a09e-4e1a-9fda-13d62805c824
caps.latest.revision: 12
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Windows Sockets: usando soquetes com arquivos mortos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo descreve [Modelo de programação de CSocket](#_core_the_csocket_programming_model).  A classe [CSocket](../mfc/reference/csocket-class.md) fornece suporte de soquete em um nível mais alto de abstração de que classifica [CAsyncSocket](../Topic/CAsyncSocket%20Class.md).  `CSocket` usa uma versão do protocolo de serialização MFC para transmitir dados de e para um objeto de soquete por meio de um objeto MFC [CArchive](../mfc/reference/carchive-class.md) .  `CSocket` fornece o bloqueio \(para gerenciar o processamento em segundo plano de mensagens do windows\) e fornece acesso a `CArchive`, que gerencia muitos aspectos da comunicação que você teria que se tornar usando a API bruto ou classificar `CAsyncSocket`.  
  
> [!TIP]
>  Você pode usar a classe `CSocket` por si só, como uma versão mais conveniente de `CAsyncSocket`, mas o modelo mais simples de programação é usar `CSocket` com um objeto de `CArchive` .  
  
 Para obter mais informações sobre como a implementação de soquetes com arquivos mortos funciona, consulte [Windows Sockets: como funcionam soquetes com arquivos mortos](../mfc/windows-sockets-how-sockets-with-archives-work.md).  Por exemplo, o código [Windows Sockets: sequência de operações](../Topic/Windows%20Sockets:%20Sequence%20of%20Operations.md) consulte e [Windows Sockets: exemplo de soquetes que usam arquivos mortos](../mfc/windows-sockets-example-of-sockets-using-archives.md).  Para obter informações sobre algumas das funcionalidades que você pode obter com suas próprias classes das classes de soquetes, consulte [Windows Sockets: derivando de classes de soquete](../mfc/windows-sockets-deriving-from-socket-classes.md).  
  
> [!NOTE]
>  Se você estiver escrevendo um programa cliente MFC para se comunicar com os servidores \(não\) MFC estabelecidas, não enviar objetos C\+\+ por meio do arquivo morto.  A menos que o servidor é um aplicativo de MFC que compreende os tipos de objetos você deseja enviar, não poderá receber e desserializar seus objetos.  Para material relacionado ao propósito da comunicação com os aplicativos não MFC também, consulte o artigo [Windows Sockets: ordenação de bytes](../mfc/windows-sockets-byte-ordering.md).  
  
##  <a name="_core_the_csocket_programming_model"></a> O modelo de programação de CSocket  
 Usar um objeto de `CSocket` envolve a criação e associar vários objetos juntos MFC da classe.  No procedimento em geral, cada etapa é executada por soquete de servidor e por soquete de cliente, com exceção da etapa 3, em que cada tipo de soquete requer uma ação diferente.  
  
> [!TIP]
>  Em tempo de execução, o aplicativo para servidores normalmente inicia primeiro e pronto para ser “escutando” quando o aplicativo cliente pesquisa uma conexão.  Se o servidor não está pronto quando o cliente tentar se conectar, você normalmente requer o aplicativo de usuário tentar se conectar novamente mais tarde.  
  
#### Para configurar a comunicação entre um soquete de servidor e um soquete de cliente  
  
1.  Construir um objeto de [CSocket](../mfc/reference/csocket-class.md) .  
  
2.  Use o objeto para criar o identificador de **SOCKET** subjacente.  
  
     Para um objeto de cliente de `CSocket` , você normalmente deve usar os parâmetros padrão a [Crie](../Topic/CAsyncSocket::Create.md), a menos que você precise de um soquete de datagrama.  Para um objeto de servidor de `CSocket` , você deve especificar uma porta na chamada de **Criar** .  
  
    > [!NOTE]
    >  `CArchive` não funciona com soquetes de datagrama.  Se você quiser usar `CSocket` para um soquete de datagrama, você deve usar a classe porque você usaria `CAsyncSocket`, isto é, sem um arquivo morto.  Como as datagramas são não confiável \(não garantido para chegar e pode ser repetidas ou fora de sequência\), não são compatíveis com a serialização meio de um arquivo morto.  Você espera que uma operação de serialização concluir o e na ordem.  Se você tentar usar `CSocket` com um objeto de `CArchive` para uma datagrama, uma asserção de MFC falha.  
  
3.  Se o soquete é um cliente, chame [CAsyncSocket::Connect](../Topic/CAsyncSocket::Connect.md) para conectar o objeto de soquete a um soquete do servidor.  
  
     \- ou \-  
  
     Se o soquete é um servidor, chame [CAsyncSocket::Listen](../Topic/CAsyncSocket::Listen.md) para iniciar a escuta se conecta tentativas de um cliente.  Após o recebimento de uma solicitação de conexão, aceitar\-la chamando [CAsyncSocket::Accept](../Topic/CAsyncSocket::Accept.md).  
  
    > [!NOTE]
    >  A função de membro de **Aceitar** usa uma referência a um novo objeto vazio, de `CSocket` como o parâmetro.  Você deve construir esse objeto antes de chamar **Aceitar**.  Se esse objeto de soquete sair do escopo, a conexão é fechada.  Não chame **Criar** para esse novo objeto de soquete.  
  
4.  Crie um objeto de [CSocketFile](../Topic/CSocketFile%20Class.md) , associando o objeto de `CSocket` a ele.  
  
5.  Crie um objeto de [CArchive](../mfc/reference/carchive-class.md) para a carga \(pull\) ou armazenar dados \(enviar\).  O arquivo morto está associado ao objeto de `CSocketFile` .  
  
     Lembre\-se de que `CArchive` não funciona com soquetes de datagrama.  
  
6.  Use o objeto de `CArchive` para passar dados entre o cliente e soquetes do servidor.  
  
     Lembre\-se de que um determinado objeto de `CArchive` move dados em uma direção apenas: para carregar \(pull\) ou armazenar enviar \(\).  Em alguns casos, você usará dois objetos de `CArchive` : um para enviar dados, outro para receber confirmações.  
  
     Após aceito uma conexão e configurado o arquivo, você pode executar tarefas como validando senhas.  
  
7.  Destruir o arquivo, o arquivo de soquete, e os objetos de soquete.  
  
    > [!NOTE]
    >  Classifica fontes de `CArchive` a função de membro de `IsBufferEmpty` especificamente para uso com `CSocket`classe.  Se o buffer contém várias mensagens de dados, por exemplo, você precisa executar um loop até que todo sejam lidos e o buffer estiver desmarcada.  Se não, sua próxima notificação que há dados a serem recebidos indefinidamente pode ser adiada.  Use `IsBufferEmpty` para assegurar que você recupera todos os dados.  
  
 O artigo [Windows Sockets: sequência de operações](../Topic/Windows%20Sockets:%20Sequence%20of%20Operations.md) ilustra os dois lados desse processo com o código de exemplo.  
  
 Para obter mais informações, consulte:  
  
-   [Windows Sockets: soquetes de fluxo](../mfc/windows-sockets-stream-sockets.md)  
  
-   [Windows Sockets: soquetes de datagrama](../mfc/windows-sockets-datagram-sockets.md)  
  
## Consulte também  
 [Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)   
 [CSocket::Create](../Topic/CSocket::Create.md)