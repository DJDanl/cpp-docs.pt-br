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
ms.openlocfilehash: 2eb2447d1f984b7734d5e9c45087023e5a6f003f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371834"
---
# <a name="dynaset"></a>Dynaset

Este tópico descreve dynasets e discute sua [disponibilidade](#_core_availability_of_dynasets).

> [!NOTE]
> Este tópico se aplica às classes MFC ODBC, incluindo [CRecordset](../../mfc/reference/crecordset-class.md). Para obter informações sobre dynasets nas classes DAO, consulte [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md). Com o DAO, você pode abrir conjuntos de discos do tipo dynaset.

Um dynaset é um conjunto de registros com propriedades dinâmicas. Durante sua vida útil, um objeto de conjunto de registros no modo dynaset (geralmente chamado de dynaset) permanece sincronizado com a fonte de dados da seguinte maneira. Em um ambiente multiusuário, outros usuários podem editar ou excluir registros que estão em seu dynaset ou adicionar registros à tabela que seu dynaset representa. Os registros que seu aplicativo adiciona ou exclui do conjunto de registros são refletidos no seu dynaset. Os registros que outros usuários adicionam à tabela não serão refletidos em seu `Requery` dynaset até que você reconstrua o dynaset chamando sua função de membro. Quando outros usuários excluem registros, o código MFC ignora as exclusões em seu conjunto de registros. As alterações de edição de outros usuários nos registros existentes são refletidas no seu dynaset assim que você rola para o registro afetado.

Da mesma forma, as edições que você faz para registros em um dynaset são refletidas em dynasets em uso por outros usuários. Os registros adicionados não são refletidos nos dynasets de outros usuários até que eles adicionem seus dynasets. Os registros excluídos são marcados como "excluídos" nos conjuntos de registros de outros usuários. Se você tiver várias conexões `CDatabase` com o mesmo banco de dados (vários objetos), os conjuntos de registros associados a essas conexões têm o mesmo status que os conjuntos de registros de outros usuários.

Os dynasets são mais valiosos quando os dados devem ser dinâmicos, como (por exemplo) em um sistema de reservas aéreas.

> [!NOTE]
> Para usar dynasets, você deve ter um driver ODBC para sua fonte de dados que suporte dynasets e a biblioteca de cursor ODBC não deve ser carregada. Para obter mais informações, consulte [Disponibilidade de Dynasets](#_core_availability_of_dynasets).

Para especificar que um conjunto de `CRecordset::dynaset` registros é um dynaset, passe como o primeiro parâmetro para a `Open` função membro do objeto recordset.

> [!NOTE]
> Para dynasets updatable, o driver ODBC deve suportar `::SQLSetPos` instruções de atualização posicionadas ou a função API ODBC. Se ambos forem suportados, o MFC usa `::SQLSetPos` para eficiência.

## <a name="availability-of-dynasets"></a><a name="_core_availability_of_dynasets"></a>Disponibilidade de Dynasets

As classes de banco de dados MFC suportam dynasets se os seguintes requisitos forem atendidos:

- A biblioteca de cursor ODBC DLL não deve estar em uso para esta fonte de dados.

   Se a biblioteca do cursor for usada, ela mascara algumas funcionalidades do driver ODBC subjacente que é necessária para o suporte a dynaset. Se você quiser usar dynasets (e seu driver ODBC tiver a funcionalidade necessária para dynasets, como descrito no resto desta seção), você pode fazer com que o MFC não carregue a biblioteca do cursor quando você criar um `CDatabase` objeto. Para obter mais informações, consulte [o ODBC](../../data/odbc/odbc-basics.md) e `CDatabase`a função de membro [OpenEx](../../mfc/reference/cdatabase-class.md#openex) ou [Open](../../mfc/reference/cdatabase-class.md#open) da classe .

   Na terminologia ODBC, dynasets e snapshots são chamados de cursores. Um cursor é um mecanismo usado para manter o controle de sua posição em um conjunto de registros.

- O driver ODBC para sua fonte de dados deve suportar cursores orientados por chave.

   Os cursores orientados por keyset gerenciam dados de uma tabela, obtendo e armazenando um conjunto de chaves. As teclas são usadas para obter dados atuais da tabela quando o usuário rola para um registro específico. Para determinar se o driver fornece `::SQLGetInfo` esse suporte, ligue para a função API do ODBC com o parâmetro *SQL_SCROLL_OPTIONS.*

   Se você tentar abrir um dynaset sem `CDBException` suporte a chave, você receberá um com o valor do código de retorno AFX_SQL_ERROR_DYNASET_NOT_SUPPORTED.

- O driver ODBC para sua fonte de dados deve suportar a busca estendida.

   Busca estendida é a capacidade de rolar para trás, bem como para a frente sobre os registros resultantes de sua consulta SQL. Para determinar se o driver suporta `::SQLGetFunctions` essa capacidade, ligue para a função API do ODBC com o parâmetro *SQL_API_SQLEXTENDEDFETCH.*

Se você quiser dynasets atualizáveis (ou snapshots, por falar nisso), `::SQLSetPos` o driver ODBC também deve suportar a função API oDBC ou atualizações posicionadas. A `::SQLSetPos` função permite que o MFC atualize a fonte de dados sem enviar instruções SQL. Se esse suporte estiver disponível, o MFC o usará em preferência para fazer atualizações usando SQL. Para determinar se o `::SQLSetPos`driver `::SQLGetInfo` suporta, ligue com o parâmetro *SQL_POS_OPERATIONS.*

As atualizações posicionadas usam sintaxe SQL (do formulário **ONDE o atual** \<nome do cursor>) para identificar uma linha específica na tabela na fonte de dados. Para determinar se o driver suporta atualizações posicionadas, ligue com `::SQLGetInfo` o parâmetro *SQL_POSITIONED_STATEMENTS.*

Geralmente, os dynasets MFC (mas não apenas para a frente) exigem um driver ODBC com conformidade aPI nível 2. Se o driver para sua fonte de dados estiver em conformidade com o conjunto de API nível 1, você ainda poderá usar instantâneos atualizáveis e somente leitura e conjuntos de registros somente para a frente, mas não dynasets. No entanto, um driver de nível 1 pode suportar dinamismos se suportar cursores de busca estendida e de conjunto. Para obter mais informações sobre os níveis de conformidade da ODBC, consulte [ODBC](../../data/odbc/odbc-basics.md).

> [!NOTE]
> Se você quiser usar instantâneos e dynasets, você `CDatabase` deve baseá-los em dois objetos diferentes (duas conexões diferentes).

Ao contrário dos snapshots, que usam armazenamento intermediário mantido pela biblioteca de cursor oDBC, os dynasets buscam um registro diretamente da fonte de dados assim que você rola até ele. Isso mantém os registros originalmente selecionados pelo dynaset sincronizados com a fonte de dados.

Para ver uma lista de drivers ODBC incluídos nesta versão do Visual C++ e para saber como obter outros drivers, confira [Lista de Drivers ODBC](../../data/odbc/odbc-driver-list.md).

## <a name="see-also"></a>Confira também

[Conectividade de banco de dados aberto (ODBC)](../../data/odbc/open-database-connectivity-odbc.md)
