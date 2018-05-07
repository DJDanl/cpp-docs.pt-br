---
title: Noções básicas de ODBC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- ODBC cursor library [ODBC], ODBC components
- ODBC components
- ODBC components, required components
- ODBC, about ODBC
- ODBC, components
ms.assetid: ec529702-0fb2-4754-b8de-d1efa8eca18f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 69b3694292171f00e03cdb941def27fd9e8ffc84
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="odbc-basics"></a>Noções básicas de ODBC
Este tópico fornece as Noções básicas de conectividade aberta de banco de dados (ODBC):  
  
-   [Como o funciona com as Classes de banco de dados ODBC](../../data/odbc/odbc-and-the-database-classes.md)  
  
-   [Como os Drivers ODBC funcionam com Dynasets](../../data/odbc/odbc-driver-requirements-for-dynasets.md)  
  
-   [Quais componentes ODBC é necessário redistribuir com seus aplicativos](../../data/odbc/redistributing-odbc-components-to-your-customers.md)  
  
 Você também deseja ler o tópico relacionado [ODBC: A biblioteca de cursores ODBC](../../data/odbc/odbc-the-odbc-cursor-library.md).  
  
> [!NOTE]
>  Fontes de dados ODBC são acessíveis por meio de classes MFC ODBC, conforme descrito neste tópico, ou as classes de objeto de acesso a dados MFC (DAO).  
  
> [!NOTE]
>  As classes MFC ODBC oferecem suporte a Unicode e multithreading. Para obter mais informações sobre o suporte a multithreading, consulte [Classes e Threads ODBC](../../data/odbc/odbc-classes-and-threads.md)  
  
 ODBC é uma interface de nível de chamada que permite que aplicativos acessem dados em qualquer banco de dados para o qual há um driver ODBC. Usando o ODBC, você pode criar aplicativos de banco de dados com acesso a qualquer banco de dados para o qual o usuário final tem um driver ODBC. ODBC fornece uma API que permite que seu aplicativo para ser independente do sistema de gerenciamento de banco de dados de origem (DBMS).  
  
 ODBC é a parte do banco de dados do Microsoft Windows Open Services Architecture (WOSA), que é uma interface que permite que aplicativos da área de trabalho do Windows para se conectar a vários ambientes de computação sem reescrever o aplicativo para cada plataforma.  
  
 A seguir é componentes de ODBC:  
  
-   API DE ODBC  
  
     Chamadas de uma biblioteca da função, um conjunto de códigos de erro e um padrão [SQL](../../data/odbc/sql.md) sintaxe para acessar dados em DBMSs.  
  
-   Gerenciador de Driver ODBC  
  
     Uma biblioteca de vínculo dinâmico (Odbc32. dll) que carrega os drivers de banco de dados ODBC em nome de um aplicativo. Esta DLL é transparente ao seu aplicativo.  
  
-   Drivers de banco de dados ODBC  
  
     Uma ou mais DLLs que processam chamadas de função ODBC para DBMSs específicos. Para obter uma lista de drivers fornecidos, consulte [lista de drivers ODBC](../../data/odbc/odbc-driver-list.md).  
  
-   [Biblioteca de cursores ODBC](../../data/odbc/odbc-the-odbc-cursor-library.md)  
  
     Uma biblioteca de vínculo dinâmico (Odbccr32.dll) que reside entre o Gerenciador de Driver ODBC e os drivers e manipula a percorrer os dados.  
  
-   [Administrador do ODBC](../../data/odbc/odbc-administrator.md)  
  
     Uma ferramenta usada para configurar um DBMS para disponibilizá-lo como uma fonte de dados para um aplicativo.  
  
 Um aplicativo obtém a independência de DBMSs trabalho por meio de um driver ODBC criado especificamente para um DBMS em vez de trabalhar diretamente com o DBMS. O driver não converte as chamadas em comandos que seu DBMS pode usar, simplificando o trabalho do desenvolvedor e torná-lo disponível para uma ampla variedade de fontes de dados.  
  
 As classes de banco de dados oferecem suporte a qualquer fonte de dados em que você tenha um driver ODBC. Por exemplo, isso pode incluir um banco de dados relacional, um banco de dados indexados sequencial acesso ISAM (método), uma planilha do Microsoft Excel ou um arquivo de texto. Os drivers ODBC gerenciam as conexões para a fonte de dados e SQL é usado para selecionar registros do banco de dados.  
  
 Para obter uma lista de drivers ODBC incluídos nesta versão do Visual C++ e para obter informações sobre como obter drivers adicionais, consulte [lista de drivers ODBC](../../data/odbc/odbc-driver-list.md).  
  
## <a name="see-also"></a>Consulte também  
 [ODBC (conectividade de banco de dados aberto)](../../data/odbc/open-database-connectivity-odbc.md)