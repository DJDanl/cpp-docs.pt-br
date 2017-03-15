---
title: "Adicionando colunas ao controle (exibi&#231;&#227;o de relat&#243;rio) | Microsoft Docs"
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
  - "Classe CListCtrl, adicionando colunas"
  - "Classe CListCtrl, exibição de relatório"
  - "colunas [C++], adicionando a CListCtrl"
  - "exibição de relatório na classe CListCtrl"
  - "modos de exibição, relatório"
ms.assetid: 7392c0d7-f8a5-4e7b-9ae7-b53dc9dd80ae
caps.latest.revision: 12
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Adicionando colunas ao controle (exibi&#231;&#227;o de relat&#243;rio)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  O procedimento a seguir se aplica a [CListView](../mfc/reference/clistview-class.md) ou o objeto de [CListCtrl](../Topic/CListCtrl%20Class.md) .  
  
 Quando um controle da lista estiver na exibição do relatório, as colunas são exibidas, fornecendo um método de organizar os vários subitens de cada item do controle da lista.  Esse arranjo é implementada com uma correspondência um\-para\-um entre uma coluna no controle da lista e o subitem associado do item do controle da lista.  Para obter mais informações sobre os subitens, consulte [Adicionando itens com controle](../mfc/adding-items-to-the-control.md).  Um exemplo de um controle da lista na visualização de relatório é fornecido pela exibição de detalhes no Windows 95 e no Windows Explorer 98.  As primeiras listas de colunas pasta, ícones do arquivo, e rótulos.  Outras colunas listam o tamanho do arquivo, tipo de arquivo, modificou de data, e assim por diante.  
  
 Mesmo que as colunas possam ser adicionadas a um controle de lista a qualquer momento, as colunas são visíveis apenas quando o controle que tem o estilo de `LVS_REPORT` bit ativado.  
  
 Cada coluna tem um objeto associado ao item de cabeçalho \(consulte\) [CHeaderCtrl](../Topic/CHeaderCtrl%20Class.md)que deve ser evitada para a coluna e permite que os usuários redimensionem a coluna.  
  
 Se o controle da lista da suporte a uma visualização de relatório, você precisa adicionar uma coluna para cada subitem possível em um item de controle da lista.  Adicionar uma coluna preparando uma estrutura de [LV\_COLUMN](http://msdn.microsoft.com/library/windows/desktop/bb774743) e depois fazendo uma chamada a [InsertColumn](../Topic/CListCtrl::InsertColumn.md).  Depois de adicionar as colunas necessárias \(às vezes referenciado como itens de cabeçalho\), você pode reorganizar\-los que usam as funções de membro e os estilos que pertencem ao controle de cabeçalho inserido.  Para obter mais informações, consulte [Classificando itens no controle de cabeçalho](../mfc/ordering-items-in-the-header-control.md).  
  
> [!NOTE]
>  Se o controle da lista é criado com o estilo de **LVS\_NOCOLUMNHEADER** , qualquer tentativa de inserir colunas será ignorada.  
  
## Consulte também  
 [Usando CListCtrl](../Topic/Using%20CListCtrl.md)   
 [Controles](../mfc/controls-mfc.md)