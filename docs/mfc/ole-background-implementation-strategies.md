---
title: "Plano de fundo OLE: Estratégias de implementação | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- OLE [MFC], development strategy
- OLE applications [MFC], implementing OLE
- applications [OLE], implementing OLE
ms.assetid: 0875ddae-99df-488c-82c6-164074a81058
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 7325cb5cb7be4750507d8694ba8bc5efc3ce8606
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ole-background-implementation-strategies"></a>Tela de fundo OLE: estratégias de implementação
Dependendo do seu aplicativo, há quatro estratégias de implementação possíveis para adicionar suporte OLE:  
  
-   Você está criando um novo aplicativo.  
  
     Essa situação normalmente requer menos de trabalho. Execute o Assistente de aplicativo MFC e selecione os recursos avançados ou suporte a documentos compostos para criar um aplicativo de esqueleto. Para obter informações sobre essas opções e o que fazer, consulte o artigo [criando um programa de EXE do MFC](../mfc/reference/mfc-application-wizard.md).  
  
-   Você tem um programa gravado com a biblioteca Microsoft Foundation Class versão 2.0 ou superior que não dá suporte a OLE.  
  
     Criar um novo aplicativo com o Assistente de aplicativo MFC como mencionado anteriormente e, em seguida, copie e cole o código do aplicativo de novo no seu aplicativo existente. Isso funciona para servidores, contêineres ou automatizados de aplicativos. Consulte o MFC [RABISCO](../visual-cpp-samples.md) exemplo para obter um exemplo dessa estratégia.  
  
-   Você tem um programa de biblioteca Microsoft Foundation Class que implementa o suporte a OLE versão 1.0.  
  
     Consulte [MFC técnica Observação 41](../mfc/tn041-mfc-ole1-migration-to-mfc-ole-2.md) para essa estratégia de conversão.  
  
-   Você tem um aplicativo que não foram gravada usando o Microsoft Foundation Classes e que podem ou não pode ter implementado suporte OLE.  
  
     Essa situação requer mais trabalho. Uma abordagem é criar um novo aplicativo, como a primeira estratégia e, em seguida, copie e cole o código existente ele. Se seu código existente é escrito em C, você precisará modificá-lo para que ele pode compilar como código C++. Se seu código C chama a API do Windows, não é necessário alterá-la para usar as Microsoft Foundation classes. Essa abordagem provavelmente exigirá alguns reestruturação de seu programa para dar suporte a arquitetura de documento/exibição usada por versões 2.0 e mais recente do que a Microsoft Foundation Classes. Para obter mais informações sobre essa arquitetura, consulte [25 de observação técnica](../mfc/tn025-document-view-and-frame-creation.md).  
  
 Depois de ter decidido uma estratégia, você deve ler o [contêineres](../mfc/containers.md) ou [servidores](../mfc/servers.md) artigos (dependendo do tipo de aplicativo que você está escrevendo) ou examinar os programas de exemplo, ou ambos. Os exemplos de OLE do MFC [OCLIENT](../visual-cpp-samples.md) e [HIERSVR](../visual-cpp-samples.md) mostram como implementar os vários aspectos dos contêineres e servidores, respectivamente. Em vários pontos durante esses artigos, você será chamado para determinadas funções nesses exemplos como exemplos das técnicas que está sendo discutidos.  
  
## <a name="see-also"></a>Consulte também  
 [Plano de fundo OLE](../mfc/ole-background.md)   
 [Contêineres: Implementando um contêiner](../mfc/containers-implementing-a-container.md)   
 [Servidores: Implementando um servidor](../mfc/servers-implementing-a-server.md)   
 [Assistente de aplicativo do MFC](../mfc/reference/mfc-application-wizard.md)

