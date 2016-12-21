---
title: "Assistente para adicionar classe MFC | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.codewiz.class.mfc.simple.overview"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Assistente para adicionar classe MFC"
  - "assistentes [MFC]"
ms.assetid: ad3b0989-d307-43b2-9417-3f9a78889024
caps.latest.revision: 16
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Assistente para adicionar classe MFC
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Use este assistente de código para adicionar uma classe em um projeto existente de MFC, ou para adicionar uma classe em um projeto de ATL que da suporte ao MFC.  Você também pode adicionar classes de MFC para projetos do Win32 que têm o suporte de MFC.  Os recursos que você especificou quando criou o projeto determina as opções disponíveis nesta caixa de diálogo.  
  
## Nomes  
 Nessa página, especifique o nome da classe, a classe base, e nomes de arquivos para a nova classe.  
  
 **Nome da classe**  
 Especifica o nome da nova classe e padrão fornece a base para os nomes das IDs e os arquivos nessa página.  C\+\+ das classes o início normalmente com C “2.0”, o que por exemplo, “CMyClass” se torna “MyClass.h”, e assim por diante.  
  
 **Classe Base**  
 Especifica o nome da classe base para a nova classe.  Por padrão, a classe base é [CWnd](../Topic/CWnd%20Class.md).  A classe base que você selecionar determina se outras caixas nessa página são ativas.  
  
 O tipo de classe é definido como a classe base determina se a classe tiver um ID da caixa de diálogo ou uma ID de recurso  Os tipos gerais de classes são os seguintes:  
  
-   Classes como [CButton](../../mfc/reference/cbutton-class.md), [CWnd](../Topic/CWnd%20Class.md), ou [CDocument](../Topic/CDocument%20Class.md), que não requerem uma ID de ID ou do recurso da caixa de diálogo  Essas classes não usam uma ID da caixa de diálogo ou de recursos  Se você selecionar uma dessas classes para a sua classe base, a caixa de **ID de Diálogo** e a caixa de **ID de recurso do DHTML** são escurecidas.  
  
-   Classes como [CDialog](../../mfc/reference/cdialog-class.md), [CFormView](../../mfc/reference/cformview-class.md), ou [CPropertyPage](../../mfc/reference/cpropertypage-class.md), o que exige uma ID da caixa de diálogo  
  
-   A classe [CDHtmlDialog](../Topic/CDHtmlDialog%20Class.md), que requer um ID da caixa de diálogo, uma ID de recurso do DHTML, e um nome de arquivo HTML.  
  
 Para classes que exigem uma ID da caixa de diálogo, você pode achar mais eficiente usar [Editor de recursos](../../mfc/resource-editors.md) para criar o recurso da caixa de diálogo, atribui o ID em [Janela Propriedades](../Topic/Properties%20Window.md), e cria uma classe associada à ID do recurso  Consulte [Criando uma nova caixa de diálogo](../../mfc/creating-a-new-dialog-box.md) para obter mais informações sobre como criar uma caixa de diálogo padrão do windows.  
  
