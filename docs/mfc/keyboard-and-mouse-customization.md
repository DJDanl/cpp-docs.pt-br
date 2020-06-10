---
title: Personalização de teclado e mouse
ms.date: 11/19/2018
helpviewer_keywords:
- customizations [MFC], keyboard and mouse (MFC Extensions)
- keyboard and mouse customizations (MFC Extensions)
ms.assetid: 1f789f1b-5f2e-4b11-b974-e3e2a2e49d82
ms.openlocfilehash: 262555b060f226a86438a2189eda44d83c55d5a2
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84621495"
---
# <a name="keyboard-and-mouse-customization"></a>Personalização de teclado e mouse

O MFC permite que o usuário do seu aplicativo personalize como ele lida com a entrada de teclado e mouse. O usuário pode personalizar a entrada do teclado atribuindo atalhos de teclado aos comandos. O usuário também pode personalizar a entrada do mouse selecionando o comando que deve ser executado quando o usuário clica duas vezes dentro de janelas específicas do aplicativo. Este tópico explica como personalizar a entrada para seu aplicativo.

Na caixa de diálogo **personalização** , o usuário pode alterar os controles personalizados para o mouse e o teclado. Para exibir essa caixa de diálogo, o usuário aponta para **Personalizar** no menu **Exibir** e, em seguida, clica em **barras de ferramentas e encaixe**. Na caixa de diálogo, o usuário clica na guia **teclado** ou na guia **mouse** .

## <a name="keyboard-customization"></a>Personalização do teclado

A ilustração a seguir mostra a guia **teclado** da caixa de diálogo **personalização** .

![Guia teclado na caixa de diálogo Personalizar](../mfc/media/mfcnextkeyboardtab.png "Guia teclado na caixa de diálogo Personalizar") <br/>
Guia de personalização do teclado

O usuário interage com a guia teclado para atribuir um ou mais atalhos de teclado a um comando. Os comandos disponíveis são listados no lado esquerdo da guia. O usuário pode selecionar qualquer comando disponível no menu. Somente comandos de menu podem ser associados a um atalho de teclado. Depois que o usuário insere um novo atalho, o botão **atribuir** é habilitado. Quando o usuário clica nesse botão, o aplicativo associa o comando selecionado a esse atalho.

Todos os atalhos de teclado atribuídos no momento são listados na caixa de listagem na coluna à direita. O usuário também pode selecionar atalhos individuais e removê-los ou redefinir todos os mapeamentos para o aplicativo.

Se você quiser dar suporte a essa personalização em seu aplicativo, deverá criar um objeto [CKeyboardManager](reference/ckeyboardmanager-class.md) . Para criar um `CKeyboardManager` objeto, chame a função [CWinAppEx:: InitKeyboardManager](reference/cwinappex-class.md#initkeyboardmanager). Esse método cria e inicializa um Gerenciador de teclado. Se você criar um Gerenciador de teclado manualmente, você ainda precisará chamá `CWinAppEx::InitKeyboardManager` -lo para inicializá-lo.

Se você usar o assistente para criar seu aplicativo, o assistente irá inicializar o Gerenciador de teclado. Depois que o aplicativo Inicializa o Gerenciador de teclado, a estrutura adiciona uma guia de **teclado** à caixa de diálogo **personalização** .

## <a name="mouse-customization"></a>Personalização do mouse

A ilustração a seguir mostra a guia do **mouse** da caixa de diálogo de **personalização** .

![Guia do mouse na caixa de diálogo Personalizar](../mfc/media/mfcnextmousetab.png "Guia do mouse na caixa de diálogo Personalizar") <br/>
Guia de personalização do mouse

O usuário interage com essa guia para atribuir um comando de menu à ação de clique duplo do mouse. O usuário seleciona uma exibição no lado esquerdo da janela e, em seguida, usa os controles no lado direito para associar um comando à ação de clique duplo. Depois que o usuário clicar em **fechar**, o aplicativo executará o comando associado sempre que o usuário clicar duas vezes em qualquer lugar da exibição.

Por padrão, a personalização do mouse não é habilitada quando você cria um aplicativo usando o assistente.

#### <a name="to-enable-mouse-customization"></a>Para habilitar a personalização do mouse

1. Inicialize um objeto [CMouseManager](reference/cmousemanager-class.md) chamando [CWinAppEx:: InitMouseManager](reference/cwinappex-class.md#initmousemanager).

1. Obtenha um ponteiro para o Gerenciador do mouse usando [CWinAppEx:: GetMouseManager](reference/cwinappex-class.md#getmousemanager).

1. Adicione exibições ao Gerenciador do mouse usando o método [CMouseManager:: AddView](reference/cmousemanager-class.md#addview) . Faça isso para cada exibição que você deseja adicionar ao Gerenciador do mouse.

Depois que o aplicativo Inicializa o Gerenciador do mouse, a estrutura adiciona a guia do **mouse** à caixa de diálogo **Personalizar** . Se você não adicionar nenhuma exibição, o acesso à guia causará uma exceção sem tratamento. Depois de criar uma lista de exibições, a guia do **mouse** estará disponível para o usuário.

Quando você adiciona uma nova exibição ao Gerenciador do mouse, você dá a ela uma ID exclusiva. Se você quiser dar suporte à personalização do mouse para uma janela, será necessário processar a mensagem de WM_LBUTTONDBLCLICK e chamar a função [CWinAppEx:: OnViewDoubleClick](reference/cwinappex-class.md#onviewdoubleclick) . Quando você chama essa função, um dos parâmetros é a ID dessa janela. É responsabilidade do programador controlar os números de ID e os objetos associados a eles.

## <a name="security-concerns"></a>Problemas de segurança

Conforme descrito em [ferramentas definidas pelo usuário](user-defined-tools.md), o usuário pode associar uma ID de ferramenta definida pelo usuário ao evento de clique duplo. Quando o usuário clica duas vezes em uma exibição, o aplicativo procura uma ferramenta de usuário que corresponda à ID associada. Se o aplicativo encontrar uma ferramenta de correspondência, ele executará a ferramenta. Se o aplicativo não conseguir encontrar uma ferramenta correspondente, ele enviará uma mensagem de WM_COMMAND com a ID para a exibição que foi clicada duas vezes.

As configurações personalizadas são armazenadas no registro. Ao editar o registro, um invasor pode substituir uma ID de ferramenta de usuário válida por um comando arbitrário. Quando o usuário clica duas vezes em uma exibição, a exibição processa o comando que o invasor plantadas. Isso pode causar um comportamento inesperado e potencialmente perigoso.

Além disso, esse tipo de ataque pode ignorar proteções de interface do usuário. Por exemplo, suponha que um aplicativo tenha a impressão desabilitada. Ou seja, em sua interface do usuário, o menu **Imprimir** e o botão não estão disponíveis. Normalmente, isso impede que o aplicativo imprima. Mas se um invasor tiver editado o registro, um usuário poderá enviar o comando de impressão diretamente clicando duas vezes no modo de exibição, ignorando os elementos da interface do usuário que não estão disponíveis.

Para se proteger contra esse tipo de ataque, adicione o código ao manipulador de comandos do aplicativo para verificar se um comando é válido antes de ser executado. Não dependa da interface do usuário para impedir que um comando seja enviado ao aplicativo.

## <a name="see-also"></a>Consulte também

[Personalização para MFC](customization-for-mfc.md)<br/>
[Classe CKeyboardManager](reference/ckeyboardmanager-class.md)<br/>
[Classe CMouseManager](reference/cmousemanager-class.md)<br/>
[Implicações de segurança da personalização](security-implications-of-customization.md)
