---
title: "strftime, wcsftime, _strftime_l, _wcsftime_l | Microsoft Docs"
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
  - "strftime"
  - "_wcsftime_l"
  - "_strftime_l"
  - "wcsftime"
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
  - "_tcsftime"
  - "strftime"
  - "wcsftime"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _strftime_l"
  - "Função strftime"
  - "Função tcsftime"
  - "Função _wcsftime_l"
  - "Função wcsftime"
  - "Função _tcsftime"
  - "cadeias de caracteres de tempo"
ms.assetid: 6330ff20-4729-4c4a-82af-932915d893ea
caps.latest.revision: 22
caps.handback.revision: 22
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# strftime, wcsftime, _strftime_l, _wcsftime_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Formatação da cadeia de caracteres de tempo.  
  
## Sintaxe  
  
```  
size_t strftime(  
   char *strDest,  
   size_t maxsize,  
   const char *format,  
   const struct tm *timeptr   
);  
size_t _strftime_l(  
   char *strDest,  
   size_t maxsize,  
   const char *format,  
   const struct tm *timeptr,  
   _locale_t locale  
);  
size_t wcsftime(  
   wchar_t *strDest,  
   size_t maxsize,  
   const wchar_t *format,  
   const struct tm *timeptr   
);  
size_t _wcsftime_l(  
   wchar_t *strDest,  
   size_t maxsize,  
   const wchar_t *format,  
   const struct tm *timeptr,  
   _locale_t locale  
);  
```  
  
#### Parâmetros  
 `strDest`  
 Cadeia de caracteres de saída.  
  
 `maxsize`  
 Tamanho do buffer de `strDest` , medido em caracteres \(`char` ou `wchart_t`\).  
  
 `format`  
 Cadeia de caracteres de controle de formato.  
  
 `timeptr`  
 a estrutura de dados de`tm` .  
  
 `locale`  
 A localidade a ser usada.  
  
## Valor de retorno  
 `strftime` retorna o número de caracteres colocados em `strDest` e `wcsftime` retorna o número correspondente de caracteres amplos.  
  
 Se o número total de caracteres, incluindo o terminador nulo, é mais do que `maxsize`, `strftime` e `wcsftime` retorna 0 e o conteúdo de `strDest` serão indefinidos.  
  
 O número de caracteres em `strDest` é igual ao número de caracteres literais em `format` bem como todos os caracteres que podem ser adicionados a `format` pelos códigos de formatação.  Nulo encerramento de uma cadeia de caracteres não é contada no valor de retorno.  
  
## Comentários  
 As funções de `strftime` e de `wcsftime` formatar o valor do tempo de `tm` em `timeptr` de acordo com o argumento fornecido de `format` e armazena o resultado no buffer `strDest`*.* No máximo, os caracteres de `maxsize` são colocados na cadeia de caracteres.  Para obter uma descrição dos campos na estrutura de `timeptr` , consulte [asctime](../../c-runtime-library/reference/asctime-wasctime.md).  `wcsftime` é o equivalente de ampla caractere de `strftime`; os pontos do argumento de cadeia de caracteres\- ponteiro para uma cadeia de caracteres de ampla caractere.  Essas funções se comportam exatamente o contrário.  
  
