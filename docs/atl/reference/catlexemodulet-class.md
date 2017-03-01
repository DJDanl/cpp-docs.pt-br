---
title: Classe CAtlExeModuleT | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL::CAtlExeModuleT<T>
- CAtlExeModuleT
- ATL.CAtlExeModuleT<T>
- ATL::CAtlExeModuleT
- ATL.CAtlExeModuleT
dev_langs:
- C++
helpviewer_keywords:
- CAtlExeModuleT class
ms.assetid: 82245f3d-91d4-44fa-aa86-7cc7fbd758d9
caps.latest.revision: 21
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
ms.openlocfilehash: 24ee6c4dfb13c31377bdd7d4f57a92d4f11ad4b8
ms.lasthandoff: 02/25/2017

---
# <a name="catlexemodulet-class"></a>Classe CAtlExeModuleT
Essa classe representa o módulo para um aplicativo.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T>  
class ATL_NO_VTABLE CAtlExeModuleT : public CAtlModuleT<T>
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Sua classe derivada de `CAtlExeModuleT`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAtlExeModuleT::CAtlExeModuleT](#catlexemodulet)|O construtor.|  
|[CAtlExeModuleT:: ~ CAtlExeModuleT](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAtlExeModuleT::InitializeCom](#initializecom)|Inicializa COM.|  
|[CAtlExeModuleT::ParseCommandLine](#parsecommandline)|Analisa a linha de comando e executa o registro se necessário.|  
|[CAtlExeModuleT::PostMessageLoop](#postmessageloop)|Esse método é chamado imediatamente depois que o loop de mensagem é encerrado.|  
|[CAtlExeModuleT::PreMessageLoop](#premessageloop)|Este método é chamado imediatamente antes de entrar no loop de mensagem.|  
|[CAtlExeModuleT::RegisterClassObjects](#registerclassobjects)|Registra o objeto de classe.|  
|[CAtlExeModuleT::RevokeClassObjects](#revokeclassobjects)|Revoga o objeto de classe.|  
|[CAtlExeModuleT::Run](#run)|Esse método executa o código no módulo EXE para inicializar, executar o loop de mensagem e limpar.|  
|[CAtlExeModuleT::RunMessageLoop](#runmessageloop)|Esse método executa o loop de mensagem.|  
|[CAtlExeModuleT::UninitializeCom](#uninitializecom)|Cancela a inicialização de COM.|  
|[CAtlExeModuleT::Unlock](#unlock)|Contagem de bloqueios do módulo diminui.|  
|[CAtlExeModuleT::WinMain](#winmain)|Este método implementa o código necessário para executar um executável.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAtlExeModuleT::m_bDelayShutdown](#m_bdelayshutdown)|Um sinalizador que indica que deve haver um atraso desligando o módulo.|  
|[CAtlExeModuleT::m_dwPause](#m_dwpause)|Um valor de pausar usado para garantir que todos os objetos são liberados antes do desligamento.|  
|[CAtlExeModuleT::m_dwTimeOut](#m_dwtimeout)|Um valor de tempo limite usado para atrasar o descarregamento do módulo.|  
  
## <a name="remarks"></a>Comentários  
 `CAtlExeModuleT`representa o módulo para um aplicativo (EXE) e contém código que suporta criando um EXE, processamento de linha de comando, registrar objetos da classe, executar o loop de mensagem e limpar ao sair.  
  
 Essa classe foi projetada para melhorar o desempenho quando os objetos no servidor EXE são criados e destruídos continuamente. Após o lançamento, o último objeto COM o EXE aguarda uma duração especificada pelo [CAtlExeModuleT::m_dwTimeOut](#m_dwtimeout) membro de dados. Se não houver nenhuma atividade durante esse período (ou seja, não há objetos são criados), o processo de desligamento é iniciado.  
  
 O [CAtlExeModuleT::m_bDelayShutdown](#m_bdelayshutdown) membro de dados é um sinalizador usado para determinar se o arquivo EXE deve usar o mecanismo definido acima. Se estiver definido como false, o módulo será encerrado imediatamente.  
  
 Para obter mais informações sobre módulos em ATL, consulte [Classes de módulo ATL](../../atl/atl-module-classes.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [_ATL_MODULE](atl-typedefs.md#_atl_module)  

  
 [CAtlModule](../../atl/reference/catlmodule-class.md)  
  
 [CAtlModuleT](../../atl/reference/catlmodulet-class.md)  
  
 `CAtlExeModuleT`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase. h  
  
##  <a name="a-namecatlexemoduleta--catlexemoduletcatlexemodulet"></a><a name="catlexemodulet"></a>CAtlExeModuleT::CAtlExeModuleT  
 O construtor.  
  
```
CAtlExeModuleT() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Se o módulo EXE não pôde ser inicializado, WinMain retornará imediatamente sem processamento adicional.  
  
##  <a name="a-namedtora--catlexemoduletcatlexemodulet"></a><a name="dtor"></a>CAtlExeModuleT:: ~ CAtlExeModuleT  
 O destruidor.  
  
```
~CAtlExeModuleT() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Libera todos os recursos alocados.  
  
##  <a name="a-nameinitializecoma--catlexemoduletinitializecom"></a><a name="initializecom"></a>CAtlExeModuleT::InitializeCom  
 Inicializa COM.  
  
```
static HRESULT InitializeCom() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Esse método é chamado a partir do construtor e pode ser substituído para inicializar COM de maneira diferente da implementação padrão. A implementação padrão ou chama **CoInitializeEx (nulo, COINIT_MULTITHREADED)** ou **CoInitialize(NULL)** dependendo da configuração do projeto.  
  
 Substituir esse método normalmente requer substituindo [CAtlExeModuleT::UninitializeCom](#uninitializecom).  
  
##  <a name="a-namembdelayshutdowna--catlexemoduletmbdelayshutdown"></a><a name="m_bdelayshutdown"></a>CAtlExeModuleT::m_bDelayShutdown  
 Um sinalizador que indica que deve haver um atraso desligando o módulo.  
  
```
bool m_bDelayShutdown;
```  
  
### <a name="remarks"></a>Comentários  
 Consulte o [visão geral de CAtlExeModuleT](../../atl/reference/catlexemodulet-class.md) para obter detalhes.  
  
##  <a name="a-namemdwpausea--catlexemoduletmdwpause"></a><a name="m_dwpause"></a>CAtlExeModuleT::m_dwPause  
 Um valor de pausar usado para garantir que todos os objetos são feitos antes do desligamento.  
  
```
DWORD m_dwPause;
```  
  
### <a name="remarks"></a>Comentários  
 Altere este valor após chamar [CAtlExeModuleT::InitializeCom](#initializecom) para definir o número de milissegundos, usado como o valor de pausa para desligar o servidor. O valor padrão é 1.000 milissegundos.  
  
##  <a name="a-namemdwtimeouta--catlexemoduletmdwtimeout"></a><a name="m_dwtimeout"></a>CAtlExeModuleT::m_dwTimeOut  
 Um valor de tempo limite usado para atrasar o descarregamento do módulo.  
  
```
DWORD m_dwTimeOut;
```  
  
### <a name="remarks"></a>Comentários  
 Altere este valor após chamar [CAtlExeModuleT::InitializeCom](#initializecom) para definir o número de milissegundos, usado como o valor de tempo limite para desligar o servidor. O valor padrão é 5.000 milissegundos. Consulte o [visão geral de CAtlExeModuleT](../../atl/reference/catlexemodulet-class.md) para obter mais detalhes.  
  
##  <a name="a-nameparsecommandlinea--catlexemoduletparsecommandline"></a><a name="parsecommandline"></a>CAtlExeModuleT::ParseCommandLine  
 Analisa a linha de comando e executa o registro se necessário.  
  
```
bool ParseCommandLine(LPCTSTR lpCmdLine, HRESULT* pnRetCode) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpCmdLine`  
 A linha de comando passados para o aplicativo.  
  
 `pnRetCode`  
 O HRESULT correspondente para o registro (se ele ocorreu).  
  
### <a name="return-value"></a>Valor de retorno  
 Retornará true se o aplicativo deve continuar sendo executado, caso contrário, false.  
  
### <a name="remarks"></a>Comentários  
 Esse método é chamado de [CAtlExeModuleT::WinMain](#winmain) e pode ser substituído para lidar com as opções de linha de comando. Verifica a implementação padrão **/RegServer** e **/UnRegServer** argumentos de linha de comando e executa o registro ou cancelamento do registro.  
  
##  <a name="a-namepostmessageloopa--catlexemoduletpostmessageloop"></a><a name="postmessageloop"></a>CAtlExeModuleT::PostMessageLoop  
 Esse método é chamado imediatamente depois que o loop de mensagem é encerrado.  
  
```
HRESULT PostMessageLoop() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Substitui esse método para executar a limpeza de aplicativo personalizado. As chamadas de implementação padrão [CAtlExeModuleT::RevokeClassObjects](#revokeclassobjects).  
  
##  <a name="a-namepremessageloopa--catlexemoduletpremessageloop"></a><a name="premessageloop"></a>CAtlExeModuleT::PreMessageLoop  
 Este método é chamado imediatamente antes de entrar no loop de mensagem.  
  
```
HRESULT PreMessageLoop(int nShowCmd) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nShowCmd`  
 O valor passado como o `nShowCmd` parâmetro WinMain.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Substitua este método para adicionar o código de inicialização personalizada para o aplicativo. A implementação padrão registra os objetos de classe.  
  
##  <a name="a-nameregisterclassobjectsa--catlexemoduletregisterclassobjects"></a><a name="registerclassobjects"></a>CAtlExeModuleT::RegisterClassObjects  
 Registra o objeto de classe OLE para que outros aplicativos possam se conectar a ele.  
  
```
HRESULT RegisterClassObjects(DWORD dwClsContext, DWORD dwFlags) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwClsContext*  
 Especifica o contexto no qual o objeto de classe deve ser executado. Os valores possíveis são CLSCTX_INPROC_SERVER, CLSCTX_INPROC_HANDLER ou CLSCTX_LOCAL_SERVER.  
  
 `dwFlags`  
 Determina os tipos de conexão para o objeto de classe. Os valores possíveis são REGCLS_SINGLEUSE, REGCLS_MULTIPLEUSE ou REGCLS_MULTI_SEPARATE.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK sucesso, S_FALSE se não houver nenhuma classe para registrar ou um erro HRESULT em caso de falha.  
  
##  <a name="a-namerevokeclassobjectsa--catlexemoduletrevokeclassobjects"></a><a name="revokeclassobjects"></a>CAtlExeModuleT::RevokeClassObjects  
 Remove o objeto de classe.  
  
```
HRESULT RevokeClassObjects() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK sucesso, S_FALSE se não houver nenhuma classe para registrar ou um erro HRESULT em caso de falha.  
  
##  <a name="a-nameruna--catlexemoduletrun"></a><a name="run"></a>CAtlExeModuleT::Run  
 Esse método executa o código no módulo EXE para inicializar, executar o loop de mensagem e limpar.  
  
```
HRESULT Run(int nShowCmd = SW_HIDE) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nShowCmd`  
 Especifica como a janela deve ser mostrado. Esse parâmetro pode ser um dos valores discutidos a [WinMain](http://msdn.microsoft.com/library/windows/desktop/ms633559) seção. O padrão é SW_HIDE.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Esse método pode ser substituído. No entanto, na prática é melhor para substituir [CAtlExeModuleT::PreMessageLoop](#premessageloop), [CAtlExeModuleT::RunMessageLoop](#runmessageloop), ou [CAtlExeModuleT::PostMessageLoop](#postmessageloop) em vez disso.  
  
##  <a name="a-namerunmessageloopa--catlexemoduletrunmessageloop"></a><a name="runmessageloop"></a>CAtlExeModuleT::RunMessageLoop  
 Esse método executa o loop de mensagem.  
  
```
void RunMessageLoop() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Esse método pode ser substituído para alterar o comportamento de loop de mensagem.  
  
##  <a name="a-nameuninitializecoma--catlexemoduletuninitializecom"></a><a name="uninitializecom"></a>CAtlExeModuleT::UninitializeCom  
 Cancela a inicialização de COM.  
  
```
static void UninitializeCom() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Por padrão esse método simplesmente chama [CoUninitialize](http://msdn.microsoft.com/library/windows/desktop/ms688715) e é chamado de destruidor. Substitua este método se você substituir [CAtlExeModuleT::InitializeCom](#initializecom).  
  
##  <a name="a-nameunlocka--catlexemoduletunlock"></a><a name="unlock"></a>CAtlExeModuleT::Unlock  
 Contagem de bloqueios do módulo diminui.  
  
```
LONG Unlock() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um valor que pode ser útil para o diagnóstico ou teste.  
  
##  <a name="a-namewinmaina--catlexemoduletwinmain"></a><a name="winmain"></a>CAtlExeModuleT::WinMain  
 Este método implementa o código necessário para executar um executável.  
  
```
int WinMain(int nShowCmd) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nShowCmd`  
 Especifica como a janela deve ser mostrado. Esse parâmetro pode ser um dos valores discutidos a [WinMain](http://msdn.microsoft.com/library/windows/desktop/ms633559) seção.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor de retorno do executável.  
  
### <a name="remarks"></a>Comentários  
 Esse método pode ser substituído. Substituir [CAtlExeModuleT::PreMessageLoop](#premessageloop), [CAtlExeModuleT::PostMessageLoop](#postmessageloop), ou [CAtlExeModuleT::RunMessageLoop](#runmessageloop) não fornece flexibilidade suficiente, é possível substituir o `WinMain` função usando esse método.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo de ATLDuck](../../visual-cpp-samples.md)   
 [Classe CAtlModuleT](../../atl/reference/catlmodulet-class.md)   
 [Classe CAtlDllModuleT](../../atl/reference/catldllmodulet-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

