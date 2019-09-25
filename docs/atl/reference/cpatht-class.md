---
title: Classe CPathT
ms.date: 03/27/2019
f1_keywords:
- CPathT
- ATLPATH/ATL::CPathT
- ATLPATH/ATL::CPathT::PCXSTR
- ATLPATH/ATL::CPathT::PXSTR
- ATLPATH/ATL::CPathT::XCHAR
- ATLPATH/ATL::CPathT::CPathT
- ATLPATH/ATL::CPathT::AddBackslash
- ATLPATH/ATL::CPathT::AddExtension
- ATLPATH/ATL::CPathT::Append
- ATLPATH/ATL::CPathT::BuildRoot
- ATLPATH/ATL::CPathT::Canonicalize
- ATLPATH/ATL::CPathT::Combine
- ATLPATH/ATL::CPathT::CommonPrefix
- ATLPATH/ATL::CPathT::CompactPath
- ATLPATH/ATL::CPathT::CompactPathEx
- ATLPATH/ATL::CPathT::FileExists
- ATLPATH/ATL::CPathT::FindExtension
- ATLPATH/ATL::CPathT::FindFileName
- ATLPATH/ATL::CPathT::GetDriveNumber
- ATLPATH/ATL::CPathT::GetExtension
- ATLPATH/ATL::CPathT::IsDirectory
- ATLPATH/ATL::CPathT::IsFileSpec
- ATLPATH/ATL::CPathT::IsPrefix
- ATLPATH/ATL::CPathT::IsRelative
- ATLPATH/ATL::CPathT::IsRoot
- ATLPATH/ATL::CPathT::IsSameRoot
- ATLPATH/ATL::CPathT::IsUNC
- ATLPATH/ATL::CPathT::IsUNCServer
- ATLPATH/ATL::CPathT::IsUNCServerShare
- ATLPATH/ATL::CPathT::MakePretty
- ATLPATH/ATL::CPathT::MatchSpec
- ATLPATH/ATL::CPathT::QuoteSpaces
- ATLPATH/ATL::CPathT::RelativePathTo
- ATLPATH/ATL::CPathT::RemoveArgs
- ATLPATH/ATL::CPathT::RemoveBackslash
- ATLPATH/ATL::CPathT::RemoveBlanks
- ATLPATH/ATL::CPathT::RemoveExtension
- ATLPATH/ATL::CPathT::RemoveFileSpec
- ATLPATH/ATL::CPathT::RenameExtension
- ATLPATH/ATL::CPathT::SkipRoot
- ATLPATH/ATL::CPathT::StripPath
- ATLPATH/ATL::CPathT::StripToRoot
- ATLPATH/ATL::CPathT::UnquoteSpaces
- ATLPATH/ATL::CPathT::m_strPath
helpviewer_keywords:
- CPathT class
ms.assetid: eba4137d-1fd2-4b44-a2e1-0944db64df3c
ms.openlocfilehash: ba1c831d772deef34449d17adc2c8e7a6f90eaef
ms.sourcegitcommit: 389c559918d9bfaf303d262ee5430d787a662e92
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/25/2019
ms.locfileid: "69496613"
---
# <a name="cpatht-class"></a>Classe CPathT

Essa classe representa um caminho.

