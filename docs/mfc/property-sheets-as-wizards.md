---
title: "Folhas de propriedades como assistentes | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "folhas de propriedade, como assistentes"
ms.assetid: 1ea66ecb-23b0-484a-838d-58671a2999b5
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Folhas de propriedades como assistentes
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma característica chave de uma folha de propriedade do assistente é que a navegação é fornecida com os botões de em seguida, ou de término do backup, e cancelar em vez das guias.  Você precisa chamar [CPropertySheet::SetWizardMode](../Topic/CPropertySheet::SetWizardMode.md) antes de chamar [CPropertySheet::DoModal](../Topic/CPropertySheet::DoModal.md) no objeto de folha de propriedade para tirar proveito desse recurso.  
  
 O usuário receberá as mesmas [CPropertyPage::OnSetActive](../Topic/CPropertyPage::OnSetActive.md) e notificações de [CPropertyPage::OnKillActive](../Topic/CPropertyPage::OnKillActive.md) ao mover de uma página para outra página.  Os botões Próximo e de término de controles são mutuamente exclusivos; ou seja, apenas um deless será mostrado por vez.  Na primeira página, o botão seguir deve ser habilitado.  Se o usuário está na última página, o botão de conclusão deve ser habilitado.  Isto não for feito automaticamente pela estrutura.  Você precisa chamar [CPropertySheet::SetWizardButton](../Topic/CPropertySheet::SetWizardButtons.md) na última página para obter esse.  
  
 Para exibir todos os botões padrão, apresentação de mush o botão de término e mover o botão próximo.  Mover o botão voltar de forma que sua posição relativa ao botão próximo é mantida.  Para obter mais explicação, pesquise por Q143210 artigo da base de dados.  Os artigos da Base de Dados de Conhecimento estão disponíveis na Biblioteca MSDN.  
  
## Exemplo  
 [!code-cpp[NVC_MFCDocView#5](../mfc/codesnippet/CPP/property-sheets-as-wizards_1.cpp)]  
  
## Consulte também  
 [Folhas de propriedade](../mfc/property-sheets-mfc.md)