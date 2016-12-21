---
title: "Controles de lista virtuais | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
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
  - "cache, dados de item de controle de lista virtual"
  - "controles de lista, Exibição de lista"
  - "controles de lista, virtual"
  - "controles de lista virtual"
ms.assetid: 319f841f-e426-423a-8276-d93f965b0b45
caps.latest.revision: 13
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Controles de lista virtuais
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um controle virtual da lista é um controle de exibição de lista que tenha o estilo de **LVS\_OWNERDATA** .  Esse estilo habilita o controle para oferecer suporte a uma contagem de itens até `DWORD` \(a contagem padrão do item estende apenas a `int`\).  No entanto, a vantagem a maior fornecida por este estilo é a capacidade de ter somente um subconjunto de itens de dados na memória a qualquer momento.  Isso permite que o controle virtual de exibição de lista empreste\-se para uso com grandes bases de dados de informações, onde os métodos específicos de acessar dados já estão em vigor.  
  
> [!NOTE]
>  Além de fornecer funcionalidade virtual da lista em `CListCtrl`, MFC o também fornece a mesma funcionalidade na classe de [CListView](../mfc/reference/clistview-class.md) .  
  
 Há alguns problemas de compatibilidade você deve estar ciente da o desenvolver controles virtuais na lista.  Para obter mais informações, consulte a seção de problemas de compatibilidade de exibição de lista controla o tópico em [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)].  
  
## Tratando a notificação de LVN\_GETDISPINFO  
 Os controles virtuais na lista mantêm as informações muito pequena do item.  Com exceção de seleção do item e informações de foco, todas as informações de item é gerenciada pelo proprietário do controle.  As informações são solicitadas pela estrutura por meio de uma notificação de **LVN\_GETDISPINFO** .  Para fornecer as informações solicitadas, o proprietário do controle virtual de listas \(ou o próprio controle\) devem lidar com essa notificação.  Isso pode ser feita facilmente usando a janela Propriedades \(consulte [Mensagens de mapeamento a funções](../Topic/Mapping%20Messages%20to%20Functions.md)\).  O código resultante deve ser algo como no exemplo a seguir \(onde `CMyDialog` possui o objeto virtual do controle da lista e a caixa de diálogo está executando a notificação\):  
  
 [!code-cpp[NVC_MFCControlLadenDialog#23](../mfc/codesnippet/CPP/virtual-list-controls_1.cpp)]  
  
 No manipulador para a notificação de **LVN\_GETDISPINFO** , você deve verificar quais tipo de informação está sendo solicitado.  Os valores possíveis são:  
  
-   `LVIF_TEXT` o membro de `pszText` deve ser preenchida.  
  
-   `LVIF_IMAGE` o membro de `iImage` deve ser preenchida.  
  
-   **LVIF\_INDENT** o membro *iIndent* deve ser preenchida.  
  
-   `LVIF_PARAM` o membro *de lParam* deve ser preenchida. \(Não presentes para sub\-elementos.\)  
  
-   `LVIF_STATE` o membro *de estado* deve ser preenchida.  
  
 Você deve fornecer o qual as informações são solicitadas novamente a estrutura.  
  
 O exemplo a seguir \(obtido do corpo do manipulador de notificação para o objeto control\) da lista a seguir demonstra um método possível fornecendo informações para os buffers de texto e a imagem de um item:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#24](../mfc/codesnippet/CPP/virtual-list-controls_2.cpp)]  
  
## Armazenar em cachê e controles virtuais de lista  
 Como esse tipo de controle da lista é planejado para grandes conjuntos de dados, é recomendado que você armazena em cachê os dados de item para melhorar o desempenho de recuperação.  A estrutura fornece um mecanismo de sugestão para facilitar em otimizar o cache enviando uma notificação de **LVN\_ODCACHEHINT** .  
  
 O exemplo a seguir atualiza o cache com o intervalo passada para a função do manipulador.  
  
 [!code-cpp[NVC_MFCControlLadenDialog#25](../mfc/codesnippet/CPP/virtual-list-controls_3.cpp)]  
  
 Para obter mais informações sobre como preparar e manter um cache, consulte a seção de gerenciamento do cache do tópico de controles de exibição de lista em [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)].  
  
## Localizando itens específicos  
 A notificação de **LVN\_ODFINDITEM** será enviada pelo controle virtual da lista quando um item específico do controle da lista precisa ser localizado.  A notificação é enviada quando o controle de exibição de lista recebe acesso rápido chave ou quando o recebe uma mensagem de **LVM\_FINDITEM** .  Informações de Pesquisa é enviada na forma de uma estrutura de **LVFINDINFO** , que é um membro da estrutura de **NMLVFINDITEM** .  Para controlar essa mensagem substituindo a função de `OnChildNotify` de seu objeto e interior do controle de lista o corpo do manipulador, marque para a mensagem de **LVN\_ODFINDITEM** .  Se for localizado, execute a ação adequada.  
  
 Você deve estar preparado para procurar um item que corresponde a informações de determinada pelo controle de exibição de lista.  Você deve retornar o índice do item, se com êxito ou \-1 se nenhum item correspondente é encontrado.  
  
## Consulte também  
 [Usando CListCtrl](../Topic/Using%20CListCtrl.md)   
 [Controles](../mfc/controls-mfc.md)