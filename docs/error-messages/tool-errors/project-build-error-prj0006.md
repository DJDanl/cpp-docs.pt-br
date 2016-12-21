---
title: "Erro PRJ0006 (compila&#231;&#227;o de projeto) | Microsoft Docs"
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
  - "PRJ0006"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "PRJ0006"
ms.assetid: ce092be4-1652-414f-8cb5-b97ef5841f89
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro PRJ0006 (compila&#231;&#227;o de projeto)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Não foi possível abrir o arquivo temporário “arquivo”.Verifique se o arquivo existe e se o diretório não está protegido contra gravação.  
  
 Visual C\+\+ não pôde criar um arquivo temporário durante o processo de compilação.  As razões para essa incluem:  
  
-   Nenhum diretório temp.  
  
-   Diretório temporário somente leitura.  
  
-   Sem espaço em disco.  
  
-   A pasta de IntDir $ \(\) é somente leitura ou contém os arquivos temporários que são somente leitura.  
  
 Esse erro também ocorrerá depois de erro PRJ0007: Não foi possível criar o diretório “” diretório de saída.  O erro PRJ0007 significa que o diretório de IntDir \($\) não pôde ser criado, implicando a criação temporária de arquivos também falhará.  
  
 Os arquivos temporários são criados sempre que você especifica:  
  
-   Um arquivo de resposta.  
  
-   Uma etapa personalizado de compilação.  
  
-   Um evento de compilação.