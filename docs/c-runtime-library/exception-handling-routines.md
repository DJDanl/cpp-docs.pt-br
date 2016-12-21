---
title: "Rotinas do tratamento de exce&#231;&#245;es | Microsoft Docs"
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
  - "c.exceptions"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "tratamento de exceção, Rotinas "
ms.assetid: f60548c6-850a-4e1e-a79b-a2a6a541ab62
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Rotinas do tratamento de exce&#231;&#245;es
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Use as funções de controle de exceções das linguagens C\+\+ para a recuperação de eventos inesperados durante a execução do programa.  
  
### Funções de manipulação de exceções gerais  
  
|Função|Uso|Equivalente a .NET Framework|  
|------------|---------|----------------------------------|  
|[\_set\_se\_translator](../c-runtime-library/reference/set-se-translator.md)|Tratar exceções do Win32 \(exceções estruturado de 2.0 C\) como exceções digitadas C\+\+|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[set\_terminate](../c-runtime-library/reference/set-terminate-crt.md)|Instalar sua própria rotina de conclusão a ser chamada por `terminate`|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[set\_unexpected](../c-runtime-library/reference/set-unexpected-crt.md)|Instalar sua própria função de término a ser chamada por `unexpected`|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[encerrar](../c-runtime-library/reference/terminate-crt.md)|Chamado depois da exceção gerada automaticamente em determinadas circunstâncias.  As chamadas de função `abort` de `terminate` ou uma função que você especifica usando `set_terminate`|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[inesperado](../Topic/unexpected%20\(CRT\).md)|Chamadas `terminate` ou uma função que você especifica usando `set_unexpected`.  A função de `unexpected` não é usada na implementação atual de controle de exceções das linguagens Microsoft C\+\+|[\<caps:sentence id\="tgt30" sentenceid\="ec8332f3bf55c7bd183338eca87744ec" class\="tgtSentence"\>Classe de System::Exception\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.exception.aspx)|  
  
## Consulte também  
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)