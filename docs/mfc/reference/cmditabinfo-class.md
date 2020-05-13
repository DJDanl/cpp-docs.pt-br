---
title: Classe CMDITabInfo
ms.date: 11/04/2016
f1_keywords:
- CMDITabInfo
- AFXMDICLIENTAREAWND/CMDITabInfo
- AFXMDICLIENTAREAWND/CMDITabInfo::Serialize
- AFXMDICLIENTAREAWND/CMDITabInfo::m_bAutoColor
- AFXMDICLIENTAREAWND/CMDITabInfo::m_bDocumentMenu
- AFXMDICLIENTAREAWND/CMDITabInfo::m_bEnableTabSwap
- AFXMDICLIENTAREAWND/CMDITabInfo::m_bFlatFrame
- AFXMDICLIENTAREAWND/CMDITabInfo::m_bTabCloseButton
- AFXMDICLIENTAREAWND/CMDITabInfo::m_bTabCustomTooltips
- AFXMDICLIENTAREAWND/CMDITabInfo::m_bTabIcons
- AFXMDICLIENTAREAWND/CMDITabInfo::m_nTabBorderSize
- AFXMDICLIENTAREAWND/CMDITabInfo::m_style
- AFXMDICLIENTAREAWND/CMDITabInfo::m_tabLocation
helpviewer_keywords:
- CMDITabInfo [MFC], Serialize
- CMDITabInfo [MFC], m_bAutoColor
- CMDITabInfo [MFC], m_bDocumentMenu
- CMDITabInfo [MFC], m_bEnableTabSwap
- CMDITabInfo [MFC], m_bFlatFrame
- CMDITabInfo [MFC], m_bTabCloseButton
- CMDITabInfo [MFC], m_bTabCustomTooltips
- CMDITabInfo [MFC], m_bTabIcons
- CMDITabInfo [MFC], m_nTabBorderSize
- CMDITabInfo [MFC], m_style
- CMDITabInfo [MFC], m_tabLocation
ms.assetid: 988ae1b7-4f7f-4239-b88f-7e28b3291c5e
ms.openlocfilehash: 30bf7726b35d762be2bbbd119e0303894879cd3d
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81752656"
---
# <a name="cmditabinfo-class"></a>Classe CMDITabInfo

