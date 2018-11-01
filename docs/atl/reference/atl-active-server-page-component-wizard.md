---
title: Assistente de página componente Active Server ATL
ms.date: 11/04/2016
f1_keywords:
- vc.codewiz.class.atl.asp.overview
helpviewer_keywords:
- ASP components, creating in ATL
- ATL Active Server Page Component Wizard
ms.assetid: 5a5cb904-dbbf-44ea-ad3d-2ddd14c1d3c5
ms.openlocfilehash: 80d7eefaa4b12d5aab8970f4b3c81fc644226e07
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50510858"
---
# <a name="atl-active-server-page-component-wizard"></a>Assistente de página componente Active Server ATL

Este assistente insere o projeto de um componente Active Server Pages (ASP). O Microsoft Internet Information Services (IIS) usa componentes ASP como parte da sua arquitetura de desenvolvimento aprimorada página da Web.

Usando esse assistente, você pode especificar que o componente do modelo de threading e seu suporte de agregação. Você também pode indicar o suporte para a interface de informações de erro, pontos de conexão e empacotamento de thread livre.

> [!WARNING]
> No Visual Studio 2017 versão 15.9, esse assistente de código foi preterido e será removido em uma versão futura do Visual Studio. Este assistente é raramente usado. O suporte geral para ATL e MFC não é afetado pela remoção do assistente. Se você quiser compartilhar seus comentários sobre essa alteração, participe [desta pesquisa](https://www.surveymonkey.com/r/QDWKKCN). Seus comentários são importantes para nós.

## <a name="remarks"></a>Comentários

A partir do Visual Studio 2008, o script de registro produzido por este assistente registrará seus componentes COM sob **HKEY_CURRENT_USER** em vez de **HKEY_LOCAL_MACHINE**. Para modificar esse comportamento, defina as **registrar o componente para todos os usuários** opção do Assistente da ATL.

## <a name="names"></a>Nomes

Especifique os nomes para o objeto, a interface e a classes a serem adicionadas ao seu projeto. Exceto para **Short name**, todas as outras caixas que podem ser editadas independentemente dos outros. Se você alterar o texto para **Short name**, a alteração é refletida nos nomes de todas as outras caixas nesta página.

Se você alterar o **Coclass** na seção de COM, a alteração é refletido na **tipo** e **ProgID** caixas, mas o **Interface** nome não é alterado. Esse comportamento de nomenclatura é projetado para tornar todos os nomes de fácil identificação para você à medida que desenvolve seu controle.

### <a name="c"></a>C++

Fornece informações para a classe C++ criada para o objeto.

- **Nome curto**

   Define o nome de raiz para o objeto. O nome que você forneceu determina o `Class` e **Coclass** nomes, o **arquivo. cpp** e **arquivo. h** nomes, o **Interface**nome, o **tipo de** nomes e o **ProgID**, a menos que você altere esses campos individualmente.

- **Arquivo .h**

   Define o nome do arquivo de cabeçalho para a nova classe do objeto. Por padrão, esse nome é baseado no nome que você fornecer em **Short name**. Clique no botão de reticências para salvar o nome de arquivo no local de sua escolha, ou para acrescentar a declaração de classe a um arquivo existente. Se você selecionar um arquivo existente, o assistente não salvará no local selecionado até que você clique **concluir** no assistente.

   O assistente não substitui um arquivo. Se você selecionar o nome de um arquivo existente, quando clicar em **Concluir**, o assistente solicitará que você indique se a declaração de classe deve ser acrescentada ao conteúdo do arquivo. Clique em **Sim** para acrescentar o arquivo; clique em **Não** para retornar ao assistente e especificar outro nome de arquivo.

- **Class**

   Define o nome da classe a ser criado. Esse nome é baseado no nome que você fornecer em **Short name**, precedidos pela 'c', o prefixo típico para um nome de classe.

- **Arquivo .cpp**

   Define o nome do arquivo de implementação para a nova classe do objeto. Por padrão, esse nome é baseado no nome que você fornecer em **Short name**. Clique no botão de reticências para salvar o nome de arquivo no local de sua escolha. O arquivo não é salvo no local selecionado até que você clique em **Concluir** no assistente.

   O assistente não substitui um arquivo. Se você selecionar o nome de um arquivo existente, quando clicar em **Concluir**, o assistente solicitará que você indique se a implementação de classe deve ser acrescentada ao conteúdo do arquivo. Clique em **Sim** para acrescentar o arquivo; clique em **Não** para retornar ao assistente e especificar outro nome de arquivo.

- **Atribuído**

   Indica se o objeto usa atributos. Se você estiver adicionando um objeto para um projeto ATL atribuído, essa opção é selecionada e não está disponível para alterar. Ou seja, você pode adicionar apenas os objetos atribuídos a um projeto criado com o suporte do atributo.

   Se você selecionar essa opção para um projeto ATL que não tem atributo dão suporte, o assistente solicita que você especifique se deseja adicionar suporte de atributo para o projeto.

   Por padrão para projetos nonattributed, quaisquer objetos que você adiciona depois de definir essa opção são designados como atribuído (a caixa de seleção está marcada). Você pode desmarcar essa caixa para adicionar um objeto que não usa atributos.

   Ver [configurações de aplicativo, o ATL Project Wizard](../../atl/reference/application-settings-atl-project-wizard.md) e [mecânica básica de atributos](../../windows/basic-mechanics-of-attributes.md) para obter mais informações.

### <a name="com"></a>COM

Fornece informações sobre a funcionalidade de COM para o objeto.

- **Coclass**

   Define o nome da classe de componente que contém uma lista de interfaces com suporte do objeto. Se esse objeto ou seu projeto usa atributos, você não pode alterar essa opção porque ATL não inclui o **coclass** atributo.

- **Tipo**

   Define a descrição do objeto que será exibido no registro para coclass.

- **Interface**

   Define a interface que você cria para seu objeto. Essa interface contém seus métodos personalizados.

- **ProgID**

   Define o nome que contêineres podem usar em vez do CLSID do objeto.

## <a name="see-also"></a>Consulte também

[Componente de página de servidor ativo do ATL](../../atl/reference/adding-an-atl-active-server-page-component.md)
