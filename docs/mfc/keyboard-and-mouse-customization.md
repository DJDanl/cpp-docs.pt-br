---
title: Personalização de teclado e mouse
ms.date: 11/04/2016
helpviewer_keywords:
- customizations [MFC], keyboard and mouse (MFC Extensions)
- keyboard and mouse customizations (MFC Extensions)
ms.assetid: 1f789f1b-5f2e-4b11-b974-e3e2a2e49d82
ms.openlocfilehash: 8bb685974ed4020611ffe275ba504951d132afac
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50487380"
---
# <a name="keyboard-and-mouse-customization"></a>Personalização de teclado e mouse

MFC permite que o usuário do seu aplicativo para personalizar como ele lida com entrada de mouse e teclado. O usuário pode personalizar a entrada do teclado, atribuindo os atalhos de teclado para comandos. O usuário também pode personalizar a entrada de mouse, selecionando o comando que deve ser executado quando o usuário clica duas vezes dentro do windows específico do aplicativo. Este tópico explica como personalizar a entrada para seu aplicativo.

No **personalização** caixa de diálogo, o usuário pode alterar os controles personalizados para o mouse e teclado. Para exibir essa caixa de diálogo, o usuário aponta para **personalizar** sobre o **exibição** menu e, em seguida, clica **encaixe e barras de ferramentas**. Na caixa de diálogo, o usuário clica em qualquer um de **teclado** guia ou o **Mouse** guia.

## <a name="keyboard-customization"></a>Personalização de teclado

A ilustração a seguir mostra a **teclado** guia o **personalização** caixa de diálogo.

![Guia de teclado na caixa de diálogo Personalizar](../mfc/media/mfcnextkeyboardtab.png "mfcnextkeyboardtab") guia de personalização de teclado

O usuário interage com a guia de teclado para atribuir um ou mais atalhos de teclado a um comando. Os comandos disponíveis são listados no lado esquerdo da guia. O usuário pode selecionar qualquer comando disponível no menu. Somente os comandos de menu podem ser associados um atalho de teclado. Depois que o usuário insere um novo atalho, o **atribuir** botão fica habilitado. Quando o usuário clica nesse botão, o aplicativo associa esse atalho o comando selecionado.

Todos os atalhos de teclado atribuída no momento são listados na caixa de listagem na coluna à direita. O usuário também pode selecionar atalhos individuais e removê-los ou redefinir todos os mapeamentos para o aplicativo.