A `CMDITabInfo` classe é usada para passar parâmetros para [cmdiframewndEx::EnableMDITabbedGroups](../../mfc/reference/cmdiframewndex-class.md#enablemditabbedgroups) method. Defina membros desta classe para controlar o comportamento de grupos com guias MDI.

## <a name="syntax"></a>Sintaxe

```
class CMDITabInfo
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|`CMDITabInfo::CMDITabInfo`|Construtor padrão.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMDITabInfo::Serialize](#serialize)|Lê ou escreve este objeto de ou para um arquivo.|

### <a name="data-members"></a>Membros de dados

|Nome|Descrição|
|----------|-----------------|
|[CMDITabInfo::m_bActiveTabCloseButton;](#m_bactivetabclosebutton_)|Especifica se um botão **Fechar** é exibido no rótulo da guia ativa.|
|[CMDITabInfo::m_bAutoColor](#m_bautocolor)|Especifica se é a corcoloração das guias MDI.|
|[CMDITabInfo::m_bDocumentMenu](#m_bdocumentmenu)|Especifica se o grupo de guiaexibe um menu pop-up que mostra uma lista de documentos abertos ou exibe botões de rolagem.|
|[CMDITabInfo::m_bEnableTabSwap](#m_benabletabswap)|Especifica se o usuário pode trocar as posições das guias arrastando.|
|[CMDITabInfo::m_bFlatFrame](#m_bflatframe)|Especifica se as guias têm uma moldura plana.|
|[CMDITabInfo::m_bTabCloseButton](#m_btabclosebutton)|Especifica se cada etiqueta de guia exibe um botão **Fechar.**|
|[CMDITabInfo::m_bTabCustomTooltips](#m_btabcustomtooltips)|Especifica se as dicas de ferramentas personalizadas estão habilitadas.|
|[CMDITabInfo::m_bTabIcons](#m_btabicons)|Especifica se é exibido ícones em guias MDI.|
|[CMDITabInfo::m_nTabBorderSize](#m_ntabbordersize)|Especifica o tamanho da borda de cada janela de guia.|
|[CMDITabInfo::m_style](#m_style)|Especifica o estilo dos rótulos da guia.|
|[CMDITabInfo::m_tabLocation](#m_tablocation)|Especifica se as etiquetas das guias estão localizadas na parte superior ou inferior da página.|

## <a name="remarks"></a>Comentários

Esta classe especifica os parâmetros dos grupos de guias MDI que o framework cria.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como definir os `CMDITabInfo` valores das várias variáveis de membros em classe.

[!code-cpp[NVC_MFC_MDITab#1](../../mfc/reference/codesnippet/cpp/cmditabinfo-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cmditabinfo](../../mfc/reference/cmditabinfo-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmdiclientareawnd.h

## <a name="cmditabinfom_bactivetabclosebutton"></a><a name="m_bactivetabclosebutton_"></a>CMDITabInfo::m_bActiveTabCloseButton;

Especifica se um botão **Fechar** é exibido no rótulo da guia ativa.

```
BOOL m_bActiveTabCloseButton;
```

### <a name="remarks"></a>Comentários

Se TRUE, o rótulo da guia ativa exibirá um botão **Fechar.** O botão **Fechar** será removido do canto superior direito da área da guia. Caso contrário, o rótulo da guia ativa não exibirá um botão **Fechar.** O botão **Fechar** aparecerá no canto superior direito da área da guia.

## <a name="cmditabinfom_bautocolor"></a><a name="m_bautocolor"></a>CMDITabInfo::m_bAutoColor

Especifica se cada guia MDI tem sua própria cor.

```
BOOL m_bAutoColor;
```

### <a name="remarks"></a>Comentários

Se TRUE, cada guia terá sua própria cor. O conjunto de cores é gerenciado pela biblioteca MFC. Caso contrário, as guias são exibidas em branco. O valor padrão é FALSE.

## <a name="cmditabinfom_bdocumentmenu"></a><a name="m_bdocumentmenu"></a>CMDITabInfo::m_bDocumentMenu

Especifica se cada guia exibe um menu pop-up que mostra uma lista de documentos abertos na borda direita da área da guia.

```
BOOL m_bDocumentMenu;
```

### <a name="remarks"></a>Comentários

Se TRUE, cada guia do Windows exibe um menu pop-up que mostra uma lista de documentos abertos na borda direita da área da guia; Caso contrário, a janela da guia exibe botões de rolagem na borda direita da área da guia. O valor padrão é FALSE.

## <a name="cmditabinfom_benabletabswap"></a><a name="m_benabletabswap"></a>CMDITabInfo::m_bEnableTabSwap

Especifica se o usuário pode trocar as posições das guias arrastando.

```
BOOL m_bEnableTabSwap;
```

### <a name="remarks"></a>Comentários

Se TRUE, o usuário pode alterar as posições das guias arrastando as guias. Caso contrário, o usuário não pode alterar as posições das guias. O valor padrão é TRUE.

## <a name="cmditabinfom_bflatframe"></a><a name="m_bflatframe"></a>CMDITabInfo::m_bFlatFrame

Especifica se cada janela de guia tem uma moldura plana.

```
BOOL m_bFlatFrame;
```

## <a name="cmditabinfom_btabclosebutton"></a><a name="m_btabclosebutton"></a>CMDITabInfo::m_bTabCloseButton

Especifica se cada janela de guia exibe um botão **Fechar.**

```
BOOL m_bTabCloseButton;
```

### <a name="remarks"></a>Comentários

Se TRUE, cada janela de guia exibe o botão **Fechar** na borda direita da guia. Caso contrário, o botão **Fechar** não será exibido. O valor padrão é TRUE.

## <a name="cmditabinfom_btabcustomtooltips"></a><a name="m_btabcustomtooltips"></a>CMDITabInfo::m_bTabCustomTooltips

Especifica se as guias exibem as pontas das ferramentas.

```
BOOL m_bTabCustomTooltips;
```

### <a name="remarks"></a>Comentários

Se TRUE, o aplicativo envia uma mensagem AFX_WM_ON_GET_TAB_TOOLTIP para o quadro principal. Você pode lidar com esta mensagem usando a macro ON_REGISTERED_MESSAGE.

## <a name="cmditabinfom_btabicons"></a><a name="m_btabicons"></a>CMDITabInfo::m_bTabIcons

Especifica se é exibido ícones em guias MDI.

```
BOOL m_bTabIcons;
```

### <a name="remarks"></a>Comentários

Se TRUE, os ícones serão exibidos em cada guia MDI. Caso contrário, os ícones não serão exibidos nas guias. O valor padrão é FALSE.

## <a name="cmditabinfom_ntabbordersize"></a><a name="m_ntabbordersize"></a>CMDITabInfo::m_nTabBorderSize

Especifica o tamanho da borda, em pixels, de cada janela de guia.

```
int m_nTabBorderSize;
```

### <a name="remarks"></a>Comentários

[CMFCVisualManager::GetMDITabsBordersSize](../../mfc/reference/cmfcvisualmanager-class.md#getmditabsborderssize) retorna o valor padrão.

## <a name="cmditabinfom_style"></a><a name="m_style"></a>CMDITabInfo::m_style

Especifica o estilo dos rótulos da guia.

```
CMFCTabCtrl::Style m_style
```

### <a name="remarks"></a>Comentários

Especifique um dos seguintes estilos para os rótulos de guia:

|||
|-|-|
|STYLE_3D|Estilo 3D.  |
|STYLE_3D_ONENOTE|Estilo Microsoft OneNote.  |
|STYLE_3D_VS2005|Estilo Microsoft Visual Studio 2005.  |
|STYLE_3D_SCROLLED|Estilo 3D com etiquetas de guia retângulo.  |
|STYLE_FLAT_SHARED_HORZ_SCROLL|Estilo plano com barra de rolagem horizontal compartilhada.  |
|STYLE_3D_ROUNDED_SCROLL|Estilo 3D com etiquetas de guia redondas.  |

## <a name="cmditabinfom_tablocation"></a><a name="m_tablocation"></a>CMDITabInfo::m_tabLocation

Especifica se as etiquetas das guias estão localizadas na parte superior ou inferior da página.

```
CMFCTabCtrl::Location m_tabLocation;
```

### <a name="remarks"></a>Comentários

Aplicar nas guias um dos seguintes sinalizadores de localização:

- LOCATION_BOTTOM: as etiquetas das guias estão localizadas na parte inferior da página.

- LOCATION_TOP: as etiquetas das guias estão localizadas no topo da página

## <a name="cmditabinfoserialize"></a><a name="serialize"></a>CMDITabInfo::Serialize

Lê ou escreve este objeto de um arquivo ou de um arquivo.

```cpp
void Serialize(CArchive& ar);
```

### <a name="parameters"></a>Parâmetros

*ar*<br/>
[em] Um objeto [CArchive Class](../../mfc/reference/carchive-class.md) para serializar.

## <a name="see-also"></a>Confira também

[Classe CMDIFrameWndEx](../../mfc/reference/cmdiframewndex-class.md)<br/>
[Grupos com guias MDI](../../mfc/mdi-tabbed-groups.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)
