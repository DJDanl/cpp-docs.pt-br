---
title: Adicionando um controle (Tutorial ATL, parte 2)
ms.custom: get-started-article
ms.date: 09/26/2018
ms.assetid: c9575a75-1064-41f1-9697-7aada560c669
ms.openlocfilehash: 45841c33ad30ff427f9b792a779d135b4f6e7eca
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57283222"
---
# <a name="adding-a-control-atl-tutorial-part-2"></a>Adicionando um controle (Tutorial ATL, parte 2)

Nesta etapa, adicione um controle ao seu projeto, compilá-lo e testá-la em uma página da Web.

## <a name="procedures"></a>Procedimentos

### <a name="to-add-an-object-to-an-atl-project"></a>Para adicionar um objeto para um projeto ATL

1. Na **Gerenciador de soluções**, clique com botão direito do `Polygon` projeto.

1. Aponte para **Add** no menu de atalho e clique em **Novo Item** no submenu.

    A caixa de diálogo **Adicionar Novo Item** é exibida. As categorias diferentes de objeto são listadas na estrutura de árvore à esquerda.

1. Clique o **ATL** pasta.

1. Na lista de modelos à direita, selecione **controle ATL**. Clique em **Adicionar**. O **controle ATL** assistente será aberto e você pode configurar o controle.

1. Tipo `PolyCtl` como o nome curto e observe que os outros campos são concluídos automaticamente. Não clique **concluir** ainda, porque você precisa fazer algumas alterações.

O **controle ATL** do assistente **nomes** página contém os seguintes campos:

|Campo|Conteúdo|
|-----------|--------------|
|**Nome curto**|O nome que você inseriu para o controle.|
|**Class**|O nome da classe C++ criado para implementar o controle.|
|**Arquivo .h**|O arquivo criado para conter a definição da classe C++.|
|**Arquivo .cpp**|O arquivo criado para conter a implementação da classe C++.|
|**CoClass**|O nome da classe de componente para este controle.|
|**Interface**|O nome da interface na qual o controle implementará seus métodos e propriedades personalizados.|
|**Tipo**|Uma descrição para o controle.|
|**ProgID**|O nome legível que pode ser usado para procurar o CLSID do controle.|

Você precisará fazer várias configurações adicionais na **controle ATL** assistente.

### <a name="to-enable-support-for-rich-error-information-and-connection-points"></a>Para habilitar o suporte para pontos de conexão e informações de erros completa

1. Clique em **opções** para abrir o **opções** página.

1. Selecione o **pontos de Conexão** caixa de seleção. Isso criará o suporte para uma interface de saída no arquivo IDL.

Você também pode adicionar interfaces para estender a funcionalidade do controle.

### <a name="to-extend-the-controls-functionality"></a>Para estender a funcionalidade do controle

1. Clique em **Interfaces** para abrir o **Interfaces** página.

1. Selecione `IProvideClassInfo2` e clique em de **backup** seta para movê-la para o **com suporte** lista.

1. Selecione `ISpecifyPropertyPages` e clique em de **backup** seta para movê-la para o **com suporte** lista.

Você também pode fazer o controle insertable, o que significa que ele pode ser inserido em aplicativos que suportam objetos inseridos, como Excel ou Word.

### <a name="to-make-the-control-insertable"></a>Para tornar o controle inserível

1. Clique em **aparência** para abrir o **aparência** página.

1. Selecione o **inserível** caixa de seleção.

O polígono exibido pelo objeto terá uma cor de preenchimento sólida, portanto, você precisa adicionar um `Fill Color` propriedade de estoque.

### <a name="to-add-a-fill-color-stock-property-and-create-the-control"></a>Para adicionar uma propriedade de estoque de cor de preenchimento e criar o controle

1. Clique em **propriedades do estoque** para abrir o **propriedades do estoque** página.

1. Sob **não tem suporte**, role para baixo a lista de possíveis propriedades pré-definidas. Selecione `Fill Color` e clique em de **backup** seta para movê-la para o **com suporte** lista.

1. Isso conclui as opções para o controle. Clique em **Finalizar**.

Como o assistente criou o controle, várias alterações de código e adições de arquivos ocorreram. Os seguintes arquivos foram criados:

|Arquivo|Descrição|
|----------|-----------------|
|PolyCtl.h|Contém a maior parte da implementação da classe C++ `CPolyCtl`.|
|PolyCtl.cpp|Contém as partes restantes do `CPolyCtl`.|
|PolyCtl.rgs|Um arquivo de texto que contém o script de registro usado para registrar o controle.|
|PolyCtl.htm|Uma página da Web que contém uma referência ao controle recém-criado.|

O assistente também executou as seguintes alterações de código:

- Adicionado um `#include` instrução aos arquivos Stdafx. h e Stdafx. cpp para incluir a ATL arquivos necessária para dar suporte a controles.

- Polygon.idl alterada para incluir detalhes do novo controle.

- Adicionado o novo controle ao mapa de objeto em Polygon.

Agora você pode compilar o controle para vê-lo em ação.

## <a name="building-and-testing-the-control"></a>Compilar e testar o controle

### <a name="to-build-and-test-the-control"></a>Para compilar e testar o controle

1. Sobre o **construir** menu, clique em **compilar polígono**.

    Depois que o controle de build é concluído, clique com botão direito Polyctl na **Gerenciador de soluções** e selecione **exibir no navegador**. A página da HTML Web que contém o controle será exibida. Você deve ver uma página com o título "Página de ATL 8.0 de teste para o objeto PolyCtl" e o texto PolyCtl. Este é o seu controle.

> [!NOTE]
> Se o controle não estiver visível, sabe que alguns navegadores exigem ajustes de configurações para executar controles ActiveX. Consulte a documentação do navegador sobre como habilitar os controles ActiveX.

> [!NOTE]
> Ao concluir este tutorial, se você receber uma mensagem de erro onde o arquivo DLL não pode ser criado, feche o arquivo Polyctl htm e o contêiner de teste do controle ActiveX e crie a solução novamente. Se você ainda não é possível criar a DLL, reinicialize o computador ou fazer logoff (se você estiver usando os serviços de Terminal).

Em seguida, você adicionará uma propriedade personalizada ao controle.

[Volte para a etapa 1](../atl/creating-the-project-atl-tutorial-part-1.md) &#124; [na etapa 3](../atl/adding-a-property-to-the-control-atl-tutorial-part-3.md)

## <a name="see-also"></a>Consulte também

[Tutorial](../atl/active-template-library-atl-tutorial.md)
