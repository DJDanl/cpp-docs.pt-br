---
title: "Declarando uma vari&#225;vel com base na nova classe de controle | Microsoft Docs"
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
  - "vc.codewiz.classes.control.variable"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "classes [C++], declarando variáveis com base em"
  - "classes de controle, variáveis"
  - "variáveis, classes de controle"
ms.assetid: 5722dc38-c0eb-40bd-93da-67a808140d03
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Declarando uma vari&#225;vel com base na nova classe de controle
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Depois que você tiver criado uma classe de controle de MFC, você pode declarar uma variável com base nele.  Para fornecer um contexto para a nova variável, você deve abrir o editor da caixa de diálogo e editar a caixa de diálogo na qual você deseja usar o controle reutilizável.  Além disso, a caixa de diálogo já deve ter uma classe associada a ela.  Para obter informações sobre como usar o editor da caixa de diálogo, consulte [Editor da caixa de diálogo](../../mfc/dialog-editor.md).  
  
### Para declarar uma variável com base em sua classe reutilizável  
  
1.  Ao editar a caixa de diálogo, arraste um controle do mesmo tipo que a classe base de seu novo controle da barra de ferramentas dos controles na caixa de diálogo.  
  
2.  Coloque o ponteiro sobre o controle removido.  
  
3.  Ao pressionar a tecla CTRL, clique duas vezes no controle.  
  
     A caixa de diálogo de [Adicione a variável de membro](../../ide/add-member-variable-wizard.md) é exibida.  
  
4.  Na caixa de **Acesso** , selecione o acesso correto para o controle.  
  
5.  Clique na caixa de seleção de **Control variable** .  
  
6.  Na caixa de **Nome da variável** , digite um nome.  
  
7.  Em **Categoria**, clique em **Controle**.  
  
8.  Na lista de **ID de Controle** , escolha o controle que você adicionou.  A lista de **Tipo de variável** deve exibir o tipo variável correto, e a caixa de **Tipo de controle** deve exibir o tipo correto do controle.  
  
9. Na caixa de **Comentário** , adicione o comentário que você deseja exibir em seu código.  
  
10. Clique em **OK**.  
  
## Consulte também  
 [Mapeando mensagens para funções](../Topic/Mapping%20Messages%20to%20Functions.md)   
 [Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)   
 [Adicionando uma classe](../Topic/Adding%20a%20Class%20\(Visual%20C++\).md)   
 [Adicionando uma função de membro](../../ide/adding-a-member-function-visual-cpp.md)   
 [Adicionando uma variável de membro](../../ide/adding-a-member-variable-visual-cpp.md)   
 [Substituindo uma função virtual](../Topic/Overriding%20a%20Virtual%20Function%20\(Visual%20C++\).md)   
 [Manipulador de mensagens do MFC](../../mfc/reference/adding-an-mfc-message-handler.md)   
 [Navegando na estrutura da classe](../../ide/navigating-the-class-structure-visual-cpp.md)