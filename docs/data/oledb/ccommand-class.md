---
title: Classe CCommand | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 74cabc19dd21be78771fba177758131d13c8794d
ms.sourcegitcommit: 889a75be1232817150be1e0e8d4d7f48f5993af2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/30/2018
ms.locfileid: "39338357"
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
 *TAccessor*  
 O tipo de classe de acessador (como `CDynamicParameterAccessor`, `CDynamicStringAccessor`, ou `CEnumeratorAccessor`) que você deseja que o comando a ser usado. O padrão é `CNoAccessor`, que especifica que a classe não oferece suporte a parâmetros ou colunas de saída.  
  
 *TRowset*  
 O tipo de classe de conjunto de linhas (como `CArrayRowset` ou `CNoRowset`) que você deseja que o comando a ser usado. O padrão é `CRowset`.  
  
 *TMultiple*  
 Para usar um comando de OLE DB que pode retornar diversos resultados, especifique [CMultipleResults](../../data/oledb/cmultipleresults-class.md). Caso contrário, use [CNoMultipleResults](../../data/oledb/cnomultipleresults-class.md). Para obter detalhes, consulte [IMultipleResults](https://msdn.microsoft.com/library/ms721289.aspx).  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[Fechar](#close)|Fecha o comando atual.|  
|[GetNextResult](#getnextresult)|Busca o próximo resultado quando usando conjuntos de resultados múltiplos.|  
|[Abrir](#open)|Executa e opcionalmente associa o comando.|  
  
### <a name="inherited-methods"></a>Métodos herdados  
  
|||  
|-|-|  
|[criar](#create)|Cria um novo comando para a sessão especificada e, em seguida, define o texto do comando.|  
|[CreateCommand](#createcommand)|Cria um novo comando.|  
|[GetParameterInfo](#getparameterinfo)|Obtém uma lista de parâmetros do comando, seus nomes e seus tipos.|  
|[Preparar](#prepare)|Valida e otimiza o comando atual.|  
|[ReleaseCommand](#releasecommand)|Libera o acessador de parâmetro, se necessário e, em seguida, libera o comando.|  
|[SetParameterInfo](#setparameterinfo)|Especifica o tipo nativo de cada parâmetro de comando.|  
|[Unprepare](#unprepare)|Descarta o plano de execução do comando atual.|  
  
## <a name="remarks"></a>Comentários  
 Use essa classe quando você precisar realizar uma operação baseada em parâmetro ou executar um comando. Se você simplesmente precisa abrir um conjunto de linhas simple, use [CTable](../../data/oledb/ctable-class.md) em vez disso.  
  
 A classe de acessador que você está usando determina o método de associação de parâmetros e dados.  
  
 Observe que você não pode usar procedimentos armazenados com o provedor OLE DB para Jet porque esse provedor não oferece suporte armazenados procedimentos (somente constantes são permitidas nas cadeias de caracteres de consulta).  

## <a name="close"></a> Ccommand:: Close
Libera o conjunto de linhas de acessador associado ao comando.  
  
### <a name="syntax"></a>Sintaxe

```cpp
void Close();  
```  
  
### <a name="remarks"></a>Comentários  
 Um comando usa um conjunto de linhas, o acessador de conjunto de resultados e (opcionalmente) um acessador de parâmetro (ao contrário das tabelas, que não dão suporte a parâmetros e não é necessário um acessador de parâmetro).  
  
 Quando você executar um comando, você deverá chamar ambos `Close` e [ReleaseCommand](../../data/oledb/ccommand-releasecommand.md) após o comando.  
  
 Quando você deseja executar o mesmo comando repetidamente, você deve liberar cada acessador de conjunto de resultados chamando `Close` antes de chamar `Execute`. No final da série, você deve liberar o acessador de parâmetro ao chamar `ReleaseCommand`. Outro cenário comum é chamar um procedimento armazenado que tem parâmetros de saída. Em muitos provedores (por exemplo, o provedor OLE DB para SQL Server) os valores de parâmetro de saída não estará acessíveis quando você fechar o acessador de conjunto de resultados. Chamar `Close` para fechar o conjunto de linhas retornado e o acessador de conjunto de resultados, mas não o acessador de parâmetro, permitindo que você recupere os valores de parâmetro de saída.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir mostra como você pode chamar `Close` e `ReleaseCommand` quando você executa o mesmo comando repetidamente.  
  
 [!code-cpp[NVC_OLEDB_Consumer#2](../../data/oledb/codesnippet/cpp/ccommand-close_1.cpp)]  
  
## <a name="getnextresult"></a> Ccommand:: Getnextresult
Busca o próximo resultado definido, se houver uma disponível.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT GetNextResult(DBROWCOUNT* pulRowsAffected, 
   bool bBind = true) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *pulRowsAffected*  
 [entrada/saída] Um ponteiro de memória em que a contagem de linhas afetadas por um comando é retornada.  
  
 *bBind*  
 [in] Especifica se deve associar o comando automaticamente depois que está sendo executado. O padrão é **verdadeira**, que faz com que o comando a ser associado automaticamente. Definindo *bBind* à **falso** impede que a associação automática do comando para que você pode vincular manualmente. (A vinculação manual é de interesse específico para os usuários OLAP.)  
  
### <a name="return-value"></a>Valor de retorno  
 Um HRESULT padrão.  
  
### <a name="remarks"></a>Comentários  
 Se um conjunto de resultados foi buscado anteriormente, essa função libera o conjunto de resultados anterior e desvincula as colunas. Se *bBind* é **verdadeiro**, ele associa as novas colunas.  
  
 Você deve chamar essa função somente se você tiver especificado vários resultados, definindo a `CCommand` parâmetro de modelo *TMultiple*=`CMultipleResults`. 

## <a name="open"></a> Ccommand:: Open
Executa e opcionalmente associa o comando.  
  
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
 *Sessão*  
 [in] A sessão na qual executar o comando.  
  
 *wszCommand*  
 [in] O comando a ser executado, é passada como uma cadeia de caracteres Unicode. Pode ser nulo ao usar `CAccessor`, caso em que o comando será recuperado do valor passado para o [DEFINE_COMMAND](../../data/oledb/define-command.md) macro. Ver [ICommand:: execute](https://msdn.microsoft.com/library/ms718095.aspx) na *referência do programador DB OLE* para obter detalhes.  
  
 *szCommand*  
 [in] Mesmo que *wszCommand* , exceto que esse parâmetro usa uma cadeia de caracteres de comando de ANSI. O quarto formulário desse método pode levar um valor NULL. Consulte "Comentários" posteriormente neste tópico para obter detalhes.  
  
 *pPropSet*  
 [in] Um ponteiro para uma matriz de [DBPROPSET](https://msdn.microsoft.com/library/ms714367.aspx) estruturas que contém as propriedades e valores a serem definidos. Ver [conjuntos de propriedades e grupos de propriedades](https://msdn.microsoft.com/library/ms713696.aspx) na *referência do programador do OLE DB* no Windows SDK.  
  
 *pRowsAffected*  
 [entrada/saída] Um ponteiro de memória em que a contagem de linhas afetadas por um comando é retornada. Se  *\*pRowsAffected* for NULL, nenhuma contagem de linhas será retornada. Caso contrário, `Open` define  *\*pRowsAffected* acordo com as seguintes condições:  
  
|If|Then|  
|--------|----------|  
|O `cParamSets` elemento de `pParams` é maior que 1|*\*pRowsAffected* representa o número total de linhas afetadas por todos os conjuntos de parâmetros especificados na execução.|  
|O número de linhas afetadas não está disponível|*\*pRowsAffected* é definido como -1.|  
|O comando não atualizar, excluir ou inserir linhas|*\*pRowsAffected* é indefinido.|  
  
 *guidCommand*  
 [in] Um GUID que especifica a sintaxe e regras gerais para o provedor a ser usado na análise do texto de comando. Ver [ICommandText::GetCommandText](https://msdn.microsoft.com/library/ms709825.aspx) e [ICommandText:: SetCommandText](https://msdn.microsoft.com/library/ms709757.aspx) no *referência do programador DB OLE* para obter detalhes.  
  
 *bBind*  
 [in] Especifica se deve associar o comando automaticamente depois que está sendo executado. O padrão é **verdadeira**, que faz com que o comando a ser associado automaticamente. Definindo *bBind* à **falso** impede que a associação automática do comando para que você pode vincular manualmente. (A vinculação manual é de interesse específico para os usuários OLAP.)  
  
 *ulPropSets*  
 [in] O número de [DBPROPSET](https://msdn.microsoft.com/library/ms714367.aspx) estruturas passada a *pPropSet* argumento.  
  
### <a name="return-value"></a>Valor de retorno  
 Um HRESULT padrão.  
  
### <a name="remarks"></a>Comentários  
 As primeiras três formas de `Open` levar a uma sessão, criar um comando e execute o comando, todos os parâmetros de associação conforme necessário.  
  
 A primeira forma de `Open` usa uma cadeia de caracteres de comando do Unicode e não tem valor padrão.  
  
 A segunda forma de `Open` usa uma cadeia de caracteres de comando ANSI e nenhum valor padrão (fornecido para compatibilidade com aplicativos existentes do ANSI).  
  
 O terceiro formulário da `Open` permite que a cadeia de caracteres de comando como NULL, devido ao tipo **int** com um valor padrão de NULL. Ele é fornecido para chamar `Open(session, NULL);` ou `Open(session);` como NULL é do tipo **int**. Esta versão requer e declara que o **int** parâmetro ser NULL.  
  
 Use a forma de quarta da `Open` quando você já tiver criado um comando e desejar executar uma única [preparar](../../data/oledb/ccommand-prepare.md) e várias execuções.  
  
> [!NOTE]
>  `Open` chamadas `Execute`, que por sua vez chama `GetNextResult`. 

## <a name="create"></a> Ccommand:: Create
Chamadas [ccommand:: CreateCommand](../../data/oledb/ccommand-createcommand.md) para criar um comando para a sessão especificada, em seguida, chama [ICommandText:: SetCommandText](https://msdn.microsoft.com/library/ms709825.aspx) para especificar o texto do comando.  
  
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
 *Sessão*  
 [in] Uma sessão na qual criar o comando.  
  
 *wszCommand*  
 [in] Um ponteiro para o texto Unicode da cadeia de caracteres de comando.  
  
 *szCommand*  
 [in] Um ponteiro para o texto ANSI da cadeia de caracteres de comando.  
  
 *guidCommand*  
 [in] Um GUID que especifica a sintaxe e regras gerais para o provedor a ser usado na análise do texto de comando. Para obter uma descrição de dialetos, consulte [ICommandText::GetCommandText](https://msdn.microsoft.com/library/ms709825.aspx) na *referência do programador DB OLE*.  
  
### <a name="return-value"></a>Valor de retorno  
 Um HRESULT padrão.  
  
### <a name="remarks"></a>Comentários  
 A primeira forma de `Create` usa uma cadeia de caracteres de comando do Unicode. A segunda forma de `Create` usa uma cadeia de caracteres de comando ANSI (fornecida para compatibilidade com aplicativos existentes do ANSI).

## <a name="createcommand"></a> Ccommand:: CreateCommand
Cria um novo comando.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT CCommandBase::CreateCommand(const CSession& session) throw ();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *Sessão*  
 [in] Um `CSession` objeto a ser associado com o novo comando.  
  
### <a name="return-value"></a>Valor de retorno  
 Um HRESULT padrão.  
  
### <a name="remarks"></a>Comentários  
 Esse método cria um comando usando o objeto de sessão especificada.  

## <a name="getparameterinfo"></a> Ccommand:: Getparameterinfo
Obtém uma lista de parâmetros do comando, seus nomes e seus tipos.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT CCommandBase::GetParameterInfo(DB_UPARAMS* pParams,  
   DBPARAMINFO** ppParamInfo,  
   OLECHAR** ppNamesBuffer) throw ();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Ver [ICommandWithParameters:: Getparameterinfo](https://msdn.microsoft.com/library/ms714917.aspx) na *referência do programador do OLE DB*.  
  
### <a name="return-value"></a>Valor de retorno  
 Um HRESULT padrão.   

## <a name="prepare"></a> Ccommand:: Prepare
Valida e otimiza o comando atual.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT CCommandBase::Prepare(ULONG cExpectedRuns = 0) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *cExpectedRuns*  
 [in] O número de vezes que você pretende executar o comando.  
  
### <a name="return-value"></a>Valor de retorno  
 Um HRESULT padrão.  
  
### <a name="remarks"></a>Comentários  
 Esse método encapsula o método OLE DB [icommandprepare:: Prepare](https://msdn.microsoft.com/library/ms718370.aspx).  

## <a name="releasecommand"></a> Ccommand:: Releasecommand
Libera o acessador de parâmetro e, em seguida, libera o próprio comando.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
void CCommandBase::ReleaseCommand() throw();  
```  
  
### <a name="remarks"></a>Comentários  
 `ReleaseCommand` é usado em conjunto com `Close`. Ver [fechar](../../data/oledb/ccommand-close.md) detalhes de uso. 

## <a name="setparameterinfo"></a> Ccommand:: SetParameterInfo
Especifica o tipo nativo de cada parâmetro de comando.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT CCommandBase::SetParameterInfo(DB_UPARAMS ulParams,  
   const DBORDINAL* pOrdinals,  
   const DBPARAMBINDINFO* pParamInfo) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Ver [ICommandWithParameters:: SetParameterInfo](https://msdn.microsoft.com/library/ms725393.aspx) na *referência do programador do OLE DB*.  
  
### <a name="return-value"></a>Valor de retorno  
 Um HRESULT padrão.  

## <a name="unprepare"></a> Ccommand:: Unprepare
Descarta o plano de execução do comando atual.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT CCommandBase::Unprepare() throw();  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um HRESULT padrão.  
  
### <a name="remarks"></a>Comentários  
 Esse método encapsula o método OLE DB [icommandprepare:: Unprepare](https://msdn.microsoft.com/library/ms719635.aspx). 
  
## <a name="see-also"></a>Consulte também  
 [Modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)