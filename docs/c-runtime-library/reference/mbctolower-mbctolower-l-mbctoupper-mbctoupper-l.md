---
title: "_mbctolower, _mbctolower_l, _mbctoupper, _mbctoupper_l | Microsoft Docs"
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
  - "_mbctolower_l"
  - "_mbctoupper_l"
  - "_mbctoupper"
  - "_mbctolower"
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
  - "mbctoupper_l"
  - "mbctolower_l"
  - "_mbctolower"
  - "_mbctolower_l"
  - "_mbctoupper"
  - "mbctoupper"
  - "mbctolower"
  - "_mbctoupper_l"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _mbctolower"
  - "Função _mbctolower_l"
  - "Função _mbctoupper"
  - "Função _mbctoupper_l"
  - "Função _totlower"
  - "Função _totupper"
  - "Função mbctolower"
  - "Função mbctolower_l"
  - "Função mbctoupper"
  - "Função mbctoupper_l"
  - "Função totlower"
  - "Função totupper"
ms.assetid: 787fab71-3224-4ed7-bc93-4dcd8023fc54
caps.latest.revision: 18
caps.handback.revision: 18
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _mbctolower, _mbctolower_l, _mbctoupper, _mbctoupper_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Testa e converte o caso de um caractere multibyte.  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos que executam no Tempo de Execução do Windows.  Para obter mais informações, consulte [Funções CRT sem suporte pelo \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
unsigned int _mbctolower(  
   unsigned int c   
);  
unsigned int _mbctolower_l(  
   unsigned int c,  
   _locale_t locale  
);  
unsigned int _mbctoupper(  
   unsigned int c   
);  
unsigned int _mbctoupper_l(  
   unsigned int c,  
   _locale_t locale  
);  
```  
  
#### Parâmetros  
 `c`  
 Caractere de multibyte a ser convertido.  
  
 `locale`  
 Localidade a ser usada.  
  
## Valor de retorno  
 Cada uma dessas funções retorna o caractere convertido `c`, se possível.  Do contrário, ela retorna o caractere `c` inalterado.  
  
## Comentários  
 As funções testam um caractere `c` e, se possível, aplicam uma das seguintes conversões.  
  
|Rotinas|Converte|  
|-------------|--------------|  
|`_mbctolower,_mbctolower_l`|Caractere maiúsculo para caractere minúsculo.|  
|`_mbctoupper,_mbctoupper_l`|Caractere minúsculo para caractere maiúsculo.|  
  
 O valor de saída é afetado pela configuração da categoria `LC_CTYPE` de localidade. Para obter mais informações, consulte [setlocale](../Topic/setlocale,%20_wsetlocale.md).  A versão dessa função sem o sufixo `_l` usa a localidade atual para esse comportamento dependente da localidade; a versão com o sufixo `_l` é idêntica, exceto pelo fato de que ela usa o parâmetro de localidade informado.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 Em versões anteriores, `_mbctolower` era chamado de`jtolower`, e `_mbctoupper` era chamado de `jtoupper`.  Para o novo código, use os nomes novos em vez disso.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_totlower`|`tolower`|`_mbctolower`|`towlower`|  
|`_totlower_l`|`_tolower_l`|`_mbctolower_l`|`_towlower_t`|  
|`_totupper`|`toupper`|`_mbctoupper`|`towupper`|  
|`_totupper_l`|`toupper_l`|`_mbctoupper_l`|`_towupper_l`|  
  
## Requisitos  
  
|Rotinas|Cabeçalho necessário|  
|-------------|--------------------------|  
|`_mbctolower,_mbctolower_l`|\<mbstring.h\>|  
|`_mbctoupper,_mbctoupper_l`|\<mbstring.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Consulte também  
 [Conversão de dados](../../c-runtime-library/data-conversion.md)   
 [\_mbbtombc, \_mbbtombc\_l](../../c-runtime-library/reference/mbbtombc-mbbtombc-l.md)   
 [\_mbcjistojms, \_mbcjistojms\_l, \_mbcjmstojis, \_mbcjmstojis\_l](../../c-runtime-library/reference/mbcjistojms-mbcjistojms-l-mbcjmstojis-mbcjmstojis-l.md)   
 [\_mbctohira, \_mbctohira\_l, \_mbctokata, \_mbctokata\_l](../Topic/_mbctohira,%20_mbctohira_l,%20_mbctokata,%20_mbctokata_l.md)   
 [\_mbctombb, \_mbctombb\_l](../../c-runtime-library/reference/mbctombb-mbctombb-l.md)