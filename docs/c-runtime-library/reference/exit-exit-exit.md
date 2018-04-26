---
title: exit, _Exit, _exit | Microsoft Docs
ms.custom: ''
ms.date: 1/02/2018
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
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
ms.openlocfilehash: e682d10fe15b611ff9ceb363d7d8593e41f386d6
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="exit-exit-exit"></a>exit, _Exit, _exit

Encerra o processo de chamada. O **sair** função termina após a limpeza; **exit** e **exit** terminá-lo imediatamente.

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

*status* código de status de saída.

## <a name="remarks"></a>Comentários

O **sair**, **exit** e **exit** funções encerrar o processo de chamada. O **sair** função chama destruidores para objetos de thread local, em seguida, chama — na ordem do último a entrar, primeiro a sair (UEPS) — as funções que são registradas por **atexit** e **OnExit**e, em seguida, libera todos os buffers de arquivo antes de ele encerra o processo. O **exit** e **exit** funções terminar o processo sem destruir os objetos de local de thread ou processamento **atexit** ou **OnExit**funções e sem eliminação de buffers de fluxo.

Embora o **sair**, **exit** e **exit** chamadas não retornam um valor, o valor em *status* é disponibilizada para o ambiente de host ou aguardando o processo de chamada, se houver, depois que o processo foi encerrado. Normalmente, os conjuntos de chamador de *status* valor como 0 para indicar uma saída normal ou algum outro valor para indicar um erro. O *status* valor está disponível para o comando de lote de sistema operacional **ERRORLEVEL** e é representado por uma das duas constantes: **EXIT_SUCCESS**, que representa um valor 0, ou **EXIT_FAILURE**, que representa um valor de 1.

O **sair**, **exit**, **exit**, **quick_exit**, **cexit**, e **c_exit** funções se comportam da seguinte maneira.

|Função|Descrição|
|--------------|-----------------|
|**exit**|Executa procedimentos completos de encerramento de biblioteca C, encerra o processo e fornece o código de status fornecido para o ambiente de host.|
|**_Exit**|Executa procedimentos mínimos de encerramento de biblioteca C, encerra o processo e fornece o código de status fornecido para o ambiente de host.|
|**_exit**|Executa procedimentos mínimos de encerramento de biblioteca C, encerra o processo e fornece o código de status fornecido para o ambiente de host.|
|**quick_exit**|Executa procedimentos rápidos de encerramento de biblioteca C, encerra o processo e fornece o código de status fornecido para o ambiente de host.|
|**_cexit**|Executa procedimentos completos de encerramento de biblioteca C e retorna ao chamador. Não encerra o processo.|
|**_c_exit**|Executa procedimentos mínimos de encerramento de biblioteca C e retorna ao chamador. Não encerra o processo.|

Quando você chama o **sair**, **exit** ou **exit** função destruidores para objetos temporários ou automática que existem no momento da chamada não forem chamados. Um objeto automática é um objeto de local não-estático definido em uma função. Um objeto temporário é um objeto que é criado pelo compilador, como um valor retornado por uma chamada de função. Para destruir um objeto automático antes de chamar **sair**, **exit**, ou **exit**, explicitamente chamar o destruidor para o objeto, como mostrado aqui:

```cpp
void last_fn() {}
    struct SomeClass {} myInstance{};
    // ...
    myInstance.~SomeClass(); // explicit destructor call
    exit(0);
}
```

Não use **DLL_PROCESS_ATTACH** chamar **sair** de **DllMain**. Para sair do **DLLMain** funcionar, retornar **FALSE** de **DLL_PROCESS_ATTACH**.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**sair**, **exit**, **Exit**|\<process.h> ou \<stdlib.h>|

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

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[abort](abort.md)<br/>
[atexit](atexit.md)<br/>
[_cexit, _c_exit](cexit-c-exit.md)<br/>
[Funções _exec, _wexec](../../c-runtime-library/exec-wexec-functions.md)<br/>
[_onexit, _onexit_m](onexit-onexit-m.md)<br/>
[quick_exit](quick-exit1.md)<br/>
[Funções _spawn, _wspawn](../../c-runtime-library/spawn-wspawn-functions.md)<br/>
[system, _wsystem](system-wsystem.md)<br/>
