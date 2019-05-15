---
title: 'TN055: Migrando aplicativos de classe de banco de dados ODBC do MFC para Classes DAO MFC'
ms.date: 06/20/2018
helpviewer_keywords:
- DAO [MFC], migration
- TN055
- migration [MFC], ODBC database applications
- ODBC classes [MFC], DAO classes
- migrating ODBC database applications [MFC]
- porting database applications to DAO
- ODBC [MFC], DAO
- porting ODBC database applications to DAO
- migrating database applications [MFC]
ms.assetid: 0f858bd1-e168-4e2e-bcd1-8debd82856e4
ms.openlocfilehash: 7a1d3436a9b19c40df2a08576d797de49833f14f
ms.sourcegitcommit: 934cb53fa4cb59fea611bfeb9db110d8d6f7d165
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/14/2019
ms.locfileid: "65611241"
---
# <a name="tn055-migrating-mfc-odbc-database-class-applications-to-mfc-dao-classes"></a>TN055: Migrando aplicativos de classe de banco de dados ODBC do MFC para Classes DAO MFC

> [!NOTE]
> Os assistentes e o ambiente do Visual C++ não têm suporte DAO (embora as classes DAO estão incluídas e você ainda pode usá-los). A Microsoft recomenda que você use [modelos OLE DB](../data/oledb/ole-db-templates.md) ou [ODBC e MFC](../data/odbc/odbc-and-mfc.md) para novos projetos. Você só deve usar DAO em manutenção de aplicativos existentes.

## <a name="overview"></a>Visão geral

Em muitas situações, ele pode ser desejável para migrar aplicativos que usam classes de banco de dados ODBC do MFC para classes de banco de dados do MFC DAO. Essa observação técnica detalhará a maioria das diferenças entre as classes MFC ODBC e DAO. Com as diferenças em mente, ele não deve ser excessivamente difícil de migrar aplicativos das classes ODBC para as classes MFC, se desejado.

## <a name="why-migrate-from-odbc-to-dao"></a>Por que migrar do ODBC para DAO

Há inúmeras razões por que você talvez queira migrar aplicativos das Classes de banco de dados ODBC para as Classes de banco de dados DAO, mas a decisão não é necessariamente simples ou óbvio. Uma coisa para ter em mente é que o mecanismo de banco de dados Microsoft Jet que é usado pelo DAO pode ler qualquer fonte de dados ODBC para os quais você tem um driver ODBC. Pode ser mais eficiente usar as Classes de banco de dados ODBC ou chamar o ODBC diretamente por conta própria, mas o mecanismo de banco de dados Microsoft Jet pode ler dados do ODBC.

Alguns casos simples que facilitam a decisão de ODBC/DAO. Por exemplo, quando precisa apenas de acesso a dados em um formato que o mecanismo Microsoft Jet pode ler diretamente (formato de acesso, formato do Excel e assim por diante) a opção óbvia é usar as Classes de banco de dados DAO.

Casos mais complexos podem surgir quando seus dados não existem em um servidor ou em uma variedade de diferentes servidores. Nesse caso, a decisão de usar as classes de banco de dados ODBC ou as classes de banco de dados DAO é difícil. Se você quiser fazer coisas como junções heterogêneas (associação de dados de servidores em vários formatos, como o SQL Server e Oracle) e, em seguida, o mecanismo de banco de dados Microsoft Jet executará a associação para você em vez de forçá-lo a fazer o trabalho necessário se você tiver usado o banco de dados ODBC Classes ou chamada ODBC diretamente. Se você estiver usando um driver ODBC que dá suporte a cursores de driver, a melhor opção talvez as classes de banco de dados ODBC.

A opção pode ser complicada, portanto, você talvez queira escrever um código de exemplo para testar o desempenho de vários métodos, considerando suas necessidades especiais. Essa observação técnica supõe que você fez a decisão de migrar das Classes de banco de dados ODBC para as classes de banco de dados DAO.

## <a name="similarities-between-odbc-database-classes-and-mfc-dao-database-classes"></a>Semelhanças entre Classes de banco de dados ODBC e Classes de banco de dados DAO MFC

O design original das classes MFC ODBC foi baseado no modelo de objeto DAO esteve em uso no Microsoft Access e Microsoft Visual Basic. Isso significa que há muitos recursos comuns das classes MFC DAO e ODBC, que nem todas ser listados nesta seção. Em geral, os modelos de programação são os mesmos.

Para destacar algumas semelhanças:

- Classes ODBC e DAO têm objetos de banco de dados que gerenciar usando o sistema de gerenciamento de banco de dados (DBMS) subjacente.

- Ambos têm objetos de conjunto de registros que representa um conjunto de resultados retornados por essa DBMS.

- Os objetos de banco de dados e o conjunto de registros DAO tem membros quase idênticos para as classes ODBC.

- Com os dois conjuntos de classes, o código para recuperar dados é idêntico, exceto por algumas alterações de nome de objeto e o membro. As alterações sejam necessárias, mas geralmente o processo é uma alteração de nome simples ao alternar das classes ODBC para classes DAO.

