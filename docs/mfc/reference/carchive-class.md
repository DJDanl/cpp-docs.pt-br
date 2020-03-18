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
ms.openlocfilehash: 3cf5c3b7a79e846928b5a7ee0af12a3324e141a3
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79418891"
---
# <a name="carchive-class"></a>Classe CArchive

Permite que você salve uma rede complexa de objetos em um formato binário permanente (geralmente o armazenamento em disco) que persiste após a exclusão desses objetos.

## <a name="syntax"></a>Sintaxe

```
class CArchive
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CArchive::CArchive](#carchive)|Cria um objeto `CArchive`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CArchive:: Abort](#abort)|Fecha um arquivo sem gerar uma exceção.|
|[CArchive:: fechar](#close)|Libera dados não gravados e desconecta da `CFile`.|
|[CArchive:: flush](#flush)|Libera dados não gravados do buffer de arquivo morto.|
|[CArchive:: GetFile](#getfile)|Obtém o ponteiro do objeto `CFile` para este arquivo.|
|[CArchive::GetObjectSchema](#getobjectschema)|Chamado da função `Serialize` para determinar a versão do objeto que está sendo desserializado.|
|[CArchive::IsBufferEmpty](#isbufferempty)|Determina se o buffer foi esvaziado durante um processo de recebimento do Windows Sockets.|
|[CArchive:: isuploading](#isloading)|Determina se o arquivo está sendo carregado.|
|[CArchive:: isarmazening](#isstoring)|Determina se o arquivo morto está sendo armazenado.|
|[CArchive::MapObject](#mapobject)|Coloca objetos no mapa que não são serializados para o arquivo, mas que estão disponíveis para referência de subobjetos.|
|[CArchive:: ler](#read)|Lê bytes brutos.|
|[CArchive::ReadClass](#readclass)|Lê uma referência de classe armazenada anteriormente com `WriteClass`.|
|[CArchive:: ReadObject](#readobject)|Chama a função de `Serialize` de um objeto para carregar.|
|[CArchive:: ReadString](#readstring)|Lê uma única linha de texto.|
|[CArchive::SerializeClass](#serializeclass)|Lê ou grava a referência de classe para o objeto `CArchive` dependendo da direção da `CArchive`.|
|[CArchive::SetLoadParams](#setloadparams)|Define o tamanho para o qual a matriz de carga cresce. Deve ser chamado antes de qualquer objeto ser carregado ou antes de `MapObject` ou `ReadObject` ser chamado.|
|[CArchive::SetObjectSchema](#setobjectschema)|Define o esquema de objeto armazenado no objeto de arquivo morto.|
|[CArchive::SetStoreParams](#setstoreparams)|Define o tamanho da tabela de hash e o tamanho do bloco do mapa usado para identificar objetos exclusivos durante o processo de serialização.|
|[CArchive:: Write](#write)|Grava bytes brutos.|
|[CArchive::WriteClass](#writeclass)|Grava uma referência para o `CRuntimeClass` para o `CArchive`.|
|[CArchive:: WriteObject](#writeobject)|Chama a função de `Serialize` de um objeto para armazenar.|
|[CArchive:: WriteString](#writestring)|Grava uma única linha de texto.|

### <a name="public-operators"></a>Operadores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CArchive:: Operator &lt;&lt;](#operator_lt_lt)|Armazena objetos e tipos primitivos para o arquivo morto.|
|[CArchive:: Operator &gt;&gt;](#operator_gt_gt)|Carrega objetos e tipos primitivos do arquivo morto.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CArchive:: m_pDocument](#m_pdocument)||

## <a name="remarks"></a>Comentários

`CArchive` não tem uma classe base.

Posteriormente, você pode carregar os objetos do armazenamento persistente, reconstituição-los na memória. Esse processo de tornar os dados persistentes é chamado de "serialização".

Você pode considerar um objeto de arquivo morto como um tipo de fluxo binário. Como um fluxo de entrada/saída, um arquivo é associado a um arquivo e permite a gravação em buffer e a leitura de dados de e para o armazenamento. Um fluxo de entrada/saída processa sequências de caracteres ASCII, mas um arquivo morto processa dados de objeto binário em um formato eficiente e não redundante.

Você deve criar um objeto [testcfile](../../mfc/reference/cfile-class.md) antes de criar um objeto `CArchive`. Além disso, você deve garantir que o status de carregamento/armazenamento do arquivo seja compatível com o modo aberto do arquivo. Você está limitado a um arquivo ativo por arquivo.

Quando você constrói um objeto `CArchive`, você o anexa a um objeto da classe `CFile` (ou uma classe derivada) que representa um arquivo aberto. Você também especifica se o arquivo será usado para carregar ou armazenar. Um objeto `CArchive` pode processar não apenas tipos primitivos, mas também objetos de classes derivadas de [CObject](../../mfc/reference/cobject-class.md)projetadas para serialização. Uma classe serializável geralmente tem uma função membro `Serialize` e geralmente usa as macros [DECLARE_SERIAL](../../mfc/reference/run-time-object-model-services.md#declare_serial) e [IMPLEMENT_SERIAL](../../mfc/reference/run-time-object-model-services.md#implement_serial) , conforme descrito em classe `CObject`.

Os operadores de extração sobrecarregada ( **>>** ) e de inserção ( **<<** ) são interfaces de programação de arquivo conveniente que dão suporte a tipos primitivos e classes derivadas de `CObject`.

`CArchive` também dá suporte à programação com as classes do MFC Windows Sockets [CSocket](../../mfc/reference/csocket-class.md) e [CSocketFile](../../mfc/reference/csocketfile-class.md). A função membro [IsBufferEmpty](#isbufferempty) dá suporte a esse uso.

Para obter mais informações sobre `CArchive`, consulte os artigos [serialização](../../mfc/serialization-in-mfc.md) e [Windows Sockets: usando soquetes com arquivos mortos](../../mfc/windows-sockets-using-sockets-with-archives.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CArchive`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

