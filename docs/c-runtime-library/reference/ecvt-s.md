---
title: _ecvt_s
ms.date: 4/2/2020
api_name:
- _ecvt_s
- _o__ecvt_s
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
- ecvt_s
- _ecvt_s
helpviewer_keywords:
- _ecvt_s function
- ecvt_s function
- numbers, converting
- converting double numbers
ms.assetid: d52fb0a6-cb91-423f-80b3-952a8955d914
ms.openlocfilehash: e33840e772de770e0f05ae45d2c2d4bec7e09939
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81348053"
---
# <a name="_ecvt_s"></a>_ecvt_s

Converte um número **duplo** em uma seqüência. Trata-se de uma versão de [_ecvt](ecvt.md) com melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

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

*_Value*<br/>
Número a ser convertido.

*_Count*<br/>
Número de dígitos armazenados.

*_Dec*<br/>
Posição do ponto decimal armazenada.

*_Sign*<br/>
Sinal do número convertido.

## <a name="return-value"></a>Valor retornado

Zero se for bem-sucedido. Se houver uma falha, o valor retornado será um código de erro. Códigos de erro são definidos em Errno.h. Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

No caso de um parâmetro inválido, conforme listado na tabela a seguir, essa função invoca o manipulador de parâmetro inválido, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, esta função define **errno** para **EINVAL** e retorna **EINVAL**.

### <a name="error-conditions"></a>Condições de erro

|*_Buffer*|*_SizeInBytes*|_Value|_Count|_Dec|_Sign|Valor retornado|Valor em *buffer*|
|---------------|--------------------|-------------|-------------|-----------|------------|------------------|-----------------------|
|**NULO**|any|any|any|any|any|**Einval**|Não modificado.|
|Não **NULL** (pontos para memória válida)|<=0|any|any|any|any|**Einval**|Não modificado.|
|any|any|any|any|**NULO**|any|**Einval**|Não modificado.|
|any|any|any|any|any|**NULO**|**Einval**|Não modificado.|

## <a name="security-issues"></a>Problemas de segurança

**_ecvt_s** pode gerar uma violação de acesso se *o buffer* não apontar para a memória válida e não for **NULL**.

## <a name="remarks"></a>Comentários

A função **_ecvt_s** converte um número de ponto flutuante em uma seqüência de caracteres. O parâmetro *_Value* é o número de ponto flutuante a ser convertido. Esta função armazena até *contar* dígitos de *_Value* como uma seqüência de caracteres e anexa um caractere nulo ('\0'). Se o número de dígitos em *_Value* exceder *_Count,* o dígito de baixa ordem é arredondado. Se houver menos de dígitos *de contagem,* a seqüência é acolchoada com zeros.

Somente dígitos são armazenados na cadeia de caracteres. A posição do ponto decimal e o sinal de *_Value* podem ser obtidos de *_Dec* e *_Sign* após a chamada. O parâmetro *_Dec* aponta para um valor inteiro dando a posição do ponto decimal em relação ao início da seqüência. Um valor inteiro de 0 ou negativo indica que o ponto decimal se encontra à esquerda do primeiro dígito. O parâmetro *_Sign* aponta para um inteiro que indica o sinal do número convertido. Se o valor inteiro for 0, o número será positivo. Caso contrário, o resultado será negativo.

Um tampão de comprimento **_CVTBUFSIZE** é suficiente para qualquer valor de ponto flutuante.

A diferença entre **_ecvt_s** e **_fcvt_s** está na interpretação do parâmetro *_Count.* **_ecvt_s** interpreta *_Count* como o número total de dígitos na cadeia de saída, enquanto **_fcvt_s** interpreta *_Count* como o número de dígitos após o ponto decimal.

No C++, o uso dessa função é simplificado por uma sobrecarga de modelo. A sobrecarga pode inferir o tamanho do buffer automaticamente, eliminando a necessidade de especificar um argumento de tamanho. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

A versão dedepuração desta função primeiro preenche o buffer com 0xFE. Para desabilitar esse comportamento, use [_CrtSetDebugFillThreshold](crtsetdebugfillthreshold.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

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

## <a name="see-also"></a>Confira também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[atof, _atof_l, _wtof, _wtof_l](atof-atof-l-wtof-wtof-l.md)<br/>
[_ecvt](ecvt.md)<br/>
[_fcvt_s](fcvt-s.md)<br/>
[_gcvt_s](gcvt-s.md)<br/>
