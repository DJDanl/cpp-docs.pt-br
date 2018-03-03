---
title: "Configurações do aplicativo, Assistente de controle ActiveX MFC | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.appwiz.mfc.ctl.appset
dev_langs:
- C++
helpviewer_keywords:
- MFC ActiveX Control Wizard, application settings
ms.assetid: 48475194-cc63-467f-8499-f142269a4c1c
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 4b63507ba50f5f9d7dfb0fe5487e2758ced02cdd
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="application-settings-mfc-activex-control-wizard"></a>Configurações do aplicativo, Assistente de Controle ActiveX MFC
Use esta página do Assistente de controle ActiveX do MFC para criar e adicionar recursos básicos para um novo projeto MFC ActiveX. Essas configurações se aplicam ao próprio aplicativo e não a qualquer recurso específico ou elemento do controle.  
  
 **Licença de tempo de execução**  
 Selecione esta opção para gerar um arquivo de licença de usuário para distribuir com o controle. A licença é um arquivo de texto, *NomeDoProjeto*. lic. Esse arquivo deve estar no mesmo diretório que a DLL do controle para permitir que uma instância do controle a ser criado em um ambiente de tempo de design. Geralmente você distribuí-lo com o controle, mas os clientes não distribuí-lo.  
  
 **Gerar arquivos de ajuda**  
 Selecione esta opção para gerar arquivos de ajuda fragmentado e configurar o projeto para incluir a Ajuda para o seu controle. Um projeto padrão, criado sem essa opção, somente gera um **sobre** caixa que é exibida quando o usuário clica o controle usa F1 ou clicar em **ajuda** no contêiner do controle.  
  
> [!NOTE]
>  Como a Ajuda é exibida depende de como o controle interage com seu contêiner. Se você incluir ajuda com o contêiner, você deve tratar mensagens entre o controle e o contêiner para exibir a Ajuda adequadamente.  
  
 Quando você gerar arquivos de ajuda usando o assistente, o projeto inclui o seguinte:  
  
-   A. vcxproj arquivo contém o código para criar e configurar o arquivo de ajuda quando o projeto é compilado.  
  
-   O arquivo *projnamePropPage*arquivo. cpp inclui um [SetHelpInfo](../../mfc/reference/colepropertypage-class.md#sethelpinfo) função no construtor.  
  
-   O arquivo projname.hpj, é o arquivo de projeto de Ajuda usado pelo compilador de ajuda para criar o arquivo de Ajuda do controle ActiveX. O arquivo. hpj é um arquivo de texto que contém as informações sobre como criar o arquivo de Ajuda e os caminhos para os arquivos adicionais (por exemplo, bitmaps) inclui o arquivo de Ajuda.  
  
-   O projeto inclui o diretório HLP para conter os arquivos de bitmap de Ajuda do projeto e o arquivo de tópico de Ajuda (*NomeDoProjeto*. rtf). Esse arquivo de tópico de Ajuda contém tópicos da Ajuda padrão para as propriedades, eventos e métodos com suporte de vários controles ActiveX comuns. Você pode editar o arquivo. RTF para adicionar ou remover tópicos de Ajuda específicos.  
  
## <a name="see-also"></a>Consulte também  
 [Assistente de controle ActiveX MFC](../../mfc/reference/mfc-activex-control-wizard.md)   
 [Nomes de controle, Assistente de controle ActiveX MFC](../../mfc/reference/control-names-mfc-activex-control-wizard.md)   
 [Configurações de controle, Assistente de controle ActiveX do MFC](../../mfc/reference/control-settings-mfc-activex-control-wizard.md)

