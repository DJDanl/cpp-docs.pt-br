---
title: Configurações do aplicativo, Assistente de Controle ActiveX MFC
ms.date: 11/04/2016
f1_keywords:
- vc.appwiz.mfc.ctl.appset
helpviewer_keywords:
- MFC ActiveX Control Wizard, application settings
ms.assetid: 48475194-cc63-467f-8499-f142269a4c1c
ms.openlocfilehash: 55f202ffabe945e55589ab1fc771a1757e23ca2f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372471"
---
# <a name="application-settings-mfc-activex-control-wizard"></a>Configurações do aplicativo, Assistente de Controle ActiveX MFC

Use esta página do MFC ActiveX Control Wizard para projetar e adicionar recursos básicos a um novo projeto MFC ActiveX. Essas configurações se aplicam ao próprio aplicativo e não a qualquer recurso ou elemento específico do controle.

- **Licença de tempo de execução**

   Selecione esta opção para gerar um arquivo de licença de usuário para distribuir com o controle. A licença é um arquivo de texto, *projname*.lic. Este arquivo deve estar no mesmo diretório que o DLL do controle para permitir que uma instância do controle seja criada em um ambiente de tempo de projeto. Você geralmente distribui este arquivo com o seu controle, mas seus clientes não o distribuem.

- **Gerar arquivos de ajuda**

   Selecione esta opção para gerar arquivos de ajuda subbed e configure o projeto para incluir ajuda para o seu controle. Um projeto padrão, criado sem essa opção, gera apenas uma caixa **Sobre** que é exibida quando o usuário clica no controle, usa F1 ou **clica** em Ajuda no contêiner do controle.

   > [!NOTE]
   > A forma como a ajuda é exibida depende de como seu controle interage com seu contêiner. Se você incluir ajuda com o recipiente, você deve lidar com mensagens entre o controle e o recipiente para exibir a ajuda adequadamente.

   Quando você gera arquivos de ajuda usando o assistente, seu projeto inclui o seguinte:

  - O arquivo .vcxproj contém código para construir e configurar o arquivo de ajuda quando o projeto é construído.

  - O arquivo *projnamePropPage*.cpp inclui uma função [SetHelpInfo](../../mfc/reference/colepropertypage-class.md#sethelpinfo) no construtor.

  - O arquivo projname.hpj é o arquivo de projeto de ajuda usado pelo compilador de ajuda para criar o arquivo de ajuda do controle ActiveX. O arquivo .hpj é um arquivo de texto contendo as informações sobre a construção do seu arquivo de ajuda e os caminhos para os arquivos adicionais (por exemplo, bitmaps) que o arquivo de ajuda inclui.

  - O projeto inclui o diretório HLP para conter os arquivos de bitmap de ajuda do projeto e o arquivo de tópico de ajuda *(projname*.rtf). Este arquivo de tópico de ajuda contém os tópicos de ajuda padrão para as propriedades comuns, eventos e métodos suportados por muitos controles ActiveX. Você pode editar o arquivo .rtf para adicionar ou remover tópicos de ajuda específicos.

## <a name="see-also"></a>Confira também

[Assistente de controle ActiveX MFC](../../mfc/reference/mfc-activex-control-wizard.md)<br/>
[Nomes de controle, Assistente de controle ActiveX do MFC](../../mfc/reference/control-names-mfc-activex-control-wizard.md)<br/>
[Configurações de controle, Assistente de controle ActiveX do MFC](../../mfc/reference/control-settings-mfc-activex-control-wizard.md)
