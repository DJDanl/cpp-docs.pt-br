---
title: Assistente para ATL COM+ 1.0 do componente | Microsoft Docs
ms.custom: ''
ms.date: 10/03/2018
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- vc.codewiz.class.atl.mts.overview
dev_langs:
- C++
helpviewer_keywords:
- ATL projects, adding components
- ATL COM+ 1.0 Component Wizard
ms.assetid: 11670681-8671-4122-96a4-2e52f8dadce0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 102ec4f85c8915cf6afb70f03d470cec4e9e807f
ms.sourcegitcommit: d1527eb2d50156bf923f2a32ec3af9efc7fc4304
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/03/2018
ms.locfileid: "48250400"
---
# <a name="atl-com-10-component-wizard"></a>Assistente para ATL COM+ 1.0 do componente

Use este assistente para adicionar um objeto ao seu projeto que oferece suporte aos serviços COM+ 1.0, incluindo transações.

Você pode especificar se o objeto dá suporte a interfaces duplas e automação. Você também pode indicar o suporte para a interface de informações de erro, controle de objeto avançado, transações e enfileiramento de mensagens assíncronas.

> [!WARNING]
> No Visual Studio 2017 versão 15,9 este assistente de código foi preterido e será removido em uma versão futura do Visual Studio. Este assistente é raramente usado. Suporte geral para ATL e MFC não é afetado pela remoção desse assistente. Se você quiser compartilhar seus comentários sobre essa substituição, conclua [desta pesquisa](https://www.surveymonkey.com/r/QDWKKCN). Sua opinião é importante para nós.

## <a name="remarks"></a>Comentários

A partir do Visual Studio 2008, o script de registro produzido por este assistente registrará seus componentes COM sob **HKEY_CURRENT_USER** em vez de **HKEY_LOCAL_MACHINE**. Para modificar esse comportamento, defina as **registrar o componente para todos os usuários** opção do Assistente da ATL.

## <a name="names"></a>Nomes

Especifique os nomes para o objeto, a interface e a classes a serem adicionadas ao seu projeto. Com exceção de **Short name**, todas as outras caixas que podem ser editadas independentemente dos outros. Se você alterar o texto para **Short name**, a alteração é refletida nos nomes de todas as outras caixas nesta página. Se você alterar o **Coclass** na seção de COM, a alteração é refletido na **tipo** e **ProgID** caixas, mas o **Interface** nome não é alterado. Esse comportamento de nomenclatura é projetado para tornar todos os nomes de fácil identificação para você à medida que desenvolve seu controle.

- **Nome curto**

   Define o nome abreviado do objeto. O nome que você forneceu determina o `Class` e `Coclass` nomes, o **arquivo. cpp** e **arquivo. h** nomes, o **Interface** nome, a **Tipo de** nomes e o **ProgID**, a menos que você altere esses campos individualmente.

- **Arquivo .h**

   Define o nome do arquivo de cabeçalho para a nova classe do objeto. Por padrão, esse nome é baseado no nome que você fornecer em **Short name**. Clique no botão de reticências para salvar o nome de arquivo no local de sua escolha, ou para acrescentar a declaração de classe a um arquivo existente. Se você escolher um arquivo existente, o assistente não o salvará no local selecionado até que você clique em **Concluir** no assistente.

   O assistente não substitui um arquivo. Se você selecionar o nome de um arquivo existente, quando clicar em **Concluir**, o assistente solicitará que você indique se a declaração de classe deve ser acrescentada ao conteúdo do arquivo. Clique em **Sim** para acrescentar o arquivo; clique em **Não** para retornar ao assistente e especificar outro nome de arquivo.

- **Class**

   Define o nome da classe a ser criado. Esse nome se baseia o nome fornecido no **Short name**, precedidos pela 'c', o prefixo típico para um nome de classe.

- **Arquivo .cpp**

   Define o nome do arquivo de implementação para a nova classe do objeto. Por padrão, esse nome se baseia o nome fornecido no **Short name**. Clique no botão de reticências para salvar o nome de arquivo no local de sua escolha. O arquivo não é salvo no local selecionado até que você clique em **Concluir** no assistente.

   O assistente não substitui um arquivo. Se você selecionar o nome de um arquivo existente, quando clicar em **Concluir**, o assistente solicitará que você indique se a implementação de classe deve ser acrescentada ao conteúdo do arquivo. Clique em **Sim** para acrescentar o arquivo; clique em **Não** para retornar ao assistente e especificar outro nome de arquivo.

- **Atribuído**

   Indica se o objeto usa atributos. Se você estiver adicionando um objeto para um projeto ATL atribuído, essa opção é selecionada e não está disponível para alterar. Ou seja, você pode adicionar apenas os objetos atribuídos a um projeto criado com o suporte do atributo.

   Se você selecionar essa opção para um projeto ATL que não tem atributo dão suporte, o assistente solicita que você especifique se deseja adicionar suporte de atributo para o projeto.

   Quaisquer objetos que você adicionar essa opção a seguir são designados como atribuído por padrão (a caixa de seleção está marcada). Você pode desmarcar essa caixa para adicionar um objeto que não usa atributos.

   Ver [configurações de aplicativo, o ATL Project Wizard](../../atl/reference/application-settings-atl-project-wizard.md) e [mecânica básica de atributos](../../windows/basic-mechanics-of-attributes.md) para obter mais informações.

### <a name="com"></a>COM

Fornece informações sobre a funcionalidade de COM para o objeto.

- **Coclass**

   Define o nome da classe de componente que contém uma lista de interfaces com suporte do objeto.

> [!NOTE]
>  Se você criar seu projeto usando atributos, ou se você indicar nesta página do assistente que o componente COM+ 1.0 usa atributos, você não pode alterar essa opção porque ATL não inclui o `coclass` atributo.

- **Tipo**

   Define a descrição do objeto que será exibido no registro

- **Interface**

   Define a interface que você cria para seu objeto. Essa interface contém seus métodos personalizados.

- **ProgID**

   Define o nome que contêineres podem usar em vez do CLSID do objeto.

## <a name="see-also"></a>Consulte também

[Componente ATL COM+ 1.0](../../atl/reference/adding-an-atl-com-plus-1-0-component.md)

