---
title: "asctime_s, _wasctime_s | Microsoft Docs"
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
  - "_wasctime_s"
  - "asctime_s"
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
  - "asctime_s"
  - "_wasctime_s"
  - "_tasctime_s"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _tasctime_s"
  - "Função _wasctime_s"
  - "Função asctime_s"
  - "Função tasctime_s"
  - "conversão de estrutura de tempo"
  - "hora, convertendo"
  - "Função wasctime_s"
ms.assetid: 17ad9b2b-a459-465d-976a-42822897688a
caps.latest.revision: 29
caps.handback.revision: 27
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# asctime_s, _wasctime_s
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Converter uma estrutura de tempo de `tm` a uma cadeia de caracteres.  Essas funções são versões de [asctime, \_wasctime](../../c-runtime-library/reference/asctime-wasctime.md) com aprimoramentos de segurança conforme descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
## Sintaxe  
  
```  
errno_t asctime_s(   
   char* buffer,  
   size_t numberOfElements,  
   const struct tm *_tm   
);  
errno_t _wasctime_s(   
   wchar_t* buffer,  
   size_t numberOfElements  
   const struct tm *_tm   
);  
template <size_t size>  
errno_t asctime_s(   
   char (&buffer)[size],  
   const struct tm *_tm   
); // C++ only  
template <size_t size>  
errno_t _wasctime_s(   
   wchar_t (&buffer)[size],  
   const struct tm *_tm   
); // C++ only  
```  
  
#### Parâmetros  
 `buffer`  
 \[out\] de ponteiro para um buffer para armazenar o resultado da cadeia de caracteres.  Essa função assume um ponteiro para um local de memória válida com um tamanho especificado por `numberOfElements`.  
  
 `numberOfElements`  
 \[in\] o tamanho do buffer usado para armazenar o resultado.  
  
 `_tm`  
 \[in\] estrutura de data\/hora.  Essa função assume um ponteiro para um objeto válido de `struct``tm` .  
  
## Valor de retorno  
 Nulo se com êxito.  Se houver uma falha, o manipulador inválido do parâmetro será chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução for permitida continuar, o valor de retorno é um código de erro.  Os códigos de erro são definidos em ERRNO.H.  Para obter mais informações, consulte [Constantes errno](../../c-runtime-library/errno-constants.md).  Os códigos de erro retornados reais para cada condição de erro são mostrados na tabela a seguir.  
  
### Condições de erro  
  
|`buffer`|`numberOfElements`|`tm`|Return|Valor em `buffer`|  
|--------------|------------------------|----------|------------|-----------------------|  
|`NULL`|Alguns|Alguns|`EINVAL`|Não modificados|  
|Não`NULL` \(pontos para a memória válido\)|0|Alguns|`EINVAL`|Não modificados|  
|Não `NULL`|0\< tamanhos \< 26|Alguns|`EINVAL`|Cadeia de caracteres vazia|  
|Não `NULL`|\>\= 26|`NULL`|`EINVAL`|Cadeia de caracteres vazia|  
|Não `NULL`|\>\= 26|Estrutura de hora inválido ou fora dos valores de intervalo para componentes de hora|`EINVAL`|Cadeia de caracteres vazia|  
  
> [!NOTE]
>  As condições de erro para `wasctime_s` são semelhantes a `asctime_s` com exceção do limite de tamanho é medido no word.  
  
## Comentários  
 A função de `asctime` converte uma hora armazenados como uma estrutura para uma cadeia de caracteres.  O valor de `_tm` geralmente é obtido de uma chamada para `gmtime` ou a `localtime`.  Ambas as funções podem ser usadas para preencher uma estrutura de `tm` , conforme definido em. TIME.H.  
  
