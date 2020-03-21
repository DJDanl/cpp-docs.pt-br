---
title: Adicionando uma página de propriedades (Tutorial ATL, parte 6)
ms.custom: get-started-article
ms.date: 09/27/2018
ms.assetid: df80d255-e7ea-49d9-b940-3f012e90cf9b
ms.openlocfilehash: 467ae19c372e24b2d368002cb83367b7087136fd
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80078764"
---
# <a name="adding-a-property-page-atl-tutorial-part-6"></a>Adicionando uma página de propriedades (Tutorial ATL, parte 6)

> [!NOTE]
> O assistente de Provedor OLE DB da ATL não está disponível no Visual Studio 2019 e posteriores.

As páginas de propriedades são implementadas como objetos COM separados, que permitem que eles sejam compartilhados se necessário. Nesta etapa, você realizará as seguintes tarefas para adicionar uma página de propriedades ao controle:

- Criação do recurso de página de propriedades

- Adição de código para criar e gerenciar a página de propriedades

- Adição da página de propriedades ao controle

## <a name="creating-the-property-page-resource"></a>Criação do recurso de página de propriedades

Para adicionar uma página de propriedades ao seu controle, use o modelo Página de Propriedades da ATL.

### <a name="to-add-a-property-page"></a>Adição de uma página de propriedades

1. No **Gerenciador de Soluções**, clique com o botão direito do mouse em `Polygon`.

1. No menu de atalho, clique em **Adicionar** > **Novo Item**.

1. Na lista de modelos, selecione **ATL** > **Página de Propriedades da ATL** e clique em **Adicionar**.

1. Quando o **Assistente de Página de Propriedades da ATL** for exibido, insira *PolyProp* como o nome **curto**.

1. Clique em **Cadeias de Caracteres** para abrir a página **Cadeias de Caracteres** e insira **&Polígono** como o **Título**.

   O **Título** da página de propriedades é a cadeia de caracteres que aparece na guia para essa página. O **Doc string** é uma descrição que um quadro de propriedades usa para colocar uma dica de ferramenta ou linha de status. Observe que o quadro de propriedades padrão atualmente não usa essa cadeia de caracteres, portanto, você pode deixá-lo com o conteúdo padrão. Você não vai gerar um **arquivo de Ajuda** no momento, por isso, exclua a entrada nessa caixa de texto.

1. Clique em **Concluir** e o objeto da página de propriedades será criado.

Os três arquivos seguintes são criados:

|Arquivo|DESCRIÇÃO|
|----------|-----------------|
|PolyProp.h|Contém a classe C++ `CPolyProp`, que implementa a página de propriedades.|
|PolyProp.cpp|Inclui o arquivo PolyProp.h.|
|PolyProp.rgs|O script de registro que registra o objeto da página de propriedades.|

As seguintes alterações no código também são feitas:

- A nova página de propriedades é adicionada ao mapa de entrada do objeto em Polygon.cpp.

- A classe `PolyProp` é adicionada ao arquivo Polygon.idl.

- O novo arquivo de script de registro PolyProp.rgs é adicionado ao recurso do projeto.

- Um modelo de caixa de diálogo é adicionado ao recurso do projeto para a página de propriedades.

- As cadeias de caracteres da propriedade que você especificou são adicionadas à tabela da cadeia de caracteres do recurso.

Agora adicione os campos que você quer que apareça na página de propriedades.

### <a name="to-add-fields-to-the-property-page"></a>Para adicionar campos à página de propriedades

1. No **Gerenciador de Soluções**, clique duas vezes no arquivo de recurso Polygon.rc. Isso abrirá o **Modo de Exibição de Recursos**.

1. No **Modo de Exibição de Recursos**, expanda o nó `Dialog` e clique duas vezes em `IDD_POLYPROP`. Observe que a caixa de diálogo que aparece está vazia, exceto por um rótulo informando para você inserir seus controles aqui.

1. Selecione esse rótulo e altere-o para `Sides:`, mudando o texto **Legenda** na janela **Propriedades**.

1. Redimensione a caixa de rótulo para que o texto caiba nela.

1. Arraste um **Controle de Edição** da **Caixa de Ferramentas** para a direita do rótulo.

1. Por fim, altere a **ID** do controle de edição para `IDC_SIDES` usando a janela **Propriedades**.

Isso conclui o processo de criação do recurso de página de propriedades.

## <a name="adding-code-to-create-and-manage-the-property-page"></a>Adição de código para criar e gerenciar a página de propriedades

Agora que você criou o recurso de página de propriedades, é preciso escrever o código de implementação.

Primeiro, habilite a classe `CPolyProp` para definir o número de lados em seu objeto quando o botão **Aplicar** for pressionado.

### <a name="to-modify-the-apply-function-to-set-the-number-of-sides"></a>Para modificar a função Aplicar para definir o número de lados

