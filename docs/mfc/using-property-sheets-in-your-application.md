---
title: Usando folhas de propriedade no aplicativo
ms.date: 11/04/2016
helpviewer_keywords:
- dialog templates [MFC], property sheets
- dialog resources
- property pages [MFC], property sheets
- DoModal method property sheets
- AddPage method [MFC]
- property sheets, about property sheets
- Create method [MFC], property sheets
- CPropertyPage class [MFC], styles
ms.assetid: 240654d4-152b-4e3f-af7b-44234339206e
ms.openlocfilehash: 789764c9af988135219bd710d4f8aec1cda9143a
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91504646"
---
# <a name="using-property-sheets-in-your-application"></a>Usando folhas de propriedade no aplicativo

Para usar uma folha de propriedades em seu aplicativo, conclua as seguintes etapas:

1. Crie um recurso de modelo de caixa de diálogo para cada página de propriedades. Tenha em mente que o usuário pode estar alternando de uma página para outra, portanto, deite cada página o mais consistente possível.

   Os modelos de caixa de diálogo de todas as páginas não precisam ter o mesmo tamanho. A estrutura usa o tamanho da página maior para determinar a quantidade de espaço a ser alocada na folha de propriedades para as páginas de propriedades.

   Ao criar o recurso de modelo de caixa de diálogo para uma página de propriedades, você deve especificar os seguintes estilos na folha de propriedades de propriedades da caixa de diálogo:

   - Defina a caixa de edição **legenda** na página **geral** como o texto que você deseja que apareça na guia desta página.

   - Defina a caixa de listagem **estilo** na página **estilos** como **filho**.

   - Defina a caixa de listagem **borda** na página **estilos** como **fina**.

   - Verifique se a caixa de seleção **TitleBar** na página **estilos** está selecionada.

   - Verifique se a caixa de seleção **desabilitado** na página **mais estilos** está selecionada.

1. Crie uma classe derivada de [CPropertyPage](../mfc/reference/cpropertypage-class.md)correspondente a cada modelo de caixa de diálogo de página de propriedades. Consulte [adicionando uma classe](../ide/adding-a-class-visual-cpp.md). Escolha `CPropertyPage` como a classe base.

1. Crie variáveis de membro para armazenar os valores dessa página de propriedades. O processo para adicionar variáveis de membro a uma página de propriedades é exatamente o mesmo que adicionar variáveis de membro a uma caixa de diálogo, porque uma página de propriedades é uma caixa de diálogo especializada. Para obter mais informações, consulte [Definindo variáveis de membro para controles de caixa de diálogo](../windows/adding-editing-or-deleting-controls.md).

1. Construa um objeto [CPropertySheet](../mfc/reference/cpropertysheet-class.md) em seu código-fonte. Normalmente, você constrói o `CPropertySheet` objeto no manipulador para o comando que exibe a folha de propriedades. Esse objeto representa a folha de propriedades inteira. Se você criar uma folha de propriedades modal com a função [DoModal](../mfc/reference/cpropertysheet-class.md#domodal) , a estrutura fornecerá três botões de comando por padrão: Ok, cancelar e aplicar. A estrutura não cria nenhum botão de comando para folhas de propriedades sem janela restrita criadas com a função [Create](../mfc/reference/cpropertysheet-class.md#create) . Você não precisa derivar uma classe `CPropertySheet` a menos que queira adicionar outros controles (como uma janela de visualização) ou exibir uma folha de propriedades sem janela restrita. Esta etapa é necessária para folhas de propriedades sem janela restrita porque elas não contêm nenhum controle padrão que possa ser usado para fechar a folha de propriedades.

1. Para cada página a ser adicionada à folha de propriedades, faça o seguinte:

   - Construa um objeto para cada `CPropertyPage` classe derivada que você criou anteriormente neste processo.

   - Chame [CPropertySheet:: AddPage](../mfc/reference/cpropertysheet-class.md#addpage) para cada página.

   Normalmente, o objeto que cria o `CPropertySheet` também cria os `CPropertyPage` objetos nesta etapa. No entanto, se você implementar uma `CPropertySheet` classe derivada, poderá inserir os `CPropertyPage` objetos no `CPropertySheet` objeto e chamar `AddPage` cada página do `CPropertySheet` Construtor de classe derivada. `AddPage` Adiciona o `CPropertyPage` objeto à lista de páginas da folha de propriedades, mas não cria realmente a janela para essa página. Portanto, não é necessário aguardar até a criação da janela da folha de propriedades para chamar `AddPage` ; você pode chamar `AddPage` a partir do construtor da folha de propriedades.

   Por padrão, se uma folha de propriedades tiver mais guias do que couber em uma única linha da folha de propriedades, as guias serão empilhadas em várias linhas. Para desabilitar o empilhamento, chame [CPropertySheet:: EnableStackedTabs](../mfc/reference/cpropertysheet-class.md#enablestackedtabs) com o parâmetro definido como **false**. Você deve chamar `EnableStackedTabs` quando criar a folha de propriedades.

1. Chame [CPropertySheet::D omodal](../mfc/reference/cpropertysheet-class.md#domodal) ou [crie](../mfc/reference/cpropertysheet-class.md#create) para exibir a folha de propriedades. Chame `DoModal` para criar uma folha de propriedades como uma caixa de diálogo modal. Chame **Create** para criar a folha de propriedades como uma caixa de diálogo sem janela restrita.

1. Troque dados entre páginas de propriedades e o proprietário da folha de propriedades. Isso é explicado no artigo [troca de dados](../mfc/exchanging-data.md).

Para obter um exemplo de como usar folhas de propriedades, consulte o exemplo geral do MFC [PROPDLG](../overview/visual-cpp-samples.md).

## <a name="see-also"></a>Consulte também

[Folhas de propriedades](../mfc/property-sheets-mfc.md)
