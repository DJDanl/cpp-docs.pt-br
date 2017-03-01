---
title: "Criando um aplicativo MFC com base em formulários | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.appwiz.mfcforms.project
dev_langs:
- C++
helpviewer_keywords:
- applications [MFC], forms-based
- forms-based applications
ms.assetid: 048d2f7d-b60d-4386-ad8e-71d49af9c05e
caps.latest.revision: 12
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: b95d52f5ecf97f43bd21dd0f2a8c4fd478431ce3
ms.lasthandoff: 02/25/2017

---
# <a name="creating-a-forms-based-mfc-application"></a>Criando um aplicativo MFC com base em formulários
Um formulário é uma caixa de diálogo com controles que permitem que um usuário acessar e possivelmente alterar dados. Você talvez queira desenvolver um aplicativo em que o usuário seleciona de uma seleção de formulários. Normalmente, um aplicativo baseado em formulários permite que os formulários de acesso do usuário por clique **novo** do **arquivo** menu. Um aplicativo baseado em diálogo, que não dão aos usuários acesso a uma **novo** opção o **arquivo** menu, também é considerado um aplicativo baseado em formulários.  
  
 Uma interface de documento único (SDI), aplicativos com base em formulários permite que apenas uma instância de um formulário para ser executado em um momento específico. É possível executar diferentes formas ao mesmo tempo em um aplicativo baseado em formulários de SDI selecionando um novo formulário do **novo** opção o **arquivo** menu.  
  
 Se você criar uma interface de documentos múltiplos (MDI), aplicativos baseados em formulários, o aplicativo poderá ser capaz de dar suporte a várias instâncias do mesmo formulário.  
  
 Se você criar um aplicativo com suporte a vários documentos de nível superior, a área de trabalho é o pai implícito para o documento e o quadro do documento não está restrito a área do cliente do aplicativo. Você pode abrir várias instâncias do documento, cada um com seu próprio quadro, o menu e o ícone da barra de tarefas. Você pode fechar instâncias subsequentes de documentos individualmente, mas se você selecionar o `Exit` opção o **arquivo** menu da instância inicial, o aplicativo fecha todas as instâncias.  
  
 SDI e MDI vários aplicativos de nível superior do documento são todos os formulários com base em e usam a arquitetura de exibição de documentos.  
  
 Qualquer aplicativo baseado em diálogo, por definição, é baseada em formulários. Um aplicativo baseado em diálogo não usa a arquitetura de documento/exibição, portanto, você deve gerenciar os métodos de criação e o acesso para seus próprios formulários adicionais.  
  
 A classe base para aplicativos baseados em formulário é [CFormView](../../mfc/reference/cformview-class.md). Se seu aplicativo tiver suporte do banco de dados, você também pode selecionar qualquer classe que deriva de `CFormView`. Um formulário é derivada de qualquer janela de `CFormView` ou de qualquer classe que herda de `CFormView`.  
  
 Mesmo se você usar uma classe base, como [CView](../../mfc/reference/cview-class.md), você posteriormente pode tornar seus aplicativos baseados em formulários, [adicionando uma classe do MFC](../../mfc/reference/adding-an-mfc-class.md) derivado de `CFormView` e verificando o **DocTemplate gerar recursos** caixa de seleção o [MFC Class Wizard](../../mfc/reference/document-template-strings-mfc-add-class-wizard.md).  
  
 Depois que você concluir o assistente, o projeto é aberto, e se você selecionou `CFormView` (ou uma classe que herda de `CFormView`) como sua classe base ou se você criou um aplicativo baseado em diálogo, Visual C++ abre o editor de caixa de diálogo. Neste ponto, você está pronto para criar o primeiro formulário.  
  
### <a name="to-begin-creating-a-forms-based-mfc-executable"></a>Para começar a criar um executável MFC baseada em formulários  
  
1.  Siga as instruções na [criando um aplicativo MFC](../../mfc/reference/creating-an-mfc-application.md).  
  
2.  No Assistente de aplicativo MFC [tipo de aplicativo](../../mfc/reference/application-type-mfc-application-wizard.md) página, selecione o **suporte para a arquitetura de documento/exibição** caixa de seleção.  
  
3.  Selecione **único documento**, **vários documentos**, ou **vários documentos de nível superior**.  
  
    > [!NOTE]
    >  Se você escolheu um SDI, MDI ou vários aplicativo de interface de nível superior do documento, por padrão, `CView` é definido como a classe base para o modo de exibição do aplicativo no [Classes geradas](../../mfc/reference/generated-classes-mfc-application-wizard.md) página do assistente. Para criar um aplicativo baseado em formulários, você deve selecionar `CFormView` como a classe base para o modo de exibição do aplicativo. Observe que o assistente não fornece nenhum suporte de impressão para um aplicativo baseado em formulários.  
  
4.  Defina quaisquer opções de projeto que você deseja em outras páginas do assistente.  
  
5.  Clique em **concluir** para gerar o aplicativo de esqueleto.  
  
 Para obter mais informações, consulte:  
  
-   [Classes de exibição derivadas](../../mfc/derived-view-classes-available-in-mfc.md)  
  
-   [Alternativas à arquitetura de documento/exibição](../../mfc/alternatives-to-the-document-view-architecture.md)  
  
-   [Opções de Design de aplicativo](../../mfc/application-design-choices.md)  
  
## <a name="see-also"></a>Consulte também  
 [Assistente de aplicativo MFC](../../mfc/reference/mfc-application-wizard.md)   
 [Modos de exibição de formulário](../../mfc/form-views-mfc.md)   
 [Criando um aplicativo MFC no estilo do Explorer arquivo](../../mfc/reference/creating-a-file-explorer-style-mfc-application.md)   
 [Criando um aplicativo MFC no estilo de navegador da Web](../../mfc/reference/creating-a-web-browser-style-mfc-application.md)


