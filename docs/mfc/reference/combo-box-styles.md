---
title: "Estilos de caixa de combina&#231;&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "CBS_LOWERCASE"
  - "CBS_SORT"
  - "CBS_OWNERDRAWVARIABLE"
  - "CBS_OEMCONVERT"
  - "CBS_AUTOHSCROLL"
  - "CBS_NOINTEGRALHEIGHT"
  - "CBS_SIMPLE"
  - "CBS_DROPDOWNLIST"
  - "CBS_DROPDOWN"
  - "CBS_UPPERCASE"
  - "CBS_HASSTRINGS"
  - "CBS_DISABLENOSCROLL"
  - "CBS_OWNERDRAWFIXED"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Constante CBS_OWNERDRAWVARIABLE"
  - "Constante CBS_NOINTEGRALHEIGHT"
  - "Constante CBS_SIMPLE"
  - "Constante CBS_AUTOHSCROLL"
  - "Constante CBS_OEMCONVERT"
  - "Constante CBS_DISABLENOSCROLL"
  - "Constante CBS_HASSTRINGS"
  - "Constante CBS_LOWERCASE"
  - "Constante CBS_SORT"
  - "Constante CBS_DROPDOWN"
  - "Constante CBS_OWNERDRAWFIXED"
  - "caixas de combinação, estilos"
  - "Constante CBS_UPPERCASE"
  - "Constante CBS_DROPDOWNLIST"
ms.assetid: d21a5023-e6a2-495b-a6bd-010a515cbc63
caps.latest.revision: 12
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estilos de caixa de combina&#231;&#227;o
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Os seguintes estilos de caixa de combinação estão disponíveis no MFC.  
  
-   **CBS\_AUTOHSCROLL** rola automaticamente o texto no controle de edição à direita quando o usuário digita um caractere no final da linha. Se esse estilo não for definido, é permitido somente texto que cabe dentro dos limites retangulares.  
  
-   **CBS\_DISABLENOSCROLL** caixa de listagem mostra uma desabilitado barra de rolagem vertical quando a caixa de listagem não contiver itens suficientes para rolar. Sem esse estilo, a barra de rolagem é ocultada quando a caixa de listagem não contém itens suficientes.  
  
-   **CBS\_DROPDOWN** semelhante ao **CBS\_SIMPLE**, exceto que a caixa de lista não será exibida a menos que o usuário seleciona um ícone ao lado do controle de edição.  
  
-   **CBS\_DROPDOWNLIST** semelhante ao **CBS\_DROPDOWN**, exceto que o controle de edição é substituído por um item de texto estático que exibe a seleção atual na caixa de listagem.  
  
-   **CBS\_HASSTRINGS** uma caixa de combinação do desenho proprietário contém itens que consiste em cadeias de caracteres. A caixa de combinação mantém a memória e os ponteiros para as cadeias de caracteres, portanto, o aplicativo pode usar o `GetText` a função de membro para recuperar o texto de um item específico.  
  
-   **CBS\_LOWERCASE** converte em minúsculas todo o texto no campo de seleção e a lista.  
  
-   **CBS\_NOINTEGRALHEIGHT** Especifica que o tamanho da caixa de combinação é exatamente o tamanho especificado pelo aplicativo quando ele criado na caixa de combinação. Normalmente, o Windows dimensiona uma caixa de combinação para que a caixa de combinação não exibe itens parciais.  
  
-   **CBS\_OEMCONVERT** texto inserido no controle de edição de caixa de combinação é convertido do conjunto de caracteres ANSI para o conjunto de caracteres OEM e depois como ANSI. Isso garante a conversão de caracteres adequada quando o aplicativo chama o `AnsiToOem` função do Windows para converter uma cadeia de caracteres ANSI na caixa de combinação para caracteres OEM. Esse estilo é mais útil para caixas de combinação que contêm nomes de arquivos e se aplica somente às caixas de combinação criadas com o **CBS\_SIMPLE** ou **CBS\_DROPDOWN** estilos.  
  
-   **CBS\_OWNERDRAWFIXED** o proprietário da caixa de listagem é responsável por seu conteúdo de desenho; os itens na caixa de listagem são todos a mesma altura.  
  
-   **CBS\_OWNERDRAWVARIABLE** o proprietário da caixa de listagem é responsável por seu conteúdo de desenho; os itens na caixa de listagem são variáveis de altura.  
  
-   **CBS\_SIMPLE** caixa de listagem é exibida em todos os momentos. A seleção atual na caixa de listagem é exibida no controle de edição.  
  
-   **CBS\_SORT** classifica automaticamente inseridas na caixa de lista de cadeias de caracteres.  
  
-   **CBS\_UPPERCASE** converte em letras maiúsculas todo o texto no campo de seleção e a lista.  
  
## Consulte também  
 [Estilos usados pelo MFC](../../mfc/reference/styles-used-by-mfc.md)   
 [CComboBox::Create](../Topic/CComboBox::Create.md)   
 [Combo Box Styles](_win32_combo_box_styles)