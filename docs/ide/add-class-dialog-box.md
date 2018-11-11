---
title: Caixa de diálogo Adicionar Classe
ms.date: 11/04/2016
f1_keywords:
- vc.addclass
helpviewer_keywords:
- Add Class dialog box
ms.assetid: 916259b8-8e5f-4267-bd10-313483beba67
ms.openlocfilehash: 405f88f7f77ea75584ec3cfd76af1ea9a0457ed6
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50643190"
---
# <a name="add-class-dialog-box"></a>Caixa de diálogo Adicionar Classe

A caixa de diálogo **Adicionar Classe** contém modelos que permitem:

- Abrir um assistente de código correspondente, se houver um disponível. Para obter mais informações, confira [Adicionando funcionalidade com assistentes de código](../ide/adding-functionality-with-code-wizards-cpp.md).

   \- ou -

- Criar a nova classe automaticamente adicionando o código-fonte e os arquivos apropriados ao projeto.

Acesse a caixa de diálogo **Adicionar Classe** no menu **Projeto**, **Gerenciador de Soluções** ou em [Modo de Exibição de Classe](/visualstudio/ide/viewing-the-structure-of-code).

> [!NOTE]
>  Quando você tentar adicionar uma classe que não é adequada ao projeto atual, você receberá uma mensagem de erro. Clique em **OK** para retornar à caixa de diálogo **Adicionar Classe**.

## <a name="add-class-templates"></a>Modelos de Adicionar Classe

Há quatro categorias de modelos **Adicionar Classe**: .NET, ATL, MFC e Genérico. Quando você selecionar um modelo no painel **Modelos**, o texto que descreve a seleção será exibido nos painéis **Categorias** e **Modelos**.

### <a name="net"></a>.NET

|Modelo|Wizard|
|--------------|------------|
|Serviço Web ASP.NET|Não disponível|
|Classe do Componente (.NET)|Não disponível|
|Classe do Instalador (.NET)|Não disponível|
|Controle de Usuário (.NET)|Não disponível|
|Windows Form (.NET)|Não disponível|

### <a name="atl"></a>ATL

|Modelo|Wizard|
|--------------|------------|
|Adicionar Suporte para ATL ao MFC|Não disponível|
|Componente Active Server Page da ATL|[Assistente do componente Active Server Page da ATL](../atl/reference/atl-active-server-page-component-wizard.md)|
|Controle da ATL|[Assistente de Controle da ATL](../atl/reference/atl-control-wizard.md)|
|Caixa de Diálogo da ATL|[Assistente de caixa de diálogo da ATL](../atl/reference/atl-dialog-wizard.md)|
|Componente COM+ 1.0 da ATL|[Assistente de componente de COM+ 1.0 da ATL](../atl/reference/atl-com-plus-1-0-component-wizard.md)|
|Consumidor OLEDB da ATL|[Assistente de cliente OLE DB da ATL](../atl/reference/atl-ole-db-consumer-wizard.md)|
|Provedor OLEDB da ATL|[Assistente de provedor OLE DB da ATL](../atl/reference/atl-ole-db-provider-wizard.md)|
|Página de Propriedades da ATL|[Assistente de página de propriedades da ATL](../atl/reference/atl-property-page-wizard.md)|
|Objeto ATL Simples|[Assistente de objeto simples da ATL](../atl/reference/atl-simple-object-wizard.md)|
|Provedor de Eventos WMI|Assistente do Provedor de Eventos WMI|
|Provedor de Instâncias da WMI|Assistente do Provedor de Instâncias da WMI|

### <a name="mfc"></a>MFC

|Modelo|Wizard|
|--------------|------------|
|MFC Class|[Assistente para adicionar classe do MFC](../mfc/reference/mfc-add-class-wizard.md)|
|Classe MFC em Controle ActiveX|[Assistente para Adicionar Classe de Controle ActiveX](../ide/add-class-from-activex-control-wizard.md)|
|Classe MFC em TypeLib|[Assistente para Adicionar Classe em TypeLib](../mfc/reference/add-class-from-typelib-wizard.md)|
|Consumidor ODBC do MFC|[Assistente de consumidor ODBC do MFC](../mfc/reference/mfc-odbc-consumer-wizard.md)|

### <a name="generic-classes"></a>Classes genéricas

|Modelo|Wizard|
|--------------|------------|
|Classe C++ Genérica|[Assistente da Classe C++ Genérica](../ide/generic-cpp-class-wizard.md)|

## <a name="see-also"></a>Consulte também

[Adicionando uma função de membro](../ide/adding-a-member-function-visual-cpp.md)<br>
[Adicionando uma variável de membro](../ide/adding-a-member-variable-visual-cpp.md)<br>
[Substituindo uma função virtual](../ide/overriding-a-virtual-function-visual-cpp.md)<br>
[Manipulador de mensagens do MFC](../mfc/reference/adding-an-mfc-message-handler.md)<br>
[Navegando pela estrutura de classe](../ide/navigating-the-class-structure-visual-cpp.md)