> [!IMPORTANT]
> Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
template <typename StringType>
class CPathT
```

#### <a name="parameters"></a>Parâmetros

*StringType*<br/>
A classe de cadeia de caracteres ATL/MFC a ser usada para o caminho (consulte [CStringT](../../atl-mfc-shared/reference/cstringt-class.md)).

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|[CPathT::P CXSTR](#pcxstr)|Um tipo de cadeia de caracteres constante.|
|[CPathT::PXSTR](#pxstr)|Um tipo de cadeia de caracteres.|
|[CPathT::XCHAR](#xchar)|Um tipo de caractere.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CPathT::CPathT](#cpatht)|O construtor para o caminho.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CPathT::AddBackslash](#addbackslash)|Chame esse método para adicionar uma barra invertida ao final de uma cadeia de caracteres para criar a sintaxe correta para um caminho.|
|[CPathT::AddExtension](#addextension)|Chame esse método para adicionar uma extensão de arquivo a um caminho.|
|[CPathT:: Append](#append)|Chame esse método para acrescentar uma cadeia de caracteres ao caminho atual.|
|[CPathT::BuildRoot](#buildroot)|Chame esse método para criar um caminho raiz a partir de um determinado número de unidade.|
|[CPathT:: canonize](#canonicalize)|Chame esse método para converter o caminho para o formulário canônico.|
|[CPathT:: Combine](#combine)|Chame esse método para concatenar uma cadeia de caracteres que representa um nome de diretório e uma cadeia de caracteres que representa um nome de caminho de arquivo em um caminho.|
|[CPathT::CommonPrefix](#commonprefix)|Chame esse método para determinar se o caminho especificado compartilha um prefixo comum com o caminho atual.|
|[CPathT::CompactPath](#compactpath)|Chame esse método para truncar um caminho de arquivo para caber dentro de uma determinada largura de pixel, substituindo os componentes de caminho por reticências.|
|[CPathT::CompactPathEx](#compactpathex)|Chame esse método para truncar um caminho de arquivo para caber em um determinado número de caracteres, substituindo os componentes de caminho por reticências.|
|[CPathT::FileExists](#fileexists)|Chame esse método para verificar se o arquivo no nome do caminho existe.|
|[CPathT::FindExtension](#findextension)|Chame esse método para localizar a posição da extensão de arquivo dentro do caminho.|
|[CPathT::FindFileName](#findfilename)|Chame esse método para localizar a posição do nome do arquivo dentro do caminho.|
|[CPathT::GetDriveNumber](#getdrivenumber)|Chame esse método para pesquisar o caminho para uma letra de unidade dentro do intervalo de ' A ' para ' Z ' e retornar o número da unidade correspondente.|
|[CPathT::GetExtension](#getextension)|Chame esse método para obter a extensão de arquivo do caminho.|
|[CPathT::IsDirectory](#isdirectory)|Chame esse método para verificar se o caminho é um diretório válido.|
|[CPathT::IsFileSpec](#isfilespec)|Chame esse método para pesquisar um caminho para qualquer caractere delimitador de caminho (por exemplo, ': ' ou '\\'). Se não houver nenhum caractere delimitador de caminho presente, o caminho será considerado como um caminho de especificação de arquivo.|
|[CPathT::IsPrefix](#isprefix)|Chame esse método para determinar se um caminho contém um prefixo válido do tipo passado por *pszPrefix*.|
|[CPathT::IsRelative](#isrelative)|Chame esse método para determinar se o caminho é relativo.|
|[CPathT::IsRoot](#isroot)|Chame esse método para determinar se o caminho é uma raiz de diretório.|
|[CPathT::IsSameRoot](#issameroot)|Chame esse método para determinar se outro caminho tem um componente raiz comum com o caminho atual.|
|[CPathT::IsUNC](#isunc)|Chame esse método para determinar se o caminho é um caminho de UNC (Convenção Universal de nomenclatura) válido para um servidor e um compartilhamento.|
|[CPathT::IsUNCServer](#isuncserver)|Chame esse método para determinar se o caminho é um caminho de UNC (Convenção Universal de nomenclatura) válido apenas para um servidor.|
|[CPathT::IsUNCServerShare](#isuncservershare)|Chame esse método para determinar se o caminho é um caminho de compartilhamento de UNC (Convenção Universal de nomenclatura \\) \ válido,*compartilhamento* *do servidor*\ .|
|[CPathT::MakePretty](#makepretty)|Chame esse método para converter um caminho para todos os caracteres minúsculos para dar ao caminho uma aparência consistente.|
|[CPathT::MatchSpec](#matchspec)|Chame esse método para pesquisar o caminho para uma cadeia de caracteres que contém um tipo de correspondência curinga.|
|[CPathT::QuoteSpaces](#quotespaces)|Chame esse método para incluir o caminho entre aspas se ele contiver espaços.|
|[CPathT::RelativePathTo](#relativepathto)|Chame esse método para criar um caminho relativo de um arquivo ou pasta para outro.|
|[CPathT::RemoveArgs](#removeargs)|Chame esse método para remover quaisquer argumentos de linha de comando do caminho.|
|[CPathT::RemoveBackslash](#removebackslash)|Chame esse método para remover a barra invertida à direita do caminho.|
|[CPathT::RemoveBlanks](#removeblanks)|Chame esse método para remover todos os espaços à esquerda e à direita do caminho.|
|[CPathT::RemoveExtension](#removeextension)|Chame esse método para remover a extensão de arquivo do caminho, se houver uma.|
|[CPathT::RemoveFileSpec](#removefilespec)|Chame esse método para remover o nome do arquivo à direita e a barra invertida do caminho, se ele os tiver.|
|[CPathT::RenameExtension](#renameextension)|Chame esse método para substituir a extensão de nome de arquivo no caminho por uma nova extensão. Se o nome do arquivo não contiver uma extensão, a extensão será anexada ao final da cadeia de caracteres.|
|[CPathT::SkipRoot](#skiproot)|Chame esse método para analisar um caminho, ignorando a letra da unidade ou o servidor UNC/partes do caminho do compartilhamento.|
|[CPathT::StripPath](#strippath)|Chame esse método para remover a parte do caminho de um caminho totalmente qualificado e um nome de arquivo.|
|[CPathT::StripToRoot](#striptoroot)|Chame esse método para remover todas as partes do caminho, exceto as informações de raiz.|
|[CPathT::UnquoteSpaces](#unquotespaces)|Chame esse método para remover aspas do início e do fim de um caminho.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CPathT:: Operator const StringType &](#operator_const_stringtype_amp)|Esse operador permite que o objeto seja tratado como uma cadeia de caracteres.|
|[CPathT:: Operator CPathT::P CXSTR](#operator_cpatht__pcxstr)|Esse operador permite que o objeto seja tratado como uma cadeia de caracteres.|
|[CPathT:: Operator StringType &](#operator_stringtype_amp)|Esse operador permite que o objeto seja tratado como uma cadeia de caracteres.|
|[CPathT:: Operator + =](#operator_add_eq)|Esse operador acrescenta uma cadeia de caracteres ao caminho.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CPathT::m_strPath](#m_strpath)|O caminho.|

## <a name="remarks"></a>Comentários

`CPath`, `CPathA` `CPathT` e `CPathW` são instanciações de definidas da seguinte maneira:

`typedef CPathT< CString > CPath;`

`typedef CPathT< CStringA > CPathA;`

`typedef CPathT< CStringW > CPathW;`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlpath. h

##  <a name="addbackslash"></a>  CPathT::AddBackslash

Chame esse método para adicionar uma barra invertida ao final de uma cadeia de caracteres para criar a sintaxe correta para um caminho. Se o caminho já tiver uma barra invertida à direita, nenhuma barra invertida será adicionada.

```
void AddBackslash();
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathAddBackslash](/windows/win32/api/shlwapi/nf-shlwapi-pathaddbackslashw).

