---
title: _strdec, _wcsdec, _mbsdec, _mbsdec_l
ms.date: 11/04/2016
apiname:
- _wcsdec
- _strdec
- _mbsdec
- _mbsdec_l
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
- api-ms-win-crt-multibyte-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _strdec
- mbsdec_l
- strdec
- _mbsdec
- _mbsdec_l
- mbsdec
- wcsdec
- _wcsdec
helpviewer_keywords:
- mbsdec_l function
- mbsdec function
- tcsdec function
- _tcsdec function
- _strdec function
- _wcsdec function
- _mbsdec_l function
- strdec function
- wcsdec function
- _mbsdec function
ms.assetid: ae37c223-800f-48a9-ae8e-38c8d20af2dd
ms.openlocfilehash: 7e88bcf5bf7ffc5eba6feecd545cda8f7950829c
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62353866"
---
# <a name="strdec-wcsdec-mbsdec-mbsdecl"></a>_strdec, _wcsdec, _mbsdec, _mbsdec_l

Recua um ponteiro de cadeia de caracteres em um caractere.

> [!IMPORTANT]
> **mbsdec** e **mbsdec_l** não pode ser usado em aplicativos executados no tempo de execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
unsigned char *_strdec(
   const unsigned char *start,
   const unsigned char *current
);
unsigned wchar_t *_wcsdec(
   const unsigned wchar_t *start,
   const unsigned wchar_t *current
);
unsigned char *_mbsdec(
   const unsigned char *start,
   const unsigned char *current
);
unsigned char *_mbsdec_l(
   const unsigned char *start,
   const unsigned char *current,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*start*<br/>
Ponteiro para qualquer caractere (ou para **_mbsdec** e **_mbsdec_l**, o primeiro byte de qualquer caractere multibyte) na cadeia de caracteres de origem; *inicie* deve preceder *atual* na cadeia de caracteres de origem.

*current*<br/>
Ponteiro para qualquer caractere (ou para **_mbsdec** e **_mbsdec_l**, o primeiro byte de qualquer caractere multibyte) na cadeia de caracteres de origem; *atual* deve seguir *iniciar* na cadeia de caracteres de origem.

*locale*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor de retorno

**_mbsdec**, **_mbsdec_l**, **_strdec**, e **_wcsdec** retornam um ponteiro para o caractere que precede imediatamente *atual*; **_mbsdec** retorna **nulo** se o valor de *iniciar* é maior que ou igual do *atual*. **_tcsdec** mapeia para uma dessas funções e seu valor de retorno depende do mapeamento.

## <a name="remarks"></a>Comentários

O **_mbsdec** e **_mbsdec_l** funções retornam um ponteiro para o primeiro byte do caractere multibyte que precede imediatamente *atual* na cadeia de caracteres que contém *iniciar*.

O valor de saída é afetado pela configuração da **LC_CTYPE** configuração da categoria da localidade; consulte [setlocale, wsetlocale](setlocale-wsetlocale.md) para obter mais informações.  **_mbsdec** reconhece sequências de caracteres multibyte de acordo com a localidade que está atualmente em uso, enquanto **_mbsdec_l** é idêntico, exceto que em vez disso, ele usa o parâmetro de localidade que é passado. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Se *inicie* ou *atual* está **nulo**, o manipulador de parâmetro inválido será invocado, conforme descrito no [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essa função retorna **EINVAL** e define **errno** para **EINVAL**.

> [!IMPORTANT]
> Essas funções podem ser vulneráveis a ameaças de estouro de buffer. Os estouros de buffer podem ser usados em ataques de sistema porque podem causar uma elevação de privilégio não garantida. Para obter mais informações, consulte [Avoiding Buffer Overruns](/windows/desktop/SecBP/avoiding-buffer-overruns) (Evitando estouros de buffer).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tcsdec**|**_strdec**|**_mbsdec**|**_wcsdec**|

**_strdec** e **_wcsdec** são versões de caractere de byte único e caracteres largos **_mbsdec** e **_mbsdec_l**. **_strdec** e **_wcsdec** são fornecidos apenas para esse mapeamento e não deve ser usado caso contrário.

Para obter mais informações, consulte [Usando mapeamentos de texto genérico](../../c-runtime-library/using-generic-text-mappings.md) e [Mapeamentos de Texto Genérico](../../c-runtime-library/generic-text-mappings.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|**_mbsdec**|\<mbstring.h>|\<mbctype.h>|
|**_mbsdec_l**|\<mbstring.h>|\<mbctype.h>|
|**_strdec**|\<tchar.h>||
|**_wcsdec**|\<tchar.h>||

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

O exemplo a seguir mostra um uso de **_tcsdec**.

```cpp
// crt_tcsdec.cpp
// Compile by using: cl /EHsc crt_tcsdec.cpp
#include <iostream>
#include <tchar.h>
using namespace std;

int main()
{
   const TCHAR *str = _T("12345");
   cout << "str: " << str << endl;

   const TCHAR *str2;
   str2 = str + 2;
   cout << "str2: " << str2 << endl;

   TCHAR *answer;
   answer = _tcsdec( str, str2 );
   cout << "answer: " << answer << endl;

   return (0);
}
```

O exemplo a seguir mostra um uso de **_mbsdec**.

```cpp
// crt_mbsdec.cpp
// Compile by using: cl /EHsc crt_mbsdec.c
#include <iostream>
#include <mbstring.h>
using namespace std;

int main()
{
   char *str = "12345";
   cout << "str: " << str << endl;

   char *str2;
   str2 = str + 2;
   cout << "str2: " << str2 << endl;

   unsigned char *answer;
   answer = _mbsdec( reinterpret_cast<unsigned char *>( str ), reinterpret_cast<unsigned char *>( str2 ));

   cout << "answer: " << answer << endl;

   return (0);
}
```

## <a name="see-also"></a>Consulte também

[Manipulação de cadeias de caracteres](../../c-runtime-library/string-manipulation-crt.md)<br/>
[_strinc, _wcsinc, _mbsinc, _mbsinc_l](strinc-wcsinc-mbsinc-mbsinc-l.md)<br/>
[_strnextc, _wcsnextc, _mbsnextc, _mbsnextc_l](strnextc-wcsnextc-mbsnextc-mbsnextc-l.md)<br/>
[_strninc, _wcsninc, _mbsninc, _mbsninc_l](strninc-wcsninc-mbsninc-mbsninc-l.md)<br/>
