---
title: Classe CAtlExeModuleT
ms.date: 11/04/2016
f1_keywords:
- CAtlExeModuleT
- ATLBASE/ATL::CAtlExeModuleT
- ATLBASE/ATL::CAtlExeModuleT::CAtlExeModuleT
- ATLBASE/ATL::CAtlExeModuleT::InitializeCom
- ATLBASE/ATL::CAtlExeModuleT::ParseCommandLine
- ATLBASE/ATL::CAtlExeModuleT::PostMessageLoop
- ATLBASE/ATL::CAtlExeModuleT::PreMessageLoop
- ATLBASE/ATL::CAtlExeModuleT::RegisterClassObjects
- ATLBASE/ATL::CAtlExeModuleT::RevokeClassObjects
- ATLBASE/ATL::CAtlExeModuleT::Run
- ATLBASE/ATL::CAtlExeModuleT::RunMessageLoop
- ATLBASE/ATL::CAtlExeModuleT::UninitializeCom
- ATLBASE/ATL::CAtlExeModuleT::Unlock
- ATLBASE/ATL::CAtlExeModuleT::WinMain
- ATLBASE/ATL::CAtlExeModuleT::m_bDelayShutdown
- ATLBASE/ATL::CAtlExeModuleT::m_dwPause
- ATLBASE/ATL::CAtlExeModuleT::m_dwTimeOut
helpviewer_keywords:
- CAtlExeModuleT class
ms.assetid: 82245f3d-91d4-44fa-aa86-7cc7fbd758d9
ms.openlocfilehash: 33edd8f2483bc21ea6cf8b68f80a2501c37d1a40
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81748755"
---
# <a name="catlexemodulet-class"></a>Classe CAtlExeModuleT

Esta classe representa o módulo para uma aplicação.

## <a name="syntax"></a>Sintaxe

```
template <class T>
class ATL_NO_VTABLE CAtlExeModuleT : public CAtlModuleT<T>
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe derivada de `CAtlExeModuleT`.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlExeModuleT::CAtlExeModuleT](#catlexemodulet)|O construtor.|
|[CAtlExeModuleT::~CAtlExeModuleT](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlExeModuleT::InitializeCom](#initializecom)|Inicializa COM.|
|[CAtlExeModuleT::ParsecommandLine](#parsecommandline)|Analisa a linha de comando e realiza o registro, se necessário.|
|[CAtlExeModuleT::PostMessageLoop](#postmessageloop)|Este método é chamado imediatamente após a saída do loop de mensagem.|
|[CAtlExeModuleT::PreMessageLoop](#premessageloop)|Este método é chamado imediatamente antes de entrar no loop de mensagem.|
|[CAtlExeModuleT::RegisterClassObjects](#registerclassobjects)|Registra o objeto da classe.|
|[CAtlExeModuleT::RevokeClassObjects](#revokeclassobjects)|Revoga o objeto da classe.|
|[CAtlExeModuleT::Run](#run)|Este método executa o código no módulo EXE para inicializar, executar o loop de mensagem e limpar.|
|[CAtlExeModuleT::RunMessageLoop](#runmessageloop)|Este método executa o loop de mensagem.|
|[CAtlExeModuleT::UninitializeCom](#uninitializecom)|Uninitializes COM.|
|[CAtlExeModuleT::Unlock](#unlock)|Decreta a contagem de bloqueios do módulo.|
|[CAtlExeModuleT::WinMain](#winmain)|Este método implementa o código necessário para executar um EXE.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlExeModuleT::m_bDelayShutdown](#m_bdelayshutdown)|Uma bandeira indicando que deve haver um atraso para desligar o módulo.|
|[CAtlExeModuleT::m_dwPause](#m_dwpause)|Um valor de pausa usado para garantir que todos os objetos sejam liberados antes do desligamento.|
|[CAtlExeModuleT::m_dwTimeOut](#m_dwtimeout)|Um valor de tempo para o tempo usado para atrasar o descarregamento do módulo.|

## <a name="remarks"></a>Comentários

`CAtlExeModuleT`representa o módulo de um aplicativo (EXE) e contém código que suporta a criação de um EXE, o processamento da linha de comando, o registro de objetos de classe, a execução do loop de mensagem e a limpeza na saída.

Esta classe foi projetada para melhorar o desempenho quando objetos COM no servidor EXE são continuamente criados e destruídos. Depois que o último objeto COM é lançado, o EXE aguarda por uma duração especificada pelo membro de dados [CAtlExeModuleT::m_dwTimeOut.](#m_dwtimeout) Se não houver atividade durante esse período (ou seja, nenhum objeto COM for criado), o processo de desligamento será iniciado.

O membro de dados [CAtlExeModuleT::m_bDelayShutdown](#m_bdelayshutdown) é um sinalizador usado para determinar se o EXE deve usar o mecanismo definido acima. Se for definido como falso, o módulo terminará imediatamente.

Para obter mais informações sobre módulos em ATL, consulte [ATL Module Classes](../../atl/atl-module-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[_ATL_MODULE](atl-typedefs.md#_atl_module)

[Catlmodule](../../atl/reference/catlmodule-class.md)

[Catlmodulet](../../atl/reference/catlmodulet-class.md)

`CAtlExeModuleT`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="catlexemoduletcatlexemodulet"></a><a name="catlexemodulet"></a>CAtlExeModuleT::CAtlExeModuleT

O construtor.

```
CAtlExeModuleT() throw();
```

### <a name="remarks"></a>Comentários

Se o módulo EXE não puder ser inicializado, o WinMain retornará imediatamente sem maior processamento.

## <a name="catlexemoduletcatlexemodulet"></a><a name="dtor"></a>CAtlExeModuleT::~CAtlExeModuleT

O destruidor.

```
~CAtlExeModuleT() throw();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados.

