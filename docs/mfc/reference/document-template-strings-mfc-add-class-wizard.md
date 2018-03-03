---
title: Cadeias de caracteres de modelo, documento MFC Assistente para Adicionar classe | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.codewiz.class.mfc.simple.doctemp
dev_langs:
- C++
helpviewer_keywords:
- MFC Add Class Wizard, document control strings
ms.assetid: 14e1c834-5e79-4dbd-811f-ec8f0a9cdcb2
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 3a9d37b1a886c28d267cd7a387317edce6bf7f3a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="document-template-strings-mfc-add-class-wizard"></a>Cadeias de caracteres de modelo do documento, Assistente para Adicionar Classe MFC
Esta página do assistente está disponível somente para classes que atendem aos seguintes critérios:  
  
-   O projeto MFC oferece suporte à arquitetura de documento/exibição.  
  
-   É a classe base da nova classe [CFormView](../../mfc/reference/cformview-class.md).  
  
-   A caixa de seleção **gerar recursos de Modelodedoc** é verificada no **nomes** seção o [Assistente de classe MFC](../../mfc/reference/mfc-add-class-wizard.md).  
  
 O assistente fornece padrões para valores a seguir para ajudá-lo com o design do modo de exibição de formulários, gerenciamento e localização. Como a maioria das cadeias de caracteres de modelo de documento são visíveis e usado por usuários do formulário, eles são localizados no **idioma de recurso** indicado no [tipos de aplicativos](../../mfc/reference/application-type-mfc-application-wizard.md) página do Assistente de aplicativo MFC Quando o projeto foi criado.  
  
> [!NOTE]
>  O assistente não oferece suporte de impressão automática para classes derivadas de `CFormView`.  
  
 Consulte [modelos de documento e o processo de criação de documento/exibição](../../mfc/document-templates-and-the-document-view-creation-process.md) para obter mais informações.  
  
## <a name="nonlocalized-strings"></a>Cadeias de caracteres não localizadas  
 Aplica-se a aplicativos que criam documentos do usuário. Os usuários podem abrir e salvar documentos mais facilmente se o tipo de documento tem uma extensão de arquivo e a ID do tipo de arquivo. Esses itens não são localizados, porque eles são usados pelo sistema e não pelo usuário.  
  
 **Extensão de arquivo**  
 Define a extensão de arquivo associada ao tipo de documento para este aplicativo de formulários. O padrão de extensão de arquivo com base no nome da classe. Por exemplo, se a nova classe do MFC é denominada **CWidget**, por padrão, a extensão de arquivo é. WID. A extensão de arquivo é usada em filtros de arquivo e o **abrir** e **Salvar como** caixas de diálogo.  
  
 Se você alterar a extensão de arquivo, a alteração será refletida no **nome do filtro** caixa.  
  
> [!NOTE]
>  Se você alterar a extensão de arquivo padrão, não inclua o período.  
  
 **ID do tipo de arquivo**  
 Define o rótulo para o tipo de documento no registro do sistema.  
  
## <a name="localized-strings"></a>Cadeias de caracteres localizadas  
 Produz cadeias de caracteres associadas a formulários e documentos que são lidos e usados por usuários do aplicativo, portanto, as cadeias de caracteres são localizadas.  
  
 **Nome do tipo de documento**  
 Identifica o tipo de documento no qual um documento do aplicativo pode ser agrupado. Por padrão, ele se baseia no nome da classe. Por exemplo, se a nova classe do MFC é denominada **CWidget**, por padrão, o nome do tipo de documento é Widget. Alterar o padrão não altera qualquer outra opção na caixa de diálogo.  
  
 **Nome do filtro**  
 Define o nome que os usuários podem indicar para localizar arquivos de tipo de arquivo especificado. Essa opção está disponível na **arquivos do tipo** e **Salvar como tipo** opções padrão do Windows **abrir** e **Salvar como** caixas de diálogo. Por padrão, o nome é baseado no nome do projeto e arquivos, em seguida, a extensão é indicado no **extensão de arquivo**. Por exemplo, se seu projeto for chamado Widget, e a extensão de arquivo é .wid, o **nome do filtro** é Widget arquivos (*.wid) por padrão.  
  
 **Nome curto do novo arquivo**  
 Define o nome que aparece no padrão do Windows `New` caixa de diálogo, se o projeto tiver mais de um modelo de documento. Se seu aplicativo for um [servidor de automação](../../mfc/automation-servers.md), esse nome é usado como o nome curto de seu objeto de automação. Por padrão, esse nome é baseado no nome da classe.  
  
 **Nome longo do tipo de arquivo**  
 Define o nome do tipo de arquivo no registro do sistema. Se seu aplicativo for um servidor de automação, esse nome é usado como o nome longo de seu objeto de automação. Por padrão, esse nome é com base no nome da classe adição. Documento. Por exemplo, se o nome da classe é **CWidget**, o **nome longo do tipo de arquivo** é documento de Widget.  
  
 **Classe de documento**  
 Indica a classe de documento do projeto. Por padrão, essa classe é classe de documento do aplicativo principal, conforme listado no [revisão gerados Classes](../../mfc/reference/generated-classes-mfc-application-wizard.md) página do Assistente de aplicativo MFC. Você pode selecionar outra classe de documento na lista, se você tiver adicionado outras classes de documento no projeto.  
  
## <a name="see-also"></a>Consulte também  
 [MFC Assistente para Adicionar classe](../../mfc/reference/mfc-add-class-wizard.md)   
 [Classe do MFC](../../mfc/reference/adding-an-mfc-class.md)   
 [Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)
