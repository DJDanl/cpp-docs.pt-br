---
title: Suporte ao banco de dados, Assistente de Aplicativo MFC
ms.date: 11/04/2016
f1_keywords:
- vc.appwiz.mfc.exe.database
helpviewer_keywords:
- MFC Application Wizard, database support
ms.assetid: 9ddf4558-fd41-4ac7-8d9b-c93d9c68ab59
ms.openlocfilehash: 94ed75ffd59294d5beb076ef4d66e57ef763f10e
ms.sourcegitcommit: 00e26915924869cd7eb3c971a7d0604388abd316
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/10/2019
ms.locfileid: "65525463"
---
# <a name="database-support-mfc-application-wizard"></a>Suporte ao banco de dados, Assistente de Aplicativo MFC

Esta página fornece opções que permitem que você especifique o nível de banco de dados de suporte (além de uma fonte de dados, se necessário) para seu projeto.

- **Suporte de banco de dados**

   Define o nível de suporte de banco de dados para seu projeto.

   |Opção|Descrição|
   |------------|-----------------|
   |**Nenhum**|Não fornece suporte de nenhum banco de dados. Esta é a opção padrão.|
   |**Somente os arquivos de cabeçalho**|Fornece o nível básico de suporte do banco de dados para seu aplicativo. Se você selecionar o suporte a ODBC sob **tipo de cliente**, o Assistente de aplicativo do MFC inclui em seu projeto, o arquivo de cabeçalho AFXDB. H. Ele adiciona bibliotecas de vínculo, mas não cria quaisquer classes específicas de banco de dados. Você pode criar conjuntos de registros mais tarde e usá-los para examinar e atualizar registros. Se você selecionar o suporte de OLE DB sob **tipo de cliente**, os arquivos de cabeçalho a seguir estão incluídos: ATLBASE.H AFXOLEDB.H ATLPLUS.H|
   |**Exibição de banco de dados sem suporte para arquivo**|Inclui arquivos de cabeçalho do banco de dados, bibliotecas de vínculo, uma exibição de registro e um conjunto de registros. (Disponível somente para aplicativos com o **suporte de arquitetura de documento/exibição** opção selecionada na [tipo de aplicativo](../../mfc/reference/application-type-mfc-application-wizard.md) página.) Essa opção inclui suporte a documentos, mas não há suporte de serialização. Se você optar por incluir uma exibição de banco de dados, você deve especificar a fonte de dados.|
   |**Exibição de banco de dados com suporte para arquivo**|Inclui arquivos de cabeçalho do banco de dados, bibliotecas de vínculo, uma exibição de registro e um conjunto de registros. (Disponível somente para aplicativos com o **suporte de arquitetura de documento/exibição** opção selecionada na **tipo de aplicativo** página.) Essa opção dá suporte à serialização do documento, o que você pode usar, por exemplo, para atualizar um arquivo de perfil do usuário. Aplicativos de banco de dados geralmente operam em uma base por registro, em vez de por arquivo base e, portanto, não precisa de serialização. No entanto, você pode ter um uso especial para serialização. Se você optar por incluir uma exibição de banco de dados, você deve especificar a fonte de dados.|

   > [!NOTE]
   > Sob **dar suporte a banco de dados**, se você selecionar uma **modo de exibição sem suporte a arquivos de banco de dados** ou **exibição com suporte a arquivos de banco de dados**, a derivação de classe de exibição for diferente, dependendo do em seu **tipo de cliente** seleção, da seguinte maneira:

   - Se você selecionar **ODBC** sob **tipo de cliente**, em seguida, deriva de classe de exibição do aplicativo [CRecordView](../../mfc/reference/crecordview-class.md). Essa classe é associada com um [CRecordset](../../mfc/reference/crecordset-class.md)-derivado da classe, que o Assistente de aplicativo do MFC também cria para você. Essa opção fornece um aplicativo baseado em formulário no qual o modo de exibição do registro é usado para exibir e atualizar registros por meio de seu conjunto de registros.

   - Se você selecionar **OLE DB** sob **tipo de cliente**, em seguida, a classe de exibição deriva [COleDBRecordView](../../mfc/reference/coledbrecordview-class.md), e ele está associado um [CTable](../../data/oledb/ctable-class.md) ou [CCommand](../../data/oledb/ccommand-class.md)-classe derivada.

