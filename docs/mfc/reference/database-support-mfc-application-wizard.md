---
title: Suporte ao banco de dados, Assistente de Aplicativo MFC
ms.date: 11/04/2016
f1_keywords:
- vc.appwiz.mfc.exe.database
helpviewer_keywords:
- MFC Application Wizard, database support
ms.assetid: 9ddf4558-fd41-4ac7-8d9b-c93d9c68ab59
ms.openlocfilehash: c13d56d2fee45e130aba81168188bec6d8828d51
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365889"
---
# <a name="database-support-mfc-application-wizard"></a>Suporte ao banco de dados, Assistente de Aplicativo MFC

Esta página fornece opções que permitem especificar o nível de suporte ao banco de dados (mais uma fonte de dados, se necessário) para o seu projeto.

- **Suporte ao banco de dados**

   Define o nível de suporte ao banco de dados para o seu projeto.

   |Opção|Descrição|
   |------------|-----------------|
   |**Nenhum**|Não fornece suporte ao banco de dados. Essa é a opção padrão.|
   |**Somente arquivos de cabeçalho**|Fornece o nível básico de suporte ao banco de dados para sua aplicação. Se você selecionar o suporte ao ODBC no **tipo Cliente,** o Assistente de Aplicativo Do MFC incluirá em seu projeto o arquivo de cabeçalho AFXDB. H. Ele adiciona bibliotecas de links, mas não cria nenhuma classe específica de banco de dados. Você pode criar conjuntos de registros mais tarde e usá-los para examinar e atualizar registros. Se você selecionar o suporte ao OLE DB no **tipo Cliente,** os seguintes arquivos de cabeçalho serão incluídos: ATLBASE. H AFXOLEDB. H ATLPLUS. H|
   |**Exibição de banco de dados sem suporte a arquivos**|Inclui arquivos de cabeçalho de banco de dados, bibliotecas de link, uma exibição de registro e um conjunto de registros. (Disponível apenas para aplicativos com a opção **de suporte à arquitetura document/exibição** selecionada na página Tipo de [aplicativo.)](../../mfc/reference/application-type-mfc-application-wizard.md) Essa opção inclui suporte a documentos, mas sem suporte à serialização. Se você optar por incluir uma exibição de banco de dados, você deve especificar a fonte dos dados.|
   |**Exibição de banco de dados com suporte a arquivos**|Inclui arquivos de cabeçalho de banco de dados, bibliotecas de link, uma exibição de registro e um conjunto de registros. (Disponível apenas para aplicativos com a opção **de suporte à arquitetura document/exibição** selecionada na página Tipo de **aplicativo.)** Essa opção suporta serialização de documentos, que você pode usar, por exemplo, para atualizar um arquivo de perfil de usuário. Os aplicativos de banco de dados normalmente operam por registro, em vez de por arquivo e, portanto, não precisam de serialização. No entanto, você pode ter um uso especial para serialização. Se você optar por incluir uma exibição de banco de dados, você deve especificar a fonte dos dados.|

   > [!NOTE]
   > Em **Suporte ao banco de dados,** se você selecionar **exibição de banco de dados sem suporte a arquivos** ou **exibição de banco de dados com suporte a arquivos,** a derivação da classe de exibição difere, dependendo da seleção **do tipo cliente,** da seguinte forma:

  - Se você selecionar **ODBC** no **tipo Cliente,** a classe de exibição do aplicativo deriva de [CRecordView](../../mfc/reference/crecordview-class.md). Esta classe está associada a uma classe derivada de [CRecordset,](../../mfc/reference/crecordset-class.md)que o MFC Application Wizard também cria para você. Esta opção oferece um aplicativo baseado em formulário no qual a exibição de registro é usada para exibir e atualizar registros através de seu conjunto de registros.

  - Se você selecionar **OLE DB** no **tipo Cliente,** a classe de exibição deriva do [COleDBRecordView](../../mfc/reference/coledbrecordview-class.md)e ela estiver associada a uma classe derivada de [CTable](../../data/oledb/ctable-class.md) ou [CCommand.](../../data/oledb/ccommand-class.md)

