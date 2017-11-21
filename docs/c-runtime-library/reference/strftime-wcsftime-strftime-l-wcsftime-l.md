---
title: strftime, wcsftime, _strftime_l, _wcsftime_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- strftime
- _wcsftime_l
- _strftime_l
- wcsftime
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
- api-ms-win-crt-time-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _tcsftime
- strftime
- wcsftime
dev_langs: C++
helpviewer_keywords:
- _strftime_l function
- strftime function
- tcsftime function
- _wcsftime_l function
- wcsftime function
- _tcsftime function
- time strings
ms.assetid: 6330ff20-4729-4c4a-82af-932915d893ea
caps.latest.revision: "22"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: ec9c46f1a6d52a8769e5db454d44baf9ec9d8a8a
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="strftime-wcsftime-strftimel-wcsftimel"></a>strftime, wcsftime, _strftime_l, _wcsftime_l
Formate uma cadeia de caracteres de hora.  
  
## <a name="syntax"></a>Sintaxe  
  
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
  
#### <a name="parameters"></a>Parâmetros  
 `strDest`  
 Cadeia de caracteres de saída.  
  
 `maxsize`  
 Tamanho do `strDest` buffer, medido em caracteres (`char` ou `wchart_t`).  
  
 `format`  
 Cadeia de caracteres de controle de formato.  
  
 `timeptr`  
 estrutura de dados `tm`.  
  
 `locale`  
 A localidade a ser usada.  
  
## <a name="return-value"></a>Valor de retorno  
 `strftime` retorna o número de caracteres colocados em `strDest` e `wcsftime` retorna o número correspondente de caracteres largos.  
  
 Se o número total de caracteres, incluindo a terminação nula, é mais de `maxsize`, ambos `strftime` e `wcsftime` retornam 0 e os conteúdos de `strDest` serão indeterminados.  
  
 O número de caracteres em `strDest` é igual ao número de caracteres literais em `format`, bem como quaisquer caracteres que possam ser adicionados ao `format` por meio de códigos de formatação. A terminação nula de uma cadeia de caracteres não será contada no valor retornado.  
  
## <a name="remarks"></a>Comentários  
 O `strftime` e `wcsftime` formato de funções de `tm` tempo valor em `timeptr` conforme fornecido `format` argumento e o resultado no buffer de armazenamento `strDest`. No máximo, caracteres `maxsize` são colocados na cadeia de caracteres. Para obter uma descrição dos campos na estrutura `timeptr`, consulte [asctime](../../c-runtime-library/reference/asctime-wasctime.md). `wcsftime` é o equivalente de caractere largo de `strftime`; seu argumento de cadeia de caracteres aponta para uma cadeia de caracteres largos. Caso contrário, essas funções se comportam de forma idêntica.  
  
