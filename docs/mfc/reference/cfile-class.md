---
title: Classe de testcfile
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
ms.openlocfilehash: a9161764f6c8646766a73add01c25cce5619ad19
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79418702"
---
# <a name="cfile-class"></a>Classe de testcfile

A classe base para classes de arquivo do Microsoft Foundation Class.

## <a name="syntax"></a>Sintaxe

```
class CFile : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[Testcfile:: RecFile](#cfile)|Constrói um objeto `CFile` a partir de um caminho ou identificador de arquivo.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[Testcfile:: Abort](#abort)|Fecha um arquivo ignorando todos os avisos e erros.|
|[Testcfile:: fechar](#close)|Fecha um arquivo e exclui o objeto.|
|[Testcfile::D uplicar](#duplicate)|Constrói um objeto duplicado com base neste arquivo.|
|[Testcfile:: flush](#flush)|Libera todos os dados que ainda serão gravados.|
|[Testcfile:: GetFileName](#getfilename)|Recupera o nome do arquivo selecionado.|
|[RecFile:: GetFilePath](#getfilepath)|Recupera o caminho completo do arquivo selecionado.|
|[Testcfile:: GetFileTitle](#getfiletitle)|Recupera o título do arquivo selecionado.|
|[Testcfile:: GetLength](#getlength)|Recupera o comprimento do arquivo.|
|[Testcfile:: GetPosition](#getposition)|Recupera o ponteiro do arquivo atual.|
|[RecFile:: GetStatus](#getstatus)|Recupera o status do arquivo aberto, ou na versão estática, recupera o status do arquivo especificado (função estática, virtual).|
|[Testcfile:: LockRange](#lockrange)|Bloqueia um intervalo de bytes em um arquivo.|
|[Testcfile:: abrir](#open)|Abre com segurança um arquivo com uma opção de teste de erro.|
|[Testcfile:: ler](#read)|Lê (sem buffer) dados de um arquivo na posição atual do arquivo.|
|[Testcfile:: remover](#remove)|Exclui o arquivo especificado (função estática).|
|[Testcfile:: renomear](#rename)|Renomeia o arquivo especificado (função estática).|
|[Testcfile:: Seek](#seek)|Posiciona o ponteiro do arquivo atual.|
|[Testcfile:: SeekToBegin](#seektobegin)|Posiciona o ponteiro do arquivo atual no início do arquivo.|
|[Testcfile:: SeekToEnd](#seektoend)|Posiciona o ponteiro do arquivo atual no final do arquivo.|
|[RecFile:: SetFilePath](#setfilepath)|Define o caminho de arquivo completo do arquivo selecionado.|
|[Testcfile:: SetLength](#setlength)|Altera o comprimento do arquivo.|
|[RecFile:: SetStatus](#setstatus)|Define o status do arquivo especificado (estático, função virtual).|
|[Testcfile:: UnlockRange](#unlockrange)|Desbloqueia um intervalo de bytes em um arquivo.|
|[Testcfile:: gravar](#write)|Grava (não buffer) dados em um arquivo na posição atual do arquivo.|

### <a name="public-operators"></a>Operadores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[MANIPULADOR de testcfile:: Operator](#operator_handle)|Um identificador para um objeto de `CFile`.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[Testcfile:: hFileNull](#hfilenull)|Determina se o objeto de `CFile` tem um identificador válido.|
|[Testcfile:: m_hFile](#m_hfile)|Geralmente contém o identificador de arquivo do sistema operacional.|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[Testcfile:: m_pTM](#m_ptm)|Ponteiro para o objeto `CAtlTransactionManager`.|

## <a name="remarks"></a>Comentários

Ele fornece diretamente serviços de entrada/saída de disco binários e não armazenados em buffer, além de dar suporte indiretamente a arquivos de texto e arquivos de memória por meio de suas classes derivadas. `CFile` trabalha em conjunto com a classe `CArchive` para dar suporte à serialização de objetos Microsoft Foundation Class.

A relação hierárquica entre essa classe e suas classes derivadas permite que seu programa opere em todos os objetos de arquivo por meio da interface de `CFile` polimórfico. Um arquivo de memória, por exemplo, se comporta como um arquivo de disco.

Use `CFile` e suas classes derivadas para e/s de disco de uso geral. Use `ofstream` ou outras classes do Microsoft `iostream` para texto formatado enviado para um arquivo de disco.

Normalmente, um arquivo de disco é aberto automaticamente em `CFile` construção e fechado na destruição. As funções de membro estático permitem interrogar o status de um arquivo sem abrir o arquivo.

Para obter mais informações sobre como usar `CFile`, consulte os arquivos de artigos [em MFC](../../mfc/files-in-mfc.md) e [manipulação de arquivos](../../c-runtime-library/file-handling.md) na *referência da biblioteca de tempo de execução*.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CFile`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

