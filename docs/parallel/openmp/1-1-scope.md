---
title: "1.1 Scope | Microsoft Docs"
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
ms.assetid: a8570a3c-1dd6-4c3d-b368-a10fcb3534a6
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# 1.1 Scope
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Esta especificação de cobre apenas o user\-directed paralelização, no qual o usuário especifica explicitamente as ações a serem tomadas pelo compilador e sistema de tempo de execução para executar o programa em paralelo.  Implementações OpenMP C e C\+\+ não são necessários para verificar se há dependências, conflitos, as condições de corrida, deadlocks ou outros problemas que resultam na execução do programa incorreto.  O usuário é responsável por garantir que o aplicativo usando as construções OpenMP C e C\+\+ API seja executado corretamente.  Gerado pelo compilador paralelização automática e diretivas do compilador para auxiliar tal paralelização não são abordadas neste documento.