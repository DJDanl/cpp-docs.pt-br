---
title: Implementação de uma página de propriedades (ATL)
ms.date: 05/09/2019
helpviewer_keywords:
- property pages, implementing
ms.assetid: c30b67fe-ce08-4249-ae29-f3060fa8d61e
ms.openlocfilehash: 688cd337d0754fc49ede0f39fd774c9990f7c79f
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87224351"
---
# <a name="example-implementing-a-property-page"></a>Exemplo: implementando uma página de propriedades

::: moniker range="vs-2019"

O assistente de Página de Propriedades da ATL não está disponível no Visual Studio 2019 e versões posteriores.

::: moniker-end

::: moniker range="<=vs-2017"

Este exemplo mostra como criar uma página de propriedades que exibe (e permite alterar) propriedades da interface [Classes de documento](../mfc/document-classes.md).

O exemplo se baseia na [amostra de ATLPages](../overview/visual-cpp-samples.md).

Para concluir este exemplo, você vai:

- [Adicionar a classe de página de propriedades da ATL](#vcconusing_the_atl_object_wizard) usando a caixa de diálogo Adicionar Classe e o Assistente de Página de Propriedades da ATL.

- [Editar o recurso de caixa de diálogo](#vcconediting_the_dialog_resource) adicionando novos controles para as propriedades interessantes da interface `Document`.

- [Adicionar manipuladores de mensagens](#vcconadding_message_handlers) para manter o site da página de propriedades informado sobre as alterações feitas pelo usuário.

- Adicionar algumas instruções `#import` e um typedef na seção [Manutenção](#vcconhousekeeping).

- [Substituir IPropertyPageImpl::SetObjects](#vcconoverriding_ipropertypageimpl_setobjects) para validar os objetos que estão sendo passados para a página de propriedades.

- [Substituir IPropertyPageImpl::Activate](#vcconoverriding_ipropertypageimpl_activate) para inicializar a interface da página de propriedades.

- [Substituir IPropertyPageImpl::Apply](#vcconoverride_ipropertypageimpl_apply) para atualizar o objeto com os valores de propriedade mais recentes.

- [Exibir a página de propriedades](#vccontesting_the_property_page) criando um objeto auxiliar simples.

- [Criar uma macro](#vcconcreating_a_macro) que testará a página de propriedades.

## <a name="adding-the-atl-property-page-class"></a><a name="vcconusing_the_atl_object_wizard"></a> Como adicionar a classe de página de propriedades da ATL

Primeiro, crie um novo projeto ATL para um servidor DLL denominado `ATLPages7`. Agora, use o [Assistente de Página de Propriedades da ATL](../atl/reference/atl-property-page-wizard.md) para gerar uma página de propriedades. Dê à página de propriedades um **Nome Curto** de **DocProperties**, em seguida, alterne para a página **Cadeias de Caracteres** para definir itens específicos da página de propriedades, conforme mostrado na tabela abaixo.

|Item|Valor|
|----------|-----------|
|Título|TextDocument|
|Doc String|Propriedades de TextDocument VCUE|
|Helpfile|*\<blank>*|

Os valores que você define nessa página do assistente serão retornados ao contêiner da página de propriedades quando ele chamar `IPropertyPage::GetPageInfo`. O que acontece com as cadeias de caracteres depois disso depende do contêiner, mas, normalmente, elas são usadas para identificar sua página para o usuário. Geralmente, o Título aparece em uma guia acima da sua página e o Doc String pode ser exibido em uma barra de status ou Dica de Ferramenta (embora o quadro da propriedade padrão não use essa cadeia de caracteres).

> [!NOTE]
> As cadeias de caracteres que você define aqui são armazenadas pelo assistente como recursos de cadeia de caracteres em seu projeto. É possível editar com facilidade essas cadeias de caracteres usando o editor de recursos se precisar alterar essas informações depois que o código da página tiver sido gerado.

Clique em **OK** para que o assistente gere a página de propriedades.

## <a name="editing-the-dialog-resource"></a><a name="vcconediting_the_dialog_resource"></a> Editando o recurso de caixa de diálogo

Agora que sua página de propriedades foi gerada, você precisará adicionar alguns controles ao recurso de caixa de diálogo que representem a página. Adicione uma caixa de edição, um controle de texto estático e uma caixa de seleção e defina as respectivas IDs, conforme mostrado abaixo:

![Editando um recurso de caixa de diálogo](../atl/media/ppgresourcelabeled.gif "Editando um recurso de caixa de diálogo")

Esses controles serão usados para exibir o nome de arquivo do documento e seu status somente leitura.

> [!NOTE]
> O recurso de caixa de diálogo não inclui um quadro ou botões de comando, e o seu layout não apresenta guias como talvez você esperasse. Esses recursos são fornecidos por um quadro de página de propriedades, como o que foi criado chamando [OleCreatePropertyFrame](/windows/win32/api/olectl/nf-olectl-olecreatepropertyframe).

## <a name="adding-message-handlers"></a><a name="vcconadding_message_handlers"></a> Como adicionar manipuladores de mensagens

Com os controles definidos, você pode adicionar manipuladores de mensagens para atualizar o status anormal da página quando o valor de qualquer um dos controles é alterado:

[!code-cpp[NVC_ATL_Windowing#73](../atl/codesnippet/cpp/example-implementing-a-property-page_1.h)]

Esse código responde às alterações feitas no controle de edição ou na caixa de seleção chamando [IPropertyPageImpl::SetDirty](../atl/reference/ipropertypageimpl-class.md#setdirty), que informa o site da página que a página foi alterada. Normalmente, o site da página responderá habilitando ou desabilitando um botão **Aplicar** no quadro da página de propriedades.

> [!NOTE]
> Em suas próprias páginas de propriedades, talvez você precise acompanhar quais propriedades precisamente foram alteradas pelo usuário para que seja possível evitar a atualização de propriedades que não foram alteradas. Este exemplo implementa esse código acompanhando os valores da propriedade original e comparando-os com os valores atuais da interface do usuário no momento de aplicar as alterações.

## <a name="housekeeping"></a><a name="vcconhousekeeping"></a> Manutenção

Agora, adicione algumas instruções `#import` a DocProperties.h para que o compilador saiba sobre a interface `Document`:

[!code-cpp[NVC_ATL_Windowing#74](../atl/codesnippet/cpp/example-implementing-a-property-page_2.h)]

Você também precisará se referir à `IPropertyPageImpl` classe base; adicione o seguinte **`typedef`** à `CDocProperties` classe:

[!code-cpp[NVC_ATL_Windowing#75](../atl/codesnippet/cpp/example-implementing-a-property-page_3.h)]

## <a name="overriding-ipropertypageimplsetobjects"></a><a name="vcconoverriding_ipropertypageimpl_setobjects"></a> Substituição de IPropertyPageImpl::SetObjects

O primeiro método `IPropertyPageImpl` que você precisa substituir é [SetObjects](../atl/reference/ipropertypageimpl-class.md#setobjects). Aqui, você adicionará código para verificar que apenas um único objeto foi passado e que ele é compatível com a interface `Document` que você está esperando:

[!code-cpp[NVC_ATL_Windowing#76](../atl/codesnippet/cpp/example-implementing-a-property-page_4.h)]

> [!NOTE]
> Faz sentido dar suporte apenas a um único objeto para essa página, pois você permitirá que o usuário defina o nome do arquivo do objeto – apenas um arquivo pode existir em qualquer local.

## <a name="overriding-ipropertypageimplactivate"></a><a name="vcconoverriding_ipropertypageimpl_activate"></a> Substituição de IPropertyPageImpl::Activate

A próxima etapa é inicializar a página de propriedades com os valores de propriedade do objeto subjacente quando a página é criada pela primeira vez.

Nesse caso, será preciso adicionar os seguintes membros à classe, uma vez que você também usará os valores iniciais da propriedade para comparação quando os usuários da página aplicarem as alterações:

[!code-cpp[NVC_ATL_Windowing#77](../atl/codesnippet/cpp/example-implementing-a-property-page_5.h)]

A implementação da classe base do método [Activate](../atl/reference/ipropertypageimpl-class.md#activate) é responsável por criar a caixa de diálogo e seus controles, de modo que você possa substituir esse método e adicionar sua própria inicialização após chamar a classe base:

[!code-cpp[NVC_ATL_Windowing#78](../atl/codesnippet/cpp/example-implementing-a-property-page_6.h)]

Esse código usa os métodos COM da interface `Document` para obter as propriedades em que você está interessado. Ele usa os wrappers de API do Win32 fornecidos por [CDialogImpl](../atl/reference/cdialogimpl-class.md) e suas classes base para exibir os valores de propriedade ao usuário.

## <a name="overriding-ipropertypageimplapply"></a><a name="vcconoverride_ipropertypageimpl_apply"></a> Substituição de IPropertyPageImpl::Apply

Quando os usuários quiserem aplicar suas alterações nos objetos, o site da página de propriedades chamará o método [Apply](../atl/reference/ipropertypageimpl-class.md#apply). Esse é o lugar para fazer o inverso do código em `Activate` – enquanto `Activate` extraiu valores do objeto e efetuou push deles nos controles da página de propriedades, `Apply` usa os valores dos controles na página de propriedades e os envia ao objeto.

[!code-cpp[NVC_ATL_Windowing#79](../atl/codesnippet/cpp/example-implementing-a-property-page_7.h)]

> [!NOTE]
> A verificação em relação a [m_bDirty](../atl/reference/ipropertypageimpl-class.md#m_bdirty) no início dessa implementação é uma verificação inicial para evitar atualizações desnecessárias de objetos se `Apply` for chamado mais de uma vez. Também há verificações em relação a cada um dos valores de propriedade para garantir que somente as alterações resultem em uma chamada de método para `Document`.

> [!NOTE]
> `Document` expõe `FullName` como uma propriedade somente leitura. Para atualizar o nome do arquivo do documento com base nas alterações feitas na página de propriedades, é preciso usar o método `Save` para salvar o arquivo com outro nome. Assim, o código em uma página de propriedades não precisa se limitar a obter ou definir propriedades.

## <a name="displaying-the-property-page"></a><a name="vccontesting_the_property_page"></a> Exibição da página de propriedades

Para exibir essa página, você precisa criar um objeto auxiliar simples. O objeto auxiliar fornecerá um método que simplifica a API `OleCreatePropertyFrame` para a exibição de uma única página conectada a um único objeto. Esse auxiliar será criado para que possa ser usado no Visual Basic.

Use a [caixa de diálogo Adicionar Classe](../ide/add-class-dialog-box.md) e o [Assistente de Objeto Simples de ATL](../atl/reference/atl-simple-object-wizard.md) para gerar uma nova classe e usar `Helper` como seu nome curto. Depois de criado, adicione um método, conforme mostrado na tabela abaixo.

|Item|Valor|
|----------|-----------|
|Nome do método|`ShowPage`|
|parâmetros|`[in] BSTR bstrCaption, [in] BSTR bstrID, [in] IUnknown* pUnk`|

O parâmetro *bstrCaption* é a legenda a ser exibida como o título da caixa de diálogo. O parâmetro *bstrID* é uma cadeia de caracteres que representa uma CLSID ou ProgID da página de propriedades a ser exibida. O parâmetro *pUnk* será o ponteiro `IUnknown` do objeto cujas propriedades serão definidas pela página de propriedades.

Implemente o método, conforme mostrado abaixo:

[!code-cpp[NVC_ATL_Windowing#80](../atl/codesnippet/cpp/example-implementing-a-property-page_8.cpp)]

## <a name="creating-a-macro"></a><a name="vcconcreating_a_macro"></a> Criação de uma macro

Após criação do projeto, você poderá testar a página de propriedades e o objeto auxiliar que está usando uma macro simples que pode ser criada e executada no ambiente de desenvolvimento do Visual Studio. Essa macro criará um objeto auxiliar e chamará seu método `ShowPage` usando ProgID da página de propriedades **DocProperties** e o ponteiro `IUnknown` do documento ativo no momento no editor do Visual Studio. O código necessário para essa macro é mostrado abaixo:

```vb
Imports EnvDTE
Imports System.Diagnostics

Public Module AtlPages

Public Sub Test()
    Dim Helper
    Helper = CreateObject("ATLPages7.Helper.1")

    On Error Resume Next
    Helper.ShowPage( ActiveDocument.Name, "ATLPages7Lib.DocumentProperties.1", DTE.ActiveDocument )
End Sub

End Module
```

Quando você executar essa macro, a página de propriedades será exibida mostrando o nome do arquivo e o status somente leitura do documento de texto ativo no momento. O estado somente leitura do documento reflete somente a capacidade de gravar no documento no ambiente de desenvolvimento; ele não afeta o atributo somente leitura do arquivo no disco.

::: moniker-end

## <a name="see-also"></a>Confira também

[Páginas de propriedade](../atl/atl-com-property-pages.md)<br/>
[Exemplo de páginas ATL](../overview/visual-cpp-samples.md)
