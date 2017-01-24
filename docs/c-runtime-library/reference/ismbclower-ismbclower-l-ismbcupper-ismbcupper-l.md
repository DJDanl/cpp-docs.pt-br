---
title: "_ismbclower, _ismbclower_l, _ismbcupper, _ismbcupper_l | Microsoft Docs"
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
  - "_ismbclower"
  - "_ismbclower_l"
  - "_ismbcupper_l"
  - "_ismbcupper"
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
  - "_ismbcupper"
  - "_ismbclower"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _ismbclower"
  - "Função _ismbclower_l"
  - "Função _ismbcupper"
  - "Função _ismbcupper_l"
  - "Função ismbclower"
  - "Função ismbclower_l"
  - "Função ismbcupper"
  - "Função ismbcupper_l"
ms.assetid: 17d89587-65bc-477c-ba8f-a84e63cf59e7
caps.latest.revision: 19
caps.handback.revision: 19
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _ismbclower, _ismbclower_l, _ismbcupper, _ismbcupper_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Verifica se um caractere multibyte é em letras minúsculas ou maiúsculas.  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos que executam no Tempo de Execução do Windows.  Para obter mais informações, consulte [Funções CRT sem suporte pelo \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
int _ismbclower(  
   unsigned int c   
);  
int _ismbclower_l(  
   unsigned int c,  
   _locale_t locale   
);  
int _ismbcupper(  
   unsigned int c   
);  
int _ismbcupper_l(  
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
|`_ismbclower`|Minúsculas alfabéticas|Retorna um valor diferente de zero se, e somente se, `c` for uma representação de byte único de uma letra ASCII minúscula em inglês: 0x61\<\=`c`\<\=0x7A.|  
|`_ismbclower_l`|Minúsculas alfabéticas|Retorna um valor diferente de zero se, e somente se, `c` for uma representação de byte único de uma letra ASCII minúscula em inglês: 0x61\<\=`c`\<\=0x7A.|  
|`_ismbcupper`|Minúsculas alfabéticas|Retorna um valor diferente de zero se, e somente se, `c` for uma representação de byte único de uma letra ASCII maiúscula em inglês: 0x41\<\=`c`\<\=0x5A.|  
|`_ismbcupper_l`|Minúsculas alfabéticas|Retorna um valor diferente de zero se, e somente se, `c` for uma representação de byte único de uma letra ASCII maiúscula em inglês: 0x41\<\=`c`\<\=0x5A.|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_ismbclower`|\<mbstring.h\>|  
|`_ismbclower_l`|\<mbstring.h\>|  
|`_ismbcupper`|\<mbstring.h\>|  
|`_ismbcupper_l`|\<mbstring.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Equivalência do .NET Framework  
  
-   [System::Char::IsLower](https://msdn.microsoft.com/en-us/library/system.char.islower.aspx)  
  
-   [System::Char::IsUpper](https://msdn.microsoft.com/en-us/library/system.char.isupper.aspx)  
  
## Consulte também  
 [Classificação de caractere](../../c-runtime-library/character-classification.md)   
 [Rotinas \_ismbc](../../c-runtime-library/ismbc-routines.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)   
 [Rotinas \_ismbb](../../c-runtime-library/ismbb-routines.md)