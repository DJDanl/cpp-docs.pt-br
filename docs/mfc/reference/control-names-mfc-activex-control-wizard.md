---
title: "Nomes de controle, Assistente de Controle ActiveX MFC | Microsoft Docs"
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
  - "vc.appwiz.mfc.ctl.names"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Assistente de controle ActiveX MFC, nomes de controle"
ms.assetid: 9b8b81d2-36df-48ed-b58a-a771a0e269ee
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Nomes de controle, Assistente de Controle ActiveX MFC
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Especifique os nomes da classe de controle e da classe da página de propriedades, os nomes de tipo, e identificadores de tipo para seu controle.  Com exceção de **Nome curto**, todos os outros campos podem ser editados independente.  Se você alterar o texto de **Nome curto**, a alteração seja refletida nos nomes de todos os outros campos nessa página.  Esse comportamento de nomeação é criado para fazer facilmente todos os nomes identificáveis para você como você desenvolve seu controle.  
  
 **Nome curto**  
 Forneça um nome abreviado para o controle.  Por padrão, esse nome é baseado no nome de projeto que você forneceu na caixa de diálogo de **Novo Projeto** .  O nome fornecido determina os nomes da classe, os nomes de tipo, e identificadores do tipo, a menos que você altere os campos individualmente.  
  
 **Control class name**  
 Por padrão, o nome da classe do controle é baseado no nome curto, com `C` como prefixo e `Ctrl` como um sufixo.  Por exemplo, se o nome curto do controle é `Price`, o nome da classe do controle é `CPriceCtrl`.  
  
 **Control .h file**  
 Por padrão, o nome do arquivo de cabeçalho é baseado no nome curto, com `Ctrl` como um sufixo e `.h` como a extensão de arquivo.  Por exemplo, se o nome curto do controle é `Price`, o nome do arquivo de cabeçalho é `PriceCtrl.h`.  O nome desse campo deve corresponder ao nome da classe do controle.  
  
 **Control .cpp file**  
 Por padrão, o nome do arquivo de cabeçalho é baseado no nome curto, com `Ctrl` como um sufixo e `.cpp` como a extensão de arquivo.  Por exemplo, se o nome curto do controle é `Price`, o nome do arquivo de cabeçalho é `PriceCtrl.cpp`.  O nome desse campo deve corresponder ao nome do cabeçalho.  
  
 **Control type name**  
 Por padrão, o nome do tipo de controle é baseado no nome curto, seguido por `Control`.  Por exemplo, se o nome curto do controle é `Price`, o nome do tipo de classe do controle é `Price Control`.  Se você alterar o valor nesse campo, verifique se o nome indica uma herança.  
  
 **Control type ID**  
 Define a ID do tipo de controle da classe do controle.  O controle grava essa cadeia de caracteres ao Registro quando o é adicionado a um projeto.  Os aplicativos de contêiner usam essa cadeia de caracteres para criar uma instância do controle.  
  
 Por padrão, o ID do tipo de controle é baseado no nome do projeto, que você indicou na caixa de diálogo de **Novo Projeto** , e o nome curto.  Esse nome deve corresponder ao nome do tipo.  
  
 Por padrão, o ID do tipo de validação a seguinte forma:  
  
 *ProjectName.ShortNameCtrl.1*  
  
 Se você alterar o nome curto nesta caixa de diálogo, o ID do tipo de validação a seguinte forma:  
  
 *ProjectName.NewShortNameCtrl.1*  
  
 **PropPage class name**  
 Por padrão, o nome da classe da página de propriedades é baseado no nome curto, com `C` como prefixo e `PropPage` como um sufixo.  Por exemplo, se o nome curto do controle é `Price`, o nome da classe da página de propriedades é `CPricePropPage`.  Esse nome deve corresponder ao nome da classe de controle, com `PropPage`.  
  
 **PropPage .h file**  
 Por padrão, o nome do arquivo de cabeçalho da página de propriedades é baseado no nome curto, como com `PropPage` como um sufixo e `.h` como a extensão de arquivo.  Por exemplo, se o nome curto do controle é `Price`, o nome do arquivo de cabeçalho de página de propriedades é `PricePropPage.h`.  Esse nome deve corresponder ao nome da classe.  
  
 **PropPage .cpp file**  
 Por padrão, o nome do arquivo de implementação da página de propriedades é baseado no nome curto, como com `PropPage` como um sufixo e `.cpp` como a extensão de arquivo.  Por exemplo, se o nome curto do controle é `Price`, o nome do arquivo de cabeçalho de página de propriedades é `PricePropPage.cpp`.  Esse nome deve corresponder ao nome do arquivo de cabeçalho.  
  
 **PropPage type name**  
 Por padrão, o nome do tipo da página de propriedades é baseado no nome curto, seguido por `Property Page`.  Por exemplo, se o nome curto do controle é `Price`, o nome do tipo da página de propriedades é `Price Property Page`.  Se você alterar o valor nesse campo, verifique se o nome indica a classe do controle.  
  
 **PropPage type ID**  
 Define a ID da classe da página de propriedades.  O controle grava essa cadeia de caracteres no Registro quando é aplicado a um projeto.  Um aplicativo de contêiner usa essa cadeia de caracteres para criar uma instância da página de propriedades do controle.  
  
 Por padrão, o ID do tipo da página de propriedades é baseado no nome do projeto, que você indicou na caixa de diálogo de **Novo Projeto** , e o nome curto.  Esse nome deve corresponder ao nome do tipo.  
  
 Por padrão, o ID do tipo da página de propriedades aparecem como segue:  
  
 *ProjectName.ShortNamePropPage.1*  
  
 Se você alterar o nome curto nesta caixa de diálogo, o ID do tipo da página de propriedades aparecem como segue:  
  
 *ProjectName.NewShortNamePropPage.1*  
  
## Consulte também  
 [Assistente de controle ActiveX MFC](../../mfc/reference/mfc-activex-control-wizard.md)   
 [Configurações do aplicativo, Assistente de Controle ActiveX MFC](../../mfc/reference/application-settings-mfc-activex-control-wizard.md)   
 [Configurações de controle, Assistente de Controle ActiveX MFC](../../mfc/reference/control-settings-mfc-activex-control-wizard.md)   
 [Tipos de arquivo criados para projetos do Visual C\+\+](../../ide/file-types-created-for-visual-cpp-projects.md)