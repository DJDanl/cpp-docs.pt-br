---
title: Criando um controle Rebar | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- rebar controls [MFC], creating
- CReBarCtrl class [MFC], creating
ms.assetid: 0a012e08-772b-4f6a-af86-7cb651d11d3e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1deb33adc104775cf9b76daf75d4ee08b6475f0a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="creating-a-rebar-control"></a>Criando um controle rebar
[CReBarCtrl](../mfc/reference/crebarctrl-class.md) objetos devem ser criados antes do objeto pai é visível. Isso minimiza as possibilidades de problemas de pintura.  
  
 Por exemplo, controles rebar (usados em objetos de janela do quadro) são usados como windows pai para controles de barra de ferramentas. Portanto, o pai do controle rebar é o objeto de janela do quadro. Porque o objeto de janela do quadro é o pai, o `OnCreate` a função de membro (do pai) é um excelente local para criar o controle rebar.  
  
 Para usar um `CReBarCtrl` do objeto, normalmente você seguirá estas etapas:  
  
### <a name="to-use-a-crebarctrl-object"></a>Para usar um objeto CReBarCtrl  
  
1.  Construir o [CReBarCtrl](../mfc/reference/crebarctrl-class.md) objeto.  
  
2.  Chamar [criar](../mfc/reference/crebarctrl-class.md#create) para criar o controle comum do Windows rebar e anexá-lo para o `CReBarCtrl` objeto, especificar qualquer estilo desejado.  
  
3.  Carregar um bitmap, com uma chamada para [CBitmap::LoadBitmap](../mfc/reference/cbitmap-class.md#loadbitmap), para ser usado como plano de fundo do objeto de controle rebar.  
  
4.  Criar e inicializar quaisquer objetos de janela filho (barras de ferramentas, controles de caixa de diálogo e assim por diante) que serão contidos pelo objeto do controle rebar.  
  
5.  Inicializar um **REBARBANDINFO** estrutura com as informações necessárias para a faixa prestes a ser inserido.  
  
6.  Chamar [InsertBand](../mfc/reference/crebarctrl-class.md#insertband) inserir janelas filho existentes (como `m_wndReToolBar`) para o novo controle rebar. Para obter mais informações sobre como inserir faixas em um controle rebar existente, consulte [controles Rebar e bandas](../mfc/rebar-controls-and-bands.md).  
  
## <a name="see-also"></a>Consulte também  
 [Usando CReBarCtrl](../mfc/using-crebarctrl.md)   
 [Controles](../mfc/controls-mfc.md)

