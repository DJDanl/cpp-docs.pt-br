---
title: "Erro das Ferramentas de Vinculador LNK2023 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "LNK2023"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK2023"
ms.assetid: c99e35a8-739a-4a20-a715-29b8c3744703
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro das Ferramentas de Vinculador LNK2023
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

DLL inadequada ou DLL do ponto \<de entrada ou ponto de entrada\>  
  
 O vinculador estiver carregando uma versão incorreta de msobj90.dll.  Certifique\-se de que link.exe e msobj90.dll no seu caminho tenham a mesma versão.  
  
 Uma dependência de msobj90.dll não esteja presente.  A lista de dependência para msobj90.dll é:  
  
-   Msvcr90.dll  
  
-   Kernel32.dll  
  
 Verifique se o computador para todas as outras cópias de msobj90.dll que pode ser expirado.