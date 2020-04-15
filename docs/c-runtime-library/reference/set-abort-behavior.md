---
title: _set_abort_behavior
ms.date: 4/2/2020
api_name:
- _set_abort_behavior
- _o__set_abort_behavior
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
- _set_abort_behavior
- set_abort_behavior
helpviewer_keywords:
- aborting programs
- _set_abort_behavior function
- set_abort_behavior function
ms.openlocfilehash: fd3a3c2f99d1702cdccf68328c2122b965b2d078
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81337878"
---
# <a name="_set_abort_behavior"></a>_set_abort_behavior

Especifica a ação a ser tomada quando um programa é terminado de maneira anormal.

> [!NOTE]
> Não use a função [abortar](abort.md) para desligar um aplicativo da Microsoft Store, exceto em cenários de teste ou depuração. Formas programáticas ou de uI para fechar um aplicativo da Loja não são permitidas de acordo com as políticas da [Microsoft Store](/legal/windows/agreements/store-policies). Para obter mais informações, consulte [o ciclo de vida do aplicativo UWP](/windows/uwp/launch-resume/app-lifecycle).

## <a name="syntax"></a>Sintaxe

```C
unsigned int _set_abort_behavior(
   unsigned int flags,
   unsigned int mask
);
```

### <a name="parameters"></a>Parâmetros

*Sinalizadores*<br/>
Novo valor das bandeiras [abortarem.](abort.md)

*mask*<br/>
Máscara para os bits de bandeiras [de abortar](abort.md) para definir.

## <a name="return-value"></a>Valor retornado

O valor antigo dos sinalizadores.

## <a name="remarks"></a>Comentários

Há duas bandeiras [de abortar:](abort.md) **_WRITE_ABORT_MSG** e **_CALL_REPORTFAULT**. **_WRITE_ABORT_MSG** determina se uma mensagem de texto útil é impressa quando um programa é anormalmente encerrado. A mensagem afirma que o aplicativo chamou a função [abortar.](abort.md) O comportamento padrão é imprimir a mensagem. **_CALL_REPORTFAULT**, se definido, especifica que um dump de falha do Watson é gerado e relatado quando [o aborté](abort.md) é chamado. Por padrão, o relatório do despejo de memória está habilitado em builds que não são do tipo DEBUG.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_set_abort_behavior**|\<stdlib.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
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

```Output
Suppressing the abort message. If successful, this message will be the only output.
```

## <a name="see-also"></a>Confira também

[Abortar](abort.md)<br/>
