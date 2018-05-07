---
title: Tarefas de programação da Internet MFC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Internet applications [MFC], getting started
- Internet applications [MFC], first steps
ms.assetid: 6377e9b8-07c4-4380-b63b-05f5a9061313
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: df7efbc8d29b2e36c6911255389cc270e7bf5e37
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="mfc-internet-programming-tasks"></a>Tarefas de programação da Internet MFC
Esta seção contém as etapas detalhadas para a adição de suporte da Internet para seus aplicativos. Tópicos incluem como usar as classes MFC para Internet habilitar seus aplicativos existentes e como adicionar suporte de documento ativo para o componente COM existente. Você deseja criar um documento com cotações de ações atualizadas, pontuações de futebol da Pittsburgh, e a temperatura mais recente no Microsoft Antártida fornece uma série de tecnologias para ajudá-lo a fazer isso pela Internet.  
  
 Tecnologias Active incluem controles ActiveX (anteriormente conhecida como controles OLE) e documentos ativos; WinInet para facilmente recuperar e salvar arquivos através da Internet; e monikers assíncronos para o download de dados eficiente. Visual C++ fornece assistentes para ajudá-lo a se familiarizar rapidamente com um aplicativo de início. Para obter uma introdução para essas tecnologias, consulte [Noções básicas de programação do MFC Internet](../mfc/mfc-internet-programming-basics.md) e [COM MFC](../mfc/mfc-com.md).  
  
 Você sempre quis FTP de um arquivo, mas ainda não adquirido WinSock e programação classes WinInet de protocolos de rede encapsular esses protocolos, oferecendo um conjunto simples de funções que você pode usar para escrever um aplicativo cliente na Internet para baixar arquivos usando HTTP, FTP e gopher. Você pode usar WinInet para procurar diretórios na unidade de disco rígido ou em todo o mundo. Modo transparente, você pode coletar dados de vários tipos diferentes e apresentá-lo para o usuário em uma interface integrada.  
  
 Você tiver grandes quantidades de dados para fazer o download assíncrono monikers fornecem uma solução de COM (Component Object Model) para a renderização progressiva de objetos grandes. WinInet também pode ser usado de forma assíncrona.  
  
 A tabela a seguir descreve algumas das coisas que você pode fazer com essas tecnologias.  
  
|Você tem|Você deseja|Você deve|  
|--------------|-----------------|----------------|  
|Um servidor Web.|Controlar logons e informações detalhadas sobre as solicitações de URL.|Grave um filtro, as notificações de solicitação para eventos de logon e o mapeamento do URL.|  
|Um navegador da Web.|Fornece conteúdo dinâmico.|Crie controles ActiveX e documentos ativos.|  
|Um aplicativo baseado no documento.|Adicione suporte para um arquivo FTP.|Use WinInet ou monikers assíncronos.|  
  
 Consulte os tópicos a seguir para obter detalhes para você começar:  
  
-   [Opções de design do aplicativo](../mfc/application-design-choices.md)  
  
-   [Escrevendo aplicativos MFC](../mfc/writing-mfc-applications.md)  
  
-   [Controles ActiveX na Internet](../mfc/activex-controls-on-the-internet.md)  
  
-   [Atualizando um controle ActiveX existente](../mfc/upgrading-an-existing-activex-control.md)  
  
-   [Documentos ativos na Internet](../mfc/active-documents-on-the-internet.md)  
  
-   [Monikers assíncronos na Internet](../mfc/asynchronous-monikers-on-the-internet.md)  
  
-   [Testando aplicativos da Internet](../mfc/testing-internet-applications.md)  
  
-   [Segurança da Internet](../mfc/internet-security-cpp.md)  
  
## <a name="see-also"></a>Consulte também  
 [Noções básicas de programação de Internet MFC](../mfc/mfc-internet-programming-basics.md)   
 [Informações da Internet por tarefa](../mfc/internet-information-by-task.md)

