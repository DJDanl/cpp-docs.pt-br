---
title: "Tratamento de erros (CRT) | Microsoft Docs"
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
  - "c.errors"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "tratamento de erros, rotinas C para"
  - "tratamento de erros, rotinas de biblioteca"
  - "erros de lógica"
  - "testando, para erros de programa"
ms.assetid: 125ac697-9eb0-4152-a440-b7842f23d97f
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Tratamento de erros (CRT)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Use essas rotinas para tratar erros de programa.  
  
### Rotinas de tratamento de erros  
  
|Rotina|Uso|Equivalente a .NET Framework|  
|------------|---------|----------------------------------|  
|macro de[assert](../c-runtime-library/reference/assert-macro-assert-wassert.md)|Testar se há erros lógicos de programação; disponíveis em versões de versão e de depuração da biblioteca de tempo de execução|[\<caps:sentence id\="tgt8" sentenceid\="14fd9bf776829d73028df00162f7533f" class\="tgtSentence"\>System::Diagnostics::Debug::Assert\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.diagnostics.debug.assert.aspx)|  
|macros de[\_ASSERT, \_ASSERTE](../Topic/_ASSERT,%20_ASSERTE,%20_ASSERT_EXPR%20Macros.md)|Semelhante a, mas `assert`disponível somente nas versões de depuração da biblioteca de tempo de execução|[\<caps:sentence id\="tgt11" sentenceid\="14fd9bf776829d73028df00162f7533f" class\="tgtSentence"\>System::Diagnostics::Debug::Assert\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.diagnostics.debug.assert.aspx)|  
|[clearerr](../c-runtime-library/reference/clearerr.md)|Indicador de erro de redefinição.  A chamada `rewind` ou fechar um fluxo também redefine o indicador de erro.|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_eof](../c-runtime-library/reference/eof.md)|Para verificar a fim de arquivo na E\/S de nível baixo|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[feof](../c-runtime-library/reference/feof.md)|Testar a fim de arquivo.  A fim de arquivo é indicada também quando retorna 0 de `_read` .|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[ferror](../c-runtime-library/reference/ferror.md)|Para testar erros de E\/S de fluxo|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|macros de[\_RPT, \_RPTF](../Topic/_RPT,%20_RPTF,%20_RPTW,%20_RPTFW%20Macros.md)|Gerencia um relatório semelhante a `printf`, mas disponível somente nas versões de depuração da biblioteca de tempo de execução|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_set\_error\_mode](../c-runtime-library/reference/set-error-mode.md)|Altera `__error_mode` para determinar um local não padrão em que o tempo de execução C gravar uma mensagem de erro de um erro que encerre possivelmente o programa.||  
|[\_set\_purecall\_handler](../c-runtime-library/reference/get-purecall-handler-set-purecall-handler.md)|Define o manipulador para uma chamada de função virtual pura.||  
  
## Consulte também  
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)