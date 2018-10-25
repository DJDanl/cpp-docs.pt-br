---
title: Ferramentas definidas pelo usuário | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- user-defined tools (MFC Extensions)
ms.assetid: cb887421-78ce-4652-bc67-96a53984ccaa
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b6aa9fdd5c50119b820ddd73d842dc8a60089e97
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50081973"
---
# <a name="user-defined-tools"></a>Ferramentas definidas pelo usuário

MFC dá suporte a ferramentas definidas pelo usuário. Uma ferramenta definida pelo usuário é um comando especial que executa um programa externo, especificado pelo usuário. Você pode usar o processo de personalização para gerenciar ferramentas definidas pelo usuário. No entanto, você não poderá usar esse processo se seu objeto de aplicativo não é derivado de [classe CWinAppEx](../mfc/reference/cwinappex-class.md). Para obter mais informações sobre a personalização, consulte [personalização para MFC](../mfc/customization-for-mfc.md).

Se você tiver habilitado o suporte de ferramentas definidas pelo usuário, a caixa de diálogo de personalização inclui automaticamente a **ferramentas** guia. A ilustração a seguir mostra a **ferramentas** página.

![Guia de ferramentas na caixa de diálogo Personalizar](../mfc/media/custdialogboxtoolstab.png "custdialogboxtoolstab") guia de ferramentas de caixa de diálogo de personalização

## <a name="enabling-user-defined-tools-support"></a>Habilitando definidos pelo usuário das ferramentas de suporte

Para habilitar ferramentas definidas pelo usuário em um aplicativo, chame [CWinAppEx::EnableUserTools](../mfc/reference/cwinappex-class.md#enableusertools). No entanto, você deve primeiro definir várias constantes em arquivos de recursos de seu aplicativo para usar como parâmetros para essa chamada.

No editor de recursos, crie um comando fictício que usa uma ID de comando apropriado. No exemplo a seguir, usamos `ID_TOOLS_ENTRY` como a ID de comando. Essa ID de comando marca um local em um ou mais menus em que o framework irá inserir as ferramentas definidas pelo usuário.

Você deve reservar alguns IDs consecutivos na tabela de cadeia de caracteres para representar as ferramentas definidas pelo usuário. O número de cadeias de caracteres que você reservou é igual ao número máximo de ferramentas de usuário que os usuários podem definir. No exemplo a seguir, esses são denominados `ID_USER_TOOL1` por meio de `ID_USER_TOOL10`.

Você pode oferecer sugestões para os usuários para ajudá-los a selecionar diretórios e os argumentos para os programas externos que serão chamados como ferramentas. Para fazer isso, crie dois menus pop-up no editor de recursos. No exemplo a seguir, esses são denominados `IDR_MENU_ARGS` e `IDR_MENU_DIRS`. Para cada comando nesses menus, defina uma cadeia de caracteres em sua tabela de cadeia de caracteres de aplicativo. A ID de recurso da cadeia de caracteres deve ser igual à ID de comando.

Você também pode criar uma classe derivada de [classe CUserTool](../mfc/reference/cusertool-class.md) para substituir a implementação padrão. Para fazer isso, passe as informações de tempo de execução para sua classe derivada, como o quarto parâmetro em CWinAppEx::EnableUserTools, em vez de RUNTIME_CLASS ([classe CUserTool](../mfc/reference/cusertool-class.md)).

Depois de definir as constantes apropriadas, chame [CWinAppEx::EnableUserTools](../mfc/reference/cwinappex-class.md#enableusertools) para habilitar ferramentas definidas pelo usuário.

A chamada de método a seguir mostra como usar essas constantes:

[!code-cpp[NVC_MFC_VisualStudioDemo#1](../mfc/codesnippet/cpp/user-defined-tools_1.cpp)]

Neste exemplo, a guia Ferramentas de será incluída na **personalização** caixa de diálogo. O framework substituirá qualquer comando que corresponde à ID do comando `ID_TOOLS_ENTRY` em qualquer outro menu com o conjunto de ferramentas de usuário definida no momento, sempre que um usuário abre o menu. As IDs de comando `ID_USER_TOOL1` por meio de `ID_USER_TOOL10` são reservados para uso de ferramentas definidas pelo usuário. A classe [classe CUserTool](../mfc/reference/cusertool-class.md) lida com chamadas para as ferramentas do usuário. Guia de ferramenta do **personalização** caixa de diálogo fornece botões para a direita dos campos de entrada de argumento e o diretório para acessar os menus **IDR_MENU_ARGS** e **IDR_MENU_DIRS**. Quando um usuário seleciona um comando de um desses menus, o framework acrescenta à caixa de texto apropriado a cadeia de caracteres que tem a ID de recurso igual à ID de comando.

### <a name="including-predefined-tools"></a>Incluindo ferramentas predefinidas

Se você quiser predefinir algumas ferramentas na inicialização do aplicativo, você deve substituir a [CFrameWnd::LoadFrame](../mfc/reference/cframewnd-class.md#loadframe) método da janela principal do seu aplicativo. Nesse método, você deve executar as etapas a seguir.

##### <a name="to-add-new-tools-in-loadframe"></a>Para adicionar novas ferramentas no LoadFrame

1. Obter um ponteiro para o [classe CUserToolsManager](../mfc/reference/cusertoolsmanager-class.md) objeto chamando [CWinAppEx::GetUserToolsManager](../mfc/reference/cwinappex-class.md#getusertoolsmanager).

1. Para todas as ferramentas que você deseja criar, chame [CUserToolsManager::CreateNewTool](../mfc/reference/cusertoolsmanager-class.md#createnewtool). Esse método retorna um ponteiro para um [classe CUserTool](../mfc/reference/cusertool-class.md) e o adiciona a ferramenta de usuário recém-criado à coleção interna de ferramentas. Se você forneceu as informações de tempo de execução para uma classe derivada de [classe CUserTool](../mfc/reference/cusertool-class.md) como o quarto parâmetro do [CWinAppEx::EnableUserTools](../mfc/reference/cwinappex-class.md#enableusertools), [CUserToolsManager::CreateNewTool](../mfc/reference/cusertoolsmanager-class.md#createnewtool) serão instanciar e retornar uma instância dessa classe em vez disso.

1. Para cada ferramenta, defina seu rótulo de texto definindo `CUserTool::m_strLabel` e defina seu comando chamando `CUserTool::SetCommand`. A implementação padrão de [classe CUserTool](../mfc/reference/cusertool-class.md) recupera automaticamente os ícones disponíveis do programa que é especificado na chamada para `SetCommand`.

## <a name="see-also"></a>Consulte também

[Personalização para MFC](../mfc/customization-for-mfc.md)<br/>
[Classe CUserTool](../mfc/reference/cusertool-class.md)<br/>
[Classe CUserToolsManager](../mfc/reference/cusertoolsmanager-class.md)<br/>
[Classe CWinAppEx](../mfc/reference/cwinappex-class.md)

