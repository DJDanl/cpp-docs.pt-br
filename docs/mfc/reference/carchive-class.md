---
title: Classe CArchive
ms.date: 11/04/2016
f1_keywords:
- CArchive
- AFX/CArchive
- AFX/CArchive::CArchive
- AFX/CArchive::Abort
- AFX/CArchive::Close
- AFX/CArchive::Flush
- AFX/CArchive::GetFile
- AFX/CArchive::GetObjectSchema
- AFX/CArchive::IsBufferEmpty
- AFX/CArchive::IsLoading
- AFX/CArchive::IsStoring
- AFX/CArchive::MapObject
- AFX/CArchive::Read
- AFX/CArchive::ReadClass
- AFX/CArchive::ReadObject
- AFX/CArchive::ReadString
- AFX/CArchive::SerializeClass
- AFX/CArchive::SetLoadParams
- AFX/CArchive::SetObjectSchema
- AFX/CArchive::SetStoreParams
- AFX/CArchive::Write
- AFX/CArchive::WriteClass
- AFX/CArchive::WriteObject
- AFX/CArchive::WriteString
- AFX/CArchive::m_pDocument
helpviewer_keywords:
- CArchive [MFC], CArchive
- CArchive [MFC], Abort
- CArchive [MFC], Close
- CArchive [MFC], Flush
- CArchive [MFC], GetFile
- CArchive [MFC], GetObjectSchema
- CArchive [MFC], IsBufferEmpty
- CArchive [MFC], IsLoading
- CArchive [MFC], IsStoring
- CArchive [MFC], MapObject
- CArchive [MFC], Read
- CArchive [MFC], ReadClass
- CArchive [MFC], ReadObject
- CArchive [MFC], ReadString
- CArchive [MFC], SerializeClass
- CArchive [MFC], SetLoadParams
- CArchive [MFC], SetObjectSchema
- CArchive [MFC], SetStoreParams
- CArchive [MFC], Write
- CArchive [MFC], WriteClass
- CArchive [MFC], WriteObject
- CArchive [MFC], WriteString
- CArchive [MFC], m_pDocument
ms.assetid: 9e950d23-b874-456e-ae4b-fe00781a7699
ms.openlocfilehash: f1e5701e95ec080845f3d2422da5d6ce4b9c906b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50465605"
---
# <a name="carchive-class"></a>Classe CArchive

Permite que você salve uma rede complexa de objetos em um formulário binário permanente (geralmente armazenamento em disco) que persiste depois que esses objetos são excluídos.

## <a name="syntax"></a>Sintaxe

```
class CArchive
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CArchive::CArchive](#carchive)|Cria um objeto `CArchive`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CArchive::Abort](#abort)|Fecha um arquivo sem lançar uma exceção.|
|[CArchive::Close](#close)|Libera os dados não escritos e desconecta o `CFile`.|
|[CArchive::Flush](#flush)|Libera os dados não gravados do buffer de arquivo morto.|
|[CArchive::GetFile](#getfile)|Obtém o `CFile` ponteiro de objeto para este arquivo morto.|
|[CArchive::GetObjectSchema](#getobjectschema)|Chamado a partir de `Serialize` função para determinar a versão do objeto que está sendo desserializado.|
|[CArchive::IsBufferEmpty](#isbufferempty)|Determina se o buffer foi esvaziado durante um Windows Sockets receber o processo.|
|[CArchive::IsLoading](#isloading)|Determina se o arquivo morto está carregando.|
|[CArchive::IsStoring](#isstoring)|Determina se o arquivo morto está armazenando.|
|[CArchive::MapObject](#mapobject)|Coloca os objetos no mapa que não são serializados para o arquivo, mas que estão disponíveis para subobjetos fazer referência.|
|[CArchive::Read](#read)|Lê os bytes brutos.|
|[CArchive::ReadClass](#readclass)|Lê uma referência de classe anteriormente armazenada com `WriteClass`.|
|[CArchive::ReadObject](#readobject)|Chama um objeto `Serialize` função para o carregamento.|
|[CArchive::ReadString](#readstring)|Lê uma única linha de texto.|
|[CArchive::SerializeClass](#serializeclass)|Lê ou grava a referência de classe para o `CArchive` objeto dependendo da direção do `CArchive`.|
|[CArchive::SetLoadParams](#setloadparams)|Define o tamanho para o qual a matriz de carga aumenta. Deve ser chamado antes de qualquer objeto é carregado ou antes `MapObject` ou `ReadObject` é chamado.|
|[CArchive::SetObjectSchema](#setobjectschema)|Define o esquema de objeto armazenado no objeto de arquivo morto.|
|[CArchive::SetStoreParams](#setstoreparams)|Define o tamanho da tabela de hash e o tamanho do bloco do mapa usado para identificar objetos exclusivos durante o processo de serialização.|
|[CArchive::Write](#write)|Grava os bytes brutos.|
|[CArchive::WriteClass](#writeclass)|Grava uma referência para o `CRuntimeClass` para o `CArchive`.|
|[CArchive::WriteObject](#writeobject)|Chama um objeto `Serialize` função para o armazenamento.|
|[CArchive::WriteString](#writestring)|Grava uma única linha de texto.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CArchive::operator &lt;&lt;](#operator_lt_lt)|Armazena objetos e tipos primitivos para o arquivo morto.|
|[CArchive::operator &gt;&gt;](#operator_gt_gt)|Carrega os objetos e tipos primitivos do arquivo morto.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CArchive::m_pDocument](#m_pdocument)||

## <a name="remarks"></a>Comentários

`CArchive` não tem uma classe base.

Mais tarde você pode carregar os objetos de armazenamento persistente, com a recomposição-los na memória. Esse processo de tornar os dados persistentes é chamado de "serialização".

Você pode pensar em um objeto de arquivo morto como um tipo de fluxo binário. Como um fluxo de entrada/saída, um arquivo morto está associado um arquivo e permite que a gravação em buffer e a leitura dos dados para e do armazenamento. Um fluxo de entrada/saída processa as sequências de caracteres ASCII, mas um arquivo morto processa dados de objeto binário em um formato eficiente e não redundante.

Você deve criar uma [CFile](../../mfc/reference/cfile-class.md) objeto antes de criar um `CArchive` objeto. Além disso, você deve garantir que o status de carga/armazenamento do arquivo morto é compatível com o modo de abertura do arquivo. Você está limitado a um arquivo de ativo por arquivo.

Quando você constrói uma `CArchive` do objeto, você pode anexá-lo a um objeto da classe `CFile` (ou uma classe derivada) que representa um arquivo aberto. Você também pode especificar se o arquivo será usado para carregar ou armazenar. Um `CArchive` objeto pode processar não somente tipos primitivos, mas também objetos de [CObject](../../mfc/reference/cobject-class.md)-projetadas para a serialização de classes derivadas. Uma classe serializável normalmente tem um `Serialize` função de membro e geralmente usa o [DECLARE_SERIAL](../../mfc/reference/run-time-object-model-services.md#declare_serial) e [IMPLEMENT_SERIAL](../../mfc/reference/run-time-object-model-services.md#implement_serial) macros, conforme descrito na classe `CObject`.

A extração sobrecarregada ( **>>**) e a inserção ( **<<**) operadores são interfaces de programação de arquivo conveniente que dão suporte a ambos os tipos primitivos e `CObject` -as classes derivadas.

`CArchive` também dá suporte à programação com as classes MFC Windows Sockets [CSocket](../../mfc/reference/csocket-class.md) e [CSocketFile](../../mfc/reference/csocketfile-class.md). O [IsBufferEmpty](#isbufferempty) função de membro dá suporte a esse uso.

Para obter mais informações sobre `CArchive`, consulte os artigos [serialização](../../mfc/serialization-in-mfc.md) e [Windows Sockets: usando soquetes com arquivos mortos](../../mfc/windows-sockets-using-sockets-with-archives.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CArchive`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

##  <a name="abort"></a>  CArchive::Abort

Chame essa função para fechar o arquivo sem lançar uma exceção.

```
void Abort ();
```

### <a name="remarks"></a>Comentários

O `CArchive` destruidor chamará normalmente `Close`, que irá liberar todos os dados que não foram salvas associados `CFile` objeto. Isso pode causar exceções.

Ao capturar essas exceções, é uma boa ideia usar `Abort`, de modo que destructing o `CArchive` objeto não causa mais exceções. Ao lidar com exceções, `CArchive::Abort` não gerará uma exceção em falhas porque, diferentemente [CArchive::Close](#close), `Abort` ignora falhas.

Se você usou **novos** alocar o `CArchive` do objeto no heap, em seguida, você deve excluí-lo depois de fechar o arquivo.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CArchive::WriteClass](#writeclass).

##  <a name="carchive"></a>  CArchive::CArchive

Constrói um `CArchive` de objeto e especifica se será usada para carregar ou armazenar objetos.

```
CArchive(
    CFile* pFile,
    UINT nMode,
    int nBufSize = 4096,
    void* lpBuf = NULL);
```

### <a name="parameters"></a>Parâmetros

*pFile*<br/>
Um ponteiro para o `CFile` objeto que é a origem ultimate ou o destino dos dados persistentes.

*nMode*<br/>
Um sinalizador que especifica se objetos serão carregados a partir ou armazenados para o arquivo morto. O *nMode* parâmetro deve ter um dos seguintes valores:

- `CArchive::load` Carrega dados de arquivo morto. Exige apenas `CFile` permissão de leitura.

- `CArchive::store` Salva os dados para o arquivo morto. Requer `CFile` permissão de gravação.

- `CArchive::bNoFlushOnDelete` Impede que o arquivo morto automaticamente chamar `Flush` quando o destruidor de arquivo morto é chamado. Se você definir esse sinalizador, você é responsável por chamar explicitamente `Close` antes que o destruidor é chamado. Se você não fizer isso, seus dados serão corrompidos.

*nBufSize*<br/>
Um inteiro que especifica o tamanho do buffer de arquivo interno, em bytes. Observe que o tamanho do buffer padrão é de 4.096 bytes. Se você arquivar rotineiramente objetos grandes, você melhorará o desempenho se você usar um tamanho de buffer maior do que é um múltiplo do tamanho do buffer de arquivo.

*lpBuf*<br/>
Um ponteiro opcional para um buffer fornecido pelo usuário de tamanho *nBufSize*. Se você não especificar esse parâmetro, o arquivo morto aloca um buffer de heap local e libera-lo quando o objeto é destruído. O arquivo morto não libera um buffer fornecido pelo usuário.

### <a name="remarks"></a>Comentários

Você não pode alterar essa especificação depois de criar o arquivo morto.

Você não poderá usar `CFile` operações para alterar o estado do arquivo até que você tiver fechado o arquivo morto. Qualquer operação de tal será danificar a integridade do arquivo morto. Você pode acessar a posição do ponteiro do arquivo a qualquer momento durante a serialização, obtendo o objeto de arquivo do arquivo morto do [GetFile](#getfile) função de membro e, em seguida, usando o [CFile::GetPosition](../../mfc/reference/cfile-class.md#getposition) função . Você deve chamar [CArchive::Flush](#flush) antes de obter a posição do ponteiro do arquivo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#12](../../mfc/codesnippet/cpp/carchive-class_1.cpp)]

##  <a name="close"></a>  CArchive::Close

Libera todos os dados restantes no buffer, fecha o arquivo morto e desconecta o arquivamento do arquivo.

```
void Close();
```

### <a name="remarks"></a>Comentários

Nenhuma outra operação no arquivo morto é permitidas. Depois de fechar um arquivo morto, você pode criar outro arquivo para o mesmo arquivo, ou você pode fechar o arquivo.

A função de membro `Close` garante que todos os dados são transferidos do arquivo morto para o arquivo e faz o arquivo morto não está disponível. Para concluir a transferência do arquivo para a mídia de armazenamento, primeiro você deve usar [CFile::Close](../../mfc/reference/cfile-class.md#close) e, em seguida, destrua o `CFile` objeto.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CArchive::WriteString](#writestring).

##  <a name="flush"></a>  CArchive::Flush

Força os dados restantes no buffer de arquivo morto a ser gravado no arquivo.

```
void Flush();
```

### <a name="remarks"></a>Comentários

A função de membro `Flush` garante que todos os dados são transferidos do arquivo para o arquivo. Você deve chamar [CFile::Close](../../mfc/reference/cfile-class.md#close) para concluir a transferência do arquivo para a mídia de armazenamento.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#13](../../mfc/codesnippet/cpp/carchive-class_2.cpp)]

##  <a name="getfile"></a>  CArchive::GetFile

Obtém o `CFile` ponteiro de objeto para este arquivo morto.

```
CFile* GetFile() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro constante para o `CFile` objeto em uso.

### <a name="remarks"></a>Comentários

Você deve liberar o arquivo morto antes de usar `GetFile`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#14](../../mfc/codesnippet/cpp/carchive-class_3.cpp)]

##  <a name="getobjectschema"></a>  CArchive::GetObjectSchema

Chame essa função do `Serialize` função para determinar a versão do objeto que atualmente está sendo desserializado.

```
UINT GetObjectSchema();
```

### <a name="return-value"></a>Valor de retorno

Durante a desserialização, a versão do objeto que está sendo lido.

### <a name="remarks"></a>Comentários

Chamar essa função é válida somente quando o `CArchive` objeto está sendo carregado ( [CArchive::IsLoading](#isloading) retorna não zero). Ele deve ser a primeira chamada no `Serialize` função e chamada apenas uma vez. Um valor de retorno (UINT) -1 indica que o número de versão é desconhecido.

Um `CObject`-classe derivada pode usar VERSIONABLE_SCHEMA combinados (usando o bit a bit **ou**) com a versão do esquema em si (na macro IMPLEMENT_SERIAL) para criar um "objeto de versátil", ou seja, um objeto cujo `Serialize` função de membro pode ler várias versões. A funcionalidade de framework padrão (sem VERSIONABLE_SCHEMA) é lançar uma exceção quando a versão é incompatível.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#15](../../mfc/codesnippet/cpp/carchive-class_4.cpp)]

##  <a name="isbufferempty"></a>  CArchive::IsBufferEmpty

Chame essa função de membro para determinar se o buffer interno do objeto de arquivo morto está vazio.

```
BOOL IsBufferEmpty() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o buffer do arquivo morto está vazio. Caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função é fornecida para dar suporte à programação com a classe do MFC Windows Sockets `CSocketFile`. Você não precisará usá-lo para um arquivo morto associado com um `CFile` objeto.

O motivo para usar `IsBufferEmpty` com um arquivo morto associado com um `CSocketFile` objeto é que o buffer do arquivo morto pode conter mais de uma mensagem ou registro. Depois de receber uma mensagem, você deve usar `IsBufferEmpty` para controlar um loop que continuará a receber dados até que o buffer está vazio. Para obter mais informações, consulte o [Receive](../../mfc/reference/casyncsocket-class.md#receive) função de membro da classe `CAsyncSocket`, que mostra como usar `IsBufferEmpty`.

Para obter mais informações, consulte [Windows Sockets: usando soquetes com arquivos mortos](../../mfc/windows-sockets-using-sockets-with-archives.md).

##  <a name="isloading"></a>  CArchive::IsLoading

Determina se o arquivo morto está carregando dados.

```
BOOL IsLoading() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o arquivo está sendo usado para carregar; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função membro é chamada pelo `Serialize` funções das classes arquivadas.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#16](../../mfc/codesnippet/cpp/carchive-class_5.cpp)]

##  <a name="isstoring"></a>  CArchive::IsStoring

Determina se o arquivo morto está armazenando dados.

```
BOOL IsStoring() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o arquivo está sendo usado para armazenar; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função membro é chamada pelo `Serialize` funções das classes arquivadas.

Se o `IsStoring` status de um arquivo morto é diferente de zero, em seguida, seu `IsLoading` status for 0 e vice-versa.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#17](../../mfc/codesnippet/cpp/carchive-class_6.cpp)]

##  <a name="mapobject"></a>  CArchive::MapObject

Chame essa função de membro para colocar os objetos no mapa que realmente não são serializados para o arquivo, mas que estão disponíveis para subobjetos fazer referência.

```
void MapObject(const CObject* pOb);
```

### <a name="parameters"></a>Parâmetros

*caixa postal*<br/>
Um ponteiro constante para o objeto que está sendo armazenado.

### <a name="remarks"></a>Comentários

Por exemplo, você não pode serializar um documento, mas você fosse serializar os itens que fazem parte do documento. Chamando `MapObject`, permitir que os itens ou subobjetos, para o documento de referência. Além disso, os subitens serializados podem serializar seus *m_pDocument* ponteiro para voltar.

Você pode chamar `MapObject` quando você armazenar ao e carregar a partir de `CArchive` objeto. `MapObject` Adiciona o objeto especificado para as estruturas de dados interno mantidas pelo `CArchive` objeto durante a serialização e desserialização, mas diferentemente [ReadObject](#readobject) e [WriteObject](#writeobject), ele não chama Serialize o objeto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#18](../../mfc/codesnippet/cpp/carchive-class_7.h)]

[!code-cpp[NVC_MFCSerialization#19](../../mfc/codesnippet/cpp/carchive-class_8.cpp)]

[!code-cpp[NVC_MFCSerialization#20](../../mfc/codesnippet/cpp/carchive-class_9.h)]

[!code-cpp[NVC_MFCSerialization#21](../../mfc/codesnippet/cpp/carchive-class_10.cpp)]

##  <a name="m_pdocument"></a>  CArchive::m_pDocument

Definido como NULL por padrão, esse ponteiro para um `CDocument` pode ser definida como algo o usuário do `CArchive` desejos da instância.

```
CDocument* m_pDocument;
```

### <a name="remarks"></a>Comentários

Um uso comum desse ponteiro é transmitir informações adicionais sobre o processo de serialização para todos os objetos que está sendo serializado. Isso é feito por inicializar o ponteiro com o documento (um `CDocument`-classe derivada) que está sendo serializado, de forma que os objetos dentro do documento podem acessar o documento se necessário. Esse ponteiro também é usado pelo `COleClientItem` objetos durante a serialização.

Os conjuntos de estrutura *m_pDocument* para o documento que está sendo serializado quando um usuário emite um arquivo abrir ou salvar o comando. Se você serializar um documento de contêiner de vinculação e incorporação (OLE) por razões diferentes de File Open ou Save, você deve definir explicitamente *m_pDocument*. Por exemplo, você faria isso ao serializar um documento de contêiner para a área de transferência.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#35](../../mfc/codesnippet/cpp/carchive-class_11.cpp)]

##  <a name="operator_lt_lt"></a>  CArchive::operator &lt;&lt;

Armazena o objeto indicado ou um tipo primitivo para o arquivo morto.

```
friend CArchive& operator<<(
    CArchive& ar,
    const CObject* pOb);

throw(
    CArchiveException*,
    CFileException*);

CArchive& AFXAPI operator<<(
    CArchive& ar,
    const RECT& rect);

CArchive& AFXAPI operator<<(
    CArchive& ar,
    POINT point);

CArchive& AFXAPI operator<<(
    CArchive& ar,
    SIZE size);

template<typename BaseType,
    class StringTraits> CArchive& operator<<(
    const ATL::CStringT<BaseType,
    StringTraits>& str);

CArchive& operator<<(BYTE by);
CArchive& operator<<(WORD w);
CArchive& operator<<(LONG l);
CArchive& operator<<(DWORD dw);
CArchive& operator<<(float f);
CArchive& operator<<(double d);
CArchive& operator<<(int i);
CArchive& operator<<(short w);
CArchive& operator<<(char ch);
CArchive& operator<<(wchar_t ch);
CArchive& operator<<(unsigned u);
CArchive& operator<<(bool b);
CArchive& operator<<(ULONGLONG dwdw);
CArchive& operator<<(LONGLONG dwdw);
```

### <a name="return-value"></a>Valor de retorno

Um `CArchive` referência que permite que os vários operadores de inserção em uma única linha.

### <a name="remarks"></a>Comentários

As duas últimas versões acima são especificamente para armazenar inteiros de 64 bits.

Se você usou a macro IMPLEMENT_SERIAL em sua implementação de classe, o operador de inserção sobrecarregado para `CObject` chama o protegido `WriteObject`. Essa função, por sua vez, chama o `Serialize` função da classe.

O [CStringT](../../atl-mfc-shared/reference/cstringt-class.md) operador de inserção (<<) dá suporte a diagnóstico despejar e armazenar para um arquivo morto.

### <a name="example"></a>Exemplo

Este exemplo demonstra o uso do `CArchive` operador de inserção << com o **int** e **longo** tipos.

[!code-cpp[NVC_MFCSerialization#31](../../mfc/codesnippet/cpp/carchive-class_12.cpp)]

### <a name="example"></a>Exemplo

Este exemplo 2 demonstra o uso do `CArchive` operador de inserção << com o `CStringT` tipo.

[!code-cpp[NVC_MFCSerialization#32](../../mfc/codesnippet/cpp/carchive-class_13.cpp)]

##  <a name="operator_gt_gt"></a>  CArchive::operator &gt;&gt;

Carrega um tipo primitivo ou objeto indicado do arquivo morto.

```
friend CArchive& operator>>(
    CArchive& ar,
    CObject *& pOb);

throw(
    CArchiveException*,
    CFileException*,
    CMemoryException*);

friend CArchive& operator>>(
    CArchive& ar,
    const CObject *& pOb);

throw(
    CArchiveException*,
    CFileException*,
    CMemoryException*);

CArchive& AFXAPI operator>>(
    CArchive& ar,
    const RECT& rect);

CArchive& AFXAPI operator>>(
    CArchive& ar,
    POINT point);

CArchive& AFXAPI operator>>(
    CArchive& ar,
    SIZE size);

template<typename BaseType,
    class StringTraits> CArchive& operator>>(
    ATL::CStringT<BaseType,
    StringTraits>& str);

CArchive& operator>>(BYTE& by);
CArchive& operator>>(WORD& w);
CArchive& operator>>(int& i);
CArchive& operator>>(LONG& l);
CArchive& operator>>(DWORD& dw);
CArchive& operator>>(float& f);
CArchive& operator>>(double& d);
CArchive& operator>>(short& w);
CArchive& operator>>(char& ch);
CArchive& operator>>(wchar_t& ch);
CArchive& operator>>(unsigned& u);
CArchive& operator>>(bool& b);
CArchive& operator>>(ULONGLONG& dwdw);
CArchive& operator>>(LONGLONG& dwdw);
```

### <a name="return-value"></a>Valor de retorno

Um `CArchive` referência que permite que os vários operadores de extração em uma única linha.

### <a name="remarks"></a>Comentários

As duas últimas versões acima são especificamente para o carregamento de inteiros de 64 bits.

Se você usou a macro IMPLEMENT_SERIAL em sua implementação de classe, os operadores de extração sobrecarregados para `CObject` chamar protegido `ReadObject` função (com um ponteiro de classe de tempo de execução diferente de zero). Essa função, por sua vez, chama o `Serialize` função da classe.

O [CStringT](../../atl-mfc-shared/reference/cstringt-class.md) operador de extração (>>) dá suporte ao carregamento de um arquivo.

### <a name="example"></a>Exemplo

Este exemplo demonstra o uso do `CArchive` operador de extração >> com o **int** tipo.

[!code-cpp[NVC_MFCSerialization#33](../../mfc/codesnippet/cpp/carchive-class_14.cpp)]

### <a name="example"></a>Exemplo

Este exemplo demonstra o uso do `CArchive` operadores de inserção e extração <\< e >> com o `CStringT` tipo.

[!code-cpp[NVC_MFCSerialization#34](../../mfc/codesnippet/cpp/carchive-class_15.cpp)]

##  <a name="read"></a>  CArchive::Read

Lê um número especificado de bytes do arquivo morto.

```
UINT Read(void* lpBuf, UINT nMax);
```

### <a name="parameters"></a>Parâmetros

*lpBuf*<br/>
Um ponteiro para um buffer fornecido pelo usuário que receberá os dados lidos do arquivo morto.

*Nmáx*<br/>
Um inteiro sem sinal especificando o número de bytes a serem lidos do arquivo morto.

### <a name="return-value"></a>Valor de retorno

Um inteiro sem sinal que contém o número de bytes realmente lidos. Se o valor de retorno for menor que o número solicitado, o final do arquivo foi atingido. Nenhuma exceção é lançada na condição de fim-de-arquivo.

### <a name="remarks"></a>Comentários

O arquivo morto não interpreta os bytes.

Você pode usar o `Read` função de membro dentro de seu `Serialize` função para a leitura de estruturas comuns que estão contidas em seus objetos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#24](../../mfc/codesnippet/cpp/carchive-class_16.cpp)]

##  <a name="readclass"></a>  CArchive::ReadClass

Chame essa função de membro para ler uma referência a uma classe anteriormente armazenada com [WriteClass](#writeclass).

```
CRuntimeClass* ReadClass(
    const CRuntimeClass* pClassRefRequested = NULL,
    UINT* pSchema = NULL,
    DWORD* pObTag = NULL);
```

### <a name="parameters"></a>Parâmetros

*pClassRefRequested*<br/>
Um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) estrutura que corresponde à referência de classe solicitada. Pode ser NULL.

*pSchema*<br/>
Um ponteiro para um esquema da classe de tempo de execução armazenado anteriormente.

*pObTag*<br/>
Um número que refere-se a marca de um objeto exclusivo. Usado internamente pela implementação do [ReadObject](#readobject). Exposto para a programação avançada *pObTag* normalmente deve ser NULL.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) estrutura.

### <a name="remarks"></a>Comentários

Se *pClassRefRequested* não for nulo, `ReadClass` verifica se as informações de classe arquivados são compatíveis com sua classe de tempo de execução. Se não for compatível, `ReadClass` lançará uma [CArchiveException](../../mfc/reference/carchiveexception-class.md).

Sua classe de tempo de execução deve usar [DECLARE_SERIAL](../../mfc/reference/run-time-object-model-services.md#declare_serial) e [IMPLEMENT_SERIAL](../../mfc/reference/run-time-object-model-services.md#implement_serial); caso contrário, `ReadClass` gerará um [CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md).

Se *pSchema* for NULL, o esquema da classe armazenado pode ser recuperado chamando [CArchive::GetObjectSchema](#getobjectschema); caso contrário, <strong>\*</strong>  *pSchema* conterá o esquema da classe de tempo de execução que foi armazenado anteriormente.

Você pode usar [SerializeClass](#serializeclass) em vez de `ReadClass`, que trata de leitura e gravação da referência de classe.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CArchive::WriteClass](#writeclass).

##  <a name="readobject"></a>  CArchive::ReadObject

Lê dados de objeto de arquivo morto e constrói um objeto do tipo apropriado.

```
CObject* ReadObject(const CRuntimeClass* pClass);
```

### <a name="parameters"></a>Parâmetros

*pClass*<br/>
Um ponteiro constante para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) estrutura que corresponde ao objeto que você pretende ler.

### <a name="return-value"></a>Valor de retorno

Um [CObject](../../mfc/reference/cobject-class.md) ponteiro deve ser convertido com segurança para a correta as classe derivada usando [CObject::IsKindOf](../../mfc/reference/cobject-class.md#iskindof).

### <a name="remarks"></a>Comentários

Normalmente, essa função é chamada pelo `CArchive` extração ( **>>**) operador sobrecarregado por um [CObject](../../mfc/reference/cobject-class.md) ponteiro. `ReadObject`, por sua vez, chama o `Serialize` função da classe arquivada.

Se você fornecer um diferente de zero *pClass* parâmetro, que é obtido com o [RUNTIME_CLASS](../../mfc/reference/run-time-object-model-services.md#runtime_class) macro e, em seguida, a função verifica a classe de tempo de execução do objeto arquivado. Isso pressupõe que você usou a macro IMPLEMENT_SERIAL na implementação da classe.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CArchive::WriteObject](#writeobject).

##  <a name="readstring"></a>  CArchive::ReadString

Chame essa função de membro para ler dados de texto em um buffer de arquivo associado a `CArchive` objeto.

```
BOOL ReadString(CString& rString);
LPTSTR ReadString(LPTSTR lpsz, UINT nMax);
```

### <a name="parameters"></a>Parâmetros

*rString*<br/>
Uma referência a um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que conterá a cadeia de caracteres resultante depois da leitura do arquivo associado ao objeto CArchive.

*lpsz*<br/>
Especifica um ponteiro para um buffer fornecido pelo usuário que receberá uma cadeia de caracteres de texto terminada em nulo.

*Nmáx*<br/>
Especifica o número máximo de caracteres a serem lidos. Deve ser um menor do que o tamanho do *lpsz* buffer.

### <a name="return-value"></a>Valor de retorno

Na versão que retorne BOOL, TRUE se bem-sucedido; FALSE caso contrário.

Na versão que retorna um `LPTSTR`, um ponteiro para o buffer que contém os dados de texto; NULL se o final do arquivo foi atingido.

### <a name="remarks"></a>Comentários

Na versão da função de membro com o *Nmáx* parâmetro, o buffer será conter até um limite de *Nmáx* - 1 caracteres. Leitura seja interrompida por um par de avanço de linha de retorno de carro. Caracteres de nova linha à direita sempre são removidos. Um caractere nulo ('\0') é acrescentado em ambos os casos.

[CArchive::Read](#read) também está disponível para a entrada de modo de texto, mas ele não terminar em um par de avanço de linha de retorno de carro.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CArchive::WriteString](#writestring).

##  <a name="serializeclass"></a>  CArchive::SerializeClass

Chame essa função de membro quando desejar armazenar e carregar as informações de versão de uma classe base.

```
void SerializeClass(const CRuntimeClass* pClassRef);
```

### <a name="parameters"></a>Parâmetros

*pClassRef*<br/>
Um ponteiro para um objeto de classe de tempo de execução para a classe base.

### <a name="remarks"></a>Comentários

`SerializeClass` lê ou grava a referência a uma classe para o `CArchive` objeto, dependendo da direção do `CArchive`. Use `SerializeClass` em vez de [ReadClass](#readclass) e [WriteClass](#writeclass) como uma maneira conveniente para serializar objetos de classe base; `SerializeClass` requer menos código e menos parâmetros.

Como o `ReadClass`, `SerializeClass` verifica se as informações de classe arquivados são compatíveis com sua classe de tempo de execução. Se não for compatível, `SerializeClass` lançará uma [CArchiveException](../../mfc/reference/carchiveexception-class.md).

Sua classe de tempo de execução deve usar [DECLARE_SERIAL](../../mfc/reference/run-time-object-model-services.md#declare_serial) e [IMPLEMENT_SERIAL](../../mfc/reference/run-time-object-model-services.md#implement_serial); caso contrário, `SerializeClass` gerará um [CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md).

Use o [RUNTIME_CLASS](../../mfc/reference/run-time-object-model-services.md#runtime_class) macro para recuperar o valor para o *pRuntimeClass* parâmetro. A classe base deve ter usado o [IMPLEMENT_SERIAL](../../mfc/reference/run-time-object-model-services.md#implement_serial) macro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#25](../../mfc/codesnippet/cpp/carchive-class_17.h)]

##  <a name="setloadparams"></a>  CArchive::SetLoadParams

Chame `SetLoadParams` quando você pretende ler um grande número de `CObject`-objetos derivados de um arquivo.

```
void SetLoadParams(UINT nGrowBy = 1024);
```

### <a name="parameters"></a>Parâmetros

*nGrowBy*<br/>
O número mínimo de slots de elemento para alocar se um aumento de tamanho é necessário.

### <a name="remarks"></a>Comentários

`CArchive` usa uma matriz de carga para resolver as referências a objetos armazenados no arquivo morto. `SetLoadParams` permite que você defina o tamanho para o qual a matriz de carga aumenta.

Você não deve chamar `SetLoadParams` depois de qualquer objeto é carregado, ou após [MapObject](#mapobject) ou [ReadObject](#readobject) é chamado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#26](../../mfc/codesnippet/cpp/carchive-class_18.h)]

##  <a name="setobjectschema"></a>  CArchive::SetObjectSchema

Chame essa função de membro para definir o esquema de objeto armazenado no objeto de arquivo morto para *nSchema*.

```
void SetObjectSchema(UINT nSchema);
```

### <a name="parameters"></a>Parâmetros

*nSchema*<br/>
Especifica o esquema do objeto.

### <a name="remarks"></a>Comentários

A próxima chamada para [GetObjectSchema](#getobjectschema) retornará o valor armazenado em *nSchema*.

Use `SetObjectSchema` para controle de versão avançada; por exemplo, quando quiser forçar uma versão específica a ser lido em um `Serialize` função de uma classe derivada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#27](../../mfc/codesnippet/cpp/carchive-class_19.cpp)]

##  <a name="setstoreparams"></a>  CArchive::SetStoreParams

Use `SetStoreParams` ao armazenar um grande número de `CObject`-objetos em um arquivo morto derivados.

```
void SetStoreParams(UINT nHashSize = 2053, UINT nBlockSize = 128);
```

### <a name="parameters"></a>Parâmetros

*nHashSize*<br/>
Mapeia o tamanho da tabela de hash para o ponteiro de interface. Deve ser um número primo.

*nBlockSize*<br/>
Especifica a granularidade de alocação de memória para estender os parâmetros. Deve ser uma potência de 2 para o melhor desempenho.

### <a name="remarks"></a>Comentários

`SetStoreParams` permite que você defina o tamanho da tabela de hash e o tamanho do bloco do mapa usado para identificar objetos exclusivos durante o processo de serialização.

Você não deve chamar `SetStoreParams` depois que todos os objetos são armazenados, ou após [MapObject](#mapobject) ou [WriteObject](#writeobject) é chamado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#26](../../mfc/codesnippet/cpp/carchive-class_18.h)]

##  <a name="write"></a>  CArchive::Write

Grava um número especificado de bytes para o arquivo morto.

```
void Write(const void* lpBuf, INT nMax);
```

### <a name="parameters"></a>Parâmetros

*lpBuf*<br/>
Um ponteiro para um buffer fornecido pelo usuário que contém os dados a serem gravados para o arquivo morto.

*Nmáx*<br/>
Um inteiro que especifica o número de bytes a serem gravados para o arquivo morto.

### <a name="remarks"></a>Comentários

O arquivo morto não formatará os bytes.

Você pode usar o `Write` função de membro dentro de seu `Serialize` função para gravar comum de estruturas que estão contidos em seus objetos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#23](../../mfc/codesnippet/cpp/carchive-class_20.cpp)]

##  <a name="writeclass"></a>  CArchive::WriteClass

Use `WriteClass` para armazenar as informações de versão e a classe de uma classe base durante a serialização da classe derivada.

```
void WriteClass(const CRuntimeClass* pClassRef);
```

### <a name="parameters"></a>Parâmetros

*pClassRef*<br/>
Um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) estrutura que corresponde à referência de classe solicitada.

### <a name="remarks"></a>Comentários

`WriteClass` grava uma referência para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) para a classe base para o `CArchive`. Use [CArchive::ReadClass](#readclass) para recuperar a referência.

`WriteClass` verifica se as informações de classe arquivados são compatíveis com sua classe de tempo de execução. Se não for compatível, `WriteClass` lançará uma [CArchiveException](../../mfc/reference/carchiveexception-class.md).

Sua classe de tempo de execução deve usar [DECLARE_SERIAL](../../mfc/reference/run-time-object-model-services.md#declare_serial) e [IMPLEMENT_SERIAL](../../mfc/reference/run-time-object-model-services.md#implement_serial); caso contrário, `WriteClass` gerará um [CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md).

Você pode usar [SerializeClass](#serializeclass) em vez de `WriteClass`, que trata de leitura e gravação da referência de classe.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#28](../../mfc/codesnippet/cpp/carchive-class_21.cpp)]

##  <a name="writeobject"></a>  CArchive::WriteObject

Armazena especificado `CObject` para o arquivo morto.

```
void WriteObject(const CObject* pOb);
```

### <a name="parameters"></a>Parâmetros

*caixa postal*<br/>
Um ponteiro constante para o objeto que está sendo armazenado.

### <a name="remarks"></a>Comentários

Normalmente, essa função é chamada pelo `CArchive` inserção ( **<<**) operador sobrecarregado para `CObject`. `WriteObject`, por sua vez, chama o `Serialize` função da classe arquivada.

Você deve usar a macro IMPLEMENT_SERIAL para habilitar o arquivamento. `WriteObject` grava o nome da classe ASCII para o arquivo morto. Este nome de classe é validado durante o processo de carregamento. Um esquema de codificação especial evita a duplicação desnecessária do nome de classe para vários objetos da classe. Esse esquema também impede que o armazenamento com redundância de objetos que são destinos de mais de um ponteiro.

O objeto exato (inclusive a presença do nome da classe ASCII) do método de codificação é um detalhe de implementação e pode mudar em futuras versões da biblioteca.

> [!NOTE]
>  Terminar de criar, excluir e atualizar todos os seus objetos antes de começar a arquivá-los. O arquivo morto seja corrompido caso você misturar arquivamento com a modificação de objeto.

### <a name="example"></a>Exemplo

Para obter uma definição da classe `CAge`, consulte o exemplo de [CObList::CObList](../../mfc/reference/coblist-class.md#coblist).

[!code-cpp[NVC_MFCSerialization#29](../../mfc/codesnippet/cpp/carchive-class_22.cpp)]

##  <a name="writestring"></a>  CArchive::WriteString

Use esta função de membro para gravar dados de um buffer para o arquivo associado a `CArchive` objeto.

```
void WriteString(LPCTSTR lpsz);
```

### <a name="parameters"></a>Parâmetros

*lpsz*<br/>
Especifica um ponteiro para um buffer que contém uma cadeia de caracteres de texto terminada em nulo.

### <a name="remarks"></a>Comentários

O caractere nulo de terminação ('\0') não é gravado no arquivo; nem é uma nova linha automaticamente gravada.

`WriteString` gera uma exceção em resposta a várias condições, como a condição de disco cheio.

`Write` também está disponível, mas em vez de finalização em um caractere nulo, ele grava o número solicitado de bytes no arquivo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#30](../../mfc/codesnippet/cpp/carchive-class_23.cpp)]

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CFile](../../mfc/reference/cfile-class.md)<br/>
[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Classe CSocket](../../mfc/reference/csocket-class.md)<br/>
[Classe CSocketFile](../../mfc/reference/csocketfile-class.md)
