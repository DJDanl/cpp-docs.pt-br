---
title: Classe CFile
ms.date: 06/12/2018
f1_keywords:
- CFile
- AFX/CFile
- AFX/CFile::CFile
- AFX/CFile::Abort
- AFX/CFile::Close
- AFX/CFile::Duplicate
- AFX/CFile::Flush
- AFX/CFile::GetFileName
- AFX/CFile::GetFilePath
- AFX/CFile::GetFileTitle
- AFX/CFile::GetLength
- AFX/CFile::GetPosition
- AFX/CFile::GetStatus
- AFX/CFile::LockRange
- AFX/CFile::Open
- AFX/CFile::Read
- AFX/CFile::Remove
- AFX/CFile::Rename
- AFX/CFile::Seek
- AFX/CFile::SeekToBegin
- AFX/CFile::SeekToEnd
- AFX/CFile::SetFilePath
- AFX/CFile::SetLength
- AFX/CFile::SetStatus
- AFX/CFile::UnlockRange
- AFX/CFile::Write
- AFX/CFile::hFileNull
- AFX/CFile::m_hFile
- AFX/CFile::m_pTM
helpviewer_keywords:
- CFile [MFC], CFile
- CFile [MFC], Abort
- CFile [MFC], Close
- CFile [MFC], Duplicate
- CFile [MFC], Flush
- CFile [MFC], GetFileName
- CFile [MFC], GetFilePath
- CFile [MFC], GetFileTitle
- CFile [MFC], GetLength
- CFile [MFC], GetPosition
- CFile [MFC], GetStatus
- CFile [MFC], LockRange
- CFile [MFC], Open
- CFile [MFC], Read
- CFile [MFC], Remove
- CFile [MFC], Rename
- CFile [MFC], Seek
- CFile [MFC], SeekToBegin
- CFile [MFC], SeekToEnd
- CFile [MFC], SetFilePath
- CFile [MFC], SetLength
- CFile [MFC], SetStatus
- CFile [MFC], UnlockRange
- CFile [MFC], Write
- CFile [MFC], hFileNull
- CFile [MFC], m_hFile
- CFile [MFC], m_pTM
ms.assetid: b2eb5757-d499-4e67-b044-dd7d1abaa0f8
ms.openlocfilehash: 4ba37d481db73fb0556659ede267b3474c3f32f5
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373913"
---
# <a name="cfile-class"></a>Classe CFile

A classe base para as classes de arquivos da Microsoft Foundation Class.

## <a name="syntax"></a>Sintaxe

