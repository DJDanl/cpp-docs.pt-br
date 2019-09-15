---
title: _set_abort_behavior
ms.date: 01/02/2018
api_name:
- _set_abort_behavior
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
- _set_abort_behavior
- set_abort_behavior
helpviewer_keywords:
- aborting programs
- _set_abort_behavior function
- set_abort_behavior function
ms.openlocfilehash: a63d4e77a91dafa4500d5fef8e9b5e94ee28cfbd
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70948662"
---
# <a name="_set_abort_behavior"></a>_set_abort_behavior

Especifica a ação a ser tomada quando um programa é terminado de maneira anormal.

> [!NOTE]
> Não use a função [Abort](abort.md) para desligar um aplicativo Microsoft Store, exceto em cenários de teste ou depuração. As maneiras programática ou de interface do usuário de fechar um aplicativo da loja não são permitidas de acordo com as [políticas de Microsoft Store](/legal/windows/agreements/store-policies). Para obter mais informações, consulte [ciclo de vida do aplicativo UWP](/windows/uwp/launch-resume/app-lifecycle).

## <a name="syntax"></a>Sintaxe

```C
unsigned int _set_abort_behavior(
   unsigned int flags,
   unsigned int mask
);
```

### <a name="parameters"></a>Parâmetros

*flags*<br/>
Novo valor dos sinalizadores de [anulação](abort.md) .

*mascara*<br/>
Máscara para os bits de sinalizadores de [anulação](abort.md) a serem definidos.

## <a name="return-value"></a>Valor de retorno

O valor antigo dos sinalizadores.

## <a name="remarks"></a>Comentários

Há dois sinalizadores de [anulação](abort.md) : **_WRITE_ABORT_MSG** e **_CALL_REPORTFAULT**. **_WRITE_ABORT_MSG** determina se uma mensagem de texto útil é impressa quando um programa é encerrado de forma anormal. A mensagem informa que o aplicativo chamou a função [Abort](abort.md) . O comportamento padrão é imprimir a mensagem. **_CALL_REPORTFAULT**, se definido, especifica que um despejo de memória Watson é gerado e relatado quando [Abort](abort.md) é chamado. Por padrão, o relatório do despejo de memória está habilitado em builds que não são do tipo DEBUG.

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
