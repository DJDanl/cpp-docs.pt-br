---
title: vsnprintf_s, _vsnprintf_s, _vsnprintf_s_l, _vsnwprintf_s, _vsnwprintf_s_l
ms.date: 11/04/2016
api_name:
- _vsnwprintf_s
- _vsnwprintf_s_l
- _vsnprintf_s
- vsnprintf_s
- _vsnprintf_s_l
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
- ntdll.dll
- ucrtbase.dll
- ntoskrnl.exe
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _vsnprintf_s
- _vsntprintf_s
- _vsnwprintf_s
helpviewer_keywords:
- vsnwprintf_s function
- _vsntprintf_s function
- _vsntprintf_s_l function
- vsntprintf_s function
- vsnwprintf_s_l function
- vsnprintf_s_l function
- vsntprintf_s_l function
- _vsnwprintf_s_l function
- _vsnprintf_s function
- vsnprintf_s function
- _vsnprintf_s_l function
- _vsnwprintf_s function
- formatted text [C++]
ms.assetid: 147ccfce-58c7-4681-a726-ef54ac1c604e
ms.openlocfilehash: edb534eb533d63c9298b7b7e9aced1be3e8652d9
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91502786"
---
# <a name="vsnprintf_s-_vsnprintf_s-_vsnprintf_s_l-_vsnwprintf_s-_vsnwprintf_s_l"></a>vsnprintf_s, _vsnprintf_s, _vsnprintf_s_l, _vsnwprintf_s, _vsnwprintf_s_l

