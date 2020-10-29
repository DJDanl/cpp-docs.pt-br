---
title: Assistente para adicionar classe de Typelib
ms.date: 05/09/2019
helpviewer_keywords:
- COM interfaces, adding classes
ms.assetid: 96152afd-9374-4649-a6ab-b0fa2a5592a3
ms.openlocfilehash: 73f2668883add0e711f0ef73e5602dd9cdc4ab28
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92924102"
---
# <a name="add-class-from-typelib-wizard"></a>Assistente para adicionar classe de Typelib

::: moniker range="msvc-160"

Esse assistente não está disponível no Visual Studio 2019 e versões posteriores.

::: moniker-end

::: moniker range="<=msvc-150"

Use este assistente para adicionar uma classe do MFC de uma biblioteca de tipos disponível. O assistente cria uma classe para cada interface que você adiciona da biblioteca de tipos selecionada.

- **Adicionar classe de**

   Especifica o local da biblioteca de tipos, com base na qual a classe é criada.

   |Opção|Descrição|
   |------------|-----------------|
   |**Registro**|A biblioteca de tipos é registrada no sistema. As bibliotecas de tipos registradas são listadas em **Bibliotecas de tipos disponíveis** .|
   |**Arquivo**|A biblioteca de tipos não está necessariamente registrada no sistema, mas está contida em um arquivo. É necessário fornecer o local do arquivo em **Local** .|

- **Bibliotecas de tipos disponíveis**

   Lista as bibliotecas de tipos atualmente registradas no sistema. Selecione uma biblioteca de tipos nesta lista para exibir suas interfaces na lista de **interfaces** .

- **Localização**

   Especifica o local da biblioteca de tipos. Se você clicar em **Arquivo** em **Adicionar Classe por meio de** , poderá fornecer o local do arquivo que contém a biblioteca de tipos. Para procurar o local do arquivo, clique no botão de reticências.

- **Interfaces**

   Lista as interfaces na biblioteca de tipos selecionada no momento na lista **bibliotecas de tipos disponíveis** .

   |Botão de transferência|Descrição|
   |---------------------|-----------------|
   |**>**|Adiciona a interface atualmente selecionada na lista **Interfaces** . Esmaecido se nenhuma interface for selecionada.|
   |**>>**|Adiciona todas as interfaces na biblioteca de tipos selecionada no momento na lista **bibliotecas de tipos disponíveis** .|
   |**\<**|Remove a classe atualmente selecionada na lista **Classes geradas** . Esmaecido se nenhuma classe estiver selecionada no momento na lista de **classes geradas** .|
   |**\<\<**|Remove todas as classes da lista **Classes geradas** . Esmaecido se a lista de **classes geradas** estiver vazia.|

- **classes geradas**

   Especifica os nomes de classe a serem gerados a partir das interfaces adicionadas usando o **>** **>>** botão ou. Você pode clicar nessa caixa para selecionar uma classe e, em seguida, usar as teclas para cima ou para baixo para percorrer a lista, exibindo cada nome de classe na caixa de **classe** e o nome do arquivo na caixa **arquivo** que o assistente gera quando você clica em **concluir** . Selecione apenas uma classe por vez nessa caixa.

   Você pode remover uma classe selecionando-a na lista e clicando em **<** . Não é necessário selecionar uma classe na caixa Classes geradas para remover todas as classes; se você clicar em **<<** , todas as classes da caixa **Classes geradas** serão removidas.

- **Classe**

   Especifica o nome da classe selecionada na caixa **Classes geradas** adicionada pelo assistente quando você clica em **Concluir** . É possível editar o nome na caixa **Classe** .

- **Arquivo**

   Define o nome do arquivo de cabeçalho para a nova classe. Por padrão, esse nome baseia-se no nome fornecido em **Classes geradas** . Clique no botão de reticências para salvar o nome de arquivo no local de sua escolha, ou para acrescentar a declaração de classe a um arquivo existente. Se você escolher um arquivo existente, o assistente não o salvará no local selecionado até que você clique em **Concluir** no assistente.

   O assistente não substitui um arquivo. Se você selecionar o nome de um arquivo existente, quando clicar em **Concluir** , o assistente solicitará que você indique se a declaração de classe deve ser acrescentada ao conteúdo do arquivo. Clique em **Sim** para acrescentar o arquivo; clique em **Não** para retornar ao assistente e especificar outro nome de arquivo.

::: moniker-end

## <a name="see-also"></a>Veja também

[Classe do MFC de uma biblioteca de tipos](../../mfc/reference/adding-an-mfc-class-from-a-type-library.md)<br/>
[Clientes de automação: usando bibliotecas de tipos](../../mfc/automation-clients-using-type-libraries.md)
