---
title: "Implementando uma página de propriedades (ATL) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: property pages, implementing
ms.assetid: c30b67fe-ce08-4249-ae29-f3060fa8d61e
caps.latest.revision: "14"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 04f2871af749091e97ec1731650f998739995781
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="example-implementing-a-property-page"></a>Exemplo: Implementando uma página de propriedades
Este exemplo mostra como criar uma página de propriedade que exibe (e permite que você altere) propriedades do [Classes de documento](../mfc/document-classes.md) interface.  
  
 O exemplo se baseia o [ATLPages exemplo](../visual-cpp-samples.md).  
  
 Para concluir este exemplo, você irá:  
  
- [Adicionar a classe de página de propriedades ATL](#vcconusing_the_atl_object_wizard) usando a caixa de diálogo Adicionar classe e o Assistente de página de propriedades ATL.  
  
- [Editar o recurso de caixa de diálogo](#vcconediting_the_dialog_resource) adicionando novos controles para as propriedades interessantes do **documento** interface.  
  
- [Adicionar manipuladores de mensagens](#vcconadding_message_handlers) manter o site de página de propriedade informados sobre as alterações feitas pelo usuário.  
  
-   Adicionar alguns `#import` instruções e um typedef no [Housekeeping](#vcconhousekeeping) seção.  
  
- [Substituir IPropertyPageImpl::SetObjects](#vcconoverriding_ipropertypageimpl_setobjects) para validar os objetos que está sendo passados para a página de propriedades.  
  
- [Substituir IPropertyPageImpl::Activate](#vcconoverriding_ipropertypageimpl_activate) inicializar a interface da página de propriedade.  
  
- [Substituir IPropertyPageImpl::Apply](#vcconoverride_ipropertypageimpl_apply) para atualizar o objeto com os valores de propriedade mais recentes.  
  
- [Exibir a página de propriedade](#vccontesting_the_property_page) criando um objeto auxiliar simples.  
  
- [Criar uma macro](#vcconcreating_a_macro) que testará a página de propriedades.  
  
##  <a name="vcconusing_the_atl_object_wizard"></a>Adicionar a classe de página de propriedades ATL  
 Primeiro, crie um novo projeto ATL para um servidor DLL chamado `ATLPages7`. Agora use o [Assistente de página de propriedades ATL](../atl/reference/atl-property-page-wizard.md) para gerar uma página de propriedades. Dê a página de propriedades uma **nome curto** de **DocProperties** , em seguida, alterne para o **cadeias de caracteres** página para definir itens específicos de páginas de propriedade, conforme mostrado na tabela a seguir.  
  
|Item|Valor|  
|----------|-----------|  
|Título|TextDocument|  
|Cadeia de caracteres do documento|Propriedades de TextDocument VCUE|  
|Arquivo de ajuda|*\<em branco >*|  
  
 Os valores que podem ser definidas nesta página do assistente serão retornados para o contêiner de página de propriedade quando ele chama **IPropertyPage::GetPageInfo**. O que acontece com as cadeias de caracteres depois que é dependente de contêiner, mas geralmente serão usados para identificar sua página para o usuário. O título geralmente será exibido em uma guia acima sua página e a cadeia de caracteres do documento podem ser exibida em uma barra de status ou dica de ferramenta (embora o quadro de propriedades padrão não usa essa cadeia de caracteres em todos os).  
  
> [!NOTE]
>  As cadeias de caracteres que você definir aqui são armazenadas como recursos de cadeia de caracteres em seu projeto pelo assistente. Você pode editar facilmente essas cadeias de caracteres usando o editor de recurso se você precisar alterar essas informações após a geração de código para a página.  
  
 Clique em **Okey** para que o Assistente para gerar a página de propriedades.  
  
##  <a name="vcconediting_the_dialog_resource"></a>O recurso de caixa de diálogo de edição  
 Agora que sua página de propriedades tiver sido gerada, você precisará adicionar alguns controles para o recurso de caixa de diálogo que representa a página. Adicione uma caixa de edição, um controle de texto estático e uma caixa de seleção e defina suas IDs, conforme mostrado abaixo:  
  
 ![Edição de um recurso de caixa de diálogo](../atl/media/ppgresourcelabeled.gif "ppgresourcelabeled")  
  
 Esses controles serão usados para exibir o nome de arquivo do documento e seu status de somente leitura.  
  
> [!NOTE]
>  O recurso de caixa de diálogo não inclui um quadro ou comando botões, nem tem a aparência com guias que você talvez esperasse. Esses recursos são fornecidos por um quadro de página de propriedade, como um criado chamando [OleCreatePropertyFrame](http://msdn.microsoft.com/library/windows/desktop/ms678437).  
  
##  <a name="vcconadding_message_handlers"></a>Adicionando manipuladores de mensagens  
 Com os controles em vigor, você pode adicionar manipuladores de mensagens para atualizar o status incorreto da página quando o valor de um dos controles alterado:  
  
 [!code-cpp[NVC_ATL_Windowing#73](../atl/codesnippet/cpp/example-implementing-a-property-page_1.h)]  
  
 Esse código responde às alterações feitas a caixa de seleção ou controle de edição chamando [IPropertyPageImpl::SetDirty](../atl/reference/ipropertypageimpl-class.md#setdirty), que informa que o site de página a página foi alterada. Normalmente a página do site responderá habilitando ou desabilitando um **aplicar** botão no quadro de página de propriedade.  
  
> [!NOTE]
>  Em suas próprias páginas de propriedade, pode ser necessário controlar exatamente quais propriedades foram alteradas pelo usuário para que você pode evitar a atualização de propriedades que não tenham sido alteradas. Este exemplo implementa esse código, mantendo o controle dos valores de propriedade original e compará-los com os valores atuais da interface do usuário quando ele é o tempo para aplicar as alterações.  
  
##  <a name="vcconhousekeeping"></a>Manutenção do sistema  
 Agora adicione algumas `#import` DocProperties.h instruções para que o compilador sabe sobre o **documento** interface:  
  
 [!code-cpp[NVC_ATL_Windowing#74](../atl/codesnippet/cpp/example-implementing-a-property-page_2.h)]  
  
 Você também precisará referir-se a `IPropertyPageImpl` classe base; adicione o seguinte `typedef` para o **CDocProperties** classe:  
  
 [!code-cpp[NVC_ATL_Windowing#75](../atl/codesnippet/cpp/example-implementing-a-property-page_3.h)]  
  
##  <a name="vcconoverriding_ipropertypageimpl_setobjects"></a>Substituindo IPropertyPageImpl::SetObjects  
 A primeira `IPropertyPageImpl` que você precisa substituir o método é [SetObjects](../atl/reference/ipropertypageimpl-class.md#setobjects). Aqui, você adicionará código para verificar que somente um único objeto foi passado e que ele oferece suporte a **documento** interface que você está esperando:  
  
 [!code-cpp[NVC_ATL_Windowing#76](../atl/codesnippet/cpp/example-implementing-a-property-page_4.h)]  
  
> [!NOTE]
>  Isso faz sentido para dar suporte a apenas um único objeto para esta página porque você permitirá que o usuário defina o nome do arquivo do objeto — pode existir apenas um arquivo em qualquer um dos locais.  
  
##  <a name="vcconoverriding_ipropertypageimpl_activate"></a>Substituindo IPropertyPageImpl::Activate  
 A próxima etapa é inicializar a página de propriedades com os valores de propriedade do objeto subjacente quando a página é criada.  
  
 Nesse caso, é necessário adicionar os membros a seguir à classe, desde que você também usará os valores de propriedade inicial para comparação quando os usuários da página aplicar suas alterações:  
  
 [!code-cpp[NVC_ATL_Windowing#77](../atl/codesnippet/cpp/example-implementing-a-property-page_5.h)]  
  
 A implementação da classe base a [ativar](../atl/reference/ipropertypageimpl-class.md#activate) método é responsável por criar a caixa de diálogo e controles, para que você pode substituir este método e adicionar seu próprios inicialização depois de chamar a classe base:  
  
 [!code-cpp[NVC_ATL_Windowing#78](../atl/codesnippet/cpp/example-implementing-a-property-page_6.h)]  
  
 Esse código usa os métodos COM o **documento** interface para obter as propriedades que você está interessado. Ele usa os wrappers de API do Win32 fornecidos pelo [CDialogImpl](../atl/reference/cdialogimpl-class.md) e suas classes base para exibir os valores de propriedade para o usuário.  
  
##  <a name="vcconoverride_ipropertypageimpl_apply"></a>Substituindo IPropertyPageImpl::Apply  
 Quando os usuários desejam aplicar suas alterações aos objetos, o site de página de propriedade chamará o [aplicar](../atl/reference/ipropertypageimpl-class.md#apply) método. Este é o local para fazer o inverso do código na **ativar** — enquanto **ativar** levou valores do objeto e enviados por push para os controles na página de propriedades, **aplicar** usa os valores dos controles na página de propriedades e envia-os para o objeto.  
  
 [!code-cpp[NVC_ATL_Windowing#79](../atl/codesnippet/cpp/example-implementing-a-property-page_7.h)]  
  
> [!NOTE]
>  A verificação [m_bDirty](../atl/reference/ipropertypageimpl-class.md#m_bdirty) no início dessa implementação é uma verificação inicial para impedir atualizações desnecessárias de objetos se **aplicar** é chamado mais de uma vez. Também há verifica cada um dos valores de propriedade para garantir que somente as alterações resultem em uma chamada de método para o **documento**.  
  
> [!NOTE]
> **Documento** expõe **FullName** como uma propriedade somente leitura. Para atualizar o nome do arquivo do documento com base nas alterações feitas na página de propriedade, você deve usar o **salvar** método para salvar o arquivo com um nome diferente. Assim, o código em uma página de propriedade não tem limite em si para obter ou definir propriedades.  
  
##  <a name="vccontesting_the_property_page"></a>Exibindo a página de propriedades  
 Para exibir esta página, você precisa criar um objeto auxiliar simples. O objeto auxiliar fornecem um método que simplifica o **OleCreatePropertyFrame** API para uma única página de exibição conectado a um único objeto. Este auxiliar será criada para que ele pode ser usado a partir do Visual Basic.  
  
 Use o [caixa de diálogo Adicionar classe](../ide/add-class-dialog-box.md) e [ATL Simple Object Wizard](../atl/reference/atl-simple-object-wizard.md) para gerar uma nova classe e usar `Helper` como seu nome curto. Depois de criado, adicione um método, conforme mostrado na tabela a seguir.  
  
|Item|Valor|  
|----------|-----------|  
|Nome do método|`ShowPage`|  
|Parâmetros|`[in] BSTR bstrCaption, [in] BSTR bstrID, [in] IUnknown* pUnk`|  
  
 O `bstrCaption` parâmetro é a legenda a ser exibido como o título da caixa de diálogo. O `bstrID` parâmetro é uma cadeia de caracteres que representa um CLSID ou ProgID da página de propriedades para exibir. O `pUnk` parâmetro será o `IUnknown` ponteiro do objeto cujas propriedades serão definidas pela página de propriedades.  
  
 Implemente o método, conforme mostrado abaixo:  
  
 [!code-cpp[NVC_ATL_Windowing#80](../atl/codesnippet/cpp/example-implementing-a-property-page_8.cpp)]  
  
##  <a name="vcconcreating_a_macro"></a>Criando uma Macro  
 Depois de criar o projeto, você pode testar a página de propriedades e o objeto auxiliar usando uma macro simples que você pode criar e executar no ambiente de desenvolvimento do Visual Studio. Esta macro criará um auxiliar de objeto, em seguida, chame seu **ShowPage** método usando o ProgID do **DocProperties** página de propriedades e o **IUnknown** ponteiro do documento atualmente ativas no editor do Visual Studio. O código que necessário para esta macro é mostrado abaixo:  
  
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
  
 Quando você executa esta macro, a página de propriedade será exibida, mostrando o nome do arquivo e o status de somente leitura do documento ativo no momento de texto. O estado somente leitura do documento somente reflete a capacidade de gravar o documento no ambiente de desenvolvimento; ela não afeta o atributo somente leitura do arquivo no disco.  
  
## <a name="see-also"></a>Consulte também  
 [Páginas de propriedade](../atl/atl-com-property-pages.md)   
 [Exemplo de ATLPages](../visual-cpp-samples.md)

