---
title: Nomes de controle, Assistente de Controle ActiveX MFC
ms.date: 11/04/2016
f1_keywords:
- vc.appwiz.mfc.ctl.names
helpviewer_keywords:
- MFC ActiveX Control Wizard, control names
ms.assetid: 9b8b81d2-36df-48ed-b58a-a771a0e269ee
ms.openlocfilehash: eff7b537e7fe5c19d10cce8766557a3d1ff49342
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80077514"
---
# <a name="control-names-mfc-activex-control-wizard"></a>Nomes de controle, Assistente de Controle ActiveX MFC

Especifique os nomes para a classe de controle e a classe de página de propriedades, os nomes de tipo e os identificadores de tipo para o seu controle. Com exceção do **nome curto**, todos os outros campos podem ser editados de forma independente. Se você alterar o texto para **nome curto**, a alteração será refletida nos nomes de todos os outros campos nesta página. Esse comportamento de nomenclatura foi criado para tornar todos os nomes facilmente identificáveis à medida que você desenvolve seu controle.

- **Nome curto**

   Forneça um nome abreviado para o controle. Por padrão, esse nome se baseia no nome do projeto que você forneceu na caixa de diálogo **novo projeto** . O nome que você fornece determina os nomes de classe, os nomes de tipo e os identificadores de tipo, a menos que você altere esses campos individualmente.

- **Nome da classe de controle**

   Por padrão, o nome da classe de controle é baseado no nome curto, com `C` como um prefixo e `Ctrl` como um sufixo. Por exemplo, se o nome curto do seu controle for `Price`, o nome da classe de controle será `CPriceCtrl`.

- **Arquivo Control. h**

   Por padrão, o nome do arquivo de cabeçalho é baseado no nome curto, com `Ctrl` como um sufixo e `.h` como a extensão de arquivo. Por exemplo, se o nome curto do seu controle for `Price`, o nome do arquivo de cabeçalho será `PriceCtrl.h`. O nome neste campo deve corresponder ao nome da classe de controle.

- **Arquivo. cpp de controle**

   Por padrão, o nome do arquivo de cabeçalho é baseado no nome curto, com `Ctrl` como um sufixo e `.cpp` como a extensão de arquivo. Por exemplo, se o nome curto do seu controle for `Price`, o nome do arquivo de cabeçalho será `PriceCtrl.cpp`. O nome neste campo deve corresponder ao nome do cabeçalho.

- **Nome do tipo de controle**

   Por padrão, o nome do tipo de controle é baseado no nome curto, seguido por `Control`. Por exemplo, se o nome curto do seu controle for `Price`, o nome do tipo de classe de controle será `Price Control`. Se você alterar o valor nesse campo, certifique-se de que o nome indica uma herança.

- **ID do tipo de controle**

   Define a ID de tipo de controle da classe de controle. O controle grava essa cadeia de caracteres no registro quando ele é adicionado a um projeto. Os aplicativos de contêiner usam essa cadeia de caracteres para criar uma instância do controle.

   Por padrão, a ID do tipo de controle se baseia no nome do projeto, que você indicou na caixa de diálogo **novo projeto** e no nome curto. Esse nome deve corresponder ao nome do tipo.

   Por padrão, a ID de tipo de controle aparece da seguinte maneira:

   *ProjectName. ShortName* CTRL. 1

   Se você alterar o nome curto nessa caixa de diálogo, a ID de tipo de controle aparecerá da seguinte maneira:

   *ProjectName. NewShortName* CTRL. 1

- **Nome da classe PropPage**

   Por padrão, o nome da classe da página de propriedades é baseado no nome curto, com `C` como um prefixo e `PropPage` como um sufixo. Por exemplo, se o nome curto do seu controle for `Price`, o nome da classe da página de propriedades será `CPricePropPage`. Esse nome deve corresponder ao nome da classe de controle, acrescentado com `PropPage`.

- **Arquivo PropPage. h**

   Por padrão, o nome do arquivo de cabeçalho da página de propriedades é baseado no nome curto, com como um `PropPage` como um sufixo e `.h` como a extensão de arquivo. Por exemplo, se o nome curto do seu controle for `Price`, o nome do arquivo de cabeçalho da página de propriedades será `PricePropPage.h`. Esse nome deve corresponder ao nome da classe.

- **Arquivo PropPage. cpp**

   Por padrão, o nome do arquivo de implementação da página de propriedades é baseado no nome curto, com como um `PropPage` como um sufixo e `.cpp` como a extensão de arquivo. Por exemplo, se o nome curto do seu controle for `Price`, o nome do arquivo de cabeçalho da página de propriedades será `PricePropPage.cpp`. Esse nome deve corresponder ao nome do arquivo de cabeçalho.

- **Nome do tipo de PropPage**

   Por padrão, o nome do tipo de página de propriedade é baseado no nome curto, seguido por `Property Page`. Por exemplo, se o nome curto do seu controle for `Price`, o nome do tipo de página de propriedade será `Price Property Page`. Se você alterar o valor nesse campo, certifique-se de que o nome indica a classe de controle.

- **ID do tipo de PropPage**

   Define a ID da classe da página de propriedades. O controle grava essa cadeia de caracteres no registro quando ele é aplicado a um projeto. Um aplicativo de contêiner usa essa cadeia de caracteres para criar uma instância da página de propriedades do controle.

   Por padrão, a ID do tipo de página de propriedade é baseada no nome do projeto, que você indicou na caixa de diálogo **novo projeto** e no nome curto. Esse nome deve corresponder ao nome do tipo.

   Por padrão, a ID de tipo de página de propriedades aparece da seguinte maneira:

   *ProjectName. ShortName* PropPage. 1

   Se você alterar o nome curto nessa caixa de diálogo, a ID do tipo de página de propriedades será exibida da seguinte maneira:

   *ProjectName. NewShortName* PropPage. 1

## <a name="see-also"></a>Confira também

[Assistente de controle ActiveX do MFC](../../mfc/reference/mfc-activex-control-wizard.md)<br/>
[Configurações do aplicativo, Assistente de controle ActiveX do MFC](../../mfc/reference/application-settings-mfc-activex-control-wizard.md)<br/>
[Configurações de controle, Assistente de controle ActiveX do MFC](../../mfc/reference/control-settings-mfc-activex-control-wizard.md)<br/>
[Tipos de arquivo criados para projetos do Visual Studio C++](../../build/reference/file-types-created-for-visual-cpp-projects.md)
