---
title: Classe CpathT
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
ms.openlocfilehash: c10b854ae5c2d7167a067675b1391be24b6a8122
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81746587"
---
# <a name="cpatht-class"></a>Classe CpathT

Esta classe representa um caminho.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <typename StringType>
class CPathT
```

#### <a name="parameters"></a>Parâmetros

*StringType*<br/>
A classe de string ATL/MFC a ser usada para o caminho (ver [CStringT](../../atl-mfc-shared/reference/cstringt-class.md)).

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|[CPathT::PCXSTR](#pcxstr)|Um tipo de corda constante.|
|[CPathT::PXSTR](#pxstr)|Um tipo de cadeia de caracteres.|
|[CpathT::XCHAR](#xchar)|Um tipo de caractere.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CpathT::CpathT](#cpatht)|O construtor para o caminho.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CPathT::AddBackslash](#addbackslash)|Chame este método para adicionar uma barra invertida ao final de uma string para criar a sintaxe correta para um caminho.|
|[CPathT::AddExtension](#addextension)|Chame este método para adicionar uma extensão de arquivo a um caminho.|
|[CPathT::Apêndice](#append)|Chame este método para anexar uma seqüência ao caminho atual.|
|[CpathT::BuildRoot](#buildroot)|Chame este método para criar um caminho raiz a partir de um determinado número de unidade.|
|[CPathT::Canonicalize](#canonicalize)|Chame este método para converter o caminho para a forma canônica.|
|[CpathT::Combine](#combine)|Chame este método para concatenar uma seqüência representando um nome de diretório e uma seqüência representando um nome de caminho de arquivo em um caminho.|
|[CpathT::Prefixo comum](#commonprefix)|Chame este método para determinar se o caminho especificado compartilha um prefixo comum com o caminho atual.|
|[CpathT::CompactPath](#compactpath)|Chame este método para truncar um caminho de arquivo para caber dentro de uma determinada largura de pixel, substituindo componentes de caminho por elipses.|
|[CpathT::CompactPathEx](#compactpathex)|Chame este método para truncar um caminho de arquivo para caber dentro de um determinado número de caracteres, substituindo componentes de caminho por elipses.|
|[CpathT::FileExiste](#fileexists)|Chame este método para verificar se o arquivo neste nome de caminho existe.|
|[CpathT::FindExtension](#findextension)|Chame este método para encontrar a posição da extensão de arquivo dentro do caminho.|
|[CPathT::FindFileName](#findfilename)|Chame este método para encontrar a posição do nome do arquivo dentro do caminho.|
|[CpathT::GetDriveNumber](#getdrivenumber)|Chame este método para procurar no caminho uma letra de unidade dentro do intervalo de 'A' a 'Z' e retorne o número de unidade correspondente.|
|[CpathT::GetExtension](#getextension)|Chame este método para obter a extensão de arquivo do caminho.|
|[CPathT::IsDirectory](#isdirectory)|Chame este método para verificar se o caminho é um diretório válido.|
|[CPathT::IsFileSpec](#isfilespec)|Chame este método para procurar um caminho para qualquer caractere delimitador\\de caminho (por exemplo, ':' ou ' ' ). Se não houver caracteres delimitadores de caminho presentes, o caminho é considerado um caminho de Especificação de Arquivos.|
|[CpathT::IsPrefix](#isprefix)|Chame este método para determinar se um caminho contém um prefixo válido do tipo passado pelo *pszPrefix*.|
|[CpathT::É relativo](#isrelative)|Chame este método para determinar se o caminho é relativo.|
|[CpathT::Isroot](#isroot)|Chame este método para determinar se o caminho é uma raiz de diretório.|
|[CpathT::Issameroot](#issameroot)|Chame este método para determinar se outro caminho tem um componente raiz comum com o caminho atual.|
|[CpathT::IsUNC](#isunc)|Chame este método para determinar se o caminho é um caminho UNC (convenção de nomeação universal) válido para um servidor e compartilhar.|
|[CPathT::IsUNCServer](#isuncserver)|Chame este método para determinar se o caminho é um caminho UNC (convenção de nomeação universal) válido apenas para um servidor.|
|[CpathT::IsUNCServerShare](#isuncservershare)|Chame este método para determinar se o caminho é um \\ \ caminho de compartilhamento de UNC (convenção de nomeação universal) válido,*compartilhamento de* *servidor*\ .|
|[CpathT::MakePretty](#makepretty)|Chame este método para converter um caminho para todos os caracteres minúsculos para dar ao caminho uma aparência consistente.|
|[CPathT::MatchSpec](#matchspec)|Chame este método para procurar no caminho uma string contendo um tipo de correspondência curinga.|
|[CpathT::QuoteSpaces](#quotespaces)|Chame este método para envolver o caminho entre aspas se ele contiver algum espaço.|
|[CpathT::RelativePathTo](#relativepathto)|Chame este método para criar um caminho relativo de um arquivo ou pasta para outro.|
|[CPathT::RemoveArgs](#removeargs)|Chame este método para remover quaisquer argumentos de linha de comando do caminho.|
|[CPathT:RemoveBackslash](#removebackslash)|Chame este método para remover a barra invertida do caminho.|
|[CPathT::RemoveBlanks](#removeblanks)|Chame este método para remover todos os espaços de liderança e de trilha do caminho.|
|[CPathT::RemoveExtensão](#removeextension)|Chame este método para remover a extensão do arquivo do caminho, se houver um.|
|[CPathT::RemoveFileSpec](#removefilespec)|Chame este método para remover o nome do arquivo de arrasto e barra invertida do caminho, se ele os tiver.|
|[CPathT::RenameExtension](#renameextension)|Chame este método para substituir a extensão do nome do arquivo no caminho por uma nova extensão. Se o nome do arquivo não contiver uma extensão, a extensão será anexada à extremidade da string.|
|[CpathT::Skiproot](#skiproot)|Chame este método para analisar um caminho, ignorando a letra de unidade ou as partes do servidor/caminho de compartilhamento do servidor UNC.|
|[CpathT::Strippath](#strippath)|Chame este método para remover a parte do caminho de um caminho e nome de arquivo totalmente qualificados.|
|[CpathT::StripToroot](#striptoroot)|Chame este método para remover todas as partes do caminho, exceto as informações de raiz.|
|[CPathT::UnquoteSpaces](#unquotespaces)|Chame este método para remover aspas do início e do fim de um caminho.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CPathT::operador const StringType &](#operator_const_stringtype_amp)|Este operador permite que o objeto seja tratado como uma corda.|
|[CPathT::operador CPathT::PCXSTR](#operator_cpatht__pcxstr)|Este operador permite que o objeto seja tratado como uma corda.|
|[CPathT:string &Type do operador](#operator_stringtype_amp)|Este operador permite que o objeto seja tratado como uma corda.|
|[CPathT::operador +=](#operator_add_eq)|Este operador anexa uma seqüência ao caminho.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CPathT::m_strPath](#m_strpath)|O caminho.|

## <a name="remarks"></a>Comentários

`CPath`, `CPathA`e `CPathW` são instantivas de `CPathT` definidos da seguinte forma:

`typedef CPathT< CString > CPath;`

`typedef CPathT< CStringA > CPathA;`

`typedef CPathT< CStringW > CPathW;`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlpath.h

## <a name="cpathtaddbackslash"></a><a name="addbackslash"></a>CPathT::AddBackslash

Chame este método para adicionar uma barra invertida ao final de uma string para criar a sintaxe correta para um caminho. Se o caminho já tiver uma barra invertida, nenhuma barra invertida será adicionada.

```cpp
void AddBackslash();
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathAddBackSlash](/windows/win32/api/shlwapi/nf-shlwapi-pathaddbackslashw).

