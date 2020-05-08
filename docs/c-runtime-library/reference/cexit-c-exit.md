---
title: _cexit, _c_exit
ms.date: 4/2/2020
api_name:
- _c_exit
- _cexit
- _o__cexit
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
- _cexit
- c_exit
- _c_exit
- cexit
helpviewer_keywords:
- cleanup operations during processes
- cexit function
- _c_exit function
- _cexit function
- c_exit function
ms.assetid: f3072045-9924-4b1a-9fef-b0dcd6d12663
ms.openlocfilehash: 78675ef91c2ab68e18f6111b4908886017ae1f79
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82917142"
---
# <a name="_cexit-_c_exit"></a>_cexit, _c_exit

Executa operações de limpeza e retorna sem encerrar o processo.

## <a name="syntax"></a>Sintaxe

```C
void _cexit( void );
void _c_exit( void );
```

## <a name="remarks"></a>Comentários

O **_cexit** chamadas de função, na ordem UEPS (último a entrar, primeiro a sair), as funções registradas por **atexit** e **_onexit**. Em seguida, **_cexit** libera todos os buffers de e/s e fecha todos os fluxos abertos antes de retornar. **_c_exit** é o mesmo que **_exit** , mas retorna ao processo de chamada sem processar **atexit** ou **_onexit** ou liberar buffers de fluxo. O comportamento de **Exit**, **_exit**, **_cexit**e **_c_exit** é mostrado na tabela a seguir.

|Função|Comportamento|
|--------------|--------------|
|**exit**|Executa procedimentos completos de encerramento de biblioteca C, encerra o processo e sai com código de status fornecido.|
|**_exit**|Executa procedimentos rápidos de encerramento de biblioteca C, encerra o processo e sai com código de status fornecido.|
|**_cexit**|Executa procedimentos completos de encerramento de biblioteca C e retorna ao chamador, mas não encerra o processo.|
|**_c_exit**|Executa procedimentos rápidos de encerramento de biblioteca C e retorna ao chamador, mas não encerra o processo.|

Quando você chama as funções **_cexit** ou **_c_exit** , os destruidores para todos os objetos temporários ou automáticos existentes no momento da chamada não são chamados. Um objeto automático é um objeto definido em uma função na qual o objeto não é declarado como estático. Um objeto temporário é um objeto criado pelo compilador. Para destruir um objeto automático antes de chamar **_cexit** ou **_c_exit**, chame explicitamente o destruidor para o objeto, da seguinte maneira:

```cpp
myObject.myClass::~myClass( );
```

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_cexit**|\<process.h>|
|**_c_exit**|\<process.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[anular](abort.md)<br/>
[atexit](atexit.md)<br/>
[Funções _exec, _wexec](../../c-runtime-library/exec-wexec-functions.md)<br/>
[exit, _Exit, _exit](exit-exit-exit.md)<br/>
[_onexit, _onexit_m](onexit-onexit-m.md)<br/>
[Funções _spawn, _wspawn](../../c-runtime-library/spawn-wspawn-functions.md)<br/>
[system, _wsystem](system-wsystem.md)<br/>
