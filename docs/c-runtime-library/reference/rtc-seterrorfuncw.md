---
title: "_RTC_SetErrorFuncW | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_RTC_SetErrorFuncW"
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
  - "_RTC_SetErrorFuncW"
  - "RTC_SetErrorFuncW"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "erros de tempo de execução"
  - "Função RTC_SetErrorFuncW"
  - "_RTC_error_fnW (typedefs)"
  - "Função _RTC_SetErrorFuncW"
  - "RTC_error_fnW (typedefs)"
ms.assetid: b3e0d71f-1bd3-4c37-9ede-2f638eb3c81a
caps.latest.revision: 15
caps.handback.revision: 15
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _RTC_SetErrorFuncW
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Designa uma função como o manipulador para a emissão de relatórios de verificações de erro em tempo de execução \(RTCs\).  
  
## Sintaxe  
  
```  
  
_RTC_error_fnW _RTC_SetErrorFuncW(  
   _RTC_error_fnW  
 function   
);  
  
```  
  
#### Parâmetros  
 `function`  
 O endereço da função que manipulará verificações de erro em tempo de execução.  
  
## Valor de retorno  
 A função de erro definido anteriormente. ou `NULL` se não houver nenhuma função definida anteriormente.  
  
## Comentários  
 No novo código, use apenas `_RTC_SetErrorFuncW`.`_RTC_SetErrorFunc` só é incluída na biblioteca para compatibilidade com versões anteriores.  
  
 O `_RTC_SetErrorFuncW` retorno de chamada se aplica somente ao componente que ele estava vinculado, mas não globalmente.  
  
 Verifique se o endereço que você passa para `_RTC_SetErrorFuncW` é que uma função de tratamento de erros válido.  
  
 Se um erro foi atribuído um tipo de\-1 usando [RTC\_SetErrorType](../Topic/_RTC_SetErrorType.md), o função de manipulação de erro não é chamado.  
  
 Antes de chamar essa função, você deve chamar uma das funções de inicialização de verificação de erro de tempo de execução. Para obter mais informações, consulte [Usando verificações de tempo de execução sem a biblioteca em tempo de execução do C](../Topic/Using%20Run-Time%20Checks%20Without%20the%20C%20Run-Time%20Library.md).  
  
 **\_RTC\_error\_fnW** é definida da seguinte maneira:  
  
 **TypeDef int \( cdecl \* \_RTC\_error\_fnW\) \(int**  `errorType` **, const wchar\_t \*** *nome de arquivo* **, int**  *LineNumber* **, const wchar\_t \*** `moduleName` **, const wchar\_t \*** *formato* **, ...\);**  
  
 onde:  
  
 `errorType`  
 O tipo de erro que é especificado pelo [RTC\_SetErrorType](../Topic/_RTC_SetErrorType.md).  
  
 *nome de arquivo*  
 O arquivo de origem onde a falha ocorreu, ou nulo se nenhuma informação de depuração está disponível.  
  
 *LineNumber*  
 A linha *filename* onde a falha ocorreu, ou 0 se não há informações de depuração.  
  
 `moduleName`  
 A DLL ou o nome do executável onde a falha ocorreu.  
  
 *formato*  
 cadeia de estilo printf para exibir uma mensagem de erro, usando os parâmetros restantes. O primeiro argumento do VA\_ARGLIST é o número de erro RTC que ocorreu.  
  
 Para obter um exemplo que mostra como usar **\_RTC\_error\_fnW**, consulte [Personalização das verificações de tempo de execução nativas](../Topic/Native%20Run-Time%20Checks%20Customization.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_RTC_SetErrorFuncW`|\< rtcapi.h \>|  
  
 Para obter mais informações, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Libraries  
 Todas as versões do [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [\_CrtDbgReport, \_CrtDbgReportW](../../c-runtime-library/reference/crtdbgreport-crtdbgreportw.md)   
 [Verificação de erros de tempo de execução](../Topic/Run-Time%20Error%20Checking.md)