## <a name="cpathtaddextension"></a><a name="addextension"></a>CPathT::AddExtension

Chame este método para adicionar uma extensão de arquivo a um caminho.

```
BOOL AddExtension(PCXSTR pszExtension);
```

### <a name="parameters"></a>Parâmetros

*pszExtensão*<br/>
A extensão do arquivo para adicionar.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathAddExtension](/windows/win32/api/shlwapi/nf-shlwapi-pathaddextensionw).

## <a name="cpathtappend"></a><a name="append"></a>CPathT::Apêndice

Chame este método para anexar uma seqüência ao caminho atual.

```
BOOL Append(PCXSTR pszMore);
```

### <a name="parameters"></a>Parâmetros

*pszMore*<br/>
A cadeia de caracteres a ser acrescentada.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathAppend](/windows/win32/api/shlwapi/nf-shlwapi-pathappendw).

## <a name="cpathtbuildroot"></a><a name="buildroot"></a>CpathT::BuildRoot

Chame este método para criar um caminho raiz a partir de um determinado número de unidade.

```cpp
void BuildRoot(int iDrive);
```

### <a name="parameters"></a>Parâmetros

*Idrive*<br/>
O número da unidade (0 é A:, 1 é B:, e assim por diante).

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathBuildRoot](/windows/win32/api/shlwapi/nf-shlwapi-pathbuildrootw).

