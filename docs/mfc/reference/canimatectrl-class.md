---
title: Classe CAnimateCtrl
ms.date: 11/04/2016
f1_keywords:
- CAnimateCtrl
- AFXCMN/CAnimateCtrl
- AFXCMN/CAnimateCtrl::CAnimateCtrl
- AFXCMN/CAnimateCtrl::Close
- AFXCMN/CAnimateCtrl::Create
- AFXCMN/CAnimateCtrl::CreateEx
- AFXCMN/CAnimateCtrl::IsPlaying
- AFXCMN/CAnimateCtrl::Open
- AFXCMN/CAnimateCtrl::Play
- AFXCMN/CAnimateCtrl::Seek
- AFXCMN/CAnimateCtrl::Stop
helpviewer_keywords:
- CAnimateCtrl [MFC], CAnimateCtrl
- CAnimateCtrl [MFC], Close
- CAnimateCtrl [MFC], Create
- CAnimateCtrl [MFC], CreateEx
- CAnimateCtrl [MFC], IsPlaying
- CAnimateCtrl [MFC], Open
- CAnimateCtrl [MFC], Play
- CAnimateCtrl [MFC], Seek
- CAnimateCtrl [MFC], Stop
ms.assetid: 5e8eb1bd-96b7-47b8-8de2-6bcbb3cc299b
ms.openlocfilehash: fcee569659d732c26e274c8ca189042a16f13557
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371055"
---
# <a name="canimatectrl-class"></a>Classe CAnimateCtrl

Fornece a funcionalidade do controle de animação comum do Windows.

## <a name="syntax"></a>Sintaxe

