---
title: "_ismbcl0, _ismbcl0_l, _ismbcl1, _ismbcl1_l, _ismbcl2, _ismbcl2_l | Microsoft Docs"
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
  - "_ismbcl2"
  - "_ismbcl1"
  - "_ismbcl0"
  - "_ismbcl2_l"
  - "_ismbcl1_l"
  - "_ismbcl0_l"
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
  - "ismbcl0"
  - "_ismbcl1_l"
  - "_ismbcl0"
  - "ismbcl1"
  - "ismbcl0_l"
  - "_ismbcl2_l"
  - "ismbcl2"
  - "ismbcl1_l"
  - "_ismbcl1"
  - "_ismbcl0_l"
  - "_ismbcl2"
  - "ismbcl2_l"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _ismbcl0"
  - "Função _ismbcl0_l"
  - "Função _ismbcl1"
  - "Função _ismbcl1_l"
  - "Função _ismbcl2"
  - "Função _ismbcl2_l"
  - "Função ismbcl0"
  - "Função ismbcl0_l"
  - "Função ismbcl1"
  - "Função ismbcl1_l"
  - "Função ismbcl2"
  - "Função ismbcl2_l"
ms.assetid: ee15ebd1-462c-4a43-95f3-6735836d626a
caps.latest.revision: 20
caps.handback.revision: 20
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _ismbcl0, _ismbcl0_l, _ismbcl1, _ismbcl1_l, _ismbcl2, _ismbcl2_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

**Função da página de código 932 específico**, usando a localidade atual ou uma categoria especificada de estado de conversão de LC\_CTYPE.  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos que executam no Tempo de Execução do Windows.  Para obter mais informações, consulte [Funções CRT sem suporte pelo \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
int _ismbcl0(  
   unsigned int c   
);  
int _ismbcl0_l(  
   unsigned int c,  
   _locale_t locale  
);  
int _ismbcl1(  
   unsigned int c   
);  
int _ismbcl1_l(  
   unsigned int c ,  
   _locale_t locale  
);  
int _ismbcl2(  
   unsigned int c   
);  
int _ismbcl2_l(  
   unsigned int c,  
   _locale_t locale  
);  
```  
  
#### Parâmetros  
 `c`  
 Caractere a ser testado.  
  
 `locale`  
 Localidade a ser usada.  
  
## Valor de retorno  
 Cada uma dessas rotinas retornará um valor diferente de zero se o caractere atender à condição de teste, caso contrário, retornará 0.  Se `c` \<\= 255 e houver uma rotina de `_ismbb` correspondente \(por exemplo, `_ismbcalnum` corresponde a `_ismbbalnum`\), o resultado será o valor de retorno da rotina `_ismbb` correspondente.  
  
## Comentários  
 Cada uma dessas funções testa um determinado caractere multibyte para uma condição específica.  
  
 O valor de saída é afetado pela configuração da categoria `LC_CTYPE` de localidade. Para obter mais informações, consulte [setlocale](../Topic/setlocale,%20_wsetlocale.md).  As versões dessas funções sem o sufixo `_l` usam a localidade atual para esse comportamento dependente da localidade; as versões com o sufixo `_l` são idênticas, exceto que elas usam o parâmetro de localidade informado.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
|Rotina|Condição de teste \(somente a página de código 932\)|  
|------------|----------------------------------------------------------|  
|`_ismbcl0`|JIS não Kanji: 0x8140\<\=`c`\<\=0x889E.|  
|`_ismbcl0_l`|JIS não Kanji: 0x8140\<\=`c`\<\=0x889E.|  
|`_ismbcl1`|JIS level\-1: 0x889F\<\=`c`\<\=0x9872.|  
|`_ismbcl1_l`|JIS level\-1: 0x889F\<\=`c`\<\=0x9872.|  
|`_ismbcl2`|JIS level\-2: 0x989F\<\=`c`\<\=0xEAA4.|  
|`_ismbcl2_l`|JIS level\-2: 0x989F\<\=`c`\<\=0xEAA4.|  
  
 As funções verificam se o valor especificado `c` corresponde às condições de teste descritas acima, mas não verificam se `c` é um caractere multibyte válido.  Se o byte menor estiver nos intervalos 0x00 – 0x3F, 0x7F, ou 0xFD – 0xFF, essas funções retornarão um valor diferente de zero, indicando que o caractere satisfaz a condição de teste.  Use [\_ismbbtrail](../../c-runtime-library/reference/ismbbtrail-ismbbtrail-l.md) para testar se o caractere multibyte está definido.  
  
 **Encerrar página de código 932 específica**  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_ismbcl0`|\<mbstring.h\>|  
|`_ismbcl0_l`|\<mbstring.h\>|  
|`_ismbcl1`|\<mbstring.h\>|  
|`_ismbcl1_l`|\<mbstring.h\>|  
|`_ismbcl2`|\<mbstring.h\>|  
|`_ismbcl2_l`|\<mbstring.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Classificação de caractere](../../c-runtime-library/character-classification.md)   
 [Rotinas \_ismbc](../../c-runtime-library/ismbc-routines.md)   
 [Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)