---
title: "Erro das Ferramentas de Vinculador LNK1181 | Microsoft Docs"
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
  - "LNK1181"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK1181"
ms.assetid: 984b0db6-e331-4284-b2a7-a212fe96c486
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro das Ferramentas de Vinculador LNK1181
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

não é possível abrir o arquivo de entrada “nome de arquivo”  
  
 O vinculador não pôde localizar `filename` porque não existe ou o caminho não foi encontrado.  
  
 Algumas as causas comuns do erro LNK1181 incluem:  
  
-   `filename` é referenciado como uma dependência adicional na linha do vinculador, mas o arquivo não existir.  
  
-   Uma instrução de **\/LIBPATH** que especifica o diretório que contém `filename` está ausente.  
  
 Para resolver problemas acima, verifique se todos os arquivos referenciados na linha do vinculador estar presente no sistema.  Também verifique se há uma instrução de **\/LIBPATH** para cada diretório que contém um arquivo de vinculador\- dependente.  
  
 Outra causa possível para LNK1181 é que um nome de arquivo longo com espaços inseridos não esteve entre aspas.  Nesse caso, o vinculador reconhecerá apenas um nome de arquivo até o primeiro espaço, e assume em uma extensão de arquivo de .obj.  A solução nessa situação é incluir o nome de arquivo caminho mais longo \(o nome de arquivo\) entre aspas.  
  
 Para obter mais informações, consulte [arquivos de .lib como a entrada do vinculador](../../build/reference/dot-lib-files-as-linker-input.md).  
  
## Consulte também  
 [\/LIBPATH \(Libpath adicional\)](../../build/reference/libpath-additional-libpath.md)