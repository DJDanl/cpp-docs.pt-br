---
title: Assistente de classe para adicionar MFC | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.codewiz.class.mfc.simple.overview
dev_langs:
- C++
helpviewer_keywords:
- MFC Add Class Wizard
- wizards [MFC]
ms.assetid: ad3b0989-d307-43b2-9417-3f9a78889024
caps.latest.revision: 16
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 4fafe461008e3545243d693e0d9e34acd57163e0
ms.openlocfilehash: 08d258c2b8386a4dd0c1d24c6ac6aa10f6c04a63
ms.lasthandoff: 02/25/2017

---
# <a name="mfc-add-class-wizard"></a>Assistente para adicionar classe MFC
Use esse assistente de código para adicionar uma classe a um projeto existente, ou para adicionar uma classe a um projeto ATL que dá suporte a MFC. Você também pode adicionar classes MFC para projetos do Win32 que têm suporte do MFC. Os recursos que você especificou quando criou seu projeto determinam as opções disponíveis nessa caixa de diálogo.  
  
## <a name="names"></a>Nomes  
 Nesta página, especifique o nome da classe, a classe base e nomes de arquivo para a nova classe.  
  
 **Nome da classe**  
 Especifica o nome da nova classe e fornece a base padrão para os nomes dos arquivos nesta página e IDs. Classes C++ geralmente iniciar com "C", por exemplo, "CMyClass" torna-se "MyClass.h", e assim por diante.  
  
 **Classe base**  
 Especifica o nome da classe base para a nova classe. Por padrão, a classe base é [CWnd](../../mfc/reference/cwnd-class.md). A classe base que você selecionar determina se outras caixas nesta página estão ativas.  
  
 O tipo de classe que é definida como a classe base determina se a classe tem uma ID de caixa de diálogo ou uma ID de recurso. Os tipos gerais de classes são da seguinte maneira:  
  
-   Classes como [CButton](../../mfc/reference/cbutton-class.md), [CWnd](../../mfc/reference/cwnd-class.md), ou [CDocument](../../mfc/reference/cdocument-class.md), que não requerem uma caixa de diálogo ID ou ID de recurso. Essas classes não usa uma ID de caixa de diálogo ou recurso. Se você selecionar uma dessas classes para sua classe base, o **identificação da caixa de diálogo** caixa e o **ID de recurso DHTML** caixa estão esmaecidos.  
  
-   Classes como [CDialog](../../mfc/reference/cdialog-class.md), [CFormView](../../mfc/reference/cformview-class.md), ou [CPropertyPage](../../mfc/reference/cpropertypage-class.md), que requer uma ID da caixa de diálogo.  
  
-   A classe [CDHtmlDialog](../../mfc/reference/cdhtmldialog-class.md), que requer uma ID de caixa de diálogo, uma ID de recurso DHTML e um nome de arquivo HTML.  
  
 Para classes que requerem uma ID da caixa de diálogo, talvez seja mais eficiente usar a [Resource editor](../../windows/resource-editors.md) para criar o recurso de caixa de diálogo, atribuir sua ID de [janela propriedades](/visualstudio/ide/reference/properties-window)e, em seguida, crie uma classe associada a essa ID de recurso. Consulte [criando uma nova caixa de diálogo](../../windows/creating-a-new-dialog-box.md) para obter mais informações sobre como criar uma caixa de diálogo padrão do Windows.  
  
