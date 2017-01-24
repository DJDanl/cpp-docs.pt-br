---
title: "Windows Sockets: como funcionam soquetes com arquivos mortos | Microsoft Docs"
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
  - "soquetes [C++], operação síncrona"
  - "soquetes [C++], com arquivamentos"
  - "soquete de estado síncrono"
  - "objeto de soquete de dois estados"
  - "Windows Sockets [C++], síncrona"
  - "Windows Sockets [C++], com arquivamentos"
ms.assetid: d8ae4039-391d-44f0-a19b-558817affcbb
caps.latest.revision: 12
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Windows Sockets: como funcionam soquetes com arquivos mortos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo explica como um objeto de [CSocket](../mfc/reference/csocket-class.md) , um objeto de [CSocketFile](../Topic/CSocketFile%20Class.md) , e um objeto de [CArchive](../mfc/reference/carchive-class.md) são combinados para simplificar enviar e receber dados por meio de um soquete do windows.  
  
 O artigo [Soquetes do windows: Exemplo de soquetes usando arquivos mortos](../mfc/windows-sockets-example-of-sockets-using-archives.md) apresenta a função de **PacketSerialize** .  O objeto de arquivo morto do trabalho de exemplo de **PacketSerialize** bem como um objeto de arquivo morto passado a uma função de MFC [Serializar](../Topic/CObject::Serialize.md) .  A diferença é que essencial para soquetes, o arquivo morto não estiver anexada a um objeto padrão de [CFile](../mfc/reference/cfile-class.md) \(associado normalmente com um arquivo de disco\) mas a um objeto de `CSocketFile` .  Em vez de se conectando a um arquivo de disco, o objeto de `CSocketFile` se conecta a `CSocket` um objeto.  
  
 Um objeto de `CArchive` gerencia um buffer.  Quando o buffer de um arquivo morto enviando \(\) para armazenar for concluída, um objeto associado para fora de `CFile` grava o conteúdo do buffer.  Liberar o buffer de um arquivo morto anexado a um soquete é equivalente a enviar uma mensagem.  Quando o buffer de um arquivo morto de carregamento \(pull\) é concluído, o objeto de `CFile` de para ler até que o buffer está disponível novamente.  
  
 A classe `CSocketFile` é derivado de `CFile`, mas não da suporte a funções de membro de [CFile](../mfc/reference/cfile-class.md) como as funções de posicionamento \(`Seek`, `GetLength`, `SetLength`, e assim por diante\), o bloqueio funções \(`LockRange`, `UnlockRange`\), ou a função de `GetPosition` .  Qualquer objeto de [CSocketFile](../Topic/CSocketFile%20Class.md) deve fazer é gravar ou para ler sequências de bytes ou de `CSocket` associado ao objeto.  Como um arquivo não estiver envolvido, as operações como `Seek` e nenhum `GetPosition` não fazem sentido.  `CSocketFile` é derivado de `CFile`, portanto herdaria normalmente todas essas funções de membro.  Para evitar isso, as funções de membro sem suporte de `CFile` são preteridos em `CSocketFile` para gerar [CNotSupportedException](../mfc/reference/cnotsupportedexception-class.md).  
  
 As funções de membro das chamadas de objeto de `CSocketFile` do `CSocket` objeto para enviar ou receber dados.  
  
 A figura a seguir mostra as relações entre esses objetos nos dois lados de comunicação.  
  
 ![CArchive CSocketFile CSocket](../Image/vc38IA1.gif "vc38IA1")  
CArchive, CSocketFile, e CSocket  
  
 O objetivo dessa complexidade aparente é impedi\-lo de ser necessidade de gerenciar os detalhes de soquete você mesmo.  Você cria o soquete, o arquivo, e o arquivo, e comece a enviar ou receber dados inserindo o ao arquivo morto ou extraindo o do arquivo morto.  [CArchive](../mfc/reference/carchive-class.md), [CSocketFile](../Topic/CSocketFile%20Class.md), e [CSocket](../mfc/reference/csocket-class.md) gerenciam os detalhes nos bastidores.  
  
 Um objeto de `CSocket` é realmente um objeto de dois estados: às vezes assíncrona \(o estado normal\) e às vezes síncrona.  Em seu estado assíncrona, um soquete pode receber notificações assíncronas da estrutura.  No entanto, durante uma operação como a recepção ou enviar dados do soquete se torna síncrona.  Isso significa que o soquete uma assíncronos não receberá notificações adicionais até que a operação síncrona seja concluída.  Como alterar os modos, você pode, por exemplo, fazer algo como:  
  
 [!CODE [NVC_MFCSimpleSocket#2](../CodeSnippet/VS_Snippets_Cpp/NVC_MFCSimpleSocket#2)]  
  
 Se `CSocket` não foi implementado como um objeto de dois estado, ele pode ser possível para receber notificações adicionais para o mesmo tipo do evento quando você processava uma notificação anterior.  Por exemplo, talvez você obtenha uma notificação de `OnReceive` ao processar `OnReceive`.  No fragmento de código acima, extrair `str` de arquivo morto pode levar a recursão.  Alternando estados, `CSocket` impede a recursão evitando notificações adicionais.  A regra geral é nenhuma notificação em notificações.  
  
> [!NOTE]
>  `CSocketFile` também pode ser usado como um arquivo \(limitado sem\) de um objeto de `CArchive` .  Por padrão, o parâmetro de `bArchiveCompatible` construtor de `CSocketFile` é **Verdadeiro**.  Isso especifica que o objeto de arquivo é para uso com um arquivo morto.  Para usar o objeto de arquivo sem um arquivo, passe **Falso** no parâmetro de `bArchiveCompatible` .  
  
 No “modo compatível arquivo morto”, um objeto de `CSocketFile` fornece o melhor desempenho e reduz o perigo de um deadlock “.” Um deadlock acontece quando os soquetes enviando e recebendo estão aguardando se, ou esperando por um recurso comuns.  Essa situação poderia ocorrer se o objeto de `CArchive` trabalhado com `CSocketFile` a maneira como faria com um objeto de `CFile` .  Com `CFile`, o arquivo morto pode assumir que se receber o menos bytes de solicitada, a fim de arquivo for atingido.  Com `CSocketFile`, porém, os dados são baseado em mensagem; o buffer pode conter várias mensagens, portanto pull de menor que o número de bytes necessários não implica a fim de arquivo.  O aplicativo não bloqueia nesse caso como ela com `CFile`, e pode continuar lê mensagens do buffer até que o buffer está vazia.  A função de [IsBufferEmpty](../Topic/CArchive::IsBufferEmpty.md) em `CArchive` é útil para monitorar o estado do buffer de arquivo morto nesse caso.  
  
 Para obter mais informações, consulte [Soquetes do windows: Usando soquetes com arquivos mortos](../mfc/windows-sockets-using-sockets-with-archives.md)  
  
## Consulte também  
 [Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)   
 [CObject::Serialize](../Topic/CObject::Serialize.md)