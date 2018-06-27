---
title: Classe CFileFind | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CFileFind
- AFX/CFileFind
- AFX/CFileFind::CFileFind
- AFX/CFileFind::Close
- AFX/CFileFind::FindFile
- AFX/CFileFind::FindNextFile
- AFX/CFileFind::GetCreationTime
- AFX/CFileFind::GetFileName
- AFX/CFileFind::GetFilePath
- AFX/CFileFind::GetFileTitle
- AFX/CFileFind::GetFileURL
- AFX/CFileFind::GetLastAccessTime
- AFX/CFileFind::GetLastWriteTime
- AFX/CFileFind::GetLength
- AFX/CFileFind::GetRoot
- AFX/CFileFind::IsArchived
- AFX/CFileFind::IsCompressed
- AFX/CFileFind::IsDirectory
- AFX/CFileFind::IsDots
- AFX/CFileFind::IsHidden
- AFX/CFileFind::IsNormal
- AFX/CFileFind::IsReadOnly
- AFX/CFileFind::IsSystem
- AFX/CFileFind::IsTemporary
- AFX/CFileFind::MatchesMask
- AFX/CFileFind::CloseContext
- AFX/CFileFind::m_pTM
dev_langs:
- C++
helpviewer_keywords:
- CFileFind [MFC], CFileFind
- CFileFind [MFC], Close
- CFileFind [MFC], FindFile
- CFileFind [MFC], FindNextFile
- CFileFind [MFC], GetCreationTime
- CFileFind [MFC], GetFileName
- CFileFind [MFC], GetFilePath
- CFileFind [MFC], GetFileTitle
- CFileFind [MFC], GetFileURL
- CFileFind [MFC], GetLastAccessTime
- CFileFind [MFC], GetLastWriteTime
- CFileFind [MFC], GetLength
- CFileFind [MFC], GetRoot
- CFileFind [MFC], IsArchived
- CFileFind [MFC], IsCompressed
- CFileFind [MFC], IsDirectory
- CFileFind [MFC], IsDots
- CFileFind [MFC], IsHidden
- CFileFind [MFC], IsNormal
- CFileFind [MFC], IsReadOnly
- CFileFind [MFC], IsSystem
- CFileFind [MFC], IsTemporary
- CFileFind [MFC], MatchesMask
- CFileFind [MFC], CloseContext
- CFileFind [MFC], m_pTM
ms.assetid: 9990068c-b023-4114-9580-a50182d15240
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: de63a53e23f4ea22a6fe8df7ab55bfc57d409779
ms.sourcegitcommit: c6b095c5f3de7533fd535d679bfee0503e5a1d91
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/26/2018
ms.locfileid: "36955070"
---
# <a name="cfilefind-class"></a>Classe CFileFind
Realiza pesquisas de arquivos local e é a classe base para [CGopherFileFind](../../mfc/reference/cgopherfilefind-class.md) e [CFtpFileFind](../../mfc/reference/cftpfilefind-class.md), que executar pesquisas de arquivos da Internet.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CFileFind : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFileFind::CFileFind](#cfilefind)|Constrói um objeto `CFileFind`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFileFind::Close](#close)|Fecha a solicitação de pesquisa.|  
|[CFileFind::FindFile](#findfile)|Pesquisa um diretório para um nome de arquivo especificado.|  
|[CFileFind::FindNextFile](#findnextfile)|Continua uma pesquisa de arquivo de uma chamada anterior para [FindFile](#findfile).|  
|[CFileFind::GetCreationTime](#getcreationtime)|Obtém a hora em que o arquivo foi criado.|  
|[CFileFind::GetFileName](#getfilename)|Obtém o nome, incluindo a extensão, do arquivo localizado|  
|[CFileFind::GetFilePath](#getfilepath)|Obtém o caminho completo do arquivo encontrado.|  
|[CFileFind::GetFileTitle](#getfiletitle)|Obtém o título do arquivo localizado. O título não inclui a extensão.|  
|[CFileFind::GetFileURL](#getfileurl)|Obtém a URL, incluindo o caminho do arquivo, do arquivo encontrado.|  
|[CFileFind::GetLastAccessTime](#getlastaccesstime)|Obtém a hora em que o arquivo foi acessado pela última vez.|  
|[CFileFind::GetLastWriteTime](#getlastwritetime)|Obtém a hora em que o arquivo foi alterado e salvo de última.|  
|[CFileFind::GetLength](#getlength)|Obtém o comprimento do arquivo localizado, em bytes.|  
|[CFileFind::GetRoot](#getroot)|Obtém o diretório raiz do arquivo encontrado.|  
|[CFileFind::IsArchived](#isarchived)|Determina se o arquivo encontrado é arquivado.|  
|[CFileFind::IsCompressed](#iscompressed)|Determina se o arquivo encontrado é compactado.|  
|[CFileFind::IsDirectory](#isdirectory)|Determina se o arquivo encontrado é um diretório.|  
|[CFileFind::IsDots](#isdots)|Determina se o nome do arquivo localizado tem o nome "."ou"...", indicando que é, na verdade, um diretório.|  
|[CFileFind::IsHidden](#ishidden)|Determina se o arquivo encontrado é oculto.|  
|[CFileFind::IsNormal](#isnormal)|Determina se o arquivo encontrado é normal (em outras palavras, não tiver outros atributos).|  
|[CFileFind::IsReadOnly](#isreadonly)|Determina se o arquivo encontrado é somente leitura.|  
|[CFileFind::IsSystem](#issystem)|Determina se o arquivo encontrado é um arquivo do sistema.|  
|[CFileFind::IsTemporary](#istemporary)|Determina se o arquivo encontrado é temporário.|  
|[CFileFind::MatchesMask](#matchesmask)|Indica os atributos de arquivo desejados do arquivo a ser localizado.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFileFind::CloseContext](#closecontext)|Fecha o arquivo especificado pelo identificador de pesquisa atual.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFileFind::m_pTM](#m_ptm)|Ponteiro para uma `CAtlTransactionManager` objeto.|  
  
## <a name="remarks"></a>Comentários  
 `CFileFind` inclui funções de membro que iniciar uma pesquisa, localize um arquivo e retornam o título, nome ou caminho do arquivo. Para pesquisas na Internet, a função de membro [GetFileURL](#getfileurl) retorna a URL do arquivo.  
  
 `CFileFind` a classe base para duas outras classes MFC deve pesquisar tipos de servidor específico: `CGopherFileFind` funciona especificamente com servidores gopher, e `CFtpFileFind` funciona especificamente com servidores de FTP. Juntos, esses três classes fornecem um mecanismo perfeito para o cliente localizar os arquivos, independentemente do protocolo de servidor, o tipo de arquivo ou local, em um computador local ou em um servidor remoto.  
  
 O código a seguir irá enumerar todos os arquivos no diretório atual, imprimindo o nome de cada arquivo:  
  
 [!code-cpp[NVC_MFCFiles#31](../../atl-mfc-shared/reference/codesnippet/cpp/cfilefind-class_1.cpp)]  
  
 Para manter o exemplo simples, esse código usa a biblioteca padrão C++ `cout` classe. O `cout` linha pode ser substituída por uma chamada para `CListBox::AddString`, por exemplo, em um programa com uma interface gráfica do usuário.  
  
 Para obter mais informações sobre como usar `CFileFind` e as outras classes WinInet, consulte o artigo [Internet Programando com WinInet](../../mfc/win32-internet-extensions-wininet.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CFileFind`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX  
  
##  <a name="cfilefind"></a>  CFileFind::CFileFind  
 Essa função de membro é chamada quando um `CFileFind` objeto for construído.  
  
```  
CFileFind();  
CFileFind(CAtlTransactionManager* pTM);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pTM*  
 Ponteiro para objeto CAtlTransactionManager  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CFileFind::GetFileName](#getfilename).  
  
##  <a name="close"></a>  CFileFind::Close  
 Chame essa função de membro para encerrar a pesquisa, redefinir o contexto e liberar todos os recursos.  
  
```  
void Close();
```  
  
### <a name="remarks"></a>Comentários  
 Depois de chamar **fechar**, você não precisa criar um novo `CFileFind` instância antes de chamar [FindFile](#findfile) para iniciar uma nova pesquisa.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CFileFind::GetFileName](#getfilename).  
  
##  <a name="closecontext"></a>  CFileFind::CloseContext  
 Fecha o arquivo especificado pelo identificador de pesquisa atual.  
  
```  
virtual void CloseContext();
```  
  
### <a name="remarks"></a>Comentários  
 Fecha o arquivo especificado pelo valor atual do identificador de pesquisa. Substitua esta função para alterar o comportamento padrão.  
  
 Você deve chamar o [FindFile](#findfile) ou [FindNextFile](#findnextfile) funções pelo menos uma vez para recuperar um identificador de pesquisa válido. O `FindFile` e `FindNextFile` funções usam o identificador de pesquisa para localizar arquivos com nomes que correspondem a um determinado nome.  
  
##  <a name="findfile"></a>  CFileFind::FindFile  
 Chame essa função de membro para abrir uma pesquisa de arquivos.  
  
```  
virtual BOOL FindFile(
    LPCTSTR pstrName = NULL,  
    DWORD dwUnused = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pstrName*  
 Um ponteiro para uma cadeia de caracteres que contém o nome do arquivo a ser localizado. Se você passar **nulo** para *pstrName*, **FindFile** um caractere curinga (*.\*) a pesquisa.  
  
 *dwUnused*  
 Reservado para tornar `FindFile` polimórfico com classes derivadas. Deve ser 0.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0. Para obter mais informações sobre o erro, chame a função Win32 [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360).  
  
### <a name="remarks"></a>Comentários  
 Depois de chamar `FindFile` para iniciar a pesquisa de arquivo, chame [FindNextFile](#findnextfile) para recuperar os arquivos posteriores. Você deve chamar `FindNextFile` pelo menos uma vez antes de chamar funções de membro a qualquer um dos seguinte atributo:  
  
- [GetCreationTime](#getcreationtime)  
  
- [GetFileName](#getfilename)  
  
- [GetFileTitle](#getfiletitle)  
  
- [GetFilePath](#getfilepath)  
  
- [GetFileURL](#getfileurl)  
  
- [GetLastAccessTime](#getlastaccesstime)  
  
- [GetLastWriteTime](#getlastwritetime)  
  
- [GetLength](#getlength)  
  
- [GetRoot](#getroot)  
  
- [IsArchived](#isarchived)  
  
- [IsCompressed](#iscompressed)  
  
- [IsDirectory](#isdirectory)  
  
- [IsDots](#isdots)  
  
- [IsHidden](#ishidden)  
  
- [IsNormal](#isnormal)  
  
- [IsReadOnly](#isreadonly)  
  
- [IsSystem](#issystem)  
  
- [IsTemporary](#istemporary)  
  
- [MatchesMask](#matchesmask)  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CFileFind::IsDirectory](#isdirectory).  
  
##  <a name="findnextfile"></a>  CFileFind::FindNextFile  
 Chamar essa função de membro para continuar a pesquisa de um arquivo de uma chamada anterior para [FindFile](#findfile).  
  
```  
virtual BOOL FindNextFile();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se houver mais arquivos; zero se o arquivo encontrado é o último no diretório ou se ocorreu um erro. Para obter mais informações sobre o erro, chame a função Win32 [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360). Se o arquivo encontrado é o último arquivo no diretório, ou se nenhuma correspondência de arquivos podem ser encontrados, o `GetLastError` função retorna ERROR_NO_MORE_FILES.  
  
### <a name="remarks"></a>Comentários  
 Você deve chamar `FindNextFile` pelo menos uma vez antes de chamar funções de membro a qualquer um dos seguinte atributo:  
  
- [GetCreationTime](#getcreationtime)  
  
- [GetFileName](#getfilename)  
  
- [GetFileTitle](#getfiletitle)  
  
- [GetFilePath](#getfilepath)  
  
- [GetFileURL](#getfileurl)  
  
- [GetLastAccessTime](#getlastaccesstime)  
  
- [GetLastWriteTime](#getlastwritetime)  
  
- [GetLength](#getlength)  
  
- [GetRoot](#getroot)  
  
- [IsArchived](#isarchived)  
  
- [IsCompressed](#iscompressed)  
  
- [IsDirectory](#isdirectory)  
  
- [IsDots](#isdots)  
  
- [IsHidden](#ishidden)  
  
- [IsNormal](#isnormal)  
  
- [IsReadOnly](#isreadonly)  
  
- [IsSystem](#issystem)  
  
- [IsTemporary](#istemporary)  
  
- [MatchesMask](#matchesmask)  
  
 `FindNextFile` Ajusta a função Win32 [FindNextFile](http://msdn.microsoft.com/library/windows/desktop/aa364428).  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CFileFind::IsDirectory](#isdirectory).  
  
##  <a name="getcreationtime"></a>  CFileFind::GetCreationTime  
 Chame essa função de membro para obter a hora em que o arquivo especificado foi criado.  
  
```  
virtual BOOL GetCreationTime(FILETIME* pTimeStamp) const;  
virtual BOOL GetCreationTime(CTime& refTime) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *pTimeStamp*  
 Um ponteiro para um [FILETIME](http://msdn.microsoft.com/library/windows/desktop/ms724284) estrutura que contém a hora em que o arquivo foi criado.  
  
 *refTime*  
 Uma referência a um [CTime](../../atl-mfc-shared/reference/ctime-class.md) objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; 0 se não houver êxito. `GetCreationTime` Retorna 0 somente se [FindNextFile](#findnextfile) nunca foi chamado neste `CFileFind` objeto.  
  
### <a name="remarks"></a>Comentários  
 Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes de chamar `GetCreationTime`.  
  
> [!NOTE]
>  Nem todos os sistemas de arquivos usam a mesma semântica para implementar o carimbo de hora retornado por essa função. Esta função pode retornar o mesmo valor retornado por outras funções de carimbo de data / hora, se o sistema de arquivos subjacente ou o servidor não der suporte a manter o atributo de tempo. Consulte o [Win32_FIND_DATA](http://msdn.microsoft.com/library/windows/desktop/aa365740) estrutura para obter informações sobre formatos de hora. Em alguns sistemas de operação, a hora retornada está na hora local da zona para a máquina foi o arquivo está localizado. Consulte o Win32 [FileTimeToLocalFileTime](http://msdn.microsoft.com/library/windows/desktop/ms724277) API para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CFileFind::GetLength](#getlength).  
  
##  <a name="getfilename"></a>  CFileFind::GetFileName  
 Chame essa função de membro para obter o nome do arquivo encontrado.  
  
```  
virtual CString GetFileName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O nome do arquivo encontrado mais recentemente.  
  
### <a name="remarks"></a>Comentários  
 Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes de chamar GetFileName.  
  
 `GetFileName` é um dos três `CFileFind` funções de membro que retornam alguma forma do nome do arquivo. A lista a seguir descreve os três e como eles podem variar:  
  
- `GetFileName` Retorna o nome do arquivo, incluindo a extensão. Por exemplo, chamar `GetFileName` para gerar uma mensagem do usuário sobre o arquivo `c:\myhtml\myfile.txt` retorna o nome do arquivo `myfile.txt`.  
  
- [GetFilePath](#getfilepath) retorna o caminho completo para o arquivo. Por exemplo, chamar `GetFilePath` para gerar uma mensagem do usuário sobre o arquivo `c:\myhtml\myfile.txt` retorna o caminho do arquivo `c:\myhtml\myfile.txt`.  
  
- [GetFileTitle](#getfiletitle) retorna o nome do arquivo, excluindo a extensão de arquivo. Por exemplo, chamar `GetFileTitle` para gerar uma mensagem do usuário sobre o arquivo `c:\myhtml\myfile.txt` retorna o nome do arquivo `myfile`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCFiles#32](../../atl-mfc-shared/reference/codesnippet/cpp/cfilefind-class_2.cpp)]  
  
##  <a name="getfilepath"></a>  CFileFind::GetFilePath  
 Chame essa função de membro para obter o caminho completo do arquivo especificado.  
  
```  
virtual CString GetFilePath() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O caminho do arquivo especificado.  
  
### <a name="remarks"></a>Comentários  
 Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes de chamar `GetFilePath`.  
  
 `GetFilePath` é um dos três `CFileFind` funções de membro que retornam alguma forma do nome do arquivo. A lista a seguir descreve os três e como eles podem variar:  
  
- [GetFileName](#getfilename) retorna o nome de arquivo, incluindo a extensão. Por exemplo, chamar `GetFileName` para gerar uma mensagem do usuário sobre o arquivo `c:\myhtml\myfile.txt` retorna o nome do arquivo `myfile.txt`.  
  
- `GetFilePath` Retorna o caminho completo para o arquivo. Por exemplo, chamar `GetFilePath` para gerar uma mensagem do usuário sobre o arquivo `c:\myhtml\myfile.txt` retorna o caminho do arquivo `c:\myhtml\myfile.txt`.  
  
- [GetFileTitle](#getfiletitle) retorna o nome do arquivo, excluindo a extensão de arquivo. Por exemplo, chamar `GetFileTitle` para gerar uma mensagem do usuário sobre o arquivo `c:\myhtml\myfile.txt` retorna o nome do arquivo `myfile`.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CFileFind::GetFileName](#getfilename).  
  
##  <a name="getfiletitle"></a>  CFileFind::GetFileTitle  
 Chame essa função de membro para obter o título do arquivo localizado.  
  
```  
virtual CString GetFileTitle() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O título do arquivo.  
  
### <a name="remarks"></a>Comentários  
 Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes de chamar `GetFileTitle`.  
  
 `GetFileTitle` é um dos três `CFileFind` funções de membro que retornam alguma forma do nome do arquivo. A lista a seguir descreve os três e como eles podem variar:  
  
- [GetFileName](#getfilename) retorna o nome de arquivo, incluindo a extensão. Por exemplo, chamar `GetFileName` para gerar uma mensagem do usuário sobre o arquivo `c:\myhtml\myfile.txt` retorna o nome do arquivo `myfile.txt`.  
  
- [GetFilePath](#getfilepath) retorna o caminho completo para o arquivo. Por exemplo, chamar `GetFilePath` para gerar uma mensagem do usuário sobre o arquivo `c:\myhtml\myfile.txt` retorna o caminho do arquivo `c:\myhtml\myfile.txt`.  
  
- `GetFileTitle` Retorna o nome do arquivo, excluindo a extensão de arquivo. Por exemplo, chamar `GetFileTitle` para gerar uma mensagem do usuário sobre o arquivo `c:\myhtml\myfile.txt` retorna o nome do arquivo `myfile`.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CFileFind::GetFileName](#getfilename).  
  
##  <a name="getfileurl"></a>  CFileFind::GetFileURL  
 Chame essa função de membro para recuperar a URL especificada.  
  
```  
virtual CString GetFileURL() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A URL completa.  
  
### <a name="remarks"></a>Comentários  
 Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes de chamar `GetFileURL`.  
  
 `GetFileURL` é semelhante à função de membro [GetFilePath](#getfilepath), exceto que ela retorna a URL do formulário `file://path`. Por exemplo, chamar `GetFileURL` para obter a URL completa para `myfile.txt` retorna a URL `file://c:\myhtml\myfile.txt`.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CFileFind::GetFileName](#getfilename).  
  
##  <a name="getlastaccesstime"></a>  CFileFind::GetLastAccessTime  
 Chame essa função de membro para obter a hora em que o arquivo especificado foi acessado pela última vez.  
  
```  
virtual BOOL GetLastAccessTime(CTime& refTime) const;  
virtual BOOL GetLastAccessTime(FILETIME* pTimeStamp) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *refTime*  
 Uma referência a um [CTime](../../atl-mfc-shared/reference/ctime-class.md) objeto.  
  
 *pTimeStamp*  
 Um ponteiro para um [FILETIME](http://msdn.microsoft.com/library/windows/desktop/ms724284) estrutura que contém a hora em que o arquivo foi acessado pela última vez.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; 0 se não houver êxito. `GetLastAccessTime` Retorna 0 somente se [FindNextFile](#findnextfile) nunca foi chamado neste `CFileFind` objeto.  
  
### <a name="remarks"></a>Comentários  
 Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes de chamar `GetLastAccessTime`.  
  
> [!NOTE]
>  Nem todos os sistemas de arquivos usam a mesma semântica para implementar o carimbo de hora retornado por essa função. Esta função pode retornar o mesmo valor retornado por outras funções de carimbo de data / hora, se o sistema de arquivos subjacente ou o servidor não der suporte a manter o atributo de tempo. Consulte o [Win32_FIND_DATA](http://msdn.microsoft.com/library/windows/desktop/aa365740) estrutura para obter informações sobre formatos de hora. Em alguns sistemas de operação, a hora retornada está na hora local da zona para a máquina foi o arquivo está localizado. Consulte o Win32 [FileTimeToLocalFileTime](http://msdn.microsoft.com/library/windows/desktop/ms724277) API para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CFileFind::GetLength](#getlength).  
  
##  <a name="getlastwritetime"></a>  CFileFind::GetLastWriteTime  
 Chame essa função de membro para obter a última vez em que o arquivo foi alterado.  
  
```  
virtual BOOL GetLastWriteTime(FILETIME* pTimeStamp) const;  
virtual BOOL GetLastWriteTime(CTime& refTime) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *pTimeStamp*  
 Um ponteiro para um [FILETIME](http://msdn.microsoft.com/library/windows/desktop/ms724284) estrutura que contém a hora em que o arquivo foi gravado pela última.  
  
 *refTime*  
 Uma referência a um [CTime](../../atl-mfc-shared/reference/ctime-class.md) objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; 0 se não houver êxito. `GetLastWriteTime` Retorna 0 somente se [FindNextFile](#findnextfile) nunca foi chamado neste `CFileFind` objeto.  
  
### <a name="remarks"></a>Comentários  
 Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes de chamar `GetLastWriteTime`.  
  
> [!NOTE]
>  Nem todos os sistemas de arquivos usam a mesma semântica para implementar o carimbo de hora retornado por essa função. Esta função pode retornar o mesmo valor retornado por outras funções de carimbo de data / hora, se o sistema de arquivos subjacente ou o servidor não der suporte a manter o atributo de tempo. Consulte o [Win32_Find_Data](http://msdn.microsoft.com/library/windows/desktop/aa365740) estrutura para obter informações sobre formatos de hora. Em alguns sistemas de operação, a hora retornada está na hora local da zona para a máquina foi o arquivo está localizado. Consulte o Win32 [FileTimeToLocalFileTime](http://msdn.microsoft.com/library/windows/desktop/ms724277) API para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CFileFind::GetLength](#getlength).  
  
##  <a name="getlength"></a>  CFileFind::GetLength  
 Chame essa função de membro para obter o tamanho do arquivo localizado, em bytes.  
  
```  
ULONGLONG GetLength() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O comprimento do arquivo localizado, em bytes.  
  
### <a name="remarks"></a>Comentários  
 Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes de chamar `GetLength`.  
  
 `GetLength` usa a estrutura de Win32 [WIN32_FIND_DATA](http://msdn.microsoft.com/library/windows/desktop/aa365740) para obter e retornar o valor do tamanho do arquivo, em bytes.  
  
> [!NOTE]
>  A partir de MFC 7.0 `GetLength` dá suporte a tipos de inteiro de 64 bits. Anteriormente, criado com esta versão mais recente da biblioteca de código existente pode resultar em avisos de truncamento.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCFiles#33](../../atl-mfc-shared/reference/codesnippet/cpp/cfilefind-class_3.cpp)]  
  
##  <a name="getroot"></a>  CFileFind::GetRoot  
 Chame essa função de membro para obter a raiz do arquivo encontrado.  
  
```  
virtual CString GetRoot() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A raiz da pesquisa ativa.  
  
### <a name="remarks"></a>Comentários  
 Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes de chamar `GetRoot`.  
  
 Essa função de membro retorna o especificador de unidade e o nome de caminho usada para iniciar uma pesquisa. Por exemplo, chamar [FindFile](#findfile) com `*.dat` resulta em `GetRoot` retornar uma cadeia de caracteres vazia. Passando um caminho, como `c:\windows\system\*.dll`, **FindFile** resultados `GetRoot` retornando `c:\windows\system\`.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CFileFind::GetFileName](#getfilename).  
  
##  <a name="isarchived"></a>  CFileFind::IsArchived  
 Chame essa função de membro para determinar se o arquivo encontrado é arquivado.  
  
```  
BOOL IsArchived() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Aplicativos marcam um arquivo, será feito o backup ou removida, com FILE_ATTRIBUTE_ARCHIVE, um atributo de arquivo identificado no [WIN32_FIND_DATA](http://msdn.microsoft.com/library/windows/desktop/aa365740) estrutura.  
  
 Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes de chamar `IsArchived`.  
  
 Consulte a função de membro [MatchesMask](#matchesmask) para obter uma lista completa dos atributos de arquivo.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CFileFind::GetLength](#getlength).  
  
##  <a name="iscompressed"></a>  CFileFind::IsCompressed  
 Chame essa função de membro para determinar se o arquivo encontrado é compactado.  
  
```  
BOOL IsCompressed() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Um arquivo compactado é marcado com FILE_ATTRIBUTE_COMPRESSED, um atributo de arquivo é identificado no [WIN32_FIND_DATA](http://msdn.microsoft.com/library/windows/desktop/aa365740) estrutura. Para um arquivo, esse atributo indica que todos os dados no arquivo é compactado. Para um diretório, esse atributo indica que a compactação é o padrão para novos arquivos e subdiretórios.  
  
 Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes de chamar `IsCompressed`.  
  
 Consulte a função de membro [MatchesMask](#matchesmask) para obter uma lista completa dos atributos de arquivo.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CFileFind::GetLength](#getlength).  
  
##  <a name="isdirectory"></a>  CFileFind::IsDirectory  
 Chame essa função de membro para determinar se o arquivo encontrado é um diretório.  
  
```  
BOOL IsDirectory() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Um arquivo que é um diretório é marcado com FILE_ATTRIBUTE_DIRECTORY um atributo de arquivo é identificado no [WIN32_FIND_DATA](http://msdn.microsoft.com/library/windows/desktop/aa365740) estrutura.  
  
 Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes de chamar `IsDirectory`.  
  
 Consulte a função de membro [MatchesMask](#matchesmask) para obter uma lista completa dos atributos de arquivo.  
  
### <a name="example"></a>Exemplo  
 Este programa pequeno pesquisa todas as pastas na unidade C:\ de forma recursiva e imprime o nome do diretório.  
  
 [!code-cpp[NVC_MFCFiles#34](../../atl-mfc-shared/reference/codesnippet/cpp/cfilefind-class_4.cpp)]  
  
##  <a name="isdots"></a>  CFileFind::IsDots  
 Chame essa função de membro para testar os marcadores de diretório pai e o diretório atuais durante a iteração por meio de arquivos.  
  
```  
virtual BOOL IsDots() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o arquivo encontrado com o nome "."ou"...", que indica que o arquivo encontrado é, na verdade, um diretório. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes de chamar `IsDots`.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CFileFind::IsDirectory](#isdirectory).  
  
##  <a name="ishidden"></a>  CFileFind::IsHidden  
 Chame essa função de membro para determinar se o arquivo encontrado está oculto.  
  
```  
BOOL IsHidden() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Arquivos ocultos, que são marcados com FILE_ATTRIBUTE_HIDDEN, um atributo de arquivo identificado no [WIN32_FIND_DATA](http://msdn.microsoft.com/library/windows/desktop/aa365740) estrutura. Um arquivo oculto não está incluído em uma listagem de diretório comum.  
  
 Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes de chamar `IsHidden`.  
  
 Consulte a função de membro [MatchesMask](#matchesmask) para obter uma lista completa dos atributos de arquivo.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CFileFind::GetLength](#getlength).  
  
##  <a name="isnormal"></a>  CFileFind::IsNormal  
 Chame essa função de membro para determinar se o arquivo encontrado é um arquivo normal.  
  
```  
BOOL IsNormal() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Os arquivos marcados com FILE_ATTRIBUTE_NORMAL, um atributo de arquivo identificado no [WIN32_FIND_DATA](http://msdn.microsoft.com/library/windows/desktop/aa365740) estrutura. Um arquivo normal não tiver outros atributos definido. Todos os outros atributos de arquivo substituem esse atributo.  
  
 Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes de chamar `IsNormal`.  
  
 Consulte a função de membro [MatchesMask](#matchesmask) para obter uma lista completa dos atributos de arquivo.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CFileFind::GetLength](#getlength).  
  
##  <a name="isreadonly"></a>  CFileFind::IsReadOnly  
 Chame essa função de membro para determinar se o arquivo encontrado é somente leitura.  
  
```  
BOOL IsReadOnly() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Um arquivo somente leitura estiver marcado com FILE_ATTRIBUTE_READONLY, um atributo de arquivo é identificado no [WIN32_FIND_DATA](http://msdn.microsoft.com/library/windows/desktop/aa365740) estrutura. Os aplicativos podem ler um arquivo, mas eles não podem gravar nele ou excluí-lo.  
  
 Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes de chamar `IsReadOnly`.  
  
 Consulte a função de membro [MatchesMask](#matchesmask) para obter uma lista completa dos atributos de arquivo.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CFileFind::GetLength](#getlength).  
  
##  <a name="issystem"></a>  CFileFind::IsSystem  
 Chame essa função de membro para determinar se o arquivo encontrado é um arquivo do sistema.  
  
```  
BOOL IsSystem() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Um arquivo do sistema está marcado com FILE_ATTRIBUTE_SYSTEM, um atributo de arquivo é identificado no [WIN32_FIND_DATA](http://msdn.microsoft.com/library/windows/desktop/aa365740) estrutura. Um arquivo de sistema faz parte de ou é usado exclusivamente pelo, o sistema operacional.  
  
 Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes de chamar `IsSystem`.  
  
 Consulte a função de membro [MatchesMask](#matchesmask) para obter uma lista completa dos atributos de arquivo.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CFileFind::GetLength](#getlength).  
  
##  <a name="istemporary"></a>  CFileFind::IsTemporary  
 Chame essa função de membro para determinar se o arquivo encontrado é um arquivo temporário.  
  
```  
BOOL IsTemporary() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Um arquivo temporário é marcado com FILE_ATTRIBUTE_TEMPORARY, um atributo de arquivo é identificado no [WIN32_FIND_DATA](http://msdn.microsoft.com/library/windows/desktop/aa365740) estrutura. Um arquivo temporário é usado para armazenamento temporário. Aplicativos devem gravar o arquivo apenas se absolutamente necessário. A maioria dos dados do arquivo permanece na memória sem que estão sendo liberados para a mídia porque o arquivo em breve será excluído.  
  
 Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes de chamar `IsTemporary`.  
  
 Consulte a função de membro [MatchesMask](#matchesmask) para obter uma lista completa dos atributos de arquivo.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CFileFind::GetLength](#getlength).  
  
##  <a name="m_ptm"></a>  CFileFind::m_pTM  
 Ponteiro para uma `CAtlTransactionManager` objeto.  
  
```  
CAtlTransactionManager* m_pTM;  
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="matchesmask"></a>  CFileFind::MatchesMask  
 Chame essa função de membro para testar os atributos de arquivo no arquivo localizado.  
  
```  
virtual BOOL MatchesMask(DWORD dwMask) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwMask*  
 Especifica um ou mais atributos de arquivo, identificados no [WIN32_FIND_DATA](http://msdn.microsoft.com/library/windows/desktop/aa365740) estrutura, para o arquivo encontrado. Para pesquisar vários atributos, use o OR bit a bit (&#124;) operador. Qualquer combinação dos atributos a seguir é aceitável:  
  
-   FILE_ATTRIBUTE_ARCHIVE o arquivo é um arquivo morto. Aplicativos usam esse atributo para marcar os arquivos de backup ou de remoção.  
  
-   FILE_ATTRIBUTE_COMPRESSED o arquivo ou diretório é compactado. Para um arquivo, isso significa que todos os dados no arquivo é compactado. Para um diretório, isso significa que a compactação é o padrão para novos arquivos e subdiretórios.  
  
-   FILE_ATTRIBUTE_DIRECTORY o arquivo é um diretório.  
  
-   FILE_ATTRIBUTE_NORMAL o arquivo não tiver outros atributos definido. Esse atributo é válido somente quando usado sozinho. Todos os outros atributos de arquivo substituem esse atributo.  
  
-   FILE_ATTRIBUTE_HIDDEN o arquivo está oculto. Não é deve ser incluída em uma listagem de diretório comum.  
  
-   FILE_ATTRIBUTE_READONLY o arquivo é somente leitura. Aplicativos podem ler o arquivo, mas não é possível gravar nele ou excluí-lo.  
  
-   FILE_ATTRIBUTE_SYSTEM o arquivo faz parte de ou é usado exclusivamente pelo sistema operacional.  
  
-   FILE_ATTRIBUTE_TEMPORARY o arquivo está sendo usado para armazenamento temporário. Aplicativos devem gravar o arquivo apenas se absolutamente necessário. A maioria dos dados do arquivo permanece na memória sem que estão sendo liberados para a mídia porque o arquivo em breve será excluído.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0. Para obter mais informações sobre o erro, chame a função Win32 [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360).  
  
### <a name="remarks"></a>Comentários  
 Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes de chamar `MatchesMask`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCFiles#35](../../atl-mfc-shared/reference/codesnippet/cpp/cfilefind-class_5.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Classe CObject](../../mfc/reference/cobject-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CFtpFileFind](../../mfc/reference/cftpfilefind-class.md)   
 [Classe CGopherFileFind](../../mfc/reference/cgopherfilefind-class.md)   
 [Classe CInternetFile](../../mfc/reference/cinternetfile-class.md)   
 [Classe CGopherFile](../../mfc/reference/cgopherfile-class.md)   
 [Classe CHttpFile](../../mfc/reference/chttpfile-class.md)
