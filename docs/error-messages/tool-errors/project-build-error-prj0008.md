---
title: "Erro PRJ0008 (compila&#231;&#227;o de projeto) | Microsoft Docs"
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
  - "PRJ0008"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "PRJ0008"
ms.assetid: 6bf7f17a-d2a8-4826-99c7-d600d846952f
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro PRJ0008 (compila&#231;&#227;o de projeto)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Não foi possível excluir o arquivo “arquivo”.  
  
 **Verifique se o arquivo não está aberto em outro processo e se ele não está protegido contra gravação.**  
  
 Durante uma recriação ou excluir, limpar todos do Visual C\+\+ intermediário e arquivos de saída conhecidos para a construção, bem como todos os arquivos que satisfaça as especificações de curinga na propriedade de **Extensões a Serem Excluídas ao Limpar** em [Página de propriedades geral dos parâmetros de configuração](../Topic/General%20Property%20Page%20\(Project\).md).  
  
 Você verá esse erro se o Visual C\+\+ não pode excluir um arquivo.  Para resolver o erro, crie o arquivo e seu diretório ser gravados para o usuário que faz a compilação.