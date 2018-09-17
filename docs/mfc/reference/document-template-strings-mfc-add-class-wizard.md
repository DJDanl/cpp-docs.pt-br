---
title: Cadeias de caracteres de modelo, documento MFC Assistente para Adicionar classe | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- vc.codewiz.class.mfc.simple.doctemp
dev_langs:
- C++
helpviewer_keywords:
- MFC Add Class Wizard, document control strings
ms.assetid: 14e1c834-5e79-4dbd-811f-ec8f0a9cdcb2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 247793199b1e865941659b970e4e59a688137a8e
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45712225"
---
# <a name="document-template-strings-mfc-add-class-wizard"></a>Cadeias de caracteres de modelo do documento, Assistente para Adicionar Classe MFC
Esta página do assistente está disponível somente para classes que atendem os critérios a seguir:  
  
-   O projeto do MFC dá suporte à arquitetura de documento/exibição.  
  
-   A classe base da nova classe é [CFormView](../../mfc/reference/cformview-class.md).  
  
-   A caixa de seleção **DocTemplate gerar recursos** é verificada na **nomes** seção os [MFC Class Wizard](../../mfc/reference/mfc-add-class-wizard.md).  
  
 O assistente fornece padrões para os seguintes valores para ajudar no design do modo de exibição de formulários, gerenciamento e localização. Como a maioria das cadeias de caracteres de modelo de documento são visíveis e usado por usuários do formulário, eles são localizados na **idioma de recurso** indicado na [tipos de aplicativos](../../mfc/reference/application-type-mfc-application-wizard.md) página do Assistente de aplicativo MFC Quando o projeto foi criado.  
  
> [!NOTE]
>  O assistente não oferece suporte automático a impressão para classes derivadas de `CFormView`.  
  
 Ver [modelos de documento e o processo de criação de documento/exibição](../../mfc/document-templates-and-the-document-view-creation-process.md) para obter mais informações.  
  
## <a name="nonlocalized-strings"></a>Cadeias de caracteres não localizadas  
 Aplica-se a aplicativos que criam documentos do usuário. Os usuários podem abrir e salvar documentos muito mais facilmente se o tipo de documento tem uma extensão de arquivo e a ID do tipo de arquivo. Esses itens não são localizados, porque eles são usados pelo sistema em vez do usuário.  
  
- **Extensão de arquivo**

   Define a extensão de arquivo associada ao tipo de documento para este aplicativo de formulários. O padrão de extensão de arquivo com base no nome da classe. Por exemplo, se a nova classe do MFC é chamada `CWidget`, por padrão, a extensão de arquivo é. WID. A extensão de arquivo é usada em filtros de arquivo e o **aberto** e **Salvar como** caixas de diálogo.  
  
   Se você alterar a extensão de arquivo, a alteração será refletida na **nome do filtro** caixa.  
  
   > [!NOTE]
   > Se você alterar a extensão de arquivo padrão, não incluem o período.  
  
- **ID do tipo de arquivo**

   Define o rótulo para o tipo de documento no registro do sistema.  
  
## <a name="localized-strings"></a>Cadeias de caracteres localizadas  
 Produz a cadeias de caracteres associadas a formulários e os documentos que são lidos e usados por usuários do aplicativo, portanto, as cadeias de caracteres são localizadas.  
  
- **Nome do tipo de documento**

   Identifica o tipo de documento sob a qual um documento do aplicativo pode ser agrupado. Por padrão, ele se baseia no nome da classe. Por exemplo, se a nova classe do MFC é denominada **CWidget**, por padrão, o nome do tipo de documento for o Widget. Alterando o padrão não altera quaisquer outras opções na caixa de diálogo.  
  
- **Nome do filtro**

   Define o nome que os usuários podem indicar para localizar arquivos do tipo de arquivo especificado. Essa opção está disponível na **arquivos de tipo** e **Salvar como tipo** opções no Windows padrão **abrir** e **Salvar como** caixas de diálogo. Por padrão, o nome é baseado no nome do projeto além de arquivos, seguidos pela extensão indicado na **extensão de arquivo**. Por exemplo, se seu projeto for chamado Widget, e a extensão de arquivo é .wid, o **nome do filtro** for o Widget arquivos (*.wid) por padrão.  
  
- **Nome curto do arquivo novo**

   Define o nome que aparece no Windows padrão **New** caixa de diálogo, se o projeto tiver mais de um modelo de documento. Se seu aplicativo for um [servidor de automação](../../mfc/automation-servers.md), esse nome é usado como o nome curto do seu objeto de automação. Por padrão, esse nome é baseado no nome da classe.  
  
- **Nome longo do tipo de arquivo**

   Define o nome do tipo de arquivo no registro do sistema. Se seu aplicativo for um servidor de automação, esse nome é usado como o nome longo de seu objeto de automação. Por padrão, esse nome se baseia no nome da classe adição. Documento. Por exemplo, se for o nome da classe `CWidget`, o **nome longo do tipo de arquivo** é documento de Widget.  
  
- **Classe de documento**

   Indica a classe de documento do projeto. Por padrão, essa classe é classe de documento do aplicativo principal, conforme listado na [Classes geradas de revisão](../../mfc/reference/generated-classes-mfc-application-wizard.md) página do Assistente de aplicativo MFC. Você pode selecionar outra classe de documento na lista, se você tiver adicionado outras classes de documento no projeto.  
  
## <a name="see-also"></a>Consulte também  
 [MFC Assistente para Adicionar classe](../../mfc/reference/mfc-add-class-wizard.md)   
 [Classe MFC](../../mfc/reference/adding-an-mfc-class.md)   
 [Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)
