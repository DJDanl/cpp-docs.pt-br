---
title: memcpy, wmemcpy | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- memcpy
- wmemcpy
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
apitype: DLLExport
f1_keywords:
- wmemcpy
- memcpy
dev_langs:
- C++
helpviewer_keywords:
- wmemcpy function
- memcpy function
ms.assetid: 34abb90b-bffb-46dc-a2f3-a5e9940839d6
caps.latest.revision: 21
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a31ada40bfab599b6da41da268bf79792f8ebf20
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
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

## <a name="return-value"></a>Valor de retorno

O valor de *dest*.

## <a name="remarks"></a>Comentários

**memcpy** cópias *contagem* bytes do *src* para *dest*; **wmemcpy** cópias *contagem* caracteres largos (dois bytes). Se a origem e destino se sobrepõem, o comportamento de **memcpy** é indefinido. Use **memmove** para lidar com regiões de sobreposição.

> [!IMPORTANT]
> Certifique-se de que o buffer de destino seja do mesmo tamanho ou maior que o buffer de origem. Para obter mais informações, consulte [Avoiding Buffer Overruns](http://msdn.microsoft.com/library/windows/desktop/ms717795) (Evitando estouros de buffer).

> [!IMPORTANT]
> Porque muitos saturações de buffer e, portanto, possíveis explorações de segurança, tem foi rastreadas para uso inapropriado de **memcpy**, essa função está listada entre as funções "proibidas" pelo Security Development Lifecycle (SDL).  Você pode observar que algumas classes de biblioteca do VC + + continuam a usar **memcpy**.  Além disso, você pode observar que o otimizador do compilador do VC + +, às vezes, emite chamadas para **memcpy**.  O produto Visual C++ foi desenvolvido de acordo com o processo SDL e, portanto, o uso desta função proibida foi cuidadosamente avaliado.  No caso do uso dela pela biblioteca, as chamadas foram cuidadosamente examinadas para garantir que os estouros de buffer não serão permitidos por meio dessas chamadas.  No caso do compilador, às vezes, determinados padrões de código são reconhecidos como idênticos para o padrão de **memcpy**e, portanto, são substituídas por uma chamada à função.  Nesses casos, o uso de **memcpy** é não mais seguro do que o original instruções teria sido; eles simplesmente foram otimizados para uma chamada para o desempenho adequado **memcpy** função.  Assim como o uso de funções de CRT "seguras" não assegura a segurança (elas simplesmente fazem com que seja mais difícil de serem inseguras), o uso de funções “proibidas” não assegura o perigo (elas apenas exigem um exame maior para garantir a segurança).
>
> Porque **memcpy** uso pelo compilador do VC + + e bibliotecas foram examinado assim com cuidado, estas chamadas são permitidas dentro do código que seriam compatível com SDL.  **memcpy** chamadas introduzidas no código fonte do aplicativo só são compatíveis com o SDL quando que usam foi revisado por especialistas de segurança.

O **memcpy** e **wmemcpy** funções só serão substituídas se a constante **_CRT_SECURE_DEPRECATE_MEMORY** está definido antes da instrução de inclusão para que as funções para ser substituído, como o exemplo a seguir:

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

Consulte [memmove](memmove-wmemmove.md) para obter um exemplo de como usar **memcpy**.

## <a name="see-also"></a>Consulte também

[Manipulação de buffer](../../c-runtime-library/buffer-manipulation.md)<br/>
[_memccpy](memccpy.md)<br/>
[memchr, wmemchr](memchr-wmemchr.md)<br/>
[memcmp, wmemcmp](memcmp-wmemcmp.md)<br/>
[memmove, wmemmove](memmove-wmemmove.md)<br/>
[memset, wmemset](memset-wmemset.md)<br/>
[strcpy_s, wcscpy_s, _mbscpy_s](strcpy-s-wcscpy-s-mbscpy-s.md)<br/>
[strncpy_s, _strncpy_s_l, wcsncpy_s, _wcsncpy_s_l, _mbsncpy_s, _mbsncpy_s_l](strncpy-s-strncpy-s-l-wcsncpy-s-wcsncpy-s-l-mbsncpy-s-mbsncpy-s-l.md)<br/>
