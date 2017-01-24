---
title: "Testando aplicativos da Internet | Microsoft Docs"
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
  - "depuração [MFC], aplicativos da Web"
  - "depurando aplicativos da Web, testando aplicativos"
  - "depuração e teste da Internet"
  - "testando, aplicativos da Internet"
  - "aplicativos da Web, testando"
ms.assetid: ac4c74e3-d4ad-4e19-8f6c-e270de067f01
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Testando aplicativos da Internet
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Há alguns desafios exclusivos de teste na Internet, especialmente para aplicativos executados em um servidor Web.  Os testes iniciais serão feitas usando um cliente provavelmente de usuário único que se conecta a um servidor de teste.  Isso será útil para depurar seu código.  
  
 Você também pode querer testar reais em condições: com vários clientes conectados pelas conexões de alta velocidade das linhas consecutivas de baixa velocidade, incluindo conexões de modem.  Pode ser difícil simular condições reais, mas é realmente valor que passa o tempo que criam cenários possíveis e que executam o.  Se possível, você também pode querer usar ferramentas para fazer a capacidade e forçar teste.  Certas classes de bug, como bug de tempo, são difíceis de localizar e reproduzir.  
  
 Um dos desafios de programação da Internet é sua visibilidade.  Muitos acessar o site podem reduzir seu servidor.  Você deseja que o servidor para diminuir normalmente.  Você quer evitar qualquer coisa que pode ser destrutivo no computador de um usuário se seu aplicativo falha \(por exemplo, corrupção de dados ao gravar no Registro ou ao gravar em cookies no cliente\).  
  
## Consulte também  
 [Tarefas de programação da Internet MFC](../mfc/mfc-internet-programming-tasks.md)   
 [Noções básicas de programação da Internet MFC](../mfc/mfc-internet-programming-basics.md)