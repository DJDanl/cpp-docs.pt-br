---
title: mbrtowc
ms.date: 4/2/2020
api_name:
- mbrtowc
- _o_mbrtowc
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
- mbrtowc
helpviewer_keywords:
- mbrtowc function
ms.assetid: a1e87fcc-6de0-4ca1-bf26-508d28490286
ms.openlocfilehash: be46c3f3c728b70c7cbf060572acc24662637a81
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81340924"
---
# <a name="mbrtowc"></a>mbrtowc

Converta um caractere multibyte na localidade atual no caractere largo equivalente, com a capacidade de reiniciar no meio de um caractere multibyte.

## <a name="syntax"></a>Sintaxe

```C
size_t mbrtowc(
   wchar_t *wchar,
   const char *mbchar,
   size_t count,
   mbstate_t *mbstate
);
```

### <a name="parameters"></a>Parâmetros

*Wchar*<br/>
Endereço de um caractere amplo para receber a seqüência de caracteres amplas convertida (tipo **wchar_t**). Esse valor poderá ser um ponteiro nulo se não for necessário nenhum caractere largo de retorno.

*Mbchar*<br/>
Endereço de uma sequência de bytes (um caractere multibyte).

*contagem*<br/>
O número de bytes a serem verificados.

*Mbstate*<br/>
O ponteiro para um objeto do estado da conversão. Se esse valor for um ponteiro nulo, a função usará um objeto de estado de conversão interna estática. Como o objeto **mbstate_t** interno não é seguro para threads, recomendamos que você sempre passe seu próprio argumento *de mbstate.*

## <a name="return-value"></a>Valor retornado

Um dos seguintes valores:

0 A próxima *contagem* ou menos bytes completam o caractere multibyte que representa o caractere de largura nulo, que é armazenado em *wchar*, se *wchar* não for um ponteiro nulo.

1 para *contar,* inclusive A próxima *contagem* ou menos bytes completam um caractere multibyte válido. O valor retornado é o número de bytes que completa os caracteres multibyte. O equivalente de caractere largo é armazenado em *wchar,* se *wchar* não for um ponteiro nulo.

(size_t) (-1) Ocorreu um erro de codificação. A próxima *contagem* ou menos bytes não contribuem para um caractere multibyte completo e válido. Neste caso, **errno** é definido como EILSEQ e o estado de mudança de conversão em *mbstate* não é especificado.

(size_t) (-2) Os próximos bytes *de contagem* contribuem para um caractere multibyte incompleto, mas potencialmente válido, e todos os bytes *de contagem* foram processados. Nenhum valor é armazenado em *wchar,* mas *mbstate* é atualizado para reiniciar a função.

## <a name="remarks"></a>Comentários

Se *mbchar* for um ponteiro nulo, a função é equivalente à chamada:

`mbrtowc(NULL, "", 1, &mbstate)`

Neste caso, o valor dos argumentos *wchar* e *contagem* são ignorados.

Se *mbchar* não for um ponteiro nulo, a função examinará os bytes de *contagem* de *mbchar* para determinar o número necessário de bytes necessários para completar o próximo caractere multibyte. Se o próximo caractere for válido, o caractere multibyte correspondente será armazenado em *wchar* se não for um ponteiro nulo. Se o caractere for o caractere nulo amplo correspondente, o estado resultante de *mbstate* é o estado de conversão inicial.

A função **mbrtowc** difere da [mbtowc, _mbtowc_l](mbtowc-mbtowc-l.md) por sua capacidade de reinicialização. O estado de conversão é armazenado em *mbstate* para chamadas subseqüentes para as mesmas ou outras funções reinicializáveis. Os resultados são indefinidos ao combinar o uso de funções reiniciáveis e não reiniciáveis.  Por exemplo, um aplicativo deve usar **wcsrlen** em vez de **wcslen** se uma chamada subseqüente para **wcsrtombs** for usada em vez de **wcstombs**.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="example"></a>Exemplo

Converte um caractere multibyte em seu caractere largo equivalente.

```cpp
// crt_mbrtowc.cpp

#include <stdio.h>
#include <mbctype.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>

#define BUF_SIZE 100

int Sample(char* szIn, wchar_t* wcOut, int nMax)
{
    mbstate_t   state = {0}; // Initial state
    size_t      nConvResult,
                nmbLen = 0,
                nwcLen = 0;
    wchar_t*    wcCur = wcOut;
    wchar_t*    wcEnd = wcCur + nMax;
    const char* mbCur = szIn;
    const char* mbEnd = mbCur + strlen(mbCur) + 1;
    char*       szLocal;

    // Sets all locale to French_Canada.1252
    szLocal = setlocale(LC_ALL, "French_Canada.1252");
    if (!szLocal)
    {
        printf("The fuction setlocale(LC_ALL, \"French_Canada.1252\") failed!\n");
        return 1;
    }

    printf("Locale set to: \"%s\"\n", szLocal);

    // Sets the code page associated current locale's code page
    // from a previous call to setlocale.
    if (_setmbcp(_MB_CP_SBCS) == -1)
    {
        printf("The fuction _setmbcp(_MB_CP_SBCS) failed!");
        return 1;
    }

    while ((mbCur < mbEnd) && (wcCur < wcEnd))
    {
        //
        nConvResult = mbrtowc(wcCur, mbCur, 1, &state);
        switch (nConvResult)
        {
            case 0:
            {  // done
                printf("Conversion succeeded!\nMultibyte String: ");
                printf(szIn);
                printf("\nWC String: ");
                wprintf(wcOut);
                printf("\n");
                mbCur = mbEnd;
                break;
            }

            case -1:
            {  // encoding error
                printf("The call to mbrtowc has detected an encoding error.\n");
                mbCur = mbEnd;
                break;
            }

            case -2:
            {  // incomplete character
                if   (!mbsinit(&state))
                {
                    printf("Currently in middle of mb conversion, state = %x\n", state);
                    // state will contain data regarding lead byte of mb character
                }

                ++nmbLen;
                ++mbCur;
                break;
            }

            default:
            {
                if   (nConvResult > 2) // The multibyte should never be larger than 2
                {
                    printf("Error: The size of the converted multibyte is %d.\n", nConvResult);
                }

                ++nmbLen;
                ++nwcLen;
                ++wcCur;
                ++mbCur;
            break;
            }
        }
    }

   return 0;
}

int main(int argc, char* argv[])
{
    char    mbBuf[BUF_SIZE] = "AaBbCc\x9A\x8B\xE0\xEF\xF0xXyYzZ";
    wchar_t wcBuf[BUF_SIZE] = {L''};

    return Sample(mbBuf, wcBuf, BUF_SIZE);
}
```

### <a name="sample-output"></a>Saída de exemplo

```Output
Locale set to: "French_Canada.1252"
Conversion succeeded!
Multibyte String: AaBbCcÜïα∩≡xXyYzZ
WC String: AaBbCcÜïα∩≡xXyYzZ
```

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**mbrtowc**|\<wchar.h>|

## <a name="see-also"></a>Confira também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
