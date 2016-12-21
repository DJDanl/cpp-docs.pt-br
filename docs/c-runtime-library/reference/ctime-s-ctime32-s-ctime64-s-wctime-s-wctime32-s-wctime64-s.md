---
title: "ctime_s, _ctime32_s, _ctime64_s, _wctime_s, _wctime32_s, _wctime64_s | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_ctime64_s"
  - "_wctime32_s"
  - "ctime_s"
  - "_wctime64_s"
  - "_ctime32_s"
  - "_wctime_s"
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
  - "api-ms-win-crt-time-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "ctime64_s"
  - "_ctime32_s"
  - "_tctime32_s"
  - "_ctime64_s"
  - "_wctime_s"
  - "_tctime_s"
  - "_tctime64_s"
  - "ctime_s"
  - "ctime32_s"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _wctime32_s"
  - "Função ctime64_s"
  - "Função _tctime64_s"
  - "Função _wctime_s"
  - "Função tctime_s"
  - "Função _wctime64_s"
  - "Função ctime_s"
  - "Função ctime32_s"
  - "Função _ctime64_s"
  - "Função tctime64_s"
  - "Função wctime64_s"
  - "Função wctime_s"
  - "Função _tctime_s"
  - "Função tctime32_s"
  - "Função wctime32_s"
  - "tempo, convertendo"
  - "Função _ctime32_s"
  - "Função _tctime32_s"
ms.assetid: 36ac419a-8000-4389-9fd8-d78b747a009b
caps.latest.revision: 27
caps.handback.revision: 27
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# ctime_s, _ctime32_s, _ctime64_s, _wctime_s, _wctime32_s, _wctime64_s
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Converter um valor de tempo em uma cadeia de caracteres e ajustar as configurações de fuso horário local. Essas são versões de [ctime, ctime64, wctime, wctime64](../../c-runtime-library/reference/ctime-ctime32-ctime64-wctime-wctime32-wctime64.md) com aprimoramentos de segurança, conforme descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
## Sintaxe  
  
```  
errno_t ctime_s(   
   char* buffer,  
   size_t numberOfElements,  
   const time_t *time   
);  
errno_t _ctime32_s(   
   char* buffer,  
   size_t numberOfElements,  
   const __time32_t *time   
);  
errno_t _ctime64_s(   
   char* buffer,  
   size_t numberOfElements,  
   const __time64_t *time )  
;  
errno_t _wctime_s(   
   wchar_t* buffer,  
   size_t numberOfElements,  
   const time_t *time   
);  
errno_t _wctime32_s(   
   wchar_t* buffer,  
   size_t numberOfElements,  
   const __time32_t *time   
);  
errno_t _wctime64_s(   
   wchar_t* buffer,  
   size_t numberOfElements,  
   const __time64_t *time   
);  
template <size_t size>  
errno_t _ctime32_s(   
   char (&buffer)[size],  
   const __time32_t *time   
); // C++ only  
template <size_t size>  
errno_t _ctime64_s(   
   char (&buffer)[size],  
   const __time64_t *time  
); // C++ only  
template <size_t size>  
errno_t _wctime32_s(   
   wchar_t (&buffer)[size],  
   const __time32_t *time   
); // C++ only  
template <size_t size>  
errno_t _wctime64_s(   
   wchar_t (&buffer)[size],  
   const __time64_t *time   
); // C++ only  
```  
  
#### Parâmetros  
 \[out\] `buffer`  
 Deve ser grande o suficiente para conter 26 caracteres. Um ponteiro para o resultado de cadeia de caracteres, ou `NULL`se:  
  
-   `time` representa uma data anterior a 1º de janeiro de 1970, meia\-noite UTC.  
  
-   Se você usar `_ctime32_s` ou `_wctime32_s` e `time` representa uma data posterior a 23:59:59 18 de janeiro de 2038, UTC.  
  
-   Se você usar `_ctime64_s` ou `_wctime64_s` e `time` representa uma data posterior a 23:59:59 em 31 de dezembro de 3000, UTC.  
  
-   Se você usar `_ctime_s` ou `_wctime_s`, essas funções são wrappers para as funções anteriores. Consulte a seção comentários.  
  
 \[in\] `numberOfElements`  
 O tamanho do buffer.  
  
 \[t in\]`ime`  
 Ponteiro para hora armazenado.  
  
## Valor de retorno  
 Zero se tiver êxito. Se houver uma falha devido a um parâmetro inválido, o manipulador de parâmetro inválido é invocado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, um código de erro é retornado. Códigos de erro são definidos em ERRNO. H; Para obter uma lista desses erros, consulte [errno](../../c-runtime-library/errno-constants.md). Os códigos de erro real gerados para cada condição de erro são mostrados na tabela a seguir.  
  
## Condições de erro  
  
|`buffer`|`numberOfElements`|`time`|Retornar|O valor `buffer`|  
|--------------|------------------------|------------|--------------|----------------------|  
|`NULL`|qualquer|qualquer|`EINVAL`|Não modificado|  
|Não `NULL` \(aponta para memória válido\)|0|qualquer|`EINVAL`|Não modificado|  
|Não `NULL`|0 \< \< 26 de tamanho|qualquer|`EINVAL`|Cadeia de caracteres vazia|  
|Não `NULL`|\>\= 26|NULL|`EINVAL`|Cadeia de caracteres vazia|  
|Não `NULL`|\>\= 26|\< 0|`EINVAL`|Cadeia de caracteres vazia|  
  