##  <a name="addextension"></a>CPathT:: AddExtension

Chame esse método para adicionar uma extensão de arquivo a um caminho.

```
BOOL AddExtension(PCXSTR pszExtension);
```

### <a name="parameters"></a>Parâmetros

*pszExtension*<br/>
A extensão de arquivo a ser adicionada.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathAddExtension](/windows/win32/api/shlwapi/nf-shlwapi-pathaddextensionw).

##  <a name="append"></a>CPathT:: Append

Chame esse método para acrescentar uma cadeia de caracteres ao caminho atual.

```
BOOL Append(PCXSTR pszMore);
```

### <a name="parameters"></a>Parâmetros

*pszMore*<br/>
A cadeia de caracteres a ser acrescentada.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathAppend](/windows/win32/api/shlwapi/nf-shlwapi-pathappendw).

##  <a name="buildroot"></a>  CPathT::BuildRoot

Chame esse método para criar um caminho raiz a partir de um determinado número de unidade.

```
void BuildRoot(int iDrive);
```

### <a name="parameters"></a>Parâmetros

*iDrive*<br/>
O número da unidade (0 é um:, 1 é B: e assim por diante).

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathBuildRoot](/windows/win32/api/shlwapi/nf-shlwapi-pathbuildrootw).

##  <a name="canonicalize"></a>CPathT:: canonize

Chame esse método para converter o caminho para o formulário canônico.

