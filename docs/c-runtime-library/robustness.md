---
title: "Robustez | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "c.runtime"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "robustez [CRT]"
ms.assetid: 7f1a87f8-eff9-4b76-ae9b-d133d3de6adf
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Robustez
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Use as funções da biblioteca de tempo de execução C para deixar seu programa mais robusto.  
  
### Funções que conferem robustez ao tempo de execução  
  
|Função|Uso|Equivalente ao .NET Framework|  
|------------|---------|-----------------------------------|  
|[\_set\_new\_handler](../Topic/_set_new_handler.md)|Transfere o controle ao mecanismo de gerenciamento de erros se o operador `new` não conseguir alocar memória.|Não aplicável.  Para chamar a função C padrão, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_set\_se\_translator](../c-runtime-library/reference/set-se-translator.md)|Trata exceções do Win32 \(exceções C estruturadas\) como exceções C\+\+.|Não aplicável.  Para chamar a função C padrão, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
|[set\_terminate](../c-runtime-library/reference/set-terminate-crt.md)|Instala sua próprio função de terminação a ser chamada por [terminate](../c-runtime-library/reference/terminate-crt.md).|Não aplicável.  Para chamar a função C padrão, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
|[set\_unexpected](../c-runtime-library/reference/set-unexpected-crt.md)|Instala sua próprio função de terminação a ser chamada por [unexpected](../Topic/unexpected%20\(CRT\).md).|Não aplicável.  Para chamar a função C padrão, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
  
## Consulte também  
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)   
 [SetUnhandledExceptionFilter](http://msdn.microsoft.com/library/windows/desktop/ms680634.aspx)