---
title: Adicionar uma classe
ms.date: 05/14/2019
f1_keywords:
- vc.addclass
helpviewer_keywords:
- ATL projects, adding classes
- classes [C++], creating
- classes [C++], adding
- Add Class dialog box
ms.assetid: c34b5f70-4e72-4faa-ba21-e2b05361c4d9
ms.openlocfilehash: fa53c2af5cd3e81c2d4877ef255430eac9525aad
ms.sourcegitcommit: fc1de63a39f7fcbfe2234e3f372b5e1c6a286087
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/15/2019
ms.locfileid: "66182676"
---
# <a name="add-a-class"></a>Adicionar uma classe

Para adicionar uma classe a um projeto do Visual Studio C++, no **Gerenciador de Soluções**, clique com o botão direito do mouse no projeto, escolha **Adicionar** e, em seguida, **Classe**. Isso abrirá a [caixa de diálogo Adicionar Classe](#add-class-dialog-box).

Ao adicionar uma classe, é necessário especificar um nome que seja diferente das classes já existentes no MFC ou na ATL. Se você especificar um nome já existente em uma das bibliotecas, o IDE mostrará uma mensagem de erro.

Caso a convenção de nomenclatura do projeto exija o uso de um nome existente, você poderá alterar apenas o uso de maiúsculas de uma ou mais letras no nome porque o C++ diferencia maiúsculas de minúsculas. Por exemplo, embora não seja possível nomear uma classe `CDocument`, é possível nomeá-la `cdocument`.

## <a name="in-this-section"></a>Nesta seção

- [Qual tipo de classe você deseja adicionar?](#what-kind-of-class-do-you-want-to-add)
- [Caixa de diálogo Adicionar Classe](#add-class-dialog-box)

## <a name="what-kind-of-class-do-you-want-to-add"></a>Qual tipo de classe você deseja adicionar?

Na caixa de diálogo **Adicionar Classe**, quando você expande o nó **Visual C++** no painel esquerdo, vários agrupamentos de modelos instalados são exibidos. Os grupos incluem **CLR**, **ATL**, **MFC** e **C++** . Quando você seleciona um grupo, uma lista dos modelos disponíveis nesse grupo é exibida no painel central. Cada modelo contém os arquivos e o código-fonte necessários para uma classe.

Para gerar uma nova classe, selecione um modelo no painel central, digite um nome para a classe na caixa **Nome** e selecione **Adicionar**. Isso abrirá o **Assistente de Adição de Classe**, de modo que você possa especificar opções para a classe.

- Para obter mais informações sobre como criar classes MFC, confira [classe MFC](../mfc/reference/adding-an-mfc-class.md).

- Para obter mais informações sobre como criar classes ATL, confira [objeto ATL simples](../atl/reference/adding-an-atl-simple-object.md).

> [!NOTE]
> O modelo **Adicionar Suporte para ATL ao MFC** não cria uma classe, mas configura o projeto para usar a ATL. Para obter mais informações, confira [suporte para ATL em um projeto MFC](../mfc/reference/adding-atl-support-to-your-mfc-project.md).

Para criar uma classe C++ que não usa o MFC, a ATL ou o CLR, use o modelo **Classe C++** no grupo **C++** de modelos instalados. Para obter mais informações, confira [Adicionar uma classe C++ genérica](../ide/adding-a-generic-cpp-class.md).

Dois tipos de classes C++ baseadas em formulário estão disponíveis. O primeiro deles, [Classe CFormView](../mfc/reference/cformview-class.md), cria uma classe MFC. O segundo cria uma classe CLR do Windows Forms.

## <a name="add-class-dialog-box"></a>Caixa de diálogo Adicionar Classe

A caixa de diálogo **Adicionar Classe** contém modelos que permitem:

- Abrir um assistente de código correspondente, se houver um disponível. Para obter mais informações, confira [Adicionar funcionalidade com assistentes de código](../ide/adding-functionality-with-code-wizards-cpp.md).

   \- ou -

- Criar a nova classe automaticamente adicionando o código-fonte e os arquivos apropriados ao projeto.

Acesse a caixa de diálogo **Adicionar Classe** no menu **Projeto**, **Gerenciador de Soluções** ou em [Modo de Exibição de Classe](/visualstudio/ide/viewing-the-structure-of-code).

> [!NOTE]
> Quando você tentar adicionar uma classe que não é adequada ao projeto atual, você receberá uma mensagem de erro. Selecione **OK** para retornar à caixa de diálogo **Adicionar Classe**.

### <a name="add-class-templates"></a>Modelos de Adicionar Classe

Há quatro categorias de modelos **Adicionar Classe**: .NET, ATL, MFC e Genérico. Quando você selecionar um modelo no painel **Modelos**, o texto que descreve a seleção será exibido nos painéis **Categorias** e **Modelos**.

#### <a name="net"></a>.NET

|Modelo|Wizard|
|--------------|------------|
|Serviço Web ASP.NET|Não disponível|
|Classe do Componente (.NET)|Não disponível|
|Classe do Instalador (.NET)|Não disponível|
|Controle de Usuário (.NET)|Não disponível|
|Windows Form (.NET)|Não disponível|

#### <a name="atl"></a>ATL

|Modelo|Wizard|
|--------------|------------|
|Adicionar Suporte para ATL ao MFC|Não disponível|
|Controle da ATL|[Assistente de controle da ATL](../atl/reference/atl-control-wizard.md)|
|Caixa de Diálogo da ATL|[Assistente de caixa de diálogo da ATL](../atl/reference/atl-dialog-wizard.md)|
|Objeto ATL Simples|[Assistente de objeto simples da ATL](../atl/reference/atl-simple-object-wizard.md)|
|Provedor de Eventos WMI|Assistente do provedor de eventos WMI|
|Provedor de Instâncias da WMI|Assistente do provedor de instâncias da WMI|

#### <a name="mfc"></a>MFC

|Modelo|Wizard|
|--------------|------------|
|MFC Class|[Assistente para adicionar classe do MFC](../mfc/reference/mfc-add-class-wizard.md)|

#### <a name="generic-classes"></a>Classes genéricas

|Modelo|Wizard|
|--------------|------------|
|Classe C++ Genérica|[Assistente da Classe C++ Genérica](../ide/generic-cpp-class-wizard.md)|
