---
title: Adicionar um método
ms.date: 11/09/2018
f1_keywords:
- vc.codewiz.method.overview
- vc.codewiz.method.idlattrib
helpviewer_keywords:
- add method wizard [C++]
- methods [C++], adding
- methods [C++], adding using wizards
- IDL attributes, add method wizard
ms.assetid: 4ba4e45f-fa38-4d5e-af44-cbec0a7ab558
ms.openlocfilehash: 23fb05e633713016b1f6289f73a916502736af10
ms.sourcegitcommit: b032daf81cb5fdb1f5a988277ee30201441c4945
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/15/2018
ms.locfileid: "51692679"
---
# <a name="add-a-method"></a>Adicionar um método

Use o [assistente de adição de método](#add-method-wizard) para adicionar um método a uma interface no projeto. Se o projeto contém uma classe associada à interface, o assistente modifica a classe também.

**Para adicionar um método ao objeto:**

1. Em **Modo de Exibição de Classe**, expanda o nó do projeto para exibir a interface à qual você deseja adicionar o método.

   > [!NOTE]
   > Adicione também métodos a dispinterfaces, que estarão localizadas no nó da biblioteca, a menos que o projeto esteja atribuído.

1. Clique com o botão direito do mouse no nome da interface.

1. No menu de atalho, escolha **Adicionar** e, depois, **Adicionar método**.

1. No Assistente de Adição de Método, forneça as informações para criar o método.

1. Especifique as configurações de linguagem IDL para esse método na página [Atributos IDL](#idl-attributes-add-method-wizard) do assistente.

1. Selecione **Concluir** para adicionar o método.

## <a name="in-this-section"></a>Nesta seção

- [Assistente de adição de método](#add-method-wizard)
- [Atributos IDL, assistente de adição de método](#idl-attributes-add-method-wizard)

## <a name="add-method-wizard"></a>Assistente de adição de método

Use este assistente para adicionar um método a uma interface. Dependendo do tipo de projeto ou de interface ao qual você está adicionando um método, o assistente exibe opções diferentes.

### <a name="names"></a>Nomes

- **Tipo de retorno**

  O tipo de dados retornado pelo método. `HRESULT` é recomendado para todos os tipos de interface, porque fornece uma maneira padrão de retornar erros.

  |Tipo de interface|Descrição|
  |--------------------|-----------------|
  |Interface dupla|`HRESULT`. Inalterável.|
  |Interface personalizada|`HRESULT`. Inalterável.|
  |Interface personalizada local|Forneça seu próprio tipo de retorno ou selecione um na lista.|
  |Dispinterface|Forneça seu próprio tipo de retorno ou selecione um na lista.|
  |Dispinterface de controle ActiveX do MFC|Se você implementar um método de estoque, o tipo de retorno será definido com o valor apropriado e não poderá ser alterado. Se você selecionar um método na lista **Nome do método** e selecionar **Personalizado** em **Selecionar tipo de método**, selecione um tipo de retorno na lista.|

- **Nome do método**

  Define o nome do método.

  |Tipo de interface|Descrição|
  |--------------------|-----------------|
  |Interface dupla ATL, interface personalizada e interface personalizada local|Forneça seu próprio nome de método.|
  |Dispinterface MFC|Forneça seu próprio nome de método ou selecione um nome de método sugerido na lista. Se você selecionar um nome na lista, o valor apropriado será exibido na caixa **Tipo de retorno** e ele não poderá ser alterado.|
  |Dispinterface de controle ActiveX do MFC|Forneça seu próprio método ou selecione um destes métodos de estoque: [DoClick](../mfc/reference/colecontrol-class.md#doclick) e [Refresh](../mfc/reference/colecontrol-class.md#refresh). Para obter mais informações, confira [Controles ActiveX MFC: Adicionando métodos de estoque](../mfc/mfc-activex-controls-adding-stock-methods.md).|

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
  |Interface dupla ATL, interface personalizada e interface personalizada local|Não disponível.|
  |Dispinterface MFC|Definida com o nome do método por padrão. Você pode editar o nome interno.|
  |Dispinterface de controle ActiveX do MFC|Você pode definir o nome interno somente de métodos personalizados. Os métodos de estoque não usam um nome interno.|

- **Atributos de parâmetro**

  Define os atributos adicionais para o parâmetro especificado em **Nome do parâmetro**.

  |Atributo de parâmetro|Descrição|Combinações permitidas|
  |-------------------------|-----------------|--------------------------|
  |**In**|Indica que o parâmetro é passado do procedimento de chamada para o procedimento chamado.|`in` somente<br /><br /> `in` e `out`|
  |**Saída**|Indica que o parâmetro de ponteiro é retornado do procedimento chamado para o procedimento de chamada (do servidor para o cliente).|`out` somente<br /><br /> `in` e `out`<br /><br /> `out` e `retval`|
  |**Retval**|Indica que o parâmetro recebe o valor retornado do membro.|`retval` e `out`|

- **Tipo de parâmetro**

  Define o tipo de dados do parâmetro. Selecione o tipo na lista.

- **Nome do parâmetro**

  Define o nome de um parâmetro a ser passado pelo método. Depois de digitar o nome, selecione **Adicionar** para adicioná-lo à lista de parâmetros que passarão pelo método. Se você não fornecer um nome de parâmetro, o assistente ignorará os atributos de parâmetro (somente ATL) ou as seleções de **Tipo de parâmetro**.

  Depois de selecionar **Adicionar**, o nome do parâmetro é exibido em **Lista de parâmetros**.

  > [!NOTE]
  > Se você fornecer um nome de parâmetro e, em seguida, selecionar **Concluir** antes de selecionar **Adicionar**, o parâmetro não será adicionado ao método. É necessário encontrar o método e inserir o parâmetro manualmente.

- **Adicionar**

  Adiciona o parâmetro especificado em **Nome do parâmetro**, seu tipo e atributos de parâmetro à **Lista de parâmetros**. Selecione **Adicionar** para adicionar um parâmetro à lista.

- **Removerr**

  Remove o parâmetro selecionado em **Lista de parâmetros** da lista.

- **Lista de parâmetros**

  Exibe todos os parâmetros e seus modificadores e tipos atualmente adicionados ao método. Conforme os parâmetros são adicionados, o assistente atualiza a **Lista de parâmetros** para exibir cada parâmetro, com seu modificador e tipo.

## <a name="idl-attributes-add-method-wizard"></a>Atributos IDL, assistente de adição de método

Use esta página do Assistente de Adição de Método para especificar as configurações de linguagem IDL para o método.

- `id`

  Define a ID numérica que identifica o método. Para obter mais informações, confira [id](/windows/desktop/Midl/id) na *Referência de MIDL*.

  Essa caixa não está disponível para interfaces personalizadas nem para dispinterfaces MFC.

- `call_as`

  Especifica o nome de um método remoto para o qual esse método local pode ser mapeado. Para obter mais informações, confira [call_as](/windows/desktop/Midl/call-as) na *Referência de MIDL*.

  Não disponível para dispinterfaces MFC.

- `helpcontext`

  Especifica uma ID de contexto que permite ao usuário exibir informações sobre esse método no arquivo de Ajuda. Para obter mais informações, confira [helpcontext](/windows/desktop/Midl/helpcontext) na *Referência de MIDL*.

  Não disponível para dispinterfaces MFC.

- `helpstring`

  Especifica uma cadeia de caracteres que é usada para descrever o elemento ao qual ela se aplica. Ela é definida, por padrão, como "method *Nome do método*". Para obter mais informações, confira [helpstring](/windows/desktop/Midl/helpstring) na *Referência de MIDL*.

  Não disponível para dispinterfaces MFC.

- **Atributos adicionais**

  Não disponível para dispinterfaces MFC.

  |Atributo|Descrição|
  |---------------|-----------------|
  |`hidden`|Indica que o método existe, mas que não deveria ser exibido em um navegador orientado ao usuário. Para obter mais informações, confira [hidden](/windows/desktop/Midl/hidden) na *Referência de MIDL*.|
  |`source`|Indica que um membro do método é uma origem de eventos. Para obter mais informações, confira [source](/windows/desktop/Midl/source) na *Referência de MIDL*.|
  |`local`|Especifica para o compilador MIDL que o método não é remoto. Para obter mais informações, confira [local](/windows/desktop/Midl/local) na *Referência de MIDL*.|
  |`restricted`|Especifica que o método não pode ser chamado arbitrariamente. Para obter mais informações, confira [restricted](/windows/desktop/Midl/restricted) na *Referência de MIDL*.|
  |`vararg`|Especifica que o método usa um número variável de argumentos. Para fazer isso, o último argumento precisa ser uma matriz segura do tipo `VARIANT` que contém os argumentos restantes. Para obter mais informações, confira [vararg](/windows/desktop/Midl/vararg) na *Referência de MIDL*.|
