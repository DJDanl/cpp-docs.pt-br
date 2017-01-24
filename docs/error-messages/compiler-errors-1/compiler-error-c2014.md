---
title: "Erro do Compilador C2014 | Microsoft Docs"
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
  - "C2014"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2014"
ms.assetid: 231d8e9c-48c0-4027-99a3-245d186275ec
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2014
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o comando de pré\-processador deve ser iniciado como o primeiro espaço nonwhite  
  
 O sinal de `#` de uma política de pré\-processador deve ser o primeiro caractere em uma linha que não é o espaço em branco.  
  
 O seguinte exemplo gera C2014:  
  
```  
// C2014.cpp  
int k; #include <stdio.h>   // C2014  
```  
  
 Solução possível:  
  
```  
// C2014b.cpp  
// compile with: /c  
int k;   
#include <stdio.h>  
```