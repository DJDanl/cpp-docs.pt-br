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
ms.openlocfilehash: 68a0a0f35d1a1f4519401080f9f207bf76c87079
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69505894"
---
# <a name="cinternetfile-class"></a>Classe CInternetFile

Permite o acesso a arquivos em sistemas remotos que usam protocolos de Internet.

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
|[CInternetFile:: Abort](#abort)|Fecha o arquivo, ignorando todos os avisos e erros.|
|[CInternetFile::Close](#close)|Fecha um `CInternetFile` e libera seus recursos.|
|[CInternetFile::Flush](#flush)|Libera o conteúdo do buffer de gravação e garante que os dados na memória sejam gravados no computador de destino.|
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
|[Operador CInternetFile:: Operator HINTERNET](#operator_hinternet)|Um operador de conversão para um identificador da Internet.|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|[CInternetFile::m_hFile](#m_hfile)|Um identificador para um arquivo.|

## <a name="remarks"></a>Comentários

Fornece uma classe base para as classes de arquivo [CHttpFile](../../mfc/reference/chttpfile-class.md) e [CGopherFile](../../mfc/reference/cgopherfile-class.md) . Você nunca cria um `CInternetFile` objeto diretamente. Em vez disso, crie um objeto de uma de suas classes derivadas chamando [CGopherConnection:: OpenFile](../../mfc/reference/cgopherconnection-class.md#openfile) ou [CHttpConnection:: OpenRequest](../../mfc/reference/chttpconnection-class.md#openrequest). Você também pode criar um `CInternetFile` objeto chamando [CFtpConnection:: OpenFile](../../mfc/reference/cftpconnection-class.md#openfile).

As `CInternetFile` funções `LockRange` `CInternetFile`de membro ,`UnlockRange`, e`Duplicate` não são implementadas para o. `Open` Se você chamar essas funções em um `CInternetFile` objeto, receberá um [CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md).

Para saber mais sobre como `CInternetFile` o funciona com as outras classes de Internet do MFC, confira o artigo [programação da Internet com WinInet](../../mfc/win32-internet-extensions-wininet.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CFile](../../mfc/reference/cfile-class.md)

[CStdioFile](../../mfc/reference/cstdiofile-class.md)

`CInternetFile`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXINET. h

##  <a name="abort"></a>  CInternetFile::Abort

Fecha o arquivo associado a esse objeto e torna o arquivo indisponível para leitura ou gravação.

```
virtual void Abort();
```

### <a name="remarks"></a>Comentários

Se você não fechou o arquivo antes de destruir o objeto, o destruidor o fecha para você.

Ao lidar com exceções `Abort` , o difere [de duas](#close) maneiras importantes. Primeiro, a `Abort` função não gera uma exceção em caso de falhas porque ignora falhas. Em segundo `Abort` lugar, o não **declara** se o arquivo não foi aberto ou foi fechado anteriormente.

##  <a name="cinternetfile"></a>  CInternetFile::CInternetFile

Essa função de membro é chamada quando `CInternetFile` um objeto é criado.

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
Um ponteiro para um objeto [CInternetConnection](../../mfc/reference/cinternetconnection-class.md) .

*bReadMode*<br/>
Indica se o arquivo é somente leitura.

*hSession*<br/>
Um identificador para uma sessão da Internet.

*pstrServer*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome do servidor.

*dwContext*<br/>
O identificador de contexto para `CInternetFile` o objeto. Consulte [noções básicas do Wininet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.

### <a name="remarks"></a>Comentários

Você nunca cria um `CInternetFile` objeto diretamente. Em vez disso, crie um objeto de uma de suas classes derivadas chamando [CGopherConnection:: OpenFile](../../mfc/reference/cgopherconnection-class.md#openfile) ou [CHttpConnection:: OpenRequest](../../mfc/reference/chttpconnection-class.md#openrequest). Você também pode criar um `CInternetFile` objeto chamando [CFtpConnection:: OpenFile](../../mfc/reference/cftpconnection-class.md#openfile).

##  <a name="close"></a>  CInternetFile::Close

Fecha um `CInternetFile` e libera qualquer um de seus recursos.

```
virtual void Close();
```

### <a name="remarks"></a>Comentários

Se o arquivo foi aberto para gravação, há uma chamada implícita para [liberar](#flush) para garantir que todos os dados armazenados em buffer sejam gravados no host. Você deve chamar `Close` quando terminar de usar um arquivo.

##  <a name="flush"></a>  CInternetFile::Flush

Chame essa função de membro para liberar o conteúdo do buffer de gravação.

```
virtual void Flush();
```

### <a name="remarks"></a>Comentários

Use `Flush` para garantir que todos os dados na memória tenham sido realmente gravados no computador de destino e para garantir que sua transação com a máquina host tenha sido concluída. `Flush`Só é eficaz em `CInternetFile` objetos abertos para gravação.

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

##  <a name="operator_hinternet"></a>Operador CInternetFile:: Operator HINTERNET

Use esse operador para obter o identificador do Windows para a sessão atual da Internet.

```
operator HINTERNET() const;
```

##  <a name="read"></a>  CInternetFile::Read

Chame essa função de membro para ler a memória especificada, começando em *lpvBuf*, o número especificado de bytes, *nCount*.

```
virtual UINT Read(
    void* lpBuf,
    UINT nCount);
```

### <a name="parameters"></a>Parâmetros

*lpBuf*<br/>
Um ponteiro para um endereço de memória para o qual os dados de arquivo são lidos.

*nCount*<br/>
O número de bytes a serem gravados.

### <a name="return-value"></a>Valor de retorno

O número de bytes transferidos para o buffer. O valor de retorno pode ser menor que *nCount* se o final do arquivo foi atingido.

### <a name="remarks"></a>Comentários

A função retorna o número de bytes realmente lidos — um número que pode ser menor que *nCount* se o arquivo terminar. Se ocorrer um erro durante a leitura do arquivo, a função lançará um objeto [CInternetException](../../mfc/reference/cinternetexception-class.md) que descreve o erro. Observe que a leitura após o final do arquivo não é considerada um erro e nenhuma exceção será gerada.

Para garantir que todos os dados sejam recuperados, um aplicativo deve continuar `CInternetFile::Read` a chamar o método até que o método retorne zero.

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
Um ponteiro para uma cadeia de caracteres que receberá a linha que está sendo lida.

*nMax*<br/>
O número máximo de caracteres a serem lidos.

*rString*<br/>
Uma referência ao objeto [CString](../../atl-mfc-shared/reference/cstringt-class.md) que recebe a linha de leitura.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o buffer que contém dados simples recuperados do objeto [CInternetFile](../../mfc/reference/cinternetfile-class.md) . Independentemente do tipo de dados do buffer passado para esse método, ele não executa nenhuma manipulação nos dados (por exemplo, conversão para Unicode), portanto, você deve mapear os dados retornados para a estrutura esperada, como se o tipo **void** <strong>\*</strong> fosse exibido.

NULL se o fim do arquivo foi atingido sem ler nenhum dado; ou, se booliano, FALSE se o fim do arquivo foi atingido sem ler nenhum dado.

### <a name="remarks"></a>Comentários

A função coloca a linha resultante na memória referenciada pelo parâmetro *pstr* . Ele para de ler caracteres quando atinge o número máximo de caracteres, especificado por *nmáx*. O buffer sempre recebe um caractere nulo de terminação.

Se você chamar `ReadString` sem primeiro chamar [SetReadBufferSize](#setreadbuffersize), receberá um buffer de 4096 bytes.

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

*nFrom*<br/>
Referência relativa para o deslocamento. Deve ser um dos seguintes valores:

- `CFile::begin`Mova o ponteiro de arquivo *lOff* bytes para frente do início do arquivo.

- `CFile::current`Mova o ponteiro de arquivo *lOff* bytes da posição atual no arquivo.

- `CFile::end`Mova o ponteiro de arquivo *lOff* bytes do final do arquivo. *lOff* deve ser negativo para buscar o arquivo existente; os valores positivos serão procurados após o final do arquivo.

### <a name="return-value"></a>Valor de retorno

O novo deslocamento de byte a partir do início do arquivo se a posição solicitada for legal; caso contrário, o valor será indefinido e um objeto [CInternetException](../../mfc/reference/cinternetexception-class.md) será gerado.

### <a name="remarks"></a>Comentários

A `Seek` função permite acesso aleatório ao conteúdo de um arquivo movendo o ponteiro uma quantidade especificada, absolutamente ou relativamente. Nenhum dado é realmente lido durante a busca.

Neste momento, uma chamada para essa função de membro só tem suporte para dados associados a `CHttpFile` objetos. Não há suporte para solicitações de FTP ou gopher. Se você chamar `Seek` um desses serviços sem suporte, ele será passado para o código de erro Win32 ERROR_INTERNET_INVALID_OPERATION.

Quando um arquivo é aberto, o ponteiro do arquivo está no deslocamento 0, o início do arquivo.

> [!NOTE]
>  O `Seek` uso de pode causar uma chamada implícita para [flush](#flush).

### <a name="example"></a>Exemplo

  Consulte o exemplo para a implementação da classe base ( [testcfile:: Seek](../../mfc/reference/cfile-class.md#seek)).

##  <a name="setreadbuffersize"></a>  CInternetFile::SetReadBufferSize

Chame essa função de membro para definir o tamanho do buffer de leitura temporário usado por `CInternetFile`um objeto derivado.

```
BOOL SetReadBufferSize(UINT nReadSize);
```

### <a name="parameters"></a>Parâmetros

*nReadSize*<br/>
O tamanho do buffer desejado em bytes.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0. Se a chamada falhar, a função do Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) poderá ser chamada para determinar a causa do erro.

### <a name="remarks"></a>Comentários

As APIs do WinInet subjacentes não executam o armazenamento em buffer, portanto, escolha um tamanho de buffer que permita que seu aplicativo leia dados com eficiência, independentemente da quantidade de dados a serem lidos. Se cada chamada para [Read](#read) normalmente envolve um grande aount de dados (por exemplo, quatro ou mais quilobytes), você não deve precisar de um buffer. No entanto, se `Read` você chamar para obter pequenas partes de dados ou se usar [ReadString](#readstring) para ler linhas individuais por vez, um buffer de leitura melhorará o desempenho do aplicativo.

Por padrão, um `CInternetFile` objeto não fornece nenhum buffer para leitura. Se você chamar essa função de membro, deverá ter certeza de que o arquivo foi aberto para acesso de leitura.

Você pode aumentar o tamanho do buffer a qualquer momento, mas reduzir o buffer não terá nenhum efeito. Se você chamar [ReadString](#readstring) sem primeiro chamar `SetReadBufferSize`, receberá um buffer de 4096 bytes.

##  <a name="setwritebuffersize"></a>  CInternetFile::SetWriteBufferSize

Chame essa função de membro para definir o tamanho do buffer de gravação temporário usado por `CInternetFile`um objeto derivado.

```
BOOL SetWriteBufferSize(UINT nWriteSize);
```

### <a name="parameters"></a>Parâmetros

*nWriteSize*<br/>
O tamanho do buffer em bytes.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0. Se a chamada falhar, a função do Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) poderá ser chamada para determinar a causa do erro.

### <a name="remarks"></a>Comentários

As APIs do WinInet subjacentes não executam o buffer, portanto, escolha um tamanho de buffer que permita que seu aplicativo grave dados com eficiência, independentemente da quantidade de dados a serem gravados. Se cada chamada para [Write](#write) normalmente envolver uma grande quantidade de dados (por exemplo, quatro ou mais quilobytes por vez), você não deve precisar de um buffer. No entanto, se você chamar [Write](#write) para gravar pequenas partes de dados, um buffer de gravação melhorará o desempenho do aplicativo.

Por padrão, um `CInternetFile` objeto não fornece nenhum buffer para gravação. Se você chamar essa função de membro, deverá ter certeza de que o arquivo foi aberto para acesso de gravação. Você pode alterar o tamanho do buffer de gravação a qualquer momento, mas fazer isso faz com que uma chamada implícita seja [liberada](#flush).

##  <a name="write"></a>  CInternetFile::Write

Chame essa função de membro para gravar na memória especificada, *lpvBuf*, o número especificado de bytes, *nCount*.

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

Se ocorrer algum erro durante a gravação dos dados, a função lançará um objeto [CInternetException](../../mfc/reference/cinternetexception-class.md) descrevendo o erro.

##  <a name="writestring"></a>  CInternetFile::WriteString

Essa função grava uma cadeia de caracteres terminada em nulo no arquivo associado.

```
virtual void WriteString(LPCTSTR pstr);
```

### <a name="parameters"></a>Parâmetros

*pstr*<br/>
Um ponteiro para uma cadeia de caracteres que contém o conteúdo a ser gravado.

### <a name="remarks"></a>Comentários

Se ocorrer algum erro durante a gravação dos dados, a função lançará um objeto [CInternetException](../../mfc/reference/cinternetexception-class.md) descrevendo o erro.

## <a name="see-also"></a>Consulte também

[Classe CStdioFile](../../mfc/reference/cstdiofile-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CInternetConnection](../../mfc/reference/cinternetconnection-class.md)
