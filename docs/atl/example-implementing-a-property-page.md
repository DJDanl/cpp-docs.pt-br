---
title: "Exemplo: implementando uma p&#225;gina de propriedades | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "páginas de propriedades, implementando"
ms.assetid: c30b67fe-ce08-4249-ae29-f3060fa8d61e
caps.latest.revision: 14
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Exemplo: implementando uma p&#225;gina de propriedades
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este exemplo mostra como criar uma página de propriedades que exibe \(e permite que você altere\) propriedades de interface de [Classes de documento](../mfc/document-classes.md) .  Essa interface é exposto por documentos em [Common Environment Object Model Examples](../Topic/Common%20Environment%20Object%20Model%20Examples.md) Visual Studio \(embora a página de propriedades que você criará se não irá importar de onde ele manipulam objetos provenientes como suportam a interface correta\).  
  
 o exemplo é baseado em [exemplo de ATLPages](../top/visual-cpp-samples.md).  
  
 Para concluir este exemplo, você:  
  
-   [Adicionar a classe da página de propriedades de ATL](#vcconusing_the_atl_object_wizard) usando a caixa de diálogo da classe e adicionar o assistente da página de propriedades de ATL.  
  
-   [Edite o recurso da caixa de diálogo](#vcconediting_the_dialog_resource) adicionando novos controles para as propriedades interessantes de interface de **Documento** .  
  
-   [adicionar manipuladores de mensagem](#vcconadding_message_handlers) para manter o site da página de propriedades informada das alterações feitas pelo usuário.  
  
-   Adicione algumas declarações de `#import` e um typedef na seção de [tarefas domésticas](#vcconhousekeeping) .  
  
-   [Substitua IPropertyPageImpl::SetObjects](#vcconoverriding_ipropertypageimpl_setobjects) para validar os objetos que estão sendo passados para a página de propriedades.  
  
-   [substituição IPropertyPageImpl::Activate](#vcconoverriding_ipropertypageimpl_activate) para inicializar a interface da página de propriedades.  
  
-   [substituição IPropertyPageImpl::Apply](#vcconoverride_ipropertypageimpl_apply) para atualizar o objeto com os valores de propriedade os últimos.  
  
-   [exibir a página de propriedades](#vccontesting_the_property_page) criando um objeto auxiliar simples.  
  
-   [Crie uma macro](#vcconcreating_a_macro) que irá testar a página de propriedades.  
  
##  <a name="vcconusing_the_atl_object_wizard"></a> Adicionando a classe da página de propriedades de ATL  
 Primeiro, crie um novo projeto de ATL para um servidor de DLL chamado `ATLPages7`.  Use agora [Assistente da página de propriedades de ATL](../atl/reference/atl-property-page-wizard.md) para gerar uma página de propriedades.  Execute a página de propriedades de **Nome curto** de **DocProperties** então alterne para a página de **Cadeias de caracteres** aos itens propriedade\-página\- específicos definidos como mostrado na tabela abaixo.  
  
|Item|Valor|  
|----------|-----------|  
|Nome|TextDocument|  
|Cadeia de caracteres de Doc|Propriedades de VCUE TextDocument|  
|Helpfile|*\<blank\>*|  
  
 Os valores que você configurou em esta página do assistente será retornado para o contêiner da página de propriedades quando chamar **IPropertyPage::GetPageInfo**.  O que acontece a cadeias de caracteres em seguida que é dependente no contêiner, mas será normalmente usado para identificar sua página para o usuário.  O título aparecerá geralmente em uma guia acima da página e a cadeia de caracteres de Doc pode ser exibida em uma barra de status ou em uma dica de ferramenta \(embora o quadro de propriedade padrão não usa essa cadeia de caracteres de qualquer\).  
  
> [!NOTE]
>  As cadeias de caracteres que você definir aqui é armazenado como recursos de cadeia de caracteres em seu projeto pelo assistente.  Você pode facilmente editar estas cadeias de caracteres usando o editor de recursos se você precisar alterar essa informação após o código para a página foi gerado.  
  
 Clique **OK** para que o assistente gere sua página de propriedades.  
  
##  <a name="vcconediting_the_dialog_resource"></a> Editando o recurso da caixa de diálogo  
 Agora que a página de propriedades foi gerada, você precisará adicionar alguns controles ao recurso da caixa de diálogo que representa sua página.  Adicione uma caixa de edição, um controle de texto estático, e uma caixa de seleção e defina seus IDs como mostrado abaixo:  
  
 ![Recurso de diálogo de edição do Visual Studio](../atl/media/ppgresourcelabeled.png "PPGResourceLabeled")  
  
 Esses controles serão usados para exibir o nome de arquivo do documento e de seu status somente leitura.  
  
> [!NOTE]
>  O recurso da caixa de diálogo não inclui um quadro ou botões de comando, ou terá o aspecto com guias que você pode ter esperado.  Esses recursos são fornecidos por um quadro da página de propriedades como o criado chamando [OleCreatePropertyFrame](http://msdn.microsoft.com/library/windows/desktop/ms678437).  
  
##  <a name="vcconadding_message_handlers"></a> Adicionando manipuladores de mensagem  
 Com os controles no lugar, você pode adicionar manipuladores de mensagem para atualizar o status sujo de página quando o valor de qualquer uma das alterações de controles:  
  
 [!code-cpp[NVC_ATL_Windowing#73](../atl/codesnippet/CPP/example-implementing-a-property-page_1.h)]  
  
 Esse código responde às alterações feitas ao controle ou para a caixa de seleção de edição chamando [IPropertyPageImpl::SetDirty](../Topic/IPropertyPageImpl::SetDirty.md), que informa ao site da página que a página foi alterado.  Normalmente o site da página irá responder ativar ou desativar um botão de **Aplicar** do elemento da página de propriedades.  
  
> [!NOTE]
>  Em suas próprias páginas de propriedades, você pode precisar manter controle com precisão que as propriedades foram alteradas pelo usuário para que você possa atualizar evitar as propriedades que não foram alteradas.  Implementa este exemplo de código que se para manter controle dos valores originais de propriedade e comparando com os valores atuais da interface do usuário quando é hora de aplicar as alterações.  
  
##  <a name="vcconhousekeeping"></a> Tarefas domésticas  
 Agora adicione um par instruções de `#import` a DocProperties.h de modo que o compilador saber sobre a interface de **Documento** :  
  
 [!code-cpp[NVC_ATL_Windowing#74](../atl/codesnippet/CPP/example-implementing-a-property-page_2.h)]  
  
 Você também precisará fazer referência à classe base de `IPropertyPageImpl` ; adicione o seguinte `typedef` a classe de **CDocProperties** :  
  
 [!code-cpp[NVC_ATL_Windowing#75](../atl/codesnippet/CPP/example-implementing-a-property-page_3.h)]  
  
##  <a name="vcconoverriding_ipropertypageimpl_setobjects"></a> Substituindo IPropertyPageImpl::SetObjects  
 O primeiro método de `IPropertyPageImpl` que você precisa substituir é [SetObjects](../Topic/IPropertyPageImpl::SetObjects.md).  Aqui você adicionará código para verificar de apenas um único objeto é passado e que oferece suporte à interface de **Documento** que você está aguardando:  
  
 [!code-cpp[NVC_ATL_Windowing#76](../atl/codesnippet/CPP/example-implementing-a-property-page_4.h)]  
  
> [!NOTE]
>  Faz sentido suporte somente um único objeto para essa página porque você permitirá que o usuário definia o nome de arquivo do objeto somente um arquivo pode existir em qualquer um local.  
  
##  <a name="vcconoverriding_ipropertypageimpl_activate"></a> Substituindo IPropertyPageImpl::Activate  
 A próxima etapa é inicializar a página de propriedades com valores de propriedade do objeto subjacente quando a página é criada primeiramente.  
  
 Em esse caso você deve adicionar os seguintes membros para a classe como você também irá usar os valores de propriedades iniciais para comparação quando os usuários da página aplicam as alterações:  
  
 [!code-cpp[NVC_ATL_Windowing#77](../atl/codesnippet/CPP/example-implementing-a-property-page_5.h)]  
  
 A implementação da classe base do método de [Ativar](../Topic/IPropertyPageImpl::Activate.md) é responsável para criar a caixa de diálogo e seus controles, então você pode substituir esse método e adicionar sua própria inicialização após chamar a classe base:  
  
 [!code-cpp[NVC_ATL_Windowing#78](../atl/codesnippet/CPP/example-implementing-a-property-page_6.h)]  
  
 Esse código usa os métodos de através da interface de **Documento** para obter as propriedades que você está interessado.  Usa nos wrappers da API do Win32 fornecidos por [CDialogImpl](../Topic/CDialogImpl%20Class.md) e por suas classes base para exibir os valores de propriedade para o usuário.  
  
##  <a name="vcconoverride_ipropertypageimpl_apply"></a> Substituindo IPropertyPageImpl::Apply  
 Quando os usuários desejam aplicar as alterações aos objetos, o site da página de propriedades chamar o método de [Aplicar](../Topic/IPropertyPageImpl::Apply.md) .  Este é o local para fazer o inverso de código em **Ativar** — enquanto **Ativar** recebe valores do objeto e introduziu os controles na página de propriedades, **Aplicar** recebe valores dos controles na página de propriedades e introdu\-los no objeto.  
  
 [!code-cpp[NVC_ATL_Windowing#79](../atl/codesnippet/CPP/example-implementing-a-property-page_7.h)]  
  
> [!NOTE]
>  A verificação contra [m\_bDirty](../Topic/IPropertyPageImpl::m_bDirty.md) no início da implementação é uma verificação inicial para evitar atualizações desnecessárias de objetos se **Aplicar** é chamado mais de uma vez.  Há também verificações com cada um dos valores de propriedade para garantir que somente as alterações conduzam a um chamada de método a **Documento**.  
  
> [!NOTE]
>  Expõe **FullName** de**Documento** como uma propriedade somente leitura.  Para atualizar o nome de arquivo do documento com base nas alterações feitas na página de propriedades, você precisa usar o método de **Salvar** para salvar o arquivo com um nome diferente.  Assim, o código em uma página de propriedades não tem que limitar\-se para obter ou definir a propriedades.  
  
##  <a name="vccontesting_the_property_page"></a> Exibindo a página de propriedades  
 Para exibir esta página, você precisará criar um objeto auxiliar simples.  O objeto auxiliar fornecerá um método que simplifica **OleCreatePropertyFrame** API para exibir uma única página conectada a um único objeto.  Este auxiliar será criado para que ele pode ser usado do Visual Basic.  
  
 Use [Adicione a caixa de diálogo de classe](../ide/add-class-dialog-box.md) e [Assistente simples de objeto de ATL](../atl/reference/atl-simple-object-wizard.md) para gerar uma nova classe e usar `Helper` como seu nome curto.  Uma vez criado, adicione um método conforme mostrado na tabela abaixo.  
  
|Item|Valor|  
|----------|-----------|  
|Nome do Método|`ShowPage`|  
|Parâmetros|`[in] BSTR bstrCaption, [in] BSTR bstrID, [in] IUnknown* pUnk`|  
  
 O parâmetro de `bstrCaption` é a legenda para ser exibida como o título da caixa de diálogo.  O parâmetro de `bstrID` é uma cadeia de caracteres que representa um CLSID ou um ProgID da página de propriedades para exibir.  O parâmetro de `pUnk` será o ponteiro de `IUnknown` do objeto cujas propriedades serão configuradas pela página de propriedades.  
  
 Implementar o método como mostrado abaixo:  
  
 [!code-cpp[NVC_ATL_Windowing#80](../atl/codesnippet/CPP/example-implementing-a-property-page_8.cpp)]  
  
##  <a name="vcconcreating_a_macro"></a> Criando uma macro  
 Depois de criar o projeto, você pode testar a página de propriedades e o objeto auxiliar usando uma macro simples que você pode criar e executar no ambiente de desenvolvimento Visual Studio.  Este macro criará um objeto auxiliar, então chama o método de **ShowPage** usando ProgID da página de propriedades de **DocProperties** e ponteiro de **IUnknown** de documento ativo no editor do Visual Studio.  o código que você precisa para este macro é mostrado abaixo:  
  
```  
Imports EnvDTE  
Imports System.Diagnostics  
  
Public Module AtlPages  
  
    Public Sub Test()  
        Dim Helper  
        Helper = CreateObject("ATLPages7.Helper.1")  
  
        On Error Resume Next  
        Helper.ShowPage( _  
            ActiveDocument.Name, _  
            "ATLPages7Lib.DocumentProperties.1", _  
            DTE.ActiveDocument _  
            )  
    End Sub  
  
End Module  
```  
  
 Quando você executa esse macros, a página de propriedades será exibida mostrando o nome de arquivo e o status somente leitura do documento de texto atualmente ativa.  O estado de somente leitura do documento reflete somente a capacidade de gravar o documento no ambiente de desenvolvimento; não afeta o atributo somente\-leitura do arquivo no disco.  
  
## Consulte também  
 [Páginas de propriedade](../atl/atl-com-property-pages.md)   
 [exemplo de ATLPages](../top/visual-cpp-samples.md)