---
title: Adicionando uma página de propriedades (ATL Tutorial, parte 6) | Microsoft Docs
ms.custom: get-started-article
ms.date: 09/27/2018
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: df80d255-e7ea-49d9-b940-3f012e90cf9b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 00390f5a5872c183fdea385158dfa5020362a06f
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50055054"
---
# <a name="adding-a-property-page-atl-tutorial-part-6"></a>Adicionando uma página de propriedades (Tutorial ATL, parte 6)

Páginas de propriedades são implementadas como objetos COM separado, que permitem que eles sejam compartilhados se necessário. Nesta etapa, você fará as seguintes tarefas para adicionar uma página de propriedades para o controle:

- Criando o recurso de página de propriedade

- Adicionando código para criar e gerenciar a página de propriedades

- Adicionando a página de propriedades ao controle

## <a name="creating-the-property-page-resource"></a>Criando o recurso de página de propriedade

Para adicionar uma página de propriedades para seu controle, use o modelo de página de propriedades ATL.

### <a name="to-add-a-property-page"></a>Para adicionar uma página de propriedades

1. Na **Gerenciador de soluções**, clique com botão direito `Polygon`.

1. No menu de atalho, clique em **Add** > **Novo Item**.

1. Na lista de modelos, selecione **ATL** > **página de propriedades ATL** e clique em **Add**.

1. Quando o **Assistente de página de propriedades ATL** for exibida, insira *PolyProp* como o **curto** nome.

1. Clique em **cadeias de caracteres** para abrir o **cadeias de caracteres** da página e insira **& polígono** como o **título**.

   O **título** da propriedade de página é a cadeia de caracteres que aparece na guia para a página. O **cadeia de caracteres Doc** é uma descrição que um quadro de propriedade usa para colocar em uma dica de ferramenta ou de linha de status. Observe que o quadro de propriedades padrão no momento, não usa essa cadeia de caracteres, portanto, você pode deixá-lo com o conteúdo padrão. Você não irá gerar uma **arquivo de Ajuda** no momento, por isso, exclua a entrada na caixa de texto.

1. Clique em **concluir**, e o objeto de página de propriedade será criado.

São criados três arquivos a seguir:

|Arquivo|Descrição|
|----------|-----------------|
|PolyProp.h|Contém a classe C++ `CPolyProp`, que implementa a página de propriedades.|
|PolyProp.cpp|Inclui o arquivo PolyProp.h.|
|PolyProp.rgs|O script de registro que registra o objeto de página de propriedade.|

Também são feitas as alterações de código a seguir:

- A nova página de propriedade é adicionada ao mapa de entrada de objeto em Polygon.

- O `PolyProp` classe é adicionada ao arquivo Polygon.idl.

- O novo arquivo de script de registro PolyProp.rgs é adicionado para o recurso do projeto.

- Um modelo de caixa de diálogo é adicionado para o recurso de projeto para a página de propriedades.

- As cadeias de caracteres de propriedade que você especificou são adicionadas à tabela de cadeia de caracteres de recursos.

Agora adicione os campos que você deseja que apareça na página de propriedades.

### <a name="to-add-fields-to-the-property-page"></a>Para adicionar campos à página de propriedades

1. Na **Gerenciador de soluções**, clique duas vezes no arquivo de recurso Polygon.rc. Isso abrirá **exibição de recurso**.

1. Na **exibição de recurso**, expanda o `Dialog` nó e clique duas vezes em `IDD_POLYPROP`. Observe que a caixa de diálogo que aparece é vazia, exceto por um rótulo que você insira aqui seus controles.

1. Selecione o rótulo e alterá-lo para ler `Sides:` alterando as **legenda** texto no **propriedades** janela.

1. Redimensione a caixa de rótulo para que ele se ajusta o tamanho do texto.

1. Arraste uma **controle de edição** da **caixa de ferramentas** à direita do rótulo.

1. Por fim, altere o **identificação** do controle de edição para `IDC_SIDES` usando o **propriedades** janela.

Isso conclui o processo de criação do recurso de página de propriedade.

## <a name="adding-code-to-create-and-manage-the-property-page"></a>Adicionando código para criar e gerenciar a página de propriedades

Agora que você criou o recurso de página de propriedade, você precisa escrever o código de implementação.

Primeiro, habilite a `CPolyProp` classe para definir o número de lados em seu objeto quando o **aplicar** é pressionado.

### <a name="to-modify-the-apply-function-to-set-the-number-of-sides"></a>Para modificar a função Apply para definir o número de lados

