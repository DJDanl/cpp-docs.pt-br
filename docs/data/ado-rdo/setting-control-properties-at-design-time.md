---
title: "Definindo propriedades de controle na hora do design | Microsoft Docs"
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
  - "Controles ActiveX [C++], propriedades"
ms.assetid: 963bf498-d371-4cfd-8bed-865427dcfad9
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Definindo propriedades de controle na hora do design
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As propriedades dos controles podem ser definidas em tempo de design usando o editor da caixa de diálogo.  Quando você define uma propriedade, o editor de recurso inicializar o controle com o valor especificado.  A propriedade ainda pode ser modificada programaticamente.  
  
 A propriedade de **DataSource** , que é encontrada em qualquer [controles vinculadas a dados](../../data/ado-rdo/databinding-with-activex-controls-in-visual-cpp.md), permite especificar o controle de [fonte de dados](../../data/ado-rdo/databinding-with-activex-controls-in-visual-cpp.md) a qual deseja associar.  
  
 Ao associar controles vinculadas a dados associados simples ADO a um controle de dados ADO \(ADODC\), você deve associar o controle com uma coluna definindo a propriedade de **DataField** a um campo válido no conjunto de linhas.  Caso contrário, o aplicativo compilado afirma em uma compilação de depuração \(a asserção de pontuação está simplesmente porque o controle esteve associado a uma coluna nula\).  
  
> [!NOTE]
>  A guia propriedades de **Geral** permite que você especifique um identificador de controle e outras propriedades necessárias para o .rc arquivo. \(O arquivo de .rc é um criado posteriormente para gerar um código do recurso de programa do windows\).  
  
### Para definir uma propriedade na guia tudo  
  
1.  [Inserir um controle ActiveX](../../data/ado-rdo/inserting-the-control-into-a-visual-cpp-application.md) em uma caixa de diálogo.  
  
2.  Clique com o botão direito do mouse no controle no publicador da caixa de diálogo, clique em **Propriedades**.  
  
3.  Clique na guia de **Tudo** para exibir as propriedades do controle.  Para uma determinada propriedade, digite o valor de inicialização.  
  
 Para definir propriedades em tempo de execução de controle, consulte [Alterando o comportamento de tempo de execução de um controle](../../data/ado-rdo/modifying-a-control-s-run-time-behavior.md).  
  
## Consulte também  
 [Usando controles ActiveX](../Topic/Using%20ActiveX%20Controls.md)