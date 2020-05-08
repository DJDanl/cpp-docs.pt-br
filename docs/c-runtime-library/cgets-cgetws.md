---
title: _cgets, _cgetws
ms.date: 4/2/2020
api_name:
- _cgetws
- _cgets
- _o__cgets
- _o__cgetws
api_location:
- msvcr100.dll
- msvcr110.dll
- msvcr80.dll
- msvcr120.dll
- msvcr90.dll
- msvcrt.dll
- msvcr110_clr0400.dll
- ucrtbase.dll
- api-ms-win-crt-conio-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- cgetws
- _cgetws
- _cgets
helpviewer_keywords:
- _cgetws function
- strings [C++], getting from console
- console, getting strings from
- _cgets function
- cgetws function
- cgets function
ms.assetid: 4d5e134a-58c3-4f62-befd-5d235b0212f4
ms.openlocfilehash: 9ae7baaa01029dcf2c02f6ea80b6e816bb671596
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82917437"
---
# <a name="_cgets-_cgetws"></a>_cgets, _cgetws

Obtém uma cadeia de caracteres do console. Estão disponíveis versões mais seguras dessas funções; consulte [_cgets_s, _cgetws_s](../c-runtime-library/reference/cgets-s-cgetws-s.md).

> [!IMPORTANT]
> Essas funções estão obsoletas. A partir do Visual Studio 2015, elas não estão disponíveis no CRT. As versões seguras dessas funções, _cgets_s e _cgetws_s, ainda estão disponíveis. Para obter informações sobre essas funções alternativas, consulte [_cgets_s, _cgetws_s](../c-runtime-library/reference/cgets-s-cgetws-s.md).

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```
char *_cgets(
   char *buffer
);
wchar_t *_cgetws(
   wchar_t *buffer
);
template <size_t size>
char *_cgets(
   char (&buffer)[size]
); // C++ only
template <size_t size>
wchar_t *_cgetws(
   wchar_t (&buffer)[size]
); // C++ only
```

#### <a name="parameters"></a>Parâmetros

*completo*<br/>
Local de armazenamento de dados.

## <a name="return-value"></a>Valor retornado

`_cgets` e `_cgetws` retornam um ponteiro para o início da cadeia de caracteres, em `buffer[2]`. Se `buffer` for **NULL**, essas funções invocarão o manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../c-runtime-library/parameter-validation.md). Se a execução puder continuar, elas retornarão **NULL** e definirão `errno` como `EINVAL`.

## <a name="remarks"></a>Comentários

Essas funções leem uma cadeia de caracteres do console e armazenam a cadeia de caracteres e seu comprimento no local apontado por `buffer`. O parâmetro `buffer` deve ser um ponteiro para uma matriz de caracteres. O primeiro elemento da matriz, `buffer[0]`, deve conter o tamanho máximo (em caracteres) da cadeia de caracteres a ser lida. A matriz deve conter elementos suficientes para conter a cadeia de caracteres, um caractere nulo de terminação ('\0') e 2 bytes adicionais. A função lê caracteres até uma combinação de CR-LF (retorno de carro – alimentação de linha) ou o número especificado de caracteres ser lido. A cadeia de caracteres é armazenada começando em `buffer[2]`. Se a função ler CR-LF, ela armazenará o caractere nulo ('\0'). A função então armazena o tamanho real da cadeia de caracteres no segundo elemento de matriz, `buffer[1]`.

Uma vez que todas as chaves de edição estão ativas quando `_cgets` ou `_cgetws` é chamado enquanto estiver em uma janela do console, pressionar a tecla F3 repete a última entrada digitada.

No C++, essas funções têm sobrecargas de modelo que invocam os equivalentes mais novos e seguros dessas funções. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../c-runtime-library/secure-template-overloads.md).

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|`_cgetts`|`_cgets`|`_cgets`|`_cgetws`|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|`_cgets`|\<conio.h>|
|`_cgetws`|\<conio.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```c
// crt_cgets.c
// compile with: /c /W3
// This program creates a buffer and initializes
// the first byte to the size of the buffer. Next, the
// program accepts an input string using _cgets and displays
// the size and text of that string.

#include <conio.h>
#include <stdio.h>
#include <errno.h>

int main( void )
{
   char buffer[83] = { 80 };  // Maximum characters in 1st byte
   char *result;

   printf( "Input line of text, followed by carriage return:\n");

   // Input a line of text:
   result = _cgets( buffer ); // C4996
   // Note: _cgets is deprecated; consider using _cgets_s
   if (!result)
   {
      printf( "An error occurred reading from the console:"
              " error code %d\n", errno);
   }
   else
   {
      printf( "\nLine length = %d\nText = %s\n",
              buffer[1], result );
   }
}
```

```Output

      A line of input.Input line of text, followed by carriage return:
Line Length = 16
Text = A line of input.
```

## <a name="see-also"></a>Confira também

[E/s de porta e de console](../c-runtime-library/console-and-port-i-o.md)<br/>
[_getch, _getwch](../c-runtime-library/reference/getch-getwch.md)
