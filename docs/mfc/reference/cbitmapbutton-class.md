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
ms.openlocfilehash: c800b40fcf2bb3008b35614390e4aafcb43a54f5
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57296755"
---
# <a name="cbitmapbutton-class"></a>Classe CBitmapButton

Cria controles de botão de pressão rotulados com imagens bitmap em vez de texto.

## <a name="syntax"></a>Sintaxe

```
class CBitmapButton : public CButton
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CBitmapButton::CBitmapButton](#cbitmapbutton)|Constrói um objeto `CBitmapButton`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CBitmapButton::AutoLoad](#autoload)|Associa um botão em uma caixa de diálogo com um objeto do `CBitmapButton` classe, carrega o bitmap(s) por nome e dimensiona o botão de acordo com o bitmap.|
|[CBitmapButton::LoadBitmaps](#loadbitmaps)|Inicializa o objeto de carregamento de um ou mais recursos de bitmap nomeado de arquivo de recurso do aplicativo e anexando os bitmaps ao objeto.|
|[CBitmapButton::SizeToContent](#sizetocontent)|Dimensiona o botão para acomodar o bitmap.|

## <a name="remarks"></a>Comentários

`CBitmapButton` objetos contêm até quatro bitmaps, que contêm imagens para os diferentes estados em um botão pode assumir: cima (ou normal), baixo (ou selecionada), com foco e desabilitada. Somente o bitmap primeiro é necessário; os outros são opcionais.

As imagens de botões de bitmap incluem a borda ao redor da imagem, bem como a própria imagem. Normalmente, a borda desempenha um papel em mostrando o estado do botão. Por exemplo, o bitmap para o estado de foco normalmente é como o mostrado para o estado ativo, mas com um retângulo tracejado baixo-relevo de borda ou uma linha sólida espessa na borda. O bitmap para disabled estado geralmente é semelhante aquele para o estado ativo, mas tem mais baixo contraste (como uma seleção de menu cinza ou esmaecidos).

Esses bitmaps podem ser de qualquer tamanho, mas todas são tratadas como se fossem do mesmo tamanho que o bitmap do estado ativo.

Vários aplicativos exigem diferentes combinações de imagens de bitmap:

|Acima|Abaixo|Focalizado|Disabled|Aplicativo|
|--------|----------|-------------|--------------|-----------------|
|×||||Bitmap|
|×|×|||Botão sem estilo WS_TABSTOP|
|×|×|×|×|Botão da caixa de diálogo com todos os estados|
|×|×|×||Botão da caixa de diálogo com estilo WS_TABSTOP|

Ao criar um controle de botão de bitmap, defina o estilo BS_OWNERDRAW para especificar que o botão é desenhado pelo proprietário. Isso faz com que o Windows enviar as mensagens WM_MEASUREITEM e WM_DRAWITEM para o botão; a estrutura lida com essas mensagens e gerencia a aparência do botão para você.

### <a name="to-create-a-bitmap-button-control-in-a-windows-client-area"></a>Para criar um controle de botão de bitmap na área de cliente da janela

1. Crie um a quatro imagens bitmap do botão.

1. Construir o [CBitmapButton](#cbitmapbutton) objeto.

1. Chame o [Create](../../mfc/reference/cbutton-class.md#create) função para criar o controle de botão do Windows e anexá-lo para o `CBitmapButton` objeto.

1. Chame o [LoadBitmaps](#loadbitmaps) a função de membro para carregar os recursos de bitmap depois que o botão de bitmap é construído.

### <a name="to-include-a-bitmap-button-control-in-a-dialog-box"></a>Para incluir um controle de botão de bitmap em uma caixa de diálogo

1. Crie um a quatro imagens bitmap do botão.

1. Crie um modelo de caixa de diálogo com um botão de desenho proprietário posicionado onde você deseja que o botão de bitmap. Não importa o tamanho do botão no modelo.

1. Definir a legenda do botão com um valor como "MYIMAGE" e definir um símbolo para o botão, como IDC_MYIMAGE.

1. Script de recurso do seu aplicativo, dê a cada uma das imagens criadas para o botão de uma ID construída acrescentando uma das letras "U", "D", "F" ou "X" (para cima, para baixo, com foco e desativado) na cadeia de caracteres usada para a legenda do botão na etapa 3. Para a legenda do botão "MYIMAGE", por exemplo, as IDs poderia ser "MYIMAGEU", "MYIMAGED", "MYIMAGEF" e "MYIMAGEX". Você **deve** especifique a ID de bitmaps de aspas duplas. Caso contrário, o resource editor atribuirá um número inteiro para o recurso e MFC falhará ao carregar a imagem.

1. Na classe de caixa de diálogo do seu aplicativo (derivado de `CDialog`), adicione um `CBitmapButton` objeto membro.

1. No `CDialog` do objeto [OnInitDialog](../../mfc/reference/cdialog-class.md#oninitdialog) chamada de rotina, o `CBitmapButton` do objeto [AutoLoad](#autoload) funcionam, usando como parâmetros de ID do controle do botão e o `CDialog` objeto **isso** ponteiro.

Se você quiser manipular mensagens de notificação do Windows, como BN_CLICKED, enviado por um controle de botão de bitmap para seu pai (normalmente uma classe derivada de `CDialog`), adicionar ao `CDialog`-objeto derivado um membro de entrada e o manipulador de mensagens do mapa de mensagem função para cada mensagem. As notificações enviadas por uma `CBitmapButton` objeto são iguais àquelas enviadas por um [CButton](../../mfc/reference/cbutton-class.md) objeto.

A classe [CToolBar](../../mfc/reference/ctoolbar-class.md) adota uma abordagem diferente para os botões de bitmap.

Para obter mais informações sobre `CBitmapButton`, consulte [controles](../../mfc/controls-mfc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CButton](../../mfc/reference/cbutton-class.md)

`CBitmapButton`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxext.h

##  <a name="autoload"></a>  CBitmapButton::AutoLoad

Associa um botão em uma caixa de diálogo com um objeto do `CBitmapButton` classe, carrega o bitmap(s) por nome e dimensiona o botão de acordo com o bitmap.

```
BOOL AutoLoad(
    UINT nID,
    CWnd* pParent);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