> [!NOTE]
>  Se você criar um recurso de caixa de diálogo pela primeira vez e derivar sua nova classe de `CDHtmlDialog`, excluir padrão do Windows **Okey** e **Cancelar** botões que aparecem na caixa de diálogo padrão. A caixa de diálogo padrão do Windows hospeda o formulário DHTML, que contém seu próprio **Okey** e **Cancelar** botões.  
  
 Enquanto a caixa de diálogo pode conter controles do Windows e controles DHTML, não é recomendável.  
  
 **ID da caixa de diálogo**  
 Especifica a ID da caixa de diálogo, se você selecionou `CDialog`, `CFormView`, `CPropertyPage`, ou `CDHtmlDialog` como o **classe Base**.  
  
 **arquivo. h**  
 Define o nome do arquivo de cabeçalho para a nova classe de objeto. Por padrão, esse nome se baseia o nome fornecido no **nome da classe**. Clique no botão de reticências para salvar o nome do arquivo para o local de sua escolha, ou para acrescentar a declaração de classe para um arquivo existente. Se você escolher um arquivo existente, o assistente não salvará no local selecionado até que você clique **concluir** no assistente.  
  
 O assistente não substituirá um arquivo. Se você selecionar o nome de um arquivo existente, quando você clica em **concluir**, o assistente solicita que você indique se a declaração de classe deve ser anexada ao conteúdo do arquivo. Clique em **Sim** para anexar o arquivo; clique em **não** para retornar ao assistente e especifique outro nome de arquivo.  
  
 **arquivo. cpp**  
 Define o nome do arquivo de implementação para a nova classe de objeto. Por padrão, esse nome se baseia o nome fornecido no **nome da classe**. Clique no botão de reticências para salvar o nome de arquivo para o local de sua escolha. O arquivo não é salvo no local selecionado até que você clique **concluir** no assistente.  
  
 O assistente não substituirá um arquivo. Se você selecionar o nome de um arquivo existente, quando você clica em **concluir**, o assistente solicita que você indique se a implementação da classe deve ser anexada ao conteúdo do arquivo. Clique em **Sim** para anexar o arquivo; clique em **não** para retornar ao assistente e especifique outro nome de arquivo.  
  
 **Acessibilidade ativa**  
 Habilita o suporte do MFC para Active Accessibility chamando [EnableActiveAccessibility](../../mfc/reference/cwnd-class.md#enableactiveaccessibility) no construtor. Essa opção está disponível para as classes derivadas de [CWnd](../../mfc/reference/cwnd-class.md).  
  
 **ID do recurso DHTML**  
 Aplica-se a classes derivadas de `CDHtmlDialog` somente. Especifica a ID do recurso da caixa de diálogo DHTML. A ID do recurso aparece na seção do arquivo. RC do projeto, juntamente com o nome de arquivo da caixa de diálogo HTML HTML. O recurso DHTML, identificado por essa ID é hospedado pela caixa de diálogo, identificado por **identificação da caixa de diálogo**.  
  
 **. Arquivo HTM**  
 Aplica-se a classes derivadas de `CDHtmlDialog` somente. Define o nome do arquivo HTML para a caixa de diálogo DHTML. Por padrão, esse nome de arquivo com base no nome da classe. O nome do arquivo é exibido na seção do arquivo. RC do projeto, juntamente com a ID de recurso DHTML diálogo caixa HTML  
  
 **Automação**  
 Define o nível de classe de suporte para [automação](../../mfc/automation.md). Automação no nível de classe está disponível para todas as classes que oferecem suporte a automação. Também está disponível para projetos criados com suporte para automação. Ou seja, o MFC um projeto que [oferece suporte a ATL](../../atl/reference/mfc-support-in-atl-projects.md), ou um projeto MFC para os quais você selecionou o **automação** caixa de seleção de [recursos avançados](../../mfc/reference/advanced-features-mfc-application-wizard.md) página do Assistente de aplicativo MFC.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Nenhum**|Indica que a classe não possui nenhum suporte de automação.|  
|**Automação**|Indica que a classe oferece suporte à automação. Se você selecionar essa opção, a classe recém-criado está disponível como um objeto programável por aplicativos de clientes de automação, como Microsoft Visual Basic e Microsoft Excel. Essa opção não está disponível para as classes base listadas depois desta tabela.|  
|**Pode ser criado por ID do tipo**|Indica que a classe e o projeto compatível com outros aplicativos que criam objetos dessa classe usando a automação. Com essa opção, os clientes de automação diretamente podem criar um objeto de automação. A ID de tipo na caixa de texto é usada pelo aplicativo cliente para especificar o objeto a ser criado; ele é todo o sistema e deve ser exclusivo. Essa opção não está disponível para as classes base listadas depois desta tabela.|  
  
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
  
 **ID do tipo**  
 Define a ID do tipo da classe. O **ID do tipo** caixa concatena o nome do projeto e o novo nome da classe da seguinte maneira: *MFCProj.MFCClass*. Essa ID é alterável somente se você tiver selecionado o **automação** opção **Creatable por ID do tipo**.  
  
 **Gerar recursos DocTemplate**  
 Indica que os documentos criados pelo aplicativo possuem recursos de modelo de documento. Para ativar essa caixa de seleção, o projeto deve oferecer suporte à arquitetura de documento/exibição MFC, e a classe base dessa classe deve ser [CFormView](../../mfc/reference/cformview-class.md).  
  
 Consulte [modelos de documento e o processo de criação de documento/exibição](../../mfc/document-templates-and-the-document-view-creation-process.md) para obter mais informações.  
  
## <a name="see-also"></a>Consulte também  
 [Classe do MFC](../../mfc/reference/adding-an-mfc-class.md)   
 [Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)

