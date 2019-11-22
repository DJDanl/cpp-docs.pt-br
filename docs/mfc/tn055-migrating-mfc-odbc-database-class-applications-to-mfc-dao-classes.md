---
title: 'TN055: migrando aplicativos de classe de banco de dados ODBC MFC para classes DAO MFC'
ms.date: 09/17/2019
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
ms.openlocfilehash: 744e1c71476ccfbe6ea8f8359dcdb9a29efc995e
ms.sourcegitcommit: 069e3833bd821e7d64f5c98d0ea41fc0c5d22e53
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/21/2019
ms.locfileid: "74305365"
---
# <a name="tn055-migrating-mfc-odbc-database-class-applications-to-mfc-dao-classes"></a>TN055: migrando aplicativos de classe de banco de dados ODBC MFC para classes DAO MFC

> [!NOTE]
> O DAO é usado com bancos de dados do Access e tem suporte por meio do Office 2013. O DAO 3,6 é a versão final e é considerado obsoleto. O ambiente C++ visual e os assistentes não dão suporte a DAO (embora as classes DAO estejam incluídas e você ainda possa usá-las). A Microsoft recomenda que você use [modelos de OLE DB](../data/oledb/ole-db-templates.md) ou [ODBC e MFC](../data/odbc/odbc-and-mfc.md) para novos projetos. Você só deve usar o DAO na manutenção de aplicativos existentes.

## <a name="overview"></a>Visão geral

Em muitas situações, pode ser desejável migrar aplicativos que usam classes de banco de dados ODBC do MFC para as classes de banco de dados DAO do MFC. Esta nota técnica detalhará a maioria das diferenças entre as classes MFC ODBC e DAO. Com as diferenças em mente, não deve ser muito difícil migrar aplicativos das classes ODBC para as classes do MFC, se desejado.

## <a name="why-migrate-from-odbc-to-dao"></a>Por que migrar do ODBC para o DAO

Há várias razões pelas quais você pode querer migrar aplicativos das classes de banco de dados ODBC para as classes de banco de dados DAO, mas a decisão não é necessariamente simples ou óbvia. Uma coisa a ser lembrada é que o mecanismo de banco de dados do Microsoft Jet usado pelo DAO pode ler qualquer fonte de dados ODBC para a qual você tenha um driver ODBC. Pode ser mais eficiente usar as classes de banco de dados ODBC ou chamar o ODBC diretamente, mas o mecanismo de banco de dados do Microsoft Jet pode ler dados ODBC.

Alguns casos simples que facilitam a decisão sobre ODBC/DAO. Por exemplo, quando você só precisa de acesso a dados em um formato que o mecanismo do Microsoft Jet possa ler diretamente (formato de acesso, formato do Excel e assim por diante), a opção óbvia é usar as classes de banco de dados DAO.

Casos mais complexos surgem quando seus dados existem em um servidor ou em uma variedade de servidores diferentes. Nesse caso, a decisão de usar as classes de banco de dados ODBC ou as classes de banco de dados DAO é uma tarefa difícil. Se você quiser fazer coisas como junções heterogêneas (unir dados de servidores em vários formatos, como SQL Server e Oracle), o mecanismo de banco de dados do Microsoft Jet realizará a junção para você, em vez de forçá-lo a fazer o trabalho necessário se você usou o banco de dados ODBC Classes ou chamadas ODBC diretamente. Se você estiver usando um driver ODBC que dá suporte a cursores de driver, sua melhor escolha pode ser as classes de banco de dados ODBC.

A escolha pode ser complicada, portanto, talvez você queira escrever algum código de exemplo para testar o desempenho de vários métodos de acordo com suas necessidades especiais. Esta observação técnica pressupõe que você tomou a decisão de migrar das classes de banco de dados ODBC para as classes de banco de dados DAO.

## <a name="similarities-between-odbc-database-classes-and-mfc-dao-database-classes"></a>Semelhanças entre classes de banco de dados ODBC e classes de banco de dados do MFC DAO

O design original das classes ODBC do MFC foi baseado no modelo de objeto DAO que está em uso no Microsoft Access e no Microsoft Visual Basic. Isso significa que há muitos recursos comuns das classes ODBC e MFC do DAO, que não serão todas listadas nesta seção. Em geral, os modelos de programação são os mesmos.

Para destacar algumas semelhanças:

- As classes ODBC e DAO têm objetos de banco de dados que gerenciam usando o DBMS (sistema de gerenciamento de banco de dados) subjacente.

- Ambos têm objetos Recordset que representam um conjunto de resultados retornados desse DBMS.

- O banco de dados DAO e os objetos Recordset têm Membros quase idênticos às classes ODBC.

