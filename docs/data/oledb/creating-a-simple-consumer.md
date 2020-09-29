---
title: Criando um consumidor simples
ms.date: 05/09/2019
helpviewer_keywords:
- OLE DB consumers, creating
ms.assetid: ae32d657-72ea-4db8-9839-75cb5cff68ae
ms.openlocfilehash: 0b142a73f66a796f3e22bae0aeacb88dc018aea9
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91501860"
---
# <a name="creating-a-simple-consumer"></a>Criando um consumidor simples

::: moniker range="vs-2019"

O Assistente de Consumidor OLE DB da ATL não está disponível no Visual Studio 2019 e posteriores. Ainda é possível adicionar a funcionalidade manualmente. Saiba mais em [Criação de um consumidor sem usar um assistente](creating-a-consumer-without-using-a-wizard.md).

::: moniker-end

::: moniker range="<=vs-2017"

Use o **Assistente de Projeto da ATL** e o **Assistente de Consumidor OLE DB do ATL** para gerar um consumidor de modelos de OLE DB.

## <a name="to-create-a-console-application-for-an-ole-db-consumer"></a>Para criar um aplicativo de console para um consumidor de OLE DB

1. No menu **Arquivo**, clique em **Novo** e em **Projeto**.

   A caixa de diálogo **Novo Projeto** aparecerá.

1. No painel **Tipos de projeto**, clique na pasta **Instalado** > **Visual C++** > **Área de Trabalho do Windows** e clique no ícone **Assistente do Windows Desktop** no painel **Modelos**. Na caixa **Nome**, digite o nome do seu projeto, por exemplo, *MeusConsoles*.

1. Clique em **OK**.

   O assistente **Projeto do Windows Desktop** é exibido.

1. Na página **Configurações do Aplicativo**, selecione **Aplicativo de Console** e **Adicionar arquivos de cabeçalho comuns para ATL**.

1. Clique em **OK** para fechar o assistente e gerar o projeto.

Em seguida, use o **Assistente de Consumidor OLE DB do ATL** para adicionar um objeto de consumidor de OLE DB.

## <a name="to-create-a-consumer-with-the-atl-ole-db-consumer-wizard"></a>Criação de um consumidor com o Assistente de Consumidor OLE DB do ATL

1. Em **Gerenciador de soluções**, clique com o botão direito do mouse no `MyCons` projeto.

1. No menu de atalho, clique em **Adicionar**, depois em **Novo Item**.

   A caixa de diálogo **Adicionar Novo Item** aparecerá.

1. No painel **Categorias**, clique em **Instalado** > **Visual C++ ** > **ATL**, clique no ícone do **Consumidor de OLEDB da ATL** no painel **Modelos** e clique em **Adicionar**.

   O **Assistente de Consumidor OLEDB do ATL** é exibido.

1. Clique no botão **Fonte de Dados**.

   A caixa de diálogo **Propriedades de associação de dados** é exibida.

1. Na caixa de diálogo **Propriedades de associação de dados**, faça o seguinte:

   1. Na guia **Provedor**, especifique um provedor de OLE DB.

   1. Na guia **Conexão**, especifique as informações necessárias, como nome do servidor, ID de logon e senha para a fonte de dados e o banco de dados no servidor.

      > [!NOTE]
      > Há um problema de segurança com o recurso **Permitir salvamento de senha** da caixa de diálogo **Propriedades de associação de dados**. Em **inserir informações para fazer logon no servidor**, há dois botões de opção: **use a segurança integrada do Windows NT** e **use um nome de usuário e senha específicos**.

      > [!NOTE]
      > Se você selecionar **Usar nome de usuário e senha específicos**, terá a opção de salvar a senha (usando a caixa de seleção **Permitir salvamento de senha**); no entanto, essa opção não é segura. É recomendável selecionar **Usar Segurança Integrada do Windows NT**; essa opção usa o Windows NT para verificar sua identidade.

      > [!NOTE]
      > Se você não puder usar a segurança integrada do Windows NT, use um aplicativo de camada intermediária para solicitar a senha ao usuário ou armazenar a senha em um local com mecanismos de segurança para ajudar a protegê-la (em vez de fazer isso no código-fonte).

   1. Depois de selecionar o provedor e outras configurações, clique em **Testar Conexão** para verificar as seleções feitas nas páginas da caixa de diálogo anterior. Se a caixa **Resultados** informar `Test connection succeeded`, clique em **OK** para criar a associação de dados.

   A caixa de diálogo **Selecionar Objeto do Banco de Dados** é exibida.

1. Use o controle de árvore para selecionar uma tabela, exibição ou procedimento armazenado. Neste exemplo, selecione a tabela `Products` do banco de dados `Northwind`.

1. Clique em **OK**. Esse procedimento levará você de volta ao **Assistente de Consumidor OLE DB do ATL**.

1. O assistente preenche os nomes de `Class` e do **arquivo .h** com base no nome da tabela, exibição ou procedimento armazenado selecionado. Você pode editar esses nomes se quiser.

1. Desmarque a caixa de seleção **Atribuído** para que o assistente crie o código de consumidor usando [Classes de modelo OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md) em vez do padrão [Atributos de consumidor OLE DB](../../windows/attributes/ole-db-consumer-attributes.md).

1. Em **Tipo**, selecione **Comando**.

   O assistente cria um consumidor baseado em [CCommand](../../data/oledb/ccommand-class.md) se você seleciona **Comando** ou um consumidor baseado em [CTable](../../data/oledb/ctable-class.md) se você seleciona **Tabela**. A classe de tabela ou comando é nomeada de acordo com o objeto selecionado, mas você pode editar o nome.

1. Em **Suporte**, deixe as caixas **Alterar**, **Inserir** e **Excluir** desmarcadas.

   Selecione as caixas **Alterar**, **Inserir** e **Excluir** para dar suporte à alteração, inserção e exclusão de registros no conjunto de linhas. Saiba mais sobre a gravação de dados no armazenamento de dados em [Atualizar conjuntos de linhas](../../data/oledb/updating-rowsets.md).

1. Clique em **Concluir** para criar o consumidor.

O assistente gera uma classe de comando e uma classe de registro de usuário, conforme mostrado em [Classes geradas pelo Assistente do Consumidor](../../data/oledb/consumer-wizard-generated-classes.md). A classe de comando terá o nome que você inseriu na caixa `Class` no assistente (nesse caso, `CProducts`), e a classe de registro de usuário terá um nome no formato "*NomeClasse*Acessador" (nesse caso, `CProductsAccessor`).

> [!NOTE]
> O assistente coloca a seguinte linha em `Products.h`:

```cpp
#error Security Issue: The connection string may contain a password
```

> [!NOTE]
> Essa linha impede a compilação do aplicativo de consumidor e lembra você de verificar se há senhas codificadas na cadeia de conexão. Depois de verificar a cadeia de conexão, você pode remover essa linha de código.

::: moniker-end

## <a name="see-also"></a>Consulte também

[Criando um consumidor OLE DB usando um assistente](../../data/oledb/creating-an-ole-db-consumer-using-a-wizard.md)
