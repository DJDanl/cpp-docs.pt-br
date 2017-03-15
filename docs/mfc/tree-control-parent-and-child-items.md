---
title: "Itens pai e filho do controle de &#225;rvore | Microsoft Docs"
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
  - "itens filho no controle de árvore"
  - "Classe CTreeCtrl, itens pai e filho"
  - "Itens pai em CTreeCtrl"
  - "controles em árvore, itens pai e filho"
ms.assetid: abcea1e4-fe9b-40d9-86dc-1db235f8f103
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Itens pai e filho do controle de &#225;rvore
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Qualquer item em um controle de árvore[CTreeCtrl](../mfc/reference/ctreectrl-class.md)\(\) pode ter uma lista de subitens, que são chamadas de itens filho, associada a ele.  Um item que tem um ou mais itens filho é chamado um item pai.  Um item filho é exibida abaixo de seu item pai e recuado para indicar que está subordinado ao pai.  Um item que não tem nenhum pai está no topo da hierarquia e é chamado um item raiz.  
  
 Em um determinado momento, o estado da lista pai de um item de itens filho pode ser expandido ou recolhido.  Quando o estado é expandido, os itens filhos são exibidos abaixo do item pai.  Quando for recolhido, os itens filhos não serão exibidos.  Na lista as alternâncias automaticamente entre os estados expandidos e recolhidos quando o usuário clicar duas vezes no item pai ou, se o pai possui o estilo de **TVS\_HASBUTTONS** , quando o usuário clicar no botão associado ao item pai.  Um aplicativo pode expandir ou recolher os itens filho usando a função de membro de [Expanda](../Topic/CTreeCtrl::Expand.md) .  
  
 Você adiciona um item a um controle de árvore chamando a função de membro de [InsertItem](../Topic/CTreeCtrl::InsertItem.md) .  Essa função retorna um identificador do tipo de **HTREEITEM** , que identifica exclusivamente o item.  Ao adicionar um item, você deve especificar o identificador do item pai do novo item.  Se você especificar **nulo** ou o valor de **TVI\_ROOT** em vez de um identificador pai do item na estrutura de [TVINSERTSTRUCT](http://msdn.microsoft.com/library/windows/desktop/bb773452) ou o parâmetro de `hParent` , o item será adicionado como um item raiz.  
  
 Um controle de árvore envia uma notificação de [TVN\_ITEMEXPANDING](http://msdn.microsoft.com/library/windows/desktop/bb773537) quando a lista pai de um item de itens filho está prestes a ser expandida ou recolhido.  A notificação a oportunidade de evitar a modificação ou de definir quaisquer atributos do item pai que dependa do estado da lista de itens filho.  Após alterar o estado da lista, o controle de árvore envia uma notificação de [TVN\_ITEMEXPANDED](http://msdn.microsoft.com/library/windows/desktop/bb773533) .  
  
 Quando uma lista de itens filho é expandida, é recuada relativo para o item pai.  Você pode definir a quantidade de recuo usando a função de membro de [SetIndent](../Topic/CTreeCtrl::SetIndent.md) ou recuperar a quantidade atual usando a função de membro de [GetIndent](../Topic/CTreeCtrl::GetIndent.md) .  
  
## Consulte também  
 [Usando CTreeCtrl](../Topic/Using%20CTreeCtrl.md)   
 [Controles](../mfc/controls-mfc.md)