## <a name="cpathtcanonicalize"></a><a name="canonicalize"></a>CPathT::Canonicalize

Chame este método para converter o caminho para a forma canônica.

```cpp
void Canonicalize();
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathCanonicalize](/windows/win32/api/shlwapi/nf-shlwapi-pathcanonicalizew).

## <a name="cpathtcombine"></a><a name="combine"></a>CpathT::Combine

Chame este método para concatenar uma seqüência representando um nome de diretório e uma seqüência representando um nome de caminho de arquivo em um caminho.

```cpp
void Combine(PCXSTR pszDir, PCXSTR  pszFile);
```

### <a name="parameters"></a>Parâmetros

*pszDir*<br/>
O caminho do diretório.

*pszFile*<br/>
O caminho do arquivo.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathCombine](/windows/win32/api/shlwapi/nf-shlwapi-pathcombinew).

## <a name="cpathtcommonprefix"></a><a name="commonprefix"></a>CpathT::Prefixo comum

Chame este método para determinar se o caminho especificado compartilha um prefixo comum com o caminho atual.

```
CPathT<StringType> CommonPrefix(PCXSTR pszOther);
```

### <a name="parameters"></a>Parâmetros

*pszOther*<br/>
O caminho para comparar com o atual.

### <a name="return-value"></a>Valor retornado

Retorna o prefixo comum.

### <a name="remarks"></a>Comentários

Um prefixo é um desses\\\\tipos: "C: ", ".", "..", ".." \\\\". Para obter mais informações, consulte [PathCommonPrefix](/windows/win32/api/shlwapi/nf-shlwapi-pathcommonprefixw).

## <a name="cpathtcompactpath"></a><a name="compactpath"></a>CpathT::CompactPath

Chame este método para truncar um caminho de arquivo para caber dentro de uma determinada largura de pixel, substituindo componentes de caminho por elipses.

```
BOOL CompactPath(HDC hDC, UINT nWidth);
```

### <a name="parameters"></a>Parâmetros

*Hdc*<br/>
O contexto do dispositivo usado para métricas de fonte.

*Nwidth*<br/>
A largura, em pixels, que a corda será forçada a se encaixar.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathCompactPath](/windows/win32/api/shlwapi/nf-shlwapi-pathcompactpathw).

## <a name="cpathtcompactpathex"></a><a name="compactpathex"></a>CpathT::CompactPathEx

Chame este método para truncar um caminho de arquivo para caber dentro de um determinado número de caracteres, substituindo componentes de caminho por elipses.

```
BOOL CompactPathEx(UINT nMaxChars, DWORD dwFlags = 0);
```

### <a name="parameters"></a>Parâmetros

*nMaxChars*<br/>
O número máximo de caracteres a serem contidos na nova seqüência, incluindo o caractere NULL final.

*dwFlags*<br/>
Reservado.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathCompactPathEx](/windows/win32/api/shlwapi/nf-shlwapi-pathcompactpathexw).

## <a name="cpathtcpatht"></a><a name="cpatht"></a>CpathT::CpathT

O construtor.

```
CPathT(PCXSTR pszPath);
CPathT(const CPathT<StringType>& path);
CPathT() throw();
```

### <a name="parameters"></a>Parâmetros

*Pszpath*<br/>
O ponteiro para uma seqüência de caminho.

*path*<br/>
A seqüência do caminho.

## <a name="cpathtfileexists"></a><a name="fileexists"></a>CpathT::FileExiste

Chame este método para verificar se o arquivo neste nome de caminho existe.

```
BOOL FileExists() const;
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o arquivo existir, FALSO de outra forma.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathFileExists](/windows/win32/api/shlwapi/nf-shlwapi-pathfileexistsw).

