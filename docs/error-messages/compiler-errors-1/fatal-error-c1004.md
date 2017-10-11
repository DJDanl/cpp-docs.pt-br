---
title: Erro fatal C1004 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C1004
dev_langs:
- C++
helpviewer_keywords:
- C1004
ms.assetid: dbe034b0-6eb0-41b4-a50c-2fccf9e78ad4
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: c6a9e74d7918e1cb2c9190c87f4f1ec75f89237b
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="fatal-error-c1004"></a>Erro fatal C1004
fim de arquivo inesperado encontrado  
  
 O compilador atingiu o final de um arquivo de origem sem resolver uma construção. O código pode estar faltando um dos seguintes elementos:  
  
-   Uma chave de fechamento  
  
-   Um parêntese de fechamento  
  
-   Marcador de comentário de um fechamento (* /)  
  
-   Um ponto e vírgula  
  
 Para resolver esse erro, verifique o seguinte:  
  
-   A unidade de disco padrão tem espaço suficiente para arquivos temporários, o que requer sobre duas vezes mais espaço do arquivo de origem.  
  
-   Um `#if` diretiva que é avaliada como false falta um fechamento `#endif` diretiva.  
  
-   Um arquivo de origem não termina com um retorno de carro e alimentação de linha.  
  
 O exemplo a seguir gera C1004:  
  
```  
// C1004.cpp  
#if TEST  
int main() {}  
// C1004  
```  
  
 Possível solução:  
  
```  
// C1004b.cpp  
#if TEST  
#endif  
  
int main() {}  
```
