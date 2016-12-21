---
title: "Criando um controle ActiveX MFC | Microsoft Docs"
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
  - "vc.appwiz.activex.project"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Controles ActiveX [C++], criando"
  - "Controles ActiveX MFC [C++], criando"
ms.assetid: 8bd5a93c-d04d-414e-bb28-163fdc1c0dd5
caps.latest.revision: 13
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Criando um controle ActiveX MFC
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Os programas de controle ActiveX são programas modulares criados para executar um tipo específico de funcionalidade a um aplicativo pai.  Por exemplo, você pode criar um controle como um botão para uso em uma caixa de diálogo, ou a barra de ferramentas para uso em uma página da Web.  
  
 A maneira mais fácil de criar um controle ActiveX de MFC é usar [Assistente de controle ActiveX de MFC](../../mfc/reference/mfc-activex-control-wizard.md).  
  
### Para criar um controle ActiveX de MFC usando o assistente de controle ActiveX de MFC  
  
1.  Siga as instruções no tópico da ajuda [Criando um projeto com um assistente de aplicativo Visual C\+\+](../../ide/creating-desktop-projects-by-using-application-wizards.md).  
  
2.  Na caixa de diálogo de **Novo Projeto** , selecione o ícone de **Controle ActiveX do MFC** no painel modelos para abrir o assistente de controle ActiveX de MFC.  
  
3.  Definir seu [configurações de aplicativo](../../mfc/reference/application-settings-mfc-activex-control-wizard.md), [controle nomes](../../mfc/reference/control-names-mfc-activex-control-wizard.md), e [controle configurações](../../mfc/reference/control-settings-mfc-activex-control-wizard.md) usando o assistente de controle ActiveX de MFC.  
  
    > [!NOTE]
    >  Ignore esta etapa para manter as configurações padrão do assistente.  
  
4.  Clique em **Concluir** para fechar o assistente e abra o novo projeto no ambiente de desenvolvimento.  
  
 Depois que você criar seu projeto, você pode exibir os arquivos criados em **Gerenciador de Soluções**.  Para obter mais informações sobre arquivos que o assistente cria para seu projeto, consulte o arquivo gerado pelo projeto ReadMe.txt.  Para obter mais informações sobre os tipos de arquivo, consulte [Tipos de arquivo criados para projetos do Visual C\+\+](../../ide/file-types-created-for-visual-cpp-projects.md).  
  
 Depois que você criar seu projeto, você pode usar os assistentes de código para adicionar [funções](../../ide/add-member-function-wizard.md), [variáveis](../../ide/add-member-variable-wizard.md), [eventos](../../ide/add-event-wizard.md), [propriedades](../../ide/names-add-property-wizard.md), e [métodos](../../ide/add-method-wizard.md).  Para obter mais informações sobre como personalizar seu controle ActiveX, consulte [Controles ActiveX MFC](../../mfc/mfc-activex-controls.md).  
  
## Consulte também  
 [Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)   
 [Páginas de propriedade](../../ide/property-pages-visual-cpp.md)   
 [Deploying Applications](http://msdn.microsoft.com/pt-br/4ff8881d-0daf-47e7-bfe7-774c625031b4)