Por exemplo, em ambos os modelos que é o procedimento para recuperar dados para criar e abrir um objeto de banco de dados, criar e abrir um objeto de conjunto de registros e navegue (mover) no entanto os dados executando alguma operação.

## <a name="differences-between-odbc-and-dao-mfc-classes"></a>Diferenças entre Classes ODBC e DAO MFC

As classes DAO incluem mais objetos e um conjunto mais rico de métodos, mas apenas nesta seção detalha as diferenças na funcionalidade e classes semelhantes.

Provavelmente, as diferenças mais óbvias entre as classes são as alterações de nome para classes semelhantes e funções globais. A lista a seguir mostra as alterações de nome de objetos, métodos e funções globais associadas com as classes de banco de dados:

|Classe ou função|Equivalente em classes DAO MFC|
|-----------------------|-----------------------------------|
|`CDatabase`|`CDaoDatabase`|
|`CDatabase::ExecuteSQL`|`CDaoDatabase::Execute`|
|`CRecordset`|`CDaoRecordset`|
|`CRecordset::GetDefaultConnect`|`CDaoRecordset::GetDefaultDBName`|
|`CFieldExchange`|`CDaoFieldExchange`|
|`RFX_Bool`|`DFX_Bool`|
|`RFX_Byte`|`DFX_Byte`|
|`RFX_Int`|`DFX_Short`|
|`RFX_Long`|`DFX_Long`|
||`DFX_Currency`|
|`RFX_Single`|`DFX_Single`|
|`RFX_Double`|`DFX_Double`|
|`RFX_Date`<sup>1</sup>|`DFX_Date` (`COleDateTime`-com base)|
|`RFX_Text`|`DFX_Text`|
|`RFX_Binary`|`DFX_Binary`|
|`RFX_LongBinary`|`DFX_LongBinary`|

<sup>1</sup> as `RFX_Date` a função é baseado no `CTime` e `TIMESTAMP_STRUCT`.

As principais alterações na funcionalidade que podem afetar seu aplicativo e exigem alterações de nome simples de mais de estão listadas abaixo.

- As constantes e macros usadas para especificar coisas como o conjunto de registros abrir tipo e opções de abrir o conjunto de registros foram alteradas.

   Com as classes ODBC MFC necessárias para definir essas opções por meio de macros ou os tipos enumerados.

   Com as classes DAO, DAO fornece a definição de uma dessas opções em um arquivo de cabeçalho (DBDAOINT. H). Assim, o tipo de conjunto de registros é um membro enumerado `CRecordset`, mas com o DAO é uma constante em vez disso. Por exemplo você usaria **snapshot** ao especificar o tipo de `CRecordset` em ODBC, mas **DB_OPEN_SNAPSHOT** ao especificar o tipo de `CDaoRecordset`.

- O tipo de conjunto de registros padrão para `CRecordset` está **snapshot** enquanto o tipo de conjunto de registros de padrão de `CDaoRecordset` é **dynaset** (consulte a observação abaixo para um problema adicional sobre instantâneos de classe do ODBC).

- O ODBC `CRecordset` classe tem uma opção para criar um tipo de conjunto de registros somente de encaminhamento. No `CDaoRecordset` classe, somente de encaminhamento não é um tipo de conjunto de registros, mas em vez disso, uma propriedade (ou opção) de certos tipos de conjuntos de registros.

- Um recordset somente de acréscimo ao abrir um `CRecordset` objeto significava que os dados do conjunto de registros podem ser de leitura e acrescentados. Com `CDaoRecordset` do objeto, a opção somente de acréscimo, literalmente, significa que os dados do conjunto de registros só podem ser anexado (e não de leitura).

- Funções de membro das classes ODBC transação são membros de `CDatabase` e agir no nível do banco de dados. Nas classes DAO, as funções de membro de transação são membros de uma classe de nível superior (`CDaoWorkspace`) e, portanto, pode afetar vários `CDaoDatabase` objetos que compartilham o mesmo espaço de trabalho (espaço de transação).

- A classe de exceção foi alterada. `CDBExceptions` são lançadas nas classes ODBC e `CDaoExceptions` nas classes DAO.

- `RFX_Date` usa `CTime` e `TIMESTAMP_STRUCT` objetos enquanto `DFX_Date` usa `COleDateTime`. O `COleDateTime` é quase idêntico ao `CTime`, mas se baseia em um OLE de 8 bytes **data** em vez de 4 bytes **time_t** para que ele pode conter uma variedade maior de dados.

   > [!NOTE]
   > DAO (`CDaoRecordset`) os instantâneos são somente leitura enquanto ODBC (`CRecordset`) instantâneos podem ser atualizáveis, dependendo do driver e o uso da biblioteca de cursores ODBC. Se você estiver usando a biblioteca de cursores, `CRecordset` instantâneos são atualizáveis. Se você estiver usando qualquer um dos drivers da Microsoft do pacote de Driver de área de trabalho 3.0 sem a biblioteca de cursores ODBC, o `CRecordset` instantâneos são somente leitura. Se você estiver usando outro driver, verifique a documentação do driver para ver se instantâneos (`STATIC_CURSORS`) são somente leitura.

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
