---
title: "Definindo op&#231;&#245;es de vinculador | Microsoft Docs"
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
  - "Arquivos  [C++], LINK"
  - "arquivos de entrada [C++]"
  - "arquivos de entrada [C++], vinculador"
  - "vinculador [C++], opções"
  - "vinculador [C++], formas de definir opções"
  - "módulos de objeto/biblioteca"
ms.assetid: e08fb487-0f2e-4f24-87db-232dbc8bd2e2
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Definindo op&#231;&#245;es de vinculador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As opções do vinculador podem ser internas ou definido fora do ambiente de desenvolvimento.  O tópico para cada opção do vinculador discute como pode ser definido no ambiente de desenvolvimento.  Consulte [Opções do vinculador](../../build/reference/linker-options.md) para obter uma lista completa.  
  
 Quando você executa o LINK fora do ambiente de desenvolvimento, você pode especificar a entrada em uma ou muitas maneiras:  
  
-   Em [linha de comando](../../build/reference/linker-command-line-syntax.md)  
  
-   Usando [arquivos de comando](../../build/reference/link-command-files.md)  
  
-   Em [variáveis de ambiente](../../build/reference/link-environment-variables.md)  
  
 VINCULAR as primeiras opções de processos especificadas na variável de ambiente de LINK, seguido pelas opções na ordem em que são especificados na linha de comando e arquivos de comando.  Se uma opção é repetida com argumentos diferentes, processado pela última vez terá precedência.  
  
 As opções se aplicam à construção inteira; nenhuma opção pode ser aplicada aos arquivos de entrada específicos.  
  
## Consulte também  
 [Referência de compilação do C\/C\+\+](../Topic/C-C++%20Building%20Reference.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)