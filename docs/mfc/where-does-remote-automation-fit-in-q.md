---
title: "Onde entra a automação remota? | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- Remote Automation, DCOM
ms.assetid: 4c4c8176-cfc0-44f7-bc87-b690f069ad2f
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 9ad6eef0bbaad7860e7f4310ce283efe18c668eb
ms.sourcegitcommit: fa7a6dccddce3747389c91277a53e296f905305c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="where-does-remote-automation-fit-in"></a>Onde entra a automação remota?
DCOM foi lançado em 1996 e está disponível com plataformas de 32 bits e 64 bits apenas. Equipe do Visual Basic, Microsoft observou sempre Visual Basic como usando a automação para permitir que seus componentes para se comunicar. A falta de uma versão distribuída limitada severamente o uso desses recursos em ambientes corporativos, para que a equipe de desenvolvimento do Visual Basic 4.0 Enterprise Edition decidiu investigar a criação de seu próprio conjunto de componentes de comunicação remota para a automação partes de OLE e COM. Claramente, uma grande meta era garantir que o resultado seria compatível com e pode ser substituído por DCOM quando ele se tornou disponível. Eles continuavam, em seguida, para implementar a automação remota (RA) para plataformas Windows de 16 bits e 32 bits.  
  
 Automação remota não está vinculada a qualquer idioma específico, mas até o lançamento do Visual C++ 4.2 Enterprise Edition, ele foi enviado com o Visual Basic 4.0. Lembre-se de que a automação remota totalmente está incluída pelo DCOM. Se você tem a oportunidade de usar DCOM em vez de automação remota em seus aplicativos, você deve fazer isso. No entanto, há cenários em que a automação remota é mais apropriada:  
  
-   Sempre que você tiver clientes de 16 bits.  
  
-   Se sua organização não transferiu para uma versão do Windows NT ou o Windows 95 habilitada DCOM ainda.  
  
-   Se você estiver atualizando um pacote de aplicativo existente que usa automação remota para usar componentes de C++ em vez de um ou mais componentes do Visual Basic.  
  
 Não precisa haver nenhuma diferença entre programas criados para usar automação remota e aqueles criados para usar a automação referente ao DCOM e os utilitários de configuração torná-lo muito simples para alternar a operação entre automação remota e DCOM. Consequentemente, não é difícil atualizar um aplicativo de automação remota de DCOM depois que a infraestrutura está em vigor.  
  
## <a name="see-also"></a>Consulte também  
 [O que a automação remota fornece](what-does-remote-automation-provide-q.md)   
 [Histórico de DCOM](../mfc/history-of-dcom.md)
