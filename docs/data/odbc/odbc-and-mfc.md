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
ms.openlocfilehash: 94a3455324a52b789bcfcf192b698a3c42b37c00
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213145"
---
# <a name="odbc-and-mfc"></a>ODBC e MFC

> [!NOTE]
>  Para usar as classes de banco de dados do MFC, você deve ter o driver ODBC apropriado para sua fonte. O último driver Microsoft ODBC para SQL Server é o [Microsoft ODBC Driver 13 para SQL Server](https://www.microsoft.com/download/details.aspx?id=50420). A maioria dos fornecedores de banco de dados fornece um driver ODBC para Windows.

Este tópico apresenta os principais conceitos das classes de banco de dados baseadas em ODBC da biblioteca do MFC (MFC) e fornece uma visão geral de como as classes funcionam em conjunto. Para obter mais informações sobre ODBC e MFC, consulte os seguintes tópicos:

- [Conectando a uma fonte de dados](connecting-to-a-data-source.md)

- [Selecionando e manipulando registros](selecting-and-manipulating-records.md)

- [Exibindo e manipulando dados em um formulário](displaying-and-manipulating-data-in-a-form.md)

- [Trabalhando com documentos e exibições](working-with-documents-and-views.md)

- [Acesso a ODBC e SQL](access-to-odbc-and-sql.md)

- [Leitura adicional sobre as classes ODBC do MFC](further-reading-about-the-mfc-odbc-classes.md)

As classes de banco de dados MFC baseadas em ODBC são projetadas para fornecer acesso a qualquer banco de dados para o qual um driver ODBC está disponível. Como as classes usam o ODBC, seu aplicativo pode acessar dados em vários formatos de dados diferentes e configurações locais/remotas diferentes. Você não precisa escrever código de caso especial para lidar com DBMS (sistemas de gerenciamento de banco de dados) diferentes. Desde que os usuários tenham um driver ODBC apropriado para os dados que desejam acessar, eles podem usar seu programa para manipular dados em tabelas armazenadas lá.

## <a name="see-also"></a>Confira também

[ODBC (conectividade de banco de dados aberto)](open-database-connectivity-odbc.md)
