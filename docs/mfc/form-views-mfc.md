---
title: Exibições de formulário (MFC)
ms.date: 11/04/2016
helpviewer_keywords:
- user interfaces [MFC], forms
- forms [MFC]
- applications [MFC], forms-based
- forms-based applications [MFC]
- forms [MFC], adding to applications
ms.assetid: efbe73c1-4ca4-4613-aac2-30d916e92c0e
ms.openlocfilehash: 94d8b7d026ee3aaf1bac9dee2226de6dd9382599
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84615690"
---
# <a name="form-views-mfc"></a>Exibições de formulário (MFC)

Você pode adicionar formulários a qualquer aplicativo Visual C++ que dê suporte às bibliotecas MFC, incluindo um [aplicativo baseado em formulários](reference/creating-a-forms-based-mfc-application.md) (um cuja classe de exibição é derivada de `CFormView` ). Se você não criou inicialmente seu aplicativo para dar suporte a formulários, Visual C++ adicionará esse suporte para você quando você inserir um novo formulário. Em um aplicativo SDI ou MDI, que implementa a [arquitetura de documento/exibição](document-view-architecture.md)padrão, quando o usuário escolhe o comando **novo** (por padrão, no menu **arquivo** ), Visual C++ solicita que o usuário escolha entre os formulários disponíveis.

Com um aplicativo SDI, quando o usuário escolhe o **novo** comando, a instância atual do formulário continua a ser executada, mas uma nova instância do aplicativo com o formulário selecionado é criada se uma não for encontrada. Em um aplicativo MDI, a instância atual do formulário continua a ser executada quando o usuário escolhe o **novo** comando.

> [!NOTE]
> Você pode inserir um formulário em um aplicativo baseado em caixa de diálogo (um cuja classe de caixa de diálogo é baseada em `CDialog` e um em que nenhuma classe de exibição é implementada). No entanto, sem a arquitetura de documento/exibição, Visual C++ não implementa automaticamente o **arquivo**&#124;**nova** funcionalidade. Você deve criar uma maneira para o usuário exibir formulários adicionais, como implementando uma caixa de diálogo com guias com várias páginas de propriedades.

Quando você insere um novo formulário em seu aplicativo, Visual C++ faz o seguinte:

- Cria uma classe com base em uma das classes de estilo de formulário escolhidas ( `CFormView` , `CRecordView` , `CDaoRecordView` ou `CDialog` ).

- Cria um recurso de caixa de diálogo com os estilos apropriados (ou você pode usar um recurso de diálogo existente que ainda não foi associado a uma classe).

   Se você escolher um recurso de diálogo existente, talvez seja necessário definir esses estilos usando a página Propriedades da caixa de diálogo. Os estilos para uma caixa de diálogo devem incluir:

     **WS_CHILD**= on

     **WS_BORDER**= desativado

     **WS_VISIBLE**= desativado

     **WS_CAPTION**= desativado

Para aplicativos baseados na arquitetura de documento/exibição, o comando **novo formulário** (clique com o botão direito do mouse no modo de exibição de classe) também:

- Cria uma `CDocument` classe baseada em

   Em vez de ter uma nova classe criada, você pode usar qualquer `CDocument` classe baseada em existente em seu projeto.

- Gera um modelo de documento (derivado de `CDocument` ) com a cadeia de caracteres, o menu e os recursos de ícone.

   Você também pode criar uma nova classe na qual basear o modelo.

- Adiciona uma chamada para `AddDocumentTemplate` no código do seu aplicativo `InitInstance` .

   Visual C++ adiciona esse código para cada novo formulário que você criar, o que adiciona o formulário à lista de formulários disponíveis quando o usuário escolhe o **novo** comando. Esse código inclui a ID de recurso associada do formulário e os nomes das classes de documento, exibição e quadro associadas que juntos compõem o novo objeto de formulário.

   Os modelos de documento funcionam como a conexão entre os documentos, janelas de quadros e exibições. Para um único documento, você pode criar vários modelos.

Para obter mais informações, consulte:

- [Criar um aplicativo baseado em formulários](reference/creating-a-forms-based-mfc-application.md)

- [Inserindo um formulário em um projeto](inserting-a-form-into-a-project.md)

## <a name="see-also"></a>Consulte também

[Elementos da interface do usuário](user-interface-elements-mfc.md)
