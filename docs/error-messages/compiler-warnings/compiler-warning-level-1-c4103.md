---
title: "Aviso do compilador (n&#237;vel 1) C4103 | Microsoft Docs"
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
  - "C4103"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4103"
ms.assetid: 9021b514-375e-4d62-b261-ccb06f299e8e
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4103
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“nome de arquivo”: o alinhamento foi alterada depois de incluir o cabeçalho, pode ocorrer devido ao bloco de falta de \#pragma \(o pop\)  
  
 Pacotes afeta o layout das classes, e geralmente, se o pacote for alterada através de arquivos de cabeçalho, pode haver problemas.  
  
 Use o \#pragma [bloco](../../preprocessor/pack.md)\(pop\) antes de sair do arquivo de cabeçalho para resolver esse aviso.  
  
 O seguinte exemplo gera C4103:  
  
```  
// C4103.h  
#pragma pack(push, 4)  
  
// defintions and declarations  
  
// uncomment the following line to resolve  
// #pragma pack(pop)  
```  
  
 Em seguida, e  
  
```  
// C4103.cpp  
// compile with: /LD /W1  
#include "c4103.h"   // C4103  
```