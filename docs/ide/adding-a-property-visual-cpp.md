---
title: Adicionar uma propriedade
ms.date: 11/09/2018
f1_keywords:
- vc.codewiz.prop.overview
- vc.codewiz.prop.idlattributes
helpviewer_keywords:
- interfaces, adding properties
- properties [C++], adding to interfaces
- names, add property wizard
- IDL attributes, add property wizard
- stock properties, about stock properties
- stock properties
ms.assetid: 37bd4db7-efd3-4faa-87ad-64902ed16a36
ms.openlocfilehash: 06940bb72f9113e0a8148e15418504b35fc95099
ms.sourcegitcommit: b032daf81cb5fdb1f5a988277ee30201441c4945
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/15/2018
ms.locfileid: "51694251"
---
# <a name="add-a-property"></a>Adicionar uma propriedade

Use o [assistente de adição de propriedade](#names-add-property-wizard) para adicionar um método a uma interface no projeto.

**Para adicionar uma propriedade ao objeto:**

1. Em [Modo de Exibição de Classe](/visualstudio/ide/viewing-the-structure-of-code), clique com o botão direito do mouse no nome da interface à qual você deseja adicionar a propriedade.

   > [!NOTE]
   > Adicione também propriedades a dispinterfaces, que estarão aninhadas no nó da biblioteca, a menos que o projeto esteja atribuído.

1. No menu de atalho, escolha **Adicionar** e, depois, **Adicionar propriedade**.

1. No [assistente de adição de propriedade](#names-add-property-wizard), forneça as informações para criar a propriedade.

1. Especifique as configurações de linguagem IDL para a propriedade na página [Atributos IDL](#idl-attributes-add-property-wizard) do assistente.

1. Selecione **Concluir** para adicionar a propriedade.

Os métodos `Get` e `Put` da propriedade são exibidos como dois ícones em Modo de Exibição de Classe, abaixo da interface na qual ela está definida. Clique duas vezes em um dos ícones para exibir a declaração de propriedade no arquivo .idl.

- Para interfaces da ATL, as funções `Get` e `Put` são adicionadas ao arquivo .cpp e as referências a essas funções são adicionadas ao arquivo .h.

- Para dispinterfaces MFC, se você selecionar **Variável de membro** como o tipo de implementação, um método e uma variável serão adicionados à classe que o implementa. Se você selecionar **métodos Get/Set** como o tipo de implementação, os dois métodos serão adicionados à classe que o implementa.

## <a name="in-this-section"></a>Nesta seção

- [Nomes, assistente de adição de propriedade](#names-add-property-wizard)
- [Atributos IDL, assistente de adição de propriedade](#idl-attributes-add-property-wizard)
- [Propriedades de estoque](#stock-properties)

## <a name="names-add-property-wizard"></a>Nomes, assistente de adição de propriedade

Use este assistente para adicionar uma propriedade a uma interface.

- **Tipo de propriedade**

  Define o tipo de propriedade que está sendo adicionado. Para dispinterfaces MFC, forneça seu próprio tipo ou selecione um na lista predefinida. Se você fornecer uma implementação de estoque de uma propriedade, **Tipo de propriedade** será definido como o tipo de estoque e não ficará disponível para alteração.

- **Nome da propriedade**

  Define o nome da propriedade. Para dispinterfaces MFC associadas a controles ActiveX, forneça seu próprio nome ou selecione um nome de propriedade de estoque na lista predefinida. Se você fornecer seu próprio nome de propriedade, o tipo de implementação **Estoque** não ficará disponível. Confira [propriedades de estoque](#stock-properties) para obter uma descrição das propriedades na lista.

  |Tipo de interface|Descrição|
  |--------------------|-----------------|
  |Interface dupla ATL, interface personalizada e interface personalizada local|Forneça um nome de propriedade.|
  |Dispinterface MFC, dispinterface MFC do controle ActiveX|Forneça um nome de propriedade ou selecione uma propriedade de estoque na lista. Se você selecionar uma propriedade na lista, o valor apropriado será exibido na caixa **Tipo de propriedade**. Você pode alterar esse tipo, dependendo da seleção em **Tipo de implementação**.|

- **Tipo de retorno**

  Somente interfaces ATL. Define o tipo de retorno para a propriedade. Para interfaces duplas, `HRESULT` sempre é o tipo de retorno, e essa caixa não fica disponível. Para interfaces personalizadas, selecione um tipo de retorno na lista. `HRESULT` ainda é recomendável, porque fornece uma maneira padrão de retornar erros.

- **Nome da variável**

  Somente dispinterfaces MFC. Disponível somente se você especificar **Variável de membro** em **Tipo de implementação**. Define o nome da variável de membro ao qual a propriedade está associada. Por padrão, o nome da variável é definido como `m_`*PropertyName*. É possível editar esse nome.

- **Função de notificação**

  Somente dispinterfaces MFC. Disponível somente se você especificar **Variável de membro** em **Tipo de implementação**. Define o nome da função de notificação chamada se a propriedade é alterada. Por padrão, o nome da função de notificação é definido como `On`*PropertyName*`Changed`. É possível editar esse nome.

- **Função Get**

  Para dispinterfaces MFC. Disponível somente se você especificar **Métodos Get/Set** em **Tipo de implementação**. Define o nome da função para obter a propriedade. Por padrão, o nome da função `Get` é definido como `Get`*PropertyName*. É possível editar esse nome. Se você excluir o nome, a função [GetNotSupported](../mfc/reference/colecontrol-class.md#getnotsupported) será inserida no mapa de expedição da interface. A função `Get`*PropertyName* especifica a propriedade como legível.

- **Função Set**

  Somente dispinterfaces MFC. Disponível somente se você especificar **Métodos Get/Set** em **Tipo de implementação**. Define o nome da função para definir a propriedade. Por padrão, o nome da função `Set` é definido como `Set`*PropertyName*. É possível editar esse nome. Se você excluir o nome, a função [SetNotSupported](../mfc/reference/colecontrol-class.md#setnotsupported) será inserida no mapa de expedição da interface. A função `Set`*PropertyName* especifica a propriedade como gravável.

- **Tipo de implementação**

  Somente dispinterfaces MFC. Especifica como implementar a propriedade que está sendo adicionada.

  |Tipo de implementação|Descrição|
  |-------------------------|-----------------|
  |**Estoque**|Especifica uma implementação de estoque para a propriedade selecionada em **Nome da propriedade**. O padrão. Para obter mais informações, confira [Propriedades de estoque](#stock-properties).<br /><br /> Se você especificar **Estoque**, as opções **Tipo de propriedade**, **Tipo de parâmetro** e **Nome do parâmetro** ficarão esmaecidas.|
  |**Variável de membro**|Especifica que a propriedade é adicionada como uma variável de membro. Adicione propriedades personalizadas ou a maioria das propriedades de estoque como variáveis de membro. Não é possível especificar **Variável de membro** para as propriedades `Caption`, `hWnd` e `Text`.<br /><br /> Fornece nomes padrão em **Nome da variável** e **Função de notificação**. É possível editar esse nome.|
  |**Métodos Get/Set**|Especifica que a propriedade é adicionada como as funções `Get`*PropertyName* e `Set`*PropertyName*, por padrão. Esses nomes são exibidos em **Função Get** e **Função Set**.<br /><br /> Altere o **Tipo de propriedade** padrão, que passa um valor para a função Get. Especifique parâmetros para as funções `Get` e `Set`.|

- **Função Get**

  Para interfaces ATL. Define a propriedade como legível; ou seja, cria o método `Get` para recuperar essa propriedade do objeto. Selecione **Get**, **Put** ou ambos.

- **Função Put**

  Somente interfaces ATL. Define a propriedade gravável; ou seja, ela cria o método `Put` para definição, ou "colocação", dessa propriedade do objeto. Selecione **Get**, **Put** ou ambos. Se você selecionar essa opção, poderá escolher uma das duas seguintes maneiras de implementar o método:

  |Opção|Descrição|
  |------------|-----------------|
  |**PropPut**|A função [PropPut](../windows/propput.md) retorna uma cópia do objeto. Esse é o padrão e a maneira mais comum para tornar a propriedade gravável.|
  |**PropPutRef**|A função [PropPutRef](../windows/propputref.md) retorna uma referência ao objeto, em vez de retornar a cópia do objeto em si. Considere o uso dessa opção para objetos, como structs ou matrizes grandes, que podem ter a sobrecarga de inicialização.|

- **Atributos de parâmetro**

  Somente interfaces ATL. Define se o parâmetro especificado pelo **Nome do parâmetro** é `in`, `out`, ambos ou nenhum.

  |Opção|Descrição|
  |------------|-----------------|
  |`in`|Indica que o parâmetro é passado do procedimento de chamada para o procedimento chamado.|
  |`out`|Indica que o parâmetro de ponteiro é retornado do procedimento chamado para o procedimento de chamada (do servidor para o cliente).|

- **Tipo de parâmetro**

  Define o tipo de dados do parâmetro. Selecione o tipo na lista.

- **Nome do parâmetro**

  Define o nome de um parâmetro que está adicionado à propriedade se a propriedade tiver parâmetros. Depois de selecionar **Adicionar**, o nome do parâmetro é exibido em **Lista de parâmetros**.

- **Lista de parâmetros**

  Exibe a lista de atributos a serem adicionadas à propriedade. Cada item na lista consiste no nome de parâmetro, no tipo de parâmetro e nos atributos. Use **Adicionar** e **Remover** para atualizar a lista.

- **Adicionar**

  Adiciona o parâmetro especificado em **Nome do parâmetro** e em **Tipo de parâmetro** à **Lista de parâmetros**. Selecione **Adicionar** para adicionar um parâmetro à lista.

- **Removerr**

  Remove o parâmetro selecionado em **Lista de parâmetros**.

- **Propriedade padrão**

  Somente dispinterface MFC. Define essa propriedade como o padrão para a interface. Uma interface pode ter apenas uma propriedade padrão; depois de especificar a propriedade padrão, para as outras propriedades adicionadas à interface, essa caixa não fica disponível.

## <a name="idl-attributes-add-property-wizard"></a>Atributos IDL, assistente de adição de propriedade

Use esta página do Assistente de Adição de Propriedade para especificar as configurações de linguagem IDL para a propriedade.

- `id`

  Define a ID numérica que identifica a propriedade. Essa opção não está disponível para propriedades de interfaces personalizadas. Confira [id](/windows/desktop/Midl/id) na *Referência de MIDL*.

- `helpcontext`

  Especifica uma ID de contexto que permite ao usuário exibir informações sobre essa propriedade no arquivo de Ajuda. Confira [helpcontext](/windows/desktop/Midl/helpcontext) na *Referência de MIDL*.

- `helpstring`

  Especifica uma cadeia de caracteres que é usada para descrever o elemento ao qual ela se aplica. Por padrão, é definido como o nome `property`&nbsp;*Propriedade&nbsp;*. Confira [helpstring](/windows/desktop/Midl/helpstring) na *Referência de MIDL*.

### <a name="other-options"></a>Outras opções

Nem todas as opções estão disponíveis para todos os tipos de propriedade.

|Opção|Descrição|
|------------|-----------------|
|`bindable`|Indica que a propriedade dá suporte à associação de dados. Confira [bindable](/windows/desktop/Midl/bindable) na *Referência de MIDL*. Para a implementação de estoque da propriedade, essa opção está definida por padrão e não pode ser alterada.|
|`defaultbind`|Indica que essa única propriedade associável melhor representa o objeto. Confira [defaultbind](/windows/desktop/Midl/defaultbind) na *Referência de MIDL*.|
|`displaybind`|Indica que essa propriedade deve ser exibida para o usuário como associável. Confira [displaybind](/windows/desktop/Midl/displaybind) na *Referência de MIDL*.|
|`immediatebind`|Indica que o banco de dados será notificado imediatamente de todas as alterações nessa propriedade de um objeto associado a dados. Confira [immediatebind](/windows/desktop/Midl/immediatebind) na *Referência de MIDL*.|
|`defaultcollelem`|Indica que a propriedade é uma função de acessador para um elemento da coleção padrão. Confira [defaultcollelem](/windows/desktop/Midl/defaultcollelem) na *Referência de MIDL*.|
|`nonbrowsable`|Marca um membro de interface ou de dispinterface que não deve ser exibido em um navegador de propriedades. Confira [nonbrowsable](/windows/desktop/Midl/nonbrowsable) na *Referência de MIDL*.|
|`requestedit`|Indica que a propriedade dá suporte à notificação `OnRequestEdit`. Confira [requestedit](/windows/desktop/Midl/requestedit) na *Referência de MIDL*. Para a implementação de estoque da propriedade, essa opção está definida por padrão e não pode ser alterada.|
|`source`|Indica que um membro da propriedade é uma origem de eventos. Confira [source](/windows/desktop/Midl/source) na *Referência de MIDL*.|
|`hidden`|Indica que a propriedade existe, mas que não deveria ser exibida em um navegador orientado ao usuário. Confira [hidden](/windows/desktop/Midl/hidden) na *Referência de MIDL*.|
|`restricted`|Especifica que a propriedade não pode ser chamada arbitrariamente. Confira [restricted](/windows/desktop/Midl/restricted) na *Referência de MIDL*.|
|`local`|Especifica para o compilador MIDL que a propriedade não é remota. Confira [local](/windows/desktop/Midl/local) na *Referência de MIDL*.|

## <a name="stock-properties"></a>Propriedades de estoque

Caso esteja adicionando uma propriedade a uma dispinterface MFC usando o [assistente de adição de propriedade](#idl-attributes-add-property-wizard), escolha uma propriedade de estoque na lista **Nome da propriedade** da página [Nomes](../ide/names-add-property-wizard.md) do assistente. Estas são as seguintes propriedades:

|Property name|Descrição|
|-------------------|-----------------|
|`Appearance`|Retorna ou define um valor que determina a aparência do controle. A propriedade `Appearance` do controle pode incluir ou omitir efeitos de exibição tridimensionais. Essa propriedade é uma propriedade de leitura/gravação de ambiente.|
|`BackColor`|Retorna ou define a propriedade `BackColor` de ambiente do controle para uma cor da paleta (RGB) ou uma cor predefinida do sistema. Por padrão, seu valor corresponde à cor de primeiro plano do contêiner do controle. Essa propriedade é uma propriedade de leitura/gravação de ambiente.|
|`BorderStyle`|Retorna ou define o estilo da borda de um controle. Essa propriedade é uma propriedade de leitura/gravação.|
|`Caption`|Retorna ou define a propriedade `Caption` do controle. A legenda é o título da janela. `Caption` não tem nenhum tipo de implementação **Variável de membro**.|
|`Enabled`|Retorna ou define a propriedade `Enabled` do controle. Um controle habilitado pode responder aos eventos gerados pelo usuário.|
|`Font`|Retorna ou define a fonte de ambiente do controle. Nulo se o controle não tem nenhuma fonte.|
|`ForeColor`|Retorna ou define a propriedade `ForeColor` de ambiente do controle.|
|`hWnd`|Retorna ou define a propriedade `hWnd` do controle. `hWnd` não tem nenhum tipo de implementação **Variável de membro**.|
|`ReadyState`|Retorna ou define a propriedade `ReadyState` do controle. Um controle pode estar nos seguintes estados: inicialização cancelada, inicializado, carregando, interativo ou completo. Para obter mais informações, confira [READYSTATE](https://msdn.microsoft.com/library/aa768362.aspx) no *SDK da Internet*.|
|`Text`|Retorna ou define o texto contido em um controle. `Text` não tem nenhum tipo de implementação **Variável de membro**.|
