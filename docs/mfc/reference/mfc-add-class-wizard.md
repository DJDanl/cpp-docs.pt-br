---
title: Adicionar do MFC Class Wizard | Microsoft Docs
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
ms.openlocfilehash: 0f9098bf7aa812e79e0928266d52ad2c1602135c
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46419836"
---
# <a name="mfc-add-class-wizard"></a>Assistente para adicionar classe MFC

Use este assistente de código para adicionar uma classe a um projeto MFC existente ou adicionar uma classe para um projeto ATL que dá suporte a MFC. Você também pode adicionar classes MFC para projetos do Win32 que têm suporte do MFC. Os recursos que você especificou quando criou seu projeto determinam as opções disponíveis nessa caixa de diálogo.

## <a name="names"></a>Nomes

Nessa página, especifique o nome de classe, a classe base e os nomes de arquivo para a nova classe.

- **Nome da classe**

   Especifica o nome da nova classe e fornece a base padrão para os nomes dos arquivos nesta página e IDs. Classes C++ geralmente inicializam com "C", por exemplo, "CMyClass" torna-se "MyClass.h", e assim por diante.

- **Classe base**

   Especifica o nome da classe base para a nova classe. Por padrão, é a classe base [CWnd](../../mfc/reference/cwnd-class.md). A classe base que você selecionar determina se outras caixas nesta página estão ativas.

   O tipo de classe definida como a classe base determina se a classe tem uma ID de caixa de diálogo ou uma ID de recurso. Os tipos gerais de classes são da seguinte maneira:

   - Classes como [CButton](../../mfc/reference/cbutton-class.md), [CWnd](../../mfc/reference/cwnd-class.md), ou [CDocument](../../mfc/reference/cdocument-class.md), que não exigem uma caixa de diálogo ID ou ID de recurso. Essas classes não usam uma ID de recurso ou caixa de diálogo. Se você selecionar uma dessas classes para a sua classe base, o **ID da caixa de diálogo** caixa e o **ID de recurso do DHTML** caixa estão esmaecidos.

   - Classes como [CDialog](../../mfc/reference/cdialog-class.md), [CFormView](../../mfc/reference/cformview-class.md), ou [CPropertyPage](../../mfc/reference/cpropertypage-class.md), que requerem uma ID de caixa de diálogo.

   - A classe [CDHtmlDialog](../../mfc/reference/cdhtmldialog-class.md), que requer uma ID de caixa de diálogo, uma ID de recurso DHTML e um nome de arquivo HTML.

   Para classes que exigem uma ID da caixa de diálogo, você talvez ache mais eficiente usar a [editor de recursos](../../windows/resource-editors.md) para criar o recurso de caixa de diálogo, atribua sua ID na [janela propriedades](/visualstudio/ide/reference/properties-window)e, em seguida, crie uma classe associada com essa ID de recurso. Ver [criando uma nova caixa de diálogo](../../windows/creating-a-new-dialog-box.md) para obter mais informações sobre como criar uma caixa de diálogo padrão do Windows.

   > [!NOTE]
   > Se você criar um recurso de caixa de diálogo pela primeira vez e derivar sua nova classe de `CDHtmlDialog`, exclua o Windows standard **Okey** e **Cancelar** botões exibidos na caixa de diálogo padrão. A caixa de diálogo padrão do Windows hospeda o formulário DHTML, que contém seu próprio **Okey** e **Cancelar** botões.

   Embora sua caixa de diálogo pode conter controles de Windows e controles DHTML, não é recomendável.

- **ID da caixa de diálogo**

   Especifica a ID da caixa de diálogo, se você selecionou `CDialog`, `CFormView`, `CPropertyPage`, ou `CDHtmlDialog` como o **classe Base**.

- **Arquivo .h**

   Define o nome do arquivo de cabeçalho para a nova classe do objeto. Por padrão, esse nome baseia-se no nome fornecido em **Nome da classe**. Clique no botão de reticências para salvar o nome de arquivo no local de sua escolha, ou para acrescentar a declaração de classe a um arquivo existente. Se você escolher um arquivo existente, o assistente não o salvará no local selecionado até que você clique em **Concluir** no assistente.

   O assistente não substitui um arquivo. Se você selecionar o nome de um arquivo existente, quando clicar em **Concluir**, o assistente solicitará que você indique se a declaração de classe deve ser acrescentada ao conteúdo do arquivo. Clique em **Sim** para acrescentar o arquivo; clique em **Não** para retornar ao assistente e especificar outro nome de arquivo.

