---
title: "Classes de ATL | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "index-page "
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "ATL, classes"
  - "classes [C++], ATL"
ms.assetid: 7da42e2d-ac84-4506-92bd-502a86d68bdc
caps.latest.revision: 26
caps.handback.revision: 18
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes de ATL
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A biblioteca ativa \(ATL\) do modelo inclui as seguintes classes.  Para localizar uma classe específica por categoria, consulte [Visão geral da classe de ATL](../../atl/atl-class-overview.md).  
  
|Classe|Descrição|Arquivo de cabeçalho|  
|------------|---------------|--------------------------|  
|[CA2AEX](../../atl/reference/ca2aex-class.md)|Essa classe é usada por macros `CA2TEX` e `CT2AEX`de conversão de cadeia de caracteres, e o typedef **CA2A**.|atlconv.h|  
|[CA2CAEX](../../atl/reference/ca2caex-class.md)|Essa classe é usada por macros `CA2CTEX` e `CT2CAEX`de conversão de cadeia de caracteres, e o typedef **CA2CA**.|atlconv.h|  
|[CA2WEX](../../atl/reference/ca2wex-class.md)|Essa classe é usada por `CA2TEX`macros, `CA2CTEX`, `CT2WEX`, e `CT2CWEX`, e o typedef **CA2W**de conversão de cadeia de caracteres.|atlconv.h|  
|[CAccessToken](../Topic/CAccessToken%20Class.md)|Essa classe é um wrapper para um token de acesso.|atlsecurity.h|  
|[CAcl](../../atl/reference/cacl-class.md)|Essa classe é um wrapper para uma estrutura de **ACL** \(lista de controle de acesso\).|atlsecurity.h|  
|[CAdapt](../../atl/reference/cadapt-class.md)|Esse modelo é usado para englobar as classes que redefinem endereço\- do operador para retornar algo diferente do endereço do objeto.|atlcomcli.h|  
|[CAtlArray](../../atl/reference/catlarray-class.md)|Essa classe implementa um objeto de matriz.|atlcoll.h|  
|[CAtlAutoThreadModule](../../atl/reference/catlautothreadmodule-class.md)|Essa classe implementa com agrupados, o servidor de apartamento\- COM o modelo.|atlbase.h|  
|[CAtlAutoThreadModuleT](../../atl/reference/catlautothreadmodulet-class.md)|Essa classe fornece métodos para implementar com agrupados, o servidor de apartamento\- COM o modelo.|atlbase.h|  
|[CAtlBaseModule](../Topic/CAtlBaseModule%20Class.md)|Essa classe é instanciada em cada projeto de ATL.|atlcore.h|  
|[CAtlComModule](../../atl/reference/catlcommodule-class.md)|Essa classe implementa um módulo de servidor COM.|atlbase.h|  
|[CAtlDebugInterfacesModule](../../atl/reference/catldebuginterfacesmodule-class.md)|Essa classe fornece suporte para depurar interfaces.|atlbase.h|  
|[CAtlDllModuleT](../../atl/reference/catldllmodulet-class.md)|Esta classe representa o módulo para uma DLL.|atlbase.h|  
|[CAtlException](../Topic/CAtlException%20Class.md)|Essa classe define uma exceção de ATL.|atlexcept.h|  
|[CAtlExeModuleT](../../atl/reference/catlexemodulet-class.md)|Esta classe representa o módulo para um aplicativo.|atlbase.h|  
|[CAtlFile](../../atl/reference/catlfile-class.md)|Essa classe fornece melhor um wrapper em torno de arquivo tratamento API do windows.|atlfile.h|  
|[CAtlFileMapping](../Topic/CAtlFileMapping%20Class.md)|Esta classe representa um arquivo memória mapeado, adicionando um operador cast métodos de [CAtlFileMappingBase](../../atl/reference/catlfilemappingbase-class.md).|atlfile.h|  
|[CAtlFileMappingBase](../../atl/reference/catlfilemappingbase-class.md)|Esta classe representa um arquivo memória mapeado.|atlfile.h|  
|[CAtlList](../Topic/CAtlList%20Class.md)|Essa classe fornece métodos para criar e gerenciar um objeto de lista.|atlcoll.h|  
|[CAtlMap](../../atl/reference/catlmap-class.md)|Essa classe fornece métodos para criar e gerenciar um objeto de mapa.|atlcoll.h|  
|[CAtlModule](../../atl/reference/catlmodule-class.md)|Essa classe fornece os métodos usados por várias classes do módulo de ATL.|atlbase.h|  
|[CAtlModuleT](../../atl/reference/catlmodulet-class.md)|Essa classe implementa um módulo de ATL.|atlbase.h|  
|[CAtlPreviewCtrlImpl](../../atl/reference/catlpreviewctrlimpl-class.md)|Essa classe é uma implementação de ATL de uma janela que é colocada em uma janela hospedeira fornecida por Shell para a visualização rico.|atlpreviewctrlimpl.h|  
|[CAtlServiceModuleT](../Topic/CAtlServiceModuleT%20Class.md)|Essa classe implementa um serviço.|atlbase.h|  
|[CAtlTemporaryFile](../../atl/reference/catltemporaryfile-class.md)|Essa classe fornece métodos para a criação e uso de um arquivo temporário.|atlfile.h|  
|[CAtlTransactionManager](../../atl/reference/catltransactionmanager-class.md)|Essa classe fornece um wrapper funções de \(KTM\) do gerenciador de transações kernel.|atltransactionmanager.h|  
|[CAtlWinModule](../../atl/reference/catlwinmodule-class.md)|Essa classe fornece suporte para componentes da janela de ATL.|atlbase.h|  
|[CAutoPtr](../../atl/reference/cautoptr-class.md)|Esta classe representa um objeto inteligente do ponteiro.|atlbase.h|  
|[CAutoPtrArray](../../atl/reference/cautoptrarray-class.md)|Essa classe fornece os métodos úteis quando construir uma matriz de ponteiros inteligentes.|atlbase.h|  
|[CAutoPtrElementTraits](../Topic/CAutoPtrElementTraits%20Class.md)|Essa classe fornece métodos estáticos, funções, e typedefs úteis para criar coleções de ponteiros inteligentes.|atlcoll.h|  
|[CAutoPtrList](../../atl/reference/cautoptrlist-class.md)|Essa classe fornece os métodos úteis quando construir uma lista de ponteiros inteligentes.|atlcoll.h|  
|[CAutoVectorPtr](../../atl/reference/cautovectorptr-class.md)|Esta classe representa um objeto inteligente do ponteiro usando o vetor novo os operadores e delete.|atlbase.h|  
|[CAutoVectorPtrElementTraits](../../atl/reference/cautovectorptrelementtraits-class.md)|Essa classe fornece métodos estáticos, funções, e typedefs úteis para criar coleções de ponteiros inteligentes que usam o vetor novo e os operadores de exclusão.|atlcoll.h|  
|[CAxDialogImpl](../Topic/CAxDialogImpl%20Class.md)|Essa classe implementa uma caixa de diálogo ou sem janela restrita \(modal\) que controles ActiveX de host.|atlwin.h|  
|[CAxWindow](../../atl/reference/caxwindow-class.md)|Essa classe fornece métodos para manipular uma janela que hospeda um controle ActiveX.|atlwin.h|  
|[CAxWindow2T](../Topic/CAxWindow2T%20Class.md)|Essa classe fornece métodos para manipular uma janela que hospeda um controle ActiveX e também têm suporte para hospedar controles ActiveX licenciadas.|atlwin.h|  
|[CBindStatusCallback](../Topic/CBindStatusCallback%20Class.md)|Essa classe implementa a interface de `IBindStatusCallback` .|atlctl.h|  
|[CComAggObject](../../atl/reference/ccomaggobject-class.md)|Essa classe implementa [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) para um objeto agregado.|atlcom.h|  
|[CComAllocator](../../atl/reference/ccomallocator-class.md)|Essa classe fornece métodos para gerenciar a memória usando rotinas de memória COM.|atlbase.h|  
|[CComApartment](../../atl/reference/ccomapartment-class.md)|Essa classe fornece suporte para gerenciar um compartimento com agrupados em um módulo de EXE.|atlbase.h|  
|[CComAutoCriticalSection](../../atl/reference/ccomautocriticalsection-class.md)|Essa classe fornece métodos para obter e definir a propriedade de um objeto de seção crítica.|atlcore.h|  
|[CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md)|Até a data de ATL 7,0, `CComAutoThreadModule` é obsoleto: consulte [módulos de ATL](../Topic/ATL%20Module%20Classes.md) para obter mais detalhes.|atlbase.h|  
|[CComBSTR](../../atl/reference/ccombstr-class.md)|Essa classe é um wrapper para `BSTR`S.|atlbase.h|  
|[CComCachedTearOffObject](../../atl/reference/ccomcachedtearoffobject-class.md)|Essa classe implementa [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) para uma interface de rasgo \- fora.|atlcom.h|  
|[CComClassFactory](../../atl/reference/ccomclassfactory-class.md)|Essa classe implementa a interface de [IClassFactory](http://msdn.microsoft.com/library/windows/desktop/ms694364) .|atlcom.h|  
|[CComClassFactory2](../Topic/CComClassFactory2%20Class.md)|Essa classe implementa a interface de [IClassFactory2](http://msdn.microsoft.com/library/windows/desktop/ms692720) .|atlcom.h|  
|[CComClassFactoryAutoThread](../../atl/reference/ccomclassfactoryautothread-class.md)|Essa classe implementa a interface de [IClassFactory](http://msdn.microsoft.com/library/windows/desktop/ms694364) e permite que objetos criados em vários construção.|atlcom.h|  
|[CComClassFactorySingleton](../../atl/reference/ccomclassfactorysingleton-class.md)|Esta classe deriva de [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) e usa [CComObjectGlobal](../../atl/reference/ccomobjectglobal-class.md) para construir um único objeto.|atlcom.h|  
|[CComCoClass](../Topic/CComCoClass%20Class.md)|Essa classe fornece métodos para criar instâncias de uma classe e obter suas propriedades.|atlcom.h|  
|[CComCompositeControl](../../atl/reference/ccomcompositecontrol-class.md)|Essa classe fornece os métodos necessários para implementar um controle composto.|atlctl.h|  
|[CComContainedObject](../../atl/reference/ccomcontainedobject-class.md)|Essa classe implementa [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) delegando a **IUnknown**do objeto do proprietário.|atlcom.h|  
|[CComControl](../../atl/reference/ccomcontrol-class.md)|Essa classe fornece métodos para criar e gerenciar controles de ATL.|atlctl.h|  
|[CComControlBase](../Topic/CComControlBase%20Class.md)|Essa classe fornece métodos para criar e gerenciar controles de ATL.|atlctl.h|  
|[CComCriticalSection](../Topic/CComCriticalSection%20Class.md)|Essa classe fornece métodos para obter e definir a propriedade de um objeto de seção crítica.|atlcore.h|  
|[CComCritSecLock](../../atl/reference/ccomcritseclock-class.md)|Essa classe fornece métodos para bloquear e desbloquear um objeto de seção crítica.|atlbase.h|  
|[CComCurrency](../../atl/reference/ccomcurrency-class.md)|Essa classe tem métodos e operadores para criar e gerenciar um objeto de `CURRENCY` .|atlcur.h|  
|[CComDynamicUnkArray](../Topic/CComDynamicUnkArray%20Class.md)|Esta classe armazena uma matriz de ponteiros de **IUnknown** .|atlcom.h|  
|[CComEnum](../../atl/reference/ccomenum-class.md)|Esta classe define um objeto enumerator COM com base em uma matriz.|atlcom.h|  
|[CComEnumImpl](../../atl/reference/ccomenumimpl-class.md)|Essa classe fornece a implementação de uma interface de enumerador COM onde os itens que estão sendo enumerados sejam armazenados em uma matriz.|atlcom.h|  
|[CComEnumOnSTL](../../atl/reference/ccomenumonstl-class.md)|Esta classe define um objeto enumerator COM com base em uma coleção de STL.|atlcom.h|  
|[CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md)|Essa classe fornece os mesmos métodos que [CComCriticalSection](../Topic/CComCriticalSection%20Class.md) mas não fornece uma seção crítica.|atlcore.h|  
|[CComGITPtr](../Topic/CComGITPtr%20Class.md)|Essa classe fornece métodos para manipular os ponteiros de interface e a tabela global \(GIT\) da interface.|atlbase.h|  
|[CComHeap](../../atl/reference/ccomheap-class.md)|Essa classe implementa [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md) usando as funções de alocação de memória COM.|ATLComMem.h|  
|[CComHeapPtr](../../atl/reference/ccomheapptr-class.md)|Uma classe inteligente do ponteiro para gerenciar ponteiros da heap.|atlbase.h|  
|[CComModule](../../atl/reference/ccommodule-class.md)|Até a data de ATL 7,0, `CComModule` é obsoleto: consulte [módulos de ATL](../Topic/ATL%20Module%20Classes.md) para obter mais detalhes.|atlbase.h|  
|[CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md)|Essa classe fornece métodos para incrementar thread\-safe e diminuir o valor de uma variável.|atlbase.h|  
|[CComMultiThreadModelNoCS](../Topic/CComMultiThreadModelNoCS%20Class.md)|Essa classe fornece métodos para incrementar thread\-safe e diminuir o valor de uma variável, sem bloqueio de seção crítica ou desbloquear funcionalidade.|atlbase.h|  
|[CComObject](../../atl/reference/ccomobject-class.md)|Essa classe implementa **IUnknown** para um objeto nonaggregated.|atlcom.h|  
|[CComObjectGlobal](../../atl/reference/ccomobjectglobal-class.md)|Essa classe gerencia uma contagem de referência módulo que contém o objeto de `Base` .|atlcom.h|  
|[CComObjectNoLock](../Topic/CComObjectNoLock%20Class.md)|Essa classe implementa **IUnknown** para um objeto nonaggregated, mas não incrementa a contagem de bloqueio de módulo no construtor.|atlcom.h|  
|[CComObjectRoot](../../atl/reference/ccomobjectroot-class.md)|Este typedef de [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md) templatized no modelo de threads padrão do servidor.|atlcom.h|  
|[CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)|Essa classe fornece métodos para gerenciamento de contagem de referência de objeto de forma para objetos nonaggregated e agregados.|atlcom.h|  
|[CComObjectStack](../Topic/CComObjectStack%20Class.md)|Esta classe cria um objeto COM temporário e ele lhe fornece uma implementação esqueletal de **IUnknown**.|atlcom.h|  
|[CComPolyObject](../../atl/reference/ccompolyobject-class.md)|Essa classe implementa **IUnknown** para um objeto agregado ou nonaggregated.|atlcom.h|  
|[CComPtr](../../atl/reference/ccomptr-class.md)|Uma classe inteligente do ponteiro para gerenciar ponteiros da interface COM.|atlcomcli.h|  
|[CComPtrBase](../../atl/reference/ccomptrbase-class.md)|Essa classe fornece uma base para as classes espertas ponteiro que usam rotinas de memória baseados em COM.|atlcomcli.h|  
|[CComQIPtr](../../atl/reference/ccomqiptr-class.md)|Uma classe inteligente do ponteiro para gerenciar ponteiros da interface COM.|atlcomcli.h|  
|[CComQIPtrElementTraits](../Topic/CComQIPtrElementTraits%20Class.md)|Essa classe fornece métodos estáticos, funções, e typedefs úteis para criar interfaces COM coleções de ponteiros.|atlcoll.h|  
|[CComSafeArray](../Topic/CComSafeArray%20Class.md)|Essa classe é um wrapper para a estrutura de `SAFEARRAY Data Type` .|atlsafe.h|  
|[CComSafeArrayBound](../../atl/reference/ccomsafearraybound-class.md)|Essa classe é um wrapper para uma estrutura de `SAFEARRAYBOUND` .|atlsafe.h|  
|[CComSimpleThreadAllocator](../../atl/reference/ccomsimplethreadallocator-class.md)|Essa classe gerencia a seleção da thread para a classe [CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md).|atlbase.h|  
|[CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md)|Essa classe fornece métodos para incrementar e diminuir o valor de uma variável.|atlbase.h|  
|[CComTearOffObject](../../atl/reference/ccomtearoffobject-class.md)|Essa classe implementa uma interface de rasgo \- fora.|atlcom.h|  
|[CComUnkArray](../../atl/reference/ccomunkarray-class.md)|Esta classe armazena ponteiros de **IUnknown** e destina\-se a ser usada como um parâmetro para a classe de modelo de [IConnectionPointImpl](../Topic/IConnectionPointImpl%20Class.md) .|atlcom.h|  
|[CComVariant](../../atl/reference/ccomvariant-class.md)|Essa classe envolve o tipo VARIANTE, fornecendo um membro que indica o tipo de dados armazenados.|atlcomcli.h|  
|[CContainedWindowT](../Topic/CContainedWindowT%20Class.md)|Essa classe implementa uma janela contida dentro de outro objeto.|atlwin.h|  
|[CCRTAllocator](../../atl/reference/ccrtallocator-class.md)|Essa classe fornece métodos para gerenciar a memória usando rotinas de memória de CRT.|atlcore.h|  
|[CCRTHeap](../../atl/reference/ccrtheap-class.md)|Essa classe implementa [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md) usando as funções do heap de CRT.|atlmem.h|  
|[CDacl](../../atl/reference/cdacl-class.md)|Essa classe é um wrapper para uma estrutura de DACL \(lista de controle de acesso discricionário\).|atlsecurity.h|  
|[Classe de CDebugReportHook](../../atl/reference/cdebugreporthook-class.md)|Use esta classe para enviar relatórios de depuração para um pipe nomeado.|atlutil.h|  
|[CDefaultCharTraits](../../atl/reference/cdefaultchartraits-class.md)|Essa classe fornece duas funções estáticas para converter caracteres entre maiúsculas e minúsculas.|atlcoll.h|  
|[CDefaultCompareTraits](../../atl/reference/cdefaultcomparetraits-class.md)|Essa classe fornece funções padrão de comparação do elemento.|atlcoll.h|  
|[CDefaultElementTraits](../../atl/reference/cdefaultelementtraits-class.md)|Essa classe fornece métodos padrão e funções para uma classe de coleção.|atlcoll.h|  
|[CDefaultHashTraits](../../atl/reference/cdefaulthashtraits-class.md)|Essa classe fornece estático para uma função de hash calculando valores.|atlcoll.h|  
|[CDialogImpl](../Topic/CDialogImpl%20Class.md)|Essa classe fornece métodos para criar uma caixa de diálogo modal ou sem janela restrita.|atlwin.h|  
|[CDynamicChain](../../atl/reference/cdynamicchain-class.md)|Essa classe fornece métodos que suportam encadeamento dinâmica de mapas de mensagem.|atlwin.h|  
|[CElementTraits](../../atl/reference/celementtraits-class.md)|Essa classe é usada por classes de coleção para fornecer métodos e funções para mover, copiar, comparação, e operações picando.|atlcoll.h|  
|[CElementTraitsBase](../../atl/reference/celementtraitsbase-class.md)|Essa classe fornece a impressão padrão e métodos de mover para uma classe de coleção.|atlcoll.h|  
|[CFirePropNotifyEvent](../Topic/CFirePropNotifyEvent%20Class.md)|Essa classe fornece métodos para notificar o coletor de contêiner sobre alterações de propriedade do controle.|atlctl.h|  
|[CGlobalHeap](../../atl/reference/cglobalheap-class.md)|Essa classe implementa [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md) usando as funções globais do heap do Win32.|atlmem.h|  
|[CHandle](../../atl/reference/chandle-class.md)|Essa classe fornece métodos para criar e usar um objeto de manipular.|atlbase.h|  
|[CHeapPtr](../../atl/reference/cheapptr-class.md)|Uma classe inteligente do ponteiro para gerenciar ponteiros da heap.|atlcore.h|  
|[CHeapPtrBase](../../atl/reference/cheapptrbase-class.md)|Esta forma a classe base para várias classes espertas do ponteiro de heap.|atlcore.h|  
|[Classe de CHeapPtrElementTraits](../../atl/reference/cheapptrelementtraits-class.md)|Essa classe fornece métodos estáticos, funções, e typedefs úteis para criar coleções de ponteiros da heap.|atlcoll.h|  
|[CHeapPtrList](../../atl/reference/cheapptrlist-class.md)|Essa classe fornece os métodos úteis quando construir uma lista de ponteiros da heap.|atlcoll.h|  
|[CImage](../../atl-mfc-shared/reference/cimage-class.md)|Fornece etapas recursos avançados suporte de bitmap, incluindo a capacidade de salvar e carregar imagens em JPEG, GIF em, no BMP, e os formatos de \(PNG\) de formato PNG.|atlimage.h|  
|[CInterfaceArray](../../atl/reference/cinterfacearray-class.md)|Essa classe fornece os métodos úteis quando construir uma matriz de ponteiros da interface COM.|atlcoll.h|  
|[CInterfaceList](../Topic/CInterfaceList%20Class.md)|Essa classe fornece os métodos úteis quando construir uma lista de ponteiros da interface COM.|atlcoll.h|  
|[CLocalHeap](../../atl/reference/clocalheap-class.md)|Essa classe implementa [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md) usando as funções local do heap do Win32.|atlmem.h|  
|[CMessageMap](../../atl/reference/cmessagemap-class.md)|Esta classe permite que os mapeamentos da mensagem de um objeto sejam acessados por outro objeto.|atlwin.h|  
|[Classe de CNonStatelessWorker](../Topic/CNonStatelessWorker%20Class.md)|Recebe solicitações de um pool de segmentos e passá\-las sobre a um objeto de trabalho que é criado e destruído em cada solicitação.|atlutil.h|  
|[Classe de CNoWorkerThread](../../atl/reference/cnoworkerthread-class.md)|Use esta classe como o argumento para as classes de cache do modelo de `MonitorClass` se você desejar desativar a manutenção dinâmico do cache.|atlutil.h|  
|[Classe de CPathT](../../atl/reference/cpatht-class.md)|Esta classe representa um caminho.|atlpath.h|  
|[CPrimitiveElementTraits](../../atl/reference/cprimitiveelementtraits-class.md)|Essa classe fornece métodos padrão e funções para uma classe de coleção composta de tipos de dados primitivos.|atlcoll.h|  
|[CPrivateObjectSecurityDesc](../Topic/CPrivateObjectSecurityDesc%20Class.md)|Esta classe representa um objeto de descritor de segurança particular do objeto.|atlsecurity.h|  
|[CRBMap](../../atl/reference/crbmap-class.md)|Esta classe representa uma estrutura de mapeamento, usando uma árvore binária Vermelho\- Preta.|atlcoll.h|  
|[CRBMultiMap](../../atl/reference/crbmultimap-class.md)|Esta classe representa uma estrutura de mapeamento que permite que cada chave está associada com mais de um valor, usando uma árvore binária Vermelho\- Preta.|atlcoll.h|  
|[CRBTree](../../atl/reference/crbtree-class.md)|Essa classe fornece métodos para criar e utilizar uma árvore Vermelho\- Preta.|atlcoll.h|  
|[CRegKey](../../atl/reference/cregkey-class.md)|Essa classe fornece métodos para manipular as entradas no Registro do sistema.|atlbase.h|  
|[CRTThreadTraits](../Topic/CRTThreadTraits%20Class.md)|Essa classe fornece a função de criação para um segmento de CRT.  Use esta classe se o segmento irá usar funções de CRT.|atlbase.h|  
|[CSacl](../Topic/CSacl%20Class.md)|Essa classe é um wrapper para uma estrutura de SACL \(lista de controle de acesso do sistema\).|atlsecurity.h|  
|[CSecurityAttributes](../../atl/reference/csecurityattributes-class.md)|Essa classe é um wrapper melhor para a estrutura de **SECURITY\_ATTRIBUTES** .|atlsecurity.h|  
|[CSecurityDesc](../../atl/reference/csecuritydesc-class.md)|Essa classe é um wrapper para a estrutura de **SECURITY\_DESCRIPTOR** .|atlsecurity.h|  
|[CSid](../../atl/reference/csid-class.md)|Essa classe é um wrapper para uma estrutura de `SID` \(identificador de segurança\).|atlsecurity.h|  
|[CSimpleArray](../../atl/reference/csimplearray-class.md)|Essa classe fornece métodos para gerenciar uma matriz simples.|atlsimpcoll.h|  
|[CSimpleArrayEqualHelper](../../atl/reference/csimplearrayequalhelper-class.md)|Essa classe é um auxiliar para a classe de [CSimpleArray](../../atl/reference/csimplearray-class.md) .|atlsimpcoll.h|  
|[CSimpleArrayEqualHelperFalse](../Topic/CSimpleArrayEqualHelperFalse%20Class.md)|Essa classe é um auxiliar para a classe de [CSimpleArray](../../atl/reference/csimplearray-class.md) .|atlsimpcoll.h|  
|[CSimpleDialog](../../atl/reference/csimpledialog-class.md)|Essa classe implementa uma caixa de diálogo modal básica.|atlwin.h|  
|[CSimpleMap](../../atl/reference/csimplemap-class.md)|Essa classe fornece suporte para uma matriz simples de mapeamento.|atlsimpcoll.h|  
|[CSimpleMapEqualHelper](../../atl/reference/csimplemapequalhelper-class.md)|Essa classe é um auxiliar para a classe de [CSimpleMap](../../atl/reference/csimplemap-class.md) .|atlsimpcoll.h|  
|[CSimpleMapEqualHelperFalse](../../atl/reference/csimplemapequalhelperfalse-class.md)|Essa classe é um auxiliar para a classe de [CSimpleMap](../../atl/reference/csimplemap-class.md) .|atlsimpcoll.h|  
|[CSnapInItemImpl](../../atl/reference/csnapinitemimpl-class.md)|Essa classe fornece métodos para implementar um objeto do snap\-in.|atlsnap.h|  
|[CSnapInPropertyPageImpl](../../atl/reference/csnapinpropertypageimpl-class.md)|Essa classe fornece métodos para implementar um objeto da página de propriedades do snap\-in.|atlsnap.h|  
|[CStockPropImpl](../../atl/reference/cstockpropimpl-class.md)|Essa classe fornece métodos para valores de propriedade conservados em estoque de suporte.|atlctl.h|  
|[CStringElementTraits](../../atl/reference/cstringelementtraits-class.md)|Essa classe fornece as funções estáticas usadas pelas classes de coleção que armazenam objetos de `CString` .|cstringt.h|  
|[CStringElementTraitsI](../../atl/reference/cstringelementtraitsi-class.md)|Essa classe fornece as funções estáticas relacionadas às cadeias de caracteres armazenadas em objetos de classe de coleção.  É semelhante a [CStringElementTraits](../../atl/reference/cstringelementtraits-class.md), mas realiza comparações não diferencia maiúsculas de minúsculas.|atlcoll.h|  
|[CStringRefElementTraits](../../atl/reference/cstringrefelementtraits-class.md)|Essa classe fornece as funções estáticas relacionadas às cadeias de caracteres armazenadas em objetos de classe de coleção.  Os objetos de cadeia de caracteres são tratados como referências.|atlcoll.h|  
|[Classe de CThreadPool](../Topic/CThreadPool%20Class.md)|Essa classe fornece um pool de segmentos de trabalho que processam uma fila de itens de trabalho.|atlutil.h|  
|[CTokenGroups](../../atl/reference/ctokengroups-class.md)|Essa classe é um wrapper para a estrutura de **TOKEN\_GROUPS** .|atlsecurity.h|  
|[CTokenPrivileges](../../atl/reference/ctokenprivileges-class.md)|Essa classe é um wrapper para a estrutura de **TOKEN\_PRIVILEGES** .|atlsecurity.h|  
|[Classe de som tipo wave](../../atl/reference/curl-class.md)|Esta classe representa uma URL.  Permite que você manipule cada elemento de URL independentemente de se outro analisando uma cadeia de caracteres existente de URL ou de uma cadeia de caracteres a partir do zero.|atlutil.h|  
|[CW2AEX](../../atl/reference/cw2aex-class.md)|Essa classe é usada por `CT2AEX`macros, `CW2TEX`, `CW2CTEX`, e `CT2CAEX`, e o typedef **CW2A**de conversão de cadeia de caracteres.|atlconv.h|  
|[CW2CWEX](../../atl/reference/cw2cwex-class.md)|Essa classe é usada por macros `CW2CTEX` e `CT2CWEX`de conversão de cadeia de caracteres, e o typedef **CW2CW**.|atlconv.h|  
|[CW2WEX](../../atl/reference/cw2wex-class.md)|Essa classe é usada por macros `CW2TEX` e `CT2WEX`de conversão de cadeia de caracteres, e o typedef `CW2W`.|atlconv.h|  
|[CWin32Heap](../../atl/reference/cwin32heap-class.md)|Essa classe implementa [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md) usando as funções de alocação da heap Win32.|atlmem.h|  
|[CWindow](../../atl/reference/cwindow-class.md)|Essa classe fornece métodos para manipular uma janela.|atlwin.h|  
|[CWindowImpl](../Topic/CWindowImpl%20Class.md)|Essa classe fornece métodos para criar ou subclassing uma janela.|atlwin.h|  
|[CWinTraits](../../atl/reference/cwintraits-class.md)|Essa classe fornece um método para padronizar os estilos usados para criar um objeto da janela.|atlwin.h|  
|[CWinTraitsOR](../../atl/reference/cwintraitsor-class.md)|Essa classe fornece um método para padronizar os estilos usados para criar um objeto da janela.|atlwin.h|  
|[CWndClassInfo](../../atl/reference/cwndclassinfo-class.md)|Essa classe fornece métodos para registrar informações de uma classe de janela.|atlwin.h|  
|[Classe de CWorkerThread](../Topic/CWorkerThread%20Class.md)|Esta classe cria um segmento de trabalho existente, ou use espera em um ou vários identificadores de objetos kernel, e executa uma função especificada de cliente quando uma das alças é sinalizado.|atlutil.h|  
|[IAtlAutoThreadModule](../../atl/reference/iatlautothreadmodule-class.md)|Esta classe representa uma interface para um método de `CreateInstance` .|atlbase.h|  
|[IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md)|Esta classe representa a interface para um gerenciador de memória.|atlmem.h|  
|[IAxWinAmbientDispatch](../../atl/reference/iaxwinambientdispatch-interface.md)|Essa interface fornece métodos para especificar características de controle ou recipiente hospedado.|atlbase.h, ATLIFace.h|  
|[IAxWinAmbientDispatchEx](../../atl/reference/iaxwinambientdispatchex-interface.md)|Essa interface implementa propriedades de ambiente suplementares para um controle hospedado.|atlbase.h, ATLIFace.h|  
|[IAxWinHostWindow](../../atl/reference/iaxwinhostwindow-interface.md)|Essa interface fornece métodos para manipular um controle e seu objeto host.|atlbase.h, ATLIFace.h|  
|[IAxWinHostWindowLic](../../atl/reference/iaxwinhostwindowlic-interface.md)|Essa interface fornece métodos para manipular um controle licenciado e seu objeto host.|atlbase.h, ATLIFace.h|  
|[ICollectionOnSTLImpl](../../atl/reference/icollectiononstlimpl-class.md)|Essa classe fornece os métodos usados por uma classe de coleção.|atlcom.h|  
|[IConnectionPointContainerImpl](../Topic/IConnectionPointContainerImpl%20Class.md)|Essa classe implementa um contêiner de ponto de conexão para gerenciar uma coleção de objetos de [IConnectionPointImpl](../Topic/IConnectionPointImpl%20Class.md) .|atlcom.h|  
|[IConnectionPointImpl](../Topic/IConnectionPointImpl%20Class.md)|Essa classe implementa um ponto de conexão.|atlcom.h|  
|[IDataObjectImpl](../../atl/reference/idataobjectimpl-class.md)|Essa classe fornece métodos para oferecer suporte a transferência de dados uniforme e gerenciar conexões.|atlctl.h|  
|[IDispatchImpl](../../atl/reference/idispatchimpl-class.md)|Essa classe fornece uma implementação padrão para a parte de `IDispatch` de uma interface dupla.|atlcom.h|  
|[IDispEventImpl](../../atl/reference/idispeventimpl-class.md)|Essa classe fornece implementações dos métodos de `IDispatch` .|atlcom.h|  
|[IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md)|Essa classe fornece implementações dos métodos de `IDispatch` , sem obter informações sobre o tipo de uma biblioteca de tipo.|atlcom.h|  
|[IDocHostUIHandlerDispatch](../Topic/IDocHostUIHandlerDispatch%20Interface.md)|Uma interface a Microsoft HTML que analisa e que processa o mecanismo.|atlbase.h, ATLIFace.h|  
|[IEnumOnSTLImpl](../../atl/reference/ienumonstlimpl-class.md)|Esta classe define uma interface de enumerador com base em uma coleção de STL.|atlcom.h|  
|[IObjectSafetyImpl](../../atl/reference/iobjectsafetyimpl-class.md)|Essa classe fornece uma implementação padrão de interface de `IObjectSafety` para permitir que um cliente recupere e definir níveis de segurança de um objeto.|atlctl.h|  
|[IObjectWithSiteImpl](../../atl/reference/iobjectwithsiteimpl-class.md)|Essa classe fornece métodos permitindo que um objeto se comunicar com seu site.|atlcom.h|  
|[IOleControlImpl](../../atl/reference/iolecontrolimpl-class.md)|Essa classe fornece uma implementação padrão de interface de **IOleControl** e implementa **IUnknown**.|atlctl.h|  
|[IOleInPlaceActiveObjectImpl](../../atl/reference/ioleinplaceactiveobjectimpl-class.md)|Essa classe fornece métodos para ajudar a comunicação entre um controle no lugar e o contêiner.|atlctl.h|  
|[IOleInPlaceObjectWindowlessImpl](../../atl/reference/ioleinplaceobjectwindowlessimpl-class.md)|Essa classe implementa **IUnknown** e fornece métodos que permitem que um controle sem janelas para receber mensagens de janela e para participar de operações de arrastar e soltar.|atlctl.h|  
|[IOleObjectImpl](../../atl/reference/ioleobjectimpl-class.md)|Essa classe implementa **IUnknown** e é a interface principal através de um contêiner que se comunica com um controle.|atlctl.h|  
|[IPerPropertyBrowsingImpl](../Topic/IPerPropertyBrowsingImpl%20Class.md)|Essa classe implementa **IUnknown** e permite que um cliente acessar informações nas páginas de propriedades de um objeto.|atlctl.h|  
|[IPersistPropertyBagImpl](../../atl/reference/ipersistpropertybagimpl-class.md)|Essa classe implementa **IUnknown** e permite que um objeto salvar suas propriedades para um saco cliente fornecido da propriedade.|atlcom.h|  
|[IPersistStorageImpl](../../atl/reference/ipersiststorageimpl-class.md)|Essa classe implementa a interface de [IPersistStorage](http://msdn.microsoft.com/library/windows/desktop/ms679731) .|atlcom.h|  
|[IPersistStreamInitImpl](../../atl/reference/ipersiststreaminitimpl-class.md)|Essa classe implementa **IUnknown** e fornece uma implementação padrão de interface de [IPersistStreamInit](http://msdn.microsoft.com/library/windows/desktop/ms682273) .|atlcom.h|  
|[IPointerInactiveImpl](../../atl/reference/ipointerinactiveimpl-class.md)|Essa classe implementa **IUnknown** e métodos de interface de [IPointerInactive](http://msdn.microsoft.com/library/windows/desktop/ms693712) .|atlctl.h|  
|[IPropertyNotifySinkCP](../../atl/reference/ipropertynotifysinkcp-class.md)|Essa classe expõe a interface de [IPropertyNotifySink](http://msdn.microsoft.com/library/windows/desktop/ms692638) como uma interface de saída em um objeto ajustável.|atlctl.h|  
|[IPropertyPage2Impl](../../atl/reference/ipropertypage2impl-class.md)|Essa classe implementa **IUnknown** e herda a implementação padrão de [IPropertyPageImpl](../../atl/reference/ipropertypageimpl-class.md).|atlctl.h|  
|[IPropertyPageImpl](../../atl/reference/ipropertypageimpl-class.md)|Essa classe implementa **IUnknown** e fornece uma implementação padrão de interface de [IPropertyPage](http://msdn.microsoft.com/library/windows/desktop/ms691246) .|atlctl.h|  
|[IProvideClassInfo2Impl](../../atl/reference/iprovideclassinfo2impl-class.md)|Essa classe fornece uma implementação padrão dos métodos de [IProvideClassInfo](http://msdn.microsoft.com/library/windows/desktop/ms687303) e de [IProvideClassInfo2](http://msdn.microsoft.com/library/windows/desktop/ms693764) .|atlcom.h|  
|[IQuickActivateImpl](../../atl/reference/iquickactivateimpl-class.md)|Essa classe combina a inicialização do controle de recipiente em uma única chamada.|atlctl.h|  
|[IRunnableObjectImpl](../../atl/reference/irunnableobjectimpl-class.md)|Essa classe implementa **IUnknown** e fornece uma implementação padrão de interface de [IRunnableObject](http://msdn.microsoft.com/library/windows/desktop/ms692783) .|atlctl.h|  
|[IServiceProviderImpl](../../atl/reference/iserviceproviderimpl-class.md)|Essa classe fornece uma implementação padrão de interface de `IServiceProvider` .|atlcom.h|  
|[ISpecifyPropertyPagesImpl](../Topic/ISpecifyPropertyPagesImpl%20Class.md)|Essa classe implementa **IUnknown** e fornece uma implementação padrão de interface de [ISpecifyPropertyPages](http://msdn.microsoft.com/library/windows/desktop/ms695217) .|atlcom.h|  
|[ISupportErrorInfoImpl](../../atl/reference/isupporterrorinfoimpl-class.md)|Essa classe fornece uma implementação padrão de interface de `ISupportErrorInfo Interface` e pode ser usada quando apenas uma única interface gera erros em um objeto.|atlcom.h|  
|[Interface de IThreadPoolConfig](../../atl/reference/ithreadpoolconfig-interface.md)|Essa interface fornece métodos para configurar um pool de segmentos.|atlutil.h|  
|[IViewObjectExImpl](../../atl/reference/iviewobjecteximpl-class.md)|Essa classe implementa **IUnknown** e fornece implementações padrão das interfaces de [IViewObject](http://msdn.microsoft.com/library/windows/desktop/ms680763), de [IViewObject2](http://msdn.microsoft.com/library/windows/desktop/ms691318), e de [IViewObjectEx](http://msdn.microsoft.com/library/windows/desktop/ms682375) .|atlctl.h|  
|[Interface de IWorkerThreadClient](../Topic/IWorkerThreadClient%20Interface.md)|`IWorkerThreadClient` é a interface implementada por clientes da classe de [CWorkerThread](../Topic/CWorkerThread%20Class.md) .|atlutil.h|  
|[\_U\_MENUorID](../../atl/reference/u-menuorid-class.md)|Essa classe fornece os wrappers para **CreateWindow** e **CreateWindowEx**.|atlwin.h|  
|[\_U\_RECT](../../atl/reference/u-rect-class.md)|Essa classe do adaptador do argumento permite ponteiros ou referências de `RECT` a ser passados para uma função que é implementada em termos de ponteiros.|atlwin.h|  
|[\_U\_STRINGorID](../../atl/reference/u-stringorid-class.md)|Essa classe do adaptador do argumento permite nomes de recurso \(`LPCTSTR`s\) ou IDs de recurso \(**UINT**s\) a serem passados para uma função sem exigir o chamador converter a identificação a uma cadeia de caracteres usando a macro de **MAKEINTRESOURCE** .|atlwin.h|  
|[Win32ThreadTraits](../Topic/Win32ThreadTraits%20Class.md)|Essa classe fornece a função de criação para um segmento do Windows.  Use esta classe se o segmento não usará funções de CRT.|atlbase.h|  
  
## Consulte também  
 [Componentes da área de trabalho COM ATL](../../atl/atl-com-desktop-components.md)   
 [Funções](../../atl/reference/atl-functions.md)   
 [Variáveis globais](../Topic/ATL%20Global%20Variables.md)   
 [Estruturas](../../atl/reference/atl-structures.md)   
 [Typedefs](../../atl/reference/atl-typedefs.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)