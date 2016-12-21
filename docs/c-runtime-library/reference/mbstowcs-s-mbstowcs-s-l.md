---
title: "mbstowcs_s, _mbstowcs_s_l | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_mbstowcs_s_l"
  - "mbstowcs_s"
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
  - "_mbstowcs_s_l"
  - "mbstowcs_s"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _mbstowcs_s_l"
  - "Função mbstowcs_s"
  - "Função mbstowcs_s_l"
ms.assetid: 2fbda953-6918-498f-b440-3e7b21ed65a4
caps.latest.revision: 31
caps.handback.revision: 31
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# mbstowcs_s, _mbstowcs_s_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Converte uma sequência de caracteres multibyte a uma sequência de caracteres amplos correspondente.  Versões de [mbstowcs, \_mbstowcs\_l](../../c-runtime-library/reference/mbstowcs-mbstowcs-l.md) com aprimoramentos de segurança conforme descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
## Sintaxe  
  
```  
errno_t mbstowcs_s(  
   size_t *pReturnValue,  
   wchar_t *wcstr,  
   size_t sizeInWords,  
   const char *mbstr,  
   size_t count   
);  
errno_t _mbstowcs_s_l(  
   size_t *pReturnValue,  
   wchar_t *wcstr,  
   size_t sizeInWords,  
   const char *mbstr,  
   size_t count,  
   _locale_t locale  
);  
template <size_t size>  
errno_t mbstowcs_s(  
   size_t *pReturnValue,  
   wchar_t (&wcstr)[size],  
   const char *mbstr,  
   size_t count   
); // C++ only  
template <size_t size>  
errno_t _mbstowcs_s_l(  
   size_t *pReturnValue,  
   wchar_t (&wcstr)[size],  
   const char *mbstr,  
   size_t count,  
   _locale_t locale  
); // C++ only  
```  
  
#### Parâmetros  
 \[saída\] `pReturnValue`  
 O número de caracteres convertidos.  
  
 \[saída\] `wcstr`  
 O endereço do buffer resultante para converter a cadeia de caracteres amplas.  
  
 \[entrada\] `sizeInWords`  
 O tamanho do buffer de `wcstr` no word.  
  
 \[in\]`mbstr`  
 O endereço de uma sequência de zero terminou caracteres multibyte.  
  
 \[entrada\] `count`  
 O número máximo de caracteres amplos a armazenar em buffer de `wcstr` , não incluindo o terminador nulo, ou [\_TRUNCATE](../../c-runtime-library/truncate.md).  
  
 \[entrada\] `locale`  
 A localidade a ser usada.  
  
## Valor de retorno  
 Zero se tiver êxito, um código de erro ou falha.  
  
|Condição de erro|Valor de retorno e `errno`|  
|----------------------|--------------------------------|  
|`wcstr` é `NULL` e `sizeInWords` \> 0|`EINVAL`|  
|`mbstr` é `NULL`|`EINVAL`|  
|O buffer de destino for muito pequeno conter a cadeia de caracteres convertida \(a menos que `count` é `_TRUNCATE`; consulte os comentários abaixo\)|`ERANGE`|  
|`wcstr` não é `NULL` e \=\= 0 de `sizeInWords`|`EINVAL`|  
  
 Se alguma dessas condições ocorrer, a exceção inválido do parâmetro é chamada conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md) .  Se a execução for permitida continuar, a função retornará um código de erro e define `errno` conforme indicado na tabela.  
  
## Comentários  
 A função de `mbstowcs_s` converte uma cadeia de caracteres de caracteres multibyte apontados por `mbstr` em caracteres amplos armazenados em buffer apontado por `wcstr`.  A conversão para cada caractere continuará até que uma destas condições seja atender:  
  
-   Um caractere nulo é encontrado multibyte  
  
-   Um caractere inválido multibyte for encontrado  
  
-   O número de caracteres amplos armazenados no buffer de `wcstr` igual `count`.  
  
 A cadeia de caracteres de destino tiver terminação sempre \(até mesmo no caso de um erro\).  
  
 Se `count` é o valor especial [\_TRUNCATE](../../c-runtime-library/truncate.md), então `mbstowcs_s` converte o máximo possível da cadeia de caracteres como caiba no buffer de destino, enquanto ainda deixar de espaço para um terminador nulo.  
  
 Se `mbstowcs_s` converte a cadeia de caracteres de origem, coloca o tamanho em caracteres amplos de cadeia de caracteres convertida, incluindo o terminador nulo, em `*``pReturnValue` \( `pReturnValue` fornecido não for `NULL`\).  Isso ocorre mesmo se o argumento de `wcstr` é `NULL` e fornece uma maneira de determinar o tamanho de buffer necessário.  Observe que se `wcstr` é `NULL`, `count` é ignorado, e `sizeInWords` deve ser 0.  
  
 Se `mbstowcs_s` encontrar um caractere inválido multibyte, o coloca 0 em `*``pReturnValue`, define o buffer de destino em uma cadeia de caracteres vazia, define `errno` a `EILSEQ`, e retorna `EILSEQ`.  
  
 Se as sequências apontadas por `mbstr` e a sobreposição de `wcstr` , o comportamento de `mbstowcs_s` são indefinidas.  
  
> [!IMPORTANT]
>  Certifique\-se de que `wcstr` e `mbstr` não se sobrepõem, e que `count` reflete corretamente o número de caracteres multibyte para converter.  
  
 `mbstowcs_s` usa a localidade atual para qualquer comportamento dependente de localidade; `_mbstowcs_s_l` é idêntico exceto que usa a localidade passada por vez.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 No C\+\+, o uso dessas funções é simplificado por sobrecargas de modelo; as sobrecargas podem interpretar o tamanho do buffer automaticamente \(eliminando a necessidade de especificar um argumento de tamanho\) e podem substituir automaticamente as funções menos seguras mais antigas por correspondentes mais seguras e mais recentes.  Para obter mais informações, consulte [Sobrecargas de modelo seguras](../Topic/Secure%20Template%20Overloads.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`mbstowcs_s`|\<stdlib.h\>|  
|`_mbstowcs_s_l`|\<stdlib.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Conversão de dados](../../c-runtime-library/data-conversion.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [MultiByteToWideChar](http://msdn.microsoft.com/library/windows/desktop/dd319072)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [\_mbclen, mblen, \_mblen\_l](../../c-runtime-library/reference/mbclen-mblen-mblen-l.md)   
 [mbtowc, \_mbtowc\_l](../Topic/mbtowc,%20_mbtowc_l.md)   
 [wcstombs, \_wcstombs\_l](../Topic/wcstombs,%20_wcstombs_l.md)   
 [wctomb, \_wctomb\_l](../../c-runtime-library/reference/wctomb-wctomb-l.md)