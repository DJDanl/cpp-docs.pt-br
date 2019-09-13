---
title: Referência de utilitários ATL
ms.date: 11/04/2016
ms.assetid: dd8a2888-34f4-461e-9bf4-834218f9b95b
ms.openlocfilehash: 6c1481929f832e6f810ce46773f328f278b503fa
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69491708"
---
# <a name="atl-utilities-reference"></a>Referência de utilitários ATL

A ATL fornece código para manipular caminhos e URLs na forma de [CPathT](../atl/reference/cpatht-class.md) e [ondulação](../atl/reference/curl-class.md). Um pool de threads, [CThreadPool](../atl/reference/cthreadpool-class.md), pode ser usado em seus aplicativos. Esse código pode ser encontrado em atlpath.h e atlutil.h.

### <a name="classes"></a>Classes

|||
|-|-|
|[Classe CPathT](../atl/reference/cpatht-class.md)|Essa classe representa um caminho.|
|[Classe CDebugReportHook](../atl/reference/cdebugreporthook-class.md)|Use esta classe para enviar relatórios de depuração a um pipe nomeado.|
|[Classe CNonStatelessWorker](../atl/reference/cnonstatelessworker-class.md)|Recebe solicitações de um pool de threads e as passa para um objeto de trabalho que é criado e destruído em cada solicitação.|
|[Classe CNoWorkerThread](../atl/reference/cnoworkerthread-class.md)|Use essa classe como o argumento para o `MonitorClass` parâmetro de modelo para armazenar classes em cache se você quiser desabilitar a manutenção do cache dinâmico.|
|[Classe CThreadPool](../atl/reference/cthreadpool-class.md)|Essa classe fornece um pool de threads de trabalho que processam uma fila de itens de trabalho.|
|[Classe CUrl](../atl/reference/curl-class.md)|Essa classe representa uma URL. Ele permite que você manipule cada elemento da URL independentemente dos outros, se estiver analisando uma cadeia de caracteres de URL existente ou criando uma cadeia de caracteres a partir do zero.|
|[Classe CWorkerThread](../atl/reference/cworkerthread-class.md)|Essa classe cria um thread de trabalho ou usa um existente, aguarda em um ou mais identificadores de objeto de kernel e executa uma função de cliente especificada quando um dos identificadores é sinalizado.|

### <a name="typedefs"></a>Typedefs

