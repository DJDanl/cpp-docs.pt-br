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
ms.openlocfilehash: 5e8912c9013175fe254b2f4a4a968a67fd071f39
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365293"
---
# <a name="form-views-mfc"></a>Exibições de formulário (MFC)

Você pode adicionar formulários a qualquer aplicativo Visual C++ que suporte as bibliotecas MFC, incluindo `CFormView`um aplicativo baseado em [formulários](../mfc/reference/creating-a-forms-based-mfc-application.md) (aquele cuja classe de visualização é derivada ). Se você não criou inicialmente seu aplicativo para suportar formulários, o Visual C++ adicionará esse suporte para você quando inserir um novo formulário. Em um aplicativo SDI ou MDI, que implementa a arquitetura padrão [de documentos/exibição,](../mfc/document-view-architecture.md)quando o usuário escolhe o comando **Novo** (por padrão, no menu **Arquivo),** o Visual C++ solicita que o usuário escolha entre os formulários disponíveis.

Com um aplicativo SDI, quando o usuário escolhe o comando **Novo,** a instância atual do formulário continua a ser executada, mas uma nova instância do aplicativo com o formulário selecionado é criada se não for encontrada. Em um aplicativo MDI, a instância atual do formulário continua a ser executada quando o usuário escolhe o comando **Novo.**

> [!NOTE]
> Você pode inserir um formulário em um aplicativo baseado em `CDialog` diálogo (aquele cuja classe de diálogo é baseada e uma em que nenhuma classe de exibição é implementada). No entanto, sem a arquitetura de documento/exibição, o Visual C++ não implementa automaticamente a funcionalidade **Arquivo**&#124;**Nova.** Você deve criar uma maneira para o usuário visualizar formulários adicionais, como implementando uma caixa de diálogo com várias páginas de propriedade.

Quando você insere um novo formulário em seu aplicativo, o Visual C++ faz o seguinte:

- Cria uma classe baseada em uma das classes`CFormView`de `CRecordView` `CDaoRecordView`estilo `CDialog`de formulário que você escolhe ( , , ou ).

- Cria um recurso de diálogo com estilos apropriados (ou você pode usar um recurso de diálogo existente que ainda não foi associado a uma classe).

   Se você escolher um recurso de diálogo existente, talvez seja necessário definir esses estilos usando a página Propriedades para a caixa de diálogo. Os estilos para uma caixa de diálogo devem incluir:

     **WS_CHILD**=On

     **WS_BORDER**=Off

     **WS_VISIBLE**=Off

     **WS_CAPTION**=Off

Para aplicativos baseados na arquitetura documento/exibição, o comando **Novo formulário** (clique com o botão direito do mouse na exibição de classe) também:

- Cria `CDocument`uma classe baseada em uma

   Em vez de ter uma nova classe criada, você pode usar qualquer classe baseada em seu `CDocument`projeto.

- Gera um modelo de `CDocument`documento (derivado de ) com recursos de string, menu e ícone.

   Você também pode criar uma nova classe na qual basear o modelo.

- Adiciona uma `AddDocumentTemplate` chamada no código `InitInstance` do seu aplicativo.

   Visual C++ adiciona este código para cada novo formulário que você cria, que adiciona o formulário à lista de formulários disponíveis quando o usuário escolhe o comando **Novo.** Esse código inclui o ID de recurso associado do formulário e os nomes das classes de documento, exibição e quadro associados que, juntas, compõem o novo objeto de formulário.

   Os modelos de documentos servem como a conexão entre documentos, janelas de quadro e visualizações. Para um único documento, você pode criar muitos modelos.

Para obter mais informações, consulte:

- [Criar um aplicativo baseado em formulários](../mfc/reference/creating-a-forms-based-mfc-application.md)

- [Inserindo um formulário em um projeto](../mfc/inserting-a-form-into-a-project.md)

## <a name="see-also"></a>Confira também

[Elementos da interface do usuário](../mfc/user-interface-elements-mfc.md)
