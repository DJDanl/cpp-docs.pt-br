---
title: _set_abort_behavior | Microsoft Docs
ms.custom: 
ms.date: 1/02/2018
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname: _set_abort_behavior
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
dev_langs: C++
helpviewer_keywords:
- aborting programs
- _set_abort_behavior function
- set_abort_behavior function
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 965ff160fd8098c60f53f639cb95aedf890edd86
ms.sourcegitcommit: a5d8f5b92cb5e984d5d6c9d67fe8a1241f3fe184
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/05/2018
---
# <a name="setabortbehavior"></a>_set_abort_behavior

Especifica a ação a ser tomada quando um programa é terminado de maneira anormal.

> [!NOTE]
> Não use o `abort` função para desligar um aplicativo da Microsoft Store, exceto em teste ou cenários de depuração. Modos de interface do usuário ou por programação para fechar um aplicativo de repositório não são permitidos de acordo com o [políticas do Microsoft Store](http://go.microsoft.com/fwlink/?LinkId=865936). Para obter mais informações, consulte [ciclo de vida do aplicativo UWP](http://go.microsoft.com/fwlink/p/?LinkId=865934).

## <a name="syntax"></a>Sintaxe

```C
unsigned int _set_abort_behavior(
   unsigned int flags,
   unsigned int mask
);
```

### <a name="parameters"></a>Parâmetros

[in] _sinalizadores_  
Novo valor dos sinalizadores `abort`.

[in] _máscara_  
Máscara para os bits dos sinalizadores `abort` a definir.

## <a name="return-value"></a>Valor de retorno

O valor antigo dos sinalizadores.

## <a name="remarks"></a>Comentários

Há dois sinalizadores `abort`: `_WRITE_ABORT_MSG` e `_CALL_REPORTFAULT`. `_WRITE_ABORT_MSG` determina se uma mensagem de texto útil é impressa quando um programa é encerrado de maneira anormal. A mensagem informa que o aplicativo tiver chamou a função `abort`. O comportamento padrão é imprimir a mensagem. `_CALL_REPORTFAULT`, se definido, especifica que um despejo de memória do Watson é gerado e relatado quando `abort` é chamada. Por padrão, o relatório do despejo de memória está habilitado em builds que não são do tipo DEBUG.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|`_set_abort_behavior`|\<stdlib.h>|

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

[abort](../../c-runtime-library/reference/abort.md)  
