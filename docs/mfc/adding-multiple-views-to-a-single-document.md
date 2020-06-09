---
title: Adicionando várias exibições a um único documento
ms.date: 11/04/2016
helpviewer_keywords:
- multiple views [MFC], SDI applications
- documents [MFC], multiple views
- single document interface (SDI), adding views
- views [MFC], SDI applications
ms.assetid: 86d0c134-01d5-429c-b672-36cfb956dc01
ms.openlocfilehash: 83bb7e54567319a7af4bd3d8a6bf02256fef68fb
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84623350"
---
# <a name="adding-multiple-views-to-a-single-document"></a>Adicionando várias exibições a um único documento

Em um aplicativo SDI (interface de documento único) criado com a biblioteca do Microsoft Foundation Class (MFC), cada tipo de documento é associado a um único tipo de exibição. Em alguns casos, é desejável ter a capacidade de alternar a exibição atual de um documento com uma nova exibição.

> [!TIP]
> Para obter procedimentos adicionais sobre como implementar vários modos de exibição para um único documento, consulte [CDocument:: AddView](reference/cdocument-class.md#addview) e o exemplo [Collect](../overview/visual-cpp-samples.md) MFC.

Você pode implementar essa funcionalidade adicionando uma nova `CView` classe derivada e um código adicional para alternar as exibições dinamicamente para um aplicativo MFC existente.

As etapas são as seguintes:

- [Modificar a classe de aplicativo existente](#vcconmodifyexistingapplicationa1)

- [Criar e modificar a nova classe de exibição](#vcconnewviewclassa2)

- [Criar e anexar o novo modo de exibição](#vcconattachnewviewa3)

- [Implementar a função de alternância](#vcconswitchingfunctiona4)

- [Adicionar suporte para alternar a exibição](#vcconswitchingtheviewa5)

O restante deste tópico pressupõe o seguinte:

- O nome do `CWinApp` objeto derivado é `CMyWinApp` , e `CMyWinApp` é declarado e definido em *MYWINAPP. H* e *MYWINAPP. CPP*.

- `CNewView`é o nome do novo `CView` objeto derivado e `CNewView` é declarado e definido em *NEWVIEW. H* e *NEWVIEW. CPP*.

## <a name="modify-the-existing-application-class"></a><a name="vcconmodifyexistingapplicationa1"></a>Modificar a classe de aplicativo existente

Para que o aplicativo alterne entre exibições, você precisa modificar a classe do aplicativo adicionando variáveis de membro para armazenar as exibições e um método para alterá-las.

Adicione o código a seguir à declaração de `CMyWinApp` em *MYWINAPP. H*:

[!code-cpp[NVC_MFCDocViewSDI#1](codesnippet/cpp/adding-multiple-views-to-a-single-document_1.h)]

As novas variáveis de membro `m_pOldView` e `m_pNewView` , em seguida, apontam para a exibição atual e a recém-criada. O novo método ( `SwitchView` ) alterna as exibições quando solicitado pelo usuário. O corpo do método é discutido posteriormente neste tópico em [implementar a função de alternância](#vcconswitchingfunctiona4).

A última modificação na classe de aplicativo requer a inclusão de um novo arquivo de cabeçalho que define uma mensagem do Windows (**WM_INITIALUPDATE**) que é usada na função de alternância.

Insira a linha a seguir na seção include de *MYWINAPP. CPP*:

[!code-cpp[NVC_MFCDocViewSDI#2](codesnippet/cpp/adding-multiple-views-to-a-single-document_2.cpp)]

Salve as alterações e continue na próxima etapa.

## <a name="create-and-modify-the-new-view-class"></a><a name="vcconnewviewclassa2"></a>Criar e modificar a nova classe de exibição

Criar a nova classe View torna-se fácil usando o **novo** comando de classe disponível em modo de exibição de classe. O único requisito para essa classe é que ela é derivada de `CView` . Adicione essa nova classe ao aplicativo. Para obter informações específicas sobre como adicionar uma nova classe ao projeto, consulte [adicionando uma classe](../ide/adding-a-class-visual-cpp.md).

Depois de adicionar a classe ao projeto, você precisa alterar a acessibilidade de alguns membros da classe View.

Modifique *NEWVIEW. H* alterando o especificador de acesso **protegido** para **público** para o construtor e destruidor. Isso permite que a classe seja criada e destruída dinamicamente e modifique a aparência da exibição antes que ela seja visível.

Salve as alterações e continue na próxima etapa.

## <a name="create-and-attach-the-new-view"></a><a name="vcconattachnewviewa3"></a>Criar e anexar o novo modo de exibição

Para criar e anexar o novo modo de exibição, você precisa modificar a `InitInstance` função de sua classe de aplicativo. A modificação adiciona um novo código que cria um novo objeto de exibição e, em seguida, inicializa `m_pOldView` e `m_pNewView` com os dois objetos de exibição existentes.

Como a nova exibição é criada dentro da `InitInstance` função, as exibições novas e existentes persistem durante o tempo de vida do aplicativo. No entanto, o aplicativo poderia facilmente criar a nova exibição dinamicamente.

Insira este código após a chamada para `ProcessShellCommand` :

[!code-cpp[NVC_MFCDocViewSDI#3](codesnippet/cpp/adding-multiple-views-to-a-single-document_3.cpp)]

Salve as alterações e continue na próxima etapa.

## <a name="implement-the-switching-function"></a><a name="vcconswitchingfunctiona4"></a>Implementar a função de alternância

Na etapa anterior, você adicionou o código que criou e inicializou um novo objeto de exibição. A última parte principal é implementar o método de alternância, `SwitchView` .

No final do arquivo de implementação para sua classe de aplicativo (*MYWINAPP. CPP*), adicione a seguinte definição de método:

[!code-cpp[NVC_MFCDocViewSDI#4](codesnippet/cpp/adding-multiple-views-to-a-single-document_4.cpp)]

Salve as alterações e continue na próxima etapa.

## <a name="add-support-for-switching-the-view"></a><a name="vcconswitchingtheviewa5"></a>Adicionar suporte para alternar a exibição

A etapa final envolve a adição de código que chama o `SwitchView` método quando o aplicativo precisa alternar entre exibições. Isso pode ser feito de várias maneiras: adicionando um novo item de menu para que o usuário escolha ou alterne os modos de exibição internamente quando determinadas condições forem atendidas.

Para obter mais informações sobre como adicionar novos itens de menu e funções de manipulador de comando, consulte [manipuladores para comandos e notificações de controle](handlers-for-commands-and-control-notifications.md).

## <a name="see-also"></a>Consulte também

[Arquitetura de documento/exibição](document-view-architecture.md)
