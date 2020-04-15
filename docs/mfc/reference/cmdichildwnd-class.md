---
title: Classe CMDIChildWnd
ms.date: 11/04/2016
f1_keywords:
- CMDIChildWnd
- AFXWIN/CMDIChildWnd
- AFXWIN/CMDIChildWnd::CMDIChildWnd
- AFXWIN/CMDIChildWnd::Create
- AFXWIN/CMDIChildWnd::GetMDIFrame
- AFXWIN/CMDIChildWnd::MDIActivate
- AFXWIN/CMDIChildWnd::MDIDestroy
- AFXWIN/CMDIChildWnd::MDIMaximize
- AFXWIN/CMDIChildWnd::MDIRestore
- AFXWIN/CMDIChildWnd::SetHandles
helpviewer_keywords:
- CMDIChildWnd [MFC], CMDIChildWnd
- CMDIChildWnd [MFC], Create
- CMDIChildWnd [MFC], GetMDIFrame
- CMDIChildWnd [MFC], MDIActivate
- CMDIChildWnd [MFC], MDIDestroy
- CMDIChildWnd [MFC], MDIMaximize
- CMDIChildWnd [MFC], MDIRestore
- CMDIChildWnd [MFC], SetHandles
ms.assetid: 6d07f5d4-9a3e-4723-9fa5-e65bb669fdd5
ms.openlocfilehash: 0fbcb47f3148b72a3155e7c17cc913d652c70c2e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370076"
---
# <a name="cmdichildwnd-class"></a>Classe CMDIChildWnd

Fornece a funcionalidade de uma janela de criança de interface de documento múltiplo do Windows (MDI), juntamente com os membros para gerenciar a janela.

## <a name="syntax"></a>Sintaxe

