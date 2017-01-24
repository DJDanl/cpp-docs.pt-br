---
title: "Personaliza&#231;&#227;o de teclado e mouse | Microsoft Docs"
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
  - "personalizações, teclado e mouse (extensões MFC)"
  - "personalizações de teclado e mouse (Extensões MFC)"
ms.assetid: 1f789f1b-5f2e-4b11-b974-e3e2a2e49d82
caps.latest.revision: 23
caps.handback.revision: 19
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Personaliza&#231;&#227;o de teclado e mouse
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

MFC permite que o usuário do seu aplicativo para personalizar o modo como ele trata a entrada de mouse e teclado. O usuário pode personalizar a entrada do teclado atribuindo atalhos de teclado para comandos. O usuário também pode personalizar a entrada de mouse, selecionando o comando que deve ser executado quando o usuário clica duas vezes dentro do windows específico do aplicativo. Este tópico explica como personalizar a entrada para seu aplicativo.  
  
 No **personalização** caixa de diálogo, o usuário pode alterar os controles personalizados para o mouse e teclado. Para exibir essa caixa de diálogo, o usuário aponta para **Personalizar** sobre o **exibição** menu e, em seguida, clica em **barras de ferramentas e encaixe**. Na caixa de diálogo, o usuário clica em um a **teclado** guia ou **Mouse** guia.  
  
## Personalização do teclado  
 A ilustração a seguir mostra o **teclado** guia de **personalização** caixa de diálogo.  
  
 ![Na guia teclado da caixa de diálogo de personalização](../mfc/media/mfcnextkeyboardtab.png "MFCNextKeyboardTab")  
Guia de personalização de teclado  
  
 O usuário interage com a guia de teclado para atribuir um ou mais atalhos de teclado a um comando. Os comandos disponíveis são listados no lado esquerdo da guia. O usuário pode selecionar todos os comandos disponíveis no menu. Comandos de menu só podem ser associados um atalho de teclado. Depois que o usuário insere um novo atalho, o **atribuir** botão fica habilitado. Quando o usuário clica nesse botão, o aplicativo associa esse atalho o comando selecionado.  
  
 Todos os atalhos de teclado atribuído no momento são listados na caixa de listagem na coluna à direita. O usuário também pode selecionar atalhos individuais e removê\-los ou redefinir todos os mapeamentos para o aplicativo.  
  
 Se você deseja oferecer suporte a essa personalização em seu aplicativo, você deve criar um [CKeyboardManager](../mfc/reference/ckeyboardmanager-class.md) objeto. Para criar um `CKeyboardManager` de objeto, chame a função [CWinAppEx::InitKeyboardManager](../Topic/CWinAppEx::InitKeyboardManager.md). Esse método cria e inicializa um Gerenciador de teclado. Se você criar Gerenciador de um teclado manualmente, você ainda deve chamar `CWinAppEx::InitKeyboardManager` para inicializá\-lo.  
  
 Se você usar o Assistente para criar seu aplicativo, o assistente irá inicializar o Gerenciador de teclado. Depois que o aplicativo inicializa o Gerenciador de teclado, o framework adiciona um **teclado** guia para o **personalização** caixa de diálogo.  
  
## Personalização de mouse  
 A ilustração a seguir mostra o **Mouse** guia de **personalização** caixa de diálogo.  
  
 ![Na guia Mouse da caixa de diálogo de personalização](../mfc/media/mfcnextmousetab.png "MFCNextMouseTab")  
Guia de personalização de mouse  
  
 O usuário interage com essa guia para atribuir um menu de comando para o mouse clique duas vezes em ação. O usuário seleciona um modo de exibição do lado esquerdo da janela e, em seguida, usa os controles no lado direito para associar um comando com a ação de clicar duas vezes. Depois que o usuário clica **Fechar**, o aplicativo executa o comando associado sempre que o usuário clica duas vezes em qualquer lugar no modo de exibição.  
  
 Por padrão, a personalização de mouse não está habilitada quando você cria um aplicativo usando o assistente.  
  
#### Para habilitar a personalização de mouse  
  
1.  Inicializar um [CMouseManager](../mfc/reference/cmousemanager-class.md) chamando [CWinAppEx::InitMouseManager](../Topic/CWinAppEx::InitMouseManager.md).  
  
2.  Obter um ponteiro para o Gerenciador de mouse usando [CWinAppEx::GetMouseManager](../Topic/CWinAppEx::GetMouseManager.md).  
  
3.  Adicionar modos de exibição para o Gerenciador de mouse usando o [CMouseManager::AddView](../Topic/CMouseManager::AddView.md) método. Faça isso para cada modo de exibição que você deseja adicionar ao Gerenciador de mouse.  
  
 Depois que o aplicativo inicializa o Gerenciador de mouse, o framework adiciona o **Mouse** guia para o **Personalizar** caixa de diálogo. Se você não adicionar nenhum modo de exibição, acessando a guia fará com que uma exceção não tratada. Depois de ter criado uma lista de modos de exibição, o **Mouse** guia está disponível para o usuário.  
  
 Quando você adiciona um novo modo de exibição para o Gerenciador de mouse, você atribui uma ID exclusiva. Se você deseja oferecer suporte a personalização de mouse para uma janela, você deve processar o `WM_LBUTTONDBLCLICK` mensagem e chame o [CWinAppEx::OnViewDoubleClick](../Topic/CWinAppEx::OnViewDoubleClick.md) função. Quando você chamar essa função, um dos parâmetros é a ID dessa janela. É responsabilidade do programador para controlar os números de ID e os objetos associados a eles.  
  
## Questões de segurança  
 Conforme descrito em [Ferramentas definidas pelo usuário](../Topic/User-defined%20Tools.md), o usuário pode associar uma ID de ferramentas definidas pelo usuário com o evento de clique duplo. Quando o usuário clica duas vezes em um modo de exibição, o aplicativo procura por uma ferramenta de usuário que corresponde a ID associada. Se o aplicativo encontra uma ferramenta correspondente, ele executa a ferramenta. Se o aplicativo não conseguir encontrar uma ferramenta correspondente, envia uma mensagem WM\_COMMAND com a ID para o modo de exibição que foi clicado duas vezes.  
  
 As configurações personalizadas são armazenadas no registro. Editando o registro, um invasor pode substituir uma ID de usuário válido ferramenta com um comando arbitrário. Quando o usuário clica duas vezes em um modo de exibição, o modo de exibição processa o comando instalados e o invasor. Isso poderia causar um comportamento inesperado e potencialmente perigoso.  
  
 Além disso, esse tipo de ataque pode ignorar proteções de interface do usuário. Por exemplo, suponha que um aplicativo tiver desabilitada a impressão. Isto é, na interface do usuário, o **impressão** menu e botão estão indisponíveis. Normalmente, isso impede que o aplicativo de impressão. Mas se um invasor tiver editado o registro, um usuário poderia agora pode enviar o comando Imprimir diretamente clicando duas vezes em modo de exibição, ignorando os elementos da interface de usuário que não estão disponíveis.  
  
 Para se proteger contra esse tipo de ataque, adicione código para o manipulador de comando do aplicativo para verificar se um comando é válido antes de ser executado. Não dependem de interface do usuário para impedir que um comando seja enviado para o aplicativo.  
  
## Consulte também  
 [Personalização para MFC](../mfc/customization-for-mfc.md)   
 [Classe de CKeyboardManager](../mfc/reference/ckeyboardmanager-class.md)   
 [Classe de CMouseManager](../mfc/reference/cmousemanager-class.md)   
 [Implicações de segurança da personalização](../Topic/Security%20Implications%20of%20Customization.md)