##  <a name="abort"></a>Testcfile:: Abort

Fecha o arquivo associado a esse objeto e torna o arquivo indisponível para leitura ou gravação.

```
virtual void Abort();
```

### <a name="remarks"></a>Comentários

Se você não tiver fechado o arquivo antes de destruir o objeto, o destruidor o fechará para você.

Ao lidar com exceções, `CFile::Abort` difere de `CFile::Close` de duas maneiras importantes. Primeiro, a função `Abort` não lançará uma exceção em caso de falhas, pois as falhas são ignoradas por `Abort`. Em segundo lugar, `Abort` não será **afirmado** se o arquivo não tiver sido aberto ou se tiver sido fechado anteriormente.

Se você usou **novo** para alocar o objeto `CFile` no heap, deverá excluí-lo após fechar o arquivo. `Abort` define `m_hFile` como `CFile::hFileNull`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#5](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_1.cpp)]

##  <a name="cfile"></a>Testcfile:: RecFile

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

### <a name="parameters"></a>parâmetros

*hFile*<br/>
Handle de um arquivo para anexar ao objeto `CFile`.

*lpszFileName*<br/>
Caminho relativo ou completo de um arquivo para anexar ao objeto `CFile`.

*nOpenFlags*<br/>
Combinação bit a bit (OR) das opções de acesso de arquivo do arquivo especificado. Consulte a seção Comentários para obter possíveis opções.

*pTM*<br/>
Ponteiro para objeto CAtlTransactionManager

### <a name="remarks"></a>Comentários

As cinco tabelas a seguir listam as possíveis opções para o parâmetro *nOpenFlags* .

Escolha apenas uma das opções de modo de acesso de arquivo a seguir. O modo de acesso de arquivo padrão é `CFile::modeRead`, que é somente leitura.

|Valor|DESCRIÇÃO|
|-----------|-----------------|
|`CFile::modeRead`|Solicita acesso somente leitura.|
|`CFile::modeWrite`|Solicita acesso somente gravação.|
|`CFile::modeReadWrite`|Solicita acesso de leitura e gravação.|

Escolha uma das opções de modo de caractere a seguir.

|Valor|DESCRIÇÃO|
|-----------|-----------------|
|`CFile::typeBinary`|Define modo binário (usado apenas em classes derivadas).|
|`CFile::typeText`|Define o modo de texto com processamento especial para pares de retorno de carro-alimentação de linha (usados somente em classes derivadas).|
|`CFile::typeUnicode`|Define modo Unicode (usado apenas em classes derivadas). O texto é gravado no arquivo em formato Unicode quando o aplicativo é compilado em uma configuração Unicode. Nenhum BOM é gravado no arquivo.|

Escolha apenas uma das opções de modo de compartilhamento de arquivo a seguir. O modo de compartilhamento de arquivo padrão é `CFile::shareExclusive`, que é exclusivo.

|Valor|DESCRIÇÃO|
|-----------|-----------------|
|`CFile::shareDenyNone`|Sem restrições de compartilhamento.|
|`CFile::shareDenyRead`|Nega acesso de leitura a todos os outros.|
|`CFile::shareDenyWrite`|Nega acesso de gravação a todos os outros.|
|`CFile::shareExclusive`|Nega acesso de leitura e gravação a todos os outros.|

Escolha a primeira ou as duas opções de modo de criação de arquivo a seguir. O modo de criação padrão é `CFile::modeNoTruncate`, que é abrir existente.