```
void Canonicalize();
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathCanonicalize](/windows/win32/api/shlwapi/nf-shlwapi-pathcanonicalizew).

##  <a name="combine"></a>CPathT:: Combine

Chame esse método para concatenar uma cadeia de caracteres que representa um nome de diretório e uma cadeia de caracteres que representa um nome de caminho de arquivo em um caminho.

```
void Combine(PCXSTR pszDir, PCXSTR  pszFile);
```

### <a name="parameters"></a>Parâmetros

*pszDir*<br/>
O caminho do diretório.

*pszFile*<br/>
O caminho do arquivo.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathCombine](/windows/win32/api/shlwapi/nf-shlwapi-pathcombinew).

##  <a name="commonprefix"></a>  CPathT::CommonPrefix

Chame esse método para determinar se o caminho especificado compartilha um prefixo comum com o caminho atual.

```
CPathT<StringType> CommonPrefix(PCXSTR pszOther);
```

### <a name="parameters"></a>Parâmetros

*pszOther*<br/>
O caminho para comparar com o atual.

### <a name="return-value"></a>Valor de retorno

Retorna o prefixo comum.

### <a name="remarks"></a>Comentários

Um prefixo é um destes tipos: "C:\\\\", ".", "..", ".. \\\\". Para obter mais informações, consulte [PathCommonPrefix](/windows/win32/api/shlwapi/nf-shlwapi-pathcommonprefixw).

##  <a name="compactpath"></a>CPathT::CompactPath

Chame esse método para truncar um caminho de arquivo para caber dentro de uma determinada largura de pixel, substituindo os componentes de caminho por reticências.

```
BOOL CompactPath(HDC hDC, UINT nWidth);
```

### <a name="parameters"></a>Parâmetros

*hDC*<br/>
O contexto do dispositivo usado para métricas de fonte.

*nWidth*<br/>
A largura, em pixels, à qual a cadeia de caracteres será forçada a se ajustar.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathCompactPath](/windows/win32/api/shlwapi/nf-shlwapi-pathcompactpathw).

##  <a name="compactpathex"></a>  CPathT::CompactPathEx

Chame esse método para truncar um caminho de arquivo para caber em um determinado número de caracteres, substituindo os componentes de caminho por reticências.

```
BOOL CompactPathEx(UINT nMaxChars, DWORD dwFlags = 0);
```

### <a name="parameters"></a>Parâmetros

*nMaxChars*<br/>
O número máximo de caracteres a serem incluídos na nova cadeia de caracteres, incluindo o caractere nulo de terminação.

*dwFlags*<br/>
Reservado.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathCompactPathEx](/windows/win32/api/shlwapi/nf-shlwapi-pathcompactpathexw).

##  <a name="cpatht"></a>  CPathT::CPathT

O construtor.

```
CPathT(PCXSTR pszPath);
CPathT(const CPathT<StringType>& path);
CPathT() throw();
```

### <a name="parameters"></a>Parâmetros

*pszPath*<br/>
O ponteiro para uma cadeia de caracteres de caminho.

*path*<br/>
A cadeia de caracteres do caminho.

##  <a name="fileexists"></a>CPathT:: fileexiste

Chame esse método para verificar se o arquivo no nome do caminho existe.

```
BOOL FileExists() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna TRUE se o arquivo existir; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathFileExists](/windows/win32/api/shlwapi/nf-shlwapi-pathfileexistsw).

##  <a name="findextension"></a>CPathT::FindExtension

Chame esse método para localizar a posição da extensão de arquivo dentro do caminho.

```
int FindExtension() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna a posição do "." anterior à extensão. Se nenhuma extensão for encontrada, retornará-1.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathFindExtension](/windows/win32/api/shlwapi/nf-shlwapi-pathfindextensionw).

##  <a name="findfilename"></a>  CPathT::FindFileName

Chame esse método para localizar a posição do nome do arquivo dentro do caminho.

```
int FindFileName() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna a posição do nome do arquivo. Se nenhum nome de arquivo for encontrado, retornará-1.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathFindFileName](/windows/win32/api/shlwapi/nf-shlwapi-pathfindfilenamew).

##  <a name="getdrivenumber"></a>  CPathT::GetDriveNumber

Chame esse método para pesquisar o caminho para uma letra de unidade dentro do intervalo de ' A ' para ' Z ' e retornar o número da unidade correspondente.

```
int GetDriveNumber() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna o número da unidade como um inteiro de 0 a 25 (correspondente a ' A ' até ' Z ') se o caminho tiver uma letra da unidade ou-1 caso contrário.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathGetDriveNumber](/windows/win32/api/shlwapi/nf-shlwapi-pathgetdrivenumberw).

##  <a name="getextension"></a>CPathT:: GetExtension

Chame esse método para obter a extensão de arquivo do caminho.

```
StringType GetExtension() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna a extensão de arquivo.

