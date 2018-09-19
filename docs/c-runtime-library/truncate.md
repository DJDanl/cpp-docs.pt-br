---
title: _TRUNCATE | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
f1_keywords:
- _TRUNCATE
- TRUNCATE
dev_langs:
- C++
helpviewer_keywords:
- TRUNCATE constant
- _TRUNCATE constant
ms.assetid: ad093dbf-1aa5-4bd2-9268-efc68afd8434
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: dd0ca0021705b98f02460cf5f519583998c7b52a
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46094851"
---
# <a name="truncate"></a>_TRUNCATE

Especifica o comportamento de truncamento da cadeia de caracteres.

## <a name="syntax"></a>Sintaxe

```
#include <stdlib.h>
```

## <a name="remarks"></a>Comentários

`_TRUNCATE` habilita o comportamento de truncamento quando passado como o parâmetro `count` para essas funções:

[strncpy_s, _strncpy_s_l, wcsncpy_s, _wcsncpy_s_l, _mbsncpy_s, _mbsncpy_s_l](../c-runtime-library/reference/strncpy-s-strncpy-s-l-wcsncpy-s-wcsncpy-s-l-mbsncpy-s-mbsncpy-s-l.md)

[strncat_s, _strncat_s_l, wcsncat_s, _wcsncat_s_l, _mbsncat_s, _mbsncat_s_l](../c-runtime-library/reference/strncat-s-strncat-s-l-wcsncat-s-wcsncat-s-l-mbsncat-s-mbsncat-s-l.md)

[mbstowcs_s, _mbstowcs_s_l](../c-runtime-library/reference/mbstowcs-s-mbstowcs-s-l.md)

[mbsrtowcs_s](../c-runtime-library/reference/mbsrtowcs-s.md)

[wcstombs_s, _wcstombs_s_l](../c-runtime-library/reference/wcstombs-s-wcstombs-s-l.md)

[wcsrtombs_s](../c-runtime-library/reference/wcsrtombs-s.md)

[_snprintf_s, _snprintf_s_l, _snwprintf_s, _snwprintf_s_l](../c-runtime-library/reference/snprintf-s-snprintf-s-l-snwprintf-s-snwprintf-s-l.md)

[vsnprintf_s, _vsnprintf_s, _vsnprintf_s_l, _vsnwprintf_s, _vsnwprintf_s_l](../c-runtime-library/reference/vsnprintf-s-vsnprintf-s-vsnprintf-s-l-vsnwprintf-s-vsnwprintf-s-l.md)

Se o buffer de destino for muito pequeno para conter toda a cadeia de caracteres, o comportamento normal dessas funções será tratá-la como uma situação de erro (consulte [Validação de parâmetro](../c-runtime-library/parameter-validation.md)). No entanto, se o truncamento da cadeia de caracteres for habilitado ao passar `_TRUNCATE`, essas funções copiarão da cadeia de caracteres somente o que couber, deixando o buffer de destino com terminação nula e retornarão com êxito.

O truncamento da cadeia de caracteres altera os valores de retorno das funções afetadas. As seguintes funções retornarão 0 se não ocorrer o truncamento ou `STRUNCATE` se ocorrer o truncamento:

[strncpy_s, _strncpy_s_l, wcsncpy_s, _wcsncpy_s_l, _mbsncpy_s, _mbsncpy_s_l](../c-runtime-library/reference/strncpy-s-strncpy-s-l-wcsncpy-s-wcsncpy-s-l-mbsncpy-s-mbsncpy-s-l.md)

[strncat_s, _strncat_s_l, wcsncat_s, _wcsncat_s_l, _mbsncat_s, _mbsncat_s_l](../c-runtime-library/reference/strncat-s-strncat-s-l-wcsncat-s-wcsncat-s-l-mbsncat-s-mbsncat-s-l.md)

[wcstombs_s, _wcstombs_s_l](../c-runtime-library/reference/wcstombs-s-wcstombs-s-l.md)

[mbstowcs_s, _mbstowcs_s_l](../c-runtime-library/reference/mbstowcs-s-mbstowcs-s-l.md)

As seguintes funções retornarão o número de caracteres copiados se não ocorrer o truncamento ou -1 se o truncamento ocorrer (correspondendo ao comportamento das funções snprintf originais):

[_snprintf_s, _snprintf_s_l, _snwprintf_s, _snwprintf_s_l](../c-runtime-library/reference/snprintf-s-snprintf-s-l-snwprintf-s-snwprintf-s-l.md)

[vsnprintf_s, _vsnprintf_s, _vsnprintf_s_l, _vsnwprintf_s, _vsnwprintf_s_l](../c-runtime-library/reference/vsnprintf-s-vsnprintf-s-vsnprintf-s-l-vsnwprintf-s-vsnwprintf-s-l.md)

## <a name="example"></a>Exemplo

```
// crt_truncate.c
#include <stdlib.h>
#include <errno.h>

int main()
{
   char src[] = "1234567890";
   char dst[5];
   errno_t err = strncpy_s(dst, _countof(dst), src, _TRUNCATE);
   if ( err == STRUNCATE )
      printf( "truncation occurred!\n" );
   printf( "'%s'\n", dst );
}
```

```Output
truncation occurred!
'1234'
```

## <a name="see-also"></a>Consulte também

[Constantes globais](../c-runtime-library/global-constants.md)