---
title: "Monikers ass&#237;ncronos na Internet | Microsoft Docs"
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
  - "Controles ActiveX [C++], assíncronos"
  - "monikers assíncronos [C++]"
  - "baixando recursos de Internet e monikers assíncronos"
  - "Internet [C++], download assíncrono"
  - "MFC [C++], monikers assíncronos"
  - "otimização [C++], download assíncrono pela Internet"
  - "aplicativos da Web [C++], assíncronos"
ms.assetid: 418b0c64-0046-4dae-8118-c9c762b5822e
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Monikers ass&#237;ncronos na Internet
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Internet requer novas abordagens para a criação do aplicativo devido ao seu acesso à rede lenta.  Os aplicativos devem executar o acesso à rede de forma assíncrona para evitar parar a interface do usuário.  A classe [CAsyncMonikerFile](../mfc/reference/casyncmonikerfile-class.md) MFC fornece suporte assíncrona para baixar arquivos.  
  
 Com apelidos assíncronas, você pode estender o aplicativo de COM baixar de forma assíncrona por meio da Internet e fornecer a renderização progressiva de objetos grandes como bitmaps e objetos de VRML.  Apelidos assíncrona habilita uma propriedade do controle ActiveX ou arquivo da web a ser baixado sem bloquear a resposta da interface do usuário.  
  
## Vantagens de apelidos assíncronas  
 Você pode usar apelidos assíncronas:  
  
-   Código e arquivos de download sem bloqueio.  
  
-   Propriedades de download em controles ActiveX sem bloqueio.  
  
-   Receber notificações de andamento de transferência.  
  
-   Controlar o progresso e informações de estado pronto.  
  
-   Fornece informações de status ao usuário sobre o progresso.  
  
-   Permite que o usuário cancele um download a qualquer momento.  
  
## Classes de MFC de apelidos assíncronas  
 [CAsyncMonikerFile](../mfc/reference/casyncmonikerfile-class.md) é derivado de [CMonikerFile](../Topic/CMonikerFile%20Class.md), que é derivado por sua vez de [COleStreamFile](../Topic/COleStreamFile%20Class.md).  Um objeto de `COleStreamFile` representa um fluxo de dados; um objeto de `CMonikerFile` usa `IMoniker` para obter os dados, e um objeto de `CAsyncMonikerFile` faz o de forma assíncrona.  
  
 Apelidos assíncronas são usadas principalmente em aplicativos e de controles ActiveX habilitados para internet fornecer uma interface do usuário respondendo durante as transferências de arquivo.  Um excelente exemplo disso é o uso de [CDataPathProperty](../mfc/reference/cdatapathproperty-class.md) fornecer propriedades assíncronas para controles ActiveX.  
  
## Classes de MFC para caminhos de dados em controles ActiveX  
 As classes `CDataPathProperty` e [CCachedDataPathProperty](../mfc/reference/ccacheddatapathproperty-class.md) MFC implementam as propriedades do controle ActiveX que podem ser carregadas de forma assíncrona.  As propriedades assíncronas são carregadas depois da iniciação síncrona.  Os controles ActiveX assíncronas ele chama repetidamente um retorno de chamada para indicar a disponibilidade de dados novos durante um processo longo de troca da propriedade.  
  
 `CDataPathProperty` é derivado de `CAsyncMonikerFile`.  `CCachedDataPathProperty` é derivado de `CDataPathProperty`.  Para implementar propriedades assíncrona em seus controles ActiveX, deve derivar uma classe de `CDataPathProperty` ou de `CCachedDataPathProperty`, e substitua [OnDataAvailable](../Topic/CAsyncMonikerFile::OnDataAvailable.md) e outras notificações que você deseja receber.  
  
#### Para baixar um arquivo usando apelidos assíncronas  
  
1.  Declare uma classe derivada de [CAsyncMonikerFile](../mfc/reference/casyncmonikerfile-class.md).  
  
2.  Substituição [OnDataAvailable](../Topic/CAsyncMonikerFile::OnDataAvailable.md) para exibir os dados.  
  
3.  Substituir outras funções de membro, incluindo [OnProgress](../Topic/CAsyncMonikerFile::OnProgress.md), [OnStartBinding](../Topic/CAsyncMonikerFile::OnStartBinding.md), e [OnStopBinding](../Topic/CAsyncMonikerFile::OnStopBinding.md).  
  
4.  Declare uma instância dessa classe e use para abrir a URL.  
  
 Para obter informações sobre como baixar de forma assíncrona em um controle ActiveX, consulte [Controles ActiveX na Internet](../mfc/activex-controls-on-the-internet.md).  
  
## Consulte também  
 [Tarefas de programação da Internet MFC](../mfc/mfc-internet-programming-tasks.md)   
 [Noções básicas de programação da Internet MFC](../mfc/mfc-internet-programming-basics.md)