## <a name="catlexemoduletinitializecom"></a><a name="initializecom"></a>CAtlExeModuleT::InitializeCom

Inicializa COM.

```
static HRESULT InitializeCom() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Este método é chamado do construtor e pode ser substituído para inicializar o COM de uma maneira diferente da implementação padrão. A implementação `CoInitializeEx(NULL, COINIT_MULTITHREADED)` padrão `CoInitialize(NULL)` ou chama ou dependendo da configuração do projeto.

Sobrepor este método normalmente requer sobreposição [catlExeModuleT::UninitializeCom](#uninitializecom).

## <a name="catlexemoduletm_bdelayshutdown"></a><a name="m_bdelayshutdown"></a>CAtlExeModuleT::m_bDelayShutdown

Uma bandeira indicando que deve haver um atraso para desligar o módulo.

```
bool m_bDelayShutdown;
```

### <a name="remarks"></a>Comentários

Consulte a visão geral do [CAtlExeModuleT](../../atl/reference/catlexemodulet-class.md) para obter detalhes.

## <a name="catlexemoduletm_dwpause"></a><a name="m_dwpause"></a>CAtlExeModuleT::m_dwPause

Um valor de pausa usado para garantir que todos os objetos se foram antes do desligamento.

```
DWORD m_dwPause;
```

### <a name="remarks"></a>Comentários

Altere esse valor depois de chamar [CAtlExeModuleT::InitializeCom](#initializecom) para definir o número de milissegundos usado como o valor de pausa para desligar o servidor. O valor padrão é de 1000 milissegundos.

## <a name="catlexemoduletm_dwtimeout"></a><a name="m_dwtimeout"></a>CAtlExeModuleT::m_dwTimeOut

Um valor de tempo para o tempo usado para atrasar o descarregamento do módulo.

```
DWORD m_dwTimeOut;
```

### <a name="remarks"></a>Comentários

Altere esse valor depois de chamar [CAtlExeModuleT::InitializeCom](#initializecom) para definir o número de milissegundos usado sustal como o valor de tempo para desligar o servidor. O valor padrão é 5.000 milissegundos. Consulte a visão geral do [CAtlExeModuleT](../../atl/reference/catlexemodulet-class.md) para obter mais detalhes.

## <a name="catlexemoduletparsecommandline"></a><a name="parsecommandline"></a>CAtlExeModuleT::ParsecommandLine

Analisa a linha de comando e realiza o registro, se necessário.

```
bool ParseCommandLine(LPCTSTR lpCmdLine, HRESULT* pnRetCode) throw();
```

### <a name="parameters"></a>Parâmetros

*lpCmdLine*<br/>
A linha de comando passou para o aplicativo.

*pnRetCode*<br/>
O HRESULT corresponde ao registro (se ocorreu).

### <a name="return-value"></a>Valor retornado

Retorne verdadeiro se o aplicativo continuar a ser executado, caso contrário, falso.

### <a name="remarks"></a>Comentários

Este método é chamado de [CAtlExeModuleT::WinMain](#winmain) e pode ser substituído para lidar com switches de linha de comando. A implementação padrão verifica os argumentos da linha de comando **/RegServer** e **/UnRegServer** e realiza o registro ou o descadastramento.

## <a name="catlexemoduletpostmessageloop"></a><a name="postmessageloop"></a>CAtlExeModuleT::PostMessageLoop

Este método é chamado imediatamente após a saída do loop de mensagem.

```
HRESULT PostMessageLoop() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Anular este método para executar a limpeza personalizada do aplicativo. A implementação padrão chama [CAtlExeModuleT::RevokeClassObjects](#revokeclassobjects).

## <a name="catlexemoduletpremessageloop"></a><a name="premessageloop"></a>CAtlExeModuleT::PreMessageLoop

Este método é chamado imediatamente antes de entrar no loop de mensagem.

```
HRESULT PreMessageLoop(int nShowCmd) throw();
```

### <a name="parameters"></a>Parâmetros

*nShowCmd*<br/>
O valor passou como o parâmetro *nShowCmd* no WinMain.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Substituir este método para adicionar código de inicialização personalizado para o aplicativo. A implementação padrão registra os objetos de classe.

## <a name="catlexemoduletregisterclassobjects"></a><a name="registerclassobjects"></a>CAtlExeModuleT::RegisterClassObjects

Registra o objeto de classe com OLE para que outros aplicativos possam se conectar a ele.

```
HRESULT RegisterClassObjects(DWORD dwClsContext, DWORD dwFlags) throw();
```

### <a name="parameters"></a>Parâmetros

*Dwclscontext*<br/>
Especifica o contexto em que o objeto de classe deve ser executado. Os valores possíveis são CLSCTX_INPROC_SERVER, CLSCTX_INPROC_HANDLER ou CLSCTX_LOCAL_SERVER.

*dwFlags*<br/>
Determina os tipos de conexão com o objeto de classe. Os valores possíveis são REGCLS_SINGLEUSE, REGCLS_MULTIPLEUSE ou REGCLS_MULTI_SEPARATE.

### <a name="return-value"></a>Valor retornado

Os retornos S_OK no sucesso, S_FALSE se não houvesse classes para registrar ou um erro HRESULT na falha.

## <a name="catlexemoduletrevokeclassobjects"></a><a name="revokeclassobjects"></a>CAtlExeModuleT::RevokeClassObjects

Remove o objeto de classe.

```
HRESULT RevokeClassObjects() throw();
```

### <a name="return-value"></a>Valor retornado

Os retornos S_OK no sucesso, S_FALSE se não houvesse classes para registrar ou um erro HRESULT na falha.

## <a name="catlexemoduletrun"></a><a name="run"></a>CAtlExeModuleT::Run

Este método executa o código no módulo EXE para inicializar, executar o loop de mensagem e limpar.

```
HRESULT Run(int nShowCmd = SW_HIDE) throw();
```

### <a name="parameters"></a>Parâmetros

*nShowCmd*<br/>
Especifica como a janela deve ser mostrada. Este parâmetro pode ser um dos valores discutidos na seção [WinMain.](/windows/win32/api/winbase/nf-winbase-winmain) Padrão para SW_HIDE.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Este método pode ser substituído. No entanto, na prática, é melhor substituir [CAtlExeModuleT::PreMessageLoop,](#premessageloop) [CAtlExeModuleT::RunMessageLoop](#runmessageloop)ou [CAtlExeModuleT::PostMessageLoop](#postmessageloop) em vez disso.

## <a name="catlexemoduletrunmessageloop"></a><a name="runmessageloop"></a>CAtlExeModuleT::RunMessageLoop

Este método executa o loop de mensagem.

```cpp
void RunMessageLoop() throw();
```

### <a name="remarks"></a>Comentários

Este método pode ser substituído para alterar o comportamento do loop de mensagem.

## <a name="catlexemoduletuninitializecom"></a><a name="uninitializecom"></a>CAtlExeModuleT::UninitializeCom

Uninitializes COM.

```
static void UninitializeCom() throw();
```

### <a name="remarks"></a>Comentários

Por padrão, este método simplesmente chama [CoUninitialize](/windows/win32/api/combaseapi/nf-combaseapi-couninitialize) e é chamado do destruidor. Anular este método se você substituir [CAtlExeModuleT::InitializeCom](#initializecom).

## <a name="catlexemoduletunlock"></a><a name="unlock"></a>CAtlExeModuleT::Unlock

Decreta a contagem de bloqueios do módulo.

```
LONG Unlock() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna um valor que pode ser útil para diagnósticos ou testes.

## <a name="catlexemoduletwinmain"></a><a name="winmain"></a>CAtlExeModuleT::WinMain

Este método implementa o código necessário para executar um EXE.

```
int WinMain(int nShowCmd) throw();
```

### <a name="parameters"></a>Parâmetros

*nShowCmd*<br/>
Especifica como a janela deve ser mostrada. Este parâmetro pode ser um dos valores discutidos na seção [WinMain.](/windows/win32/api/winbase/nf-winbase-winmain)

### <a name="return-value"></a>Valor retornado

Retorna o valor de retorno do executável.

### <a name="remarks"></a>Comentários

Este método pode ser substituído. Se substituir [CAtlExeModuleT::PreMessageLoop](#premessageloop), [CAtlExeModuleT::PostMessageLoop](#postmessageloop)ou [CAtlExeModuleT::RunMessageLoop](#runmessageloop) não fornece flexibilidade suficiente, é `WinMain` possível substituir a função usando este método.

## <a name="see-also"></a>Confira também

[Amostra de PATO ATL](../../overview/visual-cpp-samples.md)<br/>
[Classe CAtlModuleT](../../atl/reference/catlmodulet-class.md)<br/>
[Classe CAtlDllModuleT](../../atl/reference/catldllmodulet-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
