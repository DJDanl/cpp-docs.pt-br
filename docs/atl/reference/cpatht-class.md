---
title: Classe CPathT | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- CPathT class
ms.assetid: eba4137d-1fd2-4b44-a2e1-0944db64df3c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 60541891832a3d466f7396086ac0918108991582
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43753156"
---
# <a name="cpatht-class"></a>Classe CPathT

Essa classe representa um caminho.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <typename StringType>
class CPathT
```

#### <a name="parameters"></a>Parâmetros

*StringType*  
A classe de cadeia de caracteres ATL/MFC a ser usado para o caminho (consulte [CStringT](../../atl-mfc-shared/reference/cstringt-class.md)).

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|[CPathT::PCXSTR](#pcxstr)|Um tipo de cadeia de caracteres constante.|
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
|[CPathT::Append](#append)|Chame esse método para acrescentar uma cadeia de caracteres para o caminho atual.|
|[CPathT::BuildRoot](#buildroot)|Chame esse método para criar um caminho raiz de um número determinado de unidade.|
|[CPathT::Canonicalize](#canonicalize)|Chame esse método para converter o caminho em forma canônica.|
|[CPathT::Combine](#combine)|Chame esse método para concatenar uma cadeia de caracteres que representa um nome de diretório e uma cadeia de caracteres que representa um nome de caminho de arquivo em um caminho.|
|[CPathT::CommonPrefix](#commonprefix)|Chame esse método para determinar se o caminho especificado compartilha um prefixo comum com o caminho atual.|
|[CPathT::CompactPath](#compactpath)|Chame esse método para truncar um caminho de arquivo para se ajustarem à largura de um determinado pixel com a substituição de componentes de caminho com reticências.|
|[CPathT::CompactPathEx](#compactpathex)|Chame esse método para truncar um caminho de arquivo para se ajustar dentro de um determinado número de caracteres com a substituição de componentes de caminho com reticências.|
|[CPathT::FileExists](#fileexists)|Chame esse método para verificar se existe o arquivo com esse nome de caminho.|
|[CPathT::FindExtension](#findextension)|Chame esse método para localizar a posição da extensão do arquivo no caminho.|
|[CPathT::FindFileName](#findfilename)|Chame esse método para localizar a posição do nome do arquivo no caminho.|
|[CPathT::GetDriveNumber](#getdrivenumber)|Chame esse método para pesquisar o caminho para uma letra de unidade dentro do intervalo de 'A' a 'Z' e retornar o número de unidade correspondente.|
|[CPathT::GetExtension](#getextension)|Chame esse método para obter a extensão de arquivo do caminho.|
|[CPathT::IsDirectory](#isdirectory)|Chame esse método para verificar se o caminho é um diretório válido.|
|[CPathT::IsFileSpec](#isfilespec)|Chame esse método para pesquisar um caminho para qualquer caractere de delimitação de caminho (por exemplo, ':' ou '\\'). Se não houver nenhum caractere de delimitação de caminho presente, o caminho é considerado um caminho de especificação de arquivo.|
|[CPathT::IsPrefix](#isprefix)|Chame esse método para determinar se um caminho contém um prefixo válido de tipo passado *pszPrefix*.|
|[CPathT::IsRelative](#isrelative)|Chame esse método para determinar se o caminho é relativo.|
|[CPathT::IsRoot](#isroot)|Chame esse método para determinar se o caminho é uma diretório raiz.|
|[CPathT::IsSameRoot](#issameroot)|Chame esse método para determinar se outro caminho tem um componente de raiz comum com o caminho atual.|
|[CPathT::IsUNC](#isunc)|Chame esse método para determinar se o caminho é um caminho UNC (convenção de nomenclatura universal) válido para um servidor e compartilhar.|
|[CPathT::IsUNCServer](#isuncserver)|Chame esse método para determinar se o caminho é um caminho UNC (convenção de nomenclatura universal) válido para apenas um servidor.|
|[CPathT::IsUNCServerShare](#isuncservershare)|Chame esse método para determinar se o caminho é um caminho válido de compartilhamento UNC (convenção de nomenclatura universal), \\ \  *server*\ *compartilhar*.|
|[CPathT::MakePretty](#makepretty)|Chame esse método para converter um caminho em todos os caracteres minúsculos para fornecer o caminho de uma aparência consistente.|
|[CPathT::MatchSpec](#matchspec)|Chame esse método para pesquisar o caminho para uma cadeia de caracteres que contém um tipo de correspondência de curinga.|
|[CPathT::QuoteSpaces](#quotespaces)|Chame esse método para coloque o caminho entre aspas se ele contiver espaços.|
|[CPathT::RelativePathTo](#relativepathto)|Chame esse método para criar um caminho relativo de um arquivo ou pasta para outra.|
|[CPathT::RemoveArgs](#removeargs)|Chame esse método para remover quaisquer argumentos de linha de comando do caminho.|
|[CPathT::RemoveBackslash](#removebackslash)|Chame esse método para remover a barra invertida do caminho.|
|[CPathT::RemoveBlanks](#removeblanks)|Chame esse método para remover todos os espaços à esquerda e à direita do caminho.|
|[CPathT::RemoveExtension](#removeextension)|Chame esse método para remover a extensão de arquivo do caminho, se houver um.|
|[CPathT::RemoveFileSpec](#removefilespec)|Chame esse método para remover o nome de arquivo à direita e a barra invertida do caminho, se ele tivê-los.|
|[CPathT::RenameExtension](#renameextension)|Chame esse método para substituir a extensão de nome de arquivo no caminho com uma nova extensão. Se o nome do arquivo não contiver uma extensão, a extensão será anexada ao final da cadeia de caracteres.|
|[CPathT::SkipRoot](#skiproot)|Chame esse método para analisar um caminho, ignorando a letra da unidade ou partes do caminho de compartilhamento do servidor UNC.|
|[CPathT::StripPath](#strippath)|Chame esse método para remover a parte do caminho de um caminho totalmente qualificado e o nome do arquivo.|
|[CPathT::StripToRoot](#striptoroot)|Chame esse método para remover todas as partes do caminho, exceto para as informações da raiz.|
|[CPathT::UnquoteSpaces](#unquotespaces)|Chame esse método para remover as aspas de início e no final de um caminho.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CPathT::operator StringType de const &](#operator_const_stringtype_amp)|Esse operador permite que o objeto a ser tratado como uma cadeia de caracteres.|
|[CPathT::operator CPathT::PCXSTR](#operator_cpatht__pcxstr)|Esse operador permite que o objeto a ser tratado como uma cadeia de caracteres.|
|[CPathT::operator StringType &](#operator_stringtype)|Esse operador permite que o objeto a ser tratado como uma cadeia de caracteres.|
|[+ CPathT::operator =](#operator_add_eq)|Esse operador acrescenta uma cadeia de caracteres para o caminho.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CPathT::m_strPath](#m_strpath)|O caminho.|

## <a name="remarks"></a>Comentários

`CPath`, `CPathA`, e `CPathW` são instanciações de `CPathT` definido da seguinte maneira:

`typedef CPathT< CString > CPath;`

`typedef CPathT< CStringA > CPathA;`

`typedef CPathT< CStringW > CPathW;`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlpath

##  <a name="addbackslash"></a>  CPathT::AddBackslash

Chame esse método para adicionar uma barra invertida ao final de uma cadeia de caracteres para criar a sintaxe correta para um caminho. Se o caminho já tiver uma barra invertida, nenhuma barra invertida será adicionada.

```
void AddBackslash();
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathAddBackSlash](/windows/desktop/api/shlwapi/nf-shlwapi-pathaddbackslasha).

