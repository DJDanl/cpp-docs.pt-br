---
title: Assistente de consumidor ODBC MFC
ms.date: 08/29/2019
helpviewer_keywords:
- wizards [MFC]
ms.assetid: f64a890b-a252-4887-88a1-782a7cd4ff3d
ms.openlocfilehash: 45087434c0093f99383096761d58a8029c9d5009
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373019"
---
# <a name="mfc-odbc-consumer-wizard"></a>Assistente de consumidor ODBC MFC

::: moniker range="vs-2019"

Esse assistente não está disponível no Visual Studio 2019 e versões posteriores.

::: moniker-end

::: moniker range="<=vs-2017"

Este assistente configura uma classe de conjunto de registros ODBC e as vinculações de dados necessárias para acessar a fonte de dados especificada.

## <a name="uielement-list"></a>Lista de elementos de interface do usuário

- **Fonte de dados**

  O botão **Fonte de dados** permite configurar a fonte de dados especificada usando o driver ODBC especificado. Para obter mais informações sobre arquivos de origem de dados (DSN), consulte [File Data Sources](/sql/odbc/reference/file-data-sources) no ODBC SDK.

  A caixa de diálogo **Selecionar origem de dados** tem duas guias:

  - **Guia Origem de dados** do arquivo:

     A **caixa Olhar na** caixa especifica o diretório no qual selecionar arquivos a serem usados como fontes de dados. O padrão é \Arquivos do programa\Arquivos comuns\ODBC\Fontes de dados. As fontes de dados de arquivo existentes (arquivos.dsn) aparecem na caixa principal da lista. Você pode configurar as fontes de dados com antecedência usando a guia **Arquivo DSN** no [Administrador de Origem de Dados do ODBC](/sql/odbc/admin/odbc-data-source-administrator)ou criar novas usando essa caixa de diálogo.

     Para criar uma nova fonte de dados `New` de arquivo a partir desta caixa de diálogo, clique para especificar um nome DSN; a caixa de diálogo **Criar nova fonte de dados** é exibida. Na caixa de diálogo Criar nova fonte de `Next` **dados,** selecione um driver apropriado e clique em ; clique **em Procurar**e selecione o nome do arquivo a ser usado como fonte de dados (você tem que selecionar "Todos os arquivos" para visualizar arquivos não-DSN, como arquivos .xls); clique `Next`e clique em **Terminar**. (Se você selecionou um arquivo não-DSN, você receberá uma caixa de diálogo específica para o driver, como "ODBC Microsoft Excel Setup", que converterá o arquivo em um DSN.)

     > [!NOTE]
     > Você também pode criar uma nova fonte de dados de arquivo de antemão usando o Administrador de Origem de Dados oDBC. No menu **Iniciar,** selecione Configurações, **Painel de Controle,** **Ferramentas Administrativas,** Fontes de Dados **(ODBC)** e, em seguida, **Administrador de Fonte de Dados oDBC**. **Settings**

     A caixa **DSN Name** permite especificar um nome para a fonte de dados do arquivo. Você deve garantir que o nome DSN termine com a extensão de arquivo apropriada, como .xls para arquivos Excel ou .mdb para arquivos access.

     Para obter mais informações sobre DSNs, consulte [File Data Sources](/sql/odbc/reference/file-data-sources) no ODBC SDK.

  - **Guia Fonte de dados** da máquina:

     Esta guia lista as fontes do sistema e do User DATA. As fontes de dados do usuário são específicas para um usuário nesta máquina. As fontes de dados do sistema podem ser usadas por todos os usuários nesta máquina ou em um serviço em todo o sistema. Ver [fontes de dados da máquina](/sql/odbc/reference/machine-data-sources) no ODBC SDK

     Para obter mais informações sobre as fontes de dados da ODBC, consulte [Fontes de dados](/sql/odbc/reference/data-sources) no SDK ODBC.

  Clique em **OK** para concluir. A caixa de diálogo **Selecionar Objeto do Banco de Dados** é exibida. Nesta caixa de diálogo, selecione a tabela ou veja que o consumidor usará. Observe que você pode selecionar vários pontos de exibição e tabelas segurando a tecla de controle ao clicar nos itens. Clique em **OK** para concluir.

- **Classe**

   O nome da classe de consumo, baseado por padrão no nome do arquivo ou fonte de dados da máquina que você selecionou.

- **Arquivo .h**

   O nome do arquivo de cabeçalho da classe de consumo, baseado por padrão no nome do arquivo ou fonte de dados da máquina que você selecionou.

- **Arquivo .cpp**

   O nome do arquivo de implementação da classe de consumo, baseado por padrão no nome do arquivo ou fonte de dados da máquina que você selecionou.

- **Tipo**

   Especifica se o conjunto de registros é um dynaset (padrão) ou um snapshot.

  - **Dynaset**: Especifica que o conjunto de registros é um dynaset. Um dynaset é o resultado de uma consulta que fornece uma visão indexada nos dados do banco de dados consultados. Um dynaset armazena apenas um índice integral para os dados originais e, portanto, oferece um ganho de desempenho sobre um snapshot. O índice aponta diretamente para cada registro encontrado como resultado de uma consulta e indica se um registro é removido. Você também tem acesso a informações atualizadas nos registros consultados. Esse é o padrão.

  - **Instantâneo**: Especifica que o conjunto de registros é um instantâneo. Um instantâneo é o resultado de uma consulta e é uma exibição em um banco de dados em um ponto no tempo. Todos os registros encontrados como resultado da consulta são armazenados em cache, portanto você não vê nenhuma alteração nos registros originais.

- **Amarre todas as colunas**

   Especifica se todas as colunas da tabela selecionada estão vinculadas. Se você selecionar esta caixa (padrão), todas as colunas serão vinculadas; se você não selecionar esta caixa, nenhuma coluna está vinculada e você deve vinculá-las manualmente na classe recordset.

::: moniker-end

## <a name="see-also"></a>Confira também

[Consumo ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md)<br/>
[Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)
