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
ms.openlocfilehash: db499ffa5f1d82b6e3622287f86132930a929102
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58768545"
---
# <a name="cfile-class"></a>Classe CFile

A classe base para classes de arquivo do Microsoft Foundation Class.

## <a name="syntax"></a>Sintaxe

```
class CFile : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CFile::CFile](#cfile)|Constrói um `CFile` objeto a partir de um identificador de arquivo ou caminho.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CFile::Abort](#abort)|Fecha um arquivo, ignorando todos os erros e avisos.|
|[CFile::Close](#close)|Fecha um arquivo e exclui o objeto.|
|[CFile::Duplicate](#duplicate)|Constrói um objeto duplicado com base nesse arquivo.|
|[CFile::Flush](#flush)|Libera todos os dados ainda a ser gravado.|
|[CFile::GetFileName](#getfilename)|Recupera o nome do arquivo do arquivo selecionado.|
|[CFile::GetFilePath](#getfilepath)|Recupera o caminho completo do arquivo selecionado.|
|[CFile::GetFileTitle](#getfiletitle)|Recupera o título do arquivo selecionado.|
|[CFile::GetLength](#getlength)|Recupera o tamanho do arquivo.|
|[CFile::GetPosition](#getposition)|Recupera o ponteiro do arquivo atual.|
|[CFile::GetStatus](#getstatus)|Recupera o status do arquivo aberto ou na versão estática, recupera o status do arquivo especificado (função estática e virtual).|
|[CFile::LockRange](#lockrange)|Bloqueia um intervalo de bytes em um arquivo.|
|[CFile::Open](#open)|Com segurança abre um arquivo com uma opção de teste de erro.|
|[CFile::Read](#read)|Leituras de dados (sem buffer) de um arquivo na posição atual do arquivo.|
|[CFile::Remove](#remove)|Exclui o arquivo especificado (função estática).|
|[CFile::Rename](#rename)|Renomeia o arquivo especificado (função estática).|
|[CFile::Seek](#seek)|Posiciona o ponteiro do arquivo atual.|
|[CFile::SeekToBegin](#seektobegin)|Posiciona o ponteiro do arquivo atual no início do arquivo.|
|[CFile::SeekToEnd](#seektoend)|Posiciona o ponteiro do arquivo atual no final do arquivo.|
|[CFile::SetFilePath](#setfilepath)|Define o caminho completo do arquivo selecionado.|
|[CFile::SetLength](#setlength)|Altera o tamanho do arquivo.|
|[CFile::SetStatus](#setstatus)|Define o status do arquivo especificado (função estática e virtual).|
|[CFile::UnlockRange](#unlockrange)|Desbloqueia um intervalo de bytes em um arquivo.|
|[CFile::Write](#write)|Grava dados (sem buffer) em um arquivo para a posição atual do arquivo.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CFile::operator identificador](#operator_handle)|Um identificador para um `CFile` objeto.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CFile::hFileNull](#hfilenull)|Determina se o `CFile` objeto tem um identificador válido.|
|[CFile::m_hFile](#m_hfile)|Normalmente, contém o identificador de arquivo do sistema operacional.|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|[CFile::m_pTM](#m_ptm)|Ponteiro para `CAtlTransactionManager` objeto.|

## <a name="remarks"></a>Comentários

Fornece serviços de entrada/saída de disco não armazenado em buffer e binários diretamente e indiretamente dá suporte a arquivos de texto e arquivos de memória por meio de suas classes derivadas. `CFile` funciona em conjunto com o `CArchive` classe oferecer suporte à serialização de objetos do Microsoft Foundation Class.

A relação hierárquica entre essa classe e suas classes derivadas permite que seu programa operar em todos os objetos de arquivo por meio de polimórfico `CFile` interface. Um arquivo de memória, por exemplo, se comporta como um arquivo de disco.

Use `CFile` e suas classes derivadas para uso geral e/s de disco. Use `ofstream` ou outras classes de iostream da Microsoft para texto formatado, enviados para um arquivo de disco.

Normalmente, um arquivo de disco é aberto automaticamente na `CFile` construção e destruição fechada em. Funções de membro estático permitem que você interrogar o status de um arquivo sem abrir o arquivo.

Para obter mais informações sobre como usar `CFile`, consulte os artigos [arquivos no MFC](../../mfc/files-in-mfc.md) e [tratamento de arquivos](../../c-runtime-library/file-handling.md) no *referência da biblioteca de tempo de execução*.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CFile`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

