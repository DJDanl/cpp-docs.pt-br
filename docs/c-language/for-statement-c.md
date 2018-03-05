---
title: "Instrução for (C) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- for keyword [C]
ms.assetid: 560a8de4-19db-4868-9f18-dbe51b17900d
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 18c2b89e8c09ca7ddb6ba7f2cc02c9b400265a35
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="for-statement-c"></a>Instrução for (C)
A instrução **for** permite repetir uma instrução ou uma instrução composta por um número especificado de vezes. O corpo de uma instrução **for** é executado zero ou mais vezes até que uma condição opcional se torne falsa. Você pode usar expressões opcionais na instrução **for** para inicializar e alterar valores durante a execução da instrução **for**.  
  
## <a name="syntax"></a>Sintaxe  
 *iteration-statement*:  
 &nbsp;&nbsp;**for** **(** *init-expression*<sub>opt</sub> **;** *cond-expression*<sub>opt</sub> **;** *loop-expression*<sub>opt</sub> **)** *statement*  
  
 A execução de uma instrução **for** ocorre da seguinte maneira:  
  
1.  A *init-expression*, se houver, é avaliada. Isso especifica a inicialização do loop. Não há nenhuma restrição quanto ao tipo da *init-expression*.  
  
2.  A *cond-expression*, se houver, é avaliada. Essa expressão deve ter tipo aritmético ou ponteiro. Ela é avaliada antes de cada iteração. Três resultados são possíveis:  
  
    -   Se *cond-expression* é **true** (diferente de zero), *statement* é executada; em seguida, *loop-expression*, se houver, é avaliada. A *loop-expression* é avaliada após cada iteração. Não há nenhuma restrição quanto ao tipo dele. Os efeitos colaterais serão executados na ordem. Em seguida, o processo é iniciado novamente com a avaliação de *cond-expression*.  
  
    -   Se *cond-expression* está omitida, *cond-expression* é considerada true e a execução continua exatamente conforme descrita no parágrafo anterior. Uma instrução **for** sem um argumento *cond-expression* só termina quando uma instrução **break** ou **return** dentro do corpo da instrução é executada ou quando um **goto** (para uma instrução rotulada fora do corpo da instrução **for**) é executado.  
  
    -   Se a *cond-expression* for **false** (0), a execução da instrução **for** será finalizada e o controle será passado para a próxima instrução no programa.  
  
 A instrução **for** também pode terminar quando uma instrução **break**, **goto** ou **return** for executada no corpo da instrução. A instrução **continue** em um loop **for** possibilita que a *loop-expression* seja avaliada. Quando uma instrução **break** é executada em um loop **for**, *loop-expression* não é avaliado nem executado. Esta instrução  
  
```  
for( ;; )  
```  
  
 é a maneira habitual de gerar um loop infinito que só pode ser encerrado com uma instrução **break**, **goto** ou **return**.  
  
## <a name="code"></a>Código  
 Este exemplo ilustra a instrução **for**:  
  
```  
// c_for.c  
int main()  
{  
   char* line = "H e  \tl\tlo World\0";  
   int space = 0;  
   int tab = 0;  
   int i;  
   int max = strlen(line);  
   for (i = 0; i < max; i++ )   
   {  
      if ( line[i] == ' ' )  
      {  
          space++;  
      }  
      if ( line[i] == '\t' )  
      {  
          tab++;  
      }  
   }  
  
   printf("Number of spaces: %i\n", space);  
   printf("Number of tabs: %i\n", tab);  
   return 0;  
}  
```  
  
## <a name="output"></a>Saída  
  
```  
Number of spaces: 4  
Number of tabs: 2  
```  
  
## <a name="see-also"></a>Consulte também  
 [Instruções](../c-language/statements-c.md)