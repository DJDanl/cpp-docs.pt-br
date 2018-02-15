---
title: "Funções de ATL caminho | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: reference
keywords:
- ATL, caminho
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a0540fe70464e8c7997275d99d8242e62625bdec
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="atl-path-functions"></a>Funções de caminho do ATL

ATL fornece a classe ATLPath para manipular caminhos na forma de [CPathT](cpatht-class.md). Esse código pode ser encontrado em atlpath.h.  
  
### <a name="related-classes"></a>Classes relacionadas  
  
|||  
|-|-|  
|[Classe CPathT](cpatht-class.md)|Essa classe representa um caminho.|  

### <a name="related-typedefs"></a>Typedefs relacionados  
  
|||  
|-|-|  
|`CPath`|Uma especialização de [CPathT](cpatht-class.md) usando `CString`.|  
|`CPathA`|Uma especialização de [CPathT](cpatht-class.md) usando `CStringA`.|  
|`CPathW`|Uma especialização de [CPathT](cpatht-class.md) usando `CStringW`.|  
  
### <a name="functions"></a>Funções  
  
|||  
|-|-|  
|[ATLPath::AddBackslash](#addbackslash)|Essa função é um wrapper sobrecarregado para [PathAddBackslash](http://msdn.microsoft.com/library/windows/desktop/bb773561).|  
|[ATLPath::AddExtension](#addextension)|Essa função é um wrapper sobrecarregado para [PathAddExtension](http://msdn.microsoft.com/library/windows/desktop/bb773563).|  
|[ATLPath::Append](#append)|Essa função é um wrapper sobrecarregado para [PathAppend](http://msdn.microsoft.com/library/windows/desktop/bb773565).|  
|[ATLPath::BuildRoot](#buildroot)|Essa função é um wrapper sobrecarregado para [PathBuildRoot](http://msdn.microsoft.com/library/windows/desktop/bb773567).|  
|[ATLPath::Canonicalize](#canonicalize)|Essa função é um wrapper sobrecarregado para [PathCanonicalize](http://msdn.microsoft.com/library/windows/desktop/bb773569).|  
|[ATLPath::Combine](#combine)|Essa função é um wrapper sobrecarregado para [PathCombine](http://msdn.microsoft.com/library/windows/desktop/bb773571).|  
|[ATLPath::CommonPrefix](#commonprefix)|Essa função é um wrapper sobrecarregado para [PathCommonPrefix](http://msdn.microsoft.com/library/windows/desktop/bb773574).|  
|[ATLPath::CompactPath](#compactpath)|Essa função é um wrapper sobrecarregado para [PathCompactPath](http://msdn.microsoft.com/library/windows/desktop/bb773575).|  
|[ATLPath::CompactPathEx](#compactpathex)|Essa função é um wrapper sobrecarregado para [PathCompactPathEx](http://msdn.microsoft.com/library/windows/desktop/bb773578).|  
|[ATLPath::FileExists](#fileexists)|Essa função é um wrapper sobrecarregado para [PathFileExists](http://msdn.microsoft.com/library/windows/desktop/bb773584).|  
|[ATLPath::FindExtension](#findextension)|Essa função é um wrapper sobrecarregado para [PathFindExtension](http://msdn.microsoft.com/library/windows/desktop/bb773587).|  
|[ATLPath::FindFileName](#findfilename)|Essa função é um wrapper sobrecarregado para [PathFindFileName](http://msdn.microsoft.com/library/windows/desktop/bb773589).|  
|[ATLPath::GetDriveNumber](#getdrivenumber)|Essa função é um wrapper sobrecarregado para [PathGetDriveNumber](http://msdn.microsoft.com/library/windows/desktop/bb773612).|  
|[ATLPath::IsDirectory](#isdirectory)|Essa função é um wrapper sobrecarregado para [PathIsDirectory](http://msdn.microsoft.com/library/windows/desktop/bb773621).|  
|[ATLPath::IsFileSpec](#isfilespec)|Essa função é um wrapper sobrecarregado para [PathIsFileSpec](http://msdn.microsoft.com/library/windows/desktop/bb773627).|  
|[ATLPath::IsPrefix](#isprefix)|Essa função é um wrapper sobrecarregado para [PathIsPrefix](http://msdn.microsoft.com/library/windows/desktop/bb773650).|  
|[ATLPath::IsRelative](#isrelative)|Essa função é um wrapper sobrecarregado para [PathIsRelative](http://msdn.microsoft.com/library/windows/desktop/bb773660).|  
|[ATLPath::IsRoot](#isroot)|Essa função é um wrapper sobrecarregado para [PathIsRoot](http://msdn.microsoft.com/library/windows/desktop/bb773674).|  
|[ATLPath::IsSameRoot](#issameroot)|Essa função é um wrapper sobrecarregado para [PathIsSameRoot](http://msdn.microsoft.com/library/windows/desktop/bb773687).|  
|[ATLPath::IsUNC](#isunc)|Essa função é um wrapper sobrecarregado para [PathIsUNC](http://msdn.microsoft.com/library/windows/desktop/bb773712).|  
|[ATLPath::IsUNCServer](#isuncserver)|Essa função é um wrapper sobrecarregado para [PathIsUNCServer](http://msdn.microsoft.com/library/windows/desktop/bb773722).|  
|[ATLPath::IsUNCServerShare](#isuncservershare)|Essa função é um wrapper sobrecarregado para [PathIsUNCServerShare](http://msdn.microsoft.com/library/windows/desktop/bb773723).|  
|[ATLPath::MakePretty](#makepretty)|Essa função é um wrapper sobrecarregado para [PathMakePretty](http://msdn.microsoft.com/library/windows/desktop/bb773725).|  
|[ATLPath::MatchSpec](#matchspec)|Essa função é um wrapper sobrecarregado para [PathMatchSpec](http://msdn.microsoft.com/library/windows/desktop/bb773727).|  
|[ATLPath::QuoteSpaces](#quotespaces)|Essa função é um wrapper sobrecarregado para [PathQuoteSpaces](http://msdn.microsoft.com/library/windows/desktop/bb773739).|  
|[ATLPath::RelativePathTo](#relativepathto)|Essa função é um wrapper sobrecarregado para [PathRelativePathTo](http://msdn.microsoft.com/library/windows/desktop/bb773740).|  
|[ATLPath::RemoveArgs](#removeargs)|Essa função é um wrapper sobrecarregado para [PathRemoveArgs](http://msdn.microsoft.com/library/windows/desktop/bb773742).|  
|[ATLPath::RemoveBackslash](#removebackslash)|Essa função é um wrapper sobrecarregado para [PathRemoveBackslash](http://msdn.microsoft.com/library/windows/desktop/bb773743).|  
|[ATLPath::RemoveBlanks](#removeblanks)|Essa função é um wrapper sobrecarregado para [PathRemoveBlanks](http://msdn.microsoft.com/library/windows/desktop/bb773745).|  
|[ATLPath::RemoveExtension](#removeextension)|Essa função é um wrapper sobrecarregado para [PathRemoveExtension](http://msdn.microsoft.com/library/windows/desktop/bb773746).|  
|[ATLPath::RemoveFileSpec](#removefilespec)|Essa função é um wrapper sobrecarregado para [PathRemoveFileSpec](http://msdn.microsoft.com/library/windows/desktop/bb773748).|  
|[ATLPath::RenameExtension](#renameextension)|Essa função é um wrapper sobrecarregado para [PathRenameExtension](http://msdn.microsoft.com/library/windows/desktop/bb773749).|  
|[ATLPath::SkipRoot](#skiproot)|Essa função é um wrapper sobrecarregado para [PathSkipRoot](http://msdn.microsoft.com/library/windows/desktop/bb773754).|  
|[ATLPath::StripPath](#strippath)|Essa função é um wrapper sobrecarregado para [PathStripPath](http://msdn.microsoft.com/library/windows/desktop/bb773756).|  
|[ATLPath::StripToRoot](#striptoroot)|Essa função é um wrapper sobrecarregado para [PathStripToRoot](http://msdn.microsoft.com/library/windows/desktop/bb773757).|  
|[ATLPath::UnquoteSpaces](#unquotespaces)|Essa função é um wrapper sobrecarregado para [PathUnquoteSpaces](http://msdn.microsoft.com/library/windows/desktop/bb773763).|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlpath.h  

## <a name="addbackslash"></a> ATLPath::AddBackSlash

Essa função é um wrapper sobrecarregado para [PathAddBackslash](http://msdn.microsoft.com/library/windows/desktop/bb773561).  
  
### <a name="syntax"></a>Sintaxe  
  
```  
inline char* AddBackslash(char* pszPath);  
inline wchar_t* AddBackslash(wchar_t* pszPath);  
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [PathAddBackslash](http://msdn.microsoft.com/library/windows/desktop/bb773561) para obter detalhes.  
  
 
  

## <a name="addextension"></a> ATLPath::AddExtension
 Essa função é um wrapper sobrecarregado para [PathAddExtension](http://msdn.microsoft.com/library/windows/desktop/bb773563).  
  
### <a name="syntax"></a>Sintaxe  
  
```  
inline BOOL AddExtension(char* pszPath, const char* pszExtension);  
inline BOOL AddExtension(wchar_t* pszPath, const wchar_t* pszExtension);  
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [PathAddExtension](http://msdn.microsoft.com/library/windows/desktop/bb773563) para obter detalhes. 
  
## <a name="append"></a> ATLPath::Append
 Essa função é um wrapper sobrecarregado para [PathAppend](http://msdn.microsoft.com/library/windows/desktop/bb773565).  
  
### <a name="syntax"></a>Sintaxe  
  
```  
inline BOOL Append(char* pszPath, const char* pszMore);  
inline BOOL Append(wchar_t* pszPath, const wchar_t* pszMore);  
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [PathAppend](http://msdn.microsoft.com/library/windows/desktop/bb773565) para obter detalhes.  
  
 
  

## <a name="buildroot"></a> ATLPath::BuildRoot
 Essa função é um wrapper sobrecarregado para [PathBuildRoot](http://msdn.microsoft.com/library/windows/desktop/bb773567).  
  
### <a name="syntax"></a>Sintaxe  
  
```  
inline char* BuildRoot(char* pszPath, int iDrive);  
inline wchar_t* BuildRoot(wchar_t* pszPath, int iDrive);  
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [PathBuildRoot](http://msdn.microsoft.com/library/windows/desktop/bb773567) para obter detalhes.  
  
 
  

## <a name="canonicalize"></a> ATLPath::Canonicalize
 Essa função é um wrapper sobrecarregado para [PathCanonicalize](http://msdn.microsoft.com/library/windows/desktop/bb773569).  
  
### <a name="syntax"></a>Sintaxe  
  
```  
inline BOOL Canonicalize(char* pszDest, const char* pszSrc);  
inline BOOL Canonicalize(wchar_t* pszDest, const wchar_t* pszSrc);  
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [PathCanonicalize](http://msdn.microsoft.com/library/windows/desktop/bb773569) para obter detalhes.  
  
 
  

## <a name="combine"></a> ATLPath::Combine 
Essa função é um wrapper sobrecarregado para [PathCombine](https://msdn.microsoft.com/en-us/library/windows/desktop/bb773571).  

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
 Essa função é um wrapper sobrecarregado para [PathCommonPrefix](http://msdn.microsoft.com/library/windows/desktop/bb773574).  
  
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
 Consulte [PathCommonPrefix](http://msdn.microsoft.com/library/windows/desktop/bb773574) para obter detalhes.  
  
 
  

## <a name="compactpath"></a> ATLPath::CompactPath
 Essa função é um wrapper sobrecarregado para [PathCompactPath](http://msdn.microsoft.com/library/windows/desktop/bb773575).  
  
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
 Consulte [PathCompactPath](http://msdn.microsoft.com/library/windows/desktop/bb773575) para obter detalhes.  
  
 
  

## <a name="compactpathex"></a> ATLPath::CompactPathEx
 Essa função é um wrapper sobrecarregado para [PathCompactPathEx](http://msdn.microsoft.com/library/windows/desktop/bb773578).  
  
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
 Consulte [PathCompactPathEx](http://msdn.microsoft.com/library/windows/desktop/bb773578) para obter detalhes.  
  
 
  

## <a name="fileexists"></a> ATLPath::FileExists
 Essa função é um wrapper sobrecarregado para [PathFileExists](http://msdn.microsoft.com/library/windows/desktop/bb773584).  
  
### <a name="syntax"></a>Sintaxe  
  
```  
inline BOOL FileExists(const char* pszPath);  
inline BOOL FileExists(const wchar_t* pszPath);  
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [PathFileExists](http://msdn.microsoft.com/library/windows/desktop/bb773584) para obter detalhes.  
  
 
  

## <a name="findextension"></a> ATLPath::FindExtension
 Essa função é um wrapper sobrecarregado para [PathFindExtension](http://msdn.microsoft.com/library/windows/desktop/bb773587).  
  
### <a name="syntax"></a>Sintaxe  
  
```  
inline char* FindExtension(const char* pszPath);  
inline wchar_t* FindExtension(const wchar_t* pszPath);  
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [PathFindExtension](http://msdn.microsoft.com/library/windows/desktop/bb773587) para obter detalhes.  
  
 
  

## <a name="findfilename"></a> ATLPath::FindFileName
 Essa função é um wrapper sobrecarregado para [PathFindFileName](http://msdn.microsoft.com/library/windows/desktop/bb773589).  
  
### <a name="syntax"></a>Sintaxe  
  
```  
inline char* FindFileName(const char* pszPath);  
inline wchar_t* FindFileName(const wchar_t* pszPath);  
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [PathFindFileName](http://msdn.microsoft.com/library/windows/desktop/bb773589) para obter detalhes.  
  
 
  

## <a name="getdrivenumber"></a> ATLPath::GetDriveNumber  
 Essa função é um wrapper sobrecarregado para [PathGetDriveNumber](http://msdn.microsoft.com/library/windows/desktop/bb773612).  
  
### <a name="syntax"></a>Sintaxe  
  
```  
inline int GetDriveNumber(const char* pszPath);  
inline int GetDriveNumber(const wchar_t* pszPath);  
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [PathGetDriveNumber](http://msdn.microsoft.com/library/windows/desktop/bb773612) para obter detalhes.  
  
 


## <a name="isdirectory"></a>  ATLPath::IsDirectory 
Essa função é um wrapper sobrecarregado para [PathIsDirectory](https://msdn.microsoft.com/en-us/library/windows/desktop/bb773621).

```  
inline BOOL IsDirectory(const char* pszPath);
inline BOOL IsDirectory(const wchar_t* pszPath);
```  
### <a name="remarks"></a>Comentários
Consulte PathIsDirectory para obter detalhes.  

## <a name="isfilespec"></a> ATLPath::IsFileSpec
 Essa função é um wrapper sobrecarregado para [PathIsFileSpec](http://msdn.microsoft.com/library/windows/desktop/bb773627).  
  
### <a name="syntax"></a>Sintaxe  
  
```  
inline BOOL IsFileSpec(const char* pszPath);  
inline BOOL IsFileSpec(const wchar_t* pszPath);  
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [PathIsFileSpec](http://msdn.microsoft.com/library/windows/desktop/bb773627) para obter detalhes.  
  
 
  

## <a name="isprefix"></a> ATLPath::IsPrefix
 Essa função é um wrapper sobrecarregado para [PathIsPrefix](http://msdn.microsoft.com/library/windows/desktop/bb773650).  
  
### <a name="syntax"></a>Sintaxe  
  
```  
inline BOOL IsPrefix(const char* pszPrefix, const char* pszPath);  
inline BOOL IsPrefix(const wchar_t* pszPrefix, const wchar_t* pszPath);  
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [PathIsPrefix](http://msdn.microsoft.com/library/windows/desktop/bb773650) para obter detalhes.  
  
 
  

## <a name="isrelative"></a> ATLPath::IsRelative
 Essa função é um wrapper sobrecarregado para [PathIsRelative](http://msdn.microsoft.com/library/windows/desktop/bb773660).  
  
### <a name="syntax"></a>Sintaxe  
  
```  
inline BOOL IsRelative(const char* pszPath);  
inline BOOL IsRelative(const wchar_t* pszPath);  
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [PathIsRelative](http://msdn.microsoft.com/library/windows/desktop/bb773660) para obter detalhes.  
  
 
  

## <a name="isroot"></a> ATLPath::IsRoot
 Essa função é um wrapper sobrecarregado para [PathIsRoot](http://msdn.microsoft.com/library/windows/desktop/bb773674).  
  
### <a name="syntax"></a>Sintaxe  
  
```  
inline BOOL IsRoot(const char* pszPath);  
inline BOOL IsRoot(const wchar_t* pszPath);  
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [PathIsRoot](http://msdn.microsoft.com/library/windows/desktop/bb773674) para obter detalhes.  
  
 
  

## <a name="issameroot"></a> ATLPath::IsSameRoot
 Essa função é um wrapper sobrecarregado para [PathIsSameRoot](http://msdn.microsoft.com/library/windows/desktop/bb773687).  
  
### <a name="syntax"></a>Sintaxe  
  
```  
inline BOOL IsSameRoot(const char* pszPath1, const char* pszPath2);  
inline BOOL IsSameRoot(const wchar_t* pszPath1, const wchar_t* pszPath2);  
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [PathIsSameRoot](http://msdn.microsoft.com/library/windows/desktop/bb773687) para obter detalhes.  
  
 
  

## <a name="isunc"></a> ATLPath::IsUNC
 Essa função é um wrapper sobrecarregado para [PathIsUNC](http://msdn.microsoft.com/library/windows/desktop/bb773712).  
  
### <a name="syntax"></a>Sintaxe  
  
```  
inline BOOL IsUNC(const char* pszPath);  
inline BOOL IsUNC(const wchar_t* pszPath);  
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [PathIsUNC](http://msdn.microsoft.com/library/windows/desktop/bb773712) para obter detalhes.  
  
 
  

## <a name="isuncserver"></a> ATLPath::IsUNCServer
 Essa função é um wrapper sobrecarregado para [PathIsUNCServer](http://msdn.microsoft.com/library/windows/desktop/bb773722).  
  
### <a name="syntax"></a>Sintaxe  
  
```  
inline BOOL IsUNCServer(const char* pszPath);  
inline BOOL IsUNCServer(const wchar_t* pszPath);  
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [PathIsUNCServer](http://msdn.microsoft.com/library/windows/desktop/bb773722) para obter detalhes.  
  
 
  

## <a name="isuncservershare"></a> ATLPath::IsUNCServerShare
 Essa função é um wrapper sobrecarregado para [PathIsUNCServerShare](http://msdn.microsoft.com/library/windows/desktop/bb773723).  
  
### <a name="syntax"></a>Sintaxe  
  
```  
inline BOOL IsUNCServerShare(const char* pszPath);  
inline BOOL IsUNCServerShare(const wchar_t* pszPath);  
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [PathIsUNCServerShare](http://msdn.microsoft.com/library/windows/desktop/bb773723) para obter detalhes.  
  
 
  

## <a name="makepretty"></a> ATLPath::MakePretty
 Essa função é um wrapper sobrecarregado para [PathMakePretty](http://msdn.microsoft.com/library/windows/desktop/bb773725).  
  
### <a name="syntax"></a>Sintaxe  
  
```  
inline BOOL MakePretty(char* pszPath);  
inline BOOL MakePretty(wchar_t* pszPath);  
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [PathMakePretty](http://msdn.microsoft.com/library/windows/desktop/bb773725) para obter detalhes.  
  
 
  

## <a name="matchspec"></a> ATLPath::MatchSpec  
 Essa função é um wrapper sobrecarregado para [PathMatchSpec](http://msdn.microsoft.com/library/windows/desktop/bb773727).  
  
### <a name="syntax"></a>Sintaxe  
  
```  
inline BOOL MatchSpec(const char* pszPath, const char* pszSpec);  
inline BOOL MatchSpec(const wchar_t* pszPath, const wchar_t* pszSpec);  
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [PathMatchSpec](http://msdn.microsoft.com/library/windows/desktop/bb773727) para obter detalhes.  
  
 
  

## <a name="quotespaces"></a> ATLPath::QuoteSpaces  
 Essa função é um wrapper sobrecarregado para [PathQuoteSpaces](http://msdn.microsoft.com/library/windows/desktop/bb773739).  
  
### <a name="syntax"></a>Sintaxe  
  
```  
inline void QuoteSpaces(char* pszPath);  
inline void QuoteSpaces(wchar_t* pszPath);  
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [PathQuoteSpaces](http://msdn.microsoft.com/library/windows/desktop/bb773739) para obter detalhes.  
  
 
  

## <a name="relativepathto"></a> ATLPath::RelativePathTo
 Essa função é um wrapper sobrecarregado para [PathRelativePathTo](http://msdn.microsoft.com/library/windows/desktop/bb773740).  
  
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
 Consulte [PathRelativePathTo](http://msdn.microsoft.com/library/windows/desktop/bb773740) para obter detalhes.  
  
 
  

## <a name="removeargs"></a> ATLPath::RemoveArgs  
 Essa função é um wrapper sobrecarregado para [PathRemoveArgs](http://msdn.microsoft.com/library/windows/desktop/bb773742).  
  
### <a name="syntax"></a>Sintaxe  
  
```  
inline void RemoveArgs(char* pszPath);  
inline void RemoveArgs(wchar_t* pszPath);  
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [PathRemoveArgs](http://msdn.microsoft.com/library/windows/desktop/bb773742) para obter detalhes.  
  
 
  

## <a name="removebackslash"></a> ATLPath::RemoveBackslash
 Essa função é um wrapper sobrecarregado para [PathRemoveBackslash](http://msdn.microsoft.com/library/windows/desktop/bb773743).  
  
### <a name="syntax"></a>Sintaxe  
  
```  
inline char* RemoveBackslash(char* pszPath);  
inline wchar_t* RemoveBackslash(wchar_t* pszPath);  
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [PathRemoveBackslash](http://msdn.microsoft.com/library/windows/desktop/bb773743) para obter detalhes.  
  
 
  

## <a name="removeblanks"></a> ATLPath::RemoveBlanks
 Essa função é um wrapper sobrecarregado para [PathRemoveBlanks](http://msdn.microsoft.com/library/windows/desktop/bb773745).  
  
### <a name="syntax"></a>Sintaxe  
  
```  
inline void RemoveBlanks(char* pszPath);  
inline void RemoveBlanks(wchar_t* pszPath);  
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [PathRemoveBlanks](http://msdn.microsoft.com/library/windows/desktop/bb773745) para obter detalhes.  
  
 
  

## <a name="removeextension"></a> ATLPath::RemoveExtension
 Essa função é um wrapper sobrecarregado para [PathRemoveExtension](http://msdn.microsoft.com/library/windows/desktop/bb773746).  
  
### <a name="syntax"></a>Sintaxe  
  
```  
inline void RemoveExtension(char* pszPath);  
inline void RemoveExtension(wchar_t* pszPath);  
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [PathRemoveExtension](http://msdn.microsoft.com/library/windows/desktop/bb773746) para obter detalhes.  
  
 
  

## <a name="removefilespec"></a> ATLPath::RemoveFileSpec
 Essa função é um wrapper sobrecarregado para [PathRemoveFileSpec](http://msdn.microsoft.com/library/windows/desktop/bb773748).  
  
### <a name="syntax"></a>Sintaxe  
  
```  
inline BOOL RemoveFileSpec(char* pszPath);  
inline BOOL RemoveFileSpec(wchar_t* pszPath);  
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [PathRemoveFileSpec](http://msdn.microsoft.com/library/windows/desktop/bb773748) para obter detalhes.  
  
 
  

## <a name="renameextension"></a> ATLPath::RenameExtension
 Essa função é um wrapper sobrecarregado para [PathRenameExtension](http://msdn.microsoft.com/library/windows/desktop/bb773749).  
  
### <a name="syntax"></a>Sintaxe  
  
```  
inline BOOL RenameExtension(char* pszPath, const char* pszExt);  
inline BOOL RenameExtension(wchar_t* pszPath, const wchar_t* pszExt);  
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [PathRenameExtension](http://msdn.microsoft.com/library/windows/desktop/bb773749) para obter detalhes.  
  
 
  

## <a name="skiproot"></a> ATLPath::SkipRoot
 Essa função é um wrapper sobrecarregado para [PathSkipRoot](http://msdn.microsoft.com/library/windows/desktop/bb773754).  
  
### <a name="syntax"></a>Sintaxe  
  
```  
inline char* SkipRoot(const char* pszPath);  
inline wchar_t* SkipRoot(const wchar_t* pszPath);  
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [PathSkipRoot](http://msdn.microsoft.com/library/windows/desktop/bb773754) para obter detalhes.  
  
 
  

## <a name="strippath"></a> ATLPath::StripPath
 Essa função é um wrapper sobrecarregado para [PathStripPath](http://msdn.microsoft.com/library/windows/desktop/bb773756).  
  
### <a name="syntax"></a>Sintaxe  
  
```  
inline void StripPath(char* pszPath);  
inline void StripPath(wchar_t* pszPath);  
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [PathStripPath](http://msdn.microsoft.com/library/windows/desktop/bb773756) para obter detalhes.  
  
 
  


## <a name="striptoroot"></a> ATLPath::StripToRoot
 Essa função é um wrapper sobrecarregado para [PathStripToRoot](http://msdn.microsoft.com/library/windows/desktop/bb773757).  
  
### <a name="syntax"></a>Sintaxe  
  
```  
inline BOOL StripToRoot(char* pszPath);  
inline BOOL StripToRoot(wchar_t* pszPath);  
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [PathStripToRoot](http://msdn.microsoft.com/library/windows/desktop/bb773757) para obter detalhes.  
  
 
  

## <a name="unquotespaces"></a> ATLPath::UnquoteSpaces
 Essa função é um wrapper sobrecarregado para [PathUnquoteSpaces](http://msdn.microsoft.com/library/windows/desktop/bb773763).  
  
### <a name="syntax"></a>Sintaxe  
  
```  
inline void UnquoteSpaces(char* pszPath);  
inline void UnquoteSpaces(wchar_t* pszPath);  
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [PathUnquoteSpaces](http://msdn.microsoft.com/library/windows/desktop/bb773763) para obter detalhes.  
  
 
  
 
