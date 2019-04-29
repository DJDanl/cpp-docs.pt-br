---
title: _set_abort_behavior
ms.date: 1/02/2018
apiname:
- _set_abort_behavior
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
- _set_abort_behavior
- set_abort_behavior
helpviewer_keywords:
- aborting programs
- _set_abort_behavior function
- set_abort_behavior function
ms.openlocfilehash: 8b36a771a3694c6d01573d619990743c7ddc0f3e
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62356676"
---
# <a name="setabortbehavior"></a>_set_abort_behavior

Especifica a ação a ser tomada quando um programa é terminado de maneira anormal.

> [!NOTE]
> Não use o [anular](abort.md) função para desligar um aplicativo da Microsoft Store, exceto em teste ou cenários de depuração. Maneiras programáticas ou interface do usuário de fechar um aplicativo da Store não são permitidas de acordo com o [políticas do Microsoft Store](/legal/windows/agreements/store-policies). Para obter mais informações, consulte [ciclo de vida do aplicativo UWP](/windows/uwp/launch-resume/app-lifecycle).

## <a name="syntax"></a>Sintaxe

```C
unsigned int _set_abort_behavior(
   unsigned int flags,
   unsigned int mask
);
```

### <a name="parameters"></a>Parâmetros

*flags*<br/>
Novo valor de [anular](abort.md) sinalizadores.

*mask*<br/>
Máscara para o [anular](abort.md) sinalizadores de bits a ser definido.

## <a name="return-value"></a>Valor de retorno

O valor antigo dos sinalizadores.

## <a name="remarks"></a>Comentários

Há dois [anular](abort.md) sinalizadores: **_WRITE_ABORT_MSG** e **_CALL_REPORTFAULT**. **_WRITE_ABORT_MSG** determina se uma mensagem de texto útil é impressa quando um programa é encerrado de maneira anormal. A mensagem informa que o aplicativo tiver chamado de [anular](abort.md) função. O comportamento padrão é imprimir a mensagem. **_CALL_REPORTFAULT**, se definido, especifica que um despejo de memória do Watson é gerado e relatado quando [anular](abort.md) é chamado. Por padrão, o relatório do despejo de memória está habilitado em builds que não são do tipo DEBUG.

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

## <a name="see-also"></a>Consulte também

[abort](abort.md)<br/>
