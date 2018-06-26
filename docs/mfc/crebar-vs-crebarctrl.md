---
title: CReBar vs. CReBarCtrl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- CReBar
- CReBarCtrl
dev_langs:
- C++
helpviewer_keywords:
- CReBar class [MFC], vs. CReBarCtrl
- rebar controls [MFC], CReBarCtrl class [MFC]
- GetReBarCtrl class [MFC]
ms.assetid: 7f9c1d7e-5d5f-4956-843c-69ed3df688d0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c98b2fd9baf97d351c812f2c442d408ff6221d82
ms.sourcegitcommit: 060f381fe0807107ec26c18b46d3fcb859d8d2e7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/25/2018
ms.locfileid: "36932254"
---
# <a name="crebar-vs-crebarctrl"></a>CReBar vs. CReBarCtrl
MFC fornece classes para criar rebars: [CReBar](../mfc/reference/crebar-class.md) e [CReBarCtrl](../mfc/reference/crebarctrl-class.md) (que encapsula a API de controle comum do Windows). `CReBar` fornece todas as funcionalidades do controle rebar comum, e trata muitas das configurações de controle comuns necessárias e estruturas para você.  
  
 `CReBarCtrl` é uma classe wrapper para o controle rebar Win32 e, portanto, pode ser mais fácil de implementar, se você não pretende integrar o rebar na arquitetura do MFC. Se você planeja usar `CReBarCtrl` e integrar o rebar na arquitetura do MFC, você deve tomar cuidado adicional para se comunicar manipulações de controle rebar a MFC. Essa comunicação não é difícil; No entanto, é trabalho adicional é desnecessário quando você usar `CReBar`.  
  
 Visual C++ fornece duas maneiras de tirar proveito do controle rebar comuns.  
  
-   Criar o rebar usando `CReBar`e, em seguida, chame [CReBar::GetReBarCtrl](../mfc/reference/crebar-class.md#getrebarctrl) para obter acesso ao `CReBarCtrl` funções de membro.  
  
    > [!NOTE]
    >  `CReBar::GetReBarCtrl` é uma função de membro embutida que converte o **isso** ponteiro do objeto rebar. Isso significa que, em tempo de execução, a chamada de função não tem nenhuma sobrecarga.  
  
-   Criar o rebar usando [CReBarCtrl](../mfc/reference/crebarctrl-class.md)do construtor.  
  
 O método lhe dará acesso a funções de membro de controle rebar. Quando você chama `CReBar::GetReBarCtrl`, ele retorna uma referência a um `CReBarCtrl` , você pode usar um conjunto de funções de membro de objeto. Consulte [CReBar](../mfc/reference/crebar-class.md) para obter informações sobre como construir e criar um rebar usando `CReBar`.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CReBarCtrl](../mfc/using-crebarctrl.md)   
 [Controles](../mfc/controls-mfc.md)

