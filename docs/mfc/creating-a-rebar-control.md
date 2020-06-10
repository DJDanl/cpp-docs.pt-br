---
title: Criando um controle rebar
ms.date: 11/04/2016
helpviewer_keywords:
- rebar controls [MFC], creating
- CReBarCtrl class [MFC], creating
ms.assetid: 0a012e08-772b-4f6a-af86-7cb651d11d3e
ms.openlocfilehash: 6828fa3b47eaa1e29579b09611d85cd68702c332
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84617132"
---
# <a name="creating-a-rebar-control"></a>Criando um controle rebar

Os objetos [CReBarCtrl](reference/crebarctrl-class.md) devem ser criados antes de o objeto pai ser visível. Isso minimiza as possibilidades de problemas de pintura.

Por exemplo, controles Rebar (usados em objetos de janela de quadro) são normalmente usados como janelas pai para controles de barra de ferramentas. Portanto, o pai do controle rebar é o objeto janela do quadro. Como o objeto janela do quadro é o pai, a `OnCreate` função de membro (do pai) é um local excelente para criar o controle rebar.

Para usar um `CReBarCtrl` objeto, você normalmente seguirá estas etapas:

### <a name="to-use-a-crebarctrl-object"></a>Para usar um objeto CReBarCtrl

1. Construa o objeto [CReBarCtrl](reference/crebarctrl-class.md) .

1. Chame [Create](reference/crebarctrl-class.md#create) para criar o controle comum do Windows Rebar e anexe-o ao `CReBarCtrl` objeto, especificando os estilos desejados.

1. Carregue um bitmap, com uma chamada para [CBitmap:: LoadBitmap](reference/cbitmap-class.md#loadbitmap), a ser usado como o plano de fundo do objeto de controle rebar.

1. Criar e inicializar objetos de janela filho (barras de ferramentas, controles de diálogo e assim por diante) que estarão contidos no objeto de controle rebar.

1. Inicialize uma estrutura **REBARBANDINFO** com as informações necessárias para a banda prestes a ser inserida.

1. Chame [InsertBand](reference/crebarctrl-class.md#insertband) para inserir as janelas filho existentes (como `m_wndReToolBar` ) no novo controle rebar. Para obter mais informações sobre como inserir bandas em um controle rebar existente, consulte [controles e bandas de rebar](rebar-controls-and-bands.md).

## <a name="see-also"></a>Consulte também

[Usando CReBarCtrl](using-crebarctrl.md)<br/>
[Controles](controls-mfc.md)