##  <a name="addextension"></a>  CPathT::AddExtension

Chame esse método para adicionar uma extensão de arquivo a um caminho.

```
BOOL AddExtension(PCXSTR pszExtension);
```

### <a name="parameters"></a>Parâmetros

*pszExtension*  
A extensão de arquivo para adicionar.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathAddExtension](/windows/desktop/api/shlwapi/nf-shlwapi-pathaddextensiona).

##  <a name="append"></a>  CPathT::Append

Chame esse método para acrescentar uma cadeia de caracteres para o caminho atual.

```
BOOL Append(PCXSTR pszMore);
```

### <a name="parameters"></a>Parâmetros

*pszMore*  
A cadeia de caracteres a ser acrescentada.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathAppend](/windows/desktop/api/shlwapi/nf-shlwapi-pathappenda).

##  <a name="buildroot"></a>  CPathT::BuildRoot

Chame esse método para criar um caminho raiz de um número determinado de unidade.

```
void BuildRoot(int iDrive);
```

### <a name="parameters"></a>Parâmetros

*iDrive*  
O número da unidade (0 é r:, 1 é b: e assim por diante).

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathBuildRoot](/windows/desktop/api/shlwapi/nf-shlwapi-pathbuildroota).

##  <a name="canonicalize"></a>  CPathT::Canonicalize

