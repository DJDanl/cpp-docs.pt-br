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
ms.openlocfilehash: e1ce6e13b9c6045881cc0bb4114a6e11d58365c8
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368987"
---
# <a name="cdaofieldexchange-class"></a>Classe CDaoFieldExchange

Suporta as rotinas de troca de campo de registro DAO (DFX) usadas pelas classes de banco de dados DAO.

O DAO é suportado através do Office 2013. DAO 3.6 é a versão final, e é considerada obsoleta.

## <a name="syntax"></a>Sintaxe

```
class CDaoFieldExchange
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDaoFieldExchange::IsValidOperation](#isvalidoperation)|Retorna não zero se a operação atual for apropriada para o tipo de campo que está sendo atualizado.|
|[CDaoFieldExchange::SetFieldType](#setfieldtype)|Especifica o tipo de membro de dados do conjunto de registros — coluna ou parâmetro `SetFieldType`— representado por todas as chamadas subseqüentes às funções DFX até a próxima chamada para .|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDaoFieldExchange::m_nOperation](#m_noperation)|A operação DFX que está sendo executada pela `DoFieldExchange` chamada atual para a função de membro do conjunto de registros.|
|[CDaoFieldExchange::m_prs](#m_prs)|Um ponteiro para o conjunto de registros em que as operações de DFX estão sendo realizadas.|

## <a name="remarks"></a>Comentários

`CDaoFieldExchange`não tem uma classe base.

Use esta classe se estiver escrevendo rotinas de troca de dados para tipos de dados personalizados; caso contrário, você não usará diretamente esta classe. O DFX troca dados entre os membros de dados de campo do objeto [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) e os campos correspondentes do registro atual na fonte de dados. O DFX gerencia a troca em ambas as direções, desde a fonte de dados até a fonte de dados. Consulte [nota técnica 53](../../mfc/tn053-custom-dfx-routines-for-dao-database-classes.md) para obter informações sobre como escrever rotinas personalizadas de DFX.

> [!NOTE]
> As classes de banco de dados DAO são distintas das classes de banco de dados MFC baseadas em Conectividade de Banco de Dados Aberto (ODBC). Todos os nomes de classe de banco de dados DAO têm o prefixo "CDao". Você ainda pode acessar fontes de dados oDBC com as classes DAO. Em geral, as classes de MFC baseadas em DAO são mais capazes do que as classes MFC baseadas no ODBC. As classes baseadas em DAO podem acessar dados, inclusive através de drivers ODBC, através de seu próprio mecanismo de banco de dados. Eles também suportam operações ddl (Data Definition Language, linguagem de definição de dados), como adicionar tabelas através das classes, em vez de ter que chamar dao você mesmo.

> [!NOTE]
> O DFX (Record Field Exchange, troca de registros) é muito semelhante ao Detroca de `CDatabase` `CRecordset`Campo de Registro (RFX) nas classes de banco de dados MFC baseadas em ODBC (, no horário de Brasília). Se você entende RFX, você vai achar fácil de usar O DFX.

Um `CDaoFieldExchange` objeto fornece as informações de contexto necessárias para que a troca de campo de registro DAO ocorra. `CDaoFieldExchange`os objetos suportam uma série de operações, incluindo parâmetros de vinculação e membros de dados de campo e definindo várias bandeiras nos campos do registro atual. As operações DeSlemo são realizadas em membros de `CDaoFieldExchange`dados de classe de registro de tipos definidos pelo **enum** **FieldType** em . Os valores possíveis **do FieldType** são:

- `CDaoFieldExchange::outputColumn`para membros de dados de campo.

- `CDaoFieldExchange::param`para membros de dados de parâmetros.

A função membro [IsValidOperation](#isvalidoperation) é fornecida para escrever suas próprias rotinas de DFX personalizadas. Você usará [SetFieldType](#setfieldtype) frequentemente em suas funções [CDaoRecordset::DoFieldExchange.](../../mfc/reference/cdaorecordset-class.md#dofieldexchange) Para obter detalhes sobre as funções globais do DFX, consulte [Funções de troca de campo de registro](../../mfc/reference/record-field-exchange-functions.md). Para obter informações sobre como escrever rotinas dfx personalizadas para seus próprios tipos de dados, consulte [Nota Técnica 53](../../mfc/tn053-custom-dfx-routines-for-dao-database-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CDaoFieldExchange`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdao.h

## <a name="cdaofieldexchangeisvalidoperation"></a><a name="isvalidoperation"></a>CDaoFieldExchange::IsValidOperation

Se você escrever sua própria `IsValidOperation` função DFX, ligue no início de sua função para determinar se `CDaoFieldExchange::outputColumn` a `CDaoFieldExchange::param`operação atual pode ser executada em um determinado tipo de membro de dados de campo (a ou a ).

```
BOOL IsValidOperation();
```

