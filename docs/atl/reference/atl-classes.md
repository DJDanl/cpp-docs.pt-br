---
title: Classes ATL | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- classes [C++], ATL
- ATL, classes
ms.assetid: 7da42e2d-ac84-4506-92bd-502a86d68bdc
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: bc8f03660742f0e752bb9ef12043af841797d0ab
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="atl-classes"></a>Classes da ATL
A biblioteca de modelo ativa (ATL) inclui as classes a seguir. Para localizar uma classe específica por categoria, consulte o [visão geral da classe ATL](../../atl/atl-class-overview.md).  
  
|Classe|Descrição|Arquivo de cabeçalho|  
|-----------|-----------------|-----------------|  
|[CA2AEX](../../atl/reference/ca2aex-class.md)|Essa classe é usada pelas macros de conversão de cadeia de caracteres `CA2TEX` e `CT2AEX`e o typedef **CA2A**.|atlconv.h|  
|[CA2CAEX](../../atl/reference/ca2caex-class.md)|Essa classe é usada por macros de conversão de cadeia de caracteres `CA2CTEX` e `CT2CAEX`e o typedef **CA2CA**.|atlconv.h|  
|[CA2WEX](../../atl/reference/ca2wex-class.md)|Essa classe é usada pelas macros de conversão de cadeia de caracteres `CA2TEX`, `CA2CTEX`, `CT2WEX`, e `CT2CWEX`e o typedef **CA2W**.|atlconv.h|  
|[CAccessToken](../../atl/reference/caccesstoken-class.md)|Essa classe é um wrapper para um token de acesso.|atlsecurity.h|  
|[CAcl](../../atl/reference/cacl-class.md)|Essa classe é um wrapper para um **ACL** estrutura (lista de controle de acesso).|atlsecurity.h|  
|[CAdapt](../../atl/reference/cadapt-class.md)|Este modelo é usado para incluir classes que redefinem o operador address-of para retornar algo diferente do endereço do objeto.|atlcomcli.h|  
|[CAtlArray](../../atl/reference/catlarray-class.md)|Essa classe implementa um objeto de matriz.|atlcoll.h|  
|[CAtlAutoThreadModule](../../atl/reference/catlautothreadmodule-class.md)|Essa classe implementa um servidor de pool de thread, o modelo de apartment COM.|atlbase.h|  
|[CAtlAutoThreadModuleT](../../atl/reference/catlautothreadmodulet-class.md)|Essa classe fornece métodos para a implementação de um servidor de pool de thread, o modelo de apartment COM.|atlbase.h|  
|[CAtlBaseModule](../../atl/reference/catlbasemodule-class.md)|Essa classe é instanciada em cada projeto ATL.|atlcore.h|  
|[CAtlComModule](../../atl/reference/catlcommodule-class.md)|Essa classe implementa um módulo COM de servidor.|atlbase.h|  
|[CAtlDebugInterfacesModule](../../atl/reference/catldebuginterfacesmodule-class.md)|Essa classe fornece suporte para interfaces de depuração.|atlbase.h|  
|[CAtlDllModuleT](../../atl/reference/catldllmodulet-class.md)|Essa classe representa o módulo para uma DLL.|atlbase.h|  
|[CAtlException](../../atl/reference/catlexception-class.md)|Essa classe define uma exceção de ATL.|atlexcept.h|  
|[CAtlExeModuleT](../../atl/reference/catlexemodulet-class.md)|Essa classe representa o módulo para um aplicativo.|atlbase.h|  
|[CAtlFile](../../atl/reference/catlfile-class.md)|Essa classe fornece um wrapper fino em torno do Windows API de manipulação de arquivos.|atlfile.h|  
|[CAtlFileMapping](../../atl/reference/catlfilemapping-class.md)|Essa classe representa um arquivo de mapeamento de memória, adicionando um operador cast para os métodos de [CAtlFileMappingBase](../../atl/reference/catlfilemappingbase-class.md).|atlfile.h|  
|[CAtlFileMappingBase](../../atl/reference/catlfilemappingbase-class.md)|Essa classe representa um arquivo de mapeamento de memória.|atlfile.h|  
|[CAtlList](../../atl/reference/catllist-class.md)|Essa classe fornece métodos para criar e gerenciar um objeto de lista.|atlcoll.h|  
|[CAtlMap](../../atl/reference/catlmap-class.md)|Essa classe fornece métodos para criar e gerenciar um objeto de mapa.|atlcoll.h|  
|[CAtlModule](../../atl/reference/catlmodule-class.md)|Essa classe fornece métodos usados por várias classes de módulo ATL.|atlbase.h|  
|[CAtlModuleT](../../atl/reference/catlmodulet-class.md)|Essa classe implementa um módulo ATL.|atlbase.h|  
|[CAtlPreviewCtrlImpl](../../atl/reference/catlpreviewctrlimpl-class.md)|Essa classe é uma implementação de ATL de uma janela que é colocada em uma janela do host fornecida pelo Shell para visualização avançada.|atlpreviewctrlimpl.h|  
|[CAtlServiceModuleT](../../atl/reference/catlservicemodulet-class.md)|Essa classe implementa um serviço.|atlbase.h|  
|[CAtlTemporaryFile](../../atl/reference/catltemporaryfile-class.md)|Essa classe fornece métodos para a criação e uso de um arquivo temporário.|atlfile.h|  
|[CAtlTransactionManager](../../atl/reference/catltransactionmanager-class.md)|Essa classe fornece um wrapper para funções do Gerenciador KTM (Kernel Transaction).|atltransactionmanager.h|  
|[CAtlWinModule](../../atl/reference/catlwinmodule-class.md)|Essa classe fornece suporte para componentes de janelas ATL.|atlbase.h|  
|[CAutoPtr](../../atl/reference/cautoptr-class.md)|Essa classe representa um objeto de ponteiro inteligente.|atlbase.h|  
|[CAutoPtrArray](../../atl/reference/cautoptrarray-class.md)|Essa classe fornece métodos úteis ao construir uma matriz de ponteiros inteligentes.|atlbase.h|  
|[CAutoPtrElementTraits](../../atl/reference/cautoptrelementtraits-class.md)|Essa classe fornece métodos, funções estáticas e typedefs útil ao criar coleções de ponteiros inteligentes.|atlcoll.h|  
|[CAutoPtrList](../../atl/reference/cautoptrlist-class.md)|Essa classe fornece métodos úteis ao construir uma lista de ponteiros inteligentes.|atlcoll.h|  
|[CAutoVectorPtr](../../atl/reference/cautovectorptr-class.md)|Essa classe representa um objeto de ponteiro inteligente usando o vetor de novo e excluir operadores.|atlbase.h|  
|[CAutoVectorPtrElementTraits](../../atl/reference/cautovectorptrelementtraits-class.md)|Essa classe fornece métodos, funções estáticas e typedefs útil ao criar coleções de ponteiros inteligentes usando o vetor de novo e excluir operadores.|atlcoll.h|  
|[CAxDialogImpl](../../atl/reference/caxdialogimpl-class.md)|Essa classe implementa uma caixa de diálogo (modal ou sem janela restrita) que hospeda os controles ActiveX.|atlwin.h|  
|[CAxWindow](../../atl/reference/caxwindow-class.md)|Essa classe fornece métodos para manipular uma janela hospedando um controle ActiveX.|atlwin.h|  
|[CAxWindow2T](../../atl/reference/caxwindow2t-class.md)|Essa classe fornece métodos para manipular uma janela que hospeda um controle ActiveX e também tem suporte para hospedagem de controles ActiveX licenciados.|atlwin.h|  
|[CBindStatusCallback](../../atl/reference/cbindstatuscallback-class.md)|Essa classe implementa o `IBindStatusCallback` interface.|atlctl.h|  
|[CComAggObject](../../atl/reference/ccomaggobject-class.md)|Essa classe implementa [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) para um objeto agregado.|atlcom.h|  
|[CComAllocator](../../atl/reference/ccomallocator-class.md)|Essa classe fornece métodos para o gerenciamento de memória usando COM rotinas de memória.|atlbase.h|  
|[CComApartment](../../atl/reference/ccomapartment-class.md)|Essa classe fornece suporte para o gerenciamento de um compartimento em um módulo EXE pool de thread.|atlbase.h|  
|[CComAutoCriticalSection](../../atl/reference/ccomautocriticalsection-class.md)|Essa classe fornece métodos para a obtenção e liberar a propriedade de um objeto de seção crítica.|atlcore.h|  
|[CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md)|A partir de ATL 7.0, `CComAutoThreadModule` é obsoleta: consulte [ATL módulos](../../atl/atl-module-classes.md) para obter mais detalhes.|atlbase.h|  
|[CComBSTR](../../atl/reference/ccombstr-class.md)|Essa classe é um wrapper para `BSTR`s.|atlbase.h|  
|[CComCachedTearOffObject](../../atl/reference/ccomcachedtearoffobject-class.md)|Essa classe implementa [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) para uma interface destacável.|atlcom.h|  
|[CComClassFactory](../../atl/reference/ccomclassfactory-class.md)|Essa classe implementa o [IClassFactory](http://msdn.microsoft.com/library/windows/desktop/ms694364) interface.|atlcom.h|  
|[CComClassFactory2](../../atl/reference/ccomclassfactory2-class.md)|Essa classe implementa o [IClassFactory2](http://msdn.microsoft.com/library/windows/desktop/ms692720) interface.|atlcom.h|  
|[CComClassFactoryAutoThread](../../atl/reference/ccomclassfactoryautothread-class.md)|Essa classe implementa o [IClassFactory](http://msdn.microsoft.com/library/windows/desktop/ms694364) interface e permite que os objetos a serem criados em vários apartments.|atlcom.h|  
|[CComClassFactorySingleton](../../atl/reference/ccomclassfactorysingleton-class.md)|Essa classe é derivada de [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) e usa [CComObjectGlobal](../../atl/reference/ccomobjectglobal-class.md) para construir um único objeto.|atlcom.h|  
|[CComCoClass](../../atl/reference/ccomcoclass-class.md)|Essa classe fornece métodos para criar instâncias de uma classe e obter suas propriedades.|atlcom.h|  
|[CComCompositeControl](../../atl/reference/ccomcompositecontrol-class.md)|Essa classe fornece os métodos necessários para implementar um controle composto.|atlctl.h|  
|[CComContainedObject](../../atl/reference/ccomcontainedobject-class.md)|Essa classe implementa [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) delegando para o objeto de proprietário **IUnknown**.|atlcom.h|  
|[CComControl](../../atl/reference/ccomcontrol-class.md)|Essa classe fornece métodos para criar e gerenciar os controles da ATL.|atlctl.h|  
|[CComControlBase](../../atl/reference/ccomcontrolbase-class.md)|Essa classe fornece métodos para criar e gerenciar os controles da ATL.|atlctl.h|  
|[CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md)|Essa classe fornece métodos para a obtenção e liberar a propriedade de um objeto de seção crítica.|atlcore.h|  
|[CComCritSecLock](../../atl/reference/ccomcritseclock-class.md)|Essa classe fornece métodos para bloquear e desbloquear um objeto de seção crítica.|atlbase.h|  
|[CComCurrency](../../atl/reference/ccomcurrency-class.md)|Essa classe tem métodos e operadores para criar e gerenciar uma `CURRENCY` objeto.|atlcur.h|  
|[CComDynamicUnkArray](../../atl/reference/ccomdynamicunkarray-class.md)|Essa classe armazena uma matriz de **IUnknown** ponteiros.|atlcom.h|  
|[CComEnum](../../atl/reference/ccomenum-class.md)|Essa classe define um objeto de enumerador COM base em uma matriz.|atlcom.h|  
|[CComEnumImpl](../../atl/reference/ccomenumimpl-class.md)|Essa classe fornece a implementação de uma interface de enumerador COM onde os itens que estão sendo enumerados são armazenados em uma matriz.|atlcom.h|  
|[CComEnumOnSTL](../../atl/reference/ccomenumonstl-class.md)|Essa classe define um objeto de enumerador COM base em uma coleção de biblioteca padrão C++.|atlcom.h|  
|[CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md)|Essa classe fornece os mesmos métodos que [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md) , mas não fornece uma seção crítica.|atlcore.h|  
|[CComGITPtr](../../atl/reference/ccomgitptr-class.md)|Essa classe fornece métodos para lidar com ponteiros de interface e a tabela de interface global (GIT).|atlbase.h|  
|[CComHeap](../../atl/reference/ccomheap-class.md)|Essa classe implementa [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md) usando as funções de alocação de memória COM.|ATLComMem.h|  
|[CComHeapPtr](../../atl/reference/ccomheapptr-class.md)|Uma classe de ponteiro inteligente para o gerenciamento de ponteiros de pilha.|atlbase.h|  
|[CComModule](../../atl/reference/ccommodule-class.md)|A partir de ATL 7.0, `CComModule` é obsoleta: consulte [ATL módulos](../../atl/atl-module-classes.md) para obter mais detalhes.|atlbase.h|  
|[CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md)|Essa classe fornece métodos de thread-safe para incrementar e decrementar o valor de uma variável.|atlbase.h|  
|[CComMultiThreadModelNoCS](../../atl/reference/ccommultithreadmodelnocs-class.md)|Essa classe fornece métodos de thread-safe para incrementar e decrementar o valor de uma variável, sem bloqueio de seção crítica ou funcionalidade de desbloqueio.|atlbase.h|  
|[CComObject](../../atl/reference/ccomobject-class.md)|Essa classe implementa **IUnknown** para um objeto agregado.|atlcom.h|  
|[CComObjectGlobal](../../atl/reference/ccomobjectglobal-class.md)|Essa classe gerencia uma contagem de referência no módulo que contém o `Base` objeto.|atlcom.h|  
|[CComObjectNoLock](../../atl/reference/ccomobjectnolock-class.md)|Essa classe implementa **IUnknown** para um objeto agregado, mas não não incremento contar o bloqueio de módulo no construtor.|atlcom.h|  
|[CComObjectRoot](../../atl/reference/ccomobjectroot-class.md)|Este typedef de [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md) é transformado em modelo no modelo do servidor de threading padrão.|atlcom.h|  
|[CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)|Essa classe fornece métodos para lidar com o gerenciamento de contagem de referência de objeto para objetos agregados e agregados.|atlcom.h|  
|[CComObjectStack](../../atl/reference/ccomobjectstack-class.md)|Essa classe cria um objeto COM temporário e fornece uma implementação esqueleto de **IUnknown**.|atlcom.h|  
|[CComPolyObject](../../atl/reference/ccompolyobject-class.md)|Essa classe implementa **IUnknown** para um objeto agregado ou agregado.|atlcom.h|  
|[CComPtr](../../atl/reference/ccomptr-class.md)|Uma classe de ponteiro inteligente para o gerenciamento de ponteiros de interface COM.|atlcomcli.h|  
|[CComPtrBase](../../atl/reference/ccomptrbase-class.md)|Essa classe fornece uma base para classes de ponteiro inteligente usando memória COM base em rotinas.|atlcomcli.h|  
|[CComQIPtr](../../atl/reference/ccomqiptr-class.md)|Uma classe de ponteiro inteligente para o gerenciamento de ponteiros de interface COM.|atlcomcli.h|  
|[CComQIPtrElementTraits](../../atl/reference/ccomqiptrelementtraits-class.md)|Essa classe fornece métodos, funções estáticas e typedefs útil ao criar coleções de ponteiros de interface COM.|atlcoll.h|  
|[CComSafeArray](../../atl/reference/ccomsafearray-class.md)|Essa classe é um wrapper para o `SAFEARRAY Data Type` estrutura.|atlsafe.h|  
|[CComSafeArrayBound](../../atl/reference/ccomsafearraybound-class.md)|Essa classe é um wrapper para um `SAFEARRAYBOUND` estrutura.|atlsafe.h|  
|[CComSimpleThreadAllocator](../../atl/reference/ccomsimplethreadallocator-class.md)|Essa classe gerencia a seleção de thread para a classe [CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md).|atlbase.h|  
|[CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md)|Essa classe fornece métodos para incrementar e decrementar o valor de uma variável.|atlbase.h|  
|[CComTearOffObject](../../atl/reference/ccomtearoffobject-class.md)|Essa classe implementa uma interface destacável.|atlcom.h|  
|[CComUnkArray](../../atl/reference/ccomunkarray-class.md)|Essa classe armazena **IUnknown** ponteiros e foi projetado para ser usado como um parâmetro para o [IConnectionPointImpl](../../atl/reference/iconnectionpointimpl-class.md) classe de modelo.|atlcom.h|  
|[CComVariant](../../atl/reference/ccomvariant-class.md)|Essa classe encapsula o tipo de VARIANTE, fornecendo um membro que indica o tipo de dados armazenados.|atlcomcli.h|  
|[CContainedWindowT](../../atl/reference/ccontainedwindowt-class.md)|Essa classe implementa uma janela contida dentro de outro objeto.|atlwin.h|  
|[CCRTAllocator](../../atl/reference/ccrtallocator-class.md)|Essa classe fornece métodos para o gerenciamento de memória usando as rotinas de memória do CRT.|atlcore.h|  
|[CCRTHeap](../../atl/reference/ccrtheap-class.md)|Essa classe implementa [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md) usando as funções de CRT heap.|atlmem.h|  
|[CDacl](../../atl/reference/cdacl-class.md)|Essa classe é um wrapper para uma estrutura DACL (lista de controle de acesso discricionário).|atlsecurity.h|  
|[Classe CDebugReportHook](../../atl/reference/cdebugreporthook-class.md)|Use esta classe para enviar relatórios de depuração para um pipe nomeado.|atlutil.h|  
|[CDefaultCharTraits](../../atl/reference/cdefaultchartraits-class.md)|Essa classe fornece duas funções estáticas para conversão de caracteres entre maiusculas e minúsculas.|atlcoll.h|  
|[CDefaultCompareTraits](../../atl/reference/cdefaultcomparetraits-class.md)|Essa classe fornece funções de comparação de elemento de padrão.|atlcoll.h|  
|[CDefaultElementTraits](../../atl/reference/cdefaultelementtraits-class.md)|Essa classe fornece funções e métodos padrão para uma classe de coleção.|atlcoll.h|  
|[CDefaultHashTraits](../../atl/reference/cdefaulthashtraits-class.md)|Essa classe fornece uma função estática para calcular valores de hash.|atlcoll.h|  
|[CDialogImpl](../../atl/reference/cdialogimpl-class.md)|Essa classe fornece métodos para criar uma caixa de diálogo modal ou sem janela restrita.|atlwin.h|  
|[CDynamicChain](../../atl/reference/cdynamicchain-class.md)|Essa classe fornece métodos que suporte o encadeamento dinâmico de mapas de mensagem.|atlwin.h|  
|[CElementTraits](../../atl/reference/celementtraits-class.md)|Essa classe é usada pelas classes de coleção para fornecer funções e métodos para mover, copiar, comparação e operações de hash.|atlcoll.h|  
|[CElementTraitsBase](../../atl/reference/celementtraitsbase-class.md)|Esta classe fornece uma cópia padrão e move os métodos para uma classe de coleção.|atlcoll.h|  
|[CFirePropNotifyEvent](../../atl/reference/cfirepropnotifyevent-class.md)|Essa classe fornece métodos para notificar o coletor do contêiner sobre as alterações de propriedade do controle.|atlctl.h|  
|[CGlobalHeap](../../atl/reference/cglobalheap-class.md)|Essa classe implementa [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md) usando as funções de pilha global do Win32.|atlmem.h|  
|[CHandle](../../atl/reference/chandle-class.md)|Essa classe fornece métodos para criar e usar um objeto de identificador.|atlbase.h|  
|[CHeapPtr](../../atl/reference/cheapptr-class.md)|Uma classe de ponteiro inteligente para o gerenciamento de ponteiros de pilha.|atlcore.h|  
|[CHeapPtrBase](../../atl/reference/cheapptrbase-class.md)|Essa classe constitui a base para várias classes de ponteiro inteligente do heap.|atlcore.h|  
|[Classe CHeapPtrElementTraits](../../atl/reference/cheapptrelementtraits-class.md)|Essa classe fornece métodos, funções estáticas e typedefs útil ao criar coleções de ponteiros de pilha.|atlcoll.h|  
|[CHeapPtrList](../../atl/reference/cheapptrlist-class.md)|Essa classe fornece métodos úteis ao construir uma lista de ponteiros de pilha.|atlcoll.h|  
|[CImage](../../atl-mfc-shared/reference/cimage-class.md)|Fornece suporte de bitmap aprimorada, incluindo a capacidade de carregar e salvar imagens em formatos JPEG, GIF, BMP e elementos gráficos PNG (Portable Network).|atlimage.h|  
|[CInterfaceArray](../../atl/reference/cinterfacearray-class.md)|Essa classe fornece métodos úteis ao construir uma matriz de ponteiros de interface COM.|atlcoll.h|  
|[CInterfaceList](../../atl/reference/cinterfacelist-class.md)|Essa classe fornece métodos úteis ao construir uma lista de ponteiros de interface COM.|atlcoll.h|  
|[CLocalHeap](../../atl/reference/clocalheap-class.md)|Essa classe implementa [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md) usando as funções de heap local Win32.|atlmem.h|  
|[CMessageMap](../../atl/reference/cmessagemap-class.md)|Essa classe permite que mapas de mensagem de um objeto para ser acessado por outro objeto.|atlwin.h|  
|[Classe CNonStatelessWorker](../../atl/reference/cnonstatelessworker-class.md)|Recebe solicitações de um pool de threads e as transmite para um objeto de trabalho que é criado e destruído em cada solicitação.|atlutil.h|  
|[Classe CNoWorkerThread](../../atl/reference/cnoworkerthread-class.md)|Use essa classe como o argumento para o `MonitorClass` classes de cache de parâmetro de modelo se você deseja desabilitar a manutenção de cache dinâmico.|atlutil.h|  
|[Classe CPathT](../../atl/reference/cpatht-class.md)|Essa classe representa um caminho.|atlpath.h|  
|[CPrimitiveElementTraits](../../atl/reference/cprimitiveelementtraits-class.md)|Essa classe fornece métodos padrão e funções para uma classe de coleção composta de tipos de dados primitivos.|atlcoll.h|  
|[CPrivateObjectSecurityDesc](../../atl/reference/cprivateobjectsecuritydesc-class.md)|Essa classe representa um objeto de descritor de segurança do objeto particular.|atlsecurity.h|  
|[CRBMap](../../atl/reference/crbmap-class.md)|Essa classe representa uma estrutura de mapeamento, usando uma árvore binária vermelho-preto.|atlcoll.h|  
|[CRBMultiMap](../../atl/reference/crbmultimap-class.md)|Essa classe representa uma estrutura de mapeamento que permite que cada chave a ser associado a mais de um valor, usando uma árvore binária vermelho-preto.|atlcoll.h|  
|[CRBTree](../../atl/reference/crbtree-class.md)|Essa classe fornece métodos para criação e uso de uma árvore de vermelho-preto.|atlcoll.h|  
|[CRegKey](../../atl/reference/cregkey-class.md)|Essa classe fornece métodos para manipular as entradas no registro do sistema.|atlbase.h|  
|[CRTThreadTraits](../../atl/reference/crtthreadtraits-class.md)|Essa classe fornece a função de criação de um thread do CRT. Use essa classe se o thread de usar funções de CRT.|atlbase.h|  
|[CSacl](../../atl/reference/csacl-class.md)|Essa classe é um wrapper para uma estrutura SACL (lista de controle de acesso do sistema).|atlsecurity.h|  
|[CSecurityAttributes](../../atl/reference/csecurityattributes-class.md)|Essa classe é um wrapper fino para o **SECURITY_ATTRIBUTES** estrutura.|atlsecurity.h|  
|[CSecurityDesc](../../atl/reference/csecuritydesc-class.md)|Essa classe é um wrapper para o **SECURITY_DESCRIPTOR** estrutura.|atlsecurity.h|  
|[CSid](../../atl/reference/csid-class.md)|Essa classe é um wrapper para um `SID` estrutura (identificador de segurança).|atlsecurity.h|  
|[CSimpleArray](../../atl/reference/csimplearray-class.md)|Essa classe fornece métodos para gerenciar uma matriz simples.|atlsimpcoll.h|  
|[CSimpleArrayEqualHelper](../../atl/reference/csimplearrayequalhelper-class.md)|Essa classe é um auxiliar de [CSimpleArray](../../atl/reference/csimplearray-class.md) classe.|atlsimpcoll.h|  
|[CSimpleArrayEqualHelperFalse](../../atl/reference/csimplearrayequalhelperfalse-class.md)|Essa classe é um auxiliar de [CSimpleArray](../../atl/reference/csimplearray-class.md) classe.|atlsimpcoll.h|  
|[CSimpleDialog](../../atl/reference/csimpledialog-class.md)|Essa classe implementa uma caixa de diálogo modal básico.|atlwin.h|  
|[CSimpleMap](../../atl/reference/csimplemap-class.md)|Essa classe fornece suporte para uma matriz de mapeamento simples.|atlsimpcoll.h|  
|[CSimpleMapEqualHelper](../../atl/reference/csimplemapequalhelper-class.md)|Essa classe é um auxiliar de [CSimpleMap](../../atl/reference/csimplemap-class.md) classe.|atlsimpcoll.h|  
|[CSimpleMapEqualHelperFalse](../../atl/reference/csimplemapequalhelperfalse-class.md)|Essa classe é um auxiliar de [CSimpleMap](../../atl/reference/csimplemap-class.md) classe.|atlsimpcoll.h|  
|[CSnapInItemImpl](../../atl/reference/csnapinitemimpl-class.md)|Essa classe fornece métodos para a implementação de um objeto de nó do snap-in.|atlsnap.h|  
|[CSnapInPropertyPageImpl](../../atl/reference/csnapinpropertypageimpl-class.md)|Essa classe fornece métodos para a implementação de um objeto de página de propriedade do snap-in.|atlsnap.h|  
|[CStockPropImpl](../../atl/reference/cstockpropimpl-class.md)|Essa classe fornece métodos para dar suporte a valores de propriedade de estoque.|atlctl.h|  
|[CStringElementTraits](../../atl/reference/cstringelementtraits-class.md)|Essa classe fornece funções estáticas usadas pelas classes de coleção armazenar `CString` objetos.|cstringt.h|  
|[CStringElementTraitsI](../../atl/reference/cstringelementtraitsi-class.md)|Essa classe fornece funções estáticas relacionadas a cadeias de caracteres armazenadas em objetos de classe de coleção. Ele é semelhante a [CStringElementTraits](../../atl/reference/cstringelementtraits-class.md), mas executa comparações em maiusculas e minúsculas.|atlcoll.h|  
|[CStringRefElementTraits](../../atl/reference/cstringrefelementtraits-class.md)|Essa classe fornece funções estáticas relacionadas a cadeias de caracteres armazenadas em objetos de classe de coleção. Os objetos de cadeia de caracteres são tratados como referências.|atlcoll.h|  
|[Classe CThreadPool](../../atl/reference/cthreadpool-class.md)|Essa classe fornece um pool de threads de trabalho que processam uma fila de itens de trabalho.|atlutil.h|  
|[CTokenGroups](../../atl/reference/ctokengroups-class.md)|Essa classe é um wrapper para o **TOKEN_GROUPS** estrutura.|atlsecurity.h|  
|[CTokenPrivileges](../../atl/reference/ctokenprivileges-class.md)|Essa classe é um wrapper para o **TOKEN_PRIVILEGES** estrutura.|atlsecurity.h|  
|[Classe CUrl](../../atl/reference/curl-class.md)|Essa classe representa uma URL. Ele permite que você manipule cada elemento da URL, independentemente de outras pessoas se uma URL existente de análise de cadeia de caracteres ou criando uma cadeia de caracteres a partir do zero.|atlutil.h|  
|[CW2AEX](../../atl/reference/cw2aex-class.md)|Essa classe é usada pelas macros de conversão de cadeia de caracteres `CT2AEX`, `CW2TEX`, `CW2CTEX`, e `CT2CAEX`e o typedef **CW2A**.|atlconv.h|  
|[CW2CWEX](../../atl/reference/cw2cwex-class.md)|Essa classe é usada pelas macros de conversão de cadeia de caracteres `CW2CTEX` e `CT2CWEX`e o typedef **CW2CW**.|atlconv.h|  
|[CW2WEX](../../atl/reference/cw2wex-class.md)|Essa classe é usada pelas macros de conversão de cadeia de caracteres `CW2TEX` e `CT2WEX`e o typedef `CW2W`.|atlconv.h|  
|[CWin32Heap](../../atl/reference/cwin32heap-class.md)|Essa classe implementa [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md) usando as funções de alocação de heap de Win32.|atlmem.h|  
|[CWindow](../../atl/reference/cwindow-class.md)|Essa classe fornece métodos para manipular uma janela.|atlwin.h|  
|[CWindowImpl](../../atl/reference/cwindowimpl-class.md)|Essa classe fornece métodos para criar ou subclasses de uma janela.|atlwin.h|  
|[CWinTraits](../../atl/reference/cwintraits-class.md)|Essa classe fornece um método para padronizar os estilos usados ao criar um objeto de janela.|atlwin.h|  
|[CWinTraitsOR](../../atl/reference/cwintraitsor-class.md)|Essa classe fornece um método para padronizar os estilos usados ao criar um objeto de janela.|atlwin.h|  
|[CWndClassInfo](../../atl/reference/cwndclassinfo-class.md)|Essa classe fornece métodos para registrar informações para uma classe de janela.|atlwin.h|  
|[Classe CWorkerThread](../../atl/reference/cworkerthread-class.md)|Essa classe cria um thread de trabalho ou usa um existente, espera um ou mais identificadores de objeto kernel e executa uma função de cliente especificado quando uma das alças é sinalizada.|atlutil.h|  
|[IAtlAutoThreadModule](../../atl/reference/iatlautothreadmodule-class.md)|Essa classe representa uma interface para um `CreateInstance` método.|atlbase.h|  
|[IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md)|Essa classe representa a interface para um Gerenciador de memória.|atlmem.h|  
|[IAxWinAmbientDispatch](../../atl/reference/iaxwinambientdispatch-interface.md)|Essa interface fornece métodos para especificar as características do controle hospedado ou contêiner.|atlbase.h, ATLIFace.h|  
|[IAxWinAmbientDispatchEx](../../atl/reference/iaxwinambientdispatchex-interface.md)|Essa interface implementa propriedades de ambiente complementares para um controle hospedado.|atlbase.h, ATLIFace.h|  
|[IAxWinHostWindow](../../atl/reference/iaxwinhostwindow-interface.md)|Essa interface fornece métodos para manipular um controle e seu objeto de host.|atlbase.h, ATLIFace.h|  
|[IAxWinHostWindowLic](../../atl/reference/iaxwinhostwindowlic-interface.md)|Essa interface fornece métodos para manipular um controle licenciado e seu objeto de host.|atlbase.h, ATLIFace.h|  
|[ICollectionOnSTLImpl](../../atl/reference/icollectiononstlimpl-class.md)|Essa classe fornece métodos usados por uma classe de coleção.|atlcom.h|  
|[IConnectionPointContainerImpl](../../atl/reference/iconnectionpointcontainerimpl-class.md)|Essa classe implementa um contêiner de ponto de conexão para gerenciar uma coleção de [IConnectionPointImpl](../../atl/reference/iconnectionpointimpl-class.md) objetos.|atlcom.h|  
|[IConnectionPointImpl](../../atl/reference/iconnectionpointimpl-class.md)|Essa classe implementa um ponto de conexão.|atlcom.h|  
|[IDataObjectImpl](../../atl/reference/idataobjectimpl-class.md)|Essa classe fornece métodos para suporte uniforme de transferência de dados e gerenciamento de conexões.|atlctl.h|  
|[IDispatchImpl](../../atl/reference/idispatchimpl-class.md)|Essa classe fornece uma implementação padrão para o `IDispatch` parte de uma interface dupla.|atlcom.h|  
|[IDispEventImpl](../../atl/reference/idispeventimpl-class.md)|Essa classe fornece implementações do `IDispatch` métodos.|atlcom.h|  
|[IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md)|Essa classe fornece implementações do `IDispatch` métodos sem obter informações sobre o tipo de uma biblioteca de tipos.|atlcom.h|  
|[IDocHostUIHandlerDispatch](../../atl/reference/idochostuihandlerdispatch-interface.md)|Uma interface para a análise de HTML da Microsoft e o mecanismo de renderização.|atlbase.h, ATLIFace.h|  
|[IEnumOnSTLImpl](../../atl/reference/ienumonstlimpl-class.md)|Essa classe define uma interface de enumerador com base em uma coleção de biblioteca padrão C++.|atlcom.h|  
|[IObjectSafetyImpl](../../atl/reference/iobjectsafetyimpl-class.md)|Essa classe fornece uma implementação padrão da `IObjectSafety` interface para permitir que um cliente recuperar e definir níveis de segurança de um objeto.|atlctl.h|  
|[IObjectWithSiteImpl](../../atl/reference/iobjectwithsiteimpl-class.md)|Essa classe fornece métodos que permitem a um objeto para se comunicar com seu site.|atlcom.h|  
|[IOleControlImpl](../../atl/reference/iolecontrolimpl-class.md)|Essa classe fornece uma implementação padrão de **IOleControl** interface e implementa **IUnknown**.|atlctl.h|  
|[IOleInPlaceActiveObjectImpl](../../atl/reference/ioleinplaceactiveobjectimpl-class.md)|Essa classe fornece métodos para ajudar a comunicação entre um controle no local e o contêiner.|atlctl.h|  
|[IOleInPlaceObjectWindowlessImpl](../../atl/reference/ioleinplaceobjectwindowlessimpl-class.md)|Essa classe implementa **IUnknown** e fornece métodos que permitem um controle sem janelas para receber mensagens de janela e participar de operações de arrastar e soltar.|atlctl.h|  
|[IOleObjectImpl](../../atl/reference/ioleobjectimpl-class.md)|Essa classe implementa **IUnknown** e é a principal interface por meio do qual um contêiner se comunica com um controle.|atlctl.h|  
|[IPerPropertyBrowsingImpl](../../atl/reference/iperpropertybrowsingimpl-class.md)|Essa classe implementa **IUnknown** e permite que um cliente acessar as informações nas páginas de propriedades de um objeto.|atlctl.h|  
|[IPersistPropertyBagImpl](../../atl/reference/ipersistpropertybagimpl-class.md)|Essa classe implementa **IUnknown** e permite que um objeto salvar suas propriedades em um recipiente de propriedades fornecido pelo cliente.|atlcom.h|  
|[IPersistStorageImpl](../../atl/reference/ipersiststorageimpl-class.md)|Essa classe implementa o [IPersistStorage](http://msdn.microsoft.com/library/windows/desktop/ms679731) interface.|atlcom.h|  
|[IPersistStreamInitImpl](../../atl/reference/ipersiststreaminitimpl-class.md)|Essa classe implementa **IUnknown** e fornece uma implementação padrão de [IPersistStreamInit](http://msdn.microsoft.com/library/windows/desktop/ms682273) interface.|atlcom.h|  
|[IPointerInactiveImpl](../../atl/reference/ipointerinactiveimpl-class.md)|Essa classe implementa **IUnknown** e [IPointerInactive](http://msdn.microsoft.com/library/windows/desktop/ms693712) métodos de interface.|atlctl.h|  
|[IPropertyNotifySinkCP](../../atl/reference/ipropertynotifysinkcp-class.md)|Essa classe expõe o [IPropertyNotifySink](http://msdn.microsoft.com/library/windows/desktop/ms692638) interface como uma interface de saída em um objeto conectável.|atlctl.h|  
|[IPropertyPage2Impl](../../atl/reference/ipropertypage2impl-class.md)|Essa classe implementa **IUnknown** e herda a implementação padrão de [IPropertyPageImpl](../../atl/reference/ipropertypageimpl-class.md).|atlctl.h|  
|[IPropertyPageImpl](../../atl/reference/ipropertypageimpl-class.md)|Essa classe implementa **IUnknown** e fornece uma implementação padrão de [IPropertyPage](http://msdn.microsoft.com/library/windows/desktop/ms691246) interface.|atlctl.h|  
|[IProvideClassInfo2Impl](../../atl/reference/iprovideclassinfo2impl-class.md)|Essa classe fornece uma implementação padrão de [IProvideClassInfo](http://msdn.microsoft.com/library/windows/desktop/ms687303) e [IProvideClassInfo2](http://msdn.microsoft.com/library/windows/desktop/ms693764) métodos.|atlcom.h|  
|[IQuickActivateImpl](../../atl/reference/iquickactivateimpl-class.md)|Essa classe combina a inicialização dos contêineres de controle em uma única chamada.|atlctl.h|  
|[IRunnableObjectImpl](../../atl/reference/irunnableobjectimpl-class.md)|Essa classe implementa **IUnknown** e fornece uma implementação padrão de [IRunnableObject](http://msdn.microsoft.com/library/windows/desktop/ms692783) interface.|atlctl.h|  
|[IServiceProviderImpl](../../atl/reference/iserviceproviderimpl-class.md)|Essa classe fornece uma implementação padrão da `IServiceProvider` interface.|atlcom.h|  
|[ISpecifyPropertyPagesImpl](../../atl/reference/ispecifypropertypagesimpl-class.md)|Essa classe implementa **IUnknown** e fornece uma implementação padrão de [ISpecifyPropertyPages](http://msdn.microsoft.com/library/windows/desktop/ms695217) interface.|atlcom.h|  
|[ISupportErrorInfoImpl](../../atl/reference/isupporterrorinfoimpl-class.md)|Essa classe fornece uma implementação padrão da `ISupportErrorInfo Interface` interface e pode ser usada quando somente uma única interface gera erros em um objeto.|atlcom.h|  
|[Interface IThreadPoolConfig](../../atl/reference/ithreadpoolconfig-interface.md)|Essa interface fornece métodos para configurar um pool de threads.|atlutil.h|  
|[IViewObjectExImpl](../../atl/reference/iviewobjecteximpl-class.md)|Essa classe implementa **IUnknown** e fornece implementações padrão de [IViewObject](http://msdn.microsoft.com/library/windows/desktop/ms680763), [IViewObject2](http://msdn.microsoft.com/library/windows/desktop/ms691318), e [IViewObjectEx](http://msdn.microsoft.com/library/windows/desktop/ms682375)interfaces.|atlctl.h|  
|[Interface IWorkerThreadClient](../../atl/reference/iworkerthreadclient-interface.md)|`IWorkerThreadClient` é a interface implementada por clientes a [CWorkerThread](../../atl/reference/cworkerthread-class.md) classe.|atlutil.h|  
|[_U_MENUorID](../../atl/reference/u-menuorid-class.md)|Essa classe fornece wrappers para **CreateWindow** e **CreateWindowEx**.|atlwin.h|  
|[_U_RECT](../../atl/reference/u-rect-class.md)|Essa classe de adaptador do argumento permite tanto `RECT` ponteiros ou referências a serem passados para uma função que é implementada em termos de ponteiros.|atlwin.h|  
|[_U_STRINGorID](../../atl/reference/u-stringorid-class.md)|Esta classe de adaptador do argumento permite que qualquer um dos nomes de recursos (`LPCTSTR`s) ou IDs de recurso (**UINT**s) a serem passados para uma função sem exigir que o chamador converter a ID em uma cadeia de caracteres usando o **MAKEINTRESOURCE** macro.|atlwin.h|  
|[Win32ThreadTraits](../../atl/reference/win32threadtraits-class.md)|Essa classe fornece a função de criação de um thread do Windows. Use essa classe se o thread não usará as funções de CRT.|atlbase.h|  
  
## <a name="see-also"></a>Consulte também  
 [Componentes de área de trabalho COM da ATL](../../atl/atl-com-desktop-components.md)   
 [Funções](../../atl/reference/atl-functions.md)   
 [Variáveis globais](../../atl/reference/atl-global-variables.md)   
 [Estruturas](../../atl/reference/atl-structures.md)   
 [Definições de tipo](../../atl/reference/atl-typedefs.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)


