---
title: Classe CPathT | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
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
caps.latest.revision: 20
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 8cbd91ae1c4318788b38b2daaa7721d1a29fca98
ms.lasthandoff: 02/25/2017

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
 `StringType`  
 A classe de cadeia de caracteres ATL/MFC para usar para o caminho (consulte [CStringT](../../atl-mfc-shared/reference/cstringt-class.md)).  
  
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
|[CPathT::AddExtension](#addextension)|Chame esse método para adicionar uma extensão de arquivo em um caminho.|  
|[CPathT::Append](#append)|Chame esse método para acrescentar uma cadeia de caracteres para o caminho atual.|  
|[CPathT::BuildRoot](#buildroot)|Chame esse método para criar um caminho raiz de um número de unidade especificada.|  
|[CPathT::Canonicalize](#canonicalize)|Chame esse método para converter o caminho em forma canônica.|  
|[CPathT::Combine](#combine)|Chame esse método para concatenar uma cadeia de caracteres que representa um nome de diretório e uma cadeia de caracteres que representa um nome de caminho de arquivo em um caminho.|  
|[CPathT::CommonPrefix](#commonprefix)|Chame esse método para determinar se o caminho especificado compartilha um prefixo comum com o caminho atual.|  
|[CPathT::CompactPath](#compactpath)|Chame esse método para truncar um caminho de arquivo para se ajustarem à largura de um determinado pixel com a substituição de componentes de caminho com reticências.|  
|[CPathT::CompactPathEx](#compactpathex)|Chame esse método para truncar um caminho de arquivo para se ajustar dentro de um determinado número de caracteres com a substituição de componentes de caminho com reticências.|  
|[CPathT::FileExists](#fileexists)|Chame esse método para verificar se existe o arquivo com esse nome de caminho.|  
|[CPathT::FindExtension](#findextension)|Chame esse método para localizar a posição da extensão do arquivo no caminho.|  
|[CPathT::FindFileName](#findfilename)|Chame esse método para localizar a posição do nome do arquivo no caminho.|  
|[CPathT::GetDriveNumber](#getdrivenumber)|Chame esse método para procurar o caminho para uma letra de unidade dentro do intervalo de 'A' a 'Z' e retornar o número de unidade correspondente.|  
|[CPathT::GetExtension](#getextension)|Chame esse método para obter a extensão de arquivo do caminho.|  
|[CPathT::IsDirectory](#isdirectory)|Chame esse método para verificar se o caminho é um diretório válido.|  
|[CPathT::IsFileSpec](#isfilespec)|Chame esse método para pesquisar um caminho para todos os caracteres de delimitação de caminho (por exemplo, ':' ou '\\'). Se não houver nenhum caractere de delimitação de caminho presente, o caminho é considerado um caminho de especificação de arquivo.|  
|[CPathT::IsPrefix](#isprefix)|Chame esse método para determinar se um caminho contém um prefixo válido de tipo passado `pszPrefix`.|  
|[CPathT::IsRelative](#isrelative)|Chame esse método para determinar se o caminho é relativo.|  
|[CPathT::IsRoot](#isroot)|Chame esse método para determinar se o caminho é uma diretório raiz.|  
|[CPathT::IsSameRoot](#issameroot)|Chame esse método para determinar se outro caminho tem um componente raiz comuns com o caminho atual.|  
|[CPathT::IsUNC](#isunc)|Chame esse método para determinar se o caminho é um caminho UNC (convenção de nomenclatura universal) válido para um servidor e compartilhamento.|  
|[CPathT::IsUNCServer](#isuncserver)|Chame esse método para determinar se o caminho é um caminho UNC (convenção de nomenclatura universal) válido para um servidor.|  
|[CPathT::IsUNCServerShare](#isuncservershare)|Chame esse método para determinar se o caminho é um caminho válido de compartilhamento UNC (convenção de nomenclatura universal), \\ \  *servidor*\ *compartilhar*.|  
|[CPathT::MakePretty](#makepretty)|Chame esse método para converter um caminho em todos os caracteres minúsculos para fornecer o caminho de uma aparência consistente.|  
|[CPathT::MatchSpec](#matchspec)|Chame esse método para pesquisar o caminho para uma cadeia de caracteres que contém um tipo de correspondência de curingas.|  
|[CPathT::QuoteSpaces](#quotespaces)|Chame esse método para colocar o caminho entre aspas se ele contiver espaços.|  
|[CPathT::RelativePathTo](#relativepathto)|Chame esse método para criar um caminho relativo de um arquivo ou pasta para outra.|  
|[CPathT::RemoveArgs](#removeargs)|Chame esse método para remover quaisquer argumentos de linha de comando do caminho.|  
|[CPathT::RemoveBackslash](#removebackslash)|Chame esse método para remover a barra invertida à direita do caminho.|  
|[CPathT::RemoveBlanks](#removeblanks)|Chame esse método para remover todos os espaços à esquerda e à direita do caminho.|  
|[CPathT::RemoveExtension](#removeextension)|Chame esse método para remover a extensão do arquivo do caminho, se houver.|  
|[CPathT::RemoveFileSpec](#removefilespec)|Chame esse método para remover o nome de arquivo à direita e a barra invertida do caminho, caso existam.|  
|[CPathT::RenameExtension](#renameextension)|Chame esse método para substituir a extensão de nome de arquivo no caminho com uma nova extensão. Se o nome do arquivo não contém uma extensão, a extensão será anexada ao final da cadeia de caracteres.|  
|[CPathT::SkipRoot](#skiproot)|Chame esse método para analisar um caminho, ignorando a letra da unidade ou partes do caminho de compartilhamento do servidor UNC.|  
|[CPathT::StripPath](#strippath)|Chame esse método para remover a parte do caminho de um caminho totalmente qualificado e o nome do arquivo.|  
|[CPathT::StripToRoot](#striptoroot)|Chame esse método para remover todas as partes do caminho, exceto as informações da raiz.|  
|[CPathT::UnquoteSpaces](#unquotespaces)|Chame esse método para remover as aspas no início e no final de um caminho.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[StringType const CPathT::operator < /](#operator_const_stringtype_amp)|Este operador permite que o objeto deve ser tratada como uma cadeia de caracteres.|  
|[CPathT::operator CPathT::PCXSTR](#operator_cpatht__pcxstr)|Este operador permite que o objeto deve ser tratada como uma cadeia de caracteres.|  
|[CPathT::operator StringType < /](#operator_stringtype)|Este operador permite que o objeto deve ser tratada como uma cadeia de caracteres.|  
|[+ = CPathT::operator](#operator_add_eq)|Este operador acrescenta uma cadeia de caracteres para o caminho.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPathT::m_strPath](#m_strpath)|O caminho.|  
  
## <a name="remarks"></a>Comentários  
 `CPath`, `CPathA`, e `CPathW` são instanciações de `CPathT` definida da seguinte maneira:  
  
 `typedef CPathT< CString > CPath;`  
  
 `typedef CPathT< CStringA > CPathA;`  
  
 `typedef CPathT< CStringW > CPathW;`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlpath.h  
  
##  <a name="addbackslash"></a>CPathT::AddBackslash  
 Chame esse método para adicionar uma barra invertida ao final de uma cadeia de caracteres para criar a sintaxe correta para um caminho. Se o caminho já tiver uma barra invertida, sem barras invertidas serão adicionada.  
  
```
void AddBackslash();
```  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [PathAddBackSlash](http://msdn.microsoft.com/library/windows/desktop/bb773561).  
  
##  <a name="addextension"></a>CPathT::AddExtension  
 Chame esse método para adicionar uma extensão de arquivo em um caminho.  
  
```
BOOL AddExtension(PCXSTR pszExtension);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszExtension`  
 A extensão de arquivo para adicionar.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna verdadeiro em caso de êxito, FALSE em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [PathAddExtension](http://msdn.microsoft.com/library/windows/desktop/bb773563).  
  
##  <a name="append"></a>CPathT::Append  
 Chame esse método para acrescentar uma cadeia de caracteres para o caminho atual.  
  
```
BOOL Append(PCXSTR pszMore);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszMore`  
 A cadeia de caracteres a ser acrescentada.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna verdadeiro em caso de êxito, FALSE em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [PathAppend](http://msdn.microsoft.com/library/windows/desktop/bb773565).  
  
##  <a name="buildroot"></a>CPathT::BuildRoot  
 Chame esse método para criar um caminho raiz de um número de unidade especificada.  
  
```
void BuildRoot(int iDrive);
```  
  
### <a name="parameters"></a>Parâmetros  
 *iDrive*  
 O número da unidade (0 é r:, 1 é b: e assim por diante).  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [PathBuildRoot](http://msdn.microsoft.com/library/windows/desktop/bb773567).  
  
##  <a name="canonicalize"></a>CPathT::Canonicalize  
 Chame esse método para converter o caminho em forma canônica.  
  
```
void Canonicalize();
```  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [PathCanonicalize](http://msdn.microsoft.com/library/windows/desktop/bb773569).  
  
##  <a name="combine"></a>CPathT::Combine  
 Chame esse método para concatenar uma cadeia de caracteres que representa um nome de diretório e uma cadeia de caracteres que representa um nome de caminho de arquivo em um caminho.  
  
```
void Combine(PCXSTR pszDir, PCXSTR  pszFile);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszDir`  
 O caminho do diretório.  
  
 *pszFile*  
 O caminho do arquivo.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [PathCombine](http://msdn.microsoft.com/library/windows/desktop/bb773571).  
  
##  <a name="commonprefix"></a>CPathT::CommonPrefix  
 Chame esse método para determinar se o caminho especificado compartilha um prefixo comum com o caminho atual.  
  
```
CPathT<StringType> CommonPrefix(PCXSTR pszOther);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszOther`  
 O caminho a ser comparado com o atual.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o prefixo comum.  
  
### <a name="remarks"></a>Comentários  
 Um prefixo é um destes tipos: "c:\\\\",".","..","... \\\\". Para obter mais informações, consulte [PathCommonPrefix](http://msdn.microsoft.com/library/windows/desktop/bb773574).  
  
##  <a name="compactpath"></a>CPathT::CompactPath  
 Chame esse método para truncar um caminho de arquivo para se ajustarem à largura de um determinado pixel com a substituição de componentes de caminho com reticências.  
  
```
BOOL CompactPath(HDC hDC, UINT nWidth);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hDC`  
 O contexto de dispositivo usado para métricas de fonte.  
  
 `nWidth`  
 A largura, em pixels, que será forçada a cadeia de caracteres para caber em.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna verdadeiro em caso de êxito, FALSE em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [PathCompactPath](http://msdn.microsoft.com/library/windows/desktop/bb773575).  
  
##  <a name="compactpathex"></a>CPathT::CompactPathEx  
 Chame esse método para truncar um caminho de arquivo para se ajustar dentro de um determinado número de caracteres com a substituição de componentes de caminho com reticências.  
  
```
BOOL CompactPathEx(UINT nMaxChars, DWORD dwFlags = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nMaxChars`  
 O número máximo de caracteres para ser contida na nova cadeia de caracteres, incluindo o caractere de terminação nula.  
  
 `dwFlags`  
 Reservado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna verdadeiro em caso de êxito, FALSE em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [PathCompactPathEx](http://msdn.microsoft.com/library/windows/desktop/bb773578).  
  
##  <a name="cpatht"></a>CPathT::CPathT  
 O construtor.  
  
```
CPathT(PCXSTR pszPath);
CPathT(const CPathT<StringType>& path);
CPathT() throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *pszPath*  
 O ponteiro para uma cadeia de caracteres do caminho.  
  
 *path*  
 A cadeia de caracteres do caminho.  
  
##  <a name="fileexists"></a>CPathT::FileExists  
 Chame esse método para verificar se existe o arquivo com esse nome de caminho.  
  
```
BOOL FileExists() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna TRUE se o arquivo existir, FALSO caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [PathFileExists](http://msdn.microsoft.com/library/windows/desktop/bb773584).  
  
##  <a name="findextension"></a>CPathT::FindExtension  
 Chame esse método para localizar a posição da extensão do arquivo no caminho.  
  
```
int FindExtension() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a posição do "." precede a extensão. Se não for encontrada nenhuma extensão, retornará –&1;.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [PathFindExtension](http://msdn.microsoft.com/library/windows/desktop/bb773587).  
  
##  <a name="findfilename"></a>CPathT::FindFileName  
 Chame esse método para localizar a posição do nome do arquivo no caminho.  
  
```
int FindFileName() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a posição do nome do arquivo. Se nenhum nome de arquivo for encontrado, retorna –&1;.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [PathFindFileName](http://msdn.microsoft.com/library/windows/desktop/bb773589).  
  
##  <a name="getdrivenumber"></a>CPathT::GetDriveNumber  
 Chame esse método para procurar o caminho para uma letra de unidade dentro do intervalo de 'A' a 'Z' e retornar o número de unidade correspondente.  
  
```
int GetDriveNumber() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número de unidade como um inteiro de 0 a 25 (correspondente a 'A' a 'Z') se o caminho tem uma letra de unidade, ou -1, caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [PathGetDriveNumber](http://msdn.microsoft.com/library/windows/desktop/bb773612).  
  
##  <a name="getextension"></a>CPathT::GetExtension  
 Chame esse método para obter a extensão de arquivo do caminho.  
  
```
StringType GetExtension() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a extensão de arquivo.  
  
##  <a name="isdirectory"></a>CPathT::IsDirectory  
 Chame esse método para verificar se o caminho é um diretório válido.  
  
```
BOOL IsDirectory() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um valor diferente de zero (16) se o caminho for um diretório, `FALSE` caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [PathIsDirectory](http://msdn.microsoft.com/library/windows/desktop/bb773621).  
  
##  <a name="isfilespec"></a>CPathT::IsFileSpec  
 Chame esse método para pesquisar um caminho para todos os caracteres de delimitação de caminho (por exemplo, ':' ou '\\'). Se não houver nenhum caractere de delimitação de caminho presente, o caminho é considerado um caminho de especificação de arquivo.  
  
```
BOOL IsFileSpec() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna TRUE se não houver nenhum caractere de delimitação de caminho dentro do caminho, ou falsa se há caracteres de delimitação de caminho.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [PathIsFileSpec](http://msdn.microsoft.com/library/windows/desktop/bb773627).  
  
##  <a name="isprefix"></a>CPathT::IsPrefix  
 Chame esse método para determinar se um caminho contém um prefixo válido de tipo passado `pszPrefix`.  
  
```
BOOL IsPrefix(PCXSTR pszPrefix) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszPrefix`  
 O prefixo que deseja pesquisar. Um prefixo é um destes tipos: "c:\\\\",".","..","... \\\\".  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se o caminho contém o prefixo, ou FALSO caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [PathIsPrefix](http://msdn.microsoft.com/library/windows/desktop/bb773650).  
  
##  <a name="isrelative"></a>CPathT::IsRelative  
 Chame esse método para determinar se o caminho é relativo.  
  
```
BOOL IsRelative() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se o caminho for relativo, ou falso se for absoluta.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [PathIsRelative](http://msdn.microsoft.com/library/windows/desktop/bb773660).  
  
##  <a name="isroot"></a>CPathT::IsRoot  
 Chame esse método para determinar se o caminho é uma diretório raiz.  
  
```
BOOL IsRoot() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se o caminho é uma raiz, ou FALSO caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [PathIsRoot](http://msdn.microsoft.com/library/windows/desktop/bb773674).  
  
##  <a name="issameroot"></a>CPathT::IsSameRoot  
 Chame esse método para determinar se outro caminho tem um componente raiz comuns com o caminho atual.  
  
```
BOOL IsSameRoot(PCXSTR pszOther) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszOther`  
 O caminho.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se ambas as cadeias de caracteres têm o mesmo componente raiz, ou FALSO caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [PathIsSameRoot](http://msdn.microsoft.com/library/windows/desktop/bb773687).  
  
##  <a name="isunc"></a>CPathT::IsUNC  
 Chame esse método para determinar se o caminho é um caminho UNC (convenção de nomenclatura universal) válido para um servidor e compartilhamento.  
  
```
BOOL IsUNC() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se o caminho é um caminho UNC válido, ou FALSO caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [PathIsUNC](http://msdn.microsoft.com/library/windows/desktop/bb773712).  
  
##  <a name="isuncserver"></a>CPathT::IsUNCServer  
 Chame esse método para determinar se o caminho é um caminho UNC (convenção de nomenclatura universal) válido para um servidor.  
  
```
BOOL IsUNCServer() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna TRUE se a cadeia de caracteres for um caminho UNC para um servidor somente (sem nome de compartilhamento) válido, ou FALSO caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [PathIsUNCServer](http://msdn.microsoft.com/library/windows/desktop/bb773722).  
  
##  <a name="isuncservershare"></a>CPathT::IsUNCServerShare  
 Chame esse método para determinar se o caminho é um caminho válido de compartilhamento UNC (convenção de nomenclatura universal), \\ \  *servidor*\ *compartilhar*.  
  
```
BOOL IsUNCServerShare() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se o caminho está no formato \\ \  *servidor*\ *compartilhar*, ou FALSO caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [PathIsUNCServerShare](http://msdn.microsoft.com/library/windows/desktop/bb773723).  
  
##  <a name="m_strpath"></a>CPathT::m_strPath  
 O caminho.  
  
```
StringType m_strPath;
```  
  
### <a name="remarks"></a>Comentários  
 `StringType`é o parâmetro de modelo `CPathT`.  
  
##  <a name="makepretty"></a>CPathT::MakePretty  
 Chame esse método para converter um caminho em todos os caracteres minúsculos para fornecer o caminho de uma aparência consistente.  
  
```
BOOL MakePretty();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Caso contrário, retornará verdadeiro se o caminho tiver sido convertido, ou falso.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [PathMakePretty](http://msdn.microsoft.com/library/windows/desktop/bb773725).  
  
##  <a name="matchspec"></a>CPathT::MatchSpec  
 Chame esse método para pesquisar o caminho para uma cadeia de caracteres que contém um tipo de correspondência de curingas.  
  
```
BOOL MatchSpec(PCXSTR pszSpec) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszSpec`  
 Ponteiro para uma cadeia de caracteres terminada em nulo com o tipo de arquivo que deseja pesquisar. Por exemplo, para testar se o arquivo no caminho atual é um arquivo de documento, `pszSpec` deve ser definido como "*. doc".  
  
### <a name="return-value"></a>Valor de retorno  
 Caso contrário, retornará TRUE se a cadeia de caracteres corresponde ou FALSE.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [PathMatchSpec](http://msdn.microsoft.com/library/windows/desktop/bb773727).  
  
##  <a name="operator_add_eq"></a>+ = CPathT::operator  
 Este operador acrescenta uma cadeia de caracteres para o caminho.  
  
```
CPathT<StringType>& operator+=(PCXSTR pszMore);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszMore`  
 A cadeia de caracteres a ser acrescentada.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o caminho de atualização.  
  
##  <a name="operator_const_stringtype_amp"></a>StringType const CPathT::operator&amp;  
 Este operador permite que o objeto deve ser tratada como uma cadeia de caracteres.  
  
```
 operatorconst StringType&() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna uma cadeia de caracteres que representa o caminho atual gerenciado por esse objeto.  
  
##  <a name="operator_cpatht__pcxstr"></a>CPathT::operator CPathT::PCXSTR  
 Este operador permite que o objeto deve ser tratada como uma cadeia de caracteres.  
  
```
 operatorPCXSTR() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna uma cadeia de caracteres que representa o caminho atual gerenciado por esse objeto.  
  
##  <a name="operator_stringtype__amp"></a>CPathT::operator StringType&amp;  
 Este operador permite que o objeto deve ser tratada como uma cadeia de caracteres.  
  
```
 operatorStringType&() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna uma cadeia de caracteres que representa o caminho atual gerenciado por esse objeto.  
  
##  <a name="pcxstr"></a>CPathT::PCXSTR  
 Um tipo de cadeia de caracteres constante.  
  
```
typedef StringType::PCXSTR PCXSTR;
```  
  
### <a name="remarks"></a>Comentários  
 `StringType`é o parâmetro de modelo `CPathT`.  
  
##  <a name="pxstr"></a>CPathT::PXSTR  
 Um tipo de cadeia de caracteres.  
  
```
typedef StringType::PXSTR PXSTR;
```  
  
### <a name="remarks"></a>Comentários  
 `StringType`é o parâmetro de modelo `CPathT`.  
  
##  <a name="quotespaces"></a>CPathT::QuoteSpaces  
 Chame esse método para colocar o caminho entre aspas se ele contiver espaços.  
  
```
void QuoteSpaces();
```  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [PathQuoteSpaces](http://msdn.microsoft.com/library/windows/desktop/bb773739).  
  
##  <a name="relativepathto"></a>CPathT::RelativePathTo  
 Chame esse método para criar um caminho relativo de um arquivo ou pasta para outra.  
  
```
BOOL RelativePathTo(
    PCXSTR pszFrom,
    DWORD dwAttrFrom,
    PCXSTR pszTo,
    DWORD dwAttrTo);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszFrom`  
 O início do caminho relativo.  
  
 *dwAttrFrom*  
 Os atributos do `pszFrom`. Se esse valor contiver FILE_ATTRIBUTE_DIRECTORY, `pszFrom` é assumido ser um diretório; caso contrário, `pszFrom` é considerado como um arquivo.  
  
 `pszTo`  
 O ponto final do caminho relativo.  
  
 *dwAttrTo*  
 Os atributos do `pszTo`. Se esse valor contiver FILE_ATTRIBUTE_DIRECTORY, `pszTo` é assumido ser um diretório; caso contrário, `pszTo` é considerado como um arquivo.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna verdadeiro em caso de êxito, FALSE em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [PathRelativePathTo](http://msdn.microsoft.com/library/windows/desktop/bb773740).  
  
##  <a name="removeargs"></a>CPathT::RemoveArgs  
 Chame esse método para remover quaisquer argumentos de linha de comando do caminho.  
  
```
void RemoveArgs();
```  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [PathRemoveArgs](http://msdn.microsoft.com/library/windows/desktop/bb773742).  
  
##  <a name="removebackslash"></a>CPathT::RemoveBackslash  
 Chame esse método para remover a barra invertida à direita do caminho.  
  
```
void RemoveBackslash();
```  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [PathRemoveBackslash](http://msdn.microsoft.com/library/windows/desktop/bb773743).  
  
##  <a name="removeblanks"></a>CPathT::RemoveBlanks  
 Chame esse método para remover todos os espaços à esquerda e à direita do caminho.  
  
```
void RemoveBlanks();
```  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [PathRemoveBlanks](http://msdn.microsoft.com/library/windows/desktop/bb773745).  
  
##  <a name="removeextension"></a>CPathT::RemoveExtension  
 Chame esse método para remover a extensão do arquivo do caminho, se houver.  
  
```
void RemoveExtension();
```  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [PathRemoveExtension](http://msdn.microsoft.com/library/windows/desktop/bb773746).  
  
##  <a name="removefilespec"></a>CPathT::RemoveFileSpec  
 Chame esse método para remover o nome de arquivo à direita e a barra invertida do caminho, caso existam.  
  
```
BOOL RemoveFileSpec();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna verdadeiro em caso de êxito, FALSE em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [PathRemoveFileSpec](http://msdn.microsoft.com/library/windows/desktop/bb773748).  
  
##  <a name="renameextension"></a>CPathT::RenameExtension  
 Chame esse método para substituir a extensão de nome de arquivo no caminho com uma nova extensão. Se o nome do arquivo não contém uma extensão, a extensão será anexada ao final do caminho.  
  
```
BOOL RenameExtension(PCXSTR pszExtension);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszExtension`  
 A nova extensão de nome de arquivo, precedido por um "." caracteres.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna verdadeiro em caso de êxito, FALSE em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [PathRenameExtension](http://msdn.microsoft.com/library/windows/desktop/bb773749).  
  
##  <a name="skiproot"></a>CPathT::SkipRoot  
 Chame esse método para analisar um caminho, ignorando a letra da unidade ou partes do caminho de compartilhamento do servidor UNC (convenção de nomenclatura universal).  
  
```
int SkipRoot() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a posição de início de subcaminho que segue a raiz (letra da unidade ou servidor/compartilhamento UNC).  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [PathSkipRoot](http://msdn.microsoft.com/library/windows/desktop/bb773754).  
  
##  <a name="strippath"></a>CPathT::StripPath  
 Chame esse método para remover a parte do caminho de um caminho totalmente qualificado e o nome do arquivo.  
  
```
void StripPath();
```  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [PathStripPath](http://msdn.microsoft.com/library/windows/desktop/bb773756).  
  
##  <a name="striptoroot"></a>CPathT::StripToRoot  
 Chame esse método para remover todas as partes do caminho, exceto as informações da raiz.  
  
```
BOOL StripToRoot();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retornará TRUE se uma letra de unidade válido foi encontrado no caminho, ou FALSO caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [PathStripToRoot](http://msdn.microsoft.com/library/windows/desktop/bb773757).  
  
##  <a name="unquotespaces"></a>CPathT::UnquoteSpaces  
 Chame esse método para remover as aspas no início e no final de um caminho.  
  
```
void UnquoteSpaces();
```  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [PathUnquoteSpaces](http://msdn.microsoft.com/library/windows/desktop/bb773763).  
  
##  <a name="xchar"></a>CPathT::XCHAR  
 Um tipo de caractere.  
  
```
typedef StringType::XCHAR XCHAR;
```  
  
### <a name="remarks"></a>Comentários  
 `StringType`é o parâmetro de modelo `CPathT`.  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../atl/reference/atl-classes.md)   
 [Classe CStringT](../../atl-mfc-shared/reference/cstringt-class.md)
