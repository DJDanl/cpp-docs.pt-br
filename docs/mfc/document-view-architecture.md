---
title: Arquitetura do modo de exibição de documentos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- CView class [MFC], view architecture
- CDocument class [MFC]
- MFC, views
- views [MFC], MFC document/view model
- document objects [MFC]
- document objects [MFC], MFC document/view model
- MFC, documents
- documents [MFC], MFC document/view model
- document objects [MFC], document/view architecture
ms.assetid: 6127768a-553f-462a-b01b-a5ee6068c81e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c9554af9443bbd6a6394789343294630104c96f1
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33350049"
---
# <a name="documentview-architecture"></a>Arquitetura de documento/exibição
Por padrão, o Assistente de aplicativo MFC cria um esqueleto de aplicativo com uma classe de documento e uma classe de exibição. MFC separa o gerenciamento de dados para essas duas classes. O documento armazena os dados e gerencia os dados de impressão e coordena a atualização de vários modos de exibição dos dados. O modo de exibição exibe os dados e gerencia a interação do usuário com ele, incluindo a seleção e edição.  
  
 Nesse modelo, um objeto de documento MFC lê e grava dados para o armazenamento persistente. O documento também pode fornecer uma interface para os dados sempre que ela reside (como em um banco de dados). Um objeto de exibição separada gerencia a exibição de dados, de processamento de dados em uma janela de seleção de usuário e a edição de dados. A exibição obtém dados de exibição do documento e se comunica para o documento, as alterações de dados.  
  
 Enquanto você pode substituir ou ignorar a separação de documento/exibição facilmente, há motivos para seguir este modelo na maioria dos casos. Um dos melhores é quando você precisar de várias exibições do mesmo documento, como uma planilha e uma exibição de gráfico. O modelo de documento/exibição permite que um objeto de exibição separada representam cada modo de exibição de dados, enquanto o código comum a todos os modos de exibição (como um mecanismo de cálculo) podem residir no documento. O documento também usa a tarefa de atualização de todos os modos de exibição sempre que os dados são alterados.  
  
 Arquitetura de documento/exibição MFC facilita dar suporte a várias exibições, vários tipos de documentos, janelas separadoras e outros recursos valiosos da interface do usuário.  
  
 As partes do framework MFC mais visível para o usuário e para você, o programador, são o documento e a exibição. A maioria do trabalho no desenvolvimento de um aplicativo com o framework entra em escrever suas classes de documento e exibição. Família este artigo descreve:  
  
-   As finalidades de documentos e modos de exibição e como eles interagem no framework.  
  
-   Você deve fazer para implementá-las.  
  
 No Centro de exibição de documentos são quatro classes principal:  
  
 O [CDocument](../mfc/reference/cdocument-class.md) (ou [COleDocument](../mfc/reference/coledocument-class.md)) dá suporte a objetos usados para armazenar ou controlar dados do programa de classe e fornece a funcionalidade básica para classes de documento definidos pelo programador. Um documento representa a unidade de dados que o usuário normalmente é aberta com o comando Abrir no menu Arquivo e salva com o comando Salvar no menu arquivo.  
  
 O [CView](../mfc/reference/cview-class.md) (ou uma de suas classes derivadas muitos) fornece a funcionalidade básica para classes de exibição definidos pelo programador. Um modo de exibição é anexado a um documento e atua como um intermediário entre o documento e o usuário: a exibição renderiza uma imagem do documento na tela e interpreta a entrada do usuário como operações após o documento. O modo de exibição também processa a imagem de visualização de impressão e imprimir.  
  
 [CFrameWnd](../mfc/reference/cframewnd-class.md) (ou uma de suas variações) dá suporte a objetos que fornece o quadro em torno de um ou mais modos de exibição de um documento.  
  
 [CDocTemplate](../mfc/reference/cdoctemplate-class.md) (ou [CSingleDocTemplate](../mfc/reference/csingledoctemplate-class.md) ou [CMultiDocTemplate](../mfc/reference/cmultidoctemplate-class.md)) dá suporte a um objeto que coordena a um ou mais documentos existentes de um determinado tipo e gerencia a criação correta documento, exibição e objetos de janela do quadro para esse tipo.  
  
 A figura a seguir mostra a relação entre um documento e sua exibição.  
  
 ![Modo de exibição é a parte do documento que é exibido](../mfc/media/vc379n1.gif "vc379n1")  
Documento e exibição  
  
 A implementação de exibição de documentos na biblioteca de classes separa os próprios dados de sua exibição em operações de usuário nos dados. Todas as alterações nos dados são gerenciadas por meio da classe de documento. O modo de exibição chama essa interface para acessar e atualizar os dados.  
  
 Documentos, suas exibições associadas e as janelas de quadro que determinam os modos de exibição são criadas por um modelo de documento. O modelo de documento é responsável por criar e gerenciar todos os documentos de um tipo de documento.  
  
## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Um retrato da arquitetura de documento/exibição](../mfc/a-portrait-of-the-document-view-architecture.md)  
  
-   [Vantagens da arquitetura de documento/exibição](../mfc/advantages-of-the-document-view-architecture.md)  
  
-   [Classes de documento e exibição criadas pelo Assistente de aplicativo](../mfc/document-and-view-classes-created-by-the-mfc-application-wizard.md)  
  
-   [Alternativas à arquitetura de documento/exibição](../mfc/alternatives-to-the-document-view-architecture.md)  
  
-   [Adicionando várias exibições a um único documento](../mfc/adding-multiple-views-to-a-single-document.md)  
  
-   [Usando documentos](../mfc/using-documents.md)  
  
-   [Usando exibições](../mfc/using-views.md)  
  
-   [Vários tipos de documento, exibições e janelas com moldura](../mfc/multiple-document-types-views-and-frame-windows.md)  
  
-   [Inicializando e limpando documentos e exibições](../mfc/initializing-and-cleaning-up-documents-and-views.md)  
  
-   [Inicializar seus próprios adições para classes de documento e exibição](../mfc/creating-new-documents-windows-and-views.md)  
  
-   [Usando classes de banco de dados com documentos e exibições](../data/mfc-using-database-classes-with-documents-and-views.md)  
  
-   [Usando classes de banco de dados sem documentos e exibições](../data/mfc-using-database-classes-without-documents-and-views.md)  
  
-   [Amostras](../visual-cpp-samples.md)  
  
## <a name="see-also"></a>Consulte também  
 [Elementos da Interface do usuário](../mfc/user-interface-elements-mfc.md)   
 [Windows](../mfc/windows.md)   
 [Janelas com moldura](../mfc/frame-windows.md)   
 [Modelos de documento e o processo de criação de documento/exibição](../mfc/document-templates-and-the-document-view-creation-process.md)   
 [Criação de documento/exibição](../mfc/document-view-creation.md)   
 [Criando novos documentos, janelas e exibições](../mfc/creating-new-documents-windows-and-views.md)

