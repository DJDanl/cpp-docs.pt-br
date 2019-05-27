---
title: Assistente de Componente Active Server Page da ATL
ms.date: 05/09/2019
helpviewer_keywords:
- ASP components, creating in ATL
ms.assetid: 5a5cb904-dbbf-44ea-ad3d-2ddd14c1d3c5
ms.openlocfilehash: a78beeab663ef1b467cdec32ca51132e8134a9b2
ms.sourcegitcommit: fc1de63a39f7fcbfe2234e3f372b5e1c6a286087
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/15/2019
ms.locfileid: "65707045"
---
# <a name="atl-active-server-page-component-wizard"></a>Assistente de Componente Active Server Page da ATL

::: moniker range="vs-2019"

Esse assistente não está disponível no Visual Studio 2019 e versões posteriores.

::: moniker-end

::: moniker range="<=vs-2017"

Esse assistente insere no projeto um componente Active Server Pages (ASP). Os Serviços de Informações da Internet (IIS) da Microsoft usam componentes ASP como parte da arquitetura aprimorada de desenvolvimento de páginas da Web.

Usando esse assistente, você pode especificar o modelo de threading do componente e o suporte de agregação dele. Também pode indicar o suporte para a interface de informações de erro, pontos de conexão e marshaling sem thread.

## <a name="remarks"></a>Comentários

Começando com o Visual Studio 2008, o script de registro produzido por esse assistente registra os componentes COM dele em **HKEY_CURRENT_USER** em vez de em **HKEY_LOCAL_MACHINE**. Para modificar esse comportamento, defina a opção **Registrar componente para todos os usuários** do Assistente da ATL.

## <a name="names"></a>Nomes

Especifique os nomes para o objeto, a interface e as classes a ser adicionados ao seu projeto. Com a exceção de **Nome curto**, todas as demais caixas podem ser editadas de forma independente. Se você alterar o texto para **Nome curto**, a alteração será refletida nos nomes de todas as outras caixas dessa página.

Se você alterar o nome **Coclass** na seção COM, a alteração será refletida nas caixas **Tipo** e **ProgID**, mas o nome da **Interface** não mudará. Esse comportamento de nomenclatura foi criado para tornar todos os nomes facilmente identificáveis à medida que você desenvolve seu controle.

### <a name="c"></a>C++

Fornece informações para a classe C++ criada para o objeto.

- **Nome curto**

   Define o nome raiz do objeto. O nome que você fornece determina os nomes de `Class` e de **Coclass**, os nomes do **arquivo .cpp** e do **arquivo .h**, o nome da **Interface**, os nomes de **Tipo** e o **ProgID**, a menos que você altere esses campos individualmente.

- **Arquivo .h**

   Define o nome do arquivo de cabeçalho para a nova classe do objeto. Por padrão, esse nome é baseado no nome que você fornece em **Nome curto**. Clique no botão de reticências para salvar o nome de arquivo no local de sua escolha, ou para acrescentar a declaração de classe a um arquivo existente. Se você selecionar um arquivo existente, o assistente não o salvará no local selecionado até que você clique em **Concluir**.

   O assistente não substitui um arquivo. Se você selecionar o nome de um arquivo existente, quando clicar em **Concluir**, o assistente solicitará que você indique se a declaração de classe deve ser acrescentada ao conteúdo do arquivo. Clique em **Sim** para acrescentar o arquivo; clique em **Não** para retornar ao assistente e especificar outro nome de arquivo.

- **Class**

   Define o nome da classe a ser criada. Esse nome é baseado no nome fornecido em **Nome curto**, precedido por "C", o prefixo típico de um nome de classe.

- **Arquivo .cpp**

   Define o nome do arquivo de implementação para a nova classe do objeto. Por padrão, esse nome é baseado no nome que você fornece em **Nome curto**. Clique no botão de reticências para salvar o nome de arquivo no local de sua escolha. O arquivo não é salvo no local selecionado até que você clique em **Concluir** no assistente.

   O assistente não substitui um arquivo. Se você selecionar o nome de um arquivo existente, quando clicar em **Concluir**, o assistente solicitará que você indique se a implementação de classe deve ser acrescentada ao conteúdo do arquivo. Clique em **Sim** para acrescentar o arquivo; clique em **Não** para retornar ao assistente e especificar outro nome de arquivo.

- **Atribuído**

   Indica se o objeto usa atributos. Se você estiver adicionando um objeto a um projeto ATL atribuído, essa opção será selecionada e não estará disponível para alteração. Ou seja, você pode adicionar somente objetos atribuídos a um projeto criado com suporte a atributos.

   Se você selecionar essa opção para um projeto ATL que não tenha suporte a atributo, o assistente solicitará que você especifique se deseja adicionar suporte a atributo ao projeto.

   Por padrão, para projetos não atribuídos, qualquer objeto que você adicionar depois de definir essa opção será designado como atribuído (a caixa de seleção estará marcada). Você pode desmarcar essa caixa para adicionar um objeto que não usa atributos.

   Confira mais informações em [Configurações do aplicativo, Assistente de Projeto ATL](../../atl/reference/application-settings-atl-project-wizard.md) e [Mecânica básica de atributos](../../windows/basic-mechanics-of-attributes.md).

### <a name="com"></a>COM

Fornece informações sobre a funcionalidade COM do objeto.

- **Coclass**

   Define o nome da classe do componente que contém uma lista de interfaces compatíveis com o objeto. Se o seu projeto ou esse objeto usar atributos, você não poderá alterar essa opção porque a ATL não inclui o atributo **coclass**.

- **Tipo**

   Define a descrição do objeto que aparecerá no registro do coclass.

- **Interface**

   Define a interface que você cria para o seu objeto. Essa interface contém seus métodos personalizados.

- **ProgID**

   Define o nome que os contêineres podem usar em vez do CLSID do objeto.

::: moniker-end

## <a name="see-also"></a>Consulte também

[Componente Active Server Page da ATL](../../atl/reference/adding-an-atl-active-server-page-component.md)
