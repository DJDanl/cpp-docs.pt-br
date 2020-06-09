---
title: Arquitetura de exibição de documento
ms.date: 11/19/2018
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
ms.openlocfilehash: a74aeba651d385cf3a5386e94ec20e4e56b7cd57
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84624781"
---
# <a name="documentview-architecture"></a>Arquitetura de documento/exibição

Por padrão, o assistente de aplicativo do MFC cria um esqueleto de aplicativo com uma classe de documento e uma classe de exibição. O MFC separa o gerenciamento de dados nessas duas classes. O documento armazena os dados e gerencia a impressão dos dados e coordena a atualização de várias exibições dos dados. A exibição mostra os dados e gerencia a interação do usuário com ele, incluindo seleção e edição.

Nesse modelo, um objeto de documento MFC lê e grava dados no armazenamento persistente. O documento também pode fornecer uma interface para os dados onde quer que ele resida (como em um banco de dados). Um objeto de exibição separado gerencia a exibição de dados, desde a renderização dos dados em uma janela até a seleção de usuários e a edição de dados. A exibição obtém dados de exibição do documento e se comunica de volta ao documento quaisquer alterações de dados.

Embora você possa facilmente substituir ou ignorar a separação de documento/exibição, há motivos convincentes para seguir esse modelo na maioria dos casos. Uma das melhores é quando você precisa de várias exibições do mesmo documento, como uma planilha e uma exibição de gráfico. O modelo de documento/exibição permite que um objeto de exibição separado represente cada exibição dos dados, enquanto o código comum a todas as exibições (como um mecanismo de cálculo) pode residir no documento. O documento também assume a tarefa de atualizar todas as exibições sempre que os dados são alterados.

A arquitetura de exibição/documento do MFC facilita o suporte a várias exibições, vários tipos de documentos, janelas divisórias e outros recursos valiosos da interface do usuário.

As partes do MFC Framework mais visíveis para o usuário e para você, o programador, são o documento e a exibição. A maior parte do seu trabalho no desenvolvimento de um aplicativo com a estrutura vai escrever suas classes de documento e de exibição. Esta família de artigos descreve:

- A finalidade de documentos e exibições e como eles interagem na estrutura.

- O que você deve fazer para implementá-los.

No coração do documento/modo de exibição há quatro classes principais:

A classe [CDocument](reference/cdocument-class.md) (ou [COleDocument](reference/coledocument-class.md)) dá suporte a objetos usados para armazenar ou controlar os dados do seu programa e fornece a funcionalidade básica para as classes de documento definidas pelo programador. Um documento representa a unidade de dados que o usuário normalmente abre com o comando abrir no menu arquivo e salva com o comando salvar no menu arquivo.

O [cvisualização](reference/cview-class.md) (ou uma de suas várias classes derivadas) fornece a funcionalidade básica para classes de exibição definidas pelo programador. Uma exibição é anexada a um documento e atua como um intermediário entre o documento e o usuário: a exibição renderiza uma imagem do documento na tela e interpreta a entrada do usuário como operações no documento. A exibição também renderiza a imagem para impressão e visualização de impressão.

[CFrameWnd](reference/cframewnd-class.md) (ou uma de suas variações) oferece suporte a objetos que fornecem o quadro em um ou mais modos de exibição de um documento.

[CDocTemplate](reference/cdoctemplate-class.md) (ou [CSingleDocTemplate](reference/csingledoctemplate-class.md) ou [CMultiDocTemplate](reference/cmultidoctemplate-class.md)) dá suporte a um objeto que coordena um ou mais documentos existentes de um determinado tipo e gerencia a criação dos objetos corretos de documento, exibição e janela de quadro para esse tipo.

A figura a seguir mostra a relação entre um documento e sua exibição.

![A exibição é a parte do documento que é exibida](../mfc/media/vc379n1.gif "A exibição é a parte do documento que é exibida") <br/>
Documento e exibição

A implementação de documento/exibição na biblioteca de classes separa os dados em sua exibição e das operações de usuário nos dados. Todas as alterações nos dados são gerenciadas por meio da classe de documento. A exibição chama essa interface para acessar e atualizar os dados.

Documentos, suas exibições associadas e as janelas de quadros que modelam os modos de exibição são criados por um modelo de documento. O modelo de documento é responsável por criar e gerenciar todos os documentos de um tipo de documento.

## <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Uma retrato da arquitetura de documento/exibição](a-portrait-of-the-document-view-architecture.md)

- [Vantagens da arquitetura de documento/exibição](advantages-of-the-document-view-architecture.md)

- [Documentar e exibir classes criadas pelo assistente de aplicativo](document-and-view-classes-created-by-the-mfc-application-wizard.md)

- [Alternativas para a arquitetura de documento/exibição](alternatives-to-the-document-view-architecture.md)

- [Adicionando várias exibições a um único documento](adding-multiple-views-to-a-single-document.md)

- [Usando documentos](using-documents.md)

- [Usando exibições](using-views.md)

- [Vários tipos de documento, exibições e janelas com moldura](multiple-document-types-views-and-frame-windows.md)

- [Inicializando e limpando documentos e exibições](initializing-and-cleaning-up-documents-and-views.md)

- [Inicialize suas próprias inclusões no documento & classes de exibição](creating-new-documents-windows-and-views.md)

- [Usando classes de banco de dados com documentos e exibições](../data/mfc-using-database-classes-with-documents-and-views.md)

- [Usando classes de banco de dados sem documentos e exibições](../data/mfc-using-database-classes-without-documents-and-views.md)

- [Amostras](../overview/visual-cpp-samples.md)

## <a name="see-also"></a>Consulte também

[Elementos da interface do usuário](user-interface-elements-mfc.md)<br/>
[Windows](windows.md)<br/>
[Janelas com moldura](frame-windows.md)<br/>
[Modelos de documento e o processo de criação de documento/exibição](document-templates-and-the-document-view-creation-process.md)<br/>
[Criação de documento/exibição](document-view-creation.md)<br/>
[Criando novos documentos, janelas e exibições](creating-new-documents-windows-and-views.md)
