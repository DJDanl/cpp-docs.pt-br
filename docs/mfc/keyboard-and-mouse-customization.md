---
title: "Personalização de teclado e Mouse | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- customizations [MFC], keyboard and mouse (MFC Extensions)
- keyboard and mouse customizations (MFC Extensions)
ms.assetid: 1f789f1b-5f2e-4b11-b974-e3e2a2e49d82
caps.latest.revision: "23"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 1b031c4af05df7ad2b8c0850cefb116d4ac249d7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="keyboard-and-mouse-customization"></a>Personalização de teclado e mouse
MFC permite que o usuário do seu aplicativo para personalizar como ele trata a entrada do mouse e teclado. O usuário pode personalizar a entrada do teclado, atribuindo atalhos de teclado para comandos. O usuário também pode personalizar a entrada do mouse, selecionando o comando que deve ser executado quando o usuário clica duas vezes dentro do windows específico do aplicativo. Este tópico explica como personalizar a entrada para seu aplicativo.  
  
 No **personalização** caixa de diálogo, o usuário pode alterar os controles personalizados para o mouse e teclado. Para exibir essa caixa de diálogo, o usuário aponta para **personalizar** no **exibição** menu e, em seguida, clica **barras de ferramentas e encaixe**. Na caixa de diálogo, o usuário clica no **teclado** guia ou **Mouse** guia.  
  
## <a name="keyboard-customization"></a>Personalização de teclado  
 A ilustração a seguir mostra o **teclado** guia o **personalização** caixa de diálogo.  
  
 ![Guia de teclado na caixa de diálogo Personalizar](../mfc/media/mfcnextkeyboardtab.png "mfcnextkeyboardtab")  
