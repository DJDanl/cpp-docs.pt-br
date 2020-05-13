---
title: Adicionando várias exibições a um único documento
ms.date: 11/04/2016
helpviewer_keywords:
- multiple views [MFC], SDI applications
- documents [MFC], multiple views
- single document interface (SDI), adding views
- views [MFC], SDI applications
ms.assetid: 86d0c134-01d5-429c-b672-36cfb956dc01
ms.openlocfilehash: 4fa39a4d9369c84d2cffdaeff28dc9cb2f966b31
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370860"
---
# <a name="adding-multiple-views-to-a-single-document"></a>Adicionando várias exibições a um único documento

Em um aplicativo de interface de documento único (SDI) criado com a Biblioteca MFC (Microsoft Foundation Class, classe de fundação) da Microsoft, cada tipo de documento está associado a um único tipo de exibição. Em alguns casos, é desejável ter a capacidade de alternar a visão atual de um documento com uma nova visão.

> [!TIP]
> Para obter procedimentos adicionais sobre a implementação de várias visualizações para um único documento, consulte [CDocument::AddView](../mfc/reference/cdocument-class.md#addview) e a amostra de MFC [collect.](../overview/visual-cpp-samples.md)

Você pode implementar essa funcionalidade `CView`adicionando uma nova classe derivada e um código adicional para mudar as visualizações dinamicamente para um aplicativo MFC existente.

As etapas são as seguintes:

- [Modificar a classe de aplicativos existente](#vcconmodifyexistingapplicationa1)

- [Criar e modificar a nova classe de exibição](#vcconnewviewclassa2)

- [Criar e anexar a nova visão](#vcconattachnewviewa3)

- [Implementar a função de comutação](#vcconswitchingfunctiona4)

- [Adicionar suporte para alternar a exibição](#vcconswitchingtheviewa5)

O restante deste tópico assume o seguinte:

- O nome `CWinApp`do objeto derivado `CMyWinApp`é `CMyWinApp` , e é declarado e definido em *MYWINAPP. H* e *MYWINAPP. CPP*.

- `CNewView`é o nome `CView`do novo objeto `CNewView` derivado, e é declarado e definido em *NEWVIEW. H* e *NEWVIEW. CPP*.

## <a name="modify-the-existing-application-class"></a><a name="vcconmodifyexistingapplicationa1"></a>Modificar a classe de aplicativos existente

Para que o aplicativo alterne entre visualizações, você precisa modificar a classe de aplicativos adicionando variáveis de membro para armazenar as visualizações e um método para trocá-las.

Adicione o seguinte código `CMyWinApp` à declaração de no *MYWINAPP. H*:

[!code-cpp[NVC_MFCDocViewSDI#1](../mfc/codesnippet/cpp/adding-multiple-views-to-a-single-document_1.h)]

As novas variáveis `m_pOldView` de `m_pNewView`membro, e , apontam para a visão atual e a recém-criada. O novo`SwitchView`método ( ) alterna as visualizações quando solicitado pelo usuário. O corpo do método é discutido mais tarde neste tópico em [Implementar a Função de Comutação](#vcconswitchingfunctiona4).

A última modificação na classe de aplicativos requer a inclusão de um novo arquivo de cabeçalho que define uma mensagem do Windows **(WM_INITIALUPDATE)** que é usada na função de comutação.

Insira a seguinte linha na seção incluir *mywinapp. CPP*:

[!code-cpp[NVC_MFCDocViewSDI#2](../mfc/codesnippet/cpp/adding-multiple-views-to-a-single-document_2.cpp)]

Salve suas mudanças e continue até o próximo passo.

## <a name="create-and-modify-the-new-view-class"></a><a name="vcconnewviewclassa2"></a>Criar e modificar a nova classe de exibição

A criação da nova classe de exibição é facilitada usando o comando **New Class** disponível no Class View. O único requisito para esta classe `CView`é que ela deriva de . Adicione esta nova classe ao aplicativo. Para obter informações específicas sobre como adicionar uma nova classe ao projeto, consulte [Adicionar uma classe](../ide/adding-a-class-visual-cpp.md).

Depois de adicionar a classe ao projeto, você precisa alterar a acessibilidade de alguns membros da classe de exibição.

Modificar *NEWVIEW. H* alterando o especificador de acesso de **protegido** para **público** para o construtor e destruidor. Isso permite que a classe seja criada e destruída dinamicamente e modifique a aparência da exibição antes que ela seja visível.

Salve suas mudanças e continue até o próximo passo.

## <a name="create-and-attach-the-new-view"></a><a name="vcconattachnewviewa3"></a>Criar e anexar a nova visão

Para criar e anexar a nova exibição, você precisa modificar a `InitInstance` função da sua classe de aplicativo. A modificação adiciona um novo código que cria um `m_pOldView` `m_pNewView` novo objeto de exibição e, em seguida, inicializa ambos e com os dois objetos de exibição existentes.

Como a nova visão é `InitInstance` criada dentro da função, tanto as visualizações novas quanto as existentes persistem durante toda a vida útil do aplicativo. No entanto, o aplicativo poderia facilmente criar a nova visão dinamicamente.

Insira este código `ProcessShellCommand`após a chamada para:

[!code-cpp[NVC_MFCDocViewSDI#3](../mfc/codesnippet/cpp/adding-multiple-views-to-a-single-document_3.cpp)]

Salve suas mudanças e continue até o próximo passo.

## <a name="implement-the-switching-function"></a><a name="vcconswitchingfunctiona4"></a>Implementar a função de comutação

Na etapa anterior, você adicionou código que criou e inicializou um novo objeto de exibição. A última peça importante é implementar `SwitchView`o método de comutação, .

No final do arquivo de implementação para sua classe de aplicativo (*MYWINAPP. CPP*), adicionar a seguinte definição de método:

[!code-cpp[NVC_MFCDocViewSDI#4](../mfc/codesnippet/cpp/adding-multiple-views-to-a-single-document_4.cpp)]

Salve suas mudanças e continue até o próximo passo.

## <a name="add-support-for-switching-the-view"></a><a name="vcconswitchingtheviewa5"></a>Adicionar suporte para alternar a exibição

A etapa final envolve adicionar `SwitchView` código que chama o método quando o aplicativo precisa alternar entre as exibições. Isso pode ser feito de várias maneiras: adicionando um novo item de menu para o usuário escolher ou alternando as visualizações internamente quando determinadas condições são atendidas.

Para obter mais informações sobre a adição de novos itens de menu e funções de manipulador de comandos, consulte [Manipuladores para Comandos e Notificações de Controle](../mfc/handlers-for-commands-and-control-notifications.md).

## <a name="see-also"></a>Confira também

[Arquitetura de documento/exibição](../mfc/document-view-architecture.md)
