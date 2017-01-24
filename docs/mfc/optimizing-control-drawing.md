---
title: "Otimizando o desenho de controle | Microsoft Docs"
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
  - "Controles ActiveX MFC, otimizando"
ms.assetid: 29ff985d-9bf5-4678-b62d-aad12def75fb
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Otimizando o desenho de controle
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando um controle for instruído a ser desenhado em um contexto fornecido do dispositivo, normalmente seleciona objetos de GDI \(como penalidades, escovas, e fontes\) no contexto do dispositivo, executa suas operações de desenho, e restaura os objetos anteriores de GDI.  Se o contêiner tem vários controles que devem ser desenhados no mesmo contexto do dispositivo, e cada controle seleciona os objetos de GDI requer, o tempo podem ser salvos se os controles não restauração individualmente objetos selecionados anteriormente.  Os controles foram extraídos depois, o contêiner automaticamente podem restaurar os objetos originais.  
  
 Para detectar se um contêiner da suporte a essa técnica, um controle pode chamar a função de membro de [COleControl::IsOptimizedDraw](../Topic/COleControl::IsOptimizedDraw.md) .  Se esta função retorna **Verdadeiro**, o controle pode passar à etapa normal de restaurar os objetos selecionados anteriormente.  
  
 Considere um controle que tem a seguinte função \(unoptimized\) de `OnDraw` :  
  
 [!code-cpp[NVC_MFC_AxOpt#15](../mfc/codesnippet/CPP/optimizing-control-drawing_1.cpp)]  
  
 A caneta e a escova neste exemplo são variáveis locais, o que significa que seus destruidores serão chamados quando sair do escopo \(quando a função de `OnDraw` termina\).  Os destruidores tentarão excluir os objetos correspondentes de GDI.  Mas não devem ser excluídos se você planeja os deixar selecionados no contexto do dispositivo de retornar de `OnDraw`.  
  
 Para impedir que os objetos de [CPen](../Topic/CPen%20Class.md) e de [CBrush](../mfc/reference/cbrush-class.md) serem destruídos quando `OnDraw` é concluída, os armazena em variáveis de membro em vez de variáveis locais.  Na declaração de classe de controle, adicione instruções para dois novos variáveis de membro:  
  
 [!code-cpp[NVC_MFC_AxOpt#16](../mfc/codesnippet/CPP/optimizing-control-drawing_2.h)]  
[!code-cpp[NVC_MFC_AxOpt#17](../mfc/codesnippet/CPP/optimizing-control-drawing_3.h)]  
  
 Em seguida, a função de `OnDraw` pode ser reescrita como segue:  
  
 [!code-cpp[NVC_MFC_AxOpt#18](../mfc/codesnippet/CPP/optimizing-control-drawing_4.cpp)]  
  
 Essa abordagem impede a criação de forma e de escova cada vez que `OnDraw` é chamado.  A melhoria da velocidade ocorre às custas de manter dados adicionais da instância.  
  
 Se a propriedade ForeColor ou de BackColor for alterada, a caneta ou a escova precisam ser criadas novamente.  Para fazer isso, substitua as funções de membro de [OnForeColorChanged](../Topic/COleControl::OnForeColorChanged.md) e de [OnBackColorChanged](../Topic/COleControl::OnBackColorChanged.md) :  
  
 [!code-cpp[NVC_MFC_AxOpt#19](../mfc/codesnippet/CPP/optimizing-control-drawing_5.cpp)]  
  
 Finalmente, para eliminar chamadas desnecessários de `SelectObject` , modifique `OnDraw` como segue:  
  
 [!code-cpp[NVC_MFC_AxOpt#20](../mfc/codesnippet/CPP/optimizing-control-drawing_6.cpp)]  
  
## Consulte também  
 [Controles ActiveX MFC: otimização](../mfc/mfc-activex-controls-optimization.md)   
 [Classe de COleControl](../mfc/reference/colecontrol-class.md)   
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)   
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)   
 [Assistente de controle ActiveX MFC](../mfc/reference/mfc-activex-control-wizard.md)   
 [Controles ActiveX MFC: pintando um controle ActiveX](../mfc/mfc-activex-controls-painting-an-activex-control.md)