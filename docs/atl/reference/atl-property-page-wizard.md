---
title: Assistente de página de propriedades da ATL
ms.date: 10/03/2018
f1_keywords:
- vc.codewiz.class.atl.ppg.overview
helpviewer_keywords:
- ATL projects, adding property pages
- ATL Property Page Wizard
ms.assetid: 6113e325-facd-4f68-b491-144d75209922
ms.openlocfilehash: 791901ab3181ad2c8ac862a970980250693d20f7
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62248215"
---
# <a name="atl-property-page-wizard"></a>Assistente de página de propriedades da ATL

Este assistente [adiciona uma página de propriedades em um projeto ATL](../../atl/reference/adding-an-atl-property-page.md) ou a um projeto MFC com suporte ATL. Uma página de propriedades ATL fornece uma interface do usuário para definir as propriedades (ou chamar os métodos) de um ou mais objetos de COM.

> [!WARNING]
> No Visual Studio 2017 versão 15.9, esse assistente de código foi preterido e será removido em uma versão futura do Visual Studio. Este assistente é raramente usado. O suporte geral para ATL e MFC não é afetado pela remoção do assistente. Se você quiser compartilhar seus comentários sobre essa alteração, participe [desta pesquisa](https://www.surveymonkey.com/r/QDWKKCN). Seus comentários são importantes para nós.

## <a name="remarks"></a>Comentários

A partir do Visual Studio 2008, o script de registro produzido por este assistente registrará seus componentes COM sob **HKEY_CURRENT_USER** em vez de **HKEY_LOCAL_MACHINE**. Para modificar esse comportamento, defina as **registrar o componente para todos os usuários** opção do Assistente da ATL.

## <a name="names"></a>Nomes

Especifique os nomes para o objeto, a interface e a classes a serem adicionadas ao seu projeto. Exceto para **Short name**, todas as outras caixas podem ser editadas de forma independente. Se você alterar o texto para **Short name**, a alteração é refletida nos nomes de todas as outras caixas nesta página. Se você alterar o **Coclass** na seção de COM, a alteração é refletido na **tipo** e **ProgID** caixas. Esse comportamento de nomenclatura é projetado para tornar todos os nomes de fácil identificação para você à medida que você desenvolve sua página de propriedades.

> [!NOTE]
>  **Coclass** é editável apenas nonattributed projetos. Se seu projeto atribuído, você não pode editar **Coclass**.

### <a name="c"></a>C++

Fornece informações para a classe C++ criada para implementar o objeto.

|||
|-|-|
|Termo|Definição|
|**Nome curto**|Define o nome abreviado do objeto. O nome que você forneceu determina a classe e **Coclass** nomeia o arquivo (**. cpp** e **. h**) nomes, o **tipo** nome e o  **ProgID**, a menos que você altere esses campos individualmente.|
|**Arquivo .h**|Define o nome do arquivo de cabeçalho para a nova classe do objeto. Por padrão, esse nome é baseado no nome que você fornecer em **Short name**. Clique no botão de reticências para salvar o nome de arquivo no local de sua escolha, ou para acrescentar a declaração de classe a um arquivo existente. Se você selecionar um arquivo existente, o assistente não salvará no local selecionado até que você clique **concluir** no assistente.<br /><br /> O assistente não substitui um arquivo. Se você selecionar o nome de um arquivo existente, quando clicar em **Concluir**, o assistente solicitará que você indique se a declaração de classe deve ser acrescentada ao conteúdo do arquivo. Clique em **Sim** para acrescentar o arquivo; clique em **Não** para retornar ao assistente e especificar outro nome de arquivo.|
|**Class**|Define o nome da classe que implementa o objeto. Esse nome é baseado no nome que você fornecer em **Short name**, precedidos pela 'c', o prefixo típico para um nome de classe.|
|**Arquivo .cpp**|Define o nome do arquivo de implementação para a nova classe do objeto. Por padrão, esse nome é baseado no nome que você fornecer em **Short name**. Clique no botão de reticências para salvar o nome de arquivo no local de sua escolha. O arquivo não é salvo no local selecionado até que você clique em **Concluir** no assistente.<br /><br /> O assistente não substitui um arquivo. Se você selecionar o nome de um arquivo existente, quando clicar em **Concluir**, o assistente solicitará que você indique se a implementação de classe deve ser acrescentada ao conteúdo do arquivo. Clique em **Sim** para acrescentar o arquivo; clique em **Não** para retornar ao assistente e especificar outro nome de arquivo.|
|**Atribuído**|Indica se o objeto usa atributos. Se você estiver adicionando um objeto a um projeto ATL atribuído, essa opção é selecionada e não está disponível para alterar, ou seja, você pode adicionar atribuído apenas objetos para um projeto criado com o suporte do atributo.<br /><br /> Você pode adicionar um objeto atribuído somente a um projeto ATL que usa atributos. Se você selecionar essa opção para um projeto ATL que não tem atributo dão suporte, o assistente solicita que você especifique se deseja adicionar suporte de atributo para o projeto.<br /><br /> Por padrão, todos os objetos você adiciona depois de definir essa opção são designados como atribuído (a caixa de seleção está marcada). Você pode desmarcar essa caixa para adicionar um objeto que não usa atributos.<br /><br /> Ver [configurações de aplicativo, o ATL Project Wizard](../../atl/reference/application-settings-atl-project-wizard.md) e [mecânica básica de atributos](../../windows/basic-mechanics-of-attributes.md) para obter mais informações.|

### <a name="com"></a>COM

Fornece informações sobre a funcionalidade de COM para o objeto.

- **Coclass**

   Define o nome da classe de componente que contém uma lista de interfaces com suporte do objeto.

   > [!NOTE]
   > Se você criar seu projeto usando atributos, ou se você indicar nesta página do Assistente para a página de propriedades usa atributos, você não pode alterar essa opção porque ATL não inclui o `coclass` atributo.

- **Tipo**

   Define a descrição do objeto que será exibido no registro

- **ProgID**

   Define o nome que contêineres podem usar em vez do CLSID do objeto.

## <a name="see-also"></a>Consulte também

[Opções, Assistente de página de propriedades da ATL](../../atl/reference/options-atl-property-page-wizard.md)<br/>
[Cadeias de caracteres, o Assistente de página de propriedades ATL](../../atl/reference/strings-atl-property-page-wizard.md)<br/>
[Exemplo: implementar uma página de propriedades](../../atl/example-implementing-a-property-page.md)
