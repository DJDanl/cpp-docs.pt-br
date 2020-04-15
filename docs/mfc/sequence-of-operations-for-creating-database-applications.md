---
title: Sequência de operações para criação de aplicativos de banco de dados
ms.date: 11/04/2016
helpviewer_keywords:
- applications [MFC], database
- database applications [MFC]
- database applications [MFC], creating
- MFC, database applications
ms.assetid: 9371da59-8536-43cd-8314-706ad320e2ec
ms.openlocfilehash: c393269d6af108ee82786e9d59f81aad11428157
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372768"
---
# <a name="sequence-of-operations-for-creating-database-applications"></a>Sequência de operações para criação de aplicativos de banco de dados

A tabela a seguir mostra seu papel e o papel do framework na escrita de aplicativos de banco de dados.

> [!NOTE]
> O ambiente Visual C++ e os assistentes não suportam DAO (embora as classes DAO estejam incluídas e você ainda possa usá-las). A Microsoft recomenda que você use ODBC para novos projetos de MFC. Você só deve usar DAO na manutenção de aplicativos existentes.

### <a name="creating-database-applications"></a>Criando aplicativos de banco de dados

|Tarefa|Você faz|O quadro faz|
|----------|------------|------------------------|
|Decida se deve usar as classes MFC ODBC ou DAO.|Use o ODBC para novos projetos de MFC. Use DAO apenas para manter os aplicativos existentes. Para obter informações gerais, consulte o artigo [Programação de Acesso a Dados](../data/data-access-programming-mfc-atl.md).|A estrutura fornece classes que suportam o acesso ao banco de dados.|
|Crie seu aplicativo esqueleto com opções de banco de dados.|Execute o Assistente de Aplicativo Do MFC. Selecione opções na página de suporte ao banco de dados. Se você escolher uma opção que cria uma exibição de registro, também especifique:<br /><br />- Fonte de dados e nome da tabela ou nomes<br />- Consulta nome ou nomes.|O MFC Application Wizard cria arquivos e especifica as incluições necessárias. Dependendo das opções especificadas, os arquivos podem incluir uma classe de conjunto de registros.|
|Projete seu formulário ou formulário de banco de dados.|Use o editor de diálogo Visual C++ para colocar controles nos recursos do modelo de diálogo para suas classes de exibição de registro.|O MFC Application Wizard cria um recurso de modelo de diálogo vazio para você preencher.|
|Crie classes adicionais de visualização de gravação e conjunto de registros conforme necessário.|Use a exibição de classe para criar as classes e o editor de diálogo para projetar as visualizações.|O Class View cria arquivos adicionais para suas novas classes.|
|Crie objetos de conjunto de registros conforme necessário em seu código. Use cada conjunto de discos para manipular registros...|Seus conjuntos de registros são baseados nas classes derivadas de [CRecordset](../mfc/reference/crecordset-class.md) com os assistentes.|O ODBC usa o RFX (Record Field Exchange, troca de dados) para trocar dados entre o banco de dados e os membros de dados de campo do seu conjunto de registros. Se você estiver usando uma exibição de registro, o DDX (Exchange de dados de diálogo) troca dados entre o conjunto de registros e os controles na exibição de registro.|
|... ou criar um [CDatabase](../mfc/reference/cdatabase-class.md) explícito em seu código para cada banco de dados que você deseja abrir.|Baseie seus objetos de conjunto de registros nos objetos do banco de dados.|O objeto do banco de dados fornece uma interface para a fonte de dados.|
|Vincule as colunas de dados ao seu conjunto de registros dinamicamente.|No ODBC, adicione código à sua classe de conjunto de registros derivada para gerenciar a vinculação. Veja o artigo [Recordset: Colunas de dados dinamicamente vinculativas (ODBC)](../data/odbc/recordset-dynamically-binding-data-columns-odbc.md).||

## <a name="see-also"></a>Confira também

[Baseando-se no Framework](../mfc/building-on-the-framework.md)<br/>
[Sequência de operações para compilar aplicativos MFC](../mfc/sequence-of-operations-for-building-mfc-applications.md)<br/>
[Sequência de operações para a criação de aplicativos OLE](../mfc/sequence-of-operations-for-creating-ole-applications.md)<br/>
[Sequência de operações para criação de controles ActiveX](../mfc/sequence-of-operations-for-creating-activex-controls.md)
