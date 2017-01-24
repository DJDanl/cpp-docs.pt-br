---
title: "_CrtSetReportMode | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_CrtSetReportMode"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_CrtSetReportMode"
  - "CrtSetReportMode"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _CrtSetReportMode"
  - "Função CrtSetReportMode"
ms.assetid: 3ecc6a12-afdd-4242-b046-8187ff6d4b36
caps.latest.revision: 15
caps.handback.revision: 15
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _CrtSetReportMode
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Especifica o destino ou os destinos para um tipo específico de relatório gerado por `_CrtDbgReport` e por todos macros que chamam [\_CrtDbgReport, \_CrtDbgReportW](../../c-runtime-library/reference/crtdbgreport-crtdbgreportw.md), como [Assert, asserte, \_ASSERT\_EXPR macros](../Topic/_ASSERT,%20_ASSERTE,%20_ASSERT_EXPR%20Macros.md), [Assert, asserte, \_ASSERT\_EXPR macros](../Topic/_ASSERT,%20_ASSERTE,%20_ASSERT_EXPR%20Macros.md), [Macros \_RPT, \_RPTF, \_RPTW, \_RPTFW](../Topic/_RPT,%20_RPTF,%20_RPTW,%20_RPTFW%20Macros.md), e [Macros \_RPT, \_RPTF, \_RPTW, \_RPTFW](../Topic/_RPT,%20_RPTF,%20_RPTW,%20_RPTFW%20Macros.md) \(versão de depuração somente\).  
  
## Sintaxe  
  
```  
int _CrtSetReportMode(   
   int reportType,  
   int reportMode   
);  
```  
  
#### Parâmetros  
 `reportType`  
 Tipo de relatório: `_CRT_WARN`, `_CRT_ERROR` e `_CRT_ASSERT`.  
  
 `reportMode`  
 Novo modo ou modos de relatório para `reportType`.  
  
## Valor de retorno  
 Na conclusão bem\-sucedida, `_CrtSetReportMode` retorna o modo ou os modos anteriores do relatório para o tipo de relatório especificado em `reportType`.  Se um valor inválido é passado como `reportType` ou um modo inválido for especificado para `reportMode`, `_CrtSetReportMode` invoca o manipulador inválido do parâmetro como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essa função definirá `errno` como `EINVAL` e retornará \-1.  Para obter mais informações, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 `_CrtSetReportMode` especifica o destino de saída para `_CrtDbgReport`.  Como macros `_ASSERT`, `_ASSERTE`, `_RPT`, e chame `_CrtDbgReport`de `_RPTF` , `_CrtSetReportMode` especificam o destino da saída do texto especificado com as macros.  
  
 Quando [\_DEBUG](../Topic/_DEBUG.md) não está definido, as chamadas para `_CrtSetReportMode` são removidas durante o pré\-processamento.  
  
 Se você não `_CrtSetReportMode` chama para definir o destino da saída das mensagens, as opções a seguir são aplicadas:  
  
-   As falhas de asserção e erros são redirecionados para uma janela de mensagem de depuração.  
  
-   Os avisos dos aplicativos do Windows são enviados à janela saída do depurador.  
  
-   Os avisos de aplicativos do console não são exibidos.  
  
 A tabela a seguir lista os tipos de relatório definidos em Crtdbg.h.  
  
|Tipo de relatório|Descrição|  
|-----------------------|---------------|  
|`_CRT_WARN`|Avisos, mensagens, e informações que não precisa da atenção imediata.|  
|`_CRT_ERROR`|Erros, problemas irrecuperável, e problemas que exigem atenção imediata.|  
|`_CRT_ASSERT`|Falhas de asserção permissões \(expressões que avaliam a `FALSE`\).|  
  
 A função de `_CrtSetReportMode` atribui o novo modo do relatório especificado em `reportMode` ao tipo de relatório especificado em `reportType` e retorna o modo definido anteriormente de relatório para `reportType`.  A tabela a seguir lista as opções disponíveis para `reportMode` e o comportamento resultante de `_CrtDbgReport`.  Essas opções são definidas como sinalizadores de bit em Crtdbg.h.  
  
|Modo de relatório|comportamento de \_CrtDbgReport|  
|-----------------------|-------------------------------------|  
|`_CRTDBG_MODE_DEBUG`|Grava a mensagem à janela saída do depurador.|  
|`_CRTDBG_MODE_FILE`|Grava a mensagem para um identificador de arquivo fornecido pelo usuário.  [\_CrtSetReportFile](../Topic/_CrtSetReportFile.md) deve ser chamado para definir o arquivo específico ou para passar para usar como o destino.|  
|`_CRTDBG_MODE_WNDW`|Cria uma caixa de mensagem para exibir a mensagem junto com `Abort`, `Retry`, e os botões de `Ignore` .|  
|`_CRTDBG_REPORT_MODE`|Retorna `reportMode` para `reportType`especificado:<br /><br /> 1   `_CRTDBG_MODE_FILE`<br /><br /> 2   `_CRTDBG_MODE_DEBUG`<br /><br /> 4   `_CRTDBG_MODE_WNDW`|  
  
 Cada tipo de relatório pode ser relatado não usar um, dois ou três modos, ou nenhum modo de todo.  Consequentemente, é possível ter mais de um destino definido para um único tipo de relatório.  Por exemplo, o seguinte fragmento de código a seguir causa falhas de asserção ser enviado a uma janela de mensagem de depuração e a `stderr`:  
  
```  
_CrtSetReportMode( _CRT_ASSERT, _CRTDBG_MODE_FILE | _CRTDBG_MODE_WNDW );  
_CrtSetReportFile( _CRT_ASSERT, _CRTDBG_FILE_STDERR );  
```  
  
 Além disso, o modo de relatório ou os modos para cada tipo de relatório podem ser controlados separada.  Por exemplo, é possível especificar que `reportType` de `_CRT_WARN` seja enviado a uma cadeia de caracteres de depuração de saída, quando `_CRT_ASSERT` é exibido usando uma janela da mensagem de depuração e enviado a `stderr`, como ilustrado anteriormente.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalho opcional|  
|------------|--------------------------|------------------------|  
|`_CrtSetReportMode`|\<crtdbg.h\>|\<errno.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
 **Bibliotecas:** Somente as versões de depuração das [Recursos da biblioteca CRT](../../c-runtime-library/crt-library-features.md).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)