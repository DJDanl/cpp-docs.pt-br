---
title: Classe CDaoFieldExchange
ms.date: 09/17/2019
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
ms.openlocfilehash: cfffebd16c3c1d62dc4084b962c22911e4b46ae5
ms.sourcegitcommit: 069e3833bd821e7d64f5c98d0ea41fc0c5d22e53
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/21/2019
ms.locfileid: "74303887"
---
# <a name="cdaofieldexchange-class"></a>Classe CDaoFieldExchange

Dá suporte às rotinas de troca de campo de registro (DFX) do DAO usadas pelas classes de banco de dados DAO.

O DAO tem suporte por meio do Office 2013. O DAO 3,6 é a versão final e é considerado obsoleto.

## <a name="syntax"></a>Sintaxe

```
class CDaoFieldExchange
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CDaoFieldExchange::IsValidOperation](#isvalidoperation)|Retornará zero se a operação atual for apropriada para o tipo de campo que está sendo atualizado.|
|[CDaoFieldExchange::SetFieldType](#setfieldtype)|Especifica o tipo de membro de dados do conjunto de registros — coluna ou parâmetro — representado por todas as chamadas subsequentes para funções DFX até a próxima chamada para `SetFieldType`.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CDaoFieldExchange:: m_nOperation](#m_noperation)|A operação DFX que está sendo executada pela chamada atual para a função de membro `DoFieldExchange` do conjunto de registros.|
|[CDaoFieldExchange:: m_prs](#m_prs)|Um ponteiro para o conjunto de registros no qual as operações DFX estão sendo executadas.|

## <a name="remarks"></a>Comentários

`CDaoFieldExchange` não tem uma classe base.

Use essa classe se você estiver gravando rotinas de troca de dados para tipos de dados personalizados; caso contrário, você não usará essa classe diretamente. O DFX troca dados entre os membros de dados de campo do objeto [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) e os campos correspondentes do registro atual na fonte de dados. O DFX gerencia a troca em ambas as direções, da fonte de dados e da fonte de dados. Consulte a [Nota técnica 53](../../mfc/tn053-custom-dfx-routines-for-dao-database-classes.md) para obter informações sobre como escrever rotinas DFX personalizadas.

> [!NOTE]
>  As classes de banco de dados DAO são diferentes das classes de banco de dados MFC baseadas em ODBC (Open Database Connectivity). Todos os nomes de classe de banco de dados DAO têm o prefixo "CDao". Você ainda pode acessar fontes de dados ODBC com as classes DAO. Em geral, as classes do MFC baseadas no DAO são mais compatíveis do que as classes do MFC baseadas no ODBC. As classes baseadas em DAO podem acessar dados, incluindo por meio de drivers ODBC, por meio de seu próprio mecanismo de banco de dados. Eles também oferecem suporte a operações DDL (linguagem de definição de dados), como a adição de tabelas por meio de classes em vez de ter que chamar o DAO por conta própria.

> [!NOTE]
>  O intercâmbio de campo de registro DAO (DFX) é muito semelhante ao suporte RFX (Record Field Exchange) nas classes de banco de dados MFC baseadas em ODBC (`CDatabase`, `CRecordset`). Se você entender suporte RFX, achará fácil usar o DFX.

Um objeto `CDaoFieldExchange` fornece as informações de contexto necessárias para que o intercâmbio de campo do registro DAO ocorra. os objetos `CDaoFieldExchange` dão suporte a várias operações, incluindo parâmetros de associação e membros de dados de campo e configuração de vários sinalizadores nos campos do registro atual. As operações DFX são executadas em membros de dados de classe de conjunto de registros de tipos definidos pela **Enumeração** **FieldType** no `CDaoFieldExchange`. Os valores de **FieldType** possíveis são:

- `CDaoFieldExchange::outputColumn` para membros de dados de campo.

- `CDaoFieldExchange::param` para membros de dados de parâmetro.

A função membro [IsValidOperation](#isvalidoperation) é fornecida para escrever suas próprias rotinas de DFX personalizadas. Você usará [SetFieldType](#setfieldtype) frequentemente em suas funções [CDaoRecordset::D ofieldexchange](../../mfc/reference/cdaorecordset-class.md#dofieldexchange) . Para obter detalhes sobre as funções globais DFX, consulte [funções de troca de campo de registro](../../mfc/reference/record-field-exchange-functions.md). Para obter informações sobre como escrever rotinas de DFX personalizadas para seus próprios tipos de dados, consulte a [Nota técnica 53](../../mfc/tn053-custom-dfx-routines-for-dao-database-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CDaoFieldExchange`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** AFXDAO. h

##  <a name="isvalidoperation"></a>CDaoFieldExchange::IsValidOperation

