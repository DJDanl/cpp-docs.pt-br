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
ms.openlocfilehash: c60027195024a9abb1af5ce5ec47dc6f6a6bfbf8
ms.sourcegitcommit: f1b051abb1de3fe96350be0563aaf4e960da13c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/27/2018
ms.locfileid: "37038979"
---
# <a name="cinternetfile-class"></a>Classe CInternetFile
Permite acesso a arquivos nos sistemas remotos que usam protocolos de Internet.  
  
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
|[CInternetFile::Close](#close)|Fecha um `CInternetFile` e libera os recursos.|  
|[CInternetFile::Flush](#flush)|Elimina o conteúdo do buffer de gravação e verifica se que os dados na memória são gravados para o computador de destino.|  
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
 Fornece uma classe base para o [CHttpFile](../../mfc/reference/chttpfile-class.md) e [CGopherFile](../../mfc/reference/cgopherfile-class.md) classes de arquivo. Você nunca criar um `CInternetFile` diretamente do objeto. Em vez disso, crie um objeto de uma de suas classes derivadas chamando [CGopherConnection::OpenFile](../../mfc/reference/cgopherconnection-class.md#openfile) ou [CHttpConnection::OpenRequest](../../mfc/reference/chttpconnection-class.md#openrequest). Você também pode criar um `CInternetFile` objeto chamando [CFtpConnection::OpenFile](../../mfc/reference/cftpconnection-class.md#openfile).  
  
 O `CInternetFile` funções de membro `Open`, `LockRange`, `UnlockRange`, e `Duplicate` não são implementadas para `CInternetFile`. Se você chamar essas funções em um `CInternetFile` do objeto, você obterá um [CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md).  
  
 Para saber mais sobre como `CInternetFile` funciona com as outras classes de Internet MFC, consulte o artigo [Internet Programando com WinInet](../../mfc/win32-internet-extensions-wininet.md).  
  
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
 Se você não fechar o arquivo antes de destruir o objeto, o destruidor fecha-lo para você.  
  
 Quando o tratamento de exceções, `Abort` difere [fechar](#close) de duas maneiras importantes. Primeiro, o `Abort` função não lançar uma exceção em falhas porque ignora falhas. Segundo, `Abort` não **ASSERT** se o arquivo não foi aberto ou foi fechado anteriormente.  
  
##  <a name="cinternetfile"></a>  CInternetFile::CInternetFile  
 Essa função de membro é chamada quando um `CInternetFile` objeto é criado.  
  
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
 *hFile*  
 Um identificador para um arquivo da Internet.  
  
 *pstrFileName*  
 Um ponteiro para uma cadeia de caracteres que contém o nome do arquivo.  
  
 *pConnection*  
 Um ponteiro para um [CInternetConnection](../../mfc/reference/cinternetconnection-class.md) objeto.  
  
 *bReadMode*  
 Indica se o arquivo é somente leitura.  
  
 *hSession*  
 Um identificador para uma sessão de Internet.  
  
 *pstrServer*  
 Um ponteiro para uma cadeia de caracteres que contém o nome do servidor.  
  
 *dwContext*  
 O identificador de contexto para o `CInternetFile` objeto. Consulte [Noções básicas de WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.  
  
### <a name="remarks"></a>Comentários  
 Você nunca criar um `CInternetFile` diretamente do objeto. Em vez disso, crie um objeto de uma de suas classes derivadas chamando [CGopherConnection::OpenFile](../../mfc/reference/cgopherconnection-class.md#openfile) ou [CHttpConnection::OpenRequest](../../mfc/reference/chttpconnection-class.md#openrequest). Você também pode criar um `CInternetFile` objeto chamando [CFtpConnection::OpenFile](../../mfc/reference/cftpconnection-class.md#openfile).  
  
##  <a name="close"></a>  CInternetFile::Close  
 Fecha um `CInternetFile` e libera qualquer um dos seus recursos.  
  
```  
virtual void Close();
```  
  
### <a name="remarks"></a>Comentários  
 Se o arquivo foi aberto para gravação, há uma chamada implícita para [liberar](#flush) garantir que todos os dados em buffer é gravado para o host. Você deve chamar **fechar** quando terminar de usar um arquivo.  
  
##  <a name="flush"></a>  CInternetFile::Flush  
 Chame essa função de membro para liberar o conteúdo do buffer de gravação.  
  
```  
virtual void Flush();
```  
  
### <a name="remarks"></a>Comentários  
 Use `Flush` para garantir que todos os dados na memória, na verdade, foi gravado para o computador de destino e para garantir sua transação com a máquina host foi concluída. `Flush` só é eficaz em `CInternetFile` objetos aberta para gravação.  
  
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
 Chamar essa função de membro para ler na memória determinada, começando em *lpvBuf*, o número especificado de bytes, *nCount*.  
  
```  
virtual UINT Read(
    void* lpBuf,  
    UINT nCount);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpBuf*  
 Um ponteiro para um endereço de memória para o qual arquivo de dados são lidos.  
  
 *nCount*  
 O número de bytes a serem gravados.  
  
### <a name="return-value"></a>Valor de retorno  
 O número de bytes transferidos para o buffer. O valor de retorno pode ser menor que *nCount* se o final do arquivo foi atingido.  
  
### <a name="remarks"></a>Comentários  
 A função retorna o número de bytes realmente lidos — um número que pode ser menor que *nCount* se o final do arquivo. Se ocorrer um erro ao ler o arquivo, a função gera uma [CInternetException](../../mfc/reference/cinternetexception-class.md) objeto que descreve o erro. Observe que a leitura ultrapassou o fim do arquivo não é considerada um erro e nenhuma exceção será lançada.  
  
 Para garantir que todos os dados são recuperados, um aplicativo deve continuar a chamar o **CInternetFile::Read** método até que o método retorna zero.  
  
##  <a name="readstring"></a>  CInternetFile::ReadString  
 Chame essa função de membro para ler um fluxo de caracteres até encontrar um caractere de nova linha.  
  
```  
virtual BOOL ReadString(CString& rString);

 
virtual LPTSTR ReadString(
    LPTSTR pstr,  
    UINT nMax);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pstr*  
 Um ponteiro para uma cadeia de caracteres que receberão a linha que está sendo lida.  
  
 *nMax*  
 O número máximo de caracteres a ser lido.  
  
 *rString*  
 Uma referência para o [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto que recebe a linha de leitura.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o buffer que contém dados simples recuperados a partir de [CInternetFile](../../mfc/reference/cinternetfile-class.md) objeto. Independentemente do tipo de dados do buffer passado para este método, não executa qualquer manipulação dos dados (por exemplo, a conversão para Unicode), portanto você deve mapear os dados retornados para a estrutura esperada, como se o **void\***  tipo foram retornados.  
  
 **NULO** se o final do arquivo atingido sem ler todos os dados; ou, se booliano, **FALSE** se o final do arquivo atingido sem ler todos os dados.  
  
### <a name="remarks"></a>Comentários  
 A função colocará a linha resultante para a memória referenciada pelo *pstr* parâmetro. Ele interrompe a leitura dos caracteres quando atingir o número máximo de caracteres, especificado por *nMax*. O buffer sempre recebe um caractere null de terminação.  
  
 Se você chamar `ReadString` sem primeiro chamar [SetReadBufferSize](#setreadbuffersize), você obterá um buffer de 4096 bytes.  
  
##  <a name="seek"></a>  CInternetFile::Seek  
 Chame essa função de membro para reposicionar o ponteiro em um arquivo aberto anteriormente.  
  
```  
virtual ULONGLONG Seek(
    LONGLONG lOffset,  
    UINT nFrom);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lOffset*  
 Deslocamento em bytes para mover o ponteiro de leitura/gravação no arquivo.  
  
 *nFrom*  
 Referência relativa para o deslocamento. Deve ser um dos seguintes valores:  
  
- **CFile::begin** Move o ponteiro do arquivo *lOff* bytes encaminham desde o início do arquivo.  
  
- **CFile::current** Move o ponteiro do arquivo *lOff* bytes a partir da posição atual no arquivo.  
  
- **CFile::end** Move o ponteiro do arquivo *lOff* bytes do final do arquivo. *lOff* deve ser negativo para buscar em existente de arquivos; positivo valores buscará após o fim do arquivo.  
  
### <a name="return-value"></a>Valor de retorno  
 O novo byte deslocamento desde o início do arquivo, se a posição solicitada é legal. Caso contrário, o valor será indefinido e um [CInternetException](../../mfc/reference/cinternetexception-class.md) objeto é gerado.  
  
### <a name="remarks"></a>Comentários  
 O `Seek` função permite acesso aleatório ao conteúdo do arquivo movimentando o ponteiro um valor especificado, com certeza ou relativamente. Na verdade, nenhum dado será lido durante a busca.  
  
 Neste momento, uma chamada para essa função de membro somente há suporte para os dados associados com `CHttpFile` objetos. Não há suporte para solicitações de FTP ou gopher. Se você chamar `Seek` para um desses serviços sem suporte, ele transmite volta para o código de erro do Win32 **ERROR_INTERNET_INVALID_OPERATION**.  
  
 Quando um arquivo é aberto, o ponteiro do arquivo está no deslocamento de 0, o início do arquivo.  
  
> [!NOTE]
>  Usando `Seek` pode fazer com que uma chamada implícita para [liberar](#flush).  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para a implementação da classe base ( [CFile::Seek](../../mfc/reference/cfile-class.md#seek)).  
  
##  <a name="setreadbuffersize"></a>  CInternetFile::SetReadBufferSize  
 Chamar essa função de membro para definir o tamanho do buffer de leitura temporário usado por um `CInternetFile`-objeto derivado.  
  
```  
BOOL SetReadBufferSize(UINT nReadSize);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nReadSize*  
 O tamanho do buffer desejado em bytes.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0. Se a chamada falhar, a função Win32 [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360) pode ser chamado para determinar a causa do erro.  
  
### <a name="remarks"></a>Comentários  
 As APIs do WinInet subjacente não executar armazenamento em buffer, portanto escolha um tamanho de buffer que permite que seu aplicativo ler dados com eficiência, independentemente da quantidade de dados a serem lidos. Se cada chamada para [leitura](#read) normalmente envolve um aount grande de dados (por exemplo, quatro ou mais quilobytes), não é necessário um buffer. No entanto, se você chamar `Read` obter pequenos blocos de dados, ou se você usar [ReadString](#readstring) ler linhas individuais ao mesmo tempo, em seguida, um buffer de leitura melhora o desempenho do aplicativo.  
  
 Por padrão, um `CInternetFile` objeto não fornece nenhum buffer para leitura. Se você chamar esta função de membro, você deve ser-se de que o arquivo foi aberto para acesso de leitura.  
  
 Você pode aumentar o tamanho do buffer a qualquer momento, mas reduzir o buffer não terá efeito. Se você chamar [ReadString](#readstring) sem primeiro chamar `SetReadBufferSize`, você obterá um buffer de 4096 bytes.  
  
##  <a name="setwritebuffersize"></a>  CInternetFile::SetWriteBufferSize  
 Chamar essa função de membro para definir o tamanho do buffer de gravação temporário usado por um `CInternetFile`-objeto derivado.  
  
```  
BOOL SetWriteBufferSize(UINT nWriteSize);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nWriteSize*  
 O tamanho do buffer em bytes.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0. Se a chamada falhar, a função Win32 [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360) pode ser chamado para determinar a causa do erro.  
  
### <a name="remarks"></a>Comentários  
 Portanto subjacente WinInet APIs não executar armazenamento em buffer, escolha um tamanho de buffer que permite que seu aplicativo gravar os dados com eficiência, independentemente da quantidade de dados a serem gravados. Se cada chamada para [gravar](#write) normalmente envolve uma grande quantidade de dados (por exemplo, quilobytes de quatro ou mais por vez), não é necessário um buffer. No entanto, se você chamar [gravar](#write) para escrever pequenos blocos de dados, um buffer de gravação melhora o desempenho do aplicativo.  
  
 Por padrão, um `CInternetFile` objeto não fornece nenhum buffer para gravação. Se você chamar esta função de membro, você deve ser-se de que o arquivo foi aberto para acesso de gravação. Você pode alterar o tamanho do buffer de gravação a qualquer momento, mas isso fizer uma chamada implícita para [liberar](#flush).  
  
##  <a name="write"></a>  CInternetFile::Write  
 Chamar essa função de membro para gravar na memória determinada, *lpvBuf*, o número especificado de bytes, *nCount*.  
  
```  
virtual void Write(
    const void* lpBuf,  
    UINT nCount);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpBuf*  
 Um ponteiro para o primeiro byte a ser gravado.  
  
 *nCount*  
 Especifica o número de bytes a serem gravados.  
  
### <a name="remarks"></a>Comentários  
 Se ocorrer algum erro durante a gravação de dados, a função gera uma [CInternetException](../../mfc/reference/cinternetexception-class.md) objeto que descreve o erro.  
  
##  <a name="writestring"></a>  CInternetFile::WriteString  
 Essa função grava uma cadeia de caracteres terminada em nulo para o arquivo associado.  
  
```  
virtual void WriteString(LPCTSTR pstr);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pstr*  
 Um ponteiro para uma cadeia de caracteres que contém o conteúdo a ser gravado.  
  
### <a name="remarks"></a>Comentários  
 Se ocorrer algum erro durante a gravação de dados, a função gera uma [CInternetException](../../mfc/reference/cinternetexception-class.md) objeto que descreve o erro.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CStdioFile](../../mfc/reference/cstdiofile-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CInternetConnection](../../mfc/reference/cinternetconnection-class.md)
