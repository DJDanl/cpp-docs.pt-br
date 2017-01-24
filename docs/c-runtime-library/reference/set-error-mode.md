---
title: "_set_error_mode | Microsoft Docs"
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
  - "_set_error_mode"
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
  - "set_error_mode"
  - "_set_error_mode"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _set_error_mode"
  - "Função set_error_mode"
ms.assetid: f0807be5-73d1-4a32-a701-3c9bdd139c5c
caps.latest.revision: 21
caps.handback.revision: 19
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _set_error_mode
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Modifica `__error_mode` para determinar um local não padrão em que o tempo de execução C grava uma mensagem de erro para um erro que pode finalizar o programa.  
  
> [!IMPORTANT]
>  Essa API não pode ser usada em aplicativos executados no [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  Para obter mais informações, consulte [Funções de CRT sem suporte com \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
int _set_error_mode(  
   int modeval   
);  
```  
  
#### Parâmetros  
 `modeval`  
 Destino das mensagens de erro.  
  
## Valor de retorno  
 Retorna a configuração antiga ou \-1 se ocorrer um erro.  
  
## Comentários  
 Controla o coletor de saída de erro ao definir o valor de `__error_mode`.  Por exemplo, você pode direcionar a saída para um erro padrão ou usar o `MessageBox` API.  
  
 O `modeval` parâmetro pode ser definido como um dos valores a seguir.  
  
|Parâmetro|Descrição|  
|---------------|---------------|  
|`_OUT_TO_DEFAULT`|Coletor de erros é determinado pelo `__app_type`.|  
|`_OUT_TO_STDERR`|Coletor de erro é um erro padrão.|  
|`_OUT_TO_MSGBOX`|Coletor de erros é uma caixa de mensagem.|  
|`_REPORT_ERRMODE`|Relatório atual `__error_mode` valor.|  
  
 Se um valor que não sejam os listados for passado, o manipulador de parâmetro inválido é chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar,`_set_error_mode` define `errno` para `EINVAL` e retorna \-1.  
  
 Quando ele é usado com um [assert](../../c-runtime-library/reference/assert-macro-assert-wassert.md), `_set_error_mode` exibe a instrução com falha na caixa de diálogo e lhe dá a opção de escolher o `Ignore` botão para que você pode continuar a executar o programa.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_set_error_mode`|\<stdlib.h\>|  
  
## Exemplo  
  
```  
// crt_set_error_mode.c  
// compile with: /c  
#include <stdlib.h>  
#include <assert.h>  
  
int main()  
{  
   _set_error_mode(_OUT_TO_STDERR);  
   assert(2+2==5);  
}  
```  
  
  **Falha de asserção: 2 \+ 2 \= \= 5, crt\_set\_error\_mode.c de arquivo, linha 8**  
**Este aplicativo solicitou o tempo de execução terminasse de maneira incomum.  Entre em contato com a equipe de suporte do aplicativo para obter mais informações.**    
## Consulte também  
 [Macro Assert, \_wassert de declaração](../../c-runtime-library/reference/assert-macro-assert-wassert.md)