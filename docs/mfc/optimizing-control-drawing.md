---
title: Otimizando o desenho de controle
ms.date: 11/04/2016
helpviewer_keywords:
- MFC ActiveX controls [MFC], optimizing
ms.assetid: 29ff985d-9bf5-4678-b62d-aad12def75fb
ms.openlocfilehash: 17cb7318e667fe4e16416d51e7e7fba02553cfe6
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84621009"
---
# <a name="optimizing-control-drawing"></a>Otimizando o desenho de controle

Quando um controle é instruído a se desenhar em um contexto de dispositivo fornecido por contêiner, ele normalmente seleciona objetos GDI (como canetas, pincéis e fontes) no contexto do dispositivo, executa suas operações de desenho e restaura os objetos GDI anteriores. Se o contêiner tiver vários controles que devem ser desenhados no mesmo contexto de dispositivo, e cada controle selecionar os objetos GDI necessários, o tempo poderá ser salvo se os controles não restaurarem individualmente os objetos selecionados anteriormente. Depois que todos os controles tiverem sido desenhados, o contêiner poderá restaurar automaticamente os objetos originais.

Para detectar se um contêiner dá suporte a essa técnica, um controle pode chamar a função de membro [COleControl:: IsOptimizedDraw](reference/colecontrol-class.md#isoptimizeddraw) . Se essa função retornar **true**, o controle poderá ignorar a etapa normal de restaurar os objetos selecionados anteriormente.

Considere um controle que tenha a seguinte função (não otimizada) `OnDraw` :

[!code-cpp[NVC_MFC_AxOpt#15](codesnippet/cpp/optimizing-control-drawing_1.cpp)]

A caneta e o pincel neste exemplo são variáveis locais, o que significa que seus destruidores serão chamados quando ficarem fora do escopo (quando a `OnDraw` função terminar). Os destruidores tentarão excluir os objetos GDI correspondentes. Mas eles não devem ser excluídos se você planeja deixá-los selecionados no contexto do dispositivo ao retornar de `OnDraw` .

Para impedir que os objetos [CPen](reference/cpen-class.md) e [CBrush](reference/cbrush-class.md) sejam destruídos ao serem `OnDraw` concluídos, armazene-os em variáveis de membro em vez de variáveis locais. Na declaração de classe do controle, adicione declarações para duas novas variáveis de membro:

[!code-cpp[NVC_MFC_AxOpt#16](codesnippet/cpp/optimizing-control-drawing_2.h)]
[!code-cpp[NVC_MFC_AxOpt#17](codesnippet/cpp/optimizing-control-drawing_3.h)]

Em seguida, a `OnDraw` função pode ser reescrita da seguinte maneira:

[!code-cpp[NVC_MFC_AxOpt#18](codesnippet/cpp/optimizing-control-drawing_4.cpp)]

Essa abordagem evita a criação da caneta e do pincel toda vez que `OnDraw` é chamada. A melhoria da velocidade acompanha o custo de manutenção de dados de instância adicionais.

Se a propriedade ForeColor ou BackColor for alterada, a caneta ou o pincel precisarão ser criados novamente. Para fazer isso, substitua as funções de membro [Oncordeprimeiroplanochanged](reference/colecontrol-class.md#onforecolorchanged) e [OnBackColorChanged](reference/colecontrol-class.md#onbackcolorchanged) :

[!code-cpp[NVC_MFC_AxOpt#19](codesnippet/cpp/optimizing-control-drawing_5.cpp)]

Por fim, para eliminar chamadas desnecessárias `SelectObject` , modifique `OnDraw` da seguinte maneira:

[!code-cpp[NVC_MFC_AxOpt#20](codesnippet/cpp/optimizing-control-drawing_6.cpp)]

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC: otimização](mfc-activex-controls-optimization.md)<br/>
[Classe COleControl](reference/colecontrol-class.md)<br/>
[Controles ActiveX do MFC](mfc-activex-controls.md)<br/>
[Assistente de controle ActiveX MFC](reference/mfc-activex-control-wizard.md)<br/>
[Controles ActiveX do MFC: pintando um controle ActiveX](mfc-activex-controls-painting-an-activex-control.md)
