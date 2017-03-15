---
title: wcrtomb_s | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- wcrtomb_s
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
- wcrtomb_s
dev_langs:
- C++
helpviewer_keywords:
- wide characters, converting
- wcrtomb_s function
- multibyte characters
- characters, converting
ms.assetid: 9a8a1bd0-1d60-463d-a3a2-d83525eaf656
caps.latest.revision: 22
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.mt:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: eec9f8620ed6533304568704444de6df33503818
ms.lasthandoff: 02/25/2017

---
# <a name="wcrtombs"></a>wcrtomb_s
Converta um caractere largo em sua representação de caracteres multibyte. Uma versão de [wcrtomb](../../c-runtime-library/reference/wcrtomb.md) com melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
errno_t wcrtomb_s(  
   size_t *pReturnValue,  
   char *mbchar,  
   size_t sizeOfmbchar,  
   wchar_t *wchar,  
   mbstate_t *mbstate  
);  
template <size_t size>  
errno_t wcrtomb_s(  
   size_t *pReturnValue,  
   char (&mbchar)[size],  
   wchar_t *wchar,  
   mbstate_t *mbstate  
); // C++ only  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [out] `pReturnValue`  
 Retorna o número de bytes gravados ou –1 em caso de erro.  
  
 [out] `mbchar`  
 O caractere multibyte convertido resultante.  
  
 [in] `sizeOfmbchar`  
 O tamanho da variável `mbchar` em bytes.  
  
 [in] `wchar`  
 Um caractere largo a ser convertido.  
  
 [in] `mbstate`  
 Um ponteiro para um objeto `mbstate_t`.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna zero ou um valor `errno` em caso de erro.  
  
## <a name="remarks"></a>Comentários  
 A função `wcrtomb_s` converte um caractere largo que começa no estado da conversão especificado contido em `mbstate`, com base no valor contido em `wchar`, no endereço representado por `mbchar`. O valor `pReturnValue` será o número de bytes convertidos, mas não mais de `MB_CUR_MAX` bytes ou –1 em caso de erro.  
  
 Se `mbstate` for nulo, o estado da conversão `mbstate_t` interno será usado. Se o caractere contido em `wchar` não tiver nenhum caractere multibyte correspondente, o valor de `pReturnValue` será –1 e a função retornará o valor `errno` de `EILSEQ`.  
  
 A função `wcrtomb_s` difere de [wctomb_s, wctomb_s_l](../../c-runtime-library/reference/wctomb-s-wctomb-s-l.md) por sua capacidade de reinicialização. O estado da conversão é armazenado em `mbstate` para chamadas posteriores às mesmas funções ou a outras funções reiniciáveis. Os resultados são indefinidos ao combinar o uso de funções reiniciáveis e não reiniciáveis. Por exemplo, um aplicativo usaria `wcsrlen` em vez de `wcslen` se uma chamada subsequente a `wcsrtombs_s` fosse usada em vez de `wcstombs_s.`  
  
 Em C++, o uso dessa função é simplificado pelas sobrecargas de modelo; as sobrecargas podem inferir o tamanho do buffer automaticamente (eliminando a necessidade de especificar um argumento de tamanho) e podem substituir automaticamente funções mais antigas e não seguras por suas equivalentes mais recentes e seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).  
  
## <a name="exceptions"></a>Exceções  
 A função `wcrtomb_s` será multithread-safe contanto que nenhuma função no thread atual chame `setlocale` enquanto essa função estiver em execução e o `mbstate` for nulo.  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_wcrtomb_s.c  
// This program converts a wide character  
// to its corresponding multibyte character.  
//  
  
#include <string.h>  
#include <stdio.h>  
#include <wchar.h>  
  
int main( void )  
{  
    errno_t     returnValue;  
    size_t      pReturnValue;  
    mbstate_t   mbstate;  
    size_t      sizeOfmbStr = 1;  
    char        mbchar = 0;  
    wchar_t*    wchar = L"Q\0";  
  
    // Reset to initial conversion state  
    memset(&mbstate, 0, sizeof(mbstate));  
  
    returnValue = wcrtomb_s(&pReturnValue, &mbchar, sizeof(char),  
                            *wchar, &mbstate);  
    if (returnValue == 0) {  
        printf("The corresponding wide character \"");  
        wprintf(L"%s\"", wchar);  
        printf(" was converted to a the \"%c\" ", mbchar);  
        printf("multibyte character.\n");  
    }  
    else  
    {  
        printf("No corresponding multibyte character "  
               "was found.\n");  
    }  
}  
```  
  
```Output  
The corresponding wide character "Q" was converted to a the "Q" multibyte character.  
```  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`wcrtomb_s`|\<wchar.h>|  
  
## <a name="see-also"></a>Consulte também  
 [Conversão de Dados](../../c-runtime-library/data-conversion.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [mbsinit](../../c-runtime-library/reference/mbsinit.md)