##  <a name="isdirectory"></a>CPathT:: IsDirectory

Chame esse método para verificar se o caminho é um diretório válido.

```
BOOL IsDirectory() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna um valor diferente de zero (16) se o caminho for um diretório; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathIsDirectory](/windows/win32/api/shlwapi/nf-shlwapi-pathisdirectoryw).

##  <a name="isfilespec"></a>  CPathT::IsFileSpec

Chame esse método para pesquisar um caminho para qualquer caractere delimitador de caminho (por exemplo, ': ' ou '\\'). Se não houver nenhum caractere delimitador de caminho presente, o caminho será considerado como um caminho de especificação de arquivo.

```
BOOL IsFileSpec() const;
```

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se não houver nenhum caractere delimitador de caminho dentro do caminho ou FALSE se houver caracteres delimitadores de caminho.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathIsFileSpec](/windows/win32/api/shlwapi/nf-shlwapi-pathisfilespecw).

##  <a name="isprefix"></a>CPathT:: IsPrefix

Chame esse método para determinar se um caminho contém um prefixo válido do tipo passado por *pszPrefix*.

```
BOOL IsPrefix(PCXSTR pszPrefix) const;
```

### <a name="parameters"></a>Parâmetros

*pszPrefix*<br/>
O prefixo a ser pesquisado. Um prefixo é um destes tipos: "C:\\\\", ".", "..", ".. \\\\".

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se o caminho contiver o prefixo ou FALSE caso contrário.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathIsPrefix](/windows/win32/api/shlwapi/nf-shlwapi-pathisprefixw).

##  <a name="isrelative"></a>  CPathT::IsRelative

Chame esse método para determinar se o caminho é relativo.

```
BOOL IsRelative() const;
```

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se o caminho for relativo ou FALSE se for absoluto.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathIsRelative](/windows/win32/api/shlwapi/nf-shlwapi-pathisrelativew).

##  <a name="isroot"></a>  CPathT::IsRoot

Chame esse método para determinar se o caminho é uma raiz de diretório.

```
BOOL IsRoot() const;
```

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se o caminho for uma raiz ou FALSE caso contrário.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathIsRoot](/windows/win32/api/shlwapi/nf-shlwapi-pathisrootw).

##  <a name="issameroot"></a>  CPathT::IsSameRoot

Chame esse método para determinar se outro caminho tem um componente raiz comum com o caminho atual.

```
BOOL IsSameRoot(PCXSTR pszOther) const;
```

### <a name="parameters"></a>Parâmetros

*pszOther*<br/>
O outro caminho.

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se ambas as cadeias de caracteres tiverem o mesmo componente raiz ou FALSE caso contrário.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathIsSameRoot](/windows/win32/api/shlwapi/nf-shlwapi-pathissamerootw).

##  <a name="isunc"></a>  CPathT::IsUNC

Chame esse método para determinar se o caminho é um caminho de UNC (Convenção Universal de nomenclatura) válido para um servidor e um compartilhamento.

```
BOOL IsUNC() const;
```

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se o caminho for um caminho UNC válido ou FALSE caso contrário.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathIsUNC](/windows/win32/api/shlwapi/nf-shlwapi-pathisuncw).

##  <a name="isuncserver"></a>  CPathT::IsUNCServer

Chame esse método para determinar se o caminho é um caminho de UNC (Convenção Universal de nomenclatura) válido apenas para um servidor.

```
BOOL IsUNCServer() const;
```

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se a cadeia de caracteres for um caminho UNC válido somente para um servidor (nenhum nome de compartilhamento) ou FALSE caso contrário.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathIsUNCServer](/windows/win32/api/shlwapi/nf-shlwapi-pathisuncserverw).

##  <a name="isuncservershare"></a>  CPathT::IsUNCServerShare

Chame esse método para determinar se o caminho é um caminho de compartilhamento de UNC (Convenção Universal de nomenclatura \\) \ válido,*compartilhamento* *do servidor*\ .

```
BOOL IsUNCServerShare() const;
```

### <a name="return-value"></a>Valor de retorno

Retornará true se o caminho \\estiver no formato \  *Server*\ *share*ou false.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathIsUNCServerShare](/windows/win32/api/shlwapi/nf-shlwapi-pathisuncserversharew).

##  <a name="m_strpath"></a>  CPathT::m_strPath

O caminho.

```
StringType m_strPath;
```

### <a name="remarks"></a>Comentários

`StringType`é o parâmetro de modelo `CPathT`para.

##  <a name="makepretty"></a>CPathT::MakePretty

Chame esse método para converter um caminho para todos os caracteres minúsculos para dar ao caminho uma aparência consistente.

```
BOOL MakePretty();
```

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se o caminho tiver sido convertido ou FALSE caso contrário.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathMakePretty](/windows/win32/api/shlwapi/nf-shlwapi-pathmakeprettyw).

##  <a name="matchspec"></a>  CPathT::MatchSpec

Chame esse método para pesquisar o caminho para uma cadeia de caracteres que contém um tipo de correspondência curinga.

```
BOOL MatchSpec(PCXSTR pszSpec) const;
```

### <a name="parameters"></a>Parâmetros

*pszSpec*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo com o tipo de arquivo a ser pesquisado. Por exemplo, para testar se o arquivo no caminho atual é um arquivo de documento, *pszSpec* deve ser definido como "*. doc".

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se a cadeia de caracteres corresponder ou FALSE caso contrário.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathMatchSpec](/windows/win32/api/shlwapi/nf-shlwapi-pathmatchspecw).

##  <a name="operator_add_eq"></a>CPathT:: Operator + =

Esse operador acrescenta uma cadeia de caracteres ao caminho.

```
CPathT<StringType>& operator+=(PCXSTR pszMore);
```

### <a name="parameters"></a>Parâmetros

*pszMore*<br/>
A cadeia de caracteres a ser acrescentada.

### <a name="return-value"></a>Valor de retorno

Retorna o caminho atualizado.

##  <a name="operator_const_stringtype_amp"></a>StringType de const CPathT:: Operator&amp;

Esse operador permite que o objeto seja tratado como uma cadeia de caracteres.

```
operator const StringType&() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna uma cadeia de caracteres que representa o caminho atual gerenciado por este objeto.

