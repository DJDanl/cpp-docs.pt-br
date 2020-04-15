---
title: Controle do aplicativo
ms.date: 11/04/2016
helpviewer_keywords:
- application control [MFC]
ms.assetid: c1f69f15-e0fe-4515-9f36-d63d31869deb
ms.openlocfilehash: 1f438d3344e90a16def2bd4c0f9cedcd47a64203
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81363550"
---
# <a name="application-control"></a>Controle do aplicativo

O OLE requer um controle substancial sobre aplicações e seus objetos. Os DLLs do sistema OLE devem ser capazes de lançar e liberar aplicativos automaticamente, coordenar sua produção e modificação de objetos, e assim por diante. As funções neste tópico atendem a esses requisitos. Além de serem chamadas pelos DLLs do sistema OLE, essas funções também devem ser chamadas por aplicativos.

### <a name="application-control"></a>Controle do aplicativo

|||
|-|-|
|[AfxOleCanExitApp](#afxolecanexitapp)|Indica se a aplicação pode terminar.|
|[AfxOleGetMessageFilter](#afxolegetmessagefilter)|Recupera o filtro de mensagem atual do aplicativo.|
|[AfxOleGetUserCtrl](#afxolegetuserctrl)|Recupera o sinalizador de controle de usuário atual.|
|[AfxOleSetUserCtrl](#afxolesetuserctrl)|Define ou limpa o sinalizador de controle do usuário.|
|[AfxOleLockApp](#afxolelockapp)|Incrementa a contagem global do número de objetos ativos em um aplicativo.|
|[AfxOleLockControl](#afxolelockcontrol)| Bloqueia a fábrica de classe do controle especificado. |
|[AfxOleUnlockApp](#afxoleunlockapp)|Decreta a contagem do número de objetos ativos em um aplicativo.|
|[AfxOleUnlockControl](#afxoleunlockcontrol)| Desbloqueia a fábrica de classes do controle especificado. |
|[AfxOleRegisterServerClass](#afxoleregisterserverclass)|Registra um servidor no registro do sistema OLE.|
|[AfxOleSetEditMenu](#afxoleseteditmenu)|Implementa a interface do usuário para o *comando Typename* Object.|

## <a name="afxolecanexitapp"></a><a name="afxolecanexitapp"></a>AfxOleCanExitApp

Indica se a aplicação pode terminar.

```
BOOL AFXAPI AfxOleCanExitApp();
```

### <a name="return-value"></a>Valor retornado

Não zero se o aplicativo puder sair; caso contrário, 0.

### <a name="remarks"></a>Comentários

Um aplicativo não deve terminar se houver referências pendentes aos seus objetos. As funções `AfxOleLockApp` `AfxOleUnlockApp` globais e o incremento e o decrésia, respectivamente, um contador de referências aos objetos da aplicação. A aplicação não deve terminar quando este contador não for zero. Se o contador não for zero, a janela principal do aplicativo será oculta (não destruída) quando o usuário escolher Fechar no menu do sistema ou Sair do menu Arquivo. O framework chama `CFrameWnd::OnClose`essa função em .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCAutomation#2](../../mfc/codesnippet/cpp/application-control_1.cpp)]

## <a name="requirements"></a>Requisitos

**Cabeçalho**: afxdisp.h

## <a name="afxolegetmessagefilter"></a><a name="afxolegetmessagefilter"></a>AfxOleGetMessageFilter

Recupera o filtro de mensagem atual do aplicativo.

```
COleMessageFilter* AFXAPI AfxOleGetMessageFilter();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o filtro de mensagem atual.

### <a name="remarks"></a>Comentários

Chame esta função para `COleMessageFilter`acessar o objeto derivado da `AfxGetApp` corrente, assim como você chamaria para acessar o objeto de aplicativo atual.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCAutomation#3](../../mfc/codesnippet/cpp/application-control_2.cpp)]

[!code-cpp[NVC_MFCAutomation#4](../../mfc/codesnippet/cpp/application-control_3.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho**: afxwin.h

## <a name="afxolegetuserctrl"></a><a name="afxolegetuserctrl"></a>AfxOleGetUserCtrl

Recupera o sinalizador de controle de usuário atual.

```
BOOL AFXAPI AfxOleGetUserCtrl();
```

### <a name="return-value"></a>Valor retornado

Não zero se o usuário estiver no controle do aplicativo; caso contrário, 0.

### <a name="remarks"></a>Comentários

O usuário está no controle do aplicativo quando o usuário abriu ou criou explicitamente um novo documento. O usuário também está no controle se o aplicativo não foi lançado pelos DLLs do sistema OLE — ou seja, se o usuário lançou o aplicativo com o shell do sistema.

### <a name="requirements"></a>Requisitos

**Cabeçalho**: afxdisp.h

## <a name="afxolesetuserctrl"></a><a name="afxolesetuserctrl"></a>AfxOleSetUserCtrl

Define ou limpa o sinalizador de controle do usuário, `AfxOleGetUserCtrl`o que é explicado na referência para .

```
void AFXAPI AfxOleSetUserCtrl(BOOL bUserCtrl);
```

### <a name="parameters"></a>Parâmetros

*bUserCtrl*<br/>
Especifica se o sinalizador de controle de usuário deve ser definido ou limpo.

### <a name="remarks"></a>Comentários

A estrutura chama essa função quando o usuário cria ou carrega um documento, mas não quando um documento é carregado ou criado através de uma ação indireta, como carregar um objeto incorporado de um aplicativo de contêiner.

Chame esta função se outras ações em seu aplicativo devem colocar o usuário no controle do aplicativo.

### <a name="requirements"></a>Requisitos

**Cabeçalho**: afxdisp.h

## <a name="afxolelockapp"></a><a name="afxolelockapp"></a>Afxolelockapp

Incrementa a contagem global do número de objetos ativos no aplicativo.

```
void AFXAPI AfxOleLockApp();
```

### <a name="remarks"></a>Comentários

O framework mantém uma contagem do número de objetos ativos em um aplicativo. O `AfxOleLockApp` `AfxOleUnlockApp` e funções, respectivamente, incrementam e decretem esta contagem.

Quando o usuário tenta fechar um aplicativo que tem objetos ativos — um aplicativo para o qual a contagem de objetos ativos não é zero —, a estrutura oculta o aplicativo da exibição do usuário em vez de desligá-lo completamente. A `AfxOleCanExitApp` função indica se o aplicativo pode terminar.

Chamada `AfxOleLockApp` de qualquer objeto que exponha interfaces OLE, se seria indesejável que esse objeto seja destruído enquanto ainda está sendo usado por um aplicativo cliente. Chame `AfxOleUnlockApp` também o destruidor de qualquer objeto `AfxOleLockApp` que chame o construtor. Por padrão, `COleDocument` (e classes derivadas) bloqueiam e desbloqueiam automaticamente o aplicativo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCAutomation#5](../../mfc/codesnippet/cpp/application-control_4.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho**: afxdisp.h

## <a name="afxoleunlockapp"></a><a name="afxoleunlockapp"></a>Afxoleunlockapp

Decreta a contagem de objetos ativos da estrutura na aplicação.

```
void AFXAPI AfxOleUnlockApp();
```

### <a name="remarks"></a>Comentários

Consulte `AfxOleLockApp` para obter mais informações.

Quando o número de objetos `AfxOleOnReleaseAllObjects` ativos atinge zero, é chamado.

### <a name="example"></a>Exemplo

Veja o exemplo [de AfxOleLockApp](#afxolelockapp).

### <a name="requirements"></a>Requisitos

**Cabeçalho**: afxdisp.h

## <a name="afxolelockcontrol"></a>AfxOleLockControl

Bloqueia a fábrica de classes do controle especificado para que os dados criados dinamicamente associados ao controle permaneçam na memória.

### <a name="syntax"></a>Sintaxe

```
BOOL AFXAPI AfxOleLockControl(  REFCLSID clsid  );
BOOL AFXAPI AfxOleLockControl( LPCTSTR lpszProgID );
```

### <a name="parameters"></a>Parâmetros

*clsid*<br/>
A identificação única da classe do controle.

*lpszProgID*<br/>
A identificação única do programa do controle.

### <a name="return-value"></a>Valor retornado

Não zero se a fábrica de classe do controle foi bloqueada com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Isso pode acelerar significativamente a exibição dos controles. Por exemplo, uma vez que você crie um `AfxOleLockControl`controle em uma caixa de diálogo e bloqueie o controle com , você não precisa criá-lo e matá-lo novamente toda vez que a caixa de diálogo for mostrada ou destruída. Se o usuário abrir e fechar uma caixa de diálogo repetidamente, bloquear seus controles pode melhorar significativamente o desempenho. Quando estiver pronto para destruir `AfxOleUnlockControl`o controle, ligue.

### <a name="example"></a>Exemplo

```cpp
// Starts and locks control's (Microsoft Calendar) class factory.
// Control will remain in memory for lifetime of
// application or until AfxOleUnlockControl() is called.

AfxOleLockControl(_T("MSCAL.Calendar"));
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="afxoleregisterserverclass"></a><a name="afxoleregisterserverclass"></a>Afxoleregisterserverclass

Esta função permite que você registre seu servidor no registro do sistema OLE.

```
BOOL AFXAPI AfxOleRegisterServerClass(
    REFCLSID clsid,
    LPCTSTR lpszClassName,
    LPCTSTR lpszShortTypeName,
    LPCTSTR lpszLongTypeName,
    OLE_APPTYPE nAppType = OAT_SERVER,
    LPCTSTR* rglpszRegister = NULL,
    LPCTSTR* rglpszOverwrite = NULL);
```

### <a name="parameters"></a>Parâmetros

*clsid*<br/>
Referência ao ID de classe OLE do servidor.

*Lpszclassname*<br/>
Ponteiro para uma seqüência contendo o nome da classe dos objetos do servidor.

*lpszShortTypeName*<br/>
Ponteiro para uma seqüência contendo o nome curto do tipo de objeto do servidor, como "Gráfico".

*lpszLongTypeName*<br/>
Ponteiro para uma seqüência contendo o nome longo do tipo de objeto do servidor, como "Gráfico Microsoft Excel 5.0".

*nAppType*<br/>
Um valor, retirado da enumeração OLE_APPTYPE, especificando o tipo de aplicação OLE. Os valores possíveis são os seguintes:

- OAT_INPLACE_SERVER Server tem interface de usuário de servidor completo.

- OAT_SERVER servidor suporta apenas incorporação.

- OAT_CONTAINER Container suporta links para incorporações.

- OAT_DISPATCH_OBJECT `IDispatch`objeto capaz.

*rglpszRegister*<br/>
Matriz de ponteiros para strings que representam as chaves e valores a serem adicionados ao registro do sistema OLE se não forem encontrados valores existentes para as chaves.

*rglpszOverwrite*<br/>
Matriz de ponteiros para strings que representam as chaves e valores a serem adicionados ao registro do sistema OLE se o registro contiver valores existentes para as chaves dadas.

### <a name="return-value"></a>Valor retornado

Não zero se a classe do servidor for registrada com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

A maioria dos `COleTemplateServer::Register` aplicativos pode usar para registrar os tipos de documentos do aplicativo. Se o formato de registro do sistema do aplicativo não `AfxOleRegisterServerClass` se encaixar no padrão típico, você poderá usar para obter mais controle.

O registro consiste em um conjunto de chaves e valores. Os *argumentos rglpszRegister* e *rglpszOverwrite* são matrizes de ponteiros para strings, cada um consistindo de uma chave e um valor separado por um caractere **NULL** ( ). `'\0'` Cada uma dessas cordas pode ter parâmetros substituíveis cujos lugares são marcados pelas seqüências de caracteres *%1* a *%5*.

Os símbolos são preenchidos da seguinte forma:

|Símbolo|Valor|
|------------|-----------|
|%1|ID de classe, formatado como uma string|
|%2|Nome da classe|
|%3|Caminho para arquivo executável|
|%4|Nome do tipo curto|
|%5|Nome do tipo longo|

### <a name="requirements"></a>Requisitos

**Cabeçalho**: afxdisp.h

## <a name="afxoleseteditmenu"></a><a name="afxoleseteditmenu"></a>Menu afxOleSetEditMenu

Implementa a interface do usuário para o *comando Typename* Object.

```
void AFXAPI AfxOleSetEditMenu(
    COleClientItem* pClient,
    CMenu* pMenu,
    UINT iMenuItem,
    UINT nIDVerbMin,
    UINT nIDVerbMax = 0,
    UINT nIDConvert = 0);
```

### <a name="parameters"></a>Parâmetros

*pClient*<br/>
Um ponteiro para o item OLE do cliente.

*pMenu*<br/>
Um ponteiro para o objeto do menu a ser atualizado.

*Imenuitem*<br/>
O índice do item do menu a ser atualizado.

*nIDVerbMin*<br/>
O id de comando que corresponde ao verbo primário.

*nIDVerbMax*<br/>
O id de comando que corresponde ao último verbo.

*nIDConvert*<br/>
ID para o item do menu Converter.

### <a name="remarks"></a>Comentários

Se o servidor reconhecer apenas um verbo primário, o item do menu se tornará "objeto *de nome de nome* verbo" e o comando *nIDVerbMin* será enviado quando o usuário escolher o comando. Se o servidor reconhecer vários verbos, o item do menu se tornará *"objeto de nome de tipo"* e um submenu listando todos os verbos será exibido quando o usuário escolhe o comando. Quando o usuário escolhe um verbo do submenu, *nIDVerbMin* é enviado se o primeiro verbo for escolhido, *nIDVerbMin* + 1 é enviado se o segundo verbo for escolhido, e assim por diante. A `COleDocument` implementação padrão lida automaticamente com esse recurso.

Você deve ter a seguinte declaração no script de recurso de aplicativo do seu cliente (. Arquivo RC):

**#include \<afxolecl.rc>**

### <a name="requirements"></a>Requisitos

**Cabeçalho**: afxole.h

## <a name="afxoleunlockcontrol"></a><a name="afxoleunlockcontrol"></a>AfxOleUnlockControl

Desbloqueia a fábrica de classes do controle especificado.

### <a name="syntax"></a>Sintaxe

```
BOOL AFXAPI AfxOleUnlockControl( REFCLSID clsid );
BOOL AFXAPI AfxOleUnlockControl( LPCTSTR lpszProgID );
```

### <a name="parameters"></a>Parâmetros

*clsid*<br/>
A identificação única da classe do controle.

*lpszProgID*<br/>
A identificação única do programa do controle.

### <a name="return-value"></a>Valor retornado

Não zero se a fábrica de classe do controle foi desbloqueada com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Um controle é `AfxOleLockControl`bloqueado com , de modo que os dados criados dinamicamente associados ao controle permanecem na memória. Isso pode acelerar significativamente a exibição do controle porque o controle não precisa ser criado e destruído toda vez que ele é exibido. Quando estiver pronto para destruir `AfxOleUnlockControl`o controle, ligue.

### <a name="example"></a>Exemplo

```cpp
// Unlock control's (Microsoft Calendar Control) class factory.

AfxOleUnlockControl(_T("MSCAL.Calendar"));
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="see-also"></a>Confira também

[Macros e globais](mfc-macros-and-globals.md)<br/>
