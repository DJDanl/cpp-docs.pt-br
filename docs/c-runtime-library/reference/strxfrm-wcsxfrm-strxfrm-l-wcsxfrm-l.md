---
title: "strxfrm, wcsxfrm, _strxfrm_l, _wcsxfrm_l | Microsoft Docs"
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
  - "strxfrm"
  - "_wcsxfrm_l"
  - "_strxfrm_l"
  - "wcsxfrm"
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
  - "api-ms-win-crt-string-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "strxfrm"
  - "_tcsxfrm"
  - "wcsxfrm"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _strxfrm_l"
  - "Função _tcsxfrm"
  - "Função _wcsxfrm_l"
  - "comparação de cadeias de caracteres [C++], transformando cadeias de caracteres"
  - "cadeias de caracteres [C++], comparando a localidade"
  - "Função strxfrm"
  - "Função strxfrm_l"
  - "Função tcsxfrm"
  - "Função wcsxfrm"
  - "Função wcsxfrm_l"
ms.assetid: 6ba8e1f6-4484-49aa-83b8-bc2373187d9e
caps.latest.revision: 18
caps.handback.revision: 18
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# strxfrm, wcsxfrm, _strxfrm_l, _wcsxfrm_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Transformar uma cadeia de caracteres com base nas informações de localidade específica.  
  
## Sintaxe  
  
```  
size_t strxfrm(  
   char *strDest,  
   const char *strSource,  
   size_t count   
);  
size_t wcsxfrm(  
   wchar_t *strDest,  
   const wchar_t *strSource,  
   size_t count   
);  
size_t _strxfrm_l(  
   char *strDest,  
   const char *strSource,  
   size_t count,  
   _locale_t locale  
);  
size_t wcsxfrm_l(  
   wchar_t *strDest,  
   const wchar_t *strSource,  
   size_t count,  
   _locale_t locale  
);  
```  
  
#### Parâmetros  
 `strDest`  
 Cadeia de caracteres de destino.  
  
 `strSource`  
 Cadeia de caracteres de origem.  
  
 `count`  
 Número máximo de caracteres a ser colocado em `strDest`*.*  
  
 `locale`  
 A localidade a ser usada.  
  
## Valor de retorno  
 Retorna o comprimento da cadeia de caracteres se não, contando o caractere nulo sendo encerrado.  Se o valor de retorno for maior ou igual a `count`, o conteúdo de `strDest` é imprevisível.  Em um erro, cada função define `errno` e retorna `INT_MAX`.  Para um caractere inválido, `errno` é definido como `EILSEQ`.  
  
## Comentários  
 A função de `strxfrm` torna a cadeia de caracteres apontada por `strSource` em um novo formato ordenado que é armazenado em `strDest`.  Não mais do que os caracteres de `count` , incluindo o caractere nulo, são transformadas e colocadas na cadeia de caracteres resultante.  A transformação é feita usando a configuração da categoria de `LC_COLLATE` de localidade.  Para obter mais informações sobre `LC_COLLATE`, consulte [setlocale](../Topic/setlocale,%20_wsetlocale.md).  `strxfrm` usa a localidade atual para seu comportamento dependente de localidade; `_strxfrm_l` é idêntico exceto que usa a localidade transmitido em vez da localidade atual.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 Após a transformação, uma chamada a `strcmp` com as duas cadeias de caracteres que transformadas gera os resultados idêntico ao de uma chamada para `strcoll` aplicada às duas cadeias de caracteres originais.  Como com `strcoll` e `stricoll`, `strxfrm` controla automaticamente cadeias de caracteres de multibyte\- caracteres conforme apropriado.  
  
 `wcsxfrm` é uma versão de ampla caractere de `strxfrm`; os argumentos de cadeia de caracteres de `wcsxfrm` são ponteiros de ampla caractere.  Para `wcsxfrm`, depois que a transformação de cadeia de caracteres, uma chamada a `wcscmp` com dois gera transformados de cadeias de caracteres resultante idêntico ao de uma chamada para `wcscoll` aplicada às duas cadeias de caracteres originais.  Caso contrário, `wcsxfrm` e `strxfrm`, ao contrário, se comportam de forma idêntica.  `wcsxfrm` usa a localidade atual para seu comportamento dependente de localidade; `_wcsxfrm_l` usa a localidade transmitido em vez da localidade atual.  
  
 Essas funções validam seus parâmetros.  Se `strSource` for um ponteiro nulo, ou `strDest` é um ponteiro NULL \(a menos que a pontuação é zero\), ou se `count` é maior que `INT_MAX`, o manipulador inválido do parâmetro será chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md) .  Se a execução puder continuar, essas funções definirão `errno` como `EINVAL` e retornarão `INT_MAX`.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_tcsxfrm`|`strxfrm`|`strxfrm`|`wcsxfrm`|  
|`_tcsxfrm_l`|`_strxfrm_l`|`_strxfrm_l`|`_wcsxfrm_l`|  
  
 Na localidade de C “2.0”, a ordem dos caracteres no conjunto de caracteres \(conjunto de caracteres ASCII\) é igual à ordem lexicographic de caracteres.  No entanto, em outras localidades, a ordem de caracteres no conjunto de caracteres pode diferir da ordem lexicographic de caractere.  Por exemplo, em algumas localidades europeias, o caractere “a” \(valor 0x61\) precede o caractere '&\#x00E4; '\(valor\) 0xE4 no conjunto de caracteres, mas o caractere “ä” precede o caractere “a” lexicographically.  
  
 Nas localidades para o conjunto de caracteres e ordem lexicographic de caracteres diferem, use `strxfrm` em cadeias de caracteres original e `strcmp` em cadeias de caracteres resultante gerar em uma comparação de cadeia de caracteres lexicographic de acordo com a configuração atual da categoria de `LC_COLLATE` de localidade.  Assim, para comparar lexicographically duas cadeias de caracteres na localidade acima, use `strxfrm` em cadeias de caracteres original, em `strcmp` em cadeias de caracteres resultante.  Como alternativa, você pode usar `strcoll` em vez de `strcmp` em cadeias de caracteres originais.  
  
 `strxfrm` é basicamente um wrapper em torno de [LCMapString](http://msdn.microsoft.com/library/windows/desktop/dd318700) com `LCMAP_SORTKEY`.  
  
 O valor da expressão seguinte é o tamanho da matriz necessária para manter a transformação de `strxfrm` de cadeia de caracteres de origem:  
  
```  
1 + strxfrm( NULL, string, 0 )  
```  
  
 Na localidade de “C” somente 2.0, `strxfrm` é equivalente à seguinte:  
  
```  
strncpy( _string1, _string2, _count );  
return( strlen( _string1 ) );  
```  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`strxfrm`|\<string.h\>|  
|`wcsxfrm`|\<string.h\> ou \<wchar.h\>|  
|`_strxfrm_l`|\<string.h\>|  
|`_wcsxfrm_l`|\<string.h\> ou \<wchar.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Conversão de dados](../../c-runtime-library/data-conversion.md)   
 [localeconv](../../c-runtime-library/reference/localeconv.md)   
 [setlocale, \_wsetlocale](../Topic/setlocale,%20_wsetlocale.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Manipulação da cadeia de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [Funções strcoll](../../c-runtime-library/strcoll-functions.md)   
 [strcmp, wcscmp, \_mbscmp](../Topic/strcmp,%20wcscmp,%20_mbscmp.md)   
 [strncmp, wcsncmp, \_mbsncmp, \_mbsncmp\_l](../../c-runtime-library/reference/strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)