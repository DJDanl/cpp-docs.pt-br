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
ms.openlocfilehash: 0cf4554f86f4a9275e4d96b3db519fde7fb05b22
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87231865"
---
# <a name="cbitmapbutton-class"></a>Classe CBitmapButton

Cria controles de pressão rotulados com imagens de bitmap em vez de texto.

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
|[CBitmapButton:: AutoLoad](#autoload)|Associa um botão em uma caixa de diálogo a um objeto da `CBitmapButton` classe, carrega os bitmaps por nome e dimensiona o botão para ajustá-lo ao bitmap.|
|[CBitmapButton:: LoadBitmaps](#loadbitmaps)|Inicializa o objeto carregando um ou mais recursos de bitmap nomeados do arquivo de recursos do aplicativo e anexando os bitmaps ao objeto.|
|[CBitmapButton::SizeToContent](#sizetocontent)|Dimensiona o botão para acomodar o bitmap.|

## <a name="remarks"></a>Comentários

`CBitmapButton`os objetos contêm até quatro bitmaps, que contêm imagens para os diferentes Estados que um botão pode assumir: cima (ou normal), para baixo (ou selecionado), com foco e desabilitado. Somente o primeiro bitmap é necessário; os outros são opcionais.

Imagens de botão de bitmap incluem a borda em torno da imagem, bem como a própria imagem. A borda normalmente desempenha uma parte na exibição do estado do botão. Por exemplo, o bitmap para o estado focalizado geralmente é como aquele para o estado ativo, mas com uma margem de retângulo tracejada da borda ou uma linha sólida espessa na borda. O bitmap para o estado desabilitado geralmente se assemelha ao estado ativo, mas tem contraste inferior (como uma seleção de menu esmaecida ou cinza).

Esses bitmaps podem ser de qualquer tamanho, mas todos são tratados como se fossem do mesmo tamanho que o bitmap para o estado ativo.

Vários aplicativos exigem diferentes combinações de imagens de bitmap:

|Up|Down|Focalizado|Desabilitado|Aplicativo|
|--------|----------|-------------|--------------|-----------------|
|×||||Bitmap|
|×|×|||Botão sem estilo de WS_TABSTOP|
|×|×|×|×|Botão de diálogo com todos os Estados|
|×|×|×||Botão de diálogo com estilo de WS_TABSTOP|

Ao criar um controle de botão de bitmap, defina o estilo de BS_OWNERDRAW para especificar que o botão é desenhado pelo proprietário. Isso faz com que o Windows envie o WM_MEASUREITEM e WM_DRAWITEM mensagens para o botão; a estrutura manipula essas mensagens e gerencia a aparência do botão para você.

### <a name="to-create-a-bitmap-button-control-in-a-windows-client-area"></a>Para criar um controle de botão de bitmap na área do cliente da janela

1. Crie uma para quatro imagens de bitmap para o botão.

1. Construa o objeto [CBitmapButton](#cbitmapbutton) .

1. Chame a função [Create](../../mfc/reference/cbutton-class.md#create) para criar o controle de botão do Windows e anexá-lo ao `CBitmapButton` objeto.

1. Chame a função de membro [LoadBitmaps](#loadbitmaps) para carregar os recursos de bitmap depois que o botão de bitmap for construído.

### <a name="to-include-a-bitmap-button-control-in-a-dialog-box"></a>Para incluir um controle de botão de bitmap em uma caixa de diálogo

1. Crie uma para quatro imagens de bitmap para o botão.

1. Crie um modelo de caixa de diálogo com um botão de desenho proprietário posicionado onde você deseja o botão de bitmap. O tamanho do botão no modelo não importa.

1. Defina a legenda do botão como um valor como "MYIMAGE" e defina um símbolo para o botão, como IDC_MYIMAGE.

1. No script de recurso do aplicativo, forneça a cada uma das imagens criadas para o botão uma ID construída acrescentando uma das letras "U", "D," "F" ou "X" (para cima, para baixo, com foco e desabilitado) à cadeia de caracteres usada para a legenda do botão na etapa 3. Para a legenda do botão "MYIMAGE", por exemplo, as IDs seriam "myimageexception", "MYIMAGED", "MYIMAGEF" e "MYIMAGEX". Você **deve** especificar a ID dos bitmaps entre aspas duplas. Caso contrário, o editor de recursos atribuirá um inteiro ao recurso e o MFC falhará ao carregar a imagem.

1. Na classe de diálogo do aplicativo (derivada de `CDialog` ), adicione um `CBitmapButton` objeto de membro.

1. Na `CDialog` rotina [OnInitDialog](../../mfc/reference/cdialog-class.md#oninitdialog) do objeto, chame a `CBitmapButton` função [AutoLoad](#autoload) do objeto, usando como parâmetros a ID de controle do botão e o `CDialog` ponteiro do objeto **`this`** .

Se você quiser manipular mensagens de notificação do Windows, como BN_CLICKED, enviadas por um controle de botão de bitmap para seu pai (geralmente uma classe derivada de `CDialog` ), adicione ao `CDialog` objeto derivado uma entrada de mapa de mensagem e uma função de membro de manipulador de mensagens para cada mensagem. As notificações enviadas por um `CBitmapButton` objeto são as mesmas enviadas por um objeto [CButton](../../mfc/reference/cbutton-class.md) .

A classe [CToolBar](../../mfc/reference/ctoolbar-class.md) usa uma abordagem diferente para botões de bitmap.

Para obter mais informações sobre o `CBitmapButton` , consulte [controles](../../mfc/controls-mfc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CButton](../../mfc/reference/cbutton-class.md)

`CBitmapButton`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxext. h

## <a name="cbitmapbuttonautoload"></a><a name="autoload"></a>CBitmapButton:: AutoLoad

Associa um botão em uma caixa de diálogo a um objeto da `CBitmapButton` classe, carrega os bitmaps por nome e dimensiona o botão para ajustá-lo ao bitmap.

```
BOOL AutoLoad(
    UINT nID,
    CWnd* pParent);
```

### <a name="parameters"></a>parâmetros

*nID*<br/>
A ID de controle do botão.

*pParent*<br/>
Ponteiro para o objeto que possui o botão.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Use a `AutoLoad` função para inicializar um botão de desenho proprietário em uma caixa de diálogo como um botão de bitmap. As instruções para usar essa função estão nos comentários para a `CBitmapButton` classe.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCControlLadenDialog#75](../../mfc/codesnippet/cpp/cbitmapbutton-class_1.cpp)]

## <a name="cbitmapbuttoncbitmapbutton"></a><a name="cbitmapbutton"></a>CBitmapButton::CBitmapButton

Cria um objeto `CBitmapButton`.

```
CBitmapButton();
```

### <a name="remarks"></a>Comentários

Depois de criar o `CBitmapButton` objeto C++, chame [CButton:: Create](../../mfc/reference/cbutton-class.md#create) para criar o controle de botão do Windows e anexá-lo ao `CBitmapButton` objeto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCControlLadenDialog#57](../../mfc/codesnippet/cpp/cbitmapbutton-class_2.cpp)]

## <a name="cbitmapbuttonloadbitmaps"></a><a name="loadbitmaps"></a>CBitmapButton:: LoadBitmaps

Use essa função quando desejar carregar imagens de bitmap identificadas por seus nomes de recursos ou números de ID, ou quando não for possível usar a `AutoLoad` função porque, por exemplo, você está criando um botão de bitmap que não faz parte de uma caixa de diálogo.

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

### <a name="parameters"></a>parâmetros

*lpszBitmapResource*<br/>
Aponta para a cadeia de caracteres terminada em nulo que contém o nome do bitmap para o estado normal ou "vertical" de um botão de bitmap. Obrigatórios.

*lpszBitmapResourceSel*<br/>
Aponta para a cadeia de caracteres terminada em nulo que contém o nome do bitmap para o estado selecionado ou "inativo" do botão de bitmap. Pode ser NULL.

*lpszBitmapResourceFocus*<br/>
Aponta para a cadeia de caracteres terminada em nulo que contém o nome do bitmap para o estado focalizado de um botão de bitmap. Pode ser NULL.

*lpszBitmapResourceDisabled*<br/>
Aponta para a cadeia de caracteres terminada em nulo que contém o nome do bitmap para o estado desabilitado de um botão de bitmap. Pode ser NULL.

*nIDBitmapResource*<br/>
Especifica o número de ID de recurso do recurso de bitmap para o estado normal ou "vertical" de um botão de bitmap. Obrigatórios.

*nIDBitmapResourceSel*<br/>
Especifica o número de ID de recurso do recurso de bitmap para o estado selecionado ou "inativo" do botão de bitmap. Pode ser 0.

*nIDBitmapResourceFocus*<br/>
Especifica o número de ID de recurso do recurso de bitmap para o estado focalizado de um botão de bitmap. Pode ser 0.

*nIDBitmapResourceDisabled*<br/>
Especifica o número de ID de recurso do recurso de bitmap para o estado desabilitado de um botão de bitmap. Pode ser 0.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCControlLadenDialog#58](../../mfc/codesnippet/cpp/cbitmapbutton-class_3.cpp)]

## <a name="cbitmapbuttonsizetocontent"></a><a name="sizetocontent"></a>CBitmapButton::SizeToContent

Chame essa função para redimensionar um botão de bitmap para o tamanho do bitmap.

```cpp
void SizeToContent();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCControlLadenDialog#59](../../mfc/codesnippet/cpp/cbitmapbutton-class_4.cpp)]

## <a name="see-also"></a>Confira também

[Exemplo de CTRLTEST do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CButton](../../mfc/reference/cbutton-class.md)<br/>
[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)
