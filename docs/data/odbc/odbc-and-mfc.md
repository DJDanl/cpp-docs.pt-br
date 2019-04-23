---
title: ODBC e MFC
ms.date: 11/04/2016
helpviewer_keywords:
- ODBC [C++], MFC
- connections [C++], databases
- connections [C++], data source
- databases [C++], connecting to
- data sources [C++], connecting to
- MFC [C++], ODBC and
- database connections [C++], MFC ODBC classes
ms.assetid: 98f02fd7-1235-437b-89a9-edfd0fc797f7
ms.openlocfilehash: 9b7d04e2eb8bbb1adf96e05282861ef33e20434a
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59031174"
---
# <a name="odbc-and-mfc"></a>ODBC e MFC

> [!NOTE]
>  Para usar as classes de banco de dados do MFC, você deve ter o driver ODBC apropriado para sua fonte de dados. É o mais recente Microsoft ODBC driver para SQL Server [Microsoft ODBC Driver 13 for SQL Server](https://www.microsoft.com/download/details.aspx?id=50420). A maioria dos fornecedores de banco de dados fornecem um driver ODBC para Windows.

Este tópico apresenta os principais conceitos de classes de banco de dados baseado em ODBC da biblioteca Microsoft Foundation Classes (MFC) e fornece uma visão geral de como as classes funcionam juntos. Para obter mais informações sobre o ODBC e MFC, consulte os tópicos a seguir:

- [Conectando a uma fonte de dados](connecting-to-a-data-source.md)

- [Selecionando e manipulando registros](selecting-and-manipulating-records.md)

- [Exibindo e manipulando dados em um formulário](displaying-and-manipulating-data-in-a-form.md)

- [Trabalhando com documentos e exibições](working-with-documents-and-views.md)

- [Acesso a ODBC e SQL](access-to-odbc-and-sql.md)

- [Leitura adicional sobre as classes ODBC do MFC](further-reading-about-the-mfc-odbc-classes.md)

As classes de banco de dados do MFC com base em ODBC são projetadas para fornecer acesso a qualquer banco de dados para o qual um driver ODBC está disponível. Como as classes usam o ODBC, seu aplicativo pode acessar dados em vários formatos de dados diferentes e diferentes configurações de local/remoto. Você não precisa escrever código de casos especiais para lidar com sistemas de gerenciamento de outro banco de dados (DBMSs). Desde que os usuários tiverem um driver ODBC apropriado para os dados que desejam acessar, eles podem usar o seu programa para manipular dados em tabelas armazenadas lá.

## <a name="see-also"></a>Consulte também

[ODBC (conectividade de banco de dados aberto)](open-database-connectivity-odbc.md)