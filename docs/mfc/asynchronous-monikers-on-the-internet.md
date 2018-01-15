---
title: "Monikers assíncronos na Internet | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- ActiveX controls [MFC], asynchronous
- MFC, asynchronous monikers
- asynchronous monikers [MFC]
- Web applications [MFC], asynchronous
- downloading Internet resources and asynchronous monikers
- optimization [MFC], asynchronous downloading across Internet
- Internet [MFC], asynchronous downloading
ms.assetid: 418b0c64-0046-4dae-8118-c9c762b5822e
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: cd7b6be66c3049c1d82aa549cf362a840fd6f265
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="asynchronous-monikers-on-the-internet"></a>Monikers assíncronos na Internet
Internet requer novas abordagens de design do aplicativo devido a seu acesso de rede lenta. Aplicativos devem executar o acesso de rede de forma assíncrona para evitar atrasando a interface do usuário. A classe do MFC [CAsyncMonikerFile](../mfc/reference/casyncmonikerfile-class.md) fornece suporte assíncrono para download de arquivos.  
  
 Com monikers assíncronos, você pode estender o aplicativo COM para baixar de forma assíncrona através da Internet e para fornecer processamento progressivo de objetos grandes, como bitmaps e objetos VRML. Monikers assíncronos habilitar uma propriedade de controle ActiveX ou um arquivo na Internet para ser baixado sem bloquear a resposta da interface do usuário.  
  
## <a name="advantages-of-asynchronous-monikers"></a>Vantagens de Monikers assíncronos  
 Você pode usar monikers assíncronos para:  
  
-   Baixe o código e os arquivos sem bloqueio.  
  
-   Baixe propriedades em controles ActiveX sem bloqueio.  
  
-   Receba notificações de andamento de download.  
  
-   Acompanhar o progresso e informações de estado pronto.  
  
-   Fornece informações de status para o usuário sobre o progresso.  
  
-   Permitir que o usuário cancelar um download a qualquer momento.  
  
## <a name="mfc-classes-for-asynchronous-monikers"></a>Classes MFC de Monikers assíncronos  
 [CAsyncMonikerFile](../mfc/reference/casyncmonikerfile-class.md) é derivado de [CMonikerFile](../mfc/reference/cmonikerfile-class.md), que por sua vez é derivada de [COleStreamFile](../mfc/reference/colestreamfile-class.md). Um `COleStreamFile` objeto representa um fluxo de dados; um `CMonikerFile` objeto usa um `IMoniker` para obter os dados e um `CAsyncMonikerFile` objeto faz isso de forma assíncrona.  
  
 Monikers assíncronos são usados principalmente em aplicativos habilitados para Internet e controles ActiveX para fornecer uma interface do usuário responsiva durante transferências de arquivos. Um exemplo perfeito é o uso de [CDataPathProperty](../mfc/reference/cdatapathproperty-class.md) para fornecer propriedades assíncronas para controles ActiveX.  
  
## <a name="mfc-classes-for-data-paths-in-activex-controls"></a>Classes MFC para caminhos de dados em controles ActiveX  
 As classes MFC `CDataPathProperty` e [CCachedDataPathProperty](../mfc/reference/ccacheddatapathproperty-class.md) implementar propriedades de controle ActiveX que podem ser carregadas de forma assíncrona. Propriedades assíncronas são carregadas após a inicialização síncrona. Controles ActiveX assíncronos repetidamente invocar um retorno de chamada para indicar a disponibilidade de novos dados durante o processo de exchange propriedade longo.  
  
 `CDataPathProperty`é derivado de `CAsyncMonikerFile`. `CCachedDataPathProperty`é derivado de `CDataPathProperty`. Para implementar propriedades assíncronas em seus controles ActiveX, derive uma classe de `CDataPathProperty` ou `CCachedDataPathProperty`e substituir [OnDataAvailable](../mfc/reference/casyncmonikerfile-class.md#ondataavailable) e outras notificações que você deseja receber.  
  
#### <a name="to-download-a-file-using-asynchronous-monikers"></a>Para baixar um arquivo usando monikers assíncronos  
  
1.  Declarar uma classe derivada de [CAsyncMonikerFile](../mfc/reference/casyncmonikerfile-class.md).  
  
2.  Substituir [OnDataAvailable](../mfc/reference/casyncmonikerfile-class.md#ondataavailable) para exibir os dados.  
  
3.  Substituir outras funções de membro, incluindo [OnProgress](../mfc/reference/casyncmonikerfile-class.md#onprogress), [OnStartBinding](../mfc/reference/casyncmonikerfile-class.md#onstartbinding), e [OnStopBinding](../mfc/reference/casyncmonikerfile-class.md#onstopbinding).  
  
4.  Declarar uma instância dessa classe e usá-lo para abrir URLs.  
  
 Para obter informações sobre como baixar de forma assíncrona em um controle ActiveX, consulte [controles ActiveX na Internet](../mfc/activex-controls-on-the-internet.md).  
  
## <a name="see-also"></a>Consulte também  
 [Tarefas de programação da Internet MFC](../mfc/mfc-internet-programming-tasks.md)   
 [Noções básicas de programação da Internet no MFC](../mfc/mfc-internet-programming-basics.md)