1. Substitua a função `Apply` em PolyProp.h pelo seguinte código:

    [!code-cpp[NVC_ATL_Windowing#58](../atl/codesnippet/cpp/adding-a-property-page-atl-tutorial-part-6_1.h)]

Uma página de propriedades pode ter mais de um cliente conectado a ela ao mesmo tempo, portanto, a função `Apply` executa loops e chama `put_Sides` em cada cliente com o valor recuperado da caixa de edição. Você está usando a classe [CComQIPtr](../atl/reference/ccomqiptr-class.md), que executa `QueryInterface` em cada objeto para obter a interface `IPolyCtl` da interface `IUnknown` (armazenada na matriz `m_ppUnk`).

O código agora verifica que a configuração da propriedade `Sides` funcionou. Em caso de falha, o código exibe uma caixa de mensagem mostrando detalhes do erro na interface `IErrorInfo`. Normalmente, um contêiner solicita um objeto para a interface `ISupportErrorInfo` e chama `InterfaceSupportsErrorInfo` primeiro, de modo a determinar se o objeto é compatível com a configuração de informações de erro. Você pode ignorar essa tarefa.

[CComPtr](../atl/reference/ccomptr-class.md) ajuda você tratando automaticamente da contagem de referência, de modo que não seja preciso chamar `Release` na interface. `CComBSTR` ajuda com o processamento de BSTR, para que você não precise executar a chamada final a `SysFreeString`. Use também uma das várias classes de conversão de cadeia de caracteres para que você possa converter o BSTR, se necessário (é por isso que a macro USES_CONVERSION está no início da função).

Você também precisa definir o sinalizador anormal da página de propriedades para indicar que o botão **Aplicar** deve ser habilitado. Isso ocorre quando o usuário altera o valor na caixa de edição **Lados**.

### <a name="to-handle-the-apply-button"></a>Manipulação do botão Aplicar

1. No **Modo de Exibição de Classe**, clique com botão direito em `CPolyProp` e clique em **Propriedades** no menu de atalho.

1. Na janela **Propriedades**, clique no ícone **Eventos**.

1. Expanda o nó `IDC_SIDES` na lista de eventos.

1. Selecione `EN_CHANGE` e, no menu suspenso à direita, clique em **\<Adicionar > OnEnChangeSides**. A declaração do manipulador `OnEnChangeSides` será adicionada ao Polyprop.h e a implementação do manipulador a Polyprop.cpp.

Em seguida, você modificará o manipulador.

### <a name="to-modify-the-onenchangesides-method"></a>Modificação do método OnEnChangeSides

1. Adicione o seguinte código em Polyprop.cpp ao método `OnEnChangeSides` (excluindo qualquer código colocado pelo assistente):

    [!code-cpp[NVC_ATL_Windowing#59](../atl/codesnippet/cpp/adding-a-property-page-atl-tutorial-part-6_2.cpp)]

`OnEnChangeSides` será chamado quando uma mensagem `WM_COMMAND` for enviada com a notificação `EN_CHANGE` para o controle `IDC_SIDES`. Então, `OnEnChangeSides` chama `SetDirty` e passa TRUE para indicar que a página de propriedades agora está suja e o botão **Aplicar** deve ser habilitado.

## <a name="adding-the-property-page-to-the-control"></a>Adição da página de propriedades ao controle

O modelo Página de Propriedades da ATL e o assistente não adicionam a página de propriedades ao controle para você automaticamente, pois pode haver vários controles em seu projeto. Você precisará adicionar uma entrada ao mapa de propriedade do controle.

### <a name="to-add-the-property-page"></a>Para adicionar a página de propriedades

1. Abra PolyCtl.h e adicione estas linhas ao mapa de propriedade:

    [!code-cpp[NVC_ATL_Windowing#60](../atl/codesnippet/cpp/adding-a-property-page-atl-tutorial-part-6_3.h)]

O mapa de propriedade do controle agora se parece com isto:

[!code-cpp[NVC_ATL_Windowing#61](../atl/codesnippet/cpp/adding-a-property-page-atl-tutorial-part-6_4.h)]

Você poderia ter adicionado uma macro `PROP_PAGE` com a CLSID da sua página de propriedades, mas se usasse a macro `PROP_ENTRY` conforme mostrado, o valor da propriedade `Sides` também seria salvo quando o controle fosse salvo.

Os três parâmetros para a macro são a descrição da propriedade, a DISPID da propriedade e a CLSID da página de propriedades que tem a propriedade nela. Isso será útil se, por exemplo, você carregar o controle no Visual Basic e definir o número de Lados em tempo de design. Como o número de Lados é salvo, quando você recarregar seu projeto do Visual Basic, o número de Lados será restaurado.

## <a name="building-and-testing-the-control"></a>Compilação e teste do controle

Agora compile esse controle e insira-o no Contêiner de Teste do Controle ActiveX. No **Contêiner de Teste**, no menu **Editar**, clique em **Objeto da Classe PolyCtl**. A página de propriedades é exibida com as informações que você adicionou.

O botão **Aplicar** está inicialmente desabilitado. Comece a digitar um valor na caixa **Lados** e o botão **Aplicar** será habilitado. Depois de terminar de inserir o valor, clique no botão **Aplicar**. A exibição do controle muda, e o botão **Aplicar** volta a ficar desabilitado. Tente inserir um valor inválido. Você verá uma caixa de mensagem contendo a descrição do erro definida na função `put_Sides`.

Em seguida, você colocará seu controle em uma página da Web.

[Voltar para a Etapa 5](../atl/adding-an-event-atl-tutorial-part-5.md) &#124; [Na Etapa 7](../atl/putting-the-control-on-a-web-page-atl-tutorial-part-7.md)

## <a name="see-also"></a>Confira também

[Tutorial](../atl/active-template-library-atl-tutorial.md)
