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
ms.openlocfilehash: 651b5775886374f3fcc95ab6b2cb3d892d9d77e8
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87183377"
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
|[CAnimateCtrl:: fechar](#close)|Fecha o clipe AVI.|
|[CAnimateCtrl:: criar](#create)|Cria um controle de animação e o anexa a um `CAnimateCtrl` objeto.|
|[CAnimateCtrl::CreateEx](#createex)|Cria um controle de animação com os estilos estendidos do Windows especificados e o anexa a um `CAnimateCtrl` objeto.|
|[CAnimateCtrl:: IsPlaying](#isplaying)|Indica se um clipe AVI (áudio-video intercalado) está sendo reproduzido.|
|[CAnimateCtrl:: abrir](#open)|Abre um clipe AVI de um arquivo ou recurso e exibe o primeiro quadro.|
|[CAnimateCtrl::P deite](#play)|Reproduz o clipe AVI sem som.|
|[CAnimateCtrl:: Seek](#seek)|Exibe um único quadro selecionado do clipe AVI.|
|[CAnimateCtrl:: Stop](#stop)|Interrompe a reprodução do clipe AVI.|

## <a name="remarks"></a>Comentários

Esse controle (e, portanto, a `CAnimateCtrl` classe) está disponível somente para programas em execução no windows 95, windows 98 e Windows NT versão 3,51 e posterior.

Um controle de animação é uma janela retangular que exibe um clipe no formato AVI (áudio vídeo intercalado) — o formato padrão de vídeo/áudio do Windows. Um clipe AVI é uma série de quadros de bitmap, como um filme.

Os controles de animação podem reproduzir apenas clipes AVI simples. Especificamente, os clipes a serem reproduzidos por um controle de animação devem atender aos seguintes requisitos:

- Deve haver exatamente um fluxo de vídeo e deve ter pelo menos um quadro.

- Pode haver no máximo dois fluxos no arquivo (normalmente, o outro fluxo, se presente, é um fluxo de áudio, embora o controle de animação ignore as informações de áudio).

- O clipe deve ser descompactado ou compactado com compactação RLE8.

- Nenhuma alteração de paleta é permitida no fluxo de vídeo.

Você pode adicionar o clipe AVI ao seu aplicativo como um recurso AVI ou ele pode acompanhar seu aplicativo como um arquivo AVI separado.

Como seu thread continua sendo executado enquanto o clipe AVI é exibido, um uso comum para um controle de animação é para indicar a atividade do sistema durante uma operação demorada. Por exemplo, a caixa de diálogo Localizar do explorador de arquivos exibe uma lupa movendo à medida que o sistema procura um arquivo.

Se você criar um `CAnimateCtrl` objeto dentro de uma caixa de diálogo ou de um recurso de diálogo usando o editor de caixa de diálogo, ele será destruído automaticamente quando o usuário fechar a caixa de diálogo.

Se você criar um `CAnimateCtrl` objeto em uma janela, talvez seja necessário destruí-lo. Se você criar o `CAnimateCtrl` objeto na pilha, ele será destruído automaticamente. Se você criar o `CAnimateCtrl` objeto no heap usando a **`new`** função, deverá chamar **`delete`** no objeto para destruí-lo. Se você derivar uma nova classe de `CAnimateCtrl` e alocar qualquer memória nessa classe, substitua o `CAnimateCtrl` destruidor para descartar as alocações.

Para obter mais informações sobre como usar o `CAnimateCtrl` , consulte [controles](../../mfc/controls-mfc.md) e [usando CAnimateCtrl](../../mfc/using-canimatectrl.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CAnimateCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcmn. h

## <a name="canimatectrlcanimatectrl"></a><a name="canimatectrl"></a>CAnimateCtrl::CAnimateCtrl

Constrói um objeto `CAnimateCtrl`.

```
CAnimateCtrl();
```

### <a name="remarks"></a>Comentários

Você deve chamar a função [criar](#create) membro antes de poder executar qualquer outra operação no objeto que criar.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCControlLadenDialog#56](../../mfc/codesnippet/cpp/canimatectrl-class_1.cpp)]

## <a name="canimatectrlclose"></a><a name="close"></a>CAnimateCtrl:: fechar

Fecha o clipe AVI que foi aberto anteriormente no controle de animação (se houver) e o Remove da memória.

```
BOOL Close();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, zero.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CAnimateCtrl:: CAnimateCtrl](#canimatectrl).

## <a name="canimatectrlcreate"></a><a name="create"></a>CAnimateCtrl:: criar

Cria um controle de animação e o anexa a um `CAnimateCtrl` objeto.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>parâmetros

*dwStyle*<br/>
Especifica o estilo do controle de animação. Aplique qualquer combinação dos estilos do Windows descritos na seção comentários abaixo e os estilos de controle de animação descritos em [estilos de controle de animação](/windows/win32/Controls/animation-control-styles) na SDK do Windows.

*Rect*<br/>
Especifica a posição e o tamanho do controle de animação. Pode ser um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) ou uma estrutura [Rect](/windows/win32/api/windef/ns-windef-rect) .

*pParentWnd*<br/>
Especifica a janela pai do controle de animação, geralmente um `CDialog` . Ele não deve ser nulo.

*nID*<br/>
Especifica a ID do controle de animação.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, zero.

### <a name="remarks"></a>Comentários

Você constrói um `CAnimateCtrl` em duas etapas. Primeiro, chame o construtor e, em seguida, chame `Create` , que cria o controle de animação e o anexa ao `CAnimateCtrl` objeto.

Aplique os seguintes [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) a um controle de animação.

- WS_CHILD sempre

- Geralmente WS_VISIBLE

- WS_DISABLED raramente

Se você quiser usar estilos estendidos do Windows com seu controle de animação, chame [CreateEx](#createex) em vez de `Create` .

Além dos estilos de janela listados acima, talvez você queira aplicar um ou mais estilos de controle de animação a um controle de animação. Consulte a SDK do Windows para obter mais informações sobre [estilos de controle de animação](/windows/win32/Controls/animation-control-styles).

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CAnimateCtrl:: CAnimateCtrl](#canimatectrl).

## <a name="canimatectrlcreateex"></a><a name="createex"></a>CAnimateCtrl::CreateEx

Cria um controle (uma janela filho) e o associa ao `CAnimateCtrl` objeto.

```
virtual BOOL CreateEx(
    DWORD dwExStyle,
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>parâmetros

*dwExStyle*<br/>
Especifica o estilo estendido do controle que está sendo criado. Para obter uma lista de estilos estendidos do Windows, consulte o parâmetro *dwExStyle* para [CreateWindowEx](/windows/win32/api/winuser/nf-winuser-createwindowexw) no SDK do Windows.

*dwStyle*<br/>
Especifica o estilo do controle de animação. Aplique qualquer combinação dos estilos de controle de janela e animação descritos em [estilos de controle de animação](/windows/win32/Controls/animation-control-styles) no SDK do Windows.

*Rect*<br/>
Uma referência a uma estrutura [Rect](/windows/win32/api/windef/ns-windef-rect) que descreve o tamanho e a posição da janela a ser criada, nas coordenadas de cliente de *pParentWnd*.

*pParentWnd*<br/>
Um ponteiro para a janela que é o pai do controle.

*nID*<br/>
A ID da janela filho do controle.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Use `CreateEx` em vez de [Create](#create) para aplicar estilos estendidos do Windows, especificados pelo **WS_EX_** de prefácio de estilo estendido do Windows.

## <a name="canimatectrlisplaying"></a><a name="isplaying"></a>CAnimateCtrl:: IsPlaying

Indica se um clipe AVI (áudio-video intercalado) está sendo reproduzido.

```
BOOL IsPlaying() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se um clipe AVI estiver em execução; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método envia a mensagem de [ACM_ISPLAYING](/windows/win32/Controls/acm-isplaying) , que é descrita na SDK do Windows.

## <a name="canimatectrlopen"></a><a name="open"></a>CAnimateCtrl:: abrir

Chame essa função para abrir um clipe AVI e exibir seu primeiro quadro.

```
BOOL Open(LPCTSTR lpszFileName);
BOOL Open(UINT nID);
```

### <a name="parameters"></a>parâmetros

*lpszFileName*<br/>
Um `CString` objeto ou um ponteiro para uma cadeia de caracteres terminada em nulo que contém o nome do arquivo AVI ou o nome de um recurso avi. Se esse parâmetro for nulo, o sistema fechará o clipe AVI que foi aberto anteriormente para o controle de animação, se houver.

*nID*<br/>
O identificador de recurso AVI. Se esse parâmetro for nulo, o sistema fechará o clipe AVI que foi aberto anteriormente para o controle de animação, se houver.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, zero.

### <a name="remarks"></a>Comentários

O recurso AVI é carregado a partir do módulo que criou o controle de animação.

`Open`não oferece suporte a som em um clipe AVI; Você só pode abrir clipes AVI silenciosos.

Se o controle de animação tiver o `ACS_AUTOPLAY` estilo, o controle de animação iniciará automaticamente a reprodução do clipe imediatamente depois de abri-lo. Ele continuará a reproduzir o clipe em segundo plano enquanto o thread continua em execução. Quando o clipe terminar a execução, ele será repetido automaticamente.

Se o controle de animação tiver o `ACS_CENTER` estilo, o clipe AVI será centralizado no controle e o tamanho do controle não será alterado. Se o controle de animação não tiver o `ACS_CENTER` estilo, o controle será redimensionado quando o clipe AVI for aberto para o tamanho das imagens no clipe AVI. A posição do canto superior esquerdo do controle não será alterada, somente o tamanho do controle.

Se o controle de animação tiver o `ACS_TRANSPARENT` estilo, o primeiro quadro será desenhado usando uma tela de fundo transparente em vez da cor do plano de fundo especificada no clipe de animação.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CAnimateCtrl:: CAnimateCtrl](#canimatectrl).

## <a name="canimatectrlplay"></a><a name="play"></a>CAnimateCtrl::P deite

Chame essa função para reproduzir um clipe AVI em um controle de animação.

```
BOOL Play(
    UINT nFrom,
    UINT nTo,
    UINT nRep);
```

### <a name="parameters"></a>parâmetros

*Nde*<br/>
O índice de base zero do quadro em que a execução começa. O valor deve ser menor que 65.536. Um valor de 0 significa começar com o primeiro quadro no clipe AVI.

*nPara*<br/>
Índice de base zero do quadro em que a execução termina. O valor deve ser menor que 65.536. Um valor de-1 significa terminar com o último quadro no clipe AVI.

*nRep*<br/>
Número de vezes para reproduzir o clipe AVI. Um valor de-1 significa repetir o arquivo indefinidamente.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, zero.

### <a name="remarks"></a>Comentários

O controle de animação reproduzirá o clipe em segundo plano enquanto seu thread continuará em execução. Se o controle de animação tiver um `ACS_TRANSPARENT` estilo, o clipe AVI será reproduzido usando um plano de fundo transparente em vez da cor do plano de fundo especificada no clipe de animação.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CAnimateCtrl:: CAnimateCtrl](#canimatectrl).

## <a name="canimatectrlseek"></a><a name="seek"></a>CAnimateCtrl:: Seek

Chame essa função para exibir estaticamente um único quadro do seu clipe AVI.

```
BOOL Seek(UINT nTo);
```

### <a name="parameters"></a>parâmetros

*nPara*<br/>
Índice de base zero do quadro a ser exibido. O valor deve ser menor que 65.536. Um valor de 0 significa exibir o primeiro quadro no clipe AVI. Um valor de-1 significa exibir o último quadro no clipe AVI.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, zero.

### <a name="remarks"></a>Comentários

Se o controle de animação tiver um `ACS_TRANSPARENT` estilo, o clipe AVI será desenhado usando um plano de fundo transparente em vez da cor do plano de fundo especificada no clipe de animação.

### <a name="example"></a>Exemplo

Consulte o exemplo de [CAnimateCtrl:: CAnimateCtrl](#canimatectrl).

## <a name="canimatectrlstop"></a><a name="stop"></a>CAnimateCtrl:: Stop

Chame essa função para parar de reproduzir um clipe AVI em um controle de animação.

```
BOOL Stop();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, zero.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CAnimateCtrl:: CAnimateCtrl](#canimatectrl).

## <a name="see-also"></a>Confira também

[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[CAnimateCtrl:: criar](#create)<br/>
[ON_CONTROL](message-map-macros-mfc.md#on_control)