Chame esse método para converter o caminho em forma canônica.

```
void Canonicalize();
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathCanonicalize](/windows/desktop/api/shlwapi/nf-shlwapi-pathcanonicalizea).

##  <a name="combine"></a>  CPathT::Combine

Chame esse método para concatenar uma cadeia de caracteres que representa um nome de diretório e uma cadeia de caracteres que representa um nome de caminho de arquivo em um caminho.

```
void Combine(PCXSTR pszDir, PCXSTR  pszFile);
```

### <a name="parameters"></a>Parâmetros

*pszDir*  
O caminho do diretório.

*pszFile*  
O caminho do arquivo.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathCombine](/windows/desktop/api/shlwapi/nf-shlwapi-pathcombinea).

##  <a name="commonprefix"></a>  CPathT::CommonPrefix

Chame esse método para determinar se o caminho especificado compartilha um prefixo comum com o caminho atual.

```
CPathT<StringType> CommonPrefix(PCXSTR pszOther);
```

### <a name="parameters"></a>Parâmetros

*pszOther*  
O caminho a ser comparado ao atual.

### <a name="return-value"></a>Valor de retorno

Retorna o prefixo comum.

### <a name="remarks"></a>Comentários

Um prefixo é um destes tipos: "c:\\\\",".","..","... \\\\". Para obter mais informações, consulte [PathCommonPrefix](/windows/desktop/api/shlwapi/nf-shlwapi-pathcommonprefixa).

##  <a name="compactpath"></a>  CPathT::CompactPath

Chame esse método para truncar um caminho de arquivo para se ajustarem à largura de um determinado pixel com a substituição de componentes de caminho com reticências.

```
BOOL CompactPath(HDC hDC, UINT nWidth);
```

### <a name="parameters"></a>Parâmetros

*hDC*  
O contexto de dispositivo usado para métricas de fonte.

*nWidth*  
A largura, em pixels, que a cadeia de caracteres será forçada a se ajustar no.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathCompactPath](/windows/desktop/api/shlwapi/nf-shlwapi-pathcompactpatha).

##  <a name="compactpathex"></a>  CPathT::CompactPathEx

Chame esse método para truncar um caminho de arquivo para se ajustar dentro de um determinado número de caracteres com a substituição de componentes de caminho com reticências.

```
BOOL CompactPathEx(UINT nMaxChars, DWORD dwFlags = 0);
```

### <a name="parameters"></a>Parâmetros

*nMaxChars*  
O número máximo de caracteres a ser contido na nova cadeia de caracteres, incluindo o caractere nulo de terminação.

*dwFlags*  
Reservado.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathCompactPathEx](/windows/desktop/api/shlwapi/nf-shlwapi-pathcompactpathexa).

##  <a name="cpatht"></a>  CPathT::CPathT

O construtor.

```
CPathT(PCXSTR pszPath);
CPathT(const CPathT<StringType>& path);
CPathT() throw();
```

### <a name="parameters"></a>Parâmetros

*pszPath*  
O ponteiro para uma cadeia de caracteres de caminho.

*path*  
A cadeia de caracteres do caminho.

##  <a name="fileexists"></a>  CPathT::FileExists

Chame esse método para verificar se existe o arquivo com esse nome de caminho.

```
BOOL FileExists() const;
```

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se o arquivo existir, FALSE caso contrário.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathFileExists](/windows/desktop/api/shlwapi/nf-shlwapi-pathfileexistsa).

##  <a name="findextension"></a>  CPathT::FindExtension

Chame esse método para localizar a posição da extensão do arquivo no caminho.

```
int FindExtension() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna a posição do "." precede a extensão. Se nenhuma extensão for encontrado, retornará -1.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathFindExtension](/windows/desktop/api/shlwapi/nf-shlwapi-pathfindextensiona).

##  <a name="findfilename"></a>  CPathT::FindFileName

Chame esse método para localizar a posição do nome do arquivo no caminho.

```
int FindFileName() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna a posição do nome do arquivo. Se nenhum nome de arquivo for encontrado, retornará -1.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathFindFileName](/windows/desktop/api/shlwapi/nf-shlwapi-pathfindfilenamea).

##  <a name="getdrivenumber"></a>  CPathT::GetDriveNumber

Chame esse método para pesquisar o caminho para uma letra de unidade dentro do intervalo de 'A' a 'Z' e retornar o número de unidade correspondente.

```
int GetDriveNumber() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna o número de unidade como um inteiro de 0 a 25 (correspondente a 'A' a 'Z') se o caminho tiver uma letra de unidade, ou -1, caso contrário.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathGetDriveNumber](/windows/desktop/api/shlwapi/nf-shlwapi-pathgetdrivenumbera).

