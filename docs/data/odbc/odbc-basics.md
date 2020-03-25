---
title: Noções básicas de ODBC
ms.date: 11/04/2016
helpviewer_keywords:
- ODBC cursor library [ODBC], ODBC components
- ODBC components
- ODBC components, required components
- ODBC, about ODBC
- ODBC, components
ms.assetid: ec529702-0fb2-4754-b8de-d1efa8eca18f
ms.openlocfilehash: 042b1ce6d12e4f4a2be57c0e2e8e01d9750f5357
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213147"
---
# <a name="odbc-basics"></a>Noções básicas de ODBC

Este tópico fornece os fundamentos de ODBC (Open Database Connectivity):

- [Como o ODBC funciona com as classes de banco de dados](../../data/odbc/odbc-and-the-database-classes.md)

- [Como os drivers ODBC funcionam com dynasets](../../data/odbc/odbc-driver-requirements-for-dynasets.md)

- [Quais componentes do ODBC você precisa redistribuir com seus aplicativos](../../data/odbc/redistributing-odbc-components-to-your-customers.md)

Você também vai querer ler o tópico ODBC relacionado [: a biblioteca de cursores ODBC](../../data/odbc/odbc-the-odbc-cursor-library.md).

> [!NOTE]
> As fontes de dados ODBC podem ser acessadas por meio das classes ODBC do MFC, conforme descrito neste tópico ou por meio das classes DAO (objeto de acesso a dados) do MFC.

> [!NOTE]
> As classes ODBC do MFC dão suporte a Unicode e multithreading. Para obter mais informações sobre o suporte a multithreading, consulte [classes e threads ODBC](../../data/odbc/odbc-classes-and-threads.md)

O ODBC é uma interface de nível de chamada que permite que os aplicativos acessem dados em qualquer banco de dado para o qual há um driver ODBC. Usando o ODBC, você pode criar aplicativos de banco de dados com acesso a qualquer banco de dados para o qual o usuário final tenha um driver ODBC. O ODBC fornece uma API que permite que seu aplicativo seja independente do DBMS (sistema de gerenciamento de banco de dados de origem).

O ODBC é a parte do banco de dados da arquitetura do Microsoft Windows Open Services (WOSA), que é uma interface que permite que aplicativos de área de trabalho baseados no Windows se conectem a vários ambientes de computação sem reescrever o aplicativo para cada plataforma.

Estes são os componentes do ODBC:

- API ODBC

   Uma biblioteca de chamadas de função, um conjunto de códigos de erro e uma sintaxe [SQL](../../data/odbc/sql.md) padrão para acessar dados em DBMSs.

- Gerenciador de driver ODBC

   Uma biblioteca de vínculo dinâmico (Odbc32. dll) que carrega drivers de banco de dados ODBC em nome de um aplicativo. Essa DLL é transparente para seu aplicativo.

- Drivers de banco de dados ODBC

   Uma ou mais DLLs que processam chamadas de função ODBC para DBMSs específicos. Para obter uma lista de drivers fornecidos, consulte [lista de drivers ODBC](../../data/odbc/odbc-driver-list.md).

- [Biblioteca de cursores ODBC](../../data/odbc/odbc-the-odbc-cursor-library.md)

   Uma biblioteca de vínculo dinâmico (Odbccr32. dll) que reside entre o Gerenciador de driver ODBC e os drivers e manipula a rolagem pelos dados.

- [Administrador do ODBC](../../data/odbc/odbc-administrator.md)

   Uma ferramenta usada para configurar um DBMS para torná-lo disponível como uma fonte de dados para um aplicativo.

Um aplicativo obtém independência de DBMSs trabalhando por meio de um driver ODBC escrito especificamente para um DBMS, em vez de trabalhar diretamente com o DBMS. O driver traduz as chamadas em comandos que seu DBMS pode usar, simplificando o trabalho do desenvolvedor e disponibilizando-o para uma ampla variedade de fontes de dados.

As classes de banco de dados dão suporte a qualquer fonte de dado para a qual você tenha um driver ODBC. Isso pode, por exemplo, incluir um banco de dados relacional, um banco de dados de ISAM (método de acesso sequencial) indexado, uma planilha do Microsoft Excel ou um arquivo de texto. Os drivers ODBC gerenciam as conexões com a fonte de dados, e o SQL é usado para selecionar registros do Database.

Para ver uma lista de drivers ODBC incluídos nesta versão do Visual C++ e para saber como obter outros drivers, confira [Lista de Drivers ODBC](../../data/odbc/odbc-driver-list.md).

## <a name="see-also"></a>Confira também

[ODBC (conectividade de banco de dados aberto)](../../data/odbc/open-database-connectivity-odbc.md)
