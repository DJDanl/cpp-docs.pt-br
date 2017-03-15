---
title: Assistente de consumidor ODBC do MFC | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.codewiz.class.mfc.consumer.overview
dev_langs:
- C++
helpviewer_keywords:
- MFC ODBC Consumer Wizard
- wizards [MFC]
ms.assetid: f64a890b-a252-4887-88a1-782a7cd4ff3d
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: c0d4b56caa29091f24cb5fd3fca1c3c44e459c33
ms.lasthandoff: 02/25/2017

---
# <a name="mfc-odbc-consumer-wizard"></a>Assistente de consumidor ODBC MFC
Insira "Resultados da pesquisa" Resumo aqui.  
  
 Este assistente define uma classe de conjunto de registros ODBC e as ligações de dados necessário para acessar a fonte de dados especificado.  
  
## <a name="uielement-list"></a>Lista UIElement  
 **Fonte de dados**  
 O **fonte de dados** botão permite que você defina a fonte de dados especificado usando o driver ODBC especificado. Para obter mais informações sobre arquivos de fonte de dados (DSN), consulte [fontes de dados de arquivo](https://msdn.microsoft.com/library/ms715401.aspx) no SDK do ODBC. O **Selecionar fonte de dados** caixa de diálogo tem duas guias:  
  
-   **Fonte de dados de arquivo** guia: O **examinar** caixa especifica o diretório no qual selecionar arquivos a serem usados como fontes de dados. O padrão é \Program Comuns\odbc\fontes. As fontes de dados de arquivo existente (arquivos. DSN) aparecem na caixa de lista principal. Você pode configurar as fontes de dados antes do tempo usando o **DSN de arquivo** guia de [administrador de fonte de dados ODBC](https://msdn.microsoft.com/library/ms714024.aspx), ou criar novos objetos usando essa caixa de diálogo.  
  
     Para criar uma nova fonte de dados de arquivo da caixa de diálogo, clique em `New` para especificar um nome DSN; o **criar nova fonte de dados** caixa de diálogo é exibida. No **criar nova fonte de dados** caixa de diálogo Selecione um driver apropriado e clique em `Next`; clique em **procurar**e selecione o nome do arquivo a ser usado como uma fonte de dados (você precisa selecionar "Todos os arquivos" para exibir arquivos sem DSN, como arquivos. xls); clique em `Next`e, em seguida, clique em **concluir**. (Se você selecionou um arquivo DSN não, você obterá uma caixa de diálogo específica do driver, como "Configuração ODBC do Microsoft Excel," que converterá o arquivo em um DSN.)  
  
    > [!NOTE]
    >  Você também pode criar uma nova fonte de dados de arquivo antes de usar o administrador de fonte de dados ODBC. Do **iniciar** menu, selecione **configurações**, **painel de controle**, **ferramentas administrativas**, **fontes de dados (ODBC)**e então **administrador de fonte de dados ODBC**.  
  
     O **nome de DSN** caixa permite que você especifique um nome para o arquivo de origem de dados. Certifique-se de que o nome de DSN termina com a extensão de arquivo apropriado, como. xls para arquivos do Excel ou. mdb para acessar os arquivos.  
  
     Para obter mais informações sobre DSNs, consulte [fontes de dados de arquivo](https://msdn.microsoft.com/library/ms715401.aspx) no SDK do ODBC.  
  
-   **Fonte de dados da máquina** guia: essa guia lista fontes de dados de usuário e sistema. Fontes de dados do usuário são específicas para um usuário nesse computador. Fontes de dados do sistema podem ser usados por todos os usuários neste computador ou em um serviço de todo o sistema. Consulte [fontes de dados de máquina](https://msdn.microsoft.com/library/ms710952.aspx) no SDK do ODBC  
  
 Para obter mais informações sobre fontes de dados ODBC, consulte [fontes de dados](https://msdn.microsoft.com/library/ms711688.aspx) no SDK do ODBC.  
  
 Clique em **Okey** para concluir. O **Selecionar objeto de banco de dados** caixa de diálogo é exibida. Nessa caixa de diálogo, selecione a tabela ou exibição que o consumidor usará. Observe que você pode selecionar várias exibições e tabelas mantendo a tecla control enquanto clica nos itens.  
  
 **Classe**  
 O nome da classe do consumidor, baseada por padrão o nome da máquina ou arquivo de fonte de dados que você selecionou.  
  
 **arquivo. h**  
 O nome do arquivo de cabeçalho de classe consumidor, baseado por padrão o nome da máquina ou arquivo de fonte de dados que você selecionou.  
  
 **arquivo. cpp**  
 O nome do arquivo de implementação de classe consumidor, baseado por padrão o nome da máquina ou arquivo de fonte de dados que você selecionou.  
  
 **Tipo**  
 Especifica se o conjunto de registros é um dynaset (padrão) ou um instantâneo.  
  
-   **Dynaset**: Especifica que o conjunto de registros é um dynaset. Dynaset é o resultado de uma consulta que fornece uma exibição indexada em dados do banco de dados consultados. Dynaset armazena em cache apenas um índice integral para os dados originais e, portanto, oferece um desempenho obter um instantâneo. Os pontos de índice diretamente a cada registro encontrado como resultado de uma consulta e indica se um registro for removido. Você também tem acesso a informações atualizadas nos registros consultados. Esse é o padrão.  
  
-   **Instantâneo**: Especifica que o conjunto de registros é um instantâneo. Um instantâneo é o resultado de uma consulta e é uma exibição de um banco de dados em um ponto no tempo. Todos os registros em virtude da consulta são armazenados em cache, para que você não veja todas as alterações nos registros originais.  
  
 **Associar todas as colunas**  
 Especifica se todas as colunas na tabela selecionada estão vinculadas. Se você selecionar essa caixa (padrão), todas as colunas são vinculadas; Se você não selecionar essa caixa, não há colunas associadas e você deve associá-las manualmente na classe de conjunto de registros.  
  
## <a name="see-also"></a>Consulte também  
 [Consumidor ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md)   
 [Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)