##  <a name="abort"></a>  CFile::Abort

Fecha o arquivo associado a este objeto e torna o arquivo não está disponível para leitura ou gravação.

```
virtual void Abort();
```

### <a name="remarks"></a>Comentários

Se você não tiver fechado o arquivo antes de destruir o objeto, o destruidor fecha-lo para você.

Ao lidar com exceções, `CFile::Abort` difere `CFile::Close` de duas maneiras importantes. Primeiro, o `Abort` função não lançará uma exceção em falhas porque as falhas são ignoradas pelo `Abort`. Segundo, `Abort` não irá **ASSERT** se o arquivo não foi aberto ou foi fechado anteriormente.

Se você usou **novos** alocar o `CFile` do objeto no heap, em seguida, você deve excluí-lo depois de fechar o arquivo. `Abort` define `m_hFile` para `CFile::hFileNull`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#5](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_1.cpp)]

##  <a name="cfile"></a>  CFile::CFile

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

*hFile*<br/>
Handle de um arquivo para anexar ao objeto `CFile`.

*lpszFileName*<br/>
Caminho relativo ou completo de um arquivo para anexar ao objeto `CFile`.

*nOpenFlags*<br/>
Combinação bit a bit (OR) das opções de acesso de arquivo do arquivo especificado. Consulte a seção Comentários para obter possíveis opções.

*pTM*<br/>
Ponteiro para objeto CAtlTransactionManager

### <a name="remarks"></a>Comentários

As cinco tabelas a seguir listam as opções possíveis para o *nOpenFlags* parâmetro.

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
|`CFile::typeText`|Define o modo de texto com processamento especial para os pares de alimentação de linha de retorno de carro (usado apenas em classes derivadas).|
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
|`CFile::modeCreate`|Cria um novo arquivo se o arquivo não existe. Se o arquivo já existir, ele é substituído e inicialmente definido como comprimento zero.|
|`CFile::modeNoTruncate`|Cria um novo arquivo se nenhum arquivo existir; caso contrário, se o arquivo já existir, ele será anexado ao objeto `CFile`.|

Escolha as opções de cache de arquivo conforme descritas a seguir. Por padrão, o sistema usa um esquema de cache de uso geral que não está disponível como opção.

|Valor|Descrição|
|-----------|-----------------|
|`CFile::osNoBuffer`|O sistema não usa um cache intermediário para o arquivo. Esta opção cancela as duas opções a seguir.|
|`CFile::osRandomAccess`|O cache do arquivo é otimizado para acesso aleatório. Não use essa opção e a opção de varredura sequencial.|
|`CFile::osSequentialScan`|O cache do arquivo é otimizado para acesso sequencial. Não use essa opção e a opção de acesso aleatório.|
|`CFile::osWriteThrough`|Operações de gravação são realizadas sem atraso.|

Escolha a opção de segurança a seguir para impedir que o handle do arquivo seja herdado. Por padrão, qualquer novo processo filho pode usar o handle do arquivo.

|Valor|Descrição|
|-----------|-----------------|
|`CFile::modeNoInherit`|Impede qualquer processo filho de usar o handle do arquivo.|

