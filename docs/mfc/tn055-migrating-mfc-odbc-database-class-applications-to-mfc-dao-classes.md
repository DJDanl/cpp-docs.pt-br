---
title: 'TN055: Migrando aplicativos de classe de banco de dados ODBC MFC para Classes DAO MFC | Microsoft Docs'
ms.custom: ''
ms.date: 06/20/2018
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.mfc.odbc
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d46150ee76219732d0895e818fa00c68dc588853
ms.sourcegitcommit: c6b095c5f3de7533fd535d679bfee0503e5a1d91
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/26/2018
ms.locfileid: "36957384"
---
# <a name="tn055-migrating-mfc-odbc-database-class-applications-to-mfc-dao-classes"></a>TN055: migrando aplicativos de classe de banco de dados ODBC MFC para classes DAO MFC

> [!NOTE]
> Os assistentes e o ambiente do Visual C++ não dão suporte DAO (embora as classes DAO estão incluídas e você ainda pode usá-los). A Microsoft recomenda que você use [modelos OLE DB](../data/oledb/ole-db-templates.md) ou [ODBC e MFC](../data/odbc/odbc-and-mfc.md) para novos projetos. Você só deve usar DAO na manutenção de aplicativos existentes.

## <a name="overview"></a>Visão geral

Em muitas situações pode ser desejável para migrar aplicativos que usam as classes de banco de dados ODBC do MFC para classes de banco de dados DAO do MFC. Essa observação técnica detalhará a maioria das diferenças entre as classes MFC ODBC e DAO. Com as diferenças em mente, ele não deve ser muito difícil migrar aplicativos das classes ODBC para as classes MFC, se desejado.

## <a name="why-migrate-from-odbc-to-dao"></a>Por que migrar do ODBC para DAO

Há várias razões por que você talvez queira migrar aplicativos de Classes de banco de dados ODBC para as Classes de banco de dados DAO, mas a decisão não é necessariamente simples ou óbvio. Uma coisa para ter em mente é que o mecanismo de banco de dados Microsoft Jet que é usado pelo DAO pode ler qualquer fonte de dados ODBC para os quais você tem um driver ODBC. Pode ser mais eficiente para usar as Classes de banco de dados ODBC ou chamar ODBC diretamente por conta própria, mas o mecanismo de banco de dados Microsoft Jet pode ler dados do ODBC.

Alguns casos simples que tomar a decisão de ODBC/DAO fácil. Por exemplo, quando você somente precisa de acesso a dados em um formato que o Microsoft Jet pode ler diretamente (formato de acesso, formato do Excel e assim por diante) a escolha óbvia é usar as Classes de banco de dados DAO.

Casos mais complexos surgirem quando houver dados em um servidor ou em uma variedade de diferentes servidores. Nesse caso, a decisão de usar as classes de banco de dados ODBC ou as classes de banco de dados DAO é difícil. Se você deseja fazem coisas como junções heterogêneas (associação de dados de servidores em vários formatos, como SQL Server e Oracle), o mecanismo de banco de dados Microsoft Jet executará a associação para você em vez de forçá-lo a fazer o trabalho necessário se você tiver usado o banco de dados ODBC Classes ou chamada ODBC diretamente. Se você estiver usando um driver ODBC que dá suporte a cursores de driver, a melhor opção pode ser as classes de banco de dados ODBC.

A opção pode ser complicada, então você pode querer escrever um código de exemplo para testar o desempenho de vários métodos considerando suas necessidades especiais. Essa observação técnica pressupõe que você fez a decisão de migrar de Classes de banco de dados ODBC para as classes de banco de dados DAO.

## <a name="similarities-between-odbc-database-classes-and-mfc-dao-database-classes"></a>Semelhanças entre Classes de banco de dados ODBC e Classes de banco de dados DAO MFC

O design original das classes MFC ODBC foi baseado no modelo de objeto DAO em uso no Microsoft Access e Microsoft Visual Basic. Isso significa que há muitos recursos comuns de classes MFC DAO e ODBC, que nem todas ser listados nesta seção. Em geral, os modelos de programação são os mesmos.

Para destacar algumas semelhanças:

- Classes ODBC e DAO tem objetos de banco de dados que gerenciar usando o sistema de gerenciamento de banco de dados subjacente (DBMS).

- Ambos têm objetos de conjunto de registros que representa um conjunto de resultados retornados do que DBMS.