```
class CFile : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Arquivo::CFile](#cfile)|Constrói um `CFile` objeto a partir de um caminho ou alça de arquivo.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CFile::Abortar](#abort)|Fecha um arquivo ignorando todos os avisos e erros.|
|[CFile::Fechar](#close)|Fecha um arquivo e exclui o objeto.|
|[Arquivo::Duplicato](#duplicate)|Constrói um objeto duplicado com base neste arquivo.|
|[CFile::Flush](#flush)|Libera qualquer dado ainda a ser escrito.|
|[CFile::GetFileName](#getfilename)|Recupera o nome do arquivo do arquivo selecionado.|
|[CFile::GetFilePath](#getfilepath)|Recupera o caminho completo do arquivo do arquivo selecionado.|
|[CFile::GetFileTitle](#getfiletitle)|Recupera o título do arquivo selecionado.|
|[Arquivo::GetLength](#getlength)|Recupera o comprimento do arquivo.|
|[CFile::GetPosition](#getposition)|Recupera o ponteiro de arquivo atual.|
|[CFile::GetStatus](#getstatus)|Recupera o status do arquivo aberto, ou na versão estática, recupera o status do arquivo especificado (função estática e virtual).|
|[CFile::LockRange](#lockrange)|Bloqueia uma série de bytes em um arquivo.|
|[Arquivo::Abrir](#open)|Abre um arquivo com segurança com uma opção de teste de erro.|
|[CFile::Read](#read)|Lê dados (não protegidos) de um arquivo na posição atual do arquivo.|
|[Arquivo::Remover](#remove)|Exclui o arquivo especificado (função estática).|
|[CFile::Renomear](#rename)|Renomeia o arquivo especificado (função estática).|
|[CFile::Buscar](#seek)|Posiciona o ponteiro de arquivo atual.|
|[Cfile::SeekToBegin](#seektobegin)|Posiciona o ponteiro de arquivo atual no início do arquivo.|
|[Cfile::SeekToEnd](#seektoend)|Posiciona o ponteiro de arquivo atual no final do arquivo.|
|[Arquivo::SetFilePath](#setfilepath)|Define o caminho completo do arquivo do arquivo selecionado.|
|[arquivo::setLength](#setlength)|Altera o comprimento do arquivo.|
|[Arquivo::SetStatus](#setstatus)|Define o status do arquivo especificado (função estática e virtual).|
|[CFile::UnlockRange](#unlockrange)|Desbloqueia uma série de bytes em um arquivo.|
|[CFile::Write](#write)|Grava dados (não protegidos) em um arquivo para a posição atual do arquivo.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CFile::manipulação do operador](#operator_handle)|Uma alça `CFile` para um objeto.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CFile::hFileNull](#hfilenull)|Determina se `CFile` o objeto tem uma alça válida.|
|[CFile::m_hFile](#m_hfile)|Geralmente contém a alça de arquivo do sistema operacional.|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[Arquivo::m_pTM](#m_ptm)|Ponteiro para o objeto `CAtlTransactionManager`.|

## <a name="remarks"></a>Comentários

Ele fornece diretamente serviços de entrada/saída de disco binários não protegidos e suporta indiretamente arquivos de texto e arquivos de memória através de suas classes derivadas. `CFile`funciona em conjunto `CArchive` com a classe para suportar a serialização de objetos da Classe Microsoft Foundation.

A relação hierárquica entre esta classe e suas classes derivadas `CFile` permite que seu programa opere em todos os objetos de arquivo através da interface polimórfica. Um arquivo de memória, por exemplo, se comporta como um arquivo de disco.

Use `CFile` e suas classes derivadas para I/O de disco de uso geral. Use `ofstream` ou `iostream` outras classes Microsoft para texto formatado enviado a um arquivo de disco.

Normalmente, um arquivo de `CFile` disco é aberto automaticamente na construção e fechado por destruição. As funções de membro estático permitem interrogar o status de um arquivo sem abrir o arquivo.

Para obter mais `CFile`informações sobre o uso, consulte os artigos [Arquivos em MFC](../../mfc/files-in-mfc.md) e [Tratamento de Arquivos](../../c-runtime-library/file-handling.md) na Referência da Biblioteca em Tempo de *Execução*.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

`CFile`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="cfileabort"></a><a name="abort"></a>CFile::Abortar

Fecha o arquivo associado a este objeto e torna o arquivo indisponível para leitura ou escrita.

```
virtual void Abort();
```

### <a name="remarks"></a>Comentários

Se você não fechou o arquivo antes de destruir o objeto, o destruidor fecha-o para você.

Ao lidar com `CFile::Abort` exceções, `CFile::Close` difere de duas maneiras importantes. Primeiro, `Abort` a função não abrirá uma exceção sobre `Abort`falhas, porque as falhas são ignoradas por . Em `Abort` segundo lugar, **não** assert se o arquivo não foi aberto, ou foi fechado anteriormente.

Se você usou o `CFile` **novo** para alocar o objeto no heap, então você deve excluí-lo depois de fechar o arquivo. `Abort``m_hFile` conjuntos `CFile::hFileNull`para .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#5](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_1.cpp)]

## <a name="cfilecfile"></a><a name="cfile"></a>Arquivo::CFile

Constrói e inicializa um objeto `CFile`.

```
CFile();
CFile(CAtlTransactionManager* pTM);
CFile(HANDLE hFile);

CFile(
LPCTSTR lpszFileName,
UINT nOpenFlags);

