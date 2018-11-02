---
title: _fcvt_s
ms.date: 04/05/2018
apiname:
- _fcvt_s
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
- fcvt_s
- _fcvt_s
helpviewer_keywords:
- fcvt_s function
- converting floating point, to strings
- floating-point functions, converting number to string
- _fcvt_s function
ms.assetid: 48671197-1d29-4c2b-a5d8-d2368f5f68a1
ms.openlocfilehash: 51ff3c675f1f53aee9beab629b17193164a2e7eb
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50536835"
---
# <a name="fcvts"></a>_fcvt_s

Converte um número de ponto flutuante em uma cadeia de caracteres. Trata-se de uma versão de [_fcvt](fcvt.md) com melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t _fcvt_s(
   char* buffer,
   size_t sizeInBytes,
   double value,
   int count,
   int *dec,
   int *sign
);
template <size_t size>
errno_t _fcvt_s(
   char (&buffer)[size],
   double value,
   int count,
   int *dec,
   int *sign
); // C++ only
```

### <a name="parameters"></a>Parâmetros

*buffer*<br/>
O buffer fornecido que conterá o resultado da conversão.

*sizeInBytes*<br/>
O tamanho do buffer em bytes.

*value*<br/>
Número a ser convertido.

*count*<br/>
O número de dígitos após o ponto decimal.

*dec*<br/>
Ponteiro para a posição do ponto decimal armazenada.

*sign*<br/>
Ponteiro para o indicador de logon armazenado.

## <a name="return-value"></a>Valor de retorno

Zero se for bem-sucedido. Se houver uma falha, o valor retornado será um código de erro. Códigos de erro são definidos em Errno.h. Para obter uma lista desses erros, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

No caso de um parâmetro inválido, conforme listado na tabela a seguir, essa função invoca o manipulador de parâmetro inválido, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essa função definirá **errno** à **EINVAL** e retorna **EINVAL**.

### <a name="error-conditions"></a>Condições de Erro

|*buffer*|*sizeInBytes*|Valor |count|dec|sinal|Valor de|Valor em *buffer*|
|--------------|-------------------|-----------|-----------|---------|----------|------------|-----------------------|
|**NULL**|qualquer|qualquer|qualquer|qualquer|qualquer|**EINVAL**|Não modificado.|
|Não **nulo** (aponta para a memória válida)|<=0|qualquer|qualquer|qualquer|qualquer|**EINVAL**|Não modificado.|
|qualquer|qualquer|qualquer|qualquer|**NULL**|qualquer|**EINVAL**|Não modificado.|
|qualquer|qualquer|qualquer|qualquer|qualquer|**NULL**|**EINVAL**|Não modificado.|

## <a name="security-issues"></a>Problemas de segurança

**fcvt_s** pode gerar uma violação de acesso se *buffer* não apontar para a memória válida e não é **nulo**.

## <a name="remarks"></a>Comentários

O **fcvt_s** função converte um número de ponto flutuante em uma cadeia de caracteres terminada em nulo. O *valor* parâmetro é o número de ponto flutuante a ser convertido. **fcvt_s** armazena os dígitos de *valor* como uma cadeia de caracteres e acrescenta um caractere nulo ('\0'). O *contagem* parâmetro especifica o número de dígitos a serem armazenados após o ponto decimal. Dígitos em excesso são arredondados para *contagem* coloca. Se houver menos de *contagem* dígitos de precisão, a cadeia de caracteres será preenchida com zeros.

Somente dígitos são armazenados na cadeia de caracteres. A posição do ponto decimal e o sinal de *valor* pode ser obtido *dec* e *entrada* após a chamada. O *dec* parâmetro aponta para um valor inteiro; o valor inteiro dando a posição do ponto decimal em relação ao início da cadeia de caracteres. Um valor inteiro de zero ou negativo indica que o ponto decimal se encontra à esquerda do primeiro dígito. O parâmetro *sinal* aponta para um inteiro que indica o sinal do *valor*. O inteiro é definido como 0 se *valor* for positivo e é definido como um número diferente de zero se *valor* é negativo.

Um buffer de tamanho **_CVTBUFSIZE** é suficiente para qualquer flutuantes valor de ponto.

A diferença entre **ecvt_s** e **fcvt_s** está na interpretação do *contagem* parâmetro. **ecvt_s** interpreta *contagem* como o número total de dígitos na cadeia de saída, e **fcvt_s** interpreta *contagem* como o número de dígitos após o ponto decimal.

No C++, o uso dessa função é simplificado por uma sobrecarga de modelo. A sobrecarga pode inferir o tamanho do buffer automaticamente, eliminando a necessidade de especificar um argumento de tamanho. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

A versão de depuração dessa função preenche primeiro o buffer com 0xFD. Para desabilitar esse comportamento, use [_CrtSetDebugFillThreshold](crtsetdebugfillthreshold.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|Cabeçalho opcional|
|--------------|---------------------|---------------------|
|**_fcvt_s**|\<stdlib.h>|\<errno.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

**Bibliotecas:** todas as versões dos [Recursos da Biblioteca CRT](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

```C
// fcvt_s.c
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
    char * buf = 0;
    int decimal;
    int sign;
    int err;

    buf = (char*) malloc(_CVTBUFSIZE);
    err = _fcvt_s(buf, _CVTBUFSIZE, 1.2, 5, &decimal, &sign);

    if (err != 0)
    {
        printf("_fcvt_s failed with error code %d\n", err);
        exit(1);
    }

    printf("Converted value: %s\n", buf);
}
```

```Output
Converted value: 120000
```

## <a name="see-also"></a>Consulte também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[atof, _atof_l, _wtof, _wtof_l](atof-atof-l-wtof-wtof-l.md)<br/>
[_ecvt_s](ecvt-s.md)<br/>
[_gcvt_s](gcvt-s.md)<br/>
[_fcvt](fcvt.md)<br/>
