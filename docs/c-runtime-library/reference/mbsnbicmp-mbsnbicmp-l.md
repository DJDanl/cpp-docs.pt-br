---
title: "_mbsnbicmp, _mbsnbicmp_l | Microsoft Docs"
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
  - "_mbsnbicmp_l"
  - "_mbsnbicmp"
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
apitype: "DLLExport"
f1_keywords: 
  - "_strnicmp"
  - "_wcsnicmp_l"
  - "_mbsnbicmp"
  - "mbsnbicmp"
  - "mbsnbicmp_l"
  - "_tcsnicmp"
  - "_strnicmp_l"
  - "_tcsnicmp_l"
  - "_wcsnicmp"
  - "_mbsnbicmp_l"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _mbsnbicmp"
  - "Função _mbsnbicmp_l"
  - "Função _strnicmp"
  - "Função _strnicmp_l"
  - "Função _tcsnicmp"
  - "Função _tcsnicmp_l"
  - "Função _wcsnicmp"
  - "Função _wcsnicmp_l"
  - "Função mbsnbicmp"
  - "Função mbsnbicmp_l"
ms.assetid: ddb44974-8b0c-42f0-90d0-56c9350bae0c
caps.latest.revision: 16
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _mbsnbicmp, _mbsnbicmp_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Compara `n` bytes de caracteres multibyte duas cadeias de caracteres e diferencia maiúsculas de minúsculas.  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows.  Para obter mais informações, consulte [Funções de CRT sem suporte com \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
int _mbsnbicmp(  
   const unsigned char *string1,  
   const unsigned char *string2,  
   size_t count   
);  
```  
  
#### Parâmetros  
 `string1, string2`  
 Caracteres de terminação nula para comparar.  
  
 `count`  
 Número de bytes a ser comparado.  
  
## Valor de retorno  
 O valor de retorno indica a relação entre as subcadeias de caracteres.  
  
|Valor de retorno|Descrição|  
|----------------------|---------------|  
|\< 0|`string1` subcadeia de caracteres menor que `string2` subcadeia de caracteres.|  
|0|`string1` subcadeia de caracteres idêntica à `string2` subcadeia de caracteres.|  
|\> 0|`string1` subcadeia de caracteres maior que `string2` subcadeia de caracteres.|  
  
 Em caso de erro, `_mbsnbcmp` retorna `_NLSCMPERROR`, que é definido em String. h e Mbstring.h.  
  
## Comentários  
 O `_mbsnbicmp` função executa uma comparação ordinal do primeiro no máximo `count` bytes de `string1` e `string2`.  A comparação é realizada, convertendo cada caractere em minúsculas; `_mbsnbcmp` é uma versão de maiúsculas e minúsculas do `_mbsnbicmp`.  A comparação termina se um caractere nulo de terminação for atingido na cadeia de caracteres antes de `count` caracteres são comparados.  Se as cadeias de caracteres são iguais quando um caractere nulo de terminação for alcançado na cadeia de caracteres antes de `count` caracteres são comparados, a cadeia de caracteres mais curta é menor.  
  
 `_mbsnbicmp`  é semelhante ao `_mbsnicmp`, exceto que ela compara cadeias de caracteres de até `count` bytes em vez de caracteres.  
  
 Duas cadeias de caracteres que contém caracteres localizado entre 'Z' e 'a' na tabela ASCII \('\[', ' \\', '\]', ' ^', '\_' e ' '\) comparar diferente, dependendo do seu caso.  Por exemplo, duas cadeias de caracteres "`ABCDE`"e"`ABCD^`" comparar uma forma se a comparação é minúscula \("`abcde`" \> "`abcd^`"\) e a outra forma \("`ABCDE`" \< "`ABCD^`"\) se for maiúscula.  
  
 `_mbsnbicmp` reconhece sequências de caracteres multibyte de acordo com o [página de código multibyte](../../c-runtime-library/code-pages.md) atualmente em uso.  Ela não é afetada pela configuração de localidade atual.  
  
 Se `string1` ou `string2` é um ponteiro nulo, `_mbsnbicmp` invoca o manipulador de parâmetro inválido, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, a função retornará `_NLSCMPERROR` e define `errno` para `EINVAL`.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_tcsnicmp`|`_strnicmp`|`_mbsnbicmp`|`_wcsnicmp`|  
|`_tcsnicmp_l`|`_strnicmp_l`|`_mbsnbicmp_l`|`_wcsnicmp_l`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_mbsnbicmp`|\<mbstring.h\>|  
  
 Para obter mais informações de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
 Veja o exemplo de [\_mbsnbcmp, \_mbsnbcmp\_l](../../c-runtime-library/reference/mbsnbcmp-mbsnbcmp-l.md).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Manipulação da cadeia de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [\_mbsnbcat, \_mbsnbcat\_l](../../c-runtime-library/reference/mbsnbcat-mbsnbcat-l.md)   
 [\_mbsnbcmp, \_mbsnbcmp\_l](../../c-runtime-library/reference/mbsnbcmp-mbsnbcmp-l.md)   
 [\_stricmp, \_wcsicmp, \_mbsicmp, \_stricmp\_l, \_wcsicmp\_l, \_mbsicmp\_l](../../c-runtime-library/reference/stricmp-wcsicmp-mbsicmp-stricmp-l-wcsicmp-l-mbsicmp-l.md)