1. Substitua o `Apply` função em PolyProp.h com o código a seguir:

    [!code-cpp[NVC_ATL_Windowing#58](../atl/codesnippet/cpp/adding-a-property-page-atl-tutorial-part-6_1.h)]

Uma página de propriedade pode ter mais de um cliente conectado a ele ao mesmo tempo, portanto, o `Apply` executa um loop em torno de função e chama `put_Sides` em cada cliente com o valor recuperado da caixa de edição. Você está usando o [CComQIPtr](../atl/reference/ccomqiptr-class.md) classe, que executa o `QueryInterface` em cada objeto para obter o `IPolyCtl` da interface do `IUnknown` interface (armazenados no `m_ppUnk` matriz).

O código agora verifica que a configuração de `Sides` propriedade funcionada. Se ele falhar, o código exibe uma caixa de mensagem exibindo detalhes do erro do `IErrorInfo` interface. Normalmente, um contêiner solicita um objeto para o `ISupportErrorInfo` interface e chama `InterfaceSupportsErrorInfo` primeiro para determinar se o objeto dá suporte a informações de erro de configuração. Você pode ignorar esta tarefa.

[CComPtr](../atl/reference/ccomptr-class.md) ajuda você a manipulando automaticamente a contagem de referência, portanto, você não precisará chamar `Release` na interface. `CComBSTR` ajuda você com o processamento de BSTR, para que você não precise executar o último `SysFreeString` chamar. Você também usar uma das várias classes de conversão de cadeia de caracteres, para que você possa converter o BSTR, se necessário (é por isso a macro definir USES_CONVERSION é o início da função).

Você também precisa definir o sinalizador da página de propriedade para indicar que o **aplicar** botão deve ser habilitado. Isso ocorre quando o usuário altera o valor de **lados** caixa de edição.

### <a name="to-handle-the-apply-button"></a>Para lidar com o botão Aplicar

1. Na **Class View**, clique com botão direito `CPolyProp` e clique em **propriedades** no menu de atalho.

1. No **propriedades** janela, clique no **eventos** ícone.

1. Expanda o `IDC_SIDES` nó na lista de eventos.

1. Selecione `EN_CHANGE`e no menu suspenso à direita, clique em  **\<Add > OnEnChangeSides**. O `OnEnChangeSides` declaração do manipulador será adicionada ao Polyprop.h e a implementação do manipulador para Polyprop.cpp.

Em seguida, você modificará o manipulador.

### <a name="to-modify-the-onenchangesides-method"></a>Para modificar o método OnEnChangeSides

1. Adicione o seguinte código no Polyprop.cpp para o `OnEnChangeSides` método (excluindo qualquer código que o Assistente de colocar aqui):

    [!code-cpp[NVC_ATL_Windowing#59](../atl/codesnippet/cpp/adding-a-property-page-atl-tutorial-part-6_2.cpp)]

`OnEnChangeSides` será chamado quando um `WM_COMMAND` mensagem é enviada com o `EN_CHANGE` notificação para o `IDC_SIDES` controle. `OnEnChangeSides` em seguida, chama `SetDirty` e passa TRUE para indicar que a página de propriedades agora está suja e o **aplicar** botão deve ser habilitado.

## <a name="adding-the-property-page-to-the-control"></a>Adicionando a página de propriedades ao controle

O modelo de página de propriedades ATL e o assistente não adicionam a página de propriedades para o controle para você automaticamente, porque pode haver vários controles em seu projeto. Você precisará adicionar uma entrada para mapa de propriedade do controle.

### <a name="to-add-the-property-page"></a>Para adicionar a página de propriedade

1. Abra o polyctl. H e adicione estas linhas ao mapa de propriedade:

    [!code-cpp[NVC_ATL_Windowing#60](../atl/codesnippet/cpp/adding-a-property-page-atl-tutorial-part-6_3.h)]

Mapa de propriedade do controle agora aparece desta forma:

[!code-cpp[NVC_ATL_Windowing#61](../atl/codesnippet/cpp/adding-a-property-page-atl-tutorial-part-6_4.h)]

Você poderia ter adicionado uma `PROP_PAGE` macro com o CLSID da sua página de propriedades, mas se você usar o `PROP_ENTRY` macro conforme mostrado, o `Sides` valor da propriedade também é salva quando o controle é salvo.

Os três parâmetros para a macro são a descrição da propriedade, o DISPID da propriedade e o CLSID da página de propriedades que tem a propriedade nele. Isso é útil se, por exemplo, você pode carregar o controle no Visual Basic e defina o número de lados em tempo de design. Como o número de lados é salva, quando você recarregar seu projeto do Visual Basic, o número de lados será restaurado.

## <a name="building-and-testing-the-control"></a>Compilar e testar o controle

Agora, compile esse controle e inseri-lo em um contêiner de teste do controle ActiveX. No **contêiner de teste**diante a **editar** menu, clique em **objeto da classe PolyCtl**. A página de propriedades é exibida com as informações que você adicionou.

O **aplicar** botão é inicialmente desabilitado. Comece a digitar um valor na **lados** caixa e o **aplicar** botão será habilitado. Depois de terminar de inserir o valor, clique no **aplicar** botão. As alterações de exibição de controle e o **aplicar** botão está desabilitado novamente. Tente inserir um valor inválido. Você verá uma caixa de mensagem que contém a descrição do erro que você definir no `put_Sides` função.

Em seguida, você colocará seu controle em uma página da Web.

[Volte para a etapa 5](../atl/adding-an-event-atl-tutorial-part-5.md) &#124; [para a etapa 7](../atl/putting-the-control-on-a-web-page-atl-tutorial-part-7.md)

## <a name="see-also"></a>Consulte também

[Tutorial](../atl/active-template-library-atl-tutorial.md)