Se você escrever sua própria função DFX, chame `IsValidOperation` no início da função para determinar se a operação atual pode ser executada em um tipo de membro de dados de campo específico (um `CDaoFieldExchange::outputColumn` ou um `CDaoFieldExchange::param`).

```
BOOL IsValidOperation();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se a operação atual for apropriada para o tipo de campo que está sendo atualizado.

### <a name="remarks"></a>Comentários

Algumas das operações executadas pelo mecanismo DFX se aplicam apenas a um dos tipos de campo possíveis. Siga o modelo das funções DFX existentes.

Para obter informações adicionais sobre como escrever rotinas de DFX personalizadas, consulte a [Nota técnica 53](../../mfc/tn053-custom-dfx-routines-for-dao-database-classes.md).

##  <a name="m_noperation"></a>CDaoFieldExchange:: m_nOperation

Identifica a operação a ser executada no objeto [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) associado ao objeto de troca de campo.

### <a name="remarks"></a>Comentários

O objeto `CDaoFieldExchange` fornece o contexto para várias operações DFX diferentes no conjunto de registros.

> [!NOTE]
>  O valor PSEUDONULL descrito nas operações MarkForAddNew e SetFieldNull abaixo é um valor usado para marcar os campos como nulos. O mecanismo de troca do campo de registro do DAO (DFX) usa esse valor para determinar quais campos foram explicitamente marcados como nulos. PSEUDONULL não é necessário para os campos [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) e [COleCurrency](../../mfc/reference/colecurrency-class.md) .

Os valores possíveis de `m_nOperation` são:

|Operação|Descrição|
|---------------|-----------------|
|`AddToParameterList`|Cria a cláusula **Parameters** da instrução SQL.|
|`AddToSelectList`|Compila a cláusula **Select** da instrução SQL.|
|`BindField`|Associa um campo no banco de dados a um local de memória em seu aplicativo.|
|`BindParam`|Define valores de parâmetro para a consulta do conjunto de registros.|
|`Fixup`|Define o status nulo de um campo.|
|`AllocCache`|Aloca o cache usado para verificar os campos "sujos" no conjunto de registros.|
|`StoreField`|Salva o registro atual no cache.|
|`LoadField`|Restaura as variáveis de membro de dados em cache no conjunto de registros.|
|`FreeCache`|Libera o cache usado para verificar se há campos "sujos" no conjunto de registros.|
|`SetFieldNull`|Define o status de um campo como nulo e o valor como PSEUDONULL.|
|`MarkForAddNew`|Marca os campos "sujos" se não PSEUDONULL.|
|`MarkForEdit`|Marca os campos "sujos" se não corresponderem ao cache.|
|`SetDirtyField`|Define valores de campo marcados como "sujos".|
|`DumpField`|Despeja o conteúdo de um campo (somente depuração).|
|`MaxDFXOperation`|Usado para verificação de entrada.|

##  <a name="m_prs"></a>CDaoFieldExchange:: m_prs

Contém um ponteiro para o objeto [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) associado ao objeto `CDaoFieldExchange`.

### <a name="remarks"></a>Comentários

##  <a name="setfieldtype"></a>CDaoFieldExchange::SetFieldType

Chame `SetFieldType` na substituição de `DoFieldExchange` da sua classe de `CDaoRecordset`.

```
void SetFieldType(UINT nFieldType);
```

### <a name="parameters"></a>Parâmetros

*nFieldType*<br/>
Um valor de **enum FieldType**, declarado em `CDaoFieldExchange`, que pode ser um dos seguintes:

- `CDaoFieldExchange::outputColumn`

- `CDaoFieldExchange::param`

### <a name="remarks"></a>Comentários

Normalmente, o ClassWizard grava essa chamada para você. Se você escrever sua própria função e estiver usando o assistente para escrever sua função `DoFieldExchange`, adicione chamadas para sua própria função fora do mapa de campos. Se você não usar o assistente, não haverá um mapa de campos. A chamada precede chamadas para funções DFX, uma para cada membro de dados de campo de sua classe e identifica o tipo de campo como `CDaoFieldExchange::outputColumn`.

Se você parametrizar a classe do conjunto de registros, deverá adicionar chamadas DFX para todos os membros de dados de parâmetro (fora do mapa de campo) e preceder essas chamadas com uma chamada para `SetFieldType`. Passe o valor `CDaoFieldExchange::param`. (Você pode, em vez disso, usar um [CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md) e definir seus valores de parâmetro.)

Em geral, cada grupo de chamadas de função DFX associadas a membros de dados de campo ou membros de dados de parâmetros deve ser precedido por uma chamada para `SetFieldType`. O parâmetro *nFieldType* de cada chamada de `SetFieldType` identifica o tipo dos membros de dados representados pelas chamadas de função DFX que seguem a chamada `SetFieldType`.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDaoRecordset](../../mfc/reference/cdaorecordset-class.md)
