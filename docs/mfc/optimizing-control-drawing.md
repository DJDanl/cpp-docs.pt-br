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
ms.openlocfilehash: 7cf929f55b2333bf40cf6fd4ac2588ce17842312
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46377750"
---
# <a name="optimizing-control-drawing"></a>Otimizando o desenho de controle

Quando um controle é instruído para desenhar a próprio em um contexto de dispositivo fornecidos pelo contêiner, ele normalmente seleciona objetos GDI (por exemplo, fontes, pincéis e canetas) no contexto de dispositivo, executa suas operações de desenho e restaura os objetos GDI anteriores. Se o contêiner tem vários controles que estão a ser desenhado no mesmo contexto de dispositivo, e cada controle seleciona objetos GDI exigidos por ele, o tempo pode ser salvo se os controles individualmente não restaurar objetos selecionados anteriormente. Depois que todos os controles foram emitidos, o contêiner pode restaurar automaticamente os objetos originais.

Para detectar se um contêiner dá suporte a essa técnica, um controle pode chamar o [COleControl::IsOptimizedDraw](../mfc/reference/colecontrol-class.md#isoptimizeddraw) função de membro. Se essa função retorna **verdadeira**, o controle pode ignorar a etapa normal de restaurar os objetos selecionados anteriormente.

Considere um controle que tem o seguinte (não otimizado) `OnDraw` função:

[!code-cpp[NVC_MFC_AxOpt#15](../mfc/codesnippet/cpp/optimizing-control-drawing_1.cpp)]

A caneta e Pincel nesse exemplo são variáveis locais, o que significa que os destruidores serão chamados quando eles saem do escopo (quando o `OnDraw` extremidades de função). Os destruidores tentará excluir os objetos GDI correspondentes. Mas eles não devem ser excluídos se você planeja deixá-los selecionado no contexto de dispositivo após o retorno de `OnDraw`.

Para impedir que o [CPen](../mfc/reference/cpen-class.md) e [CBrush](../mfc/reference/cbrush-class.md) objetos sejam destruídos quando `OnDraw` for concluída, armazená-las em variáveis de membro em vez de variáveis locais. Na declaração de classe do controle, adicione as declarações para duas novas variáveis de membro:

[!code-cpp[NVC_MFC_AxOpt#16](../mfc/codesnippet/cpp/optimizing-control-drawing_2.h)]
[!code-cpp[NVC_MFC_AxOpt#17](../mfc/codesnippet/cpp/optimizing-control-drawing_3.h)]

Em seguida, o `OnDraw` função pode ser reescrita da seguinte maneira:

[!code-cpp[NVC_MFC_AxOpt#18](../mfc/codesnippet/cpp/optimizing-control-drawing_4.cpp)]

Essa abordagem evita a criação da caneta e Pincel sempre `OnDraw` é chamado. A melhoria de velocidade ocorre às custas de manutenção de dados de instância adicional.

Se a propriedade de cor de primeiro plano ou BackColor é alterado, a caneta ou um pincel precisa ser criado novamente. Para fazer isso, substitua os [OnForeColorChanged](../mfc/reference/colecontrol-class.md#onforecolorchanged) e [OnBackColorChanged](../mfc/reference/colecontrol-class.md#onbackcolorchanged) funções de membro:

[!code-cpp[NVC_MFC_AxOpt#19](../mfc/codesnippet/cpp/optimizing-control-drawing_5.cpp)]

Por fim, para eliminar desnecessários `SelectObject` modificar chamadas, `OnDraw` da seguinte maneira:

[!code-cpp[NVC_MFC_AxOpt#20](../mfc/codesnippet/cpp/optimizing-control-drawing_6.cpp)]

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC: otimização](../mfc/mfc-activex-controls-optimization.md)<br/>
[Classe COleControl](../mfc/reference/colecontrol-class.md)<br/>
[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)<br/>
[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)<br/>
[Assistente de controle ActiveX do MFC](../mfc/reference/mfc-activex-control-wizard.md)<br/>
[Controles ActiveX do MFC: pintando um controle ActiveX](../mfc/mfc-activex-controls-painting-an-activex-control.md)

