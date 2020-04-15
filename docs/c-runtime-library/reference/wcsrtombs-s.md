---
title: wcsrtombs_s
ms.date: 4/2/2020
api_name:
- wcsrtombs_s
- _o_wcsrtombs_s
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
- wcsrtombs_s
helpviewer_keywords:
- string conversion, wide characters
- wcsrtombs_s function
- wide characters, strings
ms.assetid: 9dccb766-113c-44bb-9b04-07a634dddec8
ms.openlocfilehash: 71a2206df9d3afb64fcaf62848988cf116d9071f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81328114"
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

*Preturnvalue*<br/>
O tamanho em bytes da seqüência convertida, incluindo o exterminador nulo.

*Mbstr*<br/>
O endereço de um buffer da cadeia de caracteres multibyte convertida resultante.

*Sizeinbytes*<br/>
O tamanho em bytes do tampão *mbstr.*

*Wcstr*<br/>
Aponta para a cadeia de caracteres largos a ser convertida.

*contagem*<br/>
O número máximo de bytes a serem armazenados no buffer *mbstr,* ou [_TRUNCATE](../../c-runtime-library/truncate.md).

*Mbstate*<br/>
Um ponteiro para um objeto de estado de conversão **mbstate_t.**

## <a name="return-value"></a>Valor retornado

Zero se for bem-sucedido ou um código de erro em caso de falha.

|Condição de erro|Valor de retorno e **errno**|
|---------------------|------------------------------|
|*mbstr* é **NULL** e *sizeInBytes* > 0|**Einval**|
|*wcstr* é **NULO**|**Einval**|
|O buffer de destino é muito pequeno para conter a seqüência convertida (a menos que a *contagem* seja **_TRUNCATE;** veja Observações abaixo)|**ERANGE**|

Se qualquer uma dessas condições ocorrer, a exceção de parâmetro inválido será invocada, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, a função retorna um código de erro e define **errno** como indicado na tabela.

## <a name="remarks"></a>Comentários

A função **wcsrtombs_s** converte uma seqüência de caracteres largos apontados por *wcstr* em caracteres multibytes armazenados no buffer apontado por *mbstr,* usando o estado de conversão contido em *mbstate*. A conversão continuará para cada caractere até que uma das seguintes condições seja atendida:

- Um caractere largo nulo é encontrado

- Um caractere largo que não pode ser convertido é encontrado

- O número de bytes armazenados no buffer *mbstr* é igual a *contagem*.

A cadeia de caracteres de destino sempre é terminada em nulo (mesmo em caso de erro).

Se *a contagem* for o valor especial [_TRUNCATE,](../../c-runtime-library/truncate.md)então **wcsrtombs_s** converte tanto da string quanto caberá no buffer de destino, enquanto ainda deixa espaço para um exterminador nulo.

Se **wcsrtombs_s** converter com sucesso a seqüência de origem, ela coloca o tamanho em bytes da seqüência de string convertida, incluindo o exterminador nulo, em *&#42;pReturnValue* (desde *que pReturnValue* não seja **NULL**). Isso ocorre mesmo que o argumento *mbstr* seja **NULO** e forneça uma maneira de determinar o tamanho de buffer necessário. Observe que se *o mbstr* for **NULL,** *a contagem* será ignorada.

Se **wcsrtombs_s** encontrar um caractere amplo, ele não poderá converter para um caractere multibyte, ele coloca -1 em * \*pReturnValue*, define o buffer de destino como uma seqüência vazia, define **errno** para **EILSEQ**e retorna **EILSEQ**.

Se as seqüências apontadas por *wcstr* e *mbstr* se sobrepõem, o comportamento de **wcsrtombs_s** é indefinido. **wcsrtombs_s** é afetado pela categoria LC_TYPE do local atual.

> [!IMPORTANT]
> Certifique-se de que *wcstr* e *mbstr* não se sobrepõem, e essa *contagem* reflete corretamente o número de caracteres largos a serem convertidos.

A função **wcsrtombs_s** difere [de wcstombs_s, _wcstombs_s_l](wcstombs-s-wcstombs-s-l.md) por sua capacidade de reinicialização. O estado de conversão é armazenado em *mbstate* para chamadas subseqüentes para as mesmas ou outras funções reinicializáveis. Os resultados são indefinidos ao combinar o uso de funções reiniciáveis e não reiniciáveis. Por exemplo, um aplicativo usaria **wcsrlen** em vez **de wcslen**, se uma chamada subseqüente para **wcsrtombs_s** fosse usada em vez de **wcstombs_s**.

Em C++, o uso dessas funções é simplificado pelas sobrecargas de modelo; as sobrecargas podem inferir o tamanho do buffer automaticamente (eliminando a necessidade de especificar um argumento de tamanho) e podem substituir automaticamente funções mais antigas e não seguras por suas equivalentes mais recentes e seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="exceptions"></a>Exceções

A função **wcsrtombs_s** é segura em vários segmentos, desde que nenhuma função no **setlocale** de chamadas de segmento atual enquanto esta função estiver sendo executada e o *mbstate* estiver nulo.

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

int main()
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

## <a name="see-also"></a>Confira também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
[wcrtomb](wcrtomb.md)<br/>
[wcrtomb_s](wcrtomb-s.md)<br/>
[wctomb, _wctomb_l](wctomb-wctomb-l.md)<br/>
[wcstombs, _wcstombs_l](wcstombs-wcstombs-l.md)<br/>
[mbsinit](mbsinit.md)<br/>
