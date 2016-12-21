---
title: "Aviso do compilador (n&#237;vel 1) C4819 | Microsoft Docs"
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
  - "C4819"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4819"
ms.assetid: c0316e85-249c-414d-9df0-622d077c6bc2
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4819
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O arquivo contém um caractere que não pode ser representado na página de código atual \(número\).Salve o arquivo no formato Unicode para evitar a perda de dados.  
  
 C4819 ocorre quando um arquivo de origem ANSI é compilado em um sistema com uma página de código que não pode representar todos os caracteres no arquivo.  
  
 Para resolver C4819, salve o arquivo no formato Unicode.  No Visual Studio, escolha **Arquivo**, **Opções de Salvamento Avançadas**.  Na caixa de diálogo **Opções de Salvamento Avançadas**, selecione uma codificação que pode representar todos os caracteres no arquivo — por exemplo, UTF\-8 — e, em seguida, escolha **OK**.