##  <a name="operator_cpatht__pcxstr"></a>CPathT:: Operator CPathT::P CXSTR

Esse operador permite que o objeto seja tratado como uma cadeia de caracteres.

```
operator PCXSTR() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna uma cadeia de caracteres que representa o caminho atual gerenciado por este objeto.

##  <a name="operator_stringtype_amp"></a>StringType CPathT:: Operator&amp;

Esse operador permite que o objeto seja tratado como uma cadeia de caracteres.

```
operator StringType&() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna uma cadeia de caracteres que representa o caminho atual gerenciado por este objeto.

##  <a name="pcxstr"></a>  CPathT::PCXSTR

Um tipo de cadeia de caracteres constante.

```
typedef StringType::PCXSTR PCXSTR;
```

### <a name="remarks"></a>Comentários

`StringType`é o parâmetro de modelo `CPathT`para.

##  <a name="pxstr"></a>  CPathT::PXSTR

Um tipo de cadeia de caracteres.

```
typedef StringType::PXSTR PXSTR;
```

### <a name="remarks"></a>Comentários

`StringType`é o parâmetro de modelo `CPathT`para.

##  <a name="quotespaces"></a>  CPathT::QuoteSpaces

Chame esse método para incluir o caminho entre aspas se ele contiver espaços.

```
void QuoteSpaces();
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathQuoteSpaces](/windows/win32/api/shlwapi/nf-shlwapi-pathquotespacesw).

##  <a name="relativepathto"></a>  CPathT::RelativePathTo

Chame esse método para criar um caminho relativo de um arquivo ou pasta para outro.

```
BOOL RelativePathTo(
    PCXSTR pszFrom,
    DWORD dwAttrFrom,
    PCXSTR pszTo,
    DWORD dwAttrTo);
