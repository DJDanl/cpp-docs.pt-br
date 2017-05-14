---
title: mbsrtowcs | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- mbsrtowcs
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
- mbsrtowcs
dev_langs:
- C++
helpviewer_keywords:
- mbsrtowcs function
ms.assetid: f3a29de8-e36e-425b-a7fa-a258e6d7909d
caps.latest.revision: 20
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
ms.sourcegitcommit: e257f037a05c45f5b98e64ea55bd125af443b0be
ms.openlocfilehash: bec54ca0efe0f8aefabbe0c616e283b64fd22166
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="mbsrtowcs"></a>mbsrtowcs
Converte um caractere multibyte na localidade atual em uma cadeia de caracteres largos correspondente, com a capacidade de reiniciar no meio de um caractere multibyte. Uma versão mais segura dessa função está disponível, consulte [mbsrtowcs_s](../../c-runtime-library/reference/mbsrtowcs-s.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
size_t mbsrtowcs(  
   wchar_t *wcstr,  
   const char **mbstr,  
   sizeof count,  
   mbstate_t *mbstate  
);  
template <size_t size>  
size_t mbsrtowcs(  
   wchar_t (&wcstr)[size],  
   const char **mbstr,  
   sizeof count,  
   mbstate_t *mbstate  
); // C++ only  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [out] `wcstr`  
 Endereço para armazenar a cadeia de caracteres largos convertida resultante.  
  
 [in, out] `mbstr`  
 O ponteiro indireto para o local da cadeia de caracteres multibyte a ser convertida.  
  
 [in] `count`  
 O número máximo de caracteres (não bytes) para converter e armazenar em `wcstr`.  
  
 [in, out] `mbstate`  
 Um ponteiro para um objeto do estado da conversão `mbstate_t`. Se esse valor for um ponteiro nulo, um objeto de estado de conversão interno estático será usado. Como o objeto `mbstate_t` interno não é thread-safe, é recomendável que você sempre passe seu próprio parâmetro `mbstate`.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna o número de caracteres convertidos com êxito, sem incluir o caractere nulo de terminação, se houver. Retorna (size_t)(-1) se ocorreu um erro e define `errno` como EILSEQ.  
  
## <a name="remarks"></a>Comentários  
 A função `mbsrtowcs` converte uma cadeia de caracteres multibyte apontada indiretamente por `mbstr` em caracteres largos armazenados no buffer apontado por `wcstr` usando o estado de conversão contido em `mbstate`. A conversão continua para cada caractere até um caractere multibyte nulo de terminação ser encontrado, uma sequência multibyte que não corresponde a um caractere válido ser encontrada ou até `count` caracteres terem sido convertidos. Se `mbsrtowcs` encontra o caractere nulo multibyte ('\0') antes ou quando `count` ocorre, ele converte em um caractere nulo de terminação 16 bits e para.  
  
 Dessa forma, a cadeia de caracteres largos em `wcstr` será terminada em nulo somente se `mbsrtowcs` encontrar um caractere nulo multibyte durante a conversão. Se as sequências apontadas por `mbstr` e por `wcstr` se sobrepuserem, o comportamento de `mbsrtowcs` será indefinido. `mbsrtowcs` é afetado pela categoria LC_TYPE da localidade atual.  
  
 A função `mbsrtowcs` difere da [mbstowcs, _mbstowcs_l](../../c-runtime-library/reference/mbstowcs-mbstowcs-l.md) por sua capacidade de reinicialização. O estado da conversão é armazenado em `mbstate` para chamadas posteriores às mesmas funções ou a outras funções reiniciáveis. Os resultados são indefinidos ao combinar o uso de funções reiniciáveis e não reiniciáveis.  Por exemplo, um aplicativo deverá usar `mbsrlen` em vez de `mbslen` se uma chamada subsequente para `mbsrtowcs` for usada em vez de `mbstowcs.`  
  
 Se `wcstr` não for um ponteiro nulo, será atribuído um ponteiro nulo ao objeto de ponteiro apontado por `mbstr` se a conversão tiver parado porque um caractere nulo de terminação foi atingido. Caso contrário, será atribuído o endereço logo depois do último caractere multibyte convertido, se houver. Isso permite que uma chamada de função subsequente reinicie a conversão em que essa chamada é interrompida.  
  
 Se o argumento `wcstr` for um ponteiro nulo, o argumento `count` será ignorado e `mbsrtowcs` retornará o tamanho necessário em caracteres largos para a cadeia de caracteres de destino. Se `mbstate` for um ponteiro nulo, a função usará um objeto de estado de conversão `mbstate_t` interna estática não thread-safe. Se a sequência de caracteres `mbstr` não tiver nenhuma representação de caracteres multibyte correspondente, –1 será retornado e `errno` será definido como `EILSEQ`.  
  
 Se `mbstr` for um ponteiro nulo, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essa função definirá `errno` como `EINVAL` e retornará -1.  
  
 Em C++, essa função tem uma sobrecarga de modelo que invoca o equivalente mais recente e seguro dessa função. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).  
  
## <a name="exceptions"></a>Exceções  
 A função `mbsrtowcs` será multithread-safe contanto que nenhuma função no thread atual chame `setlocale` enquanto essa função estiver em execução e o argumento `mbstate` não for um ponteiro nulo.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`mbsrtowcs`|\<wchar.h>|  
  
## <a name="see-also"></a>Consulte também  
 [Conversão de Dados](../../c-runtime-library/data-conversion.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [mbrtowc](../../c-runtime-library/reference/mbrtowc.md)   
 [mbtowc, _mbtowc_l](../../c-runtime-library/reference/mbtowc-mbtowc-l.md)   
 [mbstowcs, _mbstowcs_l](../../c-runtime-library/reference/mbstowcs-mbstowcs-l.md)   
 [mbsinit](../../c-runtime-library/reference/mbsinit.md)
