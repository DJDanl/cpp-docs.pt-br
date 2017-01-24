---
title: "Cadeias de caracteres de modelo do documento, Assistente para Adicionar Classe MFC | Microsoft Docs"
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
  - "vc.codewiz.class.mfc.simple.doctemp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Assistente para adicionar classe MFC, cadeias de caracteres de controle de documentos"
ms.assetid: 14e1c834-5e79-4dbd-811f-ec8f0a9cdcb2
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Cadeias de caracteres de modelo do documento, Assistente para Adicionar Classe MFC
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Esta página do assistente está disponível somente para as classes que atendem aos seguintes critérios:  
  
-   O projeto de MFC oferece suporte à arquitetura do documento\/exibição.  
  
-   A classe base da nova classe é [CFormView](../../mfc/reference/cformview-class.md).  
  
-   A caixa de seleção **Generate DocTemplate resources** é verificada na seção de **Nomes** de [Assistente da classe de MFC](../../mfc/reference/mfc-add-class-wizard.md).  
  
 O assistente fornece opções para os seguintes valores com formas ajudam a exibir o design, gerenciamento e, a localização.  Como a maioria de cadeias de caracteres de modelo de documento são visíveis e usadas pelos usuários do formulário, são encontradas em **Resource language** indicado na página de [Tipos de aplicativo](../Topic/Application%20Type,%20MFC%20Application%20Wizard.md) do assistente de aplicativo MFC quando o projeto foi criado.  
  
> [!NOTE]
>  O assistente não fornece suporte de impressão automática das classes derivadas de `CFormView`.  
  
 Consulte [Modelos de documentos e o processo de criação do documento\/exibição](../../mfc/document-templates-and-the-document-view-creation-process.md) para obter mais informações.  
  
## Cadeias de caracteres de não localizados  
 Se aplica aos aplicativos que criam documentos do usuário.  Os usuários podem abrir e salvar documentos mais facilmente se o tipo de documento tem uma extensão de arquivo e uma ID de tipo de arquivo  Esses itens não são localizados como são usados pelo sistema em vez de pelo usuário.  
  
 **Extensão de Arquivo**  
 Define a extensão de arquivo associada ao tipo de documento para este aplicativo de formulários.  A opção da extensão de arquivo com base no nome da classe.  Por exemplo, se a nova classe de MFC é nomeada **CWidget**, por padrão, a extensão de arquivo é .wid.  A extensão de arquivo é usada nos filtros de arquivo e nas caixas de diálogo de **Abrir** e de **Salvar como** .  
  
 Se você alterar a extensão de arquivo, a alteração seja refletida na caixa de **Nome do filtro** .  
  
> [!NOTE]
>  Se você alterar a extensão de arquivo padrão, não inclua o período.  
  
 **File type ID**  
 Define o rótulo do documento no Registro do sistema.  
  
## Cadeias de caracteres localizadas  
 Gerenciar as cadeias de caracteres associadas aos formulários e os documentos que são lidos e usados pelos usuários do aplicativo, de modo que as cadeias de caracteres são encontradas.  
  
 **Doc type name**  
 Identifica o tipo de documento na qual um documento de aplicativo pode ser agrupado.  Por padrão, é baseado no nome da classe.  Por exemplo, se a nova classe de MFC é nomeada **CWidget**, por padrão, o nome do tipo de documento é o Widget.  Alterar a opção não altera nenhuma outra opções desta caixa de diálogo.  
  
 **Nome do filtro**  
 Define o nome que os usuários podem indicar para localizar arquivos do tipo de arquivo especificado.  Essa opção está disponível nas opções de **Arquivos do tipo** e de **Salvar como tipo** no padrão **Abrir** e em caixas de diálogo de **Salvar como** .  Por padrão, o nome é baseado no nome do projeto mais arquivos, seguido pela extensão indicada em **Extensão de Arquivo**.  Por exemplo, se o projeto é denominado o Widget, e a extensão de arquivo é .wid, **Nome do filtro** é os arquivos do Widget \*.wid \(\) por padrão.  
  
 **File new short name**  
 Define o nome que será exibido na caixa de diálogo padrão de `New` do windows, se o projeto tiver mais de um modelo de documento.  Se seu aplicativo for [Servidor de automação](../../mfc/automation-servers.md), esse nome é usado como o nome curto do objeto de automação.  Por padrão, esse nome é baseado no nome da classe.  
  
 **File type long name**  
 Define o nome do tipo de arquivo no Registro do sistema.  Se seu aplicativo for um servidor de automação, esse nome é usado como o nome longo do objeto de automação.  Por padrão, esse nome é baseado no nome da classe mais. Documento.  Por exemplo, se o nome de classe é **CWidget**, **File type long name** é documento do Widget.  
  
 **Document class**  
 Indica a classe do projeto.  Por padrão, esta classe é a classe do documento de aplicativo principal, conforme listado na página de [Classes de revisão gerados](../../mfc/reference/generated-classes-mfc-application-wizard.md) do assistente de aplicativo MFC.  Você pode selecionar outra classe do documento na lista, se você adicionou outras classes do documento no projeto.  
  
## Consulte também  
 [Assistente para adicionar classe MFC](../../mfc/reference/mfc-add-class-wizard.md)   
 [MFC Class](../../mfc/reference/adding-an-mfc-class.md)   
 [Adicionando uma classe](../Topic/Adding%20a%20Class%20\(Visual%20C++\).md)