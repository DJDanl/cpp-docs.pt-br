---
title: Classe CfieldExchange
ms.date: 11/04/2016
f1_keywords:
- CFieldExchange
- AFXDB/CFieldExchange
- AFXDB/CFieldExchange::IsFieldType
- AFXDB/CFieldExchange::SetFieldType
helpviewer_keywords:
- CFieldExchange [MFC], IsFieldType
- CFieldExchange [MFC], SetFieldType
ms.assetid: 24c5c0b3-06a6-430e-9b6f-005a2c65e29f
ms.openlocfilehash: de9db2713a25b232bbd7f936958d1c10e96c511a
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81753174"
---
# <a name="cfieldexchange-class"></a>Classe CfieldExchange

Suporta as rotinas de troca de campo de registro (RFX) e troca de campo de registro em massa (Bulk RFX) usadas pelas classes de banco de dados.

## <a name="syntax"></a>Sintaxe

```
class CFieldExchange
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CfieldExchange::isfieldType](#isfieldtype)|Retorna não zero se a operação atual for apropriada para o tipo de campo que está sendo atualizado.|
|[CfieldExchange::setfieldType](#setfieldtype)|Especifica o tipo de membro de dados do conjunto de registros — coluna ou parâmetro `SetFieldType`— representado por todas as chamadas a seguir para funções RFX até a próxima chamada para .|

## <a name="remarks"></a>Comentários

`CFieldExchange`não tem uma classe base.

Use esta classe se você estiver escrevendo rotinas de troca de dados para tipos de dados personalizados ou quando estiver implementando a busca de linhas em massa; caso contrário, você não usará diretamente esta classe. O RFX e o Bulk RFX trocam dados entre os membros de dados de campo do objeto do seu conjunto de registros e os campos correspondentes do registro atual na fonte de dados.

> [!NOTE]
> Se você estiver trabalhando com as classes DAO (Data Access Objects, objetos de acesso de dados) em vez das classes ODBC (Open Database Connectivity, conectividade de banco de dados aberto), use a classe [CDaoFieldExchange.](../../mfc/reference/cdaofieldexchange-class.md) Para obter mais informações, consulte o artigo [Visão geral:Programação de banco de dados](../../data/data-access-programming-mfc-atl.md).

Um `CFieldExchange` objeto fornece as informações de contexto necessárias para que a troca de campo de registro ou a troca de campo em massa ocorra. `CFieldExchange`os objetos suportam uma série de operações, incluindo parâmetros de vinculação e membros de dados de campo e definindo várias bandeiras nos campos do registro atual. As operações RFX e Bulk RFX são realizadas em membros de `CFieldExchange`dados de classe de registro de tipos definidos pelo **enum** **FieldType** in . Os valores possíveis **do FieldType** são:

- `CFieldExchange::outputColumn`para membros de dados de campo.

- `CFieldExchange::inputParam`ou `CFieldExchange::param` para membros de dados de parâmetros de entrada.

- `CFieldExchange::outputParam`para membros de dados de parâmetro de saída.

- `CFieldExchange::inoutParam`para membros de dados de parâmetro de entrada/saída.

A maioria das funções de membros da classe e membros de dados são fornecidos para escrever suas próprias rotinas personalizadas de RFX. Você vai `SetFieldType` usar com freqüência. Para obter mais informações, consulte os artigos [Record Field Exchange (RFX)](../../data/odbc/record-field-exchange-rfx.md) e [Recordset (ODBC).](../../data/odbc/recordset-odbc.md) Para obter informações sobre a busca de linhas em massa, consulte o artigo [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md). Para obter detalhes sobre as funções globais RFX e Bulk RFX, consulte [Funções](../../mfc/reference/record-field-exchange-functions.md) de troca de campo de registro na seção MFC Macros and Globals desta referência.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CFieldExchange`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdb.h

## <a name="cfieldexchangeisfieldtype"></a><a name="isfieldtype"></a>CfieldExchange::isfieldType

Se você escrever sua própria `IsFieldType` função RFX, ligue no início de sua função para determinar se a operação `CFieldExchange::outputColumn` `CFieldExchange::inputParam`atual `CFieldExchange::param` `CFieldExchange::outputParam`pode `CFieldExchange::inoutParam`ser executada em um determinado campo ou tipo de membro de dados de parâmetro (a, , , ou ).

```
BOOL IsFieldType(UINT* pnField);
```

