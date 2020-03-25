---
title: Troca de dados para exibições de registro (Acesso a dados MFC)
ms.date: 11/19/2018
helpviewer_keywords:
- RFX (record field exchange), data exchange mechanism
- RFX (record field exchange), record views
- record views, data exchange
- DDX (dialog data exchange), record views
- RFX (record field exchange)
ms.assetid: abc52ca7-6997-47a7-98f3-f347f52b1f72
ms.openlocfilehash: f9f460305b55a2313b64effdf4d1dbbfd9823def
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213456"
---
# <a name="data-exchange-for-record-views---mfc-data-access"></a>Troca de dados para exibições de registro (Acesso a dados MFC)

Quando você usa [Adicionar classe](../mfc/reference/adding-an-mfc-odbc-consumer.md) para mapear os controles no recurso de modelo de caixa de diálogo de uma exibição de registro para os campos de um conjunto de registros, a estrutura gerencia a troca de dados em ambas as direções — do conjunto de registros para controles e de controles para o conjunto de registros. O uso do mecanismo DDX significa que você não precisa escrever o código para transferir os dados de um para outro lado por conta própria.

CAMPO DDX para exibições de registro funcionam em conjunto com [suporte RFX](../data/odbc/record-field-exchange-rfx.md) para conjuntos de registros da classe `CRecordset` (ODBC).  SUPORTE RFX move dados entre o registro atual da fonte de dados e os membros de dados de campo de um objeto Recordset. DDX move os dados de membros de dados de campo para os controles no formulário. Essa combinação preenche os controles do formulário inicialmente e conforme o usuário é movido de registro em registro. Ela também pode mover dados atualizados de volta ao conjunto de registros e, em seguida, para a fonte de dados.

A figura a seguir mostra a relação entre campo DDX e suporte RFX para exibições de registro.

![Troca&#45;de dados de caixa&#45;de diálogo e registro de troca de campo](../data/media/vc37xt1.gif "Troca&#45;de dados de caixa&#45;de diálogo e registro de troca de campo")<br/>
Troca de dados de diálogo e troca de campos de registro

Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](../mfc/dialog-data-exchange-and-validation.md). Para obter mais informações sobre suporte RFX, consulte [Record Field Exchange (suporte RFX)](../data/odbc/record-field-exchange-rfx.md).

## <a name="see-also"></a>Confira também

[Exibição de registro (Acesso a dados MFC)](../data/record-views-mfc-data-access.md)<br/>
[Lista de drivers ODBC](../data/odbc/odbc-driver-list.md)
