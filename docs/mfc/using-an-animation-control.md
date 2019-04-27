---
title: Usando um controle de animação
ms.date: 11/04/2016
helpviewer_keywords:
- controls [MFC], animation
- CAnimateCtrl class [MFC], animation controls
- animation controls [MFC]
ms.assetid: a009a464-e12d-4112-bf52-04a09b28dd88
ms.openlocfilehash: 10bd8c0c26f92ce5de2261d6aca6fc7cc3a37365
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62180487"
---
# <a name="using-an-animation-control"></a>Usando um controle de animação

Um uso típico de um controle de animação segue o padrão abaixo:

- O controle é criado. Se o controle for especificado em um modelo de caixa de diálogo, a criação é automática quando a caixa de diálogo é criada. (Você deve ter uma [CAnimateCtrl](../mfc/reference/canimatectrl-class.md) membro em sua classe de caixa de diálogo que corresponde ao controle de animação.) Como alternativa, você pode usar o [criar](../mfc/reference/canimatectrl-class.md#create) função de membro para criar o controle como uma janela filho de qualquer janela.

- Carregar um clipe AVI para o controle de animação chamando o [abrir](../mfc/reference/canimatectrl-class.md#open) função de membro. Se o controle de animação estiver em uma caixa de diálogo, um bom lugar para fazer isso é na classe de caixa de diálogo [OnInitDialog](../mfc/reference/cdialog-class.md#oninitdialog) função.

- Execute o clipe chamando o [reproduzir](../mfc/reference/canimatectrl-class.md#play) função de membro. Se o controle de animação estiver em uma caixa de diálogo, um bom lugar para fazer isso é na classe de caixa de diálogo `OnInitDialog` função. Chamar `Play` não será necessária se o controle de animação, que tem o estilo ACS_AUTOPLAY definido.

- Se você quiser exibir as partes do clipe ou executá-lo por quadro, use o `Seek` função de membro. Para interromper um clipe de está em execução, use o `Stop` função de membro.

- Se você não pretende destruir o controle imediatamente, remova o clipe da memória chamando o `Close` função de membro.

- Se o controle de animação é em uma caixa de diálogo, ele e o `CAnimateCtrl` objeto será destruído automaticamente. Se não, você precisa garantir que os dois o controle e o `CAnimateCtrl` objeto são destruídos corretamente. Destruindo o controle automaticamente fecha o clipe AVI.

## <a name="see-also"></a>Consulte também

[Usando CAnimateCtrl](../mfc/using-canimatectrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
