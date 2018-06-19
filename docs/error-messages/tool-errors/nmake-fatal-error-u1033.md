---
title: NMAKE Erro Fatal U1033 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- U1033
dev_langs:
- C++
helpviewer_keywords:
- U1033
ms.assetid: c146f7b5-7d5c-4329-a522-28a648546016
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e1d39d4c35ec66d405d51d601b7c5d2b2ab37b02
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33319264"
---
# <a name="nmake-fatal-error-u1033"></a>Erro fatal U1033 (NMAKE)
Erro de sintaxe: 'string' inesperado  
  
 A cadeia de caracteres não é parte da sintaxe válida para um makefile.  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  Se definir o fechamento de colchetes angulares (**<<**) para um arquivo embutido não estão no início de uma linha, ocorrerá o seguinte erro:  
  
    ```  
    syntax error : 'EOF' unexpected  
    ```  
  
2.  Se uma definição de macro no makefile continha um sinal de igual (**=**) sem um anterior nome ou se o nome que está sendo definido é uma macro que se expande para nada, ocorre o seguinte erro:  
  
    ```  
    syntax error : '=' unexpected  
    ```  
  
3.  Se o ponto e vírgula (**;**) em uma linha de comentário em ferramentas. INI não está no início da linha, ocorrerá o seguinte erro:  
  
    ```  
    syntax error : ';' unexpected  
    ```  
  
4.  Se o makefile foi formatado por um processador de texto, pode ocorrer o seguinte erro:  
  
    ```  
    syntax error : ':' unexpected  
    ```