## <a name="cpathtfindextension"></a><a name="findextension"></a>CpathT::FindExtension

Chame este método para encontrar a posição da extensão de arquivo dentro do caminho.

```
int FindExtension() const;
```

### <a name="return-value"></a>Valor retornado

Retorna a posição do "." precedendo a extensão. Se nenhuma extensão for encontrada, retorna -1.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathFindExtension](/windows/win32/api/shlwapi/nf-shlwapi-pathfindextensionw).

## <a name="cpathtfindfilename"></a><a name="findfilename"></a>CPathT::FindFileName

Chame este método para encontrar a posição do nome do arquivo dentro do caminho.

```
int FindFileName() const;
```

### <a name="return-value"></a>Valor retornado

Retorna a posição do nome do arquivo. Se nenhum nome de arquivo for encontrado, retorna -1.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathFindFileName](/windows/win32/api/shlwapi/nf-shlwapi-pathfindfilenamew).

## <a name="cpathtgetdrivenumber"></a><a name="getdrivenumber"></a>CpathT::GetDriveNumber

Chame este método para procurar no caminho uma letra de unidade dentro do intervalo de 'A' a 'Z' e retorne o número de unidade correspondente.

```
int GetDriveNumber() const;
```

### <a name="return-value"></a>Valor retornado

Retorna o número da unidade como um inteiro de 0 a 25 (correspondente a 'A' a 'Z') se o caminho tiver uma letra de unidade, ou -1 de outra forma.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathGetDriveNumber](/windows/win32/api/shlwapi/nf-shlwapi-pathgetdrivenumberw).

## <a name="cpathtgetextension"></a><a name="getextension"></a>CpathT::GetExtension

Chame este método para obter a extensão de arquivo do caminho.

```
StringType GetExtension() const;
```

### <a name="return-value"></a>Valor retornado

Retorna a extensão do arquivo.

## <a name="cpathtisdirectory"></a><a name="isdirectory"></a>CPathT::IsDirectory

Chame este método para verificar se o caminho é um diretório válido.

```
BOOL IsDirectory() const;
```

### <a name="return-value"></a>Valor retornado

Retorna um valor não-zero (16) se o caminho for um diretório, FALSO de outra forma.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathIsDirectory](/windows/win32/api/shlwapi/nf-shlwapi-pathisdirectoryw).

## <a name="cpathtisfilespec"></a><a name="isfilespec"></a>CPathT::IsFileSpec

Chame este método para procurar um caminho para qualquer caractere delimitador\\de caminho (por exemplo, ':' ou ' ' ). Se não houver caracteres delimitadores de caminho presentes, o caminho é considerado um caminho de Especificação de Arquivos.