|Valor|DESCRIÇÃO|
|-----------|-----------------|
|`CFile::modeCreate`|Cria um novo arquivo se não houver nenhum arquivo. Se o arquivo já existir, ele será substituído e definido inicialmente como comprimento zero.|
|`CFile::modeNoTruncate`|Cria um novo arquivo se não houver nenhum arquivo; caso contrário, se o arquivo já existir, ele será anexado ao objeto `CFile`.|

Escolha as opções de cache de arquivo conforme descritas a seguir. Por padrão, o sistema usa um esquema de cache de uso geral que não está disponível como uma opção.

|Valor|DESCRIÇÃO|
|-----------|-----------------|
|`CFile::osNoBuffer`|O sistema não usa um cache intermediário para o arquivo. Esta opção cancela as duas opções a seguir.|
|`CFile::osRandomAccess`|O cache do arquivo é otimizado para acesso aleatório. Não use essa opção e a opção de verificação sequencial.|
|`CFile::osSequentialScan`|O cache do arquivo é otimizado para acesso sequencial. Não use essa opção e a opção de acesso aleatório.|
|`CFile::osWriteThrough`|As operações de gravação são feitas sem atraso.|

Escolha a opção de segurança a seguir para impedir que o handle do arquivo seja herdado. Por padrão, qualquer novo processo filho pode usar o handle do arquivo.

|Valor|DESCRIÇÃO|
|-----------|-----------------|
|`CFile::modeNoInherit`|Impede qualquer processo filho de usar o handle do arquivo.|

