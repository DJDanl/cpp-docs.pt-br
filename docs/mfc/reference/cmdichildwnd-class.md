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
ms.openlocfilehash: 09a9846cc3d242ef7d812cb31b4dcdd515d5f6ef
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69506073"
---
# <a name="cmdichildwnd-class"></a>Classe CMDIChildWnd

Fornece a funcionalidade de uma janela filho MDI (interface de vários documentos do Windows), juntamente com membros para gerenciar a janela.

## <a name="syntax"></a>Sintaxe

```
class CMDIChildWnd : public CFrameWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMDIChildWnd:: CMDIChildWnd](#cmdichildwnd)|Constrói um objeto `CMDIChildWnd`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMDIChildWnd:: criar](#create)|Cria a janela filho MDI do Windows associada `CMDIChildWnd` ao objeto.|
|[CMDIChildWnd::GetMDIFrame](#getmdiframe)|Retorna o quadro MDI pai da janela do cliente MDI.|
|[CMDIChildWnd:: MDIActivate](#mdiactivate)|Ativa esta janela filho MDI.|
|[CMDIChildWnd::MDIDestroy](#mdidestroy)|Destrói esta janela filho MDI.|
|[CMDIChildWnd::MDIMaximize](#mdimaximize)|Maximiza esta janela filho MDI.|
|[CMDIChildWnd::MDIRestore](#mdirestore)|Restaura esta janela filho MDI do tamanho maximizado ou minimizado.|
|[CMDIChildWnd:: sethands](#sethandles)|Define os identificadores para os recursos de menu e acelerador.|

## <a name="remarks"></a>Comentários

Uma janela filho MDI se parece muito com uma janela de quadro típica, exceto que a janela filho MDI aparece dentro de uma janela de quadro MDI em vez de na área de trabalho. Uma janela filho MDI não tem uma barra de menus própria, mas, em vez disso, compartilha o menu da janela do quadro MDI. A estrutura altera automaticamente o menu de quadro MDI para representar a janela filho MDI ativa no momento.

Para criar uma janela filho MDI útil para seu aplicativo, derive uma classe `CMDIChildWnd`de. Adicione variáveis de membro à classe derivada para armazenar dados específicos ao seu aplicativo. Implemente funções de membro do manipulador de mensagens e um mapa de mensagens na classe derivada para especificar o que acontece quando as mensagens são direcionadas para a janela.

Há três maneiras de construir uma janela filho MDI:

- Construí-lo diretamente `Create`usando.

- Construí-lo diretamente `LoadFrame`usando.

- Construí-lo indiretamente por meio de um modelo de documento.

Antes de chamar `Create` ou `LoadFrame`, você deve construir o objeto quadro-janela no heap usando o C++ operador **novo** . Antes de `Create` chamar, você também pode registrar uma classe de janela com a função global [AfxRegisterWndClass](application-information-and-management.md#afxregisterwndclass) para definir os estilos de ícone e classe para o quadro.

Use a `Create` função membro para passar os parâmetros de criação do quadro como argumentos imediatos.

`LoadFrame`requer menos argumentos que `Create`e, em vez disso, recupera a maioria de seus valores padrão de recursos, incluindo a legenda, o ícone, a tabela de acelerador e o menu do quadro. Para ser acessível pelo `LoadFrame`, todos esses recursos devem ter a mesma ID de recurso (por exemplo, IDR_MAINFRAME).

Quando um `CMDIChildWnd` objeto contém exibições e documentos, eles são criados indiretamente pela estrutura em vez de diretamente pelo programador. O `CDocTemplate` objeto orquestra a criação do quadro, a criação das exibições que as contém e a conexão das exibições para o documento apropriado. Os parâmetros do `CDocTemplate` Construtor especificam as `CRuntimeClass` três classes envolvidas (documento, quadro e exibição). Um `CRuntimeClass` objeto é usado pela estrutura para criar dinamicamente novos quadros quando especificado pelo usuário (por exemplo, usando o comando arquivo New ou a janela MDI New).

Uma classe de janela de quadro derivada `CMDIChildWnd` de deve ser declarada com DECLARE_DYNCREATE para que o mecanismo de RUNTIME_CLASS acima funcione corretamente.

A `CMDIChildWnd` classe herda grande parte de sua implementação padrão `CFrameWnd`do. Para obter uma lista detalhada desses recursos, consulte a descrição da classe [CFrameWnd](../../mfc/reference/cframewnd-class.md) . A `CMDIChildWnd` classe tem os seguintes recursos adicionais:

- Em conjunto com a `CMultiDocTemplate` classe, vários `CMDIChildWnd` objetos do mesmo modelo de documento compartilham o mesmo menu, salvando os recursos do sistema Windows.

- O menu da janela filho MDI ativo no momento substitui totalmente o menu da janela do quadro MDI e a legenda da janela filho MDI ativa no momento é adicionada à legenda da janela do quadro MDI. Para obter mais exemplos de funções de janela filho MDI que são implementadas em conjunto com uma janela de quadro `CMDIFrameWnd` MDI, consulte a descrição da classe.

Não use o C++ operador **delete** para destruir uma janela de quadro. Use `CWnd::DestroyWindow` em seu lugar. A `CFrameWnd` implementação do `PostNcDestroy` irá excluir o C++ objeto quando a janela for destruída. Quando o usuário fechar a janela do quadro, o `OnClose` manipulador padrão chamará. `DestroyWindow`

Para obter mais informações `CMDIChildWnd`sobre o, consulte [janelas de quadros](../../mfc/frame-windows.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CFrameWnd](../../mfc/reference/cframewnd-class.md)

`CMDIChildWnd`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

##  <a name="cmdichildwnd"></a>CMDIChildWnd:: CMDIChildWnd

Chamada para construir um `CMDIChildWnd` objeto.

```
CMDIChildWnd();
```

### <a name="remarks"></a>Comentários

Chame `Create` para criar a janela visível.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CMDIChildWnd:: Create](#create).

##  <a name="create"></a>CMDIChildWnd:: criar

Chame essa função de membro para criar uma janela filho MDI do `CMDIChildWnd` Windows e anexá-la ao objeto.

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

*lpszClassName*<br/>
Aponta para uma cadeia de caracteres terminada em nulo que nomeia a classe do Windows (uma estrutura [WNDCLASS](/windows/win32/api/winuser/ns-winuser-wndclassw) ). O nome da classe pode ser qualquer nome registrado com a função global [AfxRegisterWndClass](application-information-and-management.md#afxregisterwndclass) . Deve ser NULL para um padrão `CMDIChildWnd`.

*lpszWindowName*<br/>
Aponta para uma cadeia de caracteres de caractere terminada em nulo que representa o nome da janela. Usado como texto para a barra de título.

*dwStyle*<br/>
Especifica os atributos de [estilo](../../mfc/reference/styles-used-by-mfc.md#window-styles) de janela. O estilo WS_CHILD é obrigatório.

*rect*<br/>
Contém o tamanho e a posição da janela. O `rectDefault` valor permite que o Windows especifique o tamanho e a posição do `CMDIChildWnd`novo.

*pParentWnd*<br/>
Especifica o pai da janela. Se for NULL, a janela principal do aplicativo será usada.

*pContext*<br/>
Especifica uma estrutura [CCreateContext](../../mfc/reference/ccreatecontext-structure.md) . Esse parâmetro pode ser nulo.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

A janela de quadro filho MDI ativa no momento pode determinar a legenda da janela do quadro pai. Esse recurso é desabilitado desativando o FWS_ADDTOTITLE de estilo da janela do quadro filho.

A estrutura chama essa função de membro em resposta a um comando de usuário para criar uma janela filho, e a estrutura usa o parâmetro *pContext* para conectar corretamente a janela filho ao aplicativo. Quando você chama `Create`, *pContext* pode ser nulo.

### <a name="example"></a>Exemplo

Exemplo 1:

[!code-cpp[NVC_MFCWindowing#7](../../mfc/reference/codesnippet/cpp/cmdichildwnd-class_1.cpp)]

### <a name="example"></a>Exemplo

Exemplo 2:

[!code-cpp[NVC_MFCWindowing#8](../../mfc/reference/codesnippet/cpp/cmdichildwnd-class_2.cpp)]

[!code-cpp[NVC_MFCWindowing#9](../../mfc/reference/codesnippet/cpp/cmdichildwnd-class_3.cpp)]

##  <a name="getmdiframe"></a>  CMDIChildWnd::GetMDIFrame

Chame essa função para retornar o quadro pai MDI.

```
CMDIFrameWnd* GetMDIFrame();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a janela do quadro pai MDI.