```
class CMDIChildWnd : public CFrameWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMDIChildWnd::CMDIChildWnd](#cmdichildwnd)|Constrói um objeto `CMDIChildWnd`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMDIChildWnd::Criar](#create)|Cria a janela de criança `CMDIChildWnd` MDI do Windows associada ao objeto.|
|[CMDIChildWnd::GetMDIFrame](#getmdiframe)|Retorna o quadro MDI pai da janela do cliente MDI.|
|[CMDIChildWnd::MDIActivate](#mdiactivate)|Ativa esta janela de criança MDI.|
|[CMDIChildWnd::MDIDestroy](#mdidestroy)|Destrói essa janela de criança smdi.|
|[CMDIChildWnd::MDIMaximize](#mdimaximize)|Maximiza essa janela de criança SMDI.|
|[CMDIChildWnd::MDIRestore](#mdirestore)|Restaura esta janela de criança MDI de tamanho maximizado ou minimizado.|
|[CMDIChildWnd::SetHandles](#sethandles)|Define as alças para os recursos do menu e do acelerador.|

## <a name="remarks"></a>Comentários

Uma janela de criança MDI se parece muito com uma janela de quadro típica, exceto que a janela do filho MDI aparece dentro de uma janela de quadro MDI em vez de na área de trabalho. Uma janela de criança MDI não tem uma barra de menu própria, mas compartilha o menu da janela de quadro SmDI. O framework altera automaticamente o menu de quadro SMDI para representar a janela de criança MDI atualmente ativa.

Para criar uma janela de criança MDI útil `CMDIChildWnd`para sua aplicação, obtenha uma classe de . Adicione variáveis de membro à classe derivada para armazenar dados específicos do seu aplicativo. Implemente funções de membro manipulador de mensagens e um mapa de mensagem na classe derivada para especificar o que acontece quando as mensagens são direcionadas para a janela.

Existem três maneiras de construir uma janela de criança SMDI:

- Construa-o `Create`diretamente usando .

- Construa-o `LoadFrame`diretamente usando .

- Construa-o indiretamente através de um modelo de documento.

Antes de `Create` `LoadFrame`ligar ou , você deve construir o objeto de janela de quadro no heap usando o **novo** operador C++. Antes `Create` de ligar, você também pode registrar uma classe de janela com a função global [AfxRegisterWndClass](application-information-and-management.md#afxregisterwndclass) para definir os estilos de ícone e classe para o quadro.

Use `Create` a função membro para passar os parâmetros de criação do quadro como argumentos imediatos.

`LoadFrame`requer menos argumentos do que `Create`, e, em vez disso, recupera a maioria de seus valores padrão de recursos, incluindo legenda do quadro, ícone, tabela do acelerador e menu. Para serem `LoadFrame`acessíveis por , todos esses recursos devem ter o mesmo ID de recurso (por exemplo, IDR_MAINFRAME).

Quando `CMDIChildWnd` um objeto contém visualizações e documentos, eles são criados indiretamente pela estrutura, em vez de diretamente pelo programador. O `CDocTemplate` objeto orquestra a criação do quadro, a criação das visualizações que contêm e a conexão das visualizações com o documento apropriado. Os parâmetros `CDocTemplate` da construtora `CRuntimeClass` especificam as três classes envolvidas (documento, quadro e exibição). Um `CRuntimeClass` objeto é usado pela estrutura para criar dinamicamente novos quadros quando especificado pelo usuário (por exemplo, usando o comando File New ou o comando MDI Window New).

Uma classe de janela `CMDIChildWnd` de quadro derivada deve ser declarada com DECLARE_DYNCREATE para que o mecanismo RUNTIME_CLASS acima funcione corretamente.

A `CMDIChildWnd` classe herda grande parte `CFrameWnd`de sua implementação padrão de . Para obter uma lista detalhada desses recursos, consulte a descrição da classe [CFrameWnd.](../../mfc/reference/cframewnd-class.md) A `CMDIChildWnd` classe tem os seguintes recursos adicionais:

- Em conjunto `CMultiDocTemplate` com a `CMDIChildWnd` classe, vários objetos do mesmo modelo de documento compartilham o mesmo menu, salvando recursos do sistema Windows.

- O menu de janela de criança MDI atualmente ativo substitui inteiramente o menu da janela do quadro MDI, e a legenda da janela de criança MDI atualmente ativa é adicionada à legenda da janela do quadro MDI. Para outros exemplos de funções de janela de criança MDI que são `CMDIFrameWnd` implementadas em conjunto com uma janela de quadro MDI, consulte a descrição da classe.

Não use o operador de **exclusão** C++ para destruir uma janela de quadro. Use `CWnd::DestroyWindow` em vez disso. A `CFrameWnd` implementação do `PostNcDestroy` excluirá o objeto C++ quando a janela for destruída. Quando o usuário fecha a janela `OnClose` do `DestroyWindow`quadro, o manipulador padrão chamará .

Para obter `CMDIChildWnd`mais informações, consulte [Frame Windows](../../mfc/frame-windows.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CFrameWnd](../../mfc/reference/cframewnd-class.md)

`CMDIChildWnd`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="cmdichildwndcmdichildwnd"></a><a name="cmdichildwnd"></a>CMDIChildWnd::CMDIChildWnd

Chame para `CMDIChildWnd` construir um objeto.

```
CMDIChildWnd();
```

### <a name="remarks"></a>Comentários

Ligue `Create` para criar a janela visível.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CMDIChildWnd::Create](#create).

## <a name="cmdichildwndcreate"></a><a name="create"></a>CMDIChildWnd::Criar

Chame esta função de membro para criar uma janela `CMDIChildWnd` de criança MDI do Windows e anexá-la ao objeto.

```
virtual BOOL Create(
    LPCTSTR lpszClassName,
    LPCTSTR lpszWindowName,
    DWORD dwStyle = WS_CHILD | WS_VISIBLE | WS_OVERLAPPEDWINDOW,
    const RECT& rect = rectDefault,
    CMDIFrameWnd* pParentWnd = NULL,
    CCreateContext* pContext = NULL);
```

### <a name="parameters"></a>Parâmetros

*Lpszclassname*<br/>
Aponta para uma seqüência de caracteres com término nulo que nomeia a classe Windows (uma estrutura [WNDCLASS).](/windows/win32/api/winuser/ns-winuser-wndclassw) O nome da classe pode ser qualquer nome registrado na função global [AfxRegisterWndClass.](application-information-and-management.md#afxregisterwndclass) Deve ser NULO `CMDIChildWnd`para um padrão .

*lpszWindowName*<br/>
Aponta para uma seqüência de caracteres com término nulo que representa o nome da janela. Usado como texto para a barra de título.

*Dwstyle*<br/>
Especifica os atributos de [estilo](../../mfc/reference/styles-used-by-mfc.md#window-styles) da janela. O estilo WS_CHILD é necessário.

*Rect*<br/>
Contém o tamanho e a posição da janela. O `rectDefault` valor permite que o Windows especifique o tamanho e a posição do novo `CMDIChildWnd`.

*Pparentwnd*<br/>
Especifica o pai da janela. Se NULA, a janela principal do aplicativo é usada.

*pContext*<br/>
Especifica uma estrutura [CCreateContext.](../../mfc/reference/ccreatecontext-structure.md) Este parâmetro pode ser NULO.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

A janela de quadro de filho MDI atualmente ativa pode determinar a legenda da janela do quadro pai. Este recurso é desativado desligando o FWS_ADDTOTITLE estilo bit da janela da moldura do filho.

A estrutura chama essa função de membro em resposta a um comando de usuário para criar uma janela filho, e a estrutura usa o parâmetro *pContext* para conectar adequadamente a janela filho ao aplicativo. Quando você `Create`chama , *pContext* pode ser NULO.

### <a name="example"></a>Exemplo

Exemplo 1:

[!code-cpp[NVC_MFCWindowing#7](../../mfc/reference/codesnippet/cpp/cmdichildwnd-class_1.cpp)]

### <a name="example"></a>Exemplo

Exemplo 2:

[!code-cpp[NVC_MFCWindowing#8](../../mfc/reference/codesnippet/cpp/cmdichildwnd-class_2.cpp)]

[!code-cpp[NVC_MFCWindowing#9](../../mfc/reference/codesnippet/cpp/cmdichildwnd-class_3.cpp)]

## <a name="cmdichildwndgetmdiframe"></a><a name="getmdiframe"></a>CMDIChildWnd::GetMDIFrame

Ligue para esta função para retornar o quadro pai DoM.

```
CMDIFrameWnd* GetMDIFrame();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para a janela de quadro pai MDI.

