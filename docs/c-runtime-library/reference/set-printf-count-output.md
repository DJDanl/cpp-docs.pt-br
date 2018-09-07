---
title: _set_printf_count_output | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 783225412b01430d1043dafd4761cb7432eaa1d7
ms.sourcegitcommit: 761c5f7c506915f5a62ef3847714f43e9b815352
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/07/2018
ms.locfileid: "44108313"
---
# <a name="setprintfcountoutput"></a>_set_printf_count_output

Habilitar ou desabilitar o suporte do **%n** Formatar [printf, printf_l, wprintf, wprintf_l](printf-printf-l-wprintf-wprintf-l.md)-funções da família.

## <a name="syntax"></a>Sintaxe

```C
int _set_printf_count_output(
   int enable
);
```

### <a name="parameters"></a>Parâmetros

*enable*<br/>
Um valor diferente de zero para habilitar **%n** dão suporte a 0 para desabilitar **%n** dão suporte.

## <a name="property-valuereturn-value"></a>Valor da propriedade/valor de retorno

O estado de **%n** suporte antes de chamar essa função: diferente de zero se **%n** suporte tiver sido habilitado, 0 se ele foi desabilitado.

## <a name="remarks"></a>Comentários

Por motivos de segurança, suporte para o **%n** especificador de formato é desabilitado por padrão no **printf** e todas as suas variantes. Se **%n** for encontrado em um **printf** especificação de formato, o comportamento padrão é invocar o manipulador de parâmetro inválido conforme descrito na [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Chamando **set_printf_count_output** com um argumento diferente de zero fará com que **printf**-funções da família interpretar **%n** conforme descrito em [formato Sintaxe de especificação: funções printf e wprintf](../../c-runtime-library/format-specification-syntax-printf-and-wprintf-functions.md).

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
