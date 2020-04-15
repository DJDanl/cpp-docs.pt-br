---
title: _fcvt_s
ms.date: 4/2/2020
api_name:
- _fcvt_s
- _o__fcvt_s
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
- fcvt_s
- _fcvt_s
helpviewer_keywords:
- fcvt_s function
- converting floating point, to strings
- floating-point functions, converting number to string
- _fcvt_s function
ms.assetid: 48671197-1d29-4c2b-a5d8-d2368f5f68a1
ms.openlocfilehash: 80f02467e160e3196982c10576ad55f5487e5fc1
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81347450"
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

*Buffer*<br/>
O buffer fornecido que conterá o resultado da conversão.

*Sizeinbytes*<br/>
O tamanho do buffer em bytes.

*value*<br/>
Número a ser convertido.

*contagem*<br/>
O número de dígitos após o ponto decimal.

*Dezembro*<br/>
Ponteiro para a posição do ponto decimal armazenada.

*Sinal*<br/>
Ponteiro para o indicador de logon armazenado.

## <a name="return-value"></a>Valor retornado

Zero se for bem-sucedido. Se houver uma falha, o valor retornado será um código de erro. Códigos de erro são definidos em Errno.h. Para obter uma lista desses erros, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

No caso de um parâmetro inválido, conforme listado na tabela a seguir, essa função invoca o manipulador de parâmetro inválido, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, esta função define **errno** para **EINVAL** e retorna **EINVAL**.

### <a name="error-conditions"></a>Condições de erro

|*Buffer*|*Sizeinbytes*|value|count|dec|assinar|Retorno|Valor em *buffer*|
|--------------|-------------------|-----------|-----------|---------|----------|------------|-----------------------|
|**NULO**|any|any|any|any|any|**Einval**|Não modificado.|
|Não **NULL** (pontos para memória válida)|<=0|any|any|any|any|**Einval**|Não modificado.|
|any|any|any|any|**NULO**|any|**Einval**|Não modificado.|
|any|any|any|any|any|**NULO**|**Einval**|Não modificado.|

## <a name="security-issues"></a>Problemas de segurança

**_fcvt_s** pode gerar uma violação de acesso se *o buffer* não apontar para a memória válida e não for **NULL**.

## <a name="remarks"></a>Comentários

A função **_fcvt_s** converte um número de ponto flutuante em uma seqüência de caracteres com término nulo. O parâmetro de *valor* é o número de ponto flutuante a ser convertido. **_fcvt_s** armazena os dígitos de *valor* como uma string e anexa um caractere nulo ('\0'). O parâmetro *de contagem* especifica o número de dígitos a serem armazenados após o ponto decimal. Os dígitos em excesso são arredondados para *contar* lugares. Se houver menos de *dígitos* de precisão, a seqüência é acolchoada com zeros.

Somente dígitos são armazenados na cadeia de caracteres. A posição do ponto decimal e o sinal de *valor* podem ser obtidos a partir *de dezembro* e *assinar* após a chamada. O parâmetro *dec* aponta para um valor inteiro; este valor inteiro dá a posição do ponto decimal em relação ao início da string. Um valor inteiro de zero ou negativo indica que o ponto decimal se encontra à esquerda do primeiro dígito. O *sinal* de parâmetro aponta para um inteiro indicando o sinal de *valor*. O inteiro é definido como 0 se *o valor* for positivo e é definido como um número não zero se *o valor* for negativo.

Um tampão de comprimento **_CVTBUFSIZE** é suficiente para qualquer valor de ponto flutuante.

A diferença entre **_ecvt_s** e **_fcvt_s** está na interpretação do parâmetro de *contagem.* **_ecvt_s** interpreta *a contagem* como o número total de dígitos na seqüência de saída, e **_fcvt_s** interpreta *a contagem* como o número de dígitos após o ponto decimal.

No C++, o uso dessa função é simplificado por uma sobrecarga de modelo. A sobrecarga pode inferir o tamanho do buffer automaticamente, eliminando a necessidade de especificar um argumento de tamanho. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

A versão dedepuração desta função primeiro preenche o buffer com 0xFE. Para desabilitar esse comportamento, use [_CrtSetDebugFillThreshold](crtsetdebugfillthreshold.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

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

## <a name="see-also"></a>Confira também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[atof, _atof_l, _wtof, _wtof_l](atof-atof-l-wtof-wtof-l.md)<br/>
[_ecvt_s](ecvt-s.md)<br/>
[_gcvt_s](gcvt-s.md)<br/>
[_fcvt](fcvt.md)<br/>
