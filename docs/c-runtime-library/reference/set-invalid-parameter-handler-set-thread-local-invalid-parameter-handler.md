---
title: "set_invalid_parameter_handler, _set_thread_local_invalid_parameter_handler | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_set_invalid_parameter_handler"
  - "_set_thread_local_invalid_parameter_handler"
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
  - "api-ms-win-crt-runtime-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "set_invalid_parameter_handler"
  - "_set_invalid_parameter_handler"
  - "_set_thread_local_invalid_parameter_handler"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "manipulador de parâmetro inválido"
  - "Função set_invalid_parameter_handler"
  - "Função _set_invalid_parameter_handler"
  - "função _set_thread_local_invalid_parameter_handler"
ms.assetid: c0e67934-1a41-4016-ad8e-972828f3ac11
caps.latest.revision: 27
caps.handback.revision: 27
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# set_invalid_parameter_handler, _set_thread_local_invalid_parameter_handler
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Define uma função a ser chamada quando o CRT detecta um argumento inválido.  
  
## Sintaxe  
  
```  
_invalid_parameter_handler _set_invalid_parameter_handler(  
   _invalid_parameter_handler pNew  
);  
_invalid_parameter_handler _set_thread_local_invalid_parameter_handler(  
   _invalid_parameter_handler pNew  
);  
```  
  
#### Parâmetros  
 \[in\] `pNew`  
 O ponteiro de função para o novo manipulador de parâmetro inválido.  
  
## Valor de retorno  
 Um ponteiro para o manipulador de parâmetro inválido antes da chamada.  
  
## Comentários  
 Muitas funções de tempo de execução C verificam a validade dos argumentos passados para eles. Se um argumento inválido for passado, a função pode definir o `errno` número do erro ou retornar um código de erro. Nesses casos, o manipulador de parâmetro inválido também é chamado. O tempo de execução do C fornece um manipulador de parâmetro inválido global padrão que encerra o programa e exibe uma mensagem de erro de tempo de execução. Você pode usar o `_set_invalid_parameter_handler` para definir sua própria função como o manipulador de parâmetro inválido global. O tempo de execução C também oferece suporte a um manipulador de parâmetro inválido de thread local. Se um manipulador de parâmetro de thread local é definido em um thread usando `_set_thread_local_invalid_parameter_handler`, as funções de tempo de execução C chamadas do thread de usarem esse manipulador em vez do manipulador global. Apenas uma função pode ser especificada como o manipulador de argumento inválido global por vez. Apenas uma função pode ser especificada como o manipulador de argumento inválido de thread local por thread, mas os threads diferentes podem ter diferentes manipuladores de thread local. Isso permite que você altere o manipulador usado em uma parte do seu código sem afetar o comportamento de outros threads.  
  
 Quando o tempo de execução chama a função de parâmetro inválido, isso normalmente significa que ocorreu um erro irrecuperável. A função do manipulador de parâmetro inválido fornecido deve salvar quaisquer dados que podem e, em seguida, anular. Ele não deve retornar o controle para a função principal se tiver certeza de que o erro recuperável.  
  
 A função de manipulador de parâmetro inválido deve ter o seguinte protótipo:  
  
```c  
void _invalid_parameter(  
   const wchar_t * expression,  
   const wchar_t * function,   
   const wchar_t * file,   
   unsigned int line,  
   uintptr_t pReserved  
);  
```  
  
 O `expression` argumento é uma representação de cadeia de caracteres larga da expressão do argumento que gerou o erro. O `function` argumento é o nome da função CRT que recebeu o argumento inválido. O `file` argumento é o nome do arquivo de origem CRT que contém a função. O `line` é o número da linha no arquivo. O último argumento é reservado. Os parâmetros todos têm o valor `NULL` a menos que uma versão de depuração da biblioteca CRT é usada.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_set_invalid_parameter_handler`, `_set_thread_local_invalid_parameter_handler`|C: \< stdlib. h \><br /><br /> C\+\+: \< cstdlib \> ou \< stdlib. h \>|  
  
 O `_set_invalid_parameter_handler` e `_set_thread_local_invalid_parameter_handler` funções são específicas da Microsoft. Para informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
 No exemplo a seguir, um manipulador de erro de parâmetro inválido é usado para imprimir a função que recebeu o parâmetro inválido e o arquivo e a linha em fontes de CRT. Quando a biblioteca de depuração CRT é usada, erros de parâmetro inválido também geram uma asserção, que é desabilitada usando este exemplo [\_CrtSetReportMode](../../c-runtime-library/reference/crtsetreportmode.md).  
  
```c  
// crt_set_invalid_parameter_handler.c  
// compile with: /Zi /MTd  
#include <stdio.h>  
#include <stdlib.h>  
#include <crtdbg.h>  // For _CrtSetReportMode  
  
void myInvalidParameterHandler(const wchar_t* expression,  
   const wchar_t* function,   
   const wchar_t* file,   
   unsigned int line,   
   uintptr_t pReserved)  
{  
   wprintf(L"Invalid parameter detected in function %s."  
            L" File: %s Line: %d\n", function, file, line);  
   wprintf(L"Expression: %s\n", expression);  
   abort();  
}  
  
int main( )  
{  
   char* formatString;  
  
   _invalid_parameter_handler oldHandler, newHandler;  
   newHandler = myInvalidParameterHandler;  
   oldHandler = _set_invalid_parameter_handler(newHandler);  
  
   // Disable the message box for assertions.  
   _CrtSetReportMode(_CRT_ASSERT, 0);  
  
   // Call printf_s with invalid parameters.  
  
   formatString = NULL;  
   printf(formatString);  
}  
```  
  
```Output  
Parâmetro inválido detectado na função common_vfprintf. Arquivo: minkernel\crts\ucrt\src\appcrt\stdio\output.cpp linha: expressão 32: formato! = nullptr  
```  
  
## Consulte também  
 [\_get\_invalid\_parameter\_handler, \_get\_thread\_local\_invalid\_parameter\_handler](../../c-runtime-library/reference/get-invalid-parameter-handler-get-thread-local-invalid-parameter-handler.md)   
 [Versões aprimoradas de segurança de funções CRT](../../c-runtime-library/security-enhanced-versions-of-crt-functions.md)   
 [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md)