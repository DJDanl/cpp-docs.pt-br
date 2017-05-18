---
title: "Estilos de caixa de combinação | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CBS_LOWERCASE
- CBS_SORT
- CBS_OWNERDRAWVARIABLE
- CBS_OEMCONVERT
- CBS_AUTOHSCROLL
- CBS_NOINTEGRALHEIGHT
- CBS_SIMPLE
- CBS_DROPDOWNLIST
- CBS_DROPDOWN
- CBS_UPPERCASE
- CBS_HASSTRINGS
- CBS_DISABLENOSCROLL
- CBS_OWNERDRAWFIXED
dev_langs:
- C++
helpviewer_keywords:
- CBS_OWNERDRAWVARIABLE constant
- CBS_NOINTEGRALHEIGHT constant
- CBS_SIMPLE constant
- CBS_AUTOHSCROLL constant
- CBS_OEMCONVERT constant
- CBS_DISABLENOSCROLL constant
- CBS_HASSTRINGS constant
- CBS_LOWERCASE constant
- CBS_SORT constant
- CBS_DROPDOWN constant
- CBS_OWNERDRAWFIXED constant
- combo boxes, styles
- CBS_UPPERCASE constant
- CBS_DROPDOWNLIST constant
ms.assetid: d21a5023-e6a2-495b-a6bd-010a515cbc63
caps.latest.revision: 12
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
ms.translationtype: Machine Translation
ms.sourcegitcommit: 5187996fc377bca8633360082d07f7ec8a68ee57
ms.openlocfilehash: 57069f6e6cd0999773ab3872e671a65e1e880bba
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="combo-box-styles"></a>Estilos de caixa de combinação
Os seguintes estilos de caixa de combinação estão disponíveis no MFC.  
  
-   **CBS_AUTOHSCROLL** rola automaticamente o texto no controle de edição à direita quando o usuário digita um caractere no final da linha. Se esse estilo não for definido, é permitido somente texto que cabe dentro dos limites retangulares.  
  
-   **CBS_DISABLENOSCROLL** a caixa de listagem mostra uma desabilitado barra de rolagem vertical quando a caixa de listagem não contiver itens suficientes para rolar. Sem esse estilo, a barra de rolagem é ocultada quando a caixa de listagem não contém itens suficientes.  
  
-   **CBS_DROPDOWN** semelhante ao **CBS_SIMPLE**, exceto que a caixa de lista não será exibida a menos que o usuário seleciona um ícone ao lado do controle de edição.  
  
-   **CBS_DROPDOWNLIST** semelhante ao **CBS_DROPDOWN**, exceto que o controle de edição é substituído por um item de texto estático que exibe a seleção atual na caixa de listagem.  
  
-   **CBS_HASSTRINGS** uma caixa de combinação do desenho proprietário contém itens que consiste em cadeias de caracteres. A caixa de combinação mantém a memória e os ponteiros para as cadeias de caracteres, portanto, o aplicativo pode usar o `GetText` a função de membro para recuperar o texto de um item específico.  
  
-   **CBS_LOWERCASE** converte em minúsculas todo o texto no campo de seleção e a lista.  
  
-   **CBS_NOINTEGRALHEIGHT** Especifica que o tamanho da caixa de combinação é exatamente o tamanho especificado pelo aplicativo quando ele criado na caixa de combinação. Normalmente, o Windows dimensiona uma caixa de combinação para que a caixa de combinação não exibe itens parciais.  
  
-   **CBS_OEMCONVERT** texto inserido no controle de edição de caixa de combinação é convertido do conjunto de caracteres ANSI para o conjunto de caracteres OEM e depois como ANSI. Isso garante a conversão de caracteres adequada quando o aplicativo chama o `AnsiToOem` função do Windows para converter uma cadeia de caracteres ANSI na caixa de combinação para caracteres OEM. Esse estilo é mais útil para caixas de combinação que contêm nomes de arquivos e se aplica somente às caixas de combinação criadas com o **CBS_SIMPLE** ou **CBS_DROPDOWN** estilos.  
  
-   **CBS_OWNERDRAWFIXED** o proprietário da caixa de listagem é responsável por seu conteúdo de desenho; os itens na caixa de listagem são todos a mesma altura.  
  
-   **CBS_OWNERDRAWVARIABLE** o proprietário da caixa de listagem é responsável por seu conteúdo de desenho; os itens na caixa de listagem são variáveis de altura.  
  
-   **CBS_SIMPLE** a caixa de listagem é exibida em todos os momentos. A seleção atual na caixa de listagem é exibida no controle de edição.  
  
-   **CBS_SORT** classifica automaticamente inseridas na caixa de lista de cadeias de caracteres.  
  
-   **CBS_UPPERCASE** converte em letras maiusculas todo o texto no campo de seleção e a lista.  
  
## <a name="see-also"></a>Consulte também  
 [Estilos usados pelo MFC](../../mfc/reference/styles-used-by-mfc.md)   
 [CComboBox::Create] (ccombobox class.md #ccombobox__create   




