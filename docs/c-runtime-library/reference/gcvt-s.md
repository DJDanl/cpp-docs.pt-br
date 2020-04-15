---
title: _gcvt_s
ms.date: 4/2/2020
api_name:
- _gcvt_s
- _o__gcvt_s
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
- api-ms-win-crt-convert-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _gcvt_s
- gcvt_s
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
ms.openlocfilehash: 10d2b9af45b78a3f5ed673bde3d37894ccb00168
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81345370"
---
# <a name="_gcvt_s"></a>_gcvt_s

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

*Buffer*<br/>
Buffer para armazenar o resultado da conversão.

*Sizeinbytes*<br/>
O tamanho do buffer.

*value*<br/>
Valor a ser convertido.

*dígitos*<br/>
Número de dígitos significativos armazenados.

## <a name="return-value"></a>Valor retornado

Zero se for bem-sucedido. Se ocorrer uma falha devido a um parâmetro inválido (consulte na tabela a seguir os valores inválidos), o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, um código de erro será retornado. Códigos de erro são definidos em Errno.h. Para obter uma lista desses erros, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

### <a name="error-conditions"></a>Condições de erro

|*Buffer*|*Sizeinbytes*|*value*|*dígitos*|Retorno|Valor em *buffer*|
|--------------|-------------------|-------------|--------------|------------|-----------------------|
|**NULO**|any|any|any|**Einval**|Não modificado.|
|Não **NULL** (pontos para memória válida)|zero|any|any|**Einval**|Não modificado.|
|Não **NULL** (pontos para memória válida)|any|any|>= *Sizeinbytes*|**Einval**|Não modificado.|

**Problemas de segurança**

**_gcvt_s** pode gerar uma violação de acesso se *o buffer* não apontar para a memória válida e não for **NULL**.

## <a name="remarks"></a>Comentários

A função **_gcvt_s** converte um *valor* de ponto flutuante em uma seqüência de caracteres (que inclui um ponto decimal e um possível byte de sinal) e armazena a string no *buffer*. *o buffer* deve ser grande o suficiente para acomodar o valor convertido mais um caractere nulo de terminação, que é anexado automaticamente. Um tampão de comprimento **_CVTBUFSIZE** é suficiente para qualquer valor de ponto flutuante. Se um tamanho de buffer de *dígitos* + 1 for usado, a função não substituirá a extremidade do buffer, por isso certifique-se de fornecer um buffer suficiente para esta operação. **_gcvt_s** tenta produzir *dígitos* em formato decimal. Se não puder, produz *dígitos* em formato exponencial. Zeros à direita podem ser suprimidos na conversão.

No C++, o uso dessa função é simplificado por uma sobrecarga de modelo. A sobrecarga pode inferir o tamanho do buffer automaticamente, eliminando a necessidade de especificar um argumento de tamanho. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

A versão dedepuração desta função primeiro preenche o buffer com 0xFE. Para desabilitar esse comportamento, use [_CrtSetDebugFillThreshold](crtsetdebugfillthreshold.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

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

## <a name="see-also"></a>Confira também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[atof, _atof_l, _wtof, _wtof_l](atof-atof-l-wtof-wtof-l.md)<br/>
[_ecvt_s](ecvt-s.md)<br/>
[_fcvt_s](fcvt-s.md)<br/>
[_gcvt](gcvt.md)<br/>
