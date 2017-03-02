---
title: Erro fatal C1004 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: b624a1faa886d420ef206c07d17a20a96fa9ee08
ms.lasthandoff: 02/25/2017

---
# <a name="fatal-error-c1004"></a>Erro fatal C1004
fim de arquivo inesperado encontrado  
  
 O compilador atingiu o final de um arquivo de origem sem resolver uma construção. O código pode estar faltando um dos seguintes elementos:  
  
-   Uma chave de fechamento  
  
-   Um parêntese de fechamento  
  
-   Marcador de comentário de fechamento (* /)  
  
-   Um ponto e vírgula  
  
 Para resolver esse erro, verifique o seguinte:  
  
-   A unidade de disco padrão não possui espaço suficiente para arquivos temporários que requerem praticamente duas vezes mais espaço do arquivo de origem.  
  
-   Um `#if` diretiva que seja avaliada como false carece de fechamento `#endif` diretiva.  
  
-   Um arquivo de origem não termina com um retorno de carro e alimentação de linha.  
  
 O exemplo a seguir gera C1004:  
  
```  
// C1004.cpp  
#if TEST  
int main() {}  
// C1004  
```  
  
 Resolução possível:  
  
```  
// C1004b.cpp  
#if TEST  
#endif  
  
int main() {}  
```
