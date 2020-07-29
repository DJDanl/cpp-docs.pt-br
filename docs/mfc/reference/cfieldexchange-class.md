---
title: Classe CFieldExchange
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
ms.openlocfilehash: d10bfc436297a5f861f17843007347dcef9e58ca
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87212469"
---
# <a name="cfieldexchange-class"></a>Classe CFieldExchange

Dá suporte às rotinas de troca de campo de registro (suporte RFX) e troca de campo de registro em massa (suporte RFX em massa) usadas pelas classes de banco de dados.

## <a name="syntax"></a>Sintaxe

```
class CFieldExchange
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CFieldExchange:: IsFieldType](#isfieldtype)|Retornará zero se a operação atual for apropriada para o tipo de campo que está sendo atualizado.|
|[CFieldExchange::SetFieldType](#setfieldtype)|Especifica o tipo de membro de dados do conjunto de registros — coluna ou parâmetro — representado por todas as chamadas a seguir para funções suporte RFX até a próxima chamada para `SetFieldType` .|

## <a name="remarks"></a>Comentários

`CFieldExchange`Não tem uma classe base.

Use essa classe se você estiver gravando rotinas de troca de dados para tipos de dados personalizados ou quando estiver implementando a busca em massa de linha; caso contrário, você não usará essa classe diretamente. O suporte RFX e o suporte RFX em massa trocam dados entre os membros de dados de campo do seu objeto Recordset e os campos correspondentes do registro atual na fonte de dados.

> [!NOTE]
> Se você estiver trabalhando com as classes DAO (objetos de acesso a dados) em vez das classes ODBC (Open Database Connectivity), use a classe [CDaoFieldExchange](../../mfc/reference/cdaofieldexchange-class.md) em vez disso. Para obter mais informações, consulte o artigo [visão geral: programação de banco de dados](../../data/data-access-programming-mfc-atl.md).

Um `CFieldExchange` objeto fornece as informações de contexto necessárias para o registro de campo de gravação ou troca de campo de registro em massa a ser realizada. `CFieldExchange`os objetos dão suporte a várias operações, incluindo parâmetros de associação e membros de dados de campo e configuração de vários sinalizadores nos campos do registro atual. As operações suporte RFX e suporte RFX em massa são executadas em membros de dados de classe recordset de tipos definidos pelo **`enum`** **FieldType** em `CFieldExchange` . Os valores de **FieldType** possíveis são:

- `CFieldExchange::outputColumn`para membros de dados de campo.

- `CFieldExchange::inputParam`ou `CFieldExchange::param` para membros de dados de parâmetro de entrada.

- `CFieldExchange::outputParam`para membros de dados de parâmetro de saída.

- `CFieldExchange::inoutParam`para membros de dados de parâmetro de entrada/saída.

A maioria das funções de membro da classe e os membros de dados são fornecidos para escrever suas próprias rotinas de suporte RFX personalizadas. Você usará `SetFieldType` com frequência. Para obter mais informações, consulte o [campo registro de artigos Exchange (suporte RFX)](../../data/odbc/record-field-exchange-rfx.md) e [Recordset (ODBC)](../../data/odbc/recordset-odbc.md). Para obter informações sobre a busca de linha em massa, consulte o artigo conjunto de registros [: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md). Para obter detalhes sobre as funções globais suporte RFX e suporte RFX em massa, consulte [funções de troca de campo de registro](../../mfc/reference/record-field-exchange-functions.md) na seção macros do MFC e globais desta referência.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CFieldExchange`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDB. h

## <a name="cfieldexchangeisfieldtype"></a><a name="isfieldtype"></a>CFieldExchange:: IsFieldType

Se você escrever sua própria função suporte RFX, chame `IsFieldType` no início da função para determinar se a operação atual pode ser executada em um determinado campo ou tipo de membro de dados de parâmetro (a `CFieldExchange::outputColumn` , `CFieldExchange::inputParam` , `CFieldExchange::param` , `CFieldExchange::outputParam` ou `CFieldExchange::inoutParam` ).

```
BOOL IsFieldType(UINT* pnField);
```

### <a name="parameters"></a>parâmetros

