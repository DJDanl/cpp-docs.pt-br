---
title: Assistente de objeto simples da ATL
ms.date: 11/04/2016
f1_keywords:
- vc.codewiz.class.atl.simple.overview
helpviewer_keywords:
- ATL projects, adding objects
- ATL Simple Object Wizard
ms.assetid: f7f85741-9aad-4543-a917-a29b996364da
ms.openlocfilehash: bd4c9eede16ed086020dd8f12d90876e50a0a341
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81319208"
---
# <a name="atl-simple-object-wizard"></a>Assistente de objeto simples da ATL

Este assistente insere no projeto um objeto COM mínimo. Use esta página do assistente para especificar os nomes que identificam a classe C++ e arquivos para o seu objeto e sua funcionalidade COM.

Use a página [Opções](../../atl/reference/options-atl-simple-object-wizard.md) deste assistente para especificar o modelo de rosca do objeto, seu suporte à agregação e se ele suporta interfaces duplas e automação. Você também pode indicar suporte para a interface de informações de erro, pontos de conexão, suporte ao Internet Explorer e empacotamento com threading livre.

## <a name="remarks"></a>Comentários

A partir do Visual Studio 2008, o script de registro produzido por esse assistente registra seus componentes COM em **HKEY_CURRENT_USER**, e não em **HKEY_LOCAL_MACHINE**. Para modificar esse comportamento, defina a opção **Registrar componente para todos os usuários** do Assistente da ATL.

## <a name="names"></a>Names

Especifique os nomes para o objeto, a interface e as classes a ser adicionados ao seu projeto. Com a exceção de **Nome curto**, todas as demais caixas podem ser editadas de forma independente. Se você alterar o texto para **Nome curto**, a alteração será refletida nos nomes de todas as outras caixas dessa página. Se você alterar o nome **Coclass** na seção COM, a alteração será refletida nas caixas **Tipo** e **ProgID**, mas o nome da **Interface** não mudará. Esse comportamento de nomenclatura foi criado para tornar todos os nomes facilmente identificáveis à medida que você desenvolve seu controle.

> [!NOTE]
> **Coclass** é editável apenas em projetos não atribuídos. Se o seu projeto foi atribuído, você não pode editar **Coclass**.

## <a name="c"></a>C++

Fornece informações para a classe C++ criada para o objeto.

- **Nome curto**

   Define o nome abreviado do objeto. O nome que você fornece determina os nomes `Class` e `Coclass`, os nomes do **arquivo .cpp** e do **arquivo .h**, o nome da **Interface**, os nomes de **Tipo** e o **ProgID**, a menos que você altere esses campos individualmente.

- **Arquivo .h**

   Define o nome do arquivo de cabeçalho para a nova classe do objeto. Por padrão, esse nome é baseado no nome que você fornece em **Nome curto**. Clique no botão de reticências para salvar o nome de arquivo no local de sua escolha, ou para acrescentar a declaração de classe a um arquivo existente. Se você selecionar um arquivo existente, o assistente não o salvará no local selecionado até que você clique em **Concluir**.

   O assistente não substitui um arquivo. Se você selecionar o nome de um arquivo existente, quando clicar em **Concluir**, o assistente solicitará que você indique se a declaração de classe deve ser acrescentada ao conteúdo do arquivo. Clique em **Sim** para acrescentar o arquivo; clique em **Não** para retornar ao assistente e especificar outro nome de arquivo.

- **Classe**

   Define o nome da classe a ser criada. Esse nome é baseado no nome fornecido em **Nome curto**, precedido por "C", o prefixo típico de um nome de classe.

- **Arquivo .cpp**

   Define o nome do arquivo de implementação para a nova classe do objeto. Por padrão, esse nome é baseado no nome que você fornece em **Nome curto**. Clique no botão de reticências para salvar o nome de arquivo no local de sua escolha. O arquivo não é salvo no local selecionado até que você clique em **Concluir** no assistente.

   O assistente não substitui um arquivo. Se você selecionar o nome de um arquivo existente, quando clicar em **Concluir**, o assistente solicitará que você indique se a implementação de classe deve ser acrescentada ao conteúdo do arquivo. Clique em **Sim** para acrescentar o arquivo; clique em **Não** para retornar ao assistente e especificar outro nome de arquivo.

- **Atribuído**

   Indica se o objeto usa atributos. Se você estiver adicionando um objeto a um projeto ATL atribuído, essa opção será selecionada e não estará disponível para alteração. Ou seja, você pode adicionar somente objetos atribuídos a um projeto criado com suporte a atributos.

   Você pode adicionar um objeto atribuído somente a um projeto da ATL que usa atributos. Se você selecionar essa opção para um projeto ATL que não seja compatível com o atributo, o assistente solicitará que você especifique se deseja adicionar suporte a atributo ao projeto.

   Por padrão, qualquer objeto que você adiciona após definir essa opção é designado como atribuído (a caixa de seleção fica marcada). Você pode desmarcar essa caixa para adicionar um objeto que não usa atributos.

   Confira mais informações em [Configurações do aplicativo, Assistente de Projeto ATL](../../atl/reference/application-settings-atl-project-wizard.md) e [Mecânica básica de atributos](../../windows/basic-mechanics-of-attributes.md).

## <a name="com"></a>COM

Fornece informações sobre a funcionalidade COM do objeto.

- **Coclass**

   Define o nome da classe do componente que contém uma lista de interfaces compatíveis com o objeto.

   > [!NOTE]
   > Se você criar seu projeto usando atributos ou se indicar nesta página do assistente que o objeto `coclass` usa atributos, não poderá alterar essa opção porque a ATL não inclui o atributo.

- **Tipo**

   Define a descrição do objeto que aparecerá no registro

- **Interface**

   Define a interface que você cria para o seu objeto. Essa interface contém seus métodos personalizados.

- **ProgID**

   Define o nome que os contêineres podem usar em vez do CLSID do objeto.

## <a name="see-also"></a>Confira também

[Objeto ATL Simples](../../atl/reference/adding-an-atl-simple-object.md)
