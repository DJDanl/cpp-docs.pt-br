---
title: Classe CCommand
ms.date: 11/04/2016
f1_keywords:
- ATL::CCommand
- CCommand
- ATL.CCommand
- CCommand.Close
- CCommand::Close
- CCommand.Create
- CCommand::Create
- CCommand.CreateCommand
- CreateCommand
- CCommand::CreateCommand
- ATL::CCommand::GetNextResult
- CCommand::GetNextResult
- GetNextResult
- CCommand.GetNextResult
- ATL.CCommand.GetNextResult
- GetParameterInfo
- CCommand.GetParameterInfo
- CCommand::GetParameterInfo
- ATL.CCommand.Open
- ATL::CCommand::Open
- CCommand.Open
- CCommand::Open
- CCommand.Prepare
- CCommand::Prepare
- Prepare
- CCommand.ReleaseCommand
- ReleaseCommand
- CCommand::ReleaseCommand
- SetParameterInfo
- CCommand.SetParameterInfo
- CCommand::SetParameterInfo
- Unprepare
- CCommand.Unprepare
- CCommand::Unprepare
helpviewer_keywords:
- CCommand class
- Close method
- Create method [C++]
- CreateCommand method
- GetNextResult method
- GetParameterInfo method
- Open method
- Prepare method
- ReleaseCommand method
- SetParameterInfo method
- Unprepare method
ms.assetid: 0760bfc5-b9ee-4aee-8e54-31bd78714d3a
ms.openlocfilehash: 73b02f0ffb9d9b98a17933cc3b17c8627121e3ac
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87228915"
---
# <a name="ccommand-class"></a>Classe CCommand

Fornece métodos para definir e executar um comando.

## <a name="syntax"></a>Sintaxe

```cpp
template <class TAccessor = CNoAccessor,
   template <typename T> class TRowset = CRowset,
   class TMultiple = CNoMultipleResults>
class CCommand :
   public CAccessorRowset <TAccessor, TRowset>,
   public CCommandBase,
   public TMultiple
```

### <a name="parameters"></a>parâmetros

*TAccessor*<br/>
O tipo de classe de acessador (como `CDynamicParameterAccessor` , `CDynamicStringAccessor` ou `CEnumeratorAccessor` ) que você deseja que o comando use. O padrão é `CNoAccessor` , que especifica que a classe não dá suporte a parâmetros ou colunas de saída.

*TRowset*<br/>
O tipo de classe do conjunto de linhas (como `CArrayRowset` ou `CNoRowset` ) que você deseja que o comando use. O padrão é `CRowset`.

