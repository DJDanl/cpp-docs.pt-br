---
title: _fcvt_s
ms.date: 04/05/2018
api_name:
- _fcvt_s
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
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- fcvt_s
- _fcvt_s
helpviewer_keywords:
- fcvt_s function
- converting floating point, to strings
- floating-point functions, converting number to string
- _fcvt_s function
ms.assetid: 48671197-1d29-4c2b-a5d8-d2368f5f68a1
ms.openlocfilehash: a63b542333717a57097da455fb514eeef80344b4
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70941348"
---
# <a name="_fcvt_s"></a>_fcvt_s

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

No caso de um parâmetro inválido, conforme listado na tabela a seguir, essa função invoca o manipulador de parâmetro inválido, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essa função definirá **errno** como **EINVAL** e retornará **EINVAL**.

### <a name="error-conditions"></a>Condições de Erro

|*buffer*|*sizeInBytes*|value|Contagem|dec|sinal|Valor de|Valor no *buffer*|
|--------------|-------------------|-----------|-----------|---------|----------|------------|-----------------------|
|**NULL**|qualquer|qualquer|qualquer|qualquer|qualquer|**EINVAL**|Não modificado.|
|Not **NULL** (aponta para memória válida)|<=0|qualquer|qualquer|qualquer|qualquer|**EINVAL**|Não modificado.|
|qualquer|qualquer|qualquer|qualquer|**NULL**|qualquer|**EINVAL**|Não modificado.|
|qualquer|qualquer|qualquer|qualquer|qualquer|**NULL**|**EINVAL**|Não modificado.|

## <a name="security-issues"></a>Problemas de segurança

**_fcvt_s** poderá gerar uma violação de acesso se o *buffer* não apontar para uma memória válida e não for **nulo**.

## <a name="remarks"></a>Comentários

A função **_fcvt_s** converte um número de ponto flutuante em uma cadeia de caracteres de caractere terminada em nulo. O parâmetro de *valor* é o número de ponto flutuante a ser convertido. **_fcvt_s** armazena os dígitos de *valor* como uma cadeia de caracteres e acrescenta um caractere nulo (' \ 0 '). O parâmetro *Count* especifica o número de dígitos a serem armazenados após o ponto decimal. Os dígitos em excesso são arredondados para os locais de *contagem* . Se houver menos de dígitos de *contagem* de precisão, a cadeia de caracteres será preenchida com zeros.

Somente dígitos são armazenados na cadeia de caracteres. A posição do ponto decimal e o sinal de *valor* podem ser obtidas de *Dec* e *Sign* após a chamada. O parâmetro *Dec* aponta para um valor inteiro; Esse valor inteiro fornece a posição do ponto decimal em relação ao início da cadeia de caracteres. Um valor inteiro de zero ou negativo indica que o ponto decimal se encontra à esquerda do primeiro dígito. O *sinal* de parâmetro aponta para um inteiro que indica o sinal de *valor*. O inteiro será definido como 0 se o *valor* for positivo e será definido como um número diferente de zero se o *valor* for negativo.

Um buffer de comprimento **_CVTBUFSIZE** é suficiente para qualquer valor de ponto flutuante.

A diferença entre **_ecvt_s** e **_fcvt_s** está na interpretação do parâmetro *Count* . **_ecvt_s** interpreta a *contagem* como o número total de dígitos na cadeia de caracteres de saída e **_fcvt_s** interpreta a *contagem* como o número de dígitos após o ponto decimal.

No C++, o uso dessa função é simplificado por uma sobrecarga de modelo. A sobrecarga pode inferir o tamanho do buffer automaticamente, eliminando a necessidade de especificar um argumento de tamanho. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

A versão de depuração dessa função preenche primeiro o buffer com 0xFD. Para desabilitar esse comportamento, use [_CrtSetDebugFillThreshold](crtsetdebugfillthreshold.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|Cabeçalho opcional|
|--------------|---------------------|---------------------|
|**_fcvt_s**|\<stdlib.h>|\<errno.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

**DLLs** Todas as versões dos [recursos da biblioteca CRT](../../c-runtime-library/crt-library-features.md).

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
