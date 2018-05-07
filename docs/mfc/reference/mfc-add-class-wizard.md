---
title: MFC Assistente para Adicionar classe | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- vc.codewiz.class.mfc.simple.overview
dev_langs:
- C++
helpviewer_keywords:
- MFC Add Class Wizard
- wizards [MFC]
ms.assetid: ad3b0989-d307-43b2-9417-3f9a78889024
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9560dec12a7710076f752d5329269c844f0d3a8b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="mfc-add-class-wizard"></a>Assistente para adicionar classe MFC
Use este assistente de código para adicionar uma classe a um projeto existente, ou para adicionar uma classe a um projeto de ATL que dá suporte a MFC. Você também pode adicionar classes MFC para projetos do Win32 que têm suporte do MFC. Os recursos que você especificou quando criou seu projeto determinam as opções disponíveis na caixa de diálogo.  
  
## <a name="names"></a>Nomes  
 Nesta página, especifique o nome da classe, a classe base e os nomes de arquivo para a nova classe.  
  
 **Nome de classe**  
 Especifica o nome da nova classe e fornece a base padrão para os nomes dos arquivos nesta página e IDs. Classes C++ normalmente iniciam com "C", por exemplo, "CMyClass" torna-se "MyClass.h", e assim por diante.  
  
 **Classe base**  
 Especifica o nome da classe base para a nova classe. Por padrão, a classe base é [CWnd](../../mfc/reference/cwnd-class.md). A classe base que você seleciona determina se outras caixas nessa página são ativas.  
  
 O tipo de classe que é definida como a classe base determina se a classe tem uma ID de caixa de diálogo ou uma ID de recurso. Os tipos gerais de classes são da seguinte maneira:  
  
-   Classes como [CButton](../../mfc/reference/cbutton-class.md), [CWnd](../../mfc/reference/cwnd-class.md), ou [CDocument](../../mfc/reference/cdocument-class.md), que não requerem uma caixa de diálogo ID ou ID de recurso. Essas classes não usa uma ID de caixa de diálogo ou recurso. Se você selecionar uma dessas classes para a sua classe base, o **ID da caixa de diálogo** caixa e o **ID de recurso DHTML** caixa estão esmaecidos.  
  
-   Classes como [CDialog](../../mfc/reference/cdialog-class.md), [CFormView](../../mfc/reference/cformview-class.md), ou [CPropertyPage](../../mfc/reference/cpropertypage-class.md), que exige uma identificação de caixa de diálogo.  
  
-   A classe [CDHtmlDialog](../../mfc/reference/cdhtmldialog-class.md), que requer uma ID de caixa de diálogo, uma ID de recurso DHTML e um nome de arquivo HTML.  
  
 Para classes que requerem uma ID de caixa de diálogo, talvez seja mais eficiente usar o [editor de recurso](../../windows/resource-editors.md) para criar o recurso de caixa de diálogo, atribua a sua identificação no [janela propriedades](/visualstudio/ide/reference/properties-window)e, em seguida, crie uma classe associada com essa ID de recurso. Consulte [criar uma nova caixa de diálogo](../../windows/creating-a-new-dialog-box.md) para obter mais informações sobre como criar uma caixa de diálogo padrão do Windows.  
  