O construtor padrão inicializa membros mas não anexa um arquivo ao objeto `CFile`. Depois de usar esse construtor, use o [CFile::Open](#open) método para abrir um arquivo e anexá-lo para o `CFile` objeto.

O construtor com um parâmetro inicializa membros e anexa um arquivo existente ao objeto `CFile`.

O construtor com dois parâmetros inicializa membros e tenta abrir o arquivo especificado. Se o construtor abrir o arquivo especificado com sucesso, o arquivo será anexado ao objeto `CFile`; caso contrário, o construtor lança um ponteiro para um objeto `CInvalidArgException`. Para obter mais informações sobre como lidar com exceções, consulte [exceções](../../mfc/exception-handling-in-mfc.md).

Se um objeto `CFile` abrir um arquivo especificado com sucesso, ele fechará esse arquivo automaticamente quando o objeto `CFile` for destruído; caso contrário, será necessário fechar explicitamente o arquivo após ele não estar mais anexado ao objeto `CFile`.

### <a name="example"></a>Exemplo

O código a seguir mostra como usar um `CFile`.

[!code-cpp[NVC_MFCFiles#4](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_2.cpp)]

##  <a name="close"></a>  CFile::Close

Fecha o arquivo associado a este objeto e torna o arquivo não está disponível para leitura ou gravação.

```
virtual void Close();
```

### <a name="remarks"></a>Comentários

Se você não tiver fechado o arquivo antes de destruir o objeto, o destruidor fecha-lo para você.

Se você usou **novos** alocar o `CFile` do objeto no heap, em seguida, você deve excluí-lo depois de fechar o arquivo. `Close` define `m_hFile` para `CFile::hFileNull`.

### <a name="example"></a>Exemplo

Veja o exemplo de [CFile::CFile](#cfile).

##  <a name="duplicate"></a>  CFile::Duplicate

Constrói uma duplicata `CFile` objeto para um determinado arquivo.

```
virtual CFile* Duplicate() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para uma duplicata `CFile` objeto.

### <a name="remarks"></a>Comentários

Isso é equivalente à função de tempo de execução C `_dup`.

##  <a name="flush"></a>  CFile::Flush

Força os dados restantes no buffer de arquivo a ser gravado no arquivo.

```
virtual void Flush();
```

### <a name="remarks"></a>Comentários

O uso de `Flush` não garante a liberação de `CArchive` buffers. Se você estiver usando um arquivo morto, chame [CArchive::Flush](../../mfc/reference/carchive-class.md#flush) primeiro.

### <a name="example"></a>Exemplo

Veja o exemplo de [CFile::SetFilePath](#setfilepath).

##  <a name="getfilename"></a>  CFile::GetFileName

Chame essa função de membro para recuperar o nome de um arquivo especificado.

```
virtual CString GetFileName() const;
```

### <a name="return-value"></a>Valor de retorno

O nome do arquivo.

### <a name="remarks"></a>Comentários

Por exemplo, quando você chama `GetFileName` para gerar uma mensagem para o usuário sobre o arquivo `c:\windows\write\myfile.wri`, o nome do arquivo, `myfile.wri`, será retornado.

Para retornar todo o caminho do arquivo, incluindo o nome, chame [GetFilePath](#getfilepath). Para retornar o título do arquivo ( `myfile`), chame [GetFileTitle](#getfiletitle).

### <a name="example"></a>Exemplo

Este fragmento de código abre o sistema. Arquivo INI em seu diretório do WINDOWS. Se encontrado, o exemplo imprimirá o nome e o caminho e o título, conforme mostrado na saída:

[!code-cpp[NVC_MFCFiles#6](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_3.cpp)]

##  <a name="getfilepath"></a>  CFile::GetFilePath

Chame essa função de membro para recuperar o caminho completo de um arquivo especificado.

```
virtual CString GetFilePath() const;
```

### <a name="return-value"></a>Valor de retorno

O caminho completo do arquivo especificado.

### <a name="remarks"></a>Comentários

Por exemplo, quando você chama `GetFilePath` para gerar uma mensagem para o usuário sobre o arquivo `c:\windows\write\myfile.wri`, o caminho do arquivo, `c:\windows\write\myfile.wri`, será retornado.

Para retornar apenas o nome do arquivo (`myfile.wri`), chame [GetFileName](#getfilename). Para retornar o título do arquivo (`myfile`), chame [GetFileTitle](#getfiletitle).

### <a name="example"></a>Exemplo

Veja o exemplo de [GetFileName](#getfilename).

##  <a name="getfiletitle"></a>  CFile::GetFileTitle

Chame essa função de membro para recuperar o título do arquivo (o nome de exibição) para o arquivo.

```
virtual CString GetFileTitle() const;
```

### <a name="return-value"></a>Valor de retorno

O título do arquivo subjacente.

### <a name="remarks"></a>Comentários

Este método chama [GetFileTitle](/windows/desktop/api/commdlg/nf-commdlg-getfiletitlea) para recuperar o título do arquivo. Se for bem-sucedido, o método retorna a cadeia de caracteres que o sistema usa para exibir o nome do arquivo para o usuário. Caso contrário, o método chama [PathFindFileName](/windows/desktop/api/shlwapi/nf-shlwapi-pathfindfilenamea) para recuperar o nome do arquivo (incluindo a extensão de arquivo) do arquivo subjacente. Portanto, a extensão de arquivo não será sempre incluída na cadeia de caracteres de título de arquivo retornado. Para obter mais informações, consulte [GetFileTitle](/windows/desktop/api/commdlg/nf-commdlg-getfiletitlea) e [PathFindFileName](/windows/desktop/api/shlwapi/nf-shlwapi-pathfindfilenamea) no SDK do Windows.

Para retornar todo o caminho do arquivo, incluindo o nome, chame [GetFilePath](#getfilepath). Para retornar apenas o nome do arquivo, chame [GetFileName](#getfilename).

### <a name="example"></a>Exemplo

Veja o exemplo de [GetFileName](#getfilename).

##  <a name="getlength"></a>  CFile::GetLength

Obtém o tamanho lógico atual do arquivo em bytes.

```
virtual ULONGLONG GetLength() const;
```

### <a name="return-value"></a>Valor de retorno

O tamanho do arquivo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#7](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_4.cpp)]

##  <a name="getposition"></a>  CFile::GetPosition

Obtém o valor atual do ponteiro do arquivo, que pode ser usado em chamadas subsequentes para `Seek`.

```
virtual ULONGLONG GetPosition() const;
```

### <a name="return-value"></a>Valor de retorno

O ponteiro do arquivo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#8](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_5.cpp)]

##  <a name="getstatus"></a>  CFile::GetStatus

Esse método recupera informações de status relacionadas a um determinado `CFile` instância do objeto ou um caminho de arquivo fornecido.

```
BOOL GetStatus(CFileStatus& rStatus) const;

static BOOL PASCAL GetStatus(
    LPCTSTR lpszFileName,
    CFileStatus& rStatus,
    CAtlTransactionManager* pTM = NULL);
```

### <a name="parameters"></a>Parâmetros

*rStatus*<br/>
Uma referência a um fornecido pelo usuário `CFileStatus` estrutura que receberá as informações de status. O `CFileStatus` estrutura tem os seguintes campos:

- `CTime m_ctime` A data e hora que o arquivo foi criado.

- `CTime m_mtime` A data e hora que o arquivo foi modificado pela última vez.

- `CTime m_atime` A data e hora em que o arquivo foi acessado pela última vez para leitura.

- `ULONGLONG m_size` O tamanho lógico do arquivo em bytes, conforme relatado pelo comando DIR.

- `BYTE m_attribute` O byte de atributo do arquivo.

- `char m_szFullName[_MAX_PATH]` O nome do arquivo absoluto no conjunto de caracteres do Windows.

*lpszFileName*<br/>
Uma cadeia de caracteres no caractere Windows conjunto que é o caminho para o arquivo desejado. O caminho pode ser relativo ou absoluto, ou ele pode conter um nome de caminho de rede.

*pTM*<br/>
Ponteiro para objeto CAtlTransactionManager

### <a name="return-value"></a>Valor de retorno

TRUE se as informações de status para o arquivo especificado são obtidas com êxito; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

A versão de não-estático de `GetStatus` recupera informações de status do arquivo aberto associado a determinado `CFile` objeto.  A versão estática do `GetStatus` obtém o status do arquivo de um determinado caminho de arquivo sem, na verdade, abrir o arquivo. Isso é útil para testar os existência e direitos de acesso de um arquivo.

O `m_attribute` membro o `CFileStatus` estrutura refere-se para o conjunto de atributos de arquivo. O `CFile` classe fornece a **atributo** enumeração de tipo para que os atributos de arquivo podem ser especificados simbolicamente:

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

##  <a name="hfilenull"></a>  CFile::hFileNull

Determina a presença de um identificador de arquivo válido para o `CFile` objeto.

```
static AFX_DATA const HANDLE hFileNull;
```

### <a name="remarks"></a>Comentários

Essa constante é usada para determinar se o `CFile` objeto tem um identificador de arquivo válido.

O exemplo a seguir demonstra esta operação:

[!code-cpp[NVC_MFCFiles#22](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_7.cpp)]

##  <a name="lockrange"></a>  CFile::LockRange

Bloqueia um intervalo de bytes em um arquivo aberto, lançando uma exceção se o arquivo já está bloqueado.

```
virtual void LockRange(
    ULONGLONG dwPos,
    ULONGLONG dwCount);
```

### <a name="parameters"></a>Parâmetros

*dwPos*<br/>
O deslocamento de bytes do início do intervalo de bytes a bloquear.

*dwCount*<br/>
O número de bytes no intervalo a ser bloqueado.

### <a name="remarks"></a>Comentários

Os bytes bloqueados em um arquivo impedem o acesso a esses bytes por outros processos. Você pode bloquear mais de uma região de um arquivo, mas não há regiões sobrepostas são permitidos.

Quando você desbloqueia a região, usando o `UnlockRange` função de membro, o intervalo de bytes deve corresponder exatamente à região que foi bloqueado anteriormente. O `LockRange` função não mescla regiões adjacentes; se duas regiões bloqueadas forem adjacentes, você deve desbloquear separadamente cada região.

> [!NOTE]
>  Essa função não está disponível para o `CMemFile`-classe derivada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#12](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_8.cpp)]

##  <a name="m_hfile"></a>  CFile::m_hFile

Contém o identificador de arquivo do sistema operacional para um arquivo aberto.

```
HANDLE m_hFile;
```

### <a name="remarks"></a>Comentários

`m_hFile` é uma variável pública do tipo UINT. Ele contém `CFile::hFileNull` (um indicador de arquivo vazio do operacional sistema independente,) se o identificador não foi atribuído.

Uso de `m_hFile` não é recomendado porque depende do significado do membro na classe derivada. `m_hFile` é feita a um membro público para sua conveniência para oferecer suporte a não polimórficos usar da classe.

##  <a name="m_ptm"></a>  CFile::m_pTM

Ponteiro para um `CAtlTransactionManager` objeto.

```
CAtlTransactionManager* m_pTM;
```

### <a name="remarks"></a>Comentários

##  <a name="open"></a>  CFile::Open

Sobrecarregado. `Open` foi projetado para uso com o padrão `CFile` construtor.

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
Uma cadeia de caracteres que é o caminho para o arquivo desejado. O caminho pode ser um nome de rede (UNC), absoluto ou relativo.

*nOpenFlags*<br/>
UINT que define o modo de acesso e compartilhamento do arquivo. Especifica a ação a ser tomada ao abrir o arquivo. Você pode combinar as opções com o uso de OR bit a bit ( **&#124;** ) operador. Permissão de acesso de um e um compartilhamento de opção são necessários; o `modeCreate` e `modeNoInherit` modos são opcionais. Consulte a [CFile](#cfile) construtor para obter uma lista das opções de modo.

*pError*<br/>
Um ponteiro para um objeto de exceção de arquivo existente que receberá o status de uma operação com falha.

*pTM*<br/>
Ponteiro para objeto CAtlTransactionManager

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a abertura tiver sido bem-sucedida; Caso contrário, 0. O *pError* parâmetro só será significativo se 0 será retornado.

### <a name="remarks"></a>Comentários

As duas funções formam um método "seguro" para abrir um arquivo em que uma falha é uma condição normal, esperada.

Enquanto o `CFile` construtor lançará uma exceção em uma condição de erro, `Open` retornará FALSE para condições de erro. `Open` ainda pode inicializar uma [CFileException](../../mfc/reference/cfileexception-class.md) objeto para descrever o erro, no entanto. Se você não fornecer a *pError* parâmetro, ou se você passar NULL para *pError*, `Open` retornará FALSE e não gerará um `CFileException`. Se você passar um ponteiro para um existente `CFileException`, e `Open` encontrar um erro, a função irá preenchê-lo com informações que descrevem o erro. Em nenhum caso será `Open` lançar uma exceção.

A tabela a seguir descreve os possíveis resultados de `Open`.

|`pError`|Erro encontrado|Valor retornado|Conteúdo CFileException|
|--------------|------------------------|------------------|----------------------------|
|NULL|Não|TRUE|N/D|
|PTR para `CFileException`|Não|TRUE|inalterado|
|NULL|Sim|FALSE|N/D|
|PTR para `CFileException`|Sim|FALSE|inicializado para descrever o erro|

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#13](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_9.cpp)]

[!code-cpp[NVC_MFCFiles#14](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_10.cpp)]

##  <a name="operator_handle"></a>  CFile::operator identificador

Use este operador para passar um identificador para um `CFile` de objeto para funções como [ReadFileEx](/windows/desktop/api/fileapi/nf-fileapi-readfileex) e [GetFileTime](/windows/desktop/api/fileapi/nf-fileapi-getfiletime) que esperam um `HANDLE`.

```
operator HANDLE() const;
```

##  <a name="read"></a>  CFile::Read

Lê dados em um buffer de arquivo associado a `CFile` objeto.

```
virtual UINT Read(
    void* lpBuf,
    UINT nCount);
```

### <a name="parameters"></a>Parâmetros

*lpBuf*<br/>
Ponteiro para o buffer fornecido pelo usuário que receberá os dados lidos do arquivo.

*nCount*<br/>
O número máximo de bytes a serem lidos do arquivo. Para arquivos de modo de texto, pares de alimentação de linha de retorno de carro são contados como caracteres únicos.

### <a name="return-value"></a>Valor de retorno

O número de bytes transferidos para o buffer. Observe que, para todos os `CFile` classes, o valor de retorno pode ser menor que *nCount* se o final do arquivo foi atingido.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#15](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_11.cpp)]

Para obter outro exemplo, consulte [CFile::Open](#open).

##  <a name="remove"></a>  CFile::Remove

A função estática exclui o arquivo especificado pelo caminho.

```
static void PASCAL Remove(
    LPCTSTR lpszFileName,
    CAtlTransactionManager* pTM = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpszFileName*<br/>
Uma cadeia de caracteres que é o caminho para o arquivo desejado. O caminho pode ser relativo ou absoluto e pode conter um nome de rede.

*pTM*<br/>
Ponteiro para objeto CAtlTransactionManager

### <a name="remarks"></a>Comentários

Ela não removerá um diretório.

O `Remove` função membro gera uma exceção se o arquivo conectado está aberto ou se o arquivo não pode ser removido. Isso é equivalente ao comando DEL.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#17](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_12.cpp)]

##  <a name="rename"></a>  CFile::Rename

A função estática renomeia o arquivo especificado.

```
static void PASCAL Rename(
    LPCTSTR lpszOldName,
    LPCTSTR lpszNewName,
    CAtlTransactionManager* pTM = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpszOldName*<br/>
O caminho antigo.

*lpszNewName*<br/>
O novo caminho.

*pTM*<br/>
Ponteiro para objeto CAtlTransactionManager

### <a name="remarks"></a>Comentários

Diretórios não podem ser renomeados. Isso é equivalente ao comando REN.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#18](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_13.cpp)]

##  <a name="seek"></a>  CFile::Seek

Reposiciona o ponteiro do arquivo em um arquivo aberto.

```
virtual ULONGLONG Seek(
LONGLONG lOff,
UINT nFrom);
```

### <a name="parameters"></a>Parâmetros

*lOff*<br/>
Número de bytes para mover o ponteiro do arquivo. Valores positivos movem o ponteiro do arquivo até o final do arquivo. valores negativos a movem o ponteiro do arquivo para o início do arquivo.

*nFrom*<br/>
Posição para buscar a partir do. Consulte a seção comentários para os valores possíveis.

### <a name="return-value"></a>Valor de retorno

A posição do ponteiro do arquivo se o método foi bem-sucedida; Caso contrário, o valor retornado será indefinido e um ponteiro para um `CFileException` exceção é lançada.

### <a name="remarks"></a>Comentários

A tabela a seguir lista os possíveis valores para o *nde* parâmetro.

|Valor|Descrição|
|-----------|-----------------|
|`CFile::begin`|Busca desde o início do arquivo.|
|`CFile::current`|Busca do local atual do ponteiro do arquivo.|
|`CFile::end`|Busca do final do arquivo.|

Quando um arquivo é aberto, o ponteiro do arquivo está posicionado em 0, o início do arquivo.

Você pode definir o ponteiro do arquivo para uma posição além do final de um arquivo. Se você fizer isso, o tamanho do arquivo não aumenta até que você gravar no arquivo.

O manipulador de exceção para esse método deve excluir o objeto de exceção depois que a exceção é processada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#9](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_14.cpp)]

##  <a name="seektobegin"></a>  CFile::SeekToBegin

Define o valor do ponteiro do arquivo para o início do arquivo.

```
void SeekToBegin();
```

### <a name="remarks"></a>Comentários

`SeekToBegin()` equivale a `Seek( 0L, CFile::begin )`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#19](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_15.cpp)]

##  <a name="seektoend"></a>  CFile::SeekToEnd

Define o valor do ponteiro do arquivo no final lógico do arquivo.

```
ULONGLONG SeekToEnd();
```

### <a name="return-value"></a>Valor de retorno

O comprimento do arquivo em bytes.

### <a name="remarks"></a>Comentários

`SeekToEnd()` equivale a `CFile::Seek( 0L, CFile::end )`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#19](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_15.cpp)]

##  <a name="setfilepath"></a>  CFile::SetFilePath

Chame essa função para especificar o caminho do arquivo. Por exemplo, se o caminho de um arquivo não está disponível quando um [CFile](../../mfc/reference/cfile-class.md) objeto é construído, chame `SetFilePath` fornecê-la.

```
virtual void SetFilePath(LPCTSTR lpszNewName);
```

### <a name="parameters"></a>Parâmetros

*lpszNewName*<br/>
Ponteiro para uma cadeia de caracteres especificando o novo caminho.

### <a name="remarks"></a>Comentários

> [!NOTE]
> `SetFilePath` Não abra o arquivo ou criar o arquivo; ele simplesmente associa o `CFile` objeto com um nome de caminho, que pode ser usado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#20](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_16.cpp)]

##  <a name="setlength"></a>  CFile::SetLength

Chame essa função para alterar o tamanho do arquivo.

```
virtual void SetLength(ULONGLONG dwNewLen);
```

### <a name="parameters"></a>Parâmetros

*dwNewLen*<br/>
Tamanho desejado do arquivo em bytes. Esse valor pode ser maior ou menor que o tamanho atual do arquivo. O arquivo será estendido ou truncado conforme apropriado.

### <a name="remarks"></a>Comentários

> [!NOTE]
>  Com o `CMemFile`, essa função pode lançar uma `CMemoryException` objeto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#11](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_17.cpp)]

##  <a name="setstatus"></a>  CFile::SetStatus

Define o status do arquivo associado a esse local de arquivo.

```
static void PASCAL SetStatus(
    LPCTSTR lpszFileName,
    const CFileStatus& status,
    CAtlTransactionManager* pTM = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpszFileName*<br/>
Uma cadeia de caracteres que é o caminho para o arquivo desejado. O caminho pode ser relativo ou absoluto e pode conter um nome de rede.

*status*<br/>
O buffer que contém as novas informações de status. Chame o `GetStatus` função de membro para pré-preencher o `CFileStatus` estrutura com os valores atuais e, em seguida, fazer as alterações necessárias. Se um valor for 0, o item de status correspondente não é atualizado. Consulte a [GetStatus](#getstatus) função de membro para obter uma descrição de `CFileStatus` estrutura.

*pTM*<br/>
Ponteiro para objeto CAtlTransactionManager

### <a name="remarks"></a>Comentários

Para definir o tempo, modifique a `m_mtime` campo de *status*.

Observe que quando você faz uma chamada para `SetStatus` em uma tentativa de alterar apenas os atributos do arquivo e o `m_mtime` membro da estrutura de status do arquivo é diferente de zero, os atributos também podem ser afetados (alteração da hora de carimbo de data / pode ter efeitos colaterais em os atributos). Se você quiser apenas alterar os atributos do arquivo, primeiro defina a `m_mtime` membro da estrutura de status do arquivo como zero e, em seguida, fazer uma chamada para `SetStatus`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#21](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_18.cpp)]

##  <a name="unlockrange"></a>  CFile::UnlockRange

Desbloqueia um intervalo de bytes em um arquivo aberto.

```
virtual void UnlockRange(
    ULONGLONG dwPos,
    ULONGLONG dwCount);
```

### <a name="parameters"></a>Parâmetros

*dwPos*<br/>
O deslocamento de bytes do início do intervalo de bytes para desbloquear.

*dwCount*<br/>
O número de bytes no intervalo a ser desbloqueado.

### <a name="remarks"></a>Comentários

Consulte a descrição do [LockRange](#lockrange) a função de membro para obter detalhes.

> [!NOTE]
>  Essa função não está disponível para o `CMemFile`-classe derivada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#12](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_8.cpp)]

##  <a name="write"></a>  CFile::Write

Grava dados de um buffer para o arquivo associado a `CFile` objeto.

```
virtual void Write(
    const void* lpBuf,
    UINT nCount);
```

### <a name="parameters"></a>Parâmetros

*lpBuf*<br/>
Um ponteiro para o buffer fornecido pelo usuário que contém os dados a serem gravados no arquivo.

*nCount*<br/>
O número de bytes a serem transferidos do buffer. Para arquivos de modo de texto, pares de alimentação de linha de retorno de carro são contados como caracteres únicos.

### <a name="remarks"></a>Comentários

`Write` gera uma exceção em resposta a várias condições, como a condição de disco cheio.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#16](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_19.cpp)]

Além disso, consulte os exemplos para [CFile::CFile](#cfile) e [CFile::Open](#open).

## <a name="see-also"></a>Consulte também

[Exemplo MFC DRAWCLI](../../overview/visual-cpp-samples.md)<br/>
[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CStdioFile](../../mfc/reference/cstdiofile-class.md)<br/>
[Classe CMemFile](../../mfc/reference/cmemfile-class.md)
