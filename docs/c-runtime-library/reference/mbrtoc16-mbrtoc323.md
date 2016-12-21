---
title: "mbrtoc16, mbrtoc32 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "cpp"
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "mbrtoc16"
  - "mbrtoc32"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
  - "api-ms-win-crt-convert-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "mbrtoc16"
  - "mbrtoc32"
  - "uchar/mbrtoc16"
  - "uchar/mbrtoc32"
dev_langs: 
  - "C"
  - "C++"
helpviewer_keywords: 
  - "função mbrtoc16"
  - "função mbrtoc32"
ms.assetid: 099ade4d-56f7-4e61-8b45-493f1d7a64bd
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# mbrtoc16, mbrtoc32
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Representa o primeiro caractere multibyte em uma cadeia de caracteres estreita o caractere UTF\-16 ou UTF\-32 equivalente.  
  
## Sintaxe  
  
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
  
#### Parâmetros  
 `destination`  
 Ponteiro para o `char16_t` ou `char32_t` equivalente do caractere multibyte para converter. Se for null, a função não armazena um valor.  
  
 `source`  
 Ponteiro para a cadeia de caracteres para converter caracteres multibyte.  
  
 `max_bytes`  
 O número máximo de bytes em `source` para examinar um caractere converter. Isso deve ser um valor entre 1 e o número de bytes, incluindo qualquer terminador nulo, restantes no `source`.  
  
 `state`  
 Ponteiro para uma `mbstate_t` objeto de estado de conversão usado para interpretar a cadeia de caracteres multibyte para um ou mais caracteres de saída.  
  
## Valor de retorno  
 Em caso de sucesso, retorna o valor da primeira dessas condições que se aplica, dado atual `state` valor:  
  
|Valor|Condição|  
|-----------|--------------|  
|0|O próximo `max_bytes` ou menos caracteres convertidos de `source` correspondem ao caractere grande null, que é o valor armazenado se `destination` não for nulo.<br /><br /> `state` contém o estado inicial do turno.|  
|Entre 1 e `max_bytes`, inclusive|O valor retornado é o número de bytes de `source` Concluir um caractere multibyte válido. O caractere largo convertido é armazenado se `destination` não for nulo.|  
|\-3|O próximo caractere largo resultantes de uma chamada anterior para a função foi armazenado no `destination` se `destination` não for nulo. Nenhum byte de `source` são consumidas por essa chamada para a função.<br /><br /> Quando  `source` aponta para um caractere multibyte que requer mais de um caractere largo para representar \(por exemplo, um par substituto\), então o `state` valor é atualizado para que a próxima chamada de função gravará o caractere adicional.|  
|\-2|O próximo `max_bytes` bytes representam incompleto, mas os caracteres multibyte, potencialmente válido. Nenhum valor é armazenado em `destination`. Esse resultado pode ocorrer se `max_bytes` é zero.|  
|\-1|Erro de codificação. O próximo `max_bytes` ou menos bytes não contribuem para um caractere multibyte completo e válido. Nenhum valor é armazenado em `destination`.<br /><br /> `EILSEQ` são armazenados em `errno` e o estado de conversão `state` for especificado.|  
  
## Comentários  
 O `mbrtoc16` função lê até `max_bytes` bytes do `source` para localizar o primeiro caractere multibyte completo, válido e armazena o equivalente UTF\-16 caracteres em `destination`. Os bytes de origem são interpretados de acordo com a localidade multibyte do thread atual. Se os caracteres multibyte exigir mais de um caractere de saída UTF\-16 como um par substituto, então o `state` valor é definido para armazenar o próximo caractere UTF\-16 no `destination` na próxima chamada para `mbrtoc16`. O `mbrtoc32` é idêntica, mas a saída é armazenada como um caractere UTF\-32.  
  
 Se `source` for null, essas funções de retorno o equivalente de uma chamada feita usando argumentos de `NULL` para `destination`, `""` para `source`,  e `1` para `max_bytes`. Os valores passados de `destination` e `max_bytes` são ignorados.  
  
 Se `source` for não nulo, a função começa no início da cadeia de caracteres e inspeciona até `max_bytes` bytes para determinar o número de bytes necessários para concluir o próximo caractere multibyte, incluindo as seqüências de turno. Se os bytes examinados contiverem um caractere multibyte válido e completo, a função converte o caractere em caractere largo de 16 bits ou 32 bits equivalente ou caracteres. Se `destination` não é nulo, a função armazenará o resultado da primeira \(e possivelmente somente\) de caractere no destino. Se os caracteres de saída adicionais forem necessários, um valor é definido `state`, de modo que as chamadas subseqüentes à função os caracteres adicionais de saída e retornam o valor de \-3. Se nenhum caractere de saída mais forem necessário, em seguida, `state` está definido para o estado inicial do turno.  
  
## Requisitos  
  
|Função|Cabeçalho C|Cabeçalho C\+\+|  
|------------|-----------------|---------------------|  
|`mbrtoc16`, `mbrtoc32`|\< uchar.h \>|\< cuchar \>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Consulte também  
 [Conversão de dados](../../c-runtime-library/data-conversion.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [c16rtomb, c32rtomb](../Topic/c16rtomb,%20c32rtomb1.md)   
 [mbrtowc](../../c-runtime-library/reference/mbrtowc.md)   
 [mbsrtowcs](../../c-runtime-library/reference/mbsrtowcs.md)   
 [mbsrtowcs\_s](../../c-runtime-library/reference/mbsrtowcs-s.md)