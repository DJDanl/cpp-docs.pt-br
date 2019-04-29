---
title: Funções de caminho da ATL
ms.date: 11/04/2016
helpviewer_keywords:
- ATL, path
f1_keywords:
- ATLPATH/ATL::ATLPath::AddBackslash
- ATLPATH/ATL::ATLPath::AddExtension
- ATLPATH/ATL::ATLPath::Append
- ATLPATH/ATL::ATLPath::BuildRoot
- ATLPATH/ATL::ATLPath::Canonicalize
- ATLPATH/ATL::ATLPath::Combine
- ATLPATH/ATL::ATLPath::CommonPrefix
- ATLPATH/ATL::ATLPath::CompactPath
- ATLPATH/ATL::ATLPath::CompactPathEx
- ATLPATH/ATL::ATLPath::FileExists
- ATLPATH/ATL::ATLPath::FindExtension
- ATLPATH/ATL::ATLPath::FindFileName
- ATLPATH/ATL::ATLPath::GetDriveNumber
- ATLPATH/ATL::ATLPath::IsDirectory
- ATLPATH/ATL::ATLPath::IsFileSpec
- ATLPATH/ATL::ATLPath::IsPrefix
- ATLPATH/ATL::ATLPath::IsRelative
- ATLPATH/ATL::ATLPath::IsRoot
- ATLPATH/ATL::ATLPath::IsSameRoot
- ATLPATH/ATL::ATLPath::IsUNC
- ATLPATH/ATL::ATLPath::IsUNCServer
- ATLPATH/ATL::ATLPath::IsUNCServerShare
- ATLPATH/ATL::ATLPath::MakePretty
- ATLPATH/ATL::ATLPath::MatchSpec
- ATLPATH/ATL::ATLPath::QuoteSpaces
- ATLPATH/ATL::ATLPath::RelativePathTo
- ATLPATH/ATL::ATLPath::RemoveArgs
- ATLPATH/ATL::ATLPath::RemoveBackslash
- ATLPATH/ATL::ATLPath::RemoveBlanks
- ATLPATH/ATL::ATLPath::RemoveExtension
- ATLPATH/ATL::ATLPath::RemoveFileSpec
- ATLPATH/ATL::ATLPath::RenameExtension
- ATLPATH/ATL::ATLPath::SkipRoot
- ATLPATH/ATL::ATLPath::StripPath
- ATLPATH/ATL::ATLPath::StripToRoot
- ATLPATH/ATL::ATLPath::UnquoteSpaces
ms.assetid: d1ec2b8d-7ec7-43ea-90dd-0a740d2a742b
ms.openlocfilehash: 683fd9c6464187e416ea032840507b2062de1fa3
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62248184"
---
# <a name="atl-path-functions"></a>Funções de caminho da ATL

ATL fornece a classe ATLPath para manipular caminhos na forma de [CPathT](cpatht-class.md). Esse código pode ser encontrado em atlpath.

### <a name="related-classes"></a>Classes relacionadas

|||
|-|-|
|[Classe CPathT](cpatht-class.md)|Essa classe representa um caminho.|

### <a name="related-typedefs"></a>Typedefs relacionados

|||
|-|-|
|`CPath`|Uma especialização da [CPathT](cpatht-class.md) usando `CString`.|
|`CPathA`|Uma especialização da [CPathT](cpatht-class.md) usando `CStringA`.|
|`CPathW`|Uma especialização da [CPathT](cpatht-class.md) usando `CStringW`.|

### <a name="functions"></a>Funções

|||
|-|-|
|[ATLPath::AddBackslash](#addbackslash)|Essa função é um wrapper sobrecarregado para [PathAddBackslash](/windows/desktop/api/shlwapi/nf-shlwapi-pathaddbackslasha).|
|[ATLPath::AddExtension](#addextension)|Essa função é um wrapper sobrecarregado para [PathAddExtension](/windows/desktop/api/shlwapi/nf-shlwapi-pathaddextensiona).|
|[ATLPath::Append](#append)|Essa função é um wrapper sobrecarregado para [PathAppend](/windows/desktop/api/shlwapi/nf-shlwapi-pathappenda).|
|[ATLPath::BuildRoot](#buildroot)|Essa função é um wrapper sobrecarregado para [PathBuildRoot](/windows/desktop/api/shlwapi/nf-shlwapi-pathbuildroota).|
|[ATLPath::Canonicalize](#canonicalize)|Essa função é um wrapper sobrecarregado para [PathCanonicalize](/windows/desktop/api/shlwapi/nf-shlwapi-pathcanonicalizea).|
|[ATLPath::Combine](#combine)|Essa função é um wrapper sobrecarregado para [PathCombine](/windows/desktop/api/shlwapi/nf-shlwapi-pathcombinea).|
|[ATLPath::CommonPrefix](#commonprefix)|Essa função é um wrapper sobrecarregado para [PathCommonPrefix](/windows/desktop/api/shlwapi/nf-shlwapi-pathcommonprefixa).|
|[ATLPath::CompactPath](#compactpath)|Essa função é um wrapper sobrecarregado para [PathCompactPath](/windows/desktop/api/shlwapi/nf-shlwapi-pathcompactpatha).|
|[ATLPath::CompactPathEx](#compactpathex)|Essa função é um wrapper sobrecarregado para [PathCompactPathEx](/windows/desktop/api/shlwapi/nf-shlwapi-pathcompactpathexa).|
|[ATLPath::FileExists](#fileexists)|Essa função é um wrapper sobrecarregado para [PathFileExists](/windows/desktop/api/shlwapi/nf-shlwapi-pathfileexistsa).|
|[ATLPath::FindExtension](#findextension)|Essa função é um wrapper sobrecarregado para [PathFindExtension](/windows/desktop/api/shlwapi/nf-shlwapi-pathfindextensiona).|
|[ATLPath::FindFileName](#findfilename)|Essa função é um wrapper sobrecarregado para [PathFindFileName](/windows/desktop/api/shlwapi/nf-shlwapi-pathfindfilenamea).|
|[ATLPath::GetDriveNumber](#getdrivenumber)|Essa função é um wrapper sobrecarregado para [PathGetDriveNumber](/windows/desktop/api/shlwapi/nf-shlwapi-pathgetdrivenumbera).|
|[ATLPath::IsDirectory](#isdirectory)|Essa função é um wrapper sobrecarregado para [PathIsDirectory](/windows/desktop/api/shlwapi/nf-shlwapi-pathisdirectorya).|
|[ATLPath::IsFileSpec](#isfilespec)|Essa função é um wrapper sobrecarregado para [PathIsFileSpec](/windows/desktop/api/shlwapi/nf-shlwapi-pathisfilespeca).|
|[ATLPath::IsPrefix](#isprefix)|Essa função é um wrapper sobrecarregado para [PathIsPrefix](/windows/desktop/api/shlwapi/nf-shlwapi-pathisprefixa).|
|[ATLPath::IsRelative](#isrelative)|Essa função é um wrapper sobrecarregado para [PathIsRelative](/windows/desktop/api/shlwapi/nf-shlwapi-pathisrelativea).|
|[ATLPath::IsRoot](#isroot)|Essa função é um wrapper sobrecarregado para [PathIsRoot](/windows/desktop/api/shlwapi/nf-shlwapi-pathisroota).|
|[ATLPath::IsSameRoot](#issameroot)|Essa função é um wrapper sobrecarregado para [PathIsSameRoot](/windows/desktop/api/shlwapi/nf-shlwapi-pathissameroota).|
|[ATLPath::IsUNC](#isunc)|Essa função é um wrapper sobrecarregado para [PathIsUNC](/windows/desktop/api/shlwapi/nf-shlwapi-pathisunca).|
|[ATLPath::IsUNCServer](#isuncserver)|Essa função é um wrapper sobrecarregado para [PathIsUNCServer](/windows/desktop/api/shlwapi/nf-shlwapi-pathisuncservera).|
|[ATLPath::IsUNCServerShare](#isuncservershare)|Essa função é um wrapper sobrecarregado para [PathIsUNCServerShare](/windows/desktop/api/shlwapi/nf-shlwapi-pathisuncserversharea).|
|[ATLPath::MakePretty](#makepretty)|Essa função é um wrapper sobrecarregado para [PathMakePretty](/windows/desktop/api/shlwapi/nf-shlwapi-pathmakeprettya).|
|[ATLPath::MatchSpec](#matchspec)|Essa função é um wrapper sobrecarregado para [PathMatchSpec](/windows/desktop/api/shlwapi/nf-shlwapi-pathmatchspeca).|
|[ATLPath::QuoteSpaces](#quotespaces)|Essa função é um wrapper sobrecarregado para [PathQuoteSpaces](/windows/desktop/api/shlwapi/nf-shlwapi-pathquotespacesa).|
|[ATLPath::RelativePathTo](#relativepathto)|Essa função é um wrapper sobrecarregado para [PathRelativePathTo](/windows/desktop/api/shlwapi/nf-shlwapi-pathrelativepathtoa).|
|[ATLPath::RemoveArgs](#removeargs)|Essa função é um wrapper sobrecarregado para [PathRemoveArgs](/windows/desktop/api/shlwapi/nf-shlwapi-pathremoveargsa).|
|[ATLPath::RemoveBackslash](#removebackslash)|Essa função é um wrapper sobrecarregado para [PathRemoveBackslash](/windows/desktop/api/shlwapi/nf-shlwapi-pathremovebackslasha).|
|[ATLPath::RemoveBlanks](#removeblanks)|Essa função é um wrapper sobrecarregado para [PathRemoveBlanks](/windows/desktop/api/shlwapi/nf-shlwapi-pathremoveblanksa).|
|[ATLPath::RemoveExtension](#removeextension)|Essa função é um wrapper sobrecarregado para [PathRemoveExtension](/windows/desktop/api/shlwapi/nf-shlwapi-pathremoveextensiona).|
|[ATLPath::RemoveFileSpec](#removefilespec)|Essa função é um wrapper sobrecarregado para [PathRemoveFileSpec](/windows/desktop/api/shlwapi/nf-shlwapi-pathremovefilespeca).|
|[ATLPath::RenameExtension](#renameextension)|Essa função é um wrapper sobrecarregado para [PathRenameExtension](/windows/desktop/api/shlwapi/nf-shlwapi-pathrenameextensiona).|
|[ATLPath::SkipRoot](#skiproot)|Essa função é um wrapper sobrecarregado para [PathSkipRoot](/windows/desktop/api/shlwapi/nf-shlwapi-pathskiproota).|
|[ATLPath::StripPath](#strippath)|Essa função é um wrapper sobrecarregado para [PathStripPath](/windows/desktop/api/shlwapi/nf-shlwapi-pathstrippatha).|
|[ATLPath::StripToRoot](#striptoroot)|Essa função é um wrapper sobrecarregado para [PathStripToRoot](/windows/desktop/api/shlwapi/nf-shlwapi-pathstriptoroota).|
|[ATLPath::UnquoteSpaces](#unquotespaces)|Essa função é um wrapper sobrecarregado para [PathUnquoteSpaces](/windows/desktop/api/shlwapi/nf-shlwapi-pathunquotespacesa).|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlpath

## <a name="addbackslash"></a> ATLPath::AddBackSlash

Essa função é um wrapper sobrecarregado para [PathAddBackslash](/windows/desktop/api/shlwapi/nf-shlwapi-pathaddbackslasha).

### <a name="syntax"></a>Sintaxe

```
inline char* AddBackslash(char* pszPath);
inline wchar_t* AddBackslash(wchar_t* pszPath);
```

### <a name="remarks"></a>Comentários

Ver [PathAddBackslash](/windows/desktop/api/shlwapi/nf-shlwapi-pathaddbackslasha) para obter detalhes.

## <a name="addextension"></a> ATLPath::AddExtension

Essa função é um wrapper sobrecarregado para [PathAddExtension](/windows/desktop/api/shlwapi/nf-shlwapi-pathaddextensiona).

### <a name="syntax"></a>Sintaxe

```
inline BOOL AddExtension(char* pszPath, const char* pszExtension);
inline BOOL AddExtension(wchar_t* pszPath, const wchar_t* pszExtension);
```

### <a name="remarks"></a>Comentários

Ver [PathAddExtension](/windows/desktop/api/shlwapi/nf-shlwapi-pathaddextensiona) para obter detalhes.

## <a name="append"></a> ATLPath::Append

Essa função é um wrapper sobrecarregado para [PathAppend](/windows/desktop/api/shlwapi/nf-shlwapi-pathappenda).

### <a name="syntax"></a>Sintaxe

```
inline BOOL Append(char* pszPath, const char* pszMore);
inline BOOL Append(wchar_t* pszPath, const wchar_t* pszMore);
```

### <a name="remarks"></a>Comentários

Ver [PathAppend](/windows/desktop/api/shlwapi/nf-shlwapi-pathappenda) para obter detalhes.

## <a name="buildroot"></a> ATLPath::BuildRoot

Essa função é um wrapper sobrecarregado para [PathBuildRoot](/windows/desktop/api/shlwapi/nf-shlwapi-pathbuildroota).

### <a name="syntax"></a>Sintaxe

```
inline char* BuildRoot(char* pszPath, int iDrive);
inline wchar_t* BuildRoot(wchar_t* pszPath, int iDrive);
```

### <a name="remarks"></a>Comentários

Ver [PathBuildRoot](/windows/desktop/api/shlwapi/nf-shlwapi-pathbuildroota) para obter detalhes.

## <a name="canonicalize"></a> ATLPath::Canonicalize

Essa função é um wrapper sobrecarregado para [PathCanonicalize](/windows/desktop/api/shlwapi/nf-shlwapi-pathcanonicalizea).

### <a name="syntax"></a>Sintaxe

```
inline BOOL Canonicalize(char* pszDest, const char* pszSrc);
inline BOOL Canonicalize(wchar_t* pszDest, const wchar_t* pszSrc);
```

### <a name="remarks"></a>Comentários

Ver [PathCanonicalize](/windows/desktop/api/shlwapi/nf-shlwapi-pathcanonicalizea) para obter detalhes.

## <a name="combine"></a> ATLPath::Combine

Essa função é um wrapper sobrecarregado para [PathCombine](/windows/desktop/api/shlwapi/nf-shlwapi-pathcombinea).

### <a name="syntax"></a>Sintaxe

```
inline char* Combine(
   char* pszDest,
   const char* pszDir,
   const char* pszFile
);

inline wchar_t* Combine(
   wchar_t* pszDest,
   const wchar_t* pszDir,
   const wchar_t* pszFile);
```

### <a name="remarks"></a>Comentários

Consulte PathCombine para obter detalhes.

## <a name="commonprefix"></a> ATLPath::CommonPrefix

Essa função é um wrapper sobrecarregado para [PathCommonPrefix](/windows/desktop/api/shlwapi/nf-shlwapi-pathcommonprefixa).

### <a name="syntax"></a>Sintaxe

```
inline int CommonPrefix(
   const char* pszFile1,
   const char* pszFile2,
   char* pszDest);

inline int CommonPrefix(
   const wchar_t* pszFile1,
   const wchar_t* pszFile2,
   wchar_t* pszDest);
```

### <a name="remarks"></a>Comentários

Ver [PathCommonPrefix](/windows/desktop/api/shlwapi/nf-shlwapi-pathcommonprefixa) para obter detalhes.

## <a name="compactpath"></a> ATLPath::CompactPath

Essa função é um wrapper sobrecarregado para [PathCompactPath](/windows/desktop/api/shlwapi/nf-shlwapi-pathcompactpatha).

### <a name="syntax"></a>Sintaxe

```
inline BOOL CompactPath(
   HDC hDC,
   char* pszPath,
   UINT dx);

inline BOOL CompactPath(
   HDC hDC,
   wchar_t* pszPath,
   UINT dx);
```

### <a name="remarks"></a>Comentários

Ver [PathCompactPath](/windows/desktop/api/shlwapi/nf-shlwapi-pathcompactpatha) para obter detalhes.

## <a name="compactpathex"></a> ATLPath::CompactPathEx

Essa função é um wrapper sobrecarregado para [PathCompactPathEx](/windows/desktop/api/shlwapi/nf-shlwapi-pathcompactpathexa).

### <a name="syntax"></a>Sintaxe

```
inline BOOL CompactPathEx(
   char* pszDest,
   const char* pszSrc,
   UINT nMaxChars,
   DWORD dwFlags);

inline BOOL CompactPathEx(
   wchar_t* pszDest,
   const wchar_t* pszSrc,
   UINT nMaxChars,
   DWORD dwFlags);
```

### <a name="remarks"></a>Comentários

Ver [PathCompactPathEx](/windows/desktop/api/shlwapi/nf-shlwapi-pathcompactpathexa) para obter detalhes.

## <a name="fileexists"></a> ATLPath::FileExists

Essa função é um wrapper sobrecarregado para [PathFileExists](/windows/desktop/api/shlwapi/nf-shlwapi-pathfileexistsa).

### <a name="syntax"></a>Sintaxe

```
inline BOOL FileExists(const char* pszPath);
inline BOOL FileExists(const wchar_t* pszPath);
```

### <a name="remarks"></a>Comentários

Ver [PathFileExists](/windows/desktop/api/shlwapi/nf-shlwapi-pathfileexistsa) para obter detalhes.

## <a name="findextension"></a> ATLPath::FindExtension

Essa função é um wrapper sobrecarregado para [PathFindExtension](/windows/desktop/api/shlwapi/nf-shlwapi-pathfindextensiona).

### <a name="syntax"></a>Sintaxe

```
inline char* FindExtension(const char* pszPath);
inline wchar_t* FindExtension(const wchar_t* pszPath);
```

### <a name="remarks"></a>Comentários

Ver [PathFindExtension](/windows/desktop/api/shlwapi/nf-shlwapi-pathfindextensiona) para obter detalhes.

## <a name="findfilename"></a> ATLPath::FindFileName

Essa função é um wrapper sobrecarregado para [PathFindFileName](/windows/desktop/api/shlwapi/nf-shlwapi-pathfindfilenamea).

### <a name="syntax"></a>Sintaxe

```
inline char* FindFileName(const char* pszPath);
inline wchar_t* FindFileName(const wchar_t* pszPath);
```

### <a name="remarks"></a>Comentários

Ver [PathFindFileName](/windows/desktop/api/shlwapi/nf-shlwapi-pathfindfilenamea) para obter detalhes.

## <a name="getdrivenumber"></a> ATLPath::GetDriveNumber

Essa função é um wrapper sobrecarregado para [PathGetDriveNumber](/windows/desktop/api/shlwapi/nf-shlwapi-pathgetdrivenumbera).

### <a name="syntax"></a>Sintaxe

```
inline int GetDriveNumber(const char* pszPath);
inline int GetDriveNumber(const wchar_t* pszPath);
```

### <a name="remarks"></a>Comentários

Ver [PathGetDriveNumber](/windows/desktop/api/shlwapi/nf-shlwapi-pathgetdrivenumbera) para obter detalhes.

## <a name="isdirectory"></a>  ATLPath::IsDirectory

Essa função é um wrapper sobrecarregado para [PathIsDirectory](/windows/desktop/api/shlwapi/nf-shlwapi-pathisdirectorya).

```
inline BOOL IsDirectory(const char* pszPath);
inline BOOL IsDirectory(const wchar_t* pszPath);
```

### <a name="remarks"></a>Comentários

Consulte PathIsDirectory para obter detalhes.

## <a name="isfilespec"></a> ATLPath::IsFileSpec

Essa função é um wrapper sobrecarregado para [PathIsFileSpec](/windows/desktop/api/shlwapi/nf-shlwapi-pathisfilespeca).

### <a name="syntax"></a>Sintaxe

```
inline BOOL IsFileSpec(const char* pszPath);
inline BOOL IsFileSpec(const wchar_t* pszPath);
```

### <a name="remarks"></a>Comentários

Ver [PathIsFileSpec](/windows/desktop/api/shlwapi/nf-shlwapi-pathisfilespeca) para obter detalhes.

## <a name="isprefix"></a> ATLPath::IsPrefix

Essa função é um wrapper sobrecarregado para [PathIsPrefix](/windows/desktop/api/shlwapi/nf-shlwapi-pathisprefixa).

### <a name="syntax"></a>Sintaxe

```
inline BOOL IsPrefix(const char* pszPrefix, const char* pszPath);
inline BOOL IsPrefix(const wchar_t* pszPrefix, const wchar_t* pszPath);
```

### <a name="remarks"></a>Comentários

Ver [PathIsPrefix](/windows/desktop/api/shlwapi/nf-shlwapi-pathisprefixa) para obter detalhes.

## <a name="isrelative"></a> ATLPath::IsRelative

Essa função é um wrapper sobrecarregado para [PathIsRelative](/windows/desktop/api/shlwapi/nf-shlwapi-pathisrelativea).

### <a name="syntax"></a>Sintaxe

```
inline BOOL IsRelative(const char* pszPath);
inline BOOL IsRelative(const wchar_t* pszPath);
```

### <a name="remarks"></a>Comentários

Ver [PathIsRelative](/windows/desktop/api/shlwapi/nf-shlwapi-pathisrelativea) para obter detalhes.

## <a name="isroot"></a> ATLPath::IsRoot

Essa função é um wrapper sobrecarregado para [PathIsRoot](/windows/desktop/api/shlwapi/nf-shlwapi-pathisroota).

### <a name="syntax"></a>Sintaxe

```
inline BOOL IsRoot(const char* pszPath);
inline BOOL IsRoot(const wchar_t* pszPath);
```

### <a name="remarks"></a>Comentários

Ver [PathIsRoot](/windows/desktop/api/shlwapi/nf-shlwapi-pathisroota) para obter detalhes.

## <a name="issameroot"></a> ATLPath::IsSameRoot

Essa função é um wrapper sobrecarregado para [PathIsSameRoot](/windows/desktop/api/shlwapi/nf-shlwapi-pathissameroota).

### <a name="syntax"></a>Sintaxe

```
inline BOOL IsSameRoot(const char* pszPath1, const char* pszPath2);
inline BOOL IsSameRoot(const wchar_t* pszPath1, const wchar_t* pszPath2);
```

### <a name="remarks"></a>Comentários

Ver [PathIsSameRoot](/windows/desktop/api/shlwapi/nf-shlwapi-pathissameroota) para obter detalhes.

## <a name="isunc"></a> ATLPath::IsUNC

Essa função é um wrapper sobrecarregado para [PathIsUNC](/windows/desktop/api/shlwapi/nf-shlwapi-pathisunca).

### <a name="syntax"></a>Sintaxe

```
inline BOOL IsUNC(const char* pszPath);
inline BOOL IsUNC(const wchar_t* pszPath);
```

### <a name="remarks"></a>Comentários

Ver [PathIsUNC](/windows/desktop/api/shlwapi/nf-shlwapi-pathisunca) para obter detalhes.

## <a name="isuncserver"></a> ATLPath::IsUNCServer

Essa função é um wrapper sobrecarregado para [PathIsUNCServer](/windows/desktop/api/shlwapi/nf-shlwapi-pathisuncservera).

### <a name="syntax"></a>Sintaxe

```
inline BOOL IsUNCServer(const char* pszPath);
inline BOOL IsUNCServer(const wchar_t* pszPath);
```

### <a name="remarks"></a>Comentários

Ver [PathIsUNCServer](/windows/desktop/api/shlwapi/nf-shlwapi-pathisuncservera) para obter detalhes.

## <a name="isuncservershare"></a> ATLPath::IsUNCServerShare

Essa função é um wrapper sobrecarregado para [PathIsUNCServerShare](/windows/desktop/api/shlwapi/nf-shlwapi-pathisuncserversharea).

### <a name="syntax"></a>Sintaxe

```
inline BOOL IsUNCServerShare(const char* pszPath);
inline BOOL IsUNCServerShare(const wchar_t* pszPath);
```

### <a name="remarks"></a>Comentários

Ver [PathIsUNCServerShare](/windows/desktop/api/shlwapi/nf-shlwapi-pathisuncserversharea) para obter detalhes.

## <a name="makepretty"></a> ATLPath::MakePretty

Essa função é um wrapper sobrecarregado para [PathMakePretty](/windows/desktop/api/shlwapi/nf-shlwapi-pathmakeprettya).

### <a name="syntax"></a>Sintaxe

```
inline BOOL MakePretty(char* pszPath);
inline BOOL MakePretty(wchar_t* pszPath);
```

### <a name="remarks"></a>Comentários

Ver [PathMakePretty](/windows/desktop/api/shlwapi/nf-shlwapi-pathmakeprettya) para obter detalhes.

## <a name="matchspec"></a> ATLPath::MatchSpec

Essa função é um wrapper sobrecarregado para [PathMatchSpec](/windows/desktop/api/shlwapi/nf-shlwapi-pathmatchspeca).

### <a name="syntax"></a>Sintaxe

```
inline BOOL MatchSpec(const char* pszPath, const char* pszSpec);
inline BOOL MatchSpec(const wchar_t* pszPath, const wchar_t* pszSpec);
```

### <a name="remarks"></a>Comentários

Ver [PathMatchSpec](/windows/desktop/api/shlwapi/nf-shlwapi-pathmatchspeca) para obter detalhes.

## <a name="quotespaces"></a> ATLPath::QuoteSpaces

Essa função é um wrapper sobrecarregado para [PathQuoteSpaces](/windows/desktop/api/shlwapi/nf-shlwapi-pathquotespacesa).

### <a name="syntax"></a>Sintaxe

```
inline void QuoteSpaces(char* pszPath);
inline void QuoteSpaces(wchar_t* pszPath);
```

### <a name="remarks"></a>Comentários

Ver [PathQuoteSpaces](/windows/desktop/api/shlwapi/nf-shlwapi-pathquotespacesa) para obter detalhes.

## <a name="relativepathto"></a> ATLPath::RelativePathTo

Essa função é um wrapper sobrecarregado para [PathRelativePathTo](/windows/desktop/api/shlwapi/nf-shlwapi-pathrelativepathtoa).

### <a name="syntax"></a>Sintaxe

```
inline BOOL RelativePathTo(
   char* pszPath,
   const char* pszFrom,
   DWORD dwAttrFrom,
   const char* pszTo,
   DWORD dwAttrTo);

inline BOOL RelativePathTo(
   wchar_t* pszPath,
   const wchar_t* pszFrom,
   DWORD dwAttrFrom,
   const wchar_t* pszTo,
   DWORD dwAttrTo);
```

### <a name="remarks"></a>Comentários

Ver [PathRelativePathTo](/windows/desktop/api/shlwapi/nf-shlwapi-pathrelativepathtoa) para obter detalhes.

## <a name="removeargs"></a> ATLPath::RemoveArgs

Essa função é um wrapper sobrecarregado para [PathRemoveArgs](/windows/desktop/api/shlwapi/nf-shlwapi-pathremoveargsa).

### <a name="syntax"></a>Sintaxe

```
inline void RemoveArgs(char* pszPath);
inline void RemoveArgs(wchar_t* pszPath);
```

### <a name="remarks"></a>Comentários

Ver [PathRemoveArgs](/windows/desktop/api/shlwapi/nf-shlwapi-pathremoveargsa) para obter detalhes.

## <a name="removebackslash"></a> ATLPath::RemoveBackslash

Essa função é um wrapper sobrecarregado para [PathRemoveBackslash](/windows/desktop/api/shlwapi/nf-shlwapi-pathremovebackslasha).

### <a name="syntax"></a>Sintaxe

```
inline char* RemoveBackslash(char* pszPath);
inline wchar_t* RemoveBackslash(wchar_t* pszPath);
```

### <a name="remarks"></a>Comentários

Ver [PathRemoveBackslash](/windows/desktop/api/shlwapi/nf-shlwapi-pathremovebackslasha) para obter detalhes.

## <a name="removeblanks"></a> ATLPath::RemoveBlanks

Essa função é um wrapper sobrecarregado para [PathRemoveBlanks](/windows/desktop/api/shlwapi/nf-shlwapi-pathremoveblanksa).

### <a name="syntax"></a>Sintaxe

```
inline void RemoveBlanks(char* pszPath);
inline void RemoveBlanks(wchar_t* pszPath);
```

### <a name="remarks"></a>Comentários

Ver [PathRemoveBlanks](/windows/desktop/api/shlwapi/nf-shlwapi-pathremoveblanksa) para obter detalhes.

## <a name="removeextension"></a> ATLPath::RemoveExtension

Essa função é um wrapper sobrecarregado para [PathRemoveExtension](/windows/desktop/api/shlwapi/nf-shlwapi-pathremoveextensiona).

### <a name="syntax"></a>Sintaxe

```
inline void RemoveExtension(char* pszPath);
inline void RemoveExtension(wchar_t* pszPath);
```

### <a name="remarks"></a>Comentários

Ver [PathRemoveExtension](/windows/desktop/api/shlwapi/nf-shlwapi-pathremoveextensiona) para obter detalhes.

## <a name="removefilespec"></a> ATLPath::RemoveFileSpec

Essa função é um wrapper sobrecarregado para [PathRemoveFileSpec](/windows/desktop/api/shlwapi/nf-shlwapi-pathremovefilespeca).

### <a name="syntax"></a>Sintaxe

```
inline BOOL RemoveFileSpec(char* pszPath);
inline BOOL RemoveFileSpec(wchar_t* pszPath);
```

### <a name="remarks"></a>Comentários

Ver [PathRemoveFileSpec](/windows/desktop/api/shlwapi/nf-shlwapi-pathremovefilespeca) para obter detalhes.

## <a name="renameextension"></a> ATLPath::RenameExtension

Essa função é um wrapper sobrecarregado para [PathRenameExtension](/windows/desktop/api/shlwapi/nf-shlwapi-pathrenameextensiona).

### <a name="syntax"></a>Sintaxe

```
inline BOOL RenameExtension(char* pszPath, const char* pszExt);
inline BOOL RenameExtension(wchar_t* pszPath, const wchar_t* pszExt);
```

### <a name="remarks"></a>Comentários

Ver [PathRenameExtension](/windows/desktop/api/shlwapi/nf-shlwapi-pathrenameextensiona) para obter detalhes.

## <a name="skiproot"></a> ATLPath::SkipRoot

Essa função é um wrapper sobrecarregado para [PathSkipRoot](/windows/desktop/api/shlwapi/nf-shlwapi-pathskiproota).

### <a name="syntax"></a>Sintaxe

```
inline char* SkipRoot(const char* pszPath);
inline wchar_t* SkipRoot(const wchar_t* pszPath);
```

### <a name="remarks"></a>Comentários

Ver [PathSkipRoot](/windows/desktop/api/shlwapi/nf-shlwapi-pathskiproota) para obter detalhes.

## <a name="strippath"></a> ATLPath::StripPath

Essa função é um wrapper sobrecarregado para [PathStripPath](/windows/desktop/api/shlwapi/nf-shlwapi-pathstrippatha).

### <a name="syntax"></a>Sintaxe

```
inline void StripPath(char* pszPath);
inline void StripPath(wchar_t* pszPath);
```

### <a name="remarks"></a>Comentários

Ver [PathStripPath](/windows/desktop/api/shlwapi/nf-shlwapi-pathstrippatha) para obter detalhes.

## <a name="striptoroot"></a> ATLPath::StripToRoot

Essa função é um wrapper sobrecarregado para [PathStripToRoot](/windows/desktop/api/shlwapi/nf-shlwapi-pathstriptoroota).

### <a name="syntax"></a>Sintaxe

```
inline BOOL StripToRoot(char* pszPath);
inline BOOL StripToRoot(wchar_t* pszPath);
```

### <a name="remarks"></a>Comentários

Ver [PathStripToRoot](/windows/desktop/api/shlwapi/nf-shlwapi-pathstriptoroota) para obter detalhes.

## <a name="unquotespaces"></a> ATLPath::UnquoteSpaces

Essa função é um wrapper sobrecarregado para [PathUnquoteSpaces](/windows/desktop/api/shlwapi/nf-shlwapi-pathunquotespacesa).

### <a name="syntax"></a>Sintaxe

```
inline void UnquoteSpaces(char* pszPath);
inline void UnquoteSpaces(wchar_t* pszPath);
```

### <a name="remarks"></a>Comentários

Ver [PathUnquoteSpaces](/windows/desktop/api/shlwapi/nf-shlwapi-pathunquotespacesa) para obter detalhes.