```
class CAnimateCtrl : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimateCtrl::CAnimateCtrl](#canimatectrl)|Constrói um objeto `CAnimateCtrl`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimateCtrl::Fechar](#close)|Fecha o clipe AVI.|
|[CAnimateCtrl::Criar](#create)|Cria um controle de animação `CAnimateCtrl` e o anexa a um objeto.|
|[CAnimateCtrl::CreateEx](#createex)|Cria um controle de animação com os estilos estendidos do Windows especificados e o anexa a um `CAnimateCtrl` objeto.|
|[CAnimateCtrl:::Estájogando](#isplaying)|Indica se um clipe de Áudio-Vídeo Interleaved (AVI) está sendo reproduzido.|
|[CAnimateCtrl::Aberto](#open)|Abre um clipe AVI a partir de um arquivo ou recurso e exibe o primeiro quadro.|
|[CAnimateCtrl::Play](#play)|Reproduz o clipe AVI sem som.|
|[CAnimateCtrl::Buscar](#seek)|Exibe um quadro único selecionado do clipe AVI.|
|[CAnimateCtrl::Stop](#stop)|Pare de reproduzir o clipe AVI.|

## <a name="remarks"></a>Comentários

Este controle (e, `CAnimateCtrl` portanto, a classe) está disponível apenas para programas executados no Windows 95, Windows 98 e Windows NT versão 3.51 e posterior.

Um controle de animação é uma janela retangular que exibe um clipe no formato AVI (Audio Video Interleaved), o formato padrão de vídeo/áudio do Windows. Um clipe AVI é uma série de quadros bitmap, como um filme.

Os controles de animação podem reproduzir apenas clipes AVI simples. Especificamente, os clipes a serem reproduzidos por um controle de animação devem atender aos seguintes requisitos:

- Deve haver exatamente um fluxo de vídeo e deve ter pelo menos um quadro.

- Pode haver no máximo dois fluxos no arquivo (normalmente o outro fluxo, se presente, é um fluxo de áudio, embora o controle de animação ignore as informações de áudio).

- O clipe deve ser descompactado ou comprimido com compactação RLE8.

- Não são permitidas alterações na paleta no fluxo de vídeo.

Você pode adicionar o clipe AVI ao seu aplicativo como um recurso AVI, ou ele pode acompanhar sua aplicação como um arquivo AVI separado.

Como o segmento continua a ser executado enquanto o clipe AVI é exibido, um uso comum para um controle de animação é indicar a atividade do sistema durante uma operação demorada. Por exemplo, a caixa de diálogo Encontrar do File Explorer exibe uma lupa móvel à medida que o sistema procura por um arquivo.

Se você `CAnimateCtrl` criar um objeto dentro de uma caixa de diálogo ou de um recurso de diálogo usando o editor de diálogo, ele será automaticamente destruído quando o usuário fechar a caixa de diálogo.

Se você `CAnimateCtrl` criar um objeto dentro de uma janela, talvez precise destruí-lo. Se você `CAnimateCtrl` criar o objeto na pilha, ele será destruído automaticamente. Se você `CAnimateCtrl` criar o objeto no heap usando a **nova** função, você deve chamar **excluir** no objeto para destruí-lo. Se você derivar `CAnimateCtrl` uma nova classe e alocar `CAnimateCtrl` qualquer memória nessa classe, anular o destruidor para descartar as alocações.

Para obter mais `CAnimateCtrl`informações sobre como usar, consulte [Controles](../../mfc/controls-mfc.md) e [Usando CAnimateCtrl](../../mfc/using-canimatectrl.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CAnimateCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcmn.h

## <a name="canimatectrlcanimatectrl"></a><a name="canimatectrl"></a>CAnimateCtrl::CAnimateCtrl

Constrói um objeto `CAnimateCtrl`.

```
CAnimateCtrl();
```

### <a name="remarks"></a>Comentários

Você deve chamar a função [Criar](#create) membro antes de executar quaisquer outras operações no objeto que você criar.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCControlLadenDialog#56](../../mfc/codesnippet/cpp/canimatectrl-class_1.cpp)]

## <a name="canimatectrlclose"></a><a name="close"></a>CAnimateCtrl::Fechar

Fecha o clipe AVI que foi aberto anteriormente no controle de animação (se houver) e o remove da memória.

```
BOOL Close();
```

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, zero.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CAnimateCtrl::CAnimateCtrl](#canimatectrl).

## <a name="canimatectrlcreate"></a><a name="create"></a>CAnimateCtrl::Criar

Cria um controle de animação `CAnimateCtrl` e o anexa a um objeto.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*Dwstyle*<br/>
Especifica o estilo do controle de animação. Aplique qualquer combinação dos estilos do windows descritos na seção Observações abaixo e os estilos de controle de animação descritos em [Estilos de Controle de Animação](/windows/win32/Controls/animation-control-styles) no SDK do Windows.

*Rect*<br/>
Especifica a posição e o tamanho do controle de animação. Pode ser um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) ou uma estrutura [RECT.](/windows/win32/api/windef/ns-windef-rect)

*Pparentwnd*<br/>
Especifica a janela pai do controle `CDialog`de animação, geralmente um . Não deve ser NULO.

*nID*<br/>
Especifica o ID do controle de animação.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, zero.

### <a name="remarks"></a>Comentários

Você constrói `CAnimateCtrl` um em dois passos. Primeiro, chame o construtor e, em seguida, chame, `Create`que `CAnimateCtrl` cria o controle de animação e o anexa ao objeto.

Aplique os [seguintes estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) a um controle de animação.

- WS_CHILD Sempre

- WS_VISIBLE Normalmente

- WS_DISABLED raramente

Se você quiser usar estilos de windows estendidos com `Create`seu controle de animação, chame [CreateEx](#createex) em vez de .

Além dos estilos de janela listados acima, você pode querer aplicar um ou mais dos estilos de controle de animação a um controle de animação. Consulte o Windows SDK para obter mais informações sobre [estilos de controle de animação](/windows/win32/Controls/animation-control-styles).

### <a name="example"></a>Exemplo

  Veja o exemplo de [CAnimateCtrl::CAnimateCtrl](#canimatectrl).

## <a name="canimatectrlcreateex"></a><a name="createex"></a>CAnimateCtrl::CreateEx

Cria um controle (uma janela filho) `CAnimateCtrl` e o associa ao objeto.

```
virtual BOOL CreateEx(
    DWORD dwExStyle,
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*Dwexstyle*<br/>
Especifica o estilo estendido do controle que está sendo criado. Para obter uma lista de estilos estendidos do Windows, consulte o parâmetro *dwExStyle* para [CreateWindowEx](/windows/win32/api/winuser/nf-winuser-createwindowexw) no SDK do Windows.

*Dwstyle*<br/>
Especifica o estilo do controle de animação. Aplique qualquer combinação dos estilos de controle de janela e animação descritos em [Estilos de controle de animação](/windows/win32/Controls/animation-control-styles) no SDK do Windows.

*Rect*<br/>
Uma referência a uma estrutura [RECT](/previous-versions/dd162897\(v=vs.85\)) descrevendo o tamanho e a posição da janela a ser criada, em coordenadas de cliente de *pParentWnd*.

*Pparentwnd*<br/>
Um ponteiro para a janela que é o pai do controle.

*nID*<br/>
A id da janela infantil do controle.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Use `CreateEx` em vez de [Criar](#create) para aplicar estilos estendidos do Windows, especificados pelo prefácio de estilo estendido do Windows **WS_EX_**.

## <a name="canimatectrlisplaying"></a><a name="isplaying"></a>CAnimateCtrl:::Estájogando

Indica se um clipe de Áudio-Vídeo Interleaved (AVI) está sendo reproduzido.

```
BOOL IsPlaying() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se um clipe AVI estiver sendo reproduzido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este método envia a mensagem [ACM_ISPLAYING,](/windows/win32/Controls/acm-isplaying) que é descrita no SDK do Windows.

## <a name="canimatectrlopen"></a><a name="open"></a>CAnimateCtrl::Aberto

Chame esta função para abrir um clipe AVI e exibir seu primeiro quadro.

```
BOOL Open(LPCTSTR lpszFileName);
BOOL Open(UINT nID);
```

### <a name="parameters"></a>Parâmetros

*lpszFileName*<br/>
Um `CString` objeto ou um ponteiro para uma seqüência de seqüência sem fim que contém o nome do arquivo AVI ou o nome de um recurso AVI. Se este parâmetro for NULO, o sistema fechará o clipe AVI que foi aberto anteriormente para o controle de animação, se houver.

*nID*<br/>
O identificador de recursos AVI. Se este parâmetro for NULO, o sistema fechará o clipe AVI que foi aberto anteriormente para o controle de animação, se houver.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, zero.

### <a name="remarks"></a>Comentários

O recurso AVI é carregado a partir do módulo que criou o controle de animação.

`Open`não suporta som em um clipe AVI; você pode abrir apenas clipes AVI silenciosos.

Se o controle `ACS_AUTOPLAY` de animação tiver o estilo, o controle de animação começará automaticamente a reproduzir o clipe imediatamente após sua abertura. Ele continuará a reproduzir o clipe em segundo plano enquanto seu segmento continua sendo executado. Quando o clipe terminar de tocar, ele será automaticamente repetido.

Se o controle `ACS_CENTER` de animação tiver o estilo, o clipe AVI será centrado no controle e o tamanho do controle não mudará. Se o controle de `ACS_CENTER` animação não tiver o estilo, o controle será redimensionado quando o clipe AVI for aberto ao tamanho das imagens no clipe AVI. A posição do canto superior esquerdo do controle não mudará, apenas o tamanho do controle.

Se o controle `ACS_TRANSPARENT` de animação tiver o estilo, o primeiro quadro será desenhado usando um fundo transparente em vez da cor de fundo especificada no clipe de animação.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CAnimateCtrl::CAnimateCtrl](#canimatectrl).

## <a name="canimatectrlplay"></a><a name="play"></a>CAnimateCtrl::Play

Chame esta função para reproduzir um clipe AVI em um controle de animação.

```
BOOL Play(
    UINT nFrom,
    UINT nTo,
    UINT nRep);
```

### <a name="parameters"></a>Parâmetros

*nFrom*<br/>
Índice baseado em zero do quadro onde o jogo começa. O valor deve ser inferior a 65.536. Um valor de 0 significa começar com o primeiro quadro no clipe AVI.

*nTo*<br/>
Índice baseado em zero do quadro onde o jogo termina. O valor deve ser inferior a 65.536. Um valor de - 1 significa terminar com o último quadro no clipe AVI.

*nRep*<br/>
Número de vezes para reproduzir o clipe AVI. Um valor de - 1 significa reproduzir o arquivo indefinidamente.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, zero.

### <a name="remarks"></a>Comentários

O controle de animação reproduzirá o clipe em segundo plano enquanto seu segmento continua sendo executado. Se o controle `ACS_TRANSPARENT` de animação tiver estilo, o clipe AVI será reproduzido usando um fundo transparente em vez da cor de fundo especificada no clipe de animação.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CAnimateCtrl::CAnimateCtrl](#canimatectrl).

## <a name="canimatectrlseek"></a><a name="seek"></a>CAnimateCtrl::Buscar

Chame esta função para exibir estáticamente um único quadro do seu clipe AVI.

```
BOOL Seek(UINT nTo);
```

### <a name="parameters"></a>Parâmetros

*nTo*<br/>
Índice baseado em zero do quadro a ser exibido. O valor deve ser inferior a 65.536. Um valor de 0 significa exibir o primeiro quadro no clipe AVI. Um valor de -1 significa exibir o último quadro no clipe AVI.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, zero.

### <a name="remarks"></a>Comentários

Se o controle `ACS_TRANSPARENT` de animação tiver estilo, o clipe AVI será desenhado usando um fundo transparente em vez da cor de fundo especificada no clipe de animação.

### <a name="example"></a>Exemplo

Veja o exemplo de [CAnimateCtrl::CAnimateCtrl](#canimatectrl).

## <a name="canimatectrlstop"></a><a name="stop"></a>CAnimateCtrl::Stop

Chame esta função para parar de reproduzir um clipe AVI em um controle de animação.

```
BOOL Stop();
```

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, zero.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CAnimateCtrl::CAnimateCtrl](#canimatectrl).

## <a name="see-also"></a>Confira também

[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[CAnimateCtrl::Criar](#create)<br/>
[ON_CONTROL](message-map-macros-mfc.md#on_control)