Se você quiser dar suporte a essa personalização em seu aplicativo, você deve criar uma [CKeyboardManager](../mfc/reference/ckeyboardmanager-class.md) objeto. Para criar uma `CKeyboardManager` de objeto, chame a função [CWinAppEx::InitKeyboardManager](../mfc/reference/cwinappex-class.md#initkeyboardmanager). Esse método cria e inicializa um Gerenciador de teclado. Se você criar o Gerenciador de um teclado manualmente, você ainda deve chamar `CWinAppEx::InitKeyboardManager` para inicializá-lo.

Se você usar o Assistente para criar seu aplicativo, o assistente irá inicializar o Gerenciador de teclado. Depois que seu aplicativo inicializa o Gerenciador de teclado, o framework adiciona uma **teclado** alterne para o **personalização** caixa de diálogo.

## <a name="mouse-customization"></a>Personalização de mouse

A ilustração a seguir mostra a **Mouse** guia o **personalização** caixa de diálogo.

![Guia do mouse na caixa de diálogo Personalizar](../mfc/media/mfcnextmousetab.png "mfcnextmousetab") guia de personalização de Mouse

O usuário interage com essa guia para atribuir um menu de comando para o mouse clique duas vezes em ação. O usuário seleciona um modo de exibição do lado esquerdo da janela e, em seguida, usa os controles no lado direito para associar um comando com a ação de clique duplo. Depois que o usuário clica **fechar**, o aplicativo executa o comando associado sempre que o usuário clica duas vezes em qualquer lugar no modo de exibição.

Por padrão, a personalização de mouse não está habilitada quando você cria um aplicativo usando o assistente.

#### <a name="to-enable-mouse-customization"></a>Para habilitar a personalização de mouse

1. Inicializar uma [CMouseManager](../mfc/reference/cmousemanager-class.md) objeto chamando [CWinAppEx::InitMouseManager](../mfc/reference/cwinappex-class.md#initmousemanager).

1. Obter um ponteiro para o Gerenciador de mouse usando [CWinAppEx::GetMouseManager](../mfc/reference/cwinappex-class.md#getmousemanager).

1. Adicionar modos de exibição para o Gerenciador de mouse usando o [CMouseManager::AddView](../mfc/reference/cmousemanager-class.md#addview) método. Faça isso para cada modo de exibição que você deseja adicionar ao Gerenciador de mouse.

Depois que seu aplicativo inicializa o Gerenciador de mouse, o framework adiciona o **Mouse** alterne para o **personalizar** caixa de diálogo. Se você não adicionar nenhum modo de exibição, acessando a guia fará com que uma exceção sem tratamento. Depois de criar uma lista de modos de exibição, o **Mouse** guia está disponível para o usuário.

Se você adiciona um novo modo de exibição para o Gerenciador de mouse, você atribuir uma ID exclusiva. Se você quiser dar suporte a personalização de mouse para uma janela, você deve processar a mensagem WM_LBUTTONDBLCLICK e a chamada a [CWinAppEx::OnViewDoubleClick](../mfc/reference/cwinappex-class.md#onviewdoubleclick) função. Quando você chama essa função, um dos parâmetros é a ID para essa janela. É responsabilidade do programador para controlar os números de ID e os objetos associados a eles.

## <a name="security-concerns"></a>Problemas de segurança

Conforme descrito em [ferramentas definidas pelo usuário](../mfc/user-defined-tools.md), o usuário pode associar uma ID de ferramenta definida pelo usuário com o evento de clique duplo. Quando o usuário clica duas vezes em um modo de exibição, o aplicativo procura por uma ferramenta de usuário que corresponde a ID associada. Se o aplicativo encontra uma ferramenta de correspondência, ele executa a ferramenta. Se o aplicativo não é possível localizar uma ferramenta de correspondência, ele envia uma mensagem WM_COMMAND com a ID para o modo de exibição que foi clicado duas vezes.

As configurações personalizadas são armazenadas no registro. Editando o registro, um invasor pode substituir uma ID de usuário válido da ferramenta com um comando arbitrário. Quando o usuário clica duas vezes em um modo de exibição, o modo de exibição processará o comando que o invasor instalados e irão. Isso poderia causar um comportamento inesperado e potencialmente perigoso.

Além disso, esse tipo de ataque pode ignorar proteções de interface do usuário. Por exemplo, suponha que um aplicativo tiver desabilitada a impressão. Isto é, na interface do usuário, o **impressão** menu e o botão não estão disponíveis. Normalmente, isso impede que o aplicativo de impressão. Mas se um invasor editado o registro, um usuário poderia agora pode enviar o comando de impressão diretamente clicando duas vezes em modo de exibição, ignorando os elementos de interface do usuário que não estão disponíveis.

Para se proteger contra esse tipo de ataque, adicione código para o manipulador de comando do aplicativo para verificar se um comando é válido antes de ser executado. Não dependem de interface do usuário para impedir que um comando que está sendo enviado para o aplicativo.

## <a name="see-also"></a>Consulte também

[Personalização para MFC](../mfc/customization-for-mfc.md)<br/>
[Classe CKeyboardManager](../mfc/reference/ckeyboardmanager-class.md)<br/>
[Classe CMouseManager](../mfc/reference/cmousemanager-class.md)<br/>
[Implicações de segurança da personalização](../mfc/security-implications-of-customization.md)

