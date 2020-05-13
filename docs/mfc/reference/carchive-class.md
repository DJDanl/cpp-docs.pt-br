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
ms.openlocfilehash: ef8b6ec9060e8c15dd45f8203dadd2a2aca9e168
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81753103"
---
# <a name="carchive-class"></a>Classe CArchive

Permite salvar uma rede complexa de objetos em uma forma binária permanente (geralmente armazenamento em disco) que persiste depois que esses objetos são excluídos.

## <a name="syntax"></a>Sintaxe

```
class CArchive
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CArchive::CArchive](#carchive)|Cria um objeto `CArchive`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CArchive::Abort](#abort)|Fecha um arquivo sem abrir uma exceção.|
|[CArchive::Fechar](#close)|Lava dados não escritos e `CFile`desconecta-se do .|
|[CArchive::Flush](#flush)|Libera dados não escritos do buffer de arquivo.|
|[CArchive::GetFile](#getfile)|Obtém `CFile` o ponteiro do objeto para este arquivo.|
|[CArchive::GetObjectSchema](#getobjectschema)|Chamado da `Serialize` função para determinar a versão do objeto que está sendo desserializado.|
|[CArchive::IsBufferEmpty](#isbufferempty)|Determina se o buffer foi esvaziado durante um processo de recebimento de soquetes do Windows.|
|[CArchive::isLoading](#isloading)|Determina se o arquivo está sendo carregado.|
|[CArchive::IsStoring](#isstoring)|Determina se o arquivo está armazenando.|
|[CArchive::MapObject](#mapobject)|Coloca objetos no mapa que não são serializados para o arquivo, mas que estão disponíveis para subobjetos fazerem referência.|
|[CArchive::Leia](#read)|Lê bytes crus.|
|[CArchive::ReadClass](#readclass)|Lê uma referência de classe `WriteClass`armazenada anteriormente com .|
|[CArchive::ReadObject](#readobject)|Chama a função `Serialize` de um objeto para carregamento.|
|[CArchive::ReadString](#readstring)|Lê uma única linha de texto.|
|[CArchive::SerializeClass](#serializeclass)|Lê ou escreve a referência `CArchive` de classe ao `CArchive`objeto, dependendo da direção do .|
|[CArchive::SetLoadParams](#setloadparams)|Define o tamanho para o qual a matriz de carga cresce. Deve ser chamado antes que qualquer `MapObject` `ReadObject` objeto seja carregado ou antes ou seja chamado.|
|[CArchive::SetObjectSchema](#setobjectschema)|Define o esquema do objeto armazenado no objeto de arquivo.|
|[CArchive::SetStoreParams](#setstoreparams)|Define o tamanho da tabela hash e o tamanho do bloco do mapa usado para identificar objetos únicos durante o processo de serialização.|
|[CArchive::Write](#write)|Escreve bytes crus.|
|[CArchive::WriteClass](#writeclass)|Escreve uma referência `CRuntimeClass` ao `CArchive`.|
|[CArchive::WriteObject](#writeobject)|Chama a função `Serialize` de um objeto para armazenar.|
|[CArchive::WriteString](#writestring)|Escreve uma única linha de texto.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CArchive::operador&lt;&lt;](#operator_lt_lt)|Armazena objetos e tipos primitivos no arquivo.|
|[CArchive::operador&gt;&gt;](#operator_gt_gt)|Carrega objetos e tipos primitivos do arquivo.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CArchive::m_pDocument](#m_pdocument)||

## <a name="remarks"></a>Comentários

`CArchive`não tem uma classe base.

Mais tarde, você pode carregar os objetos do armazenamento persistente, reconstituindo-os na memória. Esse processo de tornar os dados persistentes é chamado de "serialização".

Você pode pensar em um objeto de arquivo como uma espécie de fluxo binário. Como um fluxo de entrada/saída, um arquivo é associado a um arquivo e permite a gravação e leitura tamponadas de dados de e para o armazenamento. Um fluxo de entrada/saída processa seqüências de caracteres ASCII, mas um arquivo processa dados de objetos binários em um formato eficiente e não redundante.

Você deve criar um objeto [CFile](../../mfc/reference/cfile-class.md) antes de criar um `CArchive` objeto. Além disso, você deve garantir que o status de carga/armazenamento do arquivo seja compatível com o modo aberto do arquivo. Você está limitado a um arquivo ativo por arquivo.

Quando você `CArchive` constrói um objeto, você o `CFile` anexa a um objeto de classe (ou uma classe derivada) que representa um arquivo aberto. Você também especifica se o arquivo será usado para carregar ou armazenar. Um `CArchive` objeto pode processar não apenas tipos primitivos, mas também objetos de classes derivadas do [CObject](../../mfc/reference/cobject-class.md)projetadas para serialização. Uma classe serializável `Serialize` geralmente tem uma função de membro, e geralmente `CObject`usa as macros [DECLARE_SERIAL](../../mfc/reference/run-time-object-model-services.md#declare_serial) e [IMPLEMENT_SERIAL,](../../mfc/reference/run-time-object-model-services.md#implement_serial) conforme descrito em classe .

Os operadores **>>** de extração **<<** sobrecarregada ( ) e inserção são interfaces convenientes de programação de arquivamento que suportam tanto tipos primitivos quanto `CObject`classes derivadas.

`CArchive`também suporta programação com as classes MFC Windows Sockets [CSocket](../../mfc/reference/csocket-class.md) e [CSocketFile](../../mfc/reference/csocketfile-class.md). A função membro [IsBufferEmpty](#isbufferempty) suporta esse uso.

Para obter `CArchive`mais informações sobre , consulte os artigos [Serialização](../../mfc/serialization-in-mfc.md) e [Soquetes do Windows: Usando soquetes com arquivos](../../mfc/windows-sockets-using-sockets-with-archives.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CArchive`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="carchiveabort"></a><a name="abort"></a>CArchive::Abort

