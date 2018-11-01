---
title: Exibição de registro (Acesso a dados MFC)
ms.date: 11/04/2016
helpviewer_keywords:
- MFC [C++], record views
- ODBC recordsets [C++], record views
- databases [C++], record views
- record views [C++]
- forms [C++], data access tasks
ms.assetid: 562122d9-01d8-4284-acf6-ea109ab0408d
ms.openlocfilehash: 155a7e4de6272f13d12ab2a64cba190a184f62cf
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50588481"
---
# <a name="record-views--mfc-data-access"></a>Exibição de registro (Acesso a dados MFC)

Esta seção se aplica apenas às classes ODBC do MFC. Para obter informações sobre exibições de registro do OLE DB, consulte [COleDBRecordView](../mfc/reference/coledbrecordview-class.md) e [usando o OLE DB exibições de registro](../data/oledb/using-ole-db-record-views.md).

Para dar suporte a aplicativos de acesso a dados baseado em formulário, a biblioteca de classes fornece a classe [CRecordView](../mfc/reference/crecordview-class.md). Uma exibição de registro é um objeto de exibição de formulário cujos controles são mapeados diretamente para os membros de dados do campo de um [recordset](../data/odbc/recordset-odbc.md) objeto (e indiretamente para as colunas correspondentes em uma tabela na fonte de dados ou o resultado da consulta). Como sua classe base [CFormView](../mfc/reference/cformview-class.md), `CRecordView` baseia-se em um recurso de modelo de caixa de diálogo.

## <a name="form-uses"></a>Usos do formulário

Formulários são úteis para uma variedade de tarefas de acesso a dados:

- Inserir dados

- Executar um exame de somente leitura de dados

- Atualizando dados

## <a name="further-reading-about-record-views"></a>Ler mais sobre as exibições de registro

O material nos tópicos aplicam-se a classes baseadas em ODBC e baseadas em DAO. Use `CRecordView` para ODBC e `CDaoRecordView` para DAO.

Os tópicos incluem:

- [Recursos das Classes de exibição de registro](../data/features-of-record-view-classes-mfc-data-access.md)

- [Troca de dados para exibições de registro](../data/data-exchange-for-record-views-mfc-data-access.md)

- [A função no trabalho com uma exibição de registro](../data/your-role-in-working-with-a-record-view-mfc-data-access.md)

- [Projetando e criando uma exibição de registro](../data/designing-and-creating-a-record-view-mfc-data-access.md)

- [Usando uma exibição de registro](../data/using-a-record-view-mfc-data-access.md)

## <a name="see-also"></a>Consulte também

[Acesso a dados (MFC/ATL) de programação](../data/data-access-programming-mfc-atl.md)<br/>
[Lista de drivers ODBC](../data/odbc/odbc-driver-list.md)