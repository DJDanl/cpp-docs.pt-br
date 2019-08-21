---
title: Adicionando um controle (Tutorial ATL, parte 2)
ms.custom: get-started-article
ms.date: 08/19/2019
ms.assetid: c9575a75-1064-41f1-9697-7aada560c669
ms.openlocfilehash: b7952f42b24c4211a2c44ea71fd17e4f65c3421a
ms.sourcegitcommit: 9d4ffb8e6e0d70520a1e1a77805785878d445b8a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/20/2019
ms.locfileid: "69630705"
---
# <a name="adding-a-control-atl-tutorial-part-2"></a>Adicionando um controle (Tutorial ATL, parte 2)

Nesta etapa, você adiciona um controle ao seu projeto, cria-o e testa-o em uma página da Web.

## <a name="procedures"></a>Procedimentos

### <a name="to-add-an-object-to-an-atl-project"></a>Para adicionar um objeto a um projeto ATL

1. No **Gerenciador de Soluções**, clique com o botão direito do mouse no projeto `Polygon`.

1. Aponte para **Adicionar** no menu de atalho e clique em **novo item** no submenu.

    A caixa de diálogo **Adicionar Novo Item** é exibida. As diferentes categorias de objeto são listadas na estrutura de árvore à esquerda.

1. Clique na pasta **ATL** .

1. Na lista de modelos à direita, selecione **controle ATL**. Clique em **Adicionar** . O assistente de **controle do ATL** será aberto e você poderá configurar o controle.

1. Digite `PolyCtl` como o nome curto e observe que os outros campos são automaticamente concluídos. Não clique em **concluir** ainda, porque você deve fazer mais alterações.

A página **nomes** do assistente de **controle do ATL** contém os seguintes campos:

|Campo|Conteúdo|
|-----------|--------------|
|**Nome curto**|O nome que você inseriu para o controle.|
|**Class**|O C++ nome da classe criada para implementar o controle.|
|**Arquivo .h**|O arquivo criado para conter a definição da C++ classe.|
|**Arquivo .cpp**|O arquivo criado para conter a implementação da C++ classe.|
|**CoClass**|O nome da classe de componente para este controle.|
|**Interface**|O nome da interface na qual o controle irá implementar seus métodos e propriedades personalizados.|
|**Tipo**|Uma descrição para o controle.|
|**ProgID**|O nome legível que pode ser usado para pesquisar o CLSID do controle.|

Você encontrará várias configurações adicionais que devem ser alteradas no assistente de **controle do ATL** .

### <a name="to-enable-support-for-rich-error-information-and-connection-points"></a>Para habilitar o suporte para informações de erro e pontos de conexão avançados

1. Clique em **Opções** para abrir a página **Opções** .

1. Marque a caixa de seleção **pontos de conexão** . Essa opção cria suporte para uma interface de saída no arquivo IDL.

Você também pode adicionar interfaces para estender a funcionalidade do controle.

### <a name="to-extend-the-controls-functionality"></a>Para estender a funcionalidade do controle

1. Clique em **interfaces** para abrir a página **interfaces** .

1. Selecione `IProvideClassInfo2` e clique na seta para **cima** para movê-la para a lista **com suporte** .

1. Selecione `ISpecifyPropertyPages` e clique na seta para **cima** para movê-la para a lista **com suporte** .

Você também pode tornar o controle *inserível*, o que significa que ele é incorporável em aplicativos que dão suporte a objetos incorporados, como o Excel ou o Word.

### <a name="to-make-the-control-insertable"></a>Para tornar o controle que deve ser inserido

1. Clique em **aparência** para abrir a página **aparência** .

1. Marque a caixa de seleção **Inserir** .

O polígono exibido pelo objeto terá uma cor de preenchimento sólida, portanto, você precisa adicionar uma `Fill Color` Propriedade stock.

### <a name="to-add-a-fill-color-stock-property-and-create-the-control"></a>Para adicionar uma propriedade stock de cor de preenchimento e criar o controle

1. Clique em **Propriedades de ações** para abrir a página de propriedades de **ações** .

1. Em **sem suporte**, role para baixo na lista de possíveis propriedades de ações. Selecione `Fill Color` e clique na seta para **cima** para movê-la para a lista **com suporte** .

1. Escolha **Concluir**.

À medida que o assistente cria o controle, ocorrem várias alterações de código e adições de arquivos. Os seguintes arquivos são criados:

|Arquivo|Descrição|
|----------|-----------------|
|PolyCtl.h|Contém a maior parte da implementação da C++ classe `CPolyCtl`.|
|PolyCtl.cpp|Contém as partes restantes do `CPolyCtl`.|
|PolyCtl.rgs|Um arquivo de texto que contém o script de registro usado para registrar o controle.|
|PolyCtl.htm|Uma página da Web que contém uma referência ao controle recém-criado.|

O assistente também faz as seguintes alterações de código:

- Adiciona uma `#include` instrução aos arquivos de cabeçalho pré-compilados para incluir os arquivos ATL necessários para dar suporte a controles.

- Altera Polygon. idl para incluir detalhes do novo controle.

- Adiciona o novo controle ao mapa de objetos em Polygon. cpp.

Agora você pode criar o controle para vê-lo em ação.

## <a name="building-and-testing-the-control"></a>Compilação e teste do controle

### <a name="to-build-and-test-the-control"></a>Para compilar e testar o controle

1. No menu **Compilar** , clique em **Compilar polígono**.

    Quando o controle terminar de criar, clique com o botão direito do mouse em PolyCtl. htm em **Gerenciador de soluções** e selecione **Exibir no navegador**. A página da Web HTML que contém o controle é exibida. Você deve ver uma página com o título "ATL 8,0 Test Page for Object PolyCtl" e seu controle, o texto PolyCtl.

> [!NOTE]
> Se o controle não estiver visível, saiba que alguns navegadores exigem ajustes de configurações para executar controles ActiveX. Consulte a documentação do navegador sobre como habilitar controles ActiveX.

> [!NOTE]
> Ao concluir este tutorial, se você receber uma mensagem de erro informando que o arquivo DLL não pode ser criado, feche o arquivo PolyCtl. htm e o contêiner de teste do controle ActiveX e Compile a solução novamente. Se você ainda não conseguir criar a DLL, reinicialize o computador ou faça logoff se estiver usando os serviços de terminal.

Em seguida, você adicionará uma propriedade personalizada ao controle.

[Voltar para a etapa 1](../atl/creating-the-project-atl-tutorial-part-1.md) &#124; [Na etapa 3](../atl/adding-a-property-to-the-control-atl-tutorial-part-3.md)

## <a name="see-also"></a>Consulte também

[Tutorial](../atl/active-template-library-atl-tutorial.md)
