---
title: _ecvt_s | Microsoft Docs
ms.custom: ''
ms.date: 04/05/2018
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _ecvt_s
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
- ecvt_s
- _ecvt_s
dev_langs:
- C++
helpviewer_keywords:
- _ecvt_s function
- ecvt_s function
- numbers, converting
- converting double numbers
ms.assetid: d52fb0a6-cb91-423f-80b3-952a8955d914
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 623d12bb515794a1d57b5a18e0e93e70d50a6812
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32404354"
---
# <a name="ecvts"></a>_ecvt_s

Converte um **duplo** número em uma cadeia de caracteres. Trata-se de uma versão de [_ecvt](ecvt.md) com melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t _ecvt_s(
   char * _Buffer,
   size_t _SizeInBytes,
   double _Value,
   int _Count,
   int *_Dec,
   int *_Sign
);
template <size_t size>
errno_t _ecvt_s(
   char (&_Buffer)[size],
   double _Value,
   int _Count,
   int *_Dec,
   int *_Sign
); // C++ only
```

### <a name="parameters"></a>Parâmetros

*_Buffer*<br/>
Preenchido com o ponteiro para a cadeia de caracteres de dígitos, o resultado da conversão.

*_SizeInBytes*<br/>
O tamanho do buffer em bytes.

*Value*<br/>
Número a ser convertido.

*Count*<br/>
Número de dígitos armazenados.

*_Dec*<br/>
Posição do ponto decimal armazenada.

*Entrar*<br/>
Sinal do número convertido.

## <a name="return-value"></a>Valor de retorno

Zero se for bem-sucedido. Se houver uma falha, o valor retornado será um código de erro. Códigos de erro são definidos em Errno.h. Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

No caso de um parâmetro inválido, conforme listado na tabela a seguir, essa função invoca o manipulador de parâmetro inválido, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, esta função define **errno** para **EINVAL** e retorna **EINVAL**.

### <a name="error-conditions"></a>Condições de Erro

|*_Buffer*|*_SizeInBytes*|_Value|_Count|_Dec|_Sign|Valor retornado|Valor em *buffer*|
|---------------|--------------------|-------------|-------------|-----------|------------|------------------|-----------------------|
|**NULL**|qualquer|qualquer|qualquer|qualquer|qualquer|**EINVAL**|Não modificado.|
|Não **nulo** (aponta válido da memória)|<=0|qualquer|qualquer|qualquer|qualquer|**EINVAL**|Não modificado.|
|qualquer|qualquer|qualquer|qualquer|**NULL**|qualquer|**EINVAL**|Não modificado.|
|qualquer|qualquer|qualquer|qualquer|qualquer|**NULL**|**EINVAL**|Não modificado.|

## <a name="security-issues"></a>Problemas de segurança

**ecvt_s** pode gerar uma violação de acesso se *buffer* não aponta para memória válido e não é **nulo**.

## <a name="remarks"></a>Comentários

O **ecvt_s** função converte um número de ponto flutuante em uma cadeia de caracteres. O *Value* parâmetro é o número de ponto flutuante a ser convertido. Essa função armazena até *contagem* dígitos de *Value* como uma cadeia de caracteres e acrescenta um caractere nulo ('\0'). Se o número de dígitos em *Value* excede *Count*, os dígitos de ordem inferior será arredondado. Se houver menos de *contagem* dígitos, a cadeia de caracteres é preenchida com zeros.

Somente dígitos são armazenados na cadeia de caracteres. A posição do ponto decimal e o sinal de *Value* pode ser obtido *_Dec* e *entrar* após a chamada. O *_Dec* parâmetro aponta para um valor inteiro dando a posição do ponto decimal em relação ao início da cadeia de caracteres. Um valor inteiro de 0 ou negativo indica que o ponto decimal se encontra à esquerda do primeiro dígito. O *entrar* parâmetro aponta para um número inteiro que indica o sinal do número convertido. Se o valor inteiro for 0, o número será positivo. Caso contrário, o resultado será negativo.

Um buffer de comprimento **_CVTBUFSIZE** é suficiente para qualquer valor de ponto flutuante.

A diferença entre **ecvt_s** e **fcvt_s** está na interpretação de *Count* parâmetro. **ecvt_s** interpreta *Count* como o número total de dígitos na cadeia de saída, enquanto **fcvt_s** interpreta *Count* como o número de dígitos depois o ponto decimal.

No C++, o uso dessa função é simplificado por uma sobrecarga de modelo. A sobrecarga pode inferir o tamanho do buffer automaticamente, eliminando a necessidade de especificar um argumento de tamanho. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

A versão de depuração dessa função preenche primeiro o buffer com 0xFD. Para desabilitar esse comportamento, use [_CrtSetDebugFillThreshold](crtsetdebugfillthreshold.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|Cabeçalho opcional|
|--------------|---------------------|---------------------|
|**_ecvt_s**|\<stdlib.h>|\<errno.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// ecvt_s.c
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main( )
{
    char * buf = 0;
    int decimal;
    int sign;
    int err;

    buf = (char*) malloc(_CVTBUFSIZE);
    err = _ecvt_s(buf, _CVTBUFSIZE, 1.2, 5, &decimal, &sign);

    if (err != 0)
    {
        printf("_ecvt_s failed with error code %d\n", err);
        exit(1);
    }

    printf("Converted value: %s\n", buf);
}
```

```Output
Converted value: 12000
```

## <a name="see-also"></a>Consulte também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[atof, _atof_l, _wtof, _wtof_l](atof-atof-l-wtof-wtof-l.md)<br/>
[_ecvt](ecvt.md)<br/>
[_fcvt_s](fcvt-s.md)<br/>
[_gcvt_s](gcvt-s.md)<br/>
