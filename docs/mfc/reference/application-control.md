---
title: Controle do aplicativo
ms.date: 11/04/2016
helpviewer_keywords:
- application control [MFC]
ms.assetid: c1f69f15-e0fe-4515-9f36-d63d31869deb
ms.openlocfilehash: cb4ad19dfad06b793f226324d8e28c37c084ad67
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79418898"
---
# <a name="application-control"></a>Controle do aplicativo

O OLE requer um controle substancial sobre os aplicativos e seus objetos. As DLLs do sistema OLE devem ser capazes de iniciar e lançar aplicativos automaticamente, coordenar a produção e a modificação de objetos e assim por diante. As funções neste tópico atendem a esses requisitos. Além de ser chamado pelas DLLs do sistema OLE, essas funções, às vezes, devem ser chamadas por aplicativos também.

### <a name="application-control"></a>Controle do aplicativo

|||
|-|-|
|[AfxOleCanExitApp](#afxolecanexitapp)|Indica se o aplicativo pode ser encerrado.|
|[AfxOleGetMessageFilter](#afxolegetmessagefilter)|Recupera o filtro de mensagem atual do aplicativo.|
|[AfxOleGetUserCtrl](#afxolegetuserctrl)|Recupera o sinalizador de controle de usuário atual.|
|[AfxOleSetUserCtrl](#afxolesetuserctrl)|Define ou limpa o sinalizador de controle de usuário.|
|[AfxOleLockApp](#afxolelockapp)|Incrementa a contagem global da estrutura do número de objetos ativos em um aplicativo.|
|[AfxOleLockControl](#afxolelockcontrol)| Bloqueia a fábrica de classes do controle especificado. |
|[AfxOleUnlockApp](#afxoleunlockapp)|Decrementa a contagem da estrutura do número de objetos ativos em um aplicativo.|
|[AfxOleUnlockControl](#afxoleunlockcontrol)| Desbloqueia a fábrica de classes do controle especificado. |
|[AfxOleRegisterServerClass](#afxoleregisterserverclass)|Registra um servidor no registro do sistema OLE.|
|[AfxOleSetEditMenu](#afxoleseteditmenu)|Implementa a interface do usuário para o comando do objeto *TypeName* .|

##  <a name="afxolecanexitapp"></a>AfxOleCanExitApp

Indica se o aplicativo pode ser encerrado.

```
BOOL AFXAPI AfxOleCanExitApp();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o aplicativo puder sair; caso contrário, 0.

### <a name="remarks"></a>Comentários

Um aplicativo não deve terminar se houver referências pendentes a seus objetos. As funções globais `AfxOleLockApp` e `AfxOleUnlockApp` incrementar e decrementar, respectivamente, um contador de referências aos objetos do aplicativo. O aplicativo não deve terminar quando esse contador for diferente de zero. Se o contador for diferente de zero, a janela principal do aplicativo ficará oculta (não destruída) quando o usuário escolher fechar no menu do sistema ou sair do menu arquivo. A estrutura chama essa função no `CFrameWnd::OnClose`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCAutomation#2](../../mfc/codesnippet/cpp/application-control_1.cpp)]

## <a name="requirements"></a>Requisitos

**Cabeçalho**: AFXDISP. h

##  <a name="afxolegetmessagefilter"></a>AfxOleGetMessageFilter

Recupera o filtro de mensagem atual do aplicativo.

```
COleMessageFilter* AFXAPI AfxOleGetMessageFilter();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o filtro de mensagem atual.

### <a name="remarks"></a>Comentários

Chame essa função para acessar o objeto derivado de `COleMessageFilter`atual, assim como você chamaria `AfxGetApp` para acessar o objeto de aplicativo atual.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCAutomation#3](../../mfc/codesnippet/cpp/application-control_2.cpp)]

[!code-cpp[NVC_MFCAutomation#4](../../mfc/codesnippet/cpp/application-control_3.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho**: Afxwin. h

##  <a name="afxolegetuserctrl"></a>AfxOleGetUserCtrl

Recupera o sinalizador de controle de usuário atual.

```
BOOL AFXAPI AfxOleGetUserCtrl();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o usuário estiver no controle do aplicativo; caso contrário, 0.

### <a name="remarks"></a>Comentários

O usuário está no controle do aplicativo quando o usuário abriu ou criou um novo documento explicitamente. O usuário também estará no controle se o aplicativo não tiver sido iniciado pelas DLLs do sistema OLE — em outras palavras, se o usuário tiver iniciado o aplicativo com o Shell do sistema.

### <a name="requirements"></a>Requisitos

**Cabeçalho**: AFXDISP. h

##  <a name="afxolesetuserctrl"></a>AfxOleSetUserCtrl

Define ou limpa o sinalizador de controle de usuário, que é explicado na referência para `AfxOleGetUserCtrl`.

```
void AFXAPI AfxOleSetUserCtrl(BOOL bUserCtrl);
```

### <a name="parameters"></a>parâmetros

*bUserCtrl*<br/>
Especifica se o sinalizador de controle de usuário deve ser definido ou limpo.

### <a name="remarks"></a>Comentários

A estrutura chama essa função quando o usuário cria ou carrega um documento, mas não quando um documento é carregado ou criado por meio de uma ação indireta, como carregar um objeto incorporado de um aplicativo de contêiner.

Chame essa função se outras ações em seu aplicativo devem colocar o usuário no controle do aplicativo.

### <a name="requirements"></a>Requisitos

**Cabeçalho**: AFXDISP. h

##  <a name="afxolelockapp"></a>AfxOleLockApp

Incrementa a contagem global da estrutura do número de objetos ativos no aplicativo.

```
void AFXAPI AfxOleLockApp();
```

### <a name="remarks"></a>Comentários

A estrutura mantém uma contagem do número de objetos ativos em um aplicativo. As funções `AfxOleLockApp` e `AfxOleUnlockApp`, respectivamente, incrementam e decrementam essa contagem.

Quando o usuário tenta fechar um aplicativo que tem objetos ativos — um aplicativo para o qual a contagem de objetos ativos é diferente de zero — a estrutura oculta o aplicativo da exibição do usuário em vez de desligá-lo completamente. A função `AfxOleCanExitApp` indica se o aplicativo pode ser encerrado.

Chame `AfxOleLockApp` de qualquer objeto que exponha interfaces OLE, se for indesejável para esse objeto ser destruído enquanto ainda estiver sendo usado por um aplicativo cliente. Além disso, chame `AfxOleUnlockApp` no destruidor de qualquer objeto que chame `AfxOleLockApp` no construtor. Por padrão, `COleDocument` (e classes derivadas) bloqueiam e desbloqueiam automaticamente o aplicativo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCAutomation#5](../../mfc/codesnippet/cpp/application-control_4.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho**: AFXDISP. h

##  <a name="afxoleunlockapp"></a>AfxOleUnlockApp

Decrementa a contagem de objetos ativos do Framework no aplicativo.

```
void AFXAPI AfxOleUnlockApp();
```

### <a name="remarks"></a>Comentários

Consulte `AfxOleLockApp` para obter mais informações.

Quando o número de objetos ativos chega a zero, `AfxOleOnReleaseAllObjects` é chamado.

### <a name="example"></a>Exemplo

Consulte o exemplo de [AfxOleLockApp](#afxolelockapp).

### <a name="requirements"></a>Requisitos

**Cabeçalho**: AFXDISP. h

## <a name="afxolelockcontrol"></a>AfxOleLockControl

Bloqueia a fábrica de classes do controle especificado para que os dados criados dinamicamente associados ao controle permaneçam na memória.

### <a name="syntax"></a>Sintaxe

```
BOOL AFXAPI AfxOleLockControl(  REFCLSID clsid  );
BOOL AFXAPI AfxOleLockControl( LPCTSTR lpszProgID );
```

### <a name="parameters"></a>parâmetros

*CLSID*<br/>
A ID de classe exclusiva do controle.

*lpszProgID*<br/>
A ID de programa exclusiva do controle.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a fábrica de classes do controle tiver sido bloqueada com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

Isso pode acelerar significativamente a exibição dos controles. Por exemplo, depois de criar um controle em uma caixa de diálogo e bloquear o controle com `AfxOleLockControl`, você não precisará criá-lo e matar novamente toda vez que a caixa de diálogo for mostrada ou destruída. Se o usuário abrir e fechar uma caixa de diálogo repetidamente, o bloqueio dos controles poderá melhorar significativamente o desempenho. Quando você estiver pronto para destruir o controle, chame `AfxOleUnlockControl`.

### <a name="example"></a>Exemplo

```cpp
// Starts and locks control's (Microsoft Calendar) class factory.
// Control will remain in memory for lifetime of
// application or until AfxOleUnlockControl() is called.

AfxOleLockControl(_T("MSCAL.Calendar"));
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

##  <a name="afxoleregisterserverclass"></a>AfxOleRegisterServerClass

Essa função permite que você registre o servidor no registro do sistema OLE.

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

### <a name="parameters"></a>parâmetros

*CLSID*<br/>
Referência à ID de classe OLE do servidor.

*lpszClassName*<br/>
Ponteiro para uma cadeia de caracteres que contém o nome da classe dos objetos do servidor.

*lpszShortTypeName*<br/>
Ponteiro para uma cadeia de caracteres que contém o nome curto do tipo de objeto do servidor, como "gráfico".

*lpszLongTypeName*<br/>
Ponteiro para uma cadeia de caracteres que contém o nome longo do tipo de objeto do servidor, como "gráfico do Microsoft Excel 5,0".

*nAppType*<br/>
Um valor, obtido da enumeração de OLE_APPTYPE, especificando o tipo de aplicativo OLE. Os valores possíveis são os seguintes:

- O OAT_INPLACE_SERVER Server tem a interface de usuário do servidor completo.

- O OAT_SERVER Server dá suporte apenas à inserção.

- OAT_CONTAINER Contêiner dá suporte a links para incorporações.

- OAT_DISPATCH_OBJECT objeto com capacidade `IDispatch`.

*rglpszRegister*<br/>
Matriz de ponteiros para cadeias de caracteres que representam as chaves e os valores a serem adicionados ao registro do sistema OLE se nenhum valor existente para as chaves for encontrado.

*rglpszOverwrite*<br/>
Matriz de ponteiros para cadeias de caracteres que representam as chaves e valores a serem adicionados ao registro do sistema OLE se o registro contiver valores existentes para as chaves especificadas.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a classe de servidor for registrada com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

A maioria dos aplicativos pode usar `COleTemplateServer::Register` para registrar os tipos de documento do aplicativo. Se o formato do registro do sistema do seu aplicativo não se ajustar ao padrão típico, você poderá usar `AfxOleRegisterServerClass` para obter mais controle.

O registro consiste em um conjunto de chaves e valores. Os argumentos *rglpszRegister* e *rglpszOverwrite* são matrizes de ponteiros para cadeias de caracteres, cada um consistindo em uma chave e um valor separado por um caractere **nulo** (`'\0'`). Cada uma dessas cadeias de caracteres pode ter parâmetros substituíveis cujos locais são marcados pelas sequências de caracteres *%1* a *%5*.

Os símbolos são preenchidos da seguinte maneira:

|Símbolo|Valor|
|------------|-----------|
|%1|ID da classe, formatada como uma cadeia de caracteres|
|%2|Nome da classe|
|%3|Caminho para o arquivo executável|
|%4|Nome de tipo curto|
|%5|Nome de tipo longo|

### <a name="requirements"></a>Requisitos

**Cabeçalho**: AFXDISP. h

##  <a name="afxoleseteditmenu"></a>AfxOleSetEditMenu

Implementa a interface do usuário para o comando do objeto *TypeName* .

```
void AFXAPI AfxOleSetEditMenu(
    COleClientItem* pClient,
    CMenu* pMenu,
    UINT iMenuItem,
    UINT nIDVerbMin,
    UINT nIDVerbMax = 0,
    UINT nIDConvert = 0);
```

### <a name="parameters"></a>parâmetros

*pClient*<br/>
Um ponteiro para o item OLE do cliente.

*pMenu*<br/>
Um ponteiro para o objeto de menu a ser atualizado.

*iMenuItem*<br/>
O índice do item de menu a ser atualizado.

*nIDVerbMin*<br/>
A ID de comando que corresponde ao verbo primário.

*nIDVerbMax*<br/>
A ID de comando que corresponde ao último verbo.

*nIDConvert*<br/>
ID do item de menu de conversão.

### <a name="remarks"></a>Comentários

Se o servidor reconhecer apenas um verbo primário, o item de menu se tornará "verbo *TypeName* Object" e o comando *nIDVerbMin* será enviado quando o usuário escolher o comando. Se o servidor reconhecer vários verbos, o item de menu se tornará " *TypeName* Object" e um submenu listando todos os verbos aparecerá quando o usuário escolher o comando. Quando o usuário escolhe um verbo no submenu, *nIDVerbMin* é enviado se o primeiro verbo for escolhido, *nIDVerbMin* + 1 será enviado se o segundo verbo for escolhido e assim por diante. A implementação de `COleDocument` padrão manipula automaticamente esse recurso.

Você deve ter a seguinte instrução no script de recurso de aplicativo do cliente (. RC) arquivo:

**#include \<AFXOLECL. rc >**

### <a name="requirements"></a>Requisitos

**Cabeçalho**: Afxole. h

## <a name="afxoleunlockcontrol"></a>AfxOleUnlockControl

Desbloqueia a fábrica de classes do controle especificado.

### <a name="syntax"></a>Sintaxe

```
BOOL AFXAPI AfxOleUnlockControl( REFCLSID clsid );
BOOL AFXAPI AfxOleUnlockControl( LPCTSTR lpszProgID );
```

### <a name="parameters"></a>parâmetros

*CLSID*<br/>
A ID de classe exclusiva do controle.

*lpszProgID*<br/>
A ID de programa exclusiva do controle.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a fábrica de classes do controle tiver sido desbloqueada com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

Um controle é bloqueado com `AfxOleLockControl`, para que os dados criados dinamicamente associados ao controle permaneçam na memória. Isso pode acelerar significativamente a exibição do controle, pois o controle não precisa ser criado e destruído toda vez que é exibido. Quando você estiver pronto para destruir o controle, chame `AfxOleUnlockControl`.

### <a name="example"></a>Exemplo

```cpp
// Unlock control's (Microsoft Calendar Control) class factory.

AfxOleUnlockControl(_T("MSCAL.Calendar"));
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

## <a name="see-also"></a>Confira também

[Macros e globais](mfc-macros-and-globals.md)<br/>
