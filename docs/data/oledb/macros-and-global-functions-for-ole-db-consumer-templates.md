---
title: Macros e funções globais para modelos de consumidor do OLE DB | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- vc.templates.ole
- ATL.AtlTraceErrorRecords
- ATL::AtlTraceErrorRecords
- AtlTraceErrorRecords
- BEGIN_ACCESSOR
- BEGIN_ACCESSOR_MAP
- END_ACCESSOR
- END_ACCESSOR_MAP
- BEGIN_COLUMN_MAP
- BLOB_ENTRY
- BLOB_ENTRY_LENGTH
- BLOB_ENTRY_LENGTH_STATUS
- BLOB_ENTRY_STATUS
- BLOB_NAME
- BLOB_NAME_LENGTH
- BLOB_NAME_LENGTH_STATUS
- BLOB_NAME_STATUS
- BOOKMARK_ENTRY
- COLUMN_ENTRY
- COLUMN_ENTRY_EX
- COLUMN_ENTRY_LENGTH
- COLUMN_ENTRY_LENGTH_STATUS
- COLUMN_ENTRY_PS
- COLUMN_ENTRY_PS_LENGTH
- COLUMN_ENTRY_PS_LENGTH_STATUS
- COLUMN_ENTRY_PS_STATUS
- COLUMN_ENTRY_STATUS
- COLUMN_ENTRY_TYPE
- COLUMN_ENTRY_TYPE_SIZE
- COLUMN_NAME
- COLUMN_NAME_EX
- COLUMN_NAME_LENGTH
- COLUMN_NAME_LENGTH_STATUS
- COLUMN_NAME_PS
- COLUMN_NAME_PS_LENGTH
- COLUMN_NAME_PS_LENGTH_STATUS
- COLUMN_NAME_PS_STATUS
- COLUMN_NAME_STATUS
- COLUMN_NAME_TYPE
- COLUMN_NAME_TYPE_PS
- COLUMN_NAME_TYPE_SIZE
- COLUMN_NAME_TYPE_STATUS
- END_COLUMN_MAP
- DEFINE_COMMAND
- DEFINE_COMMAND_EX
- BEGIN_PARAM_MAP
- END_PARAM_MAP
- SET_PARAM_TYPE
dev_langs:
- C++
helpviewer_keywords:
- OLE DB consumer templates, macros
- macros, OLE DB consumer template
- AtlTraceErrorRecords function
- BEGIN_ACCESSOR macro, syntax
- BEGIN_ACCESSOR macro
- BEGIN_ACCESSOR_MAP macro
- END_ACCESSOR macro
- END_ACCESSOR_MAP macro
- BEGIN_COLUMN_MAP macro
- BLOB_ENTRY macro
- BLOB_ENTRY_LENGTH macro
- BLOB_ENTRY_LENGTH_STATUS macro
- BLOB_ENTRY_STATUS macro
- BLOB_NAME macro
- BLOB_NAME_LENGTH macro
- BLOB_NAME_LENGTH_STATUS macro
- BLOB_NAME_STATUS macro
- BOOKMARK_ENTRY macro
- COLUMN_ENTRY macro
- COLUMN_ENTRY_EX macro
- COLUMN_ENTRY_LENGTH macro
- COLUMN_ENTRY_LENGTH_STATUS macro
- COLUMN_ENTRY_PS macro
- COLUMN_ENTRY_PS_LENGTH macro
- COLUMN_ENTRY_PS_LENGTH_STATUS macro
- COLUMN_ENTRY_PS_STATUS macro
- COLUMN_ENTRY_STATUS macro
- COLUMN_ENTRY_TYPE macro
- COLUMN_ENTRY_TYPE_SIZE macro
- COLUMN_NAME macro
- COLUMN_NAME_EX macro
- COLUMN_NAME_LENGTH macro
- COLUMN_NAME_LENGTH_STATUS macro
- COLUMN_NAME_PS macro
- COLUMN_NAME_PS_LENGTH macro
- COLUMN_NAME_PS_LENGTH_STATUS macro
- COLUMN_NAME_PS_STATUS macro
- COLUMN_NAME_STATUS macro
- COLUMN_NAME_TYPE macro
- COLUMN_NAME_TYPE_PS macro
- COLUMN_NAME_TYPE_SIZE macro
- COLUMN_NAME_TYPE_STATUS macro
- END_COLUMN_MAP macro
- DEFINE_COMMAND macro
- DEFINE_COMMAND_EX macro
- BEGIN_PARAM_MAP macro
- END_PARAM_MAP macro
- SET_PARAM_TYPE macro
ms.assetid: 8765eb7b-32dd-407c-bacf-8890ef959837
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: a915a581a574193918f86f80083d3202c9949674
ms.sourcegitcommit: 889a75be1232817150be1e0e8d4d7f48f5993af2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/30/2018
ms.locfileid: "39338142"
---
# <a name="macros-and-global-functions-for-ole-db-consumer-templates"></a>Macros e funções globais para modelos de consumidor de banco de dados OLE
O OLE DB modelos de consumidor incluem as funções globais e macros a seguir:  
  
## <a name="global-functions"></a>Funções globais  
  
