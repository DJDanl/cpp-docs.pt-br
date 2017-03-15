---
title: Cadeias de caracteres de modelo, documento MFC Assistente para Adicionar classe | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.codewiz.class.mfc.simple.doctemp
dev_langs:
- C++
helpviewer_keywords:
- MFC Add Class Wizard, document control strings
ms.assetid: 14e1c834-5e79-4dbd-811f-ec8f0a9cdcb2
caps.latest.revision: 9
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
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: d99b1b447e29d1ddc89857149df52dc85664dcab
ms.lasthandoff: 02/25/2017

---
# <a name="document-template-strings-mfc-add-class-wizard"></a>Cadeias de caracteres de modelo do documento, Assistente para Adicionar Classe MFC
Esta página do assistente está disponível somente para classes que atendem aos seguintes critérios:  
  
-   O projeto MFC oferece suporte à arquitetura de documento/exibição.  
  
-   A classe base da nova classe é [CFormView](../../mfc/reference/cformview-class.md).  
  
-   A caixa de seleção **DocTemplate gerar recursos** é verificada no **nomes** seção o [MFC Class Wizard](../../mfc/reference/mfc-add-class-wizard.md).  
  
 O assistente fornece padrões para os seguintes valores para ajudar no design do modo de exibição de formulários, gerenciamento e localização. Como a maioria das cadeias de caracteres de modelo de documento são visíveis e usado por usuários do formulário, eles são localizados na **idioma de recurso** indicado no [tipos de aplicativos](../../mfc/reference/application-type-mfc-application-wizard.md) página do Assistente de aplicativo MFC quando o projeto foi criado.  
  
> [!NOTE]
>  O assistente não oferece suporte a impressão automática para classes derivadas de `CFormView`.  
  
 Consulte [modelos de documento e o processo de criação de documento/exibição](../../mfc/document-templates-and-the-document-view-creation-process.md) para obter mais informações.  
  
## <a name="nonlocalized-strings"></a>Cadeias de caracteres não localizadas  
 Aplica-se a aplicativos que criam documentos do usuário. Os usuários podem abrir e salvar documentos muito mais fácil se o tipo de documento tem uma extensão de arquivo e a ID do tipo de arquivo. Esses itens não são localizados, porque eles são usados pelo sistema e não pelo usuário.  
  
 **Extensão de arquivo**  
 Define a extensão de arquivo associada ao tipo de documento para este aplicativo de formulários. O padrão de extensão de arquivo com base no nome da classe. Por exemplo, se a nova classe MFC é chamada **CWidget**, por padrão, a extensão de arquivo é. wid. A extensão de arquivo é usada em filtros de arquivo e o **abrir** e **Salvar como** caixas de diálogo.  
  
 Se você alterar a extensão de arquivo, a alteração é refletida no **nome do filtro** caixa.  
  
> [!NOTE]
>  Se você alterar a extensão de arquivo padrão, não inclua o período.  
  
 **ID do tipo de arquivo**  
 Define o rótulo para o tipo de documento no registro do sistema.  
  
## <a name="localized-strings"></a>Cadeias de caracteres localizadas  
 Produz cadeias de caracteres associadas com os formulários e os documentos que são lidos e usados pelos usuários do aplicativo, para que as cadeias de caracteres são localizadas.  
  
 **Nome do tipo de documento**  
 Identifica o tipo de documento no qual um documento do aplicativo pode ser agrupado. Por padrão, ele é baseado no nome da classe. Por exemplo, se a nova classe MFC é chamada **CWidget**, por padrão, o nome do tipo de documento é Widget. Alterar o padrão não altera quaisquer outras opções na caixa de diálogo.  
  
 **Nome do filtro**  
 Define o nome que os usuários podem indicar para localizar os arquivos do tipo de arquivo especificado. Essa opção está disponível na **arquivos do tipo** e **Salvar como tipo** opções padrão do Windows **abrir** e **Salvar como** caixas de diálogo. Por padrão, o nome é baseado no nome do projeto e arquivos, seguidos pela extensão indicado na **extensão**. Por exemplo, se seu projeto for chamado Widget, e a extensão do arquivo é .wid, o **nome do filtro** é Widget arquivos (*.wid) por padrão.  
  
 **Nome curto do arquivo novo**  
 Define o nome que aparece no padrão do Windows `New` caixa de diálogo, se o projeto tiver mais de um modelo de documento. Se seu aplicativo é um [servidor de automação](../../mfc/automation-servers.md), esse nome é usado como o nome curto do seu objeto de automação. Por padrão, esse nome é baseado no nome da classe.  
  
 **Nome completo do tipo de arquivo**  
 Define o nome do tipo de arquivo no registro do sistema. Se seu aplicativo for um servidor de automação, esse nome é usado como o nome longo de seu objeto de automação. Por padrão, esse nome se baseia no nome da classe mais. Documento. Por exemplo, se o nome da classe é **CWidget**, o **nome longo do tipo de arquivo** é documento de Widget.  
  
 **Classe de documento**  
 Indica a classe de documento do projeto. Por padrão, essa classe é classe de documento do aplicativo principal, conforme listado no [Classes geradas de revisão](../../mfc/reference/generated-classes-mfc-application-wizard.md) página do Assistente de aplicativo MFC. Você pode selecionar outra classe de documento da lista, se você tiver adicionado outras classes de documento no projeto.  
  
## <a name="see-also"></a>Consulte também  
 [MFC Assistente para Adicionar classe](../../mfc/reference/mfc-add-class-wizard.md)   
 [Classe do MFC](../../mfc/reference/adding-an-mfc-class.md)   
 [Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)

