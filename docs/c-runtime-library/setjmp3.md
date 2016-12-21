---
title: "_setjmp3 | Microsoft Docs"
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
  - "_setjmp3"
apilocation: 
  - "msvcrt.dll"
  - "msvcr90.dll"
  - "msvcr110.dll"
  - "msvcr80.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr100.dll"
  - "msvcr120.dll"
apitype: "DLLExport"
f1_keywords: 
  - "setjmp3"
  - "_setjmp3"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função _setjmp3"
  - "Função setjmp3"
ms.assetid: 6129c2f3-8bac-4fdb-a827-44e1eebba500
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _setjmp3
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Função CRT interna.  Uma nova implementação da função `setjmp`.  
  
## Sintaxe  
  
```  
int _setjmp3(    OUT jmp_buf env,    int count,    (optional parameters) );  
```  
  
#### Parâmetros  
 \[out\] `env`  
 Endereço do buffer para armazenar informações de estado.  
  
 \[in\] `count`  
 O número de informações `DWORD` adicionais armazenadas no `optional parameters`.  
  
 \[in\] `optional parameters`  
 Dados adicionais enviados pelo `setjmp` intrínseco.  O primeiro `DWORD` é um ponteiro de função usado para desenrolar dados extras e retornar para um estado de registro não volátil.  O segundo `DWORD` é o nível de tentativa a ser restaurado.  Todos os demais dados são salvos na matriz de dados genérica no `jmp_buf`.  
  
## Valor de retorno  
 Sempre retorna 0.  
  
## Comentários  
 Não use essa função em um programa C\+\+.  É uma função intrínseca que não tem suporte para C\+\+.  Para obter mais informações sobre como usar o `setjmp`, consulte [Usando setjmp\/longjmp](../cpp/using-setjmp-longjmp.md).  
  
## Requisitos  
  
## Consulte também  
 [Referência da função alfabética](../c-runtime-library/reference/crt-alphabetical-function-reference.md)   
 [setjmp](../c-runtime-library/reference/setjmp.md)