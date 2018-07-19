---
title: 'Gerenciamento de memória: Alocação de quadro | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- memory leaks [MFC], frame allocation
- memory [MFC], detecting leaks
- memory [MFC], reclaiming
- memory allocation [MFC], frames
- frame variables [MFC], automatic deletion of
- scope [MFC], frame variables
- heap allocation [MFC], vs. frame allocation
- variables [MFC], frame variables
- memory leaks [MFC], detecting
- memory, releasing [MFC]
- stack frames [MFC]
- memory leaks [MFC], allocating objects on the frame
- detecting memory leaks [MFC]
- frame allocation [MFC]
- frame variables [MFC]
ms.assetid: 945a211a-6f4f-4679-bb6a-b0f2a0d4a6c1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 27cde859c20f4c9cddc1ceb3e2cae568afb6e960
ms.sourcegitcommit: 76fd30ff3e0352e2206460503b61f45897e60e4f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/13/2018
ms.locfileid: "39027213"
---
# <a name="memory-management-frame-allocation"></a>Gerenciamento de memória: alocação do quadro
Alocação de quadro recebe seu nome do "quadro de pilha" que é definido sempre que uma função é chamada. O quadro de pilha é uma área de memória que armazena temporariamente os argumentos para a função, bem como todas as variáveis que são definidas locais à função. Variáveis do quadro geralmente são chamadas de variáveis "automáticas" porque o compilador automaticamente aloca o espaço para eles.  
  
 Há duas características principais de alocações de quadro. Primeiro, quando você define uma variável local, suficiente espaço é alocado no quadro da pilha para manter a variável de inteira, mesmo se for uma matriz grande ou a estrutura de dados. Em segundo lugar, variáveis do quadro são excluídas automaticamente quando eles saem do escopo:  
  
 [!code-cpp[NVC_MFC_Utilities#10](../mfc/codesnippet/cpp/memory-management-frame-allocation_1.cpp)]  
  
 Para variáveis de função local, essa transição de escopo acontece quando a função sai, mas o escopo de uma variável de quadro pode ser menor do que uma função se chaves aninhadas são usadas. Essa exclusão automática de variáveis do quadro é muito importante. No caso de tipos primitivos simples (como **int** ou **bytes**), matrizes, ou estruturas de dados, a exclusão automática simplesmente recupera a memória usada pela variável. Uma vez que a variável tiver saído do escopo, ele não pode ser acessado de qualquer forma. No entanto, no caso de objetos de C++, o processo de exclusão automática é um pouco mais complicado.  
  
 Quando um objeto é definido como uma variável de quadro, seu construtor é invocado automaticamente no ponto em que a definição for encontrada. Quando o objeto sai do escopo, seu destruidor é invocado automaticamente antes que a memória para o objeto seja recuperada. Essa construção automática e a destruição podem ser muito útil, mas você deve estar ciente das chamadas automático, especialmente para o destruidor.  
  
 A principal vantagem de alocação de objetos no quadro é que eles são excluídos automaticamente. Quando você alocar seus objetos no quadro, você não precisa se preocupar sobre objetos esquecidos causar vazamentos de memória. (Para obter detalhes sobre vazamentos de memória, consulte o artigo [detectando vazamentos de memória no MFC](http://msdn.microsoft.com/29ee8909-96e9-4246-9332-d3a8aa8d4658).) Uma desvantagem de alocação do quadro é que as variáveis do quadro não podem ser usadas fora de seu escopo. Outro fator na escolha de alocação do quadro em comparação com a alocação de heap é que para estruturas grandes e objetos, geralmente é melhor usar o heap em vez da pilha para o armazenamento, pois o espaço de pilha é geralmente limitado.  
  
## <a name="see-also"></a>Consulte também  
 [Gerenciamento de memória](../mfc/memory-management.md)

