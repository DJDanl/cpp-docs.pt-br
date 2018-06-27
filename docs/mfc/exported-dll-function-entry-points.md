---
title: Exportou os pontos de entrada da função de DLL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- exporting DLLs [MFC], functions
- MFC, managing state data
- state management [MFC], exported DLLs
ms.assetid: 3268666e-d24b-44f2-80e8-7c80f73b93ca
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a8e9ff08054fbef3f15283395d7eb150551926dc
ms.sourcegitcommit: 060f381fe0807107ec26c18b46d3fcb859d8d2e7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/25/2018
ms.locfileid: "36928619"
---
# <a name="exported-dll-function-entry-points"></a>Pontos de entrada da função DLL exportada
Para funções exportadas de uma DLL, use o [AFX_MANAGE_STATE](reference/extension-dll-macros.md#afx_manage_state) macro para manter o estado global apropriado ao alternar do módulo DLL para a DLL do aplicativo de chamada.  
  
 Quando chamado, define essa macro `pModuleState`, um ponteiro para um `AFX_MODULE_STATE` estrutura que contém dados globais para o módulo, como o estado do módulo efetivo para o restante do escopo da função de armazenamento. Após sair do escopo que contém a macro, o estado anterior do módulo efetiva é restaurado automaticamente.  
  
 Essa alternância é obtido criando uma instância de um `AFX_MODULE_STATE` classe na pilha. No construtor, essa classe obtém um ponteiro para o estado atual do módulo e armazena em uma variável de membro e, em seguida, define `pModuleState` como o novo estado do módulo efetivo. Em seu destruidor, essa classe restaura o ponteiro armazenado em sua variável de membro como o estado do módulo efetivo.  
  
 Se você tiver uma função exportada, por exemplo, um que inicia uma caixa de diálogo na DLL, você precisa adicionar o código a seguir para o início da função:  
  
 [!code-cpp[NVC_MFCConnectionPoints#6](../mfc/codesnippet/cpp/exported-dll-function-entry-points_1.cpp)]  
  
 Isso alterna o estado atual do módulo com o estado retornado de [AfxGetStaticModuleState](reference/extension-dll-macros.md#afxgetstaticmodulestate) até o término do escopo atual.  
  
 Problemas com recursos em DLLs ocorrerá se o `AFX_MANAGE_STATE` macro não é usada. Por padrão, o MFC usa o identificador de recurso do aplicativo principal para carregar o modelo de recurso. Este modelo, na verdade, é armazenado na DLL. A causa raiz é que informações de estado do módulo do MFC não foi alternadas pelo `AFX_MANAGE_STATE` macro. O identificador de recurso é recuperado do estado do módulo do MFC. Não mudar o estado do módulo faz com que o identificador de recurso incorreto ser usado.  
  
 `AFX_MANAGE_STATE` não precisa ser colocado em cada função na DLL. Por exemplo, `InitInstance` pode ser chamado pelo código do aplicativo sem MFC `AFX_MANAGE_STATE` porque MFC automaticamente muda o estado do módulo antes de `InitInstance` e, em seguida, os comutadores novamente após `InitInstance` retorna. O mesmo vale para todos os manipuladores de mapa de mensagem. DLLs normais do MFC realmente tem um procedimento de janela mestre especial que alterna automaticamente o estado do módulo antes de encaminhar uma mensagem.  
  
## <a name="see-also"></a>Consulte também  
 [Gerenciando os dados de estado dos módulos MFC](../mfc/managing-the-state-data-of-mfc-modules.md)

