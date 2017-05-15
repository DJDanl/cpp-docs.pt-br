---
title: exit, _Exit, _exit | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _exit
- exit
apilocation:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
- api-ms-win-crt-runtime-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- Exit
- _exit
- process/exit
- process/_Exit
- stdlib/exit
- stdlib/_Exit
dev_langs:
- C++
helpviewer_keywords:
- exit function
- _exit function
- processes, terminating
- function calls, terminating
- process termination, calling
ms.assetid: b1501fa6-27c2-478c-9e93-cc4fd802a01f
caps.latest.revision: 17
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
ms.translationtype: Machine Translation
ms.sourcegitcommit: e257f037a05c45f5b98e64ea55bd125af443b0be
ms.openlocfilehash: 8d6f75bb19c2cfd89d8714ed87ff91ddf340055e
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="exit-exit-exit"></a>exit, _Exit, _exit
Encerra o processo de chamada. A função `exit` termina após a limpeza. `_exit` e `_Exit` encerram a função imediatamente.  
  
> [!NOTE]
>  Não use esse método para desligar um aplicativo UWP (Plataforma Universal do Windows) ou um aplicativo [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)], exceto em cenários de teste ou depuração. Modos de programação ou da interface do usuário para fechar um aplicativo [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] não são permitidos. Para obter mais informações sobre aplicativos do Windows 8 e 8.1, consulte [Ciclo de vida do aplicativo](http://go.microsoft.com/fwlink/?LinkId=262853). Para obter mais informações sobre aplicativos do Windows 10, consulte [Guias de instrução para aplicativos do Windows 10](http://go.microsoft.com/fwlink/p/?linkid=619133).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void exit(   
   int const status   
);  
void _Exit(   
   int const status   
);  
void _exit(   
   int const status   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `status`  
 Código de status de saída.  
  
## <a name="remarks"></a>Comentários  
 As funções `exit`, `_Exit` e `_exit` encerram o processo de chamada. A função `exit` chama destruidores para objetos de thread local, em seguida, chama — na ordem UEPS (último a entrar, primeiro a sair) — as funções que são registradas por `atexit` e `_onexit` e, em seguida, libera todos os buffers de arquivo antes de encerrar o processo. As funções `_Exit` e `_exit` encerram o processo sem destruir objetos de thread local ou processar as funções `atexit` ou `_onexit` e sem eliminação de buffers de fluxo.  
  
 Embora as chamadas `exit`, `_Exit` e `_exit` não retornem um valor, o byte de ordem inferior de `status` é disponibilizado para o ambiente de host ou o processo de chamada em espera, se houver, depois que o processo é encerrado. Normalmente, o chamador define o valor `status` como 0 para indicar uma saída normal ou para algum outro valor para indicar um erro. O valor `status` está disponível para o comando em lote do sistema operacional `ERRORLEVEL` e é representado por uma das duas constantes: `EXIT_SUCCESS`, que representa um valor de 0 ou `EXIT_FAILURE`, que representa um valor de 1.  
  
 As funções `exit`, `_Exit`, `_exit`, `quick_exit`, `_cexit` e `_c_exit` se comportam da seguinte maneira.  
  
|Função|Descrição|  
|--------------|-----------------|  
|`exit`|Executa procedimentos completos de encerramento de biblioteca C, encerra o processo e fornece o código de status fornecido para o ambiente de host.|  
|`_Exit`|Executa procedimentos mínimos de encerramento de biblioteca C, encerra o processo e fornece o código de status fornecido para o ambiente de host.|  
|`_exit`|Executa procedimentos mínimos de encerramento de biblioteca C, encerra o processo e fornece o código de status fornecido para o ambiente de host.|  
|`quick_exit`|Executa procedimentos rápidos de encerramento de biblioteca C, encerra o processo e fornece o código de status fornecido para o ambiente de host.|  
|`_cexit`|Executa procedimentos completos de encerramento de biblioteca C e retorna ao chamador. Não encerra o processo.|  
|`_c_exit`|Executa procedimentos mínimos de encerramento de biblioteca C e retorna ao chamador. Não encerra o processo.|  
  
 Quando você chama a função `exit`, `_Exit` ou `_exit`, os destruidores de quaisquer objetos temporários ou automáticos que existem no momento da chamada não são chamados. Um objeto automático é definido em uma função na qual o objeto não é declarado como estático. Um objeto temporário é um objeto que é criado pelo compilador. Para destruir um objeto automático antes de chamar `exit`, `_Exit` ou `_exit`, chame explicitamente o destruidor do objeto, da seguinte maneira:  
  
```  
myObject.myClass::~myClass();  
```  
  
 Não use `DLL_PROCESS_ATTACH` para chamar `exit` de `DllMain`. Se desejar sair da função `DLLMain`, retorne `FALSE` de `DLL_PROCESS_ATTACH`.  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho necessário|  
|--------------|---------------------|  
|`exit`, `_Exit`, `_exit`|\<process.h> ou \<stdlib.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_exit.c  
// This program returns an exit code of 1. The  
// error code could be tested in a batch file.  
  
#include <stdlib.h>  
  
int main( void )  
{  
   exit( 1 );  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [abort](../../c-runtime-library/reference/abort.md)   
 [atexit](../../c-runtime-library/reference/atexit.md)   
 [_cexit, _c_exit](../../c-runtime-library/reference/cexit-c-exit.md)   
 [Funções _exec, _wexec](../../c-runtime-library/exec-wexec-functions.md)   
 [_onexit, _onexit_m](../../c-runtime-library/reference/onexit-onexit-m.md)   
 [quick_exit](../../c-runtime-library/reference/quick-exit1.md)   
 [Funções _spawn, _wspawn](../../c-runtime-library/spawn-wspawn-functions.md)   
 [system, _wsystem](../../c-runtime-library/reference/system-wsystem.md)
