---
title: quick_exit1 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname: quick_exit
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
- quick_exit
- process/quick_exit
- stdlib/quick_exit
dev_langs: C++
helpviewer_keywords: quick_exit function
ms.assetid: ecfbdae6-01c4-45fa-aaeb-b368e1de2a9c
caps.latest.revision: "3"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: d2ae187d0132ca53b1ffba2b26ef18fa467b9072
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="quickexit"></a>quick_exit
Causa o término normal do programa.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
__declspec(noreturn) void quick_exit(  
    int status  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 status  
 O código de status para retornar para o ambiente de host.  
  
## <a name="return-value"></a>Valor de retorno  
 A função `quick_exit` não pode retornar para seu chamador.  
  
## <a name="remarks"></a>Comentários  
 A função `quick_exit` causa o término normal do programa. Ela não chama nenhuma função registrada por `atexit`, `_onexit` nem manipuladores de sinal registrados pela função `signal`. O comportamento será indefinido se `quick_exit` for chamado mais de uma vez ou se a função `exit` também for chamada.  
  
 A função `quick_exit` chama, na ordem UEPS (último a entrar, primeiro a sair), as funções registradas pelo `at_quick_exit`, exceto para aquelas funções já chamadas quando a função foi registrada.  O comportamento será indefinido se uma chamada [longjmp](../../c-runtime-library/reference/longjmp.md) for realizada durante uma chamada para uma função registrada que terminaria a chamada para a função.  
  
 Depois que as funções registradas foram chamadas, `quick_exit` invoca `_Exit` usando o valor `status` para retornar o controle para o ambiente de host.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`quick_exit`|\<process.h> ou \<stdlib.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [abort](../../c-runtime-library/reference/abort.md)   
 [atexit](../../c-runtime-library/reference/atexit.md)   
 [Funções _exec, _wexec](../../c-runtime-library/exec-wexec-functions.md)   
 [exit, _Exit, _exit](../../c-runtime-library/reference/exit-exit-exit.md)   
 [_onexit, _onexit_m](../../c-runtime-library/reference/onexit-onexit-m.md)   
 [Funções _spawn, _wspawn](../../c-runtime-library/spawn-wspawn-functions.md)   
 [system, _wsystem](../../c-runtime-library/reference/system-wsystem.md)