|||  
|-|-|  
|[AtlTraceErrorRecords](#atltraceerrorrecords)|Despeja informações de OLE DB registro de erro para o dispositivo de despejo de memória se um erro será retornado.|  
  
## <a name="accessor-map-macros"></a>Macros de mapa de acessador  
  
|||  
|-|-|  
|[BEGIN_ACCESSOR](#begin_accessor)|Marca o início de uma entrada de acessador.|  
|[BEGIN_ACCESSOR_MAP](#begin_accessor_map)|Marca o início das entradas de mapa de acessador.|  
|[END_ACCESSOR](#end_accessor)|Marca o final de uma entrada de acessador.|  
|[END_ACCESSOR_MAP](#end_accessor_map)|Marca o fim das entradas de mapa de acessador.|  
  
## <a name="column-map-macros"></a>Macros de mapa de coluna  
  
|||  
|-|-|  
|[BEGIN_COLUMN_MAP](#begin_column_map)|Marca o início das entradas de mapa de coluna na classe de registro de usuário.|  
|[BLOB_ENTRY](#blob_entry)|Usado para associar um objeto binário grande (BLOB).|  
|[BLOB_ENTRY_LENGTH](#blob_entry_length)|Informa o comprimento da coluna de dados BLOB.|  
|[BLOB_ENTRY_LENGTH_STATUS](#blob_entry_length_status)|Relata o comprimento e o status da coluna de dados BLOB.|  
|[BLOB_ENTRY_STATUS](#blob_entry_status)|Relata o status da coluna de dados BLOB.|  
|[BLOB_NAME](#blob_name)|Usado para associar um objeto binário grande pelo nome da coluna.|  
|[BLOB_NAME_LENGTH](#blob_name_length)|Informa o comprimento da coluna de dados BLOB.|  
|[BLOB_NAME_LENGTH_STATUS](#blob_name_length_status)|Relata o comprimento e o status da coluna de dados BLOB.|  
|[BLOB_NAME_STATUS](#blob_name_status)|Relata o status da coluna de dados BLOB.|  
|[BOOKMARK_ENTRY](#bookmark_entry)|Representa uma entrada de indicador no conjunto de linhas. Uma entrada de indicador é um tipo especial de entrada de coluna.|  
|[COLUMN_ENTRY](#column_entry)|Representa uma associação a uma coluna específica no banco de dados.|  
|[COLUMN_ENTRY_EX](#column_entry_ex)|Representa uma associação para a coluna específica no banco de dados. Dá suporte à *tipo*, *comprimento*, *precisão*, *escala*, e *status* parâmetros.|  
|[COLUMN_ENTRY_LENGTH](#column_entry_length)|Representa uma associação para a coluna específica no banco de dados. Dá suporte a *comprimento* variável.|  
|[COLUMN_ENTRY_LENGTH_STATUS](#column_entry_length_status)|Representa uma associação para a coluna específica no banco de dados. Dá suporte à *status* e *comprimento* parâmetros.|  
|[COLUMN_ENTRY_PS](#column_entry_ps)|Representa uma associação para a coluna específica no banco de dados. Dá suporte à *precisão* e *escala* parâmetros.|  
|[COLUMN_ENTRY_PS_LENGTH](#column_entry_ps_length)|Representa uma associação para a coluna específica no banco de dados. Dá suporte a *comprimento* variável, *precision* e *escala* parâmetros.|  
|[COLUMN_ENTRY_PS_LENGTH_STATUS](#column_entry_ps_length_status)|Representa uma associação para a coluna específica no banco de dados. Dá suporte à *status* e *comprimento* variáveis *precisão* e *escala* parâmetros.|  
|[COLUMN_ENTRY_PS_STATUS](#column_entry_ps_status)|Representa uma associação para a coluna específica no banco de dados. Dá suporte a *status* variável, *precision* e *escala* parâmetros.|  
|[COLUMN_ENTRY_STATUS](#column_entry_status)|Representa uma associação para a coluna específica no banco de dados. Dá suporte a *status* variável.|  
|[COLUMN_ENTRY_TYPE](#column_entry_type)|Representa uma associação a uma coluna específica no banco de dados. Dá suporte à *tipo* parâmetro.|  
|[COLUMN_ENTRY_TYPE_SIZE](#column_entry_type_size)|Representa uma associação para a coluna específica no banco de dados. Dá suporte à *tipo* e *tamanho* parâmetros.|  
|[COLUMN_NAME](#column_name)|Representa uma associação a uma coluna específica no banco de dados por nome.|  
|[COLUMN_NAME_EX](#column_name_ex)|Representa uma associação a uma coluna específica no banco de dados por nome. Oferece suporte à especificação de tipo de dados, tamanho, precisão, escala, comprimento da coluna e status da coluna.|  
|[COLUMN_NAME_LENGTH](#column_name_length)|Representa uma associação a uma coluna específica no banco de dados por nome. Oferece suporte à especificação de comprimento de coluna.|  
|[COLUMN_NAME_LENGTH_STATUS](#column_name_length_status)|Representa uma associação a uma coluna específica no banco de dados por nome. Oferece suporte à especificação de comprimento de coluna e status.|  
|[COLUMN_NAME_PS](#column_name_ps)|Representa uma associação a uma coluna específica no banco de dados por nome. Oferece suporte à especificação de precisão e escala.|  
|[COLUMN_NAME_PS_LENGTH](#column_name_ps_length)|Representa uma associação a uma coluna específica no banco de dados por nome. Oferece suporte à especificação de precisão, escala e coluna de comprimento.|  
|[COLUMN_NAME_PS_LENGTH_STATUS](#column_name_ps_length_status)|Representa uma associação a uma coluna específica no banco de dados por nome. Oferece suporte à especificação de precisão, escala, comprimento da coluna e status da coluna.|  
|[COLUMN_NAME_PS_STATUS](#column_name_ps_status)|Representa uma associação a uma coluna específica no banco de dados por nome. Oferece suporte à especificação de precisão, escala e coluna status.|  
|[COLUMN_NAME_STATUS](#column_name_status)|Representa uma associação a uma coluna específica no banco de dados por nome. Oferece suporte à especificação de status da coluna.|  
|[COLUMN_NAME_TYPE](#column_name_type)|Representa uma associação a uma coluna específica no banco de dados por nome. Oferece suporte à especificação de tipo de dados.|  
|[COLUMN_NAME_TYPE_PS](#column_name_type_ps)|Representa uma associação a uma coluna específica no banco de dados por nome. Oferece suporte à especificação de tipo de dados, precisão e escala.|  
|[COLUMN_NAME_TYPE_SIZE](#column_name_type_size)|Representa uma associação a uma coluna específica no banco de dados por nome. Oferece suporte à especificação de tipo de dados e tamanho.|  
|[COLUMN_NAME_TYPE_STATUS](#column_name_type_status)|Representa uma associação a uma coluna específica no banco de dados por nome. Oferece suporte à especificação do status de coluna e de tipo de dados.|  
|[END_COLUMN_MAP](#end_column_map)|Marca o fim das entradas de mapa de coluna.|  
  
## <a name="command-macros"></a>Macros de comando  
  
|||  
|-|-|  
|[DEFINE_COMMAND](#define_command)|Especifica o comando que será usado para criar o conjunto de linhas ao usar o [CCommand](../../data/oledb/ccommand-class.md) classe. Aceita apenas os tipos de cadeia de caracteres correspondente ao tipo de aplicativo especificado (ANSI ou Unicode). É recomendável que você use [DEFINE_COMMAND_EX](../../data/oledb/define-command-ex.md) em vez de DEFINE_COMMAND.|  
|[DEFINE_COMMAND_EX](#define_command_ex)|Especifica o comando que será usado para criar o conjunto de linhas ao usar o [CCommand](../../data/oledb/ccommand-class.md) classe. Dá suporte a aplicativos ANSI e Unicode.|  
  
## <a name="parameter-map-macros"></a>Macros de mapa de parâmetro  
  
|||  
|-|-|  
|[BEGIN_PARAM_MAP](#begin_param_map)|Marca o início das entradas de mapa de parâmetro na classe de registro de usuário.|  
|[END_PARAM_MAP](#end_param_map)|Marca o fim das entradas de mapa de parâmetro.|  
|[SET_PARAM_TYPE](#set_param_type)|Especifica as macros COLUMN_ENTRY que seguem a macro SET_PARAM_TYPE como entrada, saída ou entrada/saída.|  

### <a name="atltraceerrorrecords"></a> AtlTraceErrorRecords
Despeja informações de OLE DB registro de erro para o dispositivo de despejo de memória se um erro será retornado.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
inline void AtlTraceErrorRecords(HRESULT hrErr = S_OK);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *hErr*  
 [in] Um HRESULT retornado por uma função de membro de OLE DB modelo de consumidor.  
  
#### <a name="remarks"></a>Comentários  
 Se *hErr* não for S_OK, `AtlTraceErrorRecords` Despeja as informações de OLE DB registro de erro para o dispositivo de despejo (o **depurar** guia da janela de saída ou um arquivo). As informações de registro de erro, que são obtidas do provedor, incluem o número de linhas, fonte, descrição, arquivo de Ajuda, contexto e GUID para cada entrada de registro de erro. `AtlTraceErrorRecords` Essas informações apenas em compilações de depuração de despejos de memória. Em compilações de versão, é um stub vazio que é otimizado out.  
  
#### <a name="see-also"></a>Consulte também    
 [Classe CDBErrorInfo](../../data/oledb/cdberrorinfo-class.md)

### <a name="begin_accessor"></a> BEGIN_ACCESSOR
Marca o início de uma entrada de acessador.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp  
BEGIN_ACCESSOR(num, bAuto)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *num*  
 [in] O número de deslocamento de zero para o acessador neste mapa de acessador.  
  
 *bAuto*  
 [in] Especifica se esse acessador é um acessador de automático ou um acessador manual. Se **verdadeira**, o acessador é automática; se **falso**, o acessador é manual. Um acessador automático significa para você os dados são buscados em operações de movimentação.  
  
#### <a name="remarks"></a>Comentários  
 No caso de vários acessadores em um conjunto de linhas, você precisa especificar BEGIN_ACCESSOR_MAP e usar a macro BEGIN_ACCESSOR cada acessador individual. A macro BEGIN_ACCESSOR é concluída com a macro END_ACCESSOR. A macro BEGIN_ACCESSOR_MAP é concluída com a macro END_ACCESSOR_MAP.  
  
#### <a name="example"></a>Exemplo  
 Ver [BEGIN_ACCESSOR_MAP](../../data/oledb/begin-accessor-map.md).  

### <a name="begin_accessor_map"></a> BEGIN_ACCESSOR_MAP
Marca o início das entradas de mapa de acessador.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp  
BEGIN_ACCESSOR_MAP(x, num)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *x*  
 [in] O nome da classe de registro de usuário.  
  
 *num*  
 [in] O número de acessadores neste mapa de acessador.  
  
#### <a name="remarks"></a>Comentários  
 No caso de vários acessadores em um conjunto de linhas, você precisa especificar BEGIN_ACCESSOR_MAP no início e usar a macro BEGIN_ACCESSOR cada acessador individual. A macro BEGIN_ACCESSOR é concluída com a macro END_ACCESSOR. O mapa de acessador for concluído com a macro END_ACCESSOR_MAP.  
  
 Se você tiver apenas um acessador no registro do usuário, use a macro [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md).  
  
#### <a name="example"></a>Exemplo  

 ```cpp  
class CArtistsAccessor
{
public:
// Data Elements
   TCHAR m_szFirstName[21];
   TCHAR m_szLastName[31];
   short m_nAge;

// Output binding map
BEGIN_ACCESSOR_MAP(CArtistsAccessor, 2)
   BEGIN_ACCESSOR(0, true)
      COLUMN_ENTRY(1, m_szFirstName)
      COLUMN_ENTRY(2, m_szLastName)
   END_ACCESSOR()
   BEGIN_ACCESSOR(1, false) // Not an auto accessor
      COLUMN_ENTRY(3, m_nAge)
   END_ACCESSOR()
END_ACCESSOR_MAP()

   HRESULT OpenDataSource()
   {
      CDataSource _db;
      _db.Open();
      return m_session.Open(_db);
   }

   void CloseDataSource()
   {
      m_session.Close();
   }

   CSession m_session;

   DEFINE_COMMAND_EX(CArtistsAccessor, L" \
   SELECT \
      FirstName, \
      LastName, \
      Age \
      FROM Artists")
};
 ```

### <a name="end_accessor"></a> END_ACCESSOR
Marca o final de uma entrada de acessador.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
END_ACCESSOR()  
```  
  
#### <a name="remarks"></a>Comentários  
 Para vários acessadores em um conjunto de linhas, você precisa especificar BEGIN_ACCESSOR_MAP e usar a macro BEGIN_ACCESSOR cada acessador individual. A macro BEGIN_ACCESSOR é concluída com a macro END_ACCESSOR. A macro BEGIN_ACCESSOR_MAP é concluída com a macro END_ACCESSOR_MAP.  
  
#### <a name="example"></a>Exemplo  
 Ver [BEGIN_ACCESSOR_MAP](../../data/oledb/begin-accessor-map.md).  

### <a name="end_accessor_map"></a> END_ACCESSOR_MAP
Marca o fim das entradas de mapa de acessador.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
END_ACCESSOR_MAP()  
```  
  
#### <a name="remarks"></a>Comentários  
 Para vários acessadores em um conjunto de linhas, você precisa especificar BEGIN_ACCESSOR_MAP e usar a macro BEGIN_ACCESSOR cada acessador individual. A macro BEGIN_ACCESSOR é concluída com a macro END_ACCESSOR. A macro BEGIN_ACCESSOR_MAP é concluída com a macro END_ACCESSOR_MAP.  
  
#### <a name="example"></a>Exemplo  
 Ver [BEGIN_ACCESSOR_MAP](../../data/oledb/begin-accessor-map.md).  

### <a name="begin_column_map"></a> BEGIN_COLUMN_MAP
Marca o início de uma entrada de mapa de coluna.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp  
BEGIN_COLUMN_MAP(x)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *x*  
 [in] O nome da classe de registro de usuário derivado do `CAccessor`.  
  
#### <a name="remarks"></a>Comentários  
 Essa macro é usada no caso de um único acessador em um conjunto de linhas. Se você tiver vários acessadores em um conjunto de linhas, use [BEGIN_ACCESSOR_MAP](../../data/oledb/begin-accessor-map.md).  
  
 A macro BEGIN_COLUMN_MAP é concluída com a macro END_COLUMN_MAP. Essa macro é usada quando há apenas um acessador necessário no registro do usuário.  
  
 Colunas correspondem aos campos no conjunto de linhas que você deseja associar.  
  
#### <a name="example"></a>Exemplo  
 Aqui está um exemplo de mapa de parâmetro e coluna:  
  
 <!--[!CODE [NVC_OLEDB_Consumer#16](../codesnippet/vs_snippets_cpp/nvc_oledb_consumer#16)]  -->

### <a name="blob_entry"></a> BLOB_ENTRY
Usado com BEGIN_COLUMN_MAP e END_COLUMN_MAP para associar um objeto binário grande ([BLOB](https://msdn.microsoft.com/library/ms711511.aspx)).  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
BLOB_ENTRY(nOrdinal, IID, flags, data)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *nOrdinal*  
 [in] O número da coluna.  
  
 *IID*  
 [in] Interface GUID, tais como `IDD_ISequentialStream`, usado para recuperar o BLOB.  
  
 *flags*  
 [in] Sinalizadores de modo de armazenamento, conforme definido pelo modelo de armazenamento estruturado OLE (por exemplo, `STGM_READ`).  
  
 *data*  
 [in] O membro de dados correspondente no registro do usuário.  
  
#### <a name="example"></a>Exemplo  
 Ver [como recuperar um BLOB?](../../data/oledb/retrieving-a-blob.md).  

### <a name="blob_entry_length"></a> BLOB_ENTRY_LENGTH
Usado com BEGIN_COLUMN_MAP e END_COLUMN_MAP para associar um objeto binário grande ([BLOB](https://msdn.microsoft.com/library/ms711511.aspx)). Semelhante ao [BLOB_ENTRY](../../data/oledb/blob-entry.md), a menos que essa macro também obtém o comprimento em bytes da coluna BLOB.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
BLOB_ENTRY_LENGTH(nOrdinal, IID, flags, data, length)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *nOrdinal*  
 [in] O número da coluna.  
  
 *IID*  
 [in] Interface GUID, tais como `IDD_ISequentialStream`, usado para recuperar o BLOB.  
  
 *flags*  
 [in] Sinalizadores de modo de armazenamento, conforme definido pelo modelo de armazenamento estruturado OLE (por exemplo, `STGM_READ`).  
  
 *data*  
 [in] O membro de dados correspondente no registro do usuário.  
  
 *length*  
 [out] O comprimento (real) em bytes da coluna BLOB.  
  
#### <a name="example"></a>Exemplo  
 Ver [como recuperar um BLOB?](../../data/oledb/retrieving-a-blob.md).  

### <a name="blob_entry_length_status"></a> BLOB_ENTRY_LENGTH_STATUS
Usado com BEGIN_COLUMN_MAP e END_COLUMN_MAP para associar um objeto binário grande ([BLOB](https://msdn.microsoft.com/library/ms711511.aspx)). Semelhante ao [BLOB_ENTRY](../../data/oledb/blob-entry.md), a menos que essa macro também obtém o tamanho e o status da coluna BLOB.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
BLOB_ENTRY_LENGTH_STATUS(  
    nOrdinal,  
    IID,  
    flags,  
    data,
    length,
    status )  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *nOrdinal*  
 [in] O número da coluna.  
  
 *IID*  
 [in] Interface GUID, tais como `IDD_ISequentialStream`, usado para recuperar o BLOB.  
  
 *flags*  
 [in] Sinalizadores de modo de armazenamento, conforme definido pelo modelo de armazenamento estruturado OLE (por exemplo, `STGM_READ`).  
  
 *data*  
 [in] O membro de dados correspondente no registro do usuário.  
  
 *length*  
 [out] O comprimento (real) em bytes da coluna BLOB.  
  
 *status*  
 [out] O status da coluna de dados BLOB.  
  
#### <a name="example"></a>Exemplo  
 Ver [como recuperar um BLOB?](../../data/oledb/retrieving-a-blob.md).  

### <a name="blob_entry_status"></a> BLOB_ENTRY_STATUS
Usado com BEGIN_COLUMN_MAP ou BEGIN_ACCESSOR_MAP para associar um objeto binário grande ([BLOB](https://msdn.microsoft.com/library/ms711511.aspx)). Semelhante ao [BLOB_ENTRY](../../data/oledb/blob-entry.md), a menos que essa macro também obtém o status da coluna BLOB.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
BLOB_ENTRY_STATUS(nOrdinal, IID, flags, data, status)   
```  
  
#### <a name="parameters"></a>Parâmetros  
 *nOrdinal*  
 [in] O número da coluna.  
  
 *IID*  
 [in] Interface GUID, tais como `IDD_ISequentialStream`, usado para recuperar o BLOB.  
  
 *flags*  
 [in] Sinalizadores de modo de armazenamento, conforme definido pelo modelo de armazenamento estruturado OLE (por exemplo, `STGM_READ`).  
  
 *data*  
 [in] O membro de dados correspondente no registro do usuário.  
  
 *status*  
 [out] O status do campo BLOB.  
  
#### <a name="example"></a>Exemplo  
 Ver [como recuperar um BLOB?](../../data/oledb/retrieving-a-blob.md).  

### <a name="blob_name"></a> BLOB_NAME
Usado com BEGIN_COLUMN_MAP e END_COLUMN_MAP para associar um objeto binário grande ([BLOB](https://msdn.microsoft.com/library/ms711511.aspx)). Semelhante ao [BLOB_ENTRY](../../data/oledb/blob-entry.md), a menos que essa macro usa um nome de coluna em vez de um número de coluna.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
BLOB_NAME(pszName, IID, flags, data )  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *pszName*  
 [in] Um ponteiro para o nome da coluna. O nome deve ser uma cadeia de caracteres Unicode. Você pode fazer isso colocando um "L" na frente do nome, por exemplo: `L"MyColumn"`.  
  
 *IID*  
 [in] Interface GUID, tais como `IDD_ISequentialStream`, usado para recuperar o BLOB.  
  
 *flags*  
 [in] Sinalizadores de modo de armazenamento, conforme definido pelo modelo de armazenamento estruturado OLE (por exemplo, `STGM_READ`).  
  
 *data*  
 [in] O membro de dados correspondente no registro do usuário.  
  
#### <a name="example"></a>Exemplo  
 Ver [como recuperar um BLOB?](../../data/oledb/retrieving-a-blob.md).  

### <a name="blob_name_length"></a> BLOB_NAME_LENGTH
Usado com BEGIN_COLUMN_MAP e END_COLUMN_MAP para associar um objeto binário grande ([BLOB](https://msdn.microsoft.com/library/ms711511.aspx)). Semelhante ao [BLOB_NAME](../../data/oledb/blob-name.md), a menos que essa macro também obtém o comprimento em bytes da coluna de dados BLOB.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
BLOB_NAME_LENGTH(pszName, IID, flags, data, length )  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *pszName*  
 [in] Um ponteiro para o nome da coluna. O nome deve ser uma cadeia de caracteres Unicode. Você pode fazer isso colocando um "L" na frente do nome, por exemplo: `L"MyColumn"`.  
  
 *IID*  
 [in] Interface GUID, tais como `IDD_ISequentialStream`, usado para recuperar o BLOB.  
  
 *flags*  
 [in] Sinalizadores de modo de armazenamento, conforme definido pelo modelo de armazenamento estruturado OLE (por exemplo, `STGM_READ`).  
  
 *data*  
 [in] O membro de dados correspondente no registro do usuário.  
  
 *length*  
 [out] O comprimento (real) em bytes da coluna BLOB.  

### <a name="blob_name_length_status"></a> BLOB_NAME_LENGTH_STATUS
Usado com BEGIN_COLUMN_MAP e END_COLUMN_MAP para associar um objeto binário grande ([BLOB](https://msdn.microsoft.com/library/ms711511.aspx)). Semelhante ao [BLOB_NAME](../../data/oledb/blob-name.md), a menos que essa macro também obtém o tamanho e o status da coluna de dados BLOB.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
BLOB_NAME_LENGTH_STATUS(pszName, IID, flags, data, length, status )  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *pszName*  
 [in] Um ponteiro para o nome da coluna. O nome deve ser uma cadeia de caracteres Unicode. Você pode fazer isso colocando um "L" na frente do nome, por exemplo: `L"MyColumn"`.  
  
 *IID*  
 [in] Interface GUID, tais como `IDD_ISequentialStream`, usado para recuperar o BLOB.  
  
 *flags*  
 [in] Sinalizadores de modo de armazenamento, conforme definido pelo modelo de armazenamento estruturado OLE (por exemplo, `STGM_READ`).  
  
 *data*  
 [in] O membro de dados correspondente no registro do usuário.  
  
 *length*  
 [out] O comprimento (real) em bytes da coluna BLOB.  
  
 *status*  
 [out] O status do campo BLOB.  

### <a name="blob_name_status"></a> BLOB_NAME_STATUS
Usado com BEGIN_COLUMN_MAP e END_COLUMN_MAP para associar um objeto binário grande ([BLOB](https://msdn.microsoft.com/library/ms711511.aspx)). Semelhante ao [BLOB_NAME](../../data/oledb/blob-name.md), a menos que essa macro também obtém o status da coluna de dados BLOB.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
BLOB_NAME_STATUS(pszName, IID, flags, data, status )  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *pszName*  
 [in] Um ponteiro para o nome da coluna. O nome deve ser uma cadeia de caracteres Unicode. Você pode fazer isso colocando um "L" na frente do nome, por exemplo: `L"MyColumn"`.  
  
 *IID*  
 [in] Interface GUID, tais como `IDD_ISequentialStream`, usado para recuperar o BLOB.  
  
 *flags*  
 [in] Sinalizadores de modo de armazenamento, conforme definido pelo modelo de armazenamento estruturado OLE (por exemplo, `STGM_READ`).  
  
 *data*  
 [in] O membro de dados correspondente no registro do usuário.  
  
 *status*  
 [out] O status do campo BLOB.  
  
### <a name="bookmark_entry"></a> BOOKMARK_ENTRY
Associa a coluna de indicador.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
BOOKMARK_ENTRY(variable)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *variable*  
 [in] A variável a ser associado à coluna de indicador.  
  
#### <a name="example"></a>Exemplo  

```cpp  
class CArtistsBookmark
{
public:
// Data Elements
   CBookmark<4> m_bookmark;
   short m_nAge;
   TCHAR m_szFirstName[21];
   TCHAR m_szLastName[31];

// Output binding map
BEGIN_COLUMN_MAP(CArtistsBookmark)
   BOOKMARK_ENTRY(m_bookmark)
   COLUMN_ENTRY(1, m_nAge)
   COLUMN_ENTRY(2, m_szFirstName)
   COLUMN_ENTRY(3, m_szLastName)
END_COLUMN_MAP()

   void GetRowsetProperties(CDBPropSet* pPropSet)
   {
      pPropSet->AddProperty(DBPROP_BOOKMARKS, true);
   }

   HRESULT OpenDataSource()
   {
      CDataSource _db;
      _db.Open();
      return m_session.Open(_db);
   }

   void CloseDataSource()
   {
      m_session.Close();
   }

   CSession m_session;

   DEFINE_COMMAND_EX(CArtistsBookmark, L" \
   SELECT \
      Age, \
      FirstName, \
      LastName \
      FROM Artists")
};
```
  
#### <a name="see-also"></a>Consulte também  
 [Classe CBookmark](../../data/oledb/cbookmark-class.md)   
 [DBPROP_BOOKMARKS](https://msdn.microsoft.com/library/ms709728.aspx)

### <a name="column_entry"></a> COLUMN_ENTRY
Representa uma associação no conjunto de linhas para a coluna específica no conjunto de linhas.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
COLUMN_ENTRY(nOrdinal, data)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Ver [DBBINDING](https://msdn.microsoft.com/library/ms716845.aspx) na *referência do programador do OLE DB*.  
  
 *nOrdinal*  
 [in] O número da coluna.  
  
 *data*  
 [in] O membro de dados correspondente no registro do usuário.  
  
#### <a name="remarks"></a>Comentários  
 A macro COLUMN_ENTRY é usada nos seguintes locais:  
  
-   Entre os [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md) e [END_COLUMN_MAP](../../data/oledb/end-column-map.md) macros.  
  
-   Entre os [BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md) e [END_ACCESSOR](../../data/oledb/end-accessor.md) macros.  
  
-   Entre os [BEGIN_PARAM_MAP](../../data/oledb/begin-param-map.md) e [END_PARAM_MAP](../../data/oledb/end-param-map.md) macros.  
  
#### <a name="example"></a>Exemplo  
 Consulte os exemplos nos tópicos da macro, [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md) e [BEGIN_ACCESSOR_MAP](../../data/oledb/begin-accessor-map.md).  

### <a name="column_entry_ex"></a> COLUMN_ENTRY_EX
Representa uma associação no conjunto de linhas para a coluna específica no banco de dados.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
COLUMN_ENTRY_EX(nOrdinal, wType, nLength, nPrecision, nScale, data, length, status)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Ver [DBBINDING](https://msdn.microsoft.com/library/ms716845.aspx) na *referência do programador do OLE DB*.  
  
 *nOrdinal*  
 [in] O número da coluna.  
  
 *wType*  
 [in] O tipo de dados.  
  
 *nLength*  
 [in] O tamanho dos dados em bytes.  
  
 *nPrecision*  
 [in] A precisão máxima a ser usado ao obter dados e *wType* é `DBTYPE_NUMERIC`. Caso contrário, esse parâmetro será ignorado.  
  
 *nScale*  
 [in] A escala a ser usado ao obter dados e *wType* é `DBTYPE_NUMERIC` ou `DBTYPE_DECIMAL`.  
  
 *data*  
 [in] O membro de dados correspondente no registro do usuário.  
  
 *length*  
 [in] A variável a ser associado para o comprimento da coluna.  
  
 *status*  
 [in] A variável a ser associado para o status da coluna.  
  
#### <a name="remarks"></a>Comentários  
 A macro COLUMN_ENTRY_EX é usada nos seguintes locais:  
  
-   Entre os [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md) e [END_COLUMN_MAP](../../data/oledb/end-column-map.md) macros.  
  
-   Entre os [BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md) e [END_ACCESSOR](../../data/oledb/end-accessor.md) macros.  
  
-   Entre os [BEGIN_PARAM_MAP](../../data/oledb/begin-param-map.md) e [END_PARAM_MAP](../../data/oledb/end-param-map.md) macros.  
  
#### <a name="example"></a>Exemplo  
 Ver [BOOKMARK_ENTRY](../../data/oledb/bookmark-entry.md).  

### <a name="column_entry_length"></a> COLUMN_ENTRY_LENGTH
Representa uma associação no conjunto de linhas para a coluna específica no banco de dados.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
COLUMN_ENTRY_LENGTH(nOrdinal, data, length)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Ver [DBBINDING](https://msdn.microsoft.com/library/ms716845.aspx) na *referência do programador do OLE DB*.  
  
 *nOrdinal*  
 [in] O número da coluna, começando com um. Indicador corresponde à coluna zero.  
  
 *data*  
 [in] O membro de dados correspondente no registro do usuário.  
  
 *length*  
 [in] A variável a ser associado para o comprimento da coluna.  
  
#### <a name="remarks"></a>Comentários  
 Essa macro dá suporte a *comprimento* variável. Ele é usado nos seguintes locais:  
  
-   Entre os [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md) e [END_COLUMN_MAP](../../data/oledb/end-column-map.md) macros.  
  
-   Entre os [BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md) e [END_ACCESSOR](../../data/oledb/end-accessor.md) macros.  
  
-   Entre os [BEGIN_PARAM_MAP](../../data/oledb/begin-param-map.md) e [END_PARAM_MAP](../../data/oledb/end-param-map.md) macros.  
  
### <a name="column_entry_length_status"></a> COLUMN_ENTRY_LENGTH_STATUS
Representa uma associação no conjunto de linhas para a coluna específica no banco de dados.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
COLUMN_ENTRY_LENGTH_STATUS(nOrdinal, data, length, status)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Ver [DBBINDING](https://msdn.microsoft.com/library/ms716845.aspx) na *referência do programador do OLE DB*.  
  
 *nOrdinal*  
 [in] O número da coluna.  
  
 *data*  
 [in] O membro de dados correspondente no registro do usuário.  
  
 *length*  
 [in] A variável a ser associado para o comprimento da coluna.  
  
 *status*  
 [in] A variável a ser associado para o status da coluna.  
  
#### <a name="remarks"></a>Comentários  
 Use essa macro, quando você deseja dar suporte a variáveis de comprimento e o status. Ele é usado nos seguintes locais:  
  
-   Entre os [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md) e [END_COLUMN_MAP](../../data/oledb/end-column-map.md) macros.  
  
-   Entre os [BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md) e [END_ACCESSOR](../../data/oledb/end-accessor.md) macros.  
  
-   Entre os [BEGIN_PARAM_MAP](../../data/oledb/begin-param-map.md) e [END_PARAM_MAP](../../data/oledb/end-param-map.md) macros.  

### <a name="column_entry_ps"></a> COLUMN_ENTRY_PS
Representa uma associação no conjunto de linhas para a coluna específica no conjunto de linhas.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
COLUMN_ENTRY_PS(nOrdinal, nPrecision, nScale, data)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Ver [DBBINDING](https://msdn.microsoft.com/library/ms716845.aspx) na *referência do programador do OLE DB*.  
  
 *nOrdinal*  
 [in] O número da coluna.  
  
 *nPrecision*  
 [in] A precisão máxima da coluna que você deseja associar.  
  
 *nScale*  
 [in] A escala da coluna que você deseja associar.  
  
 *data*  
 [in] O membro de dados correspondente no registro do usuário.  
  
#### <a name="remarks"></a>Comentários  
 Permite que você especifique a precisão e escala da coluna que você deseja associar. Ele é usado nos seguintes locais:  
  
-   Entre os [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md) e [END_COLUMN_MAP](../../data/oledb/end-column-map.md) macros.  
  
-   Entre os [BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md) e [END_ACCESSOR](../../data/oledb/end-accessor.md) macros.  
  
-   Entre os [BEGIN_PARAM_MAP](../../data/oledb/begin-param-map.md) e [END_PARAM_MAP](../../data/oledb/end-param-map.md) macros.  

### <a name="column_entry_ps_length"></a> COLUMN_ENTRY_PS_LENGTH
Representa uma associação no conjunto de linhas para a coluna específica no banco de dados.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
COLUMN_ENTRY_PS_LENGTH(nOrdinal, nPrecision, nScale, data, length)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Ver [DBBINDING](https://msdn.microsoft.com/library/ms716845.aspx) na *referência do programador do OLE DB*.  
  
 *nOrdinal*  
 [in] O número da coluna, começando com um. Indicador corresponde à coluna zero.  
  
 *nPrecision*  
 [in] A precisão máxima da coluna que você deseja associar.  
  
 *nScale*  
 [in] A escala da coluna que você deseja associar.  
  
 *data*  
 [in] O membro de dados correspondente no registro do usuário.  
  
 *length*  
 [in] A variável a ser associado para o comprimento da coluna.  
  
#### <a name="remarks"></a>Comentários  
 Permite que você especifique a precisão e escala da coluna que você deseja associar. Essa macro dá suporte a *comprimento* variável. Ele é usado nos seguintes locais:  
  
-   Entre os [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md) e [END_COLUMN_MAP](../../data/oledb/end-column-map.md) macros.  
  
-   Entre os [BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md) e [END_ACCESSOR](../../data/oledb/end-accessor.md) macros.  
  
-   Entre os [BEGIN_PARAM_MAP](../../data/oledb/begin-param-map.md) e [END_PARAM_MAP](../../data/oledb/end-param-map.md) macros.  

### <a name="column_entry_ps_length_status"></a> COLUMN_ENTRY_PS_LENGTH_STATUS
Representa uma associação no conjunto de linhas para a coluna específica no banco de dados.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
COLUMN_ENTRY_PS_LENGTH_STATUS(nOrdinal, nPrecision, nScale, data, length, status)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Ver [DBBINDING](https://msdn.microsoft.com/library/ms716845.aspx) na *referência do programador do OLE DB*.  
  
 *nOrdinal*  
 [in] O número da coluna.  
  
 *nPrecision*  
 [in] A precisão máxima da coluna que você deseja associar.  
  
 *nScale*  
 [in] A escala da coluna que você deseja associar.  
  
 *data*  
 [in] O membro de dados correspondente no registro do usuário.  
  
 *length*  
 [in] A variável a ser associado para o comprimento da coluna.  
  
 *status*  
 [in] A variável a ser associado para o status da coluna.  
  
#### <a name="remarks"></a>Comentários  
 Permite que você especifique a precisão e escala da coluna que você deseja associar. Use essa macro, quando você deseja dar suporte a variáveis de comprimento e o status. Ele é usado nos seguintes locais:  
  
-   Entre os [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md) e [END_COLUMN_MAP](../../data/oledb/end-column-map.md) macros.  
  
-   Entre os [BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md) e [END_ACCESSOR](../../data/oledb/end-accessor.md) macros.  
  
-   Entre os [BEGIN_PARAM_MAP](../../data/oledb/begin-param-map.md) e [END_PARAM_MAP](../../data/oledb/end-param-map.md) macros.  

### <a name="column_entry_ps_status"></a> COLUMN_ENTRY_PS_STATUS
Representa uma associação no conjunto de linhas para a coluna específica no banco de dados.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
COLUMN_ENTRY_PS_STATUS(nOrdinal, nPrecision, nScale, data, status)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Ver [DBBINDING](https://msdn.microsoft.com/library/ms716845.aspx) na *referência do programador do OLE DB*.  
  
 *nOrdinal*  
 [in] O número da coluna.  
  
 *nPrecision*  
 [in] A precisão máxima da coluna que você deseja associar.  
  
 *nScale*  
 [in] A escala da coluna que você deseja associar.  
  
 *data*  
 [in] O membro de dados correspondente no registro do usuário.  
  
 *status*  
 [in] A variável a ser associado para o status da coluna.  
  
#### <a name="remarks"></a>Comentários  
 Permite que você especifique a precisão e escala da coluna que você deseja associar. Essa macro dá suporte a *status* variável. Ele é usado nos seguintes locais:  
  
-   Entre os [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md) e [END_COLUMN_MAP](../../data/oledb/end-column-map.md) macros.  
  
-   Entre os [BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md) e [END_ACCESSOR](../../data/oledb/end-accessor.md) macros.  
  
-   Entre os [BEGIN_PARAM_MAP](../../data/oledb/begin-param-map.md) e [END_PARAM_MAP](../../data/oledb/end-param-map.md) macros.  
  
### <a name="column_entry_status"></a> COLUMN_ENTRY_STATUS
Representa uma associação no conjunto de linhas para a coluna específica no banco de dados.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
COLUMN_ENTRY_STATUS(nOrdinal, data, status)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Ver [DBBINDING](https://msdn.microsoft.com/library/ms716845.aspx) na *referência do programador do OLE DB*.  
  
 *nOrdinal*  
 [in] O número da coluna.  
  
 *data*  
 [in] O membro de dados correspondente no registro do usuário.  
  
 *status*  
 [in] A variável a ser associado para o status da coluna.  
  
#### <a name="remarks"></a>Comentários  
 Essa macro dá suporte a *status* variável. Ele é usado nos seguintes locais:  
  
-   Entre os [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md) e [END_COLUMN_MAP](../../data/oledb/end-column-map.md) macros.  
  
-   Entre os [BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md) e [END_ACCESSOR](../../data/oledb/end-accessor.md) macros.  
  
-   Entre os [BEGIN_PARAM_MAP](../../data/oledb/begin-param-map.md) e [END_PARAM_MAP](../../data/oledb/end-param-map.md) macros.  

### <a name="column_entry_type"></a> COLUMN_ENTRY_TYPE
Representa uma associação para a coluna específica no banco de dados. Dá suporte à *tipo* parâmetro.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
COLUMN_ENTRY_TYPE (nOrdinal, wType, data)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *nOrdinal*  
 [in] O número da coluna.  
  
 *wType*  
 [in] Tipo de dados de entrada de coluna.  
  
 *data*  
 [in] O membro de dados correspondente no registro do usuário.  
  
#### <a name="remarks"></a>Comentários  
 Essa macro é uma variante especializada do [COLUMN_ENTRY](../../data/oledb/column-entry.md) macro que fornece um meio de especificar o tipo de dados.  

### <a name="column_entry_type_size"></a> COLUMN_ENTRY_TYPE_SIZE
Representa uma associação para a coluna específica no banco de dados. Dá suporte à *tipo* e *tamanho* parâmetros.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
COLUMN_ENTRY_TYPE_SIZE(nOrdinal, wType, nLength, data)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *nOrdinal*  
 [in] O número da coluna.  
  
 *wType*  
 [in] Tipo de dados de entrada de coluna.  
  
 *nLength*  
 [in] Tamanho da entrada de coluna em bytes.  
  
 *data*  
 [in] O membro de dados correspondente no registro do usuário.  
  
#### <a name="remarks"></a>Comentários  
 Essa macro é uma variante especializada do [COLUMN_ENTRY](../../data/oledb/column-entry.md) macro que fornece um meio de especificar o tamanho dos dados e o tipo.  

### <a name="column_name"></a> NOME DA COLUNA
Representa uma associação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante ao [COLUMN_ENTRY](../../data/oledb/column-entry.md), a menos que essa macro usa o nome da coluna em vez do número de coluna.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
COLUMN_NAME(pszName, data)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *pszName*  
 [in] Um ponteiro para o nome da coluna. O nome deve ser uma cadeia de caracteres Unicode. Você pode fazer isso colocando um "L" na frente do nome, por exemplo: `L"MyColumn"`.  
  
 *data*  
 [in] O membro de dados correspondente no registro do usuário.  
  
#### <a name="remarks"></a>Comentários  
 As macros COLUMN_NAME_ * são usadas nos mesmos locais como [COLUMN_ENTRY](../../data/oledb/column-entry.md):  
  
-   Entre os [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md) e [END_COLUMN_MAP](../../data/oledb/end-column-map.md) macros.  
  
-   Entre os [BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md) e [END_ACCESSOR](../../data/oledb/end-accessor.md) macros.  
  
-   Entre os [BEGIN_PARAM_MAP](../../data/oledb/begin-param-map.md) e [END_PARAM_MAP](../../data/oledb/end-param-map.md) macros.  

### <a name="column_name_ex"></a> COLUMN_NAME_EX
Representa uma associação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante ao [COLUMN_NAME](../../data/oledb/column-name.md), a menos que essa macro também usa o tipo de dados, tamanho, precisão, escala, comprimento da coluna e status da coluna.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
COLUMN_NAME_EX(pszName, wType, nLength, nPrecision, nScale, data, length, status )  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *pszName*  
 [in] Um ponteiro para o nome da coluna. O nome deve ser uma cadeia de caracteres Unicode. Você pode fazer isso colocando um "L" na frente do nome, por exemplo: `L"MyColumn"`.  
  
 *wType*  
 [in] O tipo de dados.  
  
 *nLength*  
 [in] O tamanho dos dados em bytes.  
  
 *nPrecision*  
 [in] A precisão máxima a ser usado ao obter dados e *wType* é `DBTYPE_NUMERIC`. Caso contrário, esse parâmetro será ignorado.  
  
 *nScale*  
 [in] A escala a ser usado ao obter dados e *wType* é `DBTYPE_NUMERIC` ou `DBTYPE_DECIMAL`.  
  
 *data*  
 [in] O membro de dados correspondente no registro do usuário.  
  
 *length*  
 [in] A variável a ser associado para o comprimento da coluna.  
  
 *status*  
 [in] A variável a ser associado para o status da coluna.  
  
#### <a name="remarks"></a>Comentários  
 Ver [COLUMN_NAME](../../data/oledb/column-name.md) para obter informações sobre onde as macros COLUMN_NAME_ * são usadas.  

### <a name="column_name_length"></a> COLUMN_NAME_LENGTH
Representa uma associação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante ao [COLUMN_NAME](../../data/oledb/column-name.md), a menos que essa macro também usa o comprimento da coluna.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
COLUMN_NAME_LENGTH(pszName, data, length)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *pszName*  
 [in] Um ponteiro para o nome da coluna. O nome deve ser uma cadeia de caracteres Unicode. Você pode fazer isso colocando um "L" na frente do nome, por exemplo: `L"MyColumn"`.  
  
 *data*  
 [in] O membro de dados correspondente no registro do usuário.  
  
 *length*  
 [in] A variável a ser associado para o comprimento da coluna.  
  
#### <a name="remarks"></a>Comentários  
 Ver [COLUMN_NAME](../../data/oledb/column-name.md) para obter informações sobre onde as macros COLUMN_NAME_ * são usadas.  

### <a name="column_name_length_status"></a> COLUMN_NAME_LENGTH_STATUS
Representa uma associação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante ao [COLUMN_NAME](../../data/oledb/column-name.md), a menos que essa macro também usa o comprimento da coluna e o status da coluna.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
COLUMN_NAME_LENGTH_STATUS(pszName, data, length, status )  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *pszName*  
 [in] Um ponteiro para o nome da coluna. O nome deve ser uma cadeia de caracteres Unicode. Você pode fazer isso colocando um "L" na frente do nome, por exemplo: `L"MyColumn"`.  
  
 *data*  
 [in] O membro de dados correspondente no registro do usuário.  
  
 *length*  
 [in] A variável a ser associado para o comprimento da coluna.  
  
 *status*  
 [in] A variável a ser associado para o status da coluna.  
  
#### <a name="remarks"></a>Comentários  
 Ver [COLUMN_NAME](../../data/oledb/column-name.md) para obter informações sobre onde as macros COLUMN_NAME_ * são usadas.  

### <a name="column_name_ps"></a> COLUMN_NAME_PS
Representa uma associação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante ao [COLUMN_NAME](../../data/oledb/column-name.md), a menos que essa macro também leva a precisão e escala.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
COLUMN_NAME_PS(pszName, nPrecision, nScale, data )  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *pszName*  
 [in] Um ponteiro para o nome da coluna. O nome deve ser uma cadeia de caracteres Unicode. Você pode fazer isso colocando um "L" na frente do nome, por exemplo: `L"MyColumn"`.  
  
 *nPrecision*  
 [in] A precisão máxima da coluna que você deseja associar.  
  
 *nScale*  
 [in] A escala da coluna que você deseja associar.  
  
 *data*  
 [in] O membro de dados correspondente no registro do usuário.  
  
#### <a name="remarks"></a>Comentários  
 Ver [COLUMN_NAME](../../data/oledb/column-name.md) para obter informações sobre onde as macros COLUMN_NAME_ * são usadas.  

### <a name="column_name_ps_length"></a> COLUMN_NAME_PS_LENGTH
Representa uma associação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante ao [COLUMN_NAME](../../data/oledb/column-name.md), a menos que essa macro também leva a precisão, escala e coluna de comprimento.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
COLUMN_NAME_PS_LENGTH(pszName, nPrecision, nScale, data, length )  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *pszName*  
 [in] Um ponteiro para o nome da coluna. O nome deve ser uma cadeia de caracteres Unicode. Você pode fazer isso colocando um "L" na frente do nome, por exemplo: `L"MyColumn"`.  
  
 *nPrecision*  
 [in] A precisão máxima da coluna que você deseja associar.  
  
 *nScale*  
 [in] A escala da coluna que você deseja associar.  
  
 *data*  
 [in] O membro de dados correspondente no registro do usuário.  
  
 *length*  
 [in] A variável a ser associado para o comprimento da coluna.  
  
#### <a name="remarks"></a>Comentários  
 Ver [COLUMN_NAME](../../data/oledb/column-name.md) para obter informações sobre onde as macros COLUMN_NAME_ * são usadas.  

### <a name="column_name_ps_length_status"></a> COLUMN_NAME_PS_LENGTH_STATUS
Representa uma associação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante ao [COLUMN_NAME](../../data/oledb/column-name.md), a menos que essa macro também leva a precisão, escala, comprimento da coluna e status da coluna.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
COLUMN_NAME_PS_LENGTH_STATUS(pszName, nPrecision, nScale, data, length, status )  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *pszName*  
 [in] Um ponteiro para o nome da coluna. O nome deve ser uma cadeia de caracteres Unicode. Você pode fazer isso colocando um "L" na frente do nome, por exemplo: `L"MyColumn"`.  
  
 *nPrecision*  
 [in] A precisão máxima da coluna que você deseja associar.  
  
 *nScale*  
 [in] A escala da coluna que você deseja associar.  
  
 *data*  
 [in] O membro de dados correspondente no registro do usuário.  
  
 *length*  
 [in] A variável a ser associado para o comprimento da coluna.  
  
 *status*  
 [in] A variável a ser associado para o status da coluna.  
  
#### <a name="remarks"></a>Comentários  
 Ver [COLUMN_NAME](../../data/oledb/column-name.md) para obter informações sobre onde as macros COLUMN_NAME_ * são usadas.  

### <a name="column_name_ps_status"></a> COLUMN_NAME_PS_STATUS
Representa uma associação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante ao [COLUMN_NAME](../../data/oledb/column-name.md), a menos que essa macro também leva a precisão, escala e coluna status.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
COLUMN_NAME_PS_STATUS(pszName, nPrecision, nScale, data, status )  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *pszName*  
 [in] Um ponteiro para o nome da coluna. O nome deve ser uma cadeia de caracteres Unicode. Você pode fazer isso colocando um "L" na frente do nome, por exemplo: `L"MyColumn"`.  
  
 *nPrecision*  
 [in] A precisão máxima da coluna que você deseja associar.  
  
 *nScale*  
 [in] A escala da coluna que você deseja associar.  
  
 *data*  
 [in] O membro de dados correspondente no registro do usuário.  
  
 *status*  
 [in] A variável a ser associado para o status da coluna.  
  
#### <a name="remarks"></a>Comentários  
 Ver [COLUMN_NAME](../../data/oledb/column-name.md) para obter informações sobre onde as macros COLUMN_NAME_ * são usadas.  

### <a name="column_name_status"></a> COLUMN_NAME_STATUS
Representa uma associação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante ao [COLUMN_NAME](../../data/oledb/column-name.md), a menos que essa macro também usa o status da coluna.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
COLUMN_NAME_STATUS(pszName, data, status )  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *pszName*  
 [in] Um ponteiro para o nome da coluna. O nome deve ser uma cadeia de caracteres Unicode. Você pode fazer isso colocando um "L" na frente do nome, por exemplo: `L"MyColumn"`.  
  
 *data*  
 [in] O membro de dados correspondente no registro do usuário.  
  
 *status*  
 [in] A variável a ser associado para o status da coluna.  
  
#### <a name="remarks"></a>Comentários  
 Ver [COLUMN_NAME](../../data/oledb/column-name.md) para obter informações sobre onde as macros COLUMN_NAME_ * são usadas.  

### <a name="column_name_type"></a> COLUMN_NAME_TYPE
Representa uma associação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante ao [COLUMN_NAME](../../data/oledb/column-name.md), a menos que essa macro também usa o tipo de dados.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
COLUMN_NAME_TYPE(pszName, wType, data)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *pszName*  
 [in] Um ponteiro para o nome da coluna. O nome deve ser uma cadeia de caracteres Unicode. Você pode fazer isso colocando um "L" na frente do nome, por exemplo: `L"MyColumn"`.  
  
 *wType*  
 [in] O tipo de dados.  
  
 *data*  
 [in] O membro de dados correspondente no registro do usuário.  
  
#### <a name="remarks"></a>Comentários  
 Ver [COLUMN_NAME](../../data/oledb/column-name.md) para obter informações sobre onde as macros COLUMN_NAME_ * são usadas.  

### <a name="column_name_type_ps"></a> COLUMN_NAME_TYPE_PS
Representa uma associação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante ao [COLUMN_NAME](../../data/oledb/column-name.md), a menos que essa macro também usa o tipo de dados, precisão e escala.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
COLUMN_NAME_TYPE_PS(pszName, wType, nPrecision, nScale, data)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *pszName*  
 [in] Um ponteiro para o nome da coluna. O nome deve ser uma cadeia de caracteres Unicode. Você pode fazer isso colocando um "L" na frente do nome, por exemplo: `L"MyColumn"`.  
  
 *wType*  
 [in] O tipo de dados.  
  
 *nPrecision*  
 [in] A precisão máxima a ser usado ao obter dados e *wType* é `DBTYPE_NUMERIC`. Caso contrário, esse parâmetro será ignorado.  
  
 *nScale*  
 [in] A escala a ser usado ao obter dados e *wType* é `DBTYPE_NUMERIC` ou `DBTYPE_DECIMAL`.  
  
 *data*  
 [in] O membro de dados correspondente no registro do usuário.  
  
#### <a name="remarks"></a>Comentários  
 Ver [COLUMN_NAME](../../data/oledb/column-name.md) para obter informações sobre onde as macros COLUMN_NAME_ * são usadas.  

### <a name="column_name_type_size"></a> COLUMN_NAME_TYPE_SIZE
Representa uma associação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante ao [COLUMN_NAME](../../data/oledb/column-name.md), a menos que essa macro também usa o tipo de dados e tamanho.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
COLUMN_NAME_TYPE_SIZE(pszName, wType, nLength, data)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *pszName*  
 [in] Um ponteiro para o nome da coluna. O nome deve ser uma cadeia de caracteres Unicode. Você pode fazer isso colocando um "L" na frente do nome, por exemplo: `L"MyColumn"`.  
  
 *wType*  
 [in] O tipo de dados.  
  
 *nLength*  
 [in] O tamanho dos dados em bytes.  
  
 *data*  
 [in] O membro de dados correspondente no registro do usuário.  
  
#### <a name="remarks"></a>Comentários  
 Ver [COLUMN_NAME](../../data/oledb/column-name.md) para obter informações sobre onde as macros COLUMN_NAME_ * são usadas.  

### <a name="column_name_type_status"></a> COLUMN_NAME_TYPE_STATUS
Representa uma associação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante ao [COLUMN_NAME](../../data/oledb/column-name.md), a menos que essa macro também usa o status de coluna e de tipo de dados.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
COLUMN_NAME_TYPE_STATUS(pszName, wType, status, data)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *pszName*  
 [in] Um ponteiro para o nome da coluna. O nome deve ser uma cadeia de caracteres Unicode. Você pode fazer isso colocando um "L" na frente do nome, por exemplo: `L"MyColumn"`.  
  
 *wType*  
 [in] O tipo de dados.  
  
 *status*  
 [in] A variável a ser associado para o status da coluna.  
  
 *data*  
 [in] O membro de dados correspondente no registro do usuário.  
  
#### <a name="remarks"></a>Comentários  
 Ver [COLUMN_NAME](../../data/oledb/column-name.md) para obter informações sobre onde as macros COLUMN_NAME_ * são usadas.  

### <a name="end_column_map"></a> END_COLUMN_MAP
Marca o fim das entradas de mapa de coluna.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
END_COLUMN_MAP()  
```  
  
#### <a name="remarks"></a>Comentários  
 Ele é usado com um único acessador em um conjunto de linhas. A macro BEGIN_COLUMN_MAP é concluída com a macro END_COLUMN_MAP.  
  
#### <a name="example"></a>Exemplo  
 Ver [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md).  

### <a name="define_command"></a> DEFINE_COMMAND
Especifica o comando que será usado para criar o conjunto de linhas ao usar o [CCommand](../../data/oledb/ccommand-class.md) classe. Aceita apenas os tipos de cadeia de caracteres correspondente ao tipo de aplicativo especificado (ANSI ou Unicode).  
  
> [!NOTE]
>  É recomendável que você use [DEFINE_COMMAND_EX](../../data/oledb/define-command-ex.md) em vez de DEFINE_COMMAND.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
DEFINE_COMMAND(x, szCommand)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *x*  
 [in] O nome da classe de registro (comando) do usuário.  
  
 *szCommand*  
 [in] A cadeia de caracteres de comando que será usada para criar o conjunto de linhas ao usar [CCommand](../../data/oledb/ccommand-class.md).  
  
#### <a name="remarks"></a>Comentários  
 A cadeia de caracteres de comando que você especificar será usada como o padrão se você não especificar o texto do comando na [ccommand:: Open](../../data/oledb/ccommand-open.md) método.  
  
 Essa macro aceita cadeias de caracteres ANSI se você compilar seu aplicativo como ANSI ou cadeias de caracteres Unicode, se você compilar seu aplicativo como Unicode. É recomendável que você use [DEFINE_COMMAND_EX](../../data/oledb/define-command-ex.md) DEFINE_COMMAND, em vez de como a primeira opção aceita cadeias de caracteres Unicode, independentemente do tipo de aplicativo ANSI ou Unicode.  
  
#### <a name="example"></a>Exemplo  
 Ver [BOOKMARK_ENTRY](../../data/oledb/bookmark-entry.md).  

### <a name="define_command_ex"></a> DEFINE_COMMAND_EX
Especifica o comando que será usado para criar o conjunto de linhas ao usar o [CCommand](../../data/oledb/ccommand-class.md) classe. Dá suporte a aplicativos ANSI e Unicode.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
DEFINE_COMMAND_EX(x, wszCommand)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *x*  
 [in] O nome da classe de registro (comando) do usuário.  
  
 *wszCommand*  
 [in] A cadeia de caracteres de comando que será usada para criar o conjunto de linhas ao usar [CCommand](../../data/oledb/ccommand-class.md).  
  
#### <a name="remarks"></a>Comentários  
 A cadeia de caracteres de comando que você especificar será usada como o padrão se você não especificar o texto do comando na [ccommand:: Open](../../data/oledb/ccommand-open.md) método.  
  
 Essa macro aceita cadeias de caracteres Unicode, independentemente do tipo de aplicativo. Essa macro é preferível [DEFINE_COMMAND](../../data/oledb/define-command.md) porque ele dá suporte a Unicode, bem como aplicativos ANSI.  
  
#### <a name="example"></a>Exemplo  
 Ver [BOOKMARK_ENTRY](../../data/oledb/bookmark-entry.md).  

### <a name="begin_param_map"></a> BEGIN_PARAM_MAP
Marca o início das entradas de mapa de parâmetro.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
BEGIN_PARAM_MAP(x)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *x*  
 [in] O nome da classe de registro de usuário.  
  
#### <a name="remarks"></a>Comentários  
 Parâmetros são usados pelo [comandos](https://msdn.microsoft.com/library/ms724608.aspx).  
  
#### <a name="example"></a>Exemplo  
 Consulte o exemplo para o [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md) macro.  

### <a name="end_param_map"></a> END_PARAM_MAP
Marca o fim das entradas de mapa de parâmetro.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
END_PARAM_MAP()  
```  
  
#### <a name="example"></a>Exemplo  
 Consulte o exemplo para o [BEGIN_PARAM_MAP](../../data/oledb/begin-param-map.md) macro.  
  
### <a name="set_param_type"></a> SET_PARAM_TYPE
Especifica as macros COLUMN_ENTRY que seguem a entrada de macro SET_PARAM_TYPE, saída ou entrada/saída.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
SET_PARAM_TYPE(type)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *type*  
 [in] O tipo a ser definido para o parâmetro.  
  
#### <a name="remarks"></a>Comentários  
 Provedores dão suporte a apenas tipos de entrada/saída parâmetros que têm suporte pela fonte de dados subjacente. O tipo é uma combinação de um ou mais `DBPARAMIO` valores (veja [estruturas DBBINDING](https://msdn.microsoft.com/library/ms716845.aspx) no *referência do programador DB OLE*):  
  
-   `DBPARAMIO_NOTPARAM` O acessador não tem parâmetros. Normalmente, você define `eParamIO` para esse valor nos acessadores de linha para lembrar o usuário que os parâmetros são ignorados.  
  
-   `DBPARAMIO_INPUT` Um parâmetro de entrada.  
  
-   `DBPARAMIO_OUTPUT` Um parâmetro de saída.  
  
-   `DBPARAMIO_INPUT | DBPARAMIO_OUTPUT` O parâmetro é uma entrada e um parâmetro de saída.  
  
#### <a name="example"></a>Exemplo  
```cpp  
class CArtistsProperty
{
public:
   short m_nReturn;
   short m_nAge;
   TCHAR m_szFirstName[21];
   TCHAR m_szLastName[31];

BEGIN_PARAM_MAP(CArtistsProperty)
   SET_PARAM_TYPE(DBPARAMIO_OUTPUT)
   COLUMN_ENTRY(1, m_nReturn)
   SET_PARAM_TYPE(DBPARAMIO_INPUT)
   COLUMN_ENTRY(2, m_nAge)
END_PARAM_MAP()

BEGIN_COLUMN_MAP(CArtistsProperty)
   COLUMN_ENTRY(1, m_szFirstName)
   COLUMN_ENTRY(2, m_szLastName)
END_COLUMN_MAP()

   HRESULT OpenDataSource()
   {
      CDataSource _db;
      _db.Open();
      return m_session.Open(_db);
   }

   void CloseDataSource()
   {
      m_session.Close();
   }

   CSession m_session;

   DEFINE_COMMAND_EX(CArtistsProperty, L" \
      { ? = SELECT Age FROM Artists WHERE Age < ? }")
};
``` 

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Macros e funções globais para modelos de consumidor do OLE DB](../../data/oledb/macros-and-global-functions-for-ole-db-consumer-templates.md)    
 [Modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)    