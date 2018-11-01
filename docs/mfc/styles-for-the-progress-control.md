---
title: Estilos para o controle de progresso
ms.date: 11/04/2016
helpviewer_keywords:
- PBS_SMOOTH style
- progress controls [MFC], styles
- PBS_VERTICAL style
- CProgressCtrl class [MFC], styles
ms.assetid: 39eb8081-bc20-4552-91b9-e7cdd1b7d8ae
ms.openlocfilehash: 494f5df03d15e1662f20aff644fb414a7254ad5f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50451721"
---
# <a name="styles-for-the-progress-control"></a>Estilos para o controle de progresso

Quando você cria inicialmente o controle de progresso ([CProgressCtrl::Create](../mfc/reference/cprogressctrl-class.md#create)), use o *dwStyle* parâmetro para especificar os estilos de janela desejado para seu controle de progresso. A lista a seguir fornece detalhes sobre os estilos de janela aplicável. O controle ignorará qualquer estilo de janela diferentes daqueles listados aqui. Você sempre deve criar o controle como uma janela filho, normalmente de um pai da caixa de diálogo.

|Estilo da janela|Efeito|
|------------------|------------|
|WS_BORDER|Cria uma borda ao redor da janela.|
|WS_CHILD|Cria uma janela filho (sempre deve ser usado para `CProgressCtrl`).|
|WS_CLIPCHILDREN|Exclui a área ocupada por janelas filhas quando você desenhar dentro da janela pai. Usado quando você cria a janela pai.|
|WS_CLIPSIBLINGS|Janelas filhas relativos uns aos outros.|
|WS_DISABLED|Cria uma janela que é inicialmente desabilitada.|
|WS_VISIBLE|Cria uma janela que é visível inicialmente.|
|WS_TABSTOP|Especifica que o controle pode receber o foco quando o usuário pressiona a tecla TAB para mover a ele.|

Além disso, você pode especificar dois estilos que se aplicam somente para o controle de progresso, PBS_VERTICAL e PBS_SMOOTH.

Use PBS_VERTICAL para orientar o controle verticalmente, em vez de horizontalmente. Use PBS_SMOOTH para preencher o controle completo, em vez de exibir pequenos quadrados delineados que preenchem o controle de forma incremental.

Sem estilo PBS_SMOOTH:

![Estilo de barra de progresso padrão](../mfc/media/vc4ruw1.gif "vc4ruw1")

Com estilos PBS_SMOOTH e PBS_VERTICAL:

![Estilo, smooth e vertical da barra de progresso](../mfc/media/vc4ruw2.gif "vc4ruw2")

Para obter mais informações, consulte [estilos da janela](../mfc/reference/styles-used-by-mfc.md#frame-window-styles-mfc) na *referência da MFC*.

## <a name="see-also"></a>Consulte também

[Usando CProgressCtrl](../mfc/using-cprogressctrl.md)

