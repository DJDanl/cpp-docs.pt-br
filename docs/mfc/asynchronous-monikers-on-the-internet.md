---
title: Monikers assíncronos na Internet
ms.date: 11/04/2016
helpviewer_keywords:
- ActiveX controls [MFC], asynchronous
- MFC, asynchronous monikers
- asynchronous monikers [MFC]
- Web applications [MFC], asynchronous
- downloading Internet resources and asynchronous monikers
- optimization [MFC], asynchronous downloading across Internet
- Internet [MFC], asynchronous downloading
ms.assetid: 418b0c64-0046-4dae-8118-c9c762b5822e
ms.openlocfilehash: 74add1ad894f883c67eefab888898c0abf518b83
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84625030"
---
# <a name="asynchronous-monikers-on-the-internet"></a>Monikers assíncronos na Internet

A Internet requer novas abordagens para o design de aplicativos devido a seu acesso lento à rede. Os aplicativos devem executar o acesso à rede de forma assíncrona para evitar a paralisação da interface do usuário. A classe MFC [CAsyncMonikerFile](reference/casyncmonikerfile-class.md) fornece suporte assíncrono para baixar arquivos.

Com monikers assíncronos, você pode estender seu aplicativo COM para baixar de forma assíncrona pela Internet e fornecer renderização progressiva de objetos grandes, como bitmaps e objetos VRML. Os monikers assíncronos permitem que uma propriedade de controle ActiveX ou um arquivo na Internet seja baixado sem bloquear a resposta da interface do usuário.

## <a name="advantages-of-asynchronous-monikers"></a>Vantagens dos monikers assíncronos

Você pode usar monikers assíncronos para:

- Baixar código e arquivos sem bloqueio.

- Baixar Propriedades em controles ActiveX sem bloqueio.

- Receba notificações de download do progresso.

- Acompanhe as informações de progresso e estado pronto.

- Forneça informações de status para o usuário sobre o progresso.

- Permitir que o usuário cancele um download a qualquer momento.

## <a name="mfc-classes-for-asynchronous-monikers"></a>Classes MFC para monikers assíncronos

[CAsyncMonikerFile](reference/casyncmonikerfile-class.md) é derivado de [CMonikerFile](reference/cmonikerfile-class.md), que, por sua vez, é derivado de [COleStreamFile](reference/colestreamfile-class.md). Um `COleStreamFile` objeto representa um fluxo de dados; um `CMonikerFile` objeto usa um `IMoniker` para obter os dados e um `CAsyncMonikerFile` objeto faz isso de forma assíncrona.

Os monikers assíncronos são usados principalmente em aplicativos habilitados para Internet e controles ActiveX para fornecer uma interface de usuário responsiva durante transferências de arquivos. Um exemplo primo disso é o uso de [CDataPathProperty](reference/cdatapathproperty-class.md) para fornecer propriedades assíncronas para controles ActiveX.

## <a name="mfc-classes-for-data-paths-in-activex-controls"></a>Classes MFC para caminhos de dados em controles ActiveX

As classes do MFC `CDataPathProperty` e [CCachedDataPathProperty](reference/ccacheddatapathproperty-class.md) implementam Propriedades do controle ActiveX que podem ser carregadas de forma assíncrona. As propriedades assíncronas são carregadas após a inicialização síncrona. Os controles ActiveX assíncronos invocam repetidamente um retorno de chamada para indicar a disponibilidade de novos dados durante um processo de troca de propriedade demorada.

`CDataPathProperty`é derivado de `CAsyncMonikerFile` . `CCachedDataPathProperty`é derivado de `CDataPathProperty` . Para implementar propriedades assíncronas nos controles ActiveX, derive uma classe de `CDataPathProperty` ou e `CCachedDataPathProperty` substitua [OnDataAvailable](reference/casyncmonikerfile-class.md#ondataavailable) e outras notificações que você deseja receber.

#### <a name="to-download-a-file-using-asynchronous-monikers"></a>Para baixar um arquivo usando monikers assíncronos

1. Declare uma classe derivada de [CAsyncMonikerFile](reference/casyncmonikerfile-class.md).

1. Substitua [OnDataAvailable](reference/casyncmonikerfile-class.md#ondataavailable) para exibir os dados.

1. Substitua outras funções de membro, incluindo [OnProgress](reference/casyncmonikerfile-class.md#onprogress), [OnStart](reference/casyncmonikerfile-class.md#onstartbinding)e [OnStopBinding](reference/casyncmonikerfile-class.md#onstopbinding).

1. Declare uma instância dessa classe e use-a para abrir URLs.

Para obter informações sobre como baixar de forma assíncrona em um controle ActiveX, consulte [controles ActiveX na Internet](activex-controls-on-the-internet.md).

## <a name="see-also"></a>Consulte também

[Tarefas de programação da Internet no MFC](mfc-internet-programming-tasks.md)<br/>
[Noções básicas de programação na Internet do MFC](mfc-internet-programming-basics.md)
