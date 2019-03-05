---
title: Adicionando várias exibições a um único documento
ms.date: 11/04/2016
helpviewer_keywords:
- multiple views [MFC], SDI applications
- documents [MFC], multiple views
- single document interface (SDI), adding views
- views [MFC], SDI applications
ms.assetid: 86d0c134-01d5-429c-b672-36cfb956dc01
ms.openlocfilehash: b665f090fc680221be70f170452d756dd5f68dc5
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57284275"
---
# <a name="adding-multiple-views-to-a-single-document"></a>Adicionando várias exibições a um único documento

Em um aplicativo de interface de documento único (SDI) criado com a biblioteca Microsoft Foundation Class (MFC), cada tipo de documento está associado um tipo de exibição único. Em alguns casos, é desejável ter a capacidade de alternar o modo de exibição atual de um documento com um novo modo de exibição.

> [!TIP]
>  Para obter procedimentos adicionais sobre a implementação de vários modos de exibição para um único documento, consulte [CDocument::AddView](../mfc/reference/cdocument-class.md#addview) e o [COLETAR](../visual-cpp-samples.md) amostra do MFC.

Você pode implementar essa funcionalidade adicionando um novo `CView`-derivado da classe e código adicional para alternar entre os modos de exibição dinamicamente a um aplicativo MFC existente.

As etapas são da seguinte maneira:

- [Modifique a classe de aplicativo existente](#vcconmodifyexistingapplicationa1)

- [Criar e modificar a nova classe de exibição](#vcconnewviewclassa2)

- [Criar e anexar o novo modo de exibição](#vcconattachnewviewa3)

- [Implementar a função de comutação](#vcconswitchingfunctiona4)

- [Adicionar suporte para alternar o modo de exibição](#vcconswitchingtheviewa5)

O restante deste tópico pressupõe o seguinte:

- O nome da `CWinApp`-é derivada do objeto `CMyWinApp`, e `CMyWinApp` é declarado e definido no *MYWINAPP. H* e *MYWINAPP. CPP*.

- `CNewView` é o nome do novo `CView`-derivados do objeto, e `CNewView` é declarado e definido no *NOVAVISUALIZACAO. H* e *NOVAVISUALIZACAO. CPP*.

##  <a name="vcconmodifyexistingapplicationa1"></a> Modifique a classe de aplicativo existente

Para o aplicativo alternar entre modos de exibição, você precisa modificar a classe de aplicativo, adicionando as variáveis de membro para armazenar os modos de exibição e um método para alterá-los.

Adicione o seguinte código à declaração de `CMyWinApp` em *MYWINAPP. H*:

[!code-cpp[NVC_MFCDocViewSDI#1](../mfc/codesnippet/cpp/adding-multiple-views-to-a-single-document_1.h)]

As novas variáveis de membro `m_pOldView` e `m_pNewView`, aponte para o modo de exibição atual e um recém-criado. O novo método (`SwitchView`) alterna os modos de exibição quando solicitado pelo usuário. O corpo do método é discutido posteriormente neste tópico em [implementar a função troca](#vcconswitchingfunctiona4).

Última modificação para a classe de aplicativo requer a inclusão de um novo arquivo de cabeçalho que define uma mensagem do Windows (**WM_INITIALUPDATE**) que é usado na função de comutação.

Insira a seguinte linha na seção incluir *MYWINAPP. CPP*:

[!code-cpp[NVC_MFCDocViewSDI#2](../mfc/codesnippet/cpp/adding-multiple-views-to-a-single-document_2.cpp)]

Salve suas alterações e continuar para a próxima etapa.

##  <a name="vcconnewviewclassa2"></a> Criar e modificar a nova classe de exibição

Criando a nova classe de exibição é mais fácil usando o **nova classe** disponível no modo de exibição de classe de comando. O único requisito para essa classe é que ele deriva `CView`. Adicione essa nova classe para o aplicativo. Para obter informações específicas sobre como adicionar uma nova classe ao projeto, consulte [adicionando uma classe](../ide/adding-a-class-visual-cpp.md).

Depois de adicionar a classe ao projeto, você precisará alterar a acessibilidade de alguns membros de classe de exibição.

Modificar *NOVAVISUALIZACAO. H* alterando-se o especificador de acesso de **protegidos** ao **público** para o construtor e destruidor. Isso permite que a classe sejam criados e destruídos dinamicamente e para modificar a aparência do modo de exibição antes que ele fique visível.

Salve suas alterações e continuar para a próxima etapa.

##  <a name="vcconattachnewviewa3"></a> Criar e anexar o novo modo de exibição

Para criar e anexar o novo modo de exibição, você precisará modificar o `InitInstance` função da sua classe de aplicativo. A modificação adiciona o novo código que cria um novo objeto de exibição e, em seguida, inicializa os dois `m_pOldView` e `m_pNewView` com os dois objetos de exibição existente.

Como o novo modo de exibição é criado dentro de `InitInstance` exibições novas e existentes de função, manter o tempo de vida do aplicativo. No entanto, o aplicativo poderia facilmente criar a nova exibição dinamicamente.

Inserir este código após a chamada para `ProcessShellCommand`:

[!code-cpp[NVC_MFCDocViewSDI#3](../mfc/codesnippet/cpp/adding-multiple-views-to-a-single-document_3.cpp)]

Salve suas alterações e continuar para a próxima etapa.

##  <a name="vcconswitchingfunctiona4"></a> Implementar a função de comutação

Na etapa anterior, você adicionou o código que é criado e inicializado de um novo objeto de exibição. A última parte principal é implementar o método de comutação, `SwitchView`.

No final do arquivo de implementação para a sua classe de aplicativo (*MYWINAPP. CPP*), adicione a seguinte definição de método:

[!code-cpp[NVC_MFCDocViewSDI#4](../mfc/codesnippet/cpp/adding-multiple-views-to-a-single-document_4.cpp)]

Salve suas alterações e continuar para a próxima etapa.

##  <a name="vcconswitchingtheviewa5"></a> Adicionar suporte para alternar o modo de exibição

A etapa final envolve a adição de código que chama o `SwitchView` método quando o aplicativo precisa para alternar entre modos de exibição. Isso pode ser feito de várias maneiras: adicionando um novo item de menu para o usuário escolha ou alternar os modos de exibição internamente quando determinadas condições forem atendidas.

Para obter mais informações sobre como adicionar novos itens de menu e as funções de manipulador de comando, consulte [manipuladores para comandos e notificações de controle](../mfc/handlers-for-commands-and-control-notifications.md).

## <a name="see-also"></a>Consulte também

[Arquitetura de documento/exibição](../mfc/document-view-architecture.md)