|||
|-|-|
|[CPath](../atl/reference/atl-typedefs.md#cpath)|Uma especialização de [CPathT](../atl/reference/cpatht-class.md) usando `CString`.|
|[CPathA](../atl/reference/atl-typedefs.md#cpatha)|Uma especialização de [CPathT](../atl/reference/cpatht-class.md) usando `CStringA`.|
|[CPathW](../atl/reference/atl-typedefs.md#cpathw)|Uma especialização de [CPathT](../atl/reference/cpatht-class.md) usando `CStringW`.|
|[ATL_URL_PORT](../atl/reference/atl-typedefs.md#atl_url_port)|O tipo usado por [ondulação](../atl/reference/curl-class.md) para especificar um número de porta.|

### <a name="enums"></a>Enums

|||
|-|-|
|[ATL_URL_SCHEME](../atl/reference/atl-url-scheme-enum.md)|Os membros dessa enumeração fornecem constantes para os esquemas compreendidos pela [rotação](../atl/reference/curl-class.md).|

### <a name="functions"></a>Funções

|||
|-|-|
|[AtlCanonicalizeUrl](../atl/reference/atl-http-utility-functions.md#atlcanonicalizeurl)|Chame essa função para canonizar uma URL, o que inclui converter caracteres e espaços não seguros em sequências de escape.|
|[AtlCombineUrl](../atl/reference/atl-http-utility-functions.md#atlcombineurl)|Chame essa função para combinar uma URL de base e uma URL relativa em uma única URL canônica.|
|[AtlEscapeUrl](../atl/reference/atl-http-utility-functions.md#atlescapeurl)|Chame essa função para converter todos os caracteres não seguros em sequências de escape.|
|[AtlGetDefaultUrlPort](../atl/reference/atl-http-utility-functions.md#atlgetdefaulturlport)|Chame essa função para obter o número da porta padrão associado a um esquema ou protocolo de Internet específico.|
|[AtlHexValue](../atl/reference/atl-text-encoding-functions.md#atlhexvalue)|Chame essa função para obter o valor numérico de um dígito hexadecimal.|
|[AtlIsUnsafeUrlChar](../atl/reference/atl-http-utility-functions.md#atlisunsafeurlchar)|Chame essa função para descobrir se um caractere é seguro para uso em uma URL.|
|[AtlUnescapeUrl](../atl/reference/atl-http-utility-functions.md#atlunescapeurl)|Chame essa função para converter caracteres de escape de volta aos valores originais.|
|[SystemTimeToHttpDate](../atl/reference/atl-http-utility-functions.md#systemtimetohttpdate)|Chame essa função para converter uma hora do sistema em uma cadeia de caracteres em um formato adequado para uso em cabeçalhos HTTP.|

|[ATLPath::AddBackslash](../atl/reference/atl-path-functions.md#addbackslash)| Essa função é um wrapper sobrecarregado para [PathAddBackslash](/windows/desktop/api/shlwapi/nf-shlwapi-pathaddbackslasha
). | |[ ATLPath::AddExtension](../atl/reference/atl-path-functions.md#addextension)| Essa função é um wrapper sobrecarregado para [PathAddExtension](/windows/win32/api/shlwapi/nf-shlwapi-pathaddextensionw). | |[ ATLPath::Append](../atl/reference/atl-path-functions.md#append)| Essa função é um wrapper sobrecarregado para [PathAppend](/windows/win32/api/shlwapi/nf-shlwapi-pathappendw). | |[ ATLPath::BuildRoot](../atl/reference/atl-path-functions.md#buildroot)| Essa função é um wrapper sobrecarregado para [PathBuildRoot](/windows/win32/api/shlwapi/nf-shlwapi-pathbuildrootw). | |[ ATLPath::Canonicalize](../atl/reference/atl-path-functions.md#canonicalize)| Essa função é um wrapper sobrecarregado para [PathCanonicalize](/windows/win32/api/shlwapi/nf-shlwapi-pathcanonicalizew). | |[ ATLPath::Combine](../atl/reference/atl-path-functions.md#combine)| Essa função é um wrapper sobrecarregado para [PathCombine](/windows/win32/api/shlwapi/nf-shlwapi-pathcombinew). | |[ ATLPath::CommonPrefix](../atl/reference/atl-path-functions.md#commonprefix)| Essa função é um wrapper sobrecarregado para [PathCommonPrefix](/windows/win32/api/shlwapi/nf-shlwapi-pathcommonprefixw). | |[ ATLPath::CompactPath](../atl/reference/atl-path-functions.md#compactpath)| Essa função é um wrapper sobrecarregado para [PathCompactPath](/windows/win32/api/shlwapi/nf-shlwapi-pathcompactpathw). | |[ ATLPath::CompactPathEx](../atl/reference/atl-path-functions.md#compactpathex)| Essa função é um wrapper sobrecarregado para [PathCompactPathEx](/windows/win32/api/shlwapi/nf-shlwapi-pathcompactpathexw). | |[ ATLPath::FileExists](../atl/reference/atl-path-functions.md#fileexists)| Essa função é um wrapper sobrecarregado para [PathFileExists](/windows/win32/api/shlwapi/nf-shlwapi-pathfileexistsw). | |[ ATLPath::FindExtension](../atl/reference/atl-path-functions.md#findextension)| Essa função é um wrapper sobrecarregado para [PathFindExtension](/windows/win32/api/shlwapi/nf-shlwapi-pathfindextensionw). | |[ ATLPath::FindFileName](../atl/reference/atl-path-functions.md#findfilename)| Essa função é um wrapper sobrecarregado para [PathFindFileName](/windows/win32/api/shlwapi/nf-shlwapi-pathfindfilenamew). | |[ ATLPath::GetDriveNumber](../atl/reference/atl-path-functions.md#getdrivenumber)| Essa função é um wrapper sobrecarregado para [PathGetDriveNumber](/windows/win32/api/shlwapi/nf-shlwapi-pathgetdrivenumberw). | |[ ATLPath::IsDirectory](../atl/reference/atl-path-functions.md#isdirectory)| Essa função é um wrapper sobrecarregado para [PathIsDirectory](/windows/win32/api/shlwapi/nf-shlwapi-pathisdirectoryw). | |[ ATLPath::IsFileSpec](../atl/reference/atl-path-functions.md#isfilespec)| Essa função é um wrapper sobrecarregado para [PathIsFileSpec](/windows/win32/api/shlwapi/nf-shlwapi-pathisfilespecw). | |[ ATLPath::IsPrefix](../atl/reference/atl-path-functions.md#isprefix)| Essa função é um wrapper sobrecarregado para [PathIsPrefix](/windows/win32/api/shlwapi/nf-shlwapi-pathisprefixw). | |[ ATLPath::IsRelative](../atl/reference/atl-path-functions.md#isrelative)| Essa função é um wrapper sobrecarregado para [PathIsRelative](/windows/win32/api/shlwapi/nf-shlwapi-pathisrelativew). | |[ ATLPath::IsRoot](../atl/reference/atl-path-functions.md#isroot)| Essa função é um wrapper sobrecarregado para [PathIsRoot](/windows/win32/api/shlwapi/nf-shlwapi-pathisrootw). | |[ ATLPath::IsSameRoot](../atl/reference/atl-path-functions.md#issameroot)| Essa função é um wrapper sobrecarregado para [PathIsSameRoot](/windows/win32/api/shlwapi/nf-shlwapi-pathissamerootw). | |[ ATLPath::IsUNC](../atl/reference/atl-path-functions.md#isunc)| Essa função é um wrapper sobrecarregado para [PathIsUNC](/windows/win32/api/shlwapi/nf-shlwapi-pathisuncw). | |[ ATLPath::IsUNCServer](../atl/reference/atl-path-functions.md#isuncserver)| Essa função é um wrapper sobrecarregado para [PathIsUNCServer](/windows/win32/api/shlwapi/nf-shlwapi-pathisuncserverw). | |[ ATLPath::IsUNCServerShare](../atl/reference/atl-path-functions.md#isuncservershare)| Essa função é um wrapper sobrecarregado para [PathIsUNCServerShare](/windows/win32/api/shlwapi/nf-shlwapi-pathisuncserversharew).| |[ATLPath::MakePretty](../atl/reference/atl-path-functions.md#makepretty)|This function is an overloaded wrapper for [PathMakePretty](/windows/win32/api/shlwapi/nf-shlwapi-pathmakeprettyw).| |[ATLPath::MatchSpec](../atl/reference/atl-path-functions.md#matchspec)|This function is an overloaded wrapper for [PathMatchSpec](/windows/win32/api/shlwapi/nf-shlwapi-pathmatchspecw).| |[ATLPath::QuoteSpaces](../atl/reference/atl-path-functions.md#quotespaces)|This function is an overloaded wrapper for [PathQuoteSpaces](/windows/win32/api/shlwapi/nf-shlwapi-pathquotespacesw).| |[ATLPath::RelativePathTo](../atl/reference/atl-path-functions.md#relativepathto)|This function is an overloaded wrapper for [PathRelativePathTo](/windows/win32/api/shlwapi/nf-shlwapi-pathrelativepathtow).| |[ATLPath::RemoveArgs](../atl/reference/atl-path-functions.md#removeargs)|This function is an overloaded wrapper for [PathRemoveArgs](/windows/win32/api/shlwapi/nf-shlwapi-pathremoveargsw).| |[ATLPath::RemoveBackslash](../atl/reference/atl-path-functions.md#removebackslash)|This function is an overloaded wrapper for [PathRemoveBackslash](/windows/win32/api/shlwapi/nf-shlwapi-pathremovebackslashw).| |[ATLPath::RemoveBlanks](../atl/reference/atl-path-functions.md#removeblanks)|This function is an overloaded wrapper for [PathRemoveBlanks](/windows/win32/api/shlwapi/nf-shlwapi-pathremoveblanksw).| |[ATLPath::RemoveExtension](../atl/reference/atl-path-functions.md#removeextension)|This function is an overloaded wrapper for [PathRemoveExtension](/windows/win32/api/shlwapi/nf-shlwapi-pathremoveextensionw).| |[ATLPath::RemoveFileSpec](../atl/reference/atl-path-functions.md#removefilespec)|This function is an overloaded wrapper for [PathRemoveFileSpec](/windows/win32/api/shlwapi/nf-shlwapi-pathremovefilespecw).| |[ATLPath::RenameExtension](../atl/reference/atl-path-functions.md#renameextension)|This function is an overloaded wrapper for [PathRenameExtension](/windows/win32/api/shlwapi/nf-shlwapi-pathrenameextensionw).| |[ATLPath::SkipRoot](../atl/reference/atl-path-functions.md#skiproot)|This function is an overloaded wrapper for [PathSkipRoot](/windows/win32/api/shlwapi/nf-shlwapi-pathskiprootw).| |[ATLPath::StripPath](../atl/reference/atl-path-functions.md#strippath)|This function is an overloaded wrapper for [PathStripPath](/windows/win32/api/shlwapi/nf-shlwapi-pathstrippathw).| |[ATLPath::StripToRoot](../atl/reference/atl-path-functions.md#striptoroot)|This function is an overloaded wrapper for [PathStripToRoot](/windows/win32/api/shlwapi/nf-shlwapi-pathstriptorootw).| |[ATLPath::UnquoteSpaces](../atl/reference/atl-path-functions.md#unquotespaces)|This function is an overloaded wrapper for [PathUnquoteSpaces](/windows/win32/api/shlwapi/nf-shlwapi-pathunquotespacesw).|

## <a name="see-also"></a>Consulte também

[Conceitos](../atl/active-template-library-atl-concepts.md)<br/>
[Componentes de área de trabalho COM da ATL](../atl/atl-com-desktop-components.md)
