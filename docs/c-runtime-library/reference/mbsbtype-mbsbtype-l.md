---
title: "_mbsbtype, _mbsbtype_l | Microsoft Docs"
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
  - "_mbsbtype_l"
  - "_mbsbtype"
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
  - "mbsbtype"
  - "mbsbtype_l"
  - "_mbsbtype_l"
  - "_mbsbtype"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _mbsbtype"
  - "Função _mbsbtype_l"
  - "Função mbsbtype"
  - "Função mbsbtype_l"
ms.assetid: 0d5dd91a-d32d-4f98-ac57-98dfc9e98eac
caps.latest.revision: 19
caps.handback.revision: 19
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _mbsbtype, _mbsbtype_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Retorna o tipo de bytes em uma cadeia de caracteres.  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos que executam no Tempo de Execução do Windows.  Para obter mais informações, consulte [Funções CRT sem suporte pelo \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
int _mbsbtype(  
   const unsigned char *mbstr,  
   size_t count   
);  
int _mbsbtype_l(  
   const unsigned char *mbstr,  
   size_t count,  
   _locale_t locale   
);  
```  
  
#### Parâmetros  
 `mbstr`  
 Endereço de uma sequência de caracteres multibyte.  
  
 `count`  
 Cabeçalho de deslocamento de byte da cadeia de caracteres.  
  
 `locale`  
 Localidade a ser usada.  
  
## Valor de retorno  
 `_mbsbtype` e `_mbsbtype_l`retornam um valor inteiro que indica o resultado de teste no byte especificado.  As constantes de manifesto na tabela a seguir são definidas em Mbctype.h.  
  
|Valor de retorno|Tipo de byte|  
|----------------------|------------------|  
|`_MBC_SINGLE` \(0\)|Caractere de byte único.  Por exemplo, na página de código 932, `_mbsbtype` retorna 0 se o byte especificado estiver dentro do intervalo de 0x20 a 0x7E ou de 0xA1 a 0xDF.|  
|`_MBC_LEAD` \(1\)|Primeiro byte do caractere de multibyte.  Por exemplo, na página de código 932, `_mbsbtype` retorna 1 se o byte especificado estiver dentro do intervalo de 0x81 a 0x9F ou de 0xE0 a 0xFC.|  
|`_MBC_TRAIL` \(2\)|Byte à direita de caractere multibyte.  Por exemplo, na página de código 932, `_mbsbtype` retorna 2 se o byte especificado estiver dentro do intervalo de 0x40 a 0x7E ou de 0x80 a 0xFC.|  
|`_MBC_ILLEGAL` \(–1\)|`NULL` cadeia de caracteres, caractere inválido ou `NULL` byte encontrado antes do byte no deslocamento `count` em `mbstr`.|  
  
## Comentários  
 A função `_mbsbtype` determina o tipo de um byte em uma cadeia de caracteres multibyte.  A função examina somente o byte no deslocamento `count` em `mbstr`, ignorando os caracteres inválidos antes do bytes especificado.  
  
 O valor de saída é afetado pela configuração da categoria `LC_CTYPE` de localidade. Para obter mais informações, consulte [setlocale](../Topic/setlocale,%20_wsetlocale.md).  A versão dessa função sem o sufixo `_l` usa a localidade atual para esse comportamento dependente da localidade; a versão com o sufixo `_l` é idêntica, exceto pelo fato de que ela usa o parâmetro de localidade informado.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 Se a cadeia de caracteres de entrada for `NULL`, o manipulador de parâmetro inválido será chamado, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, `errno` será definido como `EINVAL` e a função retornará `_MBC_ILLEGAL`.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalho opcional|  
|------------|--------------------------|------------------------|  
|`_mbsbtype`|\<mbstring.h\>|\<mbctype.h\>\*|  
|`_mbsbtype_l`|\<mbstring.h\>|\<mbctype.h\>\*|  
  
 \* No caso de constantes de manifesto usadas como valores de retorno.  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Equivalência do .NET Framework  
 Não aplicável, mas consulte [System::Globalization::CultureInfo](https://msdn.microsoft.com/en-us/library/system.globalization.cultureinfo.aspx).  
  
## Consulte também  
 [Classificação de byte](../../c-runtime-library/byte-classification.md)