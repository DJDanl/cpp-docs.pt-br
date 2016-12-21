---
title: "_mbbtype, _mbbtype_l | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_mbbtype"
  - "_mbbtype_l"
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
  - "_mbbtype_l"
  - "mbbtype"
  - "mbbtype_l"
  - "_mbbtype"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _mbbtype"
  - "Função _mbbtype_l"
  - "Função mbbtype"
  - "Função mbbtype_l"
ms.assetid: b8e34b40-842a-4298-aa39-0bd2d8e51c2a
caps.latest.revision: 18
caps.handback.revision: 18
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _mbbtype, _mbbtype_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Retorna o tipo de byte, com base no byte anterior.  
  
> [!IMPORTANT]
>  Essa API não pode ser usada em aplicativos executados no [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  Para obter mais informações, consulte [Funções de CRT sem suporte com \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
int _mbbtype(  
   unsigned char c,  
   int type   
);  
int _mbbtype_l(  
   unsigned char c,  
   int type,  
   _locale_t locale  
);  
```  
  
#### Parâmetros  
 `c`  
 O caractere para testar.  
  
 `type`  
 O tipo de byte para testar.  
  
 `locale`  
 A localidade a ser usada.  
  
## Valor de retorno  
 `_mbbtype` Retorna o tipo de bytes em uma cadeia de caracteres.  Essa decisão é contextual, conforme especificado pelo valor de `type`, que fornece a condição de teste do controle.  `type` é o tipo do byte anterior na cadeia de caracteres.  As constantes de manifesto na tabela a seguir são definidas em Mbctype.h.  
  
|Valor de `type`|`_mbbtype` testes para|Valor de retorno|`c`|  
|---------------------|----------------------------|----------------------|---------|  
|Qualquer valor exceto 1|De byte único ou byte inicial|`_MBC_SINGLE` \(0\)|Byte único \(0x20 – 0x7E, 0xA1 – 0xDF\)|  
|Qualquer valor exceto 1|De byte único ou byte inicial|`_MBC_LEAD` \(1\)|Byte do caractere multibyte inicial \(0x81 – 0x9F, 0xE0 – 0xFC\)|  
|Qualquer valor exceto 1|Bytes válidos de byte único ou de avanço|`_MBC_ILLEGAL`<br /><br /> \( –1\)|Caractere inválido \(qualquer valor exceto 0x20 – 0x7E, 0xA1 – 0xDF, 0x81 – 0x9F, 0xE0 – 0xFC|  
|1|Byte final válido|`_MBC_TRAIL` \(2\)|À direita de byte do caractere multibyte \(0x40 – 0x7E, 0x80 – 0xFC\)|  
|1|Byte final válido|`_MBC_ILLEGAL`<br /><br /> \( –1\)|Caractere inválido \(qualquer valor exceto 0x20 – 0x7E, 0xA1 – 0xDF, 0x81 – 0x9F, 0xE0 – 0xFC|  
  
## Comentários  
 O `_mbbtype` função determina o tipo de um byte em um caractere multibyte.  Se o valor de `type` é qualquer valor exceto 1, `_mbbtype` testes para um byte de byte único ou avanço válido de um caractere multibyte.  Se o valor de `type` é 1, `_mbbtype` testes para um byte final válido de um caractere multibyte.  
  
 O valor de saída é afetado pela definição da configuração de categoria `LC_CTYPE` da localidade. Consulte [setlocale, \_wsetlocale](../Topic/setlocale,%20_wsetlocale.md) para obter mais informações.  O `_mbbtype` versão dessa função usa a localidade atual para esse comportamento depende da localidade; o `_mbbtype_l` versão é idêntico, exceto que ele usa o parâmetro de localidade passado em seu lugar.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 Em versões anteriores, `_mbbtype` foi nomeada `chkctype`.  Para código novo, use `_mbbtype` em vez disso.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalho opcional|  
|------------|--------------------------|------------------------|  
|`_mbbtype`|\<mbstring.h\>|\< mbctype.h \> \*|  
|`_mbbtype_l`|\<mbstring.h\>|\< mbctype.h \> \*|  
  
 \* Para obter definições de constantes de manifesto que são usados como valores de retorno.  
  
 Para obter mais informações de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Equivalência do .NET Framework  
 Não aplicável, mas consulte [System::Globalization::CultureInfo](https://msdn.microsoft.com/en-us/library/system.globalization.cultureinfo.aspx).  
  
## Consulte também  
 [Classificação de byte](../../c-runtime-library/byte-classification.md)