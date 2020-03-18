---
title: Assistente de consumidor ODBC MFC
ms.date: 08/29/2019
helpviewer_keywords:
- wizards [MFC]
ms.assetid: f64a890b-a252-4887-88a1-782a7cd4ff3d
ms.openlocfilehash: fd7e8df6692889914af2dd060ac42ed4ca3ebb8b
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79446431"
---
# <a name="mfc-odbc-consumer-wizard"></a>Assistente de consumidor ODBC MFC

::: moniker range="vs-2019"

Esse assistente não está disponível no Visual Studio 2019 e versões posteriores.

::: moniker-end

::: moniker range="<=vs-2017"

Este assistente configura uma classe de conjunto de registros ODBC e as associações de dados necessárias para acessar a fonte de dados especificada.

## <a name="uielement-list"></a>Lista de UIElement

- **Fonte de Dados**

  O botão **fonte de dados** permite que você configure a fonte de dados especificada usando o driver ODBC especificado. Para obter mais informações sobre arquivos de fonte de dados (DSN), consulte [fontes de dados de arquivo](/sql/odbc/reference/file-data-sources) no SDK do ODBC.

  A caixa de diálogo **selecionar fonte de dados** tem duas guias:

  - Guia **fonte de dados do arquivo** :

     A caixa **examinar** especifica o diretório no qual serão selecionados os arquivos a serem usados como fontes de dados. O padrão é \Program Files\Common Files\ODBC\Data sources. As fontes de dados de arquivo existentes (arquivos. DSN) aparecem na caixa de listagem principal. Você pode configurar as fontes de dados antecipadamente usando a guia **DSN de arquivo** no administrador de [fonte de dados ODBC](/sql/odbc/admin/odbc-data-source-administrator)ou criar novas usando essa caixa de diálogo.

     Para criar uma nova fonte de dados de arquivo nessa caixa de diálogo, clique em `New` para especificar um nome de DSN; a caixa de diálogo **criar nova fonte de dados** é exibida. Na caixa de diálogo **criar nova fonte de dados** , selecione um driver apropriado e clique em `Next`; clique em **procurar**e selecione o nome do arquivo a ser usado como uma fonte de dados (você precisa selecionar "todos os arquivos" para exibir arquivos não DSN, como arquivos. xls); clique em `Next`e em **concluir**. (Se você selecionou um arquivo não DSN, obterá uma caixa de diálogo específica do driver, como "configuração ODBC do Microsoft Excel", que converterá o arquivo em um DSN.)

     > [!NOTE]
     > Você também pode criar uma nova fonte de dados de arquivo com antecedência usando o administrador de fonte de dados ODBC. No menu **Iniciar** , selecione **configurações**, **painel de controle**, **Ferramentas administrativas**, **fontes de dados (ODBC)** e, em seguida, **administrador de fonte de dados ODBC**.

     A caixa **nome do DSN** permite que você especifique um nome para a fonte de dados de arquivo. Você deve garantir que o nome do DSN termine com a extensão de arquivo apropriada, como. xls para arquivos do Excel ou. mdb para arquivos do Access.

     Para obter mais informações sobre DSNs, consulte [arquivos de fontes de dados](/sql/odbc/reference/file-data-sources) no SDK do ODBC.

  - Guia **fonte de dados do computador** :

     Esta guia lista as fontes de dados do sistema e do usuário. As fontes de dados do usuário são específicas a um usuário neste computador. As fontes de dados do sistema podem ser usadas por todos os usuários neste computador ou em um serviço de todo o usuário. Consulte [fontes de dados do computador](/sql/odbc/reference/machine-data-sources) no SDK do ODBC

     Para obter mais informações sobre fontes de dados ODBC, consulte [fontes de dados](/sql/odbc/reference/data-sources) no SDK do ODBC.

  Clique em **OK** para concluir. A caixa de diálogo **Selecionar Objeto do Banco de Dados** é exibida. Nessa caixa de diálogo, selecione a tabela ou exibição que o consumidor usará. Observe que você pode selecionar várias exibições e tabelas mantendo a tecla Control enquanto clica nos itens. Clique em **OK** para concluir.

- **Class**

   O nome da classe de consumidor, com base por padrão no nome da fonte de dados de arquivo ou computador que você selecionou.

- **Arquivo .h**

   O nome do arquivo de cabeçalho de classe do consumidor, baseado por padrão no nome da fonte de dados do arquivo ou do computador que você selecionou.

- **Arquivo .cpp**

   O nome do arquivo de implementação de classe de consumidor, com base por padrão no nome da fonte de dados de arquivo ou computador que você selecionou.

- **Tipo**

   Especifica se o conjunto de registros é um dynaset (padrão) ou um instantâneo.

   - **Dynaset**: Especifica que o conjunto de registros é um dynaset. Um dynaset é o resultado de uma consulta que fornece uma exibição indexada dos dados do banco de dado consultado. Um dynaset armazena em cache apenas um índice integral para os dados originais e, portanto, oferece um lucro de desempenho em um instantâneo. O índice aponta diretamente para cada registro encontrado como resultado de uma consulta e indica se um registro foi removido. Você também tem acesso às informações atualizadas nos registros consultados. Esse é o padrão.

   - **Instantâneo**: Especifica que o conjunto de registros é um instantâneo. Um instantâneo é o resultado de uma consulta e é uma exibição de um banco de dados em um ponto no tempo. Todos os registros encontrados como resultado da consulta são armazenados em cache, portanto, você não vê nenhuma alteração nos registros originais.

- **Associar todas as colunas**

   Especifica se todas as colunas na tabela selecionada estão associadas. Se você selecionar essa caixa (padrão), todas as colunas serão associadas; Se você não selecionar essa caixa, nenhuma coluna será associada e você deverá associá-las manualmente na classe do conjunto de registros.

::: moniker-end

## <a name="see-also"></a>Consulte também

[Consumo ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md)<br/>
[Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)
