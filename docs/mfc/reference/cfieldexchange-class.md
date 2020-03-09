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
ms.openlocfilehash: e66b3ed16d4f21d46567c37bfaf7929d32f63b8e
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78866272"
---
# <a name="cfieldexchange-class"></a>Classe CFieldExchange

Dá suporte às rotinas de troca de campo de registro (suporte RFX) e troca de campo de registro em massa (suporte RFX em massa) usadas pelas classes de banco de dados.

## <a name="syntax"></a>Sintaxe

```
class CFieldExchange
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CFieldExchange:: IsFieldType](#isfieldtype)|Retornará zero se a operação atual for apropriada para o tipo de campo que está sendo atualizado.|
|[CFieldExchange::SetFieldType](#setfieldtype)|Especifica o tipo de membro de dados do conjunto de registros — coluna ou parâmetro — representado por todas as chamadas a seguir para funções suporte RFX até a próxima chamada para `SetFieldType`.|

## <a name="remarks"></a>Comentários

`CFieldExchange` não tem uma classe base.

Use essa classe se você estiver gravando rotinas de troca de dados para tipos de dados personalizados ou quando estiver implementando a busca em massa de linha; caso contrário, você não usará essa classe diretamente. O suporte RFX e o suporte RFX em massa trocam dados entre os membros de dados de campo do seu objeto Recordset e os campos correspondentes do registro atual na fonte de dados.

> [!NOTE]
>  Se você estiver trabalhando com as classes DAO (objetos de acesso a dados) em vez das classes ODBC (Open Database Connectivity), use a classe [CDaoFieldExchange](../../mfc/reference/cdaofieldexchange-class.md) em vez disso. Para obter mais informações, consulte o artigo [visão geral: programação de banco de dados](../../data/data-access-programming-mfc-atl.md).

Um objeto de `CFieldExchange` fornece as informações de contexto necessárias para a troca de campo de registro ou de registro em massa de campo para que ocorra. os objetos `CFieldExchange` dão suporte a várias operações, incluindo parâmetros de associação e membros de dados de campo e configuração de vários sinalizadores nos campos do registro atual. As operações suporte RFX e suporte RFX em massa são executadas em membros de dados de classe recordset de tipos definidos pela **Enumeração** **FieldType** no `CFieldExchange`. Os valores de **FieldType** possíveis são:

- `CFieldExchange::outputColumn` para membros de dados de campo.

- `CFieldExchange::inputParam` ou `CFieldExchange::param` para membros de dados de parâmetro de entrada.

- `CFieldExchange::outputParam` para membros de dados de parâmetro de saída.

- `CFieldExchange::inoutParam` para membros de dados de parâmetro de entrada/saída.

A maioria das funções de membro da classe e os membros de dados são fornecidos para escrever suas próprias rotinas de suporte RFX personalizadas. Você usará `SetFieldType` com frequência. Para obter mais informações, consulte o [campo registro de artigos Exchange (suporte RFX)](../../data/odbc/record-field-exchange-rfx.md) e [Recordset (ODBC)](../../data/odbc/recordset-odbc.md). Para obter informações sobre a busca de linha em massa, consulte o artigo conjunto de registros [: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md). Para obter detalhes sobre as funções globais suporte RFX e suporte RFX em massa, consulte [funções de troca de campo de registro](../../mfc/reference/record-field-exchange-functions.md) na seção macros do MFC e globais desta referência.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CFieldExchange`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDB. h

##  <a name="isfieldtype"></a>CFieldExchange:: IsFieldType

Se você escrever sua própria função suporte RFX, chame `IsFieldType` no início de sua função para determinar se a operação atual pode ser executada em um determinado campo ou tipo de membro de dados de parâmetro (uma `CFieldExchange::outputColumn`, `CFieldExchange::inputParam`, `CFieldExchange::param`, `CFieldExchange::outputParam`ou `CFieldExchange::inoutParam`).

```
BOOL IsFieldType(UINT* pnField);
```

### <a name="parameters"></a>Parâmetros

