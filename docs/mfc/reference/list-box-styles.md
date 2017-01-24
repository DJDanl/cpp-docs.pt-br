---
title: "Estilos de caixa de listagem | Microsoft Docs"
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
  - "LBS_STANDARD"
  - "LBS_NODATA"
  - "LBS_OWNERDRAWVARIABLE"
  - "LBS_EXTENDEDSEL"
  - "LBS_USETABSTOPS"
  - "LBS_WANTKEYBOARDINPUT"
  - "LBS_NOTIFY"
  - "LBS_DISABLENOSCROLL"
  - "LBS_HASSTRINGS"
  - "LBS_NOREDRAW"
  - "LBS_NOSEL"
  - "LBS_NOINTEGRALHEIGHT"
  - "LBS_MULTICOLUMN"
  - "LBS_SORT"
  - "LBS_MULTIPLESEL"
  - "LBS_OWNERDRAWFIXED"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Constante LBS_DISABLENOSCROLL"
  - "Constante LBS_EXTENDEDSEL"
  - "Constante LBS_HASSTRINGS"
  - "Constante LBS_MULTICOLUMN"
  - "Constante LBS_MULTIPLESEL"
  - "Constante LBS_NODATA"
  - "Constante LBS_NOINTEGRALHEIGHT"
  - "Constante LBS_NOREDRAW"
  - "Constante LBS_NOSEL"
  - "Constante LBS_NOTIFY"
  - "Constante LBS_OWNERDRAWFIXED"
  - "Constante LBS_OWNERDRAWVARIABLE"
  - "Constante LBS_SORT"
  - "Constante LBS_STANDARD"
  - "Constante LBS_USETABSTOPS"
  - "Constante LBS_WANTKEYBOARDINPUT"
  - "caixas de listagem, estilos"
ms.assetid: 3f357b8d-9118-4f41-9e28-02ed92d1e88f
caps.latest.revision: 12
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estilos de caixa de listagem
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

-   **LBS\_DISABLENOSCROLL** a caixa de listagem exibe uma barra de rolagem vertical desabilitado quando a caixa de listagem não contém itens suficiente para rolar.  Sem esse estilo, a barra de rolagem ficará oculta se a caixa de listagem não contém itens suficiente.  
  
-   **LBS\_EXTENDEDSEL** o usuário pode selecionar vários itens usando a tecla SHIFT e as combinações de tecla do mouse em ou nas especiais.  
  
-   **LBS\_HASSTRINGS** especifica uma caixa de listagem da proprietário\- descompasso que contém os itens que consistem em cadeias de caracteres.  A caixa de listagem mantém a memória e os ponteiros para as cadeias de caracteres assim que o aplicativo pode usar a função de membro de `GetText` para recuperar o texto de um item específico.  
  
-   **LBS\_MULTICOLUMN** especifica uma caixa de listagem com várias colunas que seja enrolada horizontalmente.  A função de membro de `SetColumnWidth` define a largura das colunas.  
  
-   A seleção de cadeia de caracteres de**LBS\_MULTIPLESEL**é ativada \/desativar cada vez que o usuário clica em ou clique duas vezes na cadeia de caracteres.  Qualquer número de cadeias de caracteres pode ser selecionado.  
  
-   **LBS\_NODATA** especifica uma caixa de listagem de dados não.  Especificar esse estilo quando a contagem de itens na caixa de listagem excederá de milhar.  Uma caixa de listagem de dados não deve ter o estilo de **LBS\_OWNERDRAWFIXED** , mas não deve ter o estilo de **LBS\_SORT** ou de **LBS\_HASSTRINGS** .  
  
     Uma caixa de listagem de dados não é semelhante a uma caixa de listagem proprietário\- desenhada exceto que não contém nenhum cadeia de caracteres ou dados de bitmap para um item.  Os comandos adicionar, inserir, ou excluir um item sempre ignora todos os dados dados de item; solicitações localizar sempre uma cadeia de caracteres dentro da falha da caixa de listagem.  O sistema envia a mensagem de `WM_DRAWITEM` à janela do proprietário quando um item deve ser desenhado.  O membro de itemID da estrutura de `DRAWITEMSTRUCT` passada com a mensagem de `WM_DRAWITEM` especifica o número da linha do item a ser desenhado.  Uma caixa de listagem de dados sem não envia uma mensagem de `WM_DELETEITEM` .  
  
-   **LBS\_NOINTEGRALHEIGHT** o tamanho da caixa de listagem é exatamente ao tamanho especificado pelo aplicativo quando criou a caixa de listagem.  Geralmente, as janelas tamanhos de uma caixa de listagem de forma que a caixa de listagem não exibirá itens parciais.  
  
-   A exibição da caixa de listagem de**LBS\_NOREDRAW**não é atualizada quando são feitas alterações.  Esse estilo pode ser alterado a qualquer momento enviando uma mensagem de **WM\_SETREDRAW** .  
  
-   **LBS\_NOSEL** especifica que a caixa de listagem contém os itens que podem ser exibidos mas não selecionado.  
  
-   A janela pai de**LBS\_NOTIFY**recebe uma mensagem de entrada sempre que o usuário clica em ou clique duas vezes em uma cadeia de caracteres.  
  
-   **LBS\_OWNERDRAWFIXED** o proprietário da caixa de listagem é responsável para desenhar seu conteúdo; os itens na caixa de listagem têm a mesma altura.  
  
-   **LBS\_OWNERDRAWVARIABLE** o proprietário da caixa de listagem é responsável para desenhar seu conteúdo; os itens na caixa de listagem são variáveis no momento.  
  
-   As cadeias de caracteres de**LBS\_SORT**na caixa de listagem são classificadas em ordem alfabética.  
  
-   As cadeias de caracteres de**LBS\_STANDARD**na caixa de listagem são classificadas em ordem alfabética, e a janela pai recebe uma mensagem de entrada sempre que o usuário clica em ou clique duas vezes em uma cadeia de caracteres.  A caixa de listagem contém bordas por todos os lados.  
  
-   **LBS\_USETABSTOPS** permite que uma caixa de listagem reconheça e expanda caracteres de tabulação para desenhar as cadeias de caracteres.  As posições da guia padrão são 32 unidades da caixa de diálogo. \(A unidade da caixa de diálogo é a distância horizontal ou vertical.  Uma unidade horizontal da caixa de diálogo é igual a um quarto de unidade atual da largura da base da caixa de diálogo.  As unidades de base da caixa de diálogo são computadas com base na altura e a largura da fonte atual do sistema.  A função do windows de **GetDialogBaseUnits** retorna as unidades de base da caixa de diálogo atual em pixels.\) Esse estilo não deve ser usado com **LBS\_OWNERDRAWFIXED**.  
  
-   **LBS\_WANTKEYBOARDINPUT** o proprietário da caixa de listagem `WM_VKEYTOITEM` ou recebe mensagens de `WM_CHARTOITEM` sempre que o usuário digite uma chave quando a caixa de listagem entre o foco.  Isso permite que um aplicativo execute um processamento especial na entrada de teclado.  
  
## Consulte também  
 [Estilos usados pelo MFC](../../mfc/reference/styles-used-by-mfc.md)   
 [CListBox::Create](../Topic/CListBox::Create.md)   
 [List Box Styles](http://msdn.microsoft.com/library/windows/desktop/bb775149)