### <a name="parameters"></a>Parâmetros

*pnField*<br/>
O número seqüencial do membro de dados de campo ou parâmetro é devolvido neste parâmetro. Esse número corresponde à ordem do membro de dados na função [CRecordset::DoFieldExchange](../../mfc/reference/crecordset-class.md#dofieldexchange) ou [CRecordset::DoBulkFieldExchange.](../../mfc/reference/crecordset-class.md#dobulkfieldexchange)

### <a name="return-value"></a>Valor retornado

Não zero se a operação atual puder ser realizada no campo atual ou no tipo de parâmetro.

### <a name="remarks"></a>Comentários

Siga o modelo das funções RFX existentes.

## <a name="cfieldexchangesetfieldtype"></a><a name="setfieldtype"></a>CfieldExchange::setfieldType

Você precisa de `SetFieldType` uma chamada para a substituição [do DoFieldExchange](../../mfc/reference/crecordset-class.md#dofieldexchange) ou [DoBulkFieldExchange](../../mfc/reference/crecordset-class.md#dobulkfieldexchange) da sua classe de gravação.

```cpp
void SetFieldType(UINT nFieldType);
```

### <a name="parameters"></a>Parâmetros

*nFieldType*<br/>
Um valor `enum FieldType`do , `CFieldExchange`declarado em , que pode ser um dos seguintes:

- `CFieldExchange::outputColumn`

- `CFieldExchange::inputParam`

- `CFieldExchange::param`

- `CFieldExchange::outputParam`

- `CFieldExchange::inoutParam`

### <a name="remarks"></a>Comentários

Para membros de dados `SetFieldType` de campo, `CFieldExchange::outputColumn`você deve ligar com um parâmetro de , seguido por chamadas para as funções RFX ou Bulk RFX. Se você não tiver implementado a busca de `SetFieldType` linhas em massa, então `DoFieldExchange`o ClassWizard coloca essa chamada para você na seção de mapa de campo de .

Se você parametrizar sua classe `SetFieldType` de conjunto de registros, você deve ligar novamente, fora de qualquer seção de mapa de campo, seguido por chamadas RFX para todos os membros de dados de parâmetros. Cada tipo de membro de dados `SetFieldType` de parâmetro deve ter sua própria chamada. A tabela a seguir distingue os `SetFieldType` diferentes valores que você pode passar para representar os membros de dados de parâmetros da sua classe:

|Valor do parâmetro SetFieldType|Membro de dados de parâmetros|
|----------------------------------|-----------------------------------|
|`CFieldExchange::inputParam`|parâmetro de entrada. Um valor que é passado para a consulta ou procedimento armazenado do conjunto de registros.|
|`CFieldExchange::param` | mesmo `CFieldExchange::inputParam`que .|
|`CFieldExchange::outputParam`|parâmetro de saída. Um valor de retorno do procedimento armazenado do conjunto de registros.|
|`CFieldExchange::inoutParam`|Parâmetro de entrada/saída. Um valor que é repassado e devolvido do procedimento armazenado do conjunto de registros.|

Em geral, cada grupo de chamadas de função RFX associadas a membros de `SetFieldType`dados de campo ou membros de dados de parâmetros deve ser precedido por uma chamada para . O parâmetro *nFieldType* `SetFieldType` de cada chamada identifica o tipo de membros de dados `SetFieldType` representados pelas chamadas de função RFX que seguem a chamada.

Para obter mais informações sobre o manuseio dos `CRecordset` parâmetros de saída e entrada/saída, consulte a função de membro [FlushResultSet](../../mfc/reference/crecordset-class.md#flushresultset). Para obter mais informações sobre as funções RFX e Bulk RFX, consulte o tópico [Funções](../../mfc/reference/record-field-exchange-functions.md)de Troca de Campo de Registro . Para obter informações relacionadas sobre a busca de linhas em massa, consulte o artigo [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

### <a name="example"></a>Exemplo

Este exemplo mostra várias chamadas para funções `SetFieldType`RFX com chamadas de acompanhamento para . Observe `SetFieldType` que é `pFX` chamado através `CFieldExchange` do ponteiro para um objeto.

[!code-cpp[NVC_MFCDatabase#33](../../mfc/codesnippet/cpp/cfieldexchange-class_1.cpp)]

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CRecordset](../../mfc/reference/crecordset-class.md)
