---
title: _cexit, _c_exit
ms.date: 11/04/2016
api_name:
- _c_exit
- _cexit
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
ms.openlocfilehash: aa25d73bef1d85adfed77ba926e2d381e02e45e8
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70939248"
---
# <a name="_cexit-_c_exit"></a>_cexit, _c_exit

Executa operações de limpeza e retorna sem encerrar o processo.

## <a name="syntax"></a>Sintaxe

```C
void _cexit( void );
void _c_exit( void );
```

## <a name="remarks"></a>Comentários

As chamadas de função **_cexit** , na ordem UEPS (última entrada, primeiro a sair), as funções registradas por **atexit** e **_onexit**. Em seguida, **_cexit** libera todos os buffers de e/s e fecha todos os fluxos abertos antes de retornar. **_c_exit** é o mesmo que **_exit** , mas retorna ao processo de chamada sem processar **atexit** ou **_onexit** ou liberar buffers de fluxo. O comportamento de **Exit**, **_exit**, **_cexit**e **_c_exit** é mostrado na tabela a seguir.

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

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_cexit**|\<process.h>|
|**_c_exit**|\<process.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[abort](abort.md)<br/>
[atexit](atexit.md)<br/>
[Funções _exec, _wexec](../../c-runtime-library/exec-wexec-functions.md)<br/>
[exit, _Exit, _exit](exit-exit-exit.md)<br/>
[_onexit, _onexit_m](onexit-onexit-m.md)<br/>
[Funções _spawn, _wspawn](../../c-runtime-library/spawn-wspawn-functions.md)<br/>
[system, _wsystem](system-wsystem.md)<br/>
