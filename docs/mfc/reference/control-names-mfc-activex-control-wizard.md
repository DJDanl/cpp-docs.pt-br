---
title: Nomes de controle, Assistente de Controle ActiveX MFC
ms.date: 11/04/2016
f1_keywords:
- vc.appwiz.mfc.ctl.names
helpviewer_keywords:
- MFC ActiveX Control Wizard, control names
ms.assetid: 9b8b81d2-36df-48ed-b58a-a771a0e269ee
ms.openlocfilehash: a143c8b08c73676af0d37cd2b67667e8270dc2b1
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57259848"
---
# <a name="control-names-mfc-activex-control-wizard"></a>Nomes de controle, Assistente de Controle ActiveX MFC

Especifique os nomes para a classe de controle e a classe de página de propriedade, os nomes de tipo e digite identificadores para o seu controle. Com exceção de **Short name**, todos os outros campos podem ser editados de modo independente. Se você alterar o texto para **Short name**, a alteração é refletida nos nomes de todos os outros campos nesta página. Esse comportamento de nomenclatura é projetado para tornar todos os nomes de fácil identificação para você à medida que desenvolve seu controle.

- **Nome curto**

   Forneça um nome abreviado para o controle. Por padrão, esse nome é baseado no nome do projeto que você forneceu na **novo projeto** caixa de diálogo. O nome que você fornece determina os nomes de classe, os nomes de tipo e os identificadores de tipo, a menos que você altere esses campos individualmente.

- **Nome de classe de controle**

   Por padrão, o nome da classe do controle é baseado no nome curto, com `C` como um prefixo e `Ctrl` como um sufixo. Por exemplo, se seu controle menor do nome é `Price`, o nome de classe do controle é `CPriceCtrl`.

- **Arquivo de controle de. h**

   Por padrão, o nome do arquivo de cabeçalho se baseia o nome curto, com `Ctrl` como um sufixo e `.h` como a extensão de arquivo. Por exemplo, se seu controle menor do nome é `Price`, é o nome do arquivo de cabeçalho `PriceCtrl.h`. O nome neste campo deve corresponder ao nome de classe do controle.

- **Arquivo. cpp do controle**

   Por padrão, o nome do arquivo de cabeçalho se baseia o nome curto, com `Ctrl` como um sufixo e `.cpp` como a extensão de arquivo. Por exemplo, se seu controle menor do nome é `Price`, é o nome do arquivo de cabeçalho `PriceCtrl.cpp`. O nome neste campo deve corresponder ao nome de cabeçalho.

- **Nome do tipo de controle**

   Por padrão, o nome do tipo de controle se baseia o nome curto, seguido por `Control`. Por exemplo, se seu controle menor do nome é `Price`, o nome de tipo de classe de controle é `Price Control`. Se você alterar o valor neste campo, verifique se que o nome indica uma herança.

- **ID do tipo de controle**

   Define a ID do tipo de controle da classe do controle. O controle grava essa cadeia de caracteres no registro quando ele é adicionado a um projeto. Aplicativos de contêiner usam essa cadeia de caracteres para criar uma instância do controle.

   Por padrão, a ID de tipo de controle é baseada no nome do projeto indicado na **novo projeto** caixa de diálogo e o nome curto. Esse nome deve corresponder ao nome de tipo.

   Por padrão, a ID de tipo de controle aparece da seguinte maneira:

   *ProjectName.ShortName*Ctrl.1

   Se você alterar o nome curto na caixa de diálogo, a ID de tipo de controle aparece da seguinte maneira:

   *ProjectName.NewShortName*Ctrl.1

- **Nome de classe do PropPage**

   Por padrão, o nome da classe de página de propriedade é baseado no nome curto, com `C` como um prefixo e `PropPage` como um sufixo. Por exemplo, se seu controle menor do nome é `Price`, o nome de classe de página de propriedade é `CPricePropPage`. Esse nome deve corresponder ao nome de classe de controle, acrescido `PropPage`.

- **Arquivo. h do PropPage**

   Por padrão, o nome do arquivo de cabeçalho de página de propriedade é baseado no nome curto, com como uma `PropPage` como um sufixo e `.h` como a extensão de arquivo. Por exemplo, se seu controle menor do nome é `Price`, é o nome de arquivo de cabeçalho de página de propriedade `PricePropPage.h`. Esse nome deve corresponder ao nome de classe.

- **Arquivo. cpp do PropPage**

   Por padrão, o nome do arquivo de implementação de página de propriedade é baseado no nome curto, com como uma `PropPage` como um sufixo e `.cpp` como a extensão de arquivo. Por exemplo, se seu controle menor do nome é `Price`, é o nome de arquivo de cabeçalho de página de propriedade `PricePropPage.cpp`. Esse nome deve corresponder ao nome do arquivo de cabeçalho.

- **Nome de tipo do PropPage**

   Por padrão, o nome de tipo de página de propriedade se baseia o nome curto, seguido por `Property Page`. Por exemplo, se seu controle menor do nome é `Price`, é o nome do tipo de página propriedade `Price Property Page`. Se você alterar o valor neste campo, verifique se que o nome indica a classe de controle.

- **ID de tipo do PropPage**

   Define a ID da classe de página de propriedade. O controle grava essa cadeia de caracteres no registro quando ele é aplicado a um projeto. Um aplicativo de contêiner usa essa cadeia de caracteres para criar uma instância da página de propriedades do controle.

   Por padrão, a ID de tipo de página de propriedade é baseada no nome do projeto indicado na **novo projeto** caixa de diálogo e o nome curto. Esse nome deve corresponder ao nome de tipo.

   Por padrão, a ID de tipo de página de propriedade aparece da seguinte maneira:

   *ProjectName.ShortName*PropPage.1

   Se você alterar o nome curto na caixa de diálogo, a ID de tipo de página de propriedade aparece da seguinte maneira:

   *ProjectName.NewShortName*PropPage.1

## <a name="see-also"></a>Consulte também

[Assistente de controle ActiveX do MFC](../../mfc/reference/mfc-activex-control-wizard.md)<br/>
[Configurações do aplicativo, Assistente de controle ActiveX do MFC](../../mfc/reference/application-settings-mfc-activex-control-wizard.md)<br/>
[Configurações de controle, Assistente de controle ActiveX do MFC](../../mfc/reference/control-settings-mfc-activex-control-wizard.md)<br/>
[Tipos de arquivo criados para projetos do Visual C++](../../ide/file-types-created-for-visual-cpp-projects.md)
