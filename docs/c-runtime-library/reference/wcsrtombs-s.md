---
title: wcsrtombs_s
ms.date: 11/04/2016
api_name:
- wcsrtombs_s
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
- wcsrtombs_s
helpviewer_keywords:
- string conversion, wide characters
- wcsrtombs_s function
- wide characters, strings
ms.assetid: 9dccb766-113c-44bb-9b04-07a634dddec8
ms.openlocfilehash: bd43e4d4bf3a916f83fb014fc85aa5270fbd4c51
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70945179"
---
# <a name="wcsrtombs_s"></a>wcsrtombs_s

Converte uma cadeia de caracteres largos em sua representação de cadeia de caracteres multibyte. Uma versão de [wcsrtombs](wcsrtombs.md) com melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t wcsrtombs_s(
   size_t *pReturnValue,
   char *mbstr,
   size_t sizeInBytes,
   const wchar_t **wcstr,
   sizeof count,
   mbstate_t *mbstate
);
template <size_t size>
errno_t wcsrtombs_s(
   size_t *pReturnValue,
   char (&mbstr)[size],
   const wchar_t **wcstr,
   sizeof count,
   mbstate_t *mbstate
); // C++ only
```

### <a name="parameters"></a>Parâmetros

*pReturnValue*<br/>
O tamanho em bytes da cadeia de caracteres convertida, incluindo o terminador nulo.

*mbstr*<br/>
O endereço de um buffer da cadeia de caracteres multibyte convertida resultante.

*sizeInBytes*<br/>
O tamanho em bytes do buffer *mbstr* .

*wcstr*<br/>
Aponta para a cadeia de caracteres largos a ser convertida.

*count*<br/>
O número máximo de bytes a serem armazenados no buffer *mbstr* ou [_TRUNCATE](../../c-runtime-library/truncate.md).

*mbstate*<br/>
Um ponteiro para um objeto de estado de conversão **mbstate_t** .

## <a name="return-value"></a>Valor de retorno

Zero se for bem-sucedido ou um código de erro em caso de falha.

|Condição de erro|Valor de retorno e **errno**|
|---------------------|------------------------------|
|*mbstr* é **nulo** e *sizeInBytes* > 0|**EINVAL**|
|*wcstr* é **nulo**|**EINVAL**|
|O buffer de destino é muito pequeno para conter a cadeia de caracteres convertida (a menos que a *contagem* seja **_TRUNCATE**; consulte os comentários abaixo)|**ERANGE**|

Se qualquer uma dessas condições ocorrer, a exceção de parâmetro inválido será invocada, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, a função retornará um código de erro e definirá **errno** como indicado na tabela.

## <a name="remarks"></a>Comentários

A função **wcsrtombs_s** converte uma cadeia de caracteres largos apontados por *wcstr* em caracteres multibyte armazenados no buffer apontado pelo *mbstr*, usando o estado de conversão contido em *mbstate*. A conversão continuará para cada caractere até que uma das seguintes condições seja atendida:

- Um caractere largo nulo é encontrado

- Um caractere largo que não pode ser convertido é encontrado

- O número de bytes armazenados na *contagem*de Equals do buffer *mbstr* .

A cadeia de caracteres de destino sempre é terminada em nulo (mesmo em caso de erro).

Se *Count* for o valor especial [_TRUNCATE](../../c-runtime-library/truncate.md), **wcsrtombs_s** converterá a maior parte da cadeia de caracteres que se ajustará ao buffer de destino, enquanto ainda deixará espaço para um terminador nulo.

Se **wcsrtombs_s** converter com êxito a cadeia de caracteres de origem, ela colocará o tamanho em bytes da cadeia de caracteres convertida, incluindo o terminador nulo, em  *&#42;pretransformvalue* (a *preactivavalue* fornecida não é **nula**). Isso ocorre mesmo que o argumento *mbstr* seja **nulo** e forneça uma maneira de determinar o tamanho do buffer necessário. Observe que, se *mbstr* for **NULL**, *Count* será ignorado.

Se **wcsrtombs_s** encontrar um caractere largo, ele não poderá converter para um caractere multibyte, ele colocará-1 em  *\*preligávalue*, definirá o buffer de destino como uma cadeia de caracteres vazia, definirá **errno** como **EILSEQ**e retornará **EILSEQ** .

Se as sequências apontadas por *wcstr* e *mbstr* se sobrepõem, o comportamento de **wcsrtombs_s** é indefinido. **wcsrtombs_s** é afetado pela categoria LC_TYPE da localidade atual.

> [!IMPORTANT]
> Verifique se *wcstr* e *mbstr* não se sobrepõem e se *Count* reflete corretamente o número de caracteres largos a serem convertidos.

A função **wcsrtombs_s** difere de [wcstombs_s, _wcstombs_s_l](wcstombs-s-wcstombs-s-l.md) por sua reinicialização. O estado de conversão é armazenado em *mbstate* para chamadas subsequentes para as mesmas ou outras funções reiniciáveis. Os resultados são indefinidos ao combinar o uso de funções reiniciáveis e não reiniciáveis. Por exemplo, um aplicativo usaria **wcsrlen** em vez de **wcslen**, se uma chamada subsequente para **wcsrtombs_s** fosse usada em vez de **wcstombs_s**.

Em C++, o uso dessas funções é simplificado pelas sobrecargas de modelo; as sobrecargas podem inferir o tamanho do buffer automaticamente (eliminando a necessidade de especificar um argumento de tamanho) e podem substituir automaticamente funções mais antigas e não seguras por suas equivalentes mais recentes e seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

## <a name="exceptions"></a>Exceções

A função **wcsrtombs_s** é multithread segura, desde que nenhuma função no thread atual chame **setlocalize** enquanto essa função está em execução e o *mbstate* é nulo.

## <a name="example"></a>Exemplo

```cpp
// crt_wcsrtombs_s.cpp
//
// This code example converts a wide
// character string into a multibyte
// character string.
//

#include <stdio.h>
#include <memory.h>
#include <wchar.h>
#include <errno.h>

#define MB_BUFFER_SIZE 100

void main()
{
    const wchar_t   wcString[] =
                    {L"Every good boy does fine."};
    const wchar_t   *wcsIndirectString = wcString;
    char            mbString[MB_BUFFER_SIZE];
    size_t          countConverted;
    errno_t         err;
    mbstate_t       mbstate;

    // Reset to initial shift state
    ::memset((void*)&mbstate, 0, sizeof(mbstate));

    err = wcsrtombs_s(&countConverted, mbString, MB_BUFFER_SIZE,
                      &wcsIndirectString, MB_BUFFER_SIZE, &mbstate);
    if (err == EILSEQ)
    {
        printf( "An encoding error was detected in the string.\n" );
    }
    else
    {
        printf( "The string was successfully converted.\n" );
    }
}
```

```Output
The string was successfully converted.
```

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**wcsrtombs_s**|\<wchar.h>|

## <a name="see-also"></a>Consulte também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
[wcrtomb](wcrtomb.md)<br/>
[wcrtomb_s](wcrtomb-s.md)<br/>
[wctomb, _wctomb_l](wctomb-wctomb-l.md)<br/>
[wcstombs, _wcstombs_l](wcstombs-wcstombs-l.md)<br/>
[mbsinit](mbsinit.md)<br/>
