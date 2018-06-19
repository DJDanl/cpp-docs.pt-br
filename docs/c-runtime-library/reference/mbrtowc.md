---
title: mbrtowc | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- mbrtowc
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
- mbrtowc
dev_langs:
- C++
helpviewer_keywords:
- mbrtowc function
ms.assetid: a1e87fcc-6de0-4ca1-bf26-508d28490286
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 256c3df754607d0d9321f87d565e2ce94491035c
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32405309"
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

*wchar*<br/>
Endereço de um caractere largo para receber a cadeia de caracteres largos convertido (tipo **wchar_t**). Esse valor poderá ser um ponteiro nulo se não for necessário nenhum caractere largo de retorno.

*mbchar*<br/>
Endereço de uma sequência de bytes (um caractere multibyte).

*count*<br/>
O número de bytes a serem verificados.

*mbstate*<br/>
O ponteiro para um objeto do estado da conversão. Se esse valor for um ponteiro nulo, a função usará um objeto de estado de conversão interna estática. Porque o interno **mbstate_t** objeto não é thread-safe, recomendamos que você sempre passa seu próprio *mbstate* argumento.

## <a name="return-value"></a>Valor de retorno

Um dos seguintes valores:

0 a próxima *contagem* ou menos bytes concluir os caracteres multibyte que representa o caractere largo nulo, que é armazenado em *wchar*, se *wchar* não é um ponteiro nulo.

1 para *contagem*, inclusive o próximo *contagem* ou menos bytes concluir um caractere multibyte válido. O valor retornado é o número de bytes que completa os caracteres multibyte. O caractere largo equivalente é armazenado em *wchar*, se *wchar* não é um ponteiro nulo.

(size_t) (-1) Ocorreu um erro de codificação. O próximo *contagem* ou menos bytes não contribuem para um caractere multibyte completo e válido. Nesse caso, **errno** está definida como EILSEQ e o estado de shift conversão em *mbstate* não está especificado.

(size_t) -(2) O próximo *contagem* bytes contribuem para um caractere multibyte incompleto, mas potencialmente válido e todos os *contagem* bytes foram processados. Nenhum valor é armazenado em *wchar*, mas *mbstate* é atualizado para reiniciar a função.

## <a name="remarks"></a>Comentários

Se *mbchar* é um ponteiro nulo, a função é equivalente à chamada de:

`mbrtowc(NULL, "", 1, &mbstate)`

Nesse caso, o valor dos argumentos *wchar* e *contagem* são ignorados.

Se *mbchar* não é um ponteiro nulo, a função examina *contagem* bytes do *mbchar* para determinar o número de bytes que são necessárias para concluir a próxima necessário caracteres multibyte. Se o próximo caractere for válido, o caractere de multibyte correspondente é armazenado em *wchar* se não for um ponteiro nulo. Se o caractere for correspondente nulo todo caractere, o estado resultante do *mbstate* é o estado inicial de conversão.

O **mbrtowc** função difere da [mbtowc, mbtowc_l](mbtowc-mbtowc-l.md) por sua capacidade de reinicialização. O estado de conversão é armazenado em *mbstate* para chamadas subsequentes para o mesmo ou outras funções reiniciáveis. Os resultados são indefinidos ao combinar o uso de funções reiniciáveis e não reiniciáveis.  Por exemplo, um aplicativo deve usar **wcsrlen** em vez de **wcslen** se uma chamada subsequente para **wcsrtombs** é usado em vez de **wcstombs**.

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

### <a name="sample-output"></a>Saída de Exemplo

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

## <a name="see-also"></a>Consulte também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
