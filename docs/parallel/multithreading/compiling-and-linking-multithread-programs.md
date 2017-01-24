---
title: "Compilando e vinculando programas multithread | Microsoft Docs"
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
  - "compilando programas com multithread"
  - "compilando o código-fonte [C++], programas multithread"
  - "vinculando [C++], programas multithread"
  - "multithreading [C++], programas compilados"
  - "multithreading [C++], vinculando programas"
  - "threading [C++], programas compilados"
  - "threading [C++], vinculando programas"
ms.assetid: 27589afc-daf2-4f26-b868-a99de5c9dfec
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Compilando e vinculando programas multithread
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O programa de Bounce.c é introduzido em [Programa C multi\-threaded de exemplo](../../parallel/sample-multithread-c-program.md).  
  
 Os programas estão multi\-threaded criado por padrão.  
  
#### Para compilar e vincular o programa multi\-threaded Bounce.c dentro do ambiente de desenvolvimento  
  
1.  No menu **Arquivo**, clique em **Novo** e em **Projeto**.  
  
2.  No painel de **Tipos de projeto** , clique **Win32**.  
  
3.  No painel de **Modelos** , clique em **Aplicativo do Console Win32**, e os nomes do projeto.  
  
4.  Adicione o arquivo que contém a origem do C ao projeto.  
  
5.  No menu de **Compilar** , compilar o projeto clicando no comando de **Compilar** .  
  
#### Para compilar e vincular o programa multi\-threaded Bounce.c de linha de comando  
  
1.  Compilar e vincular o programa:  
  
    ```  
    CL BOUNCE.C  
    ```  
  
## Consulte também  
 [Multithread com C e Win32](../../parallel/multithreading-with-c-and-win32.md)