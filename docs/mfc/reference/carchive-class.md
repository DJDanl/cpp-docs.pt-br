---
title: Classe CArchive | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f11edef585e699d90d8d33839e0e446cb5a726db
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33357531"
---
# <a name="carchive-class"></a>Classe CArchive
Permite que você salve uma rede complexa de objetos em um formato binário permanente (geralmente o armazenamento em disco) que persiste depois que esses objetos são excluídos.  
  
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
|[CArchive::Close](#close)|Libera os dados não gravados e desconecta o `CFile`.|  
|[CArchive::Flush](#flush)|Libera os dados não gravados do buffer de arquivo morto.|  
|[CArchive::GetFile](#getfile)|Obtém o `CFile` ponteiro de objeto para este arquivo.|  
|[CArchive::GetObjectSchema](#getobjectschema)|Chamado a partir de `Serialize` função para determinar a versão do objeto que está sendo desserializado.|  
|[CArchive::IsBufferEmpty](#isbufferempty)|Determina se o buffer foi esvaziado durante um Windows Sockets receber o processo.|  
|[CArchive::IsLoading](#isloading)|Determina se o arquivo está sendo carregado.|  
|[CArchive::IsStoring](#isstoring)|Determina se o arquivo está armazenando.|  
|[CArchive::MapObject](#mapobject)|Coloca os objetos no mapa que não são serializados para o arquivo, mas que estão disponíveis para subobjetos fazer referência.|  
|[CArchive::Read](#read)|Lê os bytes brutos.|  
|[CArchive::ReadClass](#readclass)|Lê uma referência de classe previamente armazenada com `WriteClass`.|  
|[CArchive::ReadObject](#readobject)|Chama um objeto `Serialize` função para carregamento.|  
|[CArchive::ReadString](#readstring)|Lê uma única linha de texto.|  
|[CArchive::SerializeClass](#serializeclass)|Lê ou grava a referência de classe para o `CArchive` objeto dependendo da direção do `CArchive`.|  
|[CArchive::SetLoadParams](#setloadparams)|Define o tamanho para o qual a matriz de carga aumenta. Deve ser chamado antes de qualquer objeto está carregado ou antes de `MapObject` ou `ReadObject` é chamado.|  
|[CArchive::SetObjectSchema](#setobjectschema)|Define o esquema de objeto armazenado no objeto de arquivo morto.|  
|[CArchive::SetStoreParams](#setstoreparams)|Define o tamanho da tabela de hash e o tamanho do bloco do mapa usado para identificar objetos exclusivos durante o processo de serialização.|  
|[CArchive::Write](#write)|Grava os bytes brutos.|  
|[CArchive::WriteClass](#writeclass)|Grava uma referência para o `CRuntimeClass` para o `CArchive`.|  
|[CArchive::WriteObject](#writeobject)|Chama um objeto `Serialize` função de armazenamento.|  
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
  
 Mais tarde você pode carregar os objetos de armazenamento persistente, reorganização-los na memória. Esse processo de tornar os dados persistentes é chamado de "serialização".  
  
 Você pode pensar em um objeto de arquivo como um tipo de fluxo binário. Como um fluxo de entrada/saída, um arquivo morto está associado um arquivo e permite que o buffer de gravação e leitura de dados para e do armazenamento. Um fluxo de entrada/saída processa as sequências de caracteres ASCII, mas um arquivo morto processa os dados de objeto binário em um formato eficiente e não redundante.  
  
 Você deve criar um [CFile](../../mfc/reference/cfile-class.md) objeto antes de criar um `CArchive` objeto. Além disso, você deve garantir que o status de carregamento/armazenamento do arquivo é compatível com o modo de abertura do arquivo. Você está limitado a um arquivo de ativo por arquivo.  
  
 Quando você cria um `CArchive` do objeto, anexá-lo a um objeto da classe `CFile` (ou uma classe derivada) que representa um arquivo aberto. Você também pode especificar se o arquivo será usado para carregar ou armazenar. Um `CArchive` objeto pode processar não apenas tipos primitivos, mas também objetos de [CObject](../../mfc/reference/cobject-class.md)-projetados para a serialização de classes derivadas. Uma classe serializável normalmente tem um `Serialize` função de membro e geralmente usa a [DECLARE_SERIAL](../../mfc/reference/run-time-object-model-services.md#declare_serial) e [IMPLEMENT_SERIAL](../../mfc/reference/run-time-object-model-services.md#implement_serial) macros, como descrito na classe `CObject`.  
  
 A extração sobrecarregada ( **>>**) e a inserção ( **<<**) operadores são interfaces de programação de arquivo conveniente que dão suporte a ambos os tipos primitivos e `CObject` -classes derivadas.  
  
 `CArchive` também oferece suporte à programação com as classes de Windows Sockets do MFC [CSocket](../../mfc/reference/csocket-class.md) e [CSocketFile](../../mfc/reference/csocketfile-class.md). O [IsBufferEmpty](#isbufferempty) a função de membro oferece suporte a esse uso.  
  
 Para obter mais informações sobre `CArchive`, consulte os artigos [serialização](../../mfc/serialization-in-mfc.md) e [Windows Sockets: usando soquetes com arquivos mortos](../../mfc/windows-sockets-using-sockets-with-archives.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CArchive`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX  
  
##  <a name="abort"></a>  CArchive::Abort  
 Chame essa função para fechar o arquivo sem lançar uma exceção.  
  
```  
void Abort ();
```  
  
### <a name="remarks"></a>Comentários  
 O **CArchive** destruidor normalmente chamará **fechar**, que irá liberar todos os dados que não foram salvas associados `CFile` objeto. Isso pode causar exceções.  
  
 Ao capturar essas exceções, é uma boa ideia usar **anular**, de modo que destructing o `CArchive` objeto não causa mais exceções. Quando o tratamento de exceções, `CArchive::Abort` não gerará uma exceção em falhas porque, diferentemente [CArchive::Close](#close), **anular** ignora falhas.  
  
 Se você usou **novo** para alocar a `CArchive` de objetos no heap, em seguida, você deverá excluí-lo depois de fechar o arquivo.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CArchive::WriteClass](#writeclass).  
  
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
 `pFile`  
 Um ponteiro para o `CFile` objeto que é a fonte definitiva ou o destino dos dados persistentes.  
  
 `nMode`  
 Um sinalizador que especifica se objetos serão carregados a partir ou armazenados no arquivo. O `nMode` parâmetro deve ter um dos seguintes valores:  
  
- **CArchive::load** carrega dados do arquivo morto. Requer apenas `CFile` permissão de leitura.  
  
- **CArchive::store** salva dados para o arquivo morto. Requer `CFile` permissão de gravação.  
  
- **CArchive::bNoFlushOnDelete** impede que o arquivo morto automaticamente chamar `Flush` quando o destruidor de arquivamento é chamado. Se você definir esse sinalizador, você é responsável por chamar explicitamente **fechar** antes do destruidor é chamado. Se você não fizer isso, os dados serão corrompidos.  
  
 `nBufSize`  
 Um inteiro que especifica o tamanho do buffer interno de arquivo, em bytes. Observe que o tamanho do buffer padrão é de 4.096 bytes. Se você rotineiramente arquivar objetos grandes, você melhorará o desempenho se você usar um tamanho de buffer maior do que é um múltiplo do tamanho do buffer de arquivo.  
  
 `lpBuf`  
 Um ponteiro opcional para um buffer fornecido pelo usuário de tamanho `nBufSize`. Se você não especificar esse parâmetro, o arquivo aloca um buffer da pilha local e libera quando o objeto é destruído. O arquivo morto não libera um buffer fornecido pelo usuário.  
  
### <a name="remarks"></a>Comentários  
 Você não pode alterar essa especificação depois de criar o arquivo.  
  
 Você não pode usar `CFile` operações para alterar o estado do arquivo até que o arquivo tenha sido fechado. Qualquer essa operação pode danificar a integridade do arquivo. Você pode acessar a posição do ponteiro do arquivo a qualquer momento durante a serialização obtendo o objeto de arquivo do arquivo do [GetFile](#getfile) função de membro e, em seguida, usando o [CFile::GetPosition](../../mfc/reference/cfile-class.md#getposition) função . Você deve chamar [CArchive::Flush](#flush) antes de obter a posição do ponteiro do arquivo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCSerialization#12](../../mfc/codesnippet/cpp/carchive-class_1.cpp)]  
  
##  <a name="close"></a>  CArchive::Close  
 Libera todos os dados restantes no buffer, fecha o arquivo e desconecta o arquivamento do arquivo.  
  
```  
void Close();
```  
  
### <a name="remarks"></a>Comentários  
 Nenhuma outra operação no arquivo morto é permitidas. Depois de fechar um arquivo morto, você pode criar outro arquivo para o mesmo arquivo ou você pode fechar o arquivo.  
  
 A função de membro **fechar** garante que todos os dados são transferidos do arquivo para o arquivo e torna o arquivo não está disponível. Para concluir a transferência do arquivo para a mídia de armazenamento, primeiro você deve usar [CFile::Close](../../mfc/reference/cfile-class.md#close) e, em seguida, destrua o `CFile` objeto.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CArchive::WriteString](#writestring).  
  
##  <a name="flush"></a>  CArchive::Flush  
 Força todos os dados restantes no buffer de arquivo a ser gravado no arquivo.  
  
```  
void Flush();
```  
  
### <a name="remarks"></a>Comentários  
 A função de membro `Flush` garante que todos os dados são transferidos do arquivo para o arquivo. Você deve chamar [CFile::Close](../../mfc/reference/cfile-class.md#close) para concluir a transferência do arquivo para a mídia de armazenamento.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCSerialization#13](../../mfc/codesnippet/cpp/carchive-class_2.cpp)]  
  
##  <a name="getfile"></a>  CArchive::GetFile  
 Obtém o `CFile` ponteiro de objeto para este arquivo.  
  
```  
CFile* GetFile() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro de constante para o `CFile` objeto em uso.  
  
### <a name="remarks"></a>Comentários  
 Você deve liberar o arquivo antes de usar `GetFile`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCSerialization#14](../../mfc/codesnippet/cpp/carchive-class_3.cpp)]  
  
##  <a name="getobjectschema"></a>  CArchive::GetObjectSchema  
 Chamar essa função do `Serialize` função para determinar a versão do objeto que está atualmente sendo desserializado.  
  
```  
UINT GetObjectSchema();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Durante a desserialização, a versão do objeto que está sendo lido.  
  
### <a name="remarks"></a>Comentários  
 Chamar essa função é válida somente quando o `CArchive` objeto está sendo carregado ( [CArchive::IsLoading](#isloading) retorna zero). Ele deve ser a primeira chamada no `Serialize` função e chamada apenas uma vez. Um valor de retorno ( **UINT**) -1 indica que o número de versão é desconhecido.  
  
 Um `CObject`-classe derivada pode usar **VERSIONABLE_SCHEMA** combinados (usando o bit a bit `OR`) com a versão do esquema (no `IMPLEMENT_SERIAL` macro) para criar um "objeto de versátil", ou seja, um objeto cujo `Serialize` função de membro pode ler várias versões. A funcionalidade de estrutura padrão (sem **VERSIONABLE_SCHEMA**) é lançar uma exceção quando a versão é incompatível.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCSerialization#15](../../mfc/codesnippet/cpp/carchive-class_4.cpp)]  
  
##  <a name="isbufferempty"></a>  CArchive::IsBufferEmpty  
 Chame essa função de membro para determinar se o buffer interno do objeto de arquivo está vazio.  
  
```  
BOOL IsBufferEmpty() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o buffer do arquivo está vazio. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função é fornecida para oferecer suporte a programação com a classe do MFC Windows Sockets `CSocketFile`. Você não precisa usá-lo para um arquivo morto associado com um `CFile` objeto.  
  
 O motivo para usar `IsBufferEmpty` com um arquivo associado com um `CSocketFile` objeto é que o buffer do arquivo pode conter mais de uma mensagem ou registro. Depois de receber uma mensagem, você deve usar `IsBufferEmpty` para controlar um loop que continua a receber dados até que o buffer está vazio. Para obter mais informações, consulte o [Receive](../../mfc/reference/casyncsocket-class.md#receive) função de membro de classe `CAsyncSocket`, que mostra como usar `IsBufferEmpty`.  
  
 Para obter mais informações, consulte [Windows Sockets: usando soquetes com arquivos mortos](../../mfc/windows-sockets-using-sockets-with-archives.md).  
  
##  <a name="isloading"></a>  CArchive::IsLoading  
 Determina se o arquivo está carregando dados.  
  
```  
BOOL IsLoading() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o arquivo está sendo usado para carregar; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é chamada pelo `Serialize` funções das classes arquivadas.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCSerialization#16](../../mfc/codesnippet/cpp/carchive-class_5.cpp)]  
  
##  <a name="isstoring"></a>  CArchive::IsStoring  
 Determina se o arquivo está armazenando dados.  
  
```  
BOOL IsStoring() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o arquivo está sendo usado para armazenar; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é chamada pelo `Serialize` funções das classes arquivadas.  
  
 Se o `IsStoring` status de um arquivo morto é diferente de zero, em seguida, seu `IsLoading` status for 0 e vice-versa.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCSerialization#17](../../mfc/codesnippet/cpp/carchive-class_6.cpp)]  
  
##  <a name="mapobject"></a>  CArchive::MapObject  
 Chame essa função de membro para posicionar objetos no mapa que não são realmente serializados para o arquivo, mas que estão disponíveis para subobjetos para referência.  
  
```  
void MapObject(const CObject* pOb);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pOb`  
 Um ponteiro constante para o objeto que está sendo armazenado.  
  
### <a name="remarks"></a>Comentários  
 Por exemplo, você não pode serializar um documento, mas você fosse serializar os itens que fazem parte do documento. Chamando `MapObject`, permitir que os itens ou subobjetos para referenciar o documento. Além disso, os subitens serializados podem serializar seus `m_pDocument` retorno.  
  
 Você pode chamar `MapObject` quando você armazenar e carregar a partir de `CArchive` objeto. `MapObject` Adiciona o objeto especificado para as estruturas de dados interno mantidas pelo `CArchive` objeto durante a serialização e desserialização, mas ao contrário de [ReadObject](#readobject) e [WriteObject](#writeobject) **,** não chama a serializar no objeto.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCSerialization#18](../../mfc/codesnippet/cpp/carchive-class_7.h)]  
  
 [!code-cpp[NVC_MFCSerialization#19](../../mfc/codesnippet/cpp/carchive-class_8.cpp)]  
  
 [!code-cpp[NVC_MFCSerialization#20](../../mfc/codesnippet/cpp/carchive-class_9.h)]  
  
 [!code-cpp[NVC_MFCSerialization#21](../../mfc/codesnippet/cpp/carchive-class_10.cpp)]  
  
##  <a name="m_pdocument"></a>  CArchive::m_pDocument  
 Definido como **nulo** por padrão, esse ponteiro para um **CDocument** pode ser definido como qualquer usuário da `CArchive` desejos da instância.  
  
```  
CDocument* m_pDocument;  
```  
  
### <a name="remarks"></a>Comentários  
 Um uso comum deste ponteiro é fornecer informações adicionais sobre o processo de serialização para todos os objetos que está sendo serializado. Isso é feito ao inicializar o ponteiro com o documento (um **CDocument**-classe derivada) que está sendo serializada, de forma que os objetos dentro do documento podem acessar o documento, se necessário. Este ponteiro também é usado por `COleClientItem` objetos durante a serialização.  
  
 Os conjuntos de framework `m_pDocument` para o documento que está sendo serializado quando um usuário emite um arquivo abrir ou salvar o comando. Se você serializar um documento de contêiner de vinculação e incorporação (OLE) por razões diferentes de abrir arquivo ou salvar, você deve definir explicitamente `m_pDocument`. Por exemplo, você faria isso ao serializar um documento de contêiner para a área de transferência.  
  
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
 Um `CArchive` referência que permite que vários operadores de inserção em uma única linha.  
  
### <a name="remarks"></a>Comentários  
 As duas últimas versões acima são específicas para armazenar inteiros de 64 bits.  
  
 Se você usou o `IMPLEMENT_SERIAL` macro em sua implementação de classe e, em seguida, o inserção de operador sobrecarregado para `CObject` chama protegido **WriteObject**. Esta função, por sua vez, chama o `Serialize` função da classe.  
  
 O [CStringT](../../atl-mfc-shared/reference/cstringt-class.md) operador de inserção (<<) oferece suporte ao diagnóstico despejo e o armazenamento de um arquivo morto.  
  
### <a name="example"></a>Exemplo  
 Este exemplo demonstra o uso do `CArchive` operador inserção << com o `int` e `long` tipos.  
  
 [!code-cpp[NVC_MFCSerialization#31](../../mfc/codesnippet/cpp/carchive-class_12.cpp)]  
  
### <a name="example"></a>Exemplo  
 Este exemplo 2 demonstra o uso do `CArchive` operador inserção << com o `CStringT` tipo.  
  
 [!code-cpp[NVC_MFCSerialization#32](../../mfc/codesnippet/cpp/carchive-class_13.cpp)]  
  
##  <a name="operator_gt_gt"></a>  CArchive::operator &gt;&gt;  
 Carrega o objeto indicado ou tipo primitivo do arquivo morto.  
  
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
 Um `CArchive` referência que permite que vários operadores de extração em uma única linha.  
  
### <a name="remarks"></a>Comentários  
 As duas últimas versões acima são específicas para carregar inteiros de 64 bits.  
  
 Se você usou o `IMPLEMENT_SERIAL` macro em sua implementação de classe, em seguida, os operadores de extração sobrecarregados para `CObject` chamar protegido **ReadObject** função (com um ponteiro de classe de tempo de execução diferente de zero). Esta função, por sua vez, chama o `Serialize` função da classe.  
  
 O [CStringT](../../atl-mfc-shared/reference/cstringt-class.md) operador extração (>>) dá suporte ao carregamento de um arquivo.  
  
### <a name="example"></a>Exemplo  
 Este exemplo demonstra o uso do `CArchive` operador extração >> com o `int` tipo.  
  
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
 `lpBuf`  
 Um ponteiro para um buffer fornecido pelo usuário que receberá os dados lidos do arquivo morto.  
  
 `nMax`  
 Um inteiro sem sinal especificando o número de bytes a serem lidos do arquivo morto.  
  
### <a name="return-value"></a>Valor de retorno  
 Um inteiro sem sinal que contém o número de bytes realmente lidos. Se o valor de retorno for menor que o número solicitado, o final do arquivo foi atingido. Nenhuma exceção é lançada na condição de fim de arquivo.  
  
### <a name="remarks"></a>Comentários  
 O arquivo morto não interpreta os bytes.  
  
 Você pode usar o **leitura** a função de membro dentro de seu `Serialize` função para a leitura de estruturas comuns que estão contidas em seus objetos.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCSerialization#24](../../mfc/codesnippet/cpp/carchive-class_16.cpp)]  
  
##  <a name="readclass"></a>  CArchive::ReadClass  
 Chamar essa função de membro para ler uma referência a uma classe previamente armazenada com [WriteClass](#writeclass).  
  
```  
CRuntimeClass* ReadClass(
    const CRuntimeClass* pClassRefRequested = NULL,  
    UINT* pSchema = NULL,  
    DWORD* pObTag = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pClassRefRequested`  
 Um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) estrutura que corresponde à referência de classe solicitada. Pode ser **nulo**.  
  
 `pSchema`  
 Um ponteiro para um esquema da classe de tempo de execução armazenado anteriormente.  
  
 `pObTag`  
 Um número que se refere a marcação de um objeto exclusivo. Usado internamente pela implementação de [ReadObject](#readobject). Expostos para programação avançada. `pObTag` normalmente deve ser **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) estrutura.  
  
### <a name="remarks"></a>Comentários  
 Se `pClassRefRequested` não é **nulo**, `ReadClass` verifica se as informações de classe arquivado são compatíveis com a classe de tempo de execução. Se não for compatível, `ReadClass` lançará um [CArchiveException](../../mfc/reference/carchiveexception-class.md).  
  
 Use a classe de tempo de execução [DECLARE_SERIAL](../../mfc/reference/run-time-object-model-services.md#declare_serial) e [IMPLEMENT_SERIAL](../../mfc/reference/run-time-object-model-services.md#implement_serial); caso contrário, `ReadClass` lançará um [CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md).  
  
 Se `pSchema` é **nulo**, o esquema da classe armazenado pode ser recuperado chamando [CArchive::GetObjectSchema](#getobjectschema); caso contrário, **\*** `pSchema`conterá o esquema da classe de tempo de execução que foi armazenado anteriormente.  
  
 Você pode usar [SerializeClass](#serializeclass) em vez de `ReadClass`, que trata de leitura e a gravação da referência de classe.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CArchive::WriteClass](#writeclass).  
  
##  <a name="readobject"></a>  CArchive::ReadObject  
 Lê dados de objeto do arquivo morto e constrói um objeto do tipo apropriado.  
  
```  
CObject* ReadObject(const CRuntimeClass* pClass);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pClass`  
 Um ponteiro de constante para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) estrutura que corresponde ao objeto de espera ler.  
  
### <a name="return-value"></a>Valor de retorno  
 Um [CObject](../../mfc/reference/cobject-class.md) ponteiro deve ser convertido com segurança para o correto classe derivada usando [CObject::IsKindOf](../../mfc/reference/cobject-class.md#iskindof).  
  
### <a name="remarks"></a>Comentários  
 Normalmente, essa função é chamada `CArchive` extração ( **>>**) operador sobrecarregado para um [CObject](../../mfc/reference/cobject-class.md) ponteiro. **ReadObject**, por sua vez, chama o `Serialize` função da classe arquivada.  
  
 Se você fornecer uma diferente de zero `pClass` parâmetro, que é obtido com o [RUNTIME_CLASS](../../mfc/reference/run-time-object-model-services.md#runtime_class) macro e, em seguida, a função verifica a classe de tempo de execução do objeto arquivado. Isso pressupõe que você usou o `IMPLEMENT_SERIAL` macro na implementação da classe.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CArchive::WriteObject](#writeobject).  
  
##  <a name="readstring"></a>  CArchive::ReadString  
 Chamar essa função de membro para ler dados de texto em um buffer de arquivo associado a `CArchive` objeto.  
  
```  
BOOL ReadString(CString& rString); 
LPTSTR ReadString(LPTSTR lpsz, UINT nMax);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rString`  
 Uma referência a um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que irá conter a cadeia de caracteres resultante depois da leitura do arquivo associado ao objeto CArchive.  
  
 `lpsz`  
 Especifica um ponteiro para um buffer fornecido pelo usuário que recebe uma cadeia de caracteres de texto terminada em nulo.  
  
 `nMax`  
 Especifica o número máximo de caracteres a serem lidos. Deve ser um menor que o tamanho do *lpsz* buffer.  
  
### <a name="return-value"></a>Valor de retorno  
 Na versão que retorna **BOOL**, **TRUE** se for bem-sucedida; **FALSE** caso contrário.  
  
 Na versão que retorna um `LPTSTR`, um ponteiro para o buffer que contém os dados de texto. **Nulo** se o final do arquivo atingido.  
  
### <a name="remarks"></a>Comentários  
 A versão da função de membro com o `nMax` parâmetro, o buffer armazenará para um limite de `nMax` - 1 caracteres. Leitura foi interrompida por um par de avanço de linha de retorno de carro. Caracteres de nova linha à direita são sempre removidos. Um caractere nulo ('\0') é acrescentado em ambos os casos.  
  
 [CArchive::Read](#read) também está disponível para entrada de modo de texto, mas não encerra em um par de avanço de linha de retorno de carro.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CArchive::WriteString](#writestring).  
  
##  <a name="serializeclass"></a>  CArchive::SerializeClass  
 Chame essa função de membro para armazenar e carregar as informações de versão de uma classe base.  
  
```  
void SerializeClass(const CRuntimeClass* pClassRef);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pClassRef`  
 Um ponteiro para um objeto de classe de tempo de execução para a classe base.  
  
### <a name="remarks"></a>Comentários  
 `SerializeClass` lê ou grava a referência a uma classe para o `CArchive` objeto, dependendo da direção do `CArchive`. Use `SerializeClass` no lugar de [ReadClass](#readclass) e [WriteClass](#writeclass) como uma maneira conveniente para serializar objetos de classe base. `SerializeClass` requer menos código e menos parâmetros.  
  
 Como `ReadClass`, `SerializeClass` verifica se as informações de classe arquivado são compatíveis com a classe de tempo de execução. Se não for compatível, `SerializeClass` lançará um [CArchiveException](../../mfc/reference/carchiveexception-class.md).  
  
 Use a classe de tempo de execução [DECLARE_SERIAL](../../mfc/reference/run-time-object-model-services.md#declare_serial) e [IMPLEMENT_SERIAL](../../mfc/reference/run-time-object-model-services.md#implement_serial); caso contrário, `SerializeClass` lançará um [CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md).  
  
 Use o [RUNTIME_CLASS](../../mfc/reference/run-time-object-model-services.md#runtime_class) macro para recuperar o valor para o `pRuntimeClass` parâmetro. A classe base deve ter usado o [IMPLEMENT_SERIAL](../../mfc/reference/run-time-object-model-services.md#implement_serial) macro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCSerialization#25](../../mfc/codesnippet/cpp/carchive-class_17.h)]  
  
##  <a name="setloadparams"></a>  CArchive::SetLoadParams  
 Chamar `SetLoadParams` quando você pretende ler um grande número de `CObject`-objetos derivados de um arquivo.  
  
```  
void SetLoadParams(UINT nGrowBy = 1024);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nGrowBy`  
 O número mínimo de slots de elemento para alocar se um aumento de tamanho é necessário.  
  
### <a name="remarks"></a>Comentários  
 `CArchive` usa uma matriz de carga para resolver referências a objetos armazenados no arquivo morto. `SetLoadParams` permite que você defina o tamanho para o qual a matriz de carga aumenta.  
  
 Você não deve chamar `SetLoadParams` depois de qualquer objeto é carregado, ou após [MapObject](#mapobject) ou [ReadObject](#readobject) é chamado.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCSerialization#26](../../mfc/codesnippet/cpp/carchive-class_18.h)]  
  
##  <a name="setobjectschema"></a>  CArchive::SetObjectSchema  
 Chamar essa função de membro para definir o esquema de objeto armazenado no objeto de arquivo para `nSchema`.  
  
```  
void SetObjectSchema(UINT nSchema);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nSchema`  
 Especifica o esquema do objeto.  
  
### <a name="remarks"></a>Comentários  
 A próxima chamada para [GetObjectSchema](#getobjectschema) retornará o valor armazenado na `nSchema`.  
  
 Use `SetObjectSchema` para controle de versão avançada; por exemplo, quando quiser forçar uma versão específica a ser lido em um `Serialize` função de uma classe derivada.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCSerialization#27](../../mfc/codesnippet/cpp/carchive-class_19.cpp)]  
  
##  <a name="setstoreparams"></a>  CArchive::SetStoreParams  
 Use `SetStoreParams` ao armazenar um grande número de `CObject`-derivado objetos em um arquivo morto.  
  
```  
void SetStoreParams(UINT nHashSize = 2053, UINT nBlockSize = 128);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nHashSize*  
 Mapeia o tamanho da tabela de hash para o ponteiro de interface. Deve ser um número primo.  
  
 `nBlockSize`  
 Especifica a granularidade de alocação de memória para estender os parâmetros. Deve ser uma potência de 2 para o melhor desempenho.  
  
### <a name="remarks"></a>Comentários  
 `SetStoreParams` permite que você defina o tamanho da tabela de hash e o tamanho do bloco do mapa usado para identificar objetos exclusivos durante o processo de serialização.  
  
 Você não deve chamar `SetStoreParams` depois que todos os objetos são armazenados, ou após [MapObject](#mapobject) ou [WriteObject](#writeobject) é chamado.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCSerialization#26](../../mfc/codesnippet/cpp/carchive-class_18.h)]  
  
##  <a name="write"></a>  CArchive::Write  
 Grava um número especificado de bytes no arquivo.  
  
```  
void Write(const void* lpBuf, INT nMax);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpBuf`  
 Um ponteiro para um buffer fornecido pelo usuário que contém os dados a serem gravados no arquivo.  
  
 `nMax`  
 Um inteiro que especifica o número de bytes a serem gravados no arquivo.  
  
### <a name="remarks"></a>Comentários  
 O arquivo morto não formatará os bytes.  
  
 Você pode usar o **gravar** a função de membro dentro de seu `Serialize` função gravar comum estruturas que estão contidos em seus objetos.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCSerialization#23](../../mfc/codesnippet/cpp/carchive-class_20.cpp)]  
  
##  <a name="writeclass"></a>  CArchive::WriteClass  
 Use `WriteClass` para armazenar as informações de versão e a classe de uma classe base durante a serialização da classe derivada.  
  
```  
void WriteClass(const CRuntimeClass* pClassRef);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pClassRef`  
 Um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) estrutura que corresponde à referência de classe solicitada.  
  
### <a name="remarks"></a>Comentários  
 `WriteClass` grava uma referência para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) para a classe base para o `CArchive`. Use [CArchive::ReadClass](#readclass) para recuperar a referência.  
  
 `WriteClass` verifica se as informações de classe arquivado são compatíveis com sua classe de tempo de execução. Se não for compatível, `WriteClass` lançará um [CArchiveException](../../mfc/reference/carchiveexception-class.md).  
  
 Use a classe de tempo de execução [DECLARE_SERIAL](../../mfc/reference/run-time-object-model-services.md#declare_serial) e [IMPLEMENT_SERIAL](../../mfc/reference/run-time-object-model-services.md#implement_serial); caso contrário, `WriteClass` lançará um [CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md).  
  
 Você pode usar [SerializeClass](#serializeclass) em vez de `WriteClass`, que trata de leitura e a gravação da referência de classe.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCSerialization#28](../../mfc/codesnippet/cpp/carchive-class_21.cpp)]  
  
##  <a name="writeobject"></a>  CArchive::WriteObject  
 Armazena especificado `CObject` para o arquivo morto.  
  
```  
void WriteObject(const CObject* pOb);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pOb`  
 Um ponteiro constante para o objeto que está sendo armazenado.  
  
### <a name="remarks"></a>Comentários  
 Normalmente, essa função é chamada `CArchive` inserção ( **<<**) operador sobrecarregado para `CObject`. **WriteObject**, por sua vez, chama o `Serialize` função da classe arquivada.  
  
 Você deve usar o `IMPLEMENT_SERIAL` macro para ativar o arquivamento. **WriteObject** grava o nome da classe ASCII para o arquivo morto. Este nome de classe é validado durante o processo de carregamento. Um esquema de codificação especial impede a duplicação desnecessária do nome da classe para vários objetos da classe. Esse esquema também impede que o armazenamento com redundância de objetos que são destinos de mais de um ponteiro.  
  
 O objeto exato (inclusive a presença do nome da classe ASCII) do método de codificação é um detalhe de implementação e pode mudar em versões futuras da biblioteca.  
  
> [!NOTE]
>  Terminar de criar, excluir e atualizar todos os seus objetos antes de começar a arquivá-los. O arquivo morto seja corrompido caso você combinar com a modificação do objeto de arquivamento.  
  
### <a name="example"></a>Exemplo  
 Para obter uma definição da classe `CAge`, consulte o exemplo para [CObList::CObList](../../mfc/reference/coblist-class.md#coblist).  
  
 [!code-cpp[NVC_MFCSerialization#29](../../mfc/codesnippet/cpp/carchive-class_22.cpp)]  
  
##  <a name="writestring"></a>  CArchive::WriteString  
 Use esta função de membro para gravar dados de um buffer para o arquivo associado a `CArchive` objeto.  
  
```  
void WriteString(LPCTSTR lpsz);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpsz`  
 Especifica um ponteiro para um buffer que contém uma cadeia de caracteres de texto terminada em nulo.  
  
### <a name="remarks"></a>Comentários  
 O caractere null de terminação ('\0') não é gravado no arquivo; nem é uma nova linha automaticamente gravada.  
  
 `WriteString` gera uma exceção em resposta a várias condições, como a condição de disco cheio.  
  
 **Gravar** também está disponível, mas em vez de encerrar em um caractere nulo, ele grava o número solicitado de bytes no arquivo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCSerialization#30](../../mfc/codesnippet/cpp/carchive-class_23.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CFile](../../mfc/reference/cfile-class.md)   
 [Classe CObject](../../mfc/reference/cobject-class.md)   
 [Classe CSocket](../../mfc/reference/csocket-class.md)   
 [Classe CSocketFile](../../mfc/reference/csocketfile-class.md)
