---
title: Implementando uma página de propriedades (ATL) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- property pages, implementing
ms.assetid: c30b67fe-ce08-4249-ae29-f3060fa8d61e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a4c7329e7784fc5228bca5aa5b167d04ded51aaf
ms.sourcegitcommit: 26fff80635bd1d51bc51899203fddfea8b29b530
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/05/2018
ms.locfileid: "37852259"
---
# <a name="example-implementing-a-property-page"></a>Exemplo: Implementando uma página de propriedades
Este exemplo mostra como criar uma página de propriedades que exibe as propriedades de (e permite que você altere uma) a [Classes de documento](../mfc/document-classes.md) interface.  
  
 O exemplo se baseia a [ATLPages exemplo](../visual-cpp-samples.md).  
  
 Para concluir este exemplo, você irá:  
  
- [Adicione a classe de página de propriedades ATL](#vcconusing_the_atl_object_wizard) usando a caixa de diálogo Adicionar classe e o Assistente de página de propriedades da ATL.  
  
- [Editar o recurso de caixa de diálogo](#vcconediting_the_dialog_resource) adicionando novos controles para as propriedades interessantes do `Document` interface.  
  
- [Adicionar manipuladores de mensagens](#vcconadding_message_handlers) manter o site da página de propriedade informado sobre alterações feitas pelo usuário.  
  
-   Adicione algum `#import` instruções e um typedef na [Housekeeping](#vcconhousekeeping) seção.  
  
- [Substituir IPropertyPageImpl::SetObjects](#vcconoverriding_ipropertypageimpl_setobjects) para validar os objetos que estão sendo passados para a página de propriedades.  
  
- [Substituir IPropertyPageImpl::Activate](#vcconoverriding_ipropertypageimpl_activate) inicializar a interface da página de propriedades.  
  
- [Substituir IPropertyPageImpl::Apply](#vcconoverride_ipropertypageimpl_apply) para atualizar o objeto com os valores de propriedade mais recentes.  
  
- [Exibir a página de propriedade](#vccontesting_the_property_page) , criando um objeto auxiliar simples.  
  
- [Criar uma macro](#vcconcreating_a_macro) que irá testar a página de propriedades.  
  
##  <a name="vcconusing_the_atl_object_wizard"></a> Adicionando a classe de página de propriedades ATL  
 Primeiro, crie um novo projeto ATL para um servidor DLL denominado `ATLPages7`. Agora use o [Assistente de página de propriedades ATL](../atl/reference/atl-property-page-wizard.md) para gerar uma página de propriedades. Dar a página de propriedades de um **nome curto** de **DocProperties** , em seguida, alterne para o **cadeias de caracteres** página definir itens específicos de páginas de propriedade, conforme mostrado na tabela a seguir.  
  
|Item|Valor|  
|----------|-----------|  
|Título|TextDocument|  
|Cadeia de caracteres doc|Propriedades de TextDocument VCUE|  
|Arquivo de ajuda|*\<em branco >*|  
  
 Os valores que podem ser definidas nesta página do assistente serão retornados para o contêiner de página de propriedade quando ele chama `IPropertyPage::GetPageInfo`. O que acontece com as cadeias de caracteres após o que é dependente no contêiner, mas normalmente serão usados para identificar sua página para o usuário. Geralmente, o título será exibido em uma guia acima de sua página e a cadeia de caracteres Doc podem ser exibida em uma barra de status ou dica de ferramenta (embora o quadro de propriedades padrão não usa essa cadeia de caracteres em todos os).  
  
> [!NOTE]
>  As cadeias de caracteres que você definiu aqui são armazenadas como recursos de cadeia de caracteres em seu projeto pelo assistente. Você pode editar facilmente essas cadeias de caracteres usando o editor de recursos se você precisar alterar essas informações após a geração de código para sua página.  
  
 Clique em **Okey** para que o Assistente para gerar a sua página de propriedades.  
  
##  <a name="vcconediting_the_dialog_resource"></a> O recurso de caixa de diálogo de edição  
 Agora que sua página de propriedades foi gerada, você precisará adicionar alguns controles para o recurso de caixa de diálogo que representa sua página. Adicione uma caixa de edição, um controle de texto estático e uma caixa de seleção e defina suas IDs, conforme mostrado abaixo:  
  
 ![Editando um recurso de caixa de diálogo](../atl/media/ppgresourcelabeled.gif "ppgresourcelabeled")  
  
 Esses controles serão usados para exibir o nome de arquivo do documento e seu status de somente leitura.  
  
> [!NOTE]
>  O recurso de caixa de diálogo não inclui um quadro ou comando botões nem tem a aparência com guias que você talvez esperasse. Esses recursos são fornecidos por um quadro de página de propriedade, como aquele criado chamando [OleCreatePropertyFrame](http://msdn.microsoft.com/library/windows/desktop/ms678437).  
  
##  <a name="vcconadding_message_handlers"></a> Adicionando manipuladores de mensagens  
 Com os controles em vigor, você pode adicionar manipuladores de mensagens para atualizar o status de falta de limpeza da página quando o valor de qualquer um dos controles é alterado:  
  
 [!code-cpp[NVC_ATL_Windowing#73](../atl/codesnippet/cpp/example-implementing-a-property-page_1.h)]  
  
 Esse código responde às alterações feitas no controle de edição ou a caixa de seleção chamando [IPropertyPageImpl::SetDirty](../atl/reference/ipropertypageimpl-class.md#setdirty), que informa ao site do que a página foi alterado. Normalmente o site da página responderá habilitando ou desabilitando uma **aplicar** botão no quadro de página de propriedade.  
  
> [!NOTE]
>  Em suas próprias páginas de propriedade, pode ser necessário controlar exatamente quais propriedades foram alteradas pelo usuário para que você pode evitar a atualização de propriedades que não foram alteradas. Este exemplo implementa esse código por manter o controle dos valores de propriedade originais e compará-los com os valores atuais da interface do usuário quando é hora de aplicar as alterações.  
  
##  <a name="vcconhousekeeping"></a> Manutenção do sistema  
 Agora adicione alguns `#import` instruções para DocProperties.h para que o compilador sabe sobre o `Document` interface:  
  
 [!code-cpp[NVC_ATL_Windowing#74](../atl/codesnippet/cpp/example-implementing-a-property-page_2.h)]  
  
 Você também precisará fazer referência a `IPropertyPageImpl` classe base; adicione o seguinte **typedef** para o `CDocProperties` classe:  
  
 [!code-cpp[NVC_ATL_Windowing#75](../atl/codesnippet/cpp/example-implementing-a-property-page_3.h)]  
  
##  <a name="vcconoverriding_ipropertypageimpl_setobjects"></a> Substituindo IPropertyPageImpl::SetObjects  
 A primeira `IPropertyPageImpl` é o método que você precisa substituir [SetObjects](../atl/reference/ipropertypageimpl-class.md#setobjects). Aqui, você adicionará código para verificar que apenas um único objeto foi passado e que ele oferece suporte a `Document` interface que você está esperando:  
  
 [!code-cpp[NVC_ATL_Windowing#76](../atl/codesnippet/cpp/example-implementing-a-property-page_4.h)]  
  
> [!NOTE]
>  Faz sentido para dar suporte a apenas um único objeto para esta página porque você permitirá que o usuário definir o nome de arquivo do objeto — apenas um arquivo pode existir em qualquer local.  
  
##  <a name="vcconoverriding_ipropertypageimpl_activate"></a> Substituindo IPropertyPageImpl::Activate  
 A próxima etapa é inicializar a página de propriedades com os valores de propriedade do objeto subjacente quando a página é criada pela primeira vez.  
  
 Nesse caso, você deve adicionar os seguintes membros à classe, pois você também usará os valores de propriedade inicial para comparação quando os usuários da página aplicar suas alterações:  
  
 [!code-cpp[NVC_ATL_Windowing#77](../atl/codesnippet/cpp/example-implementing-a-property-page_5.h)]  
  
 A implementação da classe base a [ativar](../atl/reference/ipropertypageimpl-class.md#activate) método é responsável por criar a caixa de diálogo e seus controles, para que você pode substituir esse método e adicionar seu próprios inicialização depois de chamar a classe base:  
  
 [!code-cpp[NVC_ATL_Windowing#78](../atl/codesnippet/cpp/example-implementing-a-property-page_6.h)]  
  
 Esse código usa os métodos de COM do `Document` interface para obter as propriedades que você está interessado. Ele usa os wrappers de API do Win32 fornecidos pelo [CDialogImpl](../atl/reference/cdialogimpl-class.md) e suas classes base para exibir os valores de propriedade para o usuário.  
  
##  <a name="vcconoverride_ipropertypageimpl_apply"></a> Substituindo IPropertyPageImpl::Apply  
 Quando os usuários desejam aplicar suas alterações aos objetos, o site da página de propriedade chamará o [aplicar](../atl/reference/ipropertypageimpl-class.md#apply) método. Este é o lugar para fazer o inverso do código em `Activate` —, enquanto `Activate` levou valores do objeto e enviados por push para os controles na página de propriedades, `Apply` usa os valores dos controles na página de propriedades e envia-los para o objeto.  
  
 [!code-cpp[NVC_ATL_Windowing#79](../atl/codesnippet/cpp/example-implementing-a-property-page_7.h)]  
  
> [!NOTE]
>  A verificação em relação a [m_bDirty](../atl/reference/ipropertypageimpl-class.md#m_bdirty) no início dessa implementação é uma verificação inicial para evitar atualizações desnecessárias de objetos se `Apply` é chamado mais de uma vez. Também há verificações em relação a cada um dos valores de propriedade para garantir que somente as alterações resultem em uma chamada de método para o `Document`.  
  
> [!NOTE]
> `Document` expõe `FullName` como uma propriedade somente leitura. Para atualizar o nome do arquivo do documento com base nas alterações feitas na página de propriedade, você precisa usar o `Save` método para salvar o arquivo com um nome diferente. Assim, o código em uma página de propriedades não precise se limitar ao obter ou definir propriedades.  
  
##  <a name="vccontesting_the_property_page"></a> Exibindo a página de propriedade  
 Para exibir esta página, você precisará criar um objeto auxiliar simples. O objeto auxiliar fornecerá um método que simplifica o `OleCreatePropertyFrame` API para a exibição de uma única página conectado a um único objeto. Esse auxiliar será criado para que possa ser usado no Visual Basic.  
  
 Use o [caixa de diálogo Adicionar classe](../ide/add-class-dialog-box.md) e o [ATL Simple Object Wizard](../atl/reference/atl-simple-object-wizard.md) para gerar uma nova classe e usar `Helper` como seu nome curto. Depois de criado, adicione um método, conforme mostrado na tabela a seguir.  
  
|Item|Valor|  
|----------|-----------|  
|Nome do método|`ShowPage`|  
|Parâmetros|`[in] BSTR bstrCaption, [in] BSTR bstrID, [in] IUnknown* pUnk`|  
  
 O *bstrCaption* parâmetro é a legenda a ser exibido como o título da caixa de diálogo. O *bstrID* parâmetro é uma cadeia de caracteres que representa um CLSID ou ProgID da página de propriedades para exibir. O *pUnk* parâmetro será o `IUnknown` ponteiro do objeto cujas propriedades serão definidas pela página de propriedades.  
  
 Implemente o método, conforme mostrado abaixo:  
  
 [!code-cpp[NVC_ATL_Windowing#80](../atl/codesnippet/cpp/example-implementing-a-property-page_8.cpp)]  
  
##  <a name="vcconcreating_a_macro"></a> Criando uma Macro  
 Depois que você criou o projeto, você pode testar a página de propriedades e o objeto auxiliar usando uma macro simple que você pode criar e executar no ambiente de desenvolvimento do Visual Studio. Essa macro criará um auxiliar de objeto, em seguida, chame seu `ShowPage` método usando o ProgID do **DocProperties** página de propriedades e o `IUnknown` ponteiro do documento ativo no momento no editor do Visual Studio. O código que necessário para esta macro é mostrado abaixo:  
  
```  
Imports EnvDTE  
Imports System.Diagnostics  
 
Public Module AtlPages  
 
    Public Sub Test()  
    Dim Helper  
    Helper = CreateObject("ATLPages7.Helper.1")  
 
    On Error Resume Next  
    Helper.ShowPage(_ 
    ActiveDocument.Name,
    _ 
 "ATLPages7Lib.DocumentProperties.1",
    _ 
    DTE.ActiveDocument _)  
    End Sub  
 
End Module  
```  
  
 Quando você executa essa macro, a página de propriedades será exibida mostrando o nome do arquivo e o status de somente leitura do documento de texto ativo no momento. O estado somente leitura do documento reflete somente a capacidade de gravar o documento no ambiente de desenvolvimento; ela não afeta o atributo somente leitura do arquivo no disco.  
  
## <a name="see-also"></a>Consulte também  
 [Páginas de propriedades](../atl/atl-com-property-pages.md)   
 [Exemplo de ATLPages](../visual-cpp-samples.md)

