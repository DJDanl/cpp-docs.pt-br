---
title: "Troca de dados da caixa de di&#225;logo | Microsoft Docs"
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
  - "cancelamento de troca de dados"
  - "capturando entrada de usuário"
  - "Classe CDataExchange, usando DDX"
  - "DDX (troca de dados da caixa de diálogo), cancelando"
  - "DDX (troca de dados da caixa de diálogo), mecanismo de troca de dados"
  - "dados de caixa de diálogo"
  - "dados de caixa de diálogo, recuperando"
  - "caixas de diálogo, troca de dados"
  - "caixas de diálogo, inicializando"
  - "caixas de diálogo, recuperando entrada de usuário usando DDX"
  - "Método DoDataExchange"
  - "inicializando caixas de diálogo"
  - "recuperando dados de caixa de diálogo"
  - "transferindo dados de caixa de diálogo"
  - "Método UpdateData"
  - "entrada do usuário, recuperando a partir de caixas de diálogo MFC"
ms.assetid: 4675f63b-41d2-45ed-b6c3-235ad8ab924b
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Troca de dados da caixa de di&#225;logo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Se você usar o mecanismo de DDX, defina os valores iniciais de variáveis do membro do objeto da caixa de diálogo, normalmente no manipulador de `OnInitDialog` ou no construtor da caixa de diálogo.  Imediatamente antes da caixa de diálogo for exibida, o mecanismo de DDX da estrutura transfere os valores de variáveis de membro nos controles na caixa de diálogo, onde aparecem quando a própria caixa de diálogo aparece em resposta a `DoModal` ou a **Criar**.  A implementação padrão de `OnInitDialog` em `CDialog` chama a função de membro de `UpdateData` da classe `CWnd` para inicializar os controles na caixa de diálogo.  
  
 O mesmo mecanismo transfere valores dos controles para variáveis de membro quando o usuário clicar no botão OK \(ou sempre que chama a função de membro de `UpdateData` com o argumento **Verdadeiro**\).  O mecanismo de validação de dados na caixa de diálogo valida todos os itens de dados para você especificar as regras de validação.  
  
 A figura a seguir ilustra a caixa de diálogo de troca de dados.  
  
 ![Troca de dados do diálogo](../mfc/media/vc379d1.png "vc379D1")  
Caixa de diálogo de troca de dados  
  
 trabalho de`UpdateData` em ambas as direções, conforme especificado pelo parâmetro de **BOOL** transmitido a ele.  Para realizar a troca, os conjuntos de `UpdateData` \- acima de um objeto de `CDataExchange` e chama a substituição da sua classe da caixa de diálogo da função de membro de `CDialog``DoDataExchange` .  `DoDataExchange` usa um argumento do tipo `CDataExchange`.  O objeto de `CDataExchange` passado a `UpdateData` representa o contexto de troca, definindo informações como a direção de troca.  
  
 Quando você \(ou um assistente do código\) substituem `DoDataExchange`, você especifica uma chamada a uma função de DDX pelo membro de dados \(controle\).  Cada função de DDX sabe para trocar dados em ambas as direções com base no contexto fornecido pelo argumento de `CDataExchange` passado ao `DoDataExchange` por `UpdateData`.  
  
 MFC O fornece muitas funções de DDX para diferentes tipos de troca.  O exemplo a seguir mostra uma substituição de `DoDataExchange` no qual duas funções de DDX e uma função de DDV são chamadas:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#49](../mfc/codesnippet/CPP/dialog-data-exchange_1.cpp)]  
  
 As linhas de `DDX_` e de `DDV_` são um mapa de dados.  O exemplo DDX e funções de DDV são mostradas para um controle da caixa de seleção e um controle da caixa de edição, respectivamente.  
  
 Se o usuário cancelar uma caixa de diálogo modal, a função de membro de `OnCancel` finaliza a caixa de diálogo e `DoModal` retorna o valor **IDCANCEL**.  Nesse caso, os dados não são trocados entre a caixa de diálogo e o objeto da caixa de diálogo.  
  
## Consulte também  
 [Troca de dados da caixa de diálogo e validação](../mfc/dialog-data-exchange-and-validation.md)   
 [Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)   
 [Validação dos dados da caixa de diálogo](../mfc/dialog-data-validation.md)