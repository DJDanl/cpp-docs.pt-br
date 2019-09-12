---
title: Assistente para adicionar classe MFC
ms.date: 09/06/2019
f1_keywords:
- vc.codewiz.class.mfc.simple.overview
helpviewer_keywords:
- MFC Add Class Wizard
- wizards [MFC]
ms.assetid: ad3b0989-d307-43b2-9417-3f9a78889024
ms.openlocfilehash: 2c82e084de2123c579299ca6490bdfcfdac5d255
ms.sourcegitcommit: 3caf5261b3ea80d9cf14038c116ba981d655cd13
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/11/2019
ms.locfileid: "70908026"
---
# <a name="mfc-add-class-wizard"></a>Assistente para adicionar classe MFC

Use este assistente de código para adicionar uma classe a um projeto existente do MFC ou para adicionar uma classe a um projeto do ATL que ofereça suporte a MFC. Você também pode adicionar classes MFC a projetos Win32 que têm suporte MFC. Os recursos que você especificou quando criou o projeto determinam as opções disponíveis nessa caixa de diálogo. Para acessar o assistente, clique em **Adicionar classe** no [Assistente de classe](mfc-class-wizard.md).

![Assistente para adicionar classe MFC](media/add-mfc-class-wizard.png "Assistente para adicionar classe MFC")

## <a name="names"></a>Nomes

Nesta página, especifique o nome da classe, a classe base e os nomes de arquivo para a nova classe.

- **Nome da classe**

  Especifica o nome da nova classe e fornece a base padrão para os nomes de IDs e arquivos nesta página. C++Normalmente, as classes começam com "C", por exemplo, "CMyClass" torna-se "MyClass. h" e assim por diante.

- **Classe base**

  Especifica o nome da classe base para a nova classe. Por padrão, a classe base é [CWnd](../../mfc/reference/cwnd-class.md). A classe base selecionada determina se outras caixas nesta página estão ativas.

  O tipo de classe que você define como a classe base determina se a classe tem uma ID de caixa de diálogo ou uma ID de recurso. Os tipos gerais de classes são os seguintes:

  - Classes como [CButton](../../mfc/reference/cbutton-class.md), [CWnd](../../mfc/reference/cwnd-class.md)ou [CDocument](../../mfc/reference/cdocument-class.md), que não exigem uma ID de caixa de diálogo ou ID de recurso. Essas classes não usam uma ID de caixa de diálogo ou recurso. Se você selecionar uma dessas classes para sua classe base, a caixa **ID de diálogo** e a caixa **ID de recurso DHTML** estarão esmaecidas.

  - Classes como [CDialog](../../mfc/reference/cdialog-class.md), [CFormView](../../mfc/reference/cformview-class.md)ou [CPROPERTYPAGE](../../mfc/reference/cpropertypage-class.md), que exigem uma ID de caixa de diálogo.

  - A classe [CDHtmlDialog](../../mfc/reference/cdhtmldialog-class.md), que requer uma ID de caixa de diálogo, uma ID de recurso DHTML e um nome de arquivo HTML.

  Para classes que exigem uma ID de caixa de diálogo, talvez você ache mais eficiente usar o [Editor de recursos](../../windows/resource-editors.md) para criar o recurso de caixa de diálogo, atribuir sua ID no assistente de [classe](mfc-class-wizard.md)e, em seguida, criar uma classe associada a essa ID de recurso. Consulte [criando uma nova caixa de diálogo](../../windows/creating-a-new-dialog-box.md) para obter mais informações sobre a criação de uma caixa de diálogo padrão do Windows.

  > [!NOTE]
  > Se você criar um recurso de caixa de diálogo primeiro e derivar `CDHtmlDialog`sua nova classe do, exclua os botões padrão do Windows **OK** e **Cancelar** que aparecem na caixa de diálogo padrão. A caixa de diálogo padrão do Windows hospeda o formulário DHTML, que contém seus próprios botões **OK** e **Cancelar** .

  Embora sua caixa de diálogo possa conter controles do Windows e de DHTML, isso não é recomendável.

- **ID da caixa de diálogo**

  Especifica a ID da caixa de diálogo, se você `CDialog`selecionou `CPropertyPage`, `CFormView`, `CDHtmlDialog` ou como a **classe base**.

- **Arquivo .h**

  Define o nome do arquivo de cabeçalho para a nova classe do objeto. Por padrão, esse nome baseia-se no nome fornecido em **Nome da classe**. Clique no botão de reticências para salvar o nome de arquivo no local de sua escolha, ou para acrescentar a declaração de classe a um arquivo existente. Se você escolher um arquivo existente, o assistente não o salvará no local selecionado até que você clique em **Concluir** no assistente.

  O assistente não substitui um arquivo. Se você selecionar o nome de um arquivo existente, quando clicar em **Concluir**, o assistente solicitará que você indique se a declaração de classe deve ser acrescentada ao conteúdo do arquivo. Clique em **Sim** para acrescentar o arquivo; clique em **Não** para retornar ao assistente e especificar outro nome de arquivo.

- **Arquivo .cpp**

  Define o nome do arquivo de implementação para a nova classe do objeto. Por padrão, esse nome baseia-se no nome fornecido em **Nome da classe**. Clique no botão de reticências para salvar o nome de arquivo no local de sua escolha. O arquivo não é salvo no local selecionado até que você clique em **Concluir** no assistente.

  O assistente não substitui um arquivo. Se você selecionar o nome de um arquivo existente, quando clicar em **Concluir**, o assistente solicitará que você indique se a implementação de classe deve ser acrescentada ao conteúdo do arquivo. Clique em **Sim** para acrescentar o arquivo; clique em **Não** para retornar ao assistente e especificar outro nome de arquivo.

- **Acessibilidade ativa**

  Habilita o suporte do MFC para Acessibilidade Ativa chamando [EnableActiveAccessibility](../../mfc/reference/cwnd-class.md#enableactiveaccessibility) no construtor. Essa opção está disponível para classes derivadas de [CWnd](../../mfc/reference/cwnd-class.md).

- **Automação**

  Define o nível de suporte de classe para [automação](../../mfc/automation.md). A automação no nível de classe está disponível para todas as classes que dão suporte à automação. Ele também está disponível para projetos criados com suporte para automação. Ou seja, um projeto MFC que [dá suporte à ATL](../../atl/reference/mfc-support-in-atl-projects.md)ou um projeto MFC para o qual você selecionou a caixa de seleção **automação** na página [recursos avançados](../../mfc/reference/advanced-features-mfc-application-wizard.md) do assistente de aplicativo do MFC.

   O suporte à automação não está disponível para as seguintes classes base:

  - `CAsyncMonitorFile`

  - `CAsyncSocket`

  - `CCachedDataPathProperty`

  - `CConnectionPoint`

  - `CDatabase`

  - `CDataPathProperty`

  - `CHttpFilter`

  - `CHttpServer`

  - `CInternetSession`

  - `CObject`

  - `CSocket`

## <a name="see-also"></a>Consulte também

[Classe MFC](../../mfc/reference/adding-an-mfc-class.md)<br/>
[Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)