> [!NOTE]
>  Se você criar um recurso de caixa de diálogo pela primeira vez e derivar sua nova classe de `CDHtmlDialog`, exclua o padrão do Windows **Okey** e **Cancelar** botões que aparecem na caixa de diálogo padrão. A caixa de diálogo Windows hospeda o formulário DHTML, que contém sua própria **Okey** e **Cancelar** botões.  
  
 Enquanto a caixa de diálogo pode conter controles do Windows e controles DHTML, não é recomendável.  
  
 **ID da caixa de diálogo**  
 Especifica a ID da caixa de diálogo, se você selecionou `CDialog`, `CFormView`, `CPropertyPage`, ou `CDHtmlDialog` como o **classe Base**.  
  
 **arquivo. h**  
 Define o nome do arquivo de cabeçalho para a classe do novo objeto. Por padrão, esse nome é baseado no nome que você fornecer em **nome da classe**. Clique no botão de reticências para salvar o nome do arquivo para o local de sua escolha, ou para acrescentar a declaração de classe para um arquivo existente. Se você escolher um arquivo existente, o assistente não salvará o local selecionado até que você clique **concluir** no assistente.  
  
 O assistente não substituirá um arquivo. Se você selecionar o nome de um arquivo existente, quando você clica em **concluir**, o assistente solicitará que você indique se a declaração de classe deve ser anexada ao conteúdo do arquivo. Clique em **Sim** para anexar o arquivo; clique em **não** para retornar ao assistente e especificar outro nome de arquivo.  
  
 **arquivo. cpp**  
 Define o nome do arquivo de implementação para a classe do novo objeto. Por padrão, esse nome é baseado no nome que você fornecer em **nome da classe**. Clique no botão de reticências para salvar o nome do arquivo para o local de sua escolha. O arquivo não é salvo no local selecionado até que você clique **concluir** no assistente.  
  
 O assistente não substituirá um arquivo. Se você selecionar o nome de um arquivo existente, quando você clica em **concluir**, o assistente solicita que você indique se a implementação da classe deve ser anexada ao conteúdo do arquivo. Clique em **Sim** para anexar o arquivo; clique em **não** para retornar ao assistente e especificar outro nome de arquivo.  
  
 **Acessibilidade ativa**  
 Habilita o suporte do MFC para acessibilidade ativa chamando [EnableActiveAccessibility](../../mfc/reference/cwnd-class.md#enableactiveaccessibility) no construtor. Essa opção está disponível para as classes derivadas de [CWnd](../../mfc/reference/cwnd-class.md).  
  
 **ID do recurso DHTML**  
 Aplica-se a classes derivadas de `CDHtmlDialog` somente. Especifica a ID de recurso da caixa de diálogo DHTML. A ID do recurso aparece na seção HTML o arquivo do projeto. RC, juntamente com o nome de arquivo de caixa de diálogo HTML. O recurso DHTML, identificado por essa ID é hospedado pela caixa de diálogo, identificado por **ID da caixa de diálogo**.  
  
 **. Arquivo HTM**  
 Aplica-se a classes derivadas de `CDHtmlDialog` somente. Define o nome do arquivo HTML para a caixa de diálogo DHTML. Por padrão, esse nome de arquivo com base no nome da classe. O nome do arquivo é exibido na seção HTML o arquivo do projeto. RC, juntamente com a ID de recurso DHTML caixa de diálogo caixa  
  
 **Automação**  
 Define o nível de classe de suporte para [automação](../../mfc/automation.md). Automação no nível de classe está disponível para todas as classes que oferecem suporte à automação. Também está disponível para projetos criados com suporte para automação. Ou seja, o MFC um projeto que [oferece suporte ATL](../../atl/reference/mfc-support-in-atl-projects.md), ou um projeto MFC para que você selecionou o **automação** caixa de seleção de [recursos avançados](../../mfc/reference/advanced-features-mfc-application-wizard.md) página do MFC Assistente de aplicativo.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Nenhum**|Indica que a classe não tem nenhum suporte de automação.|  
|**Automação**|Indica que a classe oferece suporte à automação. Se você selecionar essa opção, a classe recém-criada está disponível como um objeto programável por aplicativos de cliente de automação, como Microsoft Visual Basic e o Microsoft Excel. Essa opção não está disponível para as classes base listadas depois desta tabela.|  
|**Instanciável por ID de tipo**|Indica que a classe e o projeto oferecer suporte a outros aplicativos criando objetos desta classe usando a automação. Com essa opção, os clientes de automação diretamente podem criar um objeto de automação. A ID de tipo na caixa de texto é usada pelo aplicativo cliente para especificar o objeto a ser criado; ele é todo o sistema e deve ser exclusivo. Essa opção não está disponível para as classes base listadas depois desta tabela.|  
  
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
 Define a ID do tipo da classe. O **ID do tipo** caixa concatena o nome do projeto e o novo nome de classe, da seguinte maneira: *MFCProj.MFCClass*. Essa ID é mutável somente se você tiver selecionado o **automação** opção **Creatable por ID de tipo**.  
  
 **Gerar recursos de Modelodedoc**  
 Indica que os documentos criados pelo aplicativo tem recursos de modelo de documento. Para ativar esta caixa de seleção, o projeto deve oferecer suporte a arquitetura de documento/exibição MFC e a classe base desta classe deve ser [CFormView](../../mfc/reference/cformview-class.md).  
  
 Consulte [modelos de documento e o processo de criação de documento/exibição](../../mfc/document-templates-and-the-document-view-creation-process.md) para obter mais informações.  
  
## <a name="see-also"></a>Consulte também  
 [Classe do MFC](../../mfc/reference/adding-an-mfc-class.md)   
 [Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)