- Com ambos os conjuntos de classes, o código para recuperar dados é idêntico, exceto por algumas alterações de nome de objeto e membro. As alterações serão necessárias, mas geralmente o processo é uma alteração de nome simples ao alternar das classes ODBC para as classes DAO.

Por exemplo, em ambos os modelos, o procedimento para recuperar dados é criar e abrir um objeto Database, criar e abrir um objeto Recordset e navegar (mover), embora os dados executem alguma operação.

## <a name="differences-between-odbc-and-dao-mfc-classes"></a>Diferenças entre classes ODBC e do MFC do DAO

As classes DAO incluem mais objetos e um conjunto mais rico de métodos, mas esta seção detalhará apenas as diferenças em classes e funcionalidades semelhantes.

Provavelmente, as diferenças mais óbvias entre as classes são as alterações de nome para classes semelhantes e funções globais. A lista a seguir mostra as alterações de nome dos objetos, métodos e funções globais associadas às classes de banco de dados:

|Classe ou função|Equivalente em classes DAO do MFC|
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
|`RFX_Date`<sup>1</sup>|`DFX_Date` (baseado em`COleDateTime`)|
|`RFX_Text`|`DFX_Text`|
|`RFX_Binary`|`DFX_Binary`|
|`RFX_LongBinary`|`DFX_LongBinary`|

<sup>1</sup> a função `RFX_Date` é baseada em `CTime` e `TIMESTAMP_STRUCT`.

As principais alterações na funcionalidade que podem afetar seu aplicativo e exigem mais do que alterações de nome simples são listadas abaixo.

- As constantes e macros usadas para especificar coisas como tipo aberto do conjunto de registros e opções de abertura do conjunto de registros foram alteradas.

   Com o MFC de classes ODBC, é necessário definir essas opções por meio de macros ou de tipos enumerados.

   Com as classes DAO, o DAO fornece a definição dessas opções em um arquivo de cabeçalho (DBDAOINT. H). Portanto, o tipo de conjunto de registros é um membro enumerado de `CRecordset`, mas com o DAO ele é uma constante. Por exemplo, você usaria **instantâneo** ao especificar o tipo de `CRecordset` no ODBC, mas **DB_OPEN_SNAPSHOT** ao especificar o tipo de `CDaoRecordset`.

- O tipo de conjunto de registros padrão para `CRecordset` é **instantâneo** , enquanto o tipo de conjunto de registros padrão para `CDaoRecordset` é **dynaset** (consulte a observação abaixo para obter um problema adicional sobre instantâneos de classe ODBC).

- A classe ODBC `CRecordset` tem uma opção para criar um tipo de conjunto de registros somente de encaminhamento. Na classe `CDaoRecordset`, somente encaminhamento não é um tipo de conjunto de registros, mas sim uma propriedade (ou opção) de determinados tipos de conjuntos de registros.

- Um conjunto de registros somente de acréscimo ao abrir um `CRecordset` objeto significava que os dados do conjunto de registros podem ser lidos e anexados. Com o objeto `CDaoRecordset`, a opção somente acrescentar significa literalmente que os dados do conjunto de registros só podem ser acrescentados (e não lidos).

- As funções de membro de transação das classes ODBC são membros de `CDatabase` e agem no nível de banco de dados. Nas classes DAO, as funções de membro de transação são membros de uma classe de nível superior (`CDaoWorkspace`) e, portanto, podem afetar vários objetos `CDaoDatabase` que compartilham o mesmo espaço de trabalho (espaço de transação).

- A classe de exceção foi alterada. `CDBExceptions` são lançadas nas classes ODBC e `CDaoExceptions` nas classes DAO.

- `RFX_Date` usa objetos `CTime` e `TIMESTAMP_STRUCT` enquanto `DFX_Date` usa `COleDateTime`. A `COleDateTime` é quase idêntica à `CTime`, mas é baseada em uma **Data** OLE de 8 bytes em vez de uma **time_t** de 4 bytes, para que possa conter um intervalo muito maior de dados.

   > [!NOTE]
   > Os instantâneos DAO (`CDaoRecordset`) são somente leitura enquanto os instantâneos ODBC (`CRecordset`) podem ser atualizados dependendo do driver e do uso da biblioteca de cursores ODBC. Se você estiver usando a biblioteca de cursores, `CRecordset` instantâneos serão atualizáveis. Se você estiver usando qualquer um dos drivers da Microsoft do desktop Driver Pack 3,0 sem a biblioteca de cursores ODBC, os instantâneos de `CRecordset` serão somente leitura. Se você estiver usando outro driver, verifique a documentação do driver para ver se os instantâneos (`STATIC_CURSORS`) são somente leitura.

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
