---
title: Criando um controle Rebar | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- rebar controls [MFC], creating
- CReBarCtrl class [MFC], creating
ms.assetid: 0a012e08-772b-4f6a-af86-7cb651d11d3e
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: d0f1cc709bf09d03f211f3123bd47c82bb590348
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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

