---
title: Dynaset | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- ODBC recordsets, dynasets
- ODBC cursor library [ODBC], dynasets
- keyset-driven cursors in dynasets
- cursors [ODBC], keyset-driven cursors in dynasets
- cursor library [ODBC], dynaset availability
- recordsets [C++], dynasets
- dynasets
ms.assetid: 2867e6be-208e-4fe7-8bbe-b8697cb1045c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: fb7af1771f6aafbc8732ed3b0d87b271fcee0128
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50056848"
---
# <a name="dynaset"></a>Dynaset

Este tópico descreve dynasets e discute sua [disponibilidade](#_core_availability_of_dynasets).

> [!NOTE]
>  Este tópico se aplica às classes ODBC do MFC, incluindo [CRecordset](../../mfc/reference/crecordset-class.md). Para obter informações sobre dynasets nas classes DAO, consulte [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md). Com o DAO, você pode abrir os conjuntos de registros do tipo dynaset.

Dynaset é um conjunto de registros com propriedades dinâmicas. Durante seu ciclo de vida, um objeto de conjunto de registros no modo de dynaset (normalmente chamado de dynaset) permanece sincronizado com a fonte de dados da seguinte maneira. Em um ambiente multiusuário, outros usuários podem editar ou excluir registros que estão no seu dynaset ou adicionar registros à tabela que seu dynaset representa. Registros de seu aplicativo adiciona ou exclui o conjunto de registros são refletidos no seu dynaset. Os registros que outros usuários a adicionar à tabela não serão refletidos no seu dynaset até que você recompilar o dynaset chamando seu `Requery` função de membro. Quando outros usuários excluírem registros, código MFC ignora as exclusões de conjunto de registros. Alterações de edição de outros usuários para os registros existentes são refletidas no seu dynaset tão logo você rolar para o registro afetado.

Da mesma forma, as edições feitas a registros em um dynaset são refletidas em dynasets em uso por outros usuários. Registros que você adicionar não serão refletidos em dynasets de outros usuários até que eles requery seus dynasets. Registros que você excluir são marcados como "excluído" em conjuntos de registros de outros usuários. Se você tiver várias conexões com o mesmo banco de dados (várias `CDatabase` objetos), conjuntos de registros associados a essas conexões têm o mesmo status como os conjuntos de registros de outros usuários.

Dynasets são mais eficientes quando os dados devem ser dinâmicos, como (por exemplo) em um sistema de reserva de companhia aérea.

> [!NOTE]
> Para usar dynasets, você deve ter um driver ODBC para sua fonte de dados que dá suporte a dynasets e a biblioteca de cursores ODBC não deve ser carregada. Para obter mais informações, consulte [disponibilidade de Dynasets](#_core_availability_of_dynasets).

Para especificar que um conjunto de registros é dynaset, passe `CRecordset::dynaset` como o primeiro parâmetro para o `Open` a função de membro de seu objeto de conjunto de registros.

> [!NOTE]
> Para dynasets atualizáveis, o driver ODBC deve oferecer suporte das instruções de atualização posicionada ou o `::SQLSetPos` função ODBC API. Se ambos forem compatíveis, o MFC usa `::SQLSetPos` para maior eficiência.

##  <a name="_core_availability_of_dynasets"></a> Disponibilidade de Dynasets

As classes de banco de dados MFC suportam dynasets se os seguintes requisitos forem atendidos:

- A biblioteca de cursores ODBC DLL não deve estar em uso para esta fonte de dados.

   Se a biblioteca de cursores for usada, ele mascara alguma funcionalidade do driver ODBC subjacente que é necessário para suporte de dynaset. Se você deseja usar dynasets (e o driver ODBC tem a funcionalidade necessária para dynasets, conforme descrito no restante desta seção), você pode fazer com que MFC para não carregar a biblioteca de cursores quando você cria um `CDatabase` objeto. Para obter mais informações, consulte [ODBC](../../data/odbc/odbc-basics.md) e o [OpenEx](../../mfc/reference/cdatabase-class.md#openex) ou [abrir](../../mfc/reference/cdatabase-class.md#open) função membro da classe `CDatabase`.

   Na terminologia do ODBC, dynasets e os instantâneos são denominados cursores. Um cursor é um mecanismo usado para controlar sua posição em um conjunto de registros.

- O driver ODBC para sua fonte de dados deve dar suporte a cursores controlados por conjunto de chaves.

   Cursores controlados por gerenciar dados de uma tabela, obter e armazenar um conjunto de chaves. As chaves são usadas para obter os dados atuais da tabela quando o usuário rolar até um determinado registro. Para determinar se o driver dá esse suporte, chame o `::SQLGetInfo` função de API do ODBC com o *SQL_SCROLL_OPTIONS* parâmetro.

   Se você tentar abrir um dynaset sem suporte para o conjunto de chaves, você obterá um `CDBException` AFX_SQL_ERROR_DYNASET_NOT_SUPPORTED de valor com o código de retorno.

- O driver ODBC para sua fonte de dados deve dar suporte a busca estendido.

   Buscando estendido é a capacidade de rolar para trás, bem como encaminhar nos registros resultantes da consulta SQL. Para determinar se o driver dá suporte a essa capacidade, chame o `::SQLGetFunctions` função de API do ODBC com o *SQL_API_SQLEXTENDEDFETCH* parâmetro.

Se você quiser atualizável dynasets (ou instantâneos, de fato), o driver ODBC também deve suportar qualquer um de `::SQLSetPos` atualizações posicionadas ou função de API de ODBC. O `::SQLSetPos` função permite que o MFC atualizar a fonte de dados sem enviar instruções SQL. Se esse suporte está disponível, o MFC o usa em preferência fazendo atualizações usando o SQL. Para determinar se o seu driver suporta `::SQLSetPos`, chame `::SQLGetInfo` com o *SQL_POS_OPERATIONS* parâmetro.

Atualizações posicionadas usam a sintaxe SQL (do formulário **WHERE CURRENT OF** \<cursorname >) para identificar uma linha específica na tabela na fonte de dados. Para determinar se o driver dá suporte a atualizações posicionadas, chame `::SQLGetInfo` com o *SQL_POSITIONED_STATEMENTS* parâmetro.

Em geral, o MFC dynasets (mas não apenas de encaminhamento de conjuntos de registros) exigem um driver ODBC com conformidade de API de nível 2. Se o driver de fonte de dados está em conformidade com o conjunto de APIs de nível 1, você ainda pode usar instantâneos atualizáveis tanto como somente leitura e somente de encaminhamento de conjuntos de registros, mas não dynasets. No entanto, um driver de nível 1 pode dar suporte a dynasets se ele dá suporte à busca estendido e cursores controlados por conjunto de chaves. Para obter mais informações sobre os níveis de conformidade com ODBC, consulte [ODBC](../../data/odbc/odbc-basics.md).

> [!NOTE]
> Se você quiser usar instantâneos e dynasets, você deve baseá-los em dois diferentes `CDatabase` objetos (duas conexões diferentes).

Ao contrário de instantâneos, que usam o armazenamento intermediário mantido pela biblioteca de cursores ODBC, dynasets buscar um registro diretamente da fonte de dados assim que você rola a ele. Isso impede que os registros que originalmente selecionados pelo dynaset sincronizado com a fonte de dados.

Para obter uma lista de drivers ODBC incluídos nesta versão do Visual C++ e para obter informações sobre como obter drivers adicionais, consulte [lista de drivers ODBC](../../data/odbc/odbc-driver-list.md).

## <a name="see-also"></a>Consulte também

[ODBC (conectividade de banco de dados aberto)](../../data/odbc/open-database-connectivity-odbc.md)