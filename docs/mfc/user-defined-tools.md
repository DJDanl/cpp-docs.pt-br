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
ms.openlocfilehash: a3b755fc35c98652ab87231e9d8f58cde748bfc0
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33384342"
---
# <a name="user-defined-tools"></a>Ferramentas definidas pelo usuário
MFC oferece suporte a ferramentas definidas pelo usuário. Uma ferramenta definida pelo usuário é um comando especial que executa um programa externo, especificado pelo usuário. Você pode usar o processo de personalização para gerenciar ferramentas definidas pelo usuário. No entanto, você não pode usar esse processo se o objeto de aplicativo não é derivado de [CWinAppEx classe](../mfc/reference/cwinappex-class.md). Para obter mais informações sobre personalização, consulte [personalização para MFC](../mfc/customization-for-mfc.md).  
  
 Se você tiver habilitado o suporte de ferramentas definidas pelo usuário, a caixa de diálogo de personalização inclui automaticamente o **ferramentas** guia. A ilustração a seguir mostra o **ferramentas** página.  
  
 ![Guia de ferramentas na caixa de diálogo Personalizar](../mfc/media/custdialogboxtoolstab.png "custdialogboxtoolstab")  
Guia de ferramentas da caixa de diálogo personalização  
  
## <a name="enabling-user-defined-tools-support"></a>Habilitando definido pelo usuário das ferramentas de suporte  
 Para habilitar ferramentas definidas pelo usuário em um aplicativo, chame [CWinAppEx::EnableUserTools](../mfc/reference/cwinappex-class.md#enableusertools). No entanto, você primeiro deve definir várias constantes em arquivos de recursos de seu aplicativo para usar como parâmetros para esta chamada.  
  
 No editor de recurso, criar um comando fictício que usa uma ID de comando apropriado. O exemplo a seguir, usamos **ID_TOOLS_ENTRY** como a ID de comando. Essa ID de comando marca um local em um ou mais menus onde o framework irá inserir as ferramentas definidas pelo usuário.  
  
 Você deve definir separar alguns IDs consecutivos na tabela de cadeia de caracteres para representar as ferramentas definidas pelo usuário. O número de cadeias de caracteres que você reserve é igual ao número máximo de ferramentas do usuário que os usuários podem definir. No exemplo a seguir, esses são denominados **ID_USER_TOOL1** por meio de **ID_USER_TOOL10**.  
  
 Você pode oferecer sugestões para os usuários para ajudar a selecionar diretórios e os argumentos para os programas externos que serão chamados como ferramentas. Para fazer isso, crie dois menus pop-up no editor de recursos. No exemplo a seguir esses são denominados **IDR_MENU_ARGS** e **IDR_MENU_DIRS**. Para cada comando nesses menus, defina uma cadeia de caracteres em sua tabela de cadeia de caracteres do aplicativo. A ID de recurso da cadeia de caracteres deve ser igual à ID de comando.  
  
 Você também pode criar uma classe derivada de [CUserTool classe](../mfc/reference/cusertool-class.md) para substituir a implementação padrão. Para fazer isso, passar as informações de tempo de execução para a sua classe derivada como o quarto parâmetro em CWinAppEx::EnableUserTools, em vez de RUNTIME_CLASS ([CUserTool classe](../mfc/reference/cusertool-class.md)).  
  
 Depois de definir as constantes apropriadas, chame [CWinAppEx::EnableUserTools](../mfc/reference/cwinappex-class.md#enableusertools) para habilitar ferramentas definidas pelo usuário.  
  
 A chamada de método a seguir mostra como usar essas constantes:  
  
 [!code-cpp[NVC_MFC_VisualStudioDemo#1](../mfc/codesnippet/cpp/user-defined-tools_1.cpp)]  
  
 Neste exemplo, a guia de ferramentas será incluída no **personalização** caixa de diálogo. A estrutura substituirá qualquer comando que corresponde à ID de comando **ID_TOOLS_ENTRY** em qualquer outro menu com o conjunto de ferramentas de usuário definidos atualmente sempre que um usuário abre o menu. As IDs de comando **ID_USER_TOOL1** por meio de **ID_USER_TOOL10** são reservados para uso de ferramentas definidas pelo usuário. A classe [CUserTool classe](../mfc/reference/cusertool-class.md) controla chamadas para as ferramentas de usuário. A guia da ferramenta do **personalização** caixa de diálogo fornece botões à direita dos campos de entrada de argumento e diretório para acessar os menus **IDR_MENU_ARGS** e **IDR_MENU_DIRS**. Quando um usuário seleciona um comando de um desses menus, o framework acrescenta à caixa de texto apropriada a cadeia de caracteres que tem a ID de recurso igual à ID de comando.  
  
### <a name="including-predefined-tools"></a>Incluindo ferramentas predefinidas  
 Se você quiser predefinir algumas ferramentas na inicialização do aplicativo, você deve substituir o [CFrameWnd::LoadFrame](../mfc/reference/cframewnd-class.md#loadframe) método da janela principal do seu aplicativo. Nesse método, você deve executar as etapas a seguir.  
  
##### <a name="to-add-new-tools-in-loadframe"></a>Para adicionar novas ferramentas no LoadFrame  
  
1.  Obter um ponteiro para o [CUserToolsManager classe](../mfc/reference/cusertoolsmanager-class.md) objeto chamando [CWinAppEx::GetUserToolsManager](../mfc/reference/cwinappex-class.md#getusertoolsmanager).  
  
2.  Para cada ferramenta que você deseja criar, chame [CUserToolsManager::CreateNewTool](../mfc/reference/cusertoolsmanager-class.md#createnewtool). Esse método retorna um ponteiro para um [CUserTool classe](../mfc/reference/cusertool-class.md) e o adiciona a ferramenta de usuário recém-criado à coleção interna de ferramentas. Se você forneceu as informações de tempo de execução para uma classe derivada de [CUserTool classe](../mfc/reference/cusertool-class.md) como o quarto parâmetro de [CWinAppEx::EnableUserTools](../mfc/reference/cwinappex-class.md#enableusertools), [CUserToolsManager::CreateNewTool](../mfc/reference/cusertoolsmanager-class.md#createnewtool) será instanciar e retornar uma instância dessa classe em vez disso.  
  
3.  Para cada ferramenta, defina o rótulo de texto definindo `CUserTool::m_strLabel` e defina seu comando chamando `CUserTool::SetCommand`. A implementação padrão de [CUserTool classe](../mfc/reference/cusertool-class.md) automaticamente recupera ícones disponíveis do programa que é especificado na chamada para `SetCommand`.  
  
## <a name="see-also"></a>Consulte também  
 [Personalização para MFC](../mfc/customization-for-mfc.md)   
 [Classe CUserTool](../mfc/reference/cusertool-class.md)   
 [Classe CUserToolsManager](../mfc/reference/cusertoolsmanager-class.md)   
 [Classe CWinAppEx](../mfc/reference/cwinappex-class.md)




