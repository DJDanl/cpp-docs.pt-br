---
title: Assistente de controle da ATL
ms.date: 11/04/2016
f1_keywords:
- vc.codewiz.class.atl.control.overview
helpviewer_keywords:
- ATL projects, adding controls
- controls [ATL], adding to projects
- ATL Control Wizard
ms.assetid: 991f8e72-ffbc-4382-a4ce-e255acfba5b6
ms.openlocfilehash: a10c5c358901122dda37b395c1f0fa5cdc30ce30
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81321704"
---
# <a name="atl-control-wizard"></a>Assistente de controle da ATL

Insere em um projeto ATL (ou um projeto MFC com suporte atl) um controle ATL. Você pode usar este assistente para inserir um dos três tipos de controles:

- Controle padrão

- Controle composto

- Controle DHTML

Além disso, você pode especificar um controle mínimo, removendo as interfaces da lista [Interfaces,](../../atl/reference/interfaces-atl-control-wizard.md) que são fornecidas como padrão para os controles abrirem na maioria dos contêineres. Você pode definir as interfaces suportadas para o controle na página **Interfaces** do assistente.

## <a name="remarks"></a>Comentários

O script de registro produzido por este assistente registrará seus componentes COM sob HKEY_CURRENT_USER em vez de HKEY_LOCAL_MACHINE. Para modificar esse comportamento, defina a opção **Registrar componente para todos os usuários** do Assistente da ATL.

## <a name="names"></a>Names

Especifique os nomes para o objeto, a interface e as classes a ser adicionados ao seu projeto. Com exceção **do nome Curto,** todas as outras caixas podem ser alteradas independentemente. Se você alterar o texto para **Nome curto**, a alteração será refletida nos nomes de todas as outras caixas dessa página. Se você alterar o nome **Coclass** na seção COM, a alteração será refletida na caixa **Tipo,** mas o nome **da interface** e **progID** não mudarão. Esse comportamento de nomenclatura foi criado para tornar todos os nomes facilmente identificáveis à medida que você desenvolve seu controle.

> [!NOTE]
> **Coclass** é editável em apenas controles não atribuídos. Se o seu projeto foi atribuído, você não pode editar **Coclass**.

### <a name="c"></a>C++

Fornece informações para a classe C++ criada para implementar o objeto.

- **Nome curto**

   Define o nome abreviado do objeto. O nome que você fornece determina os nomes de classe e **coclasse,** o arquivo (. CPP e . H) nomes, o nome da interface e os nomes **de tipo,** a menos que você altere esses campos individualmente.

- **Classe**

   Define o nome da classe derivada que implementa o objeto. Esse nome é baseado no nome fornecido em **Nome curto**, precedido por "C", o prefixo típico de um nome de classe.

- **Arquivo .h**

   Define o nome do arquivo de cabeçalho para a nova classe do objeto. Por padrão, esse nome é baseado no nome que você fornece em **Nome curto**. Clique no botão de reticências para salvar o nome de arquivo no local de sua escolha, ou para acrescentar a declaração de classe a um arquivo existente. Se você selecionar um arquivo existente, o assistente não irá salvá-lo no local selecionado até clicar em **Concluir**.

   O assistente não substitui um arquivo. Se você selecionar o nome de um arquivo existente, quando clicar em **Concluir**, o assistente solicitará que você indique se a declaração de classe deve ser acrescentada ao conteúdo do arquivo. Clique em **Sim** para acrescentar o arquivo; clique em **Não** para retornar ao assistente e especificar outro nome de arquivo.

- **Arquivo .cpp**

   Define o nome do arquivo de implementação para a nova classe do objeto. Por padrão, esse nome é baseado no nome que você fornece em **Nome curto**. Clique no botão de reticências para salvar o nome de arquivo no local de sua escolha. O arquivo não é salvo no local selecionado até que você clique em **Concluir** no assistente.

   O assistente não substitui um arquivo. Se você selecionar o nome de um arquivo existente, quando clicar em **Concluir**, o assistente solicitará que você indique se a implementação de classe deve ser acrescentada ao conteúdo do arquivo. Clique em **Sim** para acrescentar o arquivo; clique em **Não** para retornar ao assistente e especificar outro nome de arquivo.

- **Atribuído**

   Indica se o objeto usa atributos. Se você estiver adicionando um objeto a um projeto ATL atribuído, essa opção será selecionada e não estará disponível para alteração. Ou seja, você pode adicionar somente objetos atribuídos a um projeto criado com suporte a atributos.

   Você pode adicionar um objeto atribuído somente a um projeto da ATL que usa atributos. Se você selecionar essa opção para um projeto ATL que não seja compatível com o atributo, o assistente solicitará que você especifique se deseja adicionar suporte a atributo ao projeto.

   Por padrão, qualquer objeto que você adiciona após definir essa opção é designado como atribuído (a caixa de seleção fica marcada). Você pode desmarcar essa caixa para adicionar um objeto que não usa atributos.

   Confira mais informações em [Configurações do aplicativo, Assistente de Projeto ATL](../../atl/reference/application-settings-atl-project-wizard.md) e [Mecânica básica de atributos](../../windows/basic-mechanics-of-attributes.md).

### <a name="com"></a>COM

Fornece informações sobre a funcionalidade COM do objeto.

- **Coclass**

   Define o nome da classe do componente que contém uma lista de interfaces compatíveis com o objeto.

   > [!NOTE]
   > Se você criar seu projeto usando atributos ou se indicar nesta página do assistente que o controle usa atributos, não poderá alterar essa opção porque a ATL não inclui o atributo **coclasse.**

- **Interface**

   Define o nome da interface para o objeto. Por padrão, um nome de interface é preparado com "I".

- **Tipo**

   Define a descrição do objeto que aparecerá no registro

- **ProgID**

   Define o nome que os contêineres podem usar em vez do CLSID do objeto. Este campo não é preenchido automaticamente. Se você não preencher manualmente este campo, o controle pode não estar disponível para outras ferramentas. Por exemplo, os controles ActiveX `ProgID` gerados sem um não estão disponíveis na caixa de diálogo **Inserir controle ActiveX.** Para obter mais informações sobre a caixa de diálogo, consulte [Inserir caixa de diálogo de controle ActiveX](../../windows/insert-activex-control-dialog-box.md).

## <a name="see-also"></a>Confira também

[Controle da ATL](../../atl/reference/adding-an-atl-control.md)<br/>
[Adicionando funcionalidade ao controle composto](../../atl/adding-functionality-to-the-composite-control.md)<br/>
[Fundamentos dos Objetos ATL COM](../../atl/fundamentals-of-atl-com-objects.md)
