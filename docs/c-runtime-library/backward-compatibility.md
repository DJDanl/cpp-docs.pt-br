---
title: "Compatibilidade com vers&#245;es anteriores | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "c.programs"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "compatibilidade com versões anteriores"
  - "compatibilidade com versões anteriores, bibliotecas em tempo de execução C"
  - "compatibilidade, bibliotecas em tempo de execução C"
  - "CRT, compatibilidade"
ms.assetid: cc3175cf-97fd-492f-b329-5791aea63090
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compatibilidade com vers&#245;es anteriores
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Para compatibilidade entre versões do produto, a biblioteca OLDNAMES.LIB mapeia nomes antigos para novos nomes.  Por exemplo, mapas de `open` a `_open`.  Você deve vincular explicitamente com OLDNAMES.LIB apenas quando você compila com as seguintes combinações de opções de linha de comando:  
  
-   `/Zl` \(omita o nome da biblioteca padrão do arquivo de objeto\) e `/Ze` \(a opção — use extensões da Microsoft\)  
  
-   `/link` \(vinculador\- controle\), `/NOD` \(nenhuma pesquisa do biblioteca\), e `/Ze`  
  
 Para obter mais informações sobre opções de linha de comando do compilador, consulte [Referência do compilador](../build/reference/compiler-options.md).  
  
## Consulte também  
 [Compatibilidade](../c-runtime-library/compatibility.md)