### <a name="return-value"></a>Valor retornado

Não zero se a operação atual for adequada para o tipo de campo que está sendo atualizado.

### <a name="remarks"></a>Comentários

Algumas das operações realizadas pelo mecanismo DFX aplicam-se apenas a um dos possíveis tipos de campo. Siga o modelo das funções DFX existentes.

Para obter informações adicionais sobre a escrita de rotinas personalizadas de DFX, consulte [Nota Técnica 53](../../mfc/tn053-custom-dfx-routines-for-dao-database-classes.md).

## <a name="cdaofieldexchangem_noperation"></a><a name="m_noperation"></a>CDaoFieldExchange::m_nOperation

Identifica a operação a ser executada no objeto [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) associado ao objeto de troca de campo.

### <a name="remarks"></a>Comentários

O `CDaoFieldExchange` objeto fornece o contexto para várias operações diferentes de DFX no conjunto de registros.

> [!NOTE]
> O valor PSEUDONULL descrito nas operações MarkForAddNew e SetFieldNull abaixo é um valor usado para marcar campos Nulos. O mecanismo de troca de campo de registro DAO (DFX) usa esse valor para determinar quais campos foram explicitamente marcados como Nulos. PSEUDONULL não é necessário para os campos [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) e [COleCurrency.](../../mfc/reference/colecurrency-class.md)

Os valores possíveis `m_nOperation` são:

|Operação|Descrição|
|---------------|-----------------|
|`AddToParameterList`|Constrói a cláusula **PARAMETERS** da declaração SQL.|
|`AddToSelectList`|Constrói a cláusula **SELECT** da declaração SQL.|
|`BindField`|Vincula um campo no banco de dados a um local de memória em seu aplicativo.|
|`BindParam`|Define valores de parâmetro para a consulta do conjunto de registros.|
|`Fixup`|Define o status Nulo para um campo.|
|`AllocCache`|Aloca o cache usado para verificar se há campos "sujos" no conjunto de registros.|
|`StoreField`|Salva o registro atual no cache.|
|`LoadField`|Restaura as variáveis de membro de dados armazenados em cache no conjunto de registros.|
|`FreeCache`|Libera o cache usado para verificar se há campos "sujos" no conjunto de registros.|
|`SetFieldNull`|Define o status de um campo como Nulo e o valor é PSEUDONULL.|
|`MarkForAddNew`|Marcas campos "sujos" se não PSEUDONULL.|
|`MarkForEdit`|As marcas são "sujas" se não corresponderem ao cache.|
|`SetDirtyField`|Define valores de campo marcados como "sujos".|
|`DumpField`|Despeja o conteúdo de um campo (somente depuração).|
|`MaxDFXOperation`|Usado para verificação de entrada.|

## <a name="cdaofieldexchangem_prs"></a><a name="m_prs"></a>CDaoFieldExchange::m_prs

Contém um ponteiro para o objeto [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) associado ao `CDaoFieldExchange` objeto.

### <a name="remarks"></a>Comentários

## <a name="cdaofieldexchangesetfieldtype"></a><a name="setfieldtype"></a>CDaoFieldExchange::SetFieldType

Ligue `SetFieldType` para `CDaoRecordset` a `DoFieldExchange` substituição da sua classe.

```
void SetFieldType(UINT nFieldType);
```

### <a name="parameters"></a>Parâmetros

*nFieldType*<br/>
Um valor do **enum FieldType,** declarado em `CDaoFieldExchange`, que pode ser um dos seguintes:

- `CDaoFieldExchange::outputColumn`

- `CDaoFieldExchange::param`

### <a name="remarks"></a>Comentários

Normalmente, classwizard escreve esta chamada para você. Se você escrever sua própria função e `DoFieldExchange` estiver usando o assistente para escrever sua função, adicione chamadas à sua própria função fora do mapa de campo. Se você não usar o assistente, não haverá um mapa de campo. A chamada precede chamadas para funções DFX, uma para cada membro de dados `CDaoFieldExchange::outputColumn`de campo da sua classe, e identifica o tipo de campo como .

Se você parametrizar sua classe de conjunto de registros, você deve adicionar chamadas DFX para todos `SetFieldType`os membros de dados de parâmetros (fora do mapa de campo) e preceder essas chamadas com uma chamada para . Passe o `CDaoFieldExchange::param`valor . (Você pode, em vez disso, usar um [CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md) e definir seus valores de parâmetro.)

Em geral, cada grupo de chamadas de função DFX associadas a membros de `SetFieldType`dados de campo ou membros de dados de parâmetros deve ser precedido por uma chamada para . O parâmetro *nFieldType* `SetFieldType` de cada chamada identifica o tipo de membros de dados `SetFieldType` representados pelas chamadas de função DFX que seguem a chamada.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDaoRecordset](../../mfc/reference/cdaorecordset-class.md)
