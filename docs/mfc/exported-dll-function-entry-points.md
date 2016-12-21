---
title: "Pontos de entrada da fun&#231;&#227;o DLL exportada | Microsoft Docs"
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
  - "exportando DLLs, Funções "
  - "MFC, gerenciando dados de estado"
  - "gerenciamento de estado, DLLs exportadas"
ms.assetid: 3268666e-d24b-44f2-80e8-7c80f73b93ca
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Pontos de entrada da fun&#231;&#227;o DLL exportada
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Para funções exportadas de uma DLL, use a macro de [AFX\_MANAGE\_STATE](../Topic/AFX_MANAGE_STATE.md) para manter o estado global apropriada ao alternar do módulo DLL para a DLL do aplicativo de chamada.  
  
 Quando chamado, esta macro define `pModuleState`, um ponteiro para uma estrutura de `AFX_MODULE_STATE` que contém dados globais para o módulo, como o estado efetiva de módulo para o restante do escopo de conteúdo da função.  Em cima de deixar o escopo que contém a macro, o estado anterior efetivo do módulo é restaurado automaticamente.  
  
 Essa alternância é obtida construindo uma instância de uma classe de **AFX\_MODULE\_STATE** na pilha.  No construtor, esta classe obtém um ponteiro para o estado atual do módulo e armazenado em uma variável de membro, e defina\-a como `pModuleState` o novo estado efetivo do módulo.  No destruidor, essa classe restaura o ponteiro armazenado em sua variável de membro como o estado efetivo do módulo.  
  
 Se você tiver uma função exportada, como uma iniciando uma caixa de diálogo no DLL, adicione o seguinte código para o início da função:  
  
 [!code-cpp[NVC_MFCConnectionPoints#6](../mfc/codesnippet/CPP/exported-dll-function-entry-points_1.cpp)]  
  
 Isso alterna o estado atual do módulo com o estado retornado de [AfxGetStaticModuleState](../Topic/AfxGetStaticModuleState.md) até o final do escopo atual.  
  
 Os problemas com recursos na DLL ocorrerão se a macro de `AFX_MANAGE_STATE` não é usado.  Por padrão, o MFC usa o identificador de recurso de aplicativo principal carregar o modelo de recursos.  Esse modelo é armazenado no DLL.  A causa raiz é que as informações de estado do módulo MFC não esteve alternada pela macro de `AFX_MANAGE_STATE` .  O identificador de recurso são recuperadas do estado do módulo MFC.  Não alternar o estado do módulo faz com que a alça incorreta do recurso a ser usada.  
  
 `AFX_MANAGE_STATE` não precisa ser colocado em cada função na DLL.  Por exemplo, `InitInstance` pode ser chamado pelo código de MFC no aplicativo sem `AFX_MANAGE_STATE` porque o MFC alterna o estado automaticamente do módulo antes de `InitInstance` e depois é trocada ele novamente depois que `InitInstance` retorna.  O mesmo é válido para todos os manipuladores retornadas mapa.  Dlls normais têm realmente um procedimento de janela mestre especial que alternou o estado automaticamente do módulo antes de roteamento qualquer mensagem.  
  
## Consulte também  
 [Gerenciando os dados de estado dos módulos MFC](../mfc/managing-the-state-data-of-mfc-modules.md)