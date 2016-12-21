---
title: "Aviso do compilador C4335 | Microsoft Docs"
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
  - "C4335"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4335"
ms.assetid: e66467ad-a10b-4438-8c7c-e8e8d11d39bb
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador C4335
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Formato de arquivo de Mac detectado: converter suporte pelo arquivo de origem no formato de OS ou do UNIX  
  
 A linha caractere de término da primeira linha de um arquivo de origem é estilo Macintosh \(“\\ r "\) ao contrário do UNIX \(“\\ n "\) ou de DE OS \(“\\ r \\ n "\).  
  
 Esse aviso é emitido sempre como um erro.  Consulte o pragma de [warning](../../preprocessor/warning.md) para obter informações sobre como desabilitar esse aviso.  Além disso, esse aviso é emitido somente uma vez por compiland.  Em virtude disso, se houver várias políticas de `#include` que especificam arquivos no formato Macintosh, C4335 será emitido somente uma vez.  
  
 Uma maneira de gerar arquivos no formato a Partir é usando **Opções de Salvamento Avançadas** \(no menu de **Arquivo** \) no Visual Studio.  
  
## Exemplo  
 O exemplo a seguir produz C4335.  
  
```  
// C4335 expected  
#include "c4335.h"   // assume both include files are in Macintosh format  
#include "c4335_2.h"  
```