### <a name="remarks"></a>Comentários

O quadro retornado é dois pais removidos do `CMDIChildWnd` e é o pai da janela do tipo MDICLIENT que gerencia o `CMDIChildWnd` objeto. Chame a função de membro [GetParent](../../mfc/reference/cwnd-class.md#getparent) para retornar `CMDIChildWnd` o pai MdiClient imediato do objeto como um `CWnd` ponteiro temporário.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CMDIFrameWnd:: MDISetMenu](../../mfc/reference/cmdiframewnd-class.md#mdisetmenu).

##  <a name="mdiactivate"></a>CMDIChildWnd:: MDIActivate

Chame essa função de membro para ativar uma janela filho MDI independentemente da janela do quadro MDI.

```
void MDIActivate();
```

### <a name="remarks"></a>Comentários

Quando o quadro se torna ativo, a janela filho que foi ativada pela última vez também será ativada.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CMDIFrameWnd:: GetWindowMenuPopup](../../mfc/reference/cmdiframewnd-class.md#getwindowmenupopup).

##  <a name="mdidestroy"></a>  CMDIChildWnd::MDIDestroy

Chame essa função de membro para destruir uma janela filho MDI.

```
void MDIDestroy();
```

### <a name="remarks"></a>Comentários

A função membro remove o título da janela filho da janela do quadro e desativa a janela filho.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#10](../../mfc/reference/codesnippet/cpp/cmdichildwnd-class_4.cpp)]

##  <a name="mdimaximize"></a>  CMDIChildWnd::MDIMaximize

Chame essa função de membro para maximizar uma janela filho MDI.

```
void MDIMaximize();
```

### <a name="remarks"></a>Comentários

Quando uma janela filho é maximizada, o Windows a redimensiona para fazer com que sua área cliente preencha a área cliente da janela do quadro. O Windows coloca o menu de controle da janela filho na barra de menus do quadro para que o usuário possa restaurar ou fechar a janela filho e adicionar o título da janela filho ao título da janela do quadro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#11](../../mfc/reference/codesnippet/cpp/cmdichildwnd-class_5.cpp)]

##  <a name="mdirestore"></a>  CMDIChildWnd::MDIRestore

Chame essa função de membro para restaurar uma janela filho MDI do tamanho maximizado ou minimizado.

```
void MDIRestore();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#12](../../mfc/reference/codesnippet/cpp/cmdichildwnd-class_6.cpp)]

##  <a name="sethandles"></a>CMDIChildWnd:: sethands

Define os identificadores para os recursos de menu e acelerador.

```
void SetHandles(
    HMENU hMenu,
    HACCEL hAccel);
```

### <a name="parameters"></a>Parâmetros

*hMenu*<br/>
O identificador de um recurso de menu.

*hAccel*<br/>
O identificador de um recurso de acelerador.

### <a name="remarks"></a>Comentários

Chame essa função para definir o menu e os recursos de aceleração usados pelo objeto de janela filho MDI.

## <a name="see-also"></a>Consulte também

[MDI de exemplo do MFC](../../overview/visual-cpp-samples.md)<br/>
[Exemplo de MDIDOCVW do MFC](../../overview/visual-cpp-samples.md)<br/>
[Exemplo de SNAPVW do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CFrameWnd](../../mfc/reference/cframewnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Classe CMDIFrameWnd](../../mfc/reference/cmdiframewnd-class.md)