## Comentários  
 O `ctime_s` função converte um valor de hora armazenado como um [time\_t](../../c-runtime-library/standard-types.md) estrutura em uma cadeia de caracteres. O `time` valor geralmente é obtido de uma chamada para [tempo](../Topic/time,%20_time32,%20_time64.md), que retorna o número de segundos passado desde a meia\-noite \(00: 00:00\), 1 de janeiro de 1970, hora universal coordenada \(UTC\). A cadeia de caracteres do valor de retorno contém exatamente 26 caracteres e tem o seguinte formato:  
  
```  
Wed Jan 02 02:03:55 1980\n\0  
```  
  
 Um relógio de 24 horas é usado. Todos os campos têm uma largura constante. O caractere de nova linha \('\\n'\) e o caractere nulo \('\\0'\) ocupam as últimas duas posições da cadeia de caracteres.  
  
 A cadeia de caracteres convertida também será ajustada de acordo com as configurações de fuso horário local. Consulte o `time`, [ftime](../../c-runtime-library/reference/ftime-ftime32-ftime64.md), e [localtime32\_s](../../c-runtime-library/reference/localtime-s-localtime32-s-localtime64-s.md) funções para obter informações sobre como configurar a hora local e o [tzset](../Topic/_tzset.md) função para obter informações sobre como definir o ambiente de fuso horário e variáveis globais.  
  
 `_wctime32_s` e `_wctime64_s` são da versão de caractere largo de `_ctime32_s` e `_ctime64_s`; retorna um ponteiro para a cadeia de caracteres largos. Caso contrário, `_ctime64_s`, `_wctime32_s`, e `_wctime64_s` se comportam de forma idêntica ao `_ctime32_s`.  
  
 `ctime_s` é uma função embutida que é avaliada como `_ctime64_s` e `time_t` é equivalente a `__time64_t`. Se você precisar forçar o compilador a interpretar `time_t` como o antigo 32 bits `time_t`, você pode definir `_USE_32BIT_TIME_T`. Fazer isso fará com que `ctime_s` para avaliar a `_ctime32_s`. Isso não é recomendado porque seu aplicativo pode falhar após 18 de janeiro de 2038, e não é permitido em plataformas de 64 bits.  
  
 No C\+\+, usando essas funções é simplificado pela sobrecargas de modelo; as sobrecargas podem inferir o comprimento de buffer automaticamente, eliminando a necessidade de especificar um argumento de tamanho. Para obter mais informações, consulte [Sobrecargas de modelo seguras](../Topic/Secure%20Template%20Overloads.md).  
  
### Mapeamentos de rotina de texto genérico  
  
|TCHAR. Rotina H|Unicode e MBCS não definidos|MBCS definido|Unicode definido|  
|---------------------|----------------------------------|-------------------|----------------------|  
|`_tctime_s`|`ctime_s`|`ctime_s`|`_wctime_s`|  
|`_tctime32_s`|`_ctime32_s`|`_ctime32_s`|`_wctime32_s`|  
|`_tctime64_s`|`_ctime64_s`|`_ctime64_s`|`_wctime64_s`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`ctime_s,`<br /><br /> `_ctime32_s,`<br /><br /> `_ctime64_s`|\< h \>|  
|`_wctime_s,`<br /><br /> `_wctime32_s,`<br /><br /> `_wctime64_s`|\< h \> ou \< WCHAR \>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [compatibilidade](../../c-runtime-library/compatibility.md) na introdução.  
  
## Libraries  
 Todas as versões do [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## Exemplo  
  
```  
// crt_wctime_s.c  
/* This program gets the current  
 * time in time_t form and then uses _wctime_s to  
 * display the time in string form.  
 */  
  
#include <time.h>  
#include <stdio.h>  
  
#define SIZE 26  
  
int main( void )  
{  
   time_t ltime;  
   wchar_t buf[SIZE];  
   errno_t err;  
  
   time( &ltime );  
  
   err = _wctime_s( buf, SIZE, &ltime );  
   if (err != 0)  
   {  
      printf("Invalid Arguments for _wctime_s. Error Code: %d\n", err);  
   }  
   wprintf_s( L"The time is %s\n", buf );  
}  
```  
  
## Saída de exemplo  
  
```  
The time is Fri Apr 25 13:03:39 2003  
```  
  
## Equivalência do .NET Framework  
  
-   [System::DateTime::GetDateTimeFormats](https://msdn.microsoft.com/en-us/library/system.datetime.getdatetimeformats.aspx)  
  
-   [System::DateTime::ToString](https://msdn.microsoft.com/en-us/library/system.datetime.tostring.aspx)  
  
-   [System::DateTime::ToLongTimeString](https://msdn.microsoft.com/en-us/library/system.datetime.tolongtimestring.aspx)  
  
-   [System::DateTime::ToShortTimeString](https://msdn.microsoft.com/en-us/library/system.datetime.toshorttimestring.aspx)  
  
## Consulte também  
 [Gerenciamento de tempo](../../c-runtime-library/time-management.md)   
 [asctime\_s, \_wasctime\_s](../../c-runtime-library/reference/asctime-s-wasctime-s.md)   
 [ctime, \_ctime32, \_ctime64, \_wctime, \_wctime32, \_wctime64](../../c-runtime-library/reference/ctime-ctime32-ctime64-wctime-wctime32-wctime64.md)   
 [\_ftime, \_ftime32, \_ftime64](../../c-runtime-library/reference/ftime-ftime32-ftime64.md)   
 [gmtime\_s, \_gmtime32\_s, \_gmtime64\_s](../../c-runtime-library/reference/gmtime-s-gmtime32-s-gmtime64-s.md)   
 [localtime\_s, \_localtime32\_s, \_localtime64\_s](../../c-runtime-library/reference/localtime-s-localtime32-s-localtime64-s.md)   
 [time, \_time32, \_time64](../Topic/time,%20_time32,%20_time64.md)