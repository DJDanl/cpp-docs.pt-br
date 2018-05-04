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
ms.openlocfilehash: 9b802d8764dda321e2e313f793f4f2e4745dbcc7
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="atl-utilities-reference"></a>Referência de utilitários ATL
ATL fornece código para manipular as URLs e caminhos na forma de [CPathT](../atl/reference/cpatht-class.md) e [CUrl](../atl/reference/curl-class.md). Um pool de threads, [CThreadPool](../atl/reference/cthreadpool-class.md), podem ser usados em seus aplicativos. Esse código pode ser encontrado em atlpath.h e atlutil.h.  
  
### <a name="classes"></a>Classes  
  
|||  
|-|-|  
|[Classe CPathT](../atl/reference/cpatht-class.md)|Essa classe representa um caminho.|  
|[Classe CDebugReportHook](../atl/reference/cdebugreporthook-class.md)|Use esta classe para enviar relatórios de depuração para um pipe nomeado.|  
|[Classe CNonStatelessWorker](../atl/reference/cnonstatelessworker-class.md)|Recebe solicitações de um pool de threads e as transmite para um objeto de trabalho que é criado e destruído em cada solicitação.|  
|[Classe CNoWorkerThread](../atl/reference/cnoworkerthread-class.md)|Use essa classe como o argumento para o `MonitorClass` parâmetro de modelo para classes de cache, se você deseja desabilitar a manutenção de cache dinâmico.|  
|[Classe CThreadPool](../atl/reference/cthreadpool-class.md)|Essa classe fornece um pool de threads de trabalho que processam uma fila de itens de trabalho.|  
|[Classe CUrl](../atl/reference/curl-class.md)|Essa classe representa uma URL. Ele permite que você manipule cada elemento da URL, independentemente de outras pessoas se uma URL existente de análise de cadeia de caracteres ou criando uma cadeia de caracteres a partir do zero.|  
|[Classe CWorkerThread](../atl/reference/cworkerthread-class.md)|Essa classe cria um thread de trabalho ou usa um existente, espera um ou mais identificadores de objeto kernel e executa uma função de cliente especificado quando uma das alças é sinalizada.|  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[CPath](../atl/reference/atl-typedefs.md#cpath)|Uma especialização de [CPathT](../atl/reference/cpatht-class.md) usando `CString`.|  
|[CPathA](../atl/reference/atl-typedefs.md#cpatha)|Uma especialização de [CPathT](../atl/reference/cpatht-class.md) usando `CStringA`.|  
|[CPathW](../atl/reference/atl-typedefs.md#cpathw)|Uma especialização de [CPathT](../atl/reference/cpatht-class.md) usando `CStringW`.|  
|[ATL_URL_PORT](../atl/reference/atl-typedefs.md#atl_url_port)|O tipo usado pelo [CUrl](../atl/reference/curl-class.md) para especificar um número de porta.|  
  
### <a name="enums"></a>Enums  
  
|||  
|-|-|  
|[ATL_URL_SCHEME](../atl/reference/atl-url-scheme-enum.md)|Os membros dessa enumeração fornecem constantes para os esquemas entendidos pelo [CUrl](../atl/reference/curl-class.md).|  
  
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

|[ATLPath::AddBackslash](../atl/reference/atl-path-functions.md#addbackslash)| Essa função é um wrapper sobrecarregado para [PathAddBackslash](http://msdn.microsoft.com/library/windows/desktop/bb773561). |  
|[ATLPath::AddExtension](../atl/reference/atl-path-functions.md#addextension)| Essa função é um wrapper sobrecarregado para [PathAddExtension](http://msdn.microsoft.com/library/windows/desktop/bb773563). |  
|[ATLPath::Append](../atl/reference/atl-path-functions.md#append)| Essa função é um wrapper sobrecarregado para [PathAppend](http://msdn.microsoft.com/library/windows/desktop/bb773565). |  
|[ATLPath::BuildRoot](../atl/reference/atl-path-functions.md#buildroot)| Essa função é um wrapper sobrecarregado para [PathBuildRoot](http://msdn.microsoft.com/library/windows/desktop/bb773567). |  
|[ATLPath::Canonicalize](../atl/reference/atl-path-functions.md#canonicalize)| Essa função é um wrapper sobrecarregado para [PathCanonicalize](http://msdn.microsoft.com/library/windows/desktop/bb773569). |  
|[ATLPath::Combine](../atl/reference/atl-path-functions.md#combine)| Essa função é um wrapper sobrecarregado para [PathCombine](http://msdn.microsoft.com/library/windows/desktop/bb773571). |  
|[ATLPath::CommonPrefix](../atl/reference/atl-path-functions.md#commonprefix)| Essa função é um wrapper sobrecarregado para [PathCommonPrefix](http://msdn.microsoft.com/library/windows/desktop/bb773574). |  
|[ATLPath::CompactPath](../atl/reference/atl-path-functions.md#compactpath)| Essa função é um wrapper sobrecarregado para [PathCompactPath](http://msdn.microsoft.com/library/windows/desktop/bb773575). |  
|[ATLPath::CompactPathEx](../atl/reference/atl-path-functions.md#compactpathex)| Essa função é um wrapper sobrecarregado para [PathCompactPathEx](http://msdn.microsoft.com/library/windows/desktop/bb773578). |  
|[ATLPath::FileExists](../atl/reference/atl-path-functions.md#fileexists)| Essa função é um wrapper sobrecarregado para [PathFileExists](http://msdn.microsoft.com/library/windows/desktop/bb773584). |  
|[ATLPath::FindExtension](../atl/reference/atl-path-functions.md#findextension)| Essa função é um wrapper sobrecarregado para [PathFindExtension](http://msdn.microsoft.com/library/windows/desktop/bb773587). |  
|[ATLPath::FindFileName](../atl/reference/atl-path-functions.md#findfilename)| Essa função é um wrapper sobrecarregado para [PathFindFileName](http://msdn.microsoft.com/library/windows/desktop/bb773589). |  
|[ATLPath::GetDriveNumber](../atl/reference/atl-path-functions.md#getdrivenumber)| Essa função é um wrapper sobrecarregado para [PathGetDriveNumber](http://msdn.microsoft.com/library/windows/desktop/bb773612). |  
|[ATLPath::IsDirectory](../atl/reference/atl-path-functions.md#isdirectory)| Essa função é um wrapper sobrecarregado para [PathIsDirectory](http://msdn.microsoft.com/library/windows/desktop/bb773621). |  
|[ATLPath::IsFileSpec](../atl/reference/atl-path-functions.md#isfilespec)| Essa função é um wrapper sobrecarregado para [PathIsFileSpec](http://msdn.microsoft.com/library/windows/desktop/bb773627). |  
|[ATLPath::IsPrefix](../atl/reference/atl-path-functions.md#isprefix)| Essa função é um wrapper sobrecarregado para [PathIsPrefix](http://msdn.microsoft.com/library/windows/desktop/bb773650). |  
|[ATLPath::IsRelative](../atl/reference/atl-path-functions.md#isrelative)| Essa função é um wrapper sobrecarregado para [PathIsRelative](http://msdn.microsoft.com/library/windows/desktop/bb773660). |  
|[ATLPath::IsRoot](../atl/reference/atl-path-functions.md#isroot)| Essa função é um wrapper sobrecarregado para [PathIsRoot](http://msdn.microsoft.com/library/windows/desktop/bb773674). |  
|[ATLPath::IsSameRoot](../atl/reference/atl-path-functions.md#issameroot)| Essa função é um wrapper sobrecarregado para [PathIsSameRoot](http://msdn.microsoft.com/library/windows/desktop/bb773687). |  
|[ATLPath::IsUNC](../atl/reference/atl-path-functions.md#isunc)| Essa função é um wrapper sobrecarregado para [PathIsUNC](http://msdn.microsoft.com/library/windows/desktop/bb773712). |  
|[ATLPath::IsUNCServer](../atl/reference/atl-path-functions.md#isuncserver)| Essa função é um wrapper sobrecarregado para [PathIsUNCServer](http://msdn.microsoft.com/library/windows/desktop/bb773722). |  
|[ATLPath::IsUNCServerShare](../atl/reference/atl-path-functions.md#isuncservershare)| Essa função é um wrapper sobrecarregado para [PathIsUNCServerShare](http://msdn.microsoft.com/library/windows/desktop/bb773723). |  
|[ATLPath::MakePretty](../atl/reference/atl-path-functions.md#makepretty)| Essa função é um wrapper sobrecarregado para [PathMakePretty](http://msdn.microsoft.com/library/windows/desktop/bb773725). |  
|[ATLPath::MatchSpec](../atl/reference/atl-path-functions.md#matchspec)| Essa função é um wrapper sobrecarregado para [PathMatchSpec](http://msdn.microsoft.com/library/windows/desktop/bb773727). |  
|[ATLPath::QuoteSpaces](../atl/reference/atl-path-functions.md#quotespaces)| Essa função é um wrapper sobrecarregado para [PathQuoteSpaces](http://msdn.microsoft.com/library/windows/desktop/bb773739). |  
|[ATLPath::RelativePathTo](../atl/reference/atl-path-functions.md#relativepathto)| Essa função é um wrapper sobrecarregado para [PathRelativePathTo](http://msdn.microsoft.com/library/windows/desktop/bb773740). |  
|[ATLPath::RemoveArgs](../atl/reference/atl-path-functions.md#removeargs)| Essa função é um wrapper sobrecarregado para [PathRemoveArgs](http://msdn.microsoft.com/library/windows/desktop/bb773742). |  
|[ATLPath::RemoveBackslash](../atl/reference/atl-path-functions.md#removebackslash)| Essa função é um wrapper sobrecarregado para [PathRemoveBackslash](http://msdn.microsoft.com/library/windows/desktop/bb773743). |  
|[ATLPath::RemoveBlanks](../atl/reference/atl-path-functions.md#removeblanks)| Essa função é um wrapper sobrecarregado para [PathRemoveBlanks](http://msdn.microsoft.com/library/windows/desktop/bb773745). |  
|[ATLPath::RemoveExtension](../atl/reference/atl-path-functions.md#removeextension)| Essa função é um wrapper sobrecarregado para [PathRemoveExtension](http://msdn.microsoft.com/library/windows/desktop/bb773746). |  
|[ATLPath::RemoveFileSpec](../atl/reference/atl-path-functions.md#removefilespec)| Essa função é um wrapper sobrecarregado para [PathRemoveFileSpec](http://msdn.microsoft.com/library/windows/desktop/bb773748). |  
|[ATLPath::RenameExtension](../atl/reference/atl-path-functions.md#renameextension)| Essa função é um wrapper sobrecarregado para [PathRenameExtension](http://msdn.microsoft.com/library/windows/desktop/bb773749). |  
|[ATLPath::SkipRoot](../atl/reference/atl-path-functions.md#skiproot)| Essa função é um wrapper sobrecarregado para [PathSkipRoot](http://msdn.microsoft.com/library/windows/desktop/bb773754). |  
|[ATLPath::StripPath](../atl/reference/atl-path-functions.md#strippath)| Essa função é um wrapper sobrecarregado para [PathStripPath](http://msdn.microsoft.com/library/windows/desktop/bb773756). |  
|[ATLPath::StripToRoot](../atl/reference/atl-path-functions.md#striptoroot)| Essa função é um wrapper sobrecarregado para [PathStripToRoot](http://msdn.microsoft.com/library/windows/desktop/bb773757). |  
|[ATLPath::UnquoteSpaces](../atl/reference/atl-path-functions.md#unquotespaces)| Essa função é um wrapper sobrecarregado para [PathUnquoteSpaces](http://msdn.microsoft.com/library/windows/desktop/bb773763). |  
  

## <a name="see-also"></a>Consulte também  
 [Conceitos](../atl/active-template-library-atl-concepts.md)   
 [Componentes de área de trabalho COM da ATL](../atl/atl-com-desktop-components.md)
