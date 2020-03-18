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
ms.openlocfilehash: d37cc8e97d29cbedfeb4ba79502d44529485399f
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79418051"
---
# <a name="catlexemodulet-class"></a>Classe CAtlExeModuleT

Essa classe representa o módulo para um aplicativo.

## <a name="syntax"></a>Sintaxe

```
template <class T>
class ATL_NO_VTABLE CAtlExeModuleT : public CAtlModuleT<T>
```

#### <a name="parameters"></a>parâmetros

*T*<br/>
Sua classe derivada de `CAtlExeModuleT`.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CAtlExeModuleT::CAtlExeModuleT](#catlexemodulet)|O construtor.|
|[CAtlExeModuleT:: ~ CAtlExeModuleT](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CAtlExeModuleT::InitializeCom](#initializecom)|Inicializa COM.|
|[CAtlExeModuleT::P arseCommandLine](#parsecommandline)|Analisa a linha de comando e executa o registro, se necessário.|
|[CAtlExeModuleT::P ostMessageLoop](#postmessageloop)|Esse método é chamado imediatamente depois que o loop de mensagem é encerrado.|
|[CAtlExeModuleT::P reMessageLoop](#premessageloop)|Esse método é chamado imediatamente antes de entrar no loop de mensagem.|
|[CAtlExeModuleT::RegisterClassObjects](#registerclassobjects)|Registra o objeto de classe.|
|[CAtlExeModuleT::RevokeClassObjects](#revokeclassobjects)|Revoga o objeto de classe.|
|[CAtlExeModuleT:: Run](#run)|Esse método executa o código no módulo EXE para inicializar, executar o loop de mensagem e limpar.|
|[CAtlExeModuleT::RunMessageLoop](#runmessageloop)|Esse método executa o loop de mensagem.|
|[CAtlExeModuleT::UninitializeCom](#uninitializecom)|Desinicializa COM.|
|[CAtlExeModuleT:: desbloquear](#unlock)|Decrementa a contagem de bloqueios do módulo.|
|[CAtlExeModuleT:: WinMain](#winmain)|Esse método implementa o código necessário para executar um EXE.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CAtlExeModuleT:: m_bDelayShutdown](#m_bdelayshutdown)|Um sinalizador que indica que deve haver um atraso ao desligar o módulo.|
|[CAtlExeModuleT:: m_dwPause](#m_dwpause)|Um valor de pausa usado para garantir que todos os objetos sejam liberados antes do desligamento.|
|[CAtlExeModuleT:: m_dwTimeOut](#m_dwtimeout)|Um valor de tempo limite usado para atrasar o descarregamento do módulo.|

## <a name="remarks"></a>Comentários

`CAtlExeModuleT` representa o módulo de um aplicativo (EXE) e contém um código que dá suporte à criação de um EXE, ao processamento da linha de comando, ao registro de objetos de classe, à execução do loop de mensagem e à limpeza na saída.

Essa classe foi projetada para melhorar o desempenho quando objetos COM no servidor EXE são continuamente criados e destruídos. Após o lançamento do último objeto COM, o EXE aguarda uma duração especificada pelo membro de dados [CAtlExeModuleT:: m_dwTimeOut](#m_dwtimeout) . Se não houver nenhuma atividade durante esse período (ou seja, nenhum objeto COM for criado), o processo de desligamento será iniciado.

O membro de dados [CAtlExeModuleT:: m_bDelayShutdown](#m_bdelayshutdown) é um sinalizador usado para determinar se o exe deve usar o mecanismo definido acima. Se estiver definido como false, o módulo será encerrado imediatamente.

Para obter mais informações sobre módulos na ATL, consulte [classes de módulo do ATL](../../atl/atl-module-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[_ATL_MODULE](atl-typedefs.md#_atl_module)

[CAtlModule](../../atl/reference/catlmodule-class.md)

[CAtlModuleT](../../atl/reference/catlmodulet-class.md)

`CAtlExeModuleT`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

##  <a name="catlexemodulet"></a>CAtlExeModuleT::CAtlExeModuleT

O construtor.

```
CAtlExeModuleT() throw();
```

### <a name="remarks"></a>Comentários

Se o módulo EXE não puder ser inicializado, o WinMain retornará imediatamente sem processamento adicional.

##  <a name="dtor"></a>CAtlExeModuleT:: ~ CAtlExeModuleT

O destruidor.

```
~CAtlExeModuleT() throw();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados.

##  <a name="initializecom"></a>CAtlExeModuleT::InitializeCom

Inicializa COM.

```
static HRESULT InitializeCom() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Esse método é chamado a partir do construtor e pode ser substituído para inicializar COM de uma maneira diferente da implementação padrão. A implementação padrão chama `CoInitializeEx(NULL, COINIT_MULTITHREADED)` ou `CoInitialize(NULL)` dependendo da configuração do projeto.

Substituir esse método normalmente requer a substituição de [CAtlExeModuleT:: UninitializeCom](#uninitializecom).

##  <a name="m_bdelayshutdown"></a>CAtlExeModuleT:: m_bDelayShutdown

Um sinalizador que indica que deve haver um atraso ao desligar o módulo.

```
bool m_bDelayShutdown;
```

### <a name="remarks"></a>Comentários

Consulte a [visão geral do CAtlExeModuleT](../../atl/reference/catlexemodulet-class.md) para obter detalhes.

##  <a name="m_dwpause"></a>CAtlExeModuleT:: m_dwPause

Um valor de pausa usado para garantir que todos os objetos tenham saído antes do desligamento.

```
DWORD m_dwPause;
```

### <a name="remarks"></a>Comentários

Altere esse valor depois de chamar [CAtlExeModuleT:: InitializeCom](#initializecom) para definir o número de milissegundos usados como o valor de pausa para desligar o servidor. O valor padrão é 1000 milissegundos.

##  <a name="m_dwtimeout"></a>CAtlExeModuleT:: m_dwTimeOut

Um valor de tempo limite usado para atrasar o descarregamento do módulo.

```
DWORD m_dwTimeOut;
```

### <a name="remarks"></a>Comentários

Altere esse valor depois de chamar [CAtlExeModuleT:: InitializeCom](#initializecom) para definir o número de milissegundos usados como o valor de tempo limite para desligar o servidor. O valor padrão é 5.000 milissegundos. Consulte a [visão geral do CAtlExeModuleT](../../atl/reference/catlexemodulet-class.md) para obter mais detalhes.

##  <a name="parsecommandline"></a>CAtlExeModuleT::P arseCommandLine

Analisa a linha de comando e executa o registro, se necessário.

```
bool ParseCommandLine(LPCTSTR lpCmdLine, HRESULT* pnRetCode) throw();
```

### <a name="parameters"></a>parâmetros

*lpCmdLine*<br/>
A linha de comando passada para o aplicativo.

*pnRetCode*<br/>
O HRESULT correspondente ao registro (se tiver ocorrido).

### <a name="return-value"></a>Valor retornado

Retornará true se o aplicativo continuar a ser executado; caso contrário, false.

### <a name="remarks"></a>Comentários

Esse método é chamado de [CAtlExeModuleT:: WinMain](#winmain) e pode ser substituído para manipular as opções de linha de comando. A implementação padrão verifica os argumentos de linha de comando **/RegServer** e **opção/UnregServer** e executa o registro ou o cancelamento de registro.

##  <a name="postmessageloop"></a>CAtlExeModuleT::P ostMessageLoop

Esse método é chamado imediatamente depois que o loop de mensagem é encerrado.

```
HRESULT PostMessageLoop() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Substitua esse método para executar a limpeza de aplicativo personalizada. A implementação padrão chama [CAtlExeModuleT:: RevokeClassObjects](#revokeclassobjects).

##  <a name="premessageloop"></a>CAtlExeModuleT::P reMessageLoop

Esse método é chamado imediatamente antes de entrar no loop de mensagem.

```
HRESULT PreMessageLoop(int nShowCmd) throw();
```

### <a name="parameters"></a>parâmetros

*nShowCmd*<br/>
O valor passado como o parâmetro *nShowCmd* em WinMain.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Substitua esse método para adicionar o código de inicialização personalizado para o aplicativo. A implementação padrão registra os objetos de classe.

##  <a name="registerclassobjects"></a>CAtlExeModuleT::RegisterClassObjects

Registra o objeto de classe com OLE para que outros aplicativos possam se conectar a ele.

```
HRESULT RegisterClassObjects(DWORD dwClsContext, DWORD dwFlags) throw();
```

### <a name="parameters"></a>parâmetros

*dwClsContext*<br/>
Especifica o contexto no qual o objeto de classe deve ser executado. Os valores possíveis são CLSCTX_INPROC_SERVER, CLSCTX_INPROC_HANDLER ou CLSCTX_LOCAL_SERVER.

*dwFlags*<br/>
Determina os tipos de conexão para o objeto de classe. Os valores possíveis são REGCLS_SINGLEUSE, REGCLS_MULTIPLEUSE ou REGCLS_MULTI_SEPARATE.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito, S_FALSE se não houvesse nenhuma classe a ser registrada ou um erro HRESULT em caso de falha.

##  <a name="revokeclassobjects"></a>CAtlExeModuleT::RevokeClassObjects

Remove o objeto de classe.

```
HRESULT RevokeClassObjects() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito, S_FALSE se não houvesse nenhuma classe a ser registrada ou um erro HRESULT em caso de falha.

##  <a name="run"></a>CAtlExeModuleT:: Run

Esse método executa o código no módulo EXE para inicializar, executar o loop de mensagem e limpar.

```
HRESULT Run(int nShowCmd = SW_HIDE) throw();
```

### <a name="parameters"></a>parâmetros

*nShowCmd*<br/>
Especifica como a janela deve ser mostrada. Esse parâmetro pode ser um dos valores discutidos na seção [WinMain](/windows/win32/api/winbase/nf-winbase-winmain) . O padrão é SW_HIDE.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Esse método pode ser substituído. No entanto, na prática, é melhor substituir [CAtlExeModuleT::P remessageloop](#premessageloop), [CAtlExeModuleT:: RunMessageLoop](#runmessageloop)ou [CAtlExeModuleT::P ostmessageloop](#postmessageloop) em vez disso.

##  <a name="runmessageloop"></a>CAtlExeModuleT::RunMessageLoop

Esse método executa o loop de mensagem.

```
void RunMessageLoop() throw();
```

### <a name="remarks"></a>Comentários

Esse método pode ser substituído para alterar o comportamento do loop de mensagem.

##  <a name="uninitializecom"></a>CAtlExeModuleT::UninitializeCom

Desinicializa COM.

```
static void UninitializeCom() throw();
```

### <a name="remarks"></a>Comentários

Por padrão, esse método simplesmente chama [CoUninitialize](/windows/win32/api/combaseapi/nf-combaseapi-couninitialize) e é chamado do destruidor. Substitua esse método se você substituir [CAtlExeModuleT:: InitializeCom](#initializecom).

##  <a name="unlock"></a>CAtlExeModuleT:: desbloquear

Decrementa a contagem de bloqueios do módulo.

```
LONG Unlock() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna um valor que pode ser útil para diagnóstico ou teste.

##  <a name="winmain"></a>CAtlExeModuleT:: WinMain

Esse método implementa o código necessário para executar um EXE.

```
int WinMain(int nShowCmd) throw();
```

### <a name="parameters"></a>parâmetros

*nShowCmd*<br/>
Especifica como a janela deve ser mostrada. Esse parâmetro pode ser um dos valores discutidos na seção [WinMain](/windows/win32/api/winbase/nf-winbase-winmain) .

### <a name="return-value"></a>Valor retornado

Retorna o valor de retorno do executável.

### <a name="remarks"></a>Comentários

Esse método pode ser substituído. Se substituir [CAtlExeModuleT::P remessageloop](#premessageloop), [CAtlExeModuleT::P ostmessageloop](#postmessageloop)ou [CAtlExeModuleT:: RunMessageLoop](#runmessageloop) não fornecer flexibilidade suficiente, será possível substituir a função `WinMain` usando esse método.

## <a name="see-also"></a>Confira também

[Exemplo de ATLDuck](../../overview/visual-cpp-samples.md)<br/>
[Classe CAtlModuleT](../../atl/reference/catlmodulet-class.md)<br/>
[Classe CAtlDllModuleT](../../atl/reference/catldllmodulet-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
