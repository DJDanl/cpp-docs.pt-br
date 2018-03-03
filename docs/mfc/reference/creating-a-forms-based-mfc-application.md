---
title: "Criando um aplicativo MFC com base em formulários | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.appwiz.mfcforms.project
dev_langs:
- C++
helpviewer_keywords:
- applications [MFC], forms-based
- forms-based applications [MFC]
ms.assetid: 048d2f7d-b60d-4386-ad8e-71d49af9c05e
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 1e5d43412da21edce2633c17b5a38e4b1b787495
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="creating-a-forms-based-mfc-application"></a>Criando um aplicativo MFC com base em formulários
Um formulário é uma caixa de diálogo com os controles que permitem que um usuário acesse e possivelmente de alteração de dados. Você talvez queira desenvolver um aplicativo no qual o usuário seleciona em uma seleção de formulários. Normalmente, um aplicativo baseado em formulários permite que os formulários de acesso do usuário por clique **novo** do **arquivo** menu. Um aplicativo baseado em caixa de diálogo, que não oferecem aos usuários acesso a um **novo** opção o **arquivo** menu, também é considerado um aplicativo baseado em formulários.  
  
 Uma interface de documento único (SDI), aplicativos baseados em formulários permite apenas uma instância de um formulário específico para executar de cada vez. É possível executar diferentes formas ao mesmo tempo, de um aplicativo baseado em formulários de SDI selecionando um novo formulário do **novo** opção o **arquivo** menu.  
  
 Se você criar uma interface de documentos múltiplos (MDI), aplicativos baseados em formulários, o aplicativo será capaz de dar suporte a várias instâncias do mesmo formulário.  
  
 Se você criar um aplicativo com suporte a vários documentos de nível superior, a área de trabalho é o pai implícita para o documento e o quadro do documento não está restrito a área cliente do aplicativo. Você pode abrir várias instâncias do documento, cada qual com seu próprio quadro, o menu e o ícone da barra de tarefas. Você pode fechar instâncias subsequentes de documentos individualmente, mas se você selecionar o `Exit` opção o **arquivo** menu da instância inicial, o aplicativo fecha todas as instâncias.  
  
 SDI e MDI vários aplicativos de nível superior do documento são todos os formulários com base e usam a arquitetura de documento/exibição.  
  
 Qualquer aplicativo baseado em caixa de diálogo, por definição, é formulários baseados. Um aplicativo baseado na caixa de diálogo não usam a arquitetura de documento/exibição, portanto, você deve gerenciar os métodos de criação e o acesso para seus próprios formulários adicionais.  
  
 A classe base para aplicativos baseados em formulário é [CFormView](../../mfc/reference/cformview-class.md). Se seu aplicativo tiver suporte do banco de dados, você também pode selecionar qualquer classe que deriva de `CFormView`. Um formulário é derivada de qualquer janela de `CFormView` ou de qualquer classe que herda de `CFormView`.  
  
 Mesmo se você usar uma classe base, como [CView](../../mfc/reference/cview-class.md), mais tarde você pode fazer com que o seus aplicativos com base em formulários por [adicionando uma classe do MFC](../../mfc/reference/adding-an-mfc-class.md) derivado `CFormView` e verificando o **gerar Modelodedoc recursos** caixa de seleção de [Assistente de classe MFC](../../mfc/reference/document-template-strings-mfc-add-class-wizard.md).  
  
 Depois que você concluir o assistente, o projeto é aberto, e se você selecionou `CFormView` (ou uma classe que herda de `CFormView`) como sua classe base ou se você criou um aplicativo baseado na caixa de diálogo, o Visual C++ abre o editor de caixa de diálogo. Neste ponto, você está pronto para criar seu primeiro formulário.  
  
### <a name="to-begin-creating-a-forms-based-mfc-executable"></a>Para começar a criar um executável MFC baseada em formulários  
  
1.  Siga as instruções na [criando um aplicativo MFC](../../mfc/reference/creating-an-mfc-application.md).  
  
2.  No Assistente de aplicativo MFC [tipo de aplicativo](../../mfc/reference/application-type-mfc-application-wizard.md) página, selecione o **suporte para a arquitetura de documento/exibição** caixa de seleção.  
  
3.  Selecione **único documento**, **vários documentos**, ou **vários documentos de nível superior**.  
  
    > [!NOTE]
    >  Se você escolher um SDI, MDI ou vários aplicativo de interface de nível superior do documento, por padrão, `CView` é definido como a classe base para o modo de exibição do aplicativo no [Classes geradas pelo](../../mfc/reference/generated-classes-mfc-application-wizard.md) página do assistente. Para criar um aplicativo baseado em formulários, você deve selecionar `CFormView` como a classe base para o modo de exibição do aplicativo. Observe que o assistente não fornece nenhum suporte de impressão para um aplicativo baseado em formulários.  
  
4.  Defina outras opções de projeto que você deseja nas outras páginas do assistente.  
  
5.  Clique em **concluir** para gerar o aplicativo de esqueleto.  
  
 Para obter mais informações, consulte:  
  
-   [Classes de exibição derivadas](../../mfc/derived-view-classes-available-in-mfc.md)  
  
-   [Alternativas à arquitetura de documento/exibição](../../mfc/alternatives-to-the-document-view-architecture.md)  
  
-   [Opções de design do aplicativo](../../mfc/application-design-choices.md)  
  
## <a name="see-also"></a>Consulte também  
 [Assistente de aplicativo MFC](../../mfc/reference/mfc-application-wizard.md)   
 [Modos de exibição de formulário](../../mfc/form-views-mfc.md)   
 [Criando um aplicativo MFC no estilo do Explorer arquivo](../../mfc/reference/creating-a-file-explorer-style-mfc-application.md)   
 [Criando um aplicativo MFC no estilo de navegador da Web](../../mfc/reference/creating-a-web-browser-style-mfc-application.md)

