---
title: memcpy, wmemcpy
ms.date: 11/04/2016
api_name:
- memcpy
- wmemcpy
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
- ntoskrnl.exe
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- wmemcpy
- memcpy
helpviewer_keywords:
- wmemcpy function
- memcpy function
ms.assetid: 34abb90b-bffb-46dc-a2f3-a5e9940839d6
ms.openlocfilehash: bf7f12cd00780347f23252764aace449dd6f5722
ms.sourcegitcommit: 069e3833bd821e7d64f5c98d0ea41fc0c5d22e53
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/21/2019
ms.locfileid: "74303289"
---
# <a name="memcpy-wmemcpy"></a>memcpy, wmemcpy

Copia bytes entre buffers. Estão disponíveis versões mais seguras dessas funções, consulte [memcpy_s, wmemcpy_s](memcpy-s-wmemcpy-s.md).

## <a name="syntax"></a>Sintaxe

```C
void *memcpy(
   void *dest,
   const void *src,
   size_t count
);
wchar_t *wmemcpy(
   wchar_t *dest,
   const wchar_t *src,
   size_t count
);
```

### <a name="parameters"></a>Parâmetros

*dest*<br/>
Novo buffer.

*src*<br/>
Buffer do qual copiar.

*count*<br/>
O número de caracteres a serem copiados.

## <a name="return-value"></a>Valor retornado

O valor de *dest*.

## <a name="remarks"></a>Comentários

**memcpy** copia bytes de *contagem* de *src* para *dest*; o **wmemcpy** copia os caracteres largos da *contagem* (dois bytes). Se a origem e o destino se sobrepõem, o comportamento de **memcpy** é indefinido. Use **memmove** para lidar com regiões sobrepostas.

> [!IMPORTANT]
> Certifique-se de que o buffer de destino seja do mesmo tamanho ou maior que o buffer de origem. Para obter mais informações, consulte [Evitando saturações de buffer](/windows/win32/SecBP/avoiding-buffer-overruns).

> [!IMPORTANT]
> Como tantas estouros de buffer e, portanto, possíveis explorações de segurança, foram rastreadas para uso impróprio de **memcpy**, essa função está listada entre as funções "banidas" pelo SDL (ciclo de vida de desenvolvimento da segurança).  Você pode observar que algumas classes de biblioteca VC + + continuam a usar o **memcpy**.  Além disso, você pode observar que o otimizador do compilador VC + + às vezes emite chamadas para **memcpy**.  O produto Visual C++ foi desenvolvido de acordo com o processo SDL e, portanto, o uso desta função proibida foi cuidadosamente avaliado.  No caso do uso dela pela biblioteca, as chamadas foram cuidadosamente examinadas para garantir que os estouros de buffer não serão permitidos por meio dessas chamadas.  No caso do compilador, algumas vezes determinados padrões de código são reconhecidos como idênticos ao padrão de **memcpy**e, portanto, são substituídos por uma chamada para a função.  Nesses casos, o uso de **memcpy** não é mais não seguro do que as instruções originais teriam; Eles simplesmente foram otimizados para uma chamada para a função **memcpy** ajustada pelo desempenho.  Assim como o uso de funções CRT "seguras" não garante a segurança (elas apenas dificultam a segurança), o uso de funções "banidas" não garante o perigo (eles simplesmente exigem maior investigação para garantir a segurança).
>
> Como o uso de **memcpy** pelo compilador do vc + + e pelas bibliotecas foi cuidadosamente examinado, essas chamadas são permitidas dentro do código que, de outra forma, é compatível com o SDL.  as chamadas **memcpy** introduzidas no código-fonte do aplicativo são compatíveis apenas com o SDL quando esse uso foi revisado por especialistas em segurança.

As funções **memcpy** e **wmemcpy** só serão preteridas se a constante **_CRT_SECURE_DEPRECATE_MEMORY** for definida antes da instrução de inclusão para que as funções sejam preteridas, como no exemplo abaixo:

```C
#define _CRT_SECURE_DEPRECATE_MEMORY
#include <memory.h>
```

ou

```C
#define _CRT_SECURE_DEPRECATE_MEMORY
#include <wchar.h>
```

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**memcpy**|\<memory.h> ou \<string.h>|
|**wmemcpy**|\<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Consulte [memmove](memmove-wmemmove.md) para obter um exemplo de como usar o **memcpy**.

## <a name="see-also"></a>Consulte também

[Manipulação de buffer](../../c-runtime-library/buffer-manipulation.md)<br/>
[_memccpy](memccpy.md)<br/>
[memchr, wmemchr](memchr-wmemchr.md)<br/>
[memcmp, wmemcmp](memcmp-wmemcmp.md)<br/>
[memmove, wmemmove](memmove-wmemmove.md)<br/>
[memset, wmemset](memset-wmemset.md)<br/>
[strcpy_s, wcscpy_s, _mbscpy_s](strcpy-s-wcscpy-s-mbscpy-s.md)<br/>
[strncpy_s, _strncpy_s_l, wcsncpy_s, _wcsncpy_s_l, _mbsncpy_s, _mbsncpy_s_l](strncpy-s-strncpy-s-l-wcsncpy-s-wcsncpy-s-l-mbsncpy-s-mbsncpy-s-l.md)<br/>
