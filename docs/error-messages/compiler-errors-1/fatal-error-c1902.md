---
title: "Erro fatal C1902 | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C1902"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C1902"
ms.assetid: 2dc066cc-fcb1-4725-8bcb-9f44dd0905b7
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal C1902
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

incompatibilidade do gerenciador de base de dados do programa; verifique a instalação  
  
 Um arquivo de base de dados do programa \(.pdb\) foi criado usando uma versão mais nova de mspdb*XX*.dll o que o compilador localizado no sistema.  Esse erro geralmente indica que mspdbsrv.exe ou mspdbcore.dll estão ausentes ou têm versões diferentes do mspdb*XX*.dll. \(O espaço reservado de *XX* nas alterações de nome de arquivo de*XX*.dll de mspdb a cada versão do produto.  Por exemplo, em [!INCLUDE[vsprvslong](../../error-messages/compiler-errors-1/includes/vsprvslong_md.md)] o nome do arquivo é mspdb80.dll.\)  
  
 Certifique\-se de que as versões correspondentes de mspdbsrv.exe, de mspdbcore.dll, e de mspdb*XX*.dll do estão instaladas em seu sistema.  Certifique\-se de que as versões incompatíveis não sejam copiadas para o diretório que contém as ferramentas do compilador e link para a sua plataforma de destino.  Por exemplo, você pode ter copiado os arquivos de forma que você pode invocar a ferramenta do compilador ou do link do prompt de comando sem defina a variável de ambiente de **PATH** adequadamente.