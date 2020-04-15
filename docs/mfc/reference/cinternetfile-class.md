---
title: Classe CInternetFile
ms.date: 11/04/2016
f1_keywords:
- CInternetFile
- AFXINET/CInternetFile
- AFXINET/CInternetFile::CInternetFile
- AFXINET/CInternetFile::Abort
- AFXINET/CInternetFile::Close
- AFXINET/CInternetFile::Flush
- AFXINET/CInternetFile::GetLength
- AFXINET/CInternetFile::Read
- AFXINET/CInternetFile::ReadString
- AFXINET/CInternetFile::Seek
- AFXINET/CInternetFile::SetReadBufferSize
- AFXINET/CInternetFile::SetWriteBufferSize
- AFXINET/CInternetFile::Write
- AFXINET/CInternetFile::WriteString
- AFXINET/CInternetFile::m_hFile
helpviewer_keywords:
- CInternetFile [MFC], CInternetFile
- CInternetFile [MFC], Abort
- CInternetFile [MFC], Close
- CInternetFile [MFC], Flush
- CInternetFile [MFC], GetLength
- CInternetFile [MFC], Read
- CInternetFile [MFC], ReadString
- CInternetFile [MFC], Seek
- CInternetFile [MFC], SetReadBufferSize
- CInternetFile [MFC], SetWriteBufferSize
- CInternetFile [MFC], Write
- CInternetFile [MFC], WriteString
- CInternetFile [MFC], m_hFile
ms.assetid: 96935681-ee71-4a8d-9783-5abc7b3e6f10
ms.openlocfilehash: e3f1a7167f5464423754951764c4441513197841
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372397"
---
# <a name="cinternetfile-class"></a>Classe CInternetFile

Permite acesso a arquivos em sistemas remotos que usam protocolos de Internet.

## <a name="syntax"></a>Sintaxe

```
class CInternetFile : public CStdioFile
```

## <a name="members"></a>Membros

