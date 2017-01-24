---
title: "_ismbcgraph, _ismbcgraph_l, _ismbcprint, _ismbcprint_l, _ismbcpunct, _ismbcpunct_l, _ismbcblank, _ismbcblank_l, _ismbcspace, _ismbcspace_l | Microsoft Docs"
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
  - "_ismbcpunct_l"
  - "_ismbcblank"
  - "_ismbcprint"
  - "_ismbcgraph_l"
  - "_ismbcblank_l"
  - "_ismbcpunct"
  - "_ismbcprint_l"
  - "_ismbcspace_l"
  - "_ismbcspace"
  - "_ismbcgraph"
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
  - "_ismbcspace"
  - "_ismbcgraph"
  - "_ismbcpunct"
  - "ismbcspace_l"
  - "ismbcgraph"
  - "_ismbcgraph_l"
  - "_ismbcprint"
  - "_ismbcspace_l"
  - "ismbcprint"
  - "ismbcgraph_l"
  - "ismbcspace"
  - "ismbcpunct"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função ismbcspace_l"
  - "Função _ismbcprint_l"
  - "Função ismbcspace"
  - "Função ismbcpunct"
  - "Função _ismbcspace_l"
  - "Função _ismbcprint"
  - "Função ismbcprint"
  - "Função _ismbcgraph"
  - "Função ismbcgraph_l"
  - "Função _ismbcpunct_l"
  - "Função ismbcpunct_l"
  - "Função ismbcprint_l"
  - "Função _ismbcpunct"
  - "Função ismbcgraph"
  - "Função _ismbcgraph_l"
  - "Função _ismbcspace"
ms.assetid: 8e0a5f47-ba64-4411-92a3-3c525d16e3be
caps.latest.revision: 21
caps.handback.revision: 21
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _ismbcgraph, _ismbcgraph_l, _ismbcprint, _ismbcprint_l, _ismbcpunct, _ismbcpunct_l, _ismbcblank, _ismbcblank_l, _ismbcspace, _ismbcspace_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Determina se o caractere é um caractere gráfico, um caractere de exibição, um caractere de pontuação ou um caractere de espaço.  
  
> [!IMPORTANT]
>  Essa API não pode ser usado em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)]. Para obter mais informações, consulte[funções de CRT não têm suportadas com \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
int _ismbcgraph(  
   unsigned int c   
);  
int _ismbcgraph_l(  
   unsigned int c,  
   _locale_t locale   
);  
int _ismbcprint(  
   unsigned int c   
);  
int _ismbcprint_l(  
   unsigned int c,  
   _locale_t locale  
);  
int _ismbcpunct(  
   unsigned int c  
);  
int _ismbcpunct_l(  
   unsigned int c,  
   _locale_t locale  
);  
int _ismbcblank(  
   unsigned int c   
);  
int _ismbcblank_l(  
   unsigned int c,  
   _locale_t locale  
);  
int _ismbcspace(  
   unsigned int c   
);  
int _ismbcspace_l(  
   unsigned int c,  
   _locale_t locale  
);  
```  
  
#### Parâmetros  
 `c`  
 Caractere a ser determinado.  
  
 `locale`  
 Localidade a ser usada.  
  
## Valor de retorno  
 Todas essas rotinas retorna um valor diferente de zero se o caractere satisfaz a condição de teste, ou 0 se não existir. Se `c` \< \= 255 e há um correspondente `_ismbb` rotina \(por exemplo, `_ismbcalnum` corresponde à `_ismbbalnum`\), o resultado é o valor de retorno de correspondente `_ismbb` rotina.  
  
 As versões dessas funções são idênticas, exceto que aquelas que têm o `_l` sufixo usam a localidade que é passada para o comportamento depende da localidade, em vez da localidade atual. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
## Comentários  
 Cada uma dessas funções testa um determinado caractere multibyte para uma determinada condição.  
  
|Rotina|Condição de teste|Exemplo de código de página 932|  
|------------|-----------------------|-------------------------------------|  
|`_ismbcgraph`|Elemento gráfico|Retorna zero se e somente se `c` é uma representação de um byte de qualquer caractere imprimível ASCII ou katakana exceto \(espaço em branco\).|  
|`_ismbcprint`|Para impressão|Retorna zero se e somente se `c` é uma representação de um byte de qualquer caractere imprimível ASCII ou katakana inclusive \(de\) um espaço em branco.|  
|`_ismbcpunct`|Pontuação|Retorna zero se e somente se `c` é uma representação de um byte de qualquer caractere de pontuação ASCII ou katakana.|  
|`_ismbcblank`|Espaço ou tabulação horizontal|Retorna zero se e somente se `c` é um espaço ou um caractere de tabulação horizontal: `c`\= 0x20 ou `c`\= 0x09.|  
|`_ismbcspace`|Espaço em branco|Retorna zero se e somente se `c` é um caractere de espaço em branco: `c`\= 0x20 ou 0x09 \< \=`c`\< \= 0x0D.|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_ismbcgraph`|\< mbstring.h \>|  
|`_ismbcgraph_l`|\< mbstring.h \>|  
|`_ismbcprint`|\< mbstring.h \>|  
|`_ismbcprint_l`|\< mbstring.h \>|  
|`_ismbcpunct`|\< mbstring.h \>|  
|`_ismbcpunct_l`|\< mbstring.h \>|  
|`_ismbcblank`|\< mbstring.h \>|  
|`_ismbcblank_l`|\< mbstring.h \>|  
|`_ismbcspace`|\< mbstring.h \>|  
|`_ismbcspace_l`|\< mbstring.h \>|  
  
 Para obter informações de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Libraries  
 Todas as versões do [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## Equivalência do .NET Framework  
  
-   [System::char::IsPunctuation](https://msdn.microsoft.com/en-us/library/system.char.ispunctuation.aspx)  
  
-   [System::char::IsWhiteSpace](https://msdn.microsoft.com/en-us/library/system.char.iswhitespace.aspx)  
  
-   Para `_ismbcgraph` e `_ismbcprint`: não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Classificação de caractere](../../c-runtime-library/character-classification.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [Rotinas \_ismbc](../../c-runtime-library/ismbc-routines.md)   
 [Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)   
 [Rotinas \_ismbb](../../c-runtime-library/ismbb-routines.md)