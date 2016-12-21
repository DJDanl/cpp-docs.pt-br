---
title: "_pgmptr, _wpgmptr | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "pgmptr"
  - "_pgmptr"
  - "wpgmptr"
  - "_wpgmptr"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _pgmptr"
  - "Função _wpgmptr"
  - "Função pgmptr"
  - "Função wpgmptr"
ms.assetid: 4d44b515-0eff-4136-8bc4-684195f218f5
caps.latest.revision: 14
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _pgmptr, _wpgmptr
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O caminho do arquivo executável.  Substituído; use [\_get\_pgmptr](../c-runtime-library/reference/get-pgmptr.md) e [\_get\_wpgmptr](../c-runtime-library/reference/get-wpgmptr.md).  
  
## Sintaxe  
  
```  
extern char *_pgmptr;  
extern wchar_t *_wpgmptr;  
```  
  
## Comentários  
 Quando um programa for executado do interpretador de comandos \(Cmd.exe\), `_pgmptr` é iniciado automaticamente caminho para o máximo do arquivo executável.  Por exemplo, se Hello.exe está em C:\\BIN e C:\\BIN está no caminho, `_pgmptr` está definido como C:\\BIN\\Hello.exe quando você executa:  
  
```  
C> hello   
```  
  
 Quando um programa não é executado na linha de comando, `_pgmptr` pode ser inicializado ao nome do programa \(o nome de arquivo sem a extensão de nome de arquivo\) ou um nome de arquivo, para um caminho relativo, ou a um caminho completo.  
  
 `_wpgmptr` é a contraparte de ampla caractere de `_pgmptr` para uso com programas que usam `wmain`.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_tpgmptr`|`_pgmptr`|`_pgmptr`|`_wpgmptr`|  
  
## Requisitos  
  
|Variável|Cabeçalho necessário|  
|--------------|--------------------------|  
|`_pgmptr`, `_wpgmptr`|\<stdlib.h\>|  
  
## Exemplo  
 O programa seguir demonstra o uso de `_pgmptr`.  
  
```  
// crt_pgmptr.c  
// compile with: /W3  
// The following program demonstrates the use of _pgmptr.  
//  
#include <stdio.h>  
#include <stdlib.h>  
int main( void )  
{  
   printf("The full path of the executing program is : %Fs\n",   
     _pgmptr); // C4996  
   // Note: _pgmptr is deprecated; use _get_pgmptr instead  
}  
```  
  
 Você pode usar `_wpgmptr` alterando `%Fs` a `%S` e `main` a `wmain`.  
  
## Consulte também  
 [Variáveis globais](../c-runtime-library/global-variables.md)