- **Arquivo .cpp**

   Define o nome do arquivo de implementação para a nova classe do objeto. Por padrão, esse nome baseia-se no nome fornecido em **Nome da classe**. Clique no botão de reticências para salvar o nome de arquivo no local de sua escolha. O arquivo não é salvo no local selecionado até que você clique em **Concluir** no assistente.

   O assistente não substitui um arquivo. Se você selecionar o nome de um arquivo existente, quando clicar em **Concluir**, o assistente solicitará que você indique se a implementação de classe deve ser acrescentada ao conteúdo do arquivo. Clique em **Sim** para acrescentar o arquivo; clique em **Não** para retornar ao assistente e especificar outro nome de arquivo.

- **Acessibilidade ativa**

   Habilita o suporte do MFC para Active Accessibility, chamando [EnableActiveAccessibility](../../mfc/reference/cwnd-class.md#enableactiveaccessibility) no construtor. Essa opção está disponível para as classes derivadas [CWnd](../../mfc/reference/cwnd-class.md).

- **ID do recurso DHTML**

   Aplica-se a classes derivadas de `CDHtmlDialog` apenas. Especifica a ID do recurso da caixa de diálogo DHTML. A ID de recurso é exibido na seção HTML do arquivo. RC do projeto, juntamente com o nome de arquivo de caixa de diálogo HTML. O recurso DHTML, identificado por essa ID é hospedado pela caixa de diálogo, identificado por **ID da caixa de diálogo**.

- **. Arquivo HTM**

   Aplica-se a classes derivadas de `CDHtmlDialog` apenas. Define o nome do arquivo HTML para a caixa de diálogo do DHTML. Por padrão, esse nome de arquivo com base no nome da classe. O nome do arquivo aparece na seção HTML do arquivo. RC do projeto, juntamente com a ID do DHTML caixa de diálogo caixa recurso.

- **Automação**

   Define o nível de classe de suporte para [automação](../../mfc/automation.md). Automação no nível de classe está disponível para todas as classes que oferecem suporte à automação. Ele também está disponível para projetos criados com o suporte para a automação. Ou seja, o MFC um projeto que [dá suporte à ATL](../../atl/reference/mfc-support-in-atl-projects.md), ou um projeto MFC para o qual você selecionou o **automação** caixa de seleção a [recursos avançados](../../mfc/reference/advanced-features-mfc-application-wizard.md) página do MFC Assistente de aplicativo.

   |Opção|Descrição|
   |------------|-----------------|
   |**Nenhum**|Indica que a classe tem não há suporte de automação.|
   |**Automação**|Indica que a classe dá suporte à automação. Se você selecionar essa opção, a classe recém-criado está disponível como um objeto programável por aplicativos de cliente de automação, como Microsoft Visual Basic e o Microsoft Excel. Essa opção não está disponível para as classes base listadas depois desta tabela.|
   |**Pode ser criado por ID de tipo**|Indica que a classe e o projeto são compatíveis com outros aplicativos que criam objetos dessa classe usando a automação. Com essa opção, os clientes de automação podem criar diretamente um objeto de automação. A ID de tipo na caixa de texto é usada pelo aplicativo cliente para especificar o objeto a ser criado; é no âmbito do sistema e deve ser exclusivo. Essa opção não está disponível para as classes base listadas depois desta tabela.|

   Suporte de automação não está disponível para as seguintes classes base:

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

- **ID do tipo**

   Define a ID do tipo da classe. O **ID do tipo** caixa concatena o nome do projeto e o novo nome de classe, da seguinte maneira: *MFCProj.MFCClass*. Essa ID é mutável apenas se você tiver selecionado a **automação** opção **Creatable por ID do tipo**.

- **Gerar recursos DocTemplate**

   Indica que os documentos criados pelo aplicativo tem recursos de modelo de documento. Para ativar essa caixa de seleção, o projeto deve dar suporte a arquitetura de documento/exibição do MFC e a classe base dessa classe deve ser [CFormView](../../mfc/reference/cformview-class.md).

   Ver [modelos de documento e o processo de criação de documento/exibição](../../mfc/document-templates-and-the-document-view-creation-process.md) para obter mais informações.

## <a name="see-also"></a>Consulte também

[Classe do MFC](../../mfc/reference/adding-an-mfc-class.md)<br/>
[Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)
