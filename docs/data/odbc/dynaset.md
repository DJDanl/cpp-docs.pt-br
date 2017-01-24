---
title: "Dynaset | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "biblioteca de cursores [ODBC], disponibilidade de dynaset"
  - "cursores [ODBC], cursores controlados por conjunto de chaves em dynasets"
  - "dynasets"
  - "cursores controlados por conjunto de chaves em dynasets"
  - "biblioteca de cursores ODBC [ODBC], dynasets"
  - "conjunto de registros ODBC, dynasets"
  - "conjunto de registros [C++], dynasets"
ms.assetid: 2867e6be-208e-4fe7-8bbe-b8697cb1045c
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Dynaset
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico descreve dynasets e discute o [disponibilidade](#_core_availability_of_dynasets).  
  
> [!NOTE]
>  Este tópico aplica\-se às classes MFC ODBC, incluindo [CRecordset](../Topic/CRecordset%20Class.md).  Para obter informações sobre os dynasets em classes de DAO, consulte [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md).  Com DAO, você pode abrir os conjuntos de registros de dynaset\- tipo.  
  
 Um dynaset é um conjunto de registros com propriedades dinâmicas.  Durante o tempo de vida, um objeto do conjunto de registros permanece no modo de dynaset \(geralmente chamado um dynaset\) sincronizados com a fonte de dados da seguinte maneira.  Em um ambiente multiusuário, outros usuários podem editar ou excluir os registros que estão na dynaset ou para adicionar registros à tabela em que o dynaset representa.  Registra seu aplicativo adiciona a ou exclusões do conjunto de registros são refletidas em seu dynaset.  Os registros que outros usuários adicionarem a tabela não serão refletidas em seu dynaset até que você recria o dynaset chamando a função de membro de **Requery** .  Quando outros usuários excluam registros, o código de MFC ignora sobre as exclusões no conjunto de registros.  As alterações de edição de outros usuários aos registros existentes são refletidas em seu dynaset assim que você rola para o registro afetado.  
  
 De maneira semelhante, as edições que você cria para os registros em um dynaset são refletidas nos dynasets em uso por outros usuários.  Os registros que você adiciona não são refletidas nos dynasets de outros usuários até que você consulte novamente seus dynasets.  Os registros que você exclui são marcados como “excluída” nos conjuntos de registros de outros usuários.  Se você tiver várias conexões ao mesmo base de dados \(vários objetos de `CDatabase` \), os conjuntos de registros associados às conexões têm o mesmo status que os conjuntos de registros de outros usuários.  
  
 Dynasets é mais útil quando os dados devem ser dinâmicas, como \(por exemplo\) em um sistema de reserva de linha de sobrecarga.  
  
> [!NOTE]
>  Para usar dynasets, você deve ter um driver ODBC para sua fonte de dados que oferece suporte a dynasets e a biblioteca de cursores ODBC não deve ser carregada.  Para obter mais informações, consulte [Disponibilidade de Dynasets](#_core_availability_of_dynasets).  
  
 Para especificar que um conjunto de registros é um dynaset, passagem **CRecordset::dynaset** como o primeiro parâmetro na função de membro de **Abrir** do objeto do conjunto de registros.  
  
> [!NOTE]
>  Para dynasets atualizáveis, o driver ODBC deve oferecer suporte a instruções posicionadas de atualização ou função de API ODBC de **::SQLSetPos** .  Se ambos têm suporte, o **::SQLSetPos** MFC usa para maior eficiência.  
  
##  <a name="_core_availability_of_dynasets"></a> Disponibilidade de Dynasets  
 As classes da base de dados de MFC dão suporte a dynasets se os seguintes requisitos forem atendidos:  
  
-   A DLL de biblioteca de cursores ODBC não deve estar em uso para esta fonte de dados.  
  
     Se a biblioteca de cursores é usada, mascara alguma funcionalidade de driver ODBC subjacente que é necessário para suporte ao dynaset.  Se você quiser usar dynasets \(e o driver ODBC tem funcionalidade necessária para dynasets, conforme descrito no restante desta seção\), você pode fazer com que o MFC não carrega a biblioteca de cursores quando você cria um objeto de `CDatabase` .  Para obter mais informações, consulte [ODBC](../../data/odbc/odbc-basics.md) e a função de membro de [OpenEx](../Topic/CDatabase::OpenEx.md) ou de [Abrir](../Topic/CDatabase::Open.md) da classe `CDatabase`.  
  
     Na terminologia de ODBC, os dynasets e os instantâneos são chamados de cursores.  Um cursor é um mecanismo usado mantendo o controle de sua posição em um conjunto de registros.  
  
-   O driver ODBC para sua fonte de dados deve oferecer suporte a cursores controlados por conjunto de chaves.  
  
     Os cursores controlados por conjunto de chaves gerenciam dados de uma tabela obtendo e armazenando um conjunto de chaves.  As chaves devem ser usadas para obter dados atual da tabela quando rolagens do usuário em um registro específico.  Para determinar se o driver fornece esse suporte, chame a função de API ODBC de **::SQLGetInfo** com o parâmetro de **SQL\_SCROLL\_OPTIONS** .  
  
     Se você tentar abrir um dynaset sem suporte do conjunto de chaves, você obtém `CDBException` com o valor de código de retorno **AFX\_SQL\_ERROR\_DYNASET\_NOT\_SUPPORTED**.  
  
-   O driver ODBC para sua fonte de dados deve oferecer suporte para buscar estendido.  
  
     Buscar estendido é a habilidade de rolagem para trás bem como encaminhar sobre os registros resultantes da consulta SQL.  Para determinar se o driver da suporte a esse recurso, chame a função de API ODBC de **::SQLGetFunctions** com o parâmetro de **SQL\_API\_SQLEXTENDEDFETCH** .  
  
 Se você quiser dynasets atualizável \(ou instantâneos, para esse fim\), o driver ODBC também deve dar suporte à função de API ODBC de **::SQLSetPos** ou atualizações posicionadas.  A função de **::SQLSetPos** permite que o MFC atualizar a fonte de dados sem enviar instruções SQL.  Se esse suporte está disponível, o MFC usá\-la de preferência a fazer atualizações usando o SQL.  Para determinar se o driver suporta **::SQLSetPos**, chame **::SQLGetInfo** com o parâmetro de **SQL\_POS\_OPERATIONS** .  
  
 Posicionada sintaxe SQL do uso das atualizações \(de cursorname de **WHERE CURRENT OF** \<de formulário\>\) para identificar uma linha específica da tabela na fonte de dados.  Para determinar se seus suporte de driver posicionaram atualizações, chame **::SQLGetInfo** com o parâmetro de **SQL\_POSITIONED\_STATEMENTS** .  
  
 Em geral, os dynasets MFC \(mas os conjuntos de registros não somente avanço\) exigem um driver ODBC com conformidade de API de nível 2.  Se o driver para a fonte de dados está em conformidade com o nível 1 API definido, você ainda pode usar instantâneos atualizável e somente leitura e conjuntos de registros de somente avanço, mas não dynasets.  No entanto, um driver de nível 1 pode dar suporte a dynasets se oferece suporte à busca estendido e cursores controlados por conjunto de chaves.  Para obter mais informações sobre os níveis de conformidade de ODBC, consulte [ODBC](../../data/odbc/odbc-basics.md).  
  
> [!NOTE]
>  Se você quiser usar instantâneos e dynasets, você deve baseá\-los em dois objetos diferentes de `CDatabase` \(duas conexões diferentes\).  
  
 Diferentemente dos instantâneos, que usam o armazenamento intermediário manteve pela biblioteca de cursores ODBC, busca de dynasets um registro diretamente da fonte de dados para que você enrolasse.  Isso mantém os registros selecionados originalmente pelo dynaset sincronizado com a fonte de dados.  
  
 Para obter uma lista de drivers ODBC incluídos nesta versão do Visual C\+\+ e para obter informações sobre como obter drivers adicionais, consulte [Lista de driver ODBC](../../data/odbc/odbc-driver-list.md).  
  
## Consulte também  
 [Conectividade de banco de dados aberto \(ODBC\)](../Topic/Open%20Database%20Connectivity%20\(ODBC\).md)