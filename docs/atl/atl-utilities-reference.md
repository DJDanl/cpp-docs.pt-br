---
title: Referência de utilitários ATL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: dd8a2888-34f4-461e-9bf4-834218f9b95b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: eadb1edc174d07fbc6e9ef1bfb24b436bd76033d
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46056138"
---
# <a name="atl-utilities-reference"></a>Referência de utilitários ATL

ATL fornece código para manipular URLs e caminhos na forma de [CPathT](../atl/reference/cpatht-class.md) e [CUrl](../atl/reference/curl-class.md). Um pool de threads [CThreadPool](../atl/reference/cthreadpool-class.md), pode ser usado em seus aplicativos. Esse código pode ser encontrado em atlpath e atlutil.

### <a name="classes"></a>Classes

|||
|-|-|
|[Classe CPathT](../atl/reference/cpatht-class.md)|Essa classe representa um caminho.|
|[Classe CDebugReportHook](../atl/reference/cdebugreporthook-class.md)|Use essa classe para enviar relatórios de depuração para um pipe nomeado.|
|[Classe CNonStatelessWorker](../atl/reference/cnonstatelessworker-class.md)|Recebe solicitações de um pool de threads e as transmite para um objeto de trabalho que é criado e destruído em cada solicitação.|
|[Classe CNoWorkerThread](../atl/reference/cnoworkerthread-class.md)|Use essa classe como o argumento para o `MonitorClass` parâmetro de modelo para classes de cache se você quiser desabilitar a manutenção de cache dinâmico.|
|[Classe CThreadPool](../atl/reference/cthreadpool-class.md)|Essa classe fornece um pool de threads de trabalho que processam uma fila de itens de trabalho.|
|[Classe CUrl](../atl/reference/curl-class.md)|Essa classe representa uma URL. Ele permite que você manipule a cada elemento da URL, independentemente dos outros se uma URL existente de análise de cadeia de caracteres ou criação de uma cadeia de caracteres a partir do zero.|
|[Classe CWorkerThread](../atl/reference/cworkerthread-class.md)|Essa classe cria um thread de trabalho ou usa um existente, espera por um ou mais identificadores de objeto de kernel e executa uma função de cliente especificado quando uma das alças é sinalizada.|

### <a name="typedefs"></a>Typedefs

