---
title: "Erro fatal C1854 | Microsoft Docs"
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
  - "C1854"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C1854"
ms.assetid: 8c21a9cc-1737-475c-9e57-8725cd8937c1
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal C1854
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

não é possível substituir as informações bem formada durante a criação do cabeçalho pré\-compilado no arquivo de objeto: “nome de arquivo”  
  
 Você especificou a opção de **\/Yu** \(cabeçalho pré\-compilado de uso\) depois de especificar a opção de **\/Yc** \(criar o cabeçalho pré\-compilado\) para o mesmo arquivo.  Determinadas instruções \(como as instruções que incluem `__declspec` `dllexport`\) fazem isto inválido.