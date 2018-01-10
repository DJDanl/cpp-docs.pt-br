---
title: "Estilos de caixa de combinação | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
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
dev_langs: C++
helpviewer_keywords:
- CBS_OWNERDRAWVARIABLE constant [MFC]
- CBS_NOINTEGRALHEIGHT constant [MFC]
- CBS_SIMPLE constant [MFC]
- CBS_AUTOHSCROLL constant [MFC]
- CBS_OEMCONVERT constant [MFC]
- CBS_DISABLENOSCROLL constant [MFC]
- CBS_HASSTRINGS constant [MFC]
- CBS_LOWERCASE constant [MFC]
- CBS_SORT constant [MFC]
- CBS_DROPDOWN constant [MFC]
- CBS_OWNERDRAWFIXED constant [MFC]
- combo boxes [MFC], styles
- CBS_UPPERCASE constant [MFC]
- CBS_DROPDOWNLIST constant
ms.assetid: d21a5023-e6a2-495b-a6bd-010a515cbc63
caps.latest.revision: "12"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 028a58c443ba45a4b8167a17f73f6f3fa54e4ca7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="combo-box-styles"></a>Estilos de caixa de combinação
Os seguintes estilos de caixa de combinação estão disponíveis no MFC.  
  
-   **CBS_AUTOHSCROLL** rola automaticamente o texto no controle de edição para a direita quando o usuário digita um caractere no final da linha. Se esse estilo não for definido, é permitido somente texto que cabe dentro do limite retangular.  
  
-   **CBS_DISABLENOSCROLL** a caixa de listagem mostra uma desabilitado barra de rolagem vertical quando a caixa de listagem não contém itens suficientes para rolar. Sem esse estilo, a barra de rolagem é ocultada quando a caixa de listagem contém itens suficientes.  
  
-   **CBS_DROPDOWN** , semelhante aos **CBS_SIMPLE**, exceto que a caixa de lista não é exibida, a menos que o usuário seleciona um ícone ao lado de controle de edição.  
  
-   **CBS_DROPDOWNLIST** , semelhante aos **CBS_DROPDOWN**, exceto que o controle de edição é substituído por um item de texto estático que exibe a seleção atual na caixa de listagem.  
  
-   **CBS_HASSTRINGS** uma caixa de combinação do desenho proprietário contém itens compostos por de cadeias de caracteres. A caixa de combinação mantém a memória e os ponteiros para as cadeias de caracteres para o aplicativo pode usar o `GetText` a função de membro para recuperar o texto para um determinado item.  
  
-   **CBS_LOWERCASE** converte em minúsculas todo o texto no campo de seleção e a lista.  
  
-   **CBS_NOINTEGRALHEIGHT** Especifica que o tamanho da caixa de combinação é exatamente o tamanho especificado pelo aplicativo quando ele criado na caixa de combinação. Normalmente, o Windows dimensiona uma caixa de combinação para que a caixa de combinação não exibe itens parciais.  
  
-   **CBS_OEMCONVERT** texto inserido no controle de edição de caixa de combinação é convertido do conjunto de caracteres ANSI para o conjunto de caracteres OEM e depois em ANSI. Isso assegura a conversão de caracteres adequada quando o aplicativo chama o `AnsiToOem` função do Windows para converter uma cadeia de caracteres ANSI na caixa de combinação em caracteres OEM. Este estilo é mais útil para caixas de combinação que contêm nomes de arquivos e aplica-se somente a caixas de combinação criadas com o **CBS_SIMPLE** ou **CBS_DROPDOWN** estilos.  
  
-   **CBS_OWNERDRAWFIXED** o proprietário da caixa de listagem é responsável por desenhar seu conteúdo; os itens na caixa de lista são da mesma altura.  
  
-   **CBS_OWNERDRAWVARIABLE** o proprietário da caixa de listagem é responsável por desenhar seu conteúdo; os itens na caixa de listagem são variáveis de altura.  
  
-   **CBS_SIMPLE** a caixa de listagem é exibida em todos os momentos. A seleção atual na caixa de listagem é exibida no controle de edição.  
  
-   **CBS_SORT** classifica automaticamente as cadeias de caracteres inseridas na caixa de lista.  
  
-   **CBS_UPPERCASE** converte em letras maiusculas todo o texto no campo de seleção e a lista.  
  
## <a name="see-also"></a>Consulte também  
 [Estilos usados pelo MFC](../../mfc/reference/styles-used-by-mfc.md)   
 [CComboBox::Create] (ccombobox class.md #ccombobox__create   



