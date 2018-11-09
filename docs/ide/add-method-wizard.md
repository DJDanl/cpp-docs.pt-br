---
title: Assistente de Adição de Método
ms.date: 11/04/2016
f1_keywords:
- vc.codewiz.method.overview
helpviewer_keywords:
- Add Method Wizard [C++]
- methods [C++], adding using wizards
ms.assetid: b9a71b0e-9ecf-40fa-9f86-4200cb23d671
ms.openlocfilehash: e03f1fe925a82baa8c291ebf6fc6ccca34a00b90
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50547843"
---
# <a name="add-method-wizard"></a>Assistente de Adição de Método

Use este assistente para adicionar um método a uma interface. Dependendo do tipo de projeto ou de interface ao qual você está adicionando um método, o assistente exibe opções diferentes.

## <a name="names"></a>Nomes

- **Tipo de retorno**

   O tipo de dados retornado pelo método. `HRESULT` é recomendado para todos os tipos de interface, porque fornece uma maneira padrão de retornar erros.

   |Tipo de interface|Descrição|
   |--------------------|-----------------|
   |Interface dupla|`HRESULT`. Inalterável.|
   |Interface personalizada|`HRESULT`. Inalterável.|
   |Interface personalizada local|Forneça seu próprio tipo de retorno ou selecione um na lista.|
   |Dispinterface|Forneça seu próprio tipo de retorno ou selecione um na lista.|
   |Dispinterface de controle ActiveX do MFC|Se você implementar um método de estoque, o tipo de retorno será definido com o valor apropriado e não poderá ser alterado. Se você selecionar um método na lista **Nome do método** e clicar em **Personalizado** em **Selecionar tipo de método**, selecione um tipo de retorno na lista.|

- **Nome do método**

   Define o nome do método.

   |Tipo de interface|Descrição|
   |--------------------|-----------------|
   |Interface dupla ATL, interface personalizada e interface personalizada local|Forneça seu próprio nome de método.|
   |Dispinterface MFC|Forneça seu próprio nome de método ou selecione um nome de método sugerido na lista. Se você selecionar um nome na lista, o valor apropriado será exibido na caixa **Tipo de retorno** e ele não poderá ser alterado.|
   |Dispinterface de controle ActiveX do MFC|Forneça seu próprio método ou selecione um destes métodos de estoque: [DoClick](../mfc/reference/colecontrol-class.md#doclick) e [Refresh](../mfc/reference/colecontrol-class.md#refresh). Confira [Controles ActiveX MFC: Adicionando métodos de estoque](../mfc/mfc-activex-controls-adding-stock-methods.md) para obter mais informações.|

- **Tipo de método**

   Disponível somente para controles ActiveX MFC. Se você fornecer um nome de método na caixa **Nome do método**, em vez de selecionar um método na lista, essa caixa não ficará disponível.

   Se você selecionar um dos métodos na lista **Nome do método**, selecione a implementação de estoque ou uma implementação personalizada.

   |Tipo de método|Descrição|
   |-----------------|-----------------|
   |**Estoque**|O padrão. Insere a implementação de estoque do método selecionado na lista **Nome do método**. **Tipo de retorno** não poderá ser alterado se você selecionar **Estoque**.|
   |**Personalizado**|Insere uma implementação de stub do método selecionado na lista **Nome do método**. Para tipos de método personalizados, forneça seu próprio tipo de retorno ou selecione um na lista **Tipo de retorno**.|

- **Nome interno**

   Disponível somente para métodos personalizados adicionados a uma dispinterface MFC. Define o nome usado no mapa de expedição, no arquivo de cabeçalho (.h) e no arquivo de implementação (.cpp). Por padrão, esse nome é o mesmo que o **Nome do método**. Você poderá alterar o nome do método se estiver trabalhando com uma dispinterface MFC ou se estiver adicionando um método personalizado a uma dispinterface de controle ActiveX MFC.

   |Tipo de interface|Descrição|
   |--------------------|-----------------|
   |Interface dupla ATL, interface personalizada e interface personalizada local|Não disponível|
   |Dispinterface MFC|Definida com o nome do método por padrão. Você pode editar o nome interno.|
   |Dispinterface de controle ActiveX do MFC|Você pode definir o nome interno somente de métodos personalizados. Os métodos de estoque não usam um nome interno.|

- **Atributos de parâmetro**

   Define os atributos adicionais para o parâmetro especificado em **Nome do parâmetro**.

   |Atributo de parâmetro|Descrição|Combinações permitidas|
   |-------------------------|-----------------|--------------------------|
   |**In**|Indica que o parâmetro é passado do procedimento de chamada para o procedimento chamado.|Somente **in**<br /><br /> **in** e **out**|
   |**Saída**|Indica que o parâmetro de ponteiro é retornado do procedimento chamado para o procedimento de chamada (do servidor para o cliente).|Somente **out**<br /><br /> **in** e **out**<br /><br /> **out** e **retval**|
   |**Retval**|Indica que o parâmetro recebe o valor retornado do membro.|**retval** e out|

- **Tipo de parâmetro**

   Define o tipo de dados do parâmetro. Selecione o tipo na lista.

- **Nome do parâmetro**

   Define o nome de um parâmetro a ser passado pelo método. Depois de digitar o nome, clique em **Adicionar** para adicioná-lo à lista de parâmetros que passarão pelo método. Se você não fornecer um nome de parâmetro, o assistente ignorará os atributos de parâmetro (somente ATL) ou as seleções de **Tipo de parâmetro**.

   Depois de clicar em **Adicionar**, o nome do parâmetro é exibido em **Lista de parâmetros**.

   > [!Note]
   > Se você fornecer um nome de parâmetro e, em seguida, clicar em **Concluir** antes de clicar em **Adicionar**, o parâmetro não será adicionado ao método. É necessário encontrar o método e inserir o parâmetro manualmente.

- **Adicionar**

   Adiciona o parâmetro especificado em **Nome do parâmetro**, seu tipo e atributos de parâmetro à **Lista de parâmetros**. Clique em **Adicionar** para adicionar um parâmetro à lista.

- **Removerr**

   Remove o parâmetro selecionado em **Lista de parâmetros** da lista.

- **Lista de parâmetros**

   Exibe todos os parâmetros e seus modificadores e tipos atualmente adicionados ao método. Conforme os parâmetros são adicionados, o assistente atualiza a **Lista de parâmetros** para exibir cada parâmetro, com seu modificador e tipo.

## <a name="see-also"></a>Consulte também

[Adicionando um método](../ide/adding-a-method-visual-cpp.md)<br/>
[Atributos IDL, Assistente de Adição de Método](../ide/idl-attributes-add-method-wizard.md)