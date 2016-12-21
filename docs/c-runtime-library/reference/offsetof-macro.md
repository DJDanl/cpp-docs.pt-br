---
title: "Macro offsetof | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
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
apitype: "DLLExport"
f1_keywords: 
  - "offsetof"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Macro offsetof"
  - "membros de estrutura, deslocamento"
ms.assetid: f3b4eb16-a882-4d38-afc9-eebd976a7352
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Macro offsetof
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Recupera o deslocamento de um membro do início de sua estrutura pai.  
  
## Sintaxe  
  
```  
  
        size_t offsetof(  
   structName,  
   memberName   
);  
```  
  
#### Parâmetros  
 *structName*  
 Nome da estrutura de dados pai.  
  
 `memberName`  
 Nome do membro na estrutura de dados pai para o qual determinar o deslocamento.  
  
## Valor de retorno  
 `offsetof` Retorna o deslocamento em bytes do membro especificado do início de sua estrutura de dados pai.  É indefinido para os campos de bits.  
  
## Comentários  
 O `offsetof` macro retorna o deslocamento em bytes do `memberName` desde o início da estrutura especificado por *structName* como um valor do tipo `size_t`.  Você pode especificar tipos com o `struct` palavra\-chave.  
  
> [!NOTE]
>  `offsetof` não é uma função e não podem ser descritos utilizando um protótipo de C.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`offsetof`|\< stddef. h \>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Bibliotecas  
 Todas as versões de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## Consulte também  
 [Alocação de memória](../../c-runtime-library/memory-allocation.md)