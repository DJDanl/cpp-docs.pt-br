---
title: Sequência de operações para criação de aplicativos de banco de dados
ms.date: 11/04/2016
helpviewer_keywords:
- applications [MFC], database
- database applications [MFC]
- database applications [MFC], creating
- MFC, database applications
ms.assetid: 9371da59-8536-43cd-8314-706ad320e2ec
ms.openlocfilehash: efd6b12b186ce0ef1c0caf57f313f6aa50425fec
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57283664"
---
# <a name="sequence-of-operations-for-creating-database-applications"></a>Sequência de operações para criação de aplicativos de banco de dados

A tabela a seguir mostra a sua função e a função da estrutura em escrever aplicativos de banco de dados.

> [!NOTE]
>  Os assistentes e o ambiente do Visual C++ não têm suporte DAO (embora as classes DAO estão incluídas e você ainda pode usá-los). A Microsoft recomenda que você use o ODBC para novos projetos MFC. Você só deve usar DAO em manutenção de aplicativos existentes.

### <a name="creating-database-applications"></a>Criação de aplicativos de banco de dados

|Tarefa|Você faz|A estrutura faz|
|----------|------------|------------------------|
|Decida se deseja usar as classes MFC ODBC ou DAO.|Use ODBC para novos projetos MFC. Use DAO somente para manter os aplicativos existentes. Para obter informações gerais, consulte o artigo [programação de acesso de dados](../data/data-access-programming-mfc-atl.md).|O framework fornece classes que oferecem suporte ao acesso de banco de dados.|
|Crie seu aplicativo de esqueleto com opções de banco de dados.|Execute o Assistente de aplicativo do MFC. Selecione as opções na página de suporte do banco de dados. Se você escolher uma opção que cria uma exibição de registro, também especifique:<br /><br />-Nome da tabela e de fonte de dados ou nomes<br />-Nome ou nomes de consulta.|O Assistente de aplicativo do MFC cria arquivos e especifica que inclui o necessário. Dependendo das opções que você especificar, os arquivos podem incluir uma classe de conjunto de registros.|
|Design de banco de dados formulário ou formulários.|Use o editor de caixa de diálogo do Visual C++ para posicionar controles nos recursos de modelo de caixa de diálogo para as suas classes de exibição de registro.|O Assistente de aplicativo do MFC cria um recurso de modelo de caixa de diálogo vazio para preencher.|
|Crie classes de exibição e o conjunto de registros registro adicionais conforme necessário.|Use o modo de exibição de classe para criar as classes e a caixa de diálogo editor para os modos de exibição de design.|Modo de exibição de classe cria arquivos adicionais para as novas classes.|
|Crie objetos de conjunto de registros, conforme necessário em seu código. Use a cada conjunto de registros para manipular registros...|Conjuntos de registros se baseiam as classes derivadas de [CRecordset](../mfc/reference/crecordset-class.md) com os assistentes.|ODBC usa registrar troca de campos (RFX) para trocar dados entre o banco de dados e membros de dados de campo do seu conjunto de registros. Se você estiver usando uma exibição de registro, a troca de dados de caixa de diálogo (DDX) troca dados entre os controles no modo de exibição de registro e o conjunto de registros.|
|... ou crie um explícito [CDatabase](../mfc/reference/cdatabase-class.md) em seu código para cada banco de dados que você deseja abrir.|Os objetos de conjunto de registros de base nos objetos de banco de dados.|O objeto de banco de dados fornece uma interface para a fonte de dados.|
|Associe colunas de dados a seu conjunto de registros dinamicamente.|No ODBC, adicione código à sua classe derivada do conjunto de registros para gerenciar a associação. Consulte o artigo [conjunto de registros: Associando dinamicamente colunas de dados (ODBC)](../data/odbc/recordset-dynamically-binding-data-columns-odbc.md).||

## <a name="see-also"></a>Consulte também

[Compilando no Framework](../mfc/building-on-the-framework.md)<br/>
[Sequência de operações para compilar aplicativos MFC](../mfc/sequence-of-operations-for-building-mfc-applications.md)<br/>
[Sequência de operações para a criação de aplicativos OLE](../mfc/sequence-of-operations-for-creating-ole-applications.md)<br/>
[Sequência de operações para criação de controles ActiveX](../mfc/sequence-of-operations-for-creating-activex-controls.md)