```
BOOL IsFileSpec() const;
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE se não houver caracteres delimitadores de caminho dentro do caminho ou FALSO se houver caracteres delimitadores de caminho.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathIsFileSpec](/windows/win32/api/shlwapi/nf-shlwapi-pathisfilespecw).

## <a name="cpathtisprefix"></a><a name="isprefix"></a>CpathT::IsPrefix

Chame este método para determinar se um caminho contém um prefixo válido do tipo passado pelo *pszPrefix*.

```
BOOL IsPrefix(PCXSTR pszPrefix) const;
```

### <a name="parameters"></a>Parâmetros

*pszPrefix*<br/>
O prefixo para o qual procurar. Um prefixo é um desses\\\\tipos: "C: ", ".", "..", ".." \\\\".

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o caminho contiver o prefixo, ou FALSE de outra forma.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathIsPrefix](/windows/win32/api/shlwapi/nf-shlwapi-pathisprefixw).

## <a name="cpathtisrelative"></a><a name="isrelative"></a>CpathT::É relativo

Chame este método para determinar se o caminho é relativo.

```
BOOL IsRelative() const;
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o caminho for relativo ou FALSO se for absoluto.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathIsRelative](/windows/win32/api/shlwapi/nf-shlwapi-pathisrelativew).

## <a name="cpathtisroot"></a><a name="isroot"></a>CpathT::Isroot

Chame este método para determinar se o caminho é uma raiz de diretório.

```
BOOL IsRoot() const;
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o caminho for uma raiz, ou FALSO de outra forma.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathIsRoot](/windows/win32/api/shlwapi/nf-shlwapi-pathisrootw).

## <a name="cpathtissameroot"></a><a name="issameroot"></a>CpathT::Issameroot

Chame este método para determinar se outro caminho tem um componente raiz comum com o caminho atual.

```
BOOL IsSameRoot(PCXSTR pszOther) const;
```

### <a name="parameters"></a>Parâmetros

*pszOther*<br/>
O outro caminho.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se ambas as strings tiverem o mesmo componente raiz ou FALSE de outra forma.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathIsSameRoot](/windows/win32/api/shlwapi/nf-shlwapi-pathissamerootw).

## <a name="cpathtisunc"></a><a name="isunc"></a>CpathT::IsUNC

Chame este método para determinar se o caminho é um caminho UNC (convenção de nomeação universal) válido para um servidor e compartilhar.

```
BOOL IsUNC() const;
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o caminho for um caminho UNC válido ou FALSO de outra forma.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathIsUNC](/windows/win32/api/shlwapi/nf-shlwapi-pathisuncw).

## <a name="cpathtisuncserver"></a><a name="isuncserver"></a>CPathT::IsUNCServer

Chame este método para determinar se o caminho é um caminho UNC (convenção de nomeação universal) válido apenas para um servidor.

```
BOOL IsUNCServer() const;
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE se a seqüência for um caminho UNC válido apenas para um servidor (sem nome de compartilhamento) ou FALSO de outra forma.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathIsUNCServer](/windows/win32/api/shlwapi/nf-shlwapi-pathisuncserverw).

## <a name="cpathtisuncservershare"></a><a name="isuncservershare"></a>CpathT::IsUNCServerShare

Chame este método para determinar se o caminho é um \\ \ caminho de compartilhamento de UNC (convenção de nomeação universal) válido,*compartilhamento de* *servidor*\ .

```
BOOL IsUNCServerShare() const;
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o caminho \\ \ estiver no*formulário de compartilhamento de* *servidor*\ ou FALSO de outra forma.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathIsUNCServerShare](/windows/win32/api/shlwapi/nf-shlwapi-pathisuncserversharew).

## <a name="cpathtm_strpath"></a><a name="m_strpath"></a>CPathT::m_strPath

O caminho.

```
StringType m_strPath;
```

### <a name="remarks"></a>Comentários

`StringType`é o parâmetro `CPathT`de modelo para .

## <a name="cpathtmakepretty"></a><a name="makepretty"></a>CpathT::MakePretty

Chame este método para converter um caminho para todos os caracteres minúsculos para dar ao caminho uma aparência consistente.

