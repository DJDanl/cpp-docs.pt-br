---
title: "_mbcjistojms, _mbcjistojms_l, _mbcjmstojis, _mbcjmstojis_l | Microsoft Docs"
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
  - "_mbcjistojms"
  - "_mbcjmstojis"
  - "_mbcjistojms_l"
  - "_mbcjmstojis_l"
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
  - "mbcjistojms"
  - "_mbcjistojms"
  - "_mbcjistojms_l"
  - "_mbcjmstojis_l"
  - "_mbcjmstojis"
  - "mbcjmstojis_l"
  - "mbcjistojms_l"
  - "mbcjmstojis"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _mbcjistojms"
  - "Função _mbcjistojms_l"
  - "Função _mbcjmstojis"
  - "Função _mbcjmstojis_l"
  - "Função mbcjistojms"
  - "Função mbcjistojms_l"
  - "Função mbcjmstojis"
  - "Função mbcjmstojis_l"
ms.assetid: dece5127-b337-40a4-aa10-53320a2c9432
caps.latest.revision: 20
caps.handback.revision: 20
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _mbcjistojms, _mbcjistojms_l, _mbcjmstojis, _mbcjmstojis_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Converte entre caracteres de padrão da indústria \(JIS\) do Japão e caracteres da Microsoft do Japão \(JMS\).  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos que executam no Tempo de Execução do Windows.  Para obter mais informações, consulte [Funções CRT sem suporte pelo \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
unsigned int _mbcjistojms(  
   unsigned int c   
);  
unsigned int _mbcjistojms_l(  
   unsigned int c,  
   _locale_t locale  
);  
unsigned int _mbcjmstojis(  
   unsigned int c   
);  
unsigned int _mbcjmstojis_l(  
   unsigned int c,  
   _locale_t locale  
);  
```  
  
#### Parâmetros  
 `c`  
 Caractere a ser convertido.  
  
 `local`  
 Localidade a ser usada.  
  
## Valor de retorno  
 Na localidade japonesa, essas funções retornam um caractere convertido ou retornam 0 se não for possível fazer nenhuma conversão.  Em uma localidade não japonesa, essas funções retornam os caracteres transmitidos.  
  
## Comentários  
 A função `_mbcjistojms` converte um caractere JIS \(padrão da indústria do Japão\) em um caractere SHIFT JIS \(Microsoft Kanji\).  O caractere é convertido somente se os byte iniciais e finais estiverem no intervalo 0x21 – 0x7E.  Se o byte de ligação ou de experimentação estiver fora desse intervalo, `errno` é definido como `EILSEQ`.  Para obter mais informações sobre esse e outros códigos de erro, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
 A função `_mbcjmstojis`converte um caractere Shift JIS em um caractere JIS.  O caractere é convertido somente se o byte inicial estiver no intervalo 0x81 – 0x9F ou 0xE0 – 0xFC e o byte final estiver no intervalo 0x40 – 0x7E ou 0x80 – 0xFC.  Observe que alguns pontos de código no intervalo não têm um caractere atribuído e, portanto, não podem ser convertidos.  
  
 O valor `c` deve ser um valor de 16 bits, cujos 8 bits superiores representam o byte inicial do caractere a ser convertido e cujos 8 bits inferiores representam o byte final.  
  
 O valor de saída é afetado pela configuração da categoria `LC_CTYPE` de localidade. Para obter mais informações, consulte [setlocale](../Topic/setlocale,%20_wsetlocale.md).  As versões dessas funções sem o sufixo `_l` usam a localidade atual para esse comportamento dependente da localidade; as versões com o sufixo `_l` são idênticas, exceto que elas usam o parâmetro de localidade informado.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 Em versões anteriores, `_mbcjistojms` e `_mbcjmstojis` eram chamados`jistojms` e `jmstojis`, respectivamente.  `_mbcjistojms`,`_mbcjistojms_l`,`_mbcjmstojis` e `_mbcjmstojis_l` devem ser usados no lugar.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_mbcjistojms`|\<mbstring.h\>|  
|`_mbcjistojms_l`|\<mbstring.h\>|  
|`_mbcjmstojis`|\<mbstring.h\>|  
|`_mbcjmstojis_l`|\<mbstring.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Conversão de dados](../../c-runtime-library/data-conversion.md)   
 [Rotinas \_ismbb](../../c-runtime-library/ismbb-routines.md)