*pnField*<br/>
O número sequencial do membro de dados de campo ou parâmetro é retornado nesse parâmetro. Esse número corresponde à ordem do membro de dados na função [CRecordset::D ofieldexchange](../../mfc/reference/crecordset-class.md#dofieldexchange) ou [CRecordset::D obulkfieldexchange](../../mfc/reference/crecordset-class.md#dobulkfieldexchange) .

### <a name="return-value"></a>Valor retornado

Diferente de zero se a operação atual puder ser executada no campo ou tipo de parâmetro atual.

### <a name="remarks"></a>Comentários

Siga o modelo das funções suporte RFX existentes.

## <a name="cfieldexchangesetfieldtype"></a><a name="setfieldtype"></a>CFieldExchange::SetFieldType

Você precisa de uma chamada para `SetFieldType` na substituição de [DoFieldExchange](../../mfc/reference/crecordset-class.md#dofieldexchange) ou [DoBulkFieldExchange](../../mfc/reference/crecordset-class.md#dobulkfieldexchange) da sua classe do conjunto de registros.

```cpp
void SetFieldType(UINT nFieldType);
```

### <a name="parameters"></a>parâmetros

*nFieldType*<br/>
Um valor de `enum FieldType` , declarado em `CFieldExchange` , que pode ser um dos seguintes:

- `CFieldExchange::outputColumn`

- `CFieldExchange::inputParam`

- `CFieldExchange::param`

- `CFieldExchange::outputParam`

- `CFieldExchange::inoutParam`

### <a name="remarks"></a>Comentários

Para membros de dados de campo, você deve chamar `SetFieldType` com um parâmetro de `CFieldExchange::outputColumn` , seguido por chamadas para as funções suporte RFX ou suporte RFX em massa. Se você não tiver implementado a busca de linha em massa, o ClassWizard colocará essa `SetFieldType` chamada para você na seção mapa de campo de `DoFieldExchange` .

Se você parametrizar a classe do conjunto de registros, deverá chamar `SetFieldType` novamente, fora de qualquer seção de mapa de campo, seguida por chamadas suporte RFX para todos os membros de dados de parâmetro. Cada tipo de membro de dados de parâmetro deve ter sua própria `SetFieldType` chamada. A tabela a seguir distingue os valores diferentes que você pode passar para `SetFieldType` para representar os membros de dados de parâmetro de sua classe:

|Valor do parâmetro SetFieldType|Tipo de membro de dados de parâmetro|
|----------------------------------|-----------------------------------|
|`CFieldExchange::inputParam`|parâmetro de entrada. Um valor que é passado para a consulta ou procedimento armazenado do conjunto de registros.|
|`CFieldExchange::param` | o mesmo que `CFieldExchange::inputParam` .|
|`CFieldExchange::outputParam`|parâmetro de saída. Um valor de retorno do procedimento armazenado do conjunto de registros.|
|`CFieldExchange::inoutParam`|Parâmetro de entrada/saída. Um valor que é passado para e retornado do procedimento armazenado do conjunto de registros.|

Em geral, cada grupo de chamadas de função suporte RFX associadas a membros de dados de campo ou membros de dados de parâmetros deve ser precedido por uma chamada para `SetFieldType` . O parâmetro *nFieldType* de cada `SetFieldType` chamada identifica o tipo dos membros de dados representados pelas chamadas de função suporte RFX que seguem a `SetFieldType` chamada.

Para obter mais informações sobre como tratar os parâmetros de saída e entrada/saída, consulte a `CRecordset` função membro [FlushResultSet](../../mfc/reference/crecordset-class.md#flushresultset). Para obter mais informações sobre as funções suporte RFX e suporte RFX em massa, consulte o tópico [registro do campo funções do Exchange](../../mfc/reference/record-field-exchange-functions.md). Para obter informações relacionadas sobre a busca de linha em massa, consulte o artigo [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

### <a name="example"></a>Exemplo

Este exemplo mostra várias chamadas para funções suporte RFX com chamadas que acompanham o `SetFieldType` . Observe que `SetFieldType` é chamado pelo `pFX` ponteiro para um `CFieldExchange` objeto.

[!code-cpp[NVC_MFCDatabase#33](../../mfc/codesnippet/cpp/cfieldexchange-class_1.cpp)]

## <a name="see-also"></a>Confira também

[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CRecordset](../../mfc/reference/crecordset-class.md)