##  <a name="getextension"></a>  CPathT::GetExtension

Chame esse método para obter a extensão de arquivo do caminho.

```
StringType GetExtension() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna a extensão de arquivo.

##  <a name="isdirectory"></a>  CPathT::IsDirectory

Chame esse método para verificar se o caminho é um diretório válido.

```
BOOL IsDirectory() const;
```

### <a name="return-value"></a>Valor de retorno

Se o caminho for um diretório, FALSE caso contrário, retorna um valor diferente de zero (16).

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathIsDirectory](/windows/desktop/api/shlwapi/nf-shlwapi-pathisdirectorya).

##  <a name="isfilespec"></a>  CPathT::IsFileSpec

Chame esse método para pesquisar um caminho para qualquer caractere de delimitação de caminho (por exemplo, ':' ou '\\'). Se não houver nenhum caractere de delimitação de caminho presente, o caminho é considerado um caminho de especificação de arquivo.

```
BOOL IsFileSpec() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna TRUE se não houver nenhum caractere de delimitação de caminho dentro do caminho, ou FALSE se não houver caracteres de delimitação de caminho.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathIsFileSpec](/windows/desktop/api/shlwapi/nf-shlwapi-pathisfilespeca).

##  <a name="isprefix"></a>  CPathT::IsPrefix

Chame esse método para determinar se um caminho contém um prefixo válido de tipo passado *pszPrefix*.

```
BOOL IsPrefix(PCXSTR pszPrefix) const;
```

### <a name="parameters"></a>Parâmetros

*pszPrefix*  
O prefixo a ser pesquisado. Um prefixo é um destes tipos: "c:\\\\",".","..","... \\\\".

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se o caminho contém o prefixo, ou FALSO caso contrário.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathIsPrefix](/windows/desktop/api/shlwapi/nf-shlwapi-pathisprefixa).

##  <a name="isrelative"></a>  CPathT::IsRelative

Chame esse método para determinar se o caminho é relativo.

```
BOOL IsRelative() const;
```

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se o caminho for relativo, ou FALSE se for absoluto.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathIsRelative](/windows/desktop/api/shlwapi/nf-shlwapi-pathisrelativea).

##  <a name="isroot"></a>  CPathT::IsRoot

Chame esse método para determinar se o caminho é uma diretório raiz.

```
BOOL IsRoot() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se o caminho é uma raiz, ou FALSO caso contrário.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathIsRoot](/windows/desktop/api/shlwapi/nf-shlwapi-pathisroota).

##  <a name="issameroot"></a>  CPathT::IsSameRoot

Chame esse método para determinar se outro caminho tem um componente de raiz comum com o caminho atual.

```
BOOL IsSameRoot(PCXSTR pszOther) const;
```

### <a name="parameters"></a>Parâmetros

*pszOther*  
O caminho.

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se ambas as cadeias de caracteres têm o mesmo componente raiz, ou FALSO caso contrário.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathIsSameRoot](/windows/desktop/api/shlwapi/nf-shlwapi-pathissameroota).

##  <a name="isunc"></a>  CPathT::IsUNC

Chame esse método para determinar se o caminho é um caminho UNC (convenção de nomenclatura universal) válido para um servidor e compartilhar.

```
BOOL IsUNC() const;
```

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se o caminho é um caminho UNC válido ou FALSE caso contrário.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathIsUNC](/windows/desktop/api/shlwapi/nf-shlwapi-pathisunca).

##  <a name="isuncserver"></a>  CPathT::IsUNCServer

Chame esse método para determinar se o caminho é um caminho UNC (convenção de nomenclatura universal) válido para apenas um servidor.

```
BOOL IsUNCServer() const;
```

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se a cadeia de caracteres é um caminho UNC para um servidor somente (sem nome de compartilhamento) válido ou FALSE caso contrário.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathIsUNCServer](/windows/desktop/api/shlwapi/nf-shlwapi-pathisuncservera).

##  <a name="isuncservershare"></a>  CPathT::IsUNCServerShare

Chame esse método para determinar se o caminho é um caminho válido de compartilhamento UNC (convenção de nomenclatura universal), \\ \  *server*\ *compartilhar*.

```
BOOL IsUNCServerShare() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se o caminho está no formato \\ \  *server*\ *compartilhar*, ou FALSO caso contrário.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathIsUNCServerShare](/windows/desktop/api/shlwapi/nf-shlwapi-pathisuncserversharea).