*TMultiple*<br/>
Para usar um comando OLE DB que pode retornar vários resultados, especifique [CMultipleResults](../../data/oledb/cmultipleresults-class.md). Caso contrário, use [CNoMultipleResults](../../data/oledb/cnomultipleresults-class.md). Para obter detalhes, consulte [IMultipleResults](/previous-versions/windows/desktop/ms721289(v=vs.85)).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldbcli. h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[Fechar](#close)|Fecha o comando atual.|
|[GetNextResult](#getnextresult)|Busca o próximo resultado ao usar vários conjuntos de resultados.|
|[Abrir](#open)|Executa e, opcionalmente, associa o comando.|

### <a name="inherited-methods"></a>Métodos herdados

|||
|-|-|
|[Criar](#create)|Cria um novo comando para a sessão especificada e, em seguida, define o texto do comando.|
|[CreateCommand](#createcommand)|Cria um novo comando.|
|[GetParameterInfo](#getparameterinfo)|Obtém uma lista dos parâmetros do comando, seus nomes e seus tipos.|
|[Preparar](#prepare)|Valida e otimiza o comando atual.|
|[ReleaseCommand](#releasecommand)|Libera o acessador de parâmetro, se necessário, e libera o comando.|
|[SetParameterInfo](#setparameterinfo)|Especifica o tipo nativo de cada parâmetro de comando.|
|[Unprepare](#unprepare)|Descarta o plano de execução do comando atual.|

## <a name="remarks"></a>Comentários

Use essa classe quando precisar executar uma operação baseada em parâmetro ou executar um comando. Se você simplesmente precisar abrir um conjunto de linhas simples, use [CTable](../../data/oledb/ctable-class.md) em vez disso.

A classe acessador que você está usando determina o método de vinculação de parâmetros e dados.

Observe que você não pode usar procedimentos armazenados com o provedor de OLE DB para Jet, pois esse provedor não oferece suporte a procedimentos armazenados (somente constantes são permitidas em cadeias de caracteres de consulta).

## <a name="ccommandclose"></a><a name="close"></a>CCommand:: fechar

Libera o conjunto de linhas de acessador associado ao comando.

### <a name="syntax"></a>Sintaxe

```cpp
void Close();
```

### <a name="remarks"></a>Comentários

Um comando usa um conjunto de linhas, acessador de conjunto de resultados e (opcionalmente) um acessador de parâmetro (ao contrário de tabelas, que não dão suporte a parâmetros e não precisam de um acessador de parâmetro).

Ao executar um comando, você deve chamar ambos `Close` e [ReleaseCommand](../../data/oledb/ccommand-releasecommand.md) após o comando.

Quando você quiser executar o mesmo comando repetidamente, deverá liberar cada acessador de conjunto de resultados chamando `Close` antes de chamar `Execute` . No final da série, você deve liberar o acessador de parâmetro chamando `ReleaseCommand` . Outro cenário comum é chamar um procedimento armazenado que tem parâmetros de saída. Em muitos provedores (como o provedor de OLE DB para SQL Server), os valores de parâmetros de saída não estarão acessíveis até que você feche o acessador de conjunto de resultados. Chame `Close` para fechar o conjunto de linhas retornado e o acessador de conjunto de resultados, mas não o acessador de parâmetro, permitindo assim que você recupere os valores de parâmetro de saída.

### <a name="example"></a>Exemplo

O exemplo a seguir mostra como você pode chamar `Close` e `ReleaseCommand` quando executa o mesmo comando repetidamente.

[!code-cpp[NVC_OLEDB_Consumer#2](../../data/oledb/codesnippet/cpp/ccommand-close_1.cpp)]

## <a name="ccommandgetnextresult"></a><a name="getnextresult"></a>CCommand::GetNextResult

Busca o próximo conjunto de resultados, se houver um disponível.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT GetNextResult(DBROWCOUNT* pulRowsAffected,
   bool bBind = true) throw();
```

#### <a name="parameters"></a>parâmetros

*pulRowsAffected*<br/>
[entrada/saída] Um ponteiro para a memória em que a contagem de linhas afetadas por um comando é retornada.

*bBind*<br/>
no Especifica se o comando deve ser associado automaticamente após ser executado. O padrão é **`true`** , que faz com que o comando seja vinculado automaticamente. Definir *bBind* para **`false`** impedir a associação automática do comando para que você possa associar manualmente. (A vinculação manual é de interesse particular para os usuários OLAP.)

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Se um conjunto de resultados tiver sido previamente buscado, essa função liberará o conjunto de resultados anterior e desassociará as colunas. Se *bBind* for **`true`** , ele associará as novas colunas.

Você deve chamar essa função somente se tiver especificado vários resultados definindo o parâmetro de `CCommand` modelo *TMultiple* = `CMultipleResults` .

## <a name="ccommandopen"></a><a name="open"></a>CCommand:: abrir

Executa e, opcionalmente, associa o comando.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT Open(const CSession& session,
   LPCWSTR wszCommand,
   DBPROPSET *pPropSet = NULL,
   DBROWCOUNT* pRowsAffected = NULL,
   REFGUID guidCommand = DBGUID_DEFAULT,
   bool bBind = true,
   ULONG ulPropSets = 0) throw();

HRESULT Open(const CSession& session,
   LPCSTR szCommand,
   DBPROPSET *pPropSet = NULL,
   DBROWCOUNT* pRowsAffected = NULL,
   REFGUID guidCommand = DBGUID_DEFAULT,
   bool bBind = true,
   ULONG ulPropSets = 0) throw();

HRESULT Open(const CSession& session,
   INT szCommand = NULL,
   DBPROPSET *pPropSet = NULL,
   DBROWCOUNT* pRowsAffected = NULL,
   REFGUID guidCommand = DBGUID_DEFAULT,
   bool bBind = true,
   ULONG ulPropSets = 0) throw();

HRESULT Open(DBPROPSET *pPropSet = NULL,
   DBROWCOUNT* pRowsAffected = NULL,
   bool bBind = true,
   ULONG ulPropSets = 0) throw();
```

#### <a name="parameters"></a>parâmetros

*sessão*<br/>
no A sessão na qual executar o comando.

*wszCommand*<br/>
no O comando a ser executado, passado como uma cadeia de caracteres Unicode. Pode ser NULL ao usar `CAccessor` , caso em que o comando será recuperado do valor passado para a macro [DEFINE_COMMAND](../../data/oledb/define-command.md) . Consulte [ICommand:: execute](/previous-versions/windows/desktop/ms718095(v=vs.85)) na *referência do programador de OLE DB* para obter detalhes.

*szCommand*<br/>
no O mesmo que *wszCommand* , exceto pelo fato de que esse parâmetro usa uma cadeia de caracteres de comando ANSI. A quarta forma desse método pode usar um valor nulo. Consulte "Comentários" mais adiante neste tópico para obter detalhes.

*pPropSet*<br/>
no Um ponteiro para uma matriz de estruturas [DBPROPSET](/previous-versions/windows/desktop/ms714367(v=vs.85)) que contém propriedades e valores a serem definidos. Consulte [conjuntos de propriedades e grupos de propriedades](/previous-versions/windows/desktop/ms713696(v=vs.85)) na *referência do programador de OLE DB* no SDK do Windows.

*pRowsAffected*<br/>
[entrada/saída] Um ponteiro para a memória em que a contagem de linhas afetadas por um comando é retornada. Se * \* PROWSAFFECTED* for nulo, nenhuma contagem de linhas será retornada. Caso contrário, o `Open` define * \* pRowsAffected* de acordo com as seguintes condições:

|Se|Então|
|--------|----------|
|O `cParamSets` elemento de `pParams` é maior que 1|* \* pRowsAffected* representa o número total de linhas afetadas por todos os conjuntos de parâmetros especificados na execução.|
|O número de linhas afetadas não está disponível|* \* pRowsAffected* é definido como-1.|
|O comando não atualiza, exclui ou insere linhas|* \* pRowsAffected* é indefinido.|

*guidCommand*<br/>
no Um GUID que especifica a sintaxe e as regras gerais para o provedor usar na análise do texto do comando. Consulte [ICommandText:: GetCommandText](/previous-versions/windows/desktop/ms709825(v=vs.85)) e [ICommandText:: SetCommandText](/previous-versions/windows/desktop/ms709757(v=vs.85)) na *referência do programador de OLE DB* para obter detalhes.

*bBind*<br/>
no Especifica se o comando deve ser associado automaticamente após ser executado. O padrão é **`true`** , que faz com que o comando seja vinculado automaticamente. Definir *bBind* para **`false`** impedir a associação automática do comando para que você possa associar manualmente. (A vinculação manual é de interesse particular para os usuários OLAP.)

*ulPropSets*<br/>
no O número de estruturas [DBPROPSET](/previous-versions/windows/desktop/ms714367(v=vs.85)) passadas no argumento *pPropSet* .

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

As três primeiras formas de `Open` fazer uma sessão, criar um comando e executar o comando, ligando quaisquer parâmetros conforme necessário.

A primeira forma de `Open` usa uma cadeia de caracteres de comando Unicode e não tem valor padrão.

A segunda forma de `Open` usa uma cadeia de caracteres de comando ANSI e nenhum valor padrão (fornecido para compatibilidade com versões anteriores com os aplicativos ANSI existentes).

A terceira forma de `Open` permite que a cadeia de caracteres de comando seja nula, devido **`int`** ao tipo com um valor padrão de NULL. Ele é fornecido para chamada `Open(session, NULL);` ou `Open(session);` porque NULL é do tipo **`int`** . Essa versão requer e declara que o **`int`** parâmetro é nulo.

Use a quarta forma de `Open` quando você já criou um comando e deseja executar uma única [preparação](../../data/oledb/ccommand-prepare.md) e várias execuções.

> [!NOTE]
> `Open`chamadas `Execute` que, por sua vez, chamam `GetNextResult` .

## <a name="ccommandcreate"></a><a name="create"></a>CCommand:: criar

Chama [CCommand:: CreateCommand](../../data/oledb/ccommand-createcommand.md) para criar um comando para a sessão especificada e, em seguida, chama [ICommandText:: SetCommandText](/previous-versions/windows/desktop/ms709825(v=vs.85)) para especificar o texto do comando.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT CCommandBase::Create(const CSession& session,
   LPCWSTR wszCommand,
   REFGUID guidCommand = DBGUID_DEFAULT) throw ();

HRESULT CCommandBase::Create(const CSession& session,
   LPCSTR szCommand,
   REFGUID guidCommand = DBGUID_DEFAULT) throw ();
```

#### <a name="parameters"></a>parâmetros

*sessão*<br/>
no Uma sessão na qual o comando será criado.

*wszCommand*<br/>
no Um ponteiro para o texto Unicode da cadeia de caracteres de comando.

*szCommand*<br/>
no Um ponteiro para o texto ANSI da cadeia de caracteres de comando.

*guidCommand*<br/>
no Um GUID que especifica a sintaxe e as regras gerais para o provedor usar na análise do texto do comando. Para obter uma descrição de dialetos, consulte [ICommandText:: GetCommandText](/previous-versions/windows/desktop/ms709825(v=vs.85)) na *referência do programador de OLE DB*.

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

A primeira forma de `Create` usa uma cadeia de caracteres de comando Unicode. A segunda forma de `Create` usa uma cadeia de caracteres de comando ANSI (fornecida para compatibilidade com versões anteriores com os aplicativos ANSI existentes).

## <a name="ccommandcreatecommand"></a><a name="createcommand"></a>CCommand:: CreateCommand

Cria um novo comando.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT CCommandBase::CreateCommand(const CSession& session) throw ();
```

#### <a name="parameters"></a>parâmetros

*sessão*<br/>
no Um `CSession` objeto a ser associado ao novo comando.

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Esse método cria um comando usando o objeto de sessão especificado.

## <a name="ccommandgetparameterinfo"></a><a name="getparameterinfo"></a>CCommand:: GetParameterInfo

Obtém uma lista dos parâmetros do comando, seus nomes e seus tipos.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT CCommandBase::GetParameterInfo(DB_UPARAMS* pParams,
   DBPARAMINFO** ppParamInfo,
   OLECHAR** ppNamesBuffer) throw ();
```

#### <a name="parameters"></a>parâmetros

Consulte [ICommandWithParameters:: GetParameterInfo](/previous-versions/windows/desktop/ms714917(v=vs.85)) na *referência do programador de OLE DB*.

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

## <a name="ccommandprepare"></a><a name="prepare"></a>CCommand::P reparênteses

Valida e otimiza o comando atual.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT CCommandBase::Prepare(ULONG cExpectedRuns = 0) throw();
```

#### <a name="parameters"></a>parâmetros

*cExpectedRuns*<br/>
no O número de vezes que você espera executar o comando.

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Esse método encapsula o método OLE DB [ICommandPrepare::P reparênteses](/previous-versions/windows/desktop/ms718370(v=vs.85)).

## <a name="ccommandreleasecommand"></a><a name="releasecommand"></a>CCommand::ReleaseCommand

Libera o acessador de parâmetro e, em seguida, libera o próprio comando.

### <a name="syntax"></a>Sintaxe

```cpp
void CCommandBase::ReleaseCommand() throw();
```

### <a name="remarks"></a>Comentários

`ReleaseCommand`é usado em conjunto com `Close` . Consulte [fechar](../../data/oledb/ccommand-close.md) para obter detalhes de uso.

## <a name="ccommandsetparameterinfo"></a><a name="setparameterinfo"></a>CCommand:: SetParameterInfo

Especifica o tipo nativo de cada parâmetro de comando.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT CCommandBase::SetParameterInfo(DB_UPARAMS ulParams,
   const DBORDINAL* pOrdinals,
   const DBPARAMBINDINFO* pParamInfo) throw();
```

#### <a name="parameters"></a>parâmetros

Consulte [ICommandWithParameters:: SetParameterInfo](/previous-versions/windows/desktop/ms725393(v=vs.85)) na *referência do programador de OLE DB*.

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

## <a name="ccommandunprepare"></a><a name="unprepare"></a>CCommand:: despreparar

Descarta o plano de execução do comando atual.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT CCommandBase::Unprepare() throw();
```

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Esse método encapsula o método OLE DB [ICommandPrepare:: Unprepare](/previous-versions/windows/desktop/ms719635(v=vs.85)).

## <a name="see-also"></a>Confira também

[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)