O construtor padrão Inicializa membros, mas não anexa um arquivo ao objeto `CFile`. Depois de usar esse construtor, use o método [testcfile:: Open](#open) para abrir um arquivo e anexá-lo ao objeto `CFile`.

O construtor com um parâmetro inicializa membros e anexa um arquivo existente ao objeto `CFile`.

O construtor com dois parâmetros inicializa membros e tenta abrir o arquivo especificado. Se o construtor abrir o arquivo especificado com sucesso, o arquivo será anexado ao objeto `CFile`; caso contrário, o construtor lança um ponteiro para um objeto `CInvalidArgException`. Para obter mais informações sobre como lidar com exceções, consulte [exceções](../../mfc/exception-handling-in-mfc.md).

Se um objeto `CFile` abrir com êxito um arquivo especificado, ele fechará esse arquivo automaticamente quando o objeto `CFile` for destruído; caso contrário, você deve fechar o arquivo explicitamente depois que ele não estiver mais anexado ao objeto `CFile`.

### <a name="example"></a>Exemplo

O código a seguir mostra como usar um `CFile`.

[!code-cpp[NVC_MFCFiles#4](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_2.cpp)]

##  <a name="close"></a>Testcfile:: fechar

Fecha o arquivo associado a esse objeto e torna o arquivo indisponível para leitura ou gravação.

```
virtual void Close();
```

### <a name="remarks"></a>Comentários

Se você não tiver fechado o arquivo antes de destruir o objeto, o destruidor o fechará para você.

Se você usou **novo** para alocar o objeto `CFile` no heap, deverá excluí-lo após fechar o arquivo. `Close` define `m_hFile` como `CFile::hFileNull`.

### <a name="example"></a>Exemplo

Consulte o exemplo de [testcfile:: RecFile](#cfile).

##  <a name="duplicate"></a>Testcfile::D uplicar

Constrói um objeto `CFile` duplicado para um determinado arquivo.

```
virtual CFile* Duplicate() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto `CFile` duplicado.

### <a name="remarks"></a>Comentários

Essa função é equivalente à `_dup`de função de tempo de execução do C.

##  <a name="flush"></a>Testcfile:: flush

Força todos os dados restantes no buffer de arquivos a serem gravados no arquivo.

```
virtual void Flush();
```

### <a name="remarks"></a>Comentários

O uso de `Flush` não garante a liberação de buffers de `CArchive`. Se você estiver usando um arquivo morto, chame [CArchive:: flush](../../mfc/reference/carchive-class.md#flush) primeiro.

### <a name="example"></a>Exemplo

Consulte o exemplo de [testcfile:: SetFilePath](#setfilepath).

##  <a name="getfilename"></a>Testcfile:: GetFileName

Chame essa função de membro para recuperar o nome de um arquivo especificado.

```
virtual CString GetFileName() const;
```

### <a name="return-value"></a>Valor retornado

O nome do arquivo.

### <a name="remarks"></a>Comentários

Por exemplo, quando você chama `GetFileName` para gerar uma mensagem para o usuário sobre o `c:\windows\write\myfile.wri`de arquivos, o nome de arquivo, `myfile.wri`, é retornado.

Para retornar o caminho inteiro do arquivo, incluindo o nome, chame [GetFilePath](#getfilepath). Para retornar o título do arquivo (`myfile`), chame [GetFileTitle](#getfiletitle).

### <a name="example"></a>Exemplo

Esse fragmento de código abre o sistema. Arquivo INI no seu diretório do WINDOWS. Se for encontrado, o exemplo imprimirá o nome e o caminho e o título, conforme mostrado em saída:

[!code-cpp[NVC_MFCFiles#6](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_3.cpp)]

##  <a name="getfilepath"></a>RecFile:: GetFilePath

Chame essa função de membro para recuperar o caminho completo de um arquivo especificado.

```
virtual CString GetFilePath() const;
```

### <a name="return-value"></a>Valor retornado

O caminho completo do arquivo especificado.

### <a name="remarks"></a>Comentários

Por exemplo, quando você chama `GetFilePath` para gerar uma mensagem para o usuário sobre o arquivo `c:\windows\write\myfile.wri`, o caminho do arquivo, `c:\windows\write\myfile.wri`, é retornado.

Para retornar apenas o nome do arquivo (`myfile.wri`), chame [GetFileName](#getfilename). Para retornar o título do arquivo (`myfile`), chame [GetFileTitle](#getfiletitle).

### <a name="example"></a>Exemplo

Consulte o exemplo de [GetFileName](#getfilename).

##  <a name="getfiletitle"></a>Testcfile:: GetFileTitle

Chame essa função de membro para recuperar o título do arquivo (o nome de exibição) do arquivo.

```
virtual CString GetFileTitle() const;
```

### <a name="return-value"></a>Valor retornado

O título do arquivo subjacente.

### <a name="remarks"></a>Comentários

Esse método chama [GetFileTitle](/windows/win32/api/commdlg/nf-commdlg-getfiletitlew) para recuperar o título do arquivo. Se for bem-sucedido, o método retornará a cadeia de caracteres que o sistema usará para exibir o nome do arquivo para o usuário. Caso contrário, o método chama [PathFindFileName](/windows/win32/api/shlwapi/nf-shlwapi-pathfindfilenamew) para recuperar o nome do arquivo (incluindo a extensão de arquivo) do arquivo subjacente. Isso significa que a extensão de arquivo nem sempre é incluída na cadeia de título do arquivo retornado. Para obter mais informações, consulte [GetFileTitle](/windows/win32/api/commdlg/nf-commdlg-getfiletitlew) e [PathFindFileName](/windows/win32/api/shlwapi/nf-shlwapi-pathfindfilenamew) no SDK do Windows.

Para retornar o caminho inteiro do arquivo, incluindo o nome, chame [GetFilePath](#getfilepath). Para retornar apenas o nome do arquivo, chame [GetFileName](#getfilename).

### <a name="example"></a>Exemplo

Consulte o exemplo de [GetFileName](#getfilename).

##  <a name="getlength"></a>Testcfile:: GetLength

Obtém o comprimento lógico atual do arquivo em bytes.

```
virtual ULONGLONG GetLength() const;
```

### <a name="return-value"></a>Valor retornado

O comprimento do arquivo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#7](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_4.cpp)]

##  <a name="getposition"></a>Testcfile:: GetPosition

Obtém o valor atual do ponteiro do arquivo, que pode ser usado em chamadas posteriores para `Seek`.

```
virtual ULONGLONG GetPosition() const;
```

### <a name="return-value"></a>Valor retornado

O ponteiro do arquivo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#8](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_5.cpp)]

##  <a name="getstatus"></a>RecFile:: GetStatus

Esse método recupera informações de status relacionadas a determinada instância de objeto `CFile` ou a um determinado caminho de arquivo.

```
BOOL GetStatus(CFileStatus& rStatus) const;

static BOOL PASCAL GetStatus(
    LPCTSTR lpszFileName,
    CFileStatus& rStatus,
    CAtlTransactionManager* pTM = NULL);
```

### <a name="parameters"></a>parâmetros

*rStatus*<br/>
Uma referência a uma estrutura de `CFileStatus` fornecida pelo usuário que receberá as informações de status. A estrutura de `CFileStatus` tem os seguintes campos:

- `CTime m_ctime` a data e a hora em que o arquivo foi criado.

- `CTime m_mtime` a data e a hora da última modificação do arquivo.

- `CTime m_atime` a data e a hora em que o arquivo foi acessado pela última vez para leitura.

- `ULONGLONG m_size` o tamanho lógico do arquivo em bytes, conforme relatado pelo comando DIR.

- `BYTE m_attribute` o byte do atributo do arquivo.

- `char m_szFullName[_MAX_PATH]` o nome de arquivo absoluto no conjunto de caracteres do Windows.

*lpszFileName*<br/>
Uma cadeia de caracteres no conjunto de caracteres do Windows que é o caminho para o arquivo desejado. O caminho pode ser relativo ou absoluto, ou pode conter um nome de caminho de rede.

*pTM*<br/>
Ponteiro para objeto CAtlTransactionManager

### <a name="return-value"></a>Valor retornado

TRUE se as informações de status do arquivo especificado forem obtidas com êxito; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

A versão não estática do `GetStatus` recupera informações de status do arquivo aberto associado ao objeto `CFile` fornecido.  A versão estática do `GetStatus` Obtém o status do arquivo de um determinado caminho de arquivo sem realmente abrir o arquivo. Essa versão é útil para testar a existência e os direitos de acesso de um arquivo.

O membro de `m_attribute` da estrutura de `CFileStatus` refere-se ao conjunto de atributos de arquivo. A classe `CFile` fornece o tipo de enumeração de **atributo** para que os atributos de arquivo possam ser especificados de forma simbólica:

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

##  <a name="hfilenull"></a>Testcfile:: hFileNull

Determina a presença de um identificador de arquivo válido para o objeto `CFile`.

```
static AFX_DATA const HANDLE hFileNull;
```

### <a name="remarks"></a>Comentários

Essa constante é usada para determinar se o objeto de `CFile` tem um identificador de arquivo válido.

O exemplo a seguir demonstra essa operação:

[!code-cpp[NVC_MFCFiles#22](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_7.cpp)]

##  <a name="lockrange"></a>Testcfile:: LockRange

Bloqueia um intervalo de bytes em um arquivo aberto, lançando uma exceção se o arquivo já estiver bloqueado.

```
virtual void LockRange(
    ULONGLONG dwPos,
    ULONGLONG dwCount);
```

### <a name="parameters"></a>parâmetros

*dwPos*<br/>
O deslocamento de byte do início do intervalo de bytes a ser bloqueado.

*dwCount*<br/>
O número de bytes no intervalo a ser bloqueado.

### <a name="remarks"></a>Comentários

Os bytes bloqueados em um arquivo impedem o acesso a esses bytes por outros processos. Você pode bloquear mais de uma região de um arquivo, mas não são permitidas regiões sobrepostas.

Quando você desbloqueia a região usando a função de membro `UnlockRange`, o intervalo de bytes deve corresponder exatamente à região que foi bloqueada anteriormente. A função `LockRange` não mescla regiões adjacentes. Se duas regiões bloqueadas estiverem adjacentes, você deverá desbloquear cada região separadamente.

> [!NOTE]
>  Essa função não está disponível para a classe derivada de `CMemFile`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#12](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_8.cpp)]

##  <a name="m_hfile"></a>Testcfile:: m_hFile

Contém o identificador de arquivo do sistema operacional para um arquivo aberto.

```
HANDLE m_hFile;
```

### <a name="remarks"></a>Comentários

`m_hFile` é uma variável pública do tipo UINT. Ele contém `CFile::hFileNull`, um indicador de arquivo vazio independente do sistema operacional, se o identificador não tiver sido atribuído.

O uso de `m_hFile` não é recomendado, pois o significado do membro depende da classe derivada. `m_hFile` torna-se um membro público para sua conveniência no suporte ao uso nonpolymorphic da classe.

##  <a name="m_ptm"></a>Testcfile:: m_pTM

Ponteiro para um objeto `CAtlTransactionManager`.

```
CAtlTransactionManager* m_pTM;
```

### <a name="remarks"></a>Comentários

##  <a name="open"></a>Testcfile:: abrir

Sobrecarregado. `Open` é projetado para uso com o construtor de `CFile` padrão.

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

### <a name="parameters"></a>parâmetros

*lpszFileName*<br/>
Uma cadeia de caracteres que contém o caminho para o arquivo desejado. O caminho pode ser relativo, absoluto ou um nome de rede (UNC).

*nOpenFlags*<br/>
Um UINT que define o modo de compartilhamento e acesso do arquivo. Especifica a ação a ser tomada ao abrir o arquivo. Você pode combinar as opções usando o operador bit-a **&#124;** -or (). Uma permissão de acesso e uma opção de compartilhamento são necessárias; os modos `modeCreate` e `modeNoInherit` são opcionais. Consulte o construtor de [testcfile](#cfile) para obter uma lista de opções de modo.

*pError*<br/>
Um ponteiro para um objeto de exceção de arquivo existente que receberá o status de uma operação com falha.

*pTM*<br/>
Ponteiro para objeto CAtlTransactionManager

### <a name="return-value"></a>Valor retornado

Diferente de zero se a abertura tiver sido bem-sucedida; caso contrário, 0. O parâmetro *perror* será significativo somente se 0 for retornado.

### <a name="remarks"></a>Comentários

As duas funções `Open` são métodos "seguros" para abrir um arquivo, em que uma falha é uma condição normal e esperada.

Enquanto o construtor de `CFile` gera uma exceção em uma condição de erro, `Open` retorna FALSE para condições de erro. o `Open` ainda pode inicializar um objeto [CFileException](../../mfc/reference/cfileexception-class.md) para descrever o erro. no entanto. Se você não fornecer o parâmetro *perror* ou se passar NULL para *perror*, `Open` retornará false e não lançará um `CFileException`. Se você passar um ponteiro para um `CFileException`existente e `Open` encontrar um erro, a função o preencherá com informações que descrevem esse erro. `Open` não lança uma exceção em nenhum dos casos.

A tabela a seguir descreve os possíveis resultados de `Open`.

|`pError`|Erro encontrado|Valor retornado|Conteúdo do CFileException|
|--------------|------------------------|------------------|----------------------------|
|NULO|Não|TRUE|n/d|
|PTR a `CFileException`|Não|TRUE|inalterado|
|NULO|Sim|FALSE|n/d|
|PTR a `CFileException`|Sim|FALSE|inicializado para descrever o erro|

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#13](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_9.cpp)]

[!code-cpp[NVC_MFCFiles#14](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_10.cpp)]

##  <a name="operator_handle"></a>MANIPULADOR de testcfile:: Operator

Use esse operador para passar um identificador para um objeto `CFile` para funções como [ReadFileEx](/windows/win32/api/fileapi/nf-fileapi-readfileex) e [GetFileTime](/windows/win32/api/fileapi/nf-fileapi-getfiletime) que esperam um `HANDLE`.

```
operator HANDLE() const;
```

##  <a name="read"></a>Testcfile:: ler

Lê dados em um buffer do arquivo associado ao objeto `CFile`.

```
virtual UINT Read(
    void* lpBuf,
    UINT nCount);
```

### <a name="parameters"></a>parâmetros

*lpBuf*<br/>
Ponteiro para o buffer fornecido pelo usuário que deve receber os dados lidos do arquivo.

*nCount*<br/>
O número máximo de bytes a serem lidos do arquivo. Para arquivos de modo de texto, os pares de retorno de carro-alimentação de linha são contados como caracteres únicos.

### <a name="return-value"></a>Valor retornado

O número de bytes transferidos para o buffer. Para todas as classes de `CFile`, o valor de retorno pode ser menor que *nCount* se o final do arquivo foi atingido.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#15](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_11.cpp)]

Para obter outro exemplo, consulte [testcfile:: Open](#open).

##  <a name="remove"></a>Testcfile:: remover

Essa função estática exclui o arquivo especificado pelo caminho.

```
static void PASCAL Remove(
    LPCTSTR lpszFileName,
    CAtlTransactionManager* pTM = NULL);
```

### <a name="parameters"></a>parâmetros

*lpszFileName*<br/>
Uma cadeia de caracteres que é o caminho para o arquivo desejado. O caminho pode ser relativo ou absoluto e pode conter um nome de rede.

*pTM*<br/>
Ponteiro para objeto CAtlTransactionManager

### <a name="remarks"></a>Comentários

`Remove` não removerá um diretório.

A função membro `Remove` gera uma exceção se o arquivo conectado estiver aberto ou se o arquivo não puder ser removido. Essa função é equivalente ao comando DEL.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#17](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_12.cpp)]

##  <a name="rename"></a>Testcfile:: renomear

Essa função estática renomeia o arquivo especificado.

```
static void PASCAL Rename(
    LPCTSTR lpszOldName,
    LPCTSTR lpszNewName,
    CAtlTransactionManager* pTM = NULL);
```

### <a name="parameters"></a>parâmetros

*lpszOldName*<br/>
O caminho antigo.

*lpszNewName*<br/>
O novo caminho.

*pTM*<br/>
Ponteiro para objeto CAtlTransactionManager

### <a name="remarks"></a>Comentários

Os diretórios não podem ser renomeados. Essa função é equivalente ao comando REN.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#18](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_13.cpp)]

##  <a name="seek"></a>Testcfile:: Seek

Reposiciona o ponteiro do arquivo em um arquivo aberto.

```
virtual ULONGLONG Seek(
LONGLONG lOff,
UINT nFrom);
```

### <a name="parameters"></a>parâmetros

*lOff*<br/>
Número de bytes para mover o ponteiro do arquivo. Valores positivos movem o ponteiro do arquivo para o final do arquivo; valores negativos movem o ponteiro do arquivo para o início do arquivo.

*Nde*<br/>
Posição da qual buscar. Consulte a seção comentários para obter os valores possíveis.

### <a name="return-value"></a>Valor retornado

A posição do ponteiro do arquivo se o método foi bem-sucedido; caso contrário, o valor de retorno será indefinido e um ponteiro para uma `CFileException` exceção será gerado.

### <a name="remarks"></a>Comentários

A tabela a seguir lista os possíveis valores para o parâmetro *Nde* .

|Valor|DESCRIÇÃO|
|-----------|-----------------|
|`CFile::begin`|Busque desde o início do arquivo.|
|`CFile::current`|Procure o local atual do ponteiro do arquivo.|
|`CFile::end`|Busque a partir do final do arquivo.|

Quando um arquivo é aberto, o ponteiro do arquivo é posicionado em 0, o início do arquivo.

Você pode definir o ponteiro do arquivo para uma posição além do final de um arquivo. Se você fizer isso, o tamanho do arquivo não aumentará até que você grave no arquivo.

O manipulador de exceção para esse método deve excluir o objeto de exceção depois que a exceção é processada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#9](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_14.cpp)]

##  <a name="seektobegin"></a>Testcfile:: SeekToBegin

Define o valor do ponteiro do arquivo para o início do arquivo.

```
void SeekToBegin();
```

### <a name="remarks"></a>Comentários

`SeekToBegin()` é equivalente a `Seek( 0L, CFile::begin )`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#19](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_15.cpp)]

##  <a name="seektoend"></a>Testcfile:: SeekToEnd

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

##  <a name="setfilepath"></a>RecFile:: SetFilePath

Chame essa função para especificar o caminho do arquivo. Por exemplo, se o caminho de um arquivo não estiver disponível quando um objeto [testcfile](../../mfc/reference/cfile-class.md) for construído, chame `SetFilePath` para fornecê-lo.

```
virtual void SetFilePath(LPCTSTR lpszNewName);
```

### <a name="parameters"></a>parâmetros

*lpszNewName*<br/>
Ponteiro para uma cadeia de caracteres que especifica o novo caminho.

### <a name="remarks"></a>Comentários

> [!NOTE]
> `SetFilePath` não abre o arquivo ou cria o arquivo; Ele simplesmente associa o objeto `CFile` com um nome de caminho, que pode ser usado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#20](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_16.cpp)]

##  <a name="setlength"></a>Testcfile:: SetLength

Chame essa função para alterar o comprimento do arquivo.

```
virtual void SetLength(ULONGLONG dwNewLen);
```

### <a name="parameters"></a>parâmetros

*dwNewLen*<br/>
Comprimento desejado do arquivo em bytes. Esse valor pode ser maior ou menor que o comprimento atual do arquivo. O arquivo será estendido ou truncado conforme apropriado.

### <a name="remarks"></a>Comentários

> [!NOTE]
>  Com `CMemFile`, essa função pode gerar um objeto de `CMemoryException`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#11](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_17.cpp)]

##  <a name="setstatus"></a>RecFile:: SetStatus

Define o status do arquivo associado a esse local de arquivo.

```
static void PASCAL SetStatus(
    LPCTSTR lpszFileName,
    const CFileStatus& status,
    CAtlTransactionManager* pTM = NULL);
```

### <a name="parameters"></a>parâmetros

*lpszFileName*<br/>
Uma cadeia de caracteres que é o caminho para o arquivo desejado. O caminho pode ser relativo ou absoluto e pode conter um nome de rede.

*status*<br/>
O buffer que contém as novas informações de status. Chame a função de membro `GetStatus` para preencher previamente a estrutura de `CFileStatus` com valores atuais e, em seguida, faça as alterações necessárias. Se um valor for 0, o item de status correspondente não será atualizado. Consulte a função de membro [GetStatus](#getstatus) para obter uma descrição da estrutura de `CFileStatus`.

*pTM*<br/>
Ponteiro para objeto CAtlTransactionManager

### <a name="remarks"></a>Comentários

Para definir a hora, modifique o `m_mtime` campo de *status*.

Quando você faz uma chamada para `SetStatus` em uma tentativa de alterar apenas os atributos do arquivo e o membro de `m_mtime` da estrutura de status do arquivo é diferente de zero, os atributos também podem ser afetados (alterar o carimbo de data/hora pode ter efeitos colaterais nos atributos). Se você quiser alterar apenas os atributos do arquivo, primeiro defina o membro `m_mtime` da estrutura de status do arquivo como zero e, em seguida, faça uma chamada para `SetStatus`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#21](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_18.cpp)]

##  <a name="unlockrange"></a>Testcfile:: UnlockRange

Desbloqueia um intervalo de bytes em um arquivo aberto.

```
virtual void UnlockRange(
    ULONGLONG dwPos,
    ULONGLONG dwCount);
```

### <a name="parameters"></a>parâmetros

*dwPos*<br/>
O deslocamento de byte do início do intervalo de bytes a ser desbloqueado.

*dwCount*<br/>
O número de bytes no intervalo a ser desbloqueado.

### <a name="remarks"></a>Comentários

Consulte a descrição da função membro [LockRange](#lockrange) para obter detalhes.

> [!NOTE]
>  Esta função não está disponível para a classe derivada de `CMemFile`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#12](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_8.cpp)]

##  <a name="write"></a>Testcfile:: gravar

Grava dados de um buffer para o arquivo associado ao objeto `CFile`.

```
virtual void Write(
    const void* lpBuf,
    UINT nCount);
```

### <a name="parameters"></a>parâmetros

*lpBuf*<br/>
Um ponteiro para o buffer fornecido pelo usuário que contém os dados a serem gravados no arquivo.

*nCount*<br/>
O número de bytes a serem transferidos do buffer. Para arquivos de modo de texto, os pares de retorno de carro-alimentação de linha são contados como caracteres únicos.

### <a name="remarks"></a>Comentários

`Write` gera uma exceção em resposta a várias condições, incluindo a condição de disco cheio.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#16](../../atl-mfc-shared/reference/codesnippet/cpp/cfile-class_19.cpp)]

Consulte também os exemplos de [testcfile:: RecFile](#cfile) e [testcfile:: Open](#open).

## <a name="see-also"></a>Confira também

[Exemplo de DRAWCLI do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CStdioFile](../../mfc/reference/cstdiofile-class.md)<br/>
[Classe CMemFile](../../mfc/reference/cmemfile-class.md)
