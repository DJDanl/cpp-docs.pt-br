---
title: "_set_abort_behavior | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_set_abort_behavior"
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
  - "_set_abort_behavior"
  - "set_abort_behavior"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _set_abort_behavior"
  - "anulando programas"
  - "Função set_abort_behavior"
ms.assetid: 43918766-e4ba-4b1f-80e8-1a4a910cd452
caps.latest.revision: 26
caps.handback.revision: 24
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _set_abort_behavior
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Especifica a ação a ser realizada quando um programa é encerrado de maneira anormal.  
  
> [!NOTE]
>  Não use a função `abort` para desligar um aplicativo [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)], exceto em cenários de teste e de depuração.  As maneiras programáticas ou de interface de usuário de fechar um aplicativo do [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] não são permitidas de acordo com os [Requisitos de certificação de aplicativo do Windows 8](http://go.microsoft.com/fwlink/?LinkId=262889).  Para obter mais informações, consulte [Ciclo de vida do aplicativo \(aplicativos da Windows Store\)](http://go.microsoft.com/fwlink/?LinkId=262853).  
  
## Sintaxe  
  
```  
unsigned int _set_abort_behavior(  
   unsigned int flags,  
   unsigned int mask  
);  
```  
  
#### Parâmetros  
 \[entrada\] `flags`  
 O novo valor dos sinalizadores `abort`.  
  
 \[entrada\] `mask`  
 Mascara para os bits de sinalizadores `abort` a serem definidos.  
  
## Valor de retorno  
 O valor antigo dos sinalizadores.  
  
## Comentários  
 Existem dois sinalizadores `abort`: `_WRITE_ABORT_MSG` e `_CALL_REPORTFAULT`.  `_WRITE_ABORT_MSG` determina se uma mensagem de texto útil é impressa quando um programa é encerrado anormalmente.  A mensagem indica que o aplicativo chama a função `abort`.  O comportamento padrão é imprimir a mensagem.  `_CALL_REPORTFAULT`, se definido, especifica que um despejo de memória de Watson é gerado e relatado quando `abort` é chamado.  Por padrão, o relatório de despejo de memória é ativado em compilações de não DEPURAÇÃO.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_set_abort_behavior`|\<stdlib.h\>|  
  
 Para obter mais informações de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```c  
// crt_set_abort_behavior.c  
// compile with: /TC  
#include <stdlib.h>  
  
int main()  
{  
   printf("Suppressing the abort message. If successful, this message"  
          " will be the only output.\n");  
   // Suppress the abort message  
   _set_abort_behavior( 0, _WRITE_ABORT_MSG);  
   abort();  
}  
```  
  
  **Suprimindo a mensagem de anulação.  Se tiver êxito, esta mensagem será a única saída.**    
## Consulte também  
 [abort](../../c-runtime-library/reference/abort.md)