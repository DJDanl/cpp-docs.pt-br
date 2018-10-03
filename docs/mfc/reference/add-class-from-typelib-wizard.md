---
title: Adicionar classe de Typelib Assistente | Microsoft Docs
ms.custom: ''
ms.date: 10/03/2018
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- vc.codewiz.class.typelib
dev_langs:
- C++
helpviewer_keywords:
- Add Class from TypeLib Wizard [MFC]
- COM interfaces, adding classes
ms.assetid: 96152afd-9374-4649-a6ab-b0fa2a5592a3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 0a54948fd98b5a5445aa1fdfafcf0fcd015bbf08
ms.sourcegitcommit: d1527eb2d50156bf923f2a32ec3af9efc7fc4304
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/03/2018
ms.locfileid: "48250374"
---
# <a name="add-class-from-typelib-wizard"></a>Assistente para adicionar classe de Typelib

Use este assistente para adicionar uma classe MFC de uma biblioteca de tipos disponíveis. O assistente cria uma classe para cada interface que você adicione da biblioteca de tipo selecionado.

> [!WARNING]
> No Visual Studio 2017 versão 15,9 este assistente de código foi preterido e será removido em uma versão futura do Visual Studio. Este assistente é raramente usado. Suporte geral para ATL e MFC não é afetado pela remoção desse assistente. Se você quiser compartilhar seus comentários sobre essa substituição, conclua [desta pesquisa](https://www.surveymonkey.com/r/QDWKKCN). Sua opinião é importante para nós.

- **Adicione uma classe de**

   Especifica o local da biblioteca de tipos, com base na qual a classe é criada.

   |Opção|Descrição|
   |------------|-----------------|
   |**Registry**|A biblioteca de tipos é registrada no sistema. As bibliotecas de tipos registradas são listadas em **Bibliotecas de tipos disponíveis**.|
   |**Arquivo**|A biblioteca de tipos não está necessariamente registrada no sistema, mas está contida em um arquivo. É necessário fornecer o local do arquivo em **Local**.|

- **Bibliotecas de tipos disponíveis**

   Lista as bibliotecas de tipos registradas atualmente no sistema. Selecione nesta lista para exibir suas interfaces em uma biblioteca de tipos do **Interfaces** lista.

   Consulte "Dentro de Distributed COM: tipo bibliotecas e linguagem integração" na biblioteca MSDN para obter mais informações sobre como registrar as bibliotecas de tipos.

- **Local**

   Especifica o local da biblioteca de tipos. Se você clicar em **Arquivo** em **Adicionar Classe por meio de**, poderá fornecer o local do arquivo que contém a biblioteca de tipos. Para procurar o local do arquivo, clique no botão de reticências.

- **Interfaces**

   Lista as interfaces na biblioteca de tipos selecionada no momento a **bibliotecas de tipos disponíveis** lista.

   |Botão de transferência|Descrição|
   |---------------------|-----------------|
   |**>**|Adiciona a interface atualmente selecionada na lista **Interfaces**. Esmaecido se nenhuma interface for selecionada.|
   |**>>**|Adiciona todas as interfaces na biblioteca de tipos selecionada no momento a **bibliotecas de tipos disponíveis** lista.|
   |**\<**|Remove a classe atualmente selecionada na lista **Classes geradas**. Esmaecido se nenhuma classe selecionado no momento a **classes geradas** lista.|
   |**\<\<**|Remove todas as classes da lista **Classes geradas**. Esmaecido se o **classes geradas** lista está vazia.|

- **classes geradas**

   Especifica os nomes de classe a serem gerados com base nas interfaces adicionadas por meio do botão **>** ou **>>**. Você pode clicar nesta caixa para selecionar uma classe e, em seguida, use as teclas ou para baixo para rolar a lista, exibindo o nome de cada classe na **classe** caixa e nome de arquivo na **arquivo** caixa que o assistente gera quando você Clique em **concluir**. Selecione apenas uma classe por vez nessa caixa.

   Remova uma classe selecionando-a nessa lista e clicando em **<**. Não é necessário selecionar uma classe da caixa de classes geradas para remover todas as classes; ao clicar em **<<**, você remover todas as classes no **classes geradas** caixa.

- **Class**

   Especifica o nome da classe selecionada na caixa **Classes geradas** adicionada pelo assistente quando você clica em **Concluir**. Você pode editar o nome na **classe** caixa.

- **Arquivo**

   Define o nome do arquivo de cabeçalho para a nova classe. Por padrão, esse nome baseia-se no nome fornecido em **Classes geradas**. Clique no botão de reticências para salvar o nome de arquivo no local de sua escolha, ou para acrescentar a declaração de classe a um arquivo existente. Se você escolher um arquivo existente, o assistente não o salvará no local selecionado até que você clique em **Concluir** no assistente.

   O assistente não substitui um arquivo. Se você selecionar o nome de um arquivo existente, quando clicar em **Concluir**, o assistente solicitará que você indique se a declaração de classe deve ser acrescentada ao conteúdo do arquivo. Clique em **Sim** para acrescentar o arquivo; clique em **Não** para retornar ao assistente e especificar outro nome de arquivo.

## <a name="see-also"></a>Consulte também

[Classe do MFC de uma biblioteca de tipos](../../mfc/reference/adding-an-mfc-class-from-a-type-library.md)<br/>
[Clientes de automação: usando bibliotecas de tipo](../../mfc/automation-clients-using-type-libraries.md)

