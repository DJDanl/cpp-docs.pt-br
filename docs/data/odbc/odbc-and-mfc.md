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
ms.openlocfilehash: 38a625c73a17ecae4d8adc61e8c56bc4bdda67f6
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81320081"
---
# <a name="odbc-and-mfc"></a>ODBC e MFC

> [!NOTE]
> Para usar as classes de banco de dados Do MFC, você deve ter o driver ODBC apropriado para sua fonte de dados. O driver Microsoft ODBC mais recente para SQL Server é [o Microsoft ODBC Driver 13 para SQL Server](https://www.microsoft.com/download/details.aspx?id=50420). A maioria dos fornecedores de banco de dados fornece um driver ODBC para Windows.

Este tópico introduz os principais conceitos das classes de banco de dados baseadas em ODBC da biblioteca Da Microsoft Foundation Classes (MFC) e fornece uma visão geral de como as aulas funcionam em conjunto. Para obter mais informações sobre o ODBC e o MFC, consulte os seguintes tópicos:

- [Conectando a uma Fonte de Dados](connecting-to-a-data-source.md)

- [Selecionando e manipulando registros](selecting-and-manipulating-records.md)

- [Exibindo e manipulando dados em um formulário](displaying-and-manipulating-data-in-a-form.md)

- [Trabalhando com Documentos e visualizações](working-with-documents-and-views.md)

- [Acesso a ODBC e SQL](access-to-odbc-and-sql.md)

- [Mais leituras sobre as classes MFC ODBC](further-reading-about-the-mfc-odbc-classes.md)

As classes de banco de dados MFC baseadas no ODBC são projetadas para fornecer acesso a qualquer banco de dados para o qual um driver ODBC esteja disponível. Como as classes usam ODBC, seu aplicativo pode acessar dados em muitos formatos de dados diferentes e configurações locais/remotas diferentes. Você não precisa escrever código de caso especial para lidar com diferentes sistemas de gerenciamento de banco de dados (DBMSs). Desde que seus usuários tenham um driver ODBC apropriado para os dados que desejam acessar, eles podem usar seu programa para manipular dados em tabelas armazenadas lá.

## <a name="see-also"></a>Confira também

[Conectividade de banco de dados aberto (ODBC)](open-database-connectivity-odbc.md)
