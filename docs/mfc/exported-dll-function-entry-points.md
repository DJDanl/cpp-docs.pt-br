---
title: Pontos de entrada da função DLL exportada
ms.date: 11/04/2016
helpviewer_keywords:
- exporting DLLs [MFC], functions
- MFC, managing state data
- state management [MFC], exported DLLs
ms.assetid: 3268666e-d24b-44f2-80e8-7c80f73b93ca
ms.openlocfilehash: 129defe39a79fd38211a539a4a85d79d9a3c0998
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57279517"
---
# <a name="exported-dll-function-entry-points"></a>Pontos de entrada da função DLL exportada

Para funções exportadas de uma DLL, use o [AFX_MANAGE_STATE](reference/extension-dll-macros.md#afx_manage_state) macro para manter o estado global apropriado ao alternar de módulo DLL para a DLL do aplicativo de chamada.

Quando chamado, essa macro define `pModuleState`, um ponteiro para um `AFX_MODULE_STATE` estrutura que contém os dados globais para o módulo, como o estado do módulo em vigor para o restante do escopo da função de armazenamento. Ao sair do escopo que contém a macro, o estado anterior do módulo eficaz é restaurado automaticamente.

Essa alternância é feito construindo uma instância de um `AFX_MODULE_STATE` classe na pilha. Em seu construtor, essa classe obtém um ponteiro para o estado atual do módulo e armazena em uma variável de membro e, em seguida, define `pModuleState` como o novo estado do módulo em vigor. Em seu destruidor, essa classe restaura o ponteiro armazenado em sua variável de membro como o estado do módulo em vigor.

Se você tiver uma função exportada, por exemplo, um que inicia uma caixa de diálogo na DLL, você precisará adicionar o código a seguir para o início da função:

[!code-cpp[NVC_MFCConnectionPoints#6](../mfc/codesnippet/cpp/exported-dll-function-entry-points_1.cpp)]

Isso alterna o estado atual do módulo com o estado retornado de [AfxGetStaticModuleState](reference/extension-dll-macros.md#afxgetstaticmodulestate) até o final do escopo atual.

Problemas com os recursos em DLLs ocorrerá se o `AFX_MANAGE_STATE` macro não é usada. Por padrão, o MFC usa o identificador de recurso do aplicativo principal para carregar o modelo de recurso. Esse modelo, na verdade, é armazenado na DLL. A causa raiz é que informações de estado do módulo do MFC não foi alternadas pelo `AFX_MANAGE_STATE` macro. O identificador de recurso é recuperado do estado do módulo do MFC. Não alternar o estado do módulo faz com que o identificador de recurso incorreto a ser usado.

`AFX_MANAGE_STATE` não precisa ser colocado em cada função na DLL. Por exemplo, `InitInstance` pode ser chamado pelo código do MFC no aplicativo sem `AFX_MANAGE_STATE` porque o MFC mudará automaticamente o estado do módulo antes `InitInstance` e, em seguida, alterna-lo de volta depois `InitInstance` retorna. O mesmo é verdadeiro para todos os manipuladores de mapa de mensagem. DLLs MFC regulares, na verdade, tem um procedimento de janela mestre especial que alterna automaticamente o estado do módulo antes de encaminhar qualquer mensagem.

## <a name="see-also"></a>Consulte também

[Gerenciando os dados de estado dos módulos MFC](../mfc/managing-the-state-data-of-mfc-modules.md)
