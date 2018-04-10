---
title: Estados de módulo de uma DLL MFC Regular vinculada dinamicamente ao MFC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-tools
ms.tgt_pltfrm: ''
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- regular MFC DLLs [C++], dynamically linked to MFC
- module states [C++]
- MFC DLLs [C++], regular MFC DLLs
- module states [C++], regular MFC DLLs dynamically linked to
- DLLs [C++], module states
ms.assetid: b4493e79-d25e-4b7f-a565-60de5b32c723
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 8b88f895255c698f04b6988e63b8b75372fa59b0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="module-states-of-a-regular-mfc-dll-dynamically-linked-to-mfc"></a>Estados de módulo de uma DLL MFC Regular vinculada dinamicamente ao MFC
A capacidade de vincular dinamicamente uma DLL MFC regular para a DLL do MFC permite que algumas configurações que são muito complicadas. Por exemplo, uma DLL MFC regular e o executável que usa podem ambos dinamicamente vincular a DLL do MFC e qualquer extensão de MFC.  
  
 Esta configuração representa um problema com relação aos dados globais MFC, como o ponteiro para o atual `CWinApp` mapas de identificador de objeto.  
  
 Antes de MFC versão 4.0, esses dados globais da DLL do MFC e foi compartilhados por todos os módulos no processo. Como cada processo usando uma DLL Win32 obtém sua própria cópia dos dados da DLL, esse esquema fornecidas uma maneira fácil de controlar os dados por processo. Além disso, porque o modelo AFXDLL presume que deveria haver apenas um `CWinApp` mapas no processo de identificador de objeto e apenas um conjunto de, esses itens podem ser controlados na DLL do MFC.  
  
 Mas com a capacidade de vincular dinamicamente uma DLL MFC regular para a DLL do MFC, é possível ter dois ou mais `CWinApp` objetos em um processo e também dois ou mais conjuntos de mapas de identificador. Como MFC manter o controle de quais devem usar?  
  
 A solução é fornecer sua própria cópia dessas informações de estado global de cada módulo (aplicativo ou DLL MFC regular). Portanto, uma chamada para **AfxGetApp** comum DLL MFC retorna um ponteiro para o `CWinApp` objeto na DLL, não aquele do executável. Esta cópia por módulo dos dados globais MFC é conhecida como um estado de módulo e é descrita na [MFC Tech Observação 58](../mfc/tn058-mfc-module-state-implementation.md).  
  
 O procedimento de janela comuns MFC alterna automaticamente para o estado do módulo correto, e não será necessário se preocupar em qualquer manipuladores de mensagens implementadas no DLL normais do MFC. Mas quando o executável chama a DLL do MFC regular, você precisa definir explicitamente o estado atual do módulo para o outro para a DLL. Para fazer isso, use o **AFX_MANAGE_STATE** macro em todas as funções exportadas da DLL. Isso é feito adicionando a seguinte linha de código para o início da função DLL exportada:  
  
```  
AFX_MANAGE_STATE(AfxGetStaticModuleState( ))  
```  
  
## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
  
-   [Gerenciando os dados de estado dos módulos MFC](../mfc/managing-the-state-data-of-mfc-modules.md)  
  
-   [DLLs MFC regulares vinculadas dinamicamente a MFC](../build/regular-dlls-dynamically-linked-to-mfc.md)  
  
-   [DLLs de extensão de MFC](../build/extension-dlls-overview.md)  
  
## <a name="see-also"></a>Consulte também  
 [DLLs no Visual C++](../build/dlls-in-visual-cpp.md)