---
title: Classe CInternetFile | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b28cfffbe3ce8304d12f5a52cd3cf3af7b6679c2
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46406848"
---
# <a name="cinternetfile-class"></a>Classe CInternetFile

Permite acesso aos arquivos em sistemas remotos que usam protocolos de Internet.

## <a name="syntax"></a>Sintaxe

```
class CInternetFile : public CStdioFile
```

## <a name="members"></a>Membros

### <a name="protected-constructors"></a>Construtores Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CInternetFile::CInternetFile](#cinternetfile)|Constrói um objeto `CInternetFile`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CInternetFile::Abort](#abort)|Fecha o arquivo, ignorando todos os erros e avisos.|
|[CInternetFile::Close](#close)|Fecha um `CInternetFile` e libera seus recursos.|
|[CInternetFile::Flush](#flush)|Libera o conteúdo do buffer de gravação e torna-se de que os dados na memória são gravados para o computador de destino.|
|[CInternetFile::GetLength](#getlength)|Retorna o tamanho do arquivo.|
|[CInternetFile::Read](#read)|Lê o número de bytes especificados.|
|[CInternetFile::ReadString](#readstring)|Lê um fluxo de caracteres.|
|[CInternetFile::Seek](#seek)|Reposiciona o ponteiro em um arquivo aberto.|
|[CInternetFile::SetReadBufferSize](#setreadbuffersize)|Define o tamanho do buffer em que os dados serão lidos.|
|[CInternetFile::SetWriteBufferSize](#setwritebuffersize)|Define o tamanho do buffer em que os dados serão gravados.|
|[CInternetFile::Write](#write)|Grava o número de bytes especificados.|
|[CInternetFile::WriteString](#writestring)|Grava uma cadeia de caracteres terminada em nulo em um arquivo.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CInternetFile::operator HINTERNET](#operator_hinternet)|Um operador de conversão para um identificador de Internet.|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|[CInternetFile::m_hFile](#m_hfile)|Um identificador para um arquivo.|

## <a name="remarks"></a>Comentários

Fornece uma classe base para o [CHttpFile](../../mfc/reference/chttpfile-class.md) e [CGopherFile](../../mfc/reference/cgopherfile-class.md) classes de arquivo. Você nunca criará um `CInternetFile` diretamente do objeto. Em vez disso, crie um objeto de uma de suas classes derivadas chamando [CGopherConnection::OpenFile](../../mfc/reference/cgopherconnection-class.md#openfile) ou [CHttpConnection::OpenRequest](../../mfc/reference/chttpconnection-class.md#openrequest). Você também pode criar uma `CInternetFile` objeto chamando [CFtpConnection::OpenFile](../../mfc/reference/cftpconnection-class.md#openfile).

O `CInternetFile` funções de membro `Open`, `LockRange`, `UnlockRange`, e `Duplicate` não são implementadas para `CInternetFile`. Se você chamar essas funções em um `CInternetFile` do objeto, você obterá uma [CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md).

Para saber mais sobre como `CInternetFile` funciona com as outras classes de Internet do MFC, consulte o artigo [Internet Programando com WinInet](../../mfc/win32-internet-extensions-wininet.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CFile](../../mfc/reference/cfile-class.md)

[CStdioFile](../../mfc/reference/cstdiofile-class.md)

`CInternetFile`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxinet.h

##  <a name="abort"></a>  CInternetFile::Abort

Fecha o arquivo associado a este objeto e torna o arquivo não está disponível para leitura ou gravação.

```
virtual void Abort();
```

### <a name="remarks"></a>Comentários

Se você não tiver fechado o arquivo antes de destruir o objeto, o destruidor fecha-lo para você.

Ao lidar com exceções, `Abort` difere [fechar](#close) de duas maneiras importantes. Primeiro, o `Abort` função não gera uma exceção em falhas porque ignora falhas. Segundo, `Abort` não faz isso **ASSERT** se o arquivo não foi aberto ou foi fechado anteriormente.

##  <a name="cinternetfile"></a>  CInternetFile::CInternetFile

Essa função membro é chamada quando um `CInternetFile` objeto é criado.

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

*hFile*<br/>
Um identificador para um arquivo da Internet.

*pstrFileName*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome do arquivo.

*pConnection*<br/>
Um ponteiro para um [CInternetConnection](../../mfc/reference/cinternetconnection-class.md) objeto.

*bReadMode*<br/>
Indica se o arquivo é somente leitura.

*hSession*<br/>
Um identificador para uma sessão da Internet.

*pstrServer*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome do servidor.

*dwContext*<br/>
O identificador de contexto para o `CInternetFile` objeto. Ver [Noções básicas de WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.

### <a name="remarks"></a>Comentários

Você nunca criará um `CInternetFile` diretamente do objeto. Em vez disso, crie um objeto de uma de suas classes derivadas chamando [CGopherConnection::OpenFile](../../mfc/reference/cgopherconnection-class.md#openfile) ou [CHttpConnection::OpenRequest](../../mfc/reference/chttpconnection-class.md#openrequest). Você também pode criar uma `CInternetFile` objeto chamando [CFtpConnection::OpenFile](../../mfc/reference/cftpconnection-class.md#openfile).

##  <a name="close"></a>  CInternetFile::Close

Fecha um `CInternetFile` e libera qualquer um dos seus recursos.

```
virtual void Close();
```

### <a name="remarks"></a>Comentários

Se o arquivo foi aberto para gravação, há uma chamada implícita para [liberar](#flush) garantir que todos os dados em buffer é gravado para o host. Você deve chamar `Close` quando tiver terminado de usar um arquivo.

##  <a name="flush"></a>  CInternetFile::Flush

Chame essa função de membro para liberar o conteúdo do buffer de gravação.

```
virtual void Flush();
```

### <a name="remarks"></a>Comentários

Use `Flush` para garantir que todos os dados na memória, na verdade, foi gravada para o computador de destino e para garantir sua transação com a máquina de host foi concluída. `Flush` só é eficaz em `CInternetFile` objetos aberto para gravação.

##  <a name="getlength"></a>  CInternetFile::GetLength

Retorna o tamanho do arquivo.

```
virtual ULONGLONG GetLength() const;
```

##  <a name="m_hfile"></a>  CInternetFile::m_hFile

Um identificador para o arquivo associado a este objeto.

```
HINTERNET m_hFile;
```

##  <a name="operator_hinternet"></a>  CInternetFile::operator HINTERNET

Use este operador para obter o identificador do Windows para a sessão atual da Internet.

```
operator HINTERNET() const;
```

##  <a name="read"></a>  CInternetFile::Read

Chame essa função de membro para ler na memória fornecida, começando no *lpvBuf*, o número especificado de bytes, *nCount*.

```
virtual UINT Read(
    void* lpBuf,
    UINT nCount);
```

### <a name="parameters"></a>Parâmetros

*lpBuf*<br/>
Um ponteiro para um endereço de memória para o qual arquivo de dados são lidos.

*nCount*<br/>
O número de bytes a serem gravados.

### <a name="return-value"></a>Valor de retorno

O número de bytes transferidos para o buffer. O valor de retorno pode ser menor que *nCount* se o final do arquivo foi atingido.

### <a name="remarks"></a>Comentários

A função retorna o número de bytes realmente lidos — um número que pode ser menor que *nCount* se o final do arquivo. Se ocorrer um erro ao ler o arquivo, a função gerará um [CInternetException](../../mfc/reference/cinternetexception-class.md) objeto que descreve o erro. Observe que a leitura após o final do arquivo não é considerada um erro e nenhuma exceção será lançada.

Para garantir que todos os dados são recuperados, um aplicativo deve continuar a chamar o `CInternetFile::Read` método até que o método retorna zero.

##  <a name="readstring"></a>  CInternetFile::ReadString

Chame essa função de membro para ler um fluxo de caracteres até encontrar um caractere de nova linha.

```
virtual BOOL ReadString(CString& rString);


virtual LPTSTR ReadString(
    LPTSTR pstr,
    UINT nMax);
```

### <a name="parameters"></a>Parâmetros

*pstr*<br/>
Um ponteiro para uma cadeia de caracteres que receberão a linha que está sendo lida.

*Nmáx*<br/>
O número máximo de caracteres a ser lido.

*rString*<br/>
Uma referência para o [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto que recebe a linha de leitura.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o buffer que contém dados simples recuperados a partir de [CInternetFile](../../mfc/reference/cinternetfile-class.md) objeto. Independentemente do tipo de dados do buffer passado para esse método, ele não executa qualquer manipulações nos dados (por exemplo, a conversão para Unicode), portanto, você deve mapear os dados retornados para a estrutura esperada, como se o **void** <strong>\*</strong> tipo foram retornados.

NULL se o final do arquivo foi atingido sem ler todos os dados; ou, se boolean, FALSE se o final do arquivo foi atingido sem ler todos os dados.

### <a name="remarks"></a>Comentários

A função colocará a linha resultante na memória referenciada pela *pstr* parâmetro. Ele interrompe a leitura dos caracteres quando ele atinge o número máximo de caracteres, especificado por *Nmáx*. O buffer sempre recebe um caractere nulo de terminação.

Se você chamar `ReadString` sem primeiro chamar [SetReadBufferSize](#setreadbuffersize), você obterá um buffer de 4096 bytes.

##  <a name="seek"></a>  CInternetFile::Seek

Chame essa função de membro para reposicionar o ponteiro em um arquivo aberto anteriormente.

```
virtual ULONGLONG Seek(
    LONGLONG lOffset,
    UINT nFrom);
```

### <a name="parameters"></a>Parâmetros

*lOffset*<br/>
Deslocamento em bytes para mover o ponteiro de leitura/gravação no arquivo.

*NDE*<br/>
Referência relativa para o deslocamento. Deve ser um dos seguintes valores:

- `CFile::begin` Mova o ponteiro do arquivo *lOff* bytes encaminham desde o início do arquivo.

- `CFile::current` Mova o ponteiro do arquivo *lOff* bytes da posição atual no arquivo.

- `CFile::end` Mova o ponteiro do arquivo *lOff* bytes do final do arquivo. *lOff* deve ser negativo busca no existente de arquivos; positivo de valores serão buscar após o final do arquivo.

### <a name="return-value"></a>Valor de retorno

O byte novo deslocamento do início do arquivo se a posição solicitada é legal. Caso contrário, o valor será indefinido e um [CInternetException](../../mfc/reference/cinternetexception-class.md) objeto é gerado.

### <a name="remarks"></a>Comentários

O `Seek` função permite acesso aleatório ao conteúdo do arquivo, movendo o ponteiro de um valor especificado, forma absoluta ou relativa. Na verdade, nenhum dado será lido durante a busca.

Neste momento, uma chamada para essa função de membro só tem suporte para dados associados `CHttpFile` objetos. Não há suporte para solicitações FTP ou gopher. Se você chamar `Seek` para um desses serviços sem suporte, ele transmite volta para o código de erro Win32 ERROR_INTERNET_INVALID_OPERATION.

Quando um arquivo é aberto, o ponteiro do arquivo está no deslocamento 0, o início do arquivo.

> [!NOTE]
>  Usando o `Seek` pode fazer com que uma chamada implícita para [Flush](#flush).

### <a name="example"></a>Exemplo

  Veja o exemplo de implementação de classe base ( [CFile::Seek](../../mfc/reference/cfile-class.md#seek)).

##  <a name="setreadbuffersize"></a>  CInternetFile::SetReadBufferSize

Chame essa função de membro para definir o tamanho do buffer de leitura temporário usado por um `CInternetFile`-objeto derivado.

```
BOOL SetReadBufferSize(UINT nReadSize);
```

### <a name="parameters"></a>Parâmetros

*nReadSize*<br/>
O tamanho do buffer desejado em bytes.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0. Se a chamada falhar, a função Win32 [GetLastError](https://msdn.microsoft.com/library/windows/desktop/ms679360) pode ser chamado para determinar a causa do erro.

### <a name="remarks"></a>Comentários

As APIs do WinInet subjacente não executar armazenamento em buffer, então, escolha um tamanho de buffer que permite que seu aplicativo ler os dados com eficiência, independentemente da quantidade de dados a serem lidos. Se cada chamada para [leitura](#read) normalmente envolve um aount grande de dados (por exemplo, quatro ou mais quilobytes), não há necessidade de um buffer. No entanto, se você chamar `Read` para obter partes pequenas de dados, ou se você usar [ReadString](#readstring) ler linhas individuais ao mesmo tempo, em seguida, um buffer de leitura melhora o desempenho do aplicativo.

Por padrão, um `CInternetFile` objeto não fornece qualquer armazenamento em buffer para leitura. Se você chamar essa função membro, você deve ter certeza de que o arquivo tiver sido aberto para acesso de leitura.

Você pode aumentar o tamanho do buffer a qualquer momento, mas reduzir o buffer não terá efeito. Se você chamar [ReadString](#readstring) sem primeiro chamar `SetReadBufferSize`, você obterá um buffer de 4096 bytes.

##  <a name="setwritebuffersize"></a>  CInternetFile::SetWriteBufferSize

Chame essa função de membro para definir o tamanho do buffer de gravação temporária usado por um `CInternetFile`-objeto derivado.

```
BOOL SetWriteBufferSize(UINT nWriteSize);
```

### <a name="parameters"></a>Parâmetros

*nWriteSize*<br/>
O tamanho do buffer em bytes.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0. Se a chamada falhar, a função Win32 [GetLastError](https://msdn.microsoft.com/library/windows/desktop/ms679360) pode ser chamado para determinar a causa do erro.

### <a name="remarks"></a>Comentários

Portanto, subjacente APIs WinInet não tiverem um buffer, escolha um tamanho de buffer que permite que seu aplicativo gravar dados com eficiência, independentemente da quantidade de dados a serem gravados. Se cada chamada para [gravar](#write) normalmente envolve uma grande quantidade de dados (por exemplo, quatro ou mais quilobytes por vez), não há necessidade de um buffer. No entanto, se você chamar [gravar](#write) para escrever pequenos blocos de dados, um buffer de gravação melhora o desempenho do aplicativo.

Por padrão, um `CInternetFile` objeto não fornece qualquer armazenamento em buffer para gravação. Se você chamar essa função membro, você deve ter certeza de que o arquivo tiver sido aberto para acesso de gravação. Você pode alterar o tamanho do buffer de gravação a qualquer momento, mas isso fizer uma chamada implícita para [liberar](#flush).

##  <a name="write"></a>  CInternetFile::Write

Chame essa função de membro para gravar na memória do determinado *lpvBuf*, o número especificado de bytes, *nCount*.

```
virtual void Write(
    const void* lpBuf,
    UINT nCount);
```

### <a name="parameters"></a>Parâmetros

*lpBuf*<br/>
Um ponteiro para o primeiro byte a ser gravado.

*nCount*<br/>
Especifica o número de bytes a serem gravados.

### <a name="remarks"></a>Comentários

Se ocorrer algum erro durante a gravação de dados, a função gerará um [CInternetException](../../mfc/reference/cinternetexception-class.md) objeto que descreve o erro.

##  <a name="writestring"></a>  CInternetFile::WriteString

Essa função grava uma cadeia de caracteres terminada em nulo para o arquivo associado.

```
virtual void WriteString(LPCTSTR pstr);
```

### <a name="parameters"></a>Parâmetros

*pstr*<br/>
Um ponteiro para uma cadeia de caracteres que contém o conteúdo a ser gravado.

### <a name="remarks"></a>Comentários

Se ocorrer algum erro durante a gravação de dados, a função gerará um [CInternetException](../../mfc/reference/cinternetexception-class.md) objeto que descreve o erro.

## <a name="see-also"></a>Consulte também

[Classe CStdioFile](../../mfc/reference/cstdiofile-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CInternetConnection](../../mfc/reference/cinternetconnection-class.md)