CFile(
LPCTSTR lpszFileName,
UINT nOpenFlags,
CAtlTransactionManager* pTM);
```

### <a name="parameters"></a>Parâmetros

*Hfile*<br/>
Handle de um arquivo para anexar ao objeto `CFile`.

*lpszFileName*<br/>
Caminho relativo ou completo de um arquivo para anexar ao objeto `CFile`.

*nOpenFlags*<br/>
Combinação bit a bit (OR) das opções de acesso de arquivo do arquivo especificado. Consulte a seção Comentários para obter possíveis opções.

*Ptm*<br/>
Ponteiro para objeto CAtlTransactionManager

### <a name="remarks"></a>Comentários

As cinco tabelas a seguir listam as opções possíveis para o parâmetro *nOpenFlags.*

Escolha apenas uma das opções de modo de acesso de arquivo a seguir. O modo de acesso de arquivo padrão é `CFile::modeRead`, que é somente leitura.

|Valor|Descrição|
|-----------|-----------------|
|`CFile::modeRead`|Solicita acesso somente leitura.|
|`CFile::modeWrite`|Solicita acesso somente gravação.|
|`CFile::modeReadWrite`|Solicita acesso de leitura e gravação.|

Escolha uma das opções de modo de caractere a seguir.

|Valor|Descrição|
|-----------|-----------------|
|`CFile::typeBinary`|Define modo binário (usado apenas em classes derivadas).|
|`CFile::typeText`|Define o modo texto com processamento especial para pares de feeds de linha de retorno de transporte (usado apenas em classes derivadas).|
|`CFile::typeUnicode`|Define modo Unicode (usado apenas em classes derivadas). O texto é gravado no arquivo em formato Unicode quando o aplicativo é compilado em uma configuração Unicode. Nenhum BOM é gravado no arquivo.|

Escolha apenas uma das opções de modo de compartilhamento de arquivo a seguir. O modo de compartilhamento de arquivo padrão é `CFile::shareExclusive`, que é exclusivo.

|Valor|Descrição|
|-----------|-----------------|
|`CFile::shareDenyNone`|Sem restrições de compartilhamento.|
|`CFile::shareDenyRead`|Nega acesso de leitura a todos os outros.|
|`CFile::shareDenyWrite`|Nega acesso de gravação a todos os outros.|
|`CFile::shareExclusive`|Nega acesso de leitura e gravação a todos os outros.|

Escolha a primeira ou as duas opções de modo de criação de arquivo a seguir. O modo de criação padrão é `CFile::modeNoTruncate`, que é abrir existente.

|Valor|Descrição|
|-----------|-----------------|
|`CFile::modeCreate`|Cria um novo arquivo se não houver nenhum arquivo. Se o arquivo já existe, ele é substituído e inicialmente definido como zero comprimento.|
|`CFile::modeNoTruncate`|Cria um novo arquivo se não houver nenhum arquivo; caso contrário, se o arquivo já existe, `CFile` ele está anexado ao objeto.|

Escolha as opções de cache de arquivo conforme descritas a seguir. Por padrão, o sistema usa um esquema de cache de uso geral que não está disponível como opção.

|Valor|Descrição|
|-----------|-----------------|
|`CFile::osNoBuffer`|O sistema não usa um cache intermediário para o arquivo. Esta opção cancela as duas opções a seguir.|
|`CFile::osRandomAccess`|O cache do arquivo é otimizado para acesso aleatório. Não use essa opção e a opção de varredura seqüencial.|
|`CFile::osSequentialScan`|O cache do arquivo é otimizado para acesso sequencial. Não use essa opção e a opção de acesso aleatório.|
|`CFile::osWriteThrough`|As operações de gravação são feitas sem demora.|

Escolha a opção de segurança a seguir para impedir que o handle do arquivo seja herdado. Por padrão, qualquer novo processo filho pode usar o handle do arquivo.

|Valor|Descrição|
|-----------|-----------------|
|`CFile::modeNoInherit`|Impede qualquer processo filho de usar o handle do arquivo.|

O construtor padrão inicializa membros, mas não anexa `CFile` um arquivo ao objeto. Depois de usar este construtor, use o método [CFile::Open](#open) `CFile` para abrir um arquivo e anexá-lo ao objeto.

O construtor com um parâmetro inicializa membros e anexa um arquivo existente ao objeto `CFile`.

O construtor com dois parâmetros inicializa membros e tenta abrir o arquivo especificado. Se o construtor abrir o arquivo especificado com sucesso, o arquivo será anexado ao objeto `CFile`; caso contrário, o construtor lança um ponteiro para um objeto `CInvalidArgException`. Para obter mais informações sobre como lidar com exceções, consulte [Exceções](../../mfc/exception-handling-in-mfc.md).

Se `CFile` um objeto abrir com sucesso um arquivo especificado, `CFile` ele fechará esse arquivo automaticamente quando o objeto for destruído; caso contrário, você deve fechar explicitamente o arquivo depois que `CFile` ele não estiver mais anexado ao objeto.

### <a name="example"></a>Exemplo

O código a seguir mostra como usar um `CFile`.

[!code-cpp[NVC_MFCFiles#4](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_2.cpp)]

## <a name="cfileclose"></a><a name="close"></a>CFile::Fechar

Fecha o arquivo associado a este objeto e torna o arquivo indisponível para leitura ou escrita.

```
virtual void Close();
```

### <a name="remarks"></a>Comentários

Se você não fechou o arquivo antes de destruir o objeto, o destruidor fecha-o para você.

Se você usou o `CFile` **novo** para alocar o objeto no heap, então você deve excluí-lo depois de fechar o arquivo. `Close``m_hFile` conjuntos `CFile::hFileNull`para .

### <a name="example"></a>Exemplo

Veja o exemplo de [CFile::CFile](#cfile).

## <a name="cfileduplicate"></a><a name="duplicate"></a>Arquivo::Duplicato

Constrói um `CFile` objeto duplicado para um determinado arquivo.

```
virtual CFile* Duplicate() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para `CFile` um objeto duplicado.

