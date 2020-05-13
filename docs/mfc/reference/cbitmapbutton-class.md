---
title: Classe CBitmapButton
ms.date: 11/04/2016
f1_keywords:
- CBitmapButton
- AFXEXT/CBitmapButton
- AFXEXT/CBitmapButton::CBitmapButton
- AFXEXT/CBitmapButton::AutoLoad
- AFXEXT/CBitmapButton::LoadBitmaps
- AFXEXT/CBitmapButton::SizeToContent
helpviewer_keywords:
- CBitmapButton [MFC], CBitmapButton
- CBitmapButton [MFC], AutoLoad
- CBitmapButton [MFC], LoadBitmaps
- CBitmapButton [MFC], SizeToContent
ms.assetid: 9ad6cb45-c3c4-4fb1-96d3-1fe3df7bbcfc
ms.openlocfilehash: df21591dec1da5861125d7e9480fb9345aaad061
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81752953"
---
# <a name="cbitmapbutton-class"></a>Classe CBitmapButton

Cria controles de botão rotulados com imagens bitmapapped em vez de texto.

## <a name="syntax"></a>Sintaxe

```
class CBitmapButton : public CButton
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CBitmapButton::CBitmapButton](#cbitmapbutton)|Constrói um objeto `CBitmapButton`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CBitmapButton::Carga automática](#autoload)|Associa um botão em uma caixa `CBitmapButton` de diálogo com um objeto da classe, carrega os bitmap(s) pelo nome e dimensiona o botão para encaixar o bitmap.|
|[CBitmapButton::LoadBitmaps](#loadbitmaps)|Inicializa o objeto carregando um ou mais recursos de bitmap nomeados do arquivo de recursos do aplicativo e anexando os bitmaps ao objeto.|
|[CBitmapButton::SizeToContent](#sizetocontent)|Dimensiona o botão para acomodar o bitmap.|

## <a name="remarks"></a>Comentários

`CBitmapButton`objetos contêm até quatro bitmaps, que contêm imagens para os diferentes estados que um botão pode assumir: para cima (ou normal), para baixo (ou selecionado), focado e desativado. Apenas o primeiro bitmap é necessário; os outros são opcionais.

As imagens do botão bitmap incluem a borda ao redor da imagem, bem como a própria imagem. A borda normalmente desempenha um papel em mostrar o estado do botão. Por exemplo, o bitmap para o estado focalizado geralmente é como o do estado de cima, mas com um inset retângulo tracejada da fronteira ou uma linha sólida grossa na fronteira. O bitmap para o estado desativado geralmente se assemelha ao do estado de up, mas tem contraste mais baixo (como uma seleção de menu escurecido ou acinzentado).

Esses bitmaps podem ser de qualquer tamanho, mas todos são tratados como se fossem do mesmo tamanho do bitmap para o estado de up.

Vários aplicativos exigem diferentes combinações de imagens do bitmap:

|Para cima|Para baixo|Focalizado|Desabilitado|Aplicativo|
|--------|----------|-------------|--------------|-----------------|
|×||||Bitmap|
|×|×|||Botão sem estilo WS_TABSTOP|
|×|×|×|×|Botão de diálogo com todos os estados|
|×|×|×||Botão de diálogo com estilo WS_TABSTOP|

Ao criar um controle de botão bitmap, defina o estilo BS_OWNERDRAW para especificar se o botão é desenhado pelo proprietário. Isso faz com que o Windows envie as mensagens WM_MEASUREITEM e WM_DRAWITEM para o botão; a estrutura lida com essas mensagens e gerencia a aparência do botão para você.

### <a name="to-create-a-bitmap-button-control-in-a-windows-client-area"></a>Para criar um controle de botão bitmap na área cliente de uma janela

1. Crie de uma a quatro imagens bitmap para o botão.

1. Construa o objeto [CBitmapButton.](#cbitmapbutton)

1. Chame a função [Criar](../../mfc/reference/cbutton-class.md#create) para criar o controle `CBitmapButton` do botão do Windows e anexá-lo ao objeto.

1. Ligue para a função de membro [LoadBitmaps](#loadbitmaps) para carregar os recursos do bitmap depois que o botão bitmap for construído.

### <a name="to-include-a-bitmap-button-control-in-a-dialog-box"></a>Para incluir um controle de botão bitmap em uma caixa de diálogo

1. Crie de uma a quatro imagens bitmap para o botão.

1. Crie um modelo de diálogo com um botão de desenho do proprietário posicionado onde você deseja o botão bitmap. O tamanho do botão no modelo não importa.

1. Defina a legenda do botão como um valor como "MYIMAGE" e defina um símbolo para o botão como IDC_MYIMAGE.

1. No script de recursos do aplicativo, dê a cada uma das imagens criadas para o botão um ID construído anexando uma das letras "U", "D", "F" ou "X" (para cima, para baixo, focada e desativada) para a string usada para a legenda do botão na etapa 3. Para a legenda de botão " MYIMAGE", por exemplo, os IDs seriam " MYIMAGEU", " MYIMAGED", " MYIMAGEF" e " MYIMAGEX". Você **deve** especificar o ID de seus bitmaps dentro de aspas duplas. Caso contrário, o editor de recursos atribuirá um inteiro ao recurso e o MFC falhará ao carregar a imagem.

1. Na classe de diálogo do aplicativo `CDialog`(derivada), adicione um `CBitmapButton` objeto membro.

1. Na `CDialog` rotina [onInitDialog](../../mfc/reference/cdialog-class.md#oninitdialog) do objeto, `CBitmapButton` chame a função [AutoLoad](#autoload) do objeto, usando como `CDialog` parâmetros o ID de controle do botão e o objeto **deste** ponteiro.

Se você quiser lidar com mensagens de notificação do Windows, como BN_CLICKED, enviadas por um `CDialog`controle de `CDialog`botão bitmap para seu pai (geralmente uma classe derivada), adicione ao objeto derivado uma entrada de mapa de mensagem e função de membro do manipulador de mensagens para cada mensagem. As notificações `CBitmapButton` enviadas por um objeto são as mesmas enviadas por um objeto [CButton.](../../mfc/reference/cbutton-class.md)

A classe [CToolBar](../../mfc/reference/ctoolbar-class.md) adota uma abordagem diferente para botões de bitmap.

Para obter `CBitmapButton`mais informações sobre , consulte [Controles](../../mfc/controls-mfc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CButton](../../mfc/reference/cbutton-class.md)

`CBitmapButton`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxext.h

## <a name="cbitmapbuttonautoload"></a><a name="autoload"></a>CBitmapButton::Carga automática

Associa um botão em uma caixa `CBitmapButton` de diálogo com um objeto da classe, carrega os bitmap(s) pelo nome e dimensiona o botão para encaixar o bitmap.

```
BOOL AutoLoad(
    UINT nID,
    CWnd* pParent);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
