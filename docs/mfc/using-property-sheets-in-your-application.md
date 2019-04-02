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
ms.openlocfilehash: 4fd68f57db082ab0b0da0e8248e0be239c63c99a
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58773210"
---
# <a name="using-property-sheets-in-your-application"></a>Usando folhas de propriedade no aplicativo

Para usar uma folha de propriedades em seu aplicativo, conclua as seguintes etapas:

1. Crie um recurso de modelo de caixa de diálogo para cada página de propriedades. Tenha em mente que o usuário pode ser alternar de uma página para outra, para que o layout de cada página mais consistentemente possível.

   Os modelos de caixa de diálogo para todas as páginas não é necessário ter o mesmo tamanho. A estrutura usa o tamanho da maior página para determinar quanto espaço alocar na folha de propriedades para as páginas de propriedade.

   Quando você cria o recurso de modelo de caixa de diálogo para uma página de propriedades, você deve especificar os seguintes estilos na folha de propriedades da caixa de diálogo de propriedades:

   - Defina a **legenda** caixa de edição a **geral** página para o texto que você deseja que aparecem na guia para esta página.

   - Defina a **estilo** caixa de listagem na **estilos** paginar para o **filho**.

   - Defina a **borda** caixa de listagem na **estilos** paginar para o **fina**.

   - Certifique-se de que o **Titlebar** caixa de seleção a **estilos** página está selecionada.

   - Certifique-se de que o **desabilitados** caixa de seleção a **mais estilos** página for selecionada.

1. Criar uma [CPropertyPage](../mfc/reference/cpropertypage-class.md)-correspondente a cada modelo de caixa de diálogo de página de propriedade de classe derivada. Ver [adicionando uma classe](../ide/adding-a-class-visual-cpp.md). Escolha `CPropertyPage` como a classe base.

1. Crie variáveis para armazenar os valores para esta página de propriedades de membro. O processo para adicionar variáveis de membro para uma página de propriedades é exatamente o mesmo que adicionar variáveis de membro a uma caixa de diálogo, como uma página de propriedades é uma caixa de diálogo especializado. Para obter mais informações, consulte [definindo variáveis de membro para controles de caixa de diálogo](../windows/defining-member-variables-for-dialog-controls.md).

1. Construir uma [CPropertySheet](../mfc/reference/cpropertysheet-class.md) objeto em seu código-fonte. Normalmente, você constrói o `CPropertySheet` objeto no manipulador para o comando que exibe a folha de propriedades. Este objeto representa a folha de propriedades de inteiro. Se você criar uma folha de propriedades modal com o [DoModal](../mfc/reference/cpropertysheet-class.md#domodal) função, o framework fornece três botões de comando por padrão: Okey, cancelar e se aplicam. A estrutura não cria nenhum botão de comando para folhas de propriedades sem janela restrita criadas com o [criar](../mfc/reference/cpropertysheet-class.md#create) função. Não é necessário derivar uma classe de `CPropertySheet` , a menos que você deseja adicionar outros controles (como uma janela de visualização) ou exibir uma folha de propriedades sem janela restrita. Essa etapa é necessária para folhas de propriedades sem janela restrita, porque eles não contêm todos os controles padrão que pode ser usados para fechar a folha de propriedades.

1. Para cada página a ser adicionado à folha de propriedades, faça o seguinte:

   - Construir um objeto para cada `CPropertyPage`-derivado da classe que você criou anteriormente no processo.

   - Chame [CPropertySheet::AddPage](../mfc/reference/cpropertysheet-class.md#addpage) para cada página.

   Normalmente, o objeto que cria o `CPropertySheet` também cria o `CPropertyPage` objetos nesta etapa. No entanto, se você implementar uma `CPropertySheet`-derivado da classe, você pode inserir o `CPropertyPage` objetos na `CPropertySheet` objeto e chame `AddPage` para cada página do `CPropertySheet`-derivado do construtor de classe. `AddPage` Adiciona o `CPropertyPage` o objeto para a lista da folha de propriedades de páginas, mas não cria, na verdade, a janela para a página. Portanto, não é necessário esperar até a criação da janela de folha de propriedade para chamar `AddPage`; você pode chamar `AddPage` de construtor da folha de propriedades.

   Por padrão, se uma folha de propriedades tem mais guias cabem em uma única linha de folha de propriedades, as guias serão empilhados de várias linhas. Para desabilitar o empilhamento, chame [CPropertySheet::EnableStackedTabs](../mfc/reference/cpropertysheet-class.md#enablestackedtabs) com o parâmetro definido como **falso**. Você deve chamar `EnableStackedTabs` quando você cria a folha de propriedades.

1. Chame [CPropertySheet::DoModal](../mfc/reference/cpropertysheet-class.md#domodal) ou [criar](../mfc/reference/cpropertysheet-class.md#create) para exibir a folha de propriedades. Chamar `DoModal` para criar uma folha de propriedades como uma caixa de diálogo modal. Chame **criar** para criar a folha de propriedades como uma caixa de diálogo sem janela restrita.

1. Trocar dados entre páginas de propriedade e o proprietário da folha de propriedades. Isso é explicado no artigo [trocando dados](../mfc/exchanging-data.md).

Para obter um exemplo de como usar as folhas de propriedades, consulte o exemplo de MFC geral [PROPDLG](../overview/visual-cpp-samples.md).

## <a name="see-also"></a>Consulte também

[Folhas de propriedades](../mfc/property-sheets-mfc.md)
