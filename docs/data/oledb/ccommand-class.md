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
ms.openlocfilehash: 52c7e2ce5acdd2df33e2a6422535a337f0a43aec
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368625"
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

### <a name="parameters"></a>Parâmetros

*Taccessor*<br/>
O tipo de classe `CDynamicParameterAccessor`de `CDynamicStringAccessor`acessório `CEnumeratorAccessor`(como , ou ) que você deseja que o comando use. O padrão `CNoAccessor`é , que especifica que a classe não suporta parâmetros ou colunas de saída.

*Trowset*<br/>
O tipo de classe de `CArrayRowset` `CNoRowset`conjunto de linhas (como ou ) que você deseja que o comando use. O padrão é `CRowset`.

*Tmultiple*<br/>
Para usar um comando OLE DB que pode retornar vários resultados, especifique [CMultipleResults](../../data/oledb/cmultipleresults-class.md). Caso contrário, use [CNoMultipleResults](../../data/oledb/cnomultipleresults-class.md). Para obter detalhes, consulte [IMultipleResults](/previous-versions/windows/desktop/ms721289(v=vs.85)).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldbcli.h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[Fechar](#close)|Fecha o comando atual.|
|[Getnextresult](#getnextresult)|Busca o próximo resultado ao usar vários conjuntos de resultados.|
|[Abrir](#open)|Executa e obriga opcionalmente o comando.|

### <a name="inherited-methods"></a>Métodos herdados

|||
|-|-|
|[Criar](#create)|Cria um novo comando para a sessão especificada e define o texto de comando.|
|[CreateCommand](#createcommand)|Cria um novo comando.|
|[Getparameterinfo](#getparameterinfo)|Recebe uma lista dos parâmetros do comando, seus nomes e seus tipos.|
|[Preparar](#prepare)|Valida e otimiza o comando atual.|
|[Releasecommand](#releasecommand)|Libera o acessório de parâmetro, se necessário, e libera o comando.|
|[Setparameterinfo](#setparameterinfo)|Especifica o tipo nativo de cada parâmetro de comando.|
|[Unprepare](#unprepare)|Descarta o plano atual de execução de comando.|

## <a name="remarks"></a>Comentários

Use esta classe quando precisar executar uma operação baseada em parâmetros ou executar um comando. Se você apenas precisar abrir um conjunto de linhas simples, use [CTable](../../data/oledb/ctable-class.md) em vez disso.

A classe de acessório que você está usando determina o método de parâmetros e dados de vinculação.

Observe que você não pode usar procedimentos armazenados com o Provedor OLE DB para Jato porque esse provedor não suporta procedimentos armazenados (apenas constantes são permitidas em strings de consulta).

## <a name="ccommandclose"></a><a name="close"></a>CCommand::Fechar

Libera o conjunto de linhas de acessório associado ao comando.

### <a name="syntax"></a>Sintaxe

```cpp
void Close();
```

### <a name="remarks"></a>Comentários

Um comando usa um conjunto de linhas, um acessório de conjunto de resultados e (opcionalmente) um acessório de parâmetro (ao contrário das tabelas, que não suportam parâmetros e não precisam de um acessório de parâmetro).

Quando você executa um comando, você deve chamar ambos `Close` e [ReleaseCommand](../../data/oledb/ccommand-releasecommand.md) após o comando.

Quando você deseja executar o mesmo comando repetidamente, você `Close` deve `Execute`liberar cada acessório conjunto de resultados chamando antes de chamar . No final da série, você deve liberar o `ReleaseCommand`acessório de parâmetro chamando . Outro cenário comum é chamar um procedimento armazenado que tenha parâmetros de saída. Em muitos provedores (como o provedor OLE DB para SQL Server) os valores do parâmetro de saída não estarão acessíveis até que você feche o acessório conjunto de resultados. Chamada `Close` para fechar o conjunto de linhas retornado e o acessório conjunto de resultados, mas não o acessório de parâmetro, permitindo assim que você recupere os valores do parâmetro de saída.

### <a name="example"></a>Exemplo

O exemplo a seguir mostra como você pode chamar `Close` e `ReleaseCommand` quando executa o mesmo comando repetidamente.

[!code-cpp[NVC_OLEDB_Consumer#2](../../data/oledb/codesnippet/cpp/ccommand-close_1.cpp)]

## <a name="ccommandgetnextresult"></a><a name="getnextresult"></a>CCommand::getNextResult

Busca o próximo conjunto de resultados se estiver disponível.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT GetNextResult(DBROWCOUNT* pulRowsAffected,
   bool bBind = true) throw();
```

#### <a name="parameters"></a>Parâmetros

*pulRowsAffected*<br/>
[dentro/fora] Um ponteiro para a memória onde a contagem de linhas afetadas por um comando é devolvida.

*bVincular*<br/>
[em] Especifica se deve vincular o comando automaticamente após ser executado. O padrão é **verdadeiro,** o que faz com que o comando seja vinculado automaticamente. A *configuração bVincular-se* **a falso** impede a vinculação automática do comando para que você possa vincular manualmente. (A vinculação manual é de interesse particular dos usuários do OLAP.)

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Se um conjunto de resultados tiver sido anteriormente buscado, esta função libera o conjunto de resultados anterior e desvincula as colunas. Se *bBind* for **verdadeiro,** ele liga as novas colunas.

Você deve chamar esta função somente se tiver `CCommand` especificado vários resultados definindo o parâmetro de modelo *TMultiple*=`CMultipleResults`.

## <a name="ccommandopen"></a><a name="open"></a>CCommand::Abrir

Executa e obriga opcionalmente o comando.

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

#### <a name="parameters"></a>Parâmetros

*Sessão*<br/>
[em] A sessão em que executar o comando.

*wszCommand*<br/>
[em] O comando para executar, passou como uma seqüência Unicode. Pode ser NULO ao usar `CAccessor`, nesse caso o comando será recuperado a partir do valor passado para a macro [DEFINE_COMMAND.](../../data/oledb/define-command.md) Consulte [ICommand::Execute](/previous-versions/windows/desktop/ms718095(v=vs.85)) na *referência do programador OLE DB* para obter detalhes.

*Szcommand*<br/>
[em] O mesmo que *wszCommand,* exceto que este parâmetro leva uma seqüência de comando ANSI. A quarta forma deste método pode ter um valor NULL. Consulte "Observações" mais tarde neste tópico para obter detalhes.

*pPropSet*<br/>
[em] Um ponteiro para uma matriz de estruturas [DBPROPSET](/previous-versions/windows/desktop/ms714367(v=vs.85)) contendo propriedades e valores a serem definidos. Consulte [Conjuntos de propriedades e grupos de propriedades](/previous-versions/windows/desktop/ms713696(v=vs.85)) na referência do *programador OLE DB* no SDK do Windows.

*Prowsaffected*<br/>
[dentro/fora] Um ponteiro para a memória onde a contagem de linhas afetadas por um comando é devolvida. Se * \*pRowsAffected* for NULL, nenhuma contagem de linhas será retornada. Caso contrário, `Open` define * \*pRowsAfetados* de acordo com as seguintes condições:

|Se|Então|
|--------|----------|
|O `cParamSets` elemento `pParams` de é maior que 1|pRowsAffected representa o número total de linhas afetadas por todos os conjuntos de parâmetros especificados na execução. * \**|
|O número de linhas afetadas não está disponível|pRowsAffected está definido como -1. * \**|
|O comando não atualiza, exclui ou insere linhas|pRowsAffected é indefinido. * \**|

*guidCommand*<br/>
[em] Um GUID que especifica a sintaxe e as regras gerais para o provedor usar na análise do texto de comando. Consulte [ICommandText::GetCommandText](/previous-versions/windows/desktop/ms709825(v=vs.85)) e [iCommandText::SetCommandText](/previous-versions/windows/desktop/ms709757(v=vs.85)) in *the OLE DB Programr's Reference* for details.

*bVincular*<br/>
[em] Especifica se deve vincular o comando automaticamente após ser executado. O padrão é **verdadeiro,** o que faz com que o comando seja vinculado automaticamente. A *configuração bVincular-se* **a falso** impede a vinculação automática do comando para que você possa vincular manualmente. (A vinculação manual é de interesse particular dos usuários do OLAP.)

*ulPropSets*<br/>
[em] O número de estruturas [DBPROPSET](/previous-versions/windows/desktop/ms714367(v=vs.85)) passou no argumento *pPropSet.*

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

As três primeiras `Open` formas de tomar uma sessão, criar um comando e executar o comando, vinculando quaisquer parâmetros conforme necessário.

A primeira `Open` forma de captura de comando Unicode e não tem valor padrão.

A segunda `Open` forma de tem uma seqüência de comando ANSI e nenhum valor padrão (fornecido para compatibilidade retrógrada com aplicativos ANSI existentes).

A terceira `Open` forma de permite que a seqüência de comando seja NULA, por causa do tipo **int** com um valor padrão de NULL. Está previsto para `Open(session, NULL);` chamada `Open(session);` ou porque NULL é do tipo **int**. Esta versão requer e afirma que o parâmetro **int** seja NULL.

Use a quarta `Open` forma de quando você já criou um comando e deseja executar um único [Prepare](../../data/oledb/ccommand-prepare.md) e várias execuções.

> [!NOTE]
> `Open`chamadas `Execute`, que `GetNextResult`por sua vez chama .

## <a name="ccommandcreate"></a><a name="create"></a>CCommand::Criar

Chama [CCommand::CreateCommand](../../data/oledb/ccommand-createcommand.md) para criar um comando para a sessão especificada e, em seguida, chama [ICommandText::SetCommandText](/previous-versions/windows/desktop/ms709825(v=vs.85)) para especificar o texto de comando.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT CCommandBase::Create(const CSession& session,
   LPCWSTR wszCommand,
   REFGUID guidCommand = DBGUID_DEFAULT) throw ();

HRESULT CCommandBase::Create(const CSession& session,
   LPCSTR szCommand,
   REFGUID guidCommand = DBGUID_DEFAULT) throw ();
```

#### <a name="parameters"></a>Parâmetros

*Sessão*<br/>
[em] Uma sessão sobre a qual criar o comando.

*wszCommand*<br/>
[em] Um ponteiro para o texto Unicode da seqüência de comandos.

*Szcommand*<br/>
[em] Um ponteiro para o texto ANSI da seqüência de comandos.

*guidCommand*<br/>
[em] Um GUID que especifica a sintaxe e as regras gerais para o provedor usar na análise do texto de comando. Para obter uma descrição dos dialetos, consulte [ICommandText::GetCommandText](/previous-versions/windows/desktop/ms709825(v=vs.85)) na *referência do programador OLE DB*.

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

A primeira `Create` forma de pega uma seqüência de comando Unicode. A segunda `Create` forma de tem uma seqüência de comando ANSI (fornecida para compatibilidade retrógrada com aplicativos ANSI existentes).

## <a name="ccommandcreatecommand"></a><a name="createcommand"></a>CCommand::CreateCommand

Cria um novo comando.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT CCommandBase::CreateCommand(const CSession& session) throw ();
```

#### <a name="parameters"></a>Parâmetros

*Sessão*<br/>
[em] Um `CSession` objeto a ser associado com o novo comando.

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Este método cria um comando usando o objeto de sessão especificado.

## <a name="ccommandgetparameterinfo"></a><a name="getparameterinfo"></a>CCommand::GetParameterInfo

Recebe uma lista dos parâmetros do comando, seus nomes e seus tipos.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT CCommandBase::GetParameterInfo(DB_UPARAMS* pParams,
   DBPARAMINFO** ppParamInfo,
   OLECHAR** ppNamesBuffer) throw ();
```

#### <a name="parameters"></a>Parâmetros

Consulte [ICommandWithParameters::GetParameterInfo](/previous-versions/windows/desktop/ms714917(v=vs.85)) na *referência do programador OLE DB*.

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

## <a name="ccommandprepare"></a><a name="prepare"></a>CCommand::Prepare

Valida e otimiza o comando atual.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT CCommandBase::Prepare(ULONG cExpectedRuns = 0) throw();
```

#### <a name="parameters"></a>Parâmetros

*cExpectedRuns*<br/>
[em] O número de vezes que você espera executar o comando.

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Este método envolve o método OLE DB [ICommandPrepare::Prepare](/previous-versions/windows/desktop/ms718370(v=vs.85)).

## <a name="ccommandreleasecommand"></a><a name="releasecommand"></a>CCommand::Comando de lançamento

Libera o acessório de parâmetro e libera o comando em si.

### <a name="syntax"></a>Sintaxe

```cpp
void CCommandBase::ReleaseCommand() throw();
```

### <a name="remarks"></a>Comentários

`ReleaseCommand`é usado em `Close`conjunto com . Consulte [Close](../../data/oledb/ccommand-close.md) para obter detalhes de uso.

## <a name="ccommandsetparameterinfo"></a><a name="setparameterinfo"></a>CCommand::SetParameterInfo

Especifica o tipo nativo de cada parâmetro de comando.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT CCommandBase::SetParameterInfo(DB_UPARAMS ulParams,
   const DBORDINAL* pOrdinals,
   const DBPARAMBINDINFO* pParamInfo) throw();
```

#### <a name="parameters"></a>Parâmetros

Consulte [ICommandWithParameters::SetParameterInfo](/previous-versions/windows/desktop/ms725393(v=vs.85)) na *referência do programador OLE DB*.

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

## <a name="ccommandunprepare"></a><a name="unprepare"></a>CCommand::Despreparar

Descarta o plano atual de execução de comando.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT CCommandBase::Unprepare() throw();
```

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Este método envolve o método OLE DB [ICommandPrepare::Unprepare](/previous-versions/windows/desktop/ms719635(v=vs.85)).

## <a name="see-also"></a>Confira também

[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumo OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)
