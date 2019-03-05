---
title: Classe CDaoFieldExchange
ms.date: 11/04/2016
f1_keywords:
- CDaoFieldExchange
- AFXDAO/CDaoFieldExchange
- AFXDAO/CDaoFieldExchange::IsValidOperation
- AFXDAO/CDaoFieldExchange::SetFieldType
- AFXDAO/CDaoFieldExchange::m_nOperation
- AFXDAO/CDaoFieldExchange::m_prs
helpviewer_keywords:
- CDaoFieldExchange [MFC], IsValidOperation
- CDaoFieldExchange [MFC], SetFieldType
- CDaoFieldExchange [MFC], m_nOperation
- CDaoFieldExchange [MFC], m_prs
ms.assetid: 350a663e-92ff-44ab-ad53-d94efa2e5823
ms.openlocfilehash: d28739ced9aedd29106937cb717c87a241993036
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57291022"
---
# <a name="cdaofieldexchange-class"></a>Classe CDaoFieldExchange

Oferece suporte as rotinas de exchange (DFX) de campos de registro DAO usadas pelas classes de banco de dados DAO.

## <a name="syntax"></a>Sintaxe

```
class CDaoFieldExchange
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDaoFieldExchange::IsValidOperation](#isvalidoperation)|Retorna diferente de zero se a operação atual é apropriado para o tipo de campo que está sendo atualizado.|
|[CDaoFieldExchange::SetFieldType](#setfieldtype)|Especifica o tipo de membro de dados do conjunto de registros — coluna ou parâmetro — representado por todas as chamadas subsequentes a funções DFX até a próxima chamada para `SetFieldType`.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDaoFieldExchange::m_nOperation](#m_noperation)|A operação de DFX realizada pela chamada atual para o conjunto de registros `DoFieldExchange` função de membro.|
|[CDaoFieldExchange::m_prs](#m_prs)|Um ponteiro para o conjunto de registros nos quais DFX operações estão sendo executadas.|

## <a name="remarks"></a>Comentários

`CDaoFieldExchange` não tem uma classe base.

Use essa classe se você estiver escrevendo rotinas de troca de dados para tipos de dados personalizados. Caso contrário, você não diretamente usará essa classe. DFX troca dados entre os membros de dados do campo de sua [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) objeto e os campos correspondentes do registro atual na fonte de dados. DFX gerencia a troca em ambas as direções, da fonte de dados e à fonte de dados. Ver [53 de observação técnica](../../mfc/tn053-custom-dfx-routines-for-dao-database-classes.md) para obter informações sobre como escrever rotinas DFX personalizadas.

> [!NOTE]
>  As classes de banco de dados DAO são diferentes das classes de banco de dados MFC com base em conectividade aberta de banco de dados (ODBC). Todos os nomes de classe de banco de dados DAO têm o prefixo "CDao". Você ainda pode acessar fontes de dados ODBC com as classes DAO. Em geral, as classes do MFC com base em DAO são mais capacitadas que as classes do MFC com base em ODBC. As classes com base em DAO podem acessar dados, incluindo por meio de drivers ODBC, por meio de seu próprio mecanismo de banco de dados. Eles também dão suporte a operações de linguagem de definição de dados (DDL), como a adição de tabelas por meio de classes em vez de precisar chamar DAO por conta própria.

> [!NOTE]
>  Troca de campos de registro DAO (DFX) é muito semelhante ao registrar troca de campos (RFX) nas classes de banco de dados baseado em ODBC MFC ( `CDatabase`, `CRecordset`). Se você entender RFX, você achará fácil de usar DFX.

Um `CDaoFieldExchange` objeto fornece as informações de contexto necessárias para DAO registrar troca de campos entrem em vigor. `CDaoFieldExchange` objetos dão suporte a um número de operações, incluindo membros de dados de campo e parâmetros de ligação e definição de vários sinalizadores nos campos do registro atual. Operações de DFX são executadas nos membros de dados de classe de conjunto de registros de tipos definidos pelo **enum** **FieldType** em `CDaoFieldExchange`. Possíveis **FieldType** valores são:

- `CDaoFieldExchange::outputColumn` para membros de dados do campo.

- `CDaoFieldExchange::param` para membros de dados do parâmetro.

O [IsValidOperation](#isvalidoperation) função de membro é fornecida para escrever suas próprias rotinas DFX personalizadas. Você usará [SetFieldType](#setfieldtype) frequentemente no seu [CDaoRecordset::DoFieldExchange](../../mfc/reference/cdaorecordset-class.md#dofieldexchange) funções. Para obter detalhes sobre as funções globais de DFX, consulte [funções de troca de campo do registro](../../mfc/reference/record-field-exchange-functions.md). Para obter informações sobre como escrever rotinas DFX personalizadas para seus próprios tipos de dados, consulte [53 de observação técnica](../../mfc/tn053-custom-dfx-routines-for-dao-database-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CDaoFieldExchange`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdao.h

