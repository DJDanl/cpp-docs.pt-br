---
title: "isleadbyte, _isleadbyte_l | Microsoft Docs"
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
  - "_isleadbyte_l"
  - "isleadbyte"
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
  - "api-ms-win-crt-string-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_istleadbyte"
  - "_isleadbyte_l"
  - "isleadbyte"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "bytes iniciais"
  - "Função _isleadbyte_l"
  - "Função _istleadbyte"
  - "Função istleadbyte"
  - "Função isleadbyte"
ms.assetid: 3b2bcf09-d82b-4803-9e80-59d04942802a
caps.latest.revision: 20
caps.handback.revision: 20
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# isleadbyte, _isleadbyte_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Determina se um caractere é o byte de um caractere multibyte.  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos executados no tempo de execução do Windows. Para obter mais informações, consulte [funções de CRT não têm suportadas com \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
int isleadbyte(  
   int c   
);  
int _isleadbyte_l(  
   int c   
);  
```  
  
#### Parâmetros  
 `c`  
 Inteiro para testar.  
  
## Valor de retorno  
 `isleadbyte` Retorna um valor diferente de zero se o argumento satisfaz a condição de teste ou 0 se não existir. Na localidade "C" e em um byte do conjunto de caracteres localidades \(SBCS\), `isleadbyte` sempre retorna 0.  
  
## Comentários  
 O `isleadbyte` macro retorna um valor diferente de zero se o argumento é o primeiro byte de um caractere multibyte.`isleadbyte` produz um resultado significativo de qualquer argumento inteiro de – 1 \(`EOF`\) para `UCHAR_MAX` \(0xFF\), inclusive.  
  
 O tipo de argumento esperado `isleadbyte` é `int`; se um caractere de sinal for passado, o compilador poderá convertê\-la em um inteiro por extensão de sinal, gerando resultados imprevisíveis.  
  
 A versão dessa função com o `_l` sufixo é idêntico, exceto que ele usa a localidade passada em vez da localidade atual para o seu comportamento depende da localidade.  
  
### Mapeamentos de rotina de texto genérico  
  
|TCHAR. Rotina H|Unicode e MBCS não definidos|MBCS definido|Unicode definido|  
|---------------------|----------------------------------|-------------------|----------------------|  
|`_istleadbyte`|Sempre retorna false|**\_** `isleadbyte`|Sempre retorna false|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`isleadbyte`|\< CType \>|  
|`_isleadbyte_l`|\< CType \>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Equivalência do .NET Framework  
 Não aplicável, mas consulte [System::Globalization::CultureInfo](https://msdn.microsoft.com/en-us/library/system.globalization.cultureinfo.aspx).  
  
## Consulte também  
 [Classificação de byte](../../c-runtime-library/byte-classification.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Rotinas \_ismbb](../../c-runtime-library/ismbb-routines.md)