```
BOOL MakePretty();
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o caminho foi convertido, ou FALSO de outra forma.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathMakePretty](/windows/win32/api/shlwapi/nf-shlwapi-pathmakeprettyw).

## <a name="cpathtmatchspec"></a><a name="matchspec"></a>CPathT::MatchSpec

Chame este método para procurar no caminho uma string contendo um tipo de correspondência curinga.

```
BOOL MatchSpec(PCXSTR pszSpec) const;
```

### <a name="parameters"></a>Parâmetros

*pszSpec*<br/>
Pointer para uma seqüência de terminadas nula com o tipo de arquivo para o qual procurar. Por exemplo, para testar se o arquivo no caminho atual é um arquivo DOC, *pszSpec* deve ser definido como "*.doc".

### <a name="return-value"></a>Valor retornado

Retorna TRUE se a seqüência corresponder, ou FALSE de outra forma.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathMatchSpec](/windows/win32/api/shlwapi/nf-shlwapi-pathmatchspecw).

## <a name="cpathtoperator-"></a><a name="operator_add_eq"></a>CPathT::operador +=

Este operador anexa uma seqüência ao caminho.

```
CPathT<StringType>& operator+=(PCXSTR pszMore);
```

### <a name="parameters"></a>Parâmetros

*pszMore*<br/>
A cadeia de caracteres a ser acrescentada.

### <a name="return-value"></a>Valor retornado

Retorna o caminho atualizado.

## <a name="cpathtoperator-const-stringtype-amp"></a><a name="operator_const_stringtype_amp"></a>CPathT::operador const StringType&amp;

Este operador permite que o objeto seja tratado como uma corda.

```
operator const StringType&() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna uma string representando o caminho atual gerenciado por este objeto.

## <a name="cpathtoperator-cpathtpcxstr"></a><a name="operator_cpatht__pcxstr"></a>CPathT::operador CPathT::PCXSTR

Este operador permite que o objeto seja tratado como uma corda.

```
operator PCXSTR() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna uma string representando o caminho atual gerenciado por este objeto.

## <a name="cpathtoperator-stringtype-amp"></a><a name="operator_stringtype_amp"></a>CPathT::operador StringType&amp;

Este operador permite que o objeto seja tratado como uma corda.

```
operator StringType&() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna uma string representando o caminho atual gerenciado por este objeto.

## <a name="cpathtpcxstr"></a><a name="pcxstr"></a>CPathT::PCXSTR

Um tipo de corda constante.

```
typedef StringType::PCXSTR PCXSTR;
```

### <a name="remarks"></a>Comentários

`StringType`é o parâmetro `CPathT`de modelo para .

## <a name="cpathtpxstr"></a><a name="pxstr"></a>CPathT::PXSTR

Um tipo de cadeia de caracteres.

```
typedef StringType::PXSTR PXSTR;
```

### <a name="remarks"></a>Comentários

`StringType`é o parâmetro `CPathT`de modelo para .

## <a name="cpathtquotespaces"></a><a name="quotespaces"></a>CpathT::QuoteSpaces

Chame este método para envolver o caminho entre aspas se ele contiver algum espaço.

```cpp
void QuoteSpaces();
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathQuoteSpaces](/windows/win32/api/shlwapi/nf-shlwapi-pathquotespacesw).

## <a name="cpathtrelativepathto"></a><a name="relativepathto"></a>CpathT::RelativePathTo

Chame este método para criar um caminho relativo de um arquivo ou pasta para outro.

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
Os atributos file *de pszFrom*. Se este valor contiver FILE_ATTRIBUTE_DIRECTORY, *pszFrom* é assumido como um diretório; caso contrário, *pszFrom* é assumido como sendo um arquivo.

*Pszto*<br/>
O ponto final do caminho relativo.

*dwAttrTo*<br/>
Os atributos file *do pszTo*. Se este valor contiver FILE_ATTRIBUTE_DIRECTORY, *o pszTo* é assumido como um diretório; caso contrário, *pszTo* é assumido como sendo um arquivo.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathRelativePathTo](/windows/win32/api/shlwapi/nf-shlwapi-pathrelativepathtow).

## <a name="cpathtremoveargs"></a><a name="removeargs"></a>CPathT::RemoveArgs

Chame este método para remover quaisquer argumentos de linha de comando do caminho.

```cpp
void RemoveArgs();
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathRemoveArgs](/windows/win32/api/shlwapi/nf-shlwapi-pathremoveargsw).

## <a name="cpathtremovebackslash"></a><a name="removebackslash"></a>CPathT:RemoveBackslash

