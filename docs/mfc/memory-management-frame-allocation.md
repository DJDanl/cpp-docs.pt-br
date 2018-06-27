---
title: 'Gerenciamento de memória: Alocação do quadro | Microsoft Docs'
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
ms.openlocfilehash: 264a3b5618b1c153219d5dee838af38bd7f49f49
ms.sourcegitcommit: 060f381fe0807107ec26c18b46d3fcb859d8d2e7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/25/2018
ms.locfileid: "36931054"
---
# <a name="memory-management-frame-allocation"></a>Gerenciamento de memória: alocação do quadro
Alocação de quadro leva seu nome de "quadro de pilha" que é definido sempre que uma função é chamada. O quadro de pilhas é uma área da memória que temporariamente armazena os argumentos para a função, bem como todas as variáveis que são definidas locais à função. Variáveis de quadro geralmente são chamadas de variáveis "automáticos" porque o compilador automaticamente aloca o espaço para eles.  
  
 Há dois principais características de alocações de quadro. Primeiro, quando você define uma variável local, espaço é alocado no quadro de pilha para manter a variável de inteira, mesmo se houver uma grande matriz ou estrutura de dados. Em segundo lugar, variáveis de quadro são excluídos automaticamente quando saem do escopo:  
  
 [!code-cpp[NVC_MFC_Utilities#10](../mfc/codesnippet/cpp/memory-management-frame-allocation_1.cpp)]  
  
 Para variáveis de função local, essa transição de escopo ocorre quando a função encerrará o escopo de uma variável de quadro pode ser menor do que uma função se forem usadas chaves aninhadas. Essa exclusão automática de variáveis de quadro é muito importante. No caso de tipos primitivos simples (como **int** ou **bytes**), matrizes, ou estruturas de dados, a exclusão automática simplesmente recupera a memória usada pela variável. Desde que a variável está fora do escopo, ele não pode ser acessado mesmo assim. No entanto, no caso de objetos C++, o processo de exclusão automática é um pouco mais complicado.  
  
 Quando um objeto é definido como uma variável de quadro, seu construtor é invocado automaticamente no ponto em que a definição é encontrada. Quando o objeto sai do escopo, seu destruidor é invocado automaticamente antes que a memória para o objeto é recuperada. Essa construção automática e destruição de podem ser muito útil, mas você deve estar ciente das chamadas automático, especialmente para o destruidor.  
  
 A principal vantagem de alocação de objetos no quadro é que eles são excluídos automaticamente. Quando você alocar seus objetos no quadro, você não precisa se preocupar sobre objetos esquecidos causar vazamentos de memória. (Para obter detalhes sobre vazamentos de memória, consulte o artigo [detectando perdas de memória em MFC](http://msdn.microsoft.com/en-us/29ee8909-96e9-4246-9332-d3a8aa8d4658).) Uma desvantagem de alocação de quadro é que as variáveis de quadro não podem ser usados fora de seu escopo. Outro fator na escolha de alocação de quadro versus alocação de heap é que para grandes estruturas e objetos, geralmente é melhor usar o heap em vez da pilha para armazenamento, desde que o espaço de pilha é geralmente limitado.  
  
## <a name="see-also"></a>Consulte também  
 [Gerenciamento de memória](../mfc/memory-management.md)