*pnField*<br/>
O número sequencial do membro de dados de campo ou parâmetro é retornado nesse parâmetro. Esse número corresponde à ordem do membro de dados na função [CRecordset::D ofieldexchange](../../mfc/reference/crecordset-class.md#dofieldexchange) ou [CRecordset::D obulkfieldexchange](../../mfc/reference/crecordset-class.md#dobulkfieldexchange) .

### <a name="return-value"></a>Valor retornado

Diferente de zero se a operação atual puder ser executada no campo ou tipo de parâmetro atual.

### <a name="remarks"></a>Comentários

Siga o modelo das funções suporte RFX existentes.

##  <a name="setfieldtype"></a>CFieldExchange::SetFieldType

Você precisa de uma chamada para `SetFieldType` na substituição de [DoFieldExchange](../../mfc/reference/crecordset-class.md#dofieldexchange) ou [DoBulkFieldExchange](../../mfc/reference/crecordset-class.md#dobulkfieldexchange) da sua classe do conjunto de registros.

```
void SetFieldType(UINT nFieldType);
```

### <a name="parameters"></a>Parâmetros

*nFieldType*<br/>
Um valor da `enum FieldType`, declarado em `CFieldExchange`, que pode ser um dos seguintes:

- `CFieldExchange::outputColumn`

- `CFieldExchange::inputParam`

- `CFieldExchange::param`

- `CFieldExchange::outputParam`

- `CFieldExchange::inoutParam`

### <a name="remarks"></a>Comentários

Para membros de dados de campo, você deve chamar `SetFieldType` com um parâmetro de `CFieldExchange::outputColumn`, seguido por chamadas para as funções suporte RFX ou suporte RFX em massa. Se você não tiver implementado a busca de linha em massa, ClassWizard colocará essa `SetFieldType` chamada para você na seção de mapa de campo de `DoFieldExchange`.

Se você parametrizar a classe do conjunto de registros, deverá chamar `SetFieldType` novamente, fora de qualquer seção de mapa de campo, seguida por chamadas suporte RFX para todos os membros de dados de parâmetro. Cada tipo de membro de dados de parâmetro deve ter sua própria chamada `SetFieldType`. A tabela a seguir distingue os valores diferentes que você pode passar para `SetFieldType` para representar os membros de dados de parâmetro de sua classe:

|Valor do parâmetro SetFieldType|Tipo de membro de dados de parâmetro|
|----------------------------------|-----------------------------------|
|`CFieldExchange::inputParam`|parâmetro de entrada. Um valor que é passado para a consulta ou procedimento armazenado do conjunto de registros.|
|`CFieldExchange::param` | o mesmo que `CFieldExchange::inputParam`.|
|`CFieldExchange::outputParam`|parâmetro de saída. Um valor de retorno do procedimento armazenado do conjunto de registros.|
|`CFieldExchange::inoutParam`|Parâmetro de entrada/saída. Um valor que é passado para e retornado do procedimento armazenado do conjunto de registros.|

Em geral, cada grupo de chamadas de função suporte RFX associadas a membros de dados de campo ou membros de dados de parâmetros deve ser precedido por uma chamada para `SetFieldType`. O parâmetro *nFieldType* de cada chamada de `SetFieldType` identifica o tipo dos membros de dados representados pelas chamadas de função suporte RFX que seguem a chamada `SetFieldType`.

Para obter mais informações sobre como tratar os parâmetros de saída e entrada/saída, consulte a `CRecordset` função membro [FlushResultSet](../../mfc/reference/crecordset-class.md#flushresultset). Para obter mais informações sobre as funções suporte RFX e suporte RFX em massa, consulte o tópico [registro do campo funções do Exchange](../../mfc/reference/record-field-exchange-functions.md). Para obter informações relacionadas sobre a busca de linha em massa, consulte o artigo [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

### <a name="example"></a>Exemplo

Este exemplo mostra várias chamadas para funções suporte RFX com chamadas que acompanham para `SetFieldType`. Observe que `SetFieldType` é chamado por meio do ponteiro de `pFX` para um objeto `CFieldExchange`.

[!code-cpp[NVC_MFCDatabase#33](../../mfc/codesnippet/cpp/cfieldexchange-class_1.cpp)]

## <a name="see-also"></a>Veja também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CRecordset](../../mfc/reference/crecordset-class.md)