##  <a name="isvalidoperation"></a>  CDaoFieldExchange::IsValidOperation

Se você escrever sua própria função DFX, chame `IsValidOperation` no início de sua função para determinar se a operação atual pode ser executada em um tipo de membro de dados de campo específico (um `CDaoFieldExchange::outputColumn` ou um `CDaoFieldExchange::param`).

```
BOOL IsValidOperation();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a operação atual é apropriada para o tipo de campo que está sendo atualizado.

### <a name="remarks"></a>Comentários

Algumas das operações executadas pelo mecanismo DFX se aplicam somente a um dos tipos possíveis de campo. Siga o modelo das funções DFX existentes.

Para obter informações adicionais sobre como escrever rotinas DFX personalizadas, consulte [53 de observação técnica](../../mfc/tn053-custom-dfx-routines-for-dao-database-classes.md).

##  <a name="m_noperation"></a>  CDaoFieldExchange::m_nOperation

Identifica a operação a ser executada na [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) objeto associado ao objeto de troca de campo.

### <a name="remarks"></a>Comentários

O `CDaoFieldExchange` objeto fornece o contexto para um número de diferentes operações DFX o conjunto de registros.

> [!NOTE]
>  O valor de PSEUDONULL descrito em operações de MarkForAddNew e SetFieldNull abaixo é um valor usado para marcar campos nulos. O mecanismo de troca de campos de registro (DFX) DAO usa esse valor para determinar quais campos foram explicitamente marcadas como Null. PSEUDONULL não é necessário para [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) e [COleCurrency](../../mfc/reference/colecurrency-class.md) campos.

Os valores possíveis de `m_nOperation` são:

|Operação|Descrição|
|---------------|-----------------|
|`AddToParameterList`|Cria o **parâmetros** cláusula da instrução SQL.|
|`AddToSelectList`|Cria o **selecionar** cláusula da instrução SQL.|
|`BindField`|Associa um campo no banco de dados para um local de memória em seu aplicativo.|
|`BindParam`|Define os valores de parâmetro de consulta do conjunto de registros.|
|`Fixup`|Define o status Null para um campo.|
|`AllocCache`|Aloca o cache usado para verificar se há "sujos" campos do conjunto de registros.|
|`StoreField`|Salva o registro atual para o cache.|
|`LoadField`|Restaura as variáveis de membro de dados armazenados em cache no conjunto de registros.|
|`FreeCache`|Libera o cache usado para verificar se há "sujos" campos do conjunto de registros.|
|`SetFieldNull`|Define o status de um campo como nulo e o valor a ser PSEUDONULL.|
|`MarkForAddNew`|Campos de marcas "sujo" se não PSEUDONULL.|
|`MarkForEdit`|Marca os campos "sujo" se eles não coincidem com o cache.|
|`SetDirtyField`|Define os valores marcados como "sujo". de campo|
|`DumpField`|Despeja o conteúdo de um campo (somente debug).|
|`MaxDFXOperation`|Usado para verificação de entrada.|

##  <a name="m_prs"></a>  CDaoFieldExchange::m_prs

Contém um ponteiro para o [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) objeto associado com o `CDaoFieldExchange` objeto.

### <a name="remarks"></a>Comentários

##  <a name="setfieldtype"></a>  CDaoFieldExchange::SetFieldType

Chame `SetFieldType` em seu `CDaoRecordset` da classe `DoFieldExchange` substituir.

```
void SetFieldType(UINT nFieldType);
```

### <a name="parameters"></a>Parâmetros

*nFieldType*<br/>
Um valor de **enum FieldType**, declarado em `CDaoFieldExchange`, que pode ser qualquer um dos seguintes:

- `CDaoFieldExchange::outputColumn`

- `CDaoFieldExchange::param`

### <a name="remarks"></a>Comentários

Normalmente, o ClassWizard grava essa chamada para você. Se você escrever sua própria função e estiver usando o Assistente para escrever seu `DoFieldExchange` de função, adicione chamadas para sua própria função de fora o mapa de campo. Se você não usar o assistente, não haverá um mapa de campo. A chamada precede chamadas para funções DFX, uma para cada membro de dados do campo de sua classe e identifica o tipo de campo como `CDaoFieldExchange::outputColumn`.

Se você parametrizar sua classe de conjunto de registros, você deve adicionar DFX chamadas para todos os membros de dados de parâmetro (fora de mapa de campo) e preceder essas chamadas com uma chamada para `SetFieldType`. Passe o valor `CDaoFieldExchange::param`. (Em vez disso, você pode usar um [CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md) e defina seus valores de parâmetro.)

Em geral, cada grupo de chamadas de função DFX associados a membros de dados do campo ou membros de dados do parâmetro deve ser precedido por uma chamada para `SetFieldType`. O *nFieldType* parâmetro de cada `SetFieldType` chamada identifica o tipo dos membros de dados representado pelas chamadas de função DFX que seguem o `SetFieldType` chamar.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDaoRecordset](../../mfc/reference/cdaorecordset-class.md)
