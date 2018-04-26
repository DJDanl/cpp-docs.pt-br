---
title: _set_printf_count_output | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _set_printf_count_output
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
- api-ms-win-crt-stdio-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- set_printf_count_output
- _set_printf_count_output
dev_langs:
- C++
helpviewer_keywords:
- '%n format'
- set_printf_count_output function
- _set_printf_count_output function
ms.assetid: d8259ec5-764e-42d0-9169-72172e95163b
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 505d87a98ed212a4be7e23a05127686b370c9176
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="setprintfcountoutput"></a>_set_printf_count_output

Habilitar ou desabilitar o suporte do **%n** Formatar [printf, printf_l, and wprintf, wprintf_l](printf-printf-l-wprintf-wprintf-l.md)-as funções da família.

## <a name="syntax"></a>Sintaxe

```C
int _set_printf_count_output(
   int enable
);
```

### <a name="parameters"></a>Parâmetros

*Habilitar* um valor diferente de zero para habilitar **%n** suporte, 0 para desabilitar **%n** suporte.

## <a name="property-valuereturn-value"></a>Valor da propriedade/valor de retorno

O estado do **%n** suporte antes de chamar essa função: diferente de zero se **%n** foi habilitado o suporte, 0 se ele foi desabilitado.

## <a name="remarks"></a>Comentários

Por motivos de segurança, suporte para o **%n** especificador de formato é desabilitado por padrão em **printf** e todas as suas variantes. Se **%n** é encontrado em uma **printf** especificação de formato, o comportamento padrão é invocar o manipulador de parâmetro inválido, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Chamando **set_printf_count_output** com um argumento diferente de zero fará com que **printf**-as funções da família interpretar **%n** conforme descrito em [formato Especificação de sintaxe: funções printf e and wprintf](../../c-runtime-library/format-specification-syntax-printf-and-wprintf-functions.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_set_printf_count_output**|\<stdio.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_set_printf_count_output.c
#include <stdio.h>

int main()
{
   int e;
   int i;
   e = _set_printf_count_output( 1 );
   printf( "%%n support was %sabled.\n",
        e ? "en" : "dis" );
   printf( "%%n support is now %sabled.\n",
        _get_printf_count_output() ? "en" : "dis" );
   printf( "12345%n6789\n", &i ); // %n format should set i to 5
   printf( "i = %d\n", i );
}
```

```Output
%n support was disabled.
%n support is now enabled.
123456789
i = 5
```

## <a name="see-also"></a>Consulte também

[_get_printf_count_output](get-printf-count-output.md)<br/>