- Os objetos de banco de dados e o conjunto de registros DAO tem membros quase idênticos para as classes ODBC.

- Com os dois conjuntos de classes, o código para recuperar dados é idêntico, exceto algumas alterações de nome do objeto e o membro. As alterações serão necessárias, mas geralmente o processo é uma alteração de nome simples ao alternar das classes ODBC para classes DAO.

Por exemplo, em ambos os modelos é o procedimento para recuperar dados para criar e abrir um objeto de banco de dados, criar e abrir um objeto de conjunto de registros e navegar (mover) os executar uma operação de dados.

## <a name="differences-between-odbc-and-dao-mfc-classes"></a>Diferenças entre Classes MFC DAO e ODBC

As classes DAO incluem mais objetos e um conjunto mais rico de métodos, mas esta seção detalha apenas as diferenças na funcionalidade e classes semelhantes.

Provavelmente as diferenças mais óbvias entre as classes são as alterações de nome para classes semelhantes e funções globais. A lista a seguir mostra as alterações de nome de objetos, métodos e funções globais associadas com as classes de banco de dados:

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

<sup>1</sup> o `RFX_Date` função baseia-se em `CTime` e `TIMESTAMP_STRUCT`.

As principais alterações na funcionalidade que podem afetar seu aplicativo exigir alterações de nome simples mais de estão listadas abaixo.

- As constantes e macros usadas para especificar como o conjunto de registros abra tipo e abrir as opções de conjunto de registros foram alteradas.

   Com as classes ODBC MFC necessários para definir essas opções por meio de macros ou os tipos enumerados.

   Com as classes DAO, DAO fornece a definição dessas opções em um arquivo de cabeçalho (DBDAOINT. H). Assim, o tipo de conjunto de registros é um membro enumerado `CRecordset`, mas com DAO é uma constante em vez disso. Por exemplo, você deve usar **instantâneo** ao especificar o tipo de `CRecordset` no ODBC, mas **DB_OPEN_SNAPSHOT** ao especificar o tipo de `CDaoRecordset`.

- O tipo de conjunto de registros de padrão de `CRecordset` é **instantâneo** enquanto o tipo de conjunto de registros de padrão de `CDaoRecordset` é **dynaset** (consulte a observação abaixo para um problema adicional sobre instantâneos de classe do ODBC).

- O ODBC `CRecordset` classe tem uma opção para criar um tipo de conjunto de registros somente de encaminhamento. No `CDaoRecordset` classe, e somente de encaminhamento não é um tipo de conjunto de registros, mas em vez disso, uma propriedade (ou opção) de certos tipos de conjuntos de registros.

- Um recordset somente de acréscimo ao abrir um `CRecordset` objeto significa que dados do conjunto de registros podem ser lido e anexados. Com `CDaoRecordset` do objeto, a opção somente de acréscimo literalmente significa que os dados do conjunto de registros só podem ser anexado (e não lidas).

- Funções de membro de transação de classes ODBC são membros de `CDatabase` e agir no nível do banco de dados. Em classes DAO, as funções de membro de transação são membros de uma classe de nível superior (`CDaoWorkspace`) e, portanto, podem afetar vários `CDaoDatabase` objetos que compartilham o mesmo espaço de trabalho (espaço de transação).

- A classe de exceção foi alterada. `CDBExceptions` são geradas nas classes ODBC e `CDaoExceptions` nas classes DAO.

- `RFX_Date` usa `CTime` e `TIMESTAMP_STRUCT` objetos ao `DFX_Date` usa `COleDateTime`. O `COleDateTime` é praticamente idêntica à `CTime`, mas se baseia em um OLE de 8 bytes **data** em vez de 4 bytes **time_t** para que ele pode conter uma variedade maior de dados.

   > [!NOTE]
   > DAO (`CDaoRecordset`) os instantâneos são somente leitura ao ODBC (`CRecordset`) podem ser atualizável, dependendo do driver e o uso da biblioteca de cursores ODBC. Se você estiver usando a biblioteca de cursores, `CRecordset` instantâneos são atualizáveis. Se você estiver usando qualquer um dos drivers da Microsoft 3.0 de pacote de Driver área de trabalho sem a biblioteca de cursores ODBC, o `CRecordset` instantâneos são somente leitura. Se você estiver usando outro driver, verifique a documentação do driver para ver se instantâneos (`STATIC_CURSORS`) são somente leitura.

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)  
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)  