##  <a name="abort"></a>CArchive:: Abort

Chame essa função para fechar o arquivo sem gerar uma exceção.

```
void Abort ();
```

### <a name="remarks"></a>Comentários

O destruidor `CArchive` normalmente chamará `Close`, que liberará todos os dados que não foram salvos no objeto `CFile` associado. Isso pode causar exceções.

Ao capturar essas exceções, é uma boa ideia usar `Abort`, para que a destruição do objeto `CArchive` não cause mais exceções. Ao lidar com exceções, `CArchive::Abort` não lançará uma exceção em falhas porque, diferentemente de [CArchive:: Close](#close), `Abort` ignora as falhas.

Se você usou **novo** para alocar o objeto `CArchive` no heap, deverá excluí-lo após fechar o arquivo.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CArchive:: WriteClass](#writeclass).

##  <a name="carchive"></a>CArchive::CArchive

Constrói um objeto `CArchive` e especifica se ele será usado para carregar ou armazenar objetos.

```
CArchive(
    CFile* pFile,
    UINT nMode,
    int nBufSize = 4096,
    void* lpBuf = NULL);
```

### <a name="parameters"></a>parâmetros

*pFile*<br/>
Um ponteiro para o objeto `CFile` que é a origem ou o destino final dos dados persistentes.

*nMode*<br/>
Um sinalizador que especifica se os objetos serão carregados ou armazenados no arquivo morto. O parâmetro *nMode* deve ter um dos seguintes valores:

- `CArchive::load` carrega dados do arquivo morto. Requer apenas `CFile` permissão de leitura.

- `CArchive::store` salva os dados no arquivo morto. Requer `CFile` permissão de gravação.

- `CArchive::bNoFlushOnDelete` impede que o arquivo chame automaticamente `Flush` quando o destruidor de arquivo é chamado. Se você definir esse sinalizador, será responsável por chamar explicitamente `Close` antes de o destruidor ser chamado. Se você não fizer isso, seus dados serão corrompidos.

*nBufSize*<br/>
Um inteiro que especifica o tamanho do buffer de arquivo interno, em bytes. Observe que o tamanho do buffer padrão é 4.096 bytes. Se você arquivar regularmente objetos grandes, você melhorará o desempenho se usar um tamanho de buffer maior que seja um múltiplo do tamanho do buffer de arquivos.

*lpBuf*<br/>
Um ponteiro opcional para um buffer fornecido pelo usuário com o tamanho *nBufSize*. Se você não especificar esse parâmetro, o arquivo alocará um buffer do heap local e o liberará quando o objeto for destruído. O arquivo morto não libera um buffer fornecido pelo usuário.

### <a name="remarks"></a>Comentários

Você não pode alterar essa especificação depois de criar o arquivo morto.

Você não pode usar `CFile` operações para alterar o estado do arquivo até que você tenha fechado o arquivo morto. Qualquer operação desse tipo irá danificar a integridade do arquivo morto. Você pode acessar a posição do ponteiro do arquivo a qualquer momento durante a serialização obtendo o objeto File do arquivo da função de membro [GetFile](#getfile) e, em seguida, usando a função [testcfile:: GetPosition](../../mfc/reference/cfile-class.md#getposition) . Você deve chamar [CArchive:: flush](#flush) antes de obter a posição do ponteiro do arquivo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#12](../../mfc/codesnippet/cpp/carchive-class_1.cpp)]

##  <a name="close"></a>CArchive:: fechar

Libera todos os dados restantes no buffer, fecha o arquivo morto e desconecta o arquivo morto dele.

```
void Close();
```

### <a name="remarks"></a>Comentários

Nenhuma outra operação no arquivo é permitida. Depois de fechar um arquivo morto, você pode criar outro arquivo morto para o mesmo ou pode fechar o arquivo.

A função de membro `Close` garante que todos os dados sejam transferidos do arquivo morto para ele e torna o arquivo indisponível. Para concluir a transferência do arquivo para a mídia de armazenamento, você deve primeiro usar o [testcfile:: fechar](../../mfc/reference/cfile-class.md#close) e, em seguida, destruir o objeto de `CFile`.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CArchive:: WriteString](#writestring).

##  <a name="flush"></a>CArchive:: flush

Força todos os dados restantes no buffer de arquivo a serem gravados no arquivo.

```
void Flush();
```

### <a name="remarks"></a>Comentários

A função de membro `Flush` garante que todos os dados sejam transferidos do arquivo morto para ele. Você deve chamar [testcfile:: Close](../../mfc/reference/cfile-class.md#close) para concluir a transferência do arquivo para o meio de armazenamento.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#13](../../mfc/codesnippet/cpp/carchive-class_2.cpp)]

##  <a name="getfile"></a>CArchive:: GetFile

Obtém o ponteiro do objeto `CFile` para este arquivo.

```
CFile* GetFile() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro constante para o objeto `CFile` em uso.

### <a name="remarks"></a>Comentários

Você deve liberar o arquivo antes de usar `GetFile`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#14](../../mfc/codesnippet/cpp/carchive-class_3.cpp)]

##  <a name="getobjectschema"></a>CArchive::GetObjectSchema

Chame essa função da função `Serialize` para determinar a versão do objeto que está sendo desserializado no momento.

```
UINT GetObjectSchema();
```

### <a name="return-value"></a>Valor retornado

Durante a desserialização, a versão do objeto que está sendo lido.

### <a name="remarks"></a>Comentários

Chamar essa função só é válido quando o objeto `CArchive` está sendo carregado ( [CArchive:: Isuploading](#isloading) retorna zero). Ela deve ser a primeira chamada na função `Serialize` e chamada apenas uma vez. Um valor de retorno de (UINT)-1 indica que o número de versão é desconhecido.

Uma classe derivada de `CObject`pode usar VERSIONABLE_SCHEMA combinado (usando or **bit a**bit) com a própria versão do esquema (na macro IMPLEMENT_SERIAL) para criar um "objeto com controle de versão", ou seja, um objeto cuja função membro `Serialize` possa ler várias versões. A funcionalidade de estrutura padrão (sem VERSIONABLE_SCHEMA) é lançar uma exceção quando a versão é incompatível.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#15](../../mfc/codesnippet/cpp/carchive-class_4.cpp)]

##  <a name="isbufferempty"></a>CArchive::IsBufferEmpty

Chame essa função de membro para determinar se o buffer interno do objeto de arquivo está vazio.

```
BOOL IsBufferEmpty() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o buffer do arquivo estiver vazio; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função é fornecida para dar suporte à programação com a classe `CSocketFile`do MFC Windows Sockets. Você não precisa usá-lo para um arquivo morto associado a um objeto `CFile`.

O motivo para usar `IsBufferEmpty` com um arquivo associado a um objeto `CSocketFile` é que o buffer do arquivo pode conter mais de uma mensagem ou um registro. Depois de receber uma mensagem, você deve usar `IsBufferEmpty` para controlar um loop que continua recebendo dados até que o buffer esteja vazio. Para obter mais informações, consulte a função de membro [Receive](../../mfc/reference/casyncsocket-class.md#receive) da classe `CAsyncSocket`, que mostra como usar `IsBufferEmpty`.

Para obter mais informações, consulte [Windows Sockets: using Sockets with arquivamentos](../../mfc/windows-sockets-using-sockets-with-archives.md).

##  <a name="isloading"></a>CArchive:: isuploading

Determina se o arquivo está carregando dados.

```
BOOL IsLoading() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o arquivo morto estiver sendo usado no momento para carregamento; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função de membro é chamada pelo `Serialize` funções das classes arquivadas.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#16](../../mfc/codesnippet/cpp/carchive-class_5.cpp)]

##  <a name="isstoring"></a>CArchive:: isarmazening

Determina se o arquivo morto está armazenando dados.

```
BOOL IsStoring() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o arquivo morto estiver sendo usado no momento para armazenamento; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função de membro é chamada pelo `Serialize` funções das classes arquivadas.

Se o status de `IsStoring` de um arquivo for diferente de zero, seu status de `IsLoading` será 0, e vice-versa.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#17](../../mfc/codesnippet/cpp/carchive-class_6.cpp)]

##  <a name="mapobject"></a>CArchive::MapObject

Chame essa função de membro para posicionar objetos no mapa que não são realmente serializados para o arquivo, mas que estão disponíveis para referência de subobjetos.

```
void MapObject(const CObject* pOb);
```

### <a name="parameters"></a>parâmetros

*pOb*<br/>
Um ponteiro constante para o objeto que está sendo armazenado.

### <a name="remarks"></a>Comentários

Por exemplo, você pode não serializar um documento, mas serializaria os itens que fazem parte do documento. Ao chamar `MapObject`, você permite que esses itens, ou subobjetos, façam referência ao documento. Além disso, os subitens serializados podem serializar seus *m_pDocument* ponteiros para trás.

Você pode chamar `MapObject` ao armazenar e carregar a partir do objeto `CArchive`. `MapObject` adiciona o objeto especificado às estruturas de dados internas mantidas pelo objeto `CArchive` durante a serialização e desserialização, mas ao contrário de [ReadObject](#readobject) e [WriteObject](#writeobject), ele não chama Serialize no objeto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#18](../../mfc/codesnippet/cpp/carchive-class_7.h)]

[!code-cpp[NVC_MFCSerialization#19](../../mfc/codesnippet/cpp/carchive-class_8.cpp)]

[!code-cpp[NVC_MFCSerialization#20](../../mfc/codesnippet/cpp/carchive-class_9.h)]

[!code-cpp[NVC_MFCSerialization#21](../../mfc/codesnippet/cpp/carchive-class_10.cpp)]

##  <a name="m_pdocument"></a>CArchive:: m_pDocument

Definido como NULL por padrão, esse ponteiro para uma `CDocument` pode ser definido como qualquer coisa que o usuário da instância `CArchive` deseja.

```
CDocument* m_pDocument;
```

### <a name="remarks"></a>Comentários

Um uso comum desse ponteiro é para transmitir informações adicionais sobre o processo de serialização para todos os objetos que estão sendo serializados. Isso é feito inicializando o ponteiro com o documento (uma classe derivada de `CDocument`) que está sendo serializado, de forma que os objetos dentro do documento possam acessar o documento, se necessário. Esse ponteiro também é usado por `COleClientItem` objetos durante a serialização.

A estrutura define *m_pDocument* ao documento que está sendo serializado quando um usuário emite um comando File Open ou Save. Se você serializar um documento de contêiner OLE (vinculação e inserção de objeto) por razões diferentes de abrir ou salvar arquivo, você deverá definir explicitamente *m_pDocument*. Por exemplo, você faria isso ao serializar um documento de contêiner para a área de transferência.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#35](../../mfc/codesnippet/cpp/carchive-class_11.cpp)]

##  <a name="operator_lt_lt"></a>CArchive:: Operator &lt;&lt;

Armazena o objeto indicado ou o tipo primitivo para o arquivo morto.

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

Uma referência `CArchive` que permite vários operadores de inserção em uma única linha.

### <a name="remarks"></a>Comentários

As duas últimas versões acima são especificamente para armazenar inteiros de 64 bits.

Se você usou a macro IMPLEMENT_SERIAL em sua implementação de classe, o operador de inserção está sobrecarregado para `CObject` chama o `WriteObject`protegido. Essa função, por sua vez, chama a função `Serialize` da classe.

O operador de inserção [CStringT](../../atl-mfc-shared/reference/cstringt-class.md) (< <) dá suporte ao despejo de diagnóstico e ao armazenamento em um arquivo morto.

### <a name="example"></a>Exemplo

Este exemplo demonstra o uso do operador de inserção de `CArchive` < < com os tipos **int** e **Long** .

[!code-cpp[NVC_MFCSerialization#31](../../mfc/codesnippet/cpp/carchive-class_12.cpp)]

### <a name="example"></a>Exemplo

Este exemplo 2 demonstra o uso do operador de inserção de `CArchive` < < com o tipo `CStringT`.

[!code-cpp[NVC_MFCSerialization#32](../../mfc/codesnippet/cpp/carchive-class_13.cpp)]

##  <a name="operator_gt_gt"></a>CArchive:: Operator &gt;&gt;

Carrega o objeto indicado ou o tipo primitivo do arquivo morto.

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

Uma referência `CArchive` que habilita vários operadores de extração em uma única linha.

### <a name="remarks"></a>Comentários

As duas últimas versões acima são especificamente para carregar inteiros de 64 bits.

Se você usou a macro IMPLEMENT_SERIAL em sua implementação de classe, os operadores de extração sobrecarregados para `CObject` chamarão a função protegida `ReadObject` (com um ponteiro de classe de tempo de execução diferente de zero). Essa função, por sua vez, chama a função `Serialize` da classe.

O operador de extração [CStringT](../../atl-mfc-shared/reference/cstringt-class.md) (> >) dá suporte ao carregamento de um arquivo morto.

### <a name="example"></a>Exemplo

Este exemplo demonstra o uso do operador de extração de `CArchive` > > com o tipo **int** .

[!code-cpp[NVC_MFCSerialization#33](../../mfc/codesnippet/cpp/carchive-class_14.cpp)]

### <a name="example"></a>Exemplo

Este exemplo demonstra o uso dos operadores de inserção e extração de `CArchive` <\< e > > com o tipo de `CStringT`.

[!code-cpp[NVC_MFCSerialization#34](../../mfc/codesnippet/cpp/carchive-class_15.cpp)]

##  <a name="read"></a>CArchive:: ler

Lê um número especificado de bytes do arquivo morto.

```
UINT Read(void* lpBuf, UINT nMax);
```

### <a name="parameters"></a>parâmetros

*lpBuf*<br/>
Um ponteiro para um buffer fornecido pelo usuário que deve receber os dados lidos do arquivo morto.

*Nmáx*<br/>
Um inteiro sem sinal que especifica o número de bytes a serem lidos do arquivo morto.

### <a name="return-value"></a>Valor retornado

Um inteiro sem sinal contendo o número de bytes realmente lidos. Se o valor de retorno for menor que o número solicitado, o final do arquivo será atingido. Nenhuma exceção é lançada na condição de fim do arquivo.

### <a name="remarks"></a>Comentários

O arquivo morto não interpreta os bytes.

Você pode usar a função membro `Read` dentro de sua função `Serialize` para ler estruturas comuns contidas em seus objetos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#24](../../mfc/codesnippet/cpp/carchive-class_16.cpp)]

##  <a name="readclass"></a>CArchive::ReadClass

Chame essa função de membro para ler uma referência a uma classe armazenada anteriormente com [WriteClass](#writeclass).

```
CRuntimeClass* ReadClass(
    const CRuntimeClass* pClassRefRequested = NULL,
    UINT* pSchema = NULL,
    DWORD* pObTag = NULL);
```

### <a name="parameters"></a>parâmetros

*pClassRefRequested*<br/>
Um ponteiro para a estrutura [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que corresponde à referência de classe solicitada. Pode ser NULL.

*pSchema*<br/>
Um ponteiro para um esquema da classe de tempo de execução armazenado anteriormente.

*pObTag*<br/>
Um número que se refere à marca exclusiva de um objeto. Usado internamente pela implementação de [ReadObject](#readobject). Exposto somente para programação avançada; *pObTag* normalmente deve ser nulo.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a estrutura [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) .

### <a name="remarks"></a>Comentários

Se *pClassRefRequested* não for NULL, `ReadClass` verificará se as informações de classe arquivadas são compatíveis com sua classe de tempo de execução. Se não for compatível, `ReadClass` gerará um [CArchiveException](../../mfc/reference/carchiveexception-class.md).

Sua classe de tempo de execução deve usar [DECLARE_SERIAL](../../mfc/reference/run-time-object-model-services.md#declare_serial) e [IMPLEMENT_SERIAL](../../mfc/reference/run-time-object-model-services.md#implement_serial); caso contrário, `ReadClass` gerará um [CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md).

Se *pSchema* for NULL, o esquema da classe armazenada poderá ser recuperado chamando [CArchive:: GetObjectSchema](#getobjectschema); caso contrário, <strong>\*</strong> *pSchema* conterá o esquema da classe de tempo de execução que foi armazenada anteriormente.

Você pode usar [SerializeClass](#serializeclass) em vez de `ReadClass`, que lida com a leitura e a gravação da referência de classe.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CArchive:: WriteClass](#writeclass).

##  <a name="readobject"></a>CArchive:: ReadObject

Lê dados de objeto do arquivo morto e constrói um objeto do tipo apropriado.

```
CObject* ReadObject(const CRuntimeClass* pClass);
```

### <a name="parameters"></a>parâmetros

*pClass*<br/>
Um ponteiro constante para a estrutura [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que corresponde ao objeto que você espera ler.

### <a name="return-value"></a>Valor retornado

Um ponteiro [CObject](../../mfc/reference/cobject-class.md) que deve ser convertido com segurança na classe derivada correta usando [CObject:: IsKindOf](../../mfc/reference/cobject-class.md#iskindof).

### <a name="remarks"></a>Comentários

Essa função é normalmente chamada pelo operador de extração de `CArchive` ( **>>** ) sobrecarregado para um ponteiro [CObject](../../mfc/reference/cobject-class.md) . `ReadObject`, por sua vez, chama a função `Serialize` da classe arquivada.

Se você fornecer um parâmetro *pClass* diferente de zero, que é obtido pela macro [RUNTIME_CLASS](../../mfc/reference/run-time-object-model-services.md#runtime_class) , a função verificará a classe de tempo de execução do objeto arquivado. Isso pressupõe que você tenha usado a macro IMPLEMENT_SERIAL na implementação da classe.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CArchive:: WriteObject](#writeobject).

##  <a name="readstring"></a>CArchive:: ReadString

Chame essa função de membro para ler dados de texto em um buffer do arquivo associado ao objeto de `CArchive`.

```
BOOL ReadString(CString& rString);
LPTSTR ReadString(LPTSTR lpsz, UINT nMax);
```

### <a name="parameters"></a>parâmetros

*rString*<br/>
Uma referência a uma [CString](../../atl-mfc-shared/reference/cstringt-class.md) que conterá a cadeia de caracteres resultante depois de ser lida do arquivo associado ao objeto CArchive.

*lpsz*<br/>
Especifica um ponteiro para um buffer fornecido pelo usuário que receberá uma cadeia de texto terminada em nulo.

*Nmáx*<br/>
Especifica o número máximo de caracteres a serem lidos. Deve ser um menor que o tamanho do buffer *lpsz* .

### <a name="return-value"></a>Valor retornado

Na versão que retorna BOOL, TRUE se for bem-sucedido; Caso contrário, FALSE.

Na versão que retorna um `LPTSTR`, um ponteiro para o buffer que contém os dados de texto; NULL se o fim do arquivo foi atingido.

### <a name="remarks"></a>Comentários

Na versão da função membro com o parâmetro *nmáx* , o buffer manterá até um limite de *nmáx* -1 caracteres. A leitura é interrompida por um par de retorno de carro-alimentação de linha. Os caracteres de nova linha à direita são sempre removidos. Um caractere nulo (' \ 0 ') é acrescentado em ambos os casos.

[CArchive:: Read](#read) também está disponível para entrada de modo de texto, mas não termina em um par de retorno de carro-alimentação de linha.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CArchive:: WriteString](#writestring).

##  <a name="serializeclass"></a>CArchive::SerializeClass

Chame essa função de membro quando desejar armazenar e carregar as informações de versão de uma classe base.

```
void SerializeClass(const CRuntimeClass* pClassRef);
```

### <a name="parameters"></a>parâmetros

*pClassRef*<br/>
Um ponteiro para um objeto de classe de tempo de execução para a classe base.

### <a name="remarks"></a>Comentários

`SerializeClass` lê ou grava a referência a uma classe no objeto `CArchive`, dependendo da direção da `CArchive`. Use `SerializeClass` no lugar de [ReadClass](#readclass) e [WriteClass](#writeclass) como uma maneira conveniente de serializar objetos de classe base; `SerializeClass` requer menos código e menos parâmetros.

Assim como `ReadClass`, `SerializeClass` verifica se as informações de classe arquivadas são compatíveis com sua classe de tempo de execução. Se não for compatível, `SerializeClass` gerará um [CArchiveException](../../mfc/reference/carchiveexception-class.md).

Sua classe de tempo de execução deve usar [DECLARE_SERIAL](../../mfc/reference/run-time-object-model-services.md#declare_serial) e [IMPLEMENT_SERIAL](../../mfc/reference/run-time-object-model-services.md#implement_serial); caso contrário, `SerializeClass` gerará um [CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md).

Use a macro [RUNTIME_CLASS](../../mfc/reference/run-time-object-model-services.md#runtime_class) para recuperar o valor do parâmetro *pRuntimeClass* . A classe base deve ter usado a macro [IMPLEMENT_SERIAL](../../mfc/reference/run-time-object-model-services.md#implement_serial) .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#25](../../mfc/codesnippet/cpp/carchive-class_17.h)]

##  <a name="setloadparams"></a>CArchive::SetLoadParams

Chame `SetLoadParams` quando você vai ler um grande número de objetos derivados de `CObject`de um arquivo morto.

```
void SetLoadParams(UINT nGrowBy = 1024);
```

### <a name="parameters"></a>parâmetros

*nGrowBy*<br/>
O número mínimo de Slots de elemento a serem alocados se um aumento de tamanho for necessário.

### <a name="remarks"></a>Comentários

`CArchive` usa uma matriz de carga para resolver referências a objetos armazenados no arquivo morto. `SetLoadParams` permite que você defina o tamanho para o qual a matriz de carga cresce.

Você não deve chamar `SetLoadParams` depois que qualquer objeto for carregado ou depois que [MapObject](#mapobject) ou [ReadObject](#readobject) for chamado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#26](../../mfc/codesnippet/cpp/carchive-class_18.h)]

##  <a name="setobjectschema"></a>CArchive::SetObjectSchema

Chame essa função de membro para definir o esquema de objeto armazenado no objeto de arquivo para *nSchema*.

```
void SetObjectSchema(UINT nSchema);
```

### <a name="parameters"></a>parâmetros

*nSchema*<br/>
Especifica o esquema do objeto.

### <a name="remarks"></a>Comentários

A próxima chamada para [GetObjectSchema](#getobjectschema) retornará o valor armazenado em *nSchema*.

Usar `SetObjectSchema` para controle de versão avançado; por exemplo, quando você deseja forçar uma versão específica a ser lida em uma `Serialize` função de uma classe derivada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#27](../../mfc/codesnippet/cpp/carchive-class_19.cpp)]

##  <a name="setstoreparams"></a>CArchive::SetStoreParams

Use `SetStoreParams` ao armazenar um grande número de objetos derivados de `CObject`em um arquivo morto.

```
void SetStoreParams(UINT nHashSize = 2053, UINT nBlockSize = 128);
```

### <a name="parameters"></a>parâmetros

*nHashSize*<br/>
O tamanho da tabela de hash para mapas de ponteiro de interface. Deve ser um número primo.

*nBlockSize*<br/>
Especifica a granularidade de alocação de memória para estender os parâmetros. Deve ser uma potência de 2 para o melhor desempenho.

### <a name="remarks"></a>Comentários

`SetStoreParams` permite que você defina o tamanho da tabela de hash e o tamanho do bloco do mapa usado para identificar objetos exclusivos durante o processo de serialização.

Você não deve chamar `SetStoreParams` depois que quaisquer objetos forem armazenados ou depois que [MapObject](#mapobject) ou [WriteObject](#writeobject) for chamado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#26](../../mfc/codesnippet/cpp/carchive-class_18.h)]

##  <a name="write"></a>CArchive:: Write

Grava um número especificado de bytes no arquivo morto.

```
void Write(const void* lpBuf, INT nMax);
```

### <a name="parameters"></a>parâmetros

*lpBuf*<br/>
Um ponteiro para um buffer fornecido pelo usuário que contém os dados a serem gravados no arquivo morto.

*Nmáx*<br/>
Um inteiro que especifica o número de bytes a serem gravados no arquivo morto.

### <a name="remarks"></a>Comentários

O arquivo morto não formata os bytes.

Você pode usar a função membro `Write` dentro de sua função `Serialize` para escrever estruturas comuns contidas em seus objetos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#23](../../mfc/codesnippet/cpp/carchive-class_20.cpp)]

##  <a name="writeclass"></a>CArchive::WriteClass

Use `WriteClass` para armazenar a versão e as informações de classe de uma classe base durante a serialização da classe derivada.

```
void WriteClass(const CRuntimeClass* pClassRef);
```

### <a name="parameters"></a>parâmetros

*pClassRef*<br/>
Um ponteiro para a estrutura [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que corresponde à referência de classe solicitada.

### <a name="remarks"></a>Comentários

`WriteClass` grava uma referência ao [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) para a classe base para a `CArchive`. Use [CArchive:: ReadClass](#readclass) para recuperar a referência.

`WriteClass` verifica se as informações de classe arquivadas são compatíveis com sua classe de tempo de execução. Se não for compatível, `WriteClass` gerará um [CArchiveException](../../mfc/reference/carchiveexception-class.md).

Sua classe de tempo de execução deve usar [DECLARE_SERIAL](../../mfc/reference/run-time-object-model-services.md#declare_serial) e [IMPLEMENT_SERIAL](../../mfc/reference/run-time-object-model-services.md#implement_serial); caso contrário, `WriteClass` gerará um [CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md).

Você pode usar [SerializeClass](#serializeclass) em vez de `WriteClass`, que lida com a leitura e a gravação da referência de classe.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#28](../../mfc/codesnippet/cpp/carchive-class_21.cpp)]

##  <a name="writeobject"></a>CArchive:: WriteObject

Armazena o `CObject` especificado para o arquivo morto.

```
void WriteObject(const CObject* pOb);
```

### <a name="parameters"></a>parâmetros

*pOb*<br/>
Um ponteiro constante para o objeto que está sendo armazenado.

### <a name="remarks"></a>Comentários

Essa função é normalmente chamada pelo operador de inserção de `CArchive` ( **<<** ) sobrecarregado para `CObject`. `WriteObject`, por sua vez, chama a função `Serialize` da classe arquivada.

Você deve usar a macro IMPLEMENT_SERIAL para habilitar o arquivamento. `WriteObject` grava o nome da classe ASCII no arquivo morto. Esse nome de classe é validado posteriormente durante o processo de carregamento. Um esquema de codificação especial impede a duplicação desnecessária do nome de classe para vários objetos da classe. Esse esquema também impede o armazenamento redundante de objetos que são destinos de mais de um ponteiro.

O método de codificação de objeto exato (incluindo a presença do nome da classe ASCII) é um detalhe de implementação e pode ser alterado em versões futuras da biblioteca.

> [!NOTE]
>  Conclua a criação, a exclusão e a atualização de todos os seus objetos antes de começar a arquivá-los. Seu arquivo será corrompido se você misturar o arquivamento com a modificação do objeto.

### <a name="example"></a>Exemplo

Para obter uma definição da classe `CAge`, consulte o exemplo para [CObList:: CObList](../../mfc/reference/coblist-class.md#coblist).

[!code-cpp[NVC_MFCSerialization#29](../../mfc/codesnippet/cpp/carchive-class_22.cpp)]

##  <a name="writestring"></a>CArchive:: WriteString

Use essa função de membro para gravar dados de um buffer no arquivo associado ao objeto `CArchive`.

```
void WriteString(LPCTSTR lpsz);
```

### <a name="parameters"></a>parâmetros

*lpsz*<br/>
Especifica um ponteiro para um buffer que contém uma cadeia de texto terminada em nulo.

### <a name="remarks"></a>Comentários

O caractere nulo de terminação (' \ 0 ') não é gravado no arquivo; Nem uma nova linha gravada automaticamente.

`WriteString` gera uma exceção em resposta a várias condições, incluindo a condição de disco cheio.

`Write` também está disponível, mas em vez de terminar em um caractere nulo, ele grava o número solicitado de bytes no arquivo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSerialization#30](../../mfc/codesnippet/cpp/carchive-class_23.cpp)]

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CFile](../../mfc/reference/cfile-class.md)<br/>
[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Classe CSocket](../../mfc/reference/csocket-class.md)<br/>
[Classe CSocketFile](../../mfc/reference/csocketfile-class.md)