> [!NOTE]
>  Nas versões anteriores do Visual C\+\+ 2005, a documentação descritos o parâmetro de `format` de `wcsftime` como tendo o tipo de dados `const wchar_t *`, mas a implementação do tipo real de dados de `format` foi `const char *`.  A implementação do tipode dados de `format`foi atualizada para refletir a documentação anterior e atual, ou seja, `const wchar_t *`.  
  
 Essa função valida seus parâmetros.  Se `strDest`, `format`, ou`timeptr` for um ponteiro nulo, ou se a estrutura de dados de `tm` endereçada por `timeptr` é inválido \(por exemplo, se contiver fora dos valores de intervalo para as horas ou date\), ou se a cadeia de caracteres de `format` contém um código de formatação inválido, o manipulador inválido do parâmetro é chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, a função retornará 0 e definirá `errno` como `EINVAL`.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_tcsftime`|`strftime`|`strftime`|`wcsftime`|  
  
 O argumento de `format` consiste em um ou vários códigos; como em `printf`, os códigos de formatação são precedidos por um sinal de porcentagem \(`%`\).  Os caracteres que não iniciam com `%` estão inalterados copiado para `strDest`*.* A categoria de `LC_TIME` de localidade atual afeta a formatação de saída de `strftime`. \(Para obter mais informações sobre como `LC_TIME`, consulte [setlocale](../Topic/setlocale,%20_wsetlocale.md).\) As funções sem o sufixo de `_l` usam a localidade definida no momento.  As versões dessas funções com o sufixo de `_l` são idênticas a não ser que levam a localidade como um parâmetro e usam o que em vez de localidade definida no momento.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 Os códigos de formatação para `strftime` são listados abaixo:  
  
 `%a`  
 Nome reduzido do dia útil  
  
 `%A`  
 Nome completo do dia útil  
  
 `%b`  
 Nome do mês abreviado  
  
 `%B`  
 Nome completo de mês  
  
 `%c`  
 Representa a data e hora apropriado para a localidade  
  
 `%d`  
 Dia do mês como o número decimal \(01 – 31\)  
  
 `%H`  
 Hora no formato de 24 horas \(00 – 23\)  
  
 `%I`  
 Hora em um formato de 12 horas \(01 – 12\)  
  
 `%j`  
 Dia do ano como o número decimal \(001 – 366\)  
  
 `%m`  
 Mês como o número decimal \(01 – 12\)  
  
 `%M`  
 Minuto como o número decimal \(00 – 59\)  
  
 `%p`  
 Indicador atual do. \/P.M A.M. de localidade do relógio de 12 horas  
  
 `%S`  
 Em dependendo de como o número decimal \(00 – 59\)  
  
 `%U`  
 Semana do ano como o número decimal, a domingo como o primeiro dia da semana \(00 – 53\)  
  
 `%w`  
 Dia da semana como o número decimal \(0 – 6; Domingo é 0\)  
  
 `%W`  
 Semana do ano como o número decimal, com segunda\-feira como o primeiro dia da semana \(00 – 53\)  
  
 `%x`  
 Representa a data da localidade atual  
  
 `%X`  
 Representação de tempo para a localidade atual  
  
 `%y`  
 Ano sem século, como o número decimal \(00 – 99\)  
  
 `%Y`  
 Ano com século, como o número decimal  
  
 `%z, %Z`  
 O nome de fuso horário ou abreviação de fuso horário, dependendo das configurações do Registro; nenhum caracteres se o fuso horário é desconhecido  
  
 `%%`  
 Sinal de por cento  
  
 Como na função de `printf` , o sinalizador de `#` pode atribuir qualquer código de formatação.  Nesse caso, o significado do código de formato é alterado a seguinte maneira.  
  
|Código de formato|Significado|  
|-----------------------|-----------------|  
|`%#a, %#A, %#b, %#B, %#p, %#X, %#z, %#Z, %#%`|o sinalizador de`#` é ignorado.|  
|`%#c`|A longo prazo e hora em que a representação, apropriado para a localidade atual.  Por exemplo: “Terça\-feira 14 de março de 1995, 12:41: 29 ".|  
|`%#x`|A representação de longo prazo, apropriada à localidade atual.  Por exemplo: “Terça\-feira 14 de março de 1995”.|  
|`%#d, %#H, %#I, %#j, %#m, %#M, %#S, %#U, %#w, %#W, %#y, %#Y`|Remova zeros à esquerda \(se houver\).|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`strftime`|\<time.h\>|  
|`wcsftime`|\<time.h ou\> wchar.h \<\>|  
|`_strftime_l`|\<time.h\>|  
|`_wcsftime_l`|\<time.h ou\> wchar.h \<\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
 Consulte o exemplo de [hora](../Topic/time,%20_time32,%20_time64.md).  
  
## Equivalência do .NET Framework  
  
-   [System::DateTime::ToLongDateString](https://msdn.microsoft.com/en-us/library/system.datetime.tolongdatestring.aspx)  
  
-   [System::DateTime::ToLongTimeString](https://msdn.microsoft.com/en-us/library/system.datetime.tolongtimestring.aspx)  
  
-   [System::DateTime::ToShortDateString](https://msdn.microsoft.com/en-us/library/system.datetime.toshortdatestring.aspx)  
  
-   [System::DateTime::ToShortTimeString](https://msdn.microsoft.com/en-us/library/system.datetime.toshorttimestring.aspx)  
  
-   [System::DateTime::ToString](https://msdn.microsoft.com/en-us/library/system.datetime.tostring.aspx)  
  
## Consulte também  
 [Localidade](../../c-runtime-library/locale.md)   
 [Gerenciamento de tempo](../../c-runtime-library/time-management.md)   
 [Manipulação da cadeia de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [localeconv](../../c-runtime-library/reference/localeconv.md)   
 [setlocale, \_wsetlocale](../Topic/setlocale,%20_wsetlocale.md)   
 [Funções strcoll](../../c-runtime-library/strcoll-functions.md)   
 [strxfrm, wcsxfrm, \_strxfrm\_l, \_wcsxfrm\_l](../../c-runtime-library/reference/strxfrm-wcsxfrm-strxfrm-l-wcsxfrm-l.md)