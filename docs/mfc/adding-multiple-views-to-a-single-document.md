---
title: Adicionando várias exibições a um único documento | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- multiple views [MFC], SDI applications
- documents [MFC], multiple views
- single document interface (SDI), adding views
- views [MFC], SDI applications
ms.assetid: 86d0c134-01d5-429c-b672-36cfb956dc01
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: cb40b356b5601e19c33083c7b731a1dc411de3c5
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="adding-multiple-views-to-a-single-document"></a>Adicionando várias exibições a um único documento
Em um aplicativo de interface de documento único (SDI) criado com a biblioteca Microsoft Foundation Class (MFC), cada tipo de documento está associado um tipo de exibição única. Em alguns casos, é desejável ter a capacidade de alternar o modo de exibição atual de um documento com um novo modo de exibição.  
  
> [!TIP]
>  Para obter procedimentos adicionais sobre a implementação de vários modos de exibição de um único documento, consulte [CDocument::AddView](../mfc/reference/cdocument-class.md#addview) e [COLETAR](../visual-cpp-samples.md) exemplo do MFC.  
  
 Você pode implementar essa funcionalidade, adicionando um novo `CView`-derivado da classe e código adicional para alternar os modos de exibição dinamicamente a um aplicativo MFC existente.  
  
 As etapas são da seguinte maneira:  
  
-   [Modificar a classe do aplicativo existente](#vcconmodifyexistingapplicationa1)  
  
-   [Criar e modificar a nova classe de exibição](#vcconnewviewclassa2)  
  
-   [Criar e anexar o novo modo de exibição](#vcconattachnewviewa3)  
  
-   [Implementar a função de comutação](#vcconswitchingfunctiona4)  
  
-   [Adicionar suporte para alternar o modo de exibição](#vcconswitchingtheviewa5)  
  
 O restante deste tópico presume o seguinte:  
  
-   O nome do `CWinApp`-objeto derivado é `CMyWinApp`, e `CMyWinApp` é declarado e definidos no MYWINAPP. H e MYWINAPP. CPP.  
  
-   `CNewView` é o nome do novo `CView`-derivados do objeto, e `CNewView` é declarado e definido na nova exibição. H e nova exibição. CPP.  
  
##  <a name="vcconmodifyexistingapplicationa1"></a> Modificar a classe do aplicativo existente  
 Para o aplicativo alternar entre modos de exibição, você precisa modificar a classe do aplicativo Adicionando variáveis de membro para armazenar os modos de exibição e um método para alterá-los.  
  
 Adicione o seguinte código para a declaração de `CMyWinApp` em MYWINAPP. H:  
  
 [!code-cpp[NVC_MFCDocViewSDI#1](../mfc/codesnippet/cpp/adding-multiple-views-to-a-single-document_1.h)]  
  
 As novas variáveis de membro, `m_pOldView` e `m_pNewView`, aponte para o modo de exibição atual e o recém-criado. O novo método (`SwitchView`) alterna os modos de exibição quando solicitado pelo usuário. O corpo do método é abordado posteriormente neste tópico em [implementar a função de troca](#vcconswitchingfunctiona4).  
  
 Última modificação para a classe de aplicativo requer incluindo um novo arquivo de cabeçalho que define uma mensagem do Windows (**WM_INITIALUPDATE**) que é usado na função de alternância.  
  
 Insira a linha a seguir na seção de inclusão MYWINAPP. CPP:  
  
 [!code-cpp[NVC_MFCDocViewSDI#2](../mfc/codesnippet/cpp/adding-multiple-views-to-a-single-document_2.cpp)]  
  
 Salve suas alterações e continuar para a próxima etapa.  
  
##  <a name="vcconnewviewclassa2"></a> Criar e modificar a nova classe de exibição  
 Criando a nova classe de exibição fica mais fácil por meio de **nova classe** comando disponível no modo de exibição de classe. O único requisito para essa classe é que deriva de `CView`. Adicione essa nova classe para o aplicativo. Para obter informações específicas sobre como adicionar uma nova classe ao projeto, consulte [adicionando uma classe](../ide/adding-a-class-visual-cpp.md).  
  
 Depois de adicionar a classe ao projeto, você precisa alterar a acessibilidade de alguns membros de classe de exibição.  
  
 Modifique a nova exibição. H alterando o especificador de acesso de `protected` para **pública** para o construtor e destruidor. Isso permite que a classe a ser criados e destruídos dinamicamente e para modificar a aparência do modo de exibição antes que ele fique visível.  
  
 Salve suas alterações e continuar para a próxima etapa.  
  
##  <a name="vcconattachnewviewa3"></a> Criar e anexar o novo modo de exibição  
 Para criar e anexar o novo modo de exibição, você precisa modificar o `InitInstance` função da classe do aplicativo. A modificação adiciona um novo código que cria um novo objeto de exibição e, em seguida, inicializa os dois `m_pOldView` e `m_pNewView` com os dois objetos de exibição existentes.  
  
 Como o novo modo de exibição é criado dentro de `InitInstance` função, as exibições novas e existentes persistem pelo tempo de vida do aplicativo. No entanto, o aplicativo poderia ser tão facilmente criar a nova exibição dinamicamente.  
  
 Inserir este código após a chamada a `ProcessShellCommand`:  
  
 [!code-cpp[NVC_MFCDocViewSDI#3](../mfc/codesnippet/cpp/adding-multiple-views-to-a-single-document_3.cpp)]  
  
 Salve suas alterações e continuar para a próxima etapa.  
  
##  <a name="vcconswitchingfunctiona4"></a> Implementar a função de comutação  
 Na etapa anterior, você adicionou o código que são criados e inicializados um novo objeto de exibição. A última parte principal é implementar o método de comutação, `SwitchView`.  
  
 No final do arquivo de implementação para a sua classe de aplicativo (MYWINAPP. CPP), adicione a definição de método a seguir:  
  
 [!code-cpp[NVC_MFCDocViewSDI#4](../mfc/codesnippet/cpp/adding-multiple-views-to-a-single-document_4.cpp)]  
  
 Salve suas alterações e continuar para a próxima etapa.  
  
##  <a name="vcconswitchingtheviewa5"></a> Adicionar suporte para alternar o modo de exibição  
 A etapa final envolve a adição de código que chama o `SwitchView` método quando o aplicativo precisa para alternar entre modos de exibição. Isso pode ser feito de várias maneiras: por adicionar um novo item de menu para o usuário escolha ou alternar os modos de exibição internamente quando determinadas condições forem atendidas.  
  
 Para obter mais informações sobre como adicionar novos itens de menu e as funções de manipulador de comando, consulte [manipuladores para comandos e notificações de controle](../mfc/handlers-for-commands-and-control-notifications.md).  
  
## <a name="see-also"></a>Consulte também  
 [Arquitetura de documento/exibição](../mfc/document-view-architecture.md)

