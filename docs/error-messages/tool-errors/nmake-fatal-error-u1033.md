---
title: NMAKE Erro Fatal U1033 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- U1033
dev_langs:
- C++
helpviewer_keywords:
- U1033
ms.assetid: c146f7b5-7d5c-4329-a522-28a648546016
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: e8cd0591a1b2fac4ac8837f53ac576eb1eae7ed7
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="nmake-fatal-error-u1033"></a>Erro fatal U1033 (NMAKE)
Erro de sintaxe: 'string' inesperado  
  
 A cadeia de caracteres não faz parte da sintaxe válida para um makefile.  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  Se definir o fechamento de colchetes angulares (**<<**) para um arquivo embutido não estão no início de uma linha, ocorrerá o seguinte erro:  
  
    ```  
    syntax error : 'EOF' unexpected  
    ```  
  
2.  Se uma definição de macro no makefile continha um sinal de igual (**=**) sem um nome ou se o nome que está sendo definida é uma macro que se expande para nada, ocorrerá o seguinte erro:  
  
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
