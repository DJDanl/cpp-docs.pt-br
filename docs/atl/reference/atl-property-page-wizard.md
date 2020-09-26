---
title: Assistente de página de propriedades da ATL
ms.date: 05/09/2019
f1_keywords:
- vc.codewiz.class.atl.ppg.overview
helpviewer_keywords:
- ATL projects, adding property pages
- ATL Property Page Wizard
ms.assetid: 6113e325-facd-4f68-b491-144d75209922
ms.openlocfilehash: c25e3b9194cf0c7dc7c152edb50be01def2d2d9b
ms.sourcegitcommit: d9c94dcabd94537e304be0261b3263c2071b437b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/25/2020
ms.locfileid: "91352721"
---
# <a name="atl-property-page-wizard"></a>Assistente de página de propriedades da ATL

::: moniker range="vs-2019"

Esse assistente não está disponível no Visual Studio 2019 e versões posteriores.

::: moniker-end

::: moniker range="<=vs-2017"

Este assistente [adiciona uma página de propriedades a um projeto da ATL](../../atl/reference/adding-an-atl-property-page.md) ou a um projeto do MFC compatível com ATL. Uma página de propriedades da ATL fornece uma interface de usuário para definir as propriedades (ou chamar os métodos) de um ou mais objetos do COM.

## <a name="remarks"></a>Comentários

A partir do Visual Studio 2008, o script de registro produzido por esse assistente registra seus componentes COM em **HKEY_CURRENT_USER**, e não em **HKEY_LOCAL_MACHINE**. Para modificar esse comportamento, defina a opção **Registrar componente para todos os usuários** do Assistente da ATL.

## <a name="names"></a>Nomes

Especifique os nomes para o objeto, a interface e as classes a ser adicionados ao seu projeto. Com a exceção de **Nome curto**, todas as outras caixas podem ser editadas independentemente. Se você alterar o texto para **Nome curto**, a alteração será refletida nos nomes de todas as outras caixas dessa página. Se você alterar o nome **Coclass** na seção COM, a alteração será refletida nas caixas **Tipo** e **ProgID**. Esse comportamento de nomenclatura foi projetado para tornar todos os nomes facilmente identificáveis à medida que você desenvolve sua página de propriedades.

> [!NOTE]
> **Coclass** é editável apenas em projetos não atribuídos. Se o seu projeto foi atribuído, você não pode editar **Coclass**.

### <a name="c"></a>C++

Fornece informações para a classe C++ criada para implementar o objeto.

|Termo|Definição|
|-|-|
|**Nome curto**|Define o nome abreviado do objeto. O nome que você fornece determina a classe e os nomes **Coclass**, os nomes de arquivo (**.cpp** e **.h**), o nome de **Tipo** e de **ProgID**, a menos que você altere esses campos individualmente.|
|**Arquivo .h**|Define o nome do arquivo de cabeçalho para a nova classe do objeto. Por padrão, esse nome é baseado no nome que você fornece em **Nome curto**. Clique no botão de reticências para salvar o nome de arquivo no local de sua escolha, ou para acrescentar a declaração de classe a um arquivo existente. Se você selecionar um arquivo existente, o assistente não o salvará no local selecionado até que você clique em **Concluir**.<br /><br /> O assistente não substitui um arquivo. Se você selecionar o nome de um arquivo existente, quando clicar em **Concluir**, o assistente solicitará que você indique se a declaração de classe deve ser acrescentada ao conteúdo do arquivo. Clique em **Sim** para acrescentar o arquivo; clique em **Não** para retornar ao assistente e especificar outro nome de arquivo.|
|**Classe**|Define o nome da classe derivada que implementa o objeto. Esse nome é baseado no nome fornecido em **Nome curto**, precedido por "C", o prefixo típico de um nome de classe.|
|**Arquivo .cpp**|Define o nome do arquivo de implementação para a nova classe do objeto. Por padrão, esse nome é baseado no nome que você fornece em **Nome curto**. Clique no botão de reticências para salvar o nome de arquivo no local de sua escolha. O arquivo não é salvo no local selecionado até que você clique em **Concluir** no assistente.<br /><br /> O assistente não substitui um arquivo. Se você selecionar o nome de um arquivo existente, quando clicar em **Concluir**, o assistente solicitará que você indique se a implementação de classe deve ser acrescentada ao conteúdo do arquivo. Clique em **Sim** para acrescentar o arquivo; clique em **Não** para retornar ao assistente e especificar outro nome de arquivo.|
|**Atribuído**|Indica se o objeto usa atributos. Se você está adicionando um objeto a um projeto atribuído da ATL, essa opção é selecionada e não fica disponível para alteração, ou seja, você pode adicionar somente objetos atribuídos a um projeto criado com o suporte a atributos.<br /><br /> Você pode adicionar um objeto atribuído somente a um projeto da ATL que usa atributos. Se você selecionar essa opção para um projeto ATL que não seja compatível com o atributo, o assistente solicitará que você especifique se deseja adicionar suporte a atributo ao projeto.<br /><br /> Por padrão, qualquer objeto que você adiciona após definir essa opção é designado como atribuído (a caixa de seleção fica marcada). Você pode desmarcar essa caixa para adicionar um objeto que não usa atributos.<br /><br /> Consulte [configurações do aplicativo, assistente de projeto ATL](../../atl/reference/application-settings-atl-project-wizard.md) e [mecânica básica de atributos](../../windows/attributes/cpp-attributes-com-net.md#basic-mechanics-of-attributes) para obter mais informações.|

### <a name="com"></a>COM

Fornece informações sobre a funcionalidade COM do objeto.

- **Coclass**

   Define o nome da classe do componente que contém uma lista de interfaces compatíveis com o objeto.

   > [!NOTE]
   > Se você criar seu projeto usando atributos, ou se indicar nesta página do assistente que a página de propriedades usa atributos, não será possível alterar essa opção, pois a ATL não inclui o atributo `coclass`.

- **Tipo**

   Define a descrição do objeto que aparecerá no registro

- **ProgID**

   Define o nome que os contêineres podem usar em vez do CLSID do objeto.

::: moniker-end

## <a name="see-also"></a>Confira também

[Opções, Assistente de Página de Propriedades da ATL](../../atl/reference/options-atl-property-page-wizard.md)<br/>
[Cadeias de caracteres, Assistente de Página de Propriedades da ATL](../../atl/reference/strings-atl-property-page-wizard.md)<br/>
[Exemplo: implementando uma página de propriedades](../../atl/example-implementing-a-property-page.md)
