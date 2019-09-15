---
title: _set_printf_count_output
ms.date: 11/04/2016
api_name:
- _set_printf_count_output
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
- api-ms-win-crt-stdio-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- set_printf_count_output
- _set_printf_count_output
helpviewer_keywords:
- '%n format'
- set_printf_count_output function
- _set_printf_count_output function
ms.assetid: d8259ec5-764e-42d0-9169-72172e95163b
ms.openlocfilehash: 0d53b4e4c56a69582a4eb517fa1a5c9e10cd7d2f
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70948415"
---
# <a name="_set_printf_count_output"></a>_set_printf_count_output

Habilite ou desabilite o suporte do formato **% n** nas funções [printf, _printf_l, wprintf, _wprintf_l](printf-printf-l-wprintf-wprintf-l.md)-Family.

## <a name="syntax"></a>Sintaxe

```C
int _set_printf_count_output(
   int enable
);
```

### <a name="parameters"></a>Parâmetros

*enable*<br/>
Um valor diferente de zero para habilitar o suporte a **% n** , 0 para desabilitar o suporte a **% n** .

## <a name="property-valuereturn-value"></a>Valor da propriedade/valor de retorno

O estado do suporte de **% n** antes de chamar esta função: diferente de zero se o suporte a **% n** tiver sido habilitado, 0 se ele tiver sido desabilitado.

## <a name="remarks"></a>Comentários

Por causa de motivos de segurança, o suporte para o especificador de formato **% n** é desabilitado por padrão em **printf** e em todas as suas variantes. Se **% n** for encontrado em uma especificação de formato **printf** , o comportamento padrão será invocar o manipulador de parâmetro inválido, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Chamar **_set_printf_count_output** com um argumento diferente de zero fará com que as funções da família **printf**interpretem **% n** conforme descrito em [sintaxe de especificação de formato: funções printf e wprintf](../../c-runtime-library/format-specification-syntax-printf-and-wprintf-functions.md).

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
