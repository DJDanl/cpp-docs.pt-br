---
title: "VCPROFILE_PATH | Microsoft Docs"
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
  - "VCPROFILE_PATH"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Variável de ambiente VCPROFILE_PATH"
ms.assetid: 25217aa4-7e86-4eba-854d-10b3c457e4df
caps.latest.revision: 4
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# VCPROFILE_PATH
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Especifique o diretório para criar arquivos de .pgc.  
  
## Sintaxe  
  
```  
VCPROFILE_PATH=path  
```  
  
#### Parâmetros  
 `path`  
 O caminho do diretório em que .pgc arquivos será adicionado.  
  
## Comentários  
 Por padrão, os arquivos de .pgc são criados no mesmo diretório que o binário que está sendo analisado.  No entanto, se o caminho absoluto de binário não existir, como podem ser os casos quando você executar cenários de perfil em um computador diferente do em que o BLOB foi criado, você pode definir `VCPROFILE_PATH` a um caminho que existe.  
  
## Exemplo  
  
```  
set VCPROFILE_PATH=c:\  
```  
  
## Consulte também  
 [Variáveis de ambiente para otimizações orientadas a perfil](../../build/reference/environment-variables-for-profile-guided-optimizations.md)