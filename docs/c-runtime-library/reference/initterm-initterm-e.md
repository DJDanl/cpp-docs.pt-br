---
title: "_initterm, _initterm_e | Microsoft Docs"
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
  - "_initterm_e"
  - "_initterm"
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
  - "_initterm_e"
  - "initterm"
  - "_initterm"
  - "initterm_e"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função initterm"
  - "Função initterm_e"
  - "Função _initterm"
  - "Função _initterm_e"
ms.assetid: 85131efe-c747-429a-8897-bcdedb000172
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _initterm, _initterm_e
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Métodos internos que mostram uma tabela de ponteiros da função e iniciar os.  
  
 O primeiro ponteiro é o local inicial na tabela e o segundo ponteiro é o local final.  
  
## Sintaxe  
  
```  
void __cdecl _initterm(  
   PVFV *,  
   PVFV *  
);  
  
int __cdecl _initterm_e(  
   PVFV *,  
   PVFV *  
);  
```  
  
## Valor de retorno  
 Um código de erro diferente de zero se uma inicialização falhar e lançará um erro; 0 se nenhum erro ocorrerá.  
  
## Comentários  
 Esses métodos são chamados somente internamente durante a inicialização do programa c. criando  Não chamar esses métodos em um programa.  
  
 Quando a exames desses métodos uma tabela de entradas de função, eles ignorar entradas de `NULL` e continuar.  
  
## Consulte também  
 [Referência da função alfabética](../../c-runtime-library/reference/crt-alphabetical-function-reference.md)