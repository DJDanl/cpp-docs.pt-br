---
title: "_set_controlfp | Microsoft Docs"
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
  - "_set_controlfp"
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
  - "api-ms-win-crt-runtime-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "set_controlfp"
  - "_set_controlfp"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _set_controlfp"
  - "funções de ponto flutuante, definindo a palavra de controle"
  - "Função set_controlfp"
ms.assetid: e0689d50-f68a-4028-a9c1-fb23eedee4ad
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _set_controlfp
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Define as palavras de controle de ponto flutuante.  
  
## Sintaxe  
  
```  
void __cdecl _set_controlfp(  
    unsigned int newControl,  
    unsigned int mask  
);  
```  
  
#### Parâmetros  
 `newControl`  
 Valores de bit da nova palavra de controle.  
  
 `mask`  
 Máscara para os bits da nova palavra de controle a ser definida.  
  
## Valor de retorno  
 Nenhum.  
  
## Comentários  
 `_set_controlfp` é semelhante a `_control87`, mas define apenas as palavras de controle de ponto flutuante a `newControl`.  Os bits nos valores indicam o estado do controle de ponto flutuante.  O estado do controle de ponto flutuante permite que o programa altere a precisão, o arredondamento, e os modos de infinito no pacote de matemática de ponto flutuante.  Você também pode mascarar ou desmascarar exceções de ponto flutuante usando `_set_controlfp`.  Para obter mais informações, consulte [\_control87, \_controlfp, \_\_control87\_2](../Topic/_control87,%20_controlfp,%20__control87_2.md).  
  
 Esta função é substituída durante a criação com [\/clr \(compilação do Common Language Runtime\)](../../build/reference/clr-common-language-runtime-compilation.md) ou `/clr:pure` como Common Language Runtime oferece suporte apenas a precisão de ponto flutuante padrão.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|Compatibilidade|  
|------------|--------------------------|---------------------|  
|`_set_controlfp`|\<float.h\>|processador x86 somente|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [\_clear87, \_clearfp](../../c-runtime-library/reference/clear87-clearfp.md)   
 [\_status87, \_statusfp, \_statusfp2](../../c-runtime-library/reference/status87-statusfp-statusfp2.md)