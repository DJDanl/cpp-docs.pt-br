---
title: Assistente de consumidor ODBC MFC
ms.date: 05/09/2019
helpviewer_keywords:
- wizards [MFC]
ms.assetid: f64a890b-a252-4887-88a1-782a7cd4ff3d
ms.openlocfilehash: 2e8741677031ff9b12989d75243a13550d74b608
ms.sourcegitcommit: fc1de63a39f7fcbfe2234e3f372b5e1c6a286087
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/15/2019
ms.locfileid: "65707379"
---
# <a name="mfc-odbc-consumer-wizard"></a>Assistente de consumidor ODBC MFC

::: moniker range="vs-2019"

Este assistente não está disponível no Visual Studio de 2019 e posterior.

::: moniker-end

::: moniker range="<=vs-2017"

Este assistente configura uma classe de conjunto de registros ODBC e as associações de dados necessário para acessar a fonte de dados especificado.

## <a name="uielement-list"></a>Lista UIElement

- **Fonte de dados**

  O **fonte de dados** botão permite que você defina a fonte de dados especificado usando o driver ODBC especificado. Para obter mais informações sobre arquivos de fonte de dados (DSN), consulte [fontes de dados de arquivo](/sql/odbc/reference/file-data-sources) no SDK do ODBC.

  O **Selecionar fonte de dados** caixa de diálogo tem duas guias:

  - **Fonte de dados do arquivo** guia:

     O **xaminar** caixa especifica o diretório no qual selecionar arquivos a serem usados como fontes de dados. O padrão é \Program Comuns\odbc\fontes de dados. As fontes de dados de arquivo existente (arquivos. DSN) são exibidos na caixa de listagem principal. Você pode definir as fontes de dados previamente usando o **DSN de arquivo** guia o [administrador de fonte de dados ODBC](/sql/odbc/admin/odbc-data-source-administrator), ou crie novos objetos usando essa caixa de diálogo.

     Para criar uma nova fonte de dados de arquivo nessa caixa de diálogo, clique em `New` para especificar um nome DSN; a **criar nova fonte de dados** caixa de diálogo é exibida. No **criar nova fonte de dados** diálogo caixa, selecione um driver apropriado e clique em `Next`; clique em **procurar**e selecione o nome do arquivo a ser usado como uma fonte de dados (você precisa selecionar "Todos os arquivos" para modo de exibição não DSN arquivos, como arquivos. xls); Clique em `Next`e, em seguida, clique em **concluir**. (Se você tiver selecionado um arquivo não DSN, você obterá uma caixa de diálogo de específicos do driver, como "Configurar ODBC para Microsoft Excel," que converterá o arquivo em um DSN.)

     > [!NOTE]
     > Você também pode criar uma nova fonte de dados de arquivo antes de usar o administrador de fonte de dados ODBC. Dos **inicie** menu, selecione **configurações**, **painel de controle**, **ferramentas administrativas**, **fontes de dados (ODBC)** e então **administrador de fonte de dados ODBC**.

     O **nome DSN** caixa permite que você especifique um nome para a fonte de dados de arquivo. Você deve garantir que o nome DSN termina com a extensão de arquivo apropriado, como. xls para arquivos do Excel ou. mdb para acessar os arquivos.

     Para obter mais informações sobre DSNs, consulte [fontes de dados de arquivo](/sql/odbc/reference/file-data-sources) no SDK do ODBC.

  - **Fonte de dados de máquina** guia:

     Essa guia lista de fontes de dados de usuário e do sistema. Fontes de dados do usuário são específicas a um usuário neste computador. Fontes de dados do sistema podem ser usadas por todos os usuários neste computador ou em um serviço de todo o sistema. Ver [fontes de dados de máquina](/sql/odbc/reference/machine-data-sources) no SDK do ODBC

     Para obter mais informações sobre fontes de dados ODBC, consulte [fontes de dados](/sql/odbc/reference/data-sources) no SDK do ODBC.

  Clique em **Okey** para concluir. O **Selecionar objeto de banco de dados** caixa de diálogo é exibida. Nessa caixa de diálogo, selecione a tabela ou exibição que o consumidor usará. Observe que você pode selecionar várias tabelas e exibições mantendo a tecla control ao clicar nos itens. Clique em **Okey** para concluir.

- **Class**

      The name of the consumer class, based by default on the name of the file or machine data source that you selected.

- **Arquivo .h**

   O nome do arquivo de cabeçalho de classe consumidor, com base em por padrão no nome da máquina ou arquivo de fonte de dados que você selecionou.

- **Arquivo .cpp**

   O nome do arquivo de implementação de classe consumidor, com base em por padrão no nome da máquina ou arquivo de fonte de dados que você selecionou.

- **Tipo**

   Especifica se o conjunto de registros é dynaset (padrão) ou um instantâneo.

   - **Dynaset**: Especifica que o conjunto de registros é dynaset. Dynaset é o resultado de uma consulta que fornece uma exibição indexada em dados do banco de dados consultados. Dynaset armazena em cache apenas um índice integral para os dados originais e, assim, oferece um desempenho obter ao longo de um instantâneo. Os pontos de índice diretamente para cada registro encontrado como resultado de uma consulta e indica se um registro é removido. Você também tem acesso a informações atualizadas nos registros de consultado. Esse é o padrão.

   - **Instantâneo**: Especifica que o conjunto de registros é um instantâneo. Um instantâneo é o resultado de uma consulta e é um modo de exibição em um banco de dados em um ponto no tempo. Todos os registros encontrados em virtude da consulta são armazenados em cache, portanto, você não vir quaisquer alterações nos registros originais.

- **Associar todas as colunas**

   Especifica se todas as colunas na tabela selecionada estão vinculadas. Se você selecionar essa caixa (padrão), todas as colunas são associadas; Se você não selecionar essa caixa, não há colunas são associadas e você deve associá-las manualmente na classe de conjunto de registros.

::: moniker-end

## <a name="see-also"></a>Consulte também

[Consumidor ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md)<br/>
[Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)
