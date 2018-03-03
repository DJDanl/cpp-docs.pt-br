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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 528147eceadd35cc0d9fe656bdc7ce7965339a0a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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