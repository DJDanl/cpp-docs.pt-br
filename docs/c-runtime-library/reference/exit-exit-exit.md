---
title: exit, _Exit, _exit
ms.date: 4/2/2020
api_name:
- _exit
- exit
- _o__exit
- _o_exit
api_location:
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
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- Exit
- _exit
- process/exit
- process/_Exit
- stdlib/exit
- stdlib/_Exit
helpviewer_keywords:
- exit function
- _exit function
- processes, terminating
- function calls, terminating
- process termination, calling
ms.openlocfilehash: a1c0eeaa6d66e91b913ce7940d37409fc4f6ac29
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82909669"
---
# <a name="exit-_exit-_exit"></a>exit, _Exit, _exit

Encerra o processo de chamada. A função **Exit** termina após a limpeza; **_exit** e **_Exit** finalizá-lo imediatamente.

> [!NOTE]
> Não use esse método para desligar um aplicativo Plataforma Universal do Windows (UWP), exceto em cenários de teste ou depuração. As maneiras programática ou de interface do usuário de fechar um aplicativo da loja não são permitidas de acordo com as [políticas de Microsoft Store](/legal/windows/agreements/store-policies). Para obter mais informações, consulte [ciclo de vida do aplicativo UWP](/windows/uwp/launch-resume/app-lifecycle). Para obter mais informações sobre aplicativos do Windows 10, consulte [Guias de instrução para aplicativos do Windows 10](https://developer.microsoft.com/windows/apps).

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

*status*<br/>
Código de status de saída.

## <a name="remarks"></a>Comentários

As funções **Exit**, **_Exit** e **_exit** encerram o processo de chamada. A função **Exit** chama destruidores para objetos de thread local e, em seguida, chama – na ordem UEPS (último a entrar, primeiro a sair) — as funções registradas por **atexit** e **_onexit**e, em seguida, libera todos os buffers de arquivo antes de finalizar o processo. As funções **_Exit** e **_exit** encerram o processo sem destruir objetos locais de thread ou processar funções **atexit** ou **_onexit** e sem liberar buffers de fluxo.

Embora as chamadas **Exit**, **_Exit** e **_exit** não retornem um valor, o valor no *status* é disponibilizado para o ambiente de host ou aguardando o processo de chamada, se houver um, após o processo sair. Normalmente, o chamador define o valor de *status* como 0 para indicar uma saída normal ou para algum outro valor para indicar um erro. O valor de *status* está disponível para o **ERRORLEVEL** do comando do sistema operacional e é representado por uma das duas constantes: **EXIT_SUCCESS**, que representa um valor de 0, ou **EXIT_FAILURE**, que representa um valor de 1.

As funções **Exit**, **_Exit**, **_exit**, **quick_exit**, **_cexit**e **_c_exit** se comportam da seguinte maneira.

|Função|Descrição|
|--------------|-----------------|
|**exit**|Executa procedimentos completos de encerramento de biblioteca C, encerra o processo e fornece o código de status fornecido para o ambiente de host.|
|**_Exit**|Executa procedimentos mínimos de encerramento de biblioteca C, encerra o processo e fornece o código de status fornecido para o ambiente de host.|
|**_exit**|Executa procedimentos mínimos de encerramento de biblioteca C, encerra o processo e fornece o código de status fornecido para o ambiente de host.|
|**quick_exit**|Executa procedimentos rápidos de encerramento de biblioteca C, encerra o processo e fornece o código de status fornecido para o ambiente de host.|
|**_cexit**|Executa procedimentos completos de encerramento de biblioteca C e retorna ao chamador. Não encerra o processo.|
|**_c_exit**|Executa procedimentos mínimos de encerramento de biblioteca C e retorna ao chamador. Não encerra o processo.|

Quando você chama a função **Exit**, **_Exit** ou **_exit** , os destruidores para todos os objetos temporários ou automáticos existentes no momento da chamada não são chamados. Um objeto automático é um objeto local não estático definido em uma função. Um objeto temporário é um objeto que é criado pelo compilador, como um valor retornado por uma chamada de função. Para destruir um objeto automático antes de chamar **Exit**, **_Exit**ou **_exit**, chame explicitamente o destruidor para o objeto, como mostrado aqui:

```cpp
void last_fn() {}
    struct SomeClass {} myInstance{};
    // ...
    myInstance.~SomeClass(); // explicit destructor call
    exit(0);
}
```

Não use **DLL_PROCESS_ATTACH** para chamar **Exit** de **DllMain**. Para sair da função **DllMain** , retorne **false** de **DLL_PROCESS_ATTACH**.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**sair**, **_Exit**, **_exit**|\<process.h> ou \<stdlib.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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

## <a name="see-also"></a>Confira também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[anular](abort.md)<br/>
[atexit](atexit.md)<br/>
[_cexit, _c_exit](cexit-c-exit.md)<br/>
[Funções _exec, _wexec](../../c-runtime-library/exec-wexec-functions.md)<br/>
[_onexit, _onexit_m](onexit-onexit-m.md)<br/>
[quick_exit](quick-exit1.md)<br/>
[Funções _spawn, _wspawn](../../c-runtime-library/spawn-wspawn-functions.md)<br/>
[system, _wsystem](system-wsystem.md)<br/>