### <a name="remarks"></a>Comentários

O quadro devolvido é de `CMDIChildWnd` dois pais removidos do e é o pai `CMDIChildWnd` da janela do tipo MDICLIENT que gerencia o objeto. Ligue para a função [membro GetParent](../../mfc/reference/cwnd-class.md#getparent) para retornar o `CMDIChildWnd` pai `CWnd` Imediato do MDICLIENT do objeto como um ponteiro temporário.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CMDIFrameWnd::MDISetMenu](../../mfc/reference/cmdiframewnd-class.md#mdisetmenu).

## <a name="cmdichildwndmdiactivate"></a><a name="mdiactivate"></a>CMDIChildWnd::MDIActivate

Chame esta função de membro para ativar uma janela de criança MDI independentemente da janela do quadro MDI.

```
void MDIActivate();
```

### <a name="remarks"></a>Comentários

Quando o quadro se tornar ativo, a janela da criança que foi ativada pela última vez também será ativada.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CMDIFrameWnd::GetWindowMenuPopup](../../mfc/reference/cmdiframewnd-class.md#getwindowmenupopup).

## <a name="cmdichildwndmdidestroy"></a><a name="mdidestroy"></a>CMDIChildWnd::MDIDestroy

Chame esta função de membro para destruir uma janela de criança MDI.

```
void MDIDestroy();
```

### <a name="remarks"></a>Comentários

A função membro remove o título da janela do filho da janela do quadro e desativa a janela do filho.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#10](../../mfc/reference/codesnippet/cpp/cmdichildwnd-class_4.cpp)]

## <a name="cmdichildwndmdimaximize"></a><a name="mdimaximize"></a>CMDIChildWnd::MDIMaximize

Chame essa função de membro para maximizar uma janela de criança MDI.

```
void MDIMaximize();
```

### <a name="remarks"></a>Comentários

Quando uma janela filho é maximizada, o Windows redimensiona-a para fazer com que sua área cliente preencha a área cliente da janela do quadro. O Windows coloca o menu Controle da janela do filho na barra de menu do quadro para que o usuário possa restaurar ou fechar a janela do filho e adicionar o título da janela do filho ao título da janela de quadros.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#11](../../mfc/reference/codesnippet/cpp/cmdichildwnd-class_5.cpp)]

## <a name="cmdichildwndmdirestore"></a><a name="mdirestore"></a>CMDIChildWnd::MDIRestore

Chame esta função de membro para restaurar uma janela de criança MDI de tamanho maximizado ou minimizado.

```
void MDIRestore();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#12](../../mfc/reference/codesnippet/cpp/cmdichildwnd-class_6.cpp)]

## <a name="cmdichildwndsethandles"></a><a name="sethandles"></a>CMDIChildWnd::SetHandles

Define as alças para os recursos do menu e do acelerador.

```
void SetHandles(
    HMENU hMenu,
    HACCEL hAccel);
```

### <a name="parameters"></a>Parâmetros

*Hmenu*<br/>
A alça de um recurso de menu.

*hAccel*<br/>
A alça de um recurso do acelerador.

### <a name="remarks"></a>Comentários

Chame esta função para definir os recursos de menu e acelerador usados pelo objeto da janela de criança MDI.

## <a name="see-also"></a>Confira também

[MDI amostra MFC](../../overview/visual-cpp-samples.md)<br/>
[MFC Amostra MDIDOCVW](../../overview/visual-cpp-samples.md)<br/>
[Amostra de MFC SNAPVW](../../overview/visual-cpp-samples.md)<br/>
[Classe CFrameWnd](../../mfc/reference/cframewnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Classe CMDIFrameWnd](../../mfc/reference/cmdiframewnd-class.md)
