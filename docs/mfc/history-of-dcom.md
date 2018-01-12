---
title: "Histórico de DCOM | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- Remote Automation, DCOM
- DCOM, about DCOM
- DCOM
ms.assetid: c21aa0ea-1396-4b52-b77f-88fb0fdd2a5c
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 6ef567c39c93c3d43fdfc0fa63886144b03cd474
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="history-of-dcom"></a>Histórico de DCOM
Automação foi introduzida em 1993 antecipada, era pode ser usado apenas entre aplicativos em execução no mesmo computador. No entanto, porque ela compartilhada de bases mesmo que o resto do OLE, que é, COM (ou Component Object Model), sempre intenção era que ela se tornaria "remoto" quando COM próprio foi atualizado para incluir recursos de comunicação remota. Ele também foi planejado que a transição da operação puramente local para operação distribuída exigem pouca ou nenhuma alteração ao código existente.  
  
 Portanto, o que "remoto" significa Local COM determinado que o consumidor de uma interface residem e execução no mesmo computador que o provedor de interface. Por exemplo, Microsoft Visual Basic pode controlar uma cópia do Microsoft Excel em seu computador desktop, mas não foi capaz de direcionar a execução do Excel em outro computador. Com o desenvolvimento de COM distribuída, o consumidor de uma interface não precisa residir no mesmo computador no qual o provedor de interface é executado.  
  
 Quando COM foi adaptado para trabalhar em uma rede, em seguida, qualquer interface que não foi associado a um modelo de execução local (algumas interfaces têm confiança inerente nos recursos do computador local, como aqueles desenho interfaces cujos métodos têm identificadores para contextos de dispositivo como parâmetros) tem a capacidade de serem distribuídos. Um consumidor de interface deve fazer uma solicitação para uma determinada interface; Essa interface pode ser fornecido por uma instância de um objeto em execução (ou para ser executado) em um computador diferente. O mecanismo de distribuição dentro COM seria conectar-se o consumidor para o provedor de forma que chamadas de método feitas pelo consumidor deve aparecer no final provedor, em que poderia ser executadas. Qualquer retornam valores, em seguida, seriam enviados de volta para o consumidor. Para todas as finalidades, o ato de distribuição é transparente para o consumidor e o provedor.  
  
 Agora existem várias de COM. DCOM (para "distribuídos COM") tiver sido enviado com as versões da partir do Windows NT versão 4.0 e incluindo o Windows 2000. Desde 1996 tardia, ele também está disponível para Windows 9x x. Em ambos os casos, o DCOM consiste em um conjunto de substituição e DLLs adicionais, com alguns utilitários, que fornecem os recursos COM locais e remotos. Ele agora, portanto, é uma parte inerente de plataformas Win32 e estarão disponível em outras plataformas por outras organizações ao longo do tempo.  
  
## <a name="in-this-section"></a>Nesta seção  
 [Onde entra a automação remota](where-does-remote-automation-fit-in-q.md)  
  
 [O que a automação remota fornece](what-does-remote-automation-provide-q.md)  
  
## <a name="see-also"></a>Consulte também  
 [Automação remota](../mfc/remote-automation.md)
