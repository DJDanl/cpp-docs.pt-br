---
title: "Erro BK1503 (BSCMAKE) | Microsoft Docs"
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
  - "BK1503"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "BK1503"
ms.assetid: e6582344-b91e-486f-baf3-4f9028d83c3b
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro BK1503 (BSCMAKE)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

não é possível gravar no arquivo “nome de arquivo” \[: motivo\]  
  
 BSCMAKE combina os arquivos de .sbr gerados durante a compilação em uma base de dados do navegador.  Se o base de dados do navegador resultante exceder 64 MB, ou se o número de arquivos de entrada \(.sbr\) excede 4092, esse erro será emitido.  
  
 Se o problema é causado por mais de 4092 arquivos de .sbr, você deve reduzir o número de arquivos de entrada.  A partir do Visual Studio, isso pode ser realizado por [\/FR](../../build/reference/fr-fr-create-dot-sbr-file.md) seu projeto inteiro, então verifica novamente em um arquivo com base em arquivo.  
  
 Se o problema é causado por um arquivo de .bsc maior que 64MB, reduzir o número de .sbr arquivos como a entrada diminuirá o tamanho do arquivo resultante de .bsc.  Além disso, a quantidade de procura as informações podem ser reduzida com o uso de \/Em \(exclua símbolos expandidos macro\), de \/El \(excluir variáveis locais\), e \/Es \(excluir arquivos do sistema\).  
  
## Consulte também  
 [Opções de BSCMAKE](../Topic/BSCMAKE%20Options.md)