> [!NOTE]
>  Se você criar um recurso da caixa de diálogo primeiro e derivar sua nova classe de `CDHtmlDialog`, exclua o windows padrão **OK** e os botões de **Cancelar** que aparecem na caixa de diálogo padrão.  A caixa de diálogo padrão do windows hospeda o formulário do DHTML, que contém seus próprios **OK** e botões de **Cancelar** .  
  
 Quando a caixa de diálogo pode conter controles do windows e controles do DHTML, não é recomendável.  
  
 **ID de Diálogo**  
 Especifica a ID da caixa de diálogo, se você selecionou `CDialog`, `CFormView`, `CPropertyPage`, ou `CDHtmlDialog` como **Classe Base**.  
  
 **arquivo .h**  
 Define o nome do arquivo de cabeçalho para a nova classe do objeto.  Por padrão, esse nome é baseado no nome que você fornece em **Nome da classe**.  Clique no botão de reticências para salvar o nome de arquivo no local de sua escolha, ou para acrescentar a declaração de classe a um arquivo existente.  Se você escolher um arquivo existente, o assistente não o salve no local selecionado até que você clique **Concluir** no assistente.  
  
 O assistente não substitui um arquivo.  Se você selecionar o nome de um arquivo existente, quando você clicar em **Concluir**, o assistente solicitará que indica se a declaração de classe deve ser acrescentada ao conteúdo do arquivo.  Clique em **Sim** para anexar o arquivo; clique **Não** para retornar ao assistente e para especificar outro nome de arquivo.  
  
 **arquivo .cpp**  
 Define o nome do arquivo de implementação para a nova classe do objeto.  Por padrão, esse nome é baseado no nome que você fornece em **Nome da classe**.  Clique no botão de reticências para salvar o nome de arquivo no local de sua escolha.  O arquivo não será salvo no local selecionado até que você clique **Concluir** no assistente.  
  
 O assistente não substitui um arquivo.  Se você selecionar o nome de um arquivo existente, quando você clicar em **Concluir**, o assistente solicitará que indica se a implementação da classe deverá ser acrescentada ao conteúdo do arquivo.  Clique em **Sim** para anexar o arquivo; clique **Não** para retornar ao assistente e para especificar outro nome de arquivo.  
  
 **Acessibilidade ativa**  
 Habilita o suporte para MFC a acessibilidade ativa chamando [EnableActiveAccessibility](../Topic/CWnd::EnableActiveAccessibility.md) no construtor.  Essa opção está disponível para as classes derivadas de [CWnd](../Topic/CWnd%20Class.md).  
  
 **ID de recurso do DHTML**  
 Aplica\-se às classes derivadas de `CDHtmlDialog` somente.  Especifica a ID do recurso da caixa de diálogo do DHTML.  A ID do recurso aparece na seção de HTML do arquivo de .rc de projeto, junto com o nome de arquivo na caixa de diálogo HTML.  O recurso do DHTML, identificado por esse ID, é hospedado pela caixa de diálogo, identificada por **ID de Diálogo**.  
  
 **arquivo.htm**  
 Aplica\-se às classes derivadas de `CDHtmlDialog` somente.  Define o nome do arquivo HTML para a caixa de diálogo do DHTML.  Por padrão, esse nome de arquivo é baseado no nome da classe.  O nome de arquivo aparece na seção de HTML do arquivo de .rc de projeto, junto com a ID do recurso da caixa de diálogo do DHTML  
  
 **Automação**  
 Define a classe no nível de suporte para [Automação](../../mfc/automation.md).  A automação no nível da classe está disponível para todas as classes que oferecem suporte à automação.  Também está disponível para os projetos criados com o suporte para a automação.  Isto é, um projeto de MFC que [o oferece suporte ATL](../../atl/reference/mfc-support-in-atl-projects.md), ou um projeto de MFC para que você selecionou a caixa de seleção de **Automação** na página de [Recursos avançados](../../mfc/reference/advanced-features-mfc-application-wizard.md) do assistente de aplicativo MFC.  
  
|Opção|Descrição|  
|-----------|---------------|  
|**Nenhum**|Indica que a classe não tem suporte de automação.|  
|**Automação**|Indica que a classe oferece suporte à automação.  Se você selecionar essa opção, a classe recém\-criado está disponível como um objeto programável por aplicativos cliente de automação, como o Microsoft Visual Basic e o Microsoft Excel.  Essa opção não está disponível para as classes base listadas depois dessa tabela.|  
|**Creatable por ID do tipo**|Indica que a classe e o projeto dão suporte a outros aplicativos que criam objetos dessa classe que usa a automação.  Com essa opção, os clientes de automação podem diretamente criar um objeto de automação.  O ID do tipo na caixa de texto é usado pelo aplicativo cliente especifique o objeto a ser criado; é pelo sistema e deve ser exclusivo.  Essa opção não está disponível para as classes base listadas depois dessa tabela.|  
  
 Suporte de automação não está disponível para as seguintes classes base:  
  
-   `CAsyncMonitorFile`  
  
-   `CAsyncSocket`  
  
-   `CCachedDataPathProperty`  
  
-   `CConnectionPoint`  
  
-   `CDatabase`  
  
-   `CDataPathProperty`  
  
-   `CHttpFilter`  
  
-   `CHttpServer`  
  
-   `CInternetSession`  
  
-   `CObject`  
  
-   `CSocket`  
  
 **Identificação do tipo**  
 Define a ID do tipo da classe.  A caixa de **Identificação do tipo** concatena o nome do projeto e o novo nome da classe da seguinte maneira: *MFCProj.MFCClass*.  Essa ID é variável somente se você selecionou a opção **Creatable por ID do tipo**de **Automação** .  
  
 **Gerenciar recursos de DocTemplate**  
 Indica que os documentos criados pelo aplicativo têm recursos de modelo de documento.  Para ativar essa caixa de seleção, o projeto deve oferecer suporte à arquitetura do documento\/exibição MFC, e a classe base dessa classe deve ser [CFormView](../../mfc/reference/cformview-class.md).  
  
 Consulte [Modelos de documentos e o processo de criação do documento\/exibição](../../mfc/document-templates-and-the-document-view-creation-process.md) para obter mais informações.  
  
## Consulte também  
 [MFC Class](../../mfc/reference/adding-an-mfc-class.md)   
 [Adicionando uma classe](../Topic/Adding%20a%20Class%20\(Visual%20C++\).md)