Grave saída formatada usando um ponteiro para uma lista de argumentos. Essas são versões de [vsnprintf, _vsnprintf, _vsnprintf_l, _vsnwprintf, _vsnwprintf_l](vsnprintf-vsnprintf-vsnprintf-l-vsnwprintf-vsnwprintf-l.md) com aprimoramentos de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
int vsnprintf_s(
   char *buffer,
   size_t sizeOfBuffer,
   size_t count,
   const char *format,
   va_list argptr
);
int _vsnprintf_s(
   char *buffer,
   size_t sizeOfBuffer,
   size_t count,
   const char *format,
   va_list argptr
);
int _vsnprintf_s_l(
   char *buffer,
   size_t sizeOfBuffer,
   size_t count,
   const char *format,
   locale_t locale,
   va_list argptr
);
int _vsnwprintf_s(
   wchar_t *buffer,
   size_t sizeOfBuffer,
   size_t count,
   const wchar_t *format,
   va_list argptr
);
int _vsnwprintf_s_l(
   wchar_t *buffer,
   size_t sizeOfBuffer,
   size_t count,
   const wchar_t *format,
   locale_t locale,
   va_list argptr
);
template <size_t size>
int _vsnprintf_s(
   char (&buffer)[size],
   size_t count,
   const char *format,
   va_list argptr
); // C++ only
template <size_t size>
int _vsnwprintf_s(
   wchar_t (&buffer)[size],
   size_t count,
   const wchar_t *format,
   va_list argptr
); // C++ only
```

### <a name="parameters"></a>Parâmetros

*completo*<br/>
Local de armazenamento de saída.

*sizeOfBuffer*<br/>
O tamanho do *buffer* para saída, como a contagem de caracteres.

*contagem*<br/>
Número máximo de caracteres a gravar (não incluindo o nulo de terminação) ou [_TRUNCATE](../../c-runtime-library/truncate.md).

*format*<br/>
Especificação de formato.

*argptr*<br/>
Ponteiro para a lista de argumentos.

*locale*<br/>
A localidade a ser usada.

Para obter mais informações, consulte [Especificações de formato](../../c-runtime-library/format-specification-syntax-printf-and-wprintf-functions.md).

## <a name="return-value"></a>Valor Retornado

**vsnprintf_s**, **_vsnprintf_s** e **_vsnwprintf_s** retornam o número de caracteres gravados, sem incluir o nulo de terminação ou um valor negativo se ocorrer um truncamento dos dados ou um erro de saída.

* Se *Count* for menor que *sizeOfBuffer* e o número de caracteres de dados for menor ou igual a *count*, ou *Count* for [_TRUNCATE](../../c-runtime-library/truncate.md) e o número de caracteres de dados for menor que *sizeOfBuffer*, todos os dados serão gravados e o número de caracteres será retornado.

* Se *Count* for menor que *sizeOfBuffer* , mas os dados excederem os caracteres de *contagem* , os primeiros caracteres de *contagem* serão gravados. O truncamento dos dados restantes ocorre e-1 é retornado sem invocar o manipulador de parâmetro inválido.

* Se *Count* for [_TRUNCATE](../../c-runtime-library/truncate.md) e o número de caracteres de dados for igual a ou exceder *sizeOfBuffer*, tanto a cadeia de caracteres como caberá no *buffer* (com terminação de NULL) será gravada. O truncamento dos dados restantes ocorre e-1 é retornado sem invocar o manipulador de parâmetro inválido.

* Se *Count* for igual a ou exceder *sizeOfBuffer* , mas o número de caracteres de dados for menor que *sizeOfBuffer*, todos os dados serão gravados (com terminação nula) e o número de caracteres será retornado.

* Se *Count* e o número de caracteres de dados forem iguais ou excederem *sizeOfBuffer*, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução continuar após o manipulador de parâmetros inválido, essas funções definirão o *buffer* como uma cadeia de caracteres vazia, definirá **errno** como **ERANGE**e retornará-1.

* Se o *buffer* ou o *formato* for um ponteiro **nulo** , ou se *Count* for menor ou igual a zero, o manipulador de parâmetro inválido será invocado. Se a execução tiver permissão para continuar, essas funções definem **errno** como **EINVAL** e retornam-1.

### <a name="error-conditions"></a>Condições de erro

|**Condição**|Retorno|**errno**|
|-----------------|------------|-------------|
|o *buffer* é **nulo**|-1|**EINVAL**|
|o *formato* é **nulo**|-1|**EINVAL**|
|*contagem* <= 0|-1|**EINVAL**|
|*sizeOfBuffer* muito pequeno (e *contagem* ! = **_TRUNCATE**)|-1 (e *buffer* definido como uma cadeia de caracteres vazia)|**ERANGE**|

## <a name="remarks"></a>Comentários

**vsnprintf_s** é idêntico a **_vsnprintf_s**. **vsnprintf_s** está incluído para conformidade com o padrão ANSI. **_vnsprintf** é retido para compatibilidade com versões anteriores.

Cada uma dessas funções usa um ponteiro para uma lista de argumentos e, em seguida, formata e grava até a *contagem* de caracteres dos dados especificados para a memória apontada pelo *buffer* e acrescenta um nulo de terminação.

Se *Count* for [_TRUNCATE](../../c-runtime-library/truncate.md), essas funções gravarão a maior parte da cadeia de caracteres como se ajustarão ao *buffer* , deixando espaço para um nulo de terminação. Se a cadeia de caracteres inteira (com terminação de NULL) couber no *buffer*, essas funções retornarão o número de caracteres gravados (sem incluir o nulo de terminação); caso contrário, essas funções retornam-1 para indicar que o truncamento ocorreu.

As versões dessas funções com o sufixo **_L** são idênticas, exceto pelo fato de que usam o parâmetro Locale passado em vez da localidade do thread atual.

> [!IMPORTANT]
> Verifique se *format* não é uma cadeia de caracteres definida pelo usuário. Para obter mais informações, consulte [Avoiding Buffer Overruns](/windows/win32/SecBP/avoiding-buffer-overruns) (Evitando estouros de buffer).

> [!NOTE]
> Para garantir que haja espaço para o nulo de encerramento, verifique se a *contagem* é estritamente menor que o comprimento do buffer ou use **_TRUNCATE**.

Em C++, o uso dessas funções é simplificado pelas sobrecargas de modelo; as sobrecargas podem inferir o tamanho do buffer automaticamente (eliminando a necessidade de especificar um argumento de tamanho) e podem substituir automaticamente funções mais antigas e não seguras por suas equivalentes mais recentes e seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_vsntprintf_s**|**_vsnprintf_s**|**_vsnprintf_s**|**_vsnwprintf_s**|
|**_vsntprintf_s_l**|**_vsnprintf_s_l**|**_vsnprintf_s_l**|**_vsnwprintf_s_l**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalhos opcionais|
|-------------|---------------------|----------------------|
|**vsnprintf_s**|\<stdio.h> e \<stdarg.h>|\<varargs.h>*|
|**_vsnprintf_s**, **_vsnprintf_s_l**|\<stdio.h> e \<stdarg.h>|\<varargs.h>*|
|**_vsnwprintf_s**, **_vsnwprintf_s_l**|\<stdio.h> ou \<wchar.h> , e \<stdarg.h>|\<varargs.h>*|

\* Necessário para compatibilidade com UNIX V.

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```cpp
// crt_vsnprintf_s.cpp
#include <stdio.h>
#include <wtypes.h>

void FormatOutput(LPCSTR formatstring, ...)
{
   int nSize = 0;
   char buff[10];
   memset(buff, 0, sizeof(buff));
   va_list args;
   va_start(args, formatstring);
   nSize = vsnprintf_s( buff, _countof(buff), _TRUNCATE, formatstring, args);
   printf("nSize: %d, buff: %s\n", nSize, buff);
   va_end(args);
}

int main() {
   FormatOutput("%s %s", "Hi", "there");
   FormatOutput("%s %s", "Hi", "there!");
   FormatOutput("%s %s", "Hi", "there!!");
}
```

```Output
nSize: 8, buff: Hi there
nSize: 9, buff: Hi there!
nSize: -1, buff: Hi there!
```

## <a name="see-also"></a>Confira também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[Funções vprintf](../../c-runtime-library/vprintf-functions.md)<br/>
[fprintf, _fprintf_l, fwprintf, _fwprintf_l](fprintf-fprintf-l-fwprintf-fwprintf-l.md)<br/>
[printf, _printf_l, wprintf, _wprintf_l](printf-printf-l-wprintf-wprintf-l.md)<br/>
[sprintf, _sprintf_l, swprintf, _swprintf_l, \_ _swprintf_l](sprintf-sprintf-l-swprintf-swprintf-l-swprintf-l.md)<br/>
[va_arg, va_copy, va_end, va_start](va-arg-va-copy-va-end-va-start.md)<br/>
