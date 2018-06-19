---
title: Erro fatal C1004 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1004
dev_langs:
- C++
helpviewer_keywords:
- C1004
ms.assetid: dbe034b0-6eb0-41b4-a50c-2fccf9e78ad4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d88f76c00c8f5b36acf238f0da88e908eac6dbe8
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33197163"
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