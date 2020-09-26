---
title: Assistente de componente de COM+ 1.0 da ATL
ms.date: 05/08/2019
helpviewer_keywords:
- ATL projects, adding components
ms.assetid: 11670681-8671-4122-96a4-2e52f8dadce0
ms.openlocfilehash: 6b1fea925c5f6d657e398933b5fb26cf09c28055
ms.sourcegitcommit: d9c94dcabd94537e304be0261b3263c2071b437b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/25/2020
ms.locfileid: "91353149"
---
# <a name="atl-com-10-component-wizard"></a>Assistente de componente de COM+ 1.0 da ATL

::: moniker range="vs-2019"

Esse assistente não está disponível no Visual Studio 2019 e versões posteriores.

::: moniker-end

::: moniker range="<=vs-2017"

Use esse assistente para adicionar um objeto ao seu projeto que seja compatível com serviços COM+ 1.0, incluindo transações.

Você pode especificar se o objeto é compatível com interfaces duplas e à automação. Você também pode indicar suporte para a interface de informações de erro, controle de objeto avançado, transações e enfileiramento de mensagens assíncronas.

## <a name="remarks"></a>Comentários

A partir do Visual Studio 2008, o script de registro produzido por esse assistente registra seus componentes COM em **HKEY_CURRENT_USER**, e não em **HKEY_LOCAL_MACHINE**. Para modificar esse comportamento, defina a opção **Registrar componente para todos os usuários** do Assistente da ATL.

## <a name="names"></a>Nomes

Especifique os nomes para o objeto, a interface e as classes a ser adicionados ao seu projeto. Com exceção de **Nome curto**, todas as demais caixas podem ser editadas de forma independente. Se você alterar o texto para **Nome curto**, a alteração será refletida nos nomes de todas as outras caixas dessa página. Se você alterar o nome **Coclass** na seção COM, a alteração será refletida nas caixas **Tipo** e **ProgID**, mas o nome da **Interface** não mudará. Esse comportamento de nomenclatura foi criado para tornar todos os nomes facilmente identificáveis à medida que você desenvolve seu controle.

- **Nome curto**

   Define o nome abreviado do objeto. O nome que você fornece determina os nomes `Class` e `Coclass`, os nomes do **arquivo .cpp** e do **arquivo .h**, o nome da **Interface**, os nomes de **Tipo** e o **ProgID**, a menos que você altere esses campos individualmente.

- **Arquivo .h**

   Define o nome do arquivo de cabeçalho para a nova classe do objeto. Por padrão, esse nome é baseado no nome que você fornece em **Nome curto**. Clique no botão de reticências para salvar o nome de arquivo no local de sua escolha, ou para acrescentar a declaração de classe a um arquivo existente. Se você escolher um arquivo existente, o assistente não o salvará no local selecionado até que você clique em **Concluir** no assistente.

   O assistente não substitui um arquivo. Se você selecionar o nome de um arquivo existente, quando clicar em **Concluir**, o assistente solicitará que você indique se a declaração de classe deve ser acrescentada ao conteúdo do arquivo. Clique em **Sim** para acrescentar o arquivo; clique em **Não** para retornar ao assistente e especificar outro nome de arquivo.

- **Classe**

   Define o nome da classe a ser criada. Esse nome é baseado no nome fornecido em **Nome curto**, precedido por "C", o prefixo típico de um nome de classe.

- **Arquivo .cpp**

   Define o nome do arquivo de implementação para a nova classe do objeto. Por padrão, esse nome se baseia no nome que você fornece em **Nome curto**. Clique no botão de reticências para salvar o nome de arquivo no local de sua escolha. O arquivo não é salvo no local selecionado até que você clique em **Concluir** no assistente.

   O assistente não substitui um arquivo. Se você selecionar o nome de um arquivo existente, quando clicar em **Concluir**, o assistente solicitará que você indique se a implementação de classe deve ser acrescentada ao conteúdo do arquivo. Clique em **Sim** para acrescentar o arquivo; clique em **Não** para retornar ao assistente e especificar outro nome de arquivo.

- **Atribuído**

   Indica se o objeto usa atributos. Se você estiver adicionando um objeto a um projeto ATL atribuído, essa opção será selecionada e não estará disponível para alteração. Ou seja, você pode adicionar somente objetos atribuídos a um projeto criado com suporte a atributos.

   Se você selecionar essa opção para um projeto ATL que não seja compatível com o atributo, o assistente solicitará que você especifique se deseja adicionar suporte a atributo ao projeto.

   Qualquer objeto que você adiciona após definir essa opção será designado como atribuído por padrão (a caixa de seleção fica marcada). Você pode desmarcar essa caixa para adicionar um objeto que não usa atributos.

   Consulte [configurações do aplicativo, assistente de projeto ATL](../../atl/reference/application-settings-atl-project-wizard.md) e [mecânica básica de atributos](../../windows/attributes/cpp-attributes-com-net.md#basic-mechanics-of-attributes) para obter mais informações.

### <a name="com"></a>COM

Fornece informações sobre a funcionalidade COM do objeto.

- **Coclass**

   Define o nome da classe do componente que contém uma lista de interfaces compatíveis com o objeto.

> [!NOTE]
> Se você criar seu projeto usando atributos, ou se indicar nesta página do assistente que o componente COM+ 1.0 usa atributos, não será possível alterar essa opção, pois a ATL não inclui o atributo `coclass`.

- **Tipo**

   Define a descrição do objeto que aparecerá no registro

- **Interface**

   Define a interface que você cria para o seu objeto. Essa interface contém seus métodos personalizados.

- **ProgID**

   Define o nome que os contêineres podem usar em vez do CLSID do objeto.

::: moniker-end

## <a name="see-also"></a>Confira também

[Componente COM+ 1.0 da ATL](../../atl/reference/adding-an-atl-com-plus-1-0-component.md)