### <a name="remarks"></a>Comentários

Esta função é equivalente à função `_dup`C run-time .

## <a name="cfileflush"></a><a name="flush"></a>CFile::Flush

Força que quaisquer dados restantes no buffer de arquivo sejam gravados no arquivo.

```
virtual void Flush();
```

### <a name="remarks"></a>Comentários

O uso `Flush` de não garante `CArchive` descarga de tampões. Se você estiver usando um arquivo, ligue para [CArchive:::Flush](../../mfc/reference/carchive-class.md#flush) primeiro.

### <a name="example"></a>Exemplo

Veja o exemplo de [CFile::SetFilePath](#setfilepath).

## <a name="cfilegetfilename"></a><a name="getfilename"></a>CFile::GetFileName

Ligue para esta função de membro para recuperar o nome de um arquivo especificado.

```
virtual CString GetFileName() const;
```

### <a name="return-value"></a>Valor retornado

O nome do arquivo.

### <a name="remarks"></a>Comentários

Por exemplo, quando `GetFileName` você liga para gerar uma `c:\windows\write\myfile.wri`mensagem ao `myfile.wri`usuário sobre o arquivo , o nome do arquivo, é retornado.

Para retornar todo o caminho do arquivo, incluindo o nome, chame [GetFilePath](#getfilepath). Para retornar o título `myfile`do arquivo (), ligue [para GetFileTitle](#getfiletitle).

### <a name="example"></a>Exemplo

Este fragmento de código abre o SISTEMA. Arquivo INI em seu diretório WINDOWS. Se encontrado, o exemplo imprimirá o nome e o caminho e o título, conforme mostrado em Saída:

[!code-cpp[NVC_MFCFiles#6](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_3.cpp)]

## <a name="cfilegetfilepath"></a><a name="getfilepath"></a>CFile::GetFilePath

Ligue para esta função de membro para recuperar o caminho completo de um arquivo especificado.

```
virtual CString GetFilePath() const;
```

### <a name="return-value"></a>Valor retornado

O caminho completo do arquivo especificado.

### <a name="remarks"></a>Comentários

Por exemplo, quando `GetFilePath` você liga para gerar uma `c:\windows\write\myfile.wri`mensagem ao `c:\windows\write\myfile.wri`usuário sobre o arquivo , o caminho do arquivo, é retornado.

Para retornar apenas o nome`myfile.wri`do arquivo (), ligue [para GetFileName](#getfilename). Para retornar o título`myfile`do arquivo (), ligue [para GetFileTitle](#getfiletitle).

### <a name="example"></a>Exemplo

Veja o exemplo de [GetFileName](#getfilename).

## <a name="cfilegetfiletitle"></a><a name="getfiletitle"></a>CFile::GetFileTitle

Chame esta função de membro para recuperar o título do arquivo (o nome do display) para o arquivo.

```
virtual CString GetFileTitle() const;
```

### <a name="return-value"></a>Valor retornado

O título do arquivo subjacente.

### <a name="remarks"></a>Comentários

Este método chama [GetFileTitle](/windows/win32/api/commdlg/nf-commdlg-getfiletitlew) para recuperar o título do arquivo. Se for bem sucedido, o método retorna a string que o sistema usaria para exibir o nome do arquivo para o usuário. Caso contrário, o método chama [PathFindFileName](/windows/win32/api/shlwapi/nf-shlwapi-pathfindfilenamew) para recuperar o nome do arquivo (incluindo a extensão do arquivo) do arquivo subjacente. Isso significa que a extensão do arquivo nem sempre está incluída na seqüência de título do arquivo retornado. Para obter mais informações, consulte [GetFileTitle](/windows/win32/api/commdlg/nf-commdlg-getfiletitlew) e [PathFindFileName](/windows/win32/api/shlwapi/nf-shlwapi-pathfindfilenamew) no Windows SDK.

Para retornar todo o caminho do arquivo, incluindo o nome, chame [GetFilePath](#getfilepath). Para retornar apenas o nome do arquivo, ligue para [GetFileName](#getfilename).

### <a name="example"></a>Exemplo

Veja o exemplo de [GetFileName](#getfilename).

## <a name="cfilegetlength"></a><a name="getlength"></a>Arquivo::GetLength

Obtém o comprimento lógico atual do arquivo em bytes.

```
virtual ULONGLONG GetLength() const;
```

### <a name="return-value"></a>Valor retornado

O comprimento do arquivo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#7](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_4.cpp)]

## <a name="cfilegetposition"></a><a name="getposition"></a>CFile::GetPosition

Obtém o valor atual do ponteiro de arquivo, `Seek`que pode ser usado em chamadas posteriores para .

```
virtual ULONGLONG GetPosition() const;
```

### <a name="return-value"></a>Valor retornado

O ponteiro do arquivo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#8](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_5.cpp)]

## <a name="cfilegetstatus"></a><a name="getstatus"></a>CFile::GetStatus

Este método recupera informações de `CFile` status relacionadas a uma determinada instância de objeto ou a um determinado caminho de arquivo.

```
BOOL GetStatus(CFileStatus& rStatus) const;

static BOOL PASCAL GetStatus(
    LPCTSTR lpszFileName,
    CFileStatus& rStatus,
    CAtlTransactionManager* pTM = NULL);
```

### <a name="parameters"></a>Parâmetros

*rStatus*<br/>
Uma referência a uma `CFileStatus` estrutura fornecida pelo usuário que receberá as informações de status. A `CFileStatus` estrutura possui os seguintes campos:

- `CTime m_ctime`A data e a hora em que o arquivo foi criado.

- `CTime m_mtime`A data e a hora em que o arquivo foi modificado pela última vez.

- `CTime m_atime`A data e a hora em que o arquivo foi acessado pela última vez para leitura.

- `ULONGLONG m_size`O tamanho lógico do arquivo em bytes, conforme relatado pelo comando DIR.

- `BYTE m_attribute`O byte de atributo do arquivo.

- `char m_szFullName[_MAX_PATH]`O nome de arquivo absoluto no conjunto de caracteres do Windows.

*lpszFileName*<br/>
Uma seqüência de caracteres do Windows definida que é o caminho para o arquivo desejado. O caminho pode ser relativo ou absoluto, ou pode conter um nome de caminho de rede.

*Ptm*<br/>
Ponteiro para objeto CAtlTransactionManager

### <a name="return-value"></a>Valor retornado

TRUE se as informações de status do arquivo especificado forem obtidas com sucesso; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

A versão não `GetStatus` estática do recupera informações de status `CFile` do arquivo aberto associado ao objeto dado.  A versão `GetStatus` estática de obtém o status do arquivo de um determinado caminho de arquivo sem realmente abrir o arquivo. Esta versão é útil para testar a existência e os direitos de acesso de um arquivo.

O `m_attribute` membro `CFileStatus` da estrutura refere-se ao conjunto de atributos de arquivo. A `CFile` classe fornece o tipo de enumeração **de atributos** para que os atributos do arquivo possam ser especificados simbolicamente:

```
enum Attribute {
    normal =    0x00,
    readOnly =  0x01,
    hidden =    0x02,
    system =    0x04,
    volume =    0x08,
    directory = 0x10,
    archive =   0x20
    };
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#10](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_6.cpp)]

## <a name="cfilehfilenull"></a><a name="hfilenull"></a>CFile::hFileNull

Determina a presença de uma alça `CFile` de arquivo válida para o objeto.

```
static AFX_DATA const HANDLE hFileNull;
```

### <a name="remarks"></a>Comentários

Essa constante é usada `CFile` para determinar se o objeto tem uma alça de arquivo válida.

O exemplo a seguir demonstra esta operação:

[!code-cpp[NVC_MFCFiles#22](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_7.cpp)]

## <a name="cfilelockrange"></a><a name="lockrange"></a>CFile::LockRange

Bloqueia uma série de bytes em um arquivo aberto, abrindo uma exceção se o arquivo já estiver bloqueado.

```
virtual void LockRange(
    ULONGLONG dwPos,
    ULONGLONG dwCount);
```

### <a name="parameters"></a>Parâmetros

*dwPos*<br/>
O byte offset do início do intervalo de byte para travar.

*Dwcount*<br/>
O número de bytes no intervalo para travar.

### <a name="remarks"></a>Comentários

Os bytes bloqueados em um arquivo impedem o acesso a esses bytes por outros processos. Você pode bloquear mais de uma região de um arquivo, mas não são permitidas regiões sobrepostas.

Quando você desbloquear a `UnlockRange` região usando a função membro, o intervalo de byte deve corresponder exatamente à região que estava anteriormente bloqueada. A `LockRange` função não mescla regiões adjacentes. Se duas regiões bloqueadas estiverem adjacentes, você deve desbloquear cada região separadamente.

> [!NOTE]
> Esta função não está `CMemFile`disponível para a classe derivada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#12](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_8.cpp)]

## <a name="cfilem_hfile"></a><a name="m_hfile"></a>CFile::m_hFile

Contém o cabo de arquivo do sistema operacional para um arquivo aberto.

```
HANDLE m_hFile;
```

### <a name="remarks"></a>Comentários

`m_hFile`é uma variável pública do tipo UINT. Ele `CFile::hFileNull`contém um indicador de arquivo vazio independente do sistema operacional, se a alça não tiver sido atribuída.

O `m_hFile` uso não é recomendado, pois o significado do membro depende da classe derivada. `m_hFile`é feito um membro público para conveniência no apoio ao uso não polimormórfico da classe.

## <a name="cfilem_ptm"></a><a name="m_ptm"></a>Arquivo::m_pTM

Ponteiro para `CAtlTransactionManager` um objeto.

```
CAtlTransactionManager* m_pTM;
```

### <a name="remarks"></a>Comentários

## <a name="cfileopen"></a><a name="open"></a>Arquivo::Abrir

Sobrecarregado. `Open`é projetado para uso `CFile` com o construtor padrão.

```
virtual BOOL Open(
    LPCTSTR lpszFileName,
    UINT nOpenFlags,
    CFileException* pError = NULL);

virtual BOOL Open(
    LPCTSTR lpszFileName,
    UINT nOpenFlags,
    CAtlTransactionManager* pTM,
    CFileException* pError = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpszFileName*<br/>
Uma seqüência que contém o caminho para o arquivo desejado. O caminho pode ser relativo, absoluto ou um nome de rede (UNC).

*nOpenFlags*<br/>
Um UINT que define o modo de compartilhamento e acesso do arquivo. Ele especifica a ação a ser tomada ao abrir o arquivo. Você pode combinar opções usando o operador bitwise-OR **(&#124;).** Uma permissão de acesso e uma opção de compartilhamento são necessárias; os `modeCreate` `modeNoInherit` modos e modos são opcionais. Consulte o [construtor CFile](#cfile) para obter uma lista de opções de modo.

*pError*<br/>
Um ponteiro para um objeto de exceção de arquivo existente que receberá o status de uma operação com falha.

*Ptm*<br/>
Ponteiro para objeto CAtlTransactionManager

### <a name="return-value"></a>Valor retornado

Não zero se o aberto foi bem sucedido; caso contrário, 0. O parâmetro *pError* só é significativo se 0 for retornado.

### <a name="remarks"></a>Comentários

As `Open` duas funções são métodos "seguros" para abrir um arquivo, onde uma falha é uma condição normal e esperada.

Enquanto `CFile` o construtor lança uma exceção em uma condição de erro, `Open` retorna FALSO para condições de erro. `Open`ainda pode inicializar um objeto [CFileException](../../mfc/reference/cfileexception-class.md) para descrever o erro, no entanto. Se você não fornecer o parâmetro *pError,* ou se você `Open` passar NULL para `CFileException` *pError,* retorna FALSE e não lança um . Se você passar um ponteiro `CFileException`para `Open` um existente , e encontrar um erro, a função o preenche com informações descrevendo esse erro. `Open`não lança uma exceção em ambos os casos.

A tabela a seguir descreve `Open`os possíveis resultados de .

|`pError`|Erro encontrado|Valor retornado|Conteúdo cfileexception|
|--------------|------------------------|------------------|----------------------------|
|NULO|Não|TRUE|n/d|
|ptr para`CFileException`|Não|TRUE|inalterado|
|NULO|Sim|FALSE|n/d|
|ptr para`CFileException`|Sim|FALSE|inicializado para descrever erro|

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#13](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_9.cpp)]

[!code-cpp[NVC_MFCFiles#14](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_10.cpp)]

## <a name="cfileoperator-handle"></a><a name="operator_handle"></a>CFile::manipulação do operador

Use este operador para passar `CFile` uma alça para um objeto para funções `HANDLE`como [ReadFileEx](/windows/win32/api/fileapi/nf-fileapi-readfileex) e [GetFileTime](/windows/win32/api/fileapi/nf-fileapi-getfiletime) que esperam um .

```
operator HANDLE() const;
```

## <a name="cfileread"></a><a name="read"></a>CFile::Read

Lê dados em um buffer do `CFile` arquivo associado ao objeto.

```
virtual UINT Read(
    void* lpBuf,
    UINT nCount);
```

### <a name="parameters"></a>Parâmetros

*Lpbuf*<br/>
Ponteiro para o buffer fornecido pelo usuário que é para receber os dados lidos do arquivo.

*Ncount*<br/>
O número máximo de bytes a serem lidos no arquivo. Para arquivos de modo texto, os pares de feed de linha de retorno de transporte são contados como caracteres únicos.

### <a name="return-value"></a>Valor retornado

O número de bytes transferidos para o buffer. Para `CFile` todas as classes, o valor de retorno pode ser menor do que *nCount* se o final do arquivo for atingido.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#15](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_11.cpp)]

Para outro exemplo, consulte [CFile::Open](#open).

## <a name="cfileremove"></a><a name="remove"></a>Arquivo::Remover

Esta função estática exclui o arquivo especificado pelo caminho.

```
static void PASCAL Remove(
    LPCTSTR lpszFileName,
    CAtlTransactionManager* pTM = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpszFileName*<br/>
Uma seqüência que é o caminho para o arquivo desejado. O caminho pode ser relativo ou absoluto, e pode conter um nome de rede.

*Ptm*<br/>
Ponteiro para objeto CAtlTransactionManager

### <a name="remarks"></a>Comentários

`Remove`não vai remover um diretório.

A `Remove` função membro abre uma exceção se o arquivo conectado estiver aberto ou se o arquivo não puder ser removido. Esta função é equivalente ao comando DEL.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#17](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_12.cpp)]

## <a name="cfilerename"></a><a name="rename"></a>CFile::Renomear

Esta função estática renomeia o arquivo especificado.

```
static void PASCAL Rename(
    LPCTSTR lpszOldName,
    LPCTSTR lpszNewName,
    CAtlTransactionManager* pTM = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpszOldName*<br/>
O velho caminho.

*lpszNewName*<br/>
O novo caminho.

*Ptm*<br/>
Ponteiro para objeto CAtlTransactionManager

### <a name="remarks"></a>Comentários

Diretórios não podem ser renomeados. Esta função é equivalente ao comando REN.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#18](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_13.cpp)]

## <a name="cfileseek"></a><a name="seek"></a>CFile::Buscar

Reposiciona o ponteiro do arquivo em um arquivo aberto.

```
virtual ULONGLONG Seek(
LONGLONG lOff,
UINT nFrom);
```

### <a name="parameters"></a>Parâmetros

*Loff*<br/>
Número de bytes para mover o ponteiro de arquivo. Valores positivos movem o ponteiro do arquivo para o final do arquivo; valores negativos movem o ponteiro do arquivo para o início do arquivo.

*nFrom*<br/>
Posição para procurar. Consulte a seção Observações para obter possíveis valores.

### <a name="return-value"></a>Valor retornado

A posição do ponteiro de arquivo se o método foi bem sucedido; caso contrário, o valor de retorno é `CFileException` indefinido e um ponteiro para uma exceção é lançado.

### <a name="remarks"></a>Comentários

A tabela a seguir lista os valores possíveis para o parâmetro *nFrom.*

|Valor|Descrição|
|-----------|-----------------|
|`CFile::begin`|Procure desde o início do arquivo.|
|`CFile::current`|Procure a localização atual do ponteiro do arquivo.|
|`CFile::end`|Procure no final do arquivo.|

Quando um arquivo é aberto, o ponteiro do arquivo é posicionado em 0, o início do arquivo.

Você pode definir o ponteiro do arquivo para uma posição além do final de um arquivo. Se você fizer isso, o tamanho do arquivo não aumenta até que você escreva para o arquivo.

O manipulador de exceção deste método deve excluir o objeto de exceção após o processamento da exceção.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#9](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_14.cpp)]

## <a name="cfileseektobegin"></a><a name="seektobegin"></a>Cfile::SeekToBegin

Define o valor do ponteiro do arquivo para o início do arquivo.

```
void SeekToBegin();
```

### <a name="remarks"></a>Comentários

`SeekToBegin()` é equivalente a `Seek( 0L, CFile::begin )`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#19](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_15.cpp)]

## <a name="cfileseektoend"></a><a name="seektoend"></a>Cfile::SeekToEnd

Define o valor do ponteiro do arquivo para a extremidade lógica do arquivo.

```
ULONGLONG SeekToEnd();
```

### <a name="return-value"></a>Valor retornado

O comprimento do arquivo em bytes.

### <a name="remarks"></a>Comentários

`SeekToEnd()` é equivalente a `CFile::Seek( 0L, CFile::end )`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#19](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_15.cpp)]

## <a name="cfilesetfilepath"></a><a name="setfilepath"></a>Arquivo::SetFilePath

Chame esta função para especificar o caminho do arquivo. Por exemplo, se o caminho de um arquivo não estiver disponível `SetFilePath` quando um objeto [CFile](../../mfc/reference/cfile-class.md) for construído, ligue para fornecê-lo.

```
virtual void SetFilePath(LPCTSTR lpszNewName);
```

### <a name="parameters"></a>Parâmetros

*lpszNewName*<br/>
Ponteiro para uma seqüência especificando o novo caminho.

### <a name="remarks"></a>Comentários

> [!NOTE]
> `SetFilePath`não abre o arquivo ou cria o arquivo; ele simplesmente `CFile` associa o objeto com um nome de caminho, que pode então ser usado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#20](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_16.cpp)]

## <a name="cfilesetlength"></a><a name="setlength"></a>arquivo::setLength

Chame esta função para alterar o comprimento do arquivo.

```
virtual void SetLength(ULONGLONG dwNewLen);
```

### <a name="parameters"></a>Parâmetros

*dwNewLen*<br/>
Comprimento desejado do arquivo em bytes. Esse valor pode ser maior ou menor do que o comprimento atual do arquivo. O arquivo será estendido ou truncado conforme apropriado.

### <a name="remarks"></a>Comentários

> [!NOTE]
> Com `CMemFile`, esta função `CMemoryException` poderia lançar um objeto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#11](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_17.cpp)]

## <a name="cfilesetstatus"></a><a name="setstatus"></a>Arquivo::SetStatus

Define o status do arquivo associado a este local de arquivo.

```
static void PASCAL SetStatus(
    LPCTSTR lpszFileName,
    const CFileStatus& status,
    CAtlTransactionManager* pTM = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpszFileName*<br/>
Uma seqüência que é o caminho para o arquivo desejado. O caminho pode ser relativo ou absoluto, e pode conter um nome de rede.

*status*<br/>
O buffer contendo as novas informações de status. Ligue `GetStatus` para a função `CFileStatus` do membro para preencher a estrutura com valores atuais e, em seguida, faça alterações conforme necessário. Se um valor for 0, o item de status correspondente não será atualizado. Consulte a função [getstatus](#getstatus) membro `CFileStatus` para obter uma descrição da estrutura.

*Ptm*<br/>
Ponteiro para objeto CAtlTransactionManager

### <a name="remarks"></a>Comentários

Para definir a hora, modifique o `m_mtime` campo de *status*.

Quando você faz `SetStatus` uma chamada para na tentativa de alterar apenas `m_mtime` os atributos do arquivo, e o membro da estrutura de status do arquivo não é zero, os atributos também podem ser afetados (alterar o carimbo de hora pode ter efeitos colaterais nos atributos). Se você quiser apenas alterar os atributos `m_mtime` do arquivo, primeiro defina o membro `SetStatus`da estrutura de status do arquivo como zero e, em seguida, faça uma chamada para .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#21](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_18.cpp)]

## <a name="cfileunlockrange"></a><a name="unlockrange"></a>CFile::UnlockRange

Desbloqueia uma série de bytes em um arquivo aberto.

```
virtual void UnlockRange(
    ULONGLONG dwPos,
    ULONGLONG dwCount);
```

### <a name="parameters"></a>Parâmetros

*dwPos*<br/>
O byte offset do início do intervalo de byte para desbloquear.

*Dwcount*<br/>
O número de bytes no intervalo para desbloquear.

### <a name="remarks"></a>Comentários

Consulte a descrição da função membro [LockRange](#lockrange) para obter detalhes.

> [!NOTE]
> Esta função não está `CMemFile`disponível para a classe derivada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#12](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_8.cpp)]

## <a name="cfilewrite"></a><a name="write"></a>CFile::Write

Grava dados de um buffer para `CFile` o arquivo associado ao objeto.

```
virtual void Write(
    const void* lpBuf,
    UINT nCount);
```

### <a name="parameters"></a>Parâmetros

*Lpbuf*<br/>
Um ponteiro para o buffer fornecido pelo usuário que contém os dados a serem gravados no arquivo.

*Ncount*<br/>
O número de bytes a serem transferidos do buffer. Para arquivos de modo texto, os pares de feed de linha de retorno de transporte são contados como caracteres únicos.

### <a name="remarks"></a>Comentários

`Write`lança uma exceção em resposta a várias condições, incluindo a condição completa do disco.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#16](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_19.cpp)]

Veja também os exemplos de [CFile::CFile](#cfile) e [CFile::Open](#open)'

## <a name="see-also"></a>Confira também

[Amostra de MFC DRAWCLI](../../overview/visual-cpp-samples.md)<br/>
[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CStdioFile](../../mfc/reference/cstdiofile-class.md)<br/>
[Classe CMemFile](../../mfc/reference/cmemfile-class.md)
