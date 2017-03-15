---
title: "Definindo as imagens para um item individual | Microsoft Docs"
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
  - "caixas de combinação estendidas, imagens"
  - "imagens [C++], itens de caixa de combinação"
ms.assetid: bde83db8-23a7-4e35-837a-c86447d2c0af
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Definindo as imagens para um item individual
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os tipos diferentes de imagens usadas pelo item estendido da caixa de combinação são determinados pelos valores em `iImage`, em **iSelectedImage**, e em membros de **iOverlay** da estrutura de [COMBOBOXEXITEM](http://msdn.microsoft.com/library/windows/desktop/bb775746) .  Cada valor é o índice de uma imagem associado na lista da imagem do controle.  Por padrão, esses membros são definidos como 0, fazendo com que o controle não exibe nenhuma imagem para o item.  Se você quiser usar imagens para um item específico, você pode alterar a estrutura dessa forma, qualquer uma ao inserir o item da caixa de combinação ou alterando um item existente na caixa de combinação.  
  
## Definindo a imagem para um novo item  
 Se você estiver inserindo um novo item, inicializar `iImage`, **iSelectedImage**, e membros da estrutura de **iOverlay** com os valores apropriados e insira o item com uma chamada a [CComboBoxEx::InsertItem](../Topic/CComboBoxEx::InsertItem.md).  
  
 O exemplo a seguir insere um novo item estendido da caixa de combinação`cbi`\(\) no controle estendido da caixa de combinação`m_comboEx`\(\), fornecendo índices para todos os três estados de imagem:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#12](../mfc/codesnippet/CPP/setting-the-images-for-an-individual-item_1.cpp)]  
  
## Definindo a imagem para um item existente  
 Se você estiver alterando um item existente, você precisar trabalhar com o membro de **mask** de uma estrutura de **COMBOBOXEXITEM** .  
  
#### Para alterar um item existente para usar imagens  
  
1.  Declare uma estrutura de **COMBOBOXEXITEM** e define o membro de dados de **mask** aos valores que você está interessado na alteração.  
  
2.  Usando essa estrutura, chame um a [CComboBoxEx::GetItem](../Topic/CComboBoxEx::GetItem.md).  
  
3.  Modifique **mask**, `iImage`, e membros de **iSelectedImage** da estrutura recentemente retornada, usando os valores apropriados.  
  
4.  Chame um a [CComboBoxEx::SetItem](../Topic/CComboBoxEx::SetItem.md), passando na estrutura alterada.  
  
 O exemplo a seguir demonstra esse procedimento alternando as imagens selecionadas e não selecionada do terceiro item estendido da caixa de combinação:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#13](../mfc/codesnippet/CPP/setting-the-images-for-an-individual-item_2.cpp)]  
  
## Consulte também  
 [Usando CComboBoxEx](../mfc/using-ccomboboxex.md)   
 [Controles](../mfc/controls-mfc.md)