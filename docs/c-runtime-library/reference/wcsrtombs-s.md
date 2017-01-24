---
title: "wcsrtombs_s | Microsoft Docs"
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
  - "wcsrtombs_s"
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
  - "wcsrtombs_s"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "conversão de cadeia de caracteres, caracteres largos"
  - "Função wcsrtombs_s"
  - "caracteres largos, cadeias de caracteres"
ms.assetid: 9dccb766-113c-44bb-9b04-07a634dddec8
caps.latest.revision: 27
caps.handback.revision: 25
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# wcsrtombs_s
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Converter uma cadeia de caracteres amplas em sua representação de cadeia de caracteres de vários bytes.  Uma versão de [wcsrtombs](../../c-runtime-library/reference/wcsrtombs.md) com aprimoramentos de segurança conforme descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
## Sintaxe  
  
```  
errno_t wcsrtombs_s(  
   size_t *pReturnValue,  
   char *mbstr,  
   size_t sizeInBytes,  
   const wchar_t **wcstr,  
   sizeof count,  
   mbstate_t *mbstate  
);  
template <size_t size>  
errno_t wcsrtombs_s(  
   size_t *pReturnValue,  
   char (&mbstr)[size],  
   const wchar_t **wcstr,  
   sizeof count,  
   mbstate_t *mbstate  
); // C++ only  
```  
  
#### Parâmetros  
 \[saída\] `pReturnValue`  
 O número de caracteres convertidos.  
  
 \[saída\] `mbstr`  
 O endereço de um buffer resultante para converter a cadeia de caracteres de vários bytes.  
  
 \[saída\] `sizeInBytes`  
 O tamanho em bytes do buffer de `mbstr` .  
  
 \[entrada\] `wcstr`  
 Aponta para a cadeia de caracteres amplas a ser convertida.  
  
 \[entrada\] `count`  
 O número máximo de bytes a serem armazenadas no buffer de `mbstr` , ou [\_TRUNCATE](../../c-runtime-library/truncate.md).  
  
 \[entrada\] `mbstate`  
 Um ponteiro para um objeto do estado da conversão de `mbstate_t` .  
  
## Valor de retorno  
 Zero se tiver êxito, um código de erro ou falha.  
  
|Condição de erro|Valor de retorno e `errno`|  
|----------------------|--------------------------------|  
|`mbstr` é `NULL` e `sizeInBytes` \> 0|`EINVAL`|  
|`wcstr` é `NULL`|`EINVAL`|  
|O buffer de destino for muito pequeno conter a cadeia de caracteres convertida \(a menos que `count` é `_TRUNCATE`; consulte os comentários abaixo\)|`ERANGE`|  
  
 Se alguma dessas condições ocorrer, a exceção inválido do parâmetro é chamada conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md) .  Se a execução for permitida continuar, a função retornará um código de erro e define `errno` conforme indicado na tabela.  
  
## Comentários  
 A função de `wcsrtombs_s` converte uma cadeia de caracteres de caracteres amplos apontados por `wcstr` em caracteres multibyte armazenados em buffer apontado por `mbstr`, usando o estado de conversão contido em `mbstate`.  A conversão para cada caractere continuará até que uma destas condições seja atender:  
  
-   Um caractere largo nulo é encontrado  
  
-   Um caractere largo que não pode ser convertido for encontrado  
  
