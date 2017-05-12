---
title: _ltoa_s, _ltow_s | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _ltoa_s
- _ltow_s
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
apitype: DLLExport
f1_keywords:
- _ltow_s
- _ltoa_s
- ltoa_s
- ltow_s
dev_langs:
- C++
helpviewer_keywords:
- converting integers
- _ltoa_s function
- ltow_s function
- long integer conversion to string
- converting numbers, to strings
- ltoa_s function
- _ltow_s function
ms.assetid: d7dc61ea-1ccd-412d-b262-555a58647386
caps.latest.revision: 18
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3f91eafaf3b5d5c1b8f96b010206d699f666e224
ms.openlocfilehash: 098bb1dcf673931ab4c0d3682fafcc442835d76f
ms.contentlocale: pt-br
ms.lasthandoff: 04/01/2017

---
# <a name="ltoas-ltows"></a>_ltoa_s, _ltow_s
Converte um inteiro longo em uma cadeia de caracteres. Estas são versões de [_ltoa, _ltow](../../c-runtime-library/reference/ltoa-ltow.md) com melhorias de segurança, conforme descrito em [Recursos de Segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
errno_t _ltoa_s(  
    long value,  
    char *str,  
    size_t sizeOfstr,  
    int radix   
);  
errno_t _ltow_s(  
    long value,  
    wchar_t *str,  
    size_t sizeOfstr,  
    int radix   
);  
template <size_t size>  
errno_t _ltoa_s(  
    long value,  
    char (&str)[size],  
    int radix   
); // C++ only  
template <size_t size>  
errno_t _ltow_s(  
    long value,  
    wchar_t (&str)[size],  
    int radix   
); // C++ only  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `value`  
 Número a ser convertido.  
  
 `str`  
 Buffer da cadeia de caracteres resultante.  
  
 `sizeOfstr`  
 Tamanho de `str` em bytes para `_ltoa_s` ou palavras para `_ltow_s`.  
  
 `radix`  
 Base de `value`.  
  
## <a name="return-value"></a>Valor de retorno  
 Zero se a função for bem-sucedida ou um código de erro.  
  
## <a name="remarks"></a>Comentários  
 A função `_ltoa_s` converte os dígitos de `value` em uma cadeia de caracteres terminada em nulo e armazena o resultado (até 33 bytes) em `str`. O `radix` argumento especifica a base do `value`, que deve estar no intervalo de 2 a 36. Se `radix` é igual a 10 e `value` é negativo, o primeiro caractere da cadeia de caracteres armazenado é o sinal de subtração (-). `_ltow_s` é uma versão de caractere largo de `_ltoa_s`; o segundo argumento de `_ltow_s` é uma cadeia de caracteres largos.  
  
 Se `str` for um ponteiro `NULL` ou `sizeOfstr` for menor ou igual a zero, essas funções invocarão um manipulador de parâmetro inválido, conforme descrito em [Validação de Parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornarão -1 e definirão `errno` como `EINVAL` ou se `value` ou `str` estiverem fora do intervalo de um inteiro longo, essas funções retornarão -1 e definirão `errno` como `ERANGE`.  
  
 Em C++, o uso dessas funções é simplificado pelas sobrecargas de modelo; as sobrecargas podem inferir o tamanho do buffer automaticamente (eliminando a necessidade de especificar um argumento de tamanho) e podem substituir automaticamente funções mais antigas e não seguras por suas equivalentes mais recentes e seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|--------------------------------------|--------------------|-----------------------|  
|`_ltot_s`|`_ltoa_s`|`_ltoa_s`|`_ltow_s`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_ltoa_s`|\<stdlib.h>|  
|`_ltow_s`|\<stdlib.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="see-also"></a>Consulte também  
 [Conversão de Dados](../../c-runtime-library/data-conversion.md)   
 [_itoa, _i64toa, _ui64toa, _itow, _i64tow, _ui64tow](../../c-runtime-library/reference/itoa-i64toa-ui64toa-itow-i64tow-ui64tow.md)   
 [_ultoa, _ultow](../../c-runtime-library/reference/ultoa-ultow.md)   
 [_ultoa_s, _ultow_s](../../c-runtime-library/reference/ultoa-s-ultow-s.md)
