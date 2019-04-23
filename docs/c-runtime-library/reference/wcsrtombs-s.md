---
title: wcsrtombs_s
ms.date: 11/04/2016
apiname:
- wcsrtombs_s
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
- wcsrtombs_s
helpviewer_keywords:
- string conversion, wide characters
- wcsrtombs_s function
- wide characters, strings
ms.assetid: 9dccb766-113c-44bb-9b04-07a634dddec8
ms.openlocfilehash: bd965271a65fa91b427c7af7bbd4173b129e1d8c
ms.sourcegitcommit: 14b292596bc9b9b883a9c58cd3e366b282a1f7b3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2019
ms.locfileid: "60124909"
---
# <a name="wcsrtombss"></a>wcsrtombs_s

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
O tamanho em bytes do *mbstr* buffer.

*wcstr*<br/>
Aponta para a cadeia de caracteres largos a ser convertida.

*count*<br/>
O número máximo de bytes a ser armazenado na *mbstr* buffer, ou [TRUNCATE](../../c-runtime-library/truncate.md).

*mbstate*<br/>
Um ponteiro para um **mbstate_t** objeto de estado de conversão.

## <a name="return-value"></a>Valor de retorno

Zero se for bem-sucedido ou um código de erro em caso de falha.

|Condição de erro|Valor de retorno e **errno**|
|---------------------|------------------------------|
|*mbstr* está **nulo** e *sizeInBytes* > 0|**EINVAL**|
|*wcstr* é **nulo**|**EINVAL**|
|O buffer de destino é muito pequeno para conter a cadeia de caracteres convertida (a menos que *contagem* é **TRUNCATE**; consulte os comentários abaixo)|**ERANGE**|

Se qualquer uma dessas condições ocorrer, a exceção de parâmetro inválido será invocada, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, a função retorna um código de erro e definirá **errno** conforme indicado na tabela.

## <a name="remarks"></a>Comentários

O **wcsrtombs_s** função converte uma cadeia de caracteres largos apontada por *wcstr* em caracteres multibyte armazenados no buffer apontado por *mbstr*, usando o estado de conversão contido em *mbstate*. A conversão continuará para cada caractere até que uma das seguintes condições seja atendida:

- Um caractere largo nulo é encontrado

- Um caractere largo que não pode ser convertido é encontrado

- O número de bytes armazenados na *mbstr* buffer equals *contagem*.

A cadeia de caracteres de destino sempre é terminada em nulo (mesmo em caso de erro).

Se *contagem* é o valor especial [TRUNCATE](../../c-runtime-library/truncate.md), em seguida, **wcsrtombs_s** converterá grande parte da cadeia de caracteres que caberá no buffer de destino ainda deixando espaço para um valor nulo terminador.

Se **wcsrtombs_s** converte com êxito a cadeia de caracteres de origem, ele colocará o tamanho em bytes da cadeia de caracteres convertida, incluindo o terminador nulo, em  *&#42;pReturnValue* (fornecido  *pReturnValue* não é **nulo**). Isso ocorre mesmo se o *mbstr* argumento é **nulo** e fornece uma maneira de determinar o tamanho do buffer. Observe que, se *mbstr* é **nulo**, *contagem* será ignorado.

Se **wcsrtombs_s** encontrar um caractere largo que não é possível converter um caractere multibyte, ele colocará -1 em  *\*pReturnValue*, definirá o buffer de destino como uma cadeia de caracteres vazia, definirá **errno** para **EILSEQ**e retorna **EILSEQ**.

Se as sequências apontadas por *wcstr* e *mbstr* se sobrepõem, o comportamento do **wcsrtombs_s** é indefinido. **wcsrtombs_s** é afetado pela categoria LC_TYPE da localidade atual.

> [!IMPORTANT]
> Certifique-se de que *wcstr* e *mbstr* não se sobrepõem e que *contagem* reflete corretamente o número de caracteres largos a ser convertido.

O **wcsrtombs_s** função difere [wcstombs_s, wcstombs_s_l](wcstombs-s-wcstombs-s-l.md) por sua capacidade de reinicialização. O estado de conversão é armazenado em *mbstate* para chamadas posteriores às mesmas funções ou outras funções reiniciáveis. Os resultados são indefinidos ao combinar o uso de funções reiniciáveis e não reiniciáveis. Por exemplo, um aplicativo usaria **wcsrlen** vez **wcslen**, se uma chamada subsequente para **wcsrtombs_s** foram usadas em vez de **wcstombs_s**.

Em C++, o uso dessas funções é simplificado pelas sobrecargas de modelo; as sobrecargas podem inferir o tamanho do buffer automaticamente (eliminando a necessidade de especificar um argumento de tamanho) e podem substituir automaticamente funções mais antigas e não seguras por suas equivalentes mais recentes e seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

## <a name="exceptions"></a>Exceções

O **wcsrtombs_s** função será multithread-safe contanto que nenhuma função no thread atual chame **setlocale** enquanto essa função está em execução e o *mbstate* é nulo.

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
