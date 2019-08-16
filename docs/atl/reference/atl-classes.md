---
title: Classes e structs da ATL | Microsoft Docs
ms.date: 05/03/2018
helpviewer_keywords:
- classes [C++], ATL
- ATL, classes
ms.assetid: 7da42e2d-ac84-4506-92bd-502a86d68bdc
ms.openlocfilehash: 2bf13700ada3284b8a32718d21971e89e30e5b76
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69498043"
---
# <a name="atl-classes-and-structs"></a>Classes e structs da ATL

O Active Template Library (ATL) inclui as classes e structs a seguir. Para encontrar uma classe específica por categoria, consulte a [visão geral da classe ATL](../../atl/atl-class-overview.md).

|Classe/estrutura|Descrição|Arquivo de cabeçalho|
|-----------|-----------------|-----------------|
|[ATL_DRAWINFO](../../atl/reference/atl-drawinfo-structure.md)|Contém informações usadas para renderização em vários destinos, como uma impressora, um metarquivo ou um controle ActiveX.|atlctl.h|
|[_AtlCreateWndData](../../atl/reference/atlcreatewnddata-structure.md)|Contém dados de instância de classe em código de janelas na ATL.|atlbase.h|
|[_ATL_BASE_MODULE70](../../atl/reference/atl-base-module70-structure.md)|Usado por qualquer projeto que usa ATL.|atlbase.h|
|[_ATL_COM_MODULE70](../../atl/reference/atl-com-module70-structure.md)|Usado pelo código relacionado ao COM em ATL.| atlbase.h|
|[_ATL_FUNC_INFO](../../atl/reference/atl-func-info-structure.md)|Contém informações de tipo usadas para descrever um método ou uma propriedade em uma dispinterface.|atlcom.h|
|[_ATL_MODULE70](../../atl/reference/atl-module70-structure.md)|Contém dados usados por cada módulo ATL.|atlbase.h|
|[_ATL_WIN_MODULE70](../../atl/reference/atl-win-module70-structure.md)|Usado pelo código de janela na ATL.|atlbase.h|
|[CA2AEX](../../atl/reference/ca2aex-class.md)|Essa classe é usada pelas macros de conversão de cadeia de Caracteres CA2TEX e CT2AEX, e o typedef CA2A.|atlconv.h|
|[CA2CAEX](../../atl/reference/ca2caex-class.md)|Essa classe é usada pelas macros de conversão de cadeia de caracteres CA2CTEX e CT2CAEX, e o typedef CA2CA.|atlconv.h|
|[CA2WEX](../../atl/reference/ca2wex-class.md)|Essa classe é usada pelas macros de conversão de cadeia de Caracteres CA2TEX, CA2CTEX, CT2WEX e CT2CWEX, e o typedef CA2W.|atlconv.h|
|[CAccessToken](../../atl/reference/caccesstoken-class.md)|Essa classe é um wrapper para um token de acesso.|atlsecurity.h|
|[Cacls](../../atl/reference/cacl-class.md)|Essa classe é um wrapper para uma estrutura ACL (lista de controle de acesso).|atlsecurity.h|
|[CAdapt](../../atl/reference/cadapt-class.md)|Este modelo é usado para incluir classes que redefinem o operador address-of para retornar algo diferente do endereço do objeto.|atlcomcli.h|
|[CAtlArray](../../atl/reference/catlarray-class.md)|Essa classe implementa um objeto de matriz.|atlcoll. h|
|[CAtlAutoThreadModule](../../atl/reference/catlautothreadmodule-class.md)|Essa classe implementa um servidor COM de modelo de apartamento com pool de threads.|atlbase.h|
|[CAtlAutoThreadModuleT](../../atl/reference/catlautothreadmodulet-class.md)|Essa classe fornece métodos para implementar um servidor COM de modelo de apartamento em pool de threads.|atlbase.h|
|[CAtlBaseModule](../../atl/reference/catlbasemodule-class.md)|Essa classe é instanciada em todos os projetos ATL.|atlcore.h|
|[CAtlComModule](../../atl/reference/catlcommodule-class.md)|Essa classe implementa um módulo de servidor COM.|atlbase.h|
|[CAtlDebugInterfacesModule](../../atl/reference/catldebuginterfacesmodule-class.md)|Essa classe fornece suporte para a depuração de interfaces.|atlbase.h|
|[CAtlDllModuleT](../../atl/reference/catldllmodulet-class.md)|Essa classe representa o módulo para uma DLL.|atlbase.h|
|[CAtlException](../../atl/reference/catlexception-class.md)|Essa classe define uma exceção ATL.|atlexcept.h|
|[CAtlExeModuleT](../../atl/reference/catlexemodulet-class.md)|Essa classe representa o módulo para um aplicativo.|atlbase.h|
|[CAtlFile](../../atl/reference/catlfile-class.md)|Essa classe fornece um wrapper fino em relação à API de manipulação de arquivos do Windows.|atlfile.h|
|[CAtlFileMapping](../../atl/reference/catlfilemapping-class.md)|Essa classe representa um arquivo mapeado por memória, adicionando um operador cast aos métodos de [CAtlFileMappingBase](../../atl/reference/catlfilemappingbase-class.md).|atlfile.h|
|[CAtlFileMappingBase](../../atl/reference/catlfilemappingbase-class.md)|Essa classe representa um arquivo mapeado por memória.|atlfile.h|
|[CAtlList](../../atl/reference/catllist-class.md)|Essa classe fornece métodos para criar e gerenciar um objeto de lista.|atlcoll. h|
|[CAtlMap](../../atl/reference/catlmap-class.md)|Essa classe fornece métodos para criar e gerenciar um objeto de mapa.|atlcoll. h|
|[CAtlModule](../../atl/reference/catlmodule-class.md)|Essa classe fornece métodos usados por várias classes de módulo ATL.|atlbase.h|
|[CAtlModuleT](../../atl/reference/catlmodulet-class.md)|Essa classe implementa um módulo ATL.|atlbase.h|
|[CAtlPreviewCtrlImpl](../../atl/reference/catlpreviewctrlimpl-class.md)|Essa classe é uma implementação de ATL de uma janela que é colocada em uma janela de host fornecida pelo shell para visualização avançada.|atlpreviewctrlimpl.h|
|[CAtlServiceModuleT](../../atl/reference/catlservicemodulet-class.md)|Essa classe implementa um serviço do.|atlbase.h|
|[CAtlTemporaryFile](../../atl/reference/catltemporaryfile-class.md)|Essa classe fornece métodos para a criação e o uso de um arquivo temporário.|atlfile.h|
|[CAtlTransactionManager](../../atl/reference/catltransactionmanager-class.md)|Essa classe fornece um wrapper para funções de KTM (kernel Transaction Manager).|atltransactionmanager.h|
|[CAtlWinModule](../../atl/reference/catlwinmodule-class.md)|Essa classe fornece suporte para componentes da janela ATL.|atlbase.h|
|[CAutoPtr](../../atl/reference/cautoptr-class.md)|Essa classe representa um objeto de ponteiro inteligente.|atlbase.h|
|[CAutoPtrArray](../../atl/reference/cautoptrarray-class.md)|Essa classe fornece métodos úteis ao construir uma matriz de ponteiros inteligentes.|atlbase.h|
|[CAutoPtrElementTraits](../../atl/reference/cautoptrelementtraits-class.md)|Essa classe fornece métodos, funções estáticas e TYPEDEFs úteis ao criar coleções de apontadores inteligentes.|atlcoll. h|
|[CAutoPtrList](../../atl/reference/cautoptrlist-class.md)|Essa classe fornece métodos úteis ao construir uma lista de ponteiros inteligentes.|atlcoll. h|
|[CAutoVectorPtr](../../atl/reference/cautovectorptr-class.md)|Essa classe representa um objeto de ponteiro inteligente usando operadores New e Delete de vetor.|atlbase.h|
|[CAutoVectorPtrElementTraits](../../atl/reference/cautovectorptrelementtraits-class.md)|Essa classe fornece métodos, funções estáticas e TYPEDEFs úteis ao criar coleções de apontadores inteligentes usando operadores New e Delete de vetor.|atlcoll. h|
|[CAxDialogImpl](../../atl/reference/caxdialogimpl-class.md)|Essa classe implementa uma caixa de diálogo (modal ou sem janela restrita) que hospeda controles ActiveX.|atlwin. h|
|[CAxWindow](../../atl/reference/caxwindow-class.md)|Essa classe fornece métodos para manipular uma janela que hospeda um controle ActiveX.|atlwin. h|
|[CAxWindow2T](../../atl/reference/caxwindow2t-class.md)|Essa classe fornece métodos para manipular uma janela que hospeda um controle ActiveX e também tem suporte para hospedar controles ActiveX licenciados.|atlwin. h|
|[CBindStatusCallback](../../atl/reference/cbindstatuscallback-class.md)|Essa classe implementa a `IBindStatusCallback` interface.|atlctl.h|
|[CComAggObject](../../atl/reference/ccomaggobject-class.md)|Essa classe implementa [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) para um objeto agregado.|atlcom.h|
|[CComAllocator](../../atl/reference/ccomallocator-class.md)|Essa classe fornece métodos para gerenciar a memória usando rotinas de memória COM.|atlbase.h|
|[CComApartment](../../atl/reference/ccomapartment-class.md)|Essa classe fornece suporte para gerenciar um apartamento em um módulo EXE de pool de threads.|atlbase.h|
|[CComAutoCriticalSection](../../atl/reference/ccomautocriticalsection-class.md)|Essa classe fornece métodos para obter e liberar a propriedade de um objeto de seção crítica.|atlcore.h|
|[CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md)|A partir do ATL 7,0 `CComAutoThreadModule` , é obsoleto: consulte [módulos da ATL](../../atl/atl-module-classes.md) para obter mais detalhes.|atlbase.h|
|[CComBSTR](../../atl/reference/ccombstr-class.md)|Essa classe é um wrapper para BSTRs.|atlbase.h|
|[CComCachedTearOffObject](../../atl/reference/ccomcachedtearoffobject-class.md)|Essa classe implementa [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) para uma interface de divisão.|atlcom.h|
|[CComClassFactory](../../atl/reference/ccomclassfactory-class.md)|Essa classe implementa a interface [IClassFactory](/windows/win32/api/unknwnbase/nn-unknwnbase-iclassfactory) .|atlcom.h|
|[CComClassFactory2](../../atl/reference/ccomclassfactory2-class.md)|Essa classe implementa a interface [IClassFactory2](/windows/win32/api/ocidl/nn-ocidl-iclassfactory2) .|atlcom.h|
|[CComClassFactoryAutoThread](../../atl/reference/ccomclassfactoryautothread-class.md)|Essa classe implementa a interface [IClassFactory](/windows/win32/api/unknwnbase/nn-unknwnbase-iclassfactory) e permite que os objetos sejam criados em vários Apartments.|atlcom.h|
|[CComClassFactorySingleton](../../atl/reference/ccomclassfactorysingleton-class.md)|Essa classe deriva de [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) e usa [CComObjectGlobal](../../atl/reference/ccomobjectglobal-class.md) para construir um único objeto.|atlcom.h|
|[CComCoClass](../../atl/reference/ccomcoclass-class.md)|Essa classe fornece métodos para criar instâncias de uma classe e obter suas propriedades.|atlcom.h|
|[CComCompositeControl](../../atl/reference/ccomcompositecontrol-class.md)|Essa classe fornece os métodos necessários para implementar um controle composto.|atlctl.h|
|[CComContainedObject](../../atl/reference/ccomcontainedobject-class.md)|Essa classe implementa [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) ao delegar para o objeto do `IUnknown`proprietário.|atlcom.h|
|[CComControl](../../atl/reference/ccomcontrol-class.md)|Essa classe fornece métodos para criar e gerenciar controles ATL.|atlctl.h|
|[CComControlBase](../../atl/reference/ccomcontrolbase-class.md)|Essa classe fornece métodos para criar e gerenciar controles ATL.|atlctl.h|
|[CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md)|Essa classe fornece métodos para obter e liberar a propriedade de um objeto de seção crítica.|atlcore.h|
|[CComCritSecLock](../../atl/reference/ccomcritseclock-class.md)|Essa classe fornece métodos para bloquear e desbloquear um objeto de seção crítica.|atlbase.h|
|[CComCurrency](../../atl/reference/ccomcurrency-class.md)|Essa classe tem métodos e operadores para criar e gerenciar um objeto de moeda.|atlcur.h|
|[CComDynamicUnkArray](../../atl/reference/ccomdynamicunkarray-class.md)|Essa classe armazena uma matriz de `IUnknown` ponteiros.|atlcom.h|
|[CComEnum](../../atl/reference/ccomenum-class.md)|Essa classe define um objeto enumerador COM com base em uma matriz.|atlcom.h|
|[CComEnumImpl](../../atl/reference/ccomenumimpl-class.md)|Essa classe fornece a implementação para uma interface de enumerador COM em que os itens que estão sendo enumerados são armazenados em uma matriz.|atlcom.h|
|[CComEnumOnSTL](../../atl/reference/ccomenumonstl-class.md)|Essa classe define um objeto enumerador COM com base C++ em uma coleção de bibliotecas padrão.|atlcom.h|
|[CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md)|Essa classe fornece os mesmos métodos que [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md) , mas não fornece uma seção crítica.|atlcore.h|
|[CComGITPtr](../../atl/reference/ccomgitptr-class.md)|Essa classe fornece métodos para lidar com ponteiros de interface e com a tabela de interface global (GIT).|atlbase.h|
|[CComHeap](../../atl/reference/ccomheap-class.md)|Essa classe implementa [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md) usando as funções de alocação de memória com.|ATLComMem.h|
|[CComHeapPtr](../../atl/reference/ccomheapptr-class.md)|Uma classe de ponteiro inteligente para gerenciar ponteiros de heap.|atlbase.h|
|[CComModule](../../atl/reference/ccommodule-class.md)|A partir do ATL 7,0 `CComModule` , é obsoleto: consulte [módulos da ATL](../../atl/atl-module-classes.md) para obter mais detalhes.|atlbase.h|
|[CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md)|Essa classe fornece métodos thread-safe para incrementar e decrementar o valor de uma variável.|atlbase.h|
|[CComMultiThreadModelNoCS](../../atl/reference/ccommultithreadmodelnocs-class.md)|Essa classe fornece métodos thread-safe para incrementar e decrementar o valor de uma variável, sem bloqueio de seção crítica ou funcionalidade de desbloqueio.|atlbase.h|
|[CComObject](../../atl/reference/ccomobject-class.md)|Essa classe implementa `IUnknown` para um objeto não agregado.|atlcom.h|
|[CComObjectGlobal](../../atl/reference/ccomobjectglobal-class.md)|Essa classe gerencia uma contagem de referência no módulo que contém `Base` o objeto.|atlcom.h|
|[CComObjectNoLock](../../atl/reference/ccomobjectnolock-class.md)|Essa classe implementa `IUnknown` para um objeto não agregado, mas não incrementa a contagem de bloqueios do módulo no construtor.|atlcom.h|
|[CComObjectRoot](../../atl/reference/ccomobjectroot-class.md)|Este typedef de [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md) é modelos no modelo de Threading padrão do servidor.|atlcom.h|
|[CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)|Essa classe fornece métodos para manipular o gerenciamento de contagem de referência de objeto para objetos não agregados e agregados.|atlcom.h|
|[CComObjectStack](../../atl/reference/ccomobjectstack-class.md)|Essa classe cria um objeto COM temporário e fornece a ele uma implementação estrutural do `IUnknown`.|atlcom.h|
|[CComPolyObject](../../atl/reference/ccompolyobject-class.md)|Essa classe implementa `IUnknown` para um objeto agregado ou não agregado.|atlcom.h|
|[CComPtr](../../atl/reference/ccomptr-class.md)|Uma classe de ponteiro inteligente para gerenciar ponteiros de interface COM.|atlcomcli.h|
|[CComPtrBase](../../atl/reference/ccomptrbase-class.md)|Essa classe fornece uma base para classes de ponteiro inteligente usando rotinas de memória com base em COM.|atlcomcli.h|
|[CComQIPtr](../../atl/reference/ccomqiptr-class.md)|Uma classe de ponteiro inteligente para gerenciar ponteiros de interface COM.|atlcomcli.h|
|[CComQIPtrElementTraits](../../atl/reference/ccomqiptrelementtraits-class.md)|Essa classe fornece métodos, funções estáticas e TYPEDEFs úteis ao criar coleções de ponteiros de interface COM.|atlcoll. h|
|[CComSafeArray](../../atl/reference/ccomsafearray-class.md)|Essa classe é um wrapper para a `SAFEARRAY Data Type` estrutura.|atlsafe.h|
|[CComSafeArrayBound](../../atl/reference/ccomsafearraybound-class.md)|Essa classe é um wrapper para uma `SAFEARRAYBOUND` estrutura.|atlsafe.h|
|[CComSimpleThreadAllocator](../../atl/reference/ccomsimplethreadallocator-class.md)|Essa classe gerencia a seleção de threads para a classe [CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md).|atlbase.h|
|[CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md)|Essa classe fornece métodos para incrementar e decrementar o valor de uma variável.|atlbase.h|
|[CComTearOffObject](../../atl/reference/ccomtearoffobject-class.md)|Essa classe implementa uma interface de divisão.|atlcom.h|
|[CComUnkArray](../../atl/reference/ccomunkarray-class.md)|Essa classe armazena `IUnknown` ponteiros e é projetada para ser usada como um parâmetro para a classe de modelo [IConnectionPointImpl](../../atl/reference/iconnectionpointimpl-class.md) .|atlcom.h|
|[CComVariant](../../atl/reference/ccomvariant-class.md)|Essa classe encapsula o tipo VARIANT, fornecendo um membro que indica o tipo de dados armazenados.|atlcomcli.h|
|[CContainedWindowT](../../atl/reference/ccontainedwindowt-class.md)|Essa classe implementa uma janela contida em outro objeto.|atlwin. h|
|[CCRTAllocator](../../atl/reference/ccrtallocator-class.md)|Essa classe fornece métodos para gerenciar a memória usando rotinas de memória CRT.|atlcore.h|
|[CCRTHeap](../../atl/reference/ccrtheap-class.md)|Essa classe implementa [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md) usando as funções de heap do CRT.|atlmem.h|
|[CDacl](../../atl/reference/cdacl-class.md)|Essa classe é um wrapper para uma estrutura DACL (lista de controle de acesso condicional).|atlsecurity.h|
|[Classe CDebugReportHook](../../atl/reference/cdebugreporthook-class.md)|Use esta classe para enviar relatórios de depuração a um pipe nomeado.|atlutil.h|
|[CDefaultCharTraits](../../atl/reference/cdefaultchartraits-class.md)|Essa classe fornece duas funções estáticas para converter caracteres entre letras maiúsculas e minúsculas.|atlcoll. h|
|[CDefaultCompareTraits](../../atl/reference/cdefaultcomparetraits-class.md)|Essa classe fornece funções de comparação de elemento padrão.|atlcoll. h|
|[CDefaultElementTraits](../../atl/reference/cdefaultelementtraits-class.md)|Essa classe fornece métodos e funções padrão para uma classe de coleção.|atlcoll. h|
|[CDefaultHashTraits](../../atl/reference/cdefaulthashtraits-class.md)|Essa classe fornece uma função estática para calcular valores de hash.|atlcoll. h|
|[CDialogImpl](../../atl/reference/cdialogimpl-class.md)|Essa classe fornece métodos para criar uma caixa de diálogo modal ou sem janela restrita.|atlwin. h|
|[CDynamicChain](../../atl/reference/cdynamicchain-class.md)|Essa classe fornece métodos que dão suporte ao encadeamento dinâmico de mapas de mensagem.|atlwin. h|
|[CElementTraits](../../atl/reference/celementtraits-class.md)|Essa classe é usada por classes de coleção para fornecer métodos e funções para movimentação, cópia, comparação e operações de hash.|atlcoll. h|
|[CElementTraitsBase](../../atl/reference/celementtraitsbase-class.md)|Essa classe fornece os métodos padrão de copiar e mover para uma classe de coleção.|atlcoll. h|
|[CFirePropNotifyEvent](../../atl/reference/cfirepropnotifyevent-class.md)|Essa classe fornece métodos para notificar o coletor do contêiner sobre as alterações de propriedade de controle.|atlctl.h|
|[CGlobalHeap](../../atl/reference/cglobalheap-class.md)|Essa classe implementa [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md) usando as funções de heap global do Win32.|atlmem.h|
|[CHandle](../../atl/reference/chandle-class.md)|Essa classe fornece métodos para criar e usar um objeto Handle.|atlbase.h|
|[CHeapPtr](../../atl/reference/cheapptr-class.md)|Uma classe de ponteiro inteligente para gerenciar ponteiros de heap.|atlcore.h|
|[CHeapPtrBase](../../atl/reference/cheapptrbase-class.md)|Essa classe constitui a base para várias classes de ponteiro de heap inteligente.|atlcore.h|
|[Classe CHeapPtrElementTraits](../../atl/reference/cheapptrelementtraits-class.md)|Essa classe fornece métodos, funções estáticas e TYPEDEFs úteis ao criar coleções de ponteiros de heap.|atlcoll. h|
|[CHeapPtrList](../../atl/reference/cheapptrlist-class.md)|Essa classe fornece métodos úteis ao construir uma lista de ponteiros de heap.|atlcoll. h|
|[CImage](../../atl-mfc-shared/reference/cimage-class.md)|Fornece suporte a bitmap avançado, incluindo a capacidade de carregar e salvar imagens em formatos JPEG, GIF, BMP e Portable Network Graphics (PNG).|atlimage.h|
|[CInterfaceArray](../../atl/reference/cinterfacearray-class.md)|Essa classe fornece métodos úteis ao construir uma matriz de ponteiros de interface COM.|atlcoll. h|
|[CInterfaceList](../../atl/reference/cinterfacelist-class.md)|Essa classe fornece métodos úteis ao construir uma lista de ponteiros de interface COM.|atlcoll. h|
|[CLocalHeap](../../atl/reference/clocalheap-class.md)|Essa classe implementa [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md) usando as funções de heap local do Win32.|atlmem.h|
|[CMessageMap](../../atl/reference/cmessagemap-class.md)|Essa classe permite que os mapas de mensagens de um objeto sejam acessados por outro objeto.|atlwin. h|
|[Classe CNonStatelessWorker](../../atl/reference/cnonstatelessworker-class.md)|Recebe solicitações de um pool de threads e as passa para um objeto de trabalho que é criado e destruído em cada solicitação.|atlutil.h|
|[Classe CNoWorkerThread](../../atl/reference/cnoworkerthread-class.md)|Use essa classe como o argumento para as `MonitorClass` classes de cache de parâmetro de modelo se você quiser desabilitar a manutenção de cache dinâmico.|atlutil.h|
|[Classe CPathT](../../atl/reference/cpatht-class.md)|Essa classe representa um caminho.|atlpath.h|
|[CPrimitiveElementTraits](../../atl/reference/cprimitiveelementtraits-class.md)|Essa classe fornece métodos e funções padrão para uma classe de coleção composta por tipos de dados primitivos.|atlcoll. h|
|[CPrivateObjectSecurityDesc](../../atl/reference/cprivateobjectsecuritydesc-class.md)|Essa classe representa um objeto de descritor de segurança de objeto privado.|atlsecurity.h|
|[CRBMap](../../atl/reference/crbmap-class.md)|Essa classe representa uma estrutura de mapeamento, usando uma árvore binária vermelha-preta.|atlcoll. h|
|[CRBMultiMap](../../atl/reference/crbmultimap-class.md)|Essa classe representa uma estrutura de mapeamento que permite que cada chave seja associada a mais de um valor, usando uma árvore binária vermelha preta.|atlcoll. h|
|[CRBTree](../../atl/reference/crbtree-class.md)|Essa classe fornece métodos para criar e utilizar uma árvore vermelha preta.|atlcoll. h|
|[CRegKey](../../atl/reference/cregkey-class.md)|Essa classe fornece métodos para manipular entradas no registro do sistema.|atlbase.h|
|[CRTThreadTraits](../../atl/reference/crtthreadtraits-class.md)|Essa classe fornece a função de criação para um thread CRT. Use essa classe se o thread usar funções CRT.|atlbase.h|
|[CSacl](../../atl/reference/csacl-class.md)|Essa classe é um wrapper para uma estrutura SACL (lista de controle de acesso do sistema).|atlsecurity.h|
|[CSecurityAttributes](../../atl/reference/csecurityattributes-class.md)|Essa classe é um wrapper fino para a `SECURITY_ATTRIBUTES` estrutura.|atlsecurity.h|
|[CSecurityDesc](../../atl/reference/csecuritydesc-class.md)|Essa classe é um wrapper para a `SECURITY_DESCRIPTOR` estrutura.|atlsecurity.h|
|[CSid](../../atl/reference/csid-class.md)|Essa classe é um wrapper para uma `SID` estrutura (identificador de segurança).|atlsecurity.h|
|[CSimpleArray](../../atl/reference/csimplearray-class.md)|Essa classe fornece métodos para gerenciar uma matriz simples.|atlsimpcoll.h|
|[CSimpleArrayEqualHelper](../../atl/reference/csimplearrayequalhelper-class.md)|Essa classe é um auxiliar para a classe [CSimpleArray](../../atl/reference/csimplearray-class.md) .|atlsimpcoll.h|
|[CSimpleArrayEqualHelperFalse](../../atl/reference/csimplearrayequalhelperfalse-class.md)|Essa classe é um auxiliar para a classe [CSimpleArray](../../atl/reference/csimplearray-class.md) .|atlsimpcoll.h|
|[CSimpleDialog](../../atl/reference/csimpledialog-class.md)|Essa classe implementa uma caixa de diálogo modal básica.|atlwin. h|
|[CSimpleMap](../../atl/reference/csimplemap-class.md)|Essa classe fornece suporte para uma matriz de mapeamento simples.|atlsimpcoll.h|
|[CSimpleMapEqualHelper](../../atl/reference/csimplemapequalhelper-class.md)|Essa classe é um auxiliar para a classe [CSimpleMap](../../atl/reference/csimplemap-class.md) .|atlsimpcoll.h|
|[CSimpleMapEqualHelperFalse](../../atl/reference/csimplemapequalhelperfalse-class.md)|Essa classe é um auxiliar para a classe [CSimpleMap](../../atl/reference/csimplemap-class.md) .|atlsimpcoll.h|
|[CSnapInItemImpl](../../atl/reference/csnapinitemimpl-class.md)|Essa classe fornece métodos para implementar um objeto de nó de snap-in.|atlsnap.h|
|[CSnapInPropertyPageImpl](../../atl/reference/csnapinpropertypageimpl-class.md)|Essa classe fornece métodos para implementar um objeto de página de propriedades de snap-in.|atlsnap.h|
|[CStockPropImpl](../../atl/reference/cstockpropimpl-class.md)|Essa classe fornece métodos para dar suporte a valores de propriedade de estoque.|atlctl.h|
|[CStringElementTraits](../../atl/reference/cstringelementtraits-class.md)|Essa classe fornece funções estáticas usadas pelas classes de `CString` coleção que armazenam objetos.|cstringt.h|
|[CStringElementTraitsI](../../atl/reference/cstringelementtraitsi-class.md)|Essa classe fornece funções estáticas relacionadas a cadeias de caracteres armazenadas em objetos de classe de coleção. Ele é semelhante a [CStringElementTraits](../../atl/reference/cstringelementtraits-class.md), mas executa comparações que não diferenciam maiúsculas de minúsculas.|atlcoll. h|
|[CStringRefElementTraits](../../atl/reference/cstringrefelementtraits-class.md)|Essa classe fornece funções estáticas relacionadas a cadeias de caracteres armazenadas em objetos de classe de coleção. Os objetos de cadeia de caracteres são tratados como referências.|atlcoll. h|
|[Classe CThreadPool](../../atl/reference/cthreadpool-class.md)|Essa classe fornece um pool de threads de trabalho que processam uma fila de itens de trabalho.|atlutil.h|
|[CTokenGroups](../../atl/reference/ctokengroups-class.md)|Essa classe é um wrapper para a `TOKEN_GROUPS` estrutura.|atlsecurity.h|
|[CTokenPrivileges](../../atl/reference/ctokenprivileges-class.md)|Essa classe é um wrapper para a `TOKEN_PRIVILEGES` estrutura.|atlsecurity.h|
|[Classe CUrl](../../atl/reference/curl-class.md)|Essa classe representa uma URL. Ele permite que você manipule cada elemento da URL independentemente dos outros, se estiver analisando uma cadeia de caracteres de URL existente ou criando uma cadeia de caracteres a partir do zero.|atlutil.h|
|[CW2AEX](../../atl/reference/cw2aex-class.md)|Essa classe é usada pelas macros de conversão de cadeia de caracteres CT2AEX, CW2TEX, CW2CTEX e CT2CAEX, e o typedef CW2A.|atlconv.h|
|[CW2CWEX](../../atl/reference/cw2cwex-class.md)|Essa classe é usada pelas macros de conversão de cadeia de caracteres CW2CTEX e CT2CWEX, e o TypeDef CW2CW.|atlconv.h|
|[CW2WEX](../../atl/reference/cw2wex-class.md)|Essa classe é usada pelas macros de conversão de cadeia de caracteres CW2TEX e CT2WEX, e o typedef CW2W.|atlconv.h|
|[CWin32Heap](../../atl/reference/cwin32heap-class.md)|Essa classe implementa [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md) usando as funções de alocação de heap do Win32.|atlmem.h|
|[CWindow](../../atl/reference/cwindow-class.md)|Essa classe fornece métodos para manipular uma janela.|atlwin. h|
|[CWindowImpl](../../atl/reference/cwindowimpl-class.md)|Essa classe fornece métodos para criação ou subclasse de uma janela.|atlwin. h|
|[CWinTraits](../../atl/reference/cwintraits-class.md)|Essa classe fornece um método para padronizar os estilos usados ao criar um objeto Window.|atlwin. h|
|[CWinTraitsOR](../../atl/reference/cwintraitsor-class.md)|Essa classe fornece um método para padronizar os estilos usados ao criar um objeto Window.|atlwin. h|
|[CWndClassInfo](../../atl/reference/cwndclassinfo-class.md)|Essa classe fornece métodos para registrar informações para uma classe de janela.|atlwin. h|
|[Classe CWorkerThread](../../atl/reference/cworkerthread-class.md)|Essa classe cria um thread de trabalho ou usa um existente, aguarda em um ou mais identificadores de objeto de kernel e executa uma função de cliente especificada quando um dos identificadores é sinalizado.|atlutil.h|
|[IAtlAutoThreadModule](../../atl/reference/iatlautothreadmodule-class.md)|Essa classe representa uma interface para um `CreateInstance` método.|atlbase.h|
|[IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md)|Essa classe representa a interface para um Gerenciador de memória.|atlmem.h|
|[IAxWinAmbientDispatch](../../atl/reference/iaxwinambientdispatch-interface.md)|Essa interface fornece métodos para especificar características do controle ou contêiner hospedado.|atlbase. h, ATLIFace. h|
|[IAxWinAmbientDispatchEx](../../atl/reference/iaxwinambientdispatchex-interface.md)|Essa interface implementa propriedades de ambiente suplementares para um controle hospedado.|atlbase. h, ATLIFace. h|
|[IAxWinHostWindow](../../atl/reference/iaxwinhostwindow-interface.md)|Essa interface fornece métodos para manipular um controle e seu objeto de host.|atlbase. h, ATLIFace. h|
|[IAxWinHostWindowLic](../../atl/reference/iaxwinhostwindowlic-interface.md)|Essa interface fornece métodos para manipular um controle licenciado e seu objeto de host.|atlbase. h, ATLIFace. h|
|[ICollectionOnSTLImpl](../../atl/reference/icollectiononstlimpl-class.md)|Essa classe fornece métodos usados por uma classe de coleção.|atlcom.h|
|[IConnectionPointContainerImpl](../../atl/reference/iconnectionpointcontainerimpl-class.md)|Essa classe implementa um contêiner de ponto de conexão para gerenciar uma coleção de objetos [IConnectionPointImpl](../../atl/reference/iconnectionpointimpl-class.md) .|atlcom.h|
|[IConnectionPointImpl](../../atl/reference/iconnectionpointimpl-class.md)|Essa classe implementa um ponto de conexão.|atlcom.h|
|[IDataObjectImpl](../../atl/reference/idataobjectimpl-class.md)|Essa classe fornece métodos para dar suporte a Transferência de Dados uniformes e gerenciar conexões.|atlctl.h|
|[IDispatchImpl](../../atl/reference/idispatchimpl-class.md)|Essa classe fornece uma implementação padrão para a `IDispatch` parte de uma interface dupla.|atlcom.h|
|[IDispEventImpl](../../atl/reference/idispeventimpl-class.md)|Essa classe fornece implementações dos `IDispatch` métodos.|atlcom.h|
|[IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md)|Essa classe fornece implementações dos `IDispatch` métodos, sem obter informações de tipo de uma biblioteca de tipos.|atlcom.h|
|[IDocHostUIHandlerDispatch](../../atl/reference/idochostuihandlerdispatch-interface.md)|Uma interface para o mecanismo de análise e renderização HTML da Microsoft.|atlbase. h, ATLIFace. h|
|[IEnumOnSTLImpl](../../atl/reference/ienumonstlimpl-class.md)|Essa classe define uma interface de enumerador com C++ base em uma coleção de bibliotecas padrão.|atlcom.h|
|[IObjectSafetyImpl](../../atl/reference/iobjectsafetyimpl-class.md)|Essa classe fornece uma implementação padrão da `IObjectSafety` interface para permitir que um cliente recupere e defina os níveis de segurança de um objeto.|atlctl.h|
|[IObjectWithSiteImpl](../../atl/reference/iobjectwithsiteimpl-class.md)|Essa classe fornece métodos que permitem que um objeto se comunique com seu site.|atlcom.h|
|[IOleControlImpl](../../atl/reference/iolecontrolimpl-class.md)|Essa classe fornece uma implementação padrão da `IOleControl` interface e implementa. `IUnknown`|atlctl.h|
|[IOleInPlaceActiveObjectImpl](../../atl/reference/ioleinplaceactiveobjectimpl-class.md)|Essa classe fornece métodos para auxiliar a comunicação entre um controle in-loco e seu contêiner.|atlctl.h|
|[IOleInPlaceObjectWindowlessImpl](../../atl/reference/ioleinplaceobjectwindowlessimpl-class.md)|Essa classe implementa `IUnknown` e fornece métodos que permitem que um controle sem janela receba mensagens de janela e participe de operações de arrastar e soltar.|atlctl.h|
|[IOleObjectImpl](../../atl/reference/ioleobjectimpl-class.md)|Essa classe implementa `IUnknown` e é a interface principal por meio da qual um contêiner se comunica com um controle.|atlctl.h|
|[IPerPropertyBrowsingImpl](../../atl/reference/iperpropertybrowsingimpl-class.md)|Essa classe implementa `IUnknown` e permite que um cliente acesse as informações nas páginas de propriedades de um objeto.|atlctl.h|
|[IPersistPropertyBagImpl](../../atl/reference/ipersistpropertybagimpl-class.md)|Essa classe implementa `IUnknown` e permite que um objeto salve suas propriedades em um recipiente de propriedades fornecido pelo cliente.|atlcom.h|
|[IPersistStorageImpl](../../atl/reference/ipersiststorageimpl-class.md)|Essa classe implementa a interface [IPersistStorage](/windows/win32/api/objidl/nn-objidl-ipersiststorage) .|atlcom.h|
|[IPersistStreamInitImpl](../../atl/reference/ipersiststreaminitimpl-class.md)|Essa classe implementa `IUnknown` e fornece uma implementação padrão da interface [IPersistStreamInit](/windows/win32/api/ocidl/nn-ocidl-ipersiststreaminit) .|atlcom.h|
|[IPointerInactiveImpl](../../atl/reference/ipointerinactiveimpl-class.md)|Essa classe implementa `IUnknown` e os métodos de interface [IPointerInactive](/windows/win32/api/ocidl/nn-ocidl-ipointerinactive) .|atlctl.h|
|[IPropertyNotifySinkCP](../../atl/reference/ipropertynotifysinkcp-class.md)|Essa classe expõe a interface [IPropertyNotifySink](/windows/win32/api/ocidl/nn-ocidl-ipropertynotifysink) como uma interface de saída em um objeto que pôde ser conectado.|atlctl.h|
|[IPropertyPage2Impl](../../atl/reference/ipropertypage2impl-class.md)|Essa classe implementa `IUnknown` e herda a implementação padrão de [IPropertyPageImpl](../../atl/reference/ipropertypageimpl-class.md).|atlctl.h|
|[IPropertyPageImpl](../../atl/reference/ipropertypageimpl-class.md)|Essa classe implementa `IUnknown` e fornece uma implementação padrão da interface [IPropertyPage](/windows/win32/api/ocidl/nn-ocidl-ipropertypage) .|atlctl.h|
|[IProvideClassInfo2Impl](../../atl/reference/iprovideclassinfo2impl-class.md)|Essa classe fornece uma implementação padrão dos métodos [IProvideClassInfo](/windows/win32/api/ocidl/nn-ocidl-iprovideclassinfo) e [IProvideClassInfo2](/windows/win32/api/ocidl/nn-ocidl-iprovideclassinfo2) .|atlcom.h|
|[IQuickActivateImpl](../../atl/reference/iquickactivateimpl-class.md)|Essa classe combina a inicialização do controle de contêineres em uma única chamada.|atlctl.h|
|[IRunnableObjectImpl](../../atl/reference/irunnableobjectimpl-class.md)|Essa classe implementa `IUnknown` e fornece uma implementação padrão da interface [IRunnableObject](/windows/win32/api/objidl/nn-objidl-irunnableobject) .|atlctl.h|
|[IServiceProviderImpl](../../atl/reference/iserviceproviderimpl-class.md)|Essa classe fornece uma implementação padrão da `IServiceProvider` interface.|atlcom.h|
|[ISpecifyPropertyPagesImpl](../../atl/reference/ispecifypropertypagesimpl-class.md)|Essa classe implementa `IUnknown` e fornece uma implementação padrão da interface [ISpecifyPropertyPages](/windows/win32/api/ocidl/nn-ocidl-ispecifypropertypages) .|atlcom.h|
|[ISupportErrorInfoImpl](../../atl/reference/isupporterrorinfoimpl-class.md)|Essa classe fornece uma implementação padrão da `ISupportErrorInfo Interface` interface e pode ser usada quando apenas uma única interface gera erros em um objeto.|atlcom.h|
|[Interface IThreadPoolConfig](../../atl/reference/ithreadpoolconfig-interface.md)|Essa interface fornece métodos para configurar um pool de threads.|atlutil.h|
|[IViewObjectExImpl](../../atl/reference/iviewobjecteximpl-class.md)|Essa classe implementa `IUnknown` e fornece implementações padrão das interfaces [IViewObject](/windows/win32/api/oleidl/nn-oleidl-iviewobject), [IViewObject2](/windows/win32/api/oleidl/nn-oleidl-iviewobject2)e [IViewObjectEx](/windows/win32/api/ocidl/nn-ocidl-iviewobjectex) .|atlctl.h|
|[Interface IWorkerThreadClient](../../atl/reference/iworkerthreadclient-interface.md)|`IWorkerThreadClient`é a interface implementada por clientes da classe [CWorkerThread](../../atl/reference/cworkerthread-class.md) .|atlutil.h|
|[_U_MENUorID](../../atl/reference/u-menuorid-class.md)|Essa classe fornece wrappers para `CreateWindow` e `CreateWindowEx`.|atlwin. h|
|[_U_RECT](../../atl/reference/u-rect-class.md)|Essa classe de adaptador de argumento `RECT` permite que ponteiros ou referências sejam passados para uma função que é implementada em termos de ponteiros.|atlwin. h|
|[_U_STRINGorID](../../atl/reference/u-stringorid-class.md)|Essa classe de adaptador de argumento permite que nomes de recurso (LPCTSTRs) ou IDs de recurso (UINTs) sejam passados para uma função sem exigir que o chamador converta a ID em uma cadeia de caracteres usando a macro MAKEINTRESOURCE.|atlwin. h|
|[Win32ThreadTraits](../../atl/reference/win32threadtraits-class.md)|Essa classe fornece a função de criação para um thread do Windows. Use essa classe se o thread não usar funções CRT.|atlbase.h|

## <a name="see-also"></a>Consulte também

[Componentes de área de trabalho COM da ATL](../../atl/atl-com-desktop-components.md)<br/>
[Funções](../../atl/reference/atl-functions.md)<br/>
[Variáveis globais](../../atl/reference/atl-global-variables.md)<br/>
[Typedefs](../../atl/reference/atl-typedefs.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
