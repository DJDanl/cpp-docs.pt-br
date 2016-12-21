---
title: "Erro PRJ0024 (compila&#231;&#227;o de projeto) | Microsoft Docs"
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
  - "PRJ0024"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "PRJ0024"
ms.assetid: 8bde6368-6c1b-4e04-bc5e-3c6d0b8fa1d7
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro PRJ0024 (compila&#231;&#227;o de projeto)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O caminho “path” Unicode não pode ser convertido na página de código ANSI do usuário.  
  
 ***path***  é a versão original do Unicode da cadeia de caracteres de caminho.  Esse erro pode ocorrer nos casos em que há um caminho de Unicode que não pode ser convertido em ANSI diretamente para a página de código atual do sistema.  
  
 Esse erro pode ocorrer se você estiver trabalhando com um projeto que foi desenvolvido em um sistema que usa uma página de código que não está em seu computador.  
  
 A solução desse erro é atualizar o caminho para usar o texto ANSI ou para instalar a página de código no seu computador e defini\-la como a opção do sistema.