- **Tipo de cliente**

   Indica se seu projeto usa classes OLE DB ou ODBC.

   |Opção|Descrição|
   |------------|-----------------|
   |**OLE DB**|Quando essa opção é selecionada, clicar no botão **Origem de dados** invoca o assistente Propriedades de link de **dados** para ajudá-lo a criar uma conexão com uma fonte de dados OLE DB.|
   |**ODBCODBC**|Quando essa opção é selecionada, clicar no botão **Fonte de dados** invoca o assistente Select Data **Source** para ajudá-lo a criar uma conexão com uma fonte de dados ODBC.|

- **Fonte de dados**

   > [!NOTE]
   > O assistente de consumo ATL OLE DB e o assistente MFC ODBC Consumer não estão disponíveis no Visual Studio 2019 e posteriormente. Ainda é possível adicionar a funcionalidade manualmente. Saiba mais em [Criação de um consumidor sem usar um assistente](../../data/oledb/creating-a-consumer-without-using-a-wizard.md).

   Clique no botão **Origem de dados** para configurar uma fonte de dados usando o driver ou provedor e banco de dados especificados. Se você selecionou OLE DB na opção **Tipo Cliente,** este botão exibirá a caixa de diálogo **Propriedades do link** de dados. Se você selecionou o ODBC na opção **tipo Cliente,** este botão fornecerá a caixa de diálogo **Selecionar origem de dados.** Esta opção só está disponível se você optar por incluir uma exibição de banco de dados em seu aplicativo.

   |Opção|Descrição|
   |------------|-----------------|
   |**Propriedades do link de dados** (OLE DB)|Estabelece a fonte de dados especificada usando o provedor OLE DB especificado. Você deve especificar o provedor OLE DB, a localização dos dados, a fonte de dados, o ID de logon e (opcionalmente) uma senha. Para obter detalhes sobre esta caixa de diálogo, consulte **a fonte de dados** no ASSISTENTE DE CONSUMO [ATL OLE DB](../../atl/reference/atl-ole-db-consumer-wizard.md).|
   |**Selecionar fonte de dados** (ODBC)|Estabelece a fonte de dados especificada usando o driver ODBC especificado. Você deve selecionar um nome de origem de dados para escolher uma tabela para a fonte de dados. O assistente vincula todas as colunas da tabela `CRecordset`às variáveis de membro de uma classe derivada. Para obter detalhes sobre esta caixa de diálogo, consulte **a fonte de dados** no [MFC ODBC Consumer Wizard](../../mfc/reference/mfc-odbc-consumer-wizard.md).|

- **Gerar classe de banco de dados atribuída**

   Disponível apenas para cliente OLE DB. Especifica se as classes de banco de dados nos atributos de uso do projeto gerado.

- **Amarre todas as colunas**

   Disponível apenas para cliente ODBC. Especifica se todas as colunas da tabela selecionada estão vinculadas. Se você selecionar esta caixa, todas as colunas serão vinculadas; se você não selecionar esta caixa, nenhuma coluna está vinculada e você deve vinculá-las manualmente na classe recordset.

- **Tipo**

   Disponível apenas para cliente ODBC. Especifica se o conjunto de registros é um dynaset ou um snapshot, conforme descrito na tabela a seguir.

   |Opção|Descrição|
   |------------|-----------------|
   |**Dynaset**|Especifica que o conjunto de registros é um dynaset. Um dynaset é o resultado de uma consulta que fornece uma visão indexada nos dados do banco de dados consultados. Um dynaset armazena apenas um índice integral para os dados originais e, portanto, oferece um ganho de desempenho sobre um snapshot. O índice aponta diretamente para cada registro encontrado como resultado de uma consulta e indica se um registro é removido. Você também tem acesso a informações atualizadas nos registros consultados.|
   |**Instantâneo**|Especifica que o conjunto de registros é um instantâneo. Um instantâneo é o resultado de uma consulta e é uma exibição em um banco de dados em um ponto no tempo. Todos os registros encontrados como resultado da consulta são armazenados em cache, portanto você não vê nenhuma alteração nos registros originais.|

## <a name="see-also"></a>Confira também

[Assistente de aplicativo do MFC](../../mfc/reference/mfc-application-wizard.md)