Guia de personalização de teclado  
  
 O usuário interage com a guia de teclado para atribuir um ou mais atalhos de teclado a um comando. Os comandos disponíveis são listados no lado esquerdo da guia. O usuário pode selecionar todos os comandos disponíveis no menu. Comandos de menu só podem ser associados um atalho de teclado. Depois que o usuário insere um novo atalho, o **atribuir** botão fica habilitado. Quando o usuário clica neste botão, o aplicativo associa o comando selecionado com esse atalho.  
  
 Todos os atalhos de teclado atribuída no momento são listados na caixa de listagem na coluna à direita. O usuário também pode selecionar atalhos individuais e removê-los ou redefina todos os mapeamentos para o aplicativo.  
  
 Se você desejar oferecer suporte a essa personalização em seu aplicativo, você deve criar um [CKeyboardManager](../mfc/reference/ckeyboardmanager-class.md) objeto. Para criar um `CKeyboardManager` de objeto, chame a função [CWinAppEx::InitKeyboardManager](../mfc/reference/cwinappex-class.md#initkeyboardmanager). Esse método cria e inicializa um Gerenciador de teclado. Se você criar Gerenciador de um teclado manualmente, você ainda deve chamar `CWinAppEx::InitKeyboardManager` para inicializá-lo.  
  
 Se você usar o Assistente para criar seu aplicativo, o Assistente para inicializar o Gerenciador de teclado. Depois que o aplicativo inicia o Gerenciador de teclado, adiciona a estrutura de um **teclado** guia para o **personalização** caixa de diálogo.  
  
## <a name="mouse-customization"></a>Personalização de mouse  
 A ilustração a seguir mostra o **Mouse** guia o **personalização** caixa de diálogo.  
  
 ![Guia do mouse na caixa de diálogo Personalizar](../mfc/media/mfcnextmousetab.png "mfcnextmousetab")  
Guia de personalização de mouse  
  
 O usuário interage com esta guia para atribuir um menu de comando para o mouse clique duas vezes em ação. O usuário seleciona um modo de exibição do lado esquerdo da janela e, em seguida, usa os controles no lado direito para associar um comando com a ação de clique duplo. Depois que o usuário clica em **fechar**, o aplicativo executa o comando associado sempre que o usuário clica duas vezes em qualquer lugar no modo de exibição.  
  
 Por padrão, a personalização de mouse não está habilitada quando você cria um aplicativo usando o assistente.  
  
#### <a name="to-enable-mouse-customization"></a>Para habilitar a personalização de mouse  
  
1.  Inicializar um [CMouseManager](../mfc/reference/cmousemanager-class.md) objeto chamando [CWinAppEx::InitMouseManager](../mfc/reference/cwinappex-class.md#initmousemanager).  
  
2.  Obter um ponteiro para o Gerenciador de mouse usando [CWinAppEx::GetMouseManager](../mfc/reference/cwinappex-class.md#getmousemanager).  
  
3.  Adicionar modos de exibição para o Gerenciador de mouse usando o [CMouseManager::AddView](../mfc/reference/cmousemanager-class.md#addview) método. Faça isso para cada modo de exibição que você deseja adicionar ao Gerenciador de mouse.  
  
 Depois que o aplicativo inicia o Gerenciador de mouse, adiciona a estrutura de **Mouse** guia para o **personalizar** caixa de diálogo. Se você não adicionar nenhum modo de exibição, acessando a guia fará com que uma exceção sem tratamento. Depois de criar uma lista de modos de exibição, o **Mouse** guia está disponível para o usuário.  
  
 Se você adicionar um novo modo de exibição para o Gerenciador de mouse, você atribuir uma ID exclusiva. Se você deseja oferecer suporte a personalização de mouse para uma janela, você deve processar o `WM_LBUTTONDBLCLICK` mensagem e chame o [CWinAppEx::OnViewDoubleClick](../mfc/reference/cwinappex-class.md#onviewdoubleclick) função. Quando você chamar essa função, um dos parâmetros é a ID para essa janela. É responsabilidade do programador para controlar os números de ID e os objetos associados a eles.  
  
## <a name="security-concerns"></a>Problemas de segurança  
 Conforme descrito em [ferramentas definidas pelo usuário](../mfc/user-defined-tools.md), o usuário pode associar uma ID de ferramenta definida pelo usuário com o evento de clique duplo. Quando o usuário clica duas vezes em um modo de exibição, o aplicativo procura por uma ferramenta de usuário que corresponde a ID associada. Se o aplicativo encontra uma ferramenta correspondente, ele executa a ferramenta. Se o aplicativo não é possível localizar uma ferramenta correspondente, ele envia uma mensagem WM_COMMAND com a ID para o modo de exibição que foi clicado duas vezes.  
  
 As configurações personalizadas são armazenadas no registro. Editando o registro, um invasor pode substituir uma ID de ferramenta de usuário válido com um comando arbitrário. Quando o usuário clica duas vezes em um modo de exibição, o modo de exibição processa o comando que o invasor plantado. Isso pode causar comportamento inesperado e potencialmente perigoso.  
  
 Além disso, esse tipo de ataque pode ignorar as garantias de interface do usuário. Por exemplo, suponha que um aplicativo tiver desabilitada a impressão. Isto é, na interface do usuário, o **impressão** menu e botão estão indisponíveis. Normalmente, isso impede que o aplicativo de impressão. Mas se um invasor editou o registro, um usuário poderia agora pode enviar o comando print diretamente clicando duas vezes em modo de exibição, ignorando os elementos de interface de usuário que não estão disponíveis.  
  
 Para se proteger contra esse tipo de ataque, adicione código para o manipulador de comando do aplicativo para verificar se um comando é válido antes de ser executado. Não dependem de interface do usuário para impedir que um comando que está sendo enviado para o aplicativo.  
  
## <a name="see-also"></a>Consulte também  
 [Personalização para MFC](../mfc/customization-for-mfc.md)   
 [Classe CKeyboardManager](../mfc/reference/ckeyboardmanager-class.md)   
 [Classe CMouseManager](../mfc/reference/cmousemanager-class.md)   
 [Implicações de segurança da personalização](../mfc/security-implications-of-customization.md)