> [!NOTE]
>  Nas versões anteriores do Visual C++ 2005, a documentação descrevia o parâmetro `format` de `wcsftime` como tendo o tipo de dados `const wchar_t *`, mas a implementação real do tipo de dados de `format` foi de `const char *`. A implementação de `format` tipo de dados foi atualizado para refletir a documentação atual e anterior, ou seja, `const wchar_t *`.  
  
 Essa função valida seus parâmetros. Se `strDest`, `format`, ou `timeptr` é um ponteiro nulo, ou se o `tm` estrutura de dados endereçados por `timeptr` é inválido (por exemplo, se ele contém valores fora do intervalo para a hora ou data), ou se o `format` cadeia de caracteres contém um código de formatação inválido, o manipulador de parâmetro inválido é invocado, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, a função retornará 0 e definirá `errno` como `EINVAL`.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_tcsftime`|`strftime`|`strftime`|`wcsftime`|  
  
 O `format` argumento consiste de um ou mais códigos, como em `printf`, os códigos de formatação são precedidos por um sinal de porcentagem (`%`). Caracteres que não começam com `%` são copiados inalterada para `strDest`. A categoria `LC_TIME` da localidade atual afeta a formatação de saída de `strftime`. (Para obter mais informações sobre `LC_TIME`, consulte [setlocale](../../c-runtime-library/reference/setlocale-wsetlocale.md).) As funções sem o sufixo `_l` usam a localidade definida atualmente. As versões dessas funções com o sufixo `_l` são idênticas, exceto que usam a localidade como parâmetro e a usam em vez da localidade definida atualmente. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 Os códigos de formatação do `strftime` estão listados abaixo:  
  
 `%a`  
 Nome abreviado do dia  
  
 `%A`  
 Nomes dos dias da semana por extenso  
  
 `%b`  
 Nome abreviado do mês  
  
 `%B`  
 Nome completo do mês  
  
 `%c`  
 Representação de data e hora apropriada para a localidade  
  
 `%d`  
 Dia do mês como um número decimal (01-31)  
  
 `%H`  
 Hora no formato de 24 horas (00 - 23)  
  
 `%I`  
 Hora no formato de 12 horas (01-12)  
  
 `%j`  
 Dia do ano como um número decimal (001-366)  
  
 `%m`  
 Mês como um número decimal (01-12)  
  
 `%M`  
 Minuto como um número decimal (00 - 59)  
  
 `%p`  
 AM/PM da localidade atual. Indicador para relógio de 12 horas  
  
 `%S`  
 Segundo como um número decimal (00 - 59)  
  
 `%U`  
 Semana do ano como um número decimal, considerando o domingo como o primeiro dia da semana (00 - 53)  
  
 `%w`  
 Dia da semana como um número decimal (0 - 6; Domingo é 0)  
  
 `%W`  
 Semana do ano como um número decimal, considerando o domingo como o primeiro dia da semana (00 - 53)  
  
 `%x`  
 Representação de data para a localidade atual  
  
 `%X`  
 Representação de hora para a localidade atual  
  
 `%y`  
 Ano sem século, como número decimal (00 - 99)  
  
 `%Y`  
 Ano com século, como o número decimal  
  
 `%z, %Z`  
 O nome do fuso horário ou abreviação de fuso horário, dependendo das configurações do Registro; Nenhum caractere se o fuso horário é desconhecido  
  
 `%%`  
 Símbolo de porcentagem  
  
 Como na função `printf`, o `#` sinalizador pode ser prefixo em qualquer código de formatação. Nesse caso, o significado do código de formatação é alterado da seguinte maneira.  
  
|Código de formatação|Significado|  
|-----------------|-------------|  
|`%#a, %#A, %#b, %#B, %#p, %#X, %#z, %#Z, %#%`|`#` sinalizador é ignorado.|  
|`%#c`|Representação longa de data e hora, apropriada para a localidade atual. Por exemplo: "Terça-feira, 14 de março de 1995, 12:41:29".|  
|`%#x`|Representação longa de data, apropriada para a localidade atual. Por exemplo: "Terça-feira, 14 de março de 1995".|  
|`%#d, %#H, %#I, %#j, %#m, %#M, %#S, %#U, %#w, %#W, %#y, %#Y`|Remova os zeros à esquerda (se houver).|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`strftime`|\<time.h>|  
|`wcsftime`|\<time.h> ou \<wchar.h>|  
|`_strftime_l`|\<time.h>|  
|`_wcsftime_l`|\<time.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
 Veja o exemplo de [time](../../c-runtime-library/reference/time-time32-time64.md).  
  
## <a name="see-also"></a>Consulte também  
 [Localidade](../../c-runtime-library/locale.md)   
 [Gerenciamento de Tempo](../../c-runtime-library/time-management.md)   
 [Manipulação de cadeias de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [localeconv](../../c-runtime-library/reference/localeconv.md)   
 [setlocale, _wsetlocale](../../c-runtime-library/reference/setlocale-wsetlocale.md)   
 [Funções strcoll](../../c-runtime-library/strcoll-functions.md)   
 [strxfrm, wcsxfrm, _strxfrm_l, _wcsxfrm_l](../../c-runtime-library/reference/strxfrm-wcsxfrm-strxfrm-l-wcsxfrm-l.md)