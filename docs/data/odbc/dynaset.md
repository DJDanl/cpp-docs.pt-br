---
title: Dynaset
ms.date: 11/04/2016
helpviewer_keywords:
- ODBC recordsets, dynasets
- ODBC cursor library [ODBC], dynasets
- keyset-driven cursors in dynasets
- cursors [ODBC], keyset-driven cursors in dynasets
- cursor library [ODBC], dynaset availability
- recordsets [C++], dynasets
- dynasets
ms.assetid: 2867e6be-208e-4fe7-8bbe-b8697cb1045c
ms.openlocfilehash: ed7098600126005978c8b017e7db378fca4c1a68
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213233"
---
# <a name="dynaset"></a>Dynaset

Este tópico descreve os dynasets e discute sua [disponibilidade](#_core_availability_of_dynasets).

> [!NOTE]
>  Este tópico aplica-se às classes ODBC do MFC, incluindo [CRecordset](../../mfc/reference/crecordset-class.md). Para obter informações sobre os dynasets nas classes DAO, consulte [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md). Com o DAO, você pode abrir conjuntos de registros de tipo dynaset.

Um dynaset é um conjunto de registros com propriedades dinâmicas. Durante seu tempo de vida, um objeto Recordset no modo dynaset (geralmente chamado de dynaset) permanece sincronizado com a fonte de dados da seguinte maneira. Em um ambiente multiusuário, outros usuários podem editar ou excluir registros que estão em seu dynaset ou adicionar registros à tabela que seu dynaset representa. Registra que seu aplicativo adiciona ou exclui do conjunto de registros é refletido em seu dynaset. Os registros que outros usuários adicionam à tabela não serão refletidos no seu dynaset até que você reconstrua o dynaset chamando sua função de membro `Requery`. Quando outros usuários excluem registros, o código do MFC ignora as exclusões no conjunto de registros. As alterações de edição de outros usuários em registros existentes são refletidas em seu dynaset assim que você rola para o registro afetado.

Da mesma forma, as edições feitas nos registros em um dynaset são refletidas em dynasets em uso por outros usuários. Os registros que você adicionar não serão refletidos nos dynasets dos outros usuários até que eles Refaçam seus dynasets. Os registros excluídos são marcados como "excluídos" nos conjuntos de registros de outros usuários. Se você tiver várias conexões com o mesmo banco de dados (vários objetos `CDatabase`), os conjuntos de registros associados a essas conexões terão o mesmo status que os conjuntos de registros de outros usuários.

Os dynasets são mais valiosos quando os dados devem ser dinâmicos, como (por exemplo) em um sistema de reserva de viagens.

> [!NOTE]
> Para usar dynasets, você deve ter um driver ODBC para sua fonte de dados que ofereça suporte a dynasets e a biblioteca de cursores ODBC não deve ser carregada. Para obter mais informações, consulte [disponibilidade de dynasets](#_core_availability_of_dynasets).

Para especificar que um conjunto de registros é um dynaset, passe `CRecordset::dynaset` como o primeiro parâmetro para a função de membro `Open` do seu objeto Recordset.

> [!NOTE]
> Para dynasets atualizáveis, o driver ODBC deve dar suporte a ambas as instruções de atualização posicionadas ou a `::SQLSetPos` função da API ODBC. Se ambos tiverem suporte, o MFC usará `::SQLSetPos` para obter eficiência.

##  <a name="availability-of-dynasets"></a><a name="_core_availability_of_dynasets"></a>Disponibilidade de dynasets

As classes de banco de dados MFC dão suporte a dynasets se os seguintes requisitos forem atendidos:

- A DLL da biblioteca de cursores ODBC não deve estar em uso para esta fonte de dados.

   Se a biblioteca de cursores for usada, ela Mascarará algumas funcionalidades do driver ODBC subjacente necessário para o suporte a dynaset. Se você quiser usar dynasets (e o driver ODBC tiver a funcionalidade necessária para dynasets, conforme descrito no restante desta seção), você poderá fazer com que o MFC não carregue a biblioteca de cursores ao criar um objeto de `CDatabase`. Para obter mais informações, consulte [ODBC](../../data/odbc/odbc-basics.md) e a função de membro [OpenEx](../../mfc/reference/cdatabase-class.md#openex) ou [Open](../../mfc/reference/cdatabase-class.md#open) Member da classe `CDatabase`.

   Na terminologia ODBC, os dynasets e os instantâneos são chamados de cursores. Um cursor é um mecanismo usado para manter o controle de sua posição em um conjunto de registros.

- O driver ODBC para sua fonte de dados deve dar suporte a cursores controlados por conjunto de chaves.

   Os cursores controlados por conjunto de chaves gerenciam dados de uma tabela obtendo e armazenando um conjunto de chave. As chaves são usadas para obter dados atuais da tabela quando o usuário rola para um registro específico. Para determinar se o driver fornece esse suporte, chame a função `::SQLGetInfo` API ODBC com o parâmetro *SQL_SCROLL_OPTIONS* .

   Se você tentar abrir um dynaset sem suporte a conjunto de chaves, obterá uma `CDBException` com o valor do código de retorno AFX_SQL_ERROR_DYNASET_NOT_SUPPORTED.

- O driver ODBC para sua fonte de dados deve dar suporte à busca estendida.

   A busca estendida é a capacidade de rolar para trás, bem como para frente nos registros resultantes de sua consulta SQL. Para determinar se o driver dá suporte a essa capacidade, chame a função `::SQLGetFunctions` API do ODBC com o parâmetro *SQL_API_SQLEXTENDEDFETCH* .

Se você quiser dynasets atualizáveis (ou instantâneos, para esse assunto), o driver ODBC também deve oferecer suporte à função de API ODBC `::SQLSetPos` ou a atualizações posicionadas. A função `::SQLSetPos` permite que o MFC atualize a fonte de dados sem enviar instruções SQL. Se esse suporte estiver disponível, o MFC o usará em preferência para fazer atualizações usando o SQL. Para determinar se o driver dá suporte a `::SQLSetPos`, chame `::SQLGetInfo` com o parâmetro *SQL_POS_OPERATIONS* .

As atualizações posicionadas usam a sintaxe SQL (do formulário **em que o atual do** \<cursorname >) para identificar uma linha específica na tabela na fonte de dados. Para determinar se o driver dá suporte a atualizações posicionadas, chame `::SQLGetInfo` com o parâmetro *SQL_POSITIONED_STATEMENTS* .

Geralmente, os dynasets do MFC (mas não os conjuntos de registros somente de encaminhamento) exigem um driver ODBC com conformidade de API de nível 2. Se o driver da fonte de dados estiver em conformidade com o conjunto de API de nível 1, você ainda poderá usar instantâneos atualizáveis e somente leitura e conjuntos de registros somente de encaminhamento, mas não os dynasets. No entanto, um driver de nível 1 pode dar suporte a dynasets se ele der suporte a busca estendida e cursores controlados por conjunto de chaves. Para obter mais informações sobre os níveis de conformidade ODBC, consulte [ODBC](../../data/odbc/odbc-basics.md).

> [!NOTE]
> Se você quiser usar instantâneos e dynasets, deverá baseá-los em dois objetos de `CDatabase` diferentes (duas conexões diferentes).

Ao contrário dos instantâneos, que usam o armazenamento intermediário mantido pela biblioteca de cursores ODBC, os dynasets buscam um registro diretamente da fonte de dados assim que você rola para ele. Isso mantém os registros selecionados originalmente pelo dynaset sincronizados com a fonte de dados.

Para ver uma lista de drivers ODBC incluídos nesta versão do Visual C++ e para saber como obter outros drivers, confira [Lista de Drivers ODBC](../../data/odbc/odbc-driver-list.md).

## <a name="see-also"></a>Confira também

[ODBC (conectividade de banco de dados aberto)](../../data/odbc/open-database-connectivity-odbc.md)