Chame este método para remover a barra invertida do caminho.

```cpp
void RemoveBackslash();
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathRemoveBackslash](/windows/win32/api/shlwapi/nf-shlwapi-pathremovebackslashw).

## <a name="cpathtremoveblanks"></a><a name="removeblanks"></a>CPathT::RemoveBlanks

Chame este método para remover todos os espaços de liderança e de trilha do caminho.

```cpp
void RemoveBlanks();
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathRemoveBlanks](/windows/win32/api/shlwapi/nf-shlwapi-pathremoveblanksw).

## <a name="cpathtremoveextension"></a><a name="removeextension"></a>CPathT::RemoveExtensão

Chame este método para remover a extensão do arquivo do caminho, se houver um.

```cpp
void RemoveExtension();
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathRemoveExtension](/windows/win32/api/shlwapi/nf-shlwapi-pathremoveextensionw).

## <a name="cpathtremovefilespec"></a><a name="removefilespec"></a>CPathT::RemoveFileSpec

Chame este método para remover o nome do arquivo de arrasto e barra invertida do caminho, se ele os tiver.

```
BOOL RemoveFileSpec();
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathRemoveFileSpec](/windows/win32/api/shlwapi/nf-shlwapi-pathremovefilespecw).

## <a name="cpathtrenameextension"></a><a name="renameextension"></a>CPathT::RenameExtension

Chame este método para substituir a extensão do nome do arquivo no caminho por uma nova extensão. Se o nome do arquivo não contiver uma extensão, a extensão será anexada ao final do caminho.

```
BOOL RenameExtension(PCXSTR pszExtension);
```

### <a name="parameters"></a>Parâmetros

*pszExtensão*<br/>
A nova extensão do nome do arquivo, precedida por um caractere "."

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathRenameExtension](/windows/win32/api/shlwapi/nf-shlwapi-pathrenameextensionw).

## <a name="cpathtskiproot"></a><a name="skiproot"></a>CpathT::Skiproot

Chame este método para analisar um caminho, ignorando a letra de unidade ou as partes de caminho de servidor/compartilhamento de unidade da unidade ou UNC (convenção de nomeação universal).

```
int SkipRoot() const;
```

### <a name="return-value"></a>Valor retornado

Retorna a posição do início do subcaminho que segue a raiz (letra de unidade ou servidor/compartilhamento UNC).

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathSkipRoot](/windows/win32/api/shlwapi/nf-shlwapi-pathskiprootw).

## <a name="cpathtstrippath"></a><a name="strippath"></a>CpathT::Strippath

Chame este método para remover a parte do caminho de um caminho e nome de arquivo totalmente qualificados.

```cpp
void StripPath();
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathStripPath](/windows/win32/api/shlwapi/nf-shlwapi-pathstrippathw).

## <a name="cpathtstriptoroot"></a><a name="striptoroot"></a>CpathT::StripToroot

Chame este método para remover todas as partes do caminho, exceto as informações de raiz.

```
BOOL StripToRoot();
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE se uma letra de unidade válida foi encontrada no caminho, ou FALSA de outra forma.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathStripToRoot](/windows/win32/api/shlwapi/nf-shlwapi-pathstriptorootw).

## <a name="cpathtunquotespaces"></a><a name="unquotespaces"></a>CPathT::UnquoteSpaces

Chame este método para remover aspas do início e do fim de um caminho.

```cpp
void UnquoteSpaces();
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathUnquoteSpaces](/windows/win32/api/shlwapi/nf-shlwapi-pathunquotespacesw).

## <a name="cpathtxchar"></a><a name="xchar"></a>CpathT::XCHAR

Um tipo de caractere.

```
typedef StringType::XCHAR XCHAR;
```

### <a name="remarks"></a>Comentários

`StringType`é o parâmetro `CPathT`de modelo para .

## <a name="see-also"></a>Confira também

[Classes](../../atl/reference/atl-classes.md)<br/>
[Classe Cstringt](../../atl-mfc-shared/reference/cstringt-class.md)
