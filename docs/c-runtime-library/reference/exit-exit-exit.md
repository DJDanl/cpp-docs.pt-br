---
title: exit, _Exit, _exit | Microsoft Docs
ms.custom: 
ms.date: 1/02/2018
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
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
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: ed4835662a53f3cb19b47818a9d6adfb3dfb2930
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="exit-exit-exit"></a>exit, _Exit, _exit

Encerra o processo de chamada. A função `exit` termina após a limpeza. `_exit` e `_Exit` encerram a função imediatamente.

> [!NOTE]
> Não use esse método para desligar um aplicativo do Windows UWP (plataforma Universal), exceto em teste ou cenários de depuração. Modos de interface do usuário ou por programação para fechar um aplicativo de repositório não são permitidos de acordo com o [políticas do Microsoft Store](/legal/windows/agreements/store-policies). Para obter mais informações, consulte [ciclo de vida do aplicativo de UWP](/windows/uwp/launch-resume/app-lifecycle). Para obter mais informações sobre aplicativos do Windows 10, consulte [Guias de instrução para aplicativos do Windows 10](http://go.microsoft.com/fwlink/p/?linkid=619133).

## <a name="syntax"></a>Sintaxe

```C
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

### <a name="parameters"></a>Parâmetros

_status_  
Código de status de saída.

## <a name="remarks"></a>Comentários

As funções `exit`, `_Exit` e `_exit` encerram o processo de chamada. A função `exit` chama destruidores para objetos de thread local, em seguida, chama — na ordem UEPS (último a entrar, primeiro a sair) — as funções que são registradas por `atexit` e `_onexit` e, em seguida, libera todos os buffers de arquivo antes de encerrar o processo. As funções `_Exit` e `_exit` encerram o processo sem destruir objetos de thread local ou processar as funções `atexit` ou `_onexit` e sem eliminação de buffers de fluxo.

Embora o `exit`, `_Exit` e `_exit` chamadas não retornam um valor, o valor em _status_ ficam disponíveis para o ambiente de host ou o processo de chamada em espera, se houver, depois que o processo foi encerrado. Normalmente, os conjuntos de chamador de _status_ valor como 0 para indicar uma saída normal ou algum outro valor para indicar um erro. O _status_ valor está disponível para o comando de lote de sistema operacional `ERRORLEVEL` e é representado por uma das duas constantes: `EXIT_SUCCESS`, que representa um valor de 0, ou `EXIT_FAILURE`, que representa um valor de 1.

As funções `exit`, `_Exit`, `_exit`, `quick_exit`, `_cexit` e `_c_exit` se comportam da seguinte maneira.

|Função|Descrição|
|--------------|-----------------|
|`exit`|Executa procedimentos completos de encerramento de biblioteca C, encerra o processo e fornece o código de status fornecido para o ambiente de host.|
|`_Exit`|Executa procedimentos mínimos de encerramento de biblioteca C, encerra o processo e fornece o código de status fornecido para o ambiente de host.|
|`_exit`|Executa procedimentos mínimos de encerramento de biblioteca C, encerra o processo e fornece o código de status fornecido para o ambiente de host.|
|`quick_exit`|Executa procedimentos rápidos de encerramento de biblioteca C, encerra o processo e fornece o código de status fornecido para o ambiente de host.|
|`_cexit`|Executa procedimentos completos de encerramento de biblioteca C e retorna ao chamador. Não encerra o processo.|
|`_c_exit`|Executa procedimentos mínimos de encerramento de biblioteca C e retorna ao chamador. Não encerra o processo.|

Quando você chama a função `exit`, `_Exit` ou `_exit`, os destruidores de quaisquer objetos temporários ou automáticos que existem no momento da chamada não são chamados. Um objeto automática é um objeto de local não-estático definido em uma função. Um objeto temporário é um objeto que é criado pelo compilador, como um valor retornado por uma chamada de função. Para destruir um objeto automático antes de chamar `exit`, `_Exit`, ou `_exit`, explicitamente chamar o destruidor para o objeto, como mostrado aqui:

```cpp
void last_fn() {}
    struct SomeClass {} myInstance{};
    // ...
    myInstance.~SomeClass(); // explicit destructor call
    exit(0);
}
```

Não use `DLL_PROCESS_ATTACH` para chamar `exit` de `DllMain`. Para sair do `DLLMain` funcionar, retornar `FALSE` de `DLL_PROCESS_ATTACH`.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|`exit`, `_Exit`, `_exit`|\<process.h> ou \<stdlib.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
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
