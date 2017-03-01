---
title: Classe CArchive | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CArchive
dev_langs:
- C++
helpviewer_keywords:
- I/O [MFC], archiving objects
- CArchive class
- serialization [C++], CArchive class
- storage [C++], CArchive class
- data storage [C++], CArchive class
ms.assetid: 9e950d23-b874-456e-ae4b-fe00781a7699
caps.latest.revision: 21
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 501b365678a45148aabe638ff341f3ae995e4ab5
ms.lasthandoff: 02/25/2017

---
# <a name="carchive-class"></a>Classe CArchive
Permite que você salve uma rede complexa de objetos em um formato binário permanente (geralmente o armazenamento de disco) que persiste depois que esses objetos são excluídos.  
  
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
|[CArchive::Abort](#abort)|Fecha um arquivo sem lançar uma exceção.|  
|[CArchive::Close](#close)|Libera dados escritos e desconecta o `CFile`.|  
|[CArchive::Flush](#flush)|Libera dados escritos do buffer de arquivo morto.|  
|[CArchive::GetFile](#getfile)|Obtém o `CFile` ponteiro de objeto para este arquivo.|  
|[CArchive::GetObjectSchema](#getobjectschema)|Chamado a partir de `Serialize` função para determinar a versão do objeto que está sendo desserializado.|  
|[CArchive::IsBufferEmpty](#isbufferempty)|Determina se o buffer foi esvaziado durante um Windows Sockets processo de recebimento.|  
|[CArchive::IsLoading](#isloading)|Determina se o arquivo está sendo carregado.|  
|[CArchive::IsStoring](#isstoring)|Determina se o arquivo está armazenando.|  
|[CArchive::MapObject](#mapobject)|Coloca objetos no mapa que não são serializados para o arquivo, mas que estão disponíveis para subobjetos para referência.|  
|[CArchive::Read](#read)|Lê os bytes brutos.|  
|[CArchive::ReadClass](#readclass)|Lê uma referência de classe previamente armazenada com `WriteClass`.|  
|[CArchive::ReadObject](#readobject)|Chama um objeto `Serialize` função para carregamento.|  
|[CArchive::ReadString](#readstring)|Lê uma única linha de texto.|  
|[CArchive::SerializeClass](#serializeclass)|Lê ou grava a referência de classe para o `CArchive` objeto dependendo da direção do `CArchive`.|  
|[CArchive::SetLoadParams](#setloadparams)|Define o tamanho para o qual a matriz de carga aumenta. Deve ser chamado antes que qualquer objeto seja carregado antes ou `MapObject` ou `ReadObject` é chamado.|  
|[CArchive::SetObjectSchema](#setobjectschema)|Define o esquema de objeto armazenado no objeto de arquivo morto.|  
|[CArchive::SetStoreParams](#setstoreparams)|Define o tamanho da tabela de hash e o tamanho do bloco do mapa usado para identificar objetos exclusivos durante o processo de serialização.|  
|[CArchive::Write](#write)|Grava os bytes brutos.|  
|[CArchive::WriteClass](#writeclass)|Grava uma referência para o `CRuntimeClass` para o `CArchive`.|  
|[CArchive::WriteObject](#writeobject)|Chama um objeto `Serialize` função para o armazenamento.|  
|[CArchive::WriteString](#writestring)|Grava uma única linha de texto.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CArchive::operator&lt;&lt;](#operator_lt_lt)|Armazena objetos e tipos primitivos para o arquivo morto.|  
|[CArchive::operator&gt;&gt;](#operator_gt_gt)|Carrega os objetos e tipos primitivos do arquivo morto.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CArchive::m_pDocument](#m_pdocument)||  
  
## <a name="remarks"></a>Comentários  
 `CArchive`não tem uma classe base.  
  
 Mais tarde você pode carregar os objetos de armazenamento persistente, reorganização-los na memória. Esse processo de tornar os dados persistentes é chamado de "serialização".  
  
 Você pode pensar em um objeto de arquivo como um tipo de fluxo binário. Como um fluxo de entrada/saída, um arquivo está associado um arquivo e permite que o buffer de gravação e leitura de dados no armazenamento de. Um fluxo de entrada/saída processa as sequências de caracteres ASCII, mas um arquivo morto processa dados de objeto binário em um formato eficiente e não redundante.  
  
 Você deve criar um [CFile](../../mfc/reference/cfile-class.md) objeto antes de criar um `CArchive` objeto. Além disso, você deve garantir que o status de carga/armazenamento do arquivo é compatível com o modo de abertura do arquivo. Você está limitado a um arquivamento ativo por arquivo.  
  
 Quando você constrói um `CArchive` do objeto, anexá-lo a um objeto da classe `CFile` (ou uma classe derivada) que representa um arquivo aberto. Você também pode especificar se o arquivo será usado para carregar ou armazenar. A `CArchive` objeto pode processar não somente tipos primitivos, mas também objetos do [CObject](../../mfc/reference/cobject-class.md)-projetados para a serialização de classes derivadas. Uma classe serializável normalmente tem um `Serialize` função de membro e geralmente usa a [DECLARE_SERIAL](../../mfc/reference/run-time-object-model-services.md#declare_serial) e [IMPLEMENT_SERIAL](../../mfc/reference/run-time-object-model-services.md#implement_serial) macros, como descrito na classe `CObject`.  
  
 A extração sobrecarregada ( ** >> **) e a inserção ( ** << **) operadores são interfaces de programação de arquivo conveniente que oferecem suporte a ambos os tipos primitivos e `CObject`-classes derivadas.  
  
 `CArchive`também oferece suporte à programação com as classes do MFC Windows Sockets [CSocket](../../mfc/reference/csocket-class.md) e [CSocketFile](../../mfc/reference/csocketfile-class.md). O [IsBufferEmpty](#isbufferempty) função de membro oferece suporte a esse uso.  
  
 Para obter mais informações sobre `CArchive`, consulte os artigos [serialização](../../mfc/serialization-in-mfc.md) e [Windows Sockets: usando soquetes com arquivos mortos](../../mfc/windows-sockets-using-sockets-with-archives.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CArchive`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX. h  
  
##  <a name="a-nameaborta--carchiveabort"></a><a name="abort"></a>CArchive::Abort  
 Chame essa função para fechar o arquivo sem lançar uma exceção.  
  
```  
void Abort ();
```  
  
### <a name="remarks"></a>Comentários  
 O **CArchive** destruidor normalmente chamará **fechar**, que irá liberar todos os dados que não foram salvas associados `CFile` objeto. Isso pode causar exceções.  
  
 Ao capturar essas exceções, é uma boa ideia usar **anular**, de modo que destructing o `CArchive` objeto não faz mais exceções. Quando o tratamento de exceções, `CArchive::Abort` não gerará uma exceção em caso de falha porque, diferentemente [CArchive::Close](#close), **anular** ignora falhas.  
  
 Se você usou **novo** para alocar o `CArchive` do objeto no heap, em seguida, você deve excluí-lo depois de fechar o arquivo.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CArchive::WriteClass](#writeclass).  
  
##  <a name="a-namecarchivea--carchivecarchive"></a><a name="carchive"></a>CArchive::CArchive  
 Constrói um `CArchive` object e especifica se será usada para carregar ou armazenar objetos.  
  
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
 Um sinalizador que especifica se objetos serão carregados a partir do ou armazenados no arquivo morto. O `nMode` parâmetro deve ter um dos seguintes valores:  
  
- **CArchive::load** carrega dados de arquivo morto. Exige apenas `CFile` permissão de leitura.  
  
- **CArchive::store** salva dados no arquivo morto. Requer `CFile` permissão de gravação.  
  
- **CArchive::bNoFlushOnDelete** impede que o arquivo morto automaticamente chamar `Flush` quando o destruidor de arquivo é chamado. Se você definir esse sinalizador, você é responsável por chamar explicitamente **fechar** antes que o destruidor é chamado. Se você não fizer isso, os dados serão corrompidos.  
  
 `nBufSize`  
 Um inteiro que especifica o tamanho do buffer interno de arquivo, em bytes. Observe que o tamanho do buffer padrão é 4.096 bytes. Se você arquivar rotineiramente objetos grandes, você melhorará o desempenho se você usar um tamanho de buffer maior é um múltiplo do tamanho do buffer de arquivo.  
  
 `lpBuf`  
 Um ponteiro opcional para um buffer de tamanho fornecido pelo usuário `nBufSize`. Se você não especificar esse parâmetro, o arquivo morto aloca um buffer de heap local e libera quando o objeto é destruído. O arquivo morto não liberar um buffer fornecido pelo usuário.  
  
### <a name="remarks"></a>Comentários  
 Você não pode alterar essa especificação depois de ter criado o arquivo morto.  
  
 Você não pode usar `CFile` operações de alterar o estado do arquivo até você feche o arquivo morto. Qualquer essa operação pode danificar a integridade do arquivo. Você pode acessar a posição do ponteiro do arquivo a qualquer momento durante a serialização, obtendo o objeto de arquivo do arquivo morto do [GetFile](#getfile) função de membro e, em seguida, usando o [CFile::GetPosition](../../mfc/reference/cfile-class.md#getposition) função. Você deve chamar [CArchive::Flush](#flush) antes de obter a posição do ponteiro do arquivo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCSerialization&#12;](../../mfc/codesnippet/cpp/carchive-class_1.cpp)]  
  
##  <a name="a-nameclosea--carchiveclose"></a><a name="close"></a>CArchive::Close  
 Libera todos os dados restantes no buffer, fecha o arquivo morto e desconecta o arquivo morto do arquivo.  
  
```  
void Close();
```  
  
### <a name="remarks"></a>Comentários  
 Nenhuma outra operação no arquivo morto é permitidas. Depois de fechar um arquivo, você pode criar outro arquivo para o mesmo arquivo ou você pode fechar o arquivo.  
  
 A função de membro **fechar** garante que todos os dados são transferidos do arquivo morto para o arquivo e facilita o arquivamento não está disponível. Para concluir a transferência do arquivo para a mídia de armazenamento, primeiro você deve usar [CFile::Close](../../mfc/reference/cfile-class.md#close) e, em seguida, destrua o `CFile` objeto.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CArchive::WriteString](#writestring).  
  
##  <a name="a-nameflusha--carchiveflush"></a><a name="flush"></a>CArchive::Flush  
 Força todos os dados restantes no buffer de arquivo morto para ser gravado no arquivo.  
  
```  
void Flush();
```  
  
### <a name="remarks"></a>Comentários  
 A função de membro `Flush` garante que todos os dados são transferidos do arquivo morto para o arquivo. Você deve chamar [CFile::Close](../../mfc/reference/cfile-class.md#close) para concluir a transferência do arquivo para a mídia de armazenamento.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCSerialization&13;](../../mfc/codesnippet/cpp/carchive-class_2.cpp)]  
  
##  <a name="a-namegetfilea--carchivegetfile"></a><a name="getfile"></a>CArchive::GetFile  
 Obtém o `CFile` ponteiro de objeto para este arquivo.  
  
```  
CFile* GetFile() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro de constante para o `CFile` objeto em uso.  
  
### <a name="remarks"></a>Comentários  
 Você deve liberar o arquivamento antes de usar `GetFile`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCSerialization&#14;](../../mfc/codesnippet/cpp/carchive-class_3.cpp)]  
  
##  <a name="a-namegetobjectschemaa--carchivegetobjectschema"></a><a name="getobjectschema"></a>CArchive::GetObjectSchema  
 Chamar essa função a partir de `Serialize` função para determinar a versão do objeto que está atualmente sendo desserializado.  
  
```  
UINT GetObjectSchema();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Durante a desserialização, a versão do objeto que está sendo lido.  
  
### <a name="remarks"></a>Comentários  
 Chamar essa função só é válido quando o `CArchive` objeto está sendo carregado ( [CArchive::IsLoading](#isloading) retorna diferente de zero). Ele deve ser a primeira chamada no `Serialize` função e chamada somente uma vez. Um valor de retorno ( **UINT**) –&1; indica que o número de versão é desconhecido.  
  
 A `CObject`-classe derivada pode usar **VERSIONABLE_SCHEMA** combinados (usando o bit a bit `OR`) com a versão de esquema (no `IMPLEMENT_SERIAL` macro) para criar um "objeto de versátil", ou seja, um objeto cujo `Serialize` função de membro pode ler várias versões. A funcionalidade da estrutura padrão (sem **VERSIONABLE_SCHEMA**) é lançar uma exceção quando a versão é incompatível.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCSerialization&#15;](../../mfc/codesnippet/cpp/carchive-class_4.cpp)]  
  
##  <a name="a-nameisbufferemptya--carchiveisbufferempty"></a><a name="isbufferempty"></a>CArchive::IsBufferEmpty  
 Chame essa função de membro para determinar se o buffer interno do objeto do arquivo está vazio.  
  
```  
BOOL IsBufferEmpty() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o buffer do arquivo está vazio. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função é fornecida para dar suporte à programação com a classe do MFC Windows Sockets `CSocketFile`. Você não precisa usá-lo para um arquivo associado com um `CFile` objeto.  
  
 O motivo para usar `IsBufferEmpty` com um arquivo associado com um `CSocketFile` objeto é que o buffer do arquivo pode conter mais de uma mensagem ou registro. Depois de receber uma mensagem, você deve usar `IsBufferEmpty` para controlar um loop que continuará a receber dados até que o buffer está vazio. Para obter mais informações, consulte o [Receive](../../mfc/reference/casyncsocket-class.md#receive) a função de membro da classe `CAsyncSocket`, que mostra como usar `IsBufferEmpty`.  
  
 Para obter mais informações, consulte [Windows Sockets: usando soquetes com arquivos mortos](../../mfc/windows-sockets-using-sockets-with-archives.md).  
  
##  <a name="a-nameisloadinga--carchiveisloading"></a><a name="isloading"></a>CArchive::IsLoading  
 Determina se o arquivo está carregando dados.  
  
```  
BOOL IsLoading() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o arquivo está sendo usado para carregar; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é chamada pelo `Serialize` funções das classes arquivadas.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCSerialization n º&16;](../../mfc/codesnippet/cpp/carchive-class_5.cpp)]  
  
##  <a name="a-nameisstoringa--carchiveisstoring"></a><a name="isstoring"></a>CArchive::IsStoring  
 Determina se o arquivo é armazenar dados.  
  
```  
BOOL IsStoring() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o arquivo está sendo usado atualmente para armazenar; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é chamada pelo `Serialize` funções das classes arquivadas.  
  
 Se o `IsStoring` status de um arquivo é diferente de zero, então seu `IsLoading` status for 0 e vice-versa.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[17 NVC_MFCSerialization](../../mfc/codesnippet/cpp/carchive-class_6.cpp)]  
  
##  <a name="a-namemapobjecta--carchivemapobject"></a><a name="mapobject"></a>CArchive::MapObject  
 Chame essa função de membro para posicionar objetos no mapa do que realmente não são serializados para o arquivo, mas que estão disponíveis para subobjetos para referência.  
  
```  
void MapObject(const CObject* pOb);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pOb`  
 Um ponteiro de constante para o objeto sendo armazenado.  
  
### <a name="remarks"></a>Comentários  
 Por exemplo, você não pode serializar um documento, mas você fosse serializar os itens que fazem parte do documento. Chamando `MapObject`, permitir que os itens ou subobjetos para referenciar o documento. Além disso, os subitens serializadas podem serializar seus `m_pDocument` ponteiro back.  
  
 Você pode chamar `MapObject` quando você armazenar a e carregar a partir do `CArchive` objeto. `MapObject`Adiciona o objeto especificado para as estruturas de dados interno mantidas pelo `CArchive` objeto durante a serialização e desserialização, mas ao contrário de [ReadObject](#readobject) e [WriteObject](#writeobject)**,** não chama serializar o objeto.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCSerialization n º&18;](../../mfc/codesnippet/cpp/carchive-class_7.h)]  
  
 [!code-cpp[19 NVC_MFCSerialization](../../mfc/codesnippet/cpp/carchive-class_8.cpp)]  
  
 [!code-cpp[20 NVC_MFCSerialization](../../mfc/codesnippet/cpp/carchive-class_9.h)]  
  
 [!code-cpp[NVC_MFCSerialization&#21;](../../mfc/codesnippet/cpp/carchive-class_10.cpp)]  
  
##  <a name="a-namempdocumenta--carchivempdocument"></a><a name="m_pdocument"></a>CArchive::m_pDocument  
 Definido como **nulo** por padrão, esse ponteiro para um **CDocument** pode ser definido como qualquer coisa o usuário a `CArchive` desejos de instância.  
  
```  
CDocument* m_pDocument;  
```  
  
### <a name="remarks"></a>Comentários  
 Um uso comum deste ponteiro é transmitir informações adicionais sobre o processo de serialização para todos os objetos que estão sendo serializados. Isso é feito por inicializar o ponteiro com o documento (um **CDocument**-classe derivada) que é serializado, de forma que os objetos dentro do documento podem acessá-lo se necessário. Esse ponteiro também é usado pelo `COleClientItem` objetos durante a serialização.  
  
 Os conjuntos de estrutura `m_pDocument` para o documento que está sendo serializado quando um usuário emite um arquivo abrir ou salvar o comando. Se você serializar um documento de contêiner de vinculação e incorporação de objetos (OLE) por motivos diferentes de abrir arquivo ou salvar, você deve definir explicitamente `m_pDocument`. Por exemplo, você faria isso quando serializar um documento de contêiner na área de transferência.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCSerialization&#35;](../../mfc/codesnippet/cpp/carchive-class_11.cpp)]  
  
##  <a name="a-nameoperatorltlta--carchiveoperator-ltlt"></a><a name="operator_lt_lt"></a>CArchive::operator&lt;&lt;  
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
 As duas últimas versões acima são especificamente para armazenar números inteiros de 64 bits.  
  
 Se você usou o `IMPLEMENT_SERIAL` macro em sua implementação de classe, em seguida, o operador de inserção sobrecarregado para `CObject` chama protegido **WriteObject**. Essa função, por sua vez, chama o `Serialize` função da classe.  
  
 O [CStringT](../../atl-mfc-shared/reference/cstringt-class.md) (de operador de inserção<) supports diagnostic dumping and storing to an archive. supports="" diagnostic="" dumping="" and="" storing="" to="" an=""></) supports diagnostic dumping and storing to an archive.>  
  
### <a name="example"></a>Exemplo  
 Este exemplo demonstra o uso do `CArchive` operador de inserção < with="" the=""> `int` e `long` tipos.  
  
 [!code-cpp[NVC_MFCSerialization&#31;](../../mfc/codesnippet/cpp/carchive-class_12.cpp)]  
  
### <a name="example"></a>Exemplo  
 Este exemplo 2 demonstra o uso do `CArchive` operador de inserção < with="" the=""> `CStringT` tipo.  
  
 [!code-cpp[32 NVC_MFCSerialization](../../mfc/codesnippet/cpp/carchive-class_13.cpp)]  
  
##  <a name="a-nameoperatorgtgta--carchiveoperator-gtgt"></a><a name="operator_gt_gt"></a>CArchive::operator&gt;&gt;  
 Carrega o objeto indicado ou um tipo primitivo do arquivo morto.  
  
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
 As duas últimas versões acima são especificamente para carregar os inteiros de 64 bits.  
  
 Se você usou o `IMPLEMENT_SERIAL` macro em sua implementação de classe e os operadores de extração sobrecarregados para `CObject` chamar protegido **ReadObject** função (com um ponteiro de classe de tempo de execução diferente de zero). Essa função, por sua vez, chama o `Serialize` função da classe.  
  
 O [CStringT](../../atl-mfc-shared/reference/cstringt-class.md) operador de extração (>) oferece suporte ao carregamento de um arquivo.  
  
### <a name="example"></a>Exemplo  
 Este exemplo demonstra o uso do `CArchive` operador de extração >> com o `int` tipo.  
  
 [!code-cpp[33 NVC_MFCSerialization](../../mfc/codesnippet/cpp/carchive-class_14.cpp)]  
  
### <a name="example"></a>Exemplo  
 Este exemplo demonstra o uso do `CArchive` operadores de inserção e extração \< e >> com o `CStringT` tipo.  
  
 [!code-cpp[NVC_MFCSerialization&#34;](../../mfc/codesnippet/cpp/carchive-class_15.cpp)]  
  
##  <a name="a-namereada--carchiveread"></a><a name="read"></a>CArchive::Read  
 Lê um número especificado de bytes do arquivo morto.  
  
```  
UINT Read(void* lpBuf, UINT nMax);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpBuf`  
 Um ponteiro para um buffer fornecido pelo usuário que receberá os dados lidos do arquivo morto.  
  
 `nMax`  
 Um inteiro especificando o número de bytes a serem lidos do arquivo morto.  
  
### <a name="return-value"></a>Valor de retorno  
 Um inteiro sem sinal que contém o número de bytes realmente lidos. Se o valor de retorno for menor que o número solicitado, o final do arquivo foi atingido. Nenhuma exceção é lançada na condição de fim de arquivo.  
  
### <a name="remarks"></a>Comentários  
 O arquivo morto não interpreta os bytes.  
  
 Você pode usar o **leitura** a função de membro dentro de seu `Serialize` função para a leitura de estruturas comuns que estão contidas em seus objetos.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCSerialization&#24;](../../mfc/codesnippet/cpp/carchive-class_16.cpp)]  
  
##  <a name="a-namereadclassa--carchivereadclass"></a><a name="readclass"></a>CArchive::ReadClass  
 Chame essa função de membro para ler uma referência a uma classe previamente armazenada com [WriteClass](#writeclass).  
  
```  
CRuntimeClass* ReadClass(
    const CRuntimeClass* pClassRefRequested = NULL,  
    UINT* pSchema = NULL,  
    DWORD* pObTag = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pClassRefRequested`  
 Um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) estrutura que corresponde à referência da classe solicitada. Pode ser **nulo**.  
  
 `pSchema`  
 Um ponteiro para um esquema da classe de tempo de execução armazenado anteriormente.  
  
 `pObTag`  
 Um número que se refere à marca exclusivo de um objeto. Usado internamente pela implementação do [ReadObject](#readobject). Exposta por programação avançada. `pObTag` normalmente devem ser **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) estrutura.  
  
### <a name="remarks"></a>Comentários  
 Se `pClassRefRequested` não é **nulo**, `ReadClass` verifica se as informações de classe arquivada são compatíveis com a classe de tempo de execução. Se não for compatível, `ReadClass` lançará um [CArchiveException](../../mfc/reference/carchiveexception-class.md).  
  
 Use a classe de tempo de execução [DECLARE_SERIAL](../../mfc/reference/run-time-object-model-services.md#declare_serial) e [IMPLEMENT_SERIAL](../../mfc/reference/run-time-object-model-services.md#implement_serial); caso contrário, `ReadClass` lançará um [CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md).  
  
 Se `pSchema` é **nulo**, o esquema da classe armazenado pode ser recuperado chamando [CArchive::GetObjectSchema](#getobjectschema); caso contrário, ** \* ** `pSchema` conterá o esquema da classe de tempo de execução que foi previamente armazenado.  
  
 Você pode usar [SerializeClass](#serializeclass) em vez de `ReadClass`, que trata de leitura e gravação de referência da classe.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CArchive::WriteClass](#writeclass).  
  
##  <a name="a-namereadobjecta--carchivereadobject"></a><a name="readobject"></a>CArchive::ReadObject  
 Lê dados de objeto do arquivo morto e constrói um objeto do tipo apropriado.  
  
```  
CObject* ReadObject(const CRuntimeClass* pClass);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pClass`  
 Um ponteiro de constante para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) estrutura que corresponde ao objeto que você pretende ler.  
  
### <a name="return-value"></a>Valor de retorno  
 A [CObject](../../mfc/reference/cobject-class.md) ponteiro deve ser convertido com segurança para o correto classe derivada usando [CObject::IsKindOf](../../mfc/reference/cobject-class.md#iskindof).  
  
### <a name="remarks"></a>Comentários  
 Normalmente, essa função é chamada o `CArchive` extração ( ** >> **) operador sobrecarregado para um [CObject](../../mfc/reference/cobject-class.md) ponteiro. **ReadObject**, por sua vez, chama o `Serialize` função da classe arquivada.  
  
 Se você fornecer uma diferente de zero `pClass` parâmetro, que é obtido com a [RUNTIME_CLASS](../../mfc/reference/run-time-object-model-services.md#runtime_class) macro e, em seguida, a função verifica a classe de tempo de execução do objeto arquivado. Isso pressupõe que você usou o `IMPLEMENT_SERIAL` macro na implementação da classe.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CArchive::WriteObject](#writeobject).  
  
##  <a name="a-namereadstringa--carchivereadstring"></a><a name="readstring"></a>CArchive::ReadString  
 Chame essa função de membro para ler dados de texto em um buffer de arquivo associado a `CArchive` objeto.  
  
```  
BOOL ReadString(CString& rString); 
LPTSTR ReadString(LPTSTR lpsz, UINT nMax);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rString`  
 Uma referência a um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que irá conter a cadeia de caracteres resultante depois da leitura do arquivo associado ao objeto CArchive.  
  
 `lpsz`  
 Especifica um ponteiro para um buffer fornecido pelo usuário que receberá uma cadeia de caracteres de texto terminada em nulo.  
  
 `nMax`  
 Especifica o número máximo de caracteres a serem lidos. Deve ser um menor que o tamanho do *lpsz* buffer.  
  
### <a name="return-value"></a>Valor de retorno  
 Na versão que retorna **BOOL**, **TRUE** se bem sucedida; **FALSE** caso contrário.  
  
 Na versão que retorna um `LPTSTR`, um ponteiro para o buffer que contém os dados de texto. **Nulo** se o fim do arquivo foi atingido.  
  
### <a name="remarks"></a>Comentários  
 A versão da função de membro com o `nMax` parâmetro, o buffer será resiste a um limite de `nMax` - 1 caracteres. Leitura foi interrompida por um par de avanço de linha de retorno de carro. Caracteres de nova linha à direita sempre são removidos. Um caractere nulo ('\0') é acrescentado em ambos os casos.  
  
 [CArchive::Read](#read) também está disponível para entrada de modo de texto, mas ele não encerra em um par de avanço de linha de retorno de carro.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CArchive::WriteString](#writestring).  
  
##  <a name="a-nameserializeclassa--carchiveserializeclass"></a><a name="serializeclass"></a>CArchive::SerializeClass  
 Chame essa função de membro para armazenar e carregar as informações de versão de uma classe base.  
  
```  
void SerializeClass(const CRuntimeClass* pClassRef);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pClassRef`  
 Um ponteiro para um objeto de classe de tempo de execução para a classe base.  
  
### <a name="remarks"></a>Comentários  
 `SerializeClass`lê ou grava a referência a uma classe para o `CArchive` objeto, dependendo da direção do `CArchive`. Use `SerializeClass` no lugar de [ReadClass](#readclass) e [WriteClass](#writeclass) como uma maneira conveniente para serializar objetos da classe base. `SerializeClass` requer menos código e menos parâmetros.  
  
 Como `ReadClass`, `SerializeClass` verifica se as informações de classe arquivada são compatíveis com a classe de tempo de execução. Se não for compatível, `SerializeClass` lançará um [CArchiveException](../../mfc/reference/carchiveexception-class.md).  
  
 Use a classe de tempo de execução [DECLARE_SERIAL](../../mfc/reference/run-time-object-model-services.md#declare_serial) e [IMPLEMENT_SERIAL](../../mfc/reference/run-time-object-model-services.md#implement_serial); caso contrário, `SerializeClass` lançará um [CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md).  
  
 Use o [RUNTIME_CLASS](../../mfc/reference/run-time-object-model-services.md#runtime_class) macro para recuperar o valor para o `pRuntimeClass` parâmetro. A classe base deve ter usado o [IMPLEMENT_SERIAL](../../mfc/reference/run-time-object-model-services.md#implement_serial) macro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[25 NVC_MFCSerialization](../../mfc/codesnippet/cpp/carchive-class_17.h)]  
  
##  <a name="a-namesetloadparamsa--carchivesetloadparams"></a><a name="setloadparams"></a>CArchive::SetLoadParams  
 Chamar `SetLoadParams` quando você pretende ler um grande número de `CObject`-objetos derivados de um arquivo.  
  
```  
void SetLoadParams(UINT nGrowBy = 1024);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nGrowBy`  
 O número mínimo de slots de elemento para alocar se um aumento de tamanho é necessário.  
  
### <a name="remarks"></a>Comentários  
 `CArchive`usa uma matriz de carga para resolver referências a objetos armazenados no arquivo morto. `SetLoadParams`permite que você defina o tamanho para o qual a matriz de carga aumenta.  
  
 Você não deve chamar `SetLoadParams` após qualquer objeto é carregado, ou após [MapObject](#mapobject) ou [ReadObject](#readobject) é chamado.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCSerialization&#26;](../../mfc/codesnippet/cpp/carchive-class_18.h)]  
  
##  <a name="a-namesetobjectschemaa--carchivesetobjectschema"></a><a name="setobjectschema"></a>CArchive::SetObjectSchema  
 Chame essa função de membro para definir o esquema de objeto armazenado no objeto de arquivamento para `nSchema`.  
  
```  
void SetObjectSchema(UINT nSchema);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nSchema`  
 Especifica o esquema do objeto.  
  
### <a name="remarks"></a>Comentários  
 A próxima chamada para [GetObjectSchema](#getobjectschema) retornará o valor armazenado no `nSchema`.  
  
 Use `SetObjectSchema` para controle de versão avançada; por exemplo, quando quiser forçar uma versão específica a ser lido em um `Serialize` função de uma classe derivada.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCSerialization&#27;](../../mfc/codesnippet/cpp/carchive-class_19.cpp)]  
  
##  <a name="a-namesetstoreparamsa--carchivesetstoreparams"></a><a name="setstoreparams"></a>CArchive::SetStoreParams  
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
 `SetStoreParams`permite que você defina o tamanho da tabela de hash e o tamanho do bloco do mapa usado para identificar objetos exclusivos durante o processo de serialização.  
  
 Você não deve chamar `SetStoreParams` após todos os objetos são armazenados, ou após [MapObject](#mapobject) ou [WriteObject](#writeobject) é chamado.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCSerialization&#26;](../../mfc/codesnippet/cpp/carchive-class_18.h)]  
  
##  <a name="a-namewritea--carchivewrite"></a><a name="write"></a>CArchive::Write  
 Grava um número especificado de bytes no arquivo morto.  
  
```  
void Write(const void* lpBuf, INT nMax);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpBuf`  
 Um ponteiro para um buffer fornecido pelo usuário que contém os dados a serem gravados no arquivo morto.  
  
 `nMax`  
 Um inteiro que especifica o número de bytes a serem gravados no arquivo morto.  
  
### <a name="remarks"></a>Comentários  
 O arquivo morto não formatará os bytes.  
  
 Você pode usar o **gravar** a função de membro dentro de seu `Serialize` função gravar comum estruturas que estão contidos em seus objetos.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCSerialization&#23;](../../mfc/codesnippet/cpp/carchive-class_20.cpp)]  
  
##  <a name="a-namewriteclassa--carchivewriteclass"></a><a name="writeclass"></a>CArchive::WriteClass  
 Use `WriteClass` para armazenar as informações de versão e a classe de uma classe base durante a serialização da classe derivada.  
  
```  
void WriteClass(const CRuntimeClass* pClassRef);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pClassRef`  
 Um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) estrutura que corresponde à referência da classe solicitada.  
  
### <a name="remarks"></a>Comentários  
 `WriteClass`grava uma referência para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) para a classe base para o `CArchive`. Use [CArchive::ReadClass](#readclass) para recuperar a referência.  
  
 `WriteClass`verifica se as informações de classe arquivada são compatíveis com a classe de tempo de execução. Se não for compatível, `WriteClass` lançará um [CArchiveException](../../mfc/reference/carchiveexception-class.md).  
  
 Use a classe de tempo de execução [DECLARE_SERIAL](../../mfc/reference/run-time-object-model-services.md#declare_serial) e [IMPLEMENT_SERIAL](../../mfc/reference/run-time-object-model-services.md#implement_serial); caso contrário, `WriteClass` lançará um [CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md).  
  
 Você pode usar [SerializeClass](#serializeclass) em vez de `WriteClass`, que trata de leitura e gravação de referência da classe.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCSerialization&#28;](../../mfc/codesnippet/cpp/carchive-class_21.cpp)]  
  
##  <a name="a-namewriteobjecta--carchivewriteobject"></a><a name="writeobject"></a>CArchive::WriteObject  
 Armazena especificado `CObject` para o arquivo morto.  
  
```  
void WriteObject(const CObject* pOb);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pOb`  
 Um ponteiro de constante para o objeto sendo armazenado.  
  
### <a name="remarks"></a>Comentários  
 Normalmente, essa função é chamada o `CArchive` inserção ( ** << **) operador sobrecarregado para `CObject`. **WriteObject**, por sua vez, chama o `Serialize` função da classe arquivada.  
  
 Você deve usar o `IMPLEMENT_SERIAL` macro para ativar o arquivamento. **WriteObject** grava o nome da classe ASCII no arquivo morto. Esse nome de classe é validado durante o processo de carregamento. Um esquema de codificação especial evita a duplicação desnecessária do nome da classe para vários objetos da classe. Esse esquema também impede que o armazenamento com redundância de objetos que são destinos de mais de um ponteiro.  
  
 O objeto exato (incluindo a presença do nome da classe ASCII) do método de codificação é um detalhe de implementação e pode mudar em versões futuras da biblioteca.  
  
> [!NOTE]
>  Terminar de criar, excluir e atualizar todos os objetos antes de começar a arquivá-los. O arquivo seja corrompido caso você misturar arquivamento com a modificação do objeto.  
  
### <a name="example"></a>Exemplo  
 Para obter uma definição da classe `CAge`, consulte o exemplo para [CObList::CObList](../../mfc/reference/coblist-class.md#coblist).  
  
 [!code-cpp[29 NVC_MFCSerialization](../../mfc/codesnippet/cpp/carchive-class_22.cpp)]  
  
##  <a name="a-namewritestringa--carchivewritestring"></a><a name="writestring"></a>CArchive::WriteString  
 Use esta função de membro para gravar dados de um buffer para o arquivo associado a `CArchive` objeto.  
  
```  
void WriteString(LPCTSTR lpsz);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpsz`  
 Especifica um ponteiro para um buffer que contém uma cadeia de caracteres de texto terminada em nulo.  
  
### <a name="remarks"></a>Comentários  
 O caractere nulo de terminação ('\0') não é gravado no arquivo; nem é uma nova linha automaticamente gravada.  
  
 `WriteString`gera uma exceção em resposta a várias condições, como a condição de disco cheio.  
  
 **Gravar** também está disponível, mas em vez de terminação em um caractere nulo, ele grava o número solicitado de bytes no arquivo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[30 NVC_MFCSerialization](../../mfc/codesnippet/cpp/carchive-class_23.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CFile](../../mfc/reference/cfile-class.md)   
 [Classe CObject](../../mfc/reference/cobject-class.md)   
 [Classe CSocket](../../mfc/reference/csocket-class.md)   
 [Classe CSocketFile](../../mfc/reference/csocketfile-class.md)

