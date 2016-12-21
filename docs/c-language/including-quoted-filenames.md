---
title: "Incluindo nomes de arquivo entre aspas | Microsoft Docs"
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
  - "C"
ms.assetid: 789a047e-ea38-4c99-b71d-a2ad9c81daee
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Incluindo nomes de arquivo entre aspas
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**ANSI 3.8.2** O suporte para nomes entre aspas para arquivos de origem incluíveis  
  
 Se você indicar uma especificação de caminho completa e inequívoca para o arquivo de inclusão entre aspas duplas \(" "\), o pré\-processador pesquisará apenas essa especificação de caminho e ignorará os diretórios padrão.  
  
 Para arquivos de inclusão especificados como [\#include](../preprocessor/hash-include-directive-c-cpp.md) "path\-spec", a pesquisa de diretórios começa com os diretórios do arquivo pai e continua pelos diretórios dos arquivos avô, se houver.  Assim, a pesquisa começa em relação ao diretório que contém o arquivo de origem que está sendo processado.  Se não houver nenhum arquivo avô e o arquivo não tiver sido encontrado, a pesquisa continuará como se o nome do arquivo estivesse entre colchetes angulares.  
  
## Consulte também  
 [Pré\-processando diretivas](../Topic/Preprocessing%20Directives.md)