---
title: mbrtoc16, mbrtoc323 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- mbrtoc16
- mbrtoc32
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
- mbrtoc16
- mbrtoc32
- uchar/mbrtoc16
- uchar/mbrtoc32
dev_langs:
- C++
helpviewer_keywords:
- mbrtoc16 function
- mbrtoc32 function
ms.assetid: 099ade4d-56f7-4e61-8b45-493f1d7a64bd
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 7e686a39266587fdc214ddbb0757672a57b94314
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="mbrtoc16-mbrtoc32"></a>mbrtoc16, mbrtoc32
Converte o primeiro caractere multibyte em uma sequência de caracteres estreita no caractere UTF-16 ou UTF-32 equivalente.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
size_t mbrtoc16(   
   char16_t* destination,   
   const char* source,   
   size_t max_bytes,   
   mbstate_t* state   
);  
  
size_t mbrtoc32(  
   char32_t* destination,   
   const char* source,   
   size_t max_bytes,   
   mbstate_t* state   
);  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `destination`  
 O ponteiro para o `char16_t` ou `char32_t` equivalente do caractere multibyte a ser convertido. Se for null, a função não armazenará um valor.  
  
 `source`  
 O ponteiro para a cadeia de caracteres multibyte a ser convertida.  
  
 `max_bytes`  
 O número máximo de bytes em `source` a serem examinados para um caractere a ser convertido. Isso deve ser um valor entre um e o número de bytes, incluindo qualquer terminador nulo, restantes no `source`.  
  
 `state`  
 O ponteiro para um objeto de estado de conversão `mbstate_t` usado para interpretar a cadeia de caracteres multibyte para um ou mais caracteres de saída.  
  
## <a name="return-value"></a>Valor de retorno  
 Em caso de sucesso, retorna o valor da primeira dessas condições que se aplica, dado o valor `state` atual:  
  
|Valor|Condição|  
|-----------|---------------|  
|0|Os próximos `max_bytes` ou menos caracteres convertidos de `source` correspondem ao caractere largo nulo, que é o valor armazenado se `destination` não for nulo.<br /><br /> `state` contém o estado de deslocamento inicial.|  
|Entre 1 e `max_bytes`, inclusive|O valor retornado é o número de bytes de `source` que completa um caractere multibyte válido. O caractere largo convertido será armazenado se `destination` não for nulo.|  
|-3|O próximo caractere largo resultante de uma chamada anterior para a função foi armazenado no `destination` se `destination` não era nulo. Nenhum byte de `source` é consumido por essa chamada para a função.<br /><br /> Quando `source` aponta para um caractere multibyte que requer mais de um caractere largo para representar (por exemplo, um par substituto), então o valor `state` é atualizado para que a próxima chamada de função grave o caractere adicional.|  
|-2|Os próximos `max_bytes` bytes representam um caractere multibyte incompleto, mas potencialmente válido. Não é armazenado nenhum valor em `destination`. Esse resultado poderá ocorrer se `max_bytes` for zero.|  
|-1|Ocorreu um erro de codificação. Os próximos `max_bytes` ou menos bytes não contribuem para um caractere multibyte completo e válido. Não é armazenado nenhum valor em `destination`.<br /><br /> `EILSEQ` é armazenado em `errno` e o estado de conversão `state` não é especificado.|  
  
## <a name="remarks"></a>Comentários  
 A função `mbrtoc16` lê até `max_bytes` bytes de `source` para encontrar o primeiro caractere multibyte válido completo e, em seguida, armazena o caractere UTF-16 equivalente no `destination`. Os bytes de origem são interpretados de acordo com a localidade de multibyte do thread atual. Se os caracteres multibyte exigirem mais de um caractere de saída UTF-16, como um par substituto, então o valor `state` será definido para armazenar o próximo caractere UTF-16 no `destination` na próxima chamada para `mbrtoc16`. A função `mbrtoc32` é idêntica, mas a saída é armazenada como um caractere UTF-32.  
  
 Se `source` for null, essas funções retornam o equivalente de uma chamada feita usando argumentos de `NULL` para `destination`, `""` para `source` e `1` para `max_bytes`. Os valores passados de `destination` e `max_bytes` são ignorados.  
  
 Se `source` não for nulo, a função começará no início da cadeia de caracteres e inspecionará até `max_bytes` bytes para determinar o número de bytes necessários para completar o próximo caractere multibyte, incluindo quaisquer sequências de deslocamento. Se os bytes examinados contiverem um caractere multibyte válido e completo, a função converterá o caractere no caractere ou caracteres largos de 16 bits ou 32 bits equivalentes. Se `destination` não for nulo, a função armazenará o primeiro (e possivelmente único) caractere resultante no destino. Se os caracteres de saída adicionais forem necessários, um valor será definido em `state`, de modo que as chamadas subsequentes para a função gerarão os caracteres adicionais e retornarão o valor -3. Se não for necessário mais nenhum caractere de saída adicional, `state` será definido para o estado de deslocamento inicial.  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho C|Cabeçalho C++|  
|--------------|--------------|------------------|  
|`mbrtoc16`,                `mbrtoc32`|\<uchar.h>|\<cuchar>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Conversão de Dados](../../c-runtime-library/data-conversion.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [c16rtomb, c32rtomb](../../c-runtime-library/reference/c16rtomb-c32rtomb1.md)   
 [mbrtowc](../../c-runtime-library/reference/mbrtowc.md)   
 [mbsrtowcs](../../c-runtime-library/reference/mbsrtowcs.md)   
 [mbsrtowcs_s](../../c-runtime-library/reference/mbsrtowcs-s.md)