---
title: _gcvt_s | Microsoft Docs
ms.custom: ''
ms.date: 04/05/2018
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _gcvt_s
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
- api-ms-win-crt-convert-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _gcvt_s
- gcvt_s
dev_langs:
- C++
helpviewer_keywords:
- _gcvt_s function
- _CVTBUFSIZE
- floating-point functions, converting number to string
- gcvt_s function
- numbers, converting to strings
- conversions, floating point to strings
- strings [C++], converting from floating point
- CVTBUFSIZE
ms.assetid: 0a8d8a26-5940-4ae3-835e-0aa6ec1b0744
caps.latest.revision: 30
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 60f68507f25ba6255b1c6a439c5e74729d2a2646
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="gcvts"></a>_gcvt_s

Converte um valor de ponto flutuante em uma cadeia de caracteres. Trata-se de uma versão de [_gcvt](gcvt.md) com melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t _gcvt_s(
   char *buffer,
   size_t sizeInBytes,
   double value,
   int digits
);
template <size_t cchStr>
errno_t _gcvt_s(
   char (&buffer)[cchStr],
   double value,
   int digits
); // C++ only
```

### <a name="parameters"></a>Parâmetros

*buffer*<br/>
Buffer para armazenar o resultado da conversão.

*sizeInBytes*<br/>
O tamanho do buffer.

*value*<br/>
Valor a ser convertido.

*digits*<br/>
Número de dígitos significativos armazenados.

## <a name="return-value"></a>Valor de retorno

Zero se for bem-sucedido. Se ocorrer uma falha devido a um parâmetro inválido (consulte na tabela a seguir os valores inválidos), o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, um código de erro será retornado. Códigos de erro são definidos em Errno.h. Para obter uma lista desses erros, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

### <a name="error-conditions"></a>Condições de Erro

|*buffer*|*sizeInBytes*|*value*|*digits*|Valor de|Valor em *buffer*|
|--------------|-------------------|-------------|--------------|------------|-----------------------|
|**NULL**|qualquer|qualquer|qualquer|**EINVAL**|Não modificado.|
|Não **nulo** (aponta válido da memória)|zero|qualquer|qualquer|**EINVAL**|Não modificado.|
|Não **nulo** (aponta válido da memória)|qualquer|qualquer|>= *sizeInBytes*|**EINVAL**|Não modificado.|

**Problemas de segurança**

**gcvt_s** pode gerar uma violação de acesso se *buffer* não aponta para memória válido e não é **nulo**.

## <a name="remarks"></a>Comentários

O **gcvt_s** função converte um ponto flutuante *valor* para uma cadeia de caracteres (que inclui um ponto decimal e um byte de entrada possíveis) e armazena a cadeia de caracteres em *buffer* . *buffer* deve ser grande o suficiente para acomodar o valor convertido mais de um caractere null de terminação, que é acrescentado automaticamente. Um buffer de comprimento **_CVTBUFSIZE** é suficiente para qualquer flutuante valor de ponto. Se um tamanho de buffer de *dígitos* + 1 for usado, a função não substituirá o final do buffer, então não se esqueça de fornecer um buffer suficiente para esta operação. **gcvt_s** tenta gerar *dígitos* dígitos no formato decimal. Se não for possível, ela produz *dígitos* dígitos no formato exponencial. Zeros à direita podem ser suprimidos na conversão.

No C++, o uso dessa função é simplificado por uma sobrecarga de modelo. A sobrecarga pode inferir o tamanho do buffer automaticamente, eliminando a necessidade de especificar um argumento de tamanho. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

A versão de depuração dessa função preenche primeiro o buffer com 0xFD. Para desabilitar esse comportamento, use [_CrtSetDebugFillThreshold](crtsetdebugfillthreshold.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|**_gcvt_s**|\<stdlib.h>|\<error.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_gcvt_s.c
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
    char buf[_CVTBUFSIZE];
    int decimal;
    int sign;
    int err;

    err = _gcvt_s(buf, _CVTBUFSIZE, 1.2, 5);

    if (err != 0)
    {
        printf("_gcvt_s failed with error code %d\n", err);
        exit(1);
    }

    printf("Converted value: %s\n", buf);
}
```

```Output
Converted value: 1.2
```

## <a name="see-also"></a>Consulte também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[atof, _atof_l, _wtof, _wtof_l](atof-atof-l-wtof-wtof-l.md)<br/>
[_ecvt_s](ecvt-s.md)<br/>
[_fcvt_s](fcvt-s.md)<br/>
[_gcvt](gcvt.md)<br/>