|membro de timeptr|Valor|  
|-----------------------|-----------|  
|`tm_hour`|Hora desde meia\-noite \(0\-23\)|  
|`tm_isdst`|Positivo se o horário de verão é aplicado; 0 se o horário de verão não for aplicado; negativo se o status do horário de verão é desconhecido.  A biblioteca de tempo de execução C assumirá as regras dos Estados Unidos para implementar o cálculo de horário de verão \(DST\).|  
|`tm_mday`|Dia do mês \(1\-31\)|  
|`tm_min`|Minutos depois da hora \(0\-59\)|  
|`tm_mon`|Mês \(0\-11; janeiro \= 0\)|  
|`tm_sec`|Segundos após o minuto \(0\-59\)|  
|`tm_wday`|Dia da semana \(0\-6; Domingo \= 0\)|  
|`tm_yday`|Dia do ano \(0\-365; 1º de janeiro \= 0\)|  
|`tm_year`|Ano \(o ano atual menos 1900\)|  
  
 A cadeia de caracteres convertida também é ajustada de acordo com as configurações de fuso horário local.  Consulte [time, \_time32, \_time64](../Topic/time,%20_time32,%20_time64.md), [\_ftime, \_ftime32, \_ftime64](../../c-runtime-library/reference/ftime-ftime32-ftime64.md), e as funções de [localtime\_s, \_localtime32\_s, \_localtime64\_s](../../c-runtime-library/reference/localtime-s-localtime32-s-localtime64-s.md) para obter informações sobre como configurar a hora local e a função de [\_tzset](../Topic/_tzset.md) para obter mais informações sobre como configurar o ambiente de fuso horário e variáveis globais.  
  
 O resultado da cadeia de caracteres gerado por `asctime_s` contém exatamente 26 caracteres e tem o formato `Wed Jan 02 02:03:55 1980\n\0`.  Um relógio de 24 horas é usado.  Todos os campos têm uma largura constante.  O caractere de nova linha e o caractere nulo ocupam as duas posições as mais recentes de cadeia de caracteres.  O valor passado como o segundo parâmetro deve ser pelo menos este grande.  Se for menos, um código de erro, `EINVAL`, será retornado.  
  
 `_wasctime_s` é uma versão de caracteres largos de `asctime_s`.  Caso contrário, `_wasctime_s` e `asctime_s`, ao contrário, se comportam de forma idêntica.  
  
### Mapeamento de rotina de Genérico\- texto  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_tasctime_s`|`asctime_s`|`asctime_s`|`_wasctime_s`|  
  
 No C\+\+, o uso dessas funções é simplificado pelas sobrecargas de modelo; as sobrecargas podem interpretar o tamanho do buffer automaticamente, eliminando a necessidade de especificar um argumento de tamanho.  Para obter mais informações, consulte [Sobrecargas de modelo seguras](../Topic/Secure%20Template%20Overloads.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`asctime_s`|\<time.h\>|  
|`_wasctime_s`|\<time.h ou\> wchar.h \<\>|  
  
## Segurança  
 Se o ponteiro de buffer não é `NULL` e não o ponteiro para um buffer válido, a função substituirá o que existir no local.  Isso também pode levar a uma violação de acesso.  
  
 [excesso de buffer](http://msdn.microsoft.com/library/windows/desktop/ms717795) pode ocorrer se o argumento de tamanho passado for maior que o tamanho real do buffer.  
  
## Exemplo  
 Esse programa coloca a hora do sistema em inteiro longo `aclock`, tradu\-los na estrutura `newtime` e converte a cadeia de caracteres no formato de saída, usando a função de `asctime_s` .  
  
```  
// crt_asctime_s.c  
#include <time.h>  
#include <stdio.h>  
  
struct tm newtime;  
__time32_t aclock;  
  
int main( void )  
{  
   char buffer[32];  
   errno_t errNum;  
   _time32( &aclock );   // Get time in seconds.  
   _localtime32_s( &newtime, &aclock );   // Convert time to struct tm form.  
  
   // Print local time as a string.  
  
   errNum = asctime_s(buffer, 32, &newtime);  
   if (errNum)  
   {  
       printf("Error code: %d", (int)errNum);  
       return 1;  
   }  
   printf( "Current date and time: %s", buffer );  
   return 0;  
}  
```  
  
  **Data e hora: Quarta\-feira 14 de maio de 15: 30:17 2003**   
## Equivalência do .NET Framework  
  
-   <xref:System.DateTime.ToLongDateString%2A?displayProperty=fullName>  
  
-   <xref:System.DateTime.ToLongTimeString%2A?displayProperty=fullName>  
  
-   <xref:System.DateTime.ToShortDateString%2A?displayProperty=fullName>  
  
-   <xref:System.DateTime.ToShortTimeString%2A?displayProperty=fullName>  
  
-   <xref:System.DateTime.ToString%2A?displayProperty=fullName>  
  
## Consulte também  
 [Gerenciamento de tempo](../../c-runtime-library/time-management.md)   
 [ctime\_s, \_ctime32\_s, \_ctime64\_s, \_wctime\_s, \_wctime32\_s, \_wctime64\_s](../../c-runtime-library/reference/ctime-s-ctime32-s-ctime64-s-wctime-s-wctime32-s-wctime64-s.md)   
 [\_ftime, \_ftime32, \_ftime64](../../c-runtime-library/reference/ftime-ftime32-ftime64.md)   
 [gmtime\_s, \_gmtime32\_s, \_gmtime64\_s](../../c-runtime-library/reference/gmtime-s-gmtime32-s-gmtime64-s.md)   
 [localtime\_s, \_localtime32\_s, \_localtime64\_s](../../c-runtime-library/reference/localtime-s-localtime32-s-localtime64-s.md)   
 [time, \_time32, \_time64](../Topic/time,%20_time32,%20_time64.md)   
 [\_tzset](../Topic/_tzset.md)