- **Tipo de cliente**

   Indica se o seu projeto usa classes do OLE DB ou ODBC.

   |Opção|Descrição|
   |------------|-----------------|
   |**OLE DB**|Quando essa opção é selecionada, clicar na **fonte de dados** botão invoca o **propriedades de vínculo de dados** Assistente para ajudá-lo a criar uma conexão a uma fonte de dados OLE DB.|
   |**ODBC**|Quando essa opção é selecionada, clicar na **fonte de dados** botão invoca o **Selecionar fonte de dados** Assistente para ajudá-lo a criar uma conexão a uma fonte de dados ODBC.|

- **Fonte de dados**

   > [!NOTE]
   > O Assistente de ATL OLE DB consumidor e o Assistente de consumidor de ODBC do MFC não estão disponíveis no Visual Studio de 2019 e posterior. Você ainda pode adicionar manualmente a funcionalidade. Para obter mais informações, consulte [criando um consumidor sem usar um assistente](../../data/oledb/creating-a-consumer-without-using-a-wizard.md).

   Clique o **fonte de dados** botão para configurar uma fonte de dados usando o driver especificado ou o provedor e o banco de dados. Se você tiver selecionado o OLE DB na **tipo de cliente** opção, esse botão exibe a **propriedades de vínculo de dados** caixa de diálogo. Se você tiver selecionado o ODBC na **tipo de cliente** opção, esse botão fornece a **Selecionar fonte de dados** caixa de diálogo. Essa opção está disponível somente se você optar por incluir um modo de exibição de banco de dados em seu aplicativo.

   |Opção|Descrição|
   |------------|-----------------|
   |**Propriedades de vínculo de dados** (OLE DB)|Estabelece a fonte de dados especificado usando o provedor OLE DB especificado. Você deve especificar o provedor OLE DB, o local dos dados, a fonte de dados, ID de logon e (opcionalmente) uma senha. Para obter detalhes sobre essa caixa de diálogo, consulte **fonte de dados** na [ATL OLE DB Assistente de consumidor](../../atl/reference/atl-ole-db-consumer-wizard.md).|
   |**Selecionar fonte de dados** (ODBC)|Estabelece a fonte de dados especificado usando o driver ODBC especificado. Você deve selecionar um nome de fonte de dados para escolher uma tabela da fonte de dados. O assistente é associado a todas as colunas da tabela para as variáveis de membro de um `CRecordset`-classe derivada. Para obter detalhes sobre essa caixa de diálogo, consulte **fonte de dados** na [Assistente de consumidor ODBC MFC](../../mfc/reference/mfc-odbc-consumer-wizard.md).|

- **Gerar a classe de banco de dados atribuído**

   Disponível para somente o cliente do OLE DB. Especifica se as classes de banco de dados no projeto gerado usam atributos.

- **Associar todas as colunas**

   Disponível para somente o cliente do ODBC. Especifica se todas as colunas na tabela selecionada estão vinculadas. Se você selecionar esta caixa, todas as colunas são associadas; Se você não selecionar essa caixa, não há colunas são associadas e você deve associá-las manualmente na classe de conjunto de registros.

- **Tipo**

   Disponível para somente o cliente do ODBC. Especifica se o conjunto de registros é um dynaset ou um instantâneo, conforme descrito na tabela a seguir.

   |Opção|Descrição|
   |------------|-----------------|
   |**Dynaset**|Especifica que o conjunto de registros é dynaset. Dynaset é o resultado de uma consulta que fornece uma exibição indexada em dados do banco de dados consultados. Dynaset armazena em cache apenas um índice integral para os dados originais e, assim, oferece um desempenho obter ao longo de um instantâneo. Os pontos de índice diretamente para cada registro encontrado como resultado de uma consulta e indica se um registro é removido. Você também tem acesso a informações atualizadas nos registros de consultado.|
   |**Instantâneo**|Especifica que o conjunto de registros é um instantâneo. Um instantâneo é o resultado de uma consulta e é um modo de exibição em um banco de dados em um ponto no tempo. Todos os registros encontrados em virtude da consulta são armazenados em cache, portanto, você não vir quaisquer alterações nos registros originais.|

## <a name="see-also"></a>Consulte também

[Assistente de aplicativo do MFC](../../mfc/reference/mfc-application-wizard.md)
