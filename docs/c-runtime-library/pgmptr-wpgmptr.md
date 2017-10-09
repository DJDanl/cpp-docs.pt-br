---
title: _pgmptr, _wpgmptr | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- pgmptr
- _pgmptr
- wpgmptr
- _wpgmptr
dev_langs:
- C++
helpviewer_keywords:
- wpgmptr function
- _wpgmptr function
- _pgmptr function
- pgmptr function
ms.assetid: 4d44b515-0eff-4136-8bc4-684195f218f5
caps.latest.revision: 14
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 16d1bf59dfd4b3ef5f037aed9c0f6febfdf1a2e8
ms.openlocfilehash: 21d3ad8d4cbd73c2a1ab99497db2f671196de523
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="pgmptr-wpgmptr"></a>_pgmptr, _wpgmptr
O caminho do arquivo executável. Preterido; use [_get_pgmptr](../c-runtime-library/reference/get-pgmptr.md) e [_get_wpgmptr](../c-runtime-library/reference/get-wpgmptr.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
extern char *_pgmptr;  
extern wchar_t *_wpgmptr;  
```  
  
## <a name="remarks"></a>Comentários  
 Quando um programa é executado do interpretador de comandos (Cmd.exe), o `_pgmptr` é inicializado automaticamente para o caminho completo do arquivo executável. Por exemplo, quando Hello.exe está em C:\BIN e C:\BIN está no caminho, o `_pgmptr` é definido como C:\BIN\Hello.exe durante a execução:  
  
```  
C> hello   
```  
  
 Quando um programa não é executado da linha de comando, o `_pgmptr` pode ser inicializado para o nome do programa (nome base do arquivo sem a extensão de nome de arquivo) ou para um nome de arquivo, caminho relativo ou caminho completo.  
  
 `_wpgmptr` é a contraparte de caractere largo de `_pgmptr` para uso com programas que utilizam `wmain`.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|--------------------------------------|--------------------|-----------------------|  
|`_tpgmptr`|`_pgmptr`|`_pgmptr`|`_wpgmptr`|  
  
## <a name="requirements"></a>Requisitos  
  
|Variável|Cabeçalho necessário|  
|--------------|---------------------|  
|`_pgmptr`, `_wpgmptr`|\<stdlib.h>|  
  
## <a name="example"></a>Exemplo  
 O programa a seguir demonstra o uso de `_pgmptr`.  
  
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
  
 É possível usar `_wpgmptr` alterando `%Fs` para `%S` e `main` para `wmain`.  
  
## <a name="see-also"></a>Consulte também  
 [Variáveis globais](../c-runtime-library/global-variables.md)
