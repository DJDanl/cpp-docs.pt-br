---
title: _mbsnbicmp, _mbsnbicmp_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _mbsnbicmp_l
- _mbsnbicmp
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
- api-ms-win-crt-multibyte-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _strnicmp
- _wcsnicmp_l
- _mbsnbicmp
- mbsnbicmp
- mbsnbicmp_l
- _tcsnicmp
- _strnicmp_l
- _tcsnicmp_l
- _wcsnicmp
- _mbsnbicmp_l
dev_langs: C++
helpviewer_keywords:
- _tcsnicmp_l function
- _strnicmp function
- mbsnbicmp_l function
- _wcsnicmp_l function
- _mbsnbicmp function
- _mbsnbicmp_l function
- _tcsnicmp function
- _strnicmp_l function
- mbsnbicmp function
- _wcsnicmp function
ms.assetid: ddb44974-8b0c-42f0-90d0-56c9350bae0c
caps.latest.revision: "16"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 6abe7372f42e679264ec501918ad62823ba53ba9
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="mbsnbicmp-mbsnbicmpl"></a>_mbsnbicmp, _mbsnbicmp_l
Compara `n` bytes de duas cadeias de caracteres multibyte e ignora as maiúsculas e minúsculas.  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, consulte [Funções de CRT sem suporte com /ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _mbsnbicmp(  
   const unsigned char *string1,  
   const unsigned char *string2,  
   size_t count   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `string1, string2`  
 Cadeias de caracteres com terminação nula.  
  
 `count`  
 Número de bytes a serem comparados.  
  
## <a name="return-value"></a>Valor de retorno  
 O valor retornado indica a relação entre as subcadeias de caracteres.  
  
|Valor retornado|Descrição|  
|------------------|-----------------|  
|< 0|Subcadeia de caracteres `string1` menor do que a subcadeia de caracteres `string2`.|  
|0|Subcadeia de caracteres `string1` idêntica à subcadeia de caracteres `string2`.|  
|> 0|Subcadeia de caracteres `string1` maior que a subcadeia de caracteres `string2`.|  
  
 Em um erro, `_mbsnbcmp` retorna `_NLSCMPERROR`, que é definido em String.h e Mbstring.h.  
  
## <a name="remarks"></a>Comentários  
 A função `_mbsnbicmp` executa uma comparação ordinal de no máximo os primeiros `count` bytes de `string1` e `string2`. A comparação é executada convertendo cada caractere em minúscula, `_mbsnbcmp` é a versão que diferencia maiúsculas e minúsculas de `_mbsnbicmp`. A comparação termina se um caractere nulo de terminação é atingido em qualquer cadeia de caracteres antes dos `count` caracteres serem comparados. Se as cadeias de caracteres forem iguais quando um caractere nulo de terminação for atingido em qualquer cadeia de caracteres antes dos `count` caracteres serem comparados, a cadeia de caracteres mais curta será menor.  
  
 `_mbsnbicmp` é semelhante a `_mbsnicmp`, exceto que ela compara cadeias de caracteres de até `count` bytes em vez de por caracteres.  
  
 Duas cadeias de caracteres que contêm caracteres localizados entre 'Z' e 'a' na tabela ASCII ('[', '\\', ']', '^', '_' e '\`') são comparadas de modo diferente, dependendo das maiúsculas e minúsculas delas. Por exemplo, as duas cadeias de caracteres "`ABCDE`" e "`ABCD^`" são comparadas de uma forma se a comparação é em minúscula ("`abcde`" > "`abcd^`") e de outra forma ("`ABCDE`" < "`ABCD^`") se a comparação é em maiúscula.  
  
 `_mbsnbicmp` reconhece sequências de caracteres multibyte de acordo com a [página de código multibyte](../../c-runtime-library/code-pages.md) atualmente em uso. Ela não é afetada pela configuração da localidade atual.  
  
 Se `string1` ou `string2` for um ponteiro nulo, `_mbsnbicmp` invocará o manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, a função retornará `_NLSCMPERROR` e definirá `errno` como `EINVAL`.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|--------------------------------------|--------------------|-----------------------|  
|`_tcsnicmp`|`_strnicmp`|`_mbsnbicmp`|`_wcsnicmp`|  
|`_tcsnicmp_l`|`_strnicmp_l`|`_mbsnbicmp_l`|`_wcsnicmp_l`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_mbsnbicmp`|<mbstring.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
 Veja o exemplo de [_mbsnbcmp, _mbsnbcmp_l](../../c-runtime-library/reference/mbsnbcmp-mbsnbcmp-l.md).  
  
## <a name="see-also"></a>Consulte também  
 [Manipulação de cadeias de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [_mbsnbcat, _mbsnbcat_l](../../c-runtime-library/reference/mbsnbcat-mbsnbcat-l.md)   
 [_mbsnbcmp, _mbsnbcmp_l](../../c-runtime-library/reference/mbsnbcmp-mbsnbcmp-l.md)   
 [_stricmp, _wcsicmp, _mbsicmp, _stricmp_l, _wcsicmp_l, _mbsicmp_l](../../c-runtime-library/reference/stricmp-wcsicmp-mbsicmp-stricmp-l-wcsicmp-l-mbsicmp-l.md)