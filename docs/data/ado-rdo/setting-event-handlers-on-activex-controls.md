---
title: "Definindo manipuladores de evento em controles ActiveX | Microsoft Docs"
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
  - "Controles ActiveX [C++], eventos"
  - "eventos [C++], Controles ActiveX"
ms.assetid: c076386f-c78b-4dc9-9201-a544252d5337
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Definindo manipuladores de evento em controles ActiveX
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Os controles ActiveX podem ser programado para responder a eventos.  Você pode usar **ControlEvents** nas propriedades para exibir os eventos que estão disponíveis em um controle e para criar manipuladores de eventos.  A manipulação de eventos está normalmente feita a mudanças de armadilha na consulta de fonte de dados.  As modificações incluem:  
  
-   Implementando uma pesquisa.  Quando um valor do controle de alterações \(como uma caixa de DBCombo\), o evento de alteração é interceptado para atualizar a consulta de um controle de dados.  
  
-   Implementando uma relação mestre de detalhes.  Dois controles de dados são adicionados a uma caixa de diálogo, uma para a parte mestre e um segundo para a parte de detalhes.  Sempre que a primeira fonte de dados for alterada, a segunda consulta da fonte de dados é atualizada por meio de um manipulador de eventos.  
  
-   Erros de ajuste de registro.  A maioria dos controles têm um evento de erro que você pode escrever um manipulador de erros \(consulte [Ajuste de registro de erro](../../data/ado-rdo/error-trapping.md)\).  
  
 Para obter mais informações, consulte [Mensagens de mapeamento a funções](../Topic/Mapping%20Messages%20to%20Functions.md).  
  
## Consulte também  
 [Usando controles ActiveX](../Topic/Using%20ActiveX%20Controls.md)