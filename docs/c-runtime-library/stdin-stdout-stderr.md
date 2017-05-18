---
title: stdin, stdout, stderr | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- stdin
- stderr
- stdout
dev_langs:
- C++
helpviewer_keywords:
- stdout function
- standard output stream
- standard error stream
- stdin function
- standard input stream
- stderr function
ms.assetid: badd4735-596d-4498-857c-ec8b7e670e4c
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 1b55f23213e15c65729e2bc8386e1ca4ea819673
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="stdin-stdout-stderr"></a>stdin, stdout, stderr
## <a name="syntax"></a>Sintaxe  
  
```  
  
      FILE *stdin;   
FILE *stdout;   
FILE *stderr;   
#include <stdio.h>  
```  
  
## <a name="remarks"></a>Comentários  
 Esses são fluxos padrão para entrada, saída e saída de erro.  
  
 Por padrão, a entrada padrão é lida do teclado, enquanto a saída padrão e erro padrão são impressos na tela.  
  
 Os ponteiros de fluxo a seguir estão disponíveis para acessar fluxos padrão:  
  
|Ponteiro|Fluxo|  
|-------------|------------|  
|`stdin`|Entrada padrão|  
|**stdout**|Saída padrão|  
|`stderr`|Erro padrão|  
  
 Esses ponteiros podem ser usados como argumentos para funções. Algumas funções, como **getchar** e `putchar`, usam `stdin` e **stdout** automaticamente.  
  
 Esses ponteiros são constantes e não podem receber novos valores. A função `freopen` pode ser usada para redirecionar os fluxos de arquivos de disco ou em outros dispositivos. O sistema operacional permite redirecionar a entrada e saída no nível de comando de um programa.  
  
## <a name="see-also"></a>Consulte também  
 [E/S de fluxo](../c-runtime-library/stream-i-o.md)   
 [Constantes globais](../c-runtime-library/global-constants.md)
