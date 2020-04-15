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
- api-ms-win-crt-private-l1-1-0
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
ms.openlocfilehash: 9eb856efca054423465aa7d30092edaf83a65eeb
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81333526"
---
# <a name="_cexit-_c_exit"></a>_cexit, _c_exit

Executa operações de limpeza e retorna sem encerrar o processo.

## <a name="syntax"></a>Sintaxe

```C
void _cexit( void );
void _c_exit( void );
```

## <a name="remarks"></a>Comentários

A **função _cexit** chama, em última entrada, ordem de primeira saída (LIFO), as funções registradas pelo **atexit** e **_onexit**. Em **seguida, _cexit** lava todos os buffers de I/O e fecha todos os fluxos abertos antes de retornar. **_c_exit** é o mesmo **que _exit,** mas retorna ao processo de chamada sem processar **o ATExit** ou **_onexit** ou os buffers de fluxo de descarga. O comportamento de **saída,** **_exit,** **_cexit**e **_c_exit** é mostrado na tabela a seguir.

|Função|Comportamento|
|--------------|--------------|
|**Saída**|Executa procedimentos completos de encerramento de biblioteca C, encerra o processo e sai com código de status fornecido.|
|**_exit**|Executa procedimentos rápidos de encerramento de biblioteca C, encerra o processo e sai com código de status fornecido.|
|**_cexit**|Executa procedimentos completos de encerramento de biblioteca C e retorna ao chamador, mas não encerra o processo.|
|**_c_exit**|Executa procedimentos rápidos de encerramento de biblioteca C e retorna ao chamador, mas não encerra o processo.|

Quando você chama as funções **_cexit** ou **_c_exit,** os destruidores de quaisquer objetos temporários ou automáticos que existem no momento da chamada não são chamados. Um objeto automático é um objeto definido em uma função na qual o objeto não é declarado como estático. Um objeto temporário é um objeto criado pelo compilador. Para destruir um objeto automático antes de chamar **_cexit** ou **_c_exit,** chame explicitamente o destruidor para o objeto, da seguinte forma:

```cpp
myObject.myClass::~myClass( );
```

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_cexit**|\<process.h>|
|**_c_exit**|\<process.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[Abortar](abort.md)<br/>
[atexit](atexit.md)<br/>
[Funções _exec, _wexec](../../c-runtime-library/exec-wexec-functions.md)<br/>
[exit, _Exit, _exit](exit-exit-exit.md)<br/>
[_onexit, _onexit_m](onexit-onexit-m.md)<br/>
[Funções _spawn, _wspawn](../../c-runtime-library/spawn-wspawn-functions.md)<br/>
[system, _wsystem](system-wsystem.md)<br/>
