---
title: "Sele&#231;&#227;o atual em um controle de edi&#231;&#227;o avan&#231;ada | Microsoft Docs"
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
  - "Classe CRichEditCtrl, seleção atual em"
  - "seleção atual em CRichEditCtrls"
  - "controles de edição avançada, seleção atual em"
  - "seleção, atual em CRichEditCtrl"
ms.assetid: f6b2a2b6-5481-4ad3-9720-6dd772ea6fc8
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Sele&#231;&#227;o atual em um controle de edi&#231;&#227;o avan&#231;ada
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O usuário pode selecionar o texto em um controle de edição avançado \([CRichEditCtrl](../Topic/CRichEditCtrl%20Class.md)\) usando o mouse ou o teclado.  A seleção atual é o intervalo de caracteres selecionados, ou a posição do ponto de inserção se nenhum caractere é selecionado.  Um aplicativo pode obter informações sobre a seleção atual, defina a seleção atual, determina quando a seleção atual for alterado, e mostrar ou ocultar o realce de seleção.  
  
 Para determinar a seleção atual em um controle de edição avançado, use a função de membro de [GetSel](../Topic/CRichEditCtrl::GetSel.md) .  Para definir a seleção atual, use a função de membro de [SetSel](../Topic/CRichEditCtrl::SetSel.md) .  A estrutura de [CHARRANGE](http://msdn.microsoft.com/library/windows/desktop/bb787885) é usada com essas funções para especificar um intervalo de caracteres.  Para recuperar informações sobre o conteúdo da seleção atual, você pode usar a função de membro de [GetSelectionType](../Topic/CRichEditCtrl::GetSelectionType.md) .  
  
 Por padrão, um controle de edição mostra rico e oculta o realce de seleção quando vence e perder o foco.  Você pode mostrar ou ocultar o realce de seleção a qualquer momento usando a função de membro de [HideSelection](../Topic/CRichEditCtrl::HideSelection.md) .  Por exemplo, um aplicativo pode fornecer uma caixa de diálogo Pesquisar para localizar o texto em um controle de edição sofisticado.  O aplicativo pode selecionar o texto correspondente sem fechar a caixa de diálogo, nesse caso `HideSelection` deve usar para realçar a seleção.  
  
 Para obter o texto selecionado em um controle de edição avançado, use a função de membro de [GetSelText](../Topic/CRichEditCtrl::GetSelText.md) .  O texto é copiado para a matriz de caracteres especificada.  Você deve assegurar que a matriz é grande o suficiente para manter o texto selecionado mais um caractere nulo sendo encerrado.  
  
 Você pode procurar por uma cadeia de caracteres em um controle de edição rico usando a função de membro que [FindText](../Topic/CRichEditCtrl::FindText.md) da estrutura de [FINDTEXTEX](http://msdn.microsoft.com/library/windows/desktop/bb787909) usada por essa função especifica o intervalo de texto a ser pesquisado e a cadeia de caracteres para pesquisar por.  Você também pode especificar opções como se a pesquisa diferencia maiúsculas de minúsculas.  
  
## Consulte também  
 [Usando CRichEditCtrl](../mfc/using-cricheditctrl.md)   
 [Controles](../mfc/controls-mfc.md)