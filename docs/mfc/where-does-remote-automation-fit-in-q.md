---
title: "Onde entra a automa&#231;&#227;o remota? | Microsoft Docs"
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
  - "Automação remota, DCOM"
ms.assetid: 4c4c8176-cfc0-44f7-bc87-b690f069ad2f
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Onde entra a automa&#231;&#227;o remota?
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

DCOM foi liberado em 1996 e está disponível com plataformas de 32 bits e de 64 bits do somente.  A equipe do Visual Basic no Microsoft Visual Basic sempre viu como a utilização de automação para permitir que os componentes se comuniquem.  A falta de uma versão distribuída limitou drasticamente o uso desses recursos em ambientes do enterprise, para que a equipe que desenvolve Visual Basic 4,0 Enterprise Edition decide investigar a criação de seu próprio conjunto de componentes remota para as partes de automação OLE e COM.  Claramente, o objetivo principal foi garantir que o resultado seja compatível com o e pode ser substituído por DCOM quando se torne disponível.  Continuaram em para implementar a automação store \(RA\) para plataformas de 16 bits e de 32 bits do windows.  
  
 A automação remoto não está associada a um determinado idioma, mas até a versão do Visual C\+\+ 4,2 Enterprise Edition, foi enviada somente com o Visual Basic 4,0.  Lembre\-se de que a automação remoto completamente incluídos por DCOM.  Se você tem a oportunidade de usar DCOM em vez de automação remoto em seus aplicativos, você deve fazer isso.  Entretanto, há os cenários onde a automação remoto é mais apropriado:  
  
-   Sempre que você tem clientes de 16 bits.  
  
-   Se sua organização não desenrolou uma versão DCOM\- habilitada do Windows NT 95 ou do Windows ainda.  
  
-   Se você estiver atualizando um pacote de aplicativos existente que usa a automação remoto para usar componentes C\+\+ no lugar de um ou mais componentes do Visual Basic.  
  
 Não precisa estar nenhuma diferença entre programas projetados para usar a automação remoto e aqueles criados para usar a automação sobre DCOM, e os utilitários de configuração tornam muito simples alternar a operação entre a automação remoto e o DCOM.  Consequentemente, não é difícil atualizar um aplicativo de automação remoto ao DCOM uma vez que a infraestrutura está em vigor.  
  
## Consulte também  
 [O que a automação remota fornece?](../mfc/what-does-remote-automation-provide-q.md)   
 [Histórico de DCOM](../mfc/history-of-dcom.md)