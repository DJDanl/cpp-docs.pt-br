---
title: Otimizando o desenho de controle | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- MFC ActiveX controls [MFC], optimizing
ms.assetid: 29ff985d-9bf5-4678-b62d-aad12def75fb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8103e1e342756f9b715c1a0959ed256403e130bf
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="optimizing-control-drawing"></a>Otimizando o desenho de controle
Quando um controle é instruído para desenhar a próprio em um contexto de dispositivo fornecida pelo contêiner, ele normalmente seleciona objetos GDI (como fontes, pincéis e canetas) no contexto de dispositivo, executa as operações de desenho e restaura os objetos GDI anteriores. Se o contêiner tem vários controles que estão a ser desenhado no mesmo contexto de dispositivo, e cada controle seleciona os objetos GDI requer, tempo pode ser salvo se os controles não restauram objetos selecionados anteriormente individualmente. Depois que todos os controles foi emitidos, o contêiner pode restaurar os objetos originais automaticamente.  
  
 Para detectar se um contêiner dá suporte a essa técnica, um controle pode chamar o [COleControl::IsOptimizedDraw](../mfc/reference/colecontrol-class.md#isoptimizeddraw) função de membro. Se essa função retorna **TRUE**, o controle pode ignorar a etapa normal de restaurar os objetos selecionados anteriormente.  
  
 Considere a possibilidade de um controle que possui o seguinte (não otimizado) `OnDraw` função:  
  
 [!code-cpp[NVC_MFC_AxOpt#15](../mfc/codesnippet/cpp/optimizing-control-drawing_1.cpp)]  
  
 A caneta e Pincel neste exemplo são variáveis locais, o que significa que suas destruidores serão chamados quando saem do escopo (quando o `OnDraw` extremidades de função). Os destruidores tenta excluir os objetos GDI correspondentes. Mas eles não devem ser excluídos se você planeja deixá-los selecionado no contexto de dispositivo no retorno de `OnDraw`.  
  
 Para evitar o [CPen](../mfc/reference/cpen-class.md) e [CBrush](../mfc/reference/cbrush-class.md) objetos sejam destruídos quando `OnDraw` for concluída, armazená-las em variáveis de membro em vez de variáveis locais. Na declaração de classe do controle, adicione as declarações para duas novas variáveis de membro:  
  
 [!code-cpp[NVC_MFC_AxOpt#16](../mfc/codesnippet/cpp/optimizing-control-drawing_2.h)]  
[!code-cpp[NVC_MFC_AxOpt#17](../mfc/codesnippet/cpp/optimizing-control-drawing_3.h)]  
  
 Em seguida, o `OnDraw` função pode ser reescrita da seguinte maneira:  
  
 [!code-cpp[NVC_MFC_AxOpt#18](../mfc/codesnippet/cpp/optimizing-control-drawing_4.cpp)]  
  
 Essa abordagem evita a criação de caneta e Pincel sempre `OnDraw` é chamado. A melhoria de velocidade ocorre às custas de manutenção de dados de instância adicional.  
  
 Se a propriedade ForeColor ou BackColor é alterado, a caneta ou um pincel precisa ser criado novamente. Para fazer isso, substitua o [OnForeColorChanged](../mfc/reference/colecontrol-class.md#onforecolorchanged) e [OnBackColorChanged](../mfc/reference/colecontrol-class.md#onbackcolorchanged) funções de membro:  
  
 [!code-cpp[NVC_MFC_AxOpt#19](../mfc/codesnippet/cpp/optimizing-control-drawing_5.cpp)]  
  
 Por fim, para eliminar o desnecessária `SelectObject` chamadas, modificar `OnDraw` da seguinte maneira:  
  
 [!code-cpp[NVC_MFC_AxOpt#20](../mfc/codesnippet/cpp/optimizing-control-drawing_6.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Controles ActiveX MFC: otimização](../mfc/mfc-activex-controls-optimization.md)   
 [Classe COleControl](../mfc/reference/colecontrol-class.md)   
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)   
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)   
 [Assistente de controle ActiveX MFC](../mfc/reference/mfc-activex-control-wizard.md)   
 [Controles ActiveX do MFC: pintando um controle ActiveX](../mfc/mfc-activex-controls-painting-an-activex-control.md)

