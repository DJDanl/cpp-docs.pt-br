---
title: "Configura&#231;&#245;es do aplicativo, Assistente de Controle ActiveX MFC | Microsoft Docs"
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
  - "vc.appwiz.mfc.ctl.appset"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Assistente de controle ActiveX MFC, configurações de aplicativo"
ms.assetid: 48475194-cc63-467f-8499-f142269a4c1c
caps.latest.revision: 12
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Configura&#231;&#245;es do aplicativo, Assistente de Controle ActiveX MFC
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Use esta página do Assistente de controle de ActiveX MFC para criar e adicionar recursos básicos para um novo projeto do ActiveX MFC. Essas configurações se aplicam ao próprio aplicativo e não a qualquer elemento do controle ou um recurso específico.  
  
 **Licença de tempo de execução**  
 Selecione esta opção para gerar um arquivo de licença de usuário para distribuir com o controle. A licença é um arquivo de texto *NomeDoProjeto*. lic. Esse arquivo deve estar no mesmo diretório que a DLL do controle para permitir que uma instância do controle a ser criado em um ambiente de tempo de design. Geralmente distribuir esse arquivo com o controle, mas os clientes não distribuí\-lo.  
  
 **Gerar arquivos de ajuda**  
 Selecione esta opção para gerar arquivos de ajuda com stubs e configurar o projeto para incluir a Ajuda para o seu controle. Um projeto padrão, criado sem essa opção, apenas gera uma **sobre** caixa que é exibida quando o usuário clica o controle usa F1 ou clicar em **Ajuda** no contêiner do controle.  
  
> [!NOTE]
>  Como ajuda é exibida depende de como seu controle interage com seu contêiner. Se você incluir ajuda com seu contêiner, você deve tratar mensagens entre o controle e o contêiner para exibir a Ajuda de forma apropriada.  
  
 Ao gerar arquivos de ajuda usando o assistente, seu projeto inclui o seguinte:  
  
-   O arquivo vcxproj contém código para criar e configurar o arquivo de ajuda quando o projeto é criado.  
  
-   O arquivo *projnamePropPage*. cpp inclui um [SetHelpInfo](../Topic/COlePropertyPage::SetHelpInfo.md) função no construtor.  
  
-   O arquivo projname.hpj, é o arquivo de projeto de Ajuda usado pelo compilador de ajuda para criar o arquivo de Ajuda do controle ActiveX. O arquivo. hpj é um arquivo de texto que contém as informações sobre a criação de seu arquivo de Ajuda e os caminhos para os arquivos adicionais \(por exemplo, bitmaps\) inclui o arquivo de Ajuda.  
  
-   O projeto inclui o diretório HLP para conter os arquivos de bitmap de Ajuda do projeto e o arquivo de tópico da Ajuda \(*NomeDoProjeto*. rtf\). Esse arquivo de Ajuda contém tópicos da Ajuda padrão para as propriedades, eventos e métodos com suporte de vários controles ActiveX comuns. Você pode editar o arquivo. RTF para adicionar ou remover tópicos específicos de Ajuda.  
  
## Consulte também  
 [Assistente de controle ActiveX MFC](../../mfc/reference/mfc-activex-control-wizard.md)   
 [Nomes de controle, Assistente de Controle ActiveX MFC](../../mfc/reference/control-names-mfc-activex-control-wizard.md)   
 [Configurações de controle, Assistente de Controle ActiveX MFC](../../mfc/reference/control-settings-mfc-activex-control-wizard.md)