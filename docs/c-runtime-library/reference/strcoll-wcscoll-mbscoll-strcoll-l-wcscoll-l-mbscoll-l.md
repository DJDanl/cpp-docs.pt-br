---
title: "strcoll, wcscoll, _mbscoll, _strcoll_l, _wcscoll_l, _mbscoll_l | Microsoft Docs"
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
  - "wcscoll"
  - "_mbscoll"
  - "_mbscoll_l"
  - "strcoll"
  - "_strcoll_l"
  - "_wcscoll_l"
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
  - "api-ms-win-crt-multibyte-l1-1-0.dll"
  - "api-ms-win-crt-string-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "wcscoll"
  - "_mbscoll"
  - "_tcscoll"
  - "_ftcscoll"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "páginas de código, usando para comparações de cadeia de caracteres"
  - "Função mbscoll"
  - "Função wcscoll_l"
  - "Função ftcscoll"
  - "Função wcscoll"
  - "Função _strcoll_l"
  - "Função tcscoll"
  - "Função _ftcscoll"
  - "Função _tcscoll"
  - "Função _wcscoll_l"
  - "Função _mbscoll"
  - "Função strcoll_l"
  - "Funções strcoll"
  - "cadeias de caracteres [C++], comparando por página de código"
ms.assetid: 900a7540-c7ec-4c2f-b292-7a85f63e3fe8
caps.latest.revision: 20
caps.handback.revision: 20
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# strcoll, wcscoll, _mbscoll, _strcoll_l, _wcscoll_l, _mbscoll_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Compara cadeias de caracteres usando a localidade atual ou uma categoria especificada de conversão\- estado de LC\_COLLATE.  
  
> [!IMPORTANT]
>  `_mbscoll` e `_mbscoll_l` não podem ser usados em aplicativos executados no Tempo de Execução do Windows.  Para obter mais informações, consulte [Funções CRT sem suporte pelo \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
int strcoll(  
   const char *string1,  
   const char *string2   
);  
int wcscoll(  
   const wchar_t *string1,  
   const wchar_t *string2   
);  
int _mbscoll(  
   const unsigned char *string1,  
   const unsigned char *string2   
);  
int _strcoll_l(  
   const char *string1,  
   const char *string2,  
   _locale_t locale   
);  
int wcscoll_l(  
   const wchar_t *string1,  
   const wchar_t *string2,  
   _locale_t locale   
);  
int _mbscoll_l(  
   const unsigned char *string1,  
   const unsigned char *string2,  
   _locale_t locale   
);  
```  
  
#### Parâmetros  
 `string1`, `string2`  
 Cadeias de caracteres terminadas com Null para comparação.  
  
 `locale`  
 Localidade a ser usada.  
  
## Valor de retorno  
 Cada uma dessas funções retorna um valor que indica a relação de `string1` com `string2`*,*, conforme a seguir  
  
|Valor de retorno|Relação de string1 com string2|  
|----------------------|------------------------------------|  
|\< 0|`string1` menor que `string2`|  
|0|`string1` idêntico a `string2`|  
|\> 0|`string1` maior que `string2`|  
  
 Cada uma dessas funções retorna `_NLSCMPERROR` em um erro.  Para usar `_NLSCMPERROR`, inclua STRING.H ou MBSTRING.H.  `wcscoll` pode falhar se `string1` ou `string2` for NULO ou contiver códigos de caracteres amplos fora do domínio da sequencia de agrupamento.  Quando ocorre um erro, `wcscoll` pode definir `errno` como `EINVAL`.  Para verificar se há um erro em uma chamada a `wcscoll`, defina `errno` para 0 e verifique `errno` após a chamada `wcscoll`.  
  
## Comentários  
 Cada uma dessas funções executa uma comparação que diferencia maiúsculas de minúsculas de `string1` e de `string2` de acordo com a página de código atualmente em uso.  Essas funções devem ser usadas somente quando há uma diferença entre a ordem do conjunto de caracteres e a ordem de caracteres lexicográficos na página de código atual, e essa diferença é interessante para comparação de cadeia de caracteres.  
  
 Todas essas funções validam seus parâmetros.  Se `string1` ou `string2` for um ponteiro nulo, ou se `count` for maior que `INT_MAX`, o manipulador de parâmetro inválido será chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md) .  Se a execução puder continuar, essas funções retornarão `_NLSCMPERROR` e definirão `errno` para `EINVAL`.  
  
 A comparação das duas cadeias de caracteres é uma operação dependente de local, visto que cada localidade tem diferentes regras para ordenar caracteres.  As versões dessas funções sem o sufixo `_l` usam a localidade do thread atual para esse comportamento dependente de localidade; as versões com o sufixo `_l` são idênticas à função correspondente sem o sufixo, exceto pelo fato de que elas usam a localidade informada como um parâmetro, em vez da localidade atual.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_tcscoll`|`strcoll`|`_mbscoll`|`wcscoll`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`strcoll`|\<string.h\>|  
|`wcscoll`|\<wchar.h\>, \<string.h\>|  
|`_mbscoll`, `_mbscoll_l`|\<mbstring.h\>|  
|`_strcoll_l`|\<string.h\>|  
|`_wcscoll_l`|\<wchar.h\>, \<string.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Equivalência do .NET Framework  
 [System::String::Compare](https://msdn.microsoft.com/en-us/library/system.string.compare.aspx)  
  
## Consulte também  
 [Localidade](../../c-runtime-library/locale.md)   
 [Manipulação da cadeia de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [Funções strcoll](../../c-runtime-library/strcoll-functions.md)   
 [localeconv](../../c-runtime-library/reference/localeconv.md)   
 [\_mbsnbcoll, \_mbsnbcoll\_l, \_mbsnbicoll, \_mbsnbicoll\_l](../../c-runtime-library/reference/mbsnbcoll-mbsnbcoll-l-mbsnbicoll-mbsnbicoll-l.md)   
 [setlocale, \_wsetlocale](../Topic/setlocale,%20_wsetlocale.md)   
 [strcmp, wcscmp, \_mbscmp](../Topic/strcmp,%20wcscmp,%20_mbscmp.md)   
 [\_stricmp, \_wcsicmp, \_mbsicmp, \_stricmp\_l, \_wcsicmp\_l, \_mbsicmp\_l](../../c-runtime-library/reference/stricmp-wcsicmp-mbsicmp-stricmp-l-wcsicmp-l-mbsicmp-l.md)   
 [strncmp, wcsncmp, \_mbsncmp, \_mbsncmp\_l](../../c-runtime-library/reference/strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)   
 [\_strnicmp, \_wcsnicmp, \_mbsnicmp, \_strnicmp\_l, \_wcsnicmp\_l, \_mbsnicmp\_l](../../c-runtime-library/reference/strnicmp-wcsnicmp-mbsnicmp-strnicmp-l-wcsnicmp-l-mbsnicmp-l.md)   
 [strxfrm, wcsxfrm, \_strxfrm\_l, \_wcsxfrm\_l](../../c-runtime-library/reference/strxfrm-wcsxfrm-strxfrm-l-wcsxfrm-l.md)