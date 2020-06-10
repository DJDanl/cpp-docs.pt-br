---
title: Pontos de entrada da função DLL exportada
ms.date: 11/04/2016
helpviewer_keywords:
- exporting DLLs [MFC], functions
- MFC, managing state data
- state management [MFC], exported DLLs
ms.assetid: 3268666e-d24b-44f2-80e8-7c80f73b93ca
ms.openlocfilehash: c521cad666864c728fd871b460cf0c92b815e414
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84622636"
---
# <a name="exported-dll-function-entry-points"></a>Pontos de entrada da função DLL exportada

Para funções exportadas de uma DLL, use a macro [AFX_MANAGE_STATE](reference/extension-dll-macros.md#afx_manage_state) para manter o estado global adequado ao alternar do módulo dll para a DLL do aplicativo de chamada.

Quando chamado, essa macro define `pModuleState` um ponteiro para uma `AFX_MODULE_STATE` estrutura que contém dados globais para o módulo, como o estado de módulo efetivo para o restante do escopo de contenção da função. Ao sair do escopo que contém a macro, o estado do módulo efetivo anterior é restaurado automaticamente.

Essa alternância é obtida pela construção de uma instância de uma `AFX_MODULE_STATE` classe na pilha. Em seu construtor, essa classe obtém um ponteiro para o estado atual do módulo e o armazena em uma variável de membro e, em seguida, define `pModuleState` como o novo estado de módulo efetivo. Em seu destruidor, essa classe restaura o ponteiro armazenado em sua variável de membro como o estado de módulo efetivo.

Se você tiver uma função exportada, como uma que inicie uma caixa de diálogo em sua DLL, você precisará adicionar o seguinte código ao início da função:

[!code-cpp[NVC_MFCConnectionPoints#6](codesnippet/cpp/exported-dll-function-entry-points_1.cpp)]

Isso troca o estado atual do módulo pelo estado retornado de [AfxGetStaticModuleState](reference/extension-dll-macros.md#afxgetstaticmodulestate) até o final do escopo atual.

Problemas com recursos em DLLs ocorrerão se a `AFX_MANAGE_STATE` macro não for usada. Por padrão, o MFC usa o identificador de recurso do aplicativo principal para carregar o modelo de recurso. Esse modelo é realmente armazenado na DLL. A causa raiz é que as informações de estado do módulo do MFC não foram alternadas pela `AFX_MANAGE_STATE` macro. O identificador de recurso é recuperado do estado do módulo do MFC. Não alternar o estado do módulo faz com que o identificador de recurso errado seja usado.

`AFX_MANAGE_STATE`Não precisa ser colocado em todas as funções na DLL. Por exemplo, `InitInstance` pode ser chamado pelo código MFC no aplicativo sem que o `AFX_MANAGE_STATE` MFC alterne automaticamente o estado do módulo antes `InitInstance` e, em seguida, o alterne novamente após o `InitInstance` retorno. O mesmo é verdadeiro para todos os manipuladores de mapa de mensagem. As DLLs comuns do MFC realmente têm um procedimento de janela mestre especial que alterna automaticamente o estado do módulo antes de rotear qualquer mensagem.

## <a name="see-also"></a>Consulte também

[Gerenciando os dados de estado dos módulos MFC](managing-the-state-data-of-mfc-modules.md)
