---
title: "Erro do Compilador C2026 | Microsoft Docs"
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
  - "C2026"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2026"
ms.assetid: 8e64b6e1-b967-479b-be97-d12dc4a8e389
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2026
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

cadeia de caracteres muito grande, caracteres truncados à direita  
  
 A cadeia de caracteres era maior que o limite de 16380 caracteres de um byte.  
  
 Antes das cadeias de caracteres adjacentes que estão sendo concatenadas, uma cadeia de caracteres não pode ser mais longo que 16380 caracteres de um byte.  
  
 Uma cadeia de caracteres Unicode de aproximadamente um meio desse comprimento também gerará este erro.  
  
 Se você tiver uma cadeia de caracteres definida da seguinte maneira, gerenciar C2026:  
  
```  
char sz[] =  
"\  
imagine a really, really \  
long string here\  
";  
```  
  
 Você pode quebrá\-la acima da seguinte maneira:  
  
```  
char sz[] =  
"\  
imagine a really, really "  
"long string here\  
";  
```  
  
 Talvez você queira armazenar grandes cadeias literais exclusivamente 32K \(ou mais\) em um recurso personalizado ou em um arquivo externo.  Consulte [Criando um novo recurso personalizadas ou de dados](../../mfc/creating-a-new-custom-or-data-resource.md) para obter mais informações.