```

### <a name="parameters"></a>Parâmetros

*pszFrom*<br/>
O início do caminho relativo.

*dwAttrFrom*<br/>
Os atributos de arquivo de *pszFrom*. Se esse valor contiver FILE_ATTRIBUTE_DIRECTORY, *pszFrom* será considerado um diretório; caso contrário, *pszFrom* será considerado um arquivo.

*pszTo*<br/>
O ponto de extremidade do caminho relativo.

*dwAttrTo*<br/>
Os atributos de arquivo de *pszTo*. Se esse valor contiver FILE_ATTRIBUTE_DIRECTORY, *pszTo* será considerado um diretório; caso contrário, *pszTo* será considerado um arquivo.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathRelativePathTo](/windows/win32/api/shlwapi/nf-shlwapi-pathrelativepathtow).

##  <a name="removeargs"></a>  CPathT::RemoveArgs

Chame esse método para remover quaisquer argumentos de linha de comando do caminho.

```
void RemoveArgs();
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathRemoveArgs](/windows/win32/api/shlwapi/nf-shlwapi-pathremoveargsw).

##  <a name="removebackslash"></a>  CPathT::RemoveBackslash

Chame esse método para remover a barra invertida à direita do caminho.

```
void RemoveBackslash();
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathRemoveBackslash](/windows/win32/api/shlwapi/nf-shlwapi-pathremovebackslashw).

##  <a name="removeblanks"></a>  CPathT::RemoveBlanks

Chame esse método para remover todos os espaços à esquerda e à direita do caminho.

```
void RemoveBlanks();
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathRemoveBlanks](/windows/win32/api/shlwapi/nf-shlwapi-pathremoveblanksw).

##  <a name="removeextension"></a>  CPathT::RemoveExtension

Chame esse método para remover a extensão de arquivo do caminho, se houver uma.

```
void RemoveExtension();
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathRemoveExtension](/windows/win32/api/shlwapi/nf-shlwapi-pathremoveextensionw).

##  <a name="removefilespec"></a>  CPathT::RemoveFileSpec

Chame esse método para remover o nome do arquivo à direita e a barra invertida do caminho, se ele os tiver.

```
BOOL RemoveFileSpec();
```

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathRemoveFileSpec](/windows/win32/api/shlwapi/nf-shlwapi-pathremovefilespecw).

##  <a name="renameextension"></a>  CPathT::RenameExtension

Chame esse método para substituir a extensão de nome de arquivo no caminho por uma nova extensão. Se o nome do arquivo não contiver uma extensão, a extensão será anexada ao final do caminho.

```
BOOL RenameExtension(PCXSTR pszExtension);
```

### <a name="parameters"></a>Parâmetros

*pszExtension*<br/>
A nova extensão de nome de arquivo, precedida por um caractere ".".

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathRenameExtension](/windows/win32/api/shlwapi/nf-shlwapi-pathrenameextensionw).

##  <a name="skiproot"></a>  CPathT::SkipRoot

Chame esse método para analisar um caminho, ignorando a letra da unidade ou as partes do caminho do servidor/compartilhamento de unidades de UNC (Convenção Universal de nomenclatura).

```
int SkipRoot() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna a posição do início do subcaminho que segue a raiz (letra da unidade ou servidor/compartilhamento UNC).

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathSkipRoot](/windows/win32/api/shlwapi/nf-shlwapi-pathskiprootw).

##  <a name="strippath"></a>  CPathT::StripPath

Chame esse método para remover a parte do caminho de um caminho totalmente qualificado e um nome de arquivo.

```
void StripPath();
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathStripPath](/windows/win32/api/shlwapi/nf-shlwapi-pathstrippathw).

##  <a name="striptoroot"></a>  CPathT::StripToRoot

Chame esse método para remover todas as partes do caminho, exceto as informações de raiz.

```
BOOL StripToRoot();
```

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se uma letra de unidade válida tiver sido encontrada no caminho ou FALSE caso contrário.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathStripToRoot](/windows/win32/api/shlwapi/nf-shlwapi-pathstriptorootw).

##  <a name="unquotespaces"></a>  CPathT::UnquoteSpaces

Chame esse método para remover aspas do início e do fim de um caminho.

```
void UnquoteSpaces();
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathUnquoteSpaces](/windows/win32/api/shlwapi/nf-shlwapi-pathunquotespacesw).

##  <a name="xchar"></a>  CPathT::XCHAR

Um tipo de caractere.

```
typedef StringType::XCHAR XCHAR;
```

### <a name="remarks"></a>Comentários

`StringType`é o parâmetro de modelo `CPathT`para.

## <a name="see-also"></a>Consulte também

[Classes](../../atl/reference/atl-classes.md)<br/>
[Classe CStringT](../../atl-mfc-shared/reference/cstringt-class.md)