|||
|-|-|
|[CPath](../atl/reference/atl-typedefs.md#cpath)|Uma especialização da [CPathT](../atl/reference/cpatht-class.md) usando `CString`.|
|[CPathA](../atl/reference/atl-typedefs.md#cpatha)|Uma especialização da [CPathT](../atl/reference/cpatht-class.md) usando `CStringA`.|
|[CPathW](../atl/reference/atl-typedefs.md#cpathw)|Uma especialização da [CPathT](../atl/reference/cpatht-class.md) usando `CStringW`.|
|[ATL_URL_PORT](../atl/reference/atl-typedefs.md#atl_url_port)|O tipo usado pelo [CUrl](../atl/reference/curl-class.md) para especificar um número de porta.|

### <a name="enums"></a>Enums

|||
|-|-|
|[ATL_URL_SCHEME](../atl/reference/atl-url-scheme-enum.md)|Os membros dessa enumeração fornecem constantes para os esquemas compreendidos pelo [CUrl](../atl/reference/curl-class.md).|

### <a name="functions"></a>Funções

|||
|-|-|
|[AtlCanonicalizeUrl](../atl/reference/atl-http-utility-functions.md#atlcanonicalizeurl)|Chame essa função para canonizar uma URL, o que inclui converter caracteres e espaços não seguros em sequências de escape.|
|[AtlCombineUrl](../atl/reference/atl-http-utility-functions.md#atlcombineurl)|Chame essa função para combinar uma URL de base e uma URL relativa em uma única URL canônica.|
|[AtlEscapeUrl](../atl/reference/atl-http-utility-functions.md#atlescapeurl)|Chame essa função para converter todos os caracteres não seguros em sequências de escape.|
|[AtlGetDefaultUrlPort](../atl/reference/atl-http-utility-functions.md#atlgetdefaulturlport)|Chame essa função para obter o número da porta padrão associado a um determinado protocolo de internet ou o esquema.|
|[AtlHexValue](../atl/reference/atl-text-encoding-functions.md#atlhexvalue)|Chame essa função para obter o valor numérico de um dígito hexadecimal.|
|[AtlIsUnsafeUrlChar](../atl/reference/atl-http-utility-functions.md#atlisunsafeurlchar)|Chame essa função para descobrir se um caractere é seguro para uso em uma URL.|
|[AtlUnescapeUrl](../atl/reference/atl-http-utility-functions.md#atlunescapeurl)|Chame essa função para converter caracteres de escape de volta aos valores originais.|
|[SystemTimeToHttpDate](../atl/reference/atl-http-utility-functions.md#systemtimetohttpdate)|Chame essa função para converter uma hora do sistema em uma cadeia de caracteres em um formato adequado para uso em cabeçalhos HTTP.|  

|[ATLPath::AddBackslash](../atl/reference/atl-path-functions.md#addbackslash)| Essa função é um wrapper sobrecarregado para [PathAddBackslash](/windows/desktop/api/shlwapi/nf-shlwapi-pathaddbackslasha
). | |[ ATLPath::AddExtension](../atl/reference/atl-path-functions.md#addextension)| Essa função é um wrapper sobrecarregado para [PathAddExtension](/windows/desktop/api/shlwapi/nf-shlwapi-pathaddextensiona). | |[ ATLPath::Append](../atl/reference/atl-path-functions.md#append)| Essa função é um wrapper sobrecarregado para [PathAppend](/windows/desktop/api/shlwapi/nf-shlwapi-pathappenda). | |[ ATLPath::BuildRoot](../atl/reference/atl-path-functions.md#buildroot)| Essa função é um wrapper sobrecarregado para [PathBuildRoot](/windows/desktop/api/shlwapi/nf-shlwapi-pathbuildroota). | |[ ATLPath::Canonicalize](../atl/reference/atl-path-functions.md#canonicalize)| Essa função é um wrapper sobrecarregado para [PathCanonicalize](/windows/desktop/api/shlwapi/nf-shlwapi-pathcanonicalizea). | |[ ATLPath::Combine](../atl/reference/atl-path-functions.md#combine)| Essa função é um wrapper sobrecarregado para [PathCombine](/windows/desktop/api/shlwapi/nf-shlwapi-pathcombinea). | |[ ATLPath::CommonPrefix](../atl/reference/atl-path-functions.md#commonprefix)| Essa função é um wrapper sobrecarregado para [PathCommonPrefix](/windows/desktop/api/shlwapi/nf-shlwapi-pathcommonprefixa). | |[ ATLPath::CompactPath](../atl/reference/atl-path-functions.md#compactpath)| Essa função é um wrapper sobrecarregado para [PathCompactPath](/windows/desktop/api/shlwapi/nf-shlwapi-pathcompactpatha). | |[ ATLPath::CompactPathEx](../atl/reference/atl-path-functions.md#compactpathex)| Essa função é um wrapper sobrecarregado para [PathCompactPathEx](/windows/desktop/api/shlwapi/nf-shlwapi-pathcompactpathexa). | |[ ATLPath::FileExists](../atl/reference/atl-path-functions.md#fileexists)| Essa função é um wrapper sobrecarregado para [PathFileExists](/windows/desktop/api/shlwapi/nf-shlwapi-pathfileexistsa). | |[ ATLPath::FindExtension](../atl/reference/atl-path-functions.md#findextension)| Essa função é um wrapper sobrecarregado para [PathFindExtension](/windows/desktop/api/shlwapi/nf-shlwapi-pathfindextensiona). | |[ ATLPath::FindFileName](../atl/reference/atl-path-functions.md#findfilename)| Essa função é um wrapper sobrecarregado para [PathFindFileName](/windows/desktop/api/shlwapi/nf-shlwapi-pathfindfilenamea). | |[ ATLPath::GetDriveNumber](../atl/reference/atl-path-functions.md#getdrivenumber)| Essa função é um wrapper sobrecarregado para [PathGetDriveNumber](/windows/desktop/api/shlwapi/nf-shlwapi-pathgetdrivenumbera). | |[ ATLPath::IsDirectory](../atl/reference/atl-path-functions.md#isdirectory)| Essa função é um wrapper sobrecarregado para [PathIsDirectory](/windows/desktop/api/shlwapi/nf-shlwapi-pathisdirectorya). | |[ ATLPath::IsFileSpec](../atl/reference/atl-path-functions.md#isfilespec)| Essa função é um wrapper sobrecarregado para [PathIsFileSpec](/windows/desktop/api/shlwapi/nf-shlwapi-pathisfilespeca). | |[ ATLPath::IsPrefix](../atl/reference/atl-path-functions.md#isprefix)| Essa função é um wrapper sobrecarregado para [PathIsPrefix](/windows/desktop/api/shlwapi/nf-shlwapi-pathisprefixa). | |[ ATLPath::IsRelative](../atl/reference/atl-path-functions.md#isrelative)| Essa função é um wrapper sobrecarregado para [PathIsRelative](/windows/desktop/api/shlwapi/nf-shlwapi-pathisrelativea). | |[ ATLPath::IsRoot](../atl/reference/atl-path-functions.md#isroot)| Essa função é um wrapper sobrecarregado para [PathIsRoot](/windows/desktop/api/shlwapi/nf-shlwapi-pathisroota). | |[ ATLPath::IsSameRoot](../atl/reference/atl-path-functions.md#issameroot)| Essa função é um wrapper sobrecarregado para [PathIsSameRoot](/windows/desktop/api/shlwapi/nf-shlwapi-pathissameroota). | |[ ATLPath::IsUNC](../atl/reference/atl-path-functions.md#isunc)| Essa função é um wrapper sobrecarregado para [PathIsUNC](/windows/desktop/api/shlwapi/nf-shlwapi-pathisunca). | |[ ATLPath::IsUNCServer](../atl/reference/atl-path-functions.md#isuncserver)| Essa função é um wrapper sobrecarregado para [PathIsUNCServer](/windows/desktop/api/shlwapi/nf-shlwapi-pathisuncservera). | |[ ATLPath::IsUNCServerShare](../atl/reference/atl-path-functions.md#isuncservershare)| Essa função é um wrapper sobrecarregado para [PathIsUNCServerShare](/windows/desktop/api/shlwapi/nf-shlwapi-pathisuncserversharea).| |[ATLPath::MakePretty](../atl/reference/atl-path-functions.md#makepretty)|This function is an overloaded wrapper for [PathMakePretty](/windows/desktop/api/shlwapi/nf-shlwapi-pathmakeprettya).| |[ATLPath::MatchSpec](../atl/reference/atl-path-functions.md#matchspec)|This function is an overloaded wrapper for [PathMatchSpec](/windows/desktop/api/shlwapi/nf-shlwapi-pathmatchspeca).| |[ATLPath::QuoteSpaces](../atl/reference/atl-path-functions.md#quotespaces)|This function is an overloaded wrapper for [PathQuoteSpaces](/windows/desktop/api/shlwapi/nf-shlwapi-pathquotespacesa).| |[ATLPath::RelativePathTo](../atl/reference/atl-path-functions.md#relativepathto)|This function is an overloaded wrapper for [PathRelativePathTo](/windows/desktop/api/shlwapi/nf-shlwapi-pathrelativepathtoa).| |[ATLPath::RemoveArgs](../atl/reference/atl-path-functions.md#removeargs)|This function is an overloaded wrapper for [PathRemoveArgs](/windows/desktop/api/shlwapi/nf-shlwapi-pathremoveargsa).| |[ATLPath::RemoveBackslash](../atl/reference/atl-path-functions.md#removebackslash)|This function is an overloaded wrapper for [PathRemoveBackslash](/windows/desktop/api/shlwapi/nf-shlwapi-pathremovebackslasha).| |[ATLPath::RemoveBlanks](../atl/reference/atl-path-functions.md#removeblanks)|This function is an overloaded wrapper for [PathRemoveBlanks](/windows/desktop/api/shlwapi/nf-shlwapi-pathremoveblanksa).| |[ATLPath::RemoveExtension](../atl/reference/atl-path-functions.md#removeextension)|This function is an overloaded wrapper for [PathRemoveExtension](/windows/desktop/api/shlwapi/nf-shlwapi-pathremoveextensiona).| |[ATLPath::RemoveFileSpec](../atl/reference/atl-path-functions.md#removefilespec)|This function is an overloaded wrapper for [PathRemoveFileSpec](/windows/desktop/api/shlwapi/nf-shlwapi-pathremovefilespeca).| |[ATLPath::RenameExtension](../atl/reference/atl-path-functions.md#renameextension)|This function is an overloaded wrapper for [PathRenameExtension](/windows/desktop/api/shlwapi/nf-shlwapi-pathrenameextensiona).| |[ATLPath::SkipRoot](../atl/reference/atl-path-functions.md#skiproot)|This function is an overloaded wrapper for [PathSkipRoot](/windows/desktop/api/shlwapi/nf-shlwapi-pathskiproota).| |[ATLPath::StripPath](../atl/reference/atl-path-functions.md#strippath)|This function is an overloaded wrapper for [PathStripPath](/windows/desktop/api/shlwapi/nf-shlwapi-pathstrippatha).| |[ATLPath::StripToRoot](../atl/reference/atl-path-functions.md#striptoroot)|This function is an overloaded wrapper for [PathStripToRoot](/windows/desktop/api/shlwapi/nf-shlwapi-pathstriptoroota).| |[ATLPath::UnquoteSpaces](../atl/reference/atl-path-functions.md#unquotespaces)|This function is an overloaded wrapper for [PathUnquoteSpaces](/windows/desktop/api/shlwapi/nf-shlwapi-pathunquotespacesa).|

## <a name="see-also"></a>Consulte também

[Conceitos](../atl/active-template-library-atl-concepts.md)<br/>
[Componentes de área de trabalho COM da ATL](../atl/atl-com-desktop-components.md)
