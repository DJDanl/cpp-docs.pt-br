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
ms.openlocfilehash: ec71b5b00b26564f9c8dc3c2d98f53f8182b0ca3
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33092312"
---
# <a name="dynaset"></a>Dynaset
Este tópico descreve dynasets e descreve seus [disponibilidade](#_core_availability_of_dynasets).  
  
> [!NOTE]
>  Este tópico se aplica a classes MFC ODBC, incluindo [CRecordset](../../mfc/reference/crecordset-class.md). Para obter informações sobre dynasets nas classes DAO, consulte [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md). Com DAO, você pode abrir o conjunto de registros do tipo dynaset.  
  
 Dynaset é um conjunto de registros com propriedades dinâmicas. Durante seu ciclo de vida, um objeto de conjunto de registros no modo de dynaset (geralmente chamado de dynaset) permanece sincronizado com a fonte de dados da seguinte maneira. Em um ambiente multiusuário, outros usuários podem editar ou excluir registros que estão em sua dynaset ou adicionar registros à tabela que representa o dynaset. Registra o aplicativo adiciona ou exclui o conjunto de registros é refletidas no seu dynaset. Os registros que outros usuários adicionarem à tabela não serão refletidos no seu dynaset até que você recria o dynaset chamando seu **Requery** função de membro. Quando outros usuários exclui registros, código MFC ignora as exclusões de registros. Alterações de edição de outros usuários para os registros existentes são refletidas no seu dynaset assim que você rola para o registro afetado.  
  
 Da mesma forma, as edições feitas a registros em um dynaset são refletidas em dynasets em uso por outros usuários. Adicionar os registros não serão refletidos em dynasets de outros usuários até que eles requery seus dynasets. Excluir os registros são marcados como "excluído" em conjuntos de registros de outros usuários. Se você tiver várias conexões com o mesmo banco de dados (várias `CDatabase` objetos), conjuntos de registros associados a essas conexões com o mesmo status como conjuntos de registros de outros usuários.  
  
 Dynasets são mais valiosas quando os dados devem ser dinâmicos, como (por exemplo) em um sistema de reserva aérea.  
  
> [!NOTE]
>  Para usar dynasets, você deve ter um driver ODBC para sua fonte de dados que suporta dynasets e a biblioteca de cursores ODBC não deve ser carregada. Para obter mais informações, consulte [disponibilidade de Dynasets](#_core_availability_of_dynasets).  
  
 Para especificar um conjunto de registros é dynaset, passe **CRecordset::dynaset** como o primeiro parâmetro para o **abrir** função membro de seu objeto de conjunto de registros.  
  
> [!NOTE]
>  Para dynasets atualizáveis, o driver ODBC deve dar suporte das instruções update posicionadas ou **:: SQLSetPos** função da API do ODBC. Se ambos são suportadas, MFC usa **:: SQLSetPos** para maior eficiência.  
  
##  <a name="_core_availability_of_dynasets"></a> Disponibilidade de Dynasets  
 As classes de banco de dados MFC suportam dynasets se os seguintes requisitos são atendidos:  
  
-   A biblioteca de cursores ODBC DLL não deve estar em uso para esta fonte de dados.  
  
     Se a biblioteca de cursores for usada, ele mascara alguma funcionalidade do ODBC driver subjacente que é necessário para suporte de dynaset. Se você deseja usar dynasets (e o driver ODBC tem a funcionalidade necessária para dynasets, conforme descrito no restante desta seção), você poderá causar MFC para não carregar a biblioteca de cursores quando você cria um `CDatabase` objeto. Para obter mais informações, consulte [ODBC](../../data/odbc/odbc-basics.md) e [OpenEx](../../mfc/reference/cdatabase-class.md#openex) ou [abrir](../../mfc/reference/cdatabase-class.md#open) função de membro de classe `CDatabase`.  
  
     Na terminologia ODBC, dynasets e instantâneos são denominados cursores. Um cursor é um mecanismo usado para controlar sua posição em um conjunto de registros.  
  
-   O driver ODBC para a fonte de dados deve oferecer suporte a cursores controlados por conjunto de chaves.  
  
     Os cursores controlados por conjuntos de chaves gerenciam dados de uma tabela Obtendo e armazenar um conjunto de chaves. As chaves são usadas para obter os dados atuais da tabela quando o usuário rolar para um determinado registro. Para determinar se o driver oferece esse suporte, chame o **:: SQLGetInfo** a função de API de ODBC com o **SQL_SCROLL_OPTIONS** parâmetro.  
  
     Se você tentar abrir um dynaset sem suporte do conjunto de chaves, você receberá um `CDBException` com o valor de código de retorno **AFX_SQL_ERROR_DYNASET_NOT_SUPPORTED**.  
  
-   O driver ODBC para a fonte de dados deve oferecer suporte a busca estendida.  
  
     Buscando estendido é a capacidade de voltar, bem como encaminhar sobre os registros resultantes da consulta SQL. Para determinar se o driver dá suporte a essa capacidade, chame o **:: SQLGetFunctions** a função de API de ODBC com o **SQL_API_SQLEXTENDEDFETCH** parâmetro.  
  
 Se você quiser dynasets atualizável (ou instantâneos para essa finalidade), o driver ODBC deve também dar suporte a **:: SQLSetPos** atualizações posicionadas ou função de API de ODBC. O **:: SQLSetPos** função permite MFC atualizar a fonte de dados sem enviar instruções SQL. Se esse suporte está disponível, MFC usa em vez de fazer atualizações usando o SQL. Para determinar se o driver dá suporte a **:: SQLSetPos**, chame **:: SQLGetInfo** com o **SQL_POS_OPERATIONS** parâmetro.  
  
 Atualizações posicionadas usam a sintaxe SQL (no formato **WHERE CURRENT OF** \<cursorname >) para identificar uma linha específica na tabela na fonte de dados. Para determinar se o driver oferece suporte a atualizações posicionadas, chame **:: SQLGetInfo** com o **SQL_POSITIONED_STATEMENTS** parâmetro.  
  
 Em geral, dynasets MFC (mas conjuntos de registros somente de encaminhamento não) requerem um driver ODBC com conformidade de API de nível 2. Se o driver de fonte de dados está em conformidade com o conjunto de APIs de nível 1, você ainda pode usar instantâneos atualizáveis tanto somente leitura e conjuntos de registros somente de encaminhamento, mas não dynasets. No entanto, um driver de nível 1 pode dar suporte a dynasets se ele dá suporte à busca estendida e os cursores controlados por conjunto de chaves. Para obter mais informações sobre os níveis de conformidade do ODBC, consulte [ODBC](../../data/odbc/odbc-basics.md).  
  
> [!NOTE]
>  Se você quiser usar instantâneos e dynasets, você deve baseá-los em dois `CDatabase` objetos (duas conexões diferentes).  
  
 Ao contrário de instantâneos, que usam o armazenamento intermediário mantido pela biblioteca de cursores ODBC, dynasets buscar um registro diretamente da fonte de dados assim que você rola para ele. Isso impede que os registros originalmente selecionados pelo dynaset sincronizado com a fonte de dados.  
  
 Para obter uma lista de drivers ODBC incluídos nesta versão do Visual C++ e para obter informações sobre como obter drivers adicionais, consulte [lista de drivers ODBC](../../data/odbc/odbc-driver-list.md).  
  
## <a name="see-also"></a>Consulte também  
 [ODBC (conectividade de banco de dados aberto)](../../data/odbc/open-database-connectivity-odbc.md)