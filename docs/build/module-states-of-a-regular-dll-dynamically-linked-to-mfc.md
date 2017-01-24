---
title: "Estados de m&#243;dulo de uma DLL regular vinculada dinamicamente ao MFC | Microsoft Docs"
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
  - "DLLs [C++], estados de módulo"
  - "DLLs MFC [C++], DLLs regulares"
  - "estados de módulo [C++]"
  - "estados de módulo [C++], DLLs regulares vinculadas dinamicamente a"
  - "DLLs regulares [C++], vinculadas dinamicamente a MFC"
ms.assetid: b4493e79-d25e-4b7f-a565-60de5b32c723
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Estados de m&#243;dulo de uma DLL regular vinculada dinamicamente ao MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A capacidade de vincular dinamicamente uma DLL normal para a DLL MFC permite algumas configurações que são muito complexas.  Por exemplo, uma DLL normal e o executável que usa que pode vincular dinamicamente para a DLL MFC e a todas as dlls de extensão.  
  
 Essa configuração gerencie um problema com relação aos dados globais MFC, como o ponteiro mapas atuais dos objetos e de `CWinApp` .  
  
 Antes da versão 4,0 MFC, esses dados globais resididos na DLL próprio MFC e foram compartilhados por todos os módulos no processo.  Como cada processo que usa uma DLL do Win32 obtém sua própria cópia dos dados da DLL, esse esquema fornece uma maneira fácil de localizar dados do processo.  Além disso, como os AFXDLL modelagem presumido que não apenas um objeto de `CWinApp` e apenas um conjunto de mapas do identificador do processo, esses itens podem ser controlados na DLL próprio MFC.  
  
 Mas com a capacidade de vincular dinamicamente uma DLL normal para a DLL MFC, agora é possível ter dois ou mais objetos de `CWinApp` em um processo — e também dois ou mais conjuntos de mapas do identificador.  Como o MFC se mantém a qual par deve usar?  
  
 A solução é dar a cada módulo \(aplicativo ou DLL comum\) sua própria cópia dessas informações de estado global.  Assim, uma chamada a **AfxGetApp** na DLL normal retorna um ponteiro para o objeto de `CWinApp` na DLL, não nesse executável.  Essa cópia do módulo de dados globais MFC é conhecida como um estado de módulo e descrita em [Observação 58 da tecnologia de MFC](../mfc/tn058-mfc-module-state-implementation.md).  
  
 As opções comuns do procedimento da janela de MFC automaticamente para o estado correto do módulo, a você não precisa se preocupar sobre ele nos manipuladores de mensagem implementada no DLL normal.  Mas quando seus chamadas do executável na DLL normal, é necessário definir explicitamente o estado atual do módulo ao para a DLL.  Para fazer isso, use a macro de **AFX\_MANAGE\_STATE** em cada função exportada da DLL.  Isso é feito adicionando a seguinte linha de código ao início das funções exportadas da DLL:  
  
```  
AFX_MANAGE_STATE(AfxGetStaticModuleState( ))  
```  
  
## Que você deseja saber mais?  
  
-   [Gerenciando os dados do estado dos módulos de MFC](../mfc/managing-the-state-data-of-mfc-modules.md)  
  
-   [DLL normais vinculadas dinamicamente ao MFC](../Topic/Regular%20DLLs%20Dynamically%20Linked%20to%20MFC.md)  
  
-   [DLLs de Extensão](../build/extension-dlls-overview.md)  
  
## Consulte também  
 [DLLs no Visual C\+\+](../build/dlls-in-visual-cpp.md)