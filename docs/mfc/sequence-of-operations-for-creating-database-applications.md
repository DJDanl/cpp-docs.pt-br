---
title: Sequência de operações para criação de aplicativos de banco de dados | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- applications [MFC], database
- database applications [MFC]
- database applications [MFC], creating
- MFC, database applications
ms.assetid: 9371da59-8536-43cd-8314-706ad320e2ec
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: cbe18e9733388cc6e43f6ca3de520596c713b783
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33381323"
---
# <a name="sequence-of-operations-for-creating-database-applications"></a>Sequência de operações para criação de aplicativos de banco de dados
A tabela a seguir mostra a função e a função da estrutura em escrever aplicativos de banco de dados.  
  
> [!NOTE]
>  Os assistentes e o ambiente do Visual C++ não dão suporte DAO (embora as classes DAO estão incluídas e você ainda pode usá-los). A Microsoft recomenda que você use o ODBC para novos projetos MFC. Você só deve usar DAO na manutenção de aplicativos existentes.  
  
### <a name="creating-database-applications"></a>Criando aplicativos de banco de dados  
  
|Tarefa|Fazer|A estrutura faz|  
|----------|------------|------------------------|  
|Decida se deseja usar as classes MFC ODBC ou DAO.|Use o ODBC para novos projetos MFC. Use DAO somente para manter os aplicativos existentes. Para obter informações gerais, consulte o artigo [programação de acesso de dados](../data/data-access-programming-mfc-atl.md).|O framework fornece classes que oferecem suporte a acesso de banco de dados.|  
|Crie seu aplicativo de esqueleto com opções de banco de dados.|Execute o Assistente de aplicativo do MFC. Selecione as opções na página de suporte do banco de dados. Se você escolher uma opção que cria uma exibição de registro, também especifica:<br /><br /> -Nome da tabela e a fonte de dados ou nomes<br />-Nome ou nomes de consulta.|O Assistente de aplicativo MFC cria arquivos e especifica que inclui o necessário. Dependendo das opções que você especificar, os arquivos podem incluir uma classe de conjunto de registros.|  
|Crie banco de dados formulário ou formulários.|Use o editor de caixa de diálogo Visual C++ para posicionar controles nos recursos de modelo de caixa de diálogo para as classes de exibição de registro.|O Assistente de aplicativo MFC cria um recurso de modelo de caixa de diálogo vazia para preencher.|  
|Crie classes de exibição e o conjunto de registros registro adicionais conforme necessário.|Use o modo de exibição de classe para criar as classes e a caixa de diálogo editor para os modos de exibição de design.|Exibição de classe cria arquivos adicionais para as novas classes.|  
|Crie objetos de conjunto de registros conforme necessário em seu código. Use cada conjunto de registros para manipular registros...|Conjuntos de registros baseiam-se as classes derivadas de [CRecordset](../mfc/reference/crecordset-class.md) com os assistentes.|ODBC usa a troca de campos de registro (RFX) para trocar dados entre o banco de dados e os membros de dados de campo do seu conjunto de registros. Se você estiver usando uma exibição de registro, a troca de dados de caixa de diálogo (DDX) troca dados entre os controles no modo de exibição de registro e o conjunto de registros.|  
|.... ou criar uma explícita [CDatabase](../mfc/reference/cdatabase-class.md) em seu código para cada banco de dados que você deseja abrir.|Os objetos de conjunto de registros de base nos objetos de banco de dados.|O objeto de banco de dados fornece uma interface para a fonte de dados.|  
|Vincule dinamicamente colunas de dados para o conjunto de registros.|No ODBC, adicione o código em sua classe derivada do conjunto de registros para gerenciar a associação. Consulte o artigo [conjunto de registros: dinamicamente de associação de dados colunas (ODBC)](../data/odbc/recordset-dynamically-binding-data-columns-odbc.md).||  
  
## <a name="see-also"></a>Consulte também  
 [Compilando no Framework](../mfc/building-on-the-framework.md)   
 [Sequência de operações para criação de aplicativos MFC](../mfc/sequence-of-operations-for-building-mfc-applications.md)   
 [Sequência de operações para criação de aplicativos OLE](../mfc/sequence-of-operations-for-creating-ole-applications.md)   
 [Sequência de operações para criação de controles ActiveX](../mfc/sequence-of-operations-for-creating-activex-controls.md)
