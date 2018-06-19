---
title: Usando folhas de propriedade em seu aplicativo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 74e63faf5b1cac5e0cb841a28fd59ecee47c9970
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33383887"
---
# <a name="using-property-sheets-in-your-application"></a>Usando folhas de propriedade no aplicativo
Para usar uma folha de propriedades em seu aplicativo, conclua as seguintes etapas:  
  
1.  Crie um recurso de modelo de caixa de diálogo para cada página de propriedades. Tenha em mente que o usuário pode ser alternar de uma página para outra, para colocar cada página como consistentemente possível.  
  
     Os modelos de caixa de diálogo para todas as páginas não precisa ter o mesmo tamanho. A estrutura usa o tamanho da página do maior para determinar a quantidade de espaço para alocar na folha de propriedades para as páginas de propriedade.  
  
     Quando você cria o recurso de modelo de caixa de diálogo para uma página de propriedades, você deve especificar os seguintes estilos na folha de propriedades da caixa de diálogo de propriedades:  
  
    -   Definir o **legenda** caixa de edição de **geral** página para o texto que você deseja aparecem na guia para essa página.  
  
    -   Definir o **estilo** caixa de listagem no **estilos** página para **filho**.  
  
    -   Definir o **borda** caixa de listagem no **estilos** página para **fina**.  
  
    -   Certifique-se de que o **Titlebar** caixa de seleção de **estilos** página está selecionada.  
  
    -   Certifique-se de que o **desabilitado** caixa de seleção de **mais estilos** página está selecionada.  
  
2.  Criar um [CPropertyPage](../mfc/reference/cpropertypage-class.md)-correspondente para cada modelo de caixa de diálogo de página de propriedade de classe derivada. Consulte [adicionando uma classe](../ide/adding-a-class-visual-cpp.md). Escolha `CPropertyPage` como a classe base.  
  
3.  Crie variáveis para armazenar os valores para esta página de propriedades de membro. O processo para adicionar variáveis de membro para uma página de propriedades é exatamente o mesmo que adicionar variáveis de membro para uma caixa de diálogo, como uma página de propriedades é uma caixa de diálogo especializada. Para obter mais informações, consulte [definindo variáveis de membro para controles de caixa de diálogo](../windows/defining-member-variables-for-dialog-controls.md).  
  
4.  Construir um [CPropertySheet](../mfc/reference/cpropertysheet-class.md) objeto em seu código-fonte. Normalmente, você pode criar o `CPropertySheet` objeto no manipulador para o comando que exibe a folha de propriedades. Esse objeto representa a folha de propriedade de inteiro. Se você criar uma folha de propriedades modal com o [DoModal](../mfc/reference/cpropertysheet-class.md#domodal) função, o framework fornece três botões de comando por padrão: Okey, cancelar e aplicar. A estrutura não cria nenhum botões de comando para folhas de propriedades sem janela restrita criado com o [criar](../mfc/reference/cpropertysheet-class.md#create) função. Você não precisa derivar uma classe de `CPropertySheet` , a menos que você deseja adicionar outros controles (como uma janela de visualização) ou exibir uma folha de propriedades sem janela restrita. Esta etapa é necessária para folhas de propriedades sem janela restrita porque não contêm todos os controles padrão que podem ser usados para fechar a folha de propriedades.  
  
5.  Para cada página a ser adicionada para a folha de propriedades, faça o seguinte:  
  
    -   Construir um objeto para cada `CPropertyPage`-derivada da classe que você criou anteriormente neste processo.  
  
    -   Chamar [CPropertySheet::AddPage](../mfc/reference/cpropertysheet-class.md#addpage) para cada página.  
  
     Normalmente, o objeto que cria o `CPropertySheet` também cria o `CPropertyPage` objetos nesta etapa. No entanto, se você implementar um `CPropertySheet`-derivado da classe, você pode inserir o `CPropertyPage` objetos no `CPropertySheet` objeto e chame `AddPage` para cada página do `CPropertySheet`-derivado do construtor de classe. `AddPage` Adiciona o `CPropertyPage` o objeto para a lista da folha de propriedades de páginas, mas não cria realmente a janela para a página. Portanto, não é necessário aguardar até que a criação da janela de folha de propriedade para chamar `AddPage`; você pode chamar `AddPage` de construtor da folha de propriedades.  
  
     Por padrão, se uma folha de propriedades tem mais guias cabem em uma única linha da folha de propriedades, as guias serão empilhados em várias linhas. Para desabilitar a pilha, chame [CPropertySheet::EnableStackedTabs](../mfc/reference/cpropertysheet-class.md#enablestackedtabs) com o parâmetro definido **FALSE**. Você deve chamar `EnableStackedTabs` quando você cria a folha de propriedades.  
  
6.  Chamar [CPropertySheet::DoModal](../mfc/reference/cpropertysheet-class.md#domodal) ou [criar](../mfc/reference/cpropertysheet-class.md#create) para exibir a folha de propriedades. Chamar `DoModal` para criar uma folha de propriedades como uma caixa de diálogo modal. Chamar **criar** para criar a folha de propriedades como uma caixa de diálogo sem janela restrita.  
  
7.  Trocar dados entre páginas de propriedade e o proprietário da folha de propriedades. Isso é explicado no artigo [trocando dados](../mfc/exchanging-data.md).  
  
 Para obter um exemplo de como usar folhas de propriedades, consulte o exemplo de MFC geral [PROPDLG](../visual-cpp-samples.md).  
  
## <a name="see-also"></a>Consulte também  
 [Folhas de propriedade](../mfc/property-sheets-mfc.md)