### <a name="protected-constructors"></a>Construtores Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CInternetFile::CInternetFile](#cinternetfile)|Constrói um objeto `CInternetFile`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CInternetFile::Abortar](#abort)|Fecha o arquivo, ignorando todos os avisos e erros.|
|[CInternetFile::Fechar](#close)|Fecha e `CInternetFile` libera seus recursos.|
|[CInternetFile::Flush](#flush)|Libera o conteúdo do buffer de gravação e garante que os dados na memória sejam gravados na máquina de destino.|
|[CInternetFile::GetLength](#getlength)|Retorna o tamanho do arquivo.|
|[CInternetFile::Read](#read)|Lê o número de bytes especificados.|
|[CInternetFile::ReadString](#readstring)|Lê um fluxo de personagens.|
|[CInternetFile::Buscar](#seek)|Reposiciona o ponteiro em um arquivo aberto.|
|[CInternetFile::SetReadBufferSize](#setreadbuffersize)|Define o tamanho do buffer onde os dados serão lidos.|
|[CInternetFile::SetWriteBufferSize](#setwritebuffersize)|Define o tamanho do buffer onde os dados serão gravados.|
|[CInternetFile::Write](#write)|Grava o número de bytes especificados.|
|[CInternetFile::WriteString](#writestring)|Grava uma seqüência de terminadas nula em um arquivo.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CInternetFile::operador HINTERNET](#operator_hinternet)|Um operador de fundição para uma alça de Internet.|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CInternetFile::m_hFile](#m_hfile)|Uma alça para um arquivo.|

## <a name="remarks"></a>Comentários

Fornece uma classe base para as classes de arquivo [CHttpFile](../../mfc/reference/chttpfile-class.md) e [CGopherFile.](../../mfc/reference/cgopherfile-class.md) Você nunca `CInternetFile` cria um objeto diretamente. Em vez disso, crie um objeto de uma de suas classes derivadas chamando [CGopherConnection::OpenFile](../../mfc/reference/cgopherconnection-class.md#openfile) ou [CHttpConnection::OpenRequest](../../mfc/reference/chttpconnection-class.md#openrequest). Você também pode `CInternetFile` criar um objeto chamando [CFtpConnection::OpenFile](../../mfc/reference/cftpconnection-class.md#openfile).

As `CInternetFile` funções `Open` `LockRange`do `UnlockRange`membro, e `Duplicate` `CInternetFile`não são implementadas para . Se você chamar essas `CInternetFile` funções em um objeto, você receberá uma [CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md).

Para saber mais `CInternetFile` sobre como funciona as outras aulas de Internet do MFC, consulte o artigo [Programação na Internet com WinInet](../../mfc/win32-internet-extensions-wininet.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cfile](../../mfc/reference/cfile-class.md)

[Cstdiofile](../../mfc/reference/cstdiofile-class.md)

`CInternetFile`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxinet.h

## <a name="cinternetfileabort"></a><a name="abort"></a>CInternetFile::Abortar

Fecha o arquivo associado a este objeto e torna o arquivo indisponível para leitura ou escrita.

```
virtual void Abort();
```

### <a name="remarks"></a>Comentários

Se você não tiver fechado o arquivo antes de destruir o objeto, o destruidor fecha-o para você.

Ao lidar com `Abort` exceções, difere de [Close](#close) de duas maneiras importantes. Primeiro, `Abort` a função não lança uma exceção em falhas porque ignora falhas. Em `Abort` segundo lugar, não **afirma** se o arquivo não foi aberto ou foi fechado anteriormente.

## <a name="cinternetfilecinternetfile"></a><a name="cinternetfile"></a>CInternetFile::CInternetFile

Essa função de membro `CInternetFile` é chamada quando um objeto é criado.

```
CInternetFile(
    HINTERNET hFile,
    LPCTSTR pstrFileName,
    CInternetConnection* pConnection,
    BOOL bReadMode);

CInternetFile(
    HINTERNET hFile,
    HINTERNET hSession,
    LPCTSTR pstrFileName,
    LPCTSTR pstrServer,
    DWORD_PTR dwContext,
    BOOL bReadMode);
```

### <a name="parameters"></a>Parâmetros

*Hfile*<br/>
Uma alça para um arquivo da Internet.

*pstrFileName*<br/>
Um ponteiro para uma seqüência contendo o nome do arquivo.

*pConnection*<br/>
Um ponteiro para um objeto [CInternetConnection.](../../mfc/reference/cinternetconnection-class.md)

*bReadMode*<br/>
Indica se o arquivo é somente leitura.

*hSession*<br/>
Uma alça para uma sessão de Internet.

*PstrServer*<br/>
Um ponteiro para uma seqüência contendo o nome do servidor.

*Dwcontext*<br/>
O identificador de `CInternetFile` contexto para o objeto. Consulte [o WinInet Basics](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.

### <a name="remarks"></a>Comentários

Você nunca `CInternetFile` cria um objeto diretamente. Em vez disso, crie um objeto de uma de suas classes derivadas chamando [CGopherConnection::OpenFile](../../mfc/reference/cgopherconnection-class.md#openfile) ou [CHttpConnection::OpenRequest](../../mfc/reference/chttpconnection-class.md#openrequest). Você também pode `CInternetFile` criar um objeto chamando [CFtpConnection::OpenFile](../../mfc/reference/cftpconnection-class.md#openfile).

## <a name="cinternetfileclose"></a><a name="close"></a>CInternetFile::Fechar

Fecha e `CInternetFile` libera qualquer um de seus recursos.

```
virtual void Close();
```

### <a name="remarks"></a>Comentários

Se o arquivo foi aberto para gravação, há uma chamada implícita para [Flush](#flush) para garantir que todos os dados tamponados sejam gravados para o host. Você deve `Close` ligar quando terminar de usar um arquivo.

## <a name="cinternetfileflush"></a><a name="flush"></a>CInternetFile::Flush

Chame esta função de membro para lavar o conteúdo do buffer de gravação.

```
virtual void Flush();
```

### <a name="remarks"></a>Comentários

Use `Flush` para garantir que todos os dados na memória foram realmente gravados na máquina de destino e para garantir que sua transação com a máquina host tenha sido concluída. `Flush`só é `CInternetFile` eficaz em objetos abertos para escrita.

## <a name="cinternetfilegetlength"></a><a name="getlength"></a>CInternetFile::GetLength

Retorna o tamanho do arquivo.

```
virtual ULONGLONG GetLength() const;
```

## <a name="cinternetfilem_hfile"></a><a name="m_hfile"></a>CInternetFile::m_hFile

Uma alça para o arquivo associado a este objeto.

```
HINTERNET m_hFile;
```

## <a name="cinternetfileoperator-hinternet"></a><a name="operator_hinternet"></a>CInternetFile::operador HINTERNET

Use este operador para obter o cabo do Windows para a sessão atual da Internet.

```
operator HINTERNET() const;
```

## <a name="cinternetfileread"></a><a name="read"></a>CInternetFile::Read

Chame esta função de membro para ler na memória dada, começando em *lpvBuf*, o número especificado de bytes, *nCount*.

```
virtual UINT Read(
    void* lpBuf,
    UINT nCount);
```

### <a name="parameters"></a>Parâmetros

*Lpbuf*<br/>
Um ponteiro para um endereço de memória para o qual os dados do arquivo são lidos.

*Ncount*<br/>
O número de bytes a serem escritos.

### <a name="return-value"></a>Valor retornado

O número de bytes transferidos para o buffer. O valor de devolução pode ser menor que *o nCount* se o final do arquivo for atingido.

### <a name="remarks"></a>Comentários

A função retorna o número de bytes realmente lidos — um número que pode ser menor que *o nCount* se o arquivo terminar. Se ocorrer um erro durante a leitura do arquivo, a função lançará um objeto [CInternetException](../../mfc/reference/cinternetexception-class.md) que descreve o erro. Observe que a leitura após o final do arquivo não é considerada um erro e nenhuma exceção será lançada.

Para garantir que todos os dados sejam recuperados, um aplicativo deve continuar a chamar o `CInternetFile::Read` método até que o método retorne zero.

## <a name="cinternetfilereadstring"></a><a name="readstring"></a>CInternetFile::ReadString

Chame esta função de membro para ler um fluxo de caracteres até encontrar um caractere newline.

```
virtual BOOL ReadString(CString& rString);

virtual LPTSTR ReadString(
    LPTSTR pstr,
    UINT nMax);
```

### <a name="parameters"></a>Parâmetros

*pstr*<br/>
Um ponteiro para uma seqüência que receberá a linha que está sendo lida.

*Nmax*<br/>
O número máximo de caracteres a serem lidos.

*rString*<br/>
Uma referência ao objeto [CString](../../atl-mfc-shared/reference/cstringt-class.md) que recebe a linha de leitura.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o buffer contendo dados simples recuperados do objeto [CInternetFile.](../../mfc/reference/cinternetfile-class.md) Independentemente do tipo de dados do buffer passado para este método, ele não realiza nenhuma manipulação nos dados (por exemplo, conversão para Unicode), então você deve mapear os dados retornados para a estrutura que você espera, como se o tipo **de vazio** <strong>\*</strong> fosse devolvido.

NULO se o fim do arquivo foi alcançado sem ler nenhum dado; ou, se booleano, FALSO se o fim do arquivo foi alcançado sem ler nenhum dado.

### <a name="remarks"></a>Comentários

A função coloca a linha resultante na memória referenciada pelo parâmetro *pstr.* Ele pára de ler caracteres quando atinge o número máximo de caracteres, especificado por *nMax*. O buffer sempre recebe um caractere nulo final.

Se você `ReadString` ligar sem antes chamar [SetReadBufferSize,](#setreadbuffersize)você receberá um buffer de 4096 bytes.

## <a name="cinternetfileseek"></a><a name="seek"></a>CInternetFile::Buscar

Chame esta função de membro para reposicionar o ponteiro em um arquivo aberto anteriormente.

```
virtual ULONGLONG Seek(
    LONGLONG lOffset,
    UINT nFrom);
```

### <a name="parameters"></a>Parâmetros

*LOffset*<br/>
Deslocamento em bytes para mover o ponteiro de leitura/gravação no arquivo.

*nFrom*<br/>
Referência relativa para o deslocamento. Deve ser um dos seguintes valores: 

- `CFile::begin`Mova o ponteiro do arquivo *lOff* bytes para a frente desde o início do arquivo.

- `CFile::current`Mova o ponteiro do arquivo *lOff* bytes da posição atual no arquivo.

- `CFile::end`Mova o ponteiro do arquivo *lOff* bytes a partir do final do arquivo. *lOff* deve ser negativo para procurar no arquivo existente; valores positivos buscarão além do fim do arquivo.

### <a name="return-value"></a>Valor retornado

O novo byte offset desde o início do arquivo se a posição solicitada for legal; caso contrário, o valor é indefinido e um objeto [CInternetException](../../mfc/reference/cinternetexception-class.md) é lançado.

### <a name="remarks"></a>Comentários

A `Seek` função permite acesso aleatório ao conteúdo de um arquivo movendo o ponteiro uma quantidade especificada, absolutamente ou relativamente. Nenhum dado é realmente lido durante a busca.

Neste momento, uma chamada para esta função de membro `CHttpFile` é suportada apenas para dados associados a objetos. Não é suportado para pedidos ftp ou gopher. Se você `Seek` chamar por um desses serviços sem suporte, ele irá repassá-lo para o código de erro Win32 ERROR_INTERNET_INVALID_OPERATION.

Quando um arquivo é aberto, o ponteiro do arquivo está no offset 0, o início do arquivo.

> [!NOTE]
> O `Seek` uso pode causar uma chamada implícita para [Flush](#flush).

### <a name="example"></a>Exemplo

  Veja o exemplo da implementação da classe base [(CFile::Seek](../../mfc/reference/cfile-class.md#seek)).

## <a name="cinternetfilesetreadbuffersize"></a><a name="setreadbuffersize"></a>CInternetFile::SetReadBufferSize

Chame esta função de membro para definir o `CInternetFile`tamanho do buffer de leitura temporária usado por um objeto derivado.

```
BOOL SetReadBufferSize(UINT nReadSize);
```

### <a name="parameters"></a>Parâmetros

*nReadSize*<br/>
O tamanho do buffer desejado em bytes.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0. Se a chamada falhar, a função Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) pode ser chamada para determinar a causa do erro.

### <a name="remarks"></a>Comentários

As APIs wininet subjacentes não executam buffering, então escolha um tamanho de buffer que permita que seu aplicativo leia dados de forma eficiente, independentemente da quantidade de dados a serem lidos. Se cada chamada para [Ler](#read) normalmente envolve um grande aount de dados (por exemplo, quatro ou mais kilobytes), você não deve precisar de um buffer. No entanto, `Read` se você ligar para obter pequenos pedaços de dados ou se você usar [o ReadString](#readstring) para ler linhas individuais de cada vez, então um buffer de leitura melhora o desempenho do aplicativo.

Por padrão, `CInternetFile` um objeto não fornece nenhum buffer para leitura. Se você chamar esta função de membro, você deve ter certeza de que o arquivo foi aberto para acesso à leitura.

Você pode aumentar o tamanho do buffer a qualquer momento, mas encolher o buffer não terá efeito. Se você chamar [ReadString](#readstring) sem antes ligar, `SetReadBufferSize`você receberá um buffer de 4096 bytes.

## <a name="cinternetfilesetwritebuffersize"></a><a name="setwritebuffersize"></a>CInternetFile::SetWriteBufferSize

Chame esta função de membro para definir o `CInternetFile`tamanho do buffer de gravação temporário usado por um objeto derivado.

```
BOOL SetWriteBufferSize(UINT nWriteSize);
```

### <a name="parameters"></a>Parâmetros

*nWriteSize*<br/>
O tamanho do buffer em bytes.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0. Se a chamada falhar, a função Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) pode ser chamada para determinar a causa do erro.

### <a name="remarks"></a>Comentários

As APIs wininet subjacentes não executam buffering, então escolha um tamanho de buffer que permita que seu aplicativo escreva dados de forma eficiente, independentemente da quantidade de dados a serem gravados. Se cada chamada para [gravar](#write) normalmente envolve uma grande quantidade de dados (por exemplo, quatro ou mais kilobytes de cada vez), você não deve precisar de um buffer. No entanto, se você chamar [Write](#write) para gravar pequenos pedaços de dados, um buffer de gravação melhora o desempenho do aplicativo.

Por padrão, `CInternetFile` um objeto não fornece nenhum buffer para gravação. Se você chamar esta função de membro, você deve ter certeza de que o arquivo foi aberto para acesso à gravação. Você pode alterar o tamanho do buffer de gravação a qualquer momento, mas fazê-lo causa uma chamada implícita para [Flush](#flush).

## <a name="cinternetfilewrite"></a><a name="write"></a>CInternetFile::Write

Chame esta função de membro para escrever na memória dada, *lpvBuf*, o número especificado de bytes, *nCount*.

```
virtual void Write(
    const void* lpBuf,
    UINT nCount);
```

### <a name="parameters"></a>Parâmetros

*Lpbuf*<br/>
Um ponteiro para o primeiro byte a ser escrito.

*Ncount*<br/>
Especifica o número de bytes a serem escritos.

### <a name="remarks"></a>Comentários

Se ocorrer algum erro ao escrever os dados, a função lançará um objeto [CInternetException](../../mfc/reference/cinternetexception-class.md) descrevendo o erro.

## <a name="cinternetfilewritestring"></a><a name="writestring"></a>CInternetFile::WriteString

Esta função grava uma seqüência de terminadas nula para o arquivo associado.

```
virtual void WriteString(LPCTSTR pstr);
```

### <a name="parameters"></a>Parâmetros

*pstr*<br/>
Um ponteiro para uma seqüência contendo o conteúdo a ser escrito.

### <a name="remarks"></a>Comentários

Se ocorrer algum erro ao escrever os dados, a função lançará um objeto [CInternetException](../../mfc/reference/cinternetexception-class.md) descrevendo o erro.

## <a name="see-also"></a>Confira também

[Classe CStdioFile](../../mfc/reference/cstdiofile-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CInternetConnection](../../mfc/reference/cinternetconnection-class.md)