O botão é o controle da iD.

*pParent*<br/>
Ponteiro para o objeto que possui o botão.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Use `AutoLoad` a função para inicializar um botão de desenho do proprietário em uma caixa de diálogo como um botão bitmap. As instruções para o uso desta `CBitmapButton` função estão nas observações da classe.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCControlLadenDialog#75](../../mfc/codesnippet/cpp/cbitmapbutton-class_1.cpp)]

## <a name="cbitmapbuttoncbitmapbutton"></a><a name="cbitmapbutton"></a>CBitmapButton::CBitmapButton

Cria um objeto `CBitmapButton`.

```
CBitmapButton();
```

### <a name="remarks"></a>Comentários

Depois de criar `CBitmapButton` o objeto C++, chame [CButton::Criar](../../mfc/reference/cbutton-class.md#create) para `CBitmapButton` criar o controle do botão do Windows e anexá-lo ao objeto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCControlLadenDialog#57](../../mfc/codesnippet/cpp/cbitmapbutton-class_2.cpp)]

## <a name="cbitmapbuttonloadbitmaps"></a><a name="loadbitmaps"></a>CBitmapButton::LoadBitmaps

Use esta função quando quiser carregar imagens de bitmap identificadas por seus `AutoLoad` nomes de recursos ou números de identificação, ou quando você não puder usar a função porque, por exemplo, você está criando um botão bitmap que não faz parte de uma caixa de diálogo.

```
BOOL LoadBitmaps(
    LPCTSTR lpszBitmapResource,
    LPCTSTR lpszBitmapResourceSel = NULL,
    LPCTSTR lpszBitmapResourceFocus = NULL,
    LPCTSTR lpszBitmapResourceDisabled = NULL);

BOOL LoadBitmaps(
    UINT nIDBitmapResource,
    UINT nIDBitmapResourceSel = 0,
    UINT nIDBitmapResourceFocus = 0,
    UINT nIDBitmapResourceDisabled = 0);
```

### <a name="parameters"></a>Parâmetros

*lpszBitmapResource*<br/>
Aponta para a seqüência de terminadas nula que contém o nome do bitmap para o estado normal ou "up" de um botão bitmap. Obrigatórios.

*lpszBitmapResourceSel*<br/>
Aponta para a seqüência de terminadas nula que contém o nome do bitmap para o estado selecionado ou "para baixo" de um botão bitmap. Pode ser NULO.

*lpszBitmapResourceFocus*<br/>
Aponta para a seqüência de terminadas nula que contém o nome do bitmap para o estado focado de um botão bitmap. Pode ser NULO.

*lpszBitmapResourceDisabled*<br/>
Aponta para a seqüência de terminadas nula que contém o nome do bitmap para o estado desativado de um botão bitmap. Pode ser NULO.

*nIDBitmapRecurso*<br/>
Especifica o número de ID de recurso do recurso bitmap para o estado normal ou "up" de um botão bitmap. Obrigatórios.

*nIDBitmapResourceSel*<br/>
Especifica o número de ID de recurso do recurso bitmap para o estado selecionado ou "para baixo" de um botão bitmap. Pode ser 0.

*nIDBitmapResourceFocus*<br/>
Especifica o número de ID de recurso do recurso bitmap para o estado focado em um botão bitmap. Pode ser 0.

*nIDBitmapRecursodesativado*<br/>
Especifica o número de ID de recurso do recurso bitmap para o estado desativado de um botão bitmap. Pode ser 0.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCControlLadenDialog#58](../../mfc/codesnippet/cpp/cbitmapbutton-class_3.cpp)]

## <a name="cbitmapbuttonsizetocontent"></a><a name="sizetocontent"></a>CBitmapButton::SizeToContent

Chame esta função para redimensionar um botão bitmap para o tamanho do bitmap.

```cpp
void SizeToContent();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCControlLadenDialog#59](../../mfc/codesnippet/cpp/cbitmapbutton-class_4.cpp)]

## <a name="see-also"></a>Confira também

[Tomografia de amostra MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CButton](../../mfc/reference/cbutton-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
