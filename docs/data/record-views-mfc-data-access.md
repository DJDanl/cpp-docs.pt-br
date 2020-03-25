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
ms.openlocfilehash: 31dbd92219f263c625050524279b97ef38ba9ba1
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80209125"
---
# <a name="record-views--mfc-data-access"></a>Exibição de registro (Acesso a dados MFC)

Esta seção aplica-se somente às classes ODBC do MFC. Para obter informações sobre OLE DB exibições de registro, consulte [COleDBRecordView](../mfc/reference/coledbrecordview-class.md) e [usando OLE DB exibições de registro](../data/oledb/using-ole-db-record-views.md).

Para oferecer suporte a aplicativos de acesso a dados baseados em formulário, a biblioteca de classes fornece a classe [CRecordView](../mfc/reference/crecordview-class.md). Uma exibição de registro é um objeto de exibição de formulário cujos controles são mapeados diretamente para os membros de dados de campo de um objeto [Recordset](../data/odbc/recordset-odbc.md) (e indiretamente para as colunas correspondentes em um resultado de consulta ou tabela na fonte de dados). Como sua classe base [CFormView](../mfc/reference/cformview-class.md), `CRecordView` se baseia em um recurso de modelo de caixa de diálogo.

## <a name="form-uses"></a>Usos do formulário

Formulários são úteis para uma variedade de tarefas de acesso a dados:

- Inserir dados

- Executar um exame de somente leitura de dados

- Atualizar dados

## <a name="further-reading-about-record-views"></a>Ler mais sobre as exibições de registro

O material nos tópicos aplicam-se a classes baseadas em ODBC e baseadas em DAO. Use `CRecordView` para ODBC e `CDaoRecordView` para DAO.

Os tópicos incluem:

- [Recursos das classes de exibição de registro](../data/features-of-record-view-classes-mfc-data-access.md)

- [Troca de dados para exibições de registro](../data/data-exchange-for-record-views-mfc-data-access.md)

- [Sua função no trabalho com uma exibição de registro](../data/your-role-in-working-with-a-record-view-mfc-data-access.md)

- [Criando e criando uma exibição de registro](../data/designing-and-creating-a-record-view-mfc-data-access.md)

- [Usando uma exibição de registro](../data/using-a-record-view-mfc-data-access.md)

## <a name="see-also"></a>Confira também

[Programação de Acesso a Dados (MFC/ATL)](../data/data-access-programming-mfc-atl.md)<br/>
[Lista de drivers ODBC](../data/odbc/odbc-driver-list.md)
