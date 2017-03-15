---
title: "Caixa de di&#225;logo Adicionar Classe | Microsoft Docs"
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
  - "vc.addclass"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Caixa de diálogo Adicionar Classe"
ms.assetid: 916259b8-8e5f-4267-bd10-313483beba67
caps.latest.revision: 12
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Caixa de di&#225;logo Adicionar Classe
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O **Add Class** caixa de diálogo contém os modelos que permitem que você:  
  
-   Abra um Assistente de código correspondente, se disponível. Para obter mais informações, consulte [adicionando funcionalidade com assistentes de código](../ide/adding-functionality-with-code-wizards-cpp.md).  
  
 \- ou \-  
  
-   Crie automaticamente a nova classe adicionando o código\-fonte e arquivos apropriados ao seu projeto.  
  
 Você pode acessar o **Add Class** caixa de diálogo o **projeto** menu **Solution Explorer**, ou [Class View](http://msdn.microsoft.com/pt-br/8d7430a9-3e33-454c-a9e1-a85e3d2db925).  
  
> [!NOTE]
>  Quando você tentar adicionar uma classe que não é adequada ao seu projeto atual, você receberá uma mensagem de erro. Clique em **OK** para retornar para o **Add Class** caixa de diálogo.  
  
## Adicionar modelos de classe  
 Há quatro categorias de **Add Class** modelos: genérico, ATL, MFC e .NET. Quando você seleciona um modelo no **modelos** painel, o texto que descreve sua seleção aparecerá sob o **categorias** e **modelos** painéis.  
  
### .NET  
  
|Modelo|Assistente|  
|------------|----------------|  
|Serviço Web do ASP.NET|Não disponível|  
|Classe de componente \(.NET\)|Não disponível|  
|Classe de instalador \(.NET\)|Não disponível|  
|Controle de usuário \(.NET\)|Não disponível|  
|Formulário do Windows \(.NET\)|Não disponível|  
  
### ATL  
  
|Modelo|Assistente|  
|------------|----------------|  
|Adicionar suporte ATL ao MFC|Não disponível|  
|Componente de página de servidor ativo do ATL|[Assistente de componente de página do Active Server ATL](../atl/reference/atl-active-server-page-component-wizard.md)|  
|Controle ATL|[Assistente de controle ATL](../atl/reference/atl-control-wizard.md)|  
|Caixa de diálogo do ATL|[Assistente de caixa de diálogo do ATL](../atl/reference/atl-dialog-wizard.md)|  
|ATL componente COM\+ 1.0|[Assistente para ATL COM\+ 1.0 do componente](../atl/reference/atl-com-plus-1-0-component-wizard.md)|  
|Consumidor OLEDB do ATL|[Assistente de consumidor do ATL OLE DB](../atl/reference/atl-ole-db-consumer-wizard.md)|  
|Provedor OLEDB do ATL|[Assistente do ATL OLE DB Provider](../atl/reference/atl-ole-db-provider-wizard.md)|  
|Página de propriedades ATL|[Assistente de página de propriedades ATL](../atl/reference/atl-property-page-wizard.md)|  
|ATL Simple Object|[ATL Simple Object Wizard](../atl/reference/atl-simple-object-wizard.md)|  
|Provedor de eventos WMI|Assistente de provedor de eventos WMI|  
|Provedor de instância WMI|Assistente do provedor de instância WMI|  
  
### MFC  
  
|Modelo|Assistente|  
|------------|----------------|  
|MFC Class|[Assistente para adicionar classe MFC](../mfc/reference/mfc-add-class-wizard.md)|  
|Classe de controle ActiveX do MFC|[Assistente para Adicionar Classe de Controle ActiveX](../ide/add-class-from-activex-control-wizard.md)|  
|Classe do MFC de TypeLib|[Adicionar classe de Typelib Assistente](../mfc/reference/add-class-from-typelib-wizard.md)|  
|Consumidor ODBC do MFC|[Assistente de consumidor ODBC MFC](../mfc/reference/mfc-odbc-consumer-wizard.md)|  
  
### Classes genéricas  
  
|Modelo|Assistente|  
|------------|----------------|  
|Classe C\+\+ genérica|[Assistente da Classe C\+\+ Genérica](../ide/generic-cpp-class-wizard.md)|  
  
## Consulte também  
 [Adicionando uma função de membro](../ide/adding-a-member-function-visual-cpp.md)   
 [Adicionando uma variável de membro](../ide/adding-a-member-variable-visual-cpp.md)   
 [Substituindo uma função virtual](../Topic/Overriding%20a%20Virtual%20Function%20\(Visual%20C++\).md)   
 [Manipulador de mensagens do MFC](../mfc/reference/adding-an-mfc-message-handler.md)   
 [Navegando na estrutura da classe](../ide/navigating-the-class-structure-visual-cpp.md)