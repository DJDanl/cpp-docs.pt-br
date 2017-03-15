---
title: Estilos de caixa de listagem | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- LBS_STANDARD
- LBS_NODATA
- LBS_OWNERDRAWVARIABLE
- LBS_EXTENDEDSEL
- LBS_USETABSTOPS
- LBS_WANTKEYBOARDINPUT
- LBS_NOTIFY
- LBS_DISABLENOSCROLL
- LBS_HASSTRINGS
- LBS_NOREDRAW
- LBS_NOSEL
- LBS_NOINTEGRALHEIGHT
- LBS_MULTICOLUMN
- LBS_SORT
- LBS_MULTIPLESEL
- LBS_OWNERDRAWFIXED
dev_langs:
- C++
helpviewer_keywords:
- LBS_NOSEL constant
- LBS_NOREDRAW constant
- LBS_HASSTRINGS constant
- LBS_OWNERDRAWFIXED constant
- LBS_WANTKEYBOARDINPUT constant
- LBS_STANDARD constant
- LBS_MULTIPLESEL constant
- LBS_OWNERDRAWVARIABLE constant
- LBS_DISABLENOSCROLL constant
- LBS_NODATA constant
- list boxes, styles
- LBS_EXTENDEDSEL constant
- LBS_MULTICOLUMN constant
- LBS_NOTIFY constant
- LBS_USETABSTOPS constant
- LBS_NOINTEGRALHEIGHT constant
- LBS_SORT constant
ms.assetid: 3f357b8d-9118-4f41-9e28-02ed92d1e88f
caps.latest.revision: 12
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 8e038e5cef50bd15df85c9d7f8b213b54ed03825
ms.lasthandoff: 02/25/2017

---
# <a name="list-box-styles"></a>Estilos de caixa de listagem
-   **LBS_DISABLENOSCROLL** a caixa de listagem mostra uma desabilitado barra de rolagem vertical quando a caixa de listagem não contiver itens suficientes para rolar. Sem esse estilo, a barra de rolagem é ocultada quando a caixa de listagem não contém itens suficientes.  
  
-   **LBS_EXTENDEDSEL** o usuário pode selecionar vários itens usando a tecla SHIFT e o mouse ou combinações de teclas especiais.  
  
-   **LBS_HASSTRINGS** Especifica uma caixa de listagem de desenho proprietário que contém itens que consiste em cadeias de caracteres. A caixa de listagem mantém a memória e os ponteiros para as cadeias de caracteres, portanto, o aplicativo pode usar o `GetText` a função de membro para recuperar o texto de um item específico.  
  
-   **LBS_MULTICOLUMN** Especifica uma caixa de listagem de várias colunas que é rolada horizontalmente. O `SetColumnWidth` função membro define a largura das colunas.  
  
-   **LBS_MULTIPLESEL** seleção de cadeia de caracteres é alternada sempre que o usuário clica ou clica duas vezes a cadeia de caracteres. Qualquer número de cadeias de caracteres pode ser selecionado.  
  
-   **LBS_NODATA** Especifica uma caixa de listagem sem dados. Especifique esse estilo quando a contagem de itens na caixa de listagem excederá mil. Uma caixa de listagem sem dados também deve ter o **LBS_OWNERDRAWFIXED** de estilo, mas não deve ter o **LBS_SORT** ou **LBS_HASSTRINGS** estilo.  
  
     Uma caixa de listagem de nenhum dado é semelhante a uma caixa de listagem de desenho proprietário exceto que não contém nenhum dado de cadeia de caracteres ou bitmap para um item. Comandos para adicionar, inserir ou excluir um item sempre ignorar qualquer item dados; solicitações para localizar uma cadeia de caracteres na caixa de listagem sempre falharem. O sistema envia a `WM_DRAWITEM` mensagem na janela de proprietário quando um item deve ser desenhado. O membro itemID o `DRAWITEMSTRUCT` estrutura passado com a `WM_DRAWITEM` mensagem especifica o número da linha do item a ser desenhada. Uma caixa de listagem sem dados não envia um `WM_DELETEITEM` mensagem.  
  
-   **LBS_NOINTEGRALHEIGHT** o tamanho da caixa de listagem é exatamente o tamanho especificado pelo aplicativo quando ele criado a caixa de listagem. Normalmente, o Windows dimensiona uma caixa de listagem para que a caixa de listagem exibe itens parciais.  
  
-   **LBS_NOREDRAW** exibição da caixa de lista não é atualizada quando as alterações são feitas. Esse estilo pode ser alterado a qualquer momento, enviando uma **WM_SETREDRAW** mensagem.  
  
-   **LBS_NOSEL** Especifica que a caixa de listagem contém itens que podem ser exibidos, mas não selecionados.  
  
-   **LBS_NOTIFY** janela pai recebe uma mensagem de entrada sempre que o usuário clica ou clica duas vezes em uma cadeia de caracteres.  
  
-   **LBS_OWNERDRAWFIXED** o proprietário da caixa de listagem é responsável por seu conteúdo de desenho; os itens na caixa de listagem têm a mesma altura.  
  
-   **LBS_OWNERDRAWVARIABLE** o proprietário da caixa de listagem é responsável por seu conteúdo de desenho; os itens na caixa de listagem são variáveis de altura.  
  
-   **LBS_SORT** cadeias de caracteres na caixa de listagem são classificadas em ordem alfabética.  
  
-   **LBS_STANDARD** cadeias de caracteres na caixa de listagem são classificadas em ordem alfabética, e a janela pai recebe uma mensagem de entrada sempre que o usuário clica ou clica duas vezes em uma cadeia de caracteres. A caixa de listagem contém bordas em todos os lados.  
  
-   **LBS_USETABSTOPS** permite uma caixa de lista reconheça e expanda caracteres de tabulação ao desenhar suas sequências de caracteres. As posições de tabulação padrão são 32 unidades de caixa de diálogo. (Uma unidade de diálogo é uma distância horizontal ou vertical. Uma unidade de diálogo horizontal é igual a um quarto da unidade de largura de base da caixa de diálogo atual. As unidades base da caixa de diálogo são calculadas com base na altura e largura da fonte atual do sistema. O **GetDialogBaseUnits** função Windows retorna a caixa de diálogo atual unidades base em pixels.) Este estilo não deve ser usado com **LBS_OWNERDRAWFIXED**.  
  
-   **LBS_WANTKEYBOARDINPUT** recebe o proprietário da caixa de listagem `WM_VKEYTOITEM` ou `WM_CHARTOITEM` mensagens sempre que o usuário pressiona uma tecla enquanto a caixa de listagem tem o foco de entrada. Isso permite que um aplicativo executa processamento especial no teclado de entrada.  
  
## <a name="see-also"></a>Consulte também  
 [Estilos usados pelo MFC](../../mfc/reference/styles-used-by-mfc.md)   
 [CListBox::Create](../../mfc/reference/clistbox-class.md#create)   
 [Estilos de caixa de lista](http://msdn.microsoft.com/library/windows/desktop/bb775149)


