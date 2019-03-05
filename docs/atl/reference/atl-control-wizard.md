---
title: Assistente de controle ATL
ms.date: 11/04/2016
f1_keywords:
- vc.codewiz.class.atl.control.overview
helpviewer_keywords:
- ATL projects, adding controls
- controls [ATL], adding to projects
- ATL Control Wizard
ms.assetid: 991f8e72-ffbc-4382-a4ce-e255acfba5b6
ms.openlocfilehash: 58c3ebe4c2a15aa3f0d59191c37a7f2422a63ab5
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57287890"
---
# <a name="atl-control-wizard"></a>Assistente de controle ATL

Inserções em um projeto ATL (ou um projeto do MFC com suporte ATL) um controle da ATL. Você pode usar esse assistente para inserir um dos três tipos de controles:

- Controle padrão

- Controle de composição

- Controle DHTML

Além disso, você pode especificar um controle mínimo, removendo as interfaces do [Interfaces](../../atl/reference/interfaces-atl-control-wizard.md) lista, que são fornecidos como padrões para controles abrir na maioria dos contêineres. Você pode definir as interfaces que deseja dar suporte para o controle de **Interfaces** página do assistente.

## <a name="remarks"></a>Comentários

O script de registro produzido por este assistente registrará seus componentes COM em HKEY_CURRENT_USER em vez de HKEY_LOCAL_MACHINE. Para modificar esse comportamento, defina as **registrar o componente para todos os usuários** opção do Assistente da ATL.

## <a name="names"></a>Nomes

Especifique os nomes para o objeto, a interface e a classes a serem adicionadas ao seu projeto. Exceto para **Short name**, todas as outras caixas podem ser alteradas de forma independente. Se você alterar o texto para **Short name**, a alteração é refletida nos nomes de todas as outras caixas nesta página. Se você alterar o **Coclass** na seção de COM, a alteração é refletido na **tipo** caixa, mas o **Interface** nome e **ProgID** fazer não alterar. Esse comportamento de nomenclatura é projetado para tornar todos os nomes de fácil identificação para você à medida que desenvolve seu controle.

> [!NOTE]
>  **Coclass** é editável apenas nonattributed controles. Se seu projeto atribuído, você não pode editar **Coclass**.

### <a name="c"></a>C++

Fornece informações para a classe C++ criada para implementar o objeto.

- **Nome curto**

   Define o nome abreviado do objeto. O nome que você forneceu determina a classe e **Coclass** nomeia o arquivo (. CPP e. H) nomes de, o nome da interface e o **tipo** nomes, a menos que você altere esses campos individualmente.

- **Class**

   Define o nome da classe que implementa o objeto. Esse nome é baseado no nome que você fornecer em **Short name**, precedidos pela 'c', o prefixo típico para um nome de classe.

- **Arquivo .h**

   Define o nome do arquivo de cabeçalho para a nova classe do objeto. Por padrão, esse nome é baseado no nome que você fornecer em **Short name**. Clique no botão de reticências para salvar o nome de arquivo no local de sua escolha, ou para acrescentar a declaração de classe a um arquivo existente. Se você selecionar um arquivo existente, o assistente não salvará no local selecionado até que você clique **concluir**.

   O assistente não substitui um arquivo. Se você selecionar o nome de um arquivo existente, quando clicar em **Concluir**, o assistente solicitará que você indique se a declaração de classe deve ser acrescentada ao conteúdo do arquivo. Clique em **Sim** para acrescentar o arquivo; clique em **Não** para retornar ao assistente e especificar outro nome de arquivo.

- **Arquivo .cpp**

   Define o nome do arquivo de implementação para a nova classe do objeto. Por padrão, esse nome é baseado no nome que você fornecer em **Short name**. Clique no botão de reticências para salvar o nome de arquivo no local de sua escolha. O arquivo não é salvo no local selecionado até que você clique em **Concluir** no assistente.

   O assistente não substitui um arquivo. Se você selecionar o nome de um arquivo existente, quando clicar em **Concluir**, o assistente solicitará que você indique se a implementação de classe deve ser acrescentada ao conteúdo do arquivo. Clique em **Sim** para acrescentar o arquivo; clique em **Não** para retornar ao assistente e especificar outro nome de arquivo.

- **Atribuído**

   Indica se o objeto usa atributos. Se você estiver adicionando um objeto para um projeto ATL atribuído, essa opção é selecionada e não está disponível para alterar. Ou seja, você pode adicionar apenas os objetos atribuídos a um projeto criado com o suporte do atributo.

   Você pode adicionar um objeto atribuído somente a um projeto ATL que usa atributos. Se você selecionar essa opção para um projeto ATL que não tem atributo dão suporte, o assistente solicita que você especifique se deseja adicionar suporte de atributo para o projeto.

   Por padrão, todos os objetos você adiciona depois de definir essa opção são designados como atribuído (a caixa de seleção está marcada). Você pode desmarcar essa caixa para adicionar um objeto que não usa atributos.

   Ver [configurações de aplicativo, o ATL Project Wizard](../../atl/reference/application-settings-atl-project-wizard.md) e [mecânica básica de atributos](../../windows/basic-mechanics-of-attributes.md) para obter mais informações.

### <a name="com"></a>COM

Fornece informações sobre a funcionalidade de COM para o objeto.

- **Coclass**

   Define o nome da classe de componente que contém uma lista de interfaces com suporte do objeto.

   > [!NOTE]
   > Se você criar seu projeto usando atributos, ou se você indicar nesta página do assistente que o controle usa atributos, você não pode alterar essa opção porque ATL não inclui o **coclass** atributo.

- **Interface**

   Define o nome da interface para o objeto. Por padrão, um nome de interface é acrescentado com "I".

- **Tipo**

   Define a descrição do objeto que será exibido no registro

- **ProgID**

   Define o nome que contêineres podem usar em vez do CLSID do objeto. Este campo não é preenchido automaticamente. Se você não preencher este campo manualmente, o controle pode não estar disponível para outras ferramentas. Por exemplo, os controles ActiveX que são gerados sem um `ProgID` não estão disponíveis em de **Inserir controle ActiveX** caixa de diálogo. Para obter mais informações sobre a caixa de diálogo, confira [Inserir caixa de diálogo de controle ActiveX](../../windows/insert-activex-control-dialog-box.md).

## <a name="see-also"></a>Consulte também

[Controle da ATL](../../atl/reference/adding-an-atl-control.md)<br/>
[Adicionando funcionalidade ao controle de composição](../../atl/adding-functionality-to-the-composite-control.md)<br/>
[Princípios básicos de objetos COM da ATL](../../atl/fundamentals-of-atl-com-objects.md)
