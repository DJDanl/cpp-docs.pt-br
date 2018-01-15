---
title: Assistente de consumidor ODBC do MFC | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.codewiz.class.mfc.consumer.overview
dev_langs: C++
helpviewer_keywords:
- MFC ODBC Consumer Wizard
- wizards [MFC]
ms.assetid: f64a890b-a252-4887-88a1-782a7cd4ff3d
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ad9e4aeb15d2af04987883b6554d569e3cc16b8d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="mfc-odbc-consumer-wizard"></a>Assistente de consumidor ODBC MFC
Insira "Resultados da pesquisa" Resumo aqui.  
  
 Este assistente define uma classe de conjunto de registros ODBC e as associações de dados necessário para acessar a fonte de dados especificado.  
  
## <a name="uielement-list"></a>Lista UIElement  
 **Fonte de dados**  
 O **fonte de dados** botão permite que você defina a fonte de dados especificado usando o driver ODBC especificado. Para obter mais informações sobre arquivos de fonte de dados (DSN), consulte [fontes de dados do arquivo](https://msdn.microsoft.com/library/ms715401.aspx) no SDK do ODBC. O **Selecionar fonte de dados** caixa de diálogo tem duas guias:  
  
-   **Fonte de dados de arquivo** guia: O **examinar** Especifica o diretório no qual selecionar arquivos a serem usados como fontes de dados. O padrão é \Program Comuns\odbc\fontes. As fontes de dados de arquivo existente (arquivos. DSN) aparecem na caixa de listagem principal. Você pode definir as fontes de dados antes do tempo usando o **DSN de arquivo** guia o [administrador de fonte de dados ODBC](https://msdn.microsoft.com/library/ms714024.aspx), ou criar novos objetos usando essa caixa de diálogo.  
  
     Para criar uma nova fonte de dados de arquivo nessa caixa de diálogo, clique em `New` para especificar um nome DSN; o **criar nova fonte de dados** caixa de diálogo é exibida. No **criar nova fonte de dados** caixa de diálogo caixa, selecione um driver apropriado e clique em `Next`; clique em **procurar**e selecione o nome do arquivo a ser usado como uma fonte de dados (é necessário selecionar "Todos os arquivos" para modo de exibição não DSN arquivos, como arquivos. xls); Clique em `Next`e, em seguida, clique em **concluir**. (Se você selecionou um arquivo DSN não, será exibida uma caixa de diálogo específica do driver, como "Configurar ODBC para Microsoft Excel," qual converterá o arquivo em um DSN.)  
  
    > [!NOTE]
    >  Você também pode criar uma nova fonte de dados do arquivo antes de usar o administrador de fonte de dados ODBC. Do **iniciar** menu, selecione **configurações**, **painel de controle**, **ferramentas administrativas**, **fontes de dados (ODBC)**e, em seguida, **administrador de fonte de dados ODBC**.  
  
     O **nome DSN** caixa permite que você especifique um nome para a fonte de dados de arquivo. Certifique-se de que o nome DSN termina com a extensão de arquivo apropriado, como. xls para arquivos do Excel ou. mdb para acessar os arquivos.  
  
     Para obter mais informações sobre DSNs, consulte [fontes de dados do arquivo](https://msdn.microsoft.com/library/ms715401.aspx) no SDK do ODBC.  
  
-   **Fonte de dados da máquina** guia: essa guia lista fontes de dados de usuário e sistema. Fontes de dados do usuário são específicas a um usuário neste computador. Fontes de dados do sistema podem ser usados por todos os usuários neste computador ou em um serviço de todo o sistema. Consulte [fontes de dados de máquina](https://msdn.microsoft.com/library/ms710952.aspx) no SDK do ODBC  
  
 Para obter mais informações sobre fontes de dados ODBC, consulte [fontes de dados](https://msdn.microsoft.com/library/ms711688.aspx) no SDK do ODBC.  
  
 Clique em **Okey** para concluir. O **Selecionar objeto de banco de dados** caixa de diálogo é exibida. Nessa caixa de diálogo, selecione a tabela ou exibição que o consumidor usará. Observe que você pode selecionar várias tabelas e exibições mantendo a tecla control ao clicar nos itens.  
  
 **Class**  
 O nome da classe de consumidor, com base em por padrão o nome da máquina ou arquivo de fonte de dados que você selecionou.  
  
 **arquivo. h**  
 O nome do arquivo de cabeçalho de classe consumidor, com base em por padrão o nome da máquina ou arquivo de fonte de dados que você selecionou.  
  
 **arquivo. cpp**  
 O nome do arquivo de implementação de classe consumidor, com base em por padrão o nome da máquina ou arquivo de fonte de dados que você selecionou.  
  
 **Tipo**  
 Especifica se o conjunto de registros é dynaset (padrão) ou um instantâneo.  
  
-   **Dynaset**: Especifica que o conjunto de registros é dynaset. Dynaset é o resultado de uma consulta que fornece uma exibição indexada em dados do banco de dados consultados. Dynaset armazena em cache somente um índice integral aos dados originais e, portanto, oferece um desempenho obter um instantâneo. Os pontos de índice diretamente a cada registro encontrado como resultado de uma consulta e indica se um registro é removido. Você também tem acesso a informações atualizadas nos registros de consultado. Esse é o padrão.  
  
-   **Instantâneo**: Especifica que o conjunto de registros é um instantâneo. Um instantâneo é o resultado de uma consulta e é um modo de exibição em um banco de dados em um ponto no tempo. Todos os registros em virtude da consulta são armazenados em cache, para que você não veja todas as alterações nos registros originais.  
  
 **Associar todas as colunas**  
 Especifica se todas as colunas na tabela selecionada estão vinculadas. Se você selecionar essa caixa (padrão), todas as colunas são vinculadas; Se você não selecionar essa caixa, não há colunas associadas e você deve associá-las manualmente na classe de conjunto de registros.  
  
## <a name="see-also"></a>Consulte também  
 [Consumidor ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md)   
 [Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)

