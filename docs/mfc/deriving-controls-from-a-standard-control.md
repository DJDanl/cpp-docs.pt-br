---
title: "Derivando controles a partir de um controle padr&#227;o | Microsoft Docs"
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
  - "controles comuns [C++], derivando de"
  - "controles [MFC], derivado"
  - "controles derivados"
  - "controles padrão"
  - "controles padrão, derivando controles de"
  - "controles comuns do Windows [C++], derivando de"
ms.assetid: a6f84315-7007-4e0e-8576-78be81254802
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Derivando controles a partir de um controle padr&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Como com qualquer [CWnd](../Topic/CWnd%20Class.md)\- classe derivada, você pode alterar o comportamento de controle com uma nova classe de uma classe existente do controle.  
  
### Para criar uma classe derivada de controle  
  
1.  Derivar a sua classe de uma classe existente de controle e substituir opcionalmente a função de membro de **Criar** de modo que forneça os argumentos necessários à função de **Criar** da classe base.  
  
2.  Fornecer funções de membro retornadas a e entradas retornadas mapa para alterar o comportamento de controle em resposta a mensagens específicas do windows.  Consulte [Mensagens de mapeamento a funções](../Topic/Mapping%20Messages%20to%20Functions.md).  
  
3.  Fornecer novas funções de membro para estender a funcionalidade de controle \(opcional\).  
  
 Usar um controle derivada em uma caixa de diálogo requer o trabalho adicional.  Os tipos e as posições dos controles em uma caixa de diálogo são especificados normalmente em um recurso de diálogo\- modelo.  Se você criar uma classe derivada de controle, você não poderá especificá\-la em um modelo da caixa de diálogo desde que o compilador de recursos não conhece nada sobre sua classe derivada.  
  
#### Para colocar o controle derivada em uma caixa de diálogo  
  
1.  Inserir um objeto de classe derivada de controle na declaração da sua classe derivada da caixa de diálogo.  
  
2.  Substitua a função de membro de `OnInitDialog` em sua classe da caixa de diálogo para chamar a função de membro de `SubclassDlgItem` para o controle derivada.  
  
 subclasses de`SubclassDlgItem` “” dinamicamente um controle criado de um modelo da caixa de diálogo.  Quando um controle subclassed dinamicamente, você engancha no windows, processa algumas mensagens em seu próprio aplicativo, então passa as outras mensagens sobre como windows.  Para obter mais informações, veja a função de membro de [SubclassDlgItem](../Topic/CWnd::SubclassDlgItem.md) da classe `CWnd`*na referência de MFC*.  O exemplo a seguir mostra como você pode escrever uma substituição de `OnInitDialog` para chamar `SubclassDlgItem`:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#3](../mfc/codesnippet/CPP/deriving-controls-from-a-standard-control_1.cpp)]  
  
 Como o controle derivada é inserido na classe da caixa de diálogo, será construído quando a caixa de diálogo é construída, e será destruída quando a caixa de diálogo é destruída.  Compare esse código no exemplo em [Adicionando controles a mão](../mfc/adding-controls-by-hand.md).  
  
## Consulte também  
 [Criando e usando controles](../mfc/making-and-using-controls.md)   
 [Controles](../mfc/controls-mfc.md)