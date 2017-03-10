---
title: c16rtomb, c32rtomb1 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- c16rtomb
- c32rtomb
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
- c16rtomb
- c32rtomb
- uchar/c16rtomb
- uchar/c32rtomb
dev_langs:
- C++
helpviewer_keywords:
- c16rtomb function
- c32rtomb function
ms.assetid: 7f5743ca-a90e-4e3f-a310-c73e16f4e14d
caps.latest.revision: 3
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 585fd26bf3ea6a2d392a61b4f7793a0a9e84e267
ms.lasthandoff: 02/25/2017

---
# <a name="c16rtomb-c32rtomb"></a>c16rtomb, c32rtomb
Converta um caractere largo UTF-16 ou UTF-32 em um caractere multibyte na localidade atual.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
size_t c16rtomb(  
    char *mbchar,   
    char16_t wchar,  
    mbstate_t *state  
);  
size_t c32rtomb(  
    char *mbchar,   
    char32_t wchar,  
    mbstate_t *state  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [out] `mbchar`  
 Ponteiro para uma matriz para armazenar o caractere multibyte convertido.  
  
 [in] `wchar`  
 Um caractere largo a ser convertido.  
  
 [in, out] `state`  
 Um ponteiro para um objeto `mbstate_t`.  
  
## <a name="return-value"></a>Valor retornado  
 O número de bytes armazenados no objeto de matriz `mbchar`, incluindo quaisquer sequências de deslocamento. Se `wchar` não for um caractere largo válido, o valor (`size_t`)(-1) será retornado, `errno` será definido como `EILSEQ` e o valor de `state` será não especificado.  
  
## <a name="remarks"></a>Comentários  
 A função `c16rtomb` converte o caractere UTF-16 `wchar` para a sequência de caractere estreito multibyte equivalente na localidade atual. Se `mbchar` não for um ponteiro nulo, a função armazenará a sequência convertida no objeto de matriz apontado por `mbchar`. Até `MB_CUR_MAX` bytes são armazenados em `mbchar` e `state` é definido como o estado de deslocamento multibyte resultante.    Se `wchar` for um caractere largo nulo, uma sequência necessária para restaurar o estado de deslocamento inicial será armazenada, se necessário, seguida pelo caractere nulo e `state` será definida como o estado de conversão inicial. A função `c32rtomb` é idêntica, mas converte um caractere UTF-32.  
  
 Se `mbchar` for um ponteiro nulo, o comportamento será equivalente a uma chamada para a função que substitui um buffer interno para `mbchar` e um caractere nulo largo para `wchar`.  
  
 O objeto de estado de conversão `state` permite que você faça chamadas subsequentes para essa função e outras funções reiniciáveis que mantenham o estado de deslocamento dos caracteres de saída multibyte. Os resultados são indefinidos ao combinar o uso de funções reiniciáveis e não reiniciáveis ou se uma chamada para `setlocale` for feita entre chamadas de função reiniciável.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`c16rtomb`, `c32rtomb`|C, C++: \<uchar.h>|  
  
 Para obter informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Conversão de Dados](../../c-runtime-library/data-conversion.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [mbrtoc16, mbrtoc32](../../c-runtime-library/reference/mbrtoc16-mbrtoc323.md)   
 [wcrtomb](../../c-runtime-library/reference/wcrtomb.md)   
 [wcrtomb_s](../../c-runtime-library/reference/wcrtomb-s.md)