ID do controle. do botão

*pParent*<br/>
Ponteiro para o objeto que possui o botão.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Use o `AutoLoad` função para inicializar um botão de desenho proprietário em uma caixa de diálogo como um botão de bitmap. Instruções sobre como usar essa função é nos comentários para o `CBitmapButton` classe.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCControlLadenDialog#75](../../mfc/codesnippet/cpp/cbitmapbutton-class_1.cpp)]

##  <a name="cbitmapbutton"></a>  CBitmapButton::CBitmapButton

Cria um objeto `CBitmapButton`.

```
CBitmapButton();
```

### <a name="remarks"></a>Comentários

Depois de criar o C++ `CBitmapButton` do objeto, chame [CButton::Create](../../mfc/reference/cbutton-class.md#create) para criar o controle de botão do Windows e anexá-lo para o `CBitmapButton` objeto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCControlLadenDialog#57](../../mfc/codesnippet/cpp/cbitmapbutton-class_2.cpp)]

##  <a name="loadbitmaps"></a>  CBitmapButton::LoadBitmaps

Use essa função quando quiser carregar imagens de bitmap identificadas por seus nomes de recursos ou os números de ID, ou quando você não pode usar o `AutoLoad` porque, por exemplo, você está criando um botão de bitmap que não faz parte de uma caixa de diálogo de função.

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
Aponta para a cadeia de caracteres terminada em nulo que contém o nome do bitmap para normal do botão um bitmap ou "backup" do estado. Necessário.

*lpszBitmapResourceSel*<br/>
Aponta para a cadeia de caracteres terminada em nulo que contém o nome do bitmap para um botão de bitmap do selecionado ou "estado inativo". Pode ser NULL.

*lpszBitmapResourceFocus*<br/>
Aponta para a cadeia de caracteres terminada em nulo que contém o nome do bitmap de um botão de bitmap se concentrou em estado. Pode ser NULL.

*lpszBitmapResourceDisabled*<br/>
Aponta para a cadeia de caracteres terminada em nulo que contém o nome do bitmap de um botão de bitmap estado desabilitado. Pode ser NULL.

*nIDBitmapResource*<br/>
Especifica o número de ID de recurso do recurso de bitmap para normal do botão um bitmap ou "backup" do estado. Necessário.

*nIDBitmapResourceSel*<br/>
Especifica o número de ID de recurso do recurso de bitmap para um botão de bitmap do selecionado ou "estado inativo". Pode ser 0.

*nIDBitmapResourceFocus*<br/>
Especifica o número de ID de recurso do recurso de bitmap para o estado de foco do botão um bitmap. Pode ser 0.

*nIDBitmapResourceDisabled*<br/>
Especifica o número de ID de recurso do recurso para o estado desabilitado de um botão de bitmap bitmap. Pode ser 0.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCControlLadenDialog#58](../../mfc/codesnippet/cpp/cbitmapbutton-class_3.cpp)]

##  <a name="sizetocontent"></a>  CBitmapButton::SizeToContent

Chame essa função para redimensionar um botão de bitmap para o tamanho do bitmap.

```
void SizeToContent();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCControlLadenDialog#59](../../mfc/codesnippet/cpp/cbitmapbutton-class_4.cpp)]

## <a name="see-also"></a>Consulte também

[Exemplo MFC CTRLTEST](../../visual-cpp-samples.md)<br/>
[Classe CButton](../../mfc/reference/cbutton-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
