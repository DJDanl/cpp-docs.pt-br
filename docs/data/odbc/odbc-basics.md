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
ms.openlocfilehash: e14f5d051b9684cd79a34f5fb50feeb785d2f927
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59033229"
---
# <a name="odbc-basics"></a>Noções básicas de ODBC

Este tópico fornece as Noções básicas da conectividade aberta de banco de dados (ODBC):

- [Como o ODBC funciona com as Classes de banco de dados](../../data/odbc/odbc-and-the-database-classes.md)

- [Como os Drivers ODBC funcionam com Dynasets](../../data/odbc/odbc-driver-requirements-for-dynasets.md)

- [Quais componentes ODBC, você precisa ser redistribuídas com seus aplicativos](../../data/odbc/redistributing-odbc-components-to-your-customers.md)

Você também deseja ler o tópico relacionado [ODBC: A biblioteca de cursores ODBC](../../data/odbc/odbc-the-odbc-cursor-library.md).

> [!NOTE]
> Fontes de dados ODBC são acessíveis por meio de classes MFC ODBC, conforme descrito neste tópico, ou as classes de objeto de acesso a dados MFC (DAO).

> [!NOTE]
> As classes MFC ODBC oferecem suporte a Unicode e multithreading. Para obter mais informações sobre o suporte a multithreading, consulte [Classes e Threads ODBC](../../data/odbc/odbc-classes-and-threads.md)

O ODBC é uma interface de nível de chamada que permite que aplicativos acessem dados em qualquer banco de dados para o qual há um driver ODBC. Usando o ODBC, você pode criar aplicativos de banco de dados com acesso a qualquer banco de dados para o qual o usuário final tem um driver ODBC. O ODBC fornece uma API que permite que seu aplicativo para ser independente de sistema de gerenciamento de banco de dados de origem (DBMS).

ODBC é a parte do banco de dados do Microsoft Windows abra Services Architecture (WOSA), que é uma interface que permite que aplicativos da área de trabalho baseados em Windows para se conectar a vários ambientes de computação sem reescrever o aplicativo para cada plataforma.

A seguir é componentes de ODBC:

- API DE ODBC

   Uma biblioteca da função chama, um conjunto de códigos de erro e um padrão [SQL](../../data/odbc/sql.md) sintaxe para acessar dados em DBMSs.

- Gerenciador de Driver ODBC

   Uma biblioteca de vínculo dinâmico (Odbc32. dll) que carrega os drivers de banco de dados ODBC em nome de um aplicativo. Essa DLL é transparente para seu aplicativo.

- Drivers de banco de dados ODBC

   Uma ou mais DLLs que processam chamadas de função ODBC para DBMSs específicos. Para obter uma lista dos drivers fornecidos, consulte [lista de drivers ODBC](../../data/odbc/odbc-driver-list.md).

- [Biblioteca de cursores ODBC](../../data/odbc/odbc-the-odbc-cursor-library.md)

   Uma biblioteca de vínculo dinâmico (Odbccr32.dll) que reside entre o Gerenciador de Driver ODBC e os drivers e manipula a rolagem por meio dos dados.

- [Administrador do ODBC](../../data/odbc/odbc-administrator.md)

   Uma ferramenta usada para configurar um DBMS para disponibilizá-lo como uma fonte de dados para um aplicativo.

Um aplicativo atinge a independência de DBMSs por trabalho por meio de um driver ODBC criado especificamente para um DBMS em vez de trabalhar diretamente com o DBMS. O driver converte as chamadas em comandos que seu DBMS pode usar, simplificando o trabalho do desenvolvedor e tornando-os disponíveis para uma ampla variedade de fontes de dados.

As classes de banco de dados dão suporte a qualquer fonte de dados para o qual você tem um driver ODBC. Isso pode, por exemplo, incluir um banco de dados relacional, um banco de dados indexados acesso ISAM (método sequencial), uma planilha do Microsoft Excel ou um arquivo de texto. Os drivers ODBC gerenciar as conexões com a fonte de dados e o SQL é usado para selecionar registros do banco de dados.

Para obter uma lista de drivers ODBC incluídos nesta versão do Visual C++ e para obter informações sobre como obter drivers adicionais, consulte [lista de drivers ODBC](../../data/odbc/odbc-driver-list.md).

## <a name="see-also"></a>Consulte também

[ODBC (conectividade de banco de dados aberto)](../../data/odbc/open-database-connectivity-odbc.md)