Chame esta função para fechar o arquivo sem abrir uma exceção.

```cpp
void Abort ();
```

### <a name="remarks"></a>Comentários

O `CArchive` destruidor normalmente chamará `Close`, que irá lavar todos os dados `CFile` que não foram salvos no objeto associado. Isso pode causar exceções.

Ao capturar essas exceções, é uma `Abort`boa ideia usar, para `CArchive` que a destruição do objeto não cause mais exceções. Ao lidar com `CArchive::Abort` exceções, não lançará uma exceção sobre `Abort` falhas porque, ao contrário [do CArchive::Close,](#close)ignora falhas.

Se você usou o `CArchive` **novo** para alocar o objeto no heap, então você deve excluí-lo depois de fechar o arquivo.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CArchive::WriteClass](#writeclass).

## <a name="carchivecarchive"></a><a name="carchive"></a>CArchive::CArchive

Constrói um `CArchive` objeto e especifica se ele será usado para carregar ou armazenar objetos.

```
CArchive(
    CFile* pFile,
    UINT nMode,
    int nBufSize = 4096,
    void* lpBuf = NULL);
```

### <a name="parameters"></a>Parâmetros

*Pfile*<br/>
Um ponteiro `CFile` para o objeto que é a fonte final ou destino dos dados persistentes.

*nMode*<br/>
Um sinalizador que especifica se os objetos serão carregados ou armazenados no arquivo. O parâmetro *nMode* deve ter um dos seguintes valores:

- `CArchive::load`Carrega dados do arquivo. Requer `CFile` apenas permissão de leitura.

- `CArchive::store`Salva dados no arquivo. Requer `CFile` permissão de gravação.

- `CArchive::bNoFlushOnDelete`Impede que o arquivo `Flush` seja chamado automaticamente quando o destruidor de arquivos é chamado. Se você definir esta bandeira, você `Close` é responsável por ligar explicitamente antes que o destruidor seja chamado. Se você não fizer isso, seus dados serão corrompidos.

*nBufSize*<br/>
Um inteiro que especifica o tamanho do buffer de arquivo interno, em bytes. Observe que o tamanho do buffer padrão é de 4.096 bytes. Se você arquivar rotineiramente objetos grandes, você melhorará o desempenho se você usar um tamanho de buffer maior que é um múltiplo do tamanho do buffer de arquivo.

*Lpbuf*<br/>
Um ponteiro opcional para um buffer de tamanho *nBufSize*fornecido pelo usuário . Se você não especificar este parâmetro, o arquivo aloca um buffer do heap local e o libera quando o objeto é destruído. O arquivo não libera um buffer fornecido pelo usuário.

### <a name="remarks"></a>Comentários

Você não pode alterar essa especificação depois de ter criado o arquivo.

Você não `CFile` pode usar as operações para alterar o estado do arquivo até que você tenha fechado o arquivo. Qualquer operação desse tipo prejudicará a integridade do arquivo. Você pode acessar a posição do ponteiro do arquivo a qualquer momento durante a serialização, obtendo o objeto de arquivo do arquivo da função [getFile](#getfile) membro e, em seguida, usando a função [CFile::GetPosition.](../../mfc/reference/cfile-class.md#getposition) Você deve chamar [CArchive::Flush](#flush) antes de obter a posição do ponteiro do arquivo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#12](../../mfc/codesnippet/cpp/carchive-class_1.cpp)]

## <a name="carchiveclose"></a><a name="close"></a>CArchive::Fechar

Libera todos os dados restantes no buffer, fecha o arquivo e desconecta o arquivo do arquivo.

```cpp
void Close();
```

### <a name="remarks"></a>Comentários

Não são permitidas mais operações no arquivo. Depois de fechar um arquivo, você pode criar outro arquivo para o mesmo arquivo ou você pode fechar o arquivo.

A função `Close` membro garante que todos os dados sejam transferidos do arquivo para o arquivo e torna o arquivo indisponível. Para concluir a transferência do arquivo para o meio de armazenamento, primeiro `CFile` você deve usar [CFile:::Fechar](../../mfc/reference/cfile-class.md#close) e, em seguida, destruir o objeto.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CArchive::WriteString](#writestring).

## <a name="carchiveflush"></a><a name="flush"></a>CArchive::Flush

Força que quaisquer dados restantes no buffer de arquivo sejam gravados no arquivo.

```cpp
void Flush();
```

### <a name="remarks"></a>Comentários

A função `Flush` membro garante que todos os dados sejam transferidos do arquivo para o arquivo. Você deve chamar [CFile::Close](../../mfc/reference/cfile-class.md#close) para concluir a transferência do arquivo para o meio de armazenamento.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#13](../../mfc/codesnippet/cpp/carchive-class_2.cpp)]

## <a name="carchivegetfile"></a><a name="getfile"></a>CArchive::GetFile

Obtém `CFile` o ponteiro do objeto para este arquivo.

```
CFile* GetFile() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro constante `CFile` para o objeto em uso.

### <a name="remarks"></a>Comentários

Você deve lavar o `GetFile`arquivo antes de usar .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#14](../../mfc/codesnippet/cpp/carchive-class_3.cpp)]

## <a name="carchivegetobjectschema"></a><a name="getobjectschema"></a>CArchive::GetObjectSchema

Chame esta função `Serialize` a partir da função para determinar a versão do objeto que está sendo desserializado no momento.

```
UINT GetObjectSchema();
```

### <a name="return-value"></a>Valor retornado

Durante a desserialização, a versão do objeto está sendo lida.

### <a name="remarks"></a>Comentários

Chamar essa função só `CArchive` é válido quando o objeto está sendo carregado [(CArchive::IsLoading](#isloading) retorna não zero). Deve ser a primeira `Serialize` chamada na função e chamada apenas uma vez. Um valor de retorno de ( UINT)-1 indica que o número da versão é desconhecido.

Uma `CObject`classe derivada pode usar VERSIONABLE_SCHEMA combinada (usando bitwise **OR)** com a própria versão do esquema (na IMPLEMENT_SERIAL macro) `Serialize` para criar um "objeto iversionável", ou seja, um objeto cuja função de membro pode ler várias versões. A funcionalidade de framework padrão (sem VERSIONABLE_SCHEMA) é lançar uma exceção quando a versão é incompatível.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#15](../../mfc/codesnippet/cpp/carchive-class_4.cpp)]

## <a name="carchiveisbufferempty"></a><a name="isbufferempty"></a>CArchive::IsBufferEmpty

Ligue para esta função de membro para determinar se o buffer interno do objeto de arquivamento está vazio.

```
BOOL IsBufferEmpty() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se o buffer do arquivo estiver vazio; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função é fornecida para suportar a programação `CSocketFile`com a classe MFC Windows Sockets . Você não precisa usá-lo para um `CFile` arquivo associado a um objeto.

A razão `IsBufferEmpty` para usar com `CSocketFile` um arquivo associado a um objeto é que o buffer do arquivo pode conter mais de uma mensagem ou registro. Depois de receber uma `IsBufferEmpty` mensagem, você deve usar para controlar um loop que continua recebendo dados até que o buffer esteja vazio. Para obter mais informações, consulte `CAsyncSocket`a função De `IsBufferEmpty` [receber](../../mfc/reference/casyncsocket-class.md#receive) membro da classe, que mostra como usar .

Para obter mais informações, consulte [Soquetes do Windows: Usando soquetes com arquivos](../../mfc/windows-sockets-using-sockets-with-archives.md).

## <a name="carchiveisloading"></a><a name="isloading"></a>CArchive::isLoading

Determina se o arquivo está carregando dados.

```
BOOL IsLoading() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se o arquivo estiver sendo usado para carregamento; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função membro é `Serialize` chamada pelas funções das classes arquivadas.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#16](../../mfc/codesnippet/cpp/carchive-class_5.cpp)]

## <a name="carchiveisstoring"></a><a name="isstoring"></a>CArchive::IsStoring

Determina se o arquivo está armazenando dados.

```
BOOL IsStoring() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se o arquivo estiver sendo usado para armazenar; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função membro é `Serialize` chamada pelas funções das classes arquivadas.

Se `IsStoring` o status de um arquivo `IsLoading` não é zero, então seu status é 0, e vice-versa.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#17](../../mfc/codesnippet/cpp/carchive-class_6.cpp)]

## <a name="carchivemapobject"></a><a name="mapobject"></a>CArchive::MapObject

Chame esta função de membro para colocar objetos no mapa que não são realmente serializados para o arquivo, mas que estão disponíveis para subobjetos para referenciar.

```cpp
void MapObject(const CObject* pOb);
```

### <a name="parameters"></a>Parâmetros

*pOb*<br/>
Um ponteiro constante para o objeto que está sendo armazenado.

### <a name="remarks"></a>Comentários

Por exemplo, você pode não serializar um documento, mas serializar os itens que fazem parte do documento. Ao `MapObject`ligar, você permite que esses itens, ou subobjetos, faça referência ao documento. Além disso, subitens serializados podem serializar seus *m_pDocument* ponteiro traseiro.

Você pode `MapObject` ligar quando armazenar e `CArchive` carregar a partir do objeto. `MapObject`adiciona o objeto especificado às estruturas de `CArchive` dados internas mantidas pelo objeto durante a serialização e desserialização, mas ao contrário de [ReadObject](#readobject) e [WriteObject,](#writeobject)ele não chama serializar no objeto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#18](../../mfc/codesnippet/cpp/carchive-class_7.h)]

[!code-cpp[NVC_MFCSerialization#19](../../mfc/codesnippet/cpp/carchive-class_8.cpp)]

[!code-cpp[NVC_MFCSerialization#20](../../mfc/codesnippet/cpp/carchive-class_9.h)]

[!code-cpp[NVC_MFCSerialization#21](../../mfc/codesnippet/cpp/carchive-class_10.cpp)]

## <a name="carchivem_pdocument"></a><a name="m_pdocument"></a>CArchive::m_pDocument

Definido como NULL por padrão, `CDocument` este ponteiro para um `CArchive` pode ser definido como qualquer coisa que o usuário da instância quiser.

```
CDocument* m_pDocument;
```

### <a name="remarks"></a>Comentários

Um uso comum deste ponteiro é transmitir informações adicionais sobre o processo de serialização para todos os objetos que estão sendo serializados. Isso é conseguido inicializando o ponteiro `CDocument`com o documento (uma classe derivada) que está sendo serializado, de forma que objetos dentro do documento possam acessar o documento, se necessário. Este ponteiro também `COleClientItem` é usado por objetos durante a serialização.

A estrutura define *m_pDocument* para que o documento seja serializado quando um usuário emite um comando File Open ou Save. Se você serializar um documento de contêiner De vinculação e incorporação de objetos (OLE) por razões diferentes de Abrir ou Salvar arquivos, você deve definir explicitamente *m_pDocument*. Por exemplo, você faria isso ao serializar um documento de contêiner na Área de Transferência.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#35](../../mfc/codesnippet/cpp/carchive-class_11.cpp)]

## <a name="carchiveoperator-ltlt"></a><a name="operator_lt_lt"></a>CArchive::operador&lt;&lt;

Armazena o objeto indicado ou o tipo primitivo no arquivo.

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

### <a name="return-value"></a>Valor retornado

Uma `CArchive` referência que permite vários operadores de inserção em uma única linha.

### <a name="remarks"></a>Comentários

As duas últimas versões acima são especificamente para armazenar inteiros de 64 bits.

Se você usou a macro IMPLEMENT_SERIAL na implementação da `CObject` classe, `WriteObject`o operador de inserção sobrecarregou para chamadas protegidas . Esta função, por sua `Serialize` vez, chama a função da classe.

O operador de inserção [CStringT](../../atl-mfc-shared/reference/cstringt-class.md) (<<) suporta dumping diagnóstico e armazenamento em um arquivo.

### <a name="example"></a>Exemplo

Este exemplo demonstra o `CArchive` uso do operador de inserção << com os tipos **int** e **longo.**

[!code-cpp[NVC_MFCSerialization#31](../../mfc/codesnippet/cpp/carchive-class_12.cpp)]

### <a name="example"></a>Exemplo

Este exemplo 2 demonstra `CArchive` o uso do `CStringT` operador de inserção << com o tipo.

[!code-cpp[NVC_MFCSerialization#32](../../mfc/codesnippet/cpp/carchive-class_13.cpp)]

## <a name="carchiveoperator-gtgt"></a><a name="operator_gt_gt"></a>CArchive::operador&gt;&gt;

Carrega o objeto indicado ou o tipo primitivo do arquivo.

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

### <a name="return-value"></a>Valor retornado

Uma `CArchive` referência que permite vários operadores de extração em uma única linha.

### <a name="remarks"></a>Comentários

As duas últimas versões acima são especificamente para carregar inteiros de 64 bits.

Se você usou a macro IMPLEMENT_SERIAL na implementação da `CObject` classe, `ReadObject` os operadores de extração sobrecarregados para chamar a função protegida (com um ponteiro de classe de tempo de execução não zero). Esta função, por sua `Serialize` vez, chama a função da classe.

O operador de extração [CStringT](../../atl-mfc-shared/reference/cstringt-class.md) (>>) suporta o carregamento de um arquivo.

### <a name="example"></a>Exemplo

Este exemplo demonstra o `CArchive` uso do operador de extração >> com o tipo **int.**

[!code-cpp[NVC_MFCSerialization#33](../../mfc/codesnippet/cpp/carchive-class_14.cpp)]

### <a name="example"></a>Exemplo

Este exemplo demonstra o `CArchive` uso dos operadores de inserção e extração <\< e >> com o `CStringT` tipo.

[!code-cpp[NVC_MFCSerialization#34](../../mfc/codesnippet/cpp/carchive-class_15.cpp)]

## <a name="carchiveread"></a><a name="read"></a>CArchive::Leia

Lê um número especificado de bytes do arquivo.

```
UINT Read(void* lpBuf, UINT nMax);
```

### <a name="parameters"></a>Parâmetros

*Lpbuf*<br/>
Um ponteiro para um buffer fornecido pelo usuário que é para receber os dados lidos do arquivo.

*Nmax*<br/>
Um inteiro não assinado especificando o número de bytes a serem lidos no arquivo.

### <a name="return-value"></a>Valor retornado

Um inteiro não assinado contendo o número de bytes realmente lidos. Se o valor de devolução for menor do que o número solicitado, o final do arquivo será alcançado. Nenhuma exceção é lançada na condição de fim de arquivo.

### <a name="remarks"></a>Comentários

O arquivo não interpreta os bytes.

Você pode `Read` usar a `Serialize` função de membro dentro de sua função para ler estruturas comuns que estão contidas em seus objetos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#24](../../mfc/codesnippet/cpp/carchive-class_16.cpp)]

## <a name="carchivereadclass"></a><a name="readclass"></a>CArchive::ReadClass

Chame esta função de membro para ler uma referência a uma classe armazenada anteriormente com [WriteClass](#writeclass).

```
CRuntimeClass* ReadClass(
    const CRuntimeClass* pClassRefRequested = NULL,
    UINT* pSchema = NULL,
    DWORD* pObTag = NULL);
```

### <a name="parameters"></a>Parâmetros

*pClassRefSolicitado*<br/>
Um ponteiro para a estrutura [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que corresponde à referência de classe solicitada. Pode ser NULL.

*pSchema*<br/>
Um ponteiro para um esquema da classe de tempo de execução armazenado anteriormente.

*pObTag*<br/>
Um número que se refere à tag única de um objeto. Usado internamente pela implementação do [ReadObject](#readobject). Exposto apenas para programação avançada; *pObTag* normalmente deve ser NULA.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a estrutura [CRuntimeClass.](../../mfc/reference/cruntimeclass-structure.md)

### <a name="remarks"></a>Comentários

Se *pClassRefRequested* não `ReadClass` for NULL, verifique se as informações da classe arquivada são compatíveis com a sua classe de tempo de execução. Se não for `ReadClass` compatível, lançará um [CArchiveException](../../mfc/reference/carchiveexception-class.md).

Sua classe de tempo de execução deve usar [DECLARE_SERIAL](../../mfc/reference/run-time-object-model-services.md#declare_serial) e [IMPLEMENT_SERIAL;](../../mfc/reference/run-time-object-model-services.md#implement_serial) caso contrário, `ReadClass` lançará uma [CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md).

Se *pSchema* for NULL, o esquema da classe armazenada pode ser recuperado chamando [CArchive::GetObjectSchema](#getobjectschema); caso contrário, <strong>\*</strong> *pSchema* conterá o esquema da classe de tempo de execução que foi armazenado anteriormente.

Você pode usar [SerializeClass](#serializeclass) em vez de `ReadClass`, que lida tanto com a leitura quanto com a escrita da referência de classe.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CArchive::WriteClass](#writeclass).

## <a name="carchivereadobject"></a><a name="readobject"></a>CArchive::ReadObject

Lê dados do objeto do arquivo e constrói um objeto do tipo apropriado.

```
CObject* ReadObject(const CRuntimeClass* pClass);
```

### <a name="parameters"></a>Parâmetros

*pClass*<br/>
Um ponteiro constante para a estrutura [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que corresponde ao objeto que você espera ler.

### <a name="return-value"></a>Valor retornado

Um ponteiro [CObject](../../mfc/reference/cobject-class.md) que deve ser lançado com segurança para a classe derivada correta usando [CObject::IsKindOf](../../mfc/reference/cobject-class.md#iskindof).

### <a name="remarks"></a>Comentários

Esta função é normalmente chamada pelo operador `CArchive` de extração () **>>** sobrecarregado para um ponteiro [CObject.](../../mfc/reference/cobject-class.md) `ReadObject`, por sua `Serialize` vez, chama a função da classe arquivada.

Se você fornecer um parâmetro *pClass* não zero, que é obtido pela [macro RUNTIME_CLASS,](../../mfc/reference/run-time-object-model-services.md#runtime_class) então a função verifica a classe de tempo de execução do objeto arquivado. Isso pressupõe que você tenha usado a macro IMPLEMENT_SERIAL na implementação da classe.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CArchive::WriteObject](#writeobject).

## <a name="carchivereadstring"></a><a name="readstring"></a>CArchive::ReadString

Chame esta função de membro para ler dados de `CArchive` texto em um buffer do arquivo associado ao objeto.

```
BOOL ReadString(CString& rString);
LPTSTR ReadString(LPTSTR lpsz, UINT nMax);
```

### <a name="parameters"></a>Parâmetros

*rString*<br/>
Uma referência a um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que conterá a seqüência resultante após a leitura do arquivo associado ao objeto CArchive.

*Lpsz*<br/>
Especifica um ponteiro para um buffer fornecido pelo usuário que receberá uma seqüência de texto com término nulo.

*Nmax*<br/>
Especifica o número máximo de caracteres a serem lidos. Deve ser um a menos do tamanho do tampão *lpsz.*

### <a name="return-value"></a>Valor retornado

Na versão que retorna BOOL, TRUE se bem sucedida; FALSO de outra forma.

Na versão que `LPTSTR`retorna um , um ponteiro para o buffer contendo os dados de texto; NULA SE o fim do arquivo foi alcançado.

### <a name="remarks"></a>Comentários

Na versão da função de membro com o parâmetro *nMax,* o buffer manterá até um limite de *caracteres nMax* - 1. A leitura é interrompida por um par de ração de linha de retorno da carruagem. Os personagens newline são sempre removidos. Um caractere nulo ('\0') é anexado em ambos os casos.

[CArchive::Read](#read) também está disponível para entrada no modo de texto, mas não termina em um par de feeds de linha de retorno de transporte.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CArchive::WriteString](#writestring).

## <a name="carchiveserializeclass"></a><a name="serializeclass"></a>CArchive::SerializeClass

Ligue para esta função de membro quando quiser armazenar e carregar as informações da versão de uma classe base.

```cpp
void SerializeClass(const CRuntimeClass* pClassRef);
```

### <a name="parameters"></a>Parâmetros

*pClassRef*<br/>
Um ponteiro para um objeto de classe de tempo de execução para a classe base.

### <a name="remarks"></a>Comentários

`SerializeClass`lê ou escreve a referência a `CArchive` uma classe ao objeto, dependendo da direção do `CArchive`. Use `SerializeClass` no lugar de [ReadClass](#readclass) e [WriteClass](#writeclass) como uma maneira conveniente de serializar objetos de classe base; `SerializeClass` requer menos código e menos parâmetros.

Like `ReadClass` `SerializeClass` , verifica se as informações de classe arquivadas são compatíveis com a sua classe de tempo de execução. Se não for `SerializeClass` compatível, lançará um [CArchiveException](../../mfc/reference/carchiveexception-class.md).

Sua classe de tempo de execução deve usar [DECLARE_SERIAL](../../mfc/reference/run-time-object-model-services.md#declare_serial) e [IMPLEMENT_SERIAL;](../../mfc/reference/run-time-object-model-services.md#implement_serial) caso contrário, `SerializeClass` lançará uma [CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md).

Use a [RUNTIME_CLASS](../../mfc/reference/run-time-object-model-services.md#runtime_class) macro para recuperar o valor do parâmetro *pRuntimeClass.* A classe base deve ter usado o [IMPLEMENT_SERIAL](../../mfc/reference/run-time-object-model-services.md#implement_serial) macro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#25](../../mfc/codesnippet/cpp/carchive-class_17.h)]

## <a name="carchivesetloadparams"></a><a name="setloadparams"></a>CArchive::SetLoadParams

Ligue `SetLoadParams` quando você estiver indo `CObject`para ler um grande número de objetos derivados de um arquivo.

```cpp
void SetLoadParams(UINT nGrowBy = 1024);
```

### <a name="parameters"></a>Parâmetros

*nGrowBy*<br/>
O número mínimo de slots de elemento para alocar se for necessário um aumento de tamanho.

### <a name="remarks"></a>Comentários

`CArchive`usa uma matriz de carga para resolver referências a objetos armazenados no arquivo. `SetLoadParams`permite definir o tamanho para o qual a matriz de carga cresce.

Você não `SetLoadParams` deve ligar depois que qualquer objeto for carregado, ou depois que [MapObject](#mapobject) ou [ReadObject](#readobject) for chamado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#26](../../mfc/codesnippet/cpp/carchive-class_18.h)]

## <a name="carchivesetobjectschema"></a><a name="setobjectschema"></a>CArchive::SetObjectSchema

Ligue para esta função de membro para definir o esquema de objeto armazenado no objeto de arquivamento para *nSchema*.

```cpp
void SetObjectSchema(UINT nSchema);
```

### <a name="parameters"></a>Parâmetros

*nSchema*<br/>
Especifica o esquema do objeto.

### <a name="remarks"></a>Comentários

A próxima chamada para [GetObjectSchema](#getobjectschema) devolverá o valor armazenado em *nSchema*.

Uso `SetObjectSchema` para versões avançadas; por exemplo, quando você quiser forçar uma versão `Serialize` específica a ser lida em uma função de uma classe derivada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#27](../../mfc/codesnippet/cpp/carchive-class_19.cpp)]

## <a name="carchivesetstoreparams"></a><a name="setstoreparams"></a>CArchive::SetStoreParams

Use `SetStoreParams` ao armazenar um grande `CObject`número de objetos derivados em um arquivo.

```cpp
void SetStoreParams(UINT nHashSize = 2053, UINT nBlockSize = 128);
```

### <a name="parameters"></a>Parâmetros

*nHashSize*<br/>
O tamanho da tabela hash para mapas de ponteiro de interface. Deve ser um número primo.

*Nblocksize*<br/>
Especifica a granularidade de alocação de memória para estender os parâmetros. Deve ser um poder de 2 para o melhor desempenho.

### <a name="remarks"></a>Comentários

`SetStoreParams`permite definir o tamanho da tabela hash e o tamanho do bloco do mapa usado para identificar objetos únicos durante o processo de serialização.

Você não `SetStoreParams` deve ligar depois que nenhum objeto for armazenado, ou depois [que MapObject](#mapobject) ou [WriteObject](#writeobject) for chamado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#26](../../mfc/codesnippet/cpp/carchive-class_18.h)]

## <a name="carchivewrite"></a><a name="write"></a>CArchive::Write

Grava um número especificado de bytes no arquivo.

```cpp
void Write(const void* lpBuf, INT nMax);
```

### <a name="parameters"></a>Parâmetros

*Lpbuf*<br/>
Um ponteiro para um buffer fornecido pelo usuário que contém os dados a serem gravados no arquivo.

*Nmax*<br/>
Um inteiro que especifica o número de bytes a serem escritos no arquivo.

### <a name="remarks"></a>Comentários

O arquivo não formatar os bytes.

Você pode `Write` usar a `Serialize` função de membro dentro de sua função para escrever estruturas comuns que estão contidas em seus objetos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#23](../../mfc/codesnippet/cpp/carchive-class_20.cpp)]

## <a name="carchivewriteclass"></a><a name="writeclass"></a>CArchive::WriteClass

Use `WriteClass` para armazenar as informações de versão e classe de uma classe base durante a serialização da classe derivada.

```cpp
void WriteClass(const CRuntimeClass* pClassRef);
```

### <a name="parameters"></a>Parâmetros

*pClassRef*<br/>
Um ponteiro para a estrutura [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que corresponde à referência de classe solicitada.

### <a name="remarks"></a>Comentários

`WriteClass`escreve uma referência ao [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) para `CArchive`a classe base para o . Use [CArchive::ReadClass](#readclass) para recuperar a referência.

`WriteClass`verifica se as informações da classe arquivada são compatíveis com sua classe de tempo de execução. Se não for `WriteClass` compatível, lançará um [CArchiveException](../../mfc/reference/carchiveexception-class.md).

Sua classe de tempo de execução deve usar [DECLARE_SERIAL](../../mfc/reference/run-time-object-model-services.md#declare_serial) e [IMPLEMENT_SERIAL;](../../mfc/reference/run-time-object-model-services.md#implement_serial) caso contrário, `WriteClass` lançará uma [CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md).

Você pode usar [SerializeClass](#serializeclass) em vez de `WriteClass`, que lida tanto com a leitura quanto com a escrita da referência de classe.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#28](../../mfc/codesnippet/cpp/carchive-class_21.cpp)]

## <a name="carchivewriteobject"></a><a name="writeobject"></a>CArchive::WriteObject

Armazena o `CObject` especificado para o arquivo.

```cpp
void WriteObject(const CObject* pOb);
```

### <a name="parameters"></a>Parâmetros

*pOb*<br/>
Um ponteiro constante para o objeto que está sendo armazenado.

### <a name="remarks"></a>Comentários

Esta função é normalmente chamada pelo operador de `CArchive` inserção () **<<** sobrecarregado para `CObject`. `WriteObject`, por sua `Serialize` vez, chama a função da classe arquivada.

Você deve usar a macro IMPLEMENT_SERIAL para permitir o arquivamento. `WriteObject`escreve o nome da classe ASCII no arquivo. Esse nome de classe é validado mais tarde durante o processo de carga. Um esquema de codificação especial impede a duplicação desnecessária do nome da classe para vários objetos da classe. Esse esquema também impede o armazenamento redundante de objetos que são alvos de mais de um ponteiro.

O método exato de codificação de objetos (incluindo a presença do nome da classe ASCII) é um detalhe de implementação e pode mudar em versões futuras da biblioteca.

> [!NOTE]
> Termine de criar, excluir e atualizar todos os seus objetos antes de começar a arquivá-los. Seu arquivo será corrompido se você misturar arquivamento com modificação de objeto.

### <a name="example"></a>Exemplo

Para obter uma `CAge`definição da classe, consulte o exemplo [de CObList::CObList](../../mfc/reference/coblist-class.md#coblist).

[!code-cpp[NVC_MFCSerialization#29](../../mfc/codesnippet/cpp/carchive-class_22.cpp)]

## <a name="carchivewritestring"></a><a name="writestring"></a>CArchive::WriteString

Use esta função de membro para gravar dados `CArchive` de um buffer para o arquivo associado ao objeto.

```cpp
void WriteString(LPCTSTR lpsz);
```

### <a name="parameters"></a>Parâmetros

*Lpsz*<br/>
Especifica um ponteiro para um buffer contendo uma seqüência de texto com término nulo.

### <a name="remarks"></a>Comentários

O caractere nulo de terminação ('\0') não está escrito no arquivo; nem uma nova linha é escrita automaticamente.

`WriteString`lança uma exceção em resposta a várias condições, incluindo a condição completa do disco.

`Write`também está disponível, mas ao invés de terminar em um caractere nulo, ele escreve o número solicitado de bytes para o arquivo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#30](../../mfc/codesnippet/cpp/carchive-class_23.cpp)]

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CFile](../../mfc/reference/cfile-class.md)<br/>
[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Classe CSocket](../../mfc/reference/csocket-class.md)<br/>
[Classe CSocketFile](../../mfc/reference/csocketfile-class.md)