-   O número de bytes armazenados em buffer de `mbstr` igual `count`.  
  
 A cadeia de caracteres de destino tiver terminação sempre \(até mesmo no caso de um erro\).  
  
 Se `count` é o valor especial [\_TRUNCATE](../../c-runtime-library/truncate.md), então `wcsrtombs_s` converte o máximo possível da cadeia de caracteres como caiba no buffer de destino, enquanto ainda deixar de espaço para um terminador nulo.  
  
 Se `wcsrtombs_s` converte a cadeia de caracteres de origem, coloca o tamanho em bytes da cadeia de caracteres convertida, incluindo o terminador nulo, em `*``pReturnValue` \( `pReturnValue` fornecido não for `NULL`\).  Isso ocorre mesmo se o argumento de `mbstr` é `NULL` e fornece uma maneira de determinar o tamanho de buffer necessário.  Observe que se `mbstr` é `NULL`, `count` será ignorado.  
  
 Se `wcsrtombs_s` encontrar um caractere largo que não pode converter em um caracteres multibyte, o coloca \-1 em `*``pReturnValue`, define o buffer de destino em uma cadeia de caracteres vazia, define `errno` a `EILSEQ`, e retorna `EILSEQ`.  
  
 Se as sequências apontadas por `wcstr` e a sobreposição de `mbstr` , o comportamento de `wcsrtombs_s` são indefinidas.  `wcsrtombs_s` é afetado por categoria de LC\_TYPE de localidade atual.  
  
> [!IMPORTANT]
>  Certifique\-se de que `wcstr` e `mbstr` não se sobrepõem, e que `count` reflete corretamente o número de caracteres amplos para converter.  
  
 A função de `wcsrtombs_s` difere de [wcstombs\_s, \_wcstombs\_s\_l](../Topic/wcstombs_s,%20_wcstombs_s_l.md) por seu restartability.  O estado da conversão é armazenado em `mbstate` para chamadas subsequentes à mesma ou a outras funções restartable.  Os resultados são definidos ao misturar o uso de funções restartable e nonrestartable.  Por exemplo, um aplicativo use `wcsrlen` em vez de `wcslen`, se uma chamada subsequente a `wcsrtombs_s` foi usado em vez de `wcstombs_s.`  
  
 No C\+\+, o uso dessas funções é simplificado por sobrecargas de modelo; as sobrecargas podem interpretar o tamanho do buffer automaticamente \(eliminando a necessidade de especificar um argumento de tamanho\) e podem substituir automaticamente as funções menos seguras mais antigas por correspondentes mais seguras e mais recentes.  Para obter mais informações, consulte [Sobrecargas de modelo seguras](../Topic/Secure%20Template%20Overloads.md).  
  
## Exceções  
 A função de `wcsrtombs_s` é seguro multi\-threaded desde que nenhuma função no thread atual chama `setlocale` quando essa função executar e `mbstate` for nulo.  
  
## Exemplo  
  
```  
// crt_wcsrtombs_s.cpp  
//   
// This code example converts a wide  
// character string into a multibyte  
// character string.  
//  
  
#include <stdio.h>  
#include <memory.h>  
#include <wchar.h>  
#include <errno.h>  
  
#define MB_BUFFER_SIZE 100  
  
void main()  
{  
    const wchar_t   wcString[] =   
                    {L"Every good boy does fine."};  
    const wchar_t   *wcsIndirectString = wcString;  
    char            mbString[MB_BUFFER_SIZE];  
    size_t          countConverted;  
    errno_t         err;  
    mbstate_t       mbstate;  
  
    // Reset to initial shift state  
    ::memset((void*)&mbstate, 0, sizeof(mbstate));  
  
    err = wcsrtombs_s(&countConverted, mbString, MB_BUFFER_SIZE,  
                      &wcsIndirectString, MB_BUFFER_SIZE, &mbstate);  
    if (err == EILSEQ)  
    {  
        printf( "An encoding error was detected in the string.\n" );  
    }  
    else   
    {  
        printf( "The string was successfully converted.\n" );  
    }  
}  
```  
  
  **A cadeia de caracteres foi convertida com êxito.**   
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`wcsrtombs_s`|\<wchar.h\>|  
  
## Consulte também  
 [Conversão de dados](../../c-runtime-library/data-conversion.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [wcrtomb](../../c-runtime-library/reference/wcrtomb.md)   
 [wcrtomb\_s](../../c-runtime-library/reference/wcrtomb-s.md)   
 [wctomb, \_wctomb\_l](../../c-runtime-library/reference/wctomb-wctomb-l.md)   
 [wcstombs, \_wcstombs\_l](../Topic/wcstombs,%20_wcstombs_l.md)   
 [mbsinit](../../c-runtime-library/reference/mbsinit.md)