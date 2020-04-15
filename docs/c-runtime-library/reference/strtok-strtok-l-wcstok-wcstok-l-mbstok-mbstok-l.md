---
title: strtok, _strtok_l, wcstok, _wcstok_l, _mbstok, _mbstok_l
ms.date: 4/2/2020
api_name:
- _mbstok_l
- _mbstok
- wcstok
- _mbstok
- strtok
- _wcstok_l
- _o__mbstok
- _o__mbstok_l
- _o_strtok
- _o_wcstok
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
- api-ms-win-crt-multibyte-l1-1-0.dll
- api-ms-win-crt-string-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _mbstok
- strtok
- _tcstok
- wcstok
helpviewer_keywords:
- mbstok_l function
- strings [C++], searching
- tcstok function
- _tcstok function
- _strtok_l function
- strtok function
- mbstok function
- wcstok_l function
- _mbstok function
- tcstok_l function
- tokens, finding in strings
- _mbstok_l function
- wcstok function
- _wcstok_l function
- _tcstok_l function
- strtok_l function
ms.assetid: 904cb734-f0d7-4d77-ba81-4791ddf461ae
ms.openlocfilehash: d228d9824c534a21e4a22797e4b070e6d8d0b179
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365192"
---
# <a name="strtok-_strtok_l-wcstok-_wcstok_l-_mbstok-_mbstok_l"></a>strtok, _strtok_l, wcstok, _wcstok_l, _mbstok, _mbstok_l

Localiza o próximo token em uma cadeia de caracteres usando a localidade atual ou uma localidade específica que é informada. Versões mais seguras dessas funções estão disponíveis; consulte [strtok_s, _strtok_s_l, wcstok_s, _wcstok_s_l, _mbstok_s, _mbstok_s_l](strtok-s-strtok-s-l-wcstok-s-wcstok-s-l-mbstok-s-mbstok-s-l.md).

> [!IMPORTANT]
> **_mbstok** e **_mbstok_l** não podem ser usados em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
char *strtok(
   char *strToken,
   const char *strDelimit
);
char *strtok_l(
   char *strToken,
   const char *strDelimit,
   _locale_t locale
);
wchar_t *wcstok(
   wchar_t *strToken,
   const wchar_t *strDelimit
);
wchar_t *wcstok_l(
   wchar_t *strToken,
   const wchar_t *strDelimit,
   _locale_t locale
);
unsigned char *_mbstok(
   unsigned char *strToken,
   const unsigned char *strDelimit
);
unsigned char *_mbstok_l(
   unsigned char *strToken,
   const unsigned char *strDelimit,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*Strtoken*<br/>
Cadeia de caracteres que contém o token ou os tokens.

*strDelimit*<br/>
Conjunto de caracteres delimitadores.

*Localidade*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor retornado

Retorna um ponteiro para o próximo token encontrado em *strToken*. As funções retornam **NULL** quando não forem encontrados mais tokens. Cada chamada modifica *strToken* substituindo um caractere nulo pelo primeiro delimitador que ocorre após o token retornado.

## <a name="remarks"></a>Comentários

A função **strtok** encontra o próximo token em *strToken*. O conjunto de caracteres em *strDelimit* especifica possíveis delimitadores do token a serem encontrados no *strToken* na chamada atual. **wcstok** e **_mbstok** são versões de amplo caráter e multibytes de **strtok**. Os argumentos e o valor de retorno do **wcstok** são strings de caracteres amplos; os de **_mbstok** são cordas de caracteres multibyte. Caso contrário, essas três funções se comportam de forma idêntica.

> [!IMPORTANT]
> Essas funções acarretam uma ameaça em potencial em relação ao problema de estouro de buffer. Os problemas de estouro de buffer são um método frequente de ataque ao sistema, resultando em uma elevação de privilégio sem garantia. Para obter mais informações, consulte [Avoiding Buffer Overruns](/windows/win32/SecBP/avoiding-buffer-overruns) (Evitando estouros de buffer).

Na primeira chamada para **strtok,** a função pula os principais delimitadores e retorna um ponteiro para o primeiro token em *strToken,* terminando o token com um caractere nulo. Mais tokens podem ser quebrados do restante do *strToken* por uma série de chamadas para **strtok**. Cada chamada para **strtok** modifica *strToken* inserindo um caractere nulo após o **token** retornar por essa chamada. Para ler o próximo token do *strToken*, ligue **para strtok** com um valor **NULL** para o argumento *strToken.* O argumento **NULL** *strToken* faz com que **o strtok** procure o próximo token no *strToken*modificado . O argumento *strDelimit* pode levar qualquer valor de uma chamada para a próxima, de modo que o conjunto de delimitadores possa variar.

O valor de saída é afetado pela configuração da configuração da categoria **LC_CTYPE** do local. Para obter mais informações sobre, consulte [setlocale](setlocale-wsetlocale.md).

As versões dessas funções sem o **sufixo _l** usam a localidade atual para este comportamento dependente da localidade. As versões com o **sufixo _l** são idênticas, exceto que eles usam o parâmetro local passado em seu lugar. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

> [!NOTE]
> Cada função usa uma variável estática de thread local para classificar a cadeia de caracteres em tokens. Portanto, vários threads simultaneamente podem chamar essas funções sem efeitos indesejáveis. No entanto, em um único thread, chamadas intercaladas para uma dessas funções é tende muito a causar dados corrompidos e resultados imprecisos. Ao classificar cadeias de caracteres diferentes, termine de classificar uma cadeia de caracteres antes de começar a analisar a próxima. Além disso, fique ciente do potencial de risco ao chamar uma dessas funções de dentro de um loop em que outra função seja chamada. Se a outra função acaba usando uma dessas funções, uma sequência intercalada de chamadas resultará, disparando os dados corrompidos.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tcstok**|**strtok**|**_mbstok**|**wcstok**|
|**_tcstok**|**_strtok_l**|**_mbstok_l**|**_wcstok_l**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**strtok**|\<string.h>|
|**wcstok**|\<string.h> ou \<wchar.h>|
|**_mbstok** **_mbstok_l**|\<mbstring.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_strtok.c
// compile with: /W3
// In this program, a loop uses strtok
// to print all the tokens (separated by commas
// or blanks) in the string named "string".
//
#include <string.h>
#include <stdio.h>

char string[] = "A string\tof ,,tokens\nand some  more tokens";
char seps[]   = " ,\t\n";
char *token;

int main( void )
{
   printf( "Tokens:\n" );

   // Establish string and get the first token:
   token = strtok( string, seps ); // C4996
   // Note: strtok is deprecated; consider using strtok_s instead
   while( token != NULL )
   {
      // While there are tokens in "string"
      printf( " %s\n", token );

      // Get next token:
      token = strtok( NULL, seps ); // C4996
   }
}
```

```Output
Tokens:
A
string
of
tokens
and
some
more
tokens
```

## <a name="see-also"></a>Confira também

[Manipulação de cordas](../../c-runtime-library/string-manipulation-crt.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
[strcspn, wcscspn, _mbscspn, _mbscspn_l](strcspn-wcscspn-mbscspn-mbscspn-l.md)<br/>
[strspn, wcsspn, _mbsspn, _mbsspn_l](strspn-wcsspn-mbsspn-mbsspn-l.md)<br/>
