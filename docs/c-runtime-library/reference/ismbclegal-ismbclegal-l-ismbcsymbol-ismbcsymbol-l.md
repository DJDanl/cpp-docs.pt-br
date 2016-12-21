---
title: "_ismbclegal, _ismbclegal_l, _ismbcsymbol, _ismbcsymbol_l | Microsoft Docs"
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
  - "_ismbclegal_l"
  - "_ismbclegal"
  - "_ismbcsymbol"
  - "_ismbcsymbol_l"
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
  - "ismbcsymbol_l"
  - "_ismbcsymbol_l"
  - "_ismbcsymbol"
  - "_ismbclegal_l"
  - "_ismbclegal"
  - "ismbclegal_l"
  - "ismbcsymbol"
  - "ismbclegal"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _ismbclegal"
  - "Função _ismbclegal_l"
  - "Função _ismbcsymbol"
  - "Função _ismbcsymbol_l"
  - "Função _istlegal"
  - "Função _istlegal_l"
  - "Função ismbclegal"
  - "Função ismbclegal_l"
  - "Função ismbcsymbol"
  - "Função ismbcsymbol_l"
  - "Função istlegal"
  - "Função istlegal_l"
ms.assetid: 31bf1ea5-b56f-4e28-b21e-b49a2cf93ffc
caps.latest.revision: 18
caps.handback.revision: 18
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _ismbclegal, _ismbclegal_l, _ismbcsymbol, _ismbcsymbol_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Verifica se um caractere multibyte especificado é um caractere de símbolo ou legal.  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos que executam no Tempo de Execução do Windows.  Para obter mais informações, consulte [Funções CRT sem suporte pelo \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
int _ismbclegal(  
   unsigned int c   
);  
int _ismbclegal_l(  
   unsigned int c,   
   _locale_t locale  
);  
int _ismbcsymbol(  
   unsigned int c   
);  
int _ismbcsymbol_l(  
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
 Cada uma dessas rotinas retornará um valor diferente de zero se o caractere atender à condição de teste, caso contrário, retornará 0.  Se `c`\<\= 255 e houver uma rotina de `_ismbb` correspondente \(por exemplo, `_ismbcalnum` corresponde a `_ismbbalnum`\), o resultado será o valor de retorno da rotina correspondente de `_ismbb`.  
  
## Comentários  
 Cada uma dessas funções testa um determinado caractere multibyte para uma condição específica.  
  
 As versões dessas funções com o sufixo `_l` são idênticas, exceto que elas usam a localidade informada em vez da localidade atual de seu comportamento dependente da localidade.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
|Rotina|Condição de teste|Exemplo 932 de página de código|  
|------------|-----------------------|-------------------------------------|  
|`_ismbclegal`|Multibyte válido|Retorna um valor diferente de zero se, e somente se, o primeiro byte de `c` estiver dentro dos intervalos 0x81 – 0x9F ou 0xE0 – 0xFC e o segundo byte estiver dentro dos intervalos 0x40 \- 0x7E ou 0x80 \- FC.|  
|`_ismbcsymbol`|Símbolo de multibyte|Retorna um valor diferente de zero se, e somente se, 0x8141\=\<`c`\<\=0x81AC.|  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_istlegal`|Sempre retorna falso|`_ismbclegal`|Sempre retorna Falso.|  
|`_istlegal_l`|Sempre retorna falso|`_ismbclegal_l`|Sempre retorna Falso.|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_ismbclegal,_ismbclegal_l`|\<mbstring.h\>|  
|`_ismbcsymbol,_ismbcsymbol_l`|\<mbstring.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Classificação de caractere](../../c-runtime-library/character-classification.md)   
 [Rotinas \_ismbc](../../c-runtime-library/ismbc-routines.md)   
 [Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)   
 [Rotinas \_ismbb](../../c-runtime-library/ismbb-routines.md)