##  <a name="m_strpath"></a>  CPathT::m_strPath

O caminho.

```
StringType m_strPath;
```

### <a name="remarks"></a>Comentários

`StringType` é o parâmetro de modelo para `CPathT`.

##  <a name="makepretty"></a>  CPathT::MakePretty

Chame esse método para converter um caminho em todos os caracteres minúsculos para fornecer o caminho de uma aparência consistente.

```
BOOL MakePretty();
```

### <a name="return-value"></a>Valor de retorno

Caso contrário, retornará TRUE se o caminho tiver sido convertido, ou FALSE.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathMakePretty](/windows/desktop/api/shlwapi/nf-shlwapi-pathmakeprettya).

##  <a name="matchspec"></a>  CPathT::MatchSpec

Chame esse método para pesquisar o caminho para uma cadeia de caracteres que contém um tipo de correspondência de curinga.

```
BOOL MatchSpec(PCXSTR pszSpec) const;
```

### <a name="parameters"></a>Parâmetros

*pszSpec*  
Ponteiro para uma cadeia de caracteres terminada em nulo com o tipo de arquivo a ser pesquisado. Por exemplo, para testar se o arquivo no caminho atual é um arquivo de DOC *pszSpec* deve ser definido como "*. doc".

### <a name="return-value"></a>Valor de retorno

Caso contrário, retornará TRUE se a cadeia de caracteres corresponder, ou FALSE.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathMatchSpec](/windows/desktop/api/shlwapi/nf-shlwapi-pathmatchspeca).

##  <a name="operator_add_eq"></a>  + CPathT::operator =

Esse operador acrescenta uma cadeia de caracteres para o caminho.

```
CPathT<StringType>& operator+=(PCXSTR pszMore);
```

### <a name="parameters"></a>Parâmetros

*pszMore*  
A cadeia de caracteres a ser acrescentada.

### <a name="return-value"></a>Valor de retorno

Retorna o caminho de atualização.

##  <a name="operator_const_stringtype_amp"></a>  CPathT::operator StringType de const &amp;

Esse operador permite que o objeto a ser tratado como uma cadeia de caracteres.

```
operatorconst StringType&() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna uma cadeia de caracteres que representa o caminho atual gerenciado por este objeto.

##  <a name="operator_cpatht__pcxstr"></a>  CPathT::operator CPathT::PCXSTR

Esse operador permite que o objeto a ser tratado como uma cadeia de caracteres.

```
operatorPCXSTR() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna uma cadeia de caracteres que representa o caminho atual gerenciado por este objeto.

##  <a name="operator_stringtype__amp"></a>  CPathT::operator StringType &amp;

Esse operador permite que o objeto a ser tratado como uma cadeia de caracteres.

```
operatorStringType&() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna uma cadeia de caracteres que representa o caminho atual gerenciado por este objeto.

##  <a name="pcxstr"></a>  CPathT::PCXSTR

Um tipo de cadeia de caracteres constante.

```
typedef StringType::PCXSTR PCXSTR;
```

### <a name="remarks"></a>Comentários

`StringType` é o parâmetro de modelo para `CPathT`.

##  <a name="pxstr"></a>  CPathT::PXSTR

Um tipo de cadeia de caracteres.

```
typedef StringType::PXSTR PXSTR;
```

### <a name="remarks"></a>Comentários

`StringType` é o parâmetro de modelo para `CPathT`.

##  <a name="quotespaces"></a>  CPathT::QuoteSpaces

Chame esse método para coloque o caminho entre aspas se ele contiver espaços.

```
void QuoteSpaces();
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathQuoteSpaces](/windows/desktop/api/shlwapi/nf-shlwapi-pathquotespacesa).

##  <a name="relativepathto"></a>  CPathT::RelativePathTo

Chame esse método para criar um caminho relativo de um arquivo ou pasta para outra.

```
BOOL RelativePathTo(
    PCXSTR pszFrom,
    DWORD dwAttrFrom,
    PCXSTR pszTo,
    DWORD dwAttrTo);
```

### <a name="parameters"></a>Parâmetros

*pszFrom*  
O início do caminho relativo.

*dwAttrFrom*  
Os atributos de arquivo do *pszFrom*. Se esse valor contém FILE_ATTRIBUTE_DIRECTORY, *pszFrom* assumida para ser um diretório; caso contrário, *pszFrom* é considerado como um arquivo.

*pszTo*  
O ponto de extremidade do caminho relativo.

*dwAttrTo*  
Os atributos de arquivo do *pszTo*. Se esse valor contém FILE_ATTRIBUTE_DIRECTORY, *pszTo* assumida para ser um diretório; caso contrário, *pszTo* é considerado como um arquivo.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathRelativePathTo](/windows/desktop/api/shlwapi/nf-shlwapi-pathrelativepathtoa).

##  <a name="removeargs"></a>  CPathT::RemoveArgs

Chame esse método para remover quaisquer argumentos de linha de comando do caminho.

```
void RemoveArgs();
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathRemoveArgs](/windows/desktop/api/shlwapi/nf-shlwapi-pathremoveargsa).

##  <a name="removebackslash"></a>  CPathT::RemoveBackslash

Chame esse método para remover a barra invertida do caminho.

```
void RemoveBackslash();
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathRemoveBackslash](/windows/desktop/api/shlwapi/nf-shlwapi-pathremovebackslasha).

##  <a name="removeblanks"></a>  CPathT::RemoveBlanks

Chame esse método para remover todos os espaços à esquerda e à direita do caminho.

```
void RemoveBlanks();
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathRemoveBlanks](/windows/desktop/api/shlwapi/nf-shlwapi-pathremoveblanksa).

##  <a name="removeextension"></a>  CPathT::RemoveExtension

Chame esse método para remover a extensão de arquivo do caminho, se houver um.

```
void RemoveExtension();
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathRemoveExtension](/windows/desktop/api/shlwapi/nf-shlwapi-pathremoveextensiona).

##  <a name="removefilespec"></a>  CPathT::RemoveFileSpec

Chame esse método para remover o nome de arquivo à direita e a barra invertida do caminho, se ele tivê-los.

```
BOOL RemoveFileSpec();
```

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathRemoveFileSpec](/windows/desktop/api/shlwapi/nf-shlwapi-pathremovefilespeca).

##  <a name="renameextension"></a>  CPathT::RenameExtension

Chame esse método para substituir a extensão de nome de arquivo no caminho com uma nova extensão. Se o nome do arquivo não contiver uma extensão, a extensão será anexada ao final do caminho.

```
BOOL RenameExtension(PCXSTR pszExtension);
```

### <a name="parameters"></a>Parâmetros

*pszExtension*  
A nova extensão de nome de arquivo, precedido por um "." caracteres.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathRenameExtension](/windows/desktop/api/shlwapi/nf-shlwapi-pathrenameextensiona).

##  <a name="skiproot"></a>  CPathT::SkipRoot

Chame esse método para analisar um caminho, ignorando a letra da unidade ou partes do caminho de compartilhamento do servidor UNC (convenção de nomenclatura universal).

```
int SkipRoot() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna a posição de início do subcaminho que segue a raiz (letra da unidade ou o servidor/compartilhamento UNC).

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathSkipRoot](/windows/desktop/api/shlwapi/nf-shlwapi-pathskiproota).

##  <a name="strippath"></a>  CPathT::StripPath

Chame esse método para remover a parte do caminho de um caminho totalmente qualificado e o nome do arquivo.

```
void StripPath();
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathStripPath](/windows/desktop/api/shlwapi/nf-shlwapi-pathstrippatha).

##  <a name="striptoroot"></a>  CPathT::StripToRoot

Chame esse método para remover todas as partes do caminho, exceto para as informações da raiz.

```
BOOL StripToRoot();
```

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se uma letra de unidade válido foi encontrado no caminho, ou FALSO caso contrário.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathStripToRoot](/windows/desktop/api/shlwapi/nf-shlwapi-pathstriptoroota).

##  <a name="unquotespaces"></a>  CPathT::UnquoteSpaces

Chame esse método para remover as aspas de início e no final de um caminho.

```
void UnquoteSpaces();
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [PathUnquoteSpaces](/windows/desktop/api/shlwapi/nf-shlwapi-pathunquotespacesa).

##  <a name="xchar"></a>  CPathT::XCHAR

Um tipo de caractere.

```
typedef StringType::XCHAR XCHAR;
```

### <a name="remarks"></a>Comentários

`StringType` é o parâmetro de modelo para `CPathT`.

## <a name="see-also"></a>Consulte também

[Classes](../../atl/reference/atl-classes.md)   
[Classe CStringT](../../atl-mfc-shared/reference/cstringt-class.md)