---
title: _set_abort_behavior | Microsoft Docs
ms.custom: ''
ms.date: 1/02/2018
ms.technology:
- cpp-standard-libraries
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- aborting programs
- _set_abort_behavior function
- set_abort_behavior function
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fb308e527cc955d91af0b12547d52aa5e6316af5
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32407269"
---
# <a name="setabortbehavior"></a>_set_abort_behavior

Especifica a ação a ser tomada quando um programa é terminado de maneira anormal.

> [!NOTE]
> Não use o [anular](abort.md) função para desligar um aplicativo da Microsoft Store, exceto em teste ou cenários de depuração. Modos de interface do usuário ou por programação para fechar um aplicativo de repositório não são permitidos de acordo com o [políticas do Microsoft Store](http://go.microsoft.com/fwlink/?LinkId=865936). Para obter mais informações, consulte [ciclo de vida do aplicativo UWP](http://go.microsoft.com/fwlink/p/?LinkId=865934).

## <a name="syntax"></a>Sintaxe

```C
unsigned int _set_abort_behavior(
   unsigned int flags,
   unsigned int mask
);
```

### <a name="parameters"></a>Parâmetros

*flags*<br/>
Novo valor da [anular](abort.md) sinalizadores.

*Máscara*<br/>
Máscara para o [anular](abort.md) sinalizadores de bits para definir.

## <a name="return-value"></a>Valor de retorno

O valor antigo dos sinalizadores.

## <a name="remarks"></a>Comentários

Há dois [anular](abort.md) sinalizadores: **_WRITE_ABORT_MSG** e **_CALL_REPORTFAULT**. **_WRITE_ABORT_MSG** determina se uma mensagem de texto útil é impresso quando um programa é terminado de maneira anormal. A mensagem informa que o aplicativo tiver chamado o [anular](abort.md) função. O comportamento padrão é imprimir a mensagem. **_CALL_REPORTFAULT**, se definido, especifica que um despejo de Dr Watson é gerado e relatado quando [anular](abort.md) é chamado. Por padrão, o relatório do despejo de memória está habilitado em builds que não são do tipo DEBUG.

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
