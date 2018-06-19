---
title: Classe CSmartDockingInfo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CSmartDockingInfo
- AFXDOCKINGMANAGER/CSmartDockingInfo
- AFXDOCKINGMANAGER/CSmartDockingInfo::CopyTo
- AFXDOCKINGMANAGER/CSmartDockingInfo::m_bUseThemeColorInShading
- AFXDOCKINGMANAGER/CSmartDockingInfo::m_clrBaseBackground
- AFXDOCKINGMANAGER/CSmartDockingInfo::m_clrToneDest
- AFXDOCKINGMANAGER/CSmartDockingInfo::m_clrToneSrc
- AFXDOCKINGMANAGER/CSmartDockingInfo::m_clrTransparent
- AFXDOCKINGMANAGER/CSmartDockingInfo::m_nCentralGroupOffset
- AFXDOCKINGMANAGER/CSmartDockingInfo::m_sizeTotal
- AFXDOCKINGMANAGER/CSmartDockingInfo::m_uiMarkerBmpResID
- AFXDOCKINGMANAGER/CSmartDockingInfo::m_uiMarkerLightBmpResID
dev_langs:
- C++
helpviewer_keywords:
- CSmartDockingInfo [MFC], CopyTo
- CSmartDockingInfo [MFC], m_bUseThemeColorInShading
- CSmartDockingInfo [MFC], m_clrBaseBackground
- CSmartDockingInfo [MFC], m_clrToneDest
- CSmartDockingInfo [MFC], m_clrToneSrc
- CSmartDockingInfo [MFC], m_clrTransparent
- CSmartDockingInfo [MFC], m_nCentralGroupOffset
- CSmartDockingInfo [MFC], m_sizeTotal
- CSmartDockingInfo [MFC], m_uiMarkerBmpResID
- CSmartDockingInfo [MFC], m_uiMarkerLightBmpResID
ms.assetid: cab04f38-4bc1-4378-9337-c56fc87fbd68
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3328eacb9789b892a271208193e82546eb73f7e6
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33373661"
---
# <a name="csmartdockinginfo-class"></a>Classe CSmartDockingInfo
Define a aparência dos marcadores de encaixe inteligente.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CSmartDockingInfo : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`CSmartDockingInfo::CSmartDockingInfo`|Construtor padrão.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSmartDockingInfo::CopyTo](#copyto)|Copia os parâmetros de informações de encaixe de smart atual em fornecidos [CSmartDockingInfo](../../mfc/reference/csmartdockinginfo-class.md) objeto.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSmartDockingInfo::m_bUseThemeColorInShading](#m_busethemecolorinshading)|Especifica se deve usar a cor do tema atual quando a estrutura exibe marcadores de encaixe inteligente.|  
|[CSmartDockingInfo::m_clrBaseBackground](#m_clrbasebackground)|Especifica a cor de plano de fundo de base de marcadores de encaixe inteligentes.|  
|[CSmartDockingInfo::m_clrToneDest](#m_clrtonedest)|Especifica a cor que substitui `m_clrToneSrc` em bitmaps de marcador de encaixe inteligente.|  
|[CSmartDockingInfo::m_clrToneSrc](#m_clrtonesrc)|Especifica a cor do smart encaixe bitmaps de marcador.|  
|[CSmartDockingInfo::m_clrTransparent](#m_clrtransparent)|Especifica a cor do smart bitmaps de marcador de encaixe quando eles são transparentes.|  
|[CSmartDockingInfo::m_nCentralGroupOffset](#m_ncentralgroupoffset)|Especifica o deslocamento do grupo central de marcadores de encaixe inteligente dos limites do retângulo grupo central.|  
|[CSmartDockingInfo::m_sizeTotal](#m_sizetotal)|Especifica o tamanho total de todos os marcadores de encaixe inteligentes em um grupo.|  
|[CSmartDockingInfo::m_uiMarkerBmpResID](#m_uimarkerbmpresid)|Define o recurso IDs dos bitmaps que usa a estrutura para marcadores de encaixe inteligente que não são realçados.|  
|[CSmartDockingInfo::m_uiMarkerLightBmpResID](#m_uimarkerlightbmpresid)|Define o recurso IDs dos bitmaps que usa a estrutura para marcadores de encaixe inteligente são realçados.|  
  
## <a name="remarks"></a>Comentários  
 Os identificadores de framework inteligente marcadores de encaixe internamente. A ilustração a seguir mostra os marcadores de encaixe inteligentes padrão:  
  
 ![Padrão marcadores de encaixe inteligente](../../mfc/reference/media/nextsdmarkers.png "nextsdmarkers")  
  
 Nesta figura, a imagem à esquerda mostra um marcador de encaixe inteligente grupo central que não tenha o encaixe para uma guia habilitada. A imagem do meio mostra um marcador de encaixe inteligente da borda direita. A imagem à direita mostra um grupo central inteligente encaixe marcador com encaixe para uma guia habilitada. O marcador de encaixe inteligente grupo central tem um bitmap principal e cinco inteligente encaixe bitmaps de marcador.  
  
 Você pode personalizar os seguintes parâmetros de marcadores de encaixe inteligentes:  
  
-   Cor. Por exemplo, você pode substituir a cor azul dos marcadores na figura com todas as cores definidas pelo usuário.  
  
-   Cor de transparência.  
  
-   Deslocamento de um marcador de encaixe inteligente no grupo central da borda do retângulo delimitador.  
  
-   O bitmap principal que representa o grupo central.  
  
-   Os bitmaps que representa os marcadores de encaixe inteligentes regulares e realçados.  
  
 A ilustração a seguir mostra um exemplo de marcadores de encaixe inteligente personalizados:  
  
 ![Marcadores personalizados para encaixar inteligente](../../mfc/reference/media/nextsdmarkerscustom.png "nextsdmarkerscustom")  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CSmartDockingInfo](../../mfc/reference/csmartdockinginfo-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxDockingManager.h  
  
##  <a name="copyto"></a>  CSmartDockingInfo::CopyTo  
 Copia os parâmetros atuais do encaixe inteligentes fornecido [CSmartDockingInfo](../../mfc/reference/csmartdockinginfo-class.md) objeto.  
  
```  
void CopyTo(CSmartDockingInfo& params);
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `params`  
 Um objeto do tipo `CSmartDockingInfo` que é preenchida com os parâmetros de encaixe inteligentes atuais.  
  
##  <a name="m_busethemecolorinshading"></a>  CSmartDockingInfo::m_bUseThemeColorInShading  
 Especifica se deve usar a cor do tema atual quando a estrutura exibe marcadores de encaixe inteligente.  
  
```  
BOOL m_bUseThemeColorInShading;  
```  
  
### <a name="remarks"></a>Comentários  
 Se `TRUE`, os marcadores são desenhados usando a cor do tema atual; caso contrário, os marcadores são desenhados com uma cor azul clara.  
  
 O valor padrão é `FALSE`.  
  
##  <a name="m_clrbasebackground"></a>  CSmartDockingInfo::m_clrBaseBackground  
 Especifica a cor de plano de fundo de base de marcadores de encaixe inteligentes.  
  
```  
COLORREF m_clrBaseBackground;  
```  
  
##  <a name="m_clrtonedest"></a>  CSmartDockingInfo::m_clrToneDest  
 Especifica a cor que irá substituir `m_clrToneSrc` em bitmaps de marcador de encaixe inteligente.  
  
```  
COLORREF m_clrToneDest;  
```  
  
### <a name="remarks"></a>Comentários  
 Defina esse valor para alterar a cor do marcador bitmaps programaticamente. Por exemplo, se você quiser alterar a cor dos marcadores padrão fornecidos com o framework, defina esse valor para a cor desejada. Por padrão, [CSmartDockingInfo::m_clrToneSrc](#m_clrtonesrc) é definido como RGB (61, 123, 241) (uma cor azulada).  
  
 Para alterar a cor dos marcadores personalizados, você deve especificar `m_clrToneDest` e `m_clrToneSrc`.  
  
##  <a name="m_clrtonesrc"></a>  CSmartDockingInfo::m_clrToneSrc  
 Especifica a cor do smart encaixe bitmaps de marcador.  
  
```  
COLORREF m_clrToneSrc;  
```  
  
### <a name="remarks"></a>Comentários  
 Defina esse valor somente quando você deseja substituir a cor de um bitmap personalizado com outra cor. Você não precisa definir esse valor se você estiver alterando a cor de um padrão (estrutura fornecida) marcador.  
  
 Use `(COLORREF)-1` para deixar um membro do grupo de encaixe inteligente vazio.  
  
##  <a name="m_clrtransparent"></a>  CSmartDockingInfo::m_clrTransparent  
 Especifica a cor do smart bitmaps de marcador de encaixe quando eles são transparentes.  
  
```  
COLORREF m_clrTransparent;  
```  
  
### <a name="remarks"></a>Comentários  
 Você deve definir esse valor quando você exibir marcadores personalizados e bitmaps personalizados no grupo de encaixe.  
  
##  <a name="m_ncentralgroupoffset"></a>  CSmartDockingInfo::m_nCentralGroupOffset  
 Especifica o deslocamento entre o grupo central de marcadores de encaixe inteligentes e os limites do retângulo grupo central.  
  
```  
int m_nCentralGroupOffset;  
```  
  
### <a name="remarks"></a>Comentários  
 Especifique esse valor se você quiser alterar o deslocamento padrão entre marcadores personalizados e os limites do grupo central de marcadores de encaixe inteligente. O deslocamento padrão é de 5 pixels.  
  
##  <a name="m_sizetotal"></a>  CSmartDockingInfo::m_sizeTotal  
 Especifica o tamanho total de um retângulo que inclui todos os marcadores de encaixe inteligente no grupo central.  
  
```  
CSize m_sizeTotal;  
```  
  
### <a name="remarks"></a>Comentários  
 Defina `m_sizeTotal` para o tamanho do retângulo delimitador do marcador grupo central. Você deve especificar esse valor se você estiver usando bitmaps personalizados para marcadores.  
  
##  <a name="m_uimarkerbmpresid"></a>  CSmartDockingInfo::m_uiMarkerBmpResID  
 Define o recurso IDs dos bitmaps que são usados para não realçado personalizados marcadores de encaixe inteligente.  
  
```  
UINT m_uiMarkerBmpResID[AFX_SD_MARKERS_NUM];  
```  
  
### <a name="remarks"></a>Comentários  
 Preencha essa matriz com o recurso de IDs de bitmaps que representa os marcadores de encaixe inteligentes. `AFX_SD_MARKERS_NUM` no momento está definido como 5. Você pode preencher a matriz da seguinte maneira:  
  
 `params.m_uiMarkerBmpResID[0] = IDB_MARKER_LEFT;`  
  
 `params.m_uiMarkerBmpResID[1] = IDB_MARKER_RIGHT;`  
  
 `params.m_uiMarkerBmpResID[2] = IDB_MARKER_TOP;`  
  
 `params.m_uiMarkerBmpResID[3] = IDB_MARKER_BOTTOM;`  
  
 `params.m_uiMarkerBmpResID[4] = IDB_MARKER_CENTER;`  
  
##  <a name="m_uimarkerlightbmpresid"></a>  CSmartDockingInfo::m_uiMarkerLightBmpResID  
 Define o recurso IDs dos bitmaps que são usados para marcadores de encaixe inteligente personalizados realçados.  
  
```  
UINT m_uiMarkerLightBmpResID[AFX_SD_MARKERS_NUM];  
```  
  
### <a name="remarks"></a>Comentários  
 Preencha essa matriz com o recurso de IDs de bitmaps que representa os marcadores de encaixe inteligentes realçados. `AFX_SD_MARKERS_NUM` no momento está definido como 5. Você pode preencher a matriz da seguinte maneira:  
  
 `params.m_uiMarkerLightBmpResID[0] = IDB_MARKER_LEFT_LIGHT;`  
  
 `params.m_uiMarkerLightBmpResID[1] = IDB_MARKER_RIGHT_LIGHT;`  
  
 `params.m_uiMarkerLightBmpResID[2] = IDB_MARKER_TOP_LIGHT;`  
  
 `params.m_uiMarkerLightBmpResID[3] = IDB_MARKER_BOTTOM_LIGHT;`  
  
 `params.m_uiMarkerLightBmpResID[4] = IDB_MARKER_CENTER_LIGHT;`  